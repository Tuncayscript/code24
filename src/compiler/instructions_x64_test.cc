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
#if defined(TARGET_ARCH_X64)

#include "src/compiler/assembler/assembler.h"
#include "src/instructions.h"
#include "src/stub_code.h"
#include "src/unit_test.h"

namespace Code {

#define __ assembler->

ASSEMBLER_TEST_GENERATE(Call, assembler) {
  __ Call(StubCode::InvokeDartCode());
  __ ret();
}

static intptr_t prologue_code_size = -1;

ASSEMBLER_TEST_GENERATE(Jump, assembler) {
  ASSERT(assembler->CodeSize() == 0);
  __ pushq(PP);
  __ LoadPoolPointer();
  prologue_code_size = assembler->CodeSize();
  __ JmpPatchable(StubCode::InvokeDartCode(), PP);
  __ JmpPatchable(StubCode::AllocateArray(), PP);
  __ popq(PP);
  __ ret();
}

}  // namespace dart

#endif  // defined TARGET_ARCH_X64
