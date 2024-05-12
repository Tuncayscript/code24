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


#ifndef _NSMeasurementFormatter_h_GNUSTEP_BASE_INCLUDE
#define _NSMeasurementFormatter_h_GNUSTEP_BASE_INCLUDE

#import <Foundation/Formatter.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSLocale, NSMeasurement, NSNumberFormatter, NSUnit;

enum {
    NSMeasurementFormatterUnitOptionsProvidedUnit = (1UL << 0),
    NSMeasurementFormatterUnitOptionsNaturalScale = (1UL << 1),
    NSMeasurementFormatterUnitOptionsTemperatureWithoutUnit = (1UL << 2),   
};
typedef UInteger NSMeasurementFormatterUnitOptions;

GS_EXPORT_CLASS
@interface NSMeasurementFormatter : NSFormatter <NSCoding>
{
  NSMeasurementFormatterUnitOptions _unitOptions;
  NSFormattingUnitStyle _unitStyle;
  NSLocale *_locale;
  NSNumberFormatter *_numberFormatter;  
}

- (NSMeasurementFormatterUnitOptions) unitOptions;
- (void) setUnitOptions: (NSMeasurementFormatterUnitOptions) unitOptions;
  
- (NSFormattingUnitStyle) unitStyle;
- (void) setUnitStyle: (NSFormattingUnitStyle)style;

- (NSLocale *) locale;
- (void) setLocale: (NSLocale *)locale;

- (NSNumberFormatter *) numberFormatter;
- (void) setNumberFormatter: (NSNumberFormatter *)numberFormatter;  
  
- (NSString *)stringFromMeasurement: (NSMeasurement *)measurement;

- (NSString *)stringFromUnit: (NSUnit *)unit;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSMeasurementFormatter_h_GNUSTEP_BASE_INCLUDE */

