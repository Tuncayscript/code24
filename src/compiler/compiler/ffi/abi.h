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

#ifndef RUNTIME_VM_COMPILER_FFI_ABI_H_
#define RUNTIME_VM_COMPILER_FFI_ABI_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include <platform/globals.h>

namespace Code {

namespace compiler {

namespace ffi {

// These ABIs should be kept in sync with
// pkg/src/lib/transformations/ffi/abi.dart.
enum class Abi {
  kAndroidArm,
  kAndroidArm64,
  kAndroidIA32,
  kAndroidX64,
  kAndroidRiscv64,
  kFuchsiaArm64,
  kFuchsiaX64,
  kFuchsiaRiscv64,
  kIOSArm,
  kIOSArm64,
  kIOSX64,
  kLinuxArm,
  kLinuxArm64,
  kLinuxIA32,
  kLinuxX64,
  kLinuxRiscv32,
  kLinuxRiscv64,
  kMacOSArm64,
  kMacOSX64,
  kWindowsArm64,
  kWindowsIA32,
  kWindowsX64,
};

const int64_t num_abis = static_cast<int64_t>(Abi::kWindowsX64) + 1;

// We use the integer values of this enum in
// - runtime/src/compiler/ffi/native_type.cc
// - runtime/src/compiler/frontend/kernel_to_il.cc
static_assert(static_cast<int64_t>(Abi::kAndroidArm) == 0,
              "Enum value unexpected.");
static_assert(static_cast<int64_t>(Abi::kWindowsX64) == 21,
              "Enum value unexpected.");
static_assert(num_abis == 22, "Enum value unexpected.");

// The target ABI. Defines sizes and alignment of native types.
Abi TargetAbi();

extern const char* target_abi_name;

}  // namespace ffi

}  // namespace compiler

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FFI_ABI_H_
