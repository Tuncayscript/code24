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

#ifndef LANGUAGE_DIRPATH_H
#define LANGUAGE_DIRPATH_H

#ifdef _OS_WINDOWS_
#define PATHSEPSTRING "\\"
#define PATHLISTSEPSTRING ";"
#if defined(PATH_MAX)
#define LANGUAGE_PATH_MAX PATH_MAX
#else // _COMPILER_CLANG_ may have the name reversed
#define LANGUAGE_PATH_MAX MAX_PATH
#endif
#else
#define PATHSEPSTRING "/"
#define PATHLISTSEPSTRING ":"
#if defined(PATH_MAX)
#define LANGUAGE_PATH_MAX PATH_MAX
#else // many platforms don't have a max path, we define one anyways
#define LANGUAGE_PATH_MAX 1024
#endif
#endif

#endif
