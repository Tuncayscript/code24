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


#ifndef _NSDateComponentsFormatter_h_GNUSTEP_BASE_INCLUDE
#define _NSDateComponentsFormatter_h_GNUSTEP_BASE_INCLUDE

#include <Formatter.h>
#include <Calendar.h>



#if	defined(__cplusplus)
extern "C" {
#endif

enum
{
  // "1:10; may fall back to abbreviated units in some cases (such as 3d)"
  NSDateComponentsFormatterUnitsStylePositional = 0,
  // "1h 10m"
  NSDateComponentsFormatterUnitsStyleAbbreviated, 
  // "1hr, 10min"
  NSDateComponentsFormatterUnitsStyleShort,
  // "1 hour, 10 minutes"
  NSDateComponentsFormatterUnitsStyleFull, 
  // "One hour, ten minutes"
  NSDateComponentsFormatterUnitsStyleSpellOut,
  // "1hr 10min" - Brief is shorter than Short
  NSDateComponentsFormatterUnitsStyleBrief, 
};
typedef NSInteger NSDateComponentsFormatterUnitsStyle;
  
enum
{
  //drop none, pad none
  NSDateComponentsFormatterZeroFormattingBehaviorNone = (0),
  //Positional units: drop leading zeros, pad other zeros. All others: drop all zeros.
  NSDateComponentsFormatterZeroFormattingBehaviorDefault = (1 << 0), 
  // Off: "0h 10m", On: "10m"
  NSDateComponentsFormatterZeroFormattingBehaviorDropLeading = (1 << 1),
  // Off: "1h 0m 10s", On: "1h 10s"
  NSDateComponentsFormatterZeroFormattingBehaviorDropMiddle = (1 << 2),
  // Off: "1h 0m", On: "1h"
  NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing = (1 << 3), 
  NSDateComponentsFormatterZeroFormattingBehaviorDropAll = (NSDateComponentsFormatterZeroFormattingBehaviorDropLeading |
                                                            NSDateComponentsFormatterZeroFormattingBehaviorDropMiddle |
                                                            NSDateComponentsFormatterZeroFormattingBehaviorDropTrailing),
  // Off: "1:0:10", On: "01:00:10"
  NSDateComponentsFormatterZeroFormattingBehaviorPad = (1 << 16), 
};
typedef NSUInteger NSDateComponentsFormatterZeroFormattingBehavior;

@class NSString, NSDate;

GS_EXPORT_CLASS
@interface NSDateComponentsFormatter : NSFormatter
{
  NSCalendar *_calendar;
  NSDate *_referenceDate;
  BOOL _allowsFractionalUnits;
  BOOL _collapsesLargestUnit;
  BOOL _includesApproximationPhrase;
  NSFormattingContext _formattingContext;
  NSInteger _maximumUnitCount;
  NSDateComponentsFormatterZeroFormattingBehavior _zeroFormattingBehavior;
  NSCalendarUnit _allowedUnits;
  NSDateComponentsFormatterUnitsStyle _unitsStyle;
}
  
- (NSString *) stringForObjectValue: (id)obj;

- (NSString *) stringFromDateComponents: (NSDateComponents *)components;

- (NSString *) stringFromDate: (NSDate *)startDate toDate: (NSDate *)endDate;

- (NSString *) stringFromTimeInterval: (NSTimeInterval)ti;

- (NSDateComponentsFormatterUnitsStyle) unitsStyle;
- (void) setUnitsStyle: (NSDateComponentsFormatterUnitsStyle)style;
  
- (NSCalendarUnit) allowedUnits;
- (void) setAllowedUnits: (NSCalendarUnit)units;

- (NSDateComponentsFormatterZeroFormattingBehavior) zeroFormattingBehavior;
- (void) setZeroFormattingBehavior: (NSDateComponentsFormatterZeroFormattingBehavior)behavior;

- (NSCalendar *) calendar;
- (void) setCalender: (NSCalendar *)calendar;

- (NSDate *) referenceDate;
- (void) setReferenceDate: (NSDate *)referenceDate;

- (BOOL) allowsFractionalUnits;
- (void) setAllowsFractionalUnits: (BOOL)allowsFractionalUnits;

- (NSInteger) maximumUnitCount;
- (void) setMaximumUnitCount: (NSInteger)maximumUnitCount;

- (BOOL) collapsesLargestUnit;
- (void) setCollapsesLargestUnit: (BOOL)collapsesLargestUnit;

- (BOOL) includesApproximationPhrase;
- (void) setIncludesApproximationPhrase: (BOOL)includesApproximationPhrase;

- (NSFormattingContext) formattingContext;
- (void) setFormattingContext: (NSFormattingContext)formattingContext;

- (BOOL) getObjectValue: (id*)obj forString: (NSString *)string errorDescription: (NSString **)error;

+ (NSString *) localizedStringFromDateComponents: (NSDateComponents *)components
                                      unitsStyle: (NSDateComponentsFormatterUnitsStyle)unitsStyle;
  
@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSDateComponentsFormatter_h_GNUSTEP_BASE_INCLUDE */

