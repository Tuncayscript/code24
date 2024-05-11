/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Filename: zalloc.mm
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 11, 2024
// Purpose: Zone Allocator for Language
// Technology: Objective-C++ - LLVM 17.0.1
// Description: Provides packed allocation for data structures the runtime almost never frees.

#include <atomic>
#include <iostream>
#include <private.h>
#include <zalloc.hpp>

namespace Code {
void *AtomicQueue::pop() {
  AtomicQueue l1, l2;

  l1.pair = pair; // non atomic on purpose

  do {
    if (l1.head == nullptr) {
      return nullptr;
    }
    l2.head = l1.head->next;
    l2.gen = l1.gen + 1;
  } while (
      !atomic_pair.compare_exchange_weak(l1.pair, l2.pair, relaxed, relaxed));

  return reinterpret_cast<void *>(l1.head);
}
