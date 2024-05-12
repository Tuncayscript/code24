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


#ifndef _NSMeasurement_h_GNUSTEP_BASE_INCLUDE
#define _NSMeasurement_h_GNUSTEP_BASE_INCLUDE

#import <Object.h>



#if	defined(__cplusplus)
extern "C" {
#endif

@class NSUnit;

GS_EXPORT_CLASS
@interface NSMeasurement : NSObject <NSCopying, NSCoding>
{
  NSUnit *_unit;
  double _doubleValue;
}
  
// Creating Measurements
- (instancetype) initWithDoubleValue: (double)doubleValue 
                                unit: (NSUnit *)unit;


// Accessing unit and value
- (NSUnit *) unit;

- (double) doubleValue;

// Conversion
- (BOOL) canBeConvertedToUnit: (NSUnit *)unit;

- (NSMeasurement *) measurementByConvertingToUnit: (NSUnit *)unit;

// Operating
- (NSMeasurement *) measurementByAddingMeasurement: (NSMeasurement *)measurement;

- (NSMeasurement *) measurementBySubtractingMeasurement: (NSMeasurement *)measurement;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSMeasurement_h_GNUSTEP_BASE_INCLUDE */

