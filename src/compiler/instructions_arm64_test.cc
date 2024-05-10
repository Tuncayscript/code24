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

#include "src/globals.h"
#if defined(TARGET_ARCH_ARM64)

#include "src/compiler/assembler/assembler.h"
#include "src/cpu.h"
#include "src/instructions.h"
#include "src/stub_code.h"
#include "src/unit_test.h"

namespace Code {

#define __ assembler->

ASSEMBLER_TEST_GENERATE(Call, assembler) {
  // Code is generated, but not executed. Just parsed with CallPattern
  __ set_constant_pool_allowed(true);  // Uninitialized pp is OK.
  SPILLS_LR_TO_FRAME({});              // Clobbered LR is OK.
  __ BranchLinkPatchable(StubCode::InvokeDartCode());
  RESTORES_LR_FROM_FRAME({});  // Clobbered LR is OK.
  __ ret();
}

ASSEMBLER_TEST_RUN(Call, test) {
  // The return address, which must be the address of an instruction contained
  // in the code, points to the Ret instruction above, i.e. one instruction
  // before the end of the code buffer.
  uword end = test->payload_start() + test->code().Size();
  CallPattern call(end - Instr::kInstrSize, test->code());
  EXPECT_EQ(StubCode::InvokeDartCode().ptr(), call.TargetCode());
}

}  // namespace dart

#endif  // defined TARGET_ARCH_ARM64
