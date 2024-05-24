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


// global lock for locales, etc.

#include <yvals.h>

#include <clocale>
#include <cstdlib>

#include "init_locks.hpp"
#include "xmtx.hpp"

_STD_BEGIN

constexpr int _Max_lock = 8; // must be power of two; TRANSITION, ABI: may be less now

#pragma warning(disable : 4074)
#pragma init_seg(compiler)

static _Rmtx mtx[_Max_lock];
static long init = -1;

#if !defined(MRTDLL)

__thiscall _Init_locks::_Init_locks() noexcept { // initialize locks
    if (InterlockedIncrement(&init) == 0) {
        for (auto& elem : mtx) {
            _Mtxinit(&elem);
        }
    }
}

__thiscall _Init_locks::~_Init_locks() noexcept { // clean up locks
    if (InterlockedDecrement(&init) < 0) {
        for (auto& elem : mtx) {
            _Mtxdst(&elem);
        }
    }
}

#endif // ^^^ !defined(MRTDLL) ^^^

void __cdecl _Init_locks::_Init_locks_ctor(_Init_locks*) noexcept { // initialize locks
    if (InterlockedIncrement(&init) == 0) {
        for (auto& elem : mtx) {
            _Mtxinit(&elem);
        }
    }
}

void __cdecl _Init_locks::_Init_locks_dtor(_Init_locks*) noexcept { // clean up locks
    if (InterlockedDecrement(&init) < 0) {
        for (auto& elem : mtx) {
            _Mtxdst(&elem);
        }
    }
}

static _Init_locks initlocks;

#if !defined(MRTDLL)

__thiscall _Lockit::_Lockit() noexcept : _Locktype(0) { // lock default mutex
    if (_Locktype == _LOCK_LOCALE) {
        _lock_locales();
    } else {
        _Mtxlock(&mtx[0]);
    }
}

__thiscall _Lockit::_Lockit(int kind) noexcept : _Locktype(kind) { // lock the mutex
    if (_Locktype == _LOCK_LOCALE) {
        _lock_locales();
    } else if (_Locktype < _Max_lock) {
        _Mtxlock(&mtx[_Locktype]);
    }
}

__thiscall _Lockit::~_Lockit() noexcept { // unlock the mutex
    if (_Locktype == _LOCK_LOCALE) {
        _unlock_locales();
    } else if (_Locktype < _Max_lock) {
        _Mtxunlock(&mtx[_Locktype]);
    }
}

#endif // ^^^ !defined(MRTDLL) ^^^

void __cdecl _Lockit::_Lockit_ctor(_Lockit*) noexcept { // lock default mutex
    _Mtxlock(&mtx[0]);
}

void __cdecl _Lockit::_Lockit_ctor(_Lockit* _This, int kind) noexcept { // lock the mutex
    if (kind == _LOCK_LOCALE) {
        _lock_locales();
    } else {
        _This->_Locktype = kind & (_Max_lock - 1);
        _Mtxlock(&mtx[_This->_Locktype]);
    }
}

void __cdecl _Lockit::_Lockit_dtor(_Lockit* _This) noexcept { // unlock the mutex
    _Mtxunlock(&mtx[_This->_Locktype]);
}

_RELIABILITY_CONTRACT
void __cdecl _Lockit::_Lockit_ctor(int kind) noexcept { // lock the mutex
    if (kind == _LOCK_LOCALE) {
        _lock_locales();
    } else {
        _Mtxlock(&mtx[kind & (_Max_lock - 1)]);
    }
}

_RELIABILITY_CONTRACT
void __cdecl _Lockit::_Lockit_dtor(int kind) noexcept { // unlock the mutex
    if (kind == _LOCK_LOCALE) {
        _unlock_locales();
    } else {
        _Mtxunlock(&mtx[kind & (_Max_lock - 1)]);
    }
}
_STD_END
