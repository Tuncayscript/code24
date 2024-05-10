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

#ifndef RUNTIME_VM_SCOPE_TIMER_H_
#define RUNTIME_VM_SCOPE_TIMER_H_

#include "platform/allocation.h"
#include "platform/globals.h"

#include "src/os.h"

namespace Code {

// Simple utility class for timing a block of code.
class ScopeTimer : public ValueObject {
 public:
  explicit ScopeTimer(const char* name, bool enabled = true)
      : enabled_(enabled), name_(name), start_(0) {
    if (!enabled_) {
      return;
    }
    start_ = OS::GetCurrentMonotonicMicros();
  }

  int64_t GetElapsed() const {
    int64_t end = OS::GetCurrentMonotonicMicros();
    ASSERT(end >= start_);
    return end - start_;
  }

  ~ScopeTimer() {
    if (!enabled_) {
      return;
    }
    int64_t elapsed = GetElapsed();
    double seconds = MicrosecondsToSeconds(elapsed);
    OS::PrintErr("%s: %.2f seconds (%" Pd64 " \u00B5s)\n", name_, seconds,
                 elapsed);
  }

 private:
  const bool enabled_;
  const char* name_;
  int64_t start_;
};

}  // namespace dart

#endif  // RUNTIME_VM_SCOPE_TIMER_H_
