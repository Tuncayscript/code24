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


#ifndef _NSExtensionContext_h_GNUSTEP_BASE_INCLUDE
#define _NSExtensionContext_h_GNUSTEP_BASE_INCLUDE

#include <Object.h>



#if	defined(__cplusplus)
extern "C" {
#endif

DEFINE_BLOCK_TYPE(GSExtensionContextReturningItemsCompletionHandler, void, BOOL);
DEFINE_BLOCK_TYPE(GSOpenURLCompletionHandler, void, BOOL);

@class NSError, NSArray, NSURL;

GS_EXPORT_CLASS
@interface NSExtensionContext : NSObject
{
  NSArray *_inputItems;
}

- (void) setInputItems: (NSArray *)inputItems;
- (NSArray *) inputItems;
  
- (void)completeRequestReturningItems: (NSArray *)items completionHandler: (GSExtensionContextReturningItemsCompletionHandler)completionHandler;

- (void)cancelRequestWithError:(NSError *)error;

- (void)openURL: (NSURL *)URL completionHandler: (GSOpenURLCompletionHandler)completionHandler;

@end

GS_EXPORT NSString* const NSExtensionItemsAndErrorsKey;

GS_EXPORT NSString* const NSExtensionHostWillEnterForegroundNotification;

GS_EXPORT NSString* const NSExtensionHostDidEnterBackgroundNotification;

GS_EXPORT NSString* const NSExtensionHostWillResignActiveNotification;

GS_EXPORT NSString* const NSExtensionHostDidBecomeActiveNotification;

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSExtensionContext_h_GNUSTEP_BASE_INCLUDE */

