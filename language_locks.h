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

#ifndef LANGUAGE_LOCKS_H
#define LANGUAGE_LOCKS_H

#ifdef __cplusplus
extern "C" {
#endif

// Lock acquire and release primitives

// LANGUAGE_LOCK and language_mutex_lock are GC safe points, use uv_mutex_t if that is not desired.
// Always use LANGUAGE_LOCK unless no one holding the lock can trigger a GC or GC
// safepoint. uv_mutex_t should only be needed for GC internal locks.
// The LANGUAGE_LOCK* and LANGUAGE_UNLOCK* macros are no-op for non-threading build
// while the language_mutex_* functions are always locking and unlocking the locks.

LANGUAGE_DLLEXPORT void _language_mutex_init(language_mutex_t *lock, const char *name) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void _language_mutex_wait(language_task_t *self, language_mutex_t *lock, int safepoint);
LANGUAGE_DLLEXPORT void _language_mutex_lock(language_task_t *self, language_mutex_t *lock);
LANGUAGE_DLLEXPORT int _language_mutex_trylock_nogc(language_task_t *self, language_mutex_t *lock) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int _language_mutex_trylock(language_task_t *self, language_mutex_t *lock);
LANGUAGE_DLLEXPORT void _language_mutex_unlock(language_task_t *self, language_mutex_t *lock);
LANGUAGE_DLLEXPORT void _language_mutex_unlock_nogc(language_mutex_t *lock) LANGUAGE_NOTSAFEPOINT;

static inline void language_mutex_wait(language_mutex_t *lock, int safepoint)
{
    _language_mutex_wait(language_current_task, lock, safepoint);
}

static inline void language_mutex_lock_nogc(language_mutex_t *lock) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER
{
#ifndef __clang_gcanalyzer__
    // Hide this body from the analyzer, otherwise it complains that we're calling
    // a non-safepoint from this function. The 0 arguments guarantees that we do
    // not reach the safepoint, but the analyzer can't figure that out
    language_mutex_wait(lock, 0);
#endif
}

#define LANGUAGE_SIGATOMIC_BEGIN() do {               \
        language_current_task->ptls->defer_signal++;  \
        language_signal_fence();                      \
    } while (0)
#define LANGUAGE_SIGATOMIC_END() do {                                 \
        language_signal_fence();                                      \
        if (--language_current_task->ptls->defer_signal == 0) {       \
            language_sigint_safepoint(language_current_task->ptls);         \
        }                                                       \
    } while (0)

#define LANGUAGE_SIGATOMIC_BEGIN_self() do {          \
        self->ptls->defer_signal++;             \
        language_signal_fence();                      \
    } while (0)
#define LANGUAGE_SIGATOMIC_END_self() do {            \
        language_signal_fence();                      \
        if (--self->ptls->defer_signal == 0) {  \
            language_sigint_safepoint(self->ptls);    \
        }                                       \
    } while (0)

static inline void language_mutex_lock(language_mutex_t *lock)
{
    _language_mutex_lock(language_current_task, lock);
}

static inline int language_mutex_trylock_nogc(language_mutex_t *lock) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER
{
    return _language_mutex_trylock_nogc(language_current_task, lock);
}

static inline int language_mutex_trylock(language_mutex_t *lock)
{
    return _language_mutex_trylock(language_current_task, lock);
}

static inline void language_mutex_unlock(language_mutex_t *lock)
{
    _language_mutex_unlock(language_current_task, lock);
}

static inline void language_mutex_unlock_nogc(language_mutex_t *lock) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_LEAVE
{
    _language_mutex_unlock_nogc(lock);
}

static inline void language_mutex_init(language_mutex_t *lock, const char *name) LANGUAGE_NOTSAFEPOINT
{
    _language_mutex_init(lock, name);
}

#define LANGUAGE_MUTEX_INIT(m, name) language_mutex_init(m, name)
#define LANGUAGE_LOCK(m) language_mutex_lock(m)
#define LANGUAGE_UNLOCK(m) language_mutex_unlock(m)
#define LANGUAGE_LOCK_NOGC(m) language_mutex_lock_nogc(m)
#define LANGUAGE_UNLOCK_NOGC(m) language_mutex_unlock_nogc(m)

LANGUAGE_DLLEXPORT void language_lock_value(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_unlock_value(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_lock_field(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_unlock_field(language_mutex_t *v) LANGUAGE_NOTSAFEPOINT;

#ifdef __cplusplus
}
#endif

#endif
