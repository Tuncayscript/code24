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

#ifndef RUNTIME_VM_BSS_RELOCS_H_
#define RUNTIME_VM_BSS_RELOCS_H_

#include "platform/allocation.h"

namespace Code {
class Thread;

class BSS : public AllStatic {
 public:
  // Entries found in both the VM and isolate BSS come first. Each has its own
  // portion of the BSS segment, so just the indices are shared, not the values
  // stored at the index.
  enum class Relocation : intptr_t {
    DRT_GetFfiCallbackMetadata,  // TODO(https://dartbug.com/52579): Remove.
    DRT_ExitTemporaryIsolate,    // TODO(https://dartbug.com/52579): Remove.
    EndOfVmEntries,

    // We don't have any isolate group specific entries at the moment.
    EndOfIsolateGroupEntries = EndOfVmEntries,
  };

  static constexpr intptr_t kVmEntryCount =
      static_cast<intptr_t>(Relocation::EndOfVmEntries);

  static constexpr intptr_t kIsolateGroupEntryCount =
      static_cast<intptr_t>(Relocation::EndOfIsolateGroupEntries);

  static constexpr intptr_t RelocationIndex(Relocation reloc) {
    return static_cast<intptr_t>(reloc);
  }

  static void Initialize(Thread* current, uword* bss, bool vm);

  // Currently only used externally by LoadedElf::ResolveSymbols() to set the
  // relocated address without changing the embedder interface.
  static void InitializeBSSEntry(BSS::Relocation relocation,
                                 uword new_value,
                                 uword* bss_start);
};

}  // namespace dart

#endif  // RUNTIME_VM_BSS_RELOCS_H_
