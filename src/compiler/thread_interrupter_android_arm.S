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

// Work around for a bug in old kernels (only fixed in 3.18 Android kernel):
//
// Kernel does not clear If-Then execution state bits when entering ARM signal
// handler which violates requirements imposed by ARM architecture reference.
// Some CPUs look at these bits even while in ARM mode which causes them
// to skip some instructions in the prologue of the signal handler.
//
// To work around the issue we insert enough NOPs in the prologue to ensure
// that no actual instructions are skipped and then branch to the actual
// signal handler.
//
// For the kernel patch that fixes the issue see:
// http://git.kernel.org/cgit/linux/kernel/git/torvalds/linux.git/commit/?id=6ecf830e5029598732e04067e325d946097519cb
//

// Note: can't use CODE_* defines here because this file does not include
// globals.h.
#if !defined(PRODUCT) && defined(__ARMEL__) && defined(__ANDROID__) &&         \
    !defined(__thumb__)

.text

.globl ThreadInterruptSignalHandlerTrampoline
.hidden ThreadInterruptSignalHandlerTrampoline
.type ThreadInterruptSignalHandlerTrampoline, %function
ThreadInterruptSignalHandlerTrampoline:
  // IT (If-Then) instruction makes up to four instructions that follow it
  // conditional.
  nop
  nop
  nop
  nop
  // Tail-call the actual handler.
  // Note: no need to use interworking because we know that we are not
  // compiling for Thumb.
  b ThreadInterruptSignalHandler
.size ThreadInterruptSignalHandlerTrampoline,.-ThreadInterruptSignalHandlerTrampoline

#endif
