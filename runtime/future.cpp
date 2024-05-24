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


#include <exception>
#include <future>

_STD_BEGIN

// TRANSITION, ABI: preserved for binary compatibility
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Throw_future_error(const error_code& _Code) {
    _THROW(future_error(_Code));
}

// TRANSITION, ABI: preserved for binary compatibility
[[noreturn]] _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Rethrow_future_exception(exception_ptr _Ptr) {
    _STD rethrow_exception(_Ptr);
}

_STD_END
