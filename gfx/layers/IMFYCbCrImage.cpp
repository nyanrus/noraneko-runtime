/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include "IMFYCbCrImage.h"
#include "mozilla/gfx/DeviceManagerDx.h"
#include "mozilla/gfx/gfxVars.h"
#include "mozilla/gfx/Types.h"
#include "mozilla/layers/TextureD3D11.h"
#include "mozilla/layers/CompositableClient.h"
#include "mozilla/layers/CompositableForwarder.h"
#include "mozilla/layers/D3D11YCbCrImage.h"
#include "mozilla/layers/FenceD3D11.h"
#include "mozilla/layers/CompositeProcessD3D11FencesHolderMap.h"
#include "mozilla/layers/TextureClient.h"

namespace mozilla {
namespace layers {

IMFYCbCrImage::IMFYCbCrImage(IMFMediaBuffer* aBuffer, IMF2DBuffer* a2DBuffer,
                             KnowsCompositor* aKnowsCompositor,
                             ImageContainer* aContainer)
    : RecyclingPlanarYCbCrImage(nullptr),
      mBuffer(aBuffer),
      m2DBuffer(a2DBuffer) {
  mAllocator = aContainer->GetD3D11YCbCrRecycleAllocator(aKnowsCompositor);
}

IMFYCbCrImage::~IMFYCbCrImage() {
  if (m2DBuffer) {
    m2DBuffer->Unlock2D();
  } else {
    mBuffer->Unlock();
  }
}

/* static */
bool IMFYCbCrImage::CopyDataToTexture(const Data& aData, ID3D11Device* aDevice,
                                      DXGIYCbCrTextureData* aTextureData) {
  MOZ_ASSERT(aTextureData);

  if (!gfx::DeviceManagerDx::Get()->CanInitializeKeyedMutexTextures()) {
    return false;
  }

  ID3D11Texture2D* textureY = aTextureData->GetD3D11Texture(0);
  ID3D11Texture2D* textureCb = aTextureData->GetD3D11Texture(1);
  ID3D11Texture2D* textureCr = aTextureData->GetD3D11Texture(2);

  RefPtr<ID3D11DeviceContext> ctx;
  aDevice->GetImmediateContext(getter_AddRefs(ctx));
  if (!ctx) {
    gfxCriticalError() << "Failed to get immediate context.";
    return false;
  }

  D3D11_BOX box;
  box.front = box.top = box.left = 0;
  box.back = 1;
  box.right = aData.YDataSize().width;
  box.bottom = aData.YDataSize().height;
  ctx->UpdateSubresource(textureY, 0, &box, aData.mYChannel, aData.mYStride, 0);

  box.right = aData.CbCrDataSize().width;
  box.bottom = aData.CbCrDataSize().height;
  ctx->UpdateSubresource(textureCb, 0, &box, aData.mCbChannel,
                         aData.mCbCrStride, 0);
  ctx->UpdateSubresource(textureCr, 0, &box, aData.mCrChannel,
                         aData.mCbCrStride, 0);

  auto* fenceHolderMap = CompositeProcessD3D11FencesHolderMap::Get();
  if (!fenceHolderMap) {
    MOZ_ASSERT_UNREACHABLE("unexpected to be called");
    return false;
  }

  aTextureData->mWriteFence->IncrementAndSignal();
  fenceHolderMap->SetWriteFence(aTextureData->mFencesHolderId,
                                aTextureData->mWriteFence);

  return true;
}

TextureClient* IMFYCbCrImage::GetD3D11TextureClient(
    KnowsCompositor* aKnowsCompositor) {
  if (!mAllocator) {
    return nullptr;
  }

  auto* fenceHolderMap = CompositeProcessD3D11FencesHolderMap::Get();
  if (!fenceHolderMap) {
    MOZ_ASSERT_UNREACHABLE("unexpected to be called");
    return nullptr;
  }

  RefPtr<ID3D11Device> device = gfx::DeviceManagerDx::Get()->GetImageDevice();
  if (!device) {
    return nullptr;
  }

  {
    DXGIYCbCrTextureAllocationHelper helper(mData, TextureFlags::DEFAULT,
                                            device);
    mTextureClient = mAllocator->CreateOrRecycle(helper).unwrapOr(nullptr);
  }

  if (!mTextureClient) {
    return nullptr;
  }

  DXGIYCbCrTextureData* data =
      mTextureClient->GetInternalData()->AsDXGIYCbCrTextureData();

  if (!fenceHolderMap->WaitAllFencesAndForget(data->mFencesHolderId, device)) {
    return nullptr;
  }

  if (!CopyDataToTexture(mData, device, data)) {
    // Failed to copy data
    mTextureClient = nullptr;
    return nullptr;
  }

  return mTextureClient;
}

TextureClient* IMFYCbCrImage::GetTextureClient(
    KnowsCompositor* aKnowsCompositor) {
  if (mTextureClient) {
    return mTextureClient;
  }

  RefPtr<ID3D11Device> device = gfx::DeviceManagerDx::Get()->GetImageDevice();
  if (!device || !aKnowsCompositor->SupportsD3D11()) {
    return nullptr;
  }
  return GetD3D11TextureClient(aKnowsCompositor);
}

}  // namespace layers
}  // namespace mozilla
