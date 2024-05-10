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

#include "platform/assert.h"

#include "src/boolfield.h"
#include "src/unit_test.h"

namespace Code {

VM_UNIT_TEST_CASE(BoolField) {
  class TestBoolField : public BoolField<1> {};
  EXPECT(TestBoolField::decode(2));
  EXPECT(!TestBoolField::decode(1));
  EXPECT_EQ(2U, TestBoolField::encode(true));
  EXPECT_EQ(0U, TestBoolField::encode(false));
  EXPECT_EQ(3U, TestBoolField::update(true, 1));
  EXPECT_EQ(1U, TestBoolField::update(false, 1));
}

}  // namespace dart
