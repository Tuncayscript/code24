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


#ifndef __NSDistributedNotificationCenter_h_GNUSTEP_BASE_INCLUDE
#define __NSDistributedNotificationCenter_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>



#import	<Object.h>
#import	<Lock.h>
#import	<Notification.h>

#if	defined(__cplusplus)
extern "C" {
#endif


/**
 *  Enumeration of possible values for specifying how
 *  [NSDistributedNotificationCenter] deals with notifications when the
 *  process to which the notification should be delivered is suspended:
 <example>
 {
  NSNotificationSuspensionBehaviorDrop,       // drop the notification
  NSNotificationSuspensionBehaviorCoalesce,   // drop all for this process but the latest-sent notification
  NSNotificationSuspensionBehaviorHold,       // queue all notifications for this process until it is resumed
  NSNotificationSuspensionBehaviorDeliverImmediately  // resume the process and deliver
}
 </example>
 */
enum {
  NSNotificationSuspensionBehaviorDrop = 1,
  NSNotificationSuspensionBehaviorCoalesce = 2,
  NSNotificationSuspensionBehaviorHold = 3,
  NSNotificationSuspensionBehaviorDeliverImmediately = 4
};
typedef NSUInteger NSNotificationSuspensionBehavior;

/**
 *  Type for [NSDistributedNotificationCenter+notificationCenterForType:] -
 *  localhost current user broadcast only.  This is the only type on OS X.
 */
GS_EXPORT NSString* const NSLocalNotificationCenterType;


/**
 *  Type of [NSDistributedNotificationCenter+notificationCenterForType:] -
 *  all users on the local host.  This type is available only on GNUstep.
 */
GS_EXPORT NSString* const GSPublicNotificationCenterType;

/**
 *  Type of [NSDistributedNotificationCenter+notificationCenterForType:] -
 *  localhost and LAN broadcast.  This type is available only on GNUstep.
 */
GS_EXPORT NSString* const GSNetworkNotificationCenterType;
#endif

GS_EXPORT_CLASS
@interface	NSDistributedNotificationCenter : NSNotificationCenter
{
#if	GS_EXPOSE(NSDistributedNotificationCenter)
  NSRecursiveLock *_centerLock;	/* For thread safety.		*/
  NSString	*_type;		/* Type of notification center.	*/
  id		_remote;	/* Proxy for center.		*/
  BOOL		_suspended;	/* Is delivery suspended?	*/
#endif
#if     GS_NONFRAGILE
#else
  /* Pointer to private additional data used to avoid breaking ABI
   * when we don't have the non-fragile ABI available.
   * Use this mechanism rather than changing the instance variable
   * layout (see Source/GSInternal.h for details).
   */
  @private id _internal GS_UNUSED_IVAR;
#endif
}
+ (id) defaultCenter;
+ (NSDistributedNotificationCenter*) notificationCenterForType: (NSString*)type;

- (void) addObserver: (id)anObserver
	    selector: (SEL)aSelector
		name: (NSString*)notificationName
	      object: (NSString*)anObject;
- (void) addObserver: (id)anObserver
	    selector: (SEL)aSelector
		name: (NSString*)notificationName
	      object: (NSString*)anObject
  suspensionBehavior: (NSNotificationSuspensionBehavior)suspensionBehavior;
- (void) postNotification: (NSNotification*)notification;
- (void) postNotificationName: (NSString*)notificationName
		       object: (NSString*)anObject;
- (void) postNotificationName: (NSString*)notificationName
		       object: (NSString*)anObject
		     userInfo: (NSDictionary*)userInfo;
- (void) postNotificationName: (NSString*)notificationName
		       object: (NSString*)anObject
		     userInfo: (NSDictionary*)userInfo
	   deliverImmediately: (BOOL)deliverImmediately;
- (void) removeObserver: (id)anObserver
		   name: (NSString*)notificationName
		 object: (NSString*)anObject;
- (void) setSuspended: (BOOL)flag;
- (BOOL) suspended;

@end

#if	defined(__cplusplus)
}
#endif

#endif
#endif

