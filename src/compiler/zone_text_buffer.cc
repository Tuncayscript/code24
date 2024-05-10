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

#include "src/zone_text_buffer.h"

#include "platform/assert.h"
#include "platform/globals.h"
#include "platform/utils.h"
#include "src/object.h"
#include "src/os.h"
#include "src/zone.h"

namespace Code {

ZoneTextBuffer::ZoneTextBuffer(Zone* zone, intptr_t initial_capacity)
    : zone_(zone) {
  ASSERT(initial_capacity > 0);
  buffer_ = reinterpret_cast<char*>(zone->Alloc<char>(initial_capacity));
  capacity_ = initial_capacity;
  buffer_[length_] = '\0';
}

void ZoneTextBuffer::Clear() {
  const intptr_t initial_capacity = 64;
  buffer_ = reinterpret_cast<char*>(zone_->Alloc<char>(initial_capacity));
  capacity_ = initial_capacity;
  length_ = 0;
  buffer_[length_] = '\0';
}

bool ZoneTextBuffer::EnsureCapacity(intptr_t len) {
  intptr_t remaining = capacity_ - length_;
  if (remaining <= len) {
    intptr_t new_capacity = capacity_ + Utils::Maximum(capacity_, len);
    buffer_ = zone_->Realloc<char>(buffer_, capacity_, new_capacity);
    capacity_ = new_capacity;
  }
  return true;
}

}  // namespace dart
