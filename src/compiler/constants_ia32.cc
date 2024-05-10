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

#if defined(TARGET_ARCH_IA32)

#include "src/constants.h"  // NOLINT

namespace Code {

const char* const cpu_reg_names[kNumberOfCpuRegisters] = {
    "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};

const char* const cpu_reg_byte_names[kNumberOfCpuRegisters] = {
    "al", "cl", "dl", "bl", "ah", "ch", "dh", "bh"};

const char* const cpu_reg_abi_names[kNumberOfCpuRegisters] = {
    "eax", "ecx", "edx", "ebx", "esp", "ebp", "esi", "edi"};

const char* const fpu_reg_names[kNumberOfXmmRegisters] = {
    "xmm0", "xmm1", "xmm2", "xmm3", "xmm4", "xmm5", "xmm6", "xmm7"};

// Although 'kArgumentRegisters' and 'kFpuArgumentRegisters' are both 0, we have
// to give these arrays at least one element to appease MSVC.

const Register CallingConventions::ArgumentRegisters[] = {
    static_cast<Register>(0)};
const FpuRegister CallingConventions::FpuArgumentRegisters[] = {
    static_cast<FpuRegister>(0)};

}  // namespace dart

#endif  // defined(TARGET_ARCH_IA32)
