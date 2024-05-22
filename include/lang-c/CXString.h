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

// About:
// File: CXString.h
// Purpose: C Index strings
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 22, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef CXSTRING_H
#define CXSTRING_H

#include "lang-c/Platform.h"

#ifdef __cplusplus
extern "C" {
#endif

/**
 * \defgroup CINDEX_STRING String manipulation routines
 * \ingroup CINDEX
 *
 * @{
 */

/**
 * A character string.
 *
 * The \c CXString type is used to return strings from the interface when
 * the ownership of that string might differ from one call to the next.
 * Use \c lang_getCString() to retrieve the string data and, once finished
 * with the string data, call \c lang_disposeString() to free the string.
 */
typedef struct {
  const void *data;
  unsigned private_flags;
} CXString;

typedef struct {
  CXString *Strings;
  unsigned Count;
} CXStringSet;

/**
 * Retrieve the character data associated with the given string.
 */
CINDEX_LINKAGE const char *lang_getCString(CXString string);

/**
 * Free the given string.
 */
CINDEX_LINKAGE void lang_disposeString(CXString string);

/**
 * Free the given string set.
 */
CINDEX_LINKAGE void lang_disposeStringSet(CXStringSet *set);

/**
 * @}
 */

#ifdef __cplusplus
}
#endif
#endif
