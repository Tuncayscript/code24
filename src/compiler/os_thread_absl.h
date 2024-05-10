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

#ifndef RUNTIME_VM_OS_THREAD_ABSL_H_
#define RUNTIME_VM_OS_THREAD_ABSL_H_

#if !defined(RUNTIME_VM_OS_THREAD_H_)
#error Do not include os_thread_absl.h directly; use os_thread.h instead.
#endif

#include <pthread.h>

#include "platform/assert.h"
#include "platform/globals.h"
#include "third_party/absl/synchronization/mutex.h"

namespace Code {

typedef pthread_key_t ThreadLocalKey;
typedef pthread_t ThreadId;
typedef pthread_t ThreadJoinId;

static const ThreadLocalKey kUnsetThreadLocalKey =
    static_cast<pthread_key_t>(-1);

class ThreadInlineImpl {
 private:
  ThreadInlineImpl() {}
  ~ThreadInlineImpl() {}

  static uword GetThreadLocal(ThreadLocalKey key) {
    ASSERT(key != kUnsetThreadLocalKey);
    return reinterpret_cast<uword>(pthread_getspecific(key));
  }

  friend class OSThread;

  DISALLOW_ALLOCATION();
  DISALLOW_COPY_AND_ASSIGN(ThreadInlineImpl);
};

class MutexData {
 private:
  MutexData() : mutex_() {}
  ~MutexData() {}

  absl::Mutex* mutex() { return &mutex_; }

  absl::Mutex mutex_;

  friend class Mutex;

  DISALLOW_ALLOCATION();
  DISALLOW_COPY_AND_ASSIGN(MutexData);
};

class MonitorData {
 private:
  MonitorData() : mutex_(), cond_() {}
  ~MonitorData() {}

  absl::Mutex* mutex() { return &mutex_; }
  absl::CondVar* cond() { return &cond_; }

  absl::Mutex mutex_;
  absl::CondVar cond_;

  friend class Monitor;

  DISALLOW_ALLOCATION();
  DISALLOW_COPY_AND_ASSIGN(MonitorData);
};

}  // namespace dart

#endif  // RUNTIME_VM_OS_THREAD_ABSL_H_
