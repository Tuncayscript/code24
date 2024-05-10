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

#ifndef RUNTIME_VM_BOOLFIELD_H_
#define RUNTIME_VM_BOOLFIELD_H_

#include "platform/assert.h"
#include "src/globals.h"

namespace Code {

// BoolField is a template for encoding and decoding a bit inside an
// unsigned machine word.
template <int position>
class BoolField {
 public:
  // Returns a uword with the bool value encoded.
  static uword encode(bool value) {
    ASSERT(position < sizeof(uword));
    return static_cast<uword>((value ? 1U : 0) << position);
  }

  // Extracts the bool from the value.
  static bool decode(uword value) {
    ASSERT(position < sizeof(uword));
    return (value & (1U << position)) != 0;
  }

  // Returns a uword with the bool field value encoded based on the
  // original value. Only the single bit corresponding to this bool
  // field will be changed.
  static uword update(bool value, uword original) {
    ASSERT(position < sizeof(uword));
    const uword mask = 1U << position;
    return value ? original | mask : original & ~mask;
  }
};

}  // namespace dart

#endif  // RUNTIME_VM_BOOLFIELD_H_
