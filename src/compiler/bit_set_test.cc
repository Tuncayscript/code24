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

#include "src/bit_set.h"
#include "platform/assert.h"
#include "src/unit_test.h"

namespace Code {

template <intptr_t Size>
void TestBitSet() {
  BitSet<Size> set;
  EXPECT_EQ(-1, set.Last());
  for (int i = 0; i < Size; ++i) {
    EXPECT_EQ(false, set.Test(i));
    set.Set(i, true);
    EXPECT_EQ(true, set.Test(i));
    EXPECT_EQ(i, set.Last());
    for (int j = 0; j < Size; ++j) {
      intptr_t next = set.Next(j);
      if (j <= i) {
        EXPECT_EQ(i, next);
      } else {
        EXPECT_EQ(-1, next);
      }
    }
    set.Set(i, false);
    EXPECT_EQ(false, set.Test(i));
  }
  set.Reset();
  for (int i = 0; i < Size - 1; ++i) {
    set.Set(i, true);
    for (int j = i + 1; j < Size; ++j) {
      set.Set(j, true);
      EXPECT_EQ(j, set.Last());
      EXPECT_EQ(i, set.ClearLastAndFindPrevious(j));
      EXPECT_EQ(false, set.Test(j));
    }
  }
}

TEST_CASE(BitSetBasic) {
  TestBitSet<8>();
  TestBitSet<42>();
  TestBitSet<128>();
  TestBitSet<200>();
}

}  // namespace dart
