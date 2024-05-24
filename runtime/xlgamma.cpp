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


// moderately accurate lgamma function for random

// TRANSITION, ABI: This should be superseded by the CRT's lgamma().

#include <cmath>

//  #include <random>
_STD_BEGIN
_CRTIMP2_PURE float __CLRCALL_PURE_OR_CDECL _XLgamma(float) noexcept;
_CRTIMP2_PURE double __CLRCALL_PURE_OR_CDECL _XLgamma(double) noexcept;
_CRTIMP2_PURE long double __CLRCALL_PURE_OR_CDECL _XLgamma(long double) noexcept;

float __CLRCALL_PURE_OR_CDECL _XLgamma(float x) noexcept { // moderately accurate log gamma
    static const float coeff[6] = {76.18009172947146F, -86.50532032941677F, 24.01409824083091F, -1.23173972450155F,
        0.1208650973866179E-2F, -0.5395239384953E-5F};

    float val0 = x + 5.5F;
    val0 -= (x + 0.5F) * _STD log(val0);
    float val1 = 1.000000000190015F;
    float y    = x + 1.0F;

    for (int i = 0; i < 6; ++i, y += 1.0) {
        val1 += coeff[i] / y;
    }

    return -val0 + _STD log(2.5066282746310005F * val1 / x);
}

double __CLRCALL_PURE_OR_CDECL _XLgamma(double x) noexcept { // moderately accurate log gamma
    static const double coeff[6] = {76.18009172947146, -86.50532032941677, 24.01409824083091, -1.23173972450155,
        0.1208650973866179E-2, -0.5395239384953E-5};

    double val0 = x + 5.5;
    val0 -= (x + 0.5) * _STD log(val0);
    double val1 = 1.000000000190015;
    double y    = x + 1;

    for (int i = 0; i < 6; ++i, y += 1.0) {
        val1 += coeff[i] / y;
    }

    return -val0 + _STD log(2.5066282746310005 * val1 / x);
}

long double __CLRCALL_PURE_OR_CDECL _XLgamma(long double x) noexcept { // moderately accurate log gamma
    static const long double coeff[6] = {76.18009172947146, -86.50532032941677, 24.01409824083091, -1.23173972450155,
        0.1208650973866179E-2, -0.5395239384953E-5};

    long double val0 = x + 5.5;
    val0 -= (x + 0.5) * _STD log(val0);
    long double val1 = 1.000000000190015;
    long double y    = x + 1;

    for (int i = 0; i < 6; ++i, y += 1.0) {
        val1 += coeff[i] / y;
    }

    return -val0 + _STD log(2.5066282746310005 * val1 / x);
}
_STD_END
