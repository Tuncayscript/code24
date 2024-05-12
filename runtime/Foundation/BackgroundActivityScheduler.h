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

#ifndef _NSBackgroundActivityScheduler_h_GNUSTEP_BASE_INCLUDE
#define _NSBackgroundActivityScheduler_h_GNUSTEP_BASE_INCLUDE

#include <Object.h>
#include <Date.h>
#include <ProcessInfo.h>



#if	defined(__cplusplus)
extern "C" {
#endif

// is the activity finished?
enum {
  NSBackgroundActivityResultFinished = 1,
  NSBackgroundActivityResultDeferred = 2,
};
typedef NSInteger NSBackgroundActivityResult;

// How the activity will be treated... this is declared in NSObjCRuntime on macOS.
enum {
  NSQualityOfServiceUserInteractive = 0x21,
  NSQualityOfServiceUserInitiated = 0x19,
  NSQualityOfServiceUtility = 0x11,
  NSQualityOfServiceBackground = 0x09,
  NSQualityOfServiceDefault = -1
};
typedef NSInteger NSQualityOfService;
  
@class NSString, NSTimer;

# ifndef __has_feature
# define __has_feature(x) 0
# endif

//# if __has_feature(blocks)
//typedef void(^NSBackgroundActivityCompletionHandler)(NSBackgroundActivityResult result) GSScheduledBlock;  
//# else
  DEFINE_BLOCK_TYPE(NSBackgroundActivityCompletionHandler, void, NSBackgroundActivityResult);
  DEFINE_BLOCK_TYPE(GSScheduledBlock, void, NSBackgroundActivityCompletionHandler);  
//# endif

GS_EXPORT_CLASS
@interface NSBackgroundActivityScheduler : NSObject
{
  NSString *_identifier;
  NSQualityOfService _qualityOfService;
  NSTimeInterval _interval;
  NSTimeInterval _tolerance;
  BOOL _repeats;
  BOOL _shouldDefer;
  NSTimer *_timer;
  NSActivityOptions _opts;
  id _token;
  NSString *_reason;
  BLOCK_SCOPE GSScheduledBlock _block;
}
  
- (instancetype) initWithIdentifier: (NSString *)identifier;

- (NSString *) identifier;
- (void) setIdentifier: (NSString *)identifier;

- (NSQualityOfService) qualityOfService;
- (void) setQualityOfService: (NSQualityOfService)qualityOfService;

- (BOOL) repeats;
- (void) setRepeats: (BOOL)flag;

- (NSTimeInterval) interval;
- (void) setInterval: (NSTimeInterval)interval;

- (NSTimeInterval) tolerance;
- (void) setTolerance: (NSTimeInterval)tolerance;

- (BOOL) shouldDefer;
- (void) setShouldDefer: (BOOL)flag;
  
- (void) scheduleWithBlock: (GSScheduledBlock)block;
  
- (void) invalidate;
  
@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSBackgroundActivityScheduler_h_GNUSTEP_BASE_INCLUDE */

