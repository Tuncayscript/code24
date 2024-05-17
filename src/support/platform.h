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

#ifndef LANGUAGE_PLATFORM_H
#define LANGUAGE_PLATFORM_H

/*
 * This file provides convenient macros to be used to identify the platform
 * based of compiler-specific pre-defined macros. It is based on the
 * information that can be found at the following address:
 *
 *     https://sourceforge.net/p/predef/wiki/Home/
 *
 * Possible values include:
 *      Compiler:
 *          _COMPILER_CLANG_
 *          _COMPILER_GCC_
 *      OS:
 *          _OS_FREEBSD_
 *          _OS_OPENBSD_
 *          _OS_LINUX_
 *          _OS_WINDOWS_
 *          _OS_DARWIN_
 *          _OS_EMSCRIPTEN_
 *
 *      CPU/Architecture:
 *          _CPU_X86_
 *          _CPU_X86_64_
 *          _CPU_AARCH64_
 *          _CPU_ARM_
 *          _CPU_WASM_
 */

/*******************************************************************************
*                               Compiler                                       *
*******************************************************************************/

#if defined(__clang__)
#define _COMPILER_CLANG_
#elif defined(__GNUC__)
#define _COMPILER_GCC_
#elif defined(_MSC_VER)
#define _COMPILER_MICROSOFT_
#else
#error Unsupported compiler
#endif


#define LANGUAGE_NO_ASAN
#define LANGUAGE_NO_MSAN
#define LANGUAGE_NO_TSAN
#if defined(__has_feature) // Clang flavor
#if __has_feature(address_sanitizer)
#define _COMPILER_ASAN_ENABLED_
#undef LANGUAGE_NO_ASAN
#define LANGUAGE_NO_ASAN __attribute__((no_sanitize("address")))
#endif
#if __has_feature(memory_sanitizer)
#define _COMPILER_MSAN_ENABLED_
#undef LANGUAGE_NO_MSAN
#define LANGUAGE_NO_MSAN __attribute__((no_sanitize("memory")))
#endif
#if __has_feature(thread_sanitizer)
#if __clang_major__ < 11
#error Thread sanitizer runtime libraries in clang < 11 leak memory and cannot be used
#endif
#define _COMPILER_TSAN_ENABLED_
#undef LANGUAGE_NO_TSAN
#define LANGUAGE_NO_TSAN __attribute__((no_sanitize("thread")))
#endif
#else // GCC flavor
#if defined(__SANITIZE_ADDRESS__)
#define _COMPILER_ASAN_ENABLED_
#undef LANGUAGE_NO_ASAN
#define LANGUAGE_NO_ASAN __attribute__((no_sanitize("address")))
#endif
#endif // __has_feature
#define LANGUAGE_NO_SANITIZE LANGUAGE_NO_ASAN LANGUAGE_NO_MSAN LANGUAGE_NO_TSAN

/*******************************************************************************
*                               OS                                             *
*******************************************************************************/

#if defined(__FreeBSD__)
#define _OS_FREEBSD_
#elif defined(__OpenBSD__)
#define _OS_OPENBSD_
#elif defined(__linux__)
#define _OS_LINUX_
#elif defined(_WIN32) || defined(_WIN64)
#define _OS_WINDOWS_
#elif defined(__APPLE__) && defined(__MACH__)
#define _OS_DARWIN_
#elif defined(__EMSCRIPTEN__)
#define _OS_EMSCRIPTEN_
#endif

/*******************************************************************************
*                               Architecture                                   *
*******************************************************************************/

#if defined(__amd64__) || defined(__amd64) || defined(__x86_64__) || defined(__x86_64) || defined(_M_X64) || defined(_M_AMD64)
#define _CPU_X86_64_
#elif defined(i386) || defined(__i386) || defined(__i386__) || defined(_M_IX86) || defined(_X86_)
#define _CPU_X86_
#elif defined(__aarch64__)
#define _CPU_AARCH64_
#elif defined(__arm__) || defined(_M_ARM)
#define _CPU_ARM_
#elif defined(__PPC64__)
#define _CPU_PPC64_
#elif defined(_ARCH_PPC)
#define _CPU_PPC_
#elif defined(__wasm__)
#define _CPU_WASM_
#endif

#if defined(_CPU_X86_64_)
#  define _P64
#elif defined(_CPU_X86_)
#  define _P32
#elif defined(_OS_WINDOWS_)
/* Not sure how to determine pointer size on Windows running ARM. */
#  if _WIN64
#    define _P64
#  else
#    define _P32
#  endif
#elif __SIZEOF_POINTER__ == 8
#    define _P64
#elif __SIZEOF_POINTER__ == 4
#    define _P32
#else
#  error pointer size not known for your platform / compiler
#endif

#endif /* !PLATFORM_H */
