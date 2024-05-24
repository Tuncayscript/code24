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


// _Dscale function -- IEEE 754 version

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

short _Dscale(double* px, long lexp) noexcept { // scale *px by 2^xexp with checking
    const auto ps = reinterpret_cast<_Dval*>(px);
    short xchar   = static_cast<short>((ps->_Sh[_D0] & _DMASK) >> _DOFF);

    if (xchar == _DMAX) {
        return (ps->_Sh[_D0] & _DFRAC) != 0 || ps->_Sh[_D1] != 0 || ps->_Sh[_D2] != 0 || ps->_Sh[_D3] != 0 ? _NANCODE
                                                                                                           : _INFCODE;
    } else if (xchar == 0 && 0 < (xchar = _Dnorm(ps))) {
        return 0;
    }

    if (0 < lexp && _DMAX - xchar <= lexp) { // overflow, return +/-INF
        *px = ps->_Sh[_D0] & _DSIGN ? -_Inf._Double : _Inf._Double;
        return _INFCODE;
    } else if (-xchar < lexp) { // finite result, repack
        ps->_Sh[_D0] = static_cast<unsigned short>(ps->_Sh[_D0] & ~_DMASK | (lexp + xchar) << _DOFF);
        return _FINITE;
    } else { // denormalized, scale
        unsigned short sign = static_cast<unsigned short>(ps->_Sh[_D0] & _DSIGN);

        ps->_Sh[_D0] = static_cast<unsigned short>(1 << _DOFF | ps->_Sh[_D0] & _DFRAC);
        lexp += xchar - 1;
        if (lexp < -(48 + 1 + _DOFF) || 0 <= lexp) { // certain underflow, return +/-0
            ps->_Sh[_D0] = sign;
            ps->_Sh[_D1] = 0;
            ps->_Sh[_D2] = 0;
            ps->_Sh[_D3] = 0;
            return 0;
        } else { // nonzero, align fraction
            short xexp         = static_cast<short>(lexp);
            unsigned short psx = 0;

            for (; xexp <= -16; xexp += 16) { // scale by words
                psx          = ps->_Sh[_D3] | (psx != 0 ? 1 : 0);
                ps->_Sh[_D3] = ps->_Sh[_D2];
                ps->_Sh[_D2] = ps->_Sh[_D1];
                ps->_Sh[_D1] = ps->_Sh[_D0];
                ps->_Sh[_D0] = 0;
            }
            if (xexp != 0) { // scale by bits
                xexp         = -xexp;
                psx          = (ps->_Sh[_D3] << (16 - xexp)) | (psx != 0 ? 1 : 0);
                ps->_Sh[_D3] = static_cast<unsigned short>(ps->_Sh[_D3] >> xexp | ps->_Sh[_D2] << (16 - xexp));
                ps->_Sh[_D2] = static_cast<unsigned short>(ps->_Sh[_D2] >> xexp | ps->_Sh[_D1] << (16 - xexp));
                ps->_Sh[_D1] = static_cast<unsigned short>(ps->_Sh[_D1] >> xexp | ps->_Sh[_D0] << (16 - xexp));
                ps->_Sh[_D0] >>= xexp;
            }

            ps->_Sh[_D0] |= sign;
            if ((0x8000 < psx || 0x8000 == psx && (ps->_Sh[_D3] & 0x0001) != 0) && (++ps->_Sh[_D3] & 0xffff) == 0
                && (++ps->_Sh[_D2] & 0xffff) == 0 && (++ps->_Sh[_D1] & 0xffff) == 0) {
                ++ps->_Sh[_D0]; // round up
            } else if (ps->_Sh[_D0] == sign && ps->_Sh[_D1] == 0 && ps->_Sh[_D2] == 0 && ps->_Sh[_D3] == 0) {
                return 0;
            }

            return _FINITE;
        }
    }
}

_END_EXTERN_C_UNLESS_PURE
