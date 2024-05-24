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


// _FDnorm function -- IEEE 754 version

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

short _FDnorm(_Fval* ps) noexcept { // normalize float fraction
    short xchar         = 1;
    unsigned short sign = static_cast<unsigned short>(ps->_Sh[_F0] & _FSIGN);

    if ((ps->_Sh[_F0] &= _FFRAC) != 0 || ps->_Sh[_F1]) { // nonzero, scale
        if (ps->_Sh[_F0] == 0) {
            ps->_Sh[_F0] = ps->_Sh[_F1];
            ps->_Sh[_F1] = 0;
            xchar -= 16;
        }

        for (; ps->_Sh[_F0] < 1 << _FOFF; --xchar) { // shift left by 1
            ps->_Sh[_F0] = static_cast<unsigned short>(ps->_Sh[_F0] << 1 | ps->_Sh[_F1] >> 15);
            ps->_Sh[_F1] <<= 1;
        }
        for (; 1 << (_FOFF + 1) <= ps->_Sh[_F0]; ++xchar) { // shift right by 1
            ps->_Sh[_F1] = static_cast<unsigned short>(ps->_Sh[_F1] >> 1 | ps->_Sh[_F0] << 15);
            ps->_Sh[_F0] >>= 1;
        }
        ps->_Sh[_F0] &= _FFRAC;
    }
    ps->_Sh[_F0] |= sign;
    return xchar;
}

_END_EXTERN_C_UNLESS_PURE
