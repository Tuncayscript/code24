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

#ifndef __NSCalendarDate_h_GNUSTEP_BASE_INCLUDE
#define __NSCalendarDate_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Date.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class	NSTimeZone;
@class	NSTimeZoneDetail;

GS_EXPORT_CLASS
@interface NSCalendarDate : NSDate
{
#if	GS_EXPOSE(NSCalendarDate)
  NSTimeInterval	_seconds_since_ref;
  NSString		*_calendar_format;
  NSTimeZone		*_time_zone;
#endif
}

// Getting an NSCalendar Date
+ (id) calendarDate;
+ (id) dateWithString: (NSString*)description
       calendarFormat: (NSString*)format;
+ (id) dateWithString: (NSString*)description
       calendarFormat: (NSString*)format
	       locale: (NSDictionary*)dictionary;
+ (id) dateWithYear: (NSInteger)year
	      month: (NSUInteger)month
	        day: (NSUInteger)day
	       hour: (NSUInteger)hour
	     minute: (NSUInteger)minute
	     second: (NSUInteger)second
	   timeZone: (NSTimeZone*)aTimeZone;

// Initializing an NSCalendar Date
- (id) initWithString: (NSString*)description;
- (id) initWithString: (NSString*)description
       calendarFormat: (NSString*)format;
- (id) initWithString: (NSString*)description
       calendarFormat: (NSString*)fmt
	       locale: (NSDictionary*)locale;
- (id) initWithYear: (NSInteger)year
	      month: (NSUInteger)month
	        day: (NSUInteger)day
	       hour: (NSUInteger)hour
	     minute: (NSUInteger)minute
	     second: (NSUInteger)second
	   timeZone: (NSTimeZone*)aTimeZone;

// Retrieving Date Elements
- (NSInteger) dayOfCommonEra;
- (NSInteger) dayOfMonth;
- (NSInteger) dayOfWeek;
- (NSInteger) dayOfYear;
- (NSInteger) hourOfDay;
- (NSInteger) minuteOfHour;
- (NSInteger) monthOfYear;
- (NSInteger) secondOfMinute;
- (NSInteger) yearOfCommonEra;

/**
 * <p>Returns a calendar date formed by adding the specified offsets to the
 * receiver.  The offsets are added in order, years, then months, then
 * days, then hours then minutes then seconds, so if you add 1 month and
 * forty days to 20th September, the result will be 9th November.
 * </p>
 * <p>This method understands leap years and tries to adjust for daylight
 * savings time changes so that it preserves expected clock time.
 * </p>
 * <p>The returned date has the calendar format and timezone of the receiver.
 * </p>
 */
- (NSCalendarDate*) addYear: (NSInteger)year
		      month: (NSInteger)month
			day: (NSInteger)day
		       hour: (NSInteger)hour
		     minute: (NSInteger)minute
		     second: (NSInteger)second;

// Getting String Descriptions of Dates
- (NSString*) description;
- (NSString*) descriptionWithCalendarFormat: (NSString*)format;
- (NSString*) descriptionWithCalendarFormat: (NSString*)format
				     locale: (NSDictionary*)locale;
- (NSString*) descriptionWithLocale: (id)locale;

// Getting and Setting Calendar Formats
- (NSString*) calendarFormat;
- (void) setCalendarFormat: (NSString*)format;

// Getting and Setting Time Zones
- (void) setTimeZone: (NSTimeZone*)aTimeZone;

- (NSTimeZone*) timeZone;
#endif

- (NSTimeZoneDetail*) timeZoneDetail;
#endif

@end



@interface NSCalendarDate (GregorianDate)

- (NSInteger) lastDayOfGregorianMonth: (NSInteger)month year: (NSInteger)year;
- (NSInteger) absoluteGregorianDay: (NSInteger)day
			     month: (NSInteger)month
			      year: (NSInteger)year;
- (void) gregorianDateFromAbsolute: (NSInteger)d
			       day: (NSInteger*)day
			     month: (NSInteger*)month
			      year: (NSInteger*)year;

@end

#endif


@interface NSCalendarDate (OPENSTEP)

- (NSCalendarDate*) dateByAddingYears: (NSInteger)years
			       months: (NSInteger)months
				 days: (NSInteger)days
				hours: (NSInteger)hours
			      minutes: (NSInteger)minutes
			      seconds: (NSInteger)seconds;

- (void) years: (NSInteger*)years
	months: (NSInteger*)months
          days: (NSInteger*)days
         hours: (NSInteger*)hours
       minutes: (NSInteger*)minutes
       seconds: (NSInteger*)seconds
     sinceDate: (NSDate*)date;
@end
#endif

#if     !NO_GNUSTEP && !defined(GNUSTEP_BASE_INTERNAL)
#import <Base/NSCalendarDate+GNUstepBase.h>
#endif

#if	defined(__cplusplus)
}
#endif

#endif  /* __NSCalendarDate_h_GNUSTEP_BASE_INCLUDE*/
