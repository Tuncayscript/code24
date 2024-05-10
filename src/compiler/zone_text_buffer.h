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

#ifndef RUNTIME_VM_ZONE_TEXT_BUFFER_H_
#define RUNTIME_VM_ZONE_TEXT_BUFFER_H_

#include "platform/text_buffer.h"
#include "src/allocation.h"
#include "src/globals.h"

namespace Code {

class String;
class Zone;

// ZoneTextBuffer allocates the character buffer in the given zone. Thus,
// pointers returned by buffer() have the same lifetime as the zone.
class ZoneTextBuffer : public BaseTextBuffer {
 public:
  explicit ZoneTextBuffer(Zone* zone, intptr_t initial_capacity = 64);
  ~ZoneTextBuffer() {}

  // Allocates a new internal buffer. Thus, the contents of buffers returned by
  // previous calls to buffer() are no longer affected by this object.
  void Clear();

 private:
  bool EnsureCapacity(intptr_t len);
  Zone* zone_;

  DISALLOW_COPY_AND_ASSIGN(ZoneTextBuffer);
};

}  // namespace dart

#endif  // RUNTIME_VM_ZONE_TEXT_BUFFER_H_
