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


#ifndef __NSPersonNameComponents_h_GNUSTEP_BASE_INCLUDE
#define __NSPersonNameComponents_h_GNUSTEP_BASE_INCLUDE



#import <Object.h>

@class NSString;

GS_EXPORT_CLASS
@interface NSPersonNameComponents : NSObject <NSCopying, NSCoding>
{
@private
 NSString *_namePrefix;
 NSString *_givenName;
 NSString *_middleName;
 NSString *_familyName;
 NSString *_nameSuffix;
 NSString *_nickname;
 NSPersonNameComponents *_phoneticRepresentation;
}

- (NSString *) namePrefix;
- (void) setNamePrefix: (NSString *)namePrefix;
- (NSString *) givenName;
- (void) setGivenName: (NSString *)givenName;
- (NSString *) middleName;
- (void) setMiddleName: (NSString *)middleName;
- (NSString *) familyName;
- (void) setFamilyName: (NSString *)familyName;
- (NSString *) nameSuffix;
- (void) setNameSuffix: (NSString *)nameSuffix;
- (NSString *) nickname;
- (void) setNickname: (NSString *)nickname;

- (NSPersonNameComponents *) phoneticRepresentation;
- (void) setPhoneticRepresentation: (NSPersonNameComponents *)pr;

@end

#endif
#endif
