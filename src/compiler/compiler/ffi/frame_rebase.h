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

#ifndef RUNTIME_VM_COMPILER_FFI_FRAME_REBASE_H_
#define RUNTIME_VM_COMPILER_FFI_FRAME_REBASE_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/compiler/backend/locations.h"
#include "src/compiler/ffi/native_location.h"
#include "src/compiler/ffi/native_type.h"
#include "src/compiler/runtime_api.h"
#include "src/thread.h"

namespace Code {

namespace compiler {

namespace ffi {

// Describes a change of stack frame where the stack or base register or stack
// offset may change. This class allows easily rebasing stack locations across
// frame manipulations.
//
// If the stack offset register matches 'old_base', it is changed to 'new_base'
// and 'stack_delta_in_bytes' (# of bytes) is applied.
//
// This class can be used to rebase both Locations and NativeLocations.
class FrameRebase : public ValueObject {
 public:
  FrameRebase(Zone* zone,
              const Register old_base,
              const Register new_base,
              intptr_t stack_delta_in_bytes)
      : zone_(zone),
        old_base_(old_base),
        new_base_(new_base),
        stack_delta_in_bytes_(stack_delta_in_bytes) {}

  const NativeLocation& Rebase(const NativeLocation& loc) const;

  Location Rebase(const Location loc) const;

 private:
  Zone* zone_;
  const Register old_base_;
  const Register new_base_;
  const intptr_t stack_delta_in_bytes_;
};

}  // namespace ffi

}  // namespace compiler

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FFI_FRAME_REBASE_H_
