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

/* Bring in definitions for `_OS_X_`, `LANGUAGE_PATH_MAX` and `PATHSEPSTRING`, `jl_ptls_t`, etc... */
#include "../src/support/platform.h"
#include "../src/support/dirpath.h"
#include "../src/language_fasttls.h"

#ifdef _OS_WINDOWS_

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#else

#ifdef _OS_DARWIN_
#include <mach-o/dyld.h>
#endif
#ifdef _OS_FREEBSD_
#include <stddef.h>
#include <sys/sysctl.h>
#endif
#define _GNU_SOURCE // Need this for `dladdr()`
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <libgen.h>
#include <unistd.h>
#include <dlfcn.h>
#include <signal.h>

#endif

#include <stdint.h>

// Borrow definition from `support/dtypes.h`
#ifdef _OS_WINDOWS_
# ifdef LANGUAGE_LIBRARY_EXPORTS
#  define LANGUAGE_DLLEXPORT __declspec(dllexport)
# endif
#  define LANGUAGE_DLLIMPORT __declspec(dllimport)
#define LANGUAGE_HIDDEN
#else
# define LANGUAGE_DLLIMPORT __attribute__ ((visibility("default")))
#define LANGUAGE_HIDDEN    __attribute__ ((visibility("hidden")))
#endif
#ifndef LANGUAGE_DLLEXPORT
#  define LANGUAGE_DLLEXPORT LANGUAGE_DLLIMPORT
#endif
/*
 * DEP_LIBS is our list of dependent libraries that must be loaded before `libjulia`.
 * Note that order matters, as each entry will be opened in-order.  We define here a
 * dummy value just so this file compiles on its own, and also so that developers can
 * see what this value should look like.  Note that the last entry must always be
 * `libjulia`, and that all paths should be relative to this loader library path.
 */
#if !defined(DEP_LIBS)
#define DEP_LIBS "../lib/example.so:../lib/libjulia.so"
#endif

// We need to dlopen() ourselves in order to introspect the libdir.
#if defined(LANGUAGE_DEBUG_BUILD)
#define LIBJULIA_NAME "libjulia-debug"
#else
#define LIBJULIA_NAME "libjulia"
#endif


// Declarations from `loader_lib.c` and `loader_win_utils.c`
LANGUAGE_DLLEXPORT extern int jl_load_repl(int, char **);
LANGUAGE_DLLEXPORT void jl_loader_print_stderr(const char * msg);
void jl_loader_print_stderr3(const char * msg1, const char * msg2, const char * msg3);
static void * lookup_symbol(const void * lib_handle, const char * symbol_name);

#ifdef _OS_WINDOWS_
LPWSTR *CommandLineToArgv(LPWSTR lpCmdLine, int *pNumArgs);
char *wchar_to_utf8(const wchar_t * wstr);
wchar_t *utf8_to_wchar(const char * str);
void setup_stdio(void);
#endif

#include "../src/jloptions.h"
