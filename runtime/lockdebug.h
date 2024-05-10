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
extern void lockdebug_mutex_lock(mutex_tt<true> *lock);
extern void lockdebug_mutex_try_lock(mutex_tt<true> *lock);
extern void lockdebug_mutex_unlock(mutex_tt<true> *lock);
extern void lockdebug_mutex_assert_locked(mutex_tt<true> *lock);
extern void lockdebug_mutex_assert_unlocked(mutex_tt<true> *lock);

static inline void lockdebug_mutex_lock(mutex_tt<false> *lock) { }
static inline void lockdebug_mutex_try_lock(mutex_tt<false> *lock) { }
static inline void lockdebug_mutex_unlock(mutex_tt<false> *lock) { }
static inline void lockdebug_mutex_assert_locked(mutex_tt<false> *lock) { }
static inline void lockdebug_mutex_assert_unlocked(mutex_tt<false> *lock) { }


extern void lockdebug_monitor_enter(monitor_tt<true> *lock);
extern void lockdebug_monitor_leave(monitor_tt<true> *lock);
extern void lockdebug_monitor_wait(monitor_tt<true> *lock);
extern void lockdebug_monitor_assert_locked(monitor_tt<true> *lock);
extern void lockdebug_monitor_assert_unlocked(monitor_tt<true> *lock);

static inline void lockdebug_monitor_enter(monitor_tt<false> *lock) { }
static inline void lockdebug_monitor_leave(monitor_tt<false> *lock) { }
static inline void lockdebug_monitor_wait(monitor_tt<false> *lock) { }
static inline void lockdebug_monitor_assert_locked(monitor_tt<false> *lock) { }
static inline void lockdebug_monitor_assert_unlocked(monitor_tt<false> *lock) {}


extern void 
lockdebug_recursive_mutex_lock(recursive_mutex_tt<true> *lock);
extern void 
lockdebug_recursive_mutex_unlock(recursive_mutex_tt<true> *lock);
extern void 
lockdebug_recursive_mutex_assert_locked(recursive_mutex_tt<true> *lock);
extern void 
lockdebug_recursive_mutex_assert_unlocked(recursive_mutex_tt<true> *lock);

static inline void 
lockdebug_recursive_mutex_lock(recursive_mutex_tt<false> *lock) { }
static inline void 
lockdebug_recursive_mutex_unlock(recursive_mutex_tt<false> *lock) { }
static inline void 
lockdebug_recursive_mutex_assert_locked(recursive_mutex_tt<false> *lock) { }
static inline void 
lockdebug_recursive_mutex_assert_unlocked(recursive_mutex_tt<false> *lock) { }


extern void lockdebug_rwlock_read(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_try_read_success(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_unlock_read(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_write(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_try_write_success(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_unlock_write(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_assert_reading(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_assert_writing(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_assert_locked(rwlock_tt<true> *lock);
extern void lockdebug_rwlock_assert_unlocked(rwlock_tt<true> *lock);

static inline void lockdebug_rwlock_read(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_try_read_success(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_unlock_read(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_write(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_try_write_success(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_unlock_write(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_assert_reading(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_assert_writing(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_assert_locked(rwlock_tt<false> *) { }
static inline void lockdebug_rwlock_assert_unlocked(rwlock_tt<false> *) { }
