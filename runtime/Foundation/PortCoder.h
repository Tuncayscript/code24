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


#ifndef __NSPortCoder_h_GNUSTEP_BASE_INCLUDE
#define __NSPortCoder_h_GNUSTEP_BASE_INCLUDE
#import	<Base/VersionMacros.h>

#import	<Coder.h>

#if	defined(__cplusplus)
extern "C" {
#endif

@class NSMutableArray;
@class NSMutableDictionary;
@class NSConnection;
@class NSPort;

/**
 * This class is an [NSCoder] implementation specialized for sending objects
 * over network connections for immediate use (as opposed to the archivers
 * which persist objects for reconstitution after an indefinite term).  It is
 * used to help implement the distributed objects framework by the
 * [NSConnection] class.  Even for highly specialized applications, you
 * probably do not need to use this class directly.
 */
//FIXME: the above is what Apple's docs say, but looking at the code the
// NSConnection is actually created by this class rather than the other way
// around, so maybe the docs should be changed..
GS_EXPORT_CLASS
@interface NSPortCoder : NSCoder
{
#if	GS_EXPOSE(NSPortCoder)
@private
  NSMutableArray	*_comp;
  NSConnection		*_conn;
  BOOL			_is_by_copy;
  BOOL			_is_by_ref;
// Encoding
  BOOL			_encodingRoot;
  BOOL			_initialPass;
  id			_dst;		/* Serialization destination.	*/
  IMP			_eObjImp;	/* Method to encode an id.	*/
  IMP			_eValImp;	/* Method to encode others.	*/
#ifndef	_IN_PORT_CODER_M
#define	GSIMapTable	void*
#endif
  GSIMapTable		_clsMap;	/* Class cross references.	*/
  GSIMapTable		_cIdMap;	/* Conditionally coded.		*/
  GSIMapTable		_uIdMap;	/* Unconditionally coded.	*/
  GSIMapTable		_ptrMap;	/* Constant pointers.		*/
#ifndef	_IN_PORT_CODER_M
#undef	GSIMapTable
#endif
  unsigned		_xRefC;		/* Counter for cross-reference.	*/
  unsigned		_xRefO;		/* Counter for cross-reference.	*/
  unsigned		_xRefP;		/* Counter for cross-reference.	*/
// Decoding
  id			_src;		/* Deserialization source.	*/
  IMP			_dDesImp;	/* Method to deserialize with.	*/
  void			(*_dTagImp)(id,SEL,unsigned char*,unsigned*,unsigned*);
  IMP			_dValImp;	/* Method to decode data with.	*/
#ifndef	_IN_PORT_CODER_M
#define	GSIArray	void*
#endif
  GSIArray		_clsAry;	/* Class crossreference map.	*/
  GSIArray		_objAry;	/* Object crossreference map.	*/
  GSIArray		_ptrAry;	/* Pointer crossreference map.	*/
#ifndef	_IN_PORT_CODER_M
#undef	GSIArray
#endif
  NSMutableDictionary	*_cInfo;	/* Class version information.	*/
  unsigned		_cursor;	/* Position in data buffer.	*/
  unsigned		_version;	/* Version of archiver used.	*/
  NSZone		*_zone;		/* Zone for allocating objs.	*/
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
 * Create a new instance for communications over send and recv, and send an
 * initial message through send as specified by comp.
 */
+ (NSPortCoder*) portCoderWithReceivePort: (NSPort*)recv
				 sendPort: (NSPort*)send
			       components: (NSArray*)comp;

/**
 * Initialize a new instance for communications over send and recv, and send an
 * initial message through send as specified by comp.
 */
- (id) initWithReceivePort: (NSPort*)recv
		  sendPort: (NSPort*)send
		components: (NSArray*)comp;

/**
 * Returns the <code>NSConnection</code> using this instance.
 */
- (NSConnection*) connection;

/**
 * Return port object previously encoded by this instance.  Mainly for use
 * by the ports themselves.
 */
- (NSPort*) decodePortObject;

/**
 * Processes and acts upon the initial message the receiver was initialized
 * with..
 */
- (void) dispatch;

/**
 * Encodes aPort so it can be sent to the receiving side of the connection.
 * Mainly for use by the ports themselves.
 */
- (void) encodePortObject: (NSPort*)aPort;

/**
 * Returns YES if receiver is in the process of encoding objects by copying
 * them (rather than substituting a proxy).  This method is mainly needed
 * internally and by subclasses.
 */
- (BOOL) isBycopy;

/**
 * Returns YES if receiver will substitute a proxy when encoding objects
 * rather than by copying them.  This method is mainly needed
 * internally and by subclasses.
 */
- (BOOL) isByref;

@end

/**
 * This informal protocol allows an object to control the details of how an
 * object is sent over the wire in distributed objects Port communications.
 */
@interface NSObject (NSPortCoder)
/**
 *	Must return the class that will be created on the remote side
 *	of the connection.  If the class to be created is not the same
 *	as that of the object returned by replacementObjectForPortCoder:
 *	then the class must be capable of recognising the object it
 *	actually gets in its initWithCoder: method.
 *	The default operation is to return NSDistantObject unless the
 *	object is being sent bycopy, in which case the objects actual
 *	class is returned.  To force bycopy operation the object should
 *	return its own class.
 */
- (Class) classForPortCoder;

/**
 *	This message is sent to an object about to be encoded for sending
 *	over the wire.  The default action is to return an NSDistantObject
 *	which is a local proxy for the object unless the object is being
 *	sent bycopy, in which case the actual object is returned.
 *	To force bycopy, an object should return itself.
 */
- (id) replacementObjectForPortCoder: (NSPortCoder*)aCoder;

@end

#if	defined(__cplusplus)
}
#endif

#endif /* __NSPortCoder_h_GNUSTEP_BASE_INCLUDE */

