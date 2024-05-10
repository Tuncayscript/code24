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

#include "src/globals.h"  // Needed here to get TARGET_ARCH_X64.
#if defined(TARGET_ARCH_X64)

#include "platform/unaligned.h"

#include "src/code_patcher.h"
#include "src/instructions.h"
#include "src/instructions_x64.h"

#include "src/constants.h"
#include "src/cpu.h"
#include "src/object.h"
#include "src/object_store.h"

namespace Code {

// [start] is the address of a displacement inside a load instruction
intptr_t IndexFromPPLoadDisp8(uword start) {
  int8_t offset = *reinterpret_cast<int8_t*>(start);
  return ObjectPool::IndexFromOffset(offset);
}

intptr_t IndexFromPPLoadDisp32(uword start) {
  int32_t offset = LoadUnaligned(reinterpret_cast<int32_t*>(start));
  return ObjectPool::IndexFromOffset(offset);
}

bool DecodeLoadObjectFromPoolOrThread(uword pc, const Code& code, Object* obj) {
  ASSERT(code.ContainsInstructionAt(pc));

  uint8_t* bytes = reinterpret_cast<uint8_t*>(pc);

  COMPILE_ASSERT(THR == R14);
  if ((bytes[0] == 0x49) || (bytes[0] == 0x4d)) {
    if ((bytes[1] == 0x8b) || (bytes[1] == 0x3b)) {   // movq, cmpq
      if ((bytes[2] & 0xc7) == (0x80 | (THR & 7))) {  // [r14+disp32]
        int32_t offset = LoadUnaligned(reinterpret_cast<int32_t*>(pc + 3));
        return Thread::ObjectAtOffset(offset, obj);
      }
      if ((bytes[2] & 0xc7) == (0x40 | (THR & 7))) {  // [r14+disp8]
        uint8_t offset = *reinterpret_cast<uint8_t*>(pc + 3);
        return Thread::ObjectAtOffset(offset, obj);
      }
    }
  }

  if (((bytes[0] == 0x41) && (bytes[1] == 0xff) && (bytes[2] == 0x76))) {
    // push [r14+disp8]
    uint8_t offset = *reinterpret_cast<uint8_t*>(pc + 3);
    return Thread::ObjectAtOffset(offset, obj);
  }

  COMPILE_ASSERT(PP == R15);
  if ((bytes[0] == 0x49) || (bytes[0] == 0x4d)) {
    if ((bytes[1] == 0x8b) || (bytes[1] == 0x3b)) {  // movq, cmpq
      if ((bytes[2] & 0xc7) == (0x80 | (PP & 7))) {  // [r15+disp32]
        intptr_t index = IndexFromPPLoadDisp32(pc + 3);
        return ObjectAtPoolIndex(code, index, obj);
      }
      if ((bytes[2] & 0xc7) == (0x40 | (PP & 7))) {  // [r15+disp8]
        intptr_t index = IndexFromPPLoadDisp8(pc + 3);
        return ObjectAtPoolIndex(code, index, obj);
      }
    }
  }

  return false;
}

intptr_t TypeTestingStubCallPattern::GetSubtypeTestCachePoolIndex() {
  static int16_t indirect_call_pattern[] = {
      0xff, -1 /* 0x53 or 0x56 */, 0x07,  // callq [RBX/RSI + 0x7]
  };
  static int16_t direct_call_pattern[] = {
      0xe8, -1, -1, -1, -1,  // callq [PC + <offset>]
  };
  static int16_t pattern_disp8[] = {
      0x4d, 0x8b, 0x4f, -1,  // movq R9, [PP + offset]
  };
  static int16_t pattern_disp32[] = {
      0x4d, 0x8b, 0x8f, -1, -1, -1, -1,  // movq R9, [PP + offset]
  };

  uword pc = pc_;
  if (MatchesPattern(pc, direct_call_pattern,
                     ARRAY_SIZE(direct_call_pattern))) {
    pc -= ARRAY_SIZE(direct_call_pattern);
  } else if (MatchesPattern(pc, indirect_call_pattern,
                            ARRAY_SIZE(indirect_call_pattern))) {
    pc -= ARRAY_SIZE(indirect_call_pattern);
  } else {
    FATAL("Failed to decode at %" Px, pc_);
  }

  if (MatchesPattern(pc, pattern_disp8, ARRAY_SIZE(pattern_disp8))) {
    return IndexFromPPLoadDisp8(pc - 1);
  } else if (MatchesPattern(pc, pattern_disp32, ARRAY_SIZE(pattern_disp32))) {
    return IndexFromPPLoadDisp32(pc - 4);
  } else {
    FATAL("Failed to decode at %" Px, pc);
  }
}

}  // namespace dart

#endif  // defined TARGET_ARCH_X64
