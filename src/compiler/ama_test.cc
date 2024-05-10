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
#include "platform/globals.h"

#include "include/CODE_api.h"

#include "src/constants.h"
#include "src/unit_test.h"

namespace Code {

TEST_CASE(AMA_Test) {
  // NOTE: These are expectations we should strive to maintain. Please reach out
  // to go/dart-ama before changing them.
#if defined(TARGET_ARCH_ARM64)
  COMPILE_ASSERT(R27 == PP);
  COMPILE_ASSERT(R15 == SPREG);
  COMPILE_ASSERT(R26 == THR);
  COMPILE_ASSERT(R21 == DISPATCH_TABLE_REG);
#endif
}

}  // namespace dart
