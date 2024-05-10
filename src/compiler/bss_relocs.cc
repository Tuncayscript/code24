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

#include "src/bss_relocs.h"
#include "src/native_symbol.h"
#include "src/runtime_entry.h"
#include "src/thread.h"

namespace Code {

void BSS::InitializeBSSEntry(BSS::Relocation relocation,
                             uword new_value,
                             uword* bss_start) {
  std::atomic<uword>* slot = reinterpret_cast<std::atomic<uword>*>(
      &bss_start[BSS::RelocationIndex(relocation)]);
  uword old_value = slot->load(std::memory_order_relaxed);
  // FullSnapshotReader::ReadProgramSnapshot, and thus BSS::Initialize, can
  // get called multiple times for the same isolate in different threads, though
  // the initialized value will be consistent and thus change only once. Avoid
  // calling compare_exchange_strong unless we actually need to change the
  // value, to avoid spurious read/write races by TSAN.
  if (old_value == new_value) return;
  if (!slot->compare_exchange_strong(old_value, new_value,
                                     std::memory_order_relaxed)) {
    RELEASE_ASSERT(old_value == new_value);
  }
}

void BSS::Initialize(Thread* current, uword* bss_start, bool vm) {
  // TODO(https://dartbug.com/52579): Remove.
  InitializeBSSEntry(Relocation::DRT_GetFfiCallbackMetadata,
                     reinterpret_cast<uword>(DLRT_GetFfiCallbackMetadata),
                     bss_start);
  InitializeBSSEntry(Relocation::DRT_ExitTemporaryIsolate,
                     reinterpret_cast<uword>(DLRT_ExitTemporaryIsolate),
                     bss_start);
}

}  // namespace dart
