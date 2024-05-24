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
static const double p[]    = {1.0, 420.30235984910635, 15132.70094680474802};
static const double q[]    = {30.01511290683317, 3362.72154416553028, 30265.40189360949691};
static const double c1     = 22713.0 / 32768.0;
static const double c2     = 1.4286068203094172321214581765680755e-6;
static const double hugexp = HUGE_EXP;
static const double invln2 = 1.4426950408889634073599246810018921;

_CRTIMP2_PURE short __CLRCALL_PURE_OR_CDECL _Exp(double* px, double y, short eoff) noexcept {
    // compute y * e^(*px), (*px) finite, |y| not huge
    if (y == 0.0) { // zero
        *px = y;
        return 0;
    } else if (*px < -hugexp) { // certain underflow
        *px = _Xfe_underflow(y);
        return 0;
    } else if (hugexp < *px) { // certain overflow
        *px = _Xfe_overflow(y);
        return _INFCODE;
    } else { // xexp won't overflow
        double g   = *px * invln2;
        short xexp = static_cast<short>(g + (g < 0.0 ? -0.5 : +0.5));

        g = xexp;
        g = (*px - g * c1) - g * c2;
        if (-_Eps._Double < g && g < _Eps._Double) {
            *px = y;
        } else { // g * g worth computing
            const double z = g * g;
            const double w = (q[0] * z + q[1]) * z + q[2];

            g *= (z + p[1]) * z + p[2];
            *px = (w + g) / (w - g) * 2.0 * y;
            --xexp;
        }

        const short result_code = _Dscale(px, static_cast<long>(xexp) + eoff);

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
