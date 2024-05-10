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

#ifndef RUNTIME_VM_INSTRUCTIONS_H_
#define RUNTIME_VM_INSTRUCTIONS_H_

#include "src/globals.h"

#if defined(TARGET_ARCH_IA32)
#include "src/instructions_ia32.h"
#elif defined(TARGET_ARCH_X64)
#include "src/instructions_x64.h"
#elif defined(TARGET_ARCH_ARM)
#include "src/instructions_arm.h"
#elif defined(TARGET_ARCH_ARM64)
#include "src/instructions_arm64.h"
#elif defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)
#include "src/instructions_riscv.h"
#else
#error Unknown architecture.
#endif

namespace Code {

class Object;
class Code;

bool ObjectAtPoolIndex(const Code& code, intptr_t index, Object* obj);
bool DecodeLoadObjectFromPoolOrThread(uword pc, const Code& code, Object* obj);

#if !defined(TARGET_ARCH_IA32)

class TypeTestingStubCallPattern : public ValueObject {
 public:
  explicit TypeTestingStubCallPattern(uword pc) : pc_(pc) {}

  intptr_t GetSubtypeTestCachePoolIndex();

 private:
  const uword pc_;
};

#endif  // !defined(TARGET_ARCH_IA32)

}  // namespace dart

#endif  // RUNTIME_VM_INSTRUCTIONS_H_
