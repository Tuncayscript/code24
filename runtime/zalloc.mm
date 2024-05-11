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

void AtomicQueue::push_list(void *_head, void *_tail) {
  Entry *head = reinterpret_cast<Entry *>(_head);
  Entry *tail = reinterpret_cast<Entry *>(_tail);
  AtomicQueue l1, l2;

  l1.pair = pair; // non atomic load on purpose
  do {
    tail->next = l1.head;
    l2.head = head;
    l2.gen = l1.gen + 1;
  } while (
      !atomic_pair.compare_exchange_weak(l1.pair, l2.pair, release, relaxed));
}

template <class T> constexpr inline T gcd(T a, T b) {
  return b == 0 ? a : gcd(b, a % b);
}

template <class T> AtomicQueue Zone<T, false>::_freelist;

template <class T> T *Zone<T, false>::alloc_slow() {
  // our malloc aligns to 16 bytes and this code should be used for sizes
  // small enough that this should always be an actual malloc bucket.
  //
  // The point of this code is *NOT* speed but optimal density
  constexpr size_t n_elem =
      MALLOC_ALIGNMENT / gcd(sizeof(T), size_t{MALLOC_ALIGNMENT});
  Element *slab = reinterpret_cast<Element *>(::calloc(n_elem, sizeof(T)));
  for (size_t i = 1; i < n_elem - 1; i++) {
    slab[i].next = &slab[i + 1];
  }
  _freelist.push_list(reinterpret_cast<void *>(&slab[1]),
                      reinterpret_cast<void *>(&slab[n_elem - 1]));
  return reinterpret_cast<T *>(&slab[0]);
}

template <class T> T *Zone<T, false>::alloc() {
  void *e = _freelist.pop();
  if (e) {
    memset(e, 0, sizeof(void *));
    return reinterpret_cast<T *>(e);
  }
  return alloc_slow();
}

template <class T> void Zone<T, false>::free(T *ptr) {
  if (ptr) {
    Element *e = reinterpret_cast<Element *>(ptr);
    memset(e->buf, 0, sizeof(e->buf));
    _freelist.push(e);
  }
}

#define ZoneInstantiate(type)                                                  \
  template class Zone<type, sizeof(type) % MALLOC_ALIGNMENT == 0>

ZoneInstantiate(class_rw_t);
ZoneInstantiate(class_rw_ext_t);
}
