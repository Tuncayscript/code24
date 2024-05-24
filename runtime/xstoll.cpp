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


#include <yvals.h>

#include <cctype>
#include <cerrno>
#include <climits>
#include <cstdlib>

_EXTERN_C_UNLESS_PURE

_CRTIMP2_PURE unsigned long long __CLRCALL_PURE_OR_CDECL _Stoullx(const char*, char**, int, int*) noexcept;

_CRTIMP2_PURE long long __CLRCALL_PURE_OR_CDECL _Stollx(const char* s, char** endptr, int base, int* perr) noexcept {
    // convert string to long long, with checking
    const char* sc;
    char* se;
    char sign;
    unsigned long long x;

    if (endptr == nullptr) {
        endptr = &se;
    }

    sc = s;
    while (isspace(static_cast<unsigned char>(*sc))) {
        ++sc;
    }

    sign = static_cast<char>(*sc == '-' || *sc == '+' ? *sc++ : '+');
    x    = _Stoullx(sc, endptr, base, perr);
    if (sc == *endptr) {
        *endptr = const_cast<char*>(s);
    }

    if (s == *endptr && x != 0 || sign == '+' && LLONG_MAX < x || sign == '-' && (1ull << 63) < x) { // overflow
        errno = ERANGE;
        if (perr != nullptr) {
            *perr = 1;
        }

        return sign == '-' ? LLONG_MIN : LLONG_MAX;
    }

    return static_cast<long long>(sign == '-' ? 0 - x : x);
}

// TRANSITION, ABI: preserved for binary compatibility
_CRTIMP2_PURE long long __CLRCALL_PURE_OR_CDECL _Stoll(const char* s, char** endptr, int base) noexcept {
    // convert string, discard error code
    return _Stollx(s, endptr, base, nullptr);
}

_END_EXTERN_C_UNLESS_PURE
