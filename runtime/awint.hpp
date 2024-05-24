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


// Internal definitions for A&W Win32 wrapper routines.
#pragma once

#include <yvals.h>

#include <sdkddkver.h>

#include <Windows.h>

#define _cpp_isleadbyte(c) (__pctype_func()[static_cast<unsigned char>(c)] & _LEADBYTE)

_CRT_BEGIN_C_HEADER

#if _STL_WIN32_WINNT >= _WIN32_WINNT_WIN8

#define __crtGetSystemTimePreciseAsFileTime(lpSystemTimeAsFileTime) \
    GetSystemTimePreciseAsFileTime(lpSystemTimeAsFileTime)

#else // ^^^ _STL_WIN32_WINNT >= _WIN32_WINNT_WIN8 / _STL_WIN32_WINNT < _WIN32_WINNT_WIN8 vvv

_CRTIMP2 void __cdecl __crtGetSystemTimePreciseAsFileTime(_Out_ LPFILETIME lpSystemTimeAsFileTime) noexcept;

#endif // ^^^ _STL_WIN32_WINNT < _WIN32_WINNT_WIN8 ^^^

_CRTIMP2 int __cdecl __crtCompareStringA(_In_z_ LPCWSTR _LocaleName, _In_ DWORD _DwCmpFlags,
    _In_reads_(_CchCount1) LPCSTR _LpString1, _In_ int _CchCount1, _In_reads_(_CchCount2) LPCSTR _LpString2,
    _In_ int _CchCount2, _In_ int _CodePage) noexcept;

_CRTIMP2 int __cdecl __crtCompareStringW(_In_z_ LPCWSTR _LocaleName, _In_ DWORD _DwCmpFlags,
    _In_reads_(_CchCount1) LPCWSTR _LpString1, _In_ int _CchCount1, _In_reads_(_CchCount2) LPCWSTR _LpString2,
    _In_ int _CchCount2) noexcept;

_CRTIMP2 int __cdecl __crtLCMapStringA(_In_opt_z_ LPCWSTR _LocaleName, _In_ DWORD _DwMapFlag,
    _In_reads_(_CchSrc) LPCSTR _LpSrcStr, _In_ int _CchSrc, _Out_writes_opt_(_CchDest) char* _LpDestStr,
    _In_ int _CchDest, _In_ int _CodePage, _In_ BOOL _BError) noexcept;

_CRTIMP2 int __cdecl __crtLCMapStringW(_In_opt_z_ LPCWSTR _LocaleName, _In_ DWORD _DWMapFlag,
    _In_reads_(_CchSrc) LPCWSTR _LpSrcStr, _In_ int _CchSrc, _Out_writes_opt_(_CchDest) wchar_t* _LpDestStr,
    _In_ int _CchDest) noexcept;

_CRT_END_C_HEADER
