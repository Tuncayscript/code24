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

#ifndef RUNTIME_VM_COMPILER_ASSEMBLER_ASSEMBLER_H_
#define RUNTIME_VM_COMPILER_ASSEMBLER_ASSEMBLER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "platform/assert.h"
#include "src/allocation.h"
#include "src/compiler/assembler/object_pool_builder.h"
#include "src/compiler/runtime_api.h"
#include "src/globals.h"
#include "src/growable_array.h"
#include "src/hash_map.h"

#if defined(TARGET_ARCH_IA32)
#include "src/compiler/assembler/assembler_ia32.h"
#elif defined(TARGET_ARCH_X64)
#include "src/compiler/assembler/assembler_x64.h"
#elif defined(TARGET_ARCH_ARM)
#include "src/compiler/assembler/assembler_arm.h"
#elif defined(TARGET_ARCH_ARM64)
#include "src/compiler/assembler/assembler_arm64.h"
#elif defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)
#include "src/compiler/assembler/assembler_riscv.h"
#else
#error Unknown architecture.
#endif

#endif  // RUNTIME_VM_COMPILER_ASSEMBLER_ASSEMBLER_H_
