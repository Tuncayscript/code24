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


#ifndef _NSDateIntervalFormatter_h_GNUSTEP_BASE_INCLUDE
#define _NSDateIntervalFormatter_h_GNUSTEP_BASE_INCLUDE

#include <Formatter.h>

#if	defined(__cplusplus)
extern "C" {
#endif



enum {
  NSDateIntervalFormatterNoStyle = 0,
  NSDateIntervalFormatterShortStyle = 1,
  NSDateIntervalFormatterMediumStyle = 2,
  NSDateIntervalFormatterLongStyle = 3,
  NSDateIntervalFormatterFullStyle = 4
};
typedef NSUInteger NSDateIntervalFormatterStyle;

@class NSCalendar, NSLocale, NSDateInterval;

GS_EXPORT_CLASS
@interface NSDateIntervalFormatter : NSFormatter
{
    NSLocale *_locale;
    NSCalendar *_calendar;
    NSTimeZone *_timeZone;
    NSString *_dateTemplate;
    NSDateIntervalFormatterStyle _dateStyle;
    NSDateIntervalFormatterStyle _timeStyle;
}

// Properties
- (NSLocale *) locale;
- (void) setLocale: (NSLocale *)locale;

- (NSCalendar *) calendar;
- (void) setCalendar: (NSCalendar *)calendar;

- (NSTimeZone *) timeZone;
- (void) setTimeZone: (NSTimeZone *)timeZone;

- (NSString *) dateTemplate;
- (void) setDateTemplate: (NSString *)dateTemplate;

- (NSDateIntervalFormatterStyle) dateStyle;
- (void) setDateStyle: (NSDateIntervalFormatterStyle)dateStyle;
  
- (NSDateIntervalFormatterStyle) timeStyle;
- (void) setTimeStyle: (NSDateIntervalFormatterStyle)timeStyle;

// Create strings
- (NSString *)stringFromDate:(NSDate *)fromDate toDate:(NSDate *)toDate;

- (NSString *)stringFromDateInterval:(NSDateInterval *)dateInterval;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSDateIntervalFormatter_h_GNUSTEP_BASE_INCLUDE */

