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


// mutex support

#include "xmtx.hpp"

_EXTERN_C_UNLESS_PURE

// Win32 critical sections are recursive

_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxinit(_Rmtx* _Mtx) noexcept { // initialize mutex
    InitializeCriticalSectionEx(_Mtx, 4000, 0);
}

_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxdst(_Rmtx* _Mtx) noexcept { // delete mutex
    DeleteCriticalSection(_Mtx);
}

_RELIABILITY_CONTRACT
_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxlock(_Rmtx* _Mtx) noexcept { // lock mutex
#ifdef _M_CEE
    System::Threading::Thread::BeginThreadAffinity();
#endif
    EnterCriticalSection(_Mtx);
}

_RELIABILITY_CONTRACT
_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxunlock(_Rmtx* _Mtx) noexcept { // unlock mutex
    LeaveCriticalSection(_Mtx);
#ifdef _M_CEE
    System::Threading::Thread::EndThreadAffinity();
#endif
}

_END_EXTERN_C_UNLESS_PURE
