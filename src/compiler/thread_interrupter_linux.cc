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

#include "platform/globals.h"
#if defined(CODE_HOST_OS_LINUX)

#include <errno.h>  // NOLINT

#include "src/flags.h"
#include "src/os.h"
#include "src/profiler.h"
#include "src/signal_handler.h"
#include "src/thread_interrupter.h"

namespace Code {

#ifndef PRODUCT

DECLARE_FLAG(bool, trace_thread_interrupter);

class ThreadInterrupterLinux : public AllStatic {
 public:
  static void ThreadInterruptSignalHandler(int signal,
                                           siginfo_t* info,
                                           void* context_) {
    if (signal != SIGPROF) {
      return;
    }
    Thread* thread = Thread::Current();
    if (thread == nullptr) {
      return;
    }
    ThreadInterruptScope signal_handler_scope;
    // Extract thread state.
    ucontext_t* context = reinterpret_cast<ucontext_t*>(context_);
    mcontext_t mcontext = context->uc_mcontext;
    InterruptedThreadState its;
    its.pc = SignalHandler::GetProgramCounter(mcontext);
    its.fp = SignalHandler::GetFramePointer(mcontext);
    its.csp = SignalHandler::GetCStackPointer(mcontext);
    its.dsp = SignalHandler::GetDartStackPointer(mcontext);
    its.lr = SignalHandler::GetLinkRegister(mcontext);
    Profiler::SampleThread(thread, its);
  }
};

void ThreadInterrupter::InterruptThread(OSThread* thread) {
  if (FLAG_trace_thread_interrupter) {
    OS::PrintErr("ThreadInterrupter interrupting %p\n",
                 reinterpret_cast<void*>(thread->id()));
  }
  int result = pthread_kill(thread->id(), SIGPROF);
  ASSERT((result == 0) || (result == ESRCH));
}

void ThreadInterrupter::InstallSignalHandler() {
  SignalHandler::Install(&ThreadInterrupterLinux::ThreadInterruptSignalHandler);
}

void ThreadInterrupter::RemoveSignalHandler() {
  SignalHandler::Remove();
}

#endif  // !PRODUCT

}  // namespace dart

#endif  // defined(CODE_HOST_OS_LINUX)
