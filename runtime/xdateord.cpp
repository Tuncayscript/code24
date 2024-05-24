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


// look up date ordering

#include <locale>

#include <Windows.h>

_EXTERN_C_UNLESS_PURE

_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Getdateorder() noexcept { // return date order for current locale
    const wchar_t* const locale_name = ___lc_locale_name_func()[LC_TIME];
    if (locale_name == nullptr) { // Indicates "C" locale; GetLocaleInfoEx would see this as LOCALE_NAME_USER_DEFAULT
        return std::time_base::mdy;
    }

    wchar_t buf[2] = {0};
    GetLocaleInfoEx(locale_name, LOCALE_ILDATE, buf, static_cast<int>(std::size(buf)));

    switch (buf[0]) {
    case L'0':
        return std::time_base::mdy;
    case L'1':
        return std::time_base::dmy;
    case L'2':
        return std::time_base::ymd;
    default:
        return std::time_base::no_order;
    }
}

_END_EXTERN_C_UNLESS_PURE
