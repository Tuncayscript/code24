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


#include <cwctype>

#include "xmath.hpp"

_EXTERN_C_UNLESS_PURE

int _WStopfx(const wchar_t** ps, wchar_t** endptr) noexcept { // parse prefix of floating-point field
    const wchar_t* s = *ps;
    int code         = 0;
    while (iswspace(*s)) {
        ++s;
    }

    if (*s == L'-') {
        code = FL_NEG;
        ++s;
    } else if (*s == L'+') {
        ++s;
    }

    if (*s == L'n' || *s == L'N') { // parse "nan" or fail
        if ((*++s != L'a' && *s != L'A') || (*++s != L'n' && *s != L'N')) { // parse failed, roll back pointer
            s    = *ps;
            code = FL_ERR;
        } else { // parse optional (n-char-sequence)
            const wchar_t* q = ++s;
            code             = FL_NAN;
            if (*q == L'(') { // got L'(', skip through L')'
                do {
                    ++q;
                } while (iswalnum(*q) || *q == L'_');

                if (*q == L')') {
                    s = ++q;
                }
            }
        }

        if (endptr != nullptr) {
            *endptr = const_cast<wchar_t*>(s);
        }
    } else if (*s == L'i' || *s == L'I') { // parse "inf" or fail
        if ((*++s != L'n' && *s != L'N') || (*++s != L'f' && *s != L'F')) { // parse failed, roll back pointer
            s    = *ps;
            code = FL_ERR;
        } else { // parse optional rest of L"infinity"
            const wchar_t* q = ++s;
            code |= FL_INF;
            if ((*q == L'i' || *q == L'I') //
                && (*++q == L'n' || *q == L'N') //
                && (*++q == L'i' || *q == L'I') //
                && (*++q == L't' || *q == L'T') //
                && (*++q == L'y' || *q == L'Y')) {
                s = ++q;
            }
        }

        if (endptr != nullptr) {
            *endptr = const_cast<wchar_t*>(s);
        }
    } else if (*s == L'0' && (s[1] == L'x' || s[1] == L'X')) { // test for valid hex field following 0x or 0X
        const wchar_t* s1 = s + 2;
        if (*s1 == L'.') {
            ++s1;
        }

        if (iswxdigit(*s1)) {
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
