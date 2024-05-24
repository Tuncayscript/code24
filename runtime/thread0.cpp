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


#include <cstdlib>
#include <system_error>
#include <xthreads.h>

_STD_BEGIN

static constexpr const char* msgs[] = {
    // error messages
    "device or resource busy",
    "invalid argument",
    "no such process",
    "not enough memory",
    "operation not permitted",
    "resource deadlock would occur",
    "resource unavailable try again",
};

static constexpr errc codes[] = {
    // system_error codes
    errc::device_or_resource_busy,
    errc::invalid_argument,
    errc::no_such_process,
    errc::not_enough_memory,
    errc::operation_not_permitted,
    errc::resource_deadlock_would_occur,
    errc::resource_unavailable_try_again,
};

[[noreturn]] _CRTIMP2_PURE void __cdecl _Throw_Cpp_error(int code) { // throw error object
    _THROW(system_error(static_cast<int>(codes[code]), _STD generic_category(), msgs[code]));
}

// TRANSITION, ABI: preserved for binary compatibility
[[noreturn]] _CRTIMP2_PURE void __cdecl _Throw_C_error(int code) { // throw error object for C error
    switch (static_cast<_Thrd_result>(code)) { // select the exception
    case _Thrd_result::_Nomem:
    case _Thrd_result::_Timedout:
        _Throw_Cpp_error(_RESOURCE_UNAVAILABLE_TRY_AGAIN);

    case _Thrd_result::_Busy:
        _Throw_Cpp_error(_DEVICE_OR_RESOURCE_BUSY);

    case _Thrd_result::_Error:
        _Throw_Cpp_error(_INVALID_ARGUMENT);

    default:
        _CSTD abort();
    }
}
_STD_END
