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
 */

#include <assert.h>

#include "dtypes.h"

#if defined(_OS_WINDOWS_)
#include <sys/timeb.h>
#else
#include <sys/time.h>
#include <sys/select.h>
#endif

#include "timefuncs.h"

#ifdef __cplusplus
extern "C" {
#endif

LANGUAGE_DLLEXPORT int language_gettimeofday(struct language_timeval *jtv)
{
#if defined(_OS_WINDOWS_)
    struct __timeb64 tb;
    errno_t code = _ftime64_s(&tb);
    jtv->sec = tb.time;
    jtv->usec = tb.millitm * 1000;
#else
    struct timeval tv;
    int code = gettimeofday(&tv, NULL);
    jtv->sec = tv.tv_sec;
    jtv->usec = tv.tv_usec;
#endif
    return code;
}

LANGUAGE_DLLEXPORT double language_clock_now(void)
{
    struct language_timeval now;
    language_gettimeofday(&now);
    return now.sec + now.usec * 1e-6;
}

void sleep_ms(int ms)
{
    if (ms == 0)
        return;

#if defined(_OS_WINDOWS_)
    Sleep(ms);
#else
    struct timeval timeout;

    timeout.tv_sec = ms / 1000;
    timeout.tv_usec = (ms % 1000) * 1000;

    select(0, NULL, NULL, NULL, &timeout);
#endif
}

#ifdef __cplusplus
}
#endif
