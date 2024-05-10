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

#ifndef RUNTIME_VM_LOG_H_
#define RUNTIME_VM_LOG_H_

#include "src/allocation.h"
#include "src/growable_array.h"
#include "src/os.h"

namespace Code {

class IsolateGroup;
class LogBlock;

#if defined(_MSC_VER)
#define THR_Print(format, ...) Log::Current()->Print(format, __VA_ARGS__)
#else
#define THR_Print(format, ...) Log::Current()->Print(format, ##__VA_ARGS__)
#endif

#define THR_VPrint(format, args) Log::Current()->VPrint(format, args)

typedef void (*LogPrinter)(const char* data);

class Log {
 public:
  explicit Log(LogPrinter printer = nullptr);
  ~Log();

  static Log* Current();

  // Append a formatted string to the log.
  void Print(const char* format, ...) PRINTF_ATTRIBUTE(2, 3);

  void VPrint(const char* format, va_list args);

  // Flush and truncate the log. The log is flushed starting at cursor
  // and truncated to cursor afterwards.
  void Flush(const intptr_t cursor = 0);

  // Clears the log.
  void Clear();

  // Current cursor.
  intptr_t cursor() const;

  // A logger that does nothing.
  static Log* NoOpLog();

 private:
  void TerminateString();
  void EnableManualFlush();
  void DisableManualFlush(const intptr_t cursor);

  // Returns true when flush is required.
  bool ShouldFlush() const;

  // Returns false if we should drop log messages related to 'isolate'.
  static bool ShouldLogForIsolateGroup(const IsolateGroup* isolate);

  static Log noop_log_;
  LogPrinter printer_;
  intptr_t manual_flush_;
  MallocGrowableArray<char> buffer_;

  friend class LogBlock;
  friend class LogTestHelper;
  DISALLOW_COPY_AND_ASSIGN(Log);
};

// Causes all log messages to be buffered until destructor is called.
// Can be nested.
class LogBlock : public StackResource {
 public:
  LogBlock(ThreadState* thread, Log* log)
      : StackResource(thread), log_(log), cursor_(log->cursor()) {
    Initialize();
  }

  LogBlock()
      : StackResource(ThreadState::Current()),
        log_(Log::Current()),
        cursor_(Log::Current()->cursor()) {
    Initialize();
  }

  ~LogBlock();

 private:
  void Initialize();

  Log* const log_;
  const intptr_t cursor_;
};

}  // namespace dart

#endif  // RUNTIME_VM_LOG_H_
