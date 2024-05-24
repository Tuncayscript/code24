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


// _FDint function -- IEEE 754 version

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

short _FDint(float* px, short xexp) noexcept { // test and drop (scaled) fraction bits
    const auto ps = reinterpret_cast<_Fval*>(px);
    short xchar   = (ps->_Sh[_F0] & _FMASK) >> _FOFF;

    if (xchar == _FMAX) {
        return (ps->_Sh[_F0] & _FFRAC) == 0 && ps->_Sh[_F1] == 0 ? _INFCODE : _NANCODE;
    } else if ((ps->_Sh[_F0] & ~_FSIGN) == 0 && ps->_Sh[_F1] == 0) {
        return 0;
    }

    xchar = (_FBIAS + 16 + _FOFF + 1) - xchar - xexp;
    if (xchar <= 0) {
        return 0; // no frac bits to drop
    } else if ((16 + _FOFF + 1) <= xchar) { // all frac bits
        ps->_Sh[_F0] &= _FSIGN;
        ps->_Sh[_F1] = 0;
        return _FINITE; // report on frac, not result
    } else { // strip out frac bits
        static const unsigned short mask[] = {//
            0x0000, 0x0001, 0x0003, 0x0007, //
            0x000f, 0x001f, 0x003f, 0x007f, //
            0x00ff, 0x01ff, 0x03ff, 0x07ff, //
            0x0fff, 0x1fff, 0x3fff, 0x7fff};
        static const size_t sub[]          = {_F1, _F0};

        unsigned short frac = mask[xchar & 0xf];
        xchar >>= 4;
        frac &= ps->_Sh[sub[xchar]];
        ps->_Sh[sub[xchar]] ^= frac;
        if (0 < xchar) {
            frac |= ps->_Sh[_F1];
            ps->_Sh[_F1] = 0;
        }

        return frac != 0 ? _FINITE : 0;
    }
}

_END_EXTERN_C_UNLESS_PURE
