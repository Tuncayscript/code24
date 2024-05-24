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


#include <yvals_core.h>

#if _STL_WIN32_WINNT < _STL_WIN32_WINNT_VISTA

#include <yvals.h>

#include <Windows.h>

// TRANSITION, ABI: preserved for binary compatibility
extern "C" _CRTIMP2 int __cdecl __crtCompareStringEx(_In_opt_ LPCWSTR lpLocaleName, _In_ DWORD dwCmpFlags,
    _In_NLS_string_(cchCount1) LPCWSTR lpString1, _In_ int cchCount1, _In_NLS_string_(cchCount2) LPCWSTR lpString2,
    _In_ int cchCount2) noexcept {
    return CompareStringEx(lpLocaleName, dwCmpFlags, lpString1, cchCount1, lpString2, cchCount2, nullptr, nullptr, 0);
}

// TRANSITION, ABI: preserved for binary compatibility
extern "C" _CRTIMP2 int __cdecl __crtLCMapStringEx(_In_opt_ LPCWSTR lpLocaleName, _In_ DWORD dwMapFlags,
    _In_reads_(cchSrc) LPCWSTR lpSrcStr, _In_ int cchSrc, _Out_writes_opt_(cchDest) LPWSTR lpDestStr,
    _In_ int cchDest) noexcept {
    return LCMapStringEx(lpLocaleName, dwMapFlags, lpSrcStr, cchSrc, lpDestStr, cchDest, nullptr, nullptr, 0);
}

// TRANSITION, ABI: preserved for binary compatibility
extern "C" _CRTIMP2 int __cdecl __crtGetLocaleInfoEx(_In_opt_ LPCWSTR const lpLocaleName, _In_ LCTYPE const LCType,
    _Out_writes_opt_(cchData) LPWSTR const lpLCData, _In_ int const cchData) noexcept {
    return GetLocaleInfoEx(lpLocaleName, LCType, lpLCData, cchData);
}

#endif // _STL_WIN32_WINNT < _STL_WIN32_WINNT_VISTA
