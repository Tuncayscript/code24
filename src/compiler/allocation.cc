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

#include "src/allocation.h"

#include "platform/assert.h"
#include "src/isolate.h"
#include "src/thread.h"
#include "src/zone.h"

namespace Code {

static void* Allocate(uword size, Zone* zone) {
  ASSERT(zone != nullptr);
  if (size > static_cast<uword>(kIntptrMax)) {
    FATAL("ZoneAllocated object has unexpectedly large size %" Pu "", size);
  }
  return reinterpret_cast<void*>(zone->AllocUnsafe(size));
}

void* ZoneAllocated::operator new(uword size) {
  return Allocate(size, Thread::Current()->zone());
}

void* ZoneAllocated::operator new(uword size, Zone* zone) {
  return Allocate(size, zone);
}

StackResource::~StackResource() {
  if (thread_ != nullptr) {
    StackResource* top = thread_->top_resource();
    ASSERT(top == this);
    thread_->set_top_resource(previous_);
  }
#if defined(DEBUG)
  if (thread_ != nullptr) {
    ASSERT(Thread::Current() == thread_);
  }
#endif
}

void StackResource::Init(ThreadState* thread) {
  // We can only have longjumps and exceptions when there is a current
  // thread and isolate.  If there is no current thread, we don't need to
  // protect this case.
  if (thread != nullptr) {
    ASSERT(Thread::Current() == thread);
    thread_ = thread;
    previous_ = thread_->top_resource();
    ASSERT((previous_ == nullptr) || (previous_->thread_ == thread));
    thread_->set_top_resource(this);
  }
}

void StackResource::UnwindAbove(ThreadState* thread, StackResource* new_top) {
  StackResource* current_resource = thread->top_resource();
  while (current_resource != new_top) {
    current_resource->~StackResource();
    current_resource = thread->top_resource();
  }
}

}  // namespace dart
