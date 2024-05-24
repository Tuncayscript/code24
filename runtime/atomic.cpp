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


// implement shared_ptr spin lock

#include <yvals.h>

#include <synchapi.h>

namespace {
    SRWLOCK _Shared_ptr_lock = SRWLOCK_INIT;
} // unnamed namespace

extern "C" {

_CRTIMP2_PURE void __cdecl _Lock_shared_ptr_spin_lock() noexcept { // TRANSITION, ABI: "spin_lock" name is outdated
    AcquireSRWLockExclusive(&_Shared_ptr_lock);
}

_CRTIMP2_PURE void __cdecl _Unlock_shared_ptr_spin_lock() noexcept { // release previously obtained lock
    _Analysis_assume_lock_held_(_Shared_ptr_lock);
    ReleaseSRWLockExclusive(&_Shared_ptr_lock);
}

} // extern "C"
