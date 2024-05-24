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


#include <yvals_core.h>

#include <cstdlib>
#include <synchapi.h>

// Provides forwarders for InitOnceBeginInitialize and InitOnceComplete for
// environments that can't use /ALTERNATENAME.
// They were originally specific to /clr but are now used in other scenarios.

extern "C" {

int __stdcall __std_init_once_begin_initialize_clr(
    void** _LpInitOnce, unsigned long _DwFlags, int* _FPending, void** _LpContext) noexcept {
    return InitOnceBeginInitialize(reinterpret_cast<LPINIT_ONCE>(_LpInitOnce), _DwFlags, _FPending, _LpContext);
}

int __stdcall __std_init_once_complete_clr(void** _LpInitOnce, unsigned long _DwFlags, void* _LpContext) noexcept {
    return InitOnceComplete(reinterpret_cast<LPINIT_ONCE>(_LpInitOnce), _DwFlags, _LpContext);
}

[[noreturn]] void __stdcall __std_init_once_link_alternate_names_and_abort() noexcept {
    _CSTD abort();
}

#if defined(_M_HYBRID)
// <mutex> uses the forwarder fallbacks for ARM64EC and CHPE.
// Note that ARM64EC nevertheless needs the ALTERNATENAMEs to support x64 object files.
#elif defined(_M_IX86)
#pragma comment(linker, "/ALTERNATENAME:__imp____std_init_once_begin_initialize@16=__imp__InitOnceBeginInitialize@16")
#pragma comment(linker, "/ALTERNATENAME:__imp____std_init_once_complete@12=__imp__InitOnceComplete@12")
#elif defined(_M_X64) || defined(_M_ARM) || defined(_M_ARM64) // Note: includes _M_ARM64EC
#pragma comment(linker, "/ALTERNATENAME:__imp___std_init_once_begin_initialize=__imp_InitOnceBeginInitialize")
#pragma comment(linker, "/ALTERNATENAME:__imp___std_init_once_complete=__imp_InitOnceComplete")
#else // ^^^ known architecture / unknown architecture vvv
#error Unknown architecture
#endif // ^^^ unknown architecture ^^^

} // extern "C"
