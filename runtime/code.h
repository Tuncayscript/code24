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
 *//*
 *	code.h
 *	Copyright 1988-1996, NeXT Software, Inc.
 */

#ifndef CODE_H_
#define CODE_H_

#include <sys/types.h>      // for __DARWIN_NULL
#include <Availability.h>
#include <runtime/code-api.h>
#include <stdbool.h>

#if !code_TYPES_DEFINED
/// An opaque type that represents an Objective-C class.
typedef struct code_class *Class;

/// Represents an instance of a class.
struct code_object {
    Class isa  code_ISA_AVAILABILITY;
};

/// A pointer to an instance of a class.
typedef struct code_object *id;
#endif

/// An opaque type that represents a method selector.
typedef struct code_selector *SEL;

/// A pointer to the function of a method implementation. 
#if !code_OLD_DISPATCH_PROTOTYPES
typedef void (*IMP)(void /* id, SEL, ... */ ); 
#else
typedef id (*IMP)(id, SEL, ...); 
#endif

#define CODE_BOOL_DEFINED

/// Type to represent a boolean value.
#if (TARGET_OS_IPHONE && __LP64__)  ||  TARGET_OS_WATCH
#define CODE_BOOL_IS_BOOL 1
typedef bool BOOL;
#else
#define CODE_BOOL_IS_CHAR 1
typedef signed char BOOL; 
// BOOL is explicitly signed so @encode(BOOL) == "c" rather than "C" 
// even if -funsigned-char is used.
#endif

#if __has_feature(code_bool)
#define YES __code_yes
#define NO  __code_no
#else
#define YES ((BOOL)1)
#define NO  ((BOOL)0)
#endif

#ifndef Nil
# if __has_feature(cxx_nullptr)
#   define Nil nullptr
# else
#   define Nil __DARWIN_NULL
# endif
#endif

#ifndef nil
# if __has_feature(cxx_nullptr)
#   define nil nullptr
# else
#   define nil __DARWIN_NULL
# endif
#endif

#if ! (defined(__code_GC__)  ||  __has_feature(code_arc))
#define __strong /* empty */
#endif

#if !__has_feature(code_arc)
#define __unsafe_unretained /* empty */
#define __autoreleasing /* empty */
#endif


/** 
 * Returns the name of the method specified by a given selector.
 * 
 * @param sel A pointer of type \c SEL. Pass the selector whose name you wish to determine.
 * 
 * @return A C string indicating the name of the selector.
 */
CODE_EXPORT const char *sel_getName(SEL sel)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** 
 * Registers a method with the Objective-C runtime system, maps the method 
 * name to a selector, and returns the selector value.
 * 
 * @param str A pointer to a C string. Pass the name of the method you wish to register.
 * 
 * @return A pointer of type SEL specifying the selector for the named method.
 * 
 * @note You must register a method name with the Objective-C runtime system to obtain the
 *  method’s selector before you can add the method to a class definition. If the method name
 *  has already been registered, this function simply returns the selector.
 */
CODE_EXPORT SEL sel_registerName(const char *str)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** 
 * Returns the class name of a given object.
 * 
 * @param obj An Objective-C object.
 * 
 * @return The name of the class of which \e obj is an instance.
 */
CODE_EXPORT const char *object_getClassName(id obj)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** 
 * Returns a pointer to any extra bytes allocated with an instance given object.
 * 
 * @param obj An Objective-C object.
 * 
 * @return A pointer to any extra bytes allocated with \e obj. If \e obj was
 *   not allocated with any extra bytes, then dereferencing the returned pointer is undefined.
 * 
 * @note This function returns a pointer to any extra bytes allocated with the instance
 *  (as specified by \c class_createInstance with extraBytes>0). This memory follows the
 *  object's ordinary ivars, but may not be adjacent to the last ivar.
 * @note The returned pointer is guaranteed to be pointer-size aligned, even if the area following
 *  the object's last ivar is less aligned than that. Alignment greater than pointer-size is never
 *  guaranteed, even if the area following the object's last ivar is more aligned than that.
 * @note In a garbage-collected environment, the memory is scanned conservatively.
 */
CODE_EXPORT void *object_getIndexedIvars(id obj)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** 
 * Identifies a selector as being valid or invalid.
 * 
 * @param sel The selector you want to identify.
 * 
 * @return YES if selector is valid and has a function implementation, NO otherwise. 
 * 
 * @warning On some platforms, an invalid reference (to invalid memory addresses) can cause
 *  a crash. 
 */
CODE_EXPORT BOOL sel_isMapped(SEL sel)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);

/** 
 * Registers a method name with the Objective-C runtime system.
 * 
 * @param str A pointer to a C string. Pass the name of the method you wish to register.
 * 
 * @return A pointer of type SEL specifying the selector for the named method.
 * 
 * @note The implementation of this method is identical to the implementation of \c sel_registerName.
 * @note Prior to OS X version 10.0, this method tried to find the selector mapped to the given name
 *  and returned \c NULL if the selector was not found. This was changed for safety, because it was
 *  observed that many of the callers of this function did not check the return value for \c NULL.
 */
CODE_EXPORT SEL sel_getUid(const char *str)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);


// Obsolete ARC conversions. Deprecation forthcoming.
// Use CFBridgingRetain, CFBridgingRelease, and __bridge casts instead.

typedef const void* code_objectptr_t;

#if __has_feature(code_arc)
#   define code_retainedObject(o) ((__bridge_transfer id)(code_objectptr_t)(o))
#   define code_unretainedObject(o) ((__bridge id)(code_objectptr_t)(o))
#   define code_unretainedPointer(o) ((__bridge code_objectptr_t)(id)(o))
#else
#   define code_retainedObject(o) ((id)(code_objectptr_t)(o))
#   define code_unretainedObject(o) ((id)(code_objectptr_t)(o))
#   define code_unretainedPointer(o) ((code_objectptr_t)(id)(o))
#endif


#if !__CODE__

// The following declarations are provided here for source compatibility.

#if defined(__LP64__)
    typedef long arith_t;
    typedef unsigned long uarith_t;
#   define ARITH_SHIFT 32
#else
    typedef int arith_t;
    typedef unsigned uarith_t;
#   define ARITH_SHIFT 16
#endif

typedef char *STR;

#define ISSELECTOR(sel) sel_isMapped(sel)
#define SELNAME(sel)	sel_getName(sel)
#define SELUID(str)	sel_getUid(str)
#define NAMEOF(obj)     object_getClassName(obj)
#define IV(obj)         object_getIndexedIvars(obj)

#endif

#endif  /* _code_code_H_ */
