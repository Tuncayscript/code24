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


#ifndef __NSPortMessage_h_GNUSTEP_BASE_INCLUDE
#define __NSPortMessage_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Array.h>
#import	<Port.h>

#if	defined(__cplusplus)
extern "C" {
#endif

/**
 * <p>The data transported for distributed objects communications is sent over
 * the network encapsulated by NSPortMessage objects, which consist of two
 * [NSPort]s (sender and receiver, not sent over the network) and a body
 * consisting of one or more [NSData] or [NSPort] objects. (Data in the
 * [NSData] must be in network byte order.)</p>
 *
 * <p>See the [NSConnection] and [NSPortCoder] classes.</p>
 */
@interface	NSPortMessage : NSObject
{
#if	GS_EXPOSE(NSPortMessage)
@private
  unsigned		_msgid;
  NSPort		*_recv;
  NSPort		*_send;
  NSMutableArray	*_components;
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
/**
 * OpenStep compatibility.
 */
- (id) initWithMachMessage: (void*)buffer;

/** <init/> Initializes to send message described by items (which should
 * contain only [NSPort] and/or [NSData] objects, with contents in network
 * byte order) over aPort.  If/when a reply to the message is sent, it will
 * arrive on anotherPort.
 */
- (id) initWithSendPort: (NSPort*)aPort
	    receivePort: (NSPort*)anotherPort
	     components: (NSArray*)items;

/**
 * Request that the message be sent before when.  Will block until either
 * sends it (returns YES) or when expires (returns NO).  The latter may occur
 * if many messages are queued up (by multiple threads) faster than they can
 * be sent over the network.
 */
- (BOOL) sendBeforeDate: (NSDate*)when;

/**
 * Returns the message components originally used to constitute this message.
 */
- (NSArray*) components;

/**
 * For an outgoing message, returns the port the receiver will send itself
 * through.  For an incoming message, returns the port replies to the receiver
 * should be sent through.
 */
- (NSPort*) sendPort;

/**
 * For an outgoing message, returns the port on which a reply to this message
 * will arrive.  For an incoming message, returns the port this message
 * arrived on.
 */
- (NSPort*) receivePort;

/**
 * Sets ID for message.  This is not used by the distributed objects system,
 * but may be used in custom ways by cooperating applications to sort or
 * otherwise organize messages.
 */
- (void) setMsgid: (unsigned)anId;

/**
 * Returns ID for message.  This is not used by the distributed objects
 * system, but may be used in custom ways by cooperating applications to sort
 * or otherwise organize messages.  Set to 0 initially.
 */
- (unsigned) msgid;
@end

#if	defined(__cplusplus)
}
#endif

#endif

