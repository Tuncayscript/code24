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


#ifndef __NSDistantObject_h_GNUSTEP_BASE_INCLUDE
#define __NSDistantObject_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Proxy.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class	NSConnection;

GS_EXPORT_CLASS
@interface NSDistantObject : NSProxy <NSCoding>
{
#if	GS_EXPOSE(NSDistantObject)
@public
  NSConnection	*_connection;
  id		_object;
  unsigned	_handle;
  Protocol	*_protocol;
  unsigned	_counter;
  void		*_sigs;
#endif
}

+ (NSDistantObject*) proxyWithLocal: (id)anObject
			 connection: (NSConnection*)aConnection;
/*
 *	NB. Departure from the OpenStep/MacOS spec - the type of a target
 *	is an integer, not an id, since we can't safely pass id's
 *	between address spaces on machines with different pointer sizes.
 */
+ (NSDistantObject*) proxyWithTarget: (unsigned)anObject
			  connection: (NSConnection*)aConnection;

- (NSConnection*) connectionForProxy;
- (id) initWithLocal: (id)anObject
	  connection: (NSConnection*)aConnection;
- (id) initWithTarget: (unsigned)target
	   connection: (NSConnection*)aConnection;
- (NSMethodSignature*) methodSignatureForSelector: (SEL)aSelector;
- (void) setProtocolForProxy: (Protocol*)aProtocol;

@end

#if	defined(__cplusplus)
}
#endif

#endif /* __NSDistantObject_h_GNUSTEP_BASE_INCLUDE */
