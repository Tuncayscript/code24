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


#include <mutex>

#include <Windows.h>

_STD_BEGIN
// Returns BOOL, nonzero to indicate success, zero for failure
using _Execute_once_fp_t = int(__stdcall*)(void*, void*, void**);

// TRANSITION, ABI: _Execute_once() is preserved for binary compatibility
_CRTIMP2_PURE int __CLRCALL_PURE_OR_CDECL _Execute_once(
    once_flag& _Flag, _Execute_once_fp_t _Callback, void* _Pv) noexcept { // wrap Win32 InitOnceExecuteOnce()
    static_assert(sizeof(_Flag._Opaque) == sizeof(INIT_ONCE), "invalid size");

    return InitOnceExecuteOnce(
        reinterpret_cast<PINIT_ONCE>(&_Flag._Opaque), reinterpret_cast<PINIT_ONCE_FN>(_Callback), _Pv, nullptr);
}

[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL
    _XGetLastError() { // throw system_error containing GetLastError()
    error_code _Code(static_cast<int>(GetLastError()), _STD system_category());
    _THROW(system_error(_Code));
}
_STD_END
