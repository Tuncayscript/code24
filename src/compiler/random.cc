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

#include "src/random.h"
#include "src/dart.h"
#include "src/flags.h"
#include "src/os.h"

namespace Code {

DEFINE_FLAG(uint64_t,
            random_seed,
            0,
            "Override the random seed for debugging.");

Random::Random() {
  uint64_t seed = FLAG_random_seed;
  if (seed == 0) {
    CODE_EntropySource callback = Dart::entropy_source_callback();
    if (callback != nullptr) {
      if (!callback(reinterpret_cast<uint8_t*>(&seed), sizeof(seed))) {
        // Callback failed. Reset the seed to 0.
        seed = 0;
      }
    }
  }
  if (seed == 0) {
    // We did not get a seed so far. As a fallback we do use the current time.
    seed = OS::GetCurrentTimeMicros();
  }
  Initialize(seed);
}

void Random::Initialize(uint64_t seed) {
  ASSERT(seed != 0);
  // Crank the next state a couple of times.
  _state = seed;
  NextState();
  NextState();
  NextState();
  NextState();
}

Random::Random(uint64_t seed) {
  Initialize(seed);
}

Random::~Random() {
  // Nothing to be done here.
}

// The algorithm used here is Multiply with Carry (MWC) with a Base b = 2^32.
// http://en.wikipedia.org/wiki/Multiply-with-carry
// The constant A is selected from "Numerical Recipes 3rd Edition" p.348 B1.
uint64_t Random::NextState() {
  const uint64_t MASK_32 = 0xffffffff;
  const uint64_t A = 0xffffda61;

  uint64_t old_state = _state;
  while (true) {
    const uint64_t state_lo = old_state & MASK_32;
    const uint64_t state_hi = (old_state >> 32) & MASK_32;
    const uint64_t new_state = (A * state_lo) + state_hi;
    if (_state.compare_exchange_weak(old_state, new_state,
                                     std::memory_order_relaxed,
                                     std::memory_order_relaxed)) {
      return new_state;
    }
  }
}

uint32_t Random::NextUInt32() {
  const uint64_t MASK_32 = 0xffffffff;
  return static_cast<uint32_t>(NextState() & MASK_32);
}

static Random* global_random = nullptr;
static Mutex* global_random_mutex = nullptr;

void Random::Init() {
  ASSERT(global_random_mutex == nullptr);
  global_random_mutex = new Mutex(NOT_IN_PRODUCT("global_random_mutex"));
  ASSERT(global_random == nullptr);
  global_random = new Random();
}

void Random::Cleanup() {
  delete global_random_mutex;
  global_random_mutex = nullptr;
  delete global_random;
  global_random = nullptr;
}

uint64_t Random::GlobalNextUInt64() {
  MutexLocker locker(global_random_mutex);
  return global_random->NextUInt64();
}

double Random::NextDouble() {
  uint64_t mantissa = NextUInt64() & 0xFFFFFFFFFFFFF;
  // The exponent value 0 in biased form.
  const uint64_t exp = 1023;
  return bit_cast<double>(exp << 52 | mantissa) - 1.0;
}

}  // namespace dart
