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


#ifndef __NSPersonNameComponentsFormatter_h_GNUSTEP_BASE_INCLUDE
#define __NSPersonNameComponentsFormatter_h_GNUSTEP_BASE_INCLUDE


#import <Formatter.h>
#import <PersonNameComponents.h>



// Style...
enum {
    NSPersonNameComponentsFormatterStyleDefault = 0,
    NSPersonNameComponentsFormatterStyleShort,
    NSPersonNameComponentsFormatterStyleMedium,
    NSPersonNameComponentsFormatterStyleLong,
    NSPersonNameComponentsFormatterStyleAbbreviated
};
typedef NSUInteger NSPersonNameComponentsFormatterStyle;

// Options...
enum { NSPersonNameComponentsFormatterPhonetic = (1UL << 1) }; 
typedef NSUInteger NSPersonNameComponentsFormatterOptions;

@class NSString;

GS_EXPORT_CLASS
@interface NSPersonNameComponentsFormatter : NSFormatter
{
  @private
    BOOL _phonetic;
    NSPersonNameComponentsFormatterStyle _style;
    NSPersonNameComponentsFormatterOptions _nameOptions;
}

// Designated init...
+ (NSString *) localizedStringFromPersonNameComponents: (NSPersonNameComponents *)components
                                                 style: (NSPersonNameComponentsFormatterStyle)nameFormatStyle
                                               options: (NSPersonNameComponentsFormatterOptions)nameOptions;

// Setters
- (NSPersonNameComponentsFormatterStyle) style;
- (void) setStyle: (NSPersonNameComponentsFormatterStyle)style;
- (BOOL) isPhonetic;
- (void) setPhonetic: (BOOL)flag;

// Convenience methods...
- (NSString *) stringFromPersonNameComponents: (NSPersonNameComponents *)components;
- (NSAttributedString *) annotatedStringFromPersonNameComponents: (NSPersonNameComponents *)components;
- (NSPersonNameComponents *) personNameComponentsFromString: (NSString *)string;
- (BOOL)getObjectValue: (id *)obj
             forString: (NSString *)string
      errorDescription: (NSString **)error;

@end

// components for attributed strings;
GS_EXPORT NSString * const NSPersonNameComponentKey;
GS_EXPORT NSString * const NSPersonNameComponentGivenName;
GS_EXPORT NSString * const NSPersonNameComponentFamilyName;
GS_EXPORT NSString * const NSPersonNameComponentMiddleName;
GS_EXPORT NSString * const NSPersonNameComponentPrefix;
GS_EXPORT NSString * const NSPersonNameComponentSuffix;
GS_EXPORT NSString * const NSPersonNameComponentNickname;
GS_EXPORT NSString * const NSPersonNameComponentDelimiter; 

#endif
#endif
