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


// _Dtest function -- IEEE 754 version

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

_CRTIMP2_PURE short __CLRCALL_PURE_OR_CDECL _Dtest(double* px) noexcept { // categorize *px
    const auto ps = reinterpret_cast<_Dval*>(px);

    if ((ps->_Sh[_D0] & _DMASK) == _DMAX << _DOFF) {
        return (ps->_Sh[_D0] & _DFRAC) != 0 || ps->_Sh[_D1] != 0 || ps->_Sh[_D2] != 0 || ps->_Sh[_D3] != 0 ? _NANCODE
                                                                                                           : _INFCODE;
    } else if ((ps->_Sh[_D0] & ~_DSIGN) != 0 || ps->_Sh[_D1] != 0 || ps->_Sh[_D2] != 0 || ps->_Sh[_D3] != 0) {
        return (ps->_Sh[_D0] & _DMASK) == 0 ? _DENORM : _FINITE;
    } else {
        return 0;
    }
}

unsigned short* _Pmsw(double* px) noexcept { // get pointer to msw
    return &reinterpret_cast<_Dval*>(px)->_Sh[_D0];
}

_END_EXTERN_C_UNLESS_PURE
