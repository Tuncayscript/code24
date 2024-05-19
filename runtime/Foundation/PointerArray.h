/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip Code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 12, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


#ifndef __NSPointerArray_h_GNUSTEP_BASE_INCLUDE
#define __NSPointerArray_h_GNUSTEP_BASE_INCLUDE

#import	<Object.h>
#import <Array.h>
#import <PointerFunctions.h>



#if	defined(__cplusplus)
extern "C" {
#endif

/**
 * An NSPointerArray acts like a standard mutable array except that it
 * can contain nil and even non-object values.<br />
 * The count can also be set causing the array to shrink (discarding items)
 * or grow (adding nil/zero items).
 */
GS_EXPORT_CLASS
@interface NSPointerArray : NSObject <NSCopying, NSCoding>

/** Allocate an instance, initialise using initWithOptions: and
 * return it autoreleased.
 */
+ (id) pointerArrayWithOptions: (NSPointerFunctionsOptions)options;

/** Allocate an instance, initialise using initWithPointerFunctions: and
 * return it autoreleased.
 */
+ (id) pointerArrayWithPointerFunctions: (NSPointerFunctions *)functions;

/** Returns a new pointer array for storing strong (retained) references to
 * objects.
 */
+ (id) strongObjectsPointerArray;
/** Returns a new pointer array for storing zeroing weak references to objects.
 */
+ (id) weakObjectsPointerArray;


/** Removes all nil/zero items from the array.
 */
- (void) compact;   // eliminate NULLs

/** Returns the number of items in the array.
 */
- (NSUInteger) count;

/** Initialises the receiver with the specified options.
 */
- (id) initWithOptions: (NSPointerFunctionsOptions)options;

/** Initialises the receiver using the supplied object.
 */
- (id) initWithPointerFunctions: (NSPointerFunctions*)functions;

/** Adds an item at the end of the array.
 */
- (void) addPointer: (void*)pointer;

/** Inserts an item at the specified index causing all higher indexed
 * items to be adjusted upwards.<br />
 * WARNING ... the Apple documented (and implemented in MacOS-X 10.5)
 * behavior is to raise an exception if index is the same as the count of
 * items in the array.  This is insane ... for arrays, data and strings you
 * can insert at the end of an object to append to it, so the behavior of
 * this class in MacOS is inconsistent and must be considered buggy.
 */
- (void) insertPointer: (void*)pointer atIndex: (NSUInteger)index;

/** Returns the item at the given index or raises an exception if index
 * is out of range.
 */
- (void*) pointerAtIndex: (NSUInteger)index;

/** Returns an autorelease NSPointerFunctions instance giving the
 * functions in use by the receiver.
 */
- (NSPointerFunctions*) pointerFunctions;

/** Removes the item at the specified index, adjusting the positions of
 * all higher indexed items.
 */
- (void) removePointerAtIndex: (NSUInteger)index;

/* Replaces the item at the specified index.  The index must be less than
 * the current count or an exception is raised.
 */
- (void) replacePointerAtIndex: (NSUInteger)index withPointer: (void*)item;

/** Sets the number of items in the receiver.  Adds nil/zero items to pad
 * the end of the array, or removes extraneous items from the end.
 */
- (void) setCount: (NSUInteger)count;

@end

@interface NSPointerArray (NSArrayConveniences)  

/** Creates an instance configured to hold objects and prevent them from
 * being garbage collected.
 */
+ (id) pointerArrayWithStrongObjects;

/** Creates an instance configured to hold objects, allowing them to be
 * garbage collected and replaced by nil if/when they are collected.
 */
+ (id) pointerArrayWithWeakObjects;

/** Returns an array containing all the non-nil objects from the receiver.
 */
- (NSArray*) allObjects;

@end

#if	defined(__cplusplus)
}
#endif

#endif

#endif
