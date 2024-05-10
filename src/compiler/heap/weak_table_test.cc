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

#include "platform/globals.h"

#include "platform/assert.h"
#include "src/globals.h"
#include "src/heap/heap.h"
#include "src/heap/weak_table.h"
#include "src/unit_test.h"

namespace Code {

ISOLATE_UNIT_TEST_CASE(WeakTables) {
  const Object& old_obj = Object::Handle(String::New("old", Heap::kOld));
  const Object& new_obj = Object::Handle(String::New("new", Heap::kNew));
  const Object& imm_obj = Object::Handle(Smi::New(0));

  // Initially absent.
  Heap* heap = thread->heap();
  const intptr_t kNoValue = WeakTable::kNoValue;
  EXPECT_EQ(kNoValue, heap->GetObjectId(old_obj.ptr()));
  EXPECT_EQ(kNoValue, heap->GetObjectId(new_obj.ptr()));
  EXPECT_EQ(kNoValue, heap->GetObjectId(imm_obj.ptr()));

  // Found after insert.
  heap->SetObjectId(old_obj.ptr(), 100);
  heap->SetObjectId(new_obj.ptr(), 200);
  heap->SetObjectId(imm_obj.ptr(), 300);
  EXPECT_EQ(100, heap->GetObjectId(old_obj.ptr()));
  EXPECT_EQ(200, heap->GetObjectId(new_obj.ptr()));
  EXPECT_EQ(300, heap->GetObjectId(imm_obj.ptr()));

  // Found after update.
  heap->SetObjectId(old_obj.ptr(), 400);
  heap->SetObjectId(new_obj.ptr(), 500);
  heap->SetObjectId(imm_obj.ptr(), 600);
  EXPECT_EQ(400, heap->GetObjectId(old_obj.ptr()));
  EXPECT_EQ(500, heap->GetObjectId(new_obj.ptr()));
  EXPECT_EQ(600, heap->GetObjectId(imm_obj.ptr()));

  // Found after GC.
  GCTestHelper::CollectNewSpace();
  EXPECT_EQ(400, heap->GetObjectId(old_obj.ptr()));
  EXPECT_EQ(500, heap->GetObjectId(new_obj.ptr()));
  EXPECT_EQ(600, heap->GetObjectId(imm_obj.ptr()));

  // Found after GC.
  GCTestHelper::CollectOldSpace();
  EXPECT_EQ(400, heap->GetObjectId(old_obj.ptr()));
  EXPECT_EQ(500, heap->GetObjectId(new_obj.ptr()));
  EXPECT_EQ(600, heap->GetObjectId(imm_obj.ptr()));

  // Absent after reset.
  heap->ResetObjectIdTable();
  EXPECT_EQ(kNoValue, heap->GetObjectId(old_obj.ptr()));
  EXPECT_EQ(kNoValue, heap->GetObjectId(new_obj.ptr()));
  EXPECT_EQ(kNoValue, heap->GetObjectId(imm_obj.ptr()));
}

}  // namespace dart
