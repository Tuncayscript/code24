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

#include "src/globals.h"
#include "src/instructions.h"
#include "src/signal_handler.h"
#include "src/simulator.h"
#if defined(CODE_HOST_OS_LINUX)

namespace Code {

uintptr_t SignalHandler::GetProgramCounter(const mcontext_t& mcontext) {
  uintptr_t pc = 0;

#if defined(HOST_ARCH_IA32)
  pc = static_cast<uintptr_t>(mcontext.gregs[REG_EIP]);
#elif defined(HOST_ARCH_X64)
  pc = static_cast<uintptr_t>(mcontext.gregs[REG_RIP]);
#elif defined(HOST_ARCH_ARM)
  pc = static_cast<uintptr_t>(mcontext.arm_pc);
#elif defined(HOST_ARCH_ARM64)
  pc = static_cast<uintptr_t>(mcontext.pc);
#elif defined(HOST_ARCH_RISCV32)
  pc = static_cast<uintptr_t>(mcontext.__gregs[REG_PC]);
#elif defined(HOST_ARCH_RISCV64)
  pc = static_cast<uintptr_t>(mcontext.__gregs[REG_PC]);
#else
#error Unsupported architecture.
#endif  // HOST_ARCH_...
  return pc;
}

uintptr_t SignalHandler::GetFramePointer(const mcontext_t& mcontext) {
  uintptr_t fp = 0;

#if defined(HOST_ARCH_IA32)
  fp = static_cast<uintptr_t>(mcontext.gregs[REG_EBP]);
#elif defined(HOST_ARCH_X64)
  fp = static_cast<uintptr_t>(mcontext.gregs[REG_RBP]);
#elif defined(HOST_ARCH_ARM)
  // B1.3.3 Program Status Registers (PSRs)
  if ((mcontext.arm_cpsr & (1 << 5)) != 0) {
    // Thumb mode.
    fp = static_cast<uintptr_t>(mcontext.arm_r7);
  } else {
    // ARM mode.
    fp = static_cast<uintptr_t>(mcontext.arm_fp);
  }
#elif defined(HOST_ARCH_ARM64)
  fp = static_cast<uintptr_t>(mcontext.regs[29]);
#elif defined(HOST_ARCH_RISCV32)
  fp = static_cast<uintptr_t>(mcontext.__gregs[REG_S0]);
#elif defined(HOST_ARCH_RISCV64)
  fp = static_cast<uintptr_t>(mcontext.__gregs[REG_S0]);
#else
#error Unsupported architecture.
#endif  // HOST_ARCH_...

  return fp;
}

uintptr_t SignalHandler::GetCStackPointer(const mcontext_t& mcontext) {
  uintptr_t sp = 0;

#if defined(HOST_ARCH_IA32)
  sp = static_cast<uintptr_t>(mcontext.gregs[REG_ESP]);
#elif defined(HOST_ARCH_X64)
  sp = static_cast<uintptr_t>(mcontext.gregs[REG_RSP]);
#elif defined(HOST_ARCH_ARM)
  sp = static_cast<uintptr_t>(mcontext.arm_sp);
#elif defined(HOST_ARCH_ARM64)
  sp = static_cast<uintptr_t>(mcontext.sp);
#elif defined(HOST_ARCH_RISCV32)
  sp = static_cast<uintptr_t>(mcontext.__gregs[REG_SP]);
#elif defined(HOST_ARCH_RISCV64)
  sp = static_cast<uintptr_t>(mcontext.__gregs[REG_SP]);
#else
#error Unsupported architecture.
#endif  // HOST_ARCH_...
  return sp;
}

uintptr_t SignalHandler::GetDartStackPointer(const mcontext_t& mcontext) {
#if defined(TARGET_ARCH_ARM64) && !defined(USING_SIMULATOR)
  return static_cast<uintptr_t>(mcontext.regs[SPREG]);
#else
  return GetCStackPointer(mcontext);
#endif
}

uintptr_t SignalHandler::GetLinkRegister(const mcontext_t& mcontext) {
  uintptr_t lr = 0;

#if defined(HOST_ARCH_IA32)
  lr = 0;
#elif defined(HOST_ARCH_X64)
  lr = 0;
#elif defined(HOST_ARCH_ARM)
  lr = static_cast<uintptr_t>(mcontext.arm_lr);
#elif defined(HOST_ARCH_ARM64)
  lr = static_cast<uintptr_t>(mcontext.regs[30]);
#elif defined(HOST_ARCH_RISCV32)
  lr = static_cast<uintptr_t>(mcontext.__gregs[REG_RA]);
#elif defined(HOST_ARCH_RISCV64)
  lr = static_cast<uintptr_t>(mcontext.__gregs[REG_RA]);
#else
#error Unsupported architecture.
#endif  // HOST_ARCH_...
  return lr;
}

void SignalHandler::Install(SignalAction action) {
  struct sigaction act = {};
  act.sa_handler = nullptr;
  act.sa_sigaction = action;
  sigemptyset(&act.sa_mask);
  sigaddset(&act.sa_mask, SIGPROF);  // Prevent nested signals.
  act.sa_flags = SA_RESTART | SA_SIGINFO;
  int r = sigaction(SIGPROF, &act, nullptr);
  ASSERT(r == 0);
}

void SignalHandler::Remove() {
  // Ignore future SIGPROF signals because by default SIGPROF will terminate
  // the process and we may have some signals in flight.
  struct sigaction act = {};
  act.sa_handler = SIG_IGN;
  sigemptyset(&act.sa_mask);
  act.sa_flags = 0;
  int r = sigaction(SIGPROF, &act, nullptr);
  ASSERT(r == 0);
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_LINUX)
