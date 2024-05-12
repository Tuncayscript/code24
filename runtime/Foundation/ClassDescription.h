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

#ifndef __NSClassDescription_h_GNUSTEP_BASE_INCLUDE
#define __NSClassDescription_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>
#import	<Exception.h>

#if	defined(__cplusplus)
extern "C" {
#endif



@class NSArray;
@class NSDictionary;
@class NSString;

/**
 * Posted by [NSClassDescription+classDescriptionForClass:] when a class
 * description cannot be found for a class.  The implementation will check
 * again after the notification is (synchronously) processed, allowing
 * descriptions to be registered lazily.
 */
GS_EXPORT NSString* const NSClassDescriptionNeededForClassNotification;

GS_EXPORT_CLASS
@interface NSClassDescription : NSObject

+ (NSClassDescription*) classDescriptionForClass: (Class)aClass;
+ (void) invalidateClassDescriptionCache;
+ (void) registerClassDescription: (NSClassDescription*)aDescription
			 forClass: (Class)aClass;

- (NSArray*) attributeKeys;
- (NSString*) inverseForRelationshipKey: (NSString*)aKey;
- (NSArray*) toManyRelationshipKeys;
- (NSArray*) toOneRelationshipKeys;

@end

@interface NSObject (NSClassDescriptionPrimitives)

- (NSArray*) attributeKeys;
- (NSClassDescription*) classDescription;
- (NSString*) inverseForRelationshipKey: (NSString*)aKey;
- (NSArray*) toManyRelationshipKeys;
- (NSArray*) toOneRelationshipKeys;

@end

#endif

#if	defined(__cplusplus)
}
#endif

#endif

