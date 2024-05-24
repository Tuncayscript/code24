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


// _UShinit members (unsigned short version)

#include <fstream>

_STD_BEGIN

using ushistream = basic_istream<unsigned short, char_traits<unsigned short>>;
using ushostream = basic_ostream<unsigned short, char_traits<unsigned short>>;
using ushfilebuf = basic_filebuf<unsigned short, char_traits<unsigned short>>;

_STD_END

#define wistream ushistream
#define wostream ushostream
#define wfilebuf ushfilebuf
#define _Winit   _UShinit

#include <iostream>

#if defined(_M_CEE_PURE)
_STD_BEGIN
__PURE_APPDOMAIN_GLOBAL extern wistream* _Ptr_wcin  = nullptr;
__PURE_APPDOMAIN_GLOBAL extern wostream* _Ptr_wcout = nullptr;
__PURE_APPDOMAIN_GLOBAL extern wostream* _Ptr_wcerr = nullptr;
__PURE_APPDOMAIN_GLOBAL extern wostream* _Ptr_wclog = nullptr;
_STD_END
#else // ^^^ defined(_M_CEE_PURE) / !defined(_M_CEE_PURE) vvv
_STD_BEGIN
__PURE_APPDOMAIN_GLOBAL extern _CRTDATA2_IMPORT wistream* _Ptr_wcin  = nullptr;
__PURE_APPDOMAIN_GLOBAL extern _CRTDATA2_IMPORT wostream* _Ptr_wcout = nullptr;
__PURE_APPDOMAIN_GLOBAL extern _CRTDATA2_IMPORT wostream* _Ptr_wcerr = nullptr;
__PURE_APPDOMAIN_GLOBAL extern _CRTDATA2_IMPORT wostream* _Ptr_wclog = nullptr;
_STD_END
#include "wiostrea.cpp"
#endif // ^^^ !defined(_M_CEE_PURE) ^^^
