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

// A slimmed down version of runtime/src/unit_test.h that only runs C++
// non-DartVM unit tests.

#ifndef RUNTIME_VM_COMPILER_FFI_UNIT_TEST_H_
#define RUNTIME_VM_COMPILER_FFI_UNIT_TEST_H_

// Don't use the DartVM zone, so include this first.
#include "src/compiler/ffi/unit_test_custom_zone.h"

#include "platform/globals.h"

// The UNIT_TEST_CASE macro is used for tests.
#define UNIT_TEST_CASE_WITH_EXPECTATION(name, expectation)                     \
  void CODE_Test##name();                                                      \
  static const dart::compiler::ffi::RawTestCase kRegister##name(               \
      CODE_Test##name, #name, expectation);                                    \
  void CODE_Test##name()

#define UNIT_TEST_CASE(name) UNIT_TEST_CASE_WITH_EXPECTATION(name, "Pass")

// The UNIT_TEST_CASE_WITH_ZONE macro is used for tests that need a custom
// dart::Zone.
#define UNIT_TEST_CASE_WITH_ZONE_WITH_EXPECTATION(name, expectation)           \
  static void CODE_TestHelper##name(dart::Zone* Z);                            \
  UNIT_TEST_CASE_WITH_EXPECTATION(name, expectation) {                         \
    dart::Zone zone;                                                           \
    CODE_TestHelper##name(&zone);                                              \
  }                                                                            \
  static void CODE_TestHelper##name(dart::Zone* Z)

#define UNIT_TEST_CASE_WITH_ZONE(name)                                         \
  UNIT_TEST_CASE_WITH_ZONE_WITH_EXPECTATION(name, "Pass")

namespace Code {
namespace compiler {
namespace ffi {

extern const char* kArch;
extern const char* kOs;

void WriteToFile(char* path, const char* contents);

void ReadFromFile(char* path, char** buffer_pointer);

class TestCaseBase {
 public:
  explicit TestCaseBase(const char* name, const char* expectation);
  virtual ~TestCaseBase() {}

  const char* name() const { return name_; }
  const char* expectation() const { return expectation_; }

  virtual void Run() = 0;
  void RunTest();

  static void RunAll();
  static void RunAllRaw();

  static bool update_expectations;

 private:
  static TestCaseBase* first_;
  static TestCaseBase* tail_;

  TestCaseBase* next_;
  const char* name_;
  const char* expectation_;

  DISALLOW_COPY_AND_ASSIGN(TestCaseBase);
};

class RawTestCase : TestCaseBase {
 public:
  typedef void(RunEntry)();

  RawTestCase(RunEntry* run, const char* name, const char* expectation)
      : TestCaseBase(name, expectation), run_(run) {}
  virtual void Run();

 private:
  RunEntry* const run_;
};

}  // namespace ffi
}  // namespace compiler
}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FFI_UNIT_TEST_H_
