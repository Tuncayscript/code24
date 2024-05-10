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

#include "src/heap/verifier.h"

#include "platform/assert.h"
#include "src/dart.h"
#include "src/CODE_api_state.h"
#include "src/heap/heap.h"
#include "src/isolate.h"
#include "src/object.h"
#include "src/object_set.h"
#include "src/raw_object.h"
#include "src/stack_frame.h"

namespace Code {

void VerifyObjectVisitor::VisitObject(ObjectPtr obj) {
  ASSERT(obj->IsHeapObject());
  uword addr = UntaggedObject::ToAddr(obj);
  if (obj->IsFreeListElement() || obj->IsForwardingCorpse()) {
    if (obj->IsOldObject() && obj->untag()->IsMarked()) {
      FATAL("Marked free list element encountered %#" Px "\n", addr);
    }
  } else {
    switch (mark_expectation_) {
      case kForbidMarked:
        if (obj->IsOldObject() && obj->untag()->IsMarked()) {
          FATAL("Marked object encountered %#" Px "\n", addr);
        }
        break;
      case kAllowMarked:
        break;
      case kRequireMarked:
        if (obj->IsOldObject() && !obj->untag()->IsMarked()) {
          FATAL("Unmarked object encountered %#" Px "\n", addr);
        }
        break;
    }
    allocated_set_->Add(obj);
  }
  obj->Validate(isolate_group_);
}

void VerifyPointersVisitor::VisitPointers(ObjectPtr* from, ObjectPtr* to) {
  for (ObjectPtr* ptr = from; ptr <= to; ptr++) {
    ObjectPtr obj = *ptr;
    if (obj->IsHeapObject()) {
      if (!allocated_set_->Contains(obj)) {
        FATAL("%s: Invalid pointer: *0x%" Px " = 0x%" Px "\n", msg_,
              reinterpret_cast<uword>(ptr), static_cast<uword>(obj));
      }
    }
  }
}

#if defined(CODE_COMPRESSED_POINTERS)
void VerifyPointersVisitor::VisitCompressedPointers(uword heap_base,
                                                    CompressedObjectPtr* from,
                                                    CompressedObjectPtr* to) {
  for (CompressedObjectPtr* ptr = from; ptr <= to; ptr++) {
    ObjectPtr obj = ptr->Decompress(heap_base);
    if (obj->IsHeapObject()) {
      if (!allocated_set_->Contains(obj)) {
        FATAL("%s: Invalid pointer: *0x%" Px " = 0x%" Px "\n", msg_,
              reinterpret_cast<uword>(ptr), static_cast<uword>(obj));
      }
    }
  }
}
#endif

void VerifyWeakPointersVisitor::VisitHandle(uword addr) {
  FinalizablePersistentHandle* handle =
      reinterpret_cast<FinalizablePersistentHandle*>(addr);
  ObjectPtr raw_obj = handle->ptr();
  visitor_->VisitPointer(&raw_obj);
}

void VerifyPointersVisitor::VerifyPointers(const char* msg,
                                           MarkExpectation mark_expectation) {
  Thread* thread = Thread::Current();
  auto isolate_group = thread->isolate_group();
  HeapIterationScope iteration(thread);
  StackZone stack_zone(thread);
  ObjectSet* allocated_set = isolate_group->heap()->CreateAllocatedObjectSet(
      stack_zone.GetZone(), mark_expectation);

  VerifyPointersVisitor visitor(isolate_group, allocated_set, msg);
  // Visit all strongly reachable objects.
  iteration.IterateObjectPointers(&visitor, ValidationPolicy::kValidateFrames);
  VerifyWeakPointersVisitor weak_visitor(&visitor);

  // Visit weak handles and prologue weak handles.
  isolate_group->VisitWeakPersistentHandles(&weak_visitor);
}

}  // namespace dart
