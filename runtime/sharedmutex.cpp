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


#include <__msvc_threads_core.hpp>
#include <synchapi.h>

#include "primitives.hpp"

// these declarations must be in sync with those in xthreads.h

extern "C" {
static_assert(sizeof(_Smtx_t) == sizeof(SRWLOCK), "_Smtx_t must be the same size as SRWLOCK.");
static_assert(alignof(_Smtx_t) == alignof(SRWLOCK), "_Smtx_t must be the same alignment as SRWLOCK.");

void __cdecl _Smtx_lock_exclusive(_Smtx_t* smtx) noexcept { // lock shared mutex exclusively
    AcquireSRWLockExclusive(reinterpret_cast<PSRWLOCK>(smtx));
}

void __cdecl _Smtx_lock_shared(_Smtx_t* smtx) noexcept { // lock shared mutex non-exclusively
    AcquireSRWLockShared(reinterpret_cast<PSRWLOCK>(smtx));
}

int __cdecl _Smtx_try_lock_exclusive(_Smtx_t* smtx) noexcept { // try to lock shared mutex exclusively
    return TryAcquireSRWLockExclusive(reinterpret_cast<PSRWLOCK>(smtx));
}

int __cdecl _Smtx_try_lock_shared(_Smtx_t* smtx) noexcept { // try to lock shared mutex non-exclusively
    return TryAcquireSRWLockShared(reinterpret_cast<PSRWLOCK>(smtx));
}

void __cdecl _Smtx_unlock_exclusive(_Smtx_t* smtx) noexcept { // unlock exclusive shared mutex
    _Analysis_assume_lock_held_(*reinterpret_cast<PSRWLOCK>(smtx));
    ReleaseSRWLockExclusive(reinterpret_cast<PSRWLOCK>(smtx));
}

void __cdecl _Smtx_unlock_shared(_Smtx_t* smtx) noexcept { // unlock non-exclusive shared mutex
    ReleaseSRWLockShared(reinterpret_cast<PSRWLOCK>(smtx));
}

void __stdcall _Thrd_sleep_for(const unsigned long ms) noexcept { // suspend current thread for `ms` milliseconds
    Sleep(ms);
}

_Thrd_result __stdcall _Cnd_timedwait_for(const _Cnd_t cond, const _Mtx_t mtx, const unsigned int target_ms) noexcept {
    _Thrd_result res    = _Thrd_result::_Success;
    const auto cs       = &mtx->_Critical_section;
    const auto start_ms = GetTickCount64();

    // TRANSITION: replace with _Mtx_clear_owner(mtx);
    mtx->_Thread_id = -1;
    --mtx->_Count;

    if (!Concurrency::details::_Get_cond_var(cond)->wait_for(cs, target_ms)) { // report timeout
        const auto end_ms = GetTickCount64();
        if (end_ms - start_ms >= target_ms) {
            res = _Thrd_result::_Timedout;
        }
    }
    // TRANSITION: replace with _Mtx_reset_owner(mtx);
    mtx->_Thread_id = static_cast<long>(GetCurrentThreadId());
    ++mtx->_Count;

    return res;
}

} // extern "C"
