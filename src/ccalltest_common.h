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
#include <stdio.h>
#include <stdlib.h>
#include <complex.h>
#include <stdint.h>
#include <inttypes.h>

#include "../src/support/platform.h"
#include "../src/support/dtypes.h"

// Borrow definition from `support/dtypes.h`
#ifdef _OS_WINDOWS_
#  define DLLEXPORT __declspec(dllexport)
#else
# if defined(_OS_LINUX_) && !defined(_COMPILER_CLANG_)
// Clang and ld disagree about the proper relocation for STV_PROTECTED, causing
// linker errors.
#  define DLLEXPORT __attribute__ ((visibility("protected")))
# else
#  define DLLEXPORT __attribute__ ((visibility("default")))
# endif
#endif

#ifdef _P64
#define jint int64_t
#define PRIjint PRId64
#else
#define jint int32_t
#define PRIjint PRId32
#endif
