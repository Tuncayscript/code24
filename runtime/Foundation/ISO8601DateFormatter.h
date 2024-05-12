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

#ifndef _NSISO8601DateFormatter_h_GNUSTEP_BASE_INCLUDE
#define _NSISO8601DateFormatter_h_GNUSTEP_BASE_INCLUDE

#include <Formatter.h>

#if	defined(__cplusplus)
extern "C" {
#endif
  
enum
{
  NSISO8601DateFormatWithYear = (1UL << 0),
  NSISO8601DateFormatWithMonth  = (1UL << 1),
  NSISO8601DateFormatWithWeekOfYear = (1UL << 2),
  NSISO8601DateFormatWithDay  = (1UL << 4),
  NSISO8601DateFormatWithTime  = (1UL << 5),
  NSISO8601DateFormatWithTimeZone  = (1UL << 6),
  NSISO8601DateFormatWithSpaceBetweenDateAndTime = (1UL << 7), 
  NSISO8601DateFormatWithDashSeparatorInDate  = (1UL << 8),
  NSISO8601DateFormatWithColonSeparatorInTime   = (1UL << 9),
  NSISO8601DateFormatWithColonSeparatorInTimeZone = (1UL << 10), 
  NSISO8601DateFormatWithFractionalSeconds  = (1UL << 11),
  NSISO8601DateFormatWithFullDate = NSISO8601DateFormatWithYear |
                                    NSISO8601DateFormatWithMonth |
                                    NSISO8601DateFormatWithDay |
                                    NSISO8601DateFormatWithDashSeparatorInDate,
  NSISO8601DateFormatWithFullTime = NSISO8601DateFormatWithTime |
                                    NSISO8601DateFormatWithColonSeparatorInTime |
                                    NSISO8601DateFormatWithTimeZone |
                                    NSISO8601DateFormatWithColonSeparatorInTimeZone,
  NSISO8601DateFormatWithInternetDateTime = (NSISO8601DateFormatWithFullDate | NSISO8601DateFormatWithFullTime),
};
typedef NSUInteger NSISO8601DateFormatOptions;

@class NSTimeZone, NSString, NSDate, NSDateFormatter;

GS_EXPORT_CLASS
@interface NSISO8601DateFormatter : NSFormatter <NSCoding>
{
  NSTimeZone *_timeZone;
  NSISO8601DateFormatOptions _formatOptions;
  NSDateFormatter *_formatter; 
}
  
- (NSTimeZone *) timeZone;
- (void) setTimeZone: (NSTimeZone *)tz;

- (NSISO8601DateFormatOptions) formatOptions;
- (void) setFormatOptions: (NSISO8601DateFormatOptions)options;
  
- (NSString *) stringFromDate: (NSDate *)date;
- (NSDate *) dateFromString: (NSString *)string;

+ (NSString *) stringFromDate: (NSDate *)date
                     timeZone: (NSTimeZone *)timeZone
                formatOptions: (NSISO8601DateFormatOptions)formatOptions;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSISO8601DateFormatter_h_GNUSTEP_BASE_INCLUDE */

