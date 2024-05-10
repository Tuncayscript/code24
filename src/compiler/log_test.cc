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

#include "include/code_tools_api.h"
#include "platform/utils.h"
#include "src/code_api_impl.h"
#include "src/code_entry.h"
#include "src/debugger.h"
#include "src/globals.h"
#include "src/isolate.h"
#include "src/log.h"
#include "src/message_handler.h"
#include "src/unit_test.h"

namespace Code {

static const char* test_output_ = nullptr;

static void TestPrinter(const char* buffer) {
  if (test_output_ != nullptr) {
    free(const_cast<char*>(test_output_));
    test_output_ = nullptr;
  }
  test_output_ = Utils::StrDup(buffer);

  // Also print to stdout to see the overall result.
  OS::PrintErr("%s", test_output_);
}

class LogTestHelper : public AllStatic {
 public:
  static void SetPrinter(Log* log, LogPrinter printer) {
    ASSERT(log != nullptr);
    ASSERT(printer != nullptr);
    log->printer_ = printer;
  }

  static void FreeTestOutput() {
    if (test_output_ != nullptr) {
      free(const_cast<char*>(test_output_));
      test_output_ = nullptr;
    }
  }
};

TEST_CASE(Log_Macro) {
  test_output_ = nullptr;
  Log* log = Log::Current();
  LogTestHelper::SetPrinter(log, TestPrinter);

  THR_Print("Hello %s", "World");
  EXPECT_STREQ("Hello World", test_output_);
  THR_Print("SingleArgument");
  EXPECT_STREQ("SingleArgument", test_output_);
  LogTestHelper::FreeTestOutput();
}

TEST_CASE(Log_Basic) {
  test_output_ = nullptr;
  Log* log = new Log(TestPrinter);

  EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
  log->Print("Hello %s", "World");
  EXPECT_STREQ("Hello World", test_output_);

  delete log;
  LogTestHelper::FreeTestOutput();
}

TEST_CASE(Log_Block) {
  test_output_ = nullptr;
  Log* log = new Log(TestPrinter);

  EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
  {
    LogBlock ba(thread, log);
    log->Print("APPLE");
    EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
    {
      LogBlock ba(thread, log);
      log->Print("BANANA");
      EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
    }
    EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
    {
      LogBlock ba(thread, log);
      log->Print("PEAR");
      EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
    }
    EXPECT_EQ(static_cast<const char*>(nullptr), test_output_);
  }
  EXPECT_STREQ("APPLEBANANAPEAR", test_output_);
  delete log;
  LogTestHelper::FreeTestOutput();
}

}  // namespace dart
