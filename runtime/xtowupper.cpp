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


// _Towupper -- convert wchar_t to upper case

#include <__msvc_xlocinfo_types.hpp>
#include <cwchar>

#include "awint.hpp"

_EXTERN_C_UNLESS_PURE

_CRTIMP2_PURE wchar_t __CLRCALL_PURE_OR_CDECL _Towupper(wchar_t _Ch, const _Ctypevec* _Ctype) noexcept {
    // convert element to upper case
    wchar_t _Res = _Ch;
    if (_Ch != WEOF) {
        if (_Ctype->_LocaleName == nullptr && _Ch < 256) { // handle ASCII character in C locale
            if (L'a' <= _Ch && _Ch <= L'z') {
                _Res = static_cast<wchar_t>(_Ch - L'a' + L'A');
            }
        } else if (__crtLCMapStringW(_Ctype->_LocaleName, LCMAP_UPPERCASE, &_Ch, 1, &_Res, 1) == 0) {
            _Res = _Ch;
        }
    }

    return _Res;
}

#ifdef MRTDLL
_CRTIMP2_PURE unsigned short __CLRCALL_PURE_OR_CDECL _Towupper(unsigned short _Ch, const _Ctypevec* _Ctype) noexcept {
    return _Towupper(static_cast<wchar_t>(_Ch), _Ctype);
}
#endif

_END_EXTERN_C_UNLESS_PURE
