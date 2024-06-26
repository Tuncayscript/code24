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
 *
 */
#ifdef __x86_64__

#include <mach/vm_param.h>
	
    .text
    .private_extern __a2a3_tramphead
    .private_extern __a2a3_firsttramp
    .private_extern __a2a3_nexttramp
    .private_extern __a2a3_trampend

.align PAGE_SHIFT
__a2a3_tramphead:
    popq %r10
    andq $0xFFFFFFFFFFFFFFF8, %r10
    subq $ PAGE_SIZE, %r10
    // %rdi -- first arg -- is address of return value's space. Don't mess with it.
    movq %rsi, %rdx // arg2 -> arg3
    movq (%r10), %rsi // block -> arg2
    jmp  *16(%rsi)

.macro TrampolineEntry
    callq __a2a3_tramphead
    nop
    nop
    nop
.endmacro

.align 5
__a2a3_firsttramp:
    TrampolineEntry
__a2a3_nexttramp:
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry
    TrampolineEntry

__a2a3_trampend:

#endif
