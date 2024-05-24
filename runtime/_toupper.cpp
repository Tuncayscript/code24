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


// convert character to uppercase

#include <yvals.h>

#include <__msvc_xlocinfo_types.hpp>
#include <cctype>
#include <clocale>
#include <cstddef>

#include "awint.hpp"

// remove macro definitions of _toupper() and toupper()
#undef _toupper
#undef toupper

_EXTERN_C_UNLESS_PURE

// int _Toupper(c) - convert character to uppercase
//
// Purpose:
//     _Toupper() is a version of toupper with a locale argument.
//
// Entry:
//     c - int value of character to be converted
//     const _Ctypevec * = pointer to locale info
//
// Exit:
//     returns int value of uppercase representation of c
//
// Exceptions:
//     None.
_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Toupper(int c, const _Ctypevec* ploc) noexcept {
    int size;
    unsigned char inbuffer[3];
    unsigned char outbuffer[3];

    const wchar_t* locale_name;
    UINT codepage;

    if (ploc == nullptr) {
        locale_name = ___lc_locale_name_func()[LC_CTYPE];
        codepage    = ___lc_codepage_func();
    } else {
        locale_name = ploc->_LocaleName;
        codepage    = ploc->_Page;
    }

    if (locale_name == nullptr) {
        if (c >= 'a' && c <= 'z') {
            c = c - ('a' - 'A');
        }

        return c;
    }

    // if checking case of c does not require API call, do it
    if (static_cast<unsigned int>(c) < 256) {
        if (ploc == nullptr) {
            if (!islower(c)) {
                return c;
            }
        } else {
            if (!(ploc->_Table[c] & _LOWER)) {
                return c;
            }
        }
    }

    // convert int c to multibyte string
    if (ploc == nullptr ? _cpp_isleadbyte((c >> 8) & 0xff) : (ploc->_Table[(c >> 8) & 0xff] & _LEADBYTE) != 0) {
        inbuffer[0] = (c >> 8 & 0xff);
        inbuffer[1] = static_cast<unsigned char>(c);
        inbuffer[2] = 0;
        size        = 2;
    } else {
        inbuffer[0] = static_cast<unsigned char>(c);
        inbuffer[1] = 0;
        size        = 1;
    }

    // convert wide char to uppercase
    size = __crtLCMapStringA(locale_name, LCMAP_UPPERCASE, reinterpret_cast<const char*>(inbuffer), size,
        reinterpret_cast<char*>(outbuffer), 3, codepage, TRUE);

    if (size == 0) {
        return c;
    }

    // construct integer return value
    if (size == 1) {
        return static_cast<int>(outbuffer[0]);
    } else {
        return static_cast<int>(outbuffer[1]) | (static_cast<int>(outbuffer[0]) << 8);
    }
}

_END_EXTERN_C_UNLESS_PURE
