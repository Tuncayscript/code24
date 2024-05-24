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


#include <xutility>

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

// coefficients
static constexpr double p[] = {0.0000000001632881, 0.0000000250483893, 0.0000027557344615, 0.0001984126975233,
    0.0083333333334816, 0.1666666666666574, 1.0000000000000001};

static constexpr size_t NP = std::size(p) - 1;

_CRTIMP2_PURE double __CLRCALL_PURE_OR_CDECL _Sinh(double x, double y) noexcept { // compute y * sinh(x), |y| <= 1
    short neg;

    switch (_Dtest(&x)) { // test for special codes
    case _NANCODE:
        return x;
    case _INFCODE:
        return y != 0.0 ? x : DSIGN(x) ? -y : y;
    case 0:
        return x * y;
    default: // finite
        if (y == 0.0) {
            return x < 0.0 ? -y : y;
        }

        if (x < 0.0) {
            x   = -x;
            neg = 1;
        } else {
            neg = 0;
        }

        if (x < _Rteps._Double) {
            x *= y; // x tiny
        } else if (x < 1.0) {
            double w = x * x;

            x += x * w * _Poly(w, p, NP - 1);
            x *= y;
        } else if (x < _Xbig) { // worth adding in exp(-x)
            _Exp(&x, 1.0, -1);
            x = y * (x - 0.25 / x);
        } else {
            switch (_Exp(&x, y, -1)) { // report over/underflow
            case 0:
                _Feraise(_FE_UNDERFLOW);
                break;
            case _INFCODE:
                _Feraise(_FE_OVERFLOW);
            }
        }

        return neg ? -x : x;
    }
}

_END_EXTERN_C_UNLESS_PURE
