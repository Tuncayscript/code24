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


#ifndef _NSExtensionItem_h_GNUSTEP_BASE_INCLUDE
#define _NSExtensionItem_h_GNUSTEP_BASE_INCLUDE

#include <Object.h>



#if	defined(__cplusplus)
extern "C" {
#endif

@class NSAttributedString, NSArray, NSDictionary;

GS_EXPORT_CLASS
@interface NSExtensionItem : NSObject
{
  NSAttributedString *_attributedTitle;
  NSAttributedString *_attributedContentText;
  NSArray *_attachments;
  NSDictionary *_userInfo;
}
  
- (NSAttributedString *) attributedTitle;
- (void) setAttributedTitle: (NSAttributedString *)string;

- (NSAttributedString *) attributedContentText;
- (void) setAttributedContentText: (NSAttributedString *)string;
  
- (NSArray *) attachments;
- (void) setAttachments: (NSArray *)attachments;

- (NSDictionary *) userInfo;
- (void) setUserInfo: (NSDictionary *) userInfo;
  
@end

GS_EXPORT NSString * const NSExtensionItemAttributedTitleKey;

GS_EXPORT NSString * const NSExtensionItemAttributedContentTextKey;

GS_EXPORT NSString * const NSExtensionItemAttachmentsKey;

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSExtensionItem_h_GNUSTEP_BASE_INCLUDE */

