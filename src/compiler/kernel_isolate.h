/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#ifndef RUNTIME_VM_KERNEL_ISOLATE_H_
#define RUNTIME_VM_KERNEL_ISOLATE_H_

#include <vector>

#include "include/code_api.h"
#include "include/code_native_api.h"

#include "src/allocation.h"
#include "src/dart.h"
#include "src/experimental_features.h"
#include "src/os_thread.h"

namespace Code {

// TODO(33433): The kernel service does not belong in the VM.

class KernelIsolate : public AllStatic {
#if !defined(CODE_PRECOMPILED_RUNTIME)

 public:
  static const char* kName;

  // Tags used to indicate different requests to the dart frontend.
  //
  // Current tags include the following:
  //   0 - Perform normal compilation.
  //   1 - Update in-memory file system with in-memory sources (used by tests).
  //   2 - Accept last compilation result.
  //   3 - APP JIT snapshot training run for kernel_service.
  //   4 - Compile expressions in context (used by expression evaluation).
  //   5 - Generate dependencies used to create a dependencies file.
  //   6 - Triggers shutdown of the kernel isolate.
  //   7 - Reject last compilation result.
  static constexpr int kCompileTag = 0;
  static constexpr int kUpdateSourcesTag = 1;
  static constexpr int kAcceptTag = 2;
  static constexpr int kTrainTag = 3;
  static constexpr int kCompileExpressionTag = 4;
  static constexpr int kListDependenciesTag = 5;
  static constexpr int kNotifyIsolateShutdown = 6;
  static constexpr int kRejectTag = 7;

  static void InitializeState();
  static bool Start();
  static void Shutdown();

  static bool Exists();
  static bool IsRunning();
  static CODE_Port WaitForKernelPort();
  static CODE_Port KernelPort() { return kernel_port_; }

  static CODE_KernelCompilationResult CompileToKernel(
      const char* script_uri,
      const uint8_t* platform_kernel,
      intptr_t platform_kernel_size,
      int source_files_count = 0,
      CODE_SourceFile source_files[] = nullptr,
      bool incremental_compile = true,
      bool for_snapshot = false,
      bool embed_sources = true,
      const char* package_config = nullptr,
      const char* multiroot_filepaths = nullptr,
      const char* multiroot_scheme = nullptr,
      CODE_KernelCompilationVerbosityLevel verbosity =
          CODE_KernelCompilationVerbosityLevel_All);

  static CODE_KernelCompilationResult AcceptCompilation();
  static CODE_KernelCompilationResult RejectCompilation();
  static CODE_KernelCompilationResult UpdateInMemorySources(
      int source_files_count,
      CODE_SourceFile source_files[]);

  static CODE_KernelCompilationResult CompileExpressionToKernel(
      const uint8_t* platform_kernel,
      intptr_t platform_kernel_size,
      const char* expression,
      const Array& definitions,
      const Array& definition_types,
      const Array& type_definitions,
      const Array& type_bounds,
      const Array& type_defaults,
      const char* library_url,
      const char* klass,
      const char* method,
      TokenPosition token_pos,
      char const* script_uri,
      bool is_static);

  static CODE_KernelCompilationResult ListDependencies();

  static void NotifyAboutIsolateGroupShutdown(
      const IsolateGroup* isolate_group);

  static void AddExperimentalFlag(const char* value);
  static bool GetExperimentalFlag(ExperimentalFeature feature);

 protected:
  static void InitCallback(Isolate* I);
  static void SetKernelIsolate(Isolate* isolate);
  static void SetLoadPort(CODE_Port port);
  static void FinishedExiting();
  static void FinishedInitializing();
  static void InitializingFailed();
  static CODE_IsolateGroupCreateCallback create_group_callback() {
    return create_group_callback_;
  }

  static CODE_IsolateGroupCreateCallback create_group_callback_;
  static Monitor* monitor_;
  enum State{
      kNotStarted, kStopped, kStarting, kStarted, kStopping,
  };
  static State state_;
  static Isolate* isolate_;
  static CODE_Port kernel_port_;

  static MallocGrowableArray<char*>* experimental_flags_;
#else

 public:
  static bool IsRunning() { return false; }
  static void Shutdown() {}
  static void NotifyAboutIsolateGroupShutdown(
      const IsolateGroup* isolate_group) {}
  static bool GetExperimentalFlag(const char* value) { return false; }

 protected:
  static void SetKernelIsolate(Isolate* isolate) { UNREACHABLE(); }

#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

  friend class Dart;
  friend class Isolate;
  friend class RunKernelTask;
};

}  // namespace dart

#endif  // RUNTIME_VM_KERNEL_ISOLATE_H_
