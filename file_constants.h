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

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
const LANGUAGE_O_WRONLY      = O_WRONLY
const LANGUAGE_O_RDONLY      = O_RDONLY
const LANGUAGE_O_RDWR        = O_RDWR
const LANGUAGE_O_APPEND      = O_APPEND
const LANGUAGE_O_CREAT       = O_CREAT
const LANGUAGE_O_EXCL        = O_EXCL
const LANGUAGE_O_TRUNC       = O_TRUNC
#ifdef O_TEMPORARY
const LANGUAGE_O_TEMPORARY = O_TEMPORARY
#else
const LANGUAGE_O_TEMPORARY = 0x0000
#endif
#ifdef O_SHORT_LIVED
const LANGUAGE_O_SHORT_LIVED = O_SHORT_LIVED
#else
const LANGUAGE_O_SHORT_LIVED = 0x0000
#endif
#ifdef O_SEQUENTIAL
const LANGUAGE_O_SEQUENTIAL = O_SEQUENTIAL
#else
const LANGUAGE_O_SEQUENTIAL = 0x0000
#endif
#ifdef O_RANDOM
const LANGUAGE_O_RANDOM = O_RANDOM
#else
const LANGUAGE_O_RANDOM = 0x0000
#endif
#ifdef O_NOCTTY
const LANGUAGE_O_NOCTTY = O_NOCTTY
#else
const LANGUAGE_O_NOCTTY = 0x0000
#endif
#ifdef O_NONBLOCK
const LANGUAGE_O_NONBLOCK = O_NONBLOCK
#else
const LANGUAGE_O_NONBLOCK = 0x0000
#endif
#ifdef O_NDELAY
const LANGUAGE_O_NDELAY = O_NDELAY
#else
const LANGUAGE_O_NDELAY = 0x0000
#endif
#ifdef O_SYNC
const LANGUAGE_O_SYNC = O_SYNC
#else
const LANGUAGE_O_SYNC = 0x0000
#endif
#ifdef O_FSYNC
const LANGUAGE_O_FSYNC = O_FSYNC
#else
const LANGUAGE_O_FSYNC = 0x0000
#endif
#ifdef O_ASYNC
const LANGUAGE_O_ASYNC = O_ASYNC
#else
const LANGUAGE_O_ASYNC = 0x0000
#endif
#ifdef O_LARGEFILE
const LANGUAGE_O_LARGEFILE = O_LARGEFILE
#else
const LANGUAGE_O_LARGEFILE = 0x0000
#endif
#ifdef O_DIRECTORY
const LANGUAGE_O_DIRECTORY = O_DIRECTORY
#else
const LANGUAGE_O_DIRECTORY = 0x0000
#endif
#ifdef O_NOFOLLOW
const LANGUAGE_O_NOFOLLOW = O_NOFOLLOW
#else
const LANGUAGE_O_NOFOLLOW = 0x0000
#endif
#ifdef O_CLOEXEC
const LANGUAGE_O_CLOEXEC = O_CLOEXEC
#else
const LANGUAGE_O_CLOEXEC = 0x0000
#endif
#ifdef O_DIRECT
const LANGUAGE_O_DIRECT = O_DIRECT
#else
const LANGUAGE_O_DIRECT = 0x0000
#endif
#ifdef O_NOATIME
const LANGUAGE_O_NOATIME = O_NOATIME
#else
const LANGUAGE_O_NOATIME = 0x0000
#endif
#ifdef O_PATH
const LANGUAGE_O_PATH = O_PATH
#else
const LANGUAGE_O_PATH = 0x0000
#endif
#ifdef O_TMPFILE
const LANGUAGE_O_TMPFILE = O_TMPFILE
#else
const LANGUAGE_O_TMPFILE = 0x0000
#endif
#ifdef O_DSYNC
const LANGUAGE_O_DSYNC = O_DSYNC
#else
const LANGUAGE_O_DSYNC = 0x0000
#endif
#ifdef O_RSYNC
const LANGUAGE_O_RSYNC = O_RSYNC
#else
const LANGUAGE_O_RSYNC = 0x0000
#endif
