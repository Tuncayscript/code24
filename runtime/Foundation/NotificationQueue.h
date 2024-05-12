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


#ifndef __NSNotificationQueue_h_GNUSTEP_BASE_INCLUDE
#define __NSNotificationQueue_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Object.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSArray;
@class NSNotification;
@class NSNotificationCenter;

/*
 * Posting styles into notification queue
 */

/**
 *  Enumeration of possible timings for distribution of notifications handed
 *  to an [NSNotificationQueue]:
 <example>
{
  NSPostWhenIdle,	// post when runloop is idle
  NSPostASAP,		// post soon
  NSPostNow		// post synchronously
}
 </example>
 */
enum {
  NSPostWhenIdle = 1,
  NSPostASAP = 2,
  NSPostNow = 3
};
typedef NSUInteger NSPostingStyle;

/**
 * Enumeration of possible ways to combine notifications when dealing with
 * [NSNotificationQueue]:
 <example>
{
  NSNotificationNoCoalescing,       // don't combine
  NSNotificationCoalescingOnName,   // combine all registered with same name
  NSNotificationCoalescingOnSender  // combine all registered with same object
}
 </example>
 */
enum {
  NSNotificationNoCoalescing = 0,
  NSNotificationCoalescingOnName = 1,
  NSNotificationCoalescingOnSender = 2
};
typedef NSUInteger NSNotificationCoalescing;

/*
 * NSNotificationQueue class
 */

/**
 *  Structure used internally by [NSNotificationQueue].
 */
struct _NSNotificationQueueList;

GS_EXPORT_CLASS
@interface NSNotificationQueue : NSObject
{
#if	GS_EXPOSE(NSNotificationQueue)
@public
  NSNotificationCenter			*_center;
  struct _NSNotificationQueueList	*_asapQueue;
  struct _NSNotificationQueueList	*_idleQueue;
  NSZone				*_zone;
#endif
}

/* Creating Notification Queues */

+ (NSNotificationQueue*) defaultQueue;
- (id) initWithNotificationCenter: (NSNotificationCenter*)notificationCenter;

/* Inserting and Removing Notifications From a Queue */

- (void) dequeueNotificationsMatching: (NSNotification*)notification
			 coalesceMask: (NSUInteger)coalesceMask;

- (void) enqueueNotification: (NSNotification*)notification
	        postingStyle: (NSPostingStyle)postingStyle;

- (void) enqueueNotification: (NSNotification*)notification
	        postingStyle: (NSPostingStyle)postingStyle
	        coalesceMask: (NSUInteger)coalesceMask
		    forModes: (NSArray*)modes;

@end

#if	defined(__cplusplus)
}
#endif

#endif /* __NSNotificationQueue_h_GNUSTEP_BASE_INCLUDE */
