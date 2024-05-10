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

#ifndef RUNTIME_VM_SIGNAL_HANDLER_H_
#define RUNTIME_VM_SIGNAL_HANDLER_H_

#include "src/allocation.h"
#include "src/globals.h"

#if defined(CODE_HOST_OS_LINUX)
#include <signal.h>    // NOLINT
#include <ucontext.h>  // NOLINT
#elif defined(CODE_HOST_OS_ANDROID)
#include <signal.h>  // NOLINT
#if !defined(__BIONIC_HAVE_UCONTEXT_T)
#include <asm/sigcontext.h>  // NOLINT
// If ucontext_t is not defined on Android, define it here.
typedef struct sigcontext mcontext_t;
typedef struct ucontext {
  uint32_t uc_flags;
  struct ucontext* uc_link;
  stack_t uc_stack;
  struct sigcontext uc_mcontext;
  uint32_t uc_sigmask;
} ucontext_t;
#endif                       // !defined(__BIONIC_HAVE_UCONTEXT_T)
#elif defined(CODE_HOST_OS_MACOS)
#include <signal.h>        // NOLINT
#include <sys/ucontext.h>  // NOLINT
#elif defined(CODE_HOST_OS_WINDOWS)
// Stub out for windows.
struct siginfo_t;
struct mcontext_t;
struct sigset_t {};
#elif defined(CODE_HOST_OS_FUCHSIA)
#include <signal.h>    // NOLINT
#include <ucontext.h>  // NOLINT
#endif

namespace Code {

typedef void (*SignalAction)(int signal, siginfo_t* info, void* context);

class SignalHandler : public AllStatic {
 public:
  static void Install(SignalAction action);
  static void Remove();
  static uintptr_t GetProgramCounter(const mcontext_t& mcontext);
  static uintptr_t GetFramePointer(const mcontext_t& mcontext);
  static uintptr_t GetCStackPointer(const mcontext_t& mcontext);
  static uintptr_t GetDartStackPointer(const mcontext_t& mcontext);
  static uintptr_t GetLinkRegister(const mcontext_t& mcontext);

#if defined(CODE_HOST_OS_ANDROID)
  // Prepare current thread for handling interrupts. Returns
  // opaque pointer to the allocated state (if any).
  static void* PrepareCurrentThread();

  // Cleanup any state which was created by |PrepareCurrentThread|.
  static void CleanupCurrentThreadState(void* state);
#endif
};

#undef USE_SIGNAL_HANDLER_TRAMPOLINE

}  // namespace dart

#endif  // RUNTIME_VM_SIGNAL_HANDLER_H_
