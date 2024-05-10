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

#ifndef RUNTIME_VM_CPU_H_
#define RUNTIME_VM_CPU_H_

#include "src/allocation.h"
#include "src/globals.h"

namespace Code {

// Forward Declarations.
class Error;
class Instance;

class CPU : public AllStatic {
 public:
  static void FlushICache(uword start, uword size);
  static const char* Id();
};

}  // namespace dart

#if defined(TARGET_ARCH_IA32)
#include "src/cpu_ia32.h"
#elif defined(TARGET_ARCH_X64)
#include "src/cpu_x64.h"
#elif defined(TARGET_ARCH_ARM)
#include "src/cpu_arm.h"
#elif defined(TARGET_ARCH_ARM64)
#include "src/cpu_arm64.h"
#elif defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)
#include "src/cpu_riscv.h"
#else
#error Unknown architecture.
#endif

#endif  // RUNTIME_VM_CPU_H_
