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


// _FDunscale function -- IEEE 754 version

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

short _FDunscale(short* pex, float* px) noexcept { // separate *px to 1/2 <= |frac| < 1 and 2^*pex
    const auto ps = reinterpret_cast<_Fval*>(px);
    short xchar   = (ps->_Sh[_F0] & _FMASK) >> _FOFF;

    if (xchar == _FMAX) { // NaN or INF
        *pex = 0;
        return (ps->_Sh[_F0] & _FFRAC) != 0 || ps->_Sh[_F1] != 0 ? _NANCODE : _INFCODE;
    } else if (0 < xchar || (xchar = _FDnorm(ps)) <= 0) { // finite, reduce to [1/2, 1)
        ps->_Sh[_F0] = (ps->_Sh[_F0] & ~_FMASK) | _FBIAS << _FOFF;
        *pex         = xchar - _FBIAS;
        return _FINITE;
    } else { // zero
        *pex = 0;
        return 0;
    }
}

_END_EXTERN_C_UNLESS_PURE
