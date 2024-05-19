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

#ifndef LANGUAGE_FASTTLS_H
#define LANGUAGE_FASTTLS_H

#ifdef __cplusplus
#include <atomic>
#define _Atomic(T) std::atomic<T>
#else
#include <stdatomic.h>
#endif

// Thread-local storage access

#ifdef __cplusplus
extern "C" {
#endif

/* Bring in definitions for `_OS_X_`, `LANGUAGE_PATH_MAX` and `PATHSEPSTRING`, `language_ptls_t`, etc... */
#include "platform.h"
#include "dirpath.h"

typedef struct _language_gcframe_t language_gcframe_t;

#if defined(_OS_DARWIN_)
#include <pthread.h>
typedef void *(language_get_pgcstack_func)(pthread_key_t); // aka typeof(pthread_getspecific)
#else
typedef language_gcframe_t **(language_get_pgcstack_func)(void);
#endif

#if !defined(_OS_DARWIN_) && !defined(_OS_WINDOWS_)
#define JULIA_DEFINE_FAST_TLS                                                                   \
static __attribute__((tls_model("local-exec"))) __thread language_gcframe_t **language_pgcstack_localexec;  \
LANGUAGE_DLLEXPORT _Atomic(char) language_pgcstack_static_semaphore;                                        \
LANGUAGE_DLLEXPORT language_gcframe_t **language_get_pgcstack_static(void)                                        \
{                                                                                               \
    return language_pgcstack_localexec;                                                               \
}                                                                                               \
LANGUAGE_DLLEXPORT language_gcframe_t ***language_pgcstack_addr_static(void)                                      \
{                                                                                               \
    return &language_pgcstack_localexec;                                                              \
}
#else
#define JULIA_DEFINE_FAST_TLS
#endif

#ifdef __cplusplus
}
#endif

#endif
