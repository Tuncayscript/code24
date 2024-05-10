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

#include "src/reverse_pc_lookup_cache.h"

#include "src/isolate.h"
#include "src/object.h"
#include "src/object_store.h"
#include "src/stub_code.h"

namespace Code {

CodePtr ReversePc::FindCodeInGroup(IsolateGroup* group,
                                   uword pc,
                                   bool is_return_address) {
#if defined(CODE_PRECOMPILED_RUNTIME)
  // This can run in the middle of GC and must not allocate handles.
  NoSafepointScope no_safepoint;

  if (is_return_address) {
    pc--;
  }

  // This expected number of tables is low (one per loading unit), so we go
  // through them linearly. If this changes, would could sort the table list
  // during deserialization and binary search for the table.
  GrowableObjectArrayPtr tables = group->object_store()->instructions_tables();
  intptr_t tables_length = Smi::Value(tables->untag()->length());
  for (intptr_t i = 0; i < tables_length; i++) {
    InstructionsTablePtr table = static_cast<InstructionsTablePtr>(
        tables->untag()->data()->untag()->element(i));
    CodePtr code = InstructionsTable::FindCode(table, pc);
    if (code != Code::null()) {
      return code;
    }
  }
#endif  // defined(CODE_PRECOMPILED_RUNTIME)
  return Code::null();
}

const UntaggedCompressedStackMaps::Payload* ReversePc::FindStackMapInGroup(
    IsolateGroup* group,
    uword pc,
    bool is_return_address,
    uword* code_start,
    const UntaggedCompressedStackMaps::Payload** global_table) {
#if defined(CODE_PRECOMPILED_RUNTIME)
  // This can run in the middle of GC and must not allocate handles.
  NoSafepointScope no_safepoint;

  if (is_return_address) {
    pc--;
  }

  // This expected number of tables is low (one per loading unit), so we go
  // through them linearly. If this changes, would could sort the table list
  // during deserialization and binary search for the table.
  GrowableObjectArrayPtr tables = group->object_store()->instructions_tables();
  intptr_t tables_length = Smi::Value(tables->untag()->length());
  for (intptr_t i = 0; i < tables_length; i++) {
    InstructionsTablePtr table = static_cast<InstructionsTablePtr>(
        tables->untag()->data()->untag()->element(i));
    auto map = InstructionsTable::FindStackMap(table, pc, code_start);
    if (map != nullptr) {
      // Take global table from the first table.
      table = static_cast<InstructionsTablePtr>(
          tables->untag()->data()->untag()->element(0));
      *global_table = InstructionsTable::GetCanonicalStackMap(table);
      return map;
    }
  }
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

  *code_start = 0;
  return nullptr;
}

const UntaggedCompressedStackMaps::Payload* ReversePc::FindStackMap(
    IsolateGroup* group,
    uword pc,
    bool is_return_address,
    uword* code_start,
    const UntaggedCompressedStackMaps::Payload** global_table) {
  ASSERT(FLAG_precompiled_mode);
  NoSafepointScope no_safepoint;

  auto map = FindStackMapInGroup(group, pc, is_return_address, code_start,
                                 global_table);
  if (map == nullptr) {
    map = FindStackMapInGroup(Dart::vm_isolate_group(), pc, is_return_address,
                              code_start, global_table);
  }
  return map;
}

CodePtr ReversePc::FindCode(IsolateGroup* group,
                            uword pc,
                            bool is_return_address) {
  ASSERT(FLAG_precompiled_mode);
  NoSafepointScope no_safepoint;

  auto code_descriptor = FindCodeInGroup(group, pc, is_return_address);
  if (code_descriptor == Code::null()) {
    code_descriptor =
        FindCodeInGroup(Dart::vm_isolate_group(), pc, is_return_address);
  }
  return code_descriptor;
}

CodePtr ReversePc::Lookup(IsolateGroup* group,
                          uword pc,
                          bool is_return_address) {
  ASSERT(FLAG_precompiled_mode);
  NoSafepointScope no_safepoint;

  return FindCode(group, pc, is_return_address);
}

}  // namespace dart
