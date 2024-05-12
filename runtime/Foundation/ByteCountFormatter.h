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

#ifndef _NSByteCountFormatter_h_GNUSTEP_BASE_INCLUDE
#define _NSByteCountFormatter_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>
#import	<Formatter.h>
#import	<DecimalNumber.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class	NSString, NSAttributedString, NSDictionary,
        NSError, NSLocale, NSNumber;


enum {
  NSByteCountFormatterUseDefault = 0,
  NSByteCountFormatterUseBytes = 1UL << 0,
  NSByteCountFormatterUseKB = 1UL << 1,
  NSByteCountFormatterUseMB = 1UL << 2,
  NSByteCountFormatterUseGB = 1UL << 3,
  NSByteCountFormatterUseTB = 1UL << 4,
  NSByteCountFormatterUsePB = 1UL << 5,
  NSByteCountFormatterUseEB = 1UL << 6,
  NSByteCountFormatterUseZB = 1UL << 7,
  NSByteCountFormatterUseYBOrHigher = 0x0FFUL << 8,
  NSByteCountFormatterUseAll = 0x0FFFFUL
};
typedef NSInteger NSByteCountFormatterUnits;

enum {
  NSByteCountFormatterCountStyleFile = 0,
  NSByteCountFormatterCountStyleMemory = 1,
  NSByteCountFormatterCountStyleDecimal = 2,
  NSByteCountFormatterCountStyleBinary = 3,
};
typedef NSInteger NSByteCountFormatterCountStyle;

GS_EXPORT_CLASS
@interface NSByteCountFormatter : NSFormatter
{
#if	GS_EXPOSE(NSByteCountFormatter)
#endif
#if     GS_NONFRAGILE
#  if	defined(GS_NSByteCountFormatter_IVARS)
@public
GS_NSByteCountFormatter_IVARS;
#  endif
#else
  /* Pointer to private additional data used to avoid breaking ABI
   * when we don't have the non-fragile ABI available.
   * Use this mechanism rather than changing the instance variable
   * layout (see Source/GSInternal.h for details).
   */
  @private id _internal GS_UNUSED_IVAR;
#endif
}

- (NSFormattingContext) formattingContext;
- (void) setFormattingContext: (NSFormattingContext)ctx;

- (NSByteCountFormatterCountStyle) countStyle;
- (void) setCountStyle: (NSByteCountFormatterCountStyle)style;

- (BOOL) allowsNonnumericFormatting;
- (void) setAllowsNonnumericFormatting: (BOOL)flag;

- (BOOL) includesActualByteCount;
- (void) setIncludesActualByteCount: (BOOL)flag;

- (BOOL) isAdaptive;
- (void) setAdaptive: (BOOL)flag;

- (NSByteCountFormatterUnits) allowedUnits;
- (void) setAllowedUnits: (NSByteCountFormatterUnits)units;

- (BOOL) includesCount;
- (void) setIncludesCount: (BOOL)flag;

- (BOOL) includesUnit;
- (void) setIncludesUnit: (BOOL)flag;
  
- (BOOL) zeroPadsFractionDigits;
- (void) setZeroPadsFractionDigits: (BOOL)flag;

- (NSString *) stringForObjectValue: (id)obj;

  /* Beta methods... 
- (NSString *) stringFromMeasurement: (NSMeasurement *)measurement;
   End beta methods. */

- (NSString *)stringFromByteCount: (long long)byteCount;
  
+ (NSString *)stringFromByteCount: (long long)byteCount
                       countStyle: (NSByteCountFormatterCountStyle)countStyle;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSByteCountFormatter_h_GNUSTEP_BASE_INCLUDE */

