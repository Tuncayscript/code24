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


#ifndef _NSMassFormatter_h_GNUSTEP_BASE_INCLUDE
#define _NSMassFormatter_h_GNUSTEP_BASE_INCLUDE

#import <Formatter.h>



#if	defined(__cplusplus)
extern "C" {
#endif

enum {
    NSMassFormatterUnitGram = 11,
    NSMassFormatterUnitKilogram = 14,
    NSMassFormatterUnitOunce = (6 << 8) + 1,
    NSMassFormatterUnitPound = (6 << 8) + 2,
    NSMassFormatterUnitStone = (6 << 8) + 3,
};  
typedef NSInteger NSMassFormatterUnit;  

@class NSNumberFormatter;

GS_EXPORT_CLASS
@interface NSMassFormatter : NSObject
{
  NSNumberFormatter *_numberFormatter;
  BOOL _isForPersonMassUse;
  NSFormattingUnitStyle _unitStyle;
}

- (NSNumberFormatter *) numberFormatter;
- (void) setNumberFormatter: (NSNumberFormatter *)formatter;
  
- (NSFormattingUnitStyle) unitStyle;
- (void) setUnitStyle: (NSFormattingUnitStyle)style;

- (BOOL) isForPersonMassUse;
- (void) setForPersonMassUse: (BOOL)flag;
  
- (NSString *)stringFromValue: (double)value unit: (NSMassFormatterUnit)unit;

- (NSString *)stringFromKilograms: (double)numberInKilograms;

- (NSString *)unitStringFromValue: (double)value unit: (NSMassFormatterUnit)unit;

- (NSString *)unitStringFromKilograms: (double)numberInKilograms usedUnit: (NSMassFormatterUnit *)unitp;

- (BOOL) getObjectValue: (id*)obj forString: (NSString *)string errorDescription: (NSString **)error;
  
@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSMassFormatter_h_GNUSTEP_BASE_INCLUDE */

