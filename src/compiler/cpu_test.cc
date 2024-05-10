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

#include "src/cpu.h"
#include "platform/assert.h"
#include "src/globals.h"
#include "src/unit_test.h"

namespace Code {

VM_UNIT_TEST_CASE(Id) {
#if defined(TARGET_ARCH_IA32)
  EXPECT_STREQ("ia32", CPU::Id());
#elif defined(TARGET_ARCH_X64)
  EXPECT_STREQ("x64", CPU::Id());
#elif defined(TARGET_ARCH_ARM)
#if defined(HOST_ARCH_ARM)
  EXPECT_STREQ("arm", CPU::Id());
#else   // defined(HOST_ARCH_ARM)
  EXPECT_STREQ("simarm", CPU::Id());
#endif  // defined(HOST_ARCH_ARM)
#elif defined(TARGET_ARCH_ARM64)
#if defined(HOST_ARCH_ARM64)
  EXPECT_STREQ("arm64", CPU::Id());
#else   // defined(HOST_ARCH_ARM64)
  EXPECT_STREQ("simarm64", CPU::Id());
#endif  // defined(HOST_ARCH_ARM64)
#elif defined(TARGET_ARCH_RISCV32)
#if defined(HOST_ARCH_RISCV32)
  EXPECT_STREQ("riscv32", CPU::Id());
#else   // defined(HOST_ARCH_RISCV32)
  EXPECT_STREQ("simriscv32", CPU::Id());
#endif  // defined(HOST_ARCH_RISCV32)
#elif defined(TARGET_ARCH_RISCV64)
#if defined(HOST_ARCH_RISCV64)
  EXPECT_STREQ("riscv64", CPU::Id());
#else   // defined(HOST_ARCH_RISCV64)
  EXPECT_STREQ("simriscv64", CPU::Id());
#endif  // defined(HOST_ARCH_RISCV64)
#else
#error Architecture was not detected as supported by Dart.
#endif
}

}  // namespace dart
