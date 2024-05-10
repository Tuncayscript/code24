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

#include "src/fixed_cache.h"
#include <string.h>
#include "platform/assert.h"
#include "src/unit_test.h"

namespace Code {

UNIT_TEST_CASE(FixedCacheEmpty) {
  FixedCache<int, int, 2> cache;
  EXPECT(cache.Lookup(0) == nullptr);
  EXPECT(cache.Lookup(1) == nullptr);
  cache.Insert(1, 2);
  EXPECT(*cache.Lookup(1) == 2);
  EXPECT(cache.Lookup(0) == nullptr);
}

UNIT_TEST_CASE(FixedCacheHalfFull) {
  FixedCache<int, const char*, 8> cache;
  // Insert at end.
  cache.Insert(10, "a");
  cache.Insert(20, "b");
  cache.Insert(40, "c");
  // Insert in the middle.
  cache.Insert(15, "ab");
  cache.Insert(25, "bc");
  // Insert in front.
  cache.Insert(5, "_");
  // Check all items.
  EXPECT(strcmp(*cache.Lookup(5), "_") == 0);
  EXPECT(strcmp(*cache.Lookup(10), "a") == 0);
  EXPECT(strcmp(*cache.Lookup(20), "b") == 0);
  EXPECT(strcmp(*cache.Lookup(40), "c") == 0);
  EXPECT(strcmp(*cache.Lookup(25), "bc") == 0);
  // Nonexistent - front, middle, end.
  EXPECT(cache.Lookup(1) == nullptr);
  EXPECT(cache.Lookup(35) == nullptr);
  EXPECT(cache.Lookup(50) == nullptr);
}

struct Resource {
  Resource() : id(0) { copies++; }
  explicit Resource(int id_) : id(id_) { copies++; }

  Resource(const Resource& r) {
    id = r.id;
    copies++;
  }

  Resource& operator=(const Resource& r) {
    id = r.id;
    return *this;
  }

  ~Resource() { copies--; }

  int id;
  static int copies;
};

int Resource::copies = 0;

UNIT_TEST_CASE(FixedCacheFullResource) {
  {
    FixedCache<int, Resource, 6> cache;
    cache.Insert(10, Resource(2));
    cache.Insert(20, Resource(4));
    cache.Insert(40, Resource(16));
    cache.Insert(30, Resource(8));
    EXPECT(cache.Lookup(40)->id == 16);
    EXPECT(cache.Lookup(5) == nullptr);
    EXPECT(cache.Lookup(0) == nullptr);
    // Insert in the front, middle.
    cache.Insert(5, Resource(1));
    cache.Insert(15, Resource(3));
    cache.Insert(25, Resource(6));
    // 40 got removed by shifting.
    EXPECT(cache.Lookup(40) == nullptr);
    EXPECT(cache.Lookup(5)->id == 1);
    EXPECT(cache.Lookup(15)->id == 3);
    EXPECT(cache.Lookup(25)->id == 6);

    // Insert at end top - 30 gets replaced by 40.
    cache.Insert(40, Resource(16));
    EXPECT(cache.Lookup(40)->id == 16);
    EXPECT(cache.Lookup(30) == nullptr);
  }
  EXPECT(Resource::copies == 0);
}

}  // namespace dart
