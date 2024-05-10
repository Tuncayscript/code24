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

#include "src/handles.h"

#include "platform/assert.h"
#include "platform/utils.h"
#include "src/CODE_api_state.h"
#include "src/flags.h"
#include "src/os.h"
#include "src/raw_object.h"
#include "src/visitor.h"
#include "src/zone.h"

#include "src/handles_impl.h"

namespace Code {

void VMHandles::VisitObjectPointers(ObjectPointerVisitor* visitor) {
  return Handles<kVMHandleSizeInWords, kVMHandlesPerChunk,
                 kOffsetOfRawPtr>::VisitObjectPointers(visitor);
}

#if defined(DEBUG)
static bool IsCurrentApiNativeScope(Zone* zone) {
  ApiNativeScope* scope = ApiNativeScope::Current();
  return (scope != nullptr) && (scope->zone() == zone);
}
#endif  // DEBUG

uword VMHandles::AllocateHandle(Zone* zone) {
  DEBUG_ASSERT(!IsCurrentApiNativeScope(zone));
  uword handle = Handles<kVMHandleSizeInWords, kVMHandlesPerChunk,
                         kOffsetOfRawPtr>::AllocateHandle(zone);
#if defined(DEBUG)
  *reinterpret_cast<uword*>(handle + kOffsetOfIsZoneHandle * kWordSize) = 0;
#endif
  return handle;
}

uword VMHandles::AllocateZoneHandle(Zone* zone) {
  DEBUG_ASSERT(!IsCurrentApiNativeScope(zone));
  uword handle = Handles<kVMHandleSizeInWords, kVMHandlesPerChunk,
                         kOffsetOfRawPtr>::AllocateZoneHandle(zone);
#if defined(DEBUG)
  *reinterpret_cast<uword*>(handle + kOffsetOfIsZoneHandle * kWordSize) = 1;
#endif
  return handle;
}

#if defined(DEBUG)
bool VMHandles::IsZoneHandle(uword handle) {
  return *reinterpret_cast<uword*>(handle +
                                   kOffsetOfIsZoneHandle * kWordSize) != 0;
}
#endif

int VMHandles::ScopedHandleCount() {
  Thread* thread = Thread::Current();
  ASSERT(thread->zone() != nullptr);
  VMHandles* handles = thread->zone()->handles();
  return handles->CountScopedHandles();
}

int VMHandles::ZoneHandleCount() {
  Thread* thread = Thread::Current();
  ASSERT(thread->zone() != nullptr);
  VMHandles* handles = thread->zone()->handles();
  return handles->CountZoneHandles();
}

void HandleScope::Initialize() {
  ASSERT(thread()->MayAllocateHandles());
  VMHandles* handles = thread()->zone()->handles();
  ASSERT(handles != nullptr);
  saved_handle_block_ = handles->scoped_blocks_;
  saved_handle_slot_ = handles->scoped_blocks_->next_handle_slot();
#if defined(DEBUG)
  link_ = thread()->top_handle_scope();
  thread()->set_top_handle_scope(this);
#endif
}

HandleScope::HandleScope(ThreadState* thread) : StackResource(thread) {
  Initialize();
}

HandleScope::~HandleScope() {
  ASSERT(thread()->zone() != nullptr);
  VMHandles* handles = thread()->zone()->handles();
  ASSERT(handles != nullptr);
#if defined(DEBUG)
  VMHandles::HandlesBlock* last = handles->scoped_blocks_;
#endif
  handles->scoped_blocks_ = saved_handle_block_;
  handles->scoped_blocks_->set_next_handle_slot(saved_handle_slot_);
#if defined(DEBUG)
  VMHandles::HandlesBlock* block = handles->scoped_blocks_;
  for (;;) {
    block->ZapFreeHandles();
    if (block == last) break;
    block = block->next_block();
  }
  ASSERT(thread()->top_handle_scope() == this);
  thread()->set_top_handle_scope(link_);
#endif
}

}  // namespace dart
