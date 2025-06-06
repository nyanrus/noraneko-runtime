/* -*- Mode: C++; tab-width: 8; indent-tabs-mode: nil; c-basic-offset: 2 -*- */
/* vim: set ts=8 sts=2 et sw=2 tw=80: */
/* This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#ifndef mozilla_ipc_CrashReporterHost_h
#define mozilla_ipc_CrashReporterHost_h

#include <functional>

#include "mozilla/UniquePtr.h"
#include "base/process.h"
#include "nsExceptionHandler.h"
#include "nsIFile.h"
#include "nsThreadUtils.h"
#include "mozilla/ipc/GeckoChildProcessHost.h"
#include "mozilla/ipc/ProtocolUtils.h"

namespace CrashReporter {
class CrashReporterInitArgs;
}

namespace mozilla::ipc {

// This is the newer replacement for CrashReporterParent. It is created in
// response to a InitCrashReporter message on a top-level actor. When the
// process terminates abnormally, the top-level should call GenerateCrashReport
// to automatically integrate metadata.
class CrashReporterHost {
  typedef CrashReporter::AnnotationTable AnnotationTable;

 public:
  CrashReporterHost(GeckoProcessType aProcessType, base::ProcessId aPid,
                    const CrashReporter::CrashReporterInitArgs& aInitArgs);
  ~CrashReporterHost();

  // Helper function for generating a crash report for a process that probably
  // crashed (i.e., had an AbnormalShutdown in ActorDestroy). Returns true if
  // the process has a minidump attached and we were able to generate a report.
  bool GenerateCrashReport();

  // Given an existing minidump for a crashed child process, take ownership of
  // it from IPDL. After this, FinalizeCrashReport may be called.
  RefPtr<nsIFile> TakeCrashedChildMinidump();

  // Replace the stored minidump with a new one. After this,
  // FinalizeCrashReport may be called.
  bool AdoptMinidump(nsIFile* aFile, const AnnotationTable& aAnnotations);

  // If a minidump was already captured (e.g. via the hang reporter), this
  // finalizes the existing report by attaching metadata, writing out the
  // .extra file and notifying the crash service.
  void FinalizeCrashReport();

  // Delete any crash report we might have generated.
  void DeleteCrashReport();

  // Generate a paired minidump. This does not take the crash report, as
  // GenerateCrashReport does. After this, FinalizeCrashReport may be called.
  //
  // This calls TakeCrashedChildMinidump and FinalizeCrashReport.
  bool GenerateMinidumpAndPair(GeckoChildProcessHost* aChildProcessHost,
                               const nsACString& aPairName) {
    auto childHandle = base::kInvalidProcessHandle;
    const auto cleanup = MakeScopeExit([&]() {
      if (childHandle && childHandle != base::kInvalidProcessHandle) {
        base::CloseProcessHandle(childHandle);
      }
    });
#ifdef XP_MACOSX
    childHandle = aChildProcessHost->GetChildTask();
#else
    if (!base::OpenPrivilegedProcessHandle(
            aChildProcessHost->GetChildProcessId(), &childHandle)) {
      NS_WARNING("Failed to open child process handle.");
      return false;
    }
#endif

    nsCOMPtr<nsIFile> targetDump;
    if (!CrashReporter::CreateMinidumpsAndPair(childHandle, mThreadId,
                                               aPairName, mExtraAnnotations,
                                               getter_AddRefs(targetDump))) {
      return false;
    }

    return CrashReporter::GetIDFromMinidump(targetDump, mDumpID);
  }

  void AddAnnotationBool(CrashReporter::Annotation aKey, bool aValue);
  void AddAnnotationU32(CrashReporter::Annotation aKey, uint32_t aValue);
  void AddAnnotationNSCString(CrashReporter::Annotation aKey,
                              const nsACString& aValue);

  bool HasMinidump() const { return !mDumpID.IsEmpty(); }
  const nsString& MinidumpID() const {
    MOZ_ASSERT(HasMinidump());
    return mDumpID;
  }
  const nsCString& AdditionalMinidumps() const {
    return mExtraAnnotations[CrashReporter::Annotation::additional_minidumps];
  }

  // This is a static helper function to notify the crash service that a
  // crash has occurred and record the crash with telemetry. This can be called
  // from any thread, and if not called from the main thread, will post a
  // synchronous message to the main thread.
  static void RecordCrash(GeckoProcessType aProcessType, int32_t aCrashType,
                          const nsString& aChildDumpID);

 private:
  // Get the nsICrashService crash type to use for an impending crash.
  int32_t GetCrashType();

  static void RecordCrashWithTelemetry(GeckoProcessType aProcessType,
                                       int32_t aCrashType);
  static void NotifyCrashService(GeckoProcessType aProcessType,
                                 int32_t aCrashType,
                                 const nsString& aChildDumpID);

 private:
  GeckoProcessType mProcessType;
  base::ProcessId mPid;
  CrashReporter::ThreadId mThreadId;
  time_t mStartTime;
  AnnotationTable mExtraAnnotations;
  nsString mDumpID;
  bool mFinalized;
};

}  // namespace mozilla::ipc

#endif  // mozilla_ipc_CrashReporterHost_h
