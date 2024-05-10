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

#include "platform/globals.h"  // NOLINT

#if defined(TARGET_ARCH_ARM64)

#include "src/constants.h"  // NOLINT

namespace Code {

const char* const cpu_reg_names[kNumberOfCpuRegisters] = {
    "r0",  "r1",   "r2",  "r3",  "r4",   "r5",  "r6",  "r7",
    "r8",  "r9",   "r10", "r11", "r12",  "r13", "r14", "sp",
    "tmp", "tmp2", "r18", "r19", "r20",  "r21", "nr",  "r23",
    "r24", "r25",  "thr", "pp",  "mask", "fp",  "lr",  "csp",
};

const char* const cpu_reg_abi_names[kNumberOfCpuRegisters] = {
    "r0",  "r1",  "r2",  "r3",  "r4",  "r5",  "r6",  "r7",  "r8",  "r9",  "r10",
    "r11", "r12", "r13", "r14", "r15", "r16", "r17", "r18", "r19", "r20", "r21",
    "r22", "r23", "r24", "r25", "r26", "r27", "r28", "r29", "r30", "sp",
};

const char* const fpu_reg_names[kNumberOfFpuRegisters] = {
    "v0",  "v1",  "v2",  "v3",  "v4",  "v5",  "v6",  "v7",  "v8",  "v9",  "v10",
    "v11", "v12", "v13", "v14", "v15", "v16", "v17", "v18", "v19", "v20", "v21",
    "v22", "v23", "v24", "v25", "v26", "v27", "v28", "v29", "v30", "v31",
};

const Register CallingConventions::ArgumentRegisters[] = {
    R0, R1, R2, R3, R4, R5, R6, R7,
};

const FpuRegister CallingConventions::FpuArgumentRegisters[] = {
    V0, V1, V2, V3, V4, V5, V6, V7,
};

}  // namespace dart

#endif  // defined(TARGET_ARCH_ARM64)
