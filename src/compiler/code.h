// Copyright (c) 2011, the Dart project authors.  Please see the AUTHORS file
// for details. All rights reserved. Use of this source code is governed by a
// BSD-style license that can be found in the LICENSE file.

#ifndef RUNTIME_VM_CODE_H_
#define RUNTIME_VM_CODE_H_

#include "include/CODE_api.h"
#include "include/CODE_tools_api.h"
#include "src/allocation.h"
#include "src/isolate.h"
#include "src/lockers.h"
#include "src/os_thread.h"
#include "src/snapshot.h"

namespace Code {

// Forward declarations.
class DebugInfo;
class Isolate;
class LocalHandle;
class ReadOnlyHandles;
class ThreadPool;
namespace kernel {
class Program;
}

class Dart : public AllStatic {
 public:
  // Returns null if initialization succeeds, otherwise returns an error message
  // (caller owns error message and has to free it).
  static char* Init(const CODE_InitializeParams* params);

  // Returns null if cleanup succeeds, otherwise returns an error message
  // (caller owns error message and has to free it).
  static char* Cleanup();

  // Returns true if the VM is initialized.
  static bool IsInitialized();

  // Used to Indicate that a Dart API call is active.
  static bool SetActiveApiCall();
  static void ResetActiveApiCall();

  static Isolate* CreateIsolate(const char* name_prefix,
                                const CODE_IsolateFlags& api_flags,
                                IsolateGroup* isolate_group);

  // Initialize an isolate group either from a snapshot or from a Kernel binary.
  static ErrorPtr InitializeIsolateGroup(Thread* T,
                                         const uint8_t* snapshot_data,
                                         const uint8_t* snapshot_instructions,
                                         const uint8_t* kernel_buffer,
                                         intptr_t kernel_buffer_size);
  static ErrorPtr InitIsolateGroupFromSnapshot(
      Thread* T,
      const uint8_t* snapshot_data,
      const uint8_t* snapshot_instructions,
      const uint8_t* kernel_buffer,
      intptr_t kernel_buffer_size);
  static ErrorPtr InitializeIsolate(Thread* T,
                                    bool is_first_isolate_in_group,
                                    void* isolate_data);

  static void RunShutdownCallback();
  static void ShutdownIsolate(Thread* T);

  static Isolate* vm_isolate() { return vm_isolate_; }
  static IsolateGroup* vm_isolate_group() {
    if (vm_isolate_ == nullptr) return nullptr;
    return vm_isolate_->group();
  }
  static ThreadPool* thread_pool() { return thread_pool_; }

  static int64_t UptimeMicros();
  static int64_t UptimeMillis() {
    return UptimeMicros() / kMicrosecondsPerMillisecond;
  }

  static void set_pprof_symbol_generator(DebugInfo* value) {
    pprof_symbol_generator_ = value;
  }
  static DebugInfo* pprof_symbol_generator() { return pprof_symbol_generator_; }

  static LocalHandle* AllocateReadOnlyApiHandle();
  static bool IsReadOnlyApiHandle(CODE_Handle handle);

  static uword AllocateReadOnlyHandle();
  static bool IsReadOnlyHandle(uword address);

  // The returned string has to be free()ed.
  static char* FeaturesString(IsolateGroup* isolate_group,
                              bool is_vm_snapshot,
                              Snapshot::Kind kind);
  static Snapshot::Kind vm_snapshot_kind() { return vm_snapshot_kind_; }

  static CODE_ThreadStartCallback thread_start_callback() {
    return thread_start_callback_;
  }
  static void set_thread_start_callback(CODE_ThreadStartCallback cback) {
    thread_start_callback_ = cback;
  }
  static CODE_ThreadExitCallback thread_exit_callback() {
    return thread_exit_callback_;
  }
  static void set_thread_exit_callback(CODE_ThreadExitCallback cback) {
    thread_exit_callback_ = cback;
  }
  static void SetFileCallbacks(CODE_FileOpenCallback file_open,
                               CODE_FileReadCallback file_read,
                               CODE_FileWriteCallback file_write,
                               CODE_FileCloseCallback file_close) {
    file_open_callback_ = file_open;
    file_read_callback_ = file_read;
    file_write_callback_ = file_write;
    file_close_callback_ = file_close;
  }

  static CODE_FileOpenCallback file_open_callback() {
    return file_open_callback_;
  }
  static CODE_FileReadCallback file_read_callback() {
    return file_read_callback_;
  }
  static CODE_FileWriteCallback file_write_callback() {
    return file_write_callback_;
  }
  static CODE_FileCloseCallback file_close_callback() {
    return file_close_callback_;
  }

  static void set_entropy_source_callback(CODE_EntropySource entropy_source) {
    entropy_source_callback_ = entropy_source;
  }
  static CODE_EntropySource entropy_source_callback() {
    return entropy_source_callback_;
  }

  static void set_dwarf_stacktrace_footnote_callback(
      CODE_DwarfStackTraceFootnoteCallback cb) {
    dwarf_stacktrace_footnote_callback_ = cb;
  }

  static CODE_DwarfStackTraceFootnoteCallback
  dwarf_stacktrace_footnote_callback() {
    return dwarf_stacktrace_footnote_callback_;
  }

 private:
  static char* DartInit(const CODE_InitializeParams* params);

  static constexpr const char* kVmIsolateName = "vm-isolate";

  static void WaitForIsolateShutdown();
  static void WaitForApplicationIsolateShutdown();

  static Isolate* vm_isolate_;
  static int64_t start_time_micros_;
  static ThreadPool* thread_pool_;
  static DebugInfo* pprof_symbol_generator_;
  static ReadOnlyHandles* predefined_handles_;
  static Snapshot::Kind vm_snapshot_kind_;
  static CODE_ThreadStartCallback thread_start_callback_;
  static CODE_ThreadExitCallback thread_exit_callback_;
  static CODE_FileOpenCallback file_open_callback_;
  static CODE_FileReadCallback file_read_callback_;
  static CODE_FileWriteCallback file_write_callback_;
  static CODE_FileCloseCallback file_close_callback_;
  static CODE_EntropySource entropy_source_callback_;
  static CODE_DwarfStackTraceFootnoteCallback
      dwarf_stacktrace_footnote_callback_;
};

}  // namespace dart

#endif  // RUNTIME_VM_CODE_H_
