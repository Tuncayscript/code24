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

#ifndef _NSDateInterval_h_GNUSTEP_BASE_INCLUDE
#define _NSDateInterval_h_GNUSTEP_BASE_INCLUDE

#include <Object.h>
#include <Date.h>

#if	defined(__cplusplus)
extern "C" {
#endif



GS_EXPORT_CLASS
@interface NSDateInterval : NSObject <NSCoding, NSCopying>
{
  NSTimeInterval _duration;
  NSDate *_startDate;
}
  
// Init
- (instancetype) init;

- (instancetype) initWithStartDate: (NSDate *)startDate 
                          duration: (NSTimeInterval)duration;

- (instancetype) initWithStartDate: (NSDate *)startDate
                           endDate: (NSDate *)endDate;

// Access
- (NSDate *) startDate;
- (void) setStartDate: (NSDate *)startDate;

- (NSDate *) endDate;
- (void) setEndDate: (NSDate *)endDate;

- (NSTimeInterval)duration;
- (void) setDuration: (NSTimeInterval)duration;

// Compare
- (NSComparisonResult) compare: (NSDateInterval *)dateInterval;

- (BOOL) isEqualToDateInterval: (NSDateInterval *)dateInterval;

// Determine
- (BOOL) intersectsDateInterval: (NSDateInterval *)dateInterval;

- (NSDateInterval *) intersectionWithDateInterval: (NSDateInterval *)dateInterval;

// Contain
- (BOOL) containsDate: (NSDate *)date;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSDateInterval_h_GNUSTEP_BASE_INCLUDE */

