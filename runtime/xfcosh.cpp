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

_CRTIMP2_PURE float __CLRCALL_PURE_OR_CDECL _FCosh(float x, float y) noexcept { // compute y * cosh(x), |y| <= 1
    switch (_FDtest(&x)) { // test for special codes
    case _NANCODE:
    case _INFCODE:
        return x;
    case 0:
        return y;
    default: // finite
        if (y == 0.0) {
            return y;
        }

        if (x < 0.0) {
            x = -x;
        }

        if (x < _FXbig) { // worth adding in exp(-x)
            _FExp(&x, 1.0F, -1);
            return y * (x + 0.25F / x);
        }
        switch (_FExp(&x, y, -1)) { // report over/underflow
        case 0:
            _Feraise(_FE_UNDERFLOW);
            break;
        case _INFCODE:
            _Feraise(_FE_OVERFLOW);
        }
        return x;
    }
}

_END_EXTERN_C_UNLESS_PURE
