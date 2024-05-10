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

#ifndef RUNTIME_VM_THREAD_REGISTRY_H_
#define RUNTIME_VM_THREAD_REGISTRY_H_

#include "src/globals.h"
#include "src/growable_array.h"
#include "src/isolate.h"
#include "src/lockers.h"
#include "src/stack_frame.h"
#include "src/thread.h"

namespace Code {

#ifndef PRODUCT
class JSONStream;
class JSONArray;
#endif

// Unordered collection of threads relating to a particular isolate group.
class ThreadRegistry {
 public:
  ThreadRegistry()
      : threads_lock_(),
        active_list_(nullptr),
        free_list_(nullptr),
        active_isolates_count_(0) {}
  ~ThreadRegistry();

  void VisitObjectPointers(IsolateGroup* isolate_group_of_interest,
                           ObjectPointerVisitor* visitor,
                           ValidationPolicy validate_frames);

  void ForEachThread(std::function<void(Thread* thread)> callback);
  void ReleaseStoreBuffers();
  void AcquireMarkingStacks();
  void ReleaseMarkingStacks();
  void FlushMarkingStacks();

  // Concurrent-approximate number of active isolates in the active_list
  intptr_t active_isolates_count() { return active_isolates_count_.load(); }

  Monitor* threads_lock() const { return &threads_lock_; }

#ifndef PRODUCT
  void PrintJSON(JSONStream* stream) const;
#endif

 private:
  Thread* active_list() const { return active_list_; }

  Thread* GetFreeThreadLocked(bool is_vm_isolate);
  void ReturnThreadLocked(Thread* thread);
  void AddToActiveListLocked(Thread* thread);
  void RemoveFromActiveListLocked(Thread* thread);
  Thread* GetFromFreelistLocked(bool is_vm_isolate);
  void ReturnToFreelistLocked(Thread* thread);

  // This monitor protects the threads list for an isolate, it is used whenever
  // we need to iterate over threads (both active and free) in an isolate.
  mutable Monitor threads_lock_;
  Thread* active_list_;  // List of active threads in the isolate.
  Thread* free_list_;    // Free list of Thread objects that can be reused.
  RelaxedAtomic<intptr_t> active_isolates_count_;

  friend class Thread;
  friend class SafepointHandler;
  DISALLOW_COPY_AND_ASSIGN(ThreadRegistry);
};

}  // namespace dart

#endif  // RUNTIME_VM_THREAD_REGISTRY_H_
