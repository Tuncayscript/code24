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


// _FDtest function -- IEEE 754 version

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

_CRTIMP2_PURE short __CLRCALL_PURE_OR_CDECL _FDtest(float* px) noexcept { // categorize *px
    const auto ps = reinterpret_cast<_Fval*>(px);

    if ((ps->_Sh[_F0] & _FMASK) == _FMAX << _FOFF) {
        return (ps->_Sh[_F0] & _FFRAC) != 0 || ps->_Sh[_F1] != 0 ? _NANCODE : _INFCODE;
    } else if ((ps->_Sh[_F0] & ~_FSIGN) != 0 || ps->_Sh[_F1] != 0) {
        return (ps->_Sh[_F0] & _FMASK) == 0 ? _DENORM : _FINITE;
    } else {
        return 0;
    }
}

unsigned short* _FPmsw(float* px) noexcept { // get pointer to msw
    return &reinterpret_cast<_Fval*>(px)->_Sh[_F0];
}

_END_EXTERN_C_UNLESS_PURE
