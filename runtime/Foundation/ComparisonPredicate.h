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

#ifndef __NSComparisonPredicate_h_GNUSTEP_BASE_INCLUDE
#define __NSComparisonPredicate_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#if	OS_API_VERSION(MAC_OS_X_VERSION_10_4, GS_API_LATEST)

#import	<Expression.h>
#import	<Predicate.h>

#if	defined(__cplusplus)
extern "C" {
#endif

typedef enum _NSComparisonPredicateModifier
{
  NSDirectPredicateModifier=0,
  NSAllPredicateModifier,
  NSAnyPredicateModifier
} NSComparisonPredicateModifier;

typedef enum _NSComparisonPredicateOptions
{
  NSCaseInsensitivePredicateOption=0x01,
  NSDiacriticInsensitivePredicateOption=0x02
} NSComparisonPredicateOptions;

typedef enum _NSPredicateOperatorType
{
  NSLessThanPredicateOperatorType = 0,
  NSLessThanOrEqualToPredicateOperatorType,
  NSGreaterThanPredicateOperatorType,
  NSGreaterThanOrEqualToPredicateOperatorType,
  NSEqualToPredicateOperatorType,
  NSNotEqualToPredicateOperatorType,
  NSMatchesPredicateOperatorType,
  NSLikePredicateOperatorType,
  NSBeginsWithPredicateOperatorType,
  NSEndsWithPredicateOperatorType,
  NSInPredicateOperatorType,
  NSCustomSelectorPredicateOperatorType

  ,
  NSContainsPredicateOperatorType = 99,
  NSBetweenPredicateOperatorType
#endif
} NSPredicateOperatorType;

GS_EXPORT_CLASS
@interface NSComparisonPredicate : NSPredicate
{
#if	GS_EXPOSE(NSComparisonPredicate)
  NSComparisonPredicateModifier	_modifier;
  SEL				_selector;
  NSUInteger			_options;
  NSPredicateOperatorType	_type;
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
  @public
  NSExpression			*_left;
  NSExpression			*_right;
}

+ (NSPredicate *) predicateWithLeftExpression: (NSExpression *)left
			      rightExpression: (NSExpression *)right
			       customSelector: (SEL)sel;
+ (NSPredicate *) predicateWithLeftExpression: (NSExpression *)left
  rightExpression: (NSExpression *)right
  modifier: (NSComparisonPredicateModifier)modifier
  type: (NSPredicateOperatorType)type
  options: (NSUInteger) opts;

- (NSComparisonPredicateModifier) comparisonPredicateModifier;
- (SEL) customSelector;
- (NSPredicate *) initWithLeftExpression: (NSExpression *)left
			 rightExpression: (NSExpression *)right
			  customSelector: (SEL)sel;
- (id) initWithLeftExpression: (NSExpression *)left
	      rightExpression: (NSExpression *)right
		     modifier: (NSComparisonPredicateModifier)modifier
			 type: (NSPredicateOperatorType)type
		      options: (NSUInteger) opts;
- (NSExpression *) leftExpression;
- (NSUInteger) options;
- (NSPredicateOperatorType) predicateOperatorType;
- (NSExpression *) rightExpression;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* 100400 */
#endif
