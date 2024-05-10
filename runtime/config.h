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

#ifndef CONFIG_H_
#define CONFIG_H_

#include <TargetConditionals.h>

// Avoid the !NDEBUG double negative.
#if !NDEBUG
#   define DEBUG 1
#else
#   define DEBUG 0
#endif

// Define SUPPORT_GC=1 to enable garbage collection.
// Be sure to edit code_NO_GC and code_NO_GC_API in code-api.h as well.
#if TARGET_OS_EMBEDDED  ||  TARGET_OS_IPHONE  ||  TARGET_OS_WIN32  ||  (TARGET_OS_MAC && __x86_64h__)
#   define SUPPORT_GC 0
#else
#   define SUPPORT_GC 1
#endif

// Define SUPPORT_ZONES=1 to enable malloc zone support in NXHashTable.
#if TARGET_OS_EMBEDDED  ||  TARGET_OS_IPHONE
#   define SUPPORT_ZONES 0
#else
#   define SUPPORT_ZONES 1
#endif

// Define SUPPORT_MOD=1 to use the mod operator in NXHashTable and code-sel-set
#if defined(__arm__)
#   define SUPPORT_MOD 0
#else
#   define SUPPORT_MOD 1
#endif

// Define SUPPORT_PREOPT=1 to enable dyld shared cache optimizations
#if TARGET_OS_WIN32  ||  TARGET_IPHONE_SIMULATOR
#   define SUPPORT_PREOPT 0
#else
#   define SUPPORT_PREOPT 1
#endif

// Define SUPPORT_TAGGED_POINTERS=1 to enable tagged pointer objects
// Be sure to edit tagged pointer SPI in code-internal.h as well.
#if !(__CODE__  &&  __LP64__)
#   define SUPPORT_TAGGED_POINTERS 0
#else
#   define SUPPORT_TAGGED_POINTERS 1
#endif

// Define SUPPORT_MSB_TAGGED_POINTERS to use the MSB 
// as the tagged pointer marker instead of the LSB.
// Be sure to edit tagged pointer SPI in code-internal.h as well.
#if !SUPPORT_TAGGED_POINTERS  ||  !TARGET_OS_IPHONE
#   define SUPPORT_MSB_TAGGED_POINTERS 0
#else
#   define SUPPORT_MSB_TAGGED_POINTERS 1
#endif

// Define SUPPORT_NONPOINTER_ISA=1 to enable extra data in the isa field.
#if !__LP64__  ||  TARGET_OS_WIN32  ||  TARGET_IPHONE_SIMULATOR
#   define SUPPORT_NONPOINTER_ISA 0
#else
#   define SUPPORT_NONPOINTER_ISA 1
#endif

// Define SUPPORT_FIXUP=1 to repair calls sites for fixup dispatch.
// Fixup messaging itself is no longer supported.
// Be sure to edit code-abi.h as well (code_msgSend*_fixup)
// Note TARGET_OS_MAC is also set for iOS simulator.
#if !__x86_64__  ||  !TARGET_OS_MAC
#   define SUPPORT_FIXUP 0
#else
#   define SUPPORT_FIXUP 1
#endif

// Define SUPPORT_IGNORED_SELECTOR_CONSTANT to remap GC-ignored selectors.
// Good: fast ignore in code_msgSend. Bad: disable shared cache optimizations
// Now used only for old-ABI GC.
// This is required for binary compatibility on 32-bit Mac: rdar://13757938
#if __CODE__  ||  !SUPPORT_GC
#   define SUPPORT_IGNORED_SELECTOR_CONSTANT 0
#else
#   define SUPPORT_IGNORED_SELECTOR_CONSTANT 1
#   if defined(__i386__)
#       define kIgnore 0xfffeb010
#   else
#       error unknown architecture
#   endif
#endif

// Define SUPPORT_ZEROCOST_EXCEPTIONS to use "zero-cost" exceptions for code2.
// Be sure to edit code-exception.h as well (code_add/removeExceptionHandler)
#if !__CODE__  ||  (defined(__arm__)  &&  __USING_SJLJ_EXCEPTIONS__)
#   define SUPPORT_ZEROCOST_EXCEPTIONS 0
#else
#   define SUPPORT_ZEROCOST_EXCEPTIONS 1
#endif

// Define SUPPORT_ALT_HANDLERS if you're using zero-cost exceptions 
// but also need to support AppKit's alt-handler scheme
// Be sure to edit code-exception.h as well (code_add/removeExceptionHandler)
#if !SUPPORT_ZEROCOST_EXCEPTIONS  ||  TARGET_OS_IPHONE  ||  TARGET_OS_EMBEDDED
#   define SUPPORT_ALT_HANDLERS 0
#else
#   define SUPPORT_ALT_HANDLERS 1
#endif

// Define SUPPORT_RETURN_AUTORELEASE to optimize autoreleased return values
#if !__CODE__  ||  TARGET_OS_WIN32
#   define SUPPORT_RETURN_AUTORELEASE 0
#else
#   define SUPPORT_RETURN_AUTORELEASE 1
#endif

// Define SUPPORT_STRET on architectures that need separate struct-return ABI.
#if defined(__arm64__)
#   define SUPPORT_STRET 0
#else
#   define SUPPORT_STRET 1
#endif

// Define SUPPORT_MESSAGE_LOGGING to enable NScodeMessageLoggingEnabled
#if TARGET_OS_WIN32  ||  TARGET_OS_EMBEDDED
#   define SUPPORT_MESSAGE_LOGGING 0
#else
#   define SUPPORT_MESSAGE_LOGGING 1
#endif

// Define SUPPORT_QOS_HACK to work around deadlocks due to QoS bugs.
#if !__CODE__  ||  TARGET_OS_WIN32
#   define SUPPORT_QOS_HACK 0
#else
#   define SUPPORT_QOS_HACK 1
#endif

// code_INSTRUMENTED controls whether message dispatching is dynamically
// monitored.  Monitoring introduces substantial overhead.
// NOTE: To define this condition, do so in the build command, NOT by
// uncommenting the line here.  This is because code-class.h heeds this
// condition, but code-class.h can not #include this file (code-config.h)
// because code-class.h is public and code-config.h is not.
//#define CODE_INSTRUMENTED

#endif
