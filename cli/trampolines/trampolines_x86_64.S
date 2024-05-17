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

#define XX(name) \
DEBUGINFO(name); \
.global CNAME(name); \
.cfi_startproc; \
SEH_START1(name); \
CNAME(name)##:; \
SEH_START2(); \
    CET_START(); \
    mov CNAMEADDR(name)(%rip),%r11; \
    jmpq *%r11; \
    ud2; \
SEH_END(); \
.cfi_endproc; \
EXPORT(name); \

LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
#undef XX
