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


// _Winit members

#include <iostream>
_STD_BEGIN

__PURE_APPDOMAIN_GLOBAL int _Winit::_Init_cnt = -1;

_CRTIMP2_PURE __thiscall _Winit::_Winit() { // initialize standard wide streams first time
    if (0 <= _Init_cnt) {
        ++_Init_cnt;
    } else {
        _Init_cnt = 1;
    }
}

_CRTIMP2_PURE __thiscall _Winit::~_Winit() noexcept { // flush standard wide streams last time
    if (--_Init_cnt == 0) { // flush standard wide streams
        if (_Ptr_wcout != nullptr) {
            _Ptr_wcout->flush();
        }

        if (_Ptr_wcerr != nullptr) {
            _Ptr_wcerr->flush();
        }

        if (_Ptr_wclog != nullptr) {
            _Ptr_wclog->flush();
        }
    }
    _STD_END
}
