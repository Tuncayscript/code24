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

#ifndef __NSFormatter_h_GNUSTEP_BASE_INCLUDE
#define __NSFormatter_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>
#import	<Geometry.h>
#import	<Range.h>



#if	defined(__cplusplus)
extern "C" {
#endif
  
enum {  
  NSFormattingContextUnknown = 0,
  NSFormattingContextDynamic,
  NSFormattingContextStandalone,
  NSFormattingContextListItem,
  NSFormattingContextBeginningOfSentence,  
  NSFormattingContextMiddleOfSentence,    
};
typedef NSInteger NSFormattingContext;

enum { 
    NSFormattingUnitStyleShort = 1,
    NSFormattingUnitStyleMedium,
    NSFormattingUnitStyleLong,
};
typedef NSInteger NSFormattingUnitStyle;

@class	NSString, NSAttributedString, NSDictionary;

/**
 *  This abstract class defines the interface for classes that support
 *  conversion between strings and objects of various types.  GNUstep
 *  provides two concrete implementations of this class: [NSDateFormatter]
 *  and [NSNumberFormatter].  Others may be implemented for specialized
 *  applications.
 */
GS_EXPORT_CLASS
@interface	NSFormatter : NSObject <NSCopying, NSCoding>

/**
 *  This method calls [-stringForObjectValue:] then marks up the string with
 *  attributes if it should be displayed specially.  For example, in an
 *  application you may want to display out-of-range dates or numbers in
 *  italics.  This is an optional method and may return nil to indicate that
 *  an attributed string is not provided.
 */
- (NSAttributedString*) attributedStringForObjectValue: (id)anObject
				 withDefaultAttributes: (NSDictionary*)attr;

/**
 * For use in applications where user interactively edits a string.  If the
 * version of the string for editing purposes should look different from the
 * string displayed (returned by [-stringForObjectValue:] or
 * [-attributedStringForObjectValue:withDefaultAttributes:]), return that
 * here.  For example, the edited string may contain formatting codes or
 * similar that are not displayed in the final string.  The default
 * implementation simply returns [-stringForObjectValue:].
 */
- (NSString*) editingStringForObjectValue: (id)anObject;

/** <override-subclass />
 *  Primary method for converting a string to an object through parsing.
 *  anObject and error are output parameters; you should allocate memory for
 *  one pointer each for the variables passed into these methods.  The
 *  returned object will have been created through <code>alloc-init</code>.
 *  If there is a problem with conversion, a constant-string description of
 *  what went wrong is returned through error, and NO is returned, otherwise
 *  YES.
 */
- (BOOL) getObjectValue: (id*)anObject
	      forString: (NSString*)string
       errorDescription: (NSString**)error;

/**
 *  Checks whether partialString <em>could</em>, if it were completed, be
 *  parsed into a valid object.  newString and error are output parameters;
 *  you should allocate memory for one pointer each for the variables passed
 *  into these methods.  This method is set up to be called after every
 *  keystroke during user editing.  If it returns NO, it optionally returns
 *  newString to replace what the user was editing; if it doesn't, the editor
 *  should delete the last character the user typed.
 */
- (BOOL) isPartialStringValid: (NSString*)partialString
	     newEditingString: (NSString**)newString
	     errorDescription: (NSString**)error;

/**
 *  Checks whether a change to a string leaves it a valid string that, if it
 *  were completed, could be parsed into a valid object.  origString contains
 *  the string before the proposed change, and origSelRange contains the range
 *  that is updated in the proposed change.  partialStringPtr contains the new
 *  string to validate and proposedSelRangePtr holds the selection range that
 *  will be used if the string is accepted or replaced.  Basically, this method
 *  returns YES if partialStringPtr is valid, otherwise NO and may replace
 *  partialStringPtr and proposedSelectedRange with improved values, and may
 *  report the reason in error.
 */
- (BOOL) isPartialStringValid: (NSString**)partialStringPtr
        proposedSelectedRange: (NSRange*)proposedSelRangePtr
               originalString: (NSString*)origString
        originalSelectedRange: (NSRange)originalSelRangePtr
             errorDescription: (NSString**)error;


/** <override-subclass />
 *  Primary method for converting an object to a string through formatting.
 *  Object will be converted to string according to the formatter's
 *  implementation and init parameters.  There is no default handling if the
 *  class of anObject is not what the formatter expects, and usually nil
 *  will be returned in this case.
 */
- (NSString*) stringForObjectValue: (id)anObject;
@end

#if	defined(__cplusplus)
}
#endif

#endif
#endif

