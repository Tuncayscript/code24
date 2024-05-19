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

#ifndef _NSXPCConnection_h_GNUSTEP_BASE_INCLUDE
#define _NSXPCConnection_h_GNUSTEP_BASE_INCLUDE

#include <Object.h>
#include <Error.h>

#include <sys/types.h> // for gid_t and uid_t



#if defined(_WIN32)
#if defined(_MSC_VER)
typedef int pid_t;
#endif
typedef unsigned gid_t;
typedef unsigned uid_t;
#endif

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSMutableDictionary, NSString, NSOperationQueue, NSSet, NSLock, NSError;
@class NSXPCConnection, NSXPCListener, NSXPCInterface, NSXPCListenerEndpoint;
@protocol NSXPCListenerDelegate;

DEFINE_BLOCK_TYPE(GSXPCProxyErrorHandler, void, NSError *);
DEFINE_BLOCK_TYPE_NO_ARGS(GSXPCInterruptionHandler, void);
DEFINE_BLOCK_TYPE_NO_ARGS(GSXPCInvalidationHandler, void);


@protocol NSXPCProxyCreating

- (id) remoteObjectProxy;

- (id) remoteObjectProxyWithErrorHandler: (GSXPCProxyErrorHandler)handler;

- (id) synchronousRemoteObjectProxyWithErrorHandler: (GSXPCProxyErrorHandler)handler;

@end

enum
{
    NSXPCConnectionPrivileged = (1 << 12UL)
};
typedef NSUInteger NSXPCConnectionOptions; 
  
GS_EXPORT_CLASS
@interface NSXPCConnection : NSObject <NSXPCProxyCreating>

- (instancetype) initWithListenerEndpoint: (NSXPCListenerEndpoint *)endpoint;

- (instancetype) initWithMachServiceName: (NSString *)name
				 options: (NSXPCConnectionOptions)options;

- (instancetype) initWithServiceName:(NSString *)serviceName;
  
- (NSXPCListenerEndpoint *) endpoint;
- (void) setEndpoint: (NSXPCListenerEndpoint *) endpoint;
  
- (NSXPCInterface *) exportedInterface;
- (void) setExportInterface: (NSXPCInterface *)exportedInterface;
  
- (NSXPCInterface *) remoteObjectInterface;
- (void) setRemoteObjectInterface: (NSXPCInterface *)remoteObjectInterface;


- (id) remoteObjectProxy;
- (void) setRemoteObjectProxy: (id)remoteObjectProxy;

- (id) remoteObjectProxyWithErrorHandler:(GSXPCProxyErrorHandler)handler;

- (NSString *) serviceName;
- (void) setServiceName: (NSString *)serviceName;
  
- (id) synchronousRemoteObjectProxyWithErrorHandler:
  (GSXPCProxyErrorHandler)handler;

- (GSXPCInterruptionHandler) interruptionHandler; 
- (void) setInterruptionHandler: (GSXPCInterruptionHandler)handler;
  
- (GSXPCInvalidationHandler) invalidationHandler; 
- (void) setInvalidationHandler: (GSXPCInvalidationHandler)handler;
  
- (void) resume;

- (void) suspend;

- (void) invalidate;

- (NSUInteger) auditSessionIdentifier;
- (pid_t) processIdentifier;
- (uid_t) effectiveUserIdentifier;
- (gid_t) effectiveGroupIdentifier;

@end


@interface NSXPCListener : NSObject

+ (NSXPCListener *) serviceListener;

+ (NSXPCListener *) anonymousListener;

- (instancetype) initWithMachServiceName:(NSString *)name;

- (id <NSXPCListenerDelegate>) delegate;
- (void) setDelegate: (id <NSXPCListenerDelegate>) delegate;

- (NSXPCListenerEndpoint *) endpoint;
- (void) setEndpoint: (NSXPCListenerEndpoint *)endpoint;
  
- (void) resume;

- (void) suspend;

- (void) invalidate;

@end

@protocol NSXPCListenerDelegate <NSObject>

- (BOOL) listener: (NSXPCListener *)listener
  shouldAcceptNewConnection: (NSXPCConnection *)newConnection;

@end

@interface NSXPCInterface : NSObject

+ (NSXPCInterface *) interfaceWithProtocol: (Protocol *)protocol;

- (Protocol *) protocol;
- (void) setProtocol: (Protocol *)protocol;

- (void) setClasses: (NSSet *)classes
	forSelector: (SEL)sel
      argumentIndex: (NSUInteger)arg
	    ofReply: (BOOL)ofReply;

- (NSSet *) classesForSelector: (SEL)sel
		 argumentIndex: (NSUInteger)arg
		       ofReply: (BOOL)ofReply;

- (void) setInterface: (NSXPCInterface *)ifc
	  forSelector: (SEL)sel
	argumentIndex: (NSUInteger)arg
	      ofReply: (BOOL)ofReply;

- (NSXPCInterface *) interfaceForSelector: (SEL)sel
			    argumentIndex: (NSUInteger)arg
				  ofReply: (BOOL)ofReply;

@end

GS_EXPORT_CLASS
@interface NSXPCListenerEndpoint : NSObject <NSCoding>  // NSSecureCoding
@end

#if	defined(__cplusplus)
}
#endif

#endif	/* GS_API_MACOSX */

#endif	/* _NSXPCConnection_h_GNUSTEP_BASE_INCLUDE */
