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


#include <yvals.h>

_STD_BEGIN
// TRANSITION, ABI: _Debug_message() overloads are preserved for binary compatibility

#ifdef _DEBUG
_CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Debug_message(
    const wchar_t* message, const wchar_t* file, unsigned int line) { // report error and die
    if (::_CrtDbgReportW(_CRT_ASSERT, file, line, nullptr, L"%ls", message) == 1) {
        ::_CrtDbgBreak();
    }
}

_CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Debug_message(
    const unsigned short* message, const unsigned short* file, unsigned int line) { // report error and die
    _Debug_message(reinterpret_cast<const wchar_t*>(message), reinterpret_cast<const wchar_t*>(file), line);
}
#endif // ^^^ defined(_DEBUG) ^^^
_STD_END
