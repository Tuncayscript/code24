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

#ifndef RUNTIME_VM_STACK_FRAME_RISCV_H_
#define RUNTIME_VM_STACK_FRAME_RISCV_H_

#if !defined(RUNTIME_VM_STACK_FRAME_H_)
#error Do not include stack_frame_riscv.h directly; use stack_frame.h instead.
#endif

namespace Code {

/* RISC-V Dart Frame Layout
               |                    | <- TOS
Callee frame   | ...                |
               | saved PP           |
               | code object        |
               | saved FP           |    (FP of current frame)
               | saved PC           |    (PC of current frame)
               +--------------------+
Current frame  | ...               T| <- SP of current frame
               | first local       T|
               | caller's PP       T|
               | code object       T|    (current frame's code object)
               | caller's FP        |
               | caller's RA        |    (PC of caller frame)
               +--------------------+
Caller frame   | last parameter     | <- SP of caller frame, FP of current frame
               |  ...               |

               T against a slot indicates it needs to be traversed during GC.
*/

static constexpr int kDartFrameFixedSize = 4;  // PP, FP, RA, PC marker.
static constexpr int kSavedPcSlotFromSp = -1;

static constexpr int kFirstObjectSlotFromFp =
    -3;  // Used by GC to traverse stack.
static constexpr int kLastFixedObjectSlotFromFp = -4;

static constexpr int kFirstLocalSlotFromFp = -5;
static constexpr int kSavedCallerPpSlotFromFp = -4;
static constexpr int kPcMarkerSlotFromFp = -3;
static constexpr int kSavedCallerFpSlotFromFp = -2;
static constexpr int kSavedCallerPcSlotFromFp = -1;

static constexpr int kParamEndSlotFromFp = -1;  // One slot past last parameter.
static constexpr int kCallerSpSlotFromFp = 0;
static constexpr int kLastParamSlotFromEntrySp = 0;

// Entry and exit frame layout.
#if defined(TARGET_ARCH_RISCV64)
static constexpr int kExitLinkSlotFromEntryFp = -30;
#elif defined(TARGET_ARCH_RISCV32)
static constexpr int kExitLinkSlotFromEntryFp = -42;
#endif
COMPILE_ASSERT(kAbiPreservedCpuRegCount == 11);
COMPILE_ASSERT(kAbiPreservedFpuRegCount == 12);

// For FFI native -> Dart callbacks, this is the number of stack slots between
// arguments passed on stack and arguments saved in callback prologue.
//
// 2 = return address (1) + saved frame pointer (1).
//
// If NativeCallbackTrampolines::Enabled(), then
// kNativeCallbackTrampolineStackDelta must be added as well.
constexpr intptr_t kCallbackSlotsBeforeSavedArguments = 2;

// For FFI calls passing in TypedData, we save it on the stack before entering
// a Dart frame. This denotes how to get to the backed up typed data.
static constexpr int kFfiCallerTypedDataSlotFromFp = kCallerSpSlotFromFp;

}  // namespace dart

#endif  // RUNTIME_VM_STACK_FRAME_RISCV_H_
