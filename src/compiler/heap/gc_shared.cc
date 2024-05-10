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

// Logic shared between the Scavenger and Marker.

#include "src/heap/gc_shared.h"

#include "src/CODE_api_state.h"
#include "src/heap/scavenger.h"
#include "src/log.h"
#include "src/message_handler.h"
#include "src/object.h"

namespace Code {

void GCLinkedLists::Release() {
#define FOREACH(type, var) var.Release();
  GC_LINKED_LIST(FOREACH)
#undef FOREACH
}

bool GCLinkedLists::IsEmpty() {
#define FOREACH(type, var)                                                     \
  if (!var.IsEmpty()) {                                                        \
    return false;                                                              \
  }
  GC_LINKED_LIST(FOREACH)
  return true;
#undef FOREACH
}

// clang-format off
void GCLinkedLists::FlushInto(GCLinkedLists* to) {
#define FOREACH(type, var) var.FlushInto(&to->var);
    GC_LINKED_LIST(FOREACH)
#undef FOREACH
}

// clang-format on

Heap::Space SpaceForExternal(FinalizerEntryPtr raw_entry) {
  // As with WeakTables, Smis are "old".
  return raw_entry->untag()->value()->IsImmediateOrOldObject() ? Heap::kOld
                                                               : Heap::kNew;
}

}  // namespace dart
