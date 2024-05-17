/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 */

#include "common.h"
#include "../../src/jl_exported_funcs.inc"

// set this option to 1 to get very slightly slower trampolines which however do not trigger
// this linker warning:
//   ld: ./loader_trampolines.o: warning: relocation against `code_***_addr' in read-only section `.text'
//   ld: warning: creating DT_TEXTREL in a shared object
// If you have a large libjulia.so file or other restrictions on using TEXTREL for some
// reason, this may be worthwhile.
// This is not relevant on Windows (though it is valid there), since it always uses
// DT_TEXTREL anyways, and does not support this notion of PIC.
#define USE_PC32 0

#if USE_PC32
.cfi_startproc
language__x86.get_pc_thunk.ax:
    mov    (%esp),%eax
    ret
.cfi_endproc

#define CALL(name) \
    call language__x86.get_pc_thunk.ax; \
    jmpl *(CNAMEADDR(name) - .)(%eax); \

#else

#define CALL(name) \
    jmpl *(CNAMEADDR(name)); \

#endif

#define XX(name) \
DEBUGINFO(CNAME(name)); \
.global CNAME(name); \
.cfi_startproc; \
CNAME(name)##:; \
    CET_START(); \
    CALL(name); \
    ud2; \
.cfi_endproc; \
EXPORT(name); \

LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
#undef XX
