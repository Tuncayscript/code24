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

#ifndef RUNTIME_VM_STACK_FRAME_IA32_H_
#define RUNTIME_VM_STACK_FRAME_IA32_H_

#if !defined(RUNTIME_VM_STACK_FRAME_H_)
#error Do not include stack_frame_ia32.h directly; use stack_frame.h instead.
#endif

namespace Code {

/* IA32 Dart Frame Layout

               |                    | <- TOS
Callee frame   | ...                |
               | saved EBP          |    (EBP of current frame)
               | saved PC           |    (PC of current frame)
               +--------------------+
Current frame  | ...               T| <- ESP of current frame
               | first local       T|
               | code object       T|    (current frame's code object)
               | caller's EBP       | <- EBP of current frame
               | caller's ret addr  |    (PC of caller frame)
               +--------------------+
Caller frame   | last parameter     | <- ESP of caller frame
               |  ...               |

               T against a slot indicates it needs to be traversed during GC.
*/

static constexpr int kDartFrameFixedSize = 3;  // PC marker, EBP, PC.
static constexpr int kSavedPcSlotFromSp = -1;

static constexpr int kFirstObjectSlotFromFp =
    -1;  // Used by GC to traverse stack.
static constexpr int kLastFixedObjectSlotFromFp = -1;

static constexpr int kFirstLocalSlotFromFp = -2;
static constexpr int kPcMarkerSlotFromFp = -1;
static constexpr int kSavedCallerFpSlotFromFp = 0;
static constexpr int kSavedCallerPcSlotFromFp = 1;
static constexpr int kParamEndSlotFromFp = 1;  // One slot past last parameter.
static constexpr int kCallerSpSlotFromFp = 2;
static constexpr int kLastParamSlotFromEntrySp = 1;  // Skip return address.

// No pool pointer on IA32 (indicated by aliasing saved fp).
static constexpr int kSavedCallerPpSlotFromFp = kSavedCallerFpSlotFromFp;

// Entry and exit frame layout.
static constexpr int kExitLinkSlotFromEntryFp = -8;

// All arguments are passed on the stack, so none need to be saved. Therefore
// there is no frame for holding the saved arguments.
//
// If NativeCallbackTrampolines::Enabled(), then
// kNativeCallbackTrampolineStackDelta must be added as well.
constexpr intptr_t kCallbackSlotsBeforeSavedArguments = 0;

// For FFI calls passing in TypedData, we save it on the stack before entering
// a Dart frame. This denotes how to get to the backed up typed data.
static constexpr int kFfiCallerTypedDataSlotFromFp = kCallerSpSlotFromFp;

}  // namespace dart

#endif  // RUNTIME_VM_STACK_FRAME_IA32_H_
