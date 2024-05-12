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
/* Warning -	[-initWithString:attributes:] is the designated initialiser,
 *		but it doesn't provide any way to perform the function of the
 *		[-initWithAttributedString:] initialiser.
 *		In order to work youd this, the string argument of the
 *		designated initialiser has been overloaded such that it
 *		is expected to accept an NSAttributedString here instead of
 *		a string.  If you create an NSAttributedString subclass, you
 *		must make sure that your implementation of the initialiser
 *		copes with either an NSString or an NSAttributedString.
 *		If it receives an NSAttributedString, it should ignore the
 *		attributes argument and use the values from the string.
 */


#ifndef __NSAttributedString_h_GNUSTEP_BASE_INCLUDE
#define __NSAttributedString_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#if	defined(__cplusplus)
extern "C" {
#endif

#import	<Object.h>


#import	<String.h>
#import	<Dictionary.h>
#import	<Array.h>
#import	<Coder.h>

GS_EXPORT_CLASS
@interface NSAttributedString : NSObject <NSCoding, NSCopying, NSMutableCopying>
{
}

//Creating an NSAttributedString
- (id) initWithString: (NSString*)aString;
- (id) initWithAttributedString: (NSAttributedString*)attributedString;
- (id) initWithString: (NSString*)aString attributes: (NSDictionary*)attributes;

//Retrieving character information
- (NSUInteger) length;
/** Returns the string content of the receiver.<br />
 * NB. this is actually a proxy to the internal content (which may change)
 * so if you need an immutable instance you should copy the returned value,
 * not just retain it.
 */
- (NSString*) string;					//Primitive method!

//Retrieving attribute information
- (NSDictionary*) attributesAtIndex: (NSUInteger)index
		     effectiveRange: (NSRange*)aRange;	//Primitive method!
- (NSDictionary*) attributesAtIndex: (NSUInteger)index
	      longestEffectiveRange: (NSRange*)aRange
			    inRange: (NSRange)rangeLimit;
- (id) attribute: (NSString*)attributeName
	 atIndex: (NSUInteger)index
  effectiveRange: (NSRange*)aRange;
- (id) attribute: (NSString*)attributeName atIndex: (NSUInteger)index
  longestEffectiveRange: (NSRange*)aRange inRange: (NSRange)rangeLimit;

//Comparing attributed strings
- (BOOL) isEqualToAttributedString: (NSAttributedString*)otherString;

//Extracting a substring
- (NSAttributedString*) attributedSubstringFromRange: (NSRange)aRange;

@end //NSAttributedString


GS_EXPORT_CLASS
@interface NSMutableAttributedString : NSAttributedString
{
}

//Retrieving character information
- (NSMutableString*) mutableString;

//Changing characters
- (void) deleteCharactersInRange: (NSRange)aRange;

//Changing attributes
- (void) setAttributes: (NSDictionary*)attributes
		 range: (NSRange)aRange;		//Primitive method!
- (void) addAttribute: (NSString*)name value: (id)value range: (NSRange)aRange;
- (void) addAttributes: (NSDictionary*)attributes range: (NSRange)aRange;
- (void) removeAttribute: (NSString*)name range: (NSRange)aRange;

//Changing characters and attributes
- (void) appendAttributedString: (NSAttributedString*)attributedString;
- (void) insertAttributedString: (NSAttributedString*)attributedString
			atIndex: (NSUInteger)index;
- (void) replaceCharactersInRange: (NSRange)aRange
	     withAttributedString: (NSAttributedString*)attributedString;
- (void) replaceCharactersInRange: (NSRange)aRange
		       withString: (NSString*)aString;	//Primitive method!
- (void) setAttributedString: (NSAttributedString*)attributedString;

//Grouping changes
- (void) beginEditing;
- (void) endEditing;

@end //NSMutableAttributedString

typedef NSString* NSAttributedStringKey;

#endif /* GS_API_MACOSX */

#if	defined(__cplusplus)
}
#endif

#if     !NO_GNUSTEP && !defined(GNUSTEP_BASE_INTERNAL)
#import <Base/NSAttributedString+GNUstepBase.h>
#endif

#endif	/* __NSAttributedString_h_GNUSTEP_BASE_INCLUDE */

