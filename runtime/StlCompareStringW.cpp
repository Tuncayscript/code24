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


#include <cstring> // for wcsnlen

#include <Windows.h>

#include "awint.hpp"

// int __cdecl __crtCompareStringW - Get type information about a wide string.
//
// Purpose:
//   Internal support function. Assumes info in wide string format.
//
// Entry:
//   LPCWSTR  LocaleName  - locale context for the comparison.
//   DWORD    dwCmpFlags  - see https://aka.ms/stl/comparestringex
//   LPCWSTR  lpStringn   - wide string to be compared
//   int      cchCountn   - wide char (word) count (NOT including null terminator)
//                        (-1 if null terminated)
//
// Exit:
//   Success: 1 - if lpString1 <  lpString2
//            2 - if lpString1 == lpString2
//            3 - if lpString1 >  lpString2
//   Failure: 0
extern "C" _CRTIMP2 int __cdecl __crtCompareStringW(_In_z_ LPCWSTR LocaleName, _In_ DWORD dwCmpFlags,
    _In_reads_(cchCount1) LPCWSTR lpString1, _In_ int cchCount1, _In_reads_(cchCount2) LPCWSTR lpString2,
    _In_ int cchCount2) noexcept {
    // CompareString will compare past null terminator. Must find null terminator if in string before cchCountn wide
    // characters.
    if (cchCount1 > 0) {
        cchCount1 = static_cast<int>(wcsnlen(lpString1, cchCount1));
    }

    if (cchCount2 > 0) {
        cchCount2 = static_cast<int>(wcsnlen(lpString2, cchCount2));
    }

    if (!cchCount1 || !cchCount2) {
        return (cchCount1 - cchCount2 == 0) ? 2 : (cchCount1 - cchCount2 < 0) ? 1 : 3;
    }

    return CompareStringEx(LocaleName, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, nullptr, nullptr, 0);
}
