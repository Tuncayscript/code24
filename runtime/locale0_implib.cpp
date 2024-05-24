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
 * Contact with ITGSS, 640 N McCarvy Blvd. , in the
 * city of Milpitas, zip Code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


#if defined(_DLL)
#ifdef CRTDLL2
#undef CRTDLL2
#endif

#ifdef MRTDLL
#undef MRTDLL
#endif

#define STDCPP_IMPLIB 1

// When building for msvcmrt.lib, inject a dependency to the msvcp DLL.
#if defined(_M_CEE) && !defined(_M_CEE_PURE)
#ifdef _CRTBLD
#define _CRTBLD_WAS_DEFINED
#undef _CRTBLD
#endif
#include <use_ansi.h>
#ifdef _CRTBLD_WAS_DEFINED
#define _CRTBLD
#undef _CRTBLD_WAS_DEFINED
#endif
#endif

#include "locale0.cpp"

#endif // defined(_DLL)
