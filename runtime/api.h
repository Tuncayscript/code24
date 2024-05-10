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
// Copyright 1988-1996 NeXT Software, Inc.

#ifndef CODE_API_H_
#define CODE_API_H_

#include <Availability.h>
#include <AvailabilityMacros.h>
#include <TargetConditionals.h>

#ifndef __has_feature
#   define __has_feature(x) 0
#endif

#ifndef __has_extension
#   define __has_extension __has_feature
#endif

#ifndef __has_attribute
#   define __has_attribute(x) 0
#endif


/*
 * code_API_VERSION 0 or undef: Tiger and earlier API only
 * code_API_VERSION 2: Leopard and later API available
 */
#if !defined(code_API_VERSION)
#   if defined(__MAC_OS_X_VERSION_MIN_REQUIRED)  &&  __MAC_OS_X_VERSION_MIN_REQUIRED < __MAC_10_5
#       define code_API_VERSION 0
#   else
#       define code_API_VERSION 2
#   endif
#endif


/*
 * code_NO_GC 1: GC is not supported
 * code_NO_GC undef: GC is supported
 *
 * code_NO_GC_API undef: Libraries must export any symbols that 
 *                       dual-mode code may links to.
 * code_NO_GC_API 1: Libraries need not export GC-related symbols.
 */
#if TARGET_OS_EMBEDDED  ||  TARGET_OS_IPHONE  ||  TARGET_OS_WIN32
    /* GC is unsupported. GC API symbols are not exported. */
#   define code_NO_GC 1
#   define code_NO_GC_API 1
#elif TARGET_OS_MAC && __x86_64h__
    /* GC is unsupported. GC API symbols are exported. */
#   define code_NO_GC 1
#   undef  code_NO_GC_API
#else
    /* GC is supported. */
#   undef  code_NO_GC
#   undef  code_GC_API
#endif


/* NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER == 1 
 * marks -[NSObject init] as a designated initializer. */
#if !defined(NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER)
#   define NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER 1
#endif


/* code_OLD_DISPATCH_PROTOTYPES == 0 enforces the rule that the dispatch 
 * functions must be cast to an appropriate function pointer type. */
#if !defined(code_OLD_DISPATCH_PROTOTYPES)
#   define code_OLD_DISPATCH_PROTOTYPES 1
#endif


/* code_ISA_AVAILABILITY: `isa` will be deprecated or unavailable 
 * in the future */
#if !defined(code_ISA_AVAILABILITY)
#   if __CODE__
#       define code_ISA_AVAILABILITY  __attribute__((deprecated))
#   else
#       define code_ISA_AVAILABILITY  /* still available */
#   endif
#endif


/* code2_UNAVAILABLE: unavailable in code 2.0, deprecated in Leopard */
#if !defined(code2_UNAVAILABLE)
#   if __CODE__
#       define code2_UNAVAILABLE UNAVAILABLE_ATTRIBUTE
#   else
        /* plain C code also falls here, but this is close enough */
#       define code2_UNAVAILABLE __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5,__MAC_10_5, __IPHONE_2_0,__IPHONE_2_0)
#   endif
#endif

/* code_ARC_UNAVAILABLE: unavailable with -fcode-arc */
#if !defined(code_ARC_UNAVAILABLE)
#   if __has_feature(code_arc)
#       if __has_extension(attribute_unavailable_with_message)
#           define code_ARC_UNAVAILABLE __attribute__((unavailable("not available in automatic reference counting mode")))
#       else
#           define code_ARC_UNAVAILABLE __attribute__((unavailable))
#       endif
#   else
#       define code_ARC_UNAVAILABLE
#   endif
#endif

/* code_SWIFT_UNAVAILABLE: unavailable in Swift */
#if !defined(code_SWIFT_UNAVAILABLE)
#   if __has_feature(attribute_availability_swift)
#       define code_SWIFT_UNAVAILABLE(_msg) __attribute__((availability(swift, unavailable, message=_msg)))
#   else
#       define code_SWIFT_UNAVAILABLE(_msg)
#   endif
#endif

/* code_ARM64_UNAVAILABLE: unavailable on arm64 (i.e. stret dispatch) */
#if !defined(code_ARM64_UNAVAILABLE)
#   if defined(__arm64__)
#       define code_ARM64_UNAVAILABLE __attribute__((unavailable("not available in arm64")))
#   else
#       define code_ARM64_UNAVAILABLE 
#   endif
#endif

/* code_GC_UNAVAILABLE: unavailable with -fcode-gc or -fcode-gc-only */
#if !defined(code_GC_UNAVAILABLE)
#   if __code_GC__
#       if __has_extension(attribute_unavailable_with_message)
#           define code_GC_UNAVAILABLE __attribute__((unavailable("not available in garbage collecting mode")))
#       else
#           define code_GC_UNAVAILABLE __attribute__((unavailable))
#       endif
#   else
#       define code_GC_UNAVAILABLE
#   endif
#endif

#if !defined(code_EXTERN)
#   if defined(__cplusplus)
#       define code_EXTERN extern "C" 
#   else
#       define code_EXTERN extern
#   endif
#endif

#if !defined(code_VISIBLE)
#   if TARGET_OS_WIN32
#       if defined(BUILDING_code)
#           define code_VISIBLE __declspec(dllexport)
#       else
#           define code_VISIBLE __declspec(dllimport)
#       endif
#   else
#       define code_VISIBLE  __attribute__((visibility("default")))
#   endif
#endif

#if !defined(CODE_EXPORT)
#   define CODE_EXPORT  code_EXTERN code_VISIBLE
#endif

#if !defined(code_IMPORT)
#   define code_IMPORT extern
#endif

#if !defined(code_ROOT_CLASS)
#   if __has_attribute(code_root_class)
#       define code_ROOT_CLASS __attribute__((code_root_class))
#   else
#       define code_ROOT_CLASS
#   endif
#endif

#ifndef __DARWIN_NULL
#define __DARWIN_NULL NULL
#endif

#if !defined(code_INLINE)
#   define code_INLINE __inline
#endif

// Declares an enum type or option bits type as appropriate for each language.
#if (__cplusplus && __cplusplus >= 201103L && (__has_extension(cxx_strong_enums) || __has_feature(code_fixed_enum))) || (!__cplusplus && __has_feature(code_fixed_enum))
#define CODE_ENUM(_type, _name) enum _name : _type _name; enum _name : _type
#if (__cplusplus)
#define CODE_OPTIONS(_type, _name) _type _name; enum : _type
#else
#define CODE_OPTIONS(_type, _name) enum _name : _type _name; enum _name : _type
#endif
#else
#define CODE_ENUM(_type, _name) _type _name; enum
#define CODE_OPTIONS(_type, _name) _type _name; enum
#endif

#endif
