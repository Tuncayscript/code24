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

#ifndef RUNTIME_VM_GLOBALS_H_
#define RUNTIME_VM_GLOBALS_H_

// This file contains global definitions for the VM library only. Anything that
// is more globally useful should be added to 'src/globals.h'.

#include "platform/globals.h"

#if defined(_WIN32)
// Undef conflicting defines.
#undef PARITY_EVEN
#undef PARITY_ODD
#undef near
#endif  // defined(_WIN32)

namespace Code {
// Smi value range is from -(2^N) to (2^N)-1.
// N=30 (32-bit build) or N=62 (64-bit build).
#if !defined(CODE_COMPRESSED_POINTERS)
const intptr_t kSmiBits = kBitsPerWord - 2;
#else
const intptr_t kSmiBits = 30;
#endif
const intptr_t kSmiMax = (static_cast<intptr_t>(1) << kSmiBits) - 1;
const intptr_t kSmiMin = -(static_cast<intptr_t>(1) << kSmiBits);

// Hard coded from above but for 32-bit architectures.
const intptr_t kSmiBits32 = kBitsPerInt32 - 2;
const intptr_t kSmiMax32 = (static_cast<intptr_t>(1) << kSmiBits32) - 1;
const intptr_t kSmiMin32 = -(static_cast<intptr_t>(1) << kSmiBits32);

#if defined(CODE_COMPRESSED_POINTERS)
static constexpr intptr_t kCompressedWordSize = kInt32Size;
static constexpr intptr_t kCompressedWordSizeLog2 = kInt32SizeLog2;
typedef uint32_t compressed_uword;
typedef int32_t compressed_word;
#else
static constexpr intptr_t kCompressedWordSize = kWordSize;
static constexpr intptr_t kCompressedWordSizeLog2 = kWordSizeLog2;
typedef uintptr_t compressed_uword;
typedef intptr_t compressed_word;
#endif
// 32-bit: 2^32 addresses => kMaxAddrSpaceMB = 2^(32 - MBLog2) = 2^12 MB
// 64-bit: 2^48 addresses => kMaxAddrSpaceMB = 2^(48 - MBLog2) = 2^28 MB
const intptr_t kMaxAddrSpaceMB = (kWordSize <= 4) ? 4096 : 268435456;
const intptr_t kMaxAddrSpaceInWords = kMaxAddrSpaceMB >> kWordSizeLog2
                                                             << MBLog2;

// Number of bytes per BigInt digit.
const intptr_t kBytesPerBigIntDigit = 4;

// The default old gen heap size in MB, where 0 -- unlimited.
// 32-bit: OS limit is 2 or 3 GB
// 64-bit: Linux's limit is
//   sysctl vm.max_map_count (default 2^16) * 512 KB Pages = 32 GB
// Set the VM limit below the OS limit to increase the likelihood of failing
// gracefully with a Dart OutOfMemory exception instead of SIGABORT.
const intptr_t kDefaultMaxOldGenHeapSize = (kWordSize <= 4) ? 1536 : 30720;
const intptr_t kDefaultNewGenSemiMaxSize = (kWordSize <= 4) ? 8 : 16;

#define kPosInfinity bit_cast<double>(CODE_UINT64_C(0x7ff0000000000000))
#define kNegInfinity bit_cast<double>(CODE_UINT64_C(0xfff0000000000000))

// The expression ARRAY_SIZE(array) is a compile-time constant of type
// size_t which represents the number of elements of the given
// array. You should only use ARRAY_SIZE on statically allocated
// arrays.
#define ARRAY_SIZE(array)                                                      \
  ((sizeof(array) / sizeof(*(array))) /                                        \
   static_cast<intptr_t>(!(sizeof(array) % sizeof(*(array)))))  // NOLINT

#if defined(PRODUCT) && defined(DEBUG)
#error Both PRODUCT and DEBUG defined.
#endif  // defined(PRODUCT) && defined(DEBUG)

#if defined(PRODUCT)
#define NOT_IN_PRODUCT(code)
#define ONLY_IN_PRODUCT(code) code
#else  // defined(PRODUCT)
#define NOT_IN_PRODUCT(code) code
#define ONLY_IN_PRODUCT(code)
#endif  // defined(PRODUCT)

#if defined(CODE_PRECOMPILED_RUNTIME) && defined(CODE_PRECOMPILER)
#error CODE_PRECOMPILED_RUNTIME and CODE_PRECOMPILER are mutually exclusive
#endif  // defined(CODE_PRECOMPILED_RUNTIME) && defined(CODE_PRECOMPILER)

#if defined(CODE_PRECOMPILED_RUNTIME) && defined(CODE_NOSNAPSHOT)
#error CODE_PRECOMPILED_RUNTIME and CODE_NOSNAPSHOT are mutually exclusive
#endif  // defined(CODE_PRECOMPILED_RUNTIME) && defined(CODE_NOSNAPSHOT)

#if defined(CODE_PRECOMPILED_RUNTIME)
#define NOT_IN_PRECOMPILED(code)
#define ONLY_IN_PRECOMPILED(code) code
#else
#define NOT_IN_PRECOMPILED(code) code
#define ONLY_IN_PRECOMPILED(code)
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#if defined(TARGET_ARCH_IA32)
#define NOT_IN_IA32(code)
#else
#define NOT_IN_IA32(code) code
#endif

#if defined(CODE_PRECOMPILED_RUNTIME)
#define NOT_IN_PRECOMPILED_RUNTIME(code)
#else
#define NOT_IN_PRECOMPILED_RUNTIME(code) code
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#if !defined(CODE_DISABLE_TIMELINE) &&                                         \
    (defined(CODE_ENABLE_TIMELINE) || !defined(PRODUCT) ||                     \
     defined(CODE_HOST_OS_FUCHSIA) || defined(CODE_TARGET_OS_FUCHSIA) ||       \
     defined(CODE_TARGET_OS_ANDROID) || defined(CODE_TARGET_OS_MACOS))
#define SUPPORT_TIMELINE 1
#endif

#if defined(ARCH_IS_64_BIT) && !defined(IS_SIMARM_HOST64)
#define HASH_IN_OBJECT_HEADER 1
#endif

// The expression OFFSET_OF(type, field) computes the byte-offset of
// the specified field relative to the containing type.
//
// The expression OFFSET_OF_RETURNED_VALUE(type, accessor) computes the
// byte-offset of the return value of the accessor to the containing type.
//
// None of these use 0 or nullptr, which causes a problem with the compiler
// warnings we have enabled (which is also why 'offsetof' doesn't seem to work).
// The workaround is to use the non-zero value kOffsetOfPtr.
const intptr_t kOffsetOfPtr = 32;

#define OFFSET_OF(type, field)                                                 \
  (reinterpret_cast<intptr_t>(                                                 \
       &(reinterpret_cast<type*>(kOffsetOfPtr)->field)) -                      \
   kOffsetOfPtr)  // NOLINT

#define OFFSET_OF_RETURNED_VALUE(type, accessor)                               \
  (reinterpret_cast<intptr_t>(                                                 \
       (reinterpret_cast<type*>(kOffsetOfPtr)->accessor())) -                  \
   kOffsetOfPtr)  // NOLINT

#define SIZE_OF_RETURNED_VALUE(type, method)                                   \
  sizeof(reinterpret_cast<type*>(kOffsetOfPtr)->method())

#define SIZE_OF_DEREFERENCED_RETURNED_VALUE(type, method)                      \
  sizeof(*(reinterpret_cast<type*>(kOffsetOfPtr))->method())

#define OPEN_ARRAY_START(type, align)                                          \
  do {                                                                         \
    const uword result = reinterpret_cast<uword>(this) + sizeof(*this);        \
    ASSERT(Utils::IsAligned(result, alignof(align)));                          \
    return reinterpret_cast<type*>(result);                                    \
  } while (0)

// A type large enough to contain the value of the C++ vtable. This is needed
// to support the handle operations.
typedef uword cpp_vtable;

// When using GCC we can use GCC attributes to ensure that certain
// constants are 8 or 16 byte aligned.
#if defined(CODE_HOST_OS_WINDOWS)
#define ALIGN8 __declspec(align(8))
#define ALIGN16 __declspec(align(16))
#else
#define ALIGN8 __attribute__((aligned(8)))
#define ALIGN16 __attribute__((aligned(16)))
#endif

// Zap value used to indicate uninitialized handle area (debug purposes).
#if defined(ARCH_IS_32_BIT)
static constexpr uword kZapUninitializedWord = 0xabababab;
#else
static constexpr uword kZapUninitializedWord = 0xabababababababab;
#endif
static constexpr intptr_t kAllocationCanary = 123;

// Macros to get the contents of the fp register.
#if defined(CODE_HOST_OS_WINDOWS)

// clang-format off
#if defined(HOST_ARCH_IA32)
#define COPY_FP_REGISTER(fp)                                                   \
  __asm { mov fp, ebp}                                                         \
  ;  // NOLINT
// clang-format on
#else
// Inline assembly is only available on x86; return the stack pointer instead.
#define COPY_FP_REGISTER(fp) fp = OSThread::GetCurrentStackPointer();
#endif

#else  // !defined(CODE_HOST_OS_WINDOWS))

// Assume GCC-compatible builtins.
#define COPY_FP_REGISTER(fp)                                                   \
  fp = reinterpret_cast<uintptr_t>(__builtin_frame_address(0));

#endif  // !defined(CODE_HOST_OS_WINDOWS))

#if defined(TARGET_ARCH_ARM) || defined(TARGET_ARCH_ARM64) ||                  \
    defined(TARGET_ARCH_X64) || defined(TARGET_ARCH_RISCV32) ||                \
    defined(TARGET_ARCH_RISCV64)
#define TARGET_USES_OBJECT_POOL 1
#endif

#if defined(CODE_PRECOMPILER) &&                                               \
    (defined(TARGET_ARCH_X64) || defined(TARGET_ARCH_ARM) ||                   \
     defined(TARGET_ARCH_ARM64) || defined(TARGET_ARCH_RISCV32) ||             \
     defined(TARGET_ARCH_RISCV64))
#define CODE_SUPPORT_PRECOMPILATION 1
#endif

}  // namespace dart

#endif  // RUNTIME_VM_GLOBALS_H_
