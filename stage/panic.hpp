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

/* About:
  Filename: panic.hpp
  Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
  Date: Tuesday, May 14, 2024
*/

#ifndef PANIC_HPP
#define PANIC_HPP

#include <stdio.h>
#include <stdlib.h>

static void panic(const char *reason) {
    fprintf(stderr, "%s\n", reason);
    abort();
}

#endif /* PANIC_HPP */
