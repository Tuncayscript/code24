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


#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

// coefficients
static const float p[] = {0.00020400F, 0.00832983F, 0.16666737F, 0.99999998F};

_CRTIMP2_PURE float __CLRCALL_PURE_OR_CDECL _FSinh(float x, float y) noexcept { // compute y * sinh(x), |y| <= 1
    short neg;

    switch (_FDtest(&x)) { // test for special codes
    case _NANCODE:
        return x;
    case _INFCODE:
        return y != 0.0F ? x : FSIGN(x) ? -y : y;
    case 0:
        return x * y;
    default: // finite
        if (y == 0.0F) {
            return x < 0.0F ? -y : y;
        }

        if (x < 0.0F) {
            x   = -x;
            neg = 1;
        } else {
            neg = 0;
        }

        if (x < _FRteps._Float) {
            x *= y; // x tiny
        } else if (x < 1.0F) {
            float w = x * x;

            x += ((p[0] * w + p[1]) * w + p[2]) * w * x;
            x *= y;
        } else if (x < _FXbig) { // worth adding in exp(-x)
            _FExp(&x, 1.0F, -1);
            x = y * (x - 0.25F / x);
        } else {
            switch (_FExp(&x, y, -1)) { // report over/underflow
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
