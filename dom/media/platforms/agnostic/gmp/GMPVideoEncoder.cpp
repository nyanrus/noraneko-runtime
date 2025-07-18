/* -*- Mode: C++; tab-width: 2; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim:set ts=2 sw=2 sts=2 et cindent: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "GMPVideoEncoder.h"

#include "AnnexB.h"
#include "ErrorList.h"
#include "H264.h"
#include "GMPLog.h"
#include "GMPUtils.h"
#include "GMPService.h"
#include "GMPVideoHost.h"
#include "ImageContainer.h"
#include "ImageConversion.h"
#include "mozilla/StaticPrefs_media.h"
#include "nsServiceManagerUtils.h"
#include "prsystem.h"

namespace mozilla {

static GMPVideoCodecMode ToGMPVideoCodecMode(Usage aUsage) {
  switch (aUsage) {
    case Usage::Realtime:
      return kGMPRealtimeVideo;
    case Usage::Record:
    default:
      // ParamValidationExt in OpenH264 rejects all other codec modes besides
      // realtime and screensharing.
      return kGMPScreensharing;
  }
}

static GMPProfile ToGMPProfile(H264_PROFILE aProfile) {
  switch (aProfile) {
    case H264_PROFILE_MAIN:
      return kGMPH264ProfileMain;
    case H264_PROFILE_EXTENDED:
      return kGMPH264ProfileExtended;
    case H264_PROFILE_HIGH:
      return kGMPH264ProfileHigh;
    case H264_PROFILE_UNKNOWN:
    default:
      return kGMPH264ProfileUnknown;
  }
}

static GMPLevel ToGMPLevel(H264_LEVEL aLevel) {
  switch (aLevel) {
    case H264_LEVEL::H264_LEVEL_1:
      return kGMPH264Level1_0;
    case H264_LEVEL::H264_LEVEL_1_1:
      // H264_LEVEL_1_b has the same value as H264_LEVEL_1_1, while
      // kGMPH264Level1_B and kGMPH264Level1_1 differ. Since we can't tell the
      // difference, we just ignore the 1_b case.
      return kGMPH264Level1_1;
    case H264_LEVEL::H264_LEVEL_1_2:
      return kGMPH264Level1_2;
    case H264_LEVEL::H264_LEVEL_1_3:
      return kGMPH264Level1_3;
    case H264_LEVEL::H264_LEVEL_2:
      return kGMPH264Level2_0;
    case H264_LEVEL::H264_LEVEL_2_1:
      return kGMPH264Level2_1;
    case H264_LEVEL::H264_LEVEL_2_2:
      return kGMPH264Level2_2;
    case H264_LEVEL::H264_LEVEL_3:
      return kGMPH264Level3_0;
    case H264_LEVEL::H264_LEVEL_3_1:
      return kGMPH264Level3_1;
    case H264_LEVEL::H264_LEVEL_3_2:
      return kGMPH264Level3_2;
    case H264_LEVEL::H264_LEVEL_4:
      return kGMPH264Level4_0;
    case H264_LEVEL::H264_LEVEL_4_1:
      return kGMPH264Level4_1;
    case H264_LEVEL::H264_LEVEL_4_2:
      return kGMPH264Level4_2;
    case H264_LEVEL::H264_LEVEL_5:
      return kGMPH264Level5_0;
    case H264_LEVEL::H264_LEVEL_5_1:
      return kGMPH264Level5_1;
    case H264_LEVEL::H264_LEVEL_5_2:
      return kGMPH264Level5_2;
    // 6.0 and above isn't supported.
    default:
      return kGMPH264LevelUnknown;
  }
}

RefPtr<MediaDataEncoder::InitPromise> GMPVideoEncoder::Init() {
  MOZ_ASSERT(IsOnGMPThread());
  MOZ_ASSERT(mInitPromise.IsEmpty());

  mMPS = do_GetService("@mozilla.org/gecko-media-plugin-service;1");
  MOZ_ASSERT(mMPS);

  RefPtr<InitPromise> promise(mInitPromise.Ensure(__func__));

  nsTArray<nsCString> tags(1);
  tags.AppendElement("h264"_ns);

  UniquePtr<GetGMPVideoEncoderCallback> callback(new InitDoneCallback(this));
  if (NS_FAILED(mMPS->GetGMPVideoEncoder(nullptr, &tags, ""_ns,
                                         std::move(callback)))) {
    GMP_LOG_ERROR("[%p] GMPVideoEncoder::Init -- failed to request encoder",
                  this);
    mInitPromise.Reject(NS_ERROR_DOM_MEDIA_FATAL_ERR, __func__);
  }

  return promise;
}

void GMPVideoEncoder::InitComplete(GMPVideoEncoderProxy* aGMP,
                                   GMPVideoHost* aHost) {
  MOZ_ASSERT(IsOnGMPThread());

  mGMP = aGMP;
  mHost = aHost;

  if (NS_WARN_IF(!mGMP) || NS_WARN_IF(!mHost) ||
      NS_WARN_IF(mInitPromise.IsEmpty())) {
    GMP_LOG_ERROR(
        "[%p] GMPVideoEncoder::InitComplete -- failed to create proxy/host",
        this);
    Teardown(MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR, "No proxy/host"),
             __func__);
    return;
  }

  GMPVideoCodec codec{};

  codec.mGMPApiVersion = kGMPVersion36;
  codec.mCodecType = kGMPVideoCodecH264;
  codec.mMode = ToGMPVideoCodecMode(mConfig.mUsage);
  codec.mWidth = mConfig.mSize.width;
  codec.mHeight = mConfig.mSize.height;

  // A bitrate need to be set here, attempt to make an educated guess if none is
  // provided.
  if (mConfig.mBitrate) {
    codec.mStartBitrate = mConfig.mBitrate / 1000;
  } else {
    int32_t longDimension = std::max(mConfig.mSize.width, mConfig.mSize.height);
    if (longDimension < 720) {
      codec.mStartBitrate = 2000;
    } else if (longDimension < 1080) {
      codec.mStartBitrate = 4000;
    } else {
      codec.mStartBitrate = 8000;
    }
  }

  codec.mMinBitrate = mConfig.mMinBitrate / 1000;
  codec.mMaxBitrate = mConfig.mMaxBitrate ? mConfig.mMaxBitrate / 1000
                                          : codec.mStartBitrate * 2;
  codec.mMaxFramerate = mConfig.mFramerate;
  codec.mUseThreadedEncode = StaticPrefs::media_gmp_encoder_multithreaded();
  codec.mLogLevel = GetGMPLibraryLogLevel();

  switch (mConfig.mScalabilityMode) {
    case ScalabilityMode::L1T2:
      codec.mTemporalLayerNum = 2;
      break;
    case ScalabilityMode::L1T3:
      codec.mTemporalLayerNum = 3;
      break;
    default:
      MOZ_FALLTHROUGH_ASSERT("Unhandled scalability mode!");
    case ScalabilityMode::None:
      codec.mTemporalLayerNum = 1;
      break;
  }

  if (mConfig.mCodecSpecific.is<H264Specific>()) {
    const H264Specific& specific = mConfig.mCodecSpecific.as<H264Specific>();
    codec.mProfile = ToGMPProfile(specific.mProfile);
    codec.mLevel = ToGMPLevel(specific.mLevel);
  }

  nsTArray<uint8_t> codecSpecific;
  GMPErr err = mGMP->InitEncode(codec, codecSpecific, this,
                                PR_GetNumberOfProcessors(), 0);
  if (NS_WARN_IF(err != GMPNoErr)) {
    GMP_LOG_ERROR("[%p] GMPVideoEncoder::InitComplete -- failed to init proxy",
                  this);
    Teardown(ToMediaResult(err, "InitEncode failed"_ns), __func__);
    return;
  }

  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::InitComplete -- encoder initialized",
                this);
  mInitPromise.Resolve(TrackInfo::TrackType::kVideoTrack, __func__);
}

RefPtr<MediaDataEncoder::EncodePromise> GMPVideoEncoder::Encode(
    const MediaData* aSample) {
  MOZ_ASSERT(aSample != nullptr);
  MOZ_ASSERT(IsOnGMPThread());

  if (NS_WARN_IF(!IsInitialized())) {
    return EncodePromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                          __func__);
  }

  GMPVideoFrame* ftmp = nullptr;
  GMPErr err = mHost->CreateFrame(kGMPI420VideoFrame, &ftmp);
  if (NS_WARN_IF(err != GMPNoErr)) {
    GMP_LOG_ERROR("[%p] GMPVideoEncoder::Encode -- failed to create frame",
                  this);
    return EncodePromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                          __func__);
  }

  GMPUniquePtr<GMPVideoi420Frame> frame(static_cast<GMPVideoi420Frame*>(ftmp));
  const VideoData* sample(aSample->As<const VideoData>());
  const uint64_t timestamp = sample->mTime.ToMicroseconds();

  const gfx::IntSize ySize = mConfig.mSize;
  const gfx::IntSize cbCrSize =
      gfx::ChromaSize(ySize, gfx::ChromaSubsampling::HALF_WIDTH_AND_HEIGHT);
  const int32_t yStride = ySize.width;
  const int32_t cbCrStride = cbCrSize.width;

  GMP_LOG_DEBUG(
      "[%p] GMPVideoEncoder::Encode -- request encode of frame @ %" PRIu64
      " y %dx%d stride=%d cbCr %dx%d stride=%d",
      this, timestamp, ySize.width, ySize.height, yStride, cbCrSize.width,
      cbCrSize.height, cbCrStride);

  err = frame->CreateEmptyFrame(ySize.width, ySize.height, yStride, cbCrStride,
                                cbCrStride);
  if (NS_WARN_IF(err != GMPNoErr)) {
    GMP_LOG_ERROR(
        "[%p] GMPVideoEncoder::Encode -- failed to allocate frame data", this);
    return EncodePromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                          __func__);
  }

  uint8_t* yDest = frame->Buffer(GMPPlaneType::kGMPYPlane);
  uint8_t* uDest = frame->Buffer(GMPPlaneType::kGMPUPlane);
  uint8_t* vDest = frame->Buffer(GMPPlaneType::kGMPVPlane);

  nsresult rv = ConvertToI420(sample->mImage, yDest, yStride, uDest, cbCrStride,
                              vDest, cbCrStride, ySize);
  if (NS_WARN_IF(NS_FAILED(rv))) {
    GMP_LOG_ERROR("[%p] GMPVideoEncoder::Encode -- failed to convert to I420",
                  this);
    return EncodePromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                          __func__);
  }

  frame->SetTimestamp(timestamp);

  AutoTArray<GMPVideoFrameType, 1> frameType;
  frameType.AppendElement(sample->mKeyframe ? kGMPKeyFrame : kGMPDeltaFrame);

  nsTArray<uint8_t> codecSpecific;
  err = mGMP->Encode(std::move(frame), codecSpecific, frameType);
  if (NS_WARN_IF(err != GMPNoErr)) {
    GMP_LOG_ERROR("[%p] GMPVideoEncoder::Encode -- failed to queue frame",
                  this);
    return EncodePromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                          __func__);
  }

  RefPtr<EncodePromise::Private> promise = new EncodePromise::Private(__func__);
  mPendingEncodes.InsertOrUpdate(timestamp, promise);
  return promise.forget();
}

RefPtr<MediaDataEncoder::ReconfigurationPromise> GMPVideoEncoder::Reconfigure(
    const RefPtr<const EncoderConfigurationChangeList>& aConfigurationChanges) {
  // General reconfiguration interface not implemented right now
  return MediaDataEncoder::ReconfigurationPromise::CreateAndReject(
      NS_ERROR_DOM_MEDIA_FATAL_ERR, __func__);
}

RefPtr<MediaDataEncoder::EncodePromise> GMPVideoEncoder::Drain() {
  MOZ_ASSERT(IsOnGMPThread());
  MOZ_ASSERT(mDrainPromise.IsEmpty());

  if (NS_WARN_IF(!IsInitialized())) {
    return EncodePromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                          __func__);
  }

  if (mPendingEncodes.IsEmpty()) {
    return EncodePromise::CreateAndResolve(EncodedData(), __func__);
  }

  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::Drain -- waiting for queue to clear",
                this);
  return mDrainPromise.Ensure(__func__);
}

RefPtr<ShutdownPromise> GMPVideoEncoder::Shutdown() {
  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::Shutdown", this);
  MOZ_ASSERT(IsOnGMPThread());

  Teardown(MediaResult(NS_ERROR_DOM_MEDIA_CANCELED, "Shutdown"_ns), __func__);
  return ShutdownPromise::CreateAndResolve(true, __func__);
}

RefPtr<GenericPromise> GMPVideoEncoder::SetBitrate(uint32_t aBitsPerSec) {
  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::SetBitrate -- %u", this, aBitsPerSec);
  MOZ_ASSERT(IsOnGMPThread());

  if (NS_WARN_IF(!IsInitialized())) {
    return GenericPromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                           __func__);
  }

  GMPErr err = mGMP->SetRates(aBitsPerSec / 1000, mConfig.mFramerate);
  if (NS_WARN_IF(err != GMPNoErr)) {
    return GenericPromise::CreateAndReject(NS_ERROR_DOM_MEDIA_FATAL_ERR,
                                           __func__);
  }

  return GenericPromise::CreateAndResolve(true, __func__);
}

void GMPVideoEncoder::Encoded(GMPVideoEncodedFrame* aEncodedFrame,
                              const nsTArray<uint8_t>& aCodecSpecificInfo) {
  MOZ_ASSERT(IsOnGMPThread());
  MOZ_ASSERT(aEncodedFrame);

  uint64_t timestamp = aEncodedFrame->TimeStamp();

  RefPtr<EncodePromise::Private> promise;
  if (!mPendingEncodes.Remove(timestamp, getter_AddRefs(promise))) {
    GMP_LOG_WARNING(
        "[%p] GMPVideoEncoder::Encoded -- no frame matching timestamp %" PRIu64,
        this, timestamp);
    return;
  }

  uint8_t* encodedData = aEncodedFrame->Buffer();
  uint32_t encodedSize = aEncodedFrame->Size();

  if (NS_WARN_IF(encodedSize == 0) || NS_WARN_IF(!encodedData) ||
      NS_WARN_IF(aEncodedFrame->BufferType() != GMP_BufferLength32)) {
    GMP_LOG_ERROR("[%p] GMPVideoEncoder::Encoded -- bad/empty frame", this);
    promise->Reject(NS_ERROR_DOM_MEDIA_FATAL_ERR, __func__);
    Teardown(MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR, "Bad/empty frame"_ns),
             __func__);
    return;
  }

  // This code was copied from WebrtcGmpVideoEncoder::Encoded in order to
  // massage/correct issues with OpenH264 and WebRTC. This allows us to use the
  // PlatformEncoderModule framework with WebRTC, fallback to this encoder and
  // actually render the video.
  if (NS_WARN_IF(!AdjustOpenH264NALUSequence(aEncodedFrame))) {
    promise->Reject(NS_ERROR_DOM_MEDIA_FATAL_ERR, __func__);
    Teardown(MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR, "Bad frame data"_ns),
             __func__);
    return;
  }

  auto output = MakeRefPtr<MediaRawData>();

  UniquePtr<MediaRawDataWriter> writer(output->CreateWriter());
  if (NS_WARN_IF(!writer->SetSize(encodedSize))) {
    GMP_LOG_ERROR(
        "[%p] GMPVideoEncoder::Encoded -- failed to allocate %u buffer", this,
        encodedSize);
    promise->Reject(NS_ERROR_DOM_MEDIA_FATAL_ERR, __func__);
    Teardown(MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR, "Init writer failed"_ns),
             __func__);
    return;
  }

  memcpy(writer->Data(), encodedData, encodedSize);

  output->mTime =
      media::TimeUnit::FromMicroseconds(static_cast<int64_t>(timestamp));
  output->mKeyframe = aEncodedFrame->FrameType() == kGMPKeyFrame;

  int32_t maybeTemporalLayerId = aEncodedFrame->GetTemporalLayerId();
  auto temporalLayerId = CheckedUint8(maybeTemporalLayerId);
  if (temporalLayerId.isValid()) {
    output->mTemporalLayerId = Some(temporalLayerId.value());
  }

  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::Encoded -- %sframe @ timestamp %" PRIu64
                ", temporal layer %d",
                this, output->mKeyframe ? "key" : "", timestamp,
                maybeTemporalLayerId);

  if (mConfig.mCodecSpecific.is<H264Specific>()) {
    const H264Specific& specific = mConfig.mCodecSpecific.as<H264Specific>();
    if (specific.mFormat == H264BitStreamFormat::AVC) {
      const uint8_t kExtraData[] = {
          1 /* version */,
          static_cast<uint8_t>(specific.mProfile),
          0 /* profile compat (0) */,
          static_cast<uint8_t>(specific.mLevel),
          0xfc | 3 /* nal size - 1 */,
          0xe0 /* num SPS (0) */,
          0 /* num PPS (0) */
      };

      auto extraData = MakeRefPtr<MediaByteBuffer>();
      extraData->AppendElements(kExtraData, std::size(kExtraData));

      if (NS_WARN_IF(!AnnexB::ConvertSampleToAVCC(output, extraData))) {
        GMP_LOG_ERROR(
            "[%p] GMPVideoEncoder::Encoded -- failed to convert to AVCC", this);
        promise->Reject(NS_ERROR_DOM_MEDIA_FATAL_ERR, __func__);
        Teardown(
            MediaResult(NS_ERROR_DOM_MEDIA_FATAL_ERR, "Convert AVCC failed"_ns),
            __func__);
        return;
      }
    }
  }

  EncodedData encodedDataSet(1);
  encodedDataSet.AppendElement(std::move(output));
  promise->Resolve(std::move(encodedDataSet), __func__);

  if (mPendingEncodes.IsEmpty()) {
    mDrainPromise.ResolveIfExists(EncodedData(), __func__);
  }
}

