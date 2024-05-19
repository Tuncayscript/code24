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


#ifndef _NSProgress_h_GNUSTEP_BASE_INCLUDE
#define _NSProgress_h_GNUSTEP_BASE_INCLUDE

#import	<Base/VersionMacros.h>
#import	<Object.h>
#import <String.h>
#import <Base/Blocks.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class GS_GENERIC_CLASS(NSArray, ElementT);
@class GS_GENERIC_CLASS(NSDictionary, KeyT:id<NSCopying>, ValT);
@class NSNumber, NSURL, NSProgress;



typedef NSString* NSProgressKind;
typedef NSString* NSProgressUserInfoKey;
typedef NSString* NSProgressFileOperationKind;  

DEFINE_BLOCK_TYPE_NO_ARGS(GSProgressCancellationHandler, void);
DEFINE_BLOCK_TYPE_NO_ARGS(GSProgressPausingHandler, void);
DEFINE_BLOCK_TYPE(NSProgressPublishingHandler, void, NSProgress*);
DEFINE_BLOCK_TYPE_NO_ARGS(NSProgressUnpublishingHandler, void); 
DEFINE_BLOCK_TYPE_NO_ARGS(GSProgressPendingUnitCountBlock, void); 
DEFINE_BLOCK_TYPE_NO_ARGS(GSProgressResumingHandler, void); 
  
GS_EXPORT_CLASS
@interface NSProgress : NSObject
{
#if	GS_EXPOSE(NSProgress)
#endif
#if     GS_NONFRAGILE
#  if	defined(GS_NSProgress_IVARS)
@public
GS_NSProgress_IVARS;
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
  
// Creating progress objects...
- (instancetype) initWithParent: (NSProgress *)parent 
                       userInfo: (NSDictionary *)userInfo;
+ (NSProgress *) discreteProgressWithTotalUnitCount: (int64_t)unitCount;
+ (NSProgress *) progressWithTotalUnitCount: (int64_t)unitCount;
+ (NSProgress *) progressWithTotalUnitCount: (int64_t)unitCount 
  parent: (NSProgress *)parent 
  pendingUnitCount: (int64_t)portionOfParentTotalUnitCount;

// Current progress
+ (NSProgress *) currentProgress;
- (void) becomeCurrentWithPendingUnitCount: (int64_t)unitCount;
- (void) addChild: (NSProgress *)child
  withPendingUnitCount: (int64_t)inUnitCount;
- (void) resignCurrent;

// Reporting progress
- (int64_t) totalUnitCount;
- (void) setTotalUnitCount: (int64_t)unitCount;

- (int64_t) completedUnitCount;
- (void) setCompletedUnitCount: (int64_t)unitCount;

- (NSString *) localizedDescription;
- (NSString *) localizedAdditionalDescription;

// Observing progress
- (double) fractionCompleted;

// Controlling progress
- (BOOL) isCancellable;
- (BOOL) isCancelled;
- (void) cancel;
- (void) setCancellationHandler: (GSProgressCancellationHandler) handler;

- (BOOL) isPausable;
- (BOOL) isPaused;
- (void) pause;
- (void) setPausingHandler: (GSProgressPausingHandler) handler;

- (void) resume;
- (void) setResumingHandler: (GSProgressResumingHandler) handler;

// Progress Information
- (BOOL) isIndeterminate;
- (void) setIndeterminate: (BOOL)flag;
- (NSProgressKind) kind;
- (void) setKind: (NSProgressKind)k;
- (void) setUserInfoObject: (id)obj
                    forKey: (NSProgressUserInfoKey)key;
- (GS_GENERIC_CLASS(NSDictionary,NSProgressUserInfoKey,id) *)userInfo;

// Instance property accessors...
- (void) setFileOperationKind: (NSProgressFileOperationKind)k;
- (NSProgressFileOperationKind) fileOperationKind;
- (void) setFileUrl: (NSURL *)u;
- (NSURL *) fileUrl;
- (BOOL) isFinished;
- (BOOL) isOld;
- (void) setEstimatedTimeRemaining: (NSNumber *)n;
- (NSNumber *) estimatedTimeRemaining;
- (void) setFileCompletedCount: (NSNumber *)n;
- (NSNumber *) fileCompletedCount;
- (void) setFileTotalCount: (NSNumber *)n;
- (NSNumber *) fileTotalCount;
- (void) setThroughput: (NSNumber *)n;
- (NSNumber *) throughtput;

// Instance methods
- (void) publish;
- (void) unpublish;
- (void) performAsCurrentWithPendingUnitCount: (int64_t)unitCount 
  usingBlock: (GSProgressPendingUnitCountBlock)work;

// Type methods
+ (id) addSubscriberForFileURL: (NSURL *)url 
         withPublishingHandler: (NSProgressPublishingHandler)publishingHandler;
+ (void) removeSubscriber: (id)subscriber;
  
@end


@protocol NSProgressReporting

- (NSProgress *) progress;

@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSProgress_h_GNUSTEP_BASE_INCLUDE */

