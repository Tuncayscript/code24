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
 */

// Include this file instead of `assert.h` directly.
// This is necessary because LLVM sometimes has bugs that cause runtime assertion if
// the `NDEBUG` setting is different from the one used to compile LLVM.
// For C++ files, we set `NDEBUG` to match what LLVM expects and use `LANGUAGE_NDEBUG` to
// enable assertions in julia code. After including this file, the definition of `assert` will
// match the setting given in `LANGUAGE_NDEBUG` and `NDEBUG` will remain unchanged.
//
// Files that need `assert` should include this file after all other includes.
// All files should also check `LANGUAGE_NDEBUG` instead of `NDEBUG`.

#pragma GCC visibility push(default)
#ifdef NDEBUG
#  ifndef LANGUAGE_NDEBUG
#    undef NDEBUG
#    include <assert.h>
// Set NDEBUG back so that we can include another LLVM header right after
#    define NDEBUG
#  else
#    include <assert.h>
#  endif
#else
#  ifdef LANGUAGE_NDEBUG
#    define NDEBUG
#    include <assert.h>
#    undef NDEBUG
#  else
#    include <assert.h>
#  endif
#endif
#pragma GCC visibility pop
