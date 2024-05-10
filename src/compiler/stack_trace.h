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

#ifndef RUNTIME_VM_STACK_TRACE_H_
#define RUNTIME_VM_STACK_TRACE_H_

#include <functional>

#include "src/allocation.h"
#include "src/flag_list.h"
#include "src/object.h"
#include "src/symbols.h"

namespace Code {

class StackTraceUtils : public AllStatic {
 public:
  static constexpr uword kFutureListenerPcOffset = 1;

  struct Frame {
    // Corresponding on stack frame or |nullptr| if this is an awaiter frame
    // or a gap.
    StackFrame* frame;

    // Code object corresponding to this frame.
    const Code& code;

    // Offset into the code object corresponding to this frame.
    //
    // Will be set to |kFutureListenerPcOffset| if this frame corresponds to
    // future listener that is not yet executing.
    uword pc_offset;

    // Closure corresponding to the awaiter frame or |null| if this is
    // a synchronous frame or a gap.
    const Closure& closure;
  };

  // Returns |true| if this function is needed to correctly unwind through
  // awaiter chains. This means AOT compiler should retain |Function| object,
  // its signature and the corresponding |Code| object (so that we could
  // perform the reverse lookup).
  static bool IsNeededForAsyncAwareUnwinding(const Function& function);

  // Returns |true| if the given class might serve as an awaiter-link when
  // unwinding an awaiter chain.
  //
  // This is used to eagerly mark tear-offs of methods on this class
  // as having an awaiter-link.
  static bool IsPossibleAwaiterLink(const Class& cls);

  /// Collects all frames on the current stack until an async/async* frame is
  /// hit which has yielded before (i.e. is not in sync-async case).
  ///
  /// From there on finds the closure of the async/async* frame and starts
  /// traversing the listeners.
  static void CollectFrames(
      Thread* thread,
      int skip_frames,
      const std::function<void(const Frame&)>& handle_frame,
      bool* has_async_catch_error = nullptr);

  // If |closure| has an awaiter-link pointing to the |SuspendState|
  // the return that object.
  static bool GetSuspendState(const Closure& closure, Object* suspend_state);
};

}  // namespace dart

#endif  // RUNTIME_VM_STACK_TRACE_H_
