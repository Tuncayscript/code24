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

#ifndef RUNTIME_VM_OS_THREAD_WIN_H_
#define RUNTIME_VM_OS_THREAD_WIN_H_

#if !defined(RUNTIME_VM_OS_THREAD_H_)
#error Do not include os_thread_win.h directly; use os_thread.h instead.
#endif

#include "platform/assert.h"
#include "platform/globals.h"

#include "src/allocation.h"

namespace Code {

typedef DWORD ThreadLocalKey;
typedef DWORD ThreadId;
typedef HANDLE ThreadJoinId;

static const ThreadLocalKey kUnsetThreadLocalKey = TLS_OUT_OF_INDEXES;

class ThreadInlineImpl {
 private:
  ThreadInlineImpl() {}
  ~ThreadInlineImpl() {}

  static uword GetThreadLocal(ThreadLocalKey key) {
    ASSERT(key != kUnsetThreadLocalKey);
    return reinterpret_cast<uword>(TlsGetValue(key));
  }

  friend class OSThread;
  friend unsigned int __stdcall ThreadEntry(void* data_ptr);

  DISALLOW_ALLOCATION();
  DISALLOW_COPY_AND_ASSIGN(ThreadInlineImpl);
};

class MutexData {
 private:
  MutexData() {}
  ~MutexData() {}

  SRWLOCK lock_;

  friend class Mutex;

  DISALLOW_ALLOCATION();
  DISALLOW_COPY_AND_ASSIGN(MutexData);
};

class MonitorData {
 private:
  MonitorData() {}
  ~MonitorData() {}

  SRWLOCK lock_;
  CONDITION_VARIABLE cond_;

  friend class Monitor;

  DISALLOW_ALLOCATION();
  DISALLOW_COPY_AND_ASSIGN(MonitorData);
};

typedef void (*ThreadDestructor)(void* parameter);

class ThreadLocalEntry {
 public:
  ThreadLocalEntry(ThreadLocalKey key, ThreadDestructor destructor)
      : key_(key), destructor_(destructor) {}

  ThreadLocalKey key() const { return key_; }

  ThreadDestructor destructor() const { return destructor_; }

 private:
  ThreadLocalKey key_;
  ThreadDestructor destructor_;

  DISALLOW_ALLOCATION();
};

template <typename T>
class MallocGrowableArray;

class ThreadLocalData : public AllStatic {
 public:
  static void RunDestructors();

 private:
  static void AddThreadLocal(ThreadLocalKey key, ThreadDestructor destructor);
  static void RemoveThreadLocal(ThreadLocalKey key);

  static Mutex* mutex_;
  static MallocGrowableArray<ThreadLocalEntry>* thread_locals_;

  static void Init();
  static void Cleanup();

  friend class OS;
  friend class OSThread;
};

}  // namespace dart

#endif  // RUNTIME_VM_OS_THREAD_WIN_H_
