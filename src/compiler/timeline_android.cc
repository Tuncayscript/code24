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
#if defined(CODE_HOST_OS_ANDROID) && defined(SUPPORT_TIMELINE)

#include <errno.h>
#include <fcntl.h>
#include <cstdlib>

#include "platform/atomic.h"
#include "platform/signal_blocker.h"
#include "src/isolate.h"
#include "src/json_stream.h"
#include "src/lockers.h"
#include "src/log.h"
#include "src/object.h"
#include "src/service_event.h"
#include "src/thread.h"
#include "src/timeline.h"

namespace Code {

DECLARE_FLAG(bool, trace_timeline);

static int OpenTraceFD() {
  const char* kSystraceDebugPath = "/sys/kernel/debug/tracing/trace_marker";
  const char* kSystracePath = "/sys/kernel/tracing/trace_marker";

  int fd = TEMP_FAILURE_RETRY(::open(kSystracePath, O_WRONLY));
  if (fd < 0) {
    fd = TEMP_FAILURE_RETRY(::open(kSystraceDebugPath, O_WRONLY));
  }

  if (fd < 0 && FLAG_trace_timeline) {
    OS::PrintErr("TimelineEventSystraceRecorder: Could not open `%s` or `%s`\n",
                 kSystraceDebugPath, kSystracePath);
  }
  return fd;
}

TimelineEventSystraceRecorder::TimelineEventSystraceRecorder()
    : TimelineEventPlatformRecorder(), systrace_fd_(OpenTraceFD()) {
  Timeline::set_recorder_discards_clock_values(true);
}

TimelineEventSystraceRecorder::~TimelineEventSystraceRecorder() {
  if (systrace_fd_ >= 0) {
    close(systrace_fd_);
  }
}

intptr_t TimelineEventSystraceRecorder::PrintSystrace(TimelineEvent* event,
                                                      char* buffer,
                                                      intptr_t buffer_size) {
  ASSERT(buffer != nullptr);
  ASSERT(buffer_size > 0);
  buffer[0] = '\0';
  intptr_t length = 0;
  int64_t pid = OS::ProcessId();
  switch (event->event_type()) {
    case TimelineEvent::kBegin: {
      length = Utils::SNPrint(buffer, buffer_size, "B|%" Pd64 "|%s", pid,
                              event->label());
      break;
    }
    case TimelineEvent::kEnd: {
      length = Utils::SNPrint(buffer, buffer_size, "E");
      break;
    }
    case TimelineEvent::kCounter: {
      if (event->arguments_length() > 0) {
        // We only report the first counter value.
        length = Utils::SNPrint(buffer, buffer_size, "C|%" Pd64 "|%s|%s", pid,
                                event->label(), event->arguments()[0].value);
      }
      break;
    }
    case TimelineEvent::kAsyncBegin: {
      length = Utils::SNPrint(buffer, buffer_size, "S|%" Pd64 "|%s|%" Pd64 "",
                              pid, event->label(), event->Id());
      break;
    }
    case TimelineEvent::kAsyncEnd: {
      length = Utils::SNPrint(buffer, buffer_size, "F|%" Pd64 "|%s|%" Pd64 "",
                              pid, event->label(), event->Id());
      break;
    }
    default:
      // Ignore event types that we cannot serialize to the Systrace format.
      break;
  }
  return length;
}

void TimelineEventSystraceRecorder::OnEvent(TimelineEvent* event) {
  if (event == nullptr) {
    return;
  }
  if (systrace_fd_ < 0) {
    return;
  }

  // Serialize to the systrace format.
  const intptr_t kBufferLength = 1024;
  char buffer[kBufferLength];
  const intptr_t event_length = PrintSystrace(event, &buffer[0], kBufferLength);
  if (event_length > 0) {
    ssize_t result;
    // Repeatedly attempt the write while we are being interrupted.
    do {
      result = write(systrace_fd_, buffer, event_length);
    } while ((result == -1L) && (errno == EINTR));
  }
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_ANDROID) && !defined(PRODUCT)
