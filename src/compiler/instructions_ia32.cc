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

#include "src/globals.h"  // Needed here to get TARGET_ARCH_IA32.
#if defined(TARGET_ARCH_IA32)

#include "src/instructions.h"
#include "src/instructions_ia32.h"

#include "src/cpu.h"
#include "src/object.h"

namespace Code {

bool DecodeLoadObjectFromPoolOrThread(uword pc, const Code& code, Object* obj) {
  ASSERT(code.ContainsInstructionAt(pc));
  return false;
}

}  // namespace dart

#endif  // defined TARGET_ARCH_IA32