void GMPVideoEncoder::Teardown(const MediaResult& aResult,
                               StaticString aCallSite) {
  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::Teardown", this);
  MOZ_ASSERT(IsOnGMPThread());

  // Ensure we are kept alive at least until we return.
  RefPtr<GMPVideoEncoder> self(this);

  PendingEncodePromises pendingEncodes = std::move(mPendingEncodes);
  for (auto i = pendingEncodes.Iter(); !i.Done(); i.Next()) {
    i.Data()->Reject(aResult, aCallSite);
  }

  mInitPromise.RejectIfExists(aResult, aCallSite);
  mDrainPromise.RejectIfExists(aResult, aCallSite);

  if (mGMP) {
    mGMP->Close();
    mGMP = nullptr;
  }

  mHost = nullptr;
}

void GMPVideoEncoder::Error(GMPErr aError) {
  GMP_LOG_ERROR("[%p] GMPVideoEncoder::Error -- GMPErr(%u)", this,
                uint32_t(aError));
  MOZ_ASSERT(IsOnGMPThread());
  Teardown(ToMediaResult(aError, "Error GMP callback"_ns), __func__);
}

void GMPVideoEncoder::Terminated() {
  GMP_LOG_DEBUG("[%p] GMPVideoEncoder::Terminated", this);
  MOZ_ASSERT(IsOnGMPThread());
  Teardown(
      MediaResult(NS_ERROR_DOM_MEDIA_ABORT_ERR, "Terminated GMP callback"_ns),
      __func__);
}

}  // namespace mozilla
