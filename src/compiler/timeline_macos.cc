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
#if defined(CODE_HOST_OS_MACOS) && defined(SUPPORT_TIMELINE)

#include "src/log.h"
#include "src/timeline.h"

namespace Code {

TimelineEventMacosRecorder::TimelineEventMacosRecorder()
    : TimelineEventPlatformRecorder() {
  Timeline::set_recorder_discards_clock_values(true);
}

TimelineEventMacosRecorder::~TimelineEventMacosRecorder() {}

void TimelineEventMacosRecorder::OnEvent(TimelineEvent* event) {
  if (event == nullptr) {
    return;
  }

  os_log_t log = event->stream_->macos_log();
  if (!os_signpost_enabled(log)) {
    return;
  }

  const char* label = event->label();
  bool is_static_label = event->stream_->has_static_labels();
  uint8_t _Alignas(16) buffer[64];
  buffer[0] = 0;

  switch (event->event_type()) {
    case TimelineEvent::kInstant:
      if (is_static_label) {
        _os_signpost_emit_with_name_impl(&__dso_handle, log, OS_SIGNPOST_EVENT,
                                         OS_SIGNPOST_ID_EXCLUSIVE, label, "",
                                         buffer, sizeof(buffer));
      } else {
        os_signpost_event_emit(log, OS_SIGNPOST_ID_EXCLUSIVE, "Event", "%s",
                               label);
      }
      break;
    case TimelineEvent::kBegin:
    case TimelineEvent::kAsyncBegin:
      if (is_static_label) {
        _os_signpost_emit_with_name_impl(
            &__dso_handle, log, OS_SIGNPOST_INTERVAL_BEGIN, event->Id(), label,
            "", buffer, sizeof(buffer));
      } else {
        os_signpost_interval_begin(log, event->Id(), "Event", "%s", label);
      }
      break;
    case TimelineEvent::kEnd:
    case TimelineEvent::kAsyncEnd:
      if (is_static_label) {
        _os_signpost_emit_with_name_impl(&__dso_handle, log,
                                         OS_SIGNPOST_INTERVAL_END, event->Id(),
                                         label, "", buffer, sizeof(buffer));
      } else {
        os_signpost_interval_end(log, event->Id(), "Event");
      }
      break;
    case TimelineEvent::kCounter:
      os_signpost_event_emit(log, OS_SIGNPOST_ID_EXCLUSIVE, "Counter", "%s=%s",
                             label, event->arguments()[0].value);
      break;
    default:
      break;
  }
}

}  // namespace dart

#endif  // defined(CODE_HOST_OS_MACOS) && defined(SUPPORT_TIMELINE)
