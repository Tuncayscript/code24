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

#ifndef RUNTIME_VM_LONGJUMP_H_
#define RUNTIME_VM_LONGJUMP_H_

#include <setjmp.h>

#include "src/allocation.h"
#include "src/thread_state.h"

namespace Code {

class Error;

class LongJumpScope : public StackResource {
 public:
  explicit LongJumpScope(ThreadState* thread = ThreadState::Current())
      : StackResource(thread), top_(nullptr), base_(thread->long_jump_base()) {
    thread->set_long_jump_base(this);
  }

  ~LongJumpScope() {
    ASSERT(thread() == ThreadState::Current());
    thread()->set_long_jump_base(base_);
  }

  jmp_buf* Set();
  CODE_NORETURN void Jump(int value, const Error& error);
  CODE_NORETURN void Jump(int value);

 private:
  jmp_buf environment_;
  StackResource* top_;
  LongJumpScope* base_;

  DISALLOW_COPY_AND_ASSIGN(LongJumpScope);
};

}  // namespace dart

#endif  // RUNTIME_VM_LONGJUMP_H_
