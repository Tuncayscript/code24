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
// File: Platform.h
// Purpose: C Index platform decls 
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 22, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


#ifndef PLATFORM_H
#define PLATFORM_H

#ifdef __cplusplus
extern "C" {
#endif

/* MSVC DLL import/export. */
#ifdef _MSC_VER
  #ifdef _CINDEX_LIB_
    #define CINDEX_LINKAGE __declspec(dllexport)
  #else
    #define CINDEX_LINKAGE __declspec(dllimport)
  #endif
#else
  #define CINDEX_LINKAGE
#endif

#ifdef __GNUC__
  #define CINDEX_DEPRECATED __attribute__((deprecated))
#else
  #ifdef _MSC_VER
    #define CINDEX_DEPRECATED __declspec(deprecated)
  #else
    #define CINDEX_DEPRECATED
  #endif
#endif

#ifdef __cplusplus
}
#endif
#endif
