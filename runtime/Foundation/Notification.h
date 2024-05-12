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


#ifndef __NSNotification_h_GNUSTEP_BASE_INCLUDE
#define __NSNotification_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>
#import	<MapTable.h>
#import <Base/Blocks.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSString;
@class NSDictionary;
@class NSLock;
@class NSOperationQueue;

typedef NSString* NSNotificationName;

GS_EXPORT_CLASS
@interface NSNotification : NSObject <NSCopying, NSCoding>

/* Creating a Notification Object */
+ (NSNotification*) notificationWithName: (NSString*)name
				  object: (id)object;

+ (NSNotification*) notificationWithName: (NSString*)name
				  object: (id)object
			        userInfo: (NSDictionary*)info;

/* Querying a Notification Object */

- (NSString*) name;
- (id) object;
- (NSDictionary*) userInfo;

@end



DEFINE_BLOCK_TYPE(GSNotificationBlock, void, NSNotification *);
#endif

GS_EXPORT_CLASS
@interface NSNotificationCenter : NSObject
{
#if	GS_EXPOSE(NSNotificationCenter)
@private
  void	         *_table;
#endif
}

+ (NSNotificationCenter*) defaultCenter;

- (void) addObserver: (id)observer
            selector: (SEL)selector
                name: (NSString*)name
              object: (id)object;

- (id) addObserverForName: (NSString *)name 
                   object: (id)object 
                    queue: (NSOperationQueue *)queue 
               usingBlock: (GSNotificationBlock)block;
#endif

- (void) removeObserver: (id)observer;
- (void) removeObserver: (id)observer
                   name: (NSString*)name
                 object: (id)object;

- (void) postNotification: (NSNotification*)notification;
- (void) postNotificationName: (NSString*)name
                       object: (id)object;
- (void) postNotificationName: (NSString*)name
                       object: (id)object
                     userInfo: (NSDictionary*)info;

@end

#if	defined(__cplusplus)
}
#endif

#endif /*__NSNotification_h_GNUSTEP_BASE_INCLUDE */
