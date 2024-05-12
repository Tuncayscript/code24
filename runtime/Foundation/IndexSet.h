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

#ifndef _NSIndexSet_h_GNUSTEP_BASE_INCLUDE
#define _NSIndexSet_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>
#import <Base/Blocks.h>



#import	<Object.h>
#import	<Range.h>

#if	defined(__cplusplus)
extern "C" {
#endif

/**
 * Instances of this class are collections of unsigned integers in the
 * range 0 to NSNotFound-1.<br />
 * Each integer can appear in a collection only once.
 */
GS_EXPORT_CLASS
@interface	NSIndexSet : NSObject <NSCopying, NSMutableCopying, NSCoding>
{
#if	GS_EXPOSE(NSIndexSet)
  void	*_data;
#endif
}

/**
 * Return an empty set.
 */
+ (id) indexSet;

/**
 * Return a set containing the single value anIndex, or returns nil if
 * anIndex is NSNotFound.
 */
+ (id) indexSetWithIndex: (NSUInteger)anIndex;

/**
 * Return a set containing all the values in aRange, or returns nil if
 * aRange contains NSNotFound.
 */
+ (id) indexSetWithIndexesInRange: (NSRange)aRange;

/**
 * Returns YES if the receiver contains anIndex, NO otherwise.
 */
- (BOOL) containsIndex: (NSUInteger)anIndex;

/**
 * Returns YES if the receiver contains all the index values present
 * in aSet, NO otherwise.
 */
- (BOOL) containsIndexes: (NSIndexSet*)aSet;

/**
 * Returns YES if the receiver contains all the index values present
 * in aRange, NO otherwise.
 */
- (BOOL) containsIndexesInRange: (NSRange)aRange;

/**
 * Returns the number of index values present in the receiver.
 */
- (NSUInteger) count;


/** Not implemented
 * Returns the number of indexes set within the specified range.
 */
- (NSUInteger) countOfIndexesInRange: (NSRange)range;
#endif


DEFINE_BLOCK_TYPE(GSIndexSetEnumerationBlock, void, NSUInteger, BOOL*);
- (void) enumerateIndexesInRange: (NSRange)range
                         options: (NSEnumerationOptions)opts
		      usingBlock: (GSIndexSetEnumerationBlock)aBlock;
/**
 * Enumerate all indices in the set by applying a block to them.
 */
- (void) enumerateIndexesUsingBlock: (GSIndexSetEnumerationBlock)aBlock;

- (void) enumerateIndexesWithOptions: (NSEnumerationOptions)opts
		          usingBlock: (GSIndexSetEnumerationBlock)aBlock;

#endif


DEFINE_BLOCK_TYPE(GSIndexSetRangeEnumerationBlock, void, NSRange, BOOL*);

- (void) enumerateRangesInRange: (NSRange)range 
                        options: (NSEnumerationOptions)opts 
                     usingBlock: (GSIndexSetRangeEnumerationBlock)aBlock;

- (void) enumerateRangesUsingBlock: (GSIndexSetRangeEnumerationBlock)aBlock;

- (void) enumerateRangesWithOptions: (NSEnumerationOptions)opts 
                         usingBlock: (GSIndexSetRangeEnumerationBlock)aBlock;
#endif

/**
 * Returns the first index value in the receiver or NSNotFound if the
 * receiver is empty.
 */
- (NSUInteger) firstIndex;

/**
 * Copies index values into aBuffer until there are no index values left or
 * aBuffer is full (assuming that the size of aBuffer is given by aCount).<br />
 * Only copies index values present in aRange and copies them in order.<br />
 * Returns the number of index values placed in aBuffer.<br />
 * Modifies aRange to start after the last index value copied.<br />
 * If aRange is a null pointer, this method attempts to get <em>all</em>
 * index values from the set (and of course no range can be returned in it).
 */
- (NSUInteger) getIndexes: (NSUInteger*)aBuffer
		 maxCount: (NSUInteger)aCount
	     inIndexRange: (NSRangePointer)aRange;

/**
 * Return the first index value in the receiver which is greater than
 * anIndex.
 */
- (NSUInteger) indexGreaterThanIndex: (NSUInteger)anIndex;

/**
 * Return the first index value in the receiver which is greater than
 * or equal to anIndex.
 */
- (NSUInteger) indexGreaterThanOrEqualToIndex: (NSUInteger)anIndex;

/**
 * Return the first index value in the receiver which is less than
 * anIndex.
 */
- (NSUInteger) indexLessThanIndex: (NSUInteger)anIndex;

/**
 * Return the first index value in the receiver which is less than
 * or equal to anIndex.
 */
- (NSUInteger) indexLessThanOrEqualToIndex: (NSUInteger)anIndex;

/**
 * Initialise the receiver to contain anIndex.  Returns the initialised
 * object or nil if anIndex is NSNotFound.
 */
- (id) initWithIndex: (NSUInteger)anIndex;

/** <init />
 * Initialise the receiver to contain all index values in aRange.
 * Returns the initialised object or nil if aRange contains NSNotFound.
 */
- (id) initWithIndexesInRange: (NSRange)aRange;

/**
 * Initialises the receiver with the index values from aSet.
 */
- (id) initWithIndexSet: (NSIndexSet*)aSet;

/**
 * Returns YES if the receiver contains any index values which lie in aRange,
 * No otherwise.
 */
- (BOOL) intersectsIndexesInRange: (NSRange)aRange;

/**
 * Tests two index sets for equality and returns either YES or NO.
 */
- (BOOL) isEqualToIndexSet: (NSIndexSet*)aSet;

/**
 * Returns the last index value in the receiver or NSNotFound if the
 * receiver is empty.
 */
- (NSUInteger) lastIndex;
@end


GS_EXPORT_CLASS
@interface	NSMutableIndexSet : NSIndexSet

/**
 * Adds anIndex to the set of indexes stored in the receiver.
 */
- (void) addIndex: (NSUInteger)anIndex;

/**
 * Adds all the indexes from aSet to the set of indexes stored in the receiver.
 */
- (void) addIndexes: (NSIndexSet*)aSet;

/**
 * Adds all the indexes in aRange to the set of indexes stored in the receiver.
 */
- (void) addIndexesInRange: (NSRange)aRange;

/**
 * Removes all indexes stored in the receiver.
 */
- (void) removeAllIndexes;

/**
 * Removes anIndex from the set of indexes stored in the receiver.
 */
- (void) removeIndex: (NSUInteger)anIndex;

/**
 * Removes all the indexes in aSet from the set of indexes
 * stored in the receiver.
 */
- (void) removeIndexes: (NSIndexSet*)aSet;

/**
 * Removes all the indexes in aRange from the set of indexes
 * stored in the receiver.
 */
- (void) removeIndexesInRange: (NSRange)aRange;

/**
 * Moves all the indexes from anIndex upwards by the amount specified.<br />
 * If amount is negative, index values below anIndex will be overwritten
 * by the shifted values.<br />
 * If amount is positive, a 'hole' will be left in the index range after
 * anIndex.
 */
- (void) shiftIndexesStartingAtIndex: (NSUInteger)anIndex
				  by: (NSInteger)amount;

@end

#if	defined(__cplusplus)
}
#endif

#endif
#endif
