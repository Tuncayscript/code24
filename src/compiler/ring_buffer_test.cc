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

#include "src/ring_buffer.h"
#include "platform/assert.h"
#include "src/unit_test.h"

namespace Code {

TEST_CASE(RingBuffer) {
  RingBuffer<int, 2> buf;
  EXPECT_EQ(0, buf.Size());
  buf.Add(42);
  EXPECT_EQ(1, buf.Size());
  EXPECT_EQ(42, buf.Get(0));
  buf.Add(87);
  EXPECT_EQ(2, buf.Size());
  EXPECT_EQ(87, buf.Get(0));
  EXPECT_EQ(42, buf.Get(1));
  buf.Add(-1);
  EXPECT_EQ(2, buf.Size());
  EXPECT_EQ(-1, buf.Get(0));
  EXPECT_EQ(87, buf.Get(1));
}

}  // namespace dart
