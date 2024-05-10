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

#include "src/thread_barrier.h"
#include "platform/assert.h"
#include "src/random.h"
#include "src/thread_pool.h"
#include "src/unit_test.h"

namespace Code {

class FuzzTask : public ThreadPool::Task {
 public:
  FuzzTask(intptr_t num_rounds, ThreadBarrier* barrier, uint64_t seed)
      : num_rounds_(num_rounds), barrier_(barrier), rng_(seed) {}

  virtual void Run() {
    for (intptr_t i = 0; i < num_rounds_; ++i) {
      RandomSleep();
      barrier_->Sync();
    }
    barrier_->Release();
  }

 private:
  void RandomSleep() {
    int64_t ms = rng_.NextUInt32() % 4;
    if (ms > 0) {
      OS::Sleep(ms);
    }
  }

  const intptr_t num_rounds_;
  ThreadBarrier* barrier_;
  Random rng_;
};

VM_UNIT_TEST_CASE(ThreadBarrier) {
  const intptr_t kNumTasks = 5;
  const intptr_t kNumRounds = 500;

  ThreadBarrier* barrier = new ThreadBarrier(kNumTasks + 1, kNumTasks + 1);
  for (intptr_t i = 0; i < kNumTasks; ++i) {
    Dart::thread_pool()->Run<FuzzTask>(kNumRounds, barrier, i + 1);
  }
  for (intptr_t i = 0; i < kNumRounds; ++i) {
    barrier->Sync();
  }
  barrier->Release();
}

}  // namespace dart
