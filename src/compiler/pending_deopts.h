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

#ifndef RUNTIME_VM_PENDING_DEOPTS_H_
#define RUNTIME_VM_PENDING_DEOPTS_H_

#if defined(SHOULD_NOT_INCLUDE_RUNTIME)
#error "Should not include runtime"
#endif

#include "src/growable_array.h"

namespace Code {

class PendingLazyDeopt {
 public:
  PendingLazyDeopt(uword fp, uword pc) : fp_(fp), pc_(pc) {}
  uword fp() { return fp_; }
  uword pc() { return pc_; }
  void set_pc(uword pc) { pc_ = pc; }

 private:
  uword fp_;
  uword pc_;
};

class PendingDeopts {
 public:
  enum ClearReason {
    kClearDueToThrow,
    kClearDueToDeopt,
  };
  PendingDeopts();
  ~PendingDeopts();

  bool HasPendingDeopts() { return pending_deopts_->length() > 0; }

  void AddPendingDeopt(uword fp, uword pc);
  uword FindPendingDeopt(uword fp);
  void ClearPendingDeoptsBelow(uword fp, ClearReason reason);
  void ClearPendingDeoptsAtOrBelow(uword fp, ClearReason reason);
  uword RemapExceptionPCForDeopt(uword program_counter,
                                 uword frame_pointer,
                                 bool* clear_deopt);

 private:
  PendingLazyDeopt* FindPendingDeoptRecord(uword fp);

  MallocGrowableArray<PendingLazyDeopt>* pending_deopts_;
};

}  // namespace dart

#endif  // RUNTIME_VM_PENDING_DEOPTS_H_
