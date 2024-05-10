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

#include "src/compiler/ffi/frame_rebase.h"

namespace Code {

namespace compiler {

namespace ffi {

const NativeLocation& FrameRebase::Rebase(const NativeLocation& loc) const {
  if (!loc.IsStack() || loc.AsStack().base_register() != old_base_) {
    return loc;
  }

  return *new (zone_) NativeStackLocation(
      loc.payload_type(), loc.container_type(), new_base_,
      loc.AsStack().offset_in_bytes() + stack_delta_in_bytes_);
}

Location FrameRebase::Rebase(const Location loc) const {
  if (loc.IsPairLocation()) {
    return Location::Pair(Rebase(loc.Component(0)), Rebase(loc.Component(1)));
  }
  if (!loc.HasStackIndex() || loc.base_reg() != old_base_) {
    return loc;
  }

  const intptr_t new_stack_index =
      loc.stack_index() + stack_delta_in_bytes_ / compiler::target::kWordSize;
  if (loc.IsStackSlot()) {
    return Location::StackSlot(new_stack_index, new_base_);
  }
  if (loc.IsDoubleStackSlot()) {
    return Location::DoubleStackSlot(new_stack_index, new_base_);
  }
  ASSERT(loc.IsQuadStackSlot());
  return Location::QuadStackSlot(new_stack_index, new_base_);
}

}  // namespace ffi

}  // namespace compiler

}  // namespace dart
