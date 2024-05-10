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

// A light-weight assembler for the Irregexp byte code.

#include "src/regexp_bytecodes.h"

#ifndef RUNTIME_VM_REGEXP_ASSEMBLER_BYTECODE_INL_H_
#define RUNTIME_VM_REGEXP_ASSEMBLER_BYTECODE_INL_H_

namespace Code {

void BytecodeRegExpMacroAssembler::Emit(uint32_t byte,
                                        uint32_t twenty_four_bits) {
  uint32_t word = ((twenty_four_bits << BYTECODE_SHIFT) | byte);
  ASSERT(pc_ <= buffer_->length());
  if (pc_ + 3 >= buffer_->length()) {
    Expand();
  }
  *reinterpret_cast<uint32_t*>(buffer_->data() + pc_) = word;
  pc_ += 4;
}

void BytecodeRegExpMacroAssembler::Emit16(uint32_t word) {
  ASSERT(pc_ <= buffer_->length());
  if (pc_ + 1 >= buffer_->length()) {
    Expand();
  }
  *reinterpret_cast<uint16_t*>(buffer_->data() + pc_) = word;
  pc_ += 2;
}

void BytecodeRegExpMacroAssembler::Emit8(uint32_t word) {
  ASSERT(pc_ <= buffer_->length());
  if (pc_ == buffer_->length()) {
    Expand();
  }
  *reinterpret_cast<unsigned char*>(buffer_->data() + pc_) = word;
  pc_ += 1;
}

void BytecodeRegExpMacroAssembler::Emit32(uint32_t word) {
  ASSERT(pc_ <= buffer_->length());
  if (pc_ + 3 >= buffer_->length()) {
    Expand();
  }
  *reinterpret_cast<uint32_t*>(buffer_->data() + pc_) = word;
  pc_ += 4;
}

}  // namespace dart

#endif  // RUNTIME_VM_REGEXP_ASSEMBLER_BYTECODE_INL_H_
