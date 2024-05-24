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


// force DLL instances

#define __FORCE_INSTANCE

#include <ios>
#include <istream>
#include <locale>
#include <ostream>
#include <streambuf>
#include <xlocale>
#include <xlocmes>
#include <xlocmon>
#include <xlocnum>
#include <xloctime>

_STD_BEGIN

template class _CRTIMP2_PURE_IMPORT _Yarn<char>;
template class _CRTIMP2_PURE_IMPORT _Yarn<wchar_t>;
template class _CRTIMP2_PURE_IMPORT _Yarn<unsigned short>;

_STD_END
