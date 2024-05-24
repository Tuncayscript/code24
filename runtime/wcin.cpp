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


// initialize standard wide input stream

#include <fstream>
#include <iostream>

#include "init_locks.hpp"

#pragma warning(disable : 4074)
#pragma init_seg(compiler)
static std::_Init_locks initlocks;

_STD_BEGIN

__PURE_APPDOMAIN_GLOBAL static wfilebuf wfin(stdin);
#if defined(_M_CEE_PURE)
__PURE_APPDOMAIN_GLOBAL extern wistream wcin(&wfin);
#else
__PURE_APPDOMAIN_GLOBAL extern _CRTDATA2_IMPORT wistream wcin(&wfin);
#endif

struct _Init_wcin { // ensures that wcin is initialized
    __CLR_OR_THIS_CALL _Init_wcin() { // initialize wcin
        _Ptr_wcin = &wcin;
        wcin.tie(_Ptr_wcout);
    }
};
__PURE_APPDOMAIN_GLOBAL static _Init_wcin init_wcin;

_STD_END
