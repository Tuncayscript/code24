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

#ifndef LANGUAGE_WINUCONTEXT_H
#define LANGUAGE_WINUCONTEXT_H

#include "dtypes.h"

#ifdef __cplusplus
extern "C" {
#endif

#include <setjmp.h>
typedef struct {
    struct stack_t {
        void *ss_sp;
        size_t ss_size;
    } uc_stack;
    jmp_buf uc_mcontext;
#ifdef _COMPILER_TSAN_ENABLED_
    void *tsan_state;
#endif
} win32_ucontext_t;
void language_makecontext(win32_ucontext_t *ucp, void (*func)(void));
void language_swapcontext(win32_ucontext_t *oucp, const win32_ucontext_t *ucp);
void language_setcontext(const win32_ucontext_t *ucp);

#ifdef __cplusplus
}
#endif
#endif
