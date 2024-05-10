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

#if defined(TARGET_ARCH_X64)

#include "src/constants.h"  // NOLINT

namespace Code {

const char* const cpu_reg_names[kNumberOfCpuRegisters] = {
    "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
    "r8",  "r9",  "r10", "tmp", "r12", "r13", "thr", "pp"};

const char* const cpu_reg_abi_names[kNumberOfCpuRegisters] = {
    "rax", "rcx", "rdx", "rbx", "rsp", "rbp", "rsi", "rdi",
    "r8",  "r9",  "r10", "r11", "r12", "r13", "r14", "r15"};

const char* const cpu_reg_byte_names[kNumberOfByteRegisters] = {
    "al",  "cl",  "dl",   "bl",   "ah",   "ch",   "dh",   "bh",
    "r8b", "r9b", "r10b", "r11b", "r12b", "r13b", "r14b", "r15b"};

const char* const fpu_reg_names[kNumberOfXmmRegisters] = {
    "xmm0", "xmm1", "xmm2",  "xmm3",  "xmm4",  "xmm5",  "xmm6",  "xmm7",
    "xmm8", "xmm9", "xmm10", "xmm11", "xmm12", "xmm13", "xmm14", "xmm15"};

#if defined(CODE_TARGET_OS_WINDOWS)
const Register CallingConventions::ArgumentRegisters[] = {
    CallingConventions::kArg1Reg, CallingConventions::kArg2Reg,
    CallingConventions::kArg3Reg, CallingConventions::kArg4Reg};

const XmmRegister CallingConventions::FpuArgumentRegisters[] = {
    XmmRegister::XMM0, XmmRegister::XMM1, XmmRegister::XMM2, XmmRegister::XMM3};
#else
const Register CallingConventions::ArgumentRegisters[] = {
    CallingConventions::kArg1Reg, CallingConventions::kArg2Reg,
    CallingConventions::kArg3Reg, CallingConventions::kArg4Reg,
    CallingConventions::kArg5Reg, CallingConventions::kArg6Reg};

const XmmRegister CallingConventions::FpuArgumentRegisters[] = {
    XmmRegister::XMM0, XmmRegister::XMM1, XmmRegister::XMM2, XmmRegister::XMM3,
    XmmRegister::XMM4, XmmRegister::XMM5, XmmRegister::XMM6, XmmRegister::XMM7};
#endif

}  // namespace dart

#endif  // defined(TARGET_ARCH_X64)
