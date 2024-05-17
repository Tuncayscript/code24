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

// Notes:
// bctr: branch to CTR without LR update (tail-call)
// localentry: On PPC functions have a localentry that assumes r2 contains
//             the TOC pointer, and a global entry point that sets r2.
// See 64-Bit ELF V2 ABI Specification: Power Architecture v1.4

#define XX(name) \
.global CNAME(name); \
.type CNAME(name)##, @function; \
.cfi_startproc; \
CNAME(name)##: ; \
    addis 2, 12, .TOC.-CNAME(name)##@ha; \
    addi 2, 2, .TOC.-CNAME(name)##@l; \
    .localentry CNAME(name)##,.-CNAME(name)##; \
    addis 12,2,CNAMEADDR(name)##@toc@ha; \
    ld 12,CNAMEADDR(name)##@toc@l(12); \
    mtctr 12; \
    bctr; \
.cfi_endproc; \
.size CNAME(name)##,.-CNAME(name)##; \

LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
#undef XX
