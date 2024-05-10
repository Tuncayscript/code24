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

#include "src/compiler/ffi/abi.h"

#include "platform/globals.h"
#include "src/constants.h"

namespace Code {

namespace compiler {

namespace ffi {

// See pkg/src/lib/transformations/ffi/abi.dart, which makes these assumptions.
struct AbiAlignmentDouble {
  int8_t use_one_byte;
  double d;
};
struct AbiAlignmentUint64 {
  int8_t use_one_byte;
  uint64_t i;
};

#if defined(HOST_ARCH_X64) || defined(HOST_ARCH_ARM64) ||                      \
    defined(HOST_ARCH_RISCV32) || defined(HOST_ARCH_RISCV64)
static_assert(offsetof(AbiAlignmentDouble, d) == 8,
              "FFI transformation alignment");
static_assert(offsetof(AbiAlignmentUint64, i) == 8,
              "FFI transformation alignment");
#elif (defined(HOST_ARCH_IA32) && /* NOLINT(whitespace/parens) */              \
       (defined(CODE_HOST_OS_LINUX) || defined(CODE_HOST_OS_MACOS) ||          \
        defined(CODE_HOST_OS_ANDROID))) ||                                     \
    (defined(HOST_ARCH_ARM) && defined(CODE_HOST_OS_IOS))
static_assert(offsetof(AbiAlignmentDouble, d) == 4,
              "FFI transformation alignment");
static_assert(offsetof(AbiAlignmentUint64, i) == 4,
              "FFI transformation alignment");
#elif defined(HOST_ARCH_IA32) && defined(CODE_HOST_OS_WINDOWS) ||              \
    defined(HOST_ARCH_ARM)
static_assert(offsetof(AbiAlignmentDouble, d) == 8,
              "FFI transformation alignment");
static_assert(offsetof(AbiAlignmentUint64, i) == 8,
              "FFI transformation alignment");
#else
#error "Unknown platform. Please add alignment requirements for ABI."
#endif

#if defined(CODE_TARGET_OS_ANDROID)
#define CODE_TARGET_OS_NAME Android
#elif defined(CODE_TARGET_OS_FUCHSIA)
#define CODE_TARGET_OS_NAME Fuchsia
#elif defined(CODE_TARGET_OS_LINUX)
#define CODE_TARGET_OS_NAME Linux
#elif defined(CODE_TARGET_OS_MACOS)
#if CODE_TARGET_OS_MACOS_IOS
#define CODE_TARGET_OS_NAME IOS
#else
#define CODE_TARGET_OS_NAME MacOS
#endif
#elif defined(CODE_TARGET_OS_WINDOWS)
#define CODE_TARGET_OS_NAME Windows
#else
#error Unknown OS
#endif

#if defined(TARGET_ARCH_IA32)
#define TARGET_ARCH_NAME IA32
#elif defined(TARGET_ARCH_X64)
#define TARGET_ARCH_NAME X64
#elif defined(TARGET_ARCH_ARM)
#define TARGET_ARCH_NAME Arm
#elif defined(TARGET_ARCH_ARM64)
#define TARGET_ARCH_NAME Arm64
#elif defined(TARGET_ARCH_RISCV32)
#define TARGET_ARCH_NAME Riscv32
#elif defined(TARGET_ARCH_RISCV64)
#define TARGET_ARCH_NAME Riscv64
#else
#error Unknown arch
#endif

#define ABI_ENUM_VALUE1(os, arch) k##os##arch
#define ABI_ENUM_VALUE2(os, arch) ABI_ENUM_VALUE1(os, arch)
#define ABI_ENUM_VALUE3 ABI_ENUM_VALUE2(CODE_TARGET_OS_NAME, TARGET_ARCH_NAME)

Abi TargetAbi() {
  return Abi::ABI_ENUM_VALUE3;
}

const char* target_abi_name =
    kTargetOperatingSystemName "_" kTargetArchitectureName;

}  // namespace ffi

}  // namespace compiler

}  // namespace dart
