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

#include "src/unwinding_records.h"
#include "src/globals.h"

namespace Code {

#if (!defined(CODE_TARGET_OS_WINDOWS) && !defined(CODE_HOST_OS_WINDOWS)) ||    \
    (!defined(TARGET_ARCH_X64) && !defined(TARGET_ARCH_ARM64))

const void* UnwindingRecords::GenerateRecordsInto(intptr_t offset,
                                                  uint8_t* target_buffer) {
  return nullptr;
}

#endif

#if !defined(CODE_HOST_OS_WINDOWS) ||                                          \
    (!defined(TARGET_ARCH_X64) && !defined(TARGET_ARCH_ARM64))

void UnwindingRecords::RegisterExecutablePage(Page* page) {}
void UnwindingRecords::UnregisterExecutablePage(Page* page) {}

#endif

}  // namespace dart
