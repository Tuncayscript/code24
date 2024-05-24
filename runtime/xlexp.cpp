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
static const long double p[] = {42.038913947607355L, 10096.353102778762831L, 333228.767219512631062L};
static const long double q[] = {1.0L, 841.167880526530790L, 75730.834075476293976L, 666457.534439025262146L};

static const long double c1     = (22713.0L / 32768.0L);
static const long double c2     = 1.4286068203094172321214581765680755e-6L;
static const long double hugexp = LHUGE_EXP;
static const long double invln2 = 1.4426950408889634073599246810018921L;

_CRTIMP2_PURE short __CLRCALL_PURE_OR_CDECL _LExp(long double* px, long double y, short eoff) noexcept {
    // compute y * e^(*px), (*px) finite, |y| not huge
    if (y == 0.0L) { // zero
        *px = y;
        return 0;
    } else if (*px < -hugexp) { // certain underflow
        *px = _Xfe_underflow(y);
        return 0;
    } else if (hugexp < *px) { // certain overflow
        *px = _Xfe_overflow(y);
        return _INFCODE;
    } else { // xexp won't overflow
        long double g = *px * invln2;
        short xexp    = static_cast<short>(g + (g < 0 ? -0.5L : +0.5L));

        g = xexp;
        g = (*px - g * c1) - g * c2;
        if (-_LEps._Long_double < g && g < _LEps._Long_double) {
            *px = y;
        } else { // g * g worth computing
            const long double z = g * g;
            const long double w = ((z + q[1]) * z + q[2]) * z + q[3];

            g *= (p[0] * z + p[1]) * z + p[2];
            *px = (w + g) / (w - g) * 2.0L * y;
            --xexp;
        }

        const short result_code = _LDscale(px, static_cast<long>(xexp) + eoff);

        switch (result_code) {
        case 0:
            *px = _Xfe_underflow(y);
            break;
        case _INFCODE:
            *px = _Xfe_overflow(y);
            break;
        default:
            break;
        }

        return result_code;
    }
}

_END_EXTERN_C_UNLESS_PURE
