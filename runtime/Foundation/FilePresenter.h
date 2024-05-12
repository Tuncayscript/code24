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


#ifndef __NSFilePresenter_h_GNUSTEP_BASE_INCLUDE
#define __NSFilePresenter_h_GNUSTEP_BASE_INCLUDE

#import <Object.h>

@class NSError, NSFileVersion, NSOperationQueue, NSSet;



DEFINE_BLOCK_TYPE_NO_ARGS(GSFilePresenterCompletionHandler, void);
DEFINE_BLOCK_TYPE(GSFilePresenterSubitemDeletionHandler, void, NSError*);
DEFINE_BLOCK_TYPE_NO_ARGS(GSFilePresenterReacquirer, void); 
DEFINE_BLOCK_TYPE(GSFilePresentedItemChangesWithCompletionHandler, void, NSError*);

@protocol NSFilePresenter <NSObject>

- (NSURL *) presentedItemURL;
- (NSOperationQueue *) presentedItemOperationQueue;

#if GS_PROTOCOLS_HAVE_OPTIONAL
@optional
#else
@end
@interface NSObject (NSFilePresenter)
#endif

- (NSURL *) primaryPresentedItemURL;
- (NSString *) observedPresentedItemUbiquityAttributes;

- (void) accommodatePresentedItemDeletionWithCompletionHandler: (GSFilePresenterCompletionHandler)completionHandler;
- (void) accommodatePresentedSubitemDeletionAtURL:(NSURL *)url completionHandler: (GSFilePresenterSubitemDeletionHandler)completionHandler;
- (void) presentedItemDidChange;
- (void) presentedItemDidChangeUbiquityAttributes: (NSSet *)attributes; // 10.13
- (void) presentedItemDidGainVersion: (NSFileVersion *)version;
- (void) presentedItemDidLoseVersion: (NSFileVersion *)version;
- (void) presentedItemDidMoveToURL: (NSURL *)newURL;
- (void) presentedItemDidResolveConflictVersion: (NSFileVersion *)version;
- (void) presentedSubitemAtURL: (NSURL *)oldURL didMoveToURL: (NSURL *)newURL;
- (void) presentedSubitemAtURL: (NSURL *)url didGainVersion: (NSFileVersion *)version;
- (void) presentedSubitemAtURL: (NSURL *)url didLoseVersion: (NSFileVersion *)version;
- (void) presentedSubitemAtURL: (NSURL *)url didResolveConflictVersion: (NSFileVersion *)version;
- (void) presentedSubitemDidAppearAtURL: (NSURL *)url;
- (void) presentedSubitemDidChangeAtURL: (NSURL *)url;
- (void) relinquishPresentedItemToReader: (GSFilePresenterReacquirer)reader;
- (void) relinquishPresentedItemToWriter: (GSFilePresenterReacquirer)writer;
- (void) savePresentedItemChangesWithCompletionHandler: (GSFilePresentedItemChangesWithCompletionHandler)completionHandler;

@end

#endif
#endif
