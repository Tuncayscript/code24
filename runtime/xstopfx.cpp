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


#include <cctype>

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

int _Stopfx(const char** ps, char** endptr) noexcept { // parse prefix of floating-point field
    const char* s = *ps;
    int code      = 0;

    while (isspace(static_cast<unsigned char>(*s))) {
        ++s;
    }

    if (*s == '-') {
        code = FL_NEG;
        ++s;
    } else if (*s == '+') {
        ++s;
    }

    if (*s == 'n' || *s == 'N') { // parse "nan" or fail
        if ((*++s != 'a' && *s != 'A') || (*++s != 'n' && *s != 'N')) { // parse failed, roll back pointer
            s    = *ps;
            code = FL_ERR;
        } else { // parse optional (n-char-sequence)
            const char* q = ++s;

            code = FL_NAN;
            if (*q == '(') { // got '(', skip through ')'
                do {
                    ++q;
                } while (isalnum(static_cast<unsigned char>(*q)) || *q == '_');

                if (*q == ')') {
                    s = ++q;
                }
            }
        }

        if (endptr != nullptr) {
            *endptr = const_cast<char*>(s);
        }
    } else if (*s == 'i' || *s == 'I') { // parse "inf" or fail
        if ((*++s != 'n' && *s != 'N') || (*++s != 'f' && *s != 'F')) { // parse failed, roll back pointer
            s    = *ps;
            code = FL_ERR;
        } else { // parse optional rest of "infinity"
            const char* q = ++s;
            code |= FL_INF;

            if ((*q == 'i' || *q == 'I') //
                && (*++q == 'n' || *q == 'N') //
                && (*++q == 'i' || *q == 'I') //
                && (*++q == 't' || *q == 'T') //
                && (*++q == 'y' || *q == 'Y')) {
                s = ++q;
            }
        }

        if (endptr != nullptr) {
            *endptr = const_cast<char*>(s);
        }
    } else if (*s == '0' && (s[1] == 'x' || s[1] == 'X')) { // test for valid hex field following 0x or 0X
        const char* s1 = s + 2;
        if (*s1 == '.') {
            ++s1;
        }

        if (isxdigit(static_cast<unsigned char>(*s1))) {
            s += 2;
            code |= FL_HEX;
        } else {
            code |= FL_DEC;
        }
    } else {
        code |= FL_DEC;
    }

    *ps = s;
    return code;
}

_END_EXTERN_C_UNLESS_PURE
