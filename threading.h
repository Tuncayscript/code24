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

#ifndef THREADING_H
#define THREADING_H

#include <stdint.h>
#ifdef __cplusplus
extern "C" {
#endif

#include "code.h"

#define PROFILE_LANGUAGE_THREADING            0

extern _Atomic(language_ptls_t*) language_all_tls_states LANGUAGE_GLOBALLY_ROOTED; /* thread local storage */

typedef struct _language_threadarg_t {
    int16_t tid;
    uv_barrier_t *barrier;
    void *arg;
} language_threadarg_t;

// each thread must initialize its TLS
language_ptls_t language_init_threadtls(int16_t tid) LANGUAGE_NOTSAFEPOINT;

// provided by a threading infrastructure
void language_init_threadinginfra(void);
void language_parallel_gc_threadfun(void *arg);
void language_concurrent_gc_threadfun(void *arg);
void language_threadfun(void *arg);

#ifdef __cplusplus
}
#endif

#endif  /* THREADING_H */
