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
#if defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)

#include "src/runtime_entry.h"

#include "src/simulator.h"
#include "src/stub_code.h"

#if !defined(CODE_PRECOMPILED_RUNTIME)
#include "src/compiler/assembler/assembler.h"
#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

namespace Code {

#define __ assembler->

uword RuntimeEntry::GetEntryPoint() const {
  // Compute the effective address. When running under the simulator,
  // this is a redirection address that forces the simulator to call
  // into the runtime system.
  uword entry = reinterpret_cast<uword>(function());
#if defined(USING_SIMULATOR)
  // Redirection to leaf runtime calls supports a maximum of 4 arguments passed
  // in registers (maximum 2 double arguments for leaf float runtime calls).
  ASSERT(argument_count() >= 0);
  ASSERT(!is_leaf() || (!is_float() && (argument_count() <= 4)) ||
         (argument_count() <= 2));
  Simulator::CallKind call_kind =
      is_leaf() ? (is_float() ? Simulator::kLeafFloatRuntimeCall
                              : Simulator::kLeafRuntimeCall)
                : Simulator::kRuntimeCall;
  entry =
      Simulator::RedirectExternalReference(entry, call_kind, argument_count());
#endif
  return entry;
}

}  // namespace dart

#endif  // defined TARGET_ARCH_RISCV
