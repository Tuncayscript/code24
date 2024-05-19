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


#ifndef __NSPredicate_h_GNUSTEP_BASE_INCLUDE
#define __NSPredicate_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>
#import	<Object.h>
#import	<Array.h>
#import	<Dictionary.h>
#import	<Set.h>
#import <String.h>

#if	defined(__cplusplus)
extern "C" {
#endif

#if	OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
DEFINE_BLOCK_TYPE(GSBlockPredicateBlock, BOOL, id, GS_GENERIC_CLASS(NSDictionary,NSString*,id)*);
#endif

GS_EXPORT_CLASS
@interface NSPredicate : NSObject <NSCoding, NSCopying>

+ (NSPredicate *) predicateWithFormat: (NSString *)format, ...;
+ (NSPredicate *) predicateWithFormat: (NSString *)format
			argumentArray: (NSArray *)args;
+ (NSPredicate *) predicateWithFormat: (NSString *)format
			    arguments: (va_list)args;
+ (NSPredicate *) predicateWithValue: (BOOL)value;
#if	OS_API_VERSION(MAC_OS_X_VERSION_10_6, GS_API_LATEST)
+ (NSPredicate *) predicateWithBlock: (GSBlockPredicateBlock)block;
#endif
- (BOOL) evaluateWithObject: (id)object;
- (NSString *) predicateFormat;
- (NSPredicate *) predicateWithSubstitutionVariables:
  (GS_GENERIC_CLASS(NSDictionary,NSString*,id)*)variables;

- (BOOL) evaluateWithObject: (id)object
	  substitutionVariables: 
	  (GS_GENERIC_CLASS(NSDictionary,NSString*,id)*)variables;
#endif
@end

@interface GS_GENERIC_CLASS(NSArray, ElementT) (NSPredicate)
/** Evaluate each object in the array using the specified predicate and
 * return an array containing all the objects which evaluate to YES.
 */
- (GS_GENERIC_CLASS(NSArray, ElementT) *) filteredArrayUsingPredicate: (NSPredicate *)predicate;
@end

@interface NSMutableArray (NSPredicate)
/** Evaluate each object in the array using the specified predicate and
 * remove each objects which evaluates to NO.
 */
- (void) filterUsingPredicate: (NSPredicate *)predicate;
@end

@interface GS_GENERIC_CLASS(NSSet, ElementT) (NSPredicate)
/** Evaluate each object in the set using the specified predicate and
 * return an set containing all the objects which evaluate to YES.
 */
- (GS_GENERIC_CLASS(NSSet, ElementT) *) filteredSetUsingPredicate: (NSPredicate *)predicate;
@end

@interface NSMutableSet (NSPredicate)
/** Evaluate each object in the set using the specified predicate and
 * remove each objects which evaluates to NO.
 */
- (void) filterUsingPredicate: (NSPredicate *)predicate;
@end

#if	defined(__cplusplus)
}
#endif

#endif	/* 100400 */
#endif /* __NSPredicate_h_GNUSTEP_BASE_INCLUDE */
