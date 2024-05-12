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


#ifndef __NSFileCoordinator_h_GNUSTEP_BASE_INCLUDE
#define __NSFileCoordinator_h_GNUSTEP_BASE_INCLUDE

#import <Object.h>
#import <URL.h>



@class NSArray, NSError, NSMutableDictionary, NSOperationQueue, NSSet; 

@protocol NSFilePresenter;

enum {
    NSFileCoordinatorReadingWithoutChanges = 1 << 0,
    NSFileCoordinatorReadingResolvesSymbolicLink = 1 << 1,
    NSFileCoordinatorReadingImmediatelyAvailableMetadataOnly = 1 << 2,
    NSFileCoordinatorReadingForUploading = 1 << 3,
};
typedef NSUInteger NSFileCoordinatorReadingOptions;

enum {
    NSFileCoordinatorWritingForDeleting = 1 << 0,
    NSFileCoordinatorWritingForMoving = 1 << 1,
    NSFileCoordinatorWritingForMerging = 1 << 2,
    NSFileCoordinatorWritingForReplacing = 1 << 3,
    NSFileCoordinatorWritingContentIndependentMetadataOnly = 1 << 4,
};
typedef NSUInteger NSFileCoordinatorWritingOptions;

GS_EXPORT_CLASS
@interface NSFileAccessIntent : NSObject
{
  NSURL *_url;
  BOOL _isRead;
  NSInteger _options;
}
+ (instancetype) readingIntentWithURL: (NSURL *)url
                              options: (NSFileCoordinatorReadingOptions)options;
+ (instancetype) writingIntentWithURL: (NSURL *)url
                              options: (NSFileCoordinatorWritingOptions)options;
- (NSURL *) URL;
@end

DEFINE_BLOCK_TYPE(GSNoEscapeReadWriteHandler, void, NSURL*, NSURL*);
DEFINE_BLOCK_TYPE(GSNoEscapeNewURLHandler, void, NSURL*);
DEFINE_BLOCK_TYPE(GSAccessorCallbackHandler, void, NSError*);
DEFINE_BLOCK_TYPE(GSDualWriteURLCallbackHandler, void, NSURL*, NSURL*);
DEFINE_BLOCK_TYPE_NO_ARGS(GSBatchAccessorCompletionHandler, void);
DEFINE_BLOCK_TYPE(GSBatchAccessorCompositeBlock, void, GSBatchAccessorCompletionHandler);

GS_EXPORT_CLASS
@interface NSFileCoordinator : NSObject
{
  id _purposeIdentifier;
  BOOL _isCancelled;
}

+ (NSArray *) filePresenters;

- (NSString *) purposeIdentifier;

- (void) setPurposeIdentifier: (NSString *)ident;  // copy
                 
- (void)cancel;
                 
- (void)coordinateAccessWithIntents: (NSArray *)intents
                              queue: (NSOperationQueue *)queue
                         byAccessor: (GSAccessorCallbackHandler)accessor;
                 
- (void)coordinateReadingItemAtURL: (NSURL *)readingURL
                           options: (NSFileCoordinatorReadingOptions)readingOptions
                  writingItemAtURL: (NSURL *)writingURL
                           options: (NSFileCoordinatorWritingOptions)writingOptions
                             error: (NSError **)outError
                        byAccessor: (GSNoEscapeReadWriteHandler)readerWriter;
                 
- (void)coordinateReadingItemAtURL: (NSURL *)url
                           options: (NSFileCoordinatorReadingOptions)options
                             error: (NSError **)outError
                        byAccessor: (GSNoEscapeNewURLHandler)reader;
                 
- (void)coordinateWritingItemAtURL: (NSURL *)url
                           options: (NSFileCoordinatorWritingOptions)options error:(NSError **)outError
                        byAccessor: (GSNoEscapeNewURLHandler)writer;

- (void)coordinateWritingItemAtURL: (NSURL *)url1
                           options: (NSFileCoordinatorWritingOptions)options1
                  writingItemAtURL: (NSURL *)url2
                           options: (NSFileCoordinatorWritingOptions)options2
                             error: (NSError **)outError
                        byAccessor: (GSDualWriteURLCallbackHandler)writer;

- (void)itemAtURL: (NSURL *)oldURL didMoveToURL: (NSURL *)newURL;

- (void)itemAtURL: (NSURL *)oldURL willMoveToURL: (NSURL *)newURL; 

- (void)itemAtURL: (NSURL *)url didChangeUbiquityAttributes: (NSSet *)attributes;

- (void)prepareForReadingItemsAtURLs: (NSArray *)readingURLs
                             options: (NSFileCoordinatorReadingOptions)readingOptions
                  writingItemsAtURLs: (NSArray *)writingURLs
                             options: (NSFileCoordinatorWritingOptions)writingOptions
                               error: (NSError **)outError
                          byAccessor: (GSBatchAccessorCompositeBlock)batchAccessor;                 
@end
 
#endif
#endif
