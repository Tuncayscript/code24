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

#include "src/code_patcher.h"
#include "src/cpu.h"
#include "src/instructions.h"
#include "src/object.h"
#include "src/virtual_memory.h"

namespace Code {

#if defined(CODE_HOST_OS_MACOS) || defined(CODE_HOST_OS_MACOS_IOS)
// On iOS even with debugger attached we must still guarantee that memory
// is never executable and writable at the same time. On Mac OS X
// com.apple.security.cs.allow-jit entitelement allows WX memory regions to be
// created - but we should not rely on this entitelement to be present.
static constexpr bool kShouldWriteProtectCodeByDefault = true;
#else
static constexpr bool kShouldWriteProtectCodeByDefault = false;
#endif

DEFINE_FLAG(bool,
            write_protect_code,
            kShouldWriteProtectCodeByDefault,
            "Write protect jitted code");

#if defined(TARGET_ARCH_IA32)
WritableInstructionsScope::WritableInstructionsScope(uword address,
                                                     intptr_t size)
    : address_(address), size_(size) {
  if (FLAG_write_protect_code) {
    VirtualMemory::Protect(reinterpret_cast<void*>(address), size,
                           VirtualMemory::kReadWrite);
  }
}

WritableInstructionsScope::~WritableInstructionsScope() {
  if (FLAG_write_protect_code) {
    VirtualMemory::Protect(reinterpret_cast<void*>(address_), size_,
                           VirtualMemory::kReadExecute);
  }
}
#endif  // defined(TARGET_ARCH_IA32)

bool MatchesPattern(uword end, const int16_t* pattern, intptr_t size) {
  // When breaking within generated code in GDB, it may overwrite individual
  // instructions with trap instructions, which can cause this test to fail.
  //
  // Ignoring trap instructions would work well enough within GDB alone, but it
  // doesn't work in RR, because the check for the trap instruction itself will
  // cause replay to diverge from the original record.
  if (FLAG_support_rr) return true;

  uint8_t* bytes = reinterpret_cast<uint8_t*>(end - size);
  for (intptr_t i = 0; i < size; i++) {
    int16_t val = pattern[i];
    if ((val >= 0) && (val != bytes[i])) {
      return false;
    }
  }
  return true;
}

}  // namespace dart
