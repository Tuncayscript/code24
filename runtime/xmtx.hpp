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

#include <cstdlib>

#include <Windows.h>

#ifdef _M_CEE
#define _RELIABILITY_CONTRACT                                                    \
    [System::Runtime::ConstrainedExecution::ReliabilityContract(                 \
        System::Runtime::ConstrainedExecution::Consistency::WillNotCorruptState, \
        System::Runtime::ConstrainedExecution::Cer::Success)]
#else // ^^^ defined(_M_CEE) / !defined(_M_CEE) vvv
#define _RELIABILITY_CONTRACT
#endif // ^^^ !defined(_M_CEE) ^^^

_EXTERN_C_UNLESS_PURE

using _Rmtx = CRITICAL_SECTION;

_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxinit(_Rmtx*) noexcept;
_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxdst(_Rmtx*) noexcept;
_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxlock(_Rmtx*) noexcept;
_MRTIMP2_PURE void __CLRCALL_PURE_OR_CDECL _Mtxunlock(_Rmtx*) noexcept;

_END_EXTERN_C_UNLESS_PURE
