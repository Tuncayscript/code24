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


// TRANSITION, ABI: The functions in this file are preserved for binary compatibility

#include <stdexcept>

#include <Windows.h>

namespace stdext {
    namespace threads {

        _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtx_new(void*& _Ptr) {
            _Ptr = new CRITICAL_SECTION;
            InitializeCriticalSectionEx(static_cast<CRITICAL_SECTION*>(_Ptr), 4000, 0);
        }

        _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtx_delete(void* _Ptr) {
            DeleteCriticalSection(static_cast<CRITICAL_SECTION*>(_Ptr));
            delete static_cast<CRITICAL_SECTION*>(_Ptr);
        }

        _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtx_lock(void* _Ptr) {
            EnterCriticalSection(static_cast<CRITICAL_SECTION*>(_Ptr));
        }

        _CRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtx_unlock(void* _Ptr) {
            LeaveCriticalSection(static_cast<CRITICAL_SECTION*>(_Ptr));
        }

    } // namespace threads
} // namespace stdext
