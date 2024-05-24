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


// ios::Init members

#include <iostream>
_STD_BEGIN

__PURE_APPDOMAIN_GLOBAL int ios_base::Init::_Init_cnt = -1;
int& ios_base::Init::_Init_cnt_func() {
    return ios_base::Init::_Init_cnt;
}

_CRTIMP2_PURE void __cdecl ios_base::Init::_Init_ctor(ios_base::Init*) { // initialize standard streams first time
    if (0 <= _Init_cnt) {
        ++_Init_cnt;
    } else {
        _Init_cnt = 1;
    }
}

_CRTIMP2_PURE void __cdecl ios_base::Init::_Init_dtor(ios_base::Init*) { // flush standard streams last time
    if (--_Init_cnt == 0) { // flush standard streams
        if (_Ptr_cerr != nullptr) {
            _Ptr_cerr->flush();
        }

        if (_Ptr_clog != nullptr) {
            _Ptr_clog->flush();
        }

        if (_Ptr_cout != nullptr) {
            _Ptr_cout->flush();
        }
    }
}
_STD_END
