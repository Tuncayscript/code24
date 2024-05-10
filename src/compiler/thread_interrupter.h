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

#ifndef RUNTIME_VM_THREAD_INTERRUPTER_H_
#define RUNTIME_VM_THREAD_INTERRUPTER_H_

#include "src/allocation.h"
#include "src/os_thread.h"
#include "src/signal_handler.h"
#include "src/thread.h"

namespace Code {

struct InterruptedThreadState {
  uintptr_t pc;
  uintptr_t csp;
  uintptr_t dsp;
  uintptr_t fp;
  uintptr_t lr;
};

class ThreadInterrupter : public AllStatic {
 public:
  static void Init();

  static void Startup();
  static void Cleanup();

  // Delay between interrupts.
  static void SetInterruptPeriod(intptr_t period);

  // Wake up the thread interrupter thread.
  static void WakeUp();

  // Interrupt a thread.
  static void InterruptThread(OSThread* thread);

  // Prepare current thread for handling interrupts. Returns
  // opaque pointer to the allocated state (if any).
  static void* PrepareCurrentThread();

  // Cleanup any state which was created by |PrepareCurrentThread|.
  static void CleanupCurrentThreadState(void* state);

 private:
  static constexpr intptr_t kMaxThreads = 4096;
  static bool initialized_;
  static bool shutdown_;
  static bool thread_running_;
  static bool woken_up_;
  static ThreadJoinId interrupter_thread_id_;
  static Monitor* monitor_;
  static intptr_t interrupt_period_;
  static intptr_t current_wait_time_;

  static bool InDeepSleep() {
    return current_wait_time_ == Monitor::kNoTimeout;
  }

  static void ThreadMain(uword parameters);

  static void InstallSignalHandler();

  static void RemoveSignalHandler();

  friend class ThreadInterrupterVisitIsolates;
};

}  // namespace dart

#endif  // RUNTIME_VM_THREAD_INTERRUPTER_H_
