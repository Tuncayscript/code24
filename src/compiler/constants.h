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

#ifndef RUNTIME_VM_CONSTANTS_H_
#define RUNTIME_VM_CONSTANTS_H_

#if defined(TARGET_ARCH_IA32)
#include "src/constants_ia32.h"
#elif defined(TARGET_ARCH_X64)
#include "src/constants_x64.h"
#elif defined(TARGET_ARCH_ARM)
#include "src/constants_arm.h"
#elif defined(TARGET_ARCH_ARM64)
#include "src/constants_arm64.h"
#elif defined(TARGET_ARCH_RISCV32) || defined(TARGET_ARCH_RISCV64)
#include "src/constants_riscv.h"
#else
#error Unknown architecture.
#endif

#include "platform/assert.h"
#include "platform/utils.h"

#include "src/pointer_tagging.h"

namespace Code {

// An architecture independent ABI for the InstantiateType stub.
//
// We re-use registers from another ABI to avoid duplicating this ABI across 4
// architectures.
struct InstantiateTypeABI {
  static constexpr Register kTypeReg =
      InstantiationABI::kUninstantiatedTypeArgumentsReg;
  static constexpr Register kInstantiatorTypeArgumentsReg =
      InstantiationABI::kInstantiatorTypeArgumentsReg;
  static constexpr Register kFunctionTypeArgumentsReg =
      InstantiationABI::kFunctionTypeArgumentsReg;
  static constexpr Register kResultTypeReg = InstantiationABI::kResultTypeReg;
  static constexpr Register kScratchReg = InstantiationABI::kScratchReg;
};

class RegisterNames {
 public:
  static const char* RegisterName(Register reg) {
    ASSERT((0 <= reg) && (reg < kNumberOfCpuRegisters));
    return cpu_reg_names[reg];
  }
  static const char* RegisterAbiName(Register reg) {
    ASSERT((0 <= reg) && (reg < kNumberOfCpuRegisters));
    return cpu_reg_abi_names[reg];
  }
  static const char* FpuRegisterName(FpuRegister reg) {
    ASSERT((0 <= reg) && (reg < kNumberOfFpuRegisters));
    return fpu_reg_names[reg];
  }
#if defined(TARGET_ARCH_ARM)
  static const char* FpuSRegisterName(SRegister reg) {
    ASSERT((0 <= reg) && (reg < kNumberOfSRegisters));
    return fpu_s_reg_names[reg];
  }
  static const char* FpuDRegisterName(DRegister reg) {
    ASSERT((0 <= reg) && (reg < kNumberOfDRegisters));
    return fpu_d_reg_names[reg];
  }
#endif  // defined(TARGET_ARCH_ARM)

#if defined(TARGET_ARCH_X64) || defined(TARGET_ARCH_IA32)
  static const char* RegisterByteName(ByteRegister reg) {
    ASSERT((0 <= reg) && (reg < kNumberOfByteRegisters));
    return cpu_reg_byte_names[reg];
  }
#endif  // defined(TARGET_ARCH_X64) || defined(TARGET_ARCH_IA32)
};

static constexpr bool IsArgumentRegister(Register reg) {
  return ((1 << reg) & CallingConventions::kArgumentRegisters) != 0;
}

static constexpr bool IsFpuArgumentRegister(FpuRegister reg) {
  return ((1 << reg) & CallingConventions::kFpuArgumentRegisters) != 0;
}

static constexpr bool IsCalleeSavedRegister(Register reg) {
  return ((1 << reg) & CallingConventions::kCalleeSaveCpuRegisters) != 0;
}

#if !defined(TARGET_ARCH_IA32)
constexpr bool IsAbiPreservedRegister(Register reg) {
  return (kAbiPreservedCpuRegs & (1 << reg)) != 0;
}
#endif

static inline ScaleFactor ToScaleFactor(intptr_t index_scale,
                                        bool index_unboxed) {
  RELEASE_ASSERT(index_scale >= 0);
  const intptr_t shift = Utils::ShiftForPowerOfTwo(index_scale) -
                         (index_unboxed ? 0 : kSmiTagShift);
  // index_scale < kSmiTagShift for boxed indexes must be handled by the caller,
  // and ScaleFactor is currently only defined up to TIMES_16 == 4.
  RELEASE_ASSERT(shift >= 0 && shift <= 4);
  return static_cast<ScaleFactor>(shift);
}

// Helper for using register sets with range loops:
//
//   for (auto reg : RegisterRange(kDartAvailableCpuRegs)) { ... }
//
static inline Utils::BitsRange<Register> RegisterRange(uint32_t regs) {
  return Utils::BitsRange<Register>(regs);
}

}  // namespace dart

#endif  // RUNTIME_VM_CONSTANTS_H_
