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
#if defined(CODE_HOST_OS_ANDROID)

#include <errno.h>        // NOLINT
#include <sys/syscall.h>  // NOLINT

#include "src/flags.h"
#include "src/os.h"
#include "src/profiler.h"
#include "src/signal_handler.h"
#include "src/thread_interrupter.h"

namespace Code {

#ifndef PRODUCT

// Old linux kernels on ARM might require a trampoline to
// work around incorrect Thumb -> ARM transitions.
// See thread_interrupted_android_arm.S for more details.
#if defined(HOST_ARCH_ARM) &&                                                  \
    (defined(CODE_HOST_OS_LINUX) || defined(CODE_HOST_OS_ANDROID)) &&          \
    !defined(__thumb__)
#define USE_SIGNAL_HANDLER_TRAMPOLINE
#endif

DECLARE_FLAG(bool, trace_thread_interrupter);

namespace {
#if defined(USE_SIGNAL_HANDLER_TRAMPOLINE)
extern "C" {
#endif
void ThreadInterruptSignalHandler(int signal, siginfo_t* info, void* context_) {
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
#if defined(USE_SIGNAL_HANDLER_TRAMPOLINE)
}  // extern "C"
#endif
}  // namespace

void ThreadInterrupter::InterruptThread(OSThread* thread) {
  if (FLAG_trace_thread_interrupter) {
    OS::PrintErr("ThreadInterrupter interrupting %p\n",
                 reinterpret_cast<void*>(thread->id()));
  }
  int result = syscall(__NR_tgkill, getpid(), thread->id(), SIGPROF);
  ASSERT((result == 0) || (result == ESRCH));
}

#if defined(USE_SIGNAL_HANDLER_TRAMPOLINE)
// Defined in thread_interrupted_android_arm.S
extern "C" void ThreadInterruptSignalHandlerTrampoline(int signal,
                                                       siginfo_t* info,
                                                       void* context_);
#endif

void ThreadInterrupter::InstallSignalHandler() {
#if defined(USE_SIGNAL_HANDLER_TRAMPOLINE)
  SignalHandler::Install(&ThreadInterruptSignalHandlerTrampoline);
#else
  SignalHandler::Install(&ThreadInterruptSignalHandler);
#endif
}

void ThreadInterrupter::RemoveSignalHandler() {
  SignalHandler::Remove();
}

void* ThreadInterrupter::PrepareCurrentThread() {
  return SignalHandler::PrepareCurrentThread();
}

void ThreadInterrupter::CleanupCurrentThreadState(void* state) {
  SignalHandler::CleanupCurrentThreadState(state);
}

#endif  // !PRODUCT

}  // namespace dart

#endif  // defined(CODE_HOST_OS_ANDROID)
