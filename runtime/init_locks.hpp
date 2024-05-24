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


#pragma once

#include <yvals.h>

_STD_BEGIN

class _CRTIMP2_PURE_IMPORT _Init_locks { // initialize mutexes
public:
#ifdef _M_CEE_PURE
    __CLR_OR_THIS_CALL _Init_locks() noexcept {
        _Init_locks_ctor(this);
    }

    __CLR_OR_THIS_CALL ~_Init_locks() noexcept {
        _Init_locks_dtor(this);
    }
#else // ^^^ defined(_M_CEE_PURE) / !defined(_M_CEE_PURE) vvv
    __thiscall _Init_locks() noexcept;
    __thiscall ~_Init_locks() noexcept;
#endif // ^^^ !defined(_M_CEE_PURE) ^^^

private:
    static void __cdecl _Init_locks_ctor(_Init_locks*) noexcept;
    static void __cdecl _Init_locks_dtor(_Init_locks*) noexcept;
};

_STD_END
