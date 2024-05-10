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

#include "src/snapshot.h"

#include "platform/assert.h"
#include "src/dart.h"

namespace Code {

const char* Snapshot::KindToCString(Kind kind) {
  switch (kind) {
    case kFull:
      return "full";
    case kFullCore:
      return "full-core";
    case kFullJIT:
      return "full-jit";
    case kFullAOT:
      return "full-aot";
    case kNone:
      return "none";
    case kInvalid:
    default:
      return "invalid";
  }
}

const Snapshot* Snapshot::SetupFromBuffer(const void* raw_memory) {
  ASSERT(raw_memory != nullptr);
  const Snapshot* snapshot = reinterpret_cast<const Snapshot*>(raw_memory);
  if (!snapshot->check_magic()) {
    return nullptr;
  }
  // If the raw length is negative or greater than what the local machine can
  // handle, then signal an error.
  int64_t length = snapshot->large_length();
  if ((length < 0) || (length > kIntptrMax)) {
    return nullptr;
  }
  return snapshot;
}

}  // namespace dart
