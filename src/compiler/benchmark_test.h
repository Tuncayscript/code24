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

#ifndef RUNTIME_VM_BENCHMARK_TEST_H_
#define RUNTIME_VM_BENCHMARK_TEST_H_

#include "include/CODE_api.h"

#include "src/dart.h"
#include "src/globals.h"
#include "src/isolate.h"
#include "src/object.h"
#include "src/unit_test.h"
#include "src/zone.h"

namespace Code {

DECLARE_FLAG(int, code_heap_size);
DECLARE_FLAG(int, old_gen_growth_space_ratio);

namespace bin {
// Snapshot pieces if we link in a snapshot, otherwise initialized to nullptr.
extern const uint8_t* vm_snapshot_data;
extern const uint8_t* vm_snapshot_instructions;
extern const uint8_t* core_isolate_snapshot_data;
extern const uint8_t* core_isolate_snapshot_instructions;
}  // namespace bin

// The BENCHMARK macros are used for benchmarking a specific functionality
// of the VM.
#define BENCHMARK_HELPER(name, kind)                                           \
  void CODE_Benchmark##name(Benchmark* benchmark);                             \
  static Benchmark kRegister##name(CODE_Benchmark##name, #name, kind);         \
  static void CODE_BenchmarkHelper##name(Benchmark* benchmark,                 \
                                         Thread* thread);                      \
  void CODE_Benchmark##name(Benchmark* benchmark) {                            \
    FLAG_old_gen_growth_space_ratio = 100;                                     \
    BenchmarkIsolateScope __isolate__(benchmark);                              \
    Thread* __thread__ = Thread::Current();                                    \
    ASSERT(__thread__->isolate() == benchmark->isolate());                     \
    CODE_BenchmarkHelper##name(benchmark, __thread__);                         \
  }                                                                            \
  static void CODE_BenchmarkHelper##name(Benchmark* benchmark, Thread* thread)

#define BENCHMARK(name) BENCHMARK_HELPER(name, "RunTime")
#define BENCHMARK_SIZE(name) BENCHMARK_HELPER(name, "CodeSize")
#define BENCHMARK_MEMORY(name) BENCHMARK_HELPER(name, "MemoryUse")

inline CODE_Handle NewString(const char* str) {
  return CODE_NewStringFromCString(str);
}

class Benchmark {
 public:
  typedef void(RunEntry)(Benchmark* benchmark);

  Benchmark(RunEntry* run, const char* name, const char* score_kind)
      : run_(run),
        name_(name),
        score_kind_(score_kind),
        score_(0),
        isolate_(nullptr),
        next_(nullptr) {
    if (first_ == nullptr) {
      first_ = this;
    } else {
      tail_->next_ = this;
    }
    tail_ = this;
  }

  // Accessors.
  const char* name() const { return name_; }
  const char* score_kind() const { return score_kind_; }
  void set_score(int64_t value) { score_ = value; }
  int64_t score() const { return score_; }
  Isolate* isolate() const { return reinterpret_cast<Isolate*>(isolate_); }

  void Run() { (*run_)(this); }
  void RunBenchmark();

  static void RunAll(const char* executable);
  static void SetExecutable(const char* arg) { executable_ = arg; }
  static const char* Executable() { return executable_; }

  void CreateIsolate() {
    isolate_ = TestCase::CreateTestIsolate();
    EXPECT(isolate_ != nullptr);
  }

 private:
  static Benchmark* first_;
  static Benchmark* tail_;
  static const char* executable_;

  RunEntry* const run_;
  const char* name_;
  const char* score_kind_;
  int64_t score_;
  CODE_Isolate isolate_;
  Benchmark* next_;

  DISALLOW_COPY_AND_ASSIGN(Benchmark);
};

class BenchmarkIsolateScope {
 public:
  explicit BenchmarkIsolateScope(Benchmark* benchmark) : benchmark_(benchmark) {
    benchmark->CreateIsolate();
    CODE_EnterScope();  // Create a Dart API scope for unit benchmarks.
  }
  ~BenchmarkIsolateScope() {
    CODE_ExitScope();  // Exit the Dart API scope created for unit tests.
    ASSERT(benchmark_->isolate() == Isolate::Current());
    CODE_ShutdownIsolate();
    benchmark_ = nullptr;
  }
  Benchmark* benchmark() const { return benchmark_; }

 private:
  Benchmark* benchmark_;

  DISALLOW_COPY_AND_ASSIGN(BenchmarkIsolateScope);
};

}  // namespace dart

#endif  // RUNTIME_VM_BENCHMARK_TEST_H_
