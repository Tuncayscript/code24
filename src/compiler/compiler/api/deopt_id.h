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

#ifndef RUNTIME_VM_COMPILER_API_DEOPT_ID_H_
#define RUNTIME_VM_COMPILER_API_DEOPT_ID_H_

#include "platform/allocation.h"

namespace Code {

// Deoptimization Id logic.
//
// Deoptimization ids are used to refer to deoptimization points, at which
// control can enter unoptimized code from the optimized version of the code.
//
// Note: any instruction that does a call has two deoptimization points,
// one before the call and one after the call - so that we could deoptimize
// to either before or after the call depending on whether the same call
// already occurred in the optimized code (and potentially produced
// observable side-effects) or not.
//
// To simplify implementation we always allocate two deopt ids (one for before
// point and one for the after point).
class DeoptId : public AllStatic {
 public:
  static constexpr intptr_t kNone = -1;

  static inline intptr_t Next(intptr_t deopt_id) { return deopt_id + kStep; }

  static inline intptr_t ToDeoptAfter(intptr_t deopt_id) {
    ASSERT(IsDeoptBefore(deopt_id));
    return deopt_id + kAfterOffset;
  }

  static inline bool IsDeoptBefore(intptr_t deopt_id) {
    return (deopt_id % kStep) == kBeforeOffset;
  }

  static inline bool IsDeoptAfter(intptr_t deopt_id) {
    return (deopt_id % kStep) == kAfterOffset;
  }

 private:
  static constexpr intptr_t kStep = 2;
  static constexpr intptr_t kBeforeOffset = 0;
  static constexpr intptr_t kAfterOffset = 1;
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_API_DEOPT_ID_H_
