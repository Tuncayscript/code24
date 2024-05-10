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

#include "src/compiler/compiler_timings.h"

namespace Code {

namespace {
#define DEFINE_NAME(Name) #Name,
const char* timer_names[] = {COMPILER_TIMERS_LIST(DEFINE_NAME)};
#undef DEFINE_NAME

}  // namespace

void CompilerTimings::PrintTimers(
    Zone* zone,
    const std::unique_ptr<CompilerTimings::Timers>& timers,
    const Timer& total,
    intptr_t level) {
  const int64_t total_elapsed = total.TotalElapsedTime();

  int64_t total_accounted = 0;
  int64_t total_accounted_cpu = 0;
  for (intptr_t i = 0; i < kNumTimers; i++) {
    const auto& entry = timers->timers_[i];
    total_accounted += entry.TotalElapsedTime();
    total_accounted_cpu += entry.TotalElapsedTimeCpu();
  }

  if (level > 0) {
    // Print (self: ...) timing on the previous line if our amount of time
    // spent outside of nested timers is between 1% and 99%.
    const double kMinInterestingSelfPercent = 1.0;
    const double kMaxInterestingSelfPercent = 99.0;

    const int64_t self = total_elapsed - total_accounted;
    const auto self_pct =
        static_cast<double>(Utils::Abs(self)) * 100 / total_elapsed;
    if (kMinInterestingSelfPercent < self_pct &&
        self_pct < kMaxInterestingSelfPercent) {
      const int64_t self_cpu =
          total.TotalElapsedTimeCpu() - total_accounted_cpu;
      const auto self_timer = Timer(self, self_cpu);
      OS::PrintErr(" (self: [%6.2f%%] %s)\n", self_pct,
                   self_timer.FormatElapsedHumanReadable(zone));
    } else {
      OS::PrintErr("\n");
    }
  }

  // Sort timers by the amount of time elapsed within each one.
  Timer* by_elapsed[kNumTimers];
  for (intptr_t i = 0; i < kNumTimers; i++) {
    by_elapsed[i] = &timers->timers_[i];
  }
  qsort(by_elapsed, kNumTimers, sizeof(Timer*),
        [](const void* pa, const void* pb) -> int {
          const auto a_elapsed =
              (*static_cast<Timer* const*>(pa))->TotalElapsedTime();
          const auto b_elapsed =
              (*static_cast<Timer* const*>(pb))->TotalElapsedTime();
          return b_elapsed < a_elapsed ? -1 : b_elapsed > a_elapsed ? 1 : 0;
        });

  // Print sorted in descending order.
  for (intptr_t i = 0; i < kNumTimers; i++) {
    auto timer = by_elapsed[i];
    if (timer->TotalElapsedTime() > 0) {
      const auto timer_id = static_cast<TimerId>(timer - &timers->timers_[0]);
      const auto pct =
          static_cast<double>(timer->TotalElapsedTime()) * 100 / total_elapsed;
      // Must be int for * width specifier.
      const int indent = static_cast<int>(level * 2);

      // Note: don't emit EOL because PrintTimers can print self timing.
      OS::PrintErr(
          "%*s[%6.2f%%] %-*s %-10s", indent, "", pct, 60 - indent,
          timer_names[timer_id],
          Timer::FormatElapsedHumanReadable(zone, timer->TotalElapsedTime(),
                                            timer->TotalElapsedTimeCpu()));

      // Print nested timers if any or just emit EOL.
      if (timers->nested_[timer_id] != nullptr) {
        PrintTimers(zone, timers->nested_[timer_id], *timer, level + 1);
      } else {
        OS::PrintErr("\n");
      }
    }
  }
}

void CompilerTimings::Print() {
  Zone* zone = Thread::Current()->zone();

  OS::PrintErr("Precompilation took: %s\n",
               total_.FormatElapsedHumanReadable(zone));

  PrintTimers(zone, root_, total_, 0);

  OS::PrintErr("Inlining by outcome\n  Success: %s\n  Failure: %s\n",
               try_inlining_success_.FormatElapsedHumanReadable(zone),
               try_inlining_failure_.FormatElapsedHumanReadable(zone));
}

}  // namespace dart
