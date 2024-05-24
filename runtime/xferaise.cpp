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

void __CLRCALL_PURE_OR_CDECL _Feraise(int except) noexcept { // report floating-point exception
    if ((except & (_FE_DIVBYZERO | _FE_INVALID)) != 0) {
        errno = EDOM;
    } else if ((except & (_FE_UNDERFLOW | _FE_OVERFLOW)) != 0) {
        errno = ERANGE;
    }
}

_END_EXTERN_C_UNLESS_PURE
