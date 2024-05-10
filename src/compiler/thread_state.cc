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

#include "src/thread_state.h"

#include "src/handles_impl.h"
#include "src/zone.h"

namespace Code {

ThreadState::ThreadState(bool is_os_thread) : BaseThread(is_os_thread) {}

ThreadState::~ThreadState() {}

bool ThreadState::ZoneIsOwnedByThread(Zone* zone) const {
  ASSERT(zone != nullptr);
  Zone* current = zone_;
  while (current != nullptr) {
    if (current == zone) {
      return true;
    }
    current = current->previous();
  }
  return false;
}

bool ThreadState::IsValidZoneHandle(CODE_Handle object) const {
  Zone* zone = this->zone();
  while (zone != nullptr) {
    if (zone->handles()->IsValidZoneHandle(reinterpret_cast<uword>(object))) {
      return true;
    }
    zone = zone->previous();
  }
  return false;
}

intptr_t ThreadState::CountZoneHandles() const {
  intptr_t count = 0;
  Zone* zone = this->zone();
  while (zone != nullptr) {
    count += zone->handles()->CountZoneHandles();
    zone = zone->previous();
  }
  ASSERT(count >= 0);
  return count;
}

bool ThreadState::IsValidScopedHandle(CODE_Handle object) const {
  Zone* zone = this->zone();
  while (zone != nullptr) {
    if (zone->handles()->IsValidScopedHandle(reinterpret_cast<uword>(object))) {
      return true;
    }
    zone = zone->previous();
  }
  return false;
}

intptr_t ThreadState::CountScopedHandles() const {
  intptr_t count = 0;
  Zone* zone = this->zone();
  while (zone != nullptr) {
    count += zone->handles()->CountScopedHandles();
    zone = zone->previous();
  }
  ASSERT(count >= 0);
  return count;
}

}  // namespace dart
