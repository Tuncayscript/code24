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

#include "src/flags.h"
#include "platform/assert.h"
#include "src/heap/heap.h"
#include "src/unit_test.h"

namespace Code {

DEFINE_FLAG(bool, basic_flag, true, "Testing of a basic boolean flag.");

DECLARE_FLAG(bool, print_flags);

VM_UNIT_TEST_CASE(BasicFlags) {
  EXPECT_EQ(true, FLAG_basic_flag);
  EXPECT_EQ(false, FLAG_verbose_gc);
  EXPECT_EQ(false, FLAG_print_flags);
}

DEFINE_FLAG(bool, parse_flag_bool_test, true, "Flags::Parse (bool) testing");
DEFINE_FLAG(charp, string_opt_test, nullptr, "Testing: string option.");
DEFINE_FLAG(charp, entrypoint_test, "main", "Testing: entrypoint");
DEFINE_FLAG(int, counter, 100, "Testing: int flag");

VM_UNIT_TEST_CASE(ParseFlags) {
  EXPECT_EQ(true, FLAG_parse_flag_bool_test);
  Flags::Parse("no_parse_flag_bool_test");
  EXPECT_EQ(false, FLAG_parse_flag_bool_test);
  Flags::Parse("parse_flag_bool_test");
  EXPECT_EQ(true, FLAG_parse_flag_bool_test);
  Flags::Parse("parse_flag_bool_test=false");
  EXPECT_EQ(false, FLAG_parse_flag_bool_test);
  Flags::Parse("parse_flag_bool_test=true");
  EXPECT_EQ(true, FLAG_parse_flag_bool_test);

  EXPECT_EQ(true, FLAG_string_opt_test == nullptr);
  Flags::Parse("string_opt_test=doobidoo");
  EXPECT_EQ(true, FLAG_string_opt_test != nullptr);
  EXPECT_EQ(0, strcmp(FLAG_string_opt_test, "doobidoo"));
  FLAG_string_opt_test = reinterpret_cast<charp>(0xDEADBEEF);
  Flags::Parse("string_opt_test=foofoo");
  EXPECT_EQ(true, FLAG_string_opt_test != nullptr);
  EXPECT_EQ(0, strcmp(FLAG_string_opt_test, "foofoo"));

  EXPECT_EQ(true, FLAG_entrypoint_test != nullptr);
  EXPECT_EQ(0, strcmp(FLAG_entrypoint_test, "main"));

  EXPECT_EQ(100, FLAG_counter);
  Flags::Parse("counter=-300");
  EXPECT_EQ(-300, FLAG_counter);
  Flags::Parse("counter=$300");
  EXPECT_EQ(-300, FLAG_counter);
}

}  // namespace dart
