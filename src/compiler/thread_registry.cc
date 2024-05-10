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

#include "src/thread_registry.h"

#include "src/json_stream.h"
#include "src/lockers.h"

namespace Code {

ThreadRegistry::~ThreadRegistry() {
  // Go over the free thread list and delete the thread objects.
  {
    MonitorLocker ml(threads_lock());
    // At this point the active list should be empty.
    ASSERT(active_list_ == nullptr);

    // Now delete all the threads in the free list.
    while (free_list_ != nullptr) {
      Thread* thread = free_list_;
      free_list_ = thread->next_;
      delete thread;
    }
  }
}

Thread* ThreadRegistry::GetFreeThreadLocked(bool is_vm_isolate) {
  ASSERT(threads_lock()->IsOwnedByCurrentThread());
  Thread* thread = GetFromFreelistLocked(is_vm_isolate);
  ASSERT(thread->api_top_scope() == nullptr);
  // Now add this Thread to the active list for the isolate.
  AddToActiveListLocked(thread);
  return thread;
}

void ThreadRegistry::ReturnThreadLocked(Thread* thread) {
  ASSERT(threads_lock()->IsOwnedByCurrentThread());
  // Remove thread from the active list for the isolate.
  RemoveFromActiveListLocked(thread);
  ReturnToFreelistLocked(thread);
}

void ThreadRegistry::VisitObjectPointers(
    IsolateGroup* isolate_group_of_interest,
    ObjectPointerVisitor* visitor,
    ValidationPolicy validate_frames) {
  MonitorLocker ml(threads_lock());
  Thread* thread = active_list_;
  while (thread != nullptr) {
    if (thread->isolate_group() == isolate_group_of_interest) {
      // The mutator thread is visited by the isolate itself (see
      // [IsolateGroup::VisitStackPointers]).
      if (!thread->IsDartMutatorThread()) {
        thread->VisitObjectPointers(visitor, validate_frames);
      }
    }
    thread = thread->next_;
  }
}

void ThreadRegistry::ForEachThread(
    std::function<void(Thread* thread)> callback) {
  MonitorLocker ml(threads_lock());
  Thread* thread = active_list_;
  while (thread != nullptr) {
    callback(thread);
    thread = thread->next_;
  }
}

void ThreadRegistry::ReleaseStoreBuffers() {
  MonitorLocker ml(threads_lock());
  Thread* thread = active_list_;
  while (thread != nullptr) {
    if (!thread->BypassSafepoints()) {
      thread->ReleaseStoreBuffer();
    }
    thread = thread->next_;
  }
}

void ThreadRegistry::AcquireMarkingStacks() {
  MonitorLocker ml(threads_lock());
  Thread* thread = active_list_;
  while (thread != nullptr) {
    if (!thread->BypassSafepoints()) {
      thread->MarkingStackAcquire();
      thread->DeferredMarkingStackAcquire();
    }
    thread = thread->next_;
  }
}

void ThreadRegistry::ReleaseMarkingStacks() {
  MonitorLocker ml(threads_lock());
  Thread* thread = active_list_;
  while (thread != nullptr) {
    if (!thread->BypassSafepoints()) {
      thread->MarkingStackRelease();
      thread->DeferredMarkingStackRelease();
      ASSERT(!thread->is_marking());
    }
    thread = thread->next_;
  }
}

void ThreadRegistry::FlushMarkingStacks() {
  MonitorLocker ml(threads_lock());
  Thread* thread = active_list_;
  while (thread != nullptr) {
    if (!thread->BypassSafepoints() && thread->is_marking()) {
      thread->MarkingStackFlush();
      thread->DeferredMarkingStackFlush();
      ASSERT(thread->is_marking());
    }
    thread = thread->next_;
  }
}

void ThreadRegistry::AddToActiveListLocked(Thread* thread) {
  ASSERT(thread != nullptr);
  ASSERT(threads_lock()->IsOwnedByCurrentThread());
  thread->next_ = active_list_;
  active_list_ = thread;
  active_isolates_count_.fetch_add(1);
}

void ThreadRegistry::RemoveFromActiveListLocked(Thread* thread) {
  ASSERT(thread != nullptr);
  ASSERT(threads_lock()->IsOwnedByCurrentThread());
  Thread* prev = nullptr;
  Thread* current = active_list_;
  while (current != nullptr) {
    if (current == thread) {
      if (prev == nullptr) {
        active_list_ = current->next_;
      } else {
        prev->next_ = current->next_;
      }
      active_isolates_count_.fetch_sub(1);
      break;
    }
    prev = current;
    current = current->next_;
  }
}

Thread* ThreadRegistry::GetFromFreelistLocked(bool is_vm_isolate) {
  ASSERT(threads_lock()->IsOwnedByCurrentThread());
  Thread* thread = nullptr;
  // Get thread structure from free list or create a new one.
  if (free_list_ == nullptr) {
    thread = new Thread(is_vm_isolate);
  } else {
    thread = free_list_;
    free_list_ = thread->next_;
  }
  return thread;
}

void ThreadRegistry::ReturnToFreelistLocked(Thread* thread) {
  ASSERT(thread != nullptr);
  ASSERT(thread->os_thread() == nullptr);
  ASSERT(thread->isolate_ == nullptr);
  ASSERT(thread->isolate_group_ == nullptr);
  ASSERT(thread->field_table_values_ == nullptr);
  ASSERT(threads_lock()->IsOwnedByCurrentThread());
  // Add thread to the free list.
  thread->next_ = free_list_;
  free_list_ = thread;
}

}  // namespace dart
