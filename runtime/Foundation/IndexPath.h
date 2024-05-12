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

#ifndef _NSIndexPath_h_GNUSTEP_BASE_INCLUDE
#define _NSIndexPath_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif

&& GS_API_VERSION( 10200,GS_API_LATEST)

/**
 * Instances of this class represent a series of indexes into a hierarchy
 * of arrays.<br />
 * Each instance is a unique shared object.
 */
GS_EXPORT_CLASS
@interface	NSIndexPath : NSObject <NSCopying, NSCoding>
{
#if	GS_EXPOSE(NSIndexPath)
@private
  NSUInteger	_hash;
  NSUInteger	_length;
  NSUInteger	*_indexes;
#endif
#if     GS_NONFRAGILE
#else
  /* Pointer to private additional data used to avoid breaking ABI
   * when we don't have the non-fragile ABI available.
   * Use this mechanism rather than changing the instance variable
   * layout (see Source/GSInternal.h for details).
   */
  @private id _internal GS_UNUSED_IVAR;
#endif
}

/**
 * Return a path containing the single value anIndex.
 */
+ (id) indexPathWithIndex: (NSUInteger)anIndex;

/**
 * Return a path containing all the indexes in the supplied array.
 */
+ (id) indexPathWithIndexes: (NSUInteger*)indexes length: (NSUInteger)length;


/**
 * Return a path containing an item number and section.
 */
+ (NSIndexPath *) indexPathForItem: (NSInteger)item inSection: (NSInteger)section;

/**
 * Return an index number identifying an item in a collection view
 */
- (NSInteger) item;

/**
 * Return an index number identifying a section in a collection view
 */
- (NSInteger) section;
#endif


/**
 * Return a path containing row number and section.
 */
+ (NSIndexPath *) indexPathForRow: (NSInteger)item inSection: (NSInteger)section;

/**
 * Return an index number identifying a row in a table view
 */
- (NSInteger) item;
#endif

/**
 * Compares other with the receiver.<br />
 * Returns NSOrderedSame if the two are identical.<br />
 * Returns NSOrderedAscending if other is less than the receiver in a
 * depth-wise comparison.<br />
 * Returns NSOrderedDescending otherwise.
 */
- (NSComparisonResult) compare: (NSIndexPath*)other;

/**
 * Copies all index values from the receiver into aBuffer.
 */
- (void) getIndexes: (NSUInteger*)aBuffer;

/**
 * Return the index at the specified position or NSNotFound if there
 * is no index at the specified position.
 */
- (NSUInteger) indexAtPosition: (NSUInteger)position;

/**
 * Return path formed by adding anIndex to the receiver.
 */
- (NSIndexPath *) indexPathByAddingIndex: (NSUInteger)anIndex;

/**
 * Return path formed by removing the last index from the receiver.
 */
- (NSIndexPath *) indexPathByRemovingLastIndex;

/** <init />
 * Returns the shared instance containing the specified index, creating it
 * and destroying the receiver if necessary.
 */
- (id) initWithIndex: (NSUInteger)anIndex;

/** <init />
 * Returns the shared instance containing the specified index array,
 * creating it and destroying the receiver if necessary.
 */
- (id) initWithIndexes: (NSUInteger*)indexes length: (NSUInteger)length;

/**
 * Returns the number of index values present in the receiver.
 */
- (NSUInteger) length;

@end

#endif

#if	defined(__cplusplus)
}
#endif

#endif
