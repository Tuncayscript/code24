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

#ifndef RUNTIME_VM_DISPATCH_TABLE_H_
#define RUNTIME_VM_DISPATCH_TABLE_H_

#include <memory>

#include "src/globals.h"

namespace Code {

class DispatchTable {
 public:
  explicit DispatchTable(intptr_t length)
      : length_(length), array_(new uword[length]()) {}

  intptr_t length() const { return length_; }

  // The element of the dispatch table array to which the dispatch table
  // register points.
#if defined(TARGET_ARCH_X64)
  // Max negative byte offset / 8
  static constexpr intptr_t kOriginElement = 16;
#elif defined(TARGET_ARCH_ARM)
  // Max negative load offset / 4
  static constexpr intptr_t kOriginElement = 1023;
#elif defined(TARGET_ARCH_ARM64)
  // Max consecutive sub immediate value
  static constexpr intptr_t kOriginElement = 4096;
#elif defined(TARGET_ARCH_RISCV32)
  // Max consecutive sub immediate value
  static constexpr intptr_t kOriginElement = 2048 / 4;
#elif defined(TARGET_ARCH_RISCV64)
  // Max consecutive sub immediate value
  static constexpr intptr_t kOriginElement = 2048 / 8;
#else
  static constexpr intptr_t kOriginElement = 0;
#endif

#if defined(TARGET_ARCH_X64)
  // Origin + Max positive byte offset / 8
  static constexpr intptr_t kLargestSmallOffset = 31;
#elif defined(TARGET_ARCH_ARM)
  // Origin + Max positive load offset / 4
  static constexpr intptr_t kLargestSmallOffset = 2046;
#elif defined(TARGET_ARCH_ARM64)
  // Origin + Max consecutive add immediate value
  static constexpr intptr_t kLargestSmallOffset = 8192;
#elif defined(TARGET_ARCH_RISCV32)
  // Origin + Max consecutive add immediate value
  static constexpr intptr_t kLargestSmallOffset = 4096 / 4;
#elif defined(TARGET_ARCH_RISCV64)
  // Origin + Max consecutive add immediate value
  static constexpr intptr_t kLargestSmallOffset = 4096 / 8;
#else
  // No AOT on IA32
  static constexpr intptr_t kLargestSmallOffset = 0;
#endif

  // Dispatch table array pointer to put into the dispatch table register.
  const uword* ArrayOrigin() const;

 private:
  uword* array() { return array_.get(); }

  intptr_t length_;
  std::unique_ptr<uword[]> array_;

  friend class Deserializer;  // For non-const array().
  DISALLOW_COPY_AND_ASSIGN(DispatchTable);
};

}  // namespace dart

#endif  // RUNTIME_VM_DISPATCH_TABLE_H_
