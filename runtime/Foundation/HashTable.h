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

#ifndef __NSHashTable_h_GNUSTEP_BASE_INCLUDE
#define __NSHashTable_h_GNUSTEP_BASE_INCLUDE 1
#import	<Base/VersionMacros.h>

/**** Included Headers *******************************************************/

#import <Object.h>
#import <Enumerator.h>
#import <PointerFunctions.h>
#import	<String.h>

#if	defined(__cplusplus)
extern "C" {
#endif


@class GS_GENERIC_CLASS(NSArray, ElementT);
@class GS_GENERIC_CLASS(NSSet, ElementT);

/**** Type, Constant, and Macro Definitions **********************************/

enum {
  NSHashTableStrongMemory
    = NSPointerFunctionsStrongMemory,
  NSHashTableZeroingWeakMemory
    = NSPointerFunctionsZeroingWeakMemory,
  NSHashTableCopyIn
    = NSPointerFunctionsCopyIn,
  NSHashTableObjectPointerPersonality
    = NSPointerFunctionsObjectPointerPersonality,
  NSHashTableWeakMemory
    = NSPointerFunctionsWeakMemory
};

typedef NSUInteger NSHashTableOptions;

GS_EXPORT_CLASS
@interface GS_GENERIC_CLASS(NSHashTable, ElementT) : NSObject <NSCopying, NSCoding, NSFastEnumeration>

+ (instancetype) hashTableWithOptions: (NSPointerFunctionsOptions)options;

+ (instancetype) hashTableWithWeakObjects;
/**
 * Creates a hash table that uses zeroing weak references (either using the
 * automatic reference counting or garbage collection mechanism, depending on
 * which mode this framework is compiled in) so that objects are removed when
 * their last other reference disappears.
 */
+ (instancetype) weakObjectsHashTable;


- (instancetype) initWithOptions: (NSPointerFunctionsOptions)options
                        capacity: (NSUInteger)initialCapacity;

- (instancetype) initWithPointerFunctions: (NSPointerFunctions*)functions
                                 capacity: (NSUInteger)initialCapacity;

/** Adds the object to the receiver.
 */
- (void) addObject: (GS_GENERIC_TYPE(ElementT))object;

/** Returns an array containing all objects in the receiver.
 */
- (GS_GENERIC_CLASS(NSArray, ElementT)*) allObjects;

/** Returns any objct from the receiver, or nil if the receiver contains no
 * objects.
 */
- (GS_GENERIC_TYPE(ElementT)) anyObject;

/** Returns YES if the receiver contains an item equal to anObject, or NO
 * otherwise.
 */
- (BOOL) containsObject: (GS_GENERIC_TYPE(ElementT))anObject;

/** Return the number of items atored in the receiver.
 */
- (NSUInteger) count;

/** Removes from the receiver any items which are not also present in 'other'.
 */
- (void) intersectHashTable: (GS_GENERIC_CLASS(NSHashTable, ElementT)*)other;

/** Returns YES if the receiver and 'other' contain any items in common.
 */
- (BOOL) intersectsHashTable: (GS_GENERIC_CLASS(NSHashTable, ElementT)*)other;

/** Returns YES if the receiver and 'other' contain equal sets of items.
 */
- (BOOL) isEqualToHashTable: (GS_GENERIC_CLASS(NSHashTable, ElementT)*)other;

/** Returns YES fi all the items in the receiver are also present in 'other'
 */
- (BOOL) isSubsetOfHashTable: (GS_GENERIC_CLASS(NSHashTable, ElementT)*)other;

/** Returns an item stored in the receiver which is equal to the supplied
 * object argument, or nil if no matchi is found.
 */
- (GS_GENERIC_TYPE(ElementT)) member: (GS_GENERIC_TYPE(ElementT))object;

/** Removes from the receivr all those items which are prsent in both
 * the receiver and in 'other'.
 */
- (void) minusHashTable: (GS_GENERIC_CLASS(NSHashTable, ElementT)*)other;

/** Return an enumerator for the receiver.
 */
- (GS_GENERIC_CLASS(NSEnumerator, ElementT)*) objectEnumerator;

/** Return an NSPointerFunctions value describing the functions used by the
 * receiver to handle its contents.
 */
- (NSPointerFunctions*) pointerFunctions;

/** Removes all objects.
 */
- (void) removeAllObjects;

/** Remove the object (or any equal object) from the receiver.
 */
- (void) removeObject: (GS_GENERIC_TYPE(ElementT))object;

/** Returns a set containing all the objects in the receiver.
 */
- (GS_GENERIC_CLASS(NSSet, ElementT)*) setRepresentation; 

/** Adds to the receiver thse items present in 'other' which were
 * not present in the receiver.
 */
- (void) unionHashTable: (GS_GENERIC_CLASS(NSHashTable, ElementT)*)other;


@end


/**
 * Type for enumerating.<br />
 * NB. Implementation detail ... in GNUstep the layout <strong>must</strong>
 * correspond to that used by the GSIMap macros.
 */
typedef struct { void *map; void *node; size_t bucket; } NSHashEnumerator;

/** Callback functions for an NSHashTable.  See NSCreateHashTable() . <br />*/
typedef struct _NSHashTableCallBacks
{
  /** <code>NSUInteger (*hash)(NSHashTable *, const void *)</code> ...
   *  Hashing function.  NOTE: Elements with equal values must have equal hash
   *  function values.  The default if NULL uses the pointer addresses
   *  directly. <br/>*/
  NSUInteger (*hash)(NSHashTable *, const void *);

  /** <code>BOOL (*isEqual)(NSHashTable *, const void *, const void *)</code>
   *  ... Comparison function.  The default if NULL uses '<code>==</code>'.
   *  <br/>*/
  BOOL (*isEqual)(NSHashTable *, const void *, const void *);

  /** <code>void (*retain)(NSHashTable *, const void *)</code> ...
   *  Retaining function called when adding elements to the table.
   *  The default if NULL is a no-op (no reference counting). <br/> */
  void (*retain)(NSHashTable *, const void *);

  /** <code>void (*release)(NSHashTable *, void *)</code> ... Releasing
   *  function called when a data element is removed from the table.
   *  The default if NULL is a no-op (no reference counting).<br/>*/
  void (*release)(NSHashTable *, void *);

  /** <code>NSString *(*describe)(NSHashTable *, const void *)</code> ...
   *  Description function.  The default if NULL prints boilerplate. <br /> */
  NSString *(*describe)(NSHashTable *, const void *);
} NSHashTableCallBacks;

GS_EXPORT const NSHashTableCallBacks NSIntegerHashCallBacks;
GS_EXPORT const NSHashTableCallBacks NSIntHashCallBacks; /*DEPRECATED*/
GS_EXPORT const NSHashTableCallBacks NSNonOwnedPointerHashCallBacks;
GS_EXPORT const NSHashTableCallBacks NSNonRetainedObjectHashCallBacks;
GS_EXPORT const NSHashTableCallBacks NSObjectHashCallBacks;
GS_EXPORT const NSHashTableCallBacks NSOwnedPointerHashCallBacks;
GS_EXPORT const NSHashTableCallBacks NSPointerToStructHashCallBacks;

GS_EXPORT NSHashTable *
NSCreateHashTable(NSHashTableCallBacks callBacks,
                  NSUInteger capacity);

GS_EXPORT NSHashTable *
NSCreateHashTableWithZone(NSHashTableCallBacks callBacks,
                          NSUInteger capacity,
                          NSZone *zone);

GS_EXPORT NSHashTable *
NSCopyHashTableWithZone(NSHashTable *table, NSZone *zone);

GS_EXPORT void
NSFreeHashTable(NSHashTable *table);

GS_EXPORT void
NSResetHashTable(NSHashTable *table);

GS_EXPORT BOOL
NSCompareHashTables(NSHashTable *table1, NSHashTable *table2);

GS_EXPORT NSUInteger
NSCountHashTable(NSHashTable *table);

GS_EXPORT void *
NSHashGet(NSHashTable *table, const void *element);

GS_EXPORT NSArray *
NSAllHashTableObjects(NSHashTable *table);

GS_EXPORT void
NSEndHashTableEnumeration(NSHashEnumerator *enumerator);

GS_EXPORT NSHashEnumerator
NSEnumerateHashTable(NSHashTable *table);

GS_EXPORT void *
NSNextHashEnumeratorItem(NSHashEnumerator *enumerator);

GS_EXPORT void
NSHashInsert(NSHashTable *table, const void *element);

GS_EXPORT void
NSHashInsertKnownAbsent(NSHashTable *table, const void *element);

GS_EXPORT void *
NSHashInsertIfAbsent(NSHashTable *table, const void *element);

GS_EXPORT void
NSHashRemove(NSHashTable *table, const void *element);

GS_EXPORT NSString *
NSStringFromHashTable(NSHashTable *table);

#if	defined(__cplusplus)
}
#endif

#endif /* __NSHashTable_h_GNUSTEP_BASE_INCLUDE */
