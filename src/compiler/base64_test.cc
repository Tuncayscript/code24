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

#include "src/base64.h"

#include "platform/assert.h"
#include "src/unit_test.h"

namespace Code {

TEST_CASE(Base64Decode) {
  intptr_t decoded_len;
  uint8_t* decoded_bytes = DecodeBase64("SGVsbG8sIHdvcmxkIQo=", &decoded_len);
  const char expected_bytes[] = "Hello, world!\n";
  intptr_t expected_len = strlen(expected_bytes);
  EXPECT(!memcmp(expected_bytes, decoded_bytes, expected_len));
  EXPECT_EQ(expected_len, decoded_len);
  free(decoded_bytes);
}

TEST_CASE(Base64DecodeMalformed) {
  intptr_t decoded_len;
  EXPECT(DecodeBase64("SomethingMalformed", &decoded_len) == nullptr);
}

TEST_CASE(Base64DecodeEmpty) {
  intptr_t decoded_len;
  EXPECT(DecodeBase64("", &decoded_len) == nullptr);
}
}  // namespace dart
