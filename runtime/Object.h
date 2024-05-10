/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
  *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with ITGSS, 651 N Broad St, Suite 201, in the
 * city of Middletown, zip code 19709, and county of New Castle, state of Delaware.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */
/*
	Object.h
	Copyright 1988-1996 NeXT Software, Inc.
  
	DEFINED AS:	A common class
	HEADER FILES:	<runtime/Object.h>

*/

#ifndef OBJECT_H_
#define OBJECT_H_

#include <stdarg.h>
#include <runtime/code-runtime.h>

#if __CODE__  &&  !__CODE__

__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_NA)
code_ROOT_CLASS
@interface Object
{
	Class isa;	/* A pointer to the instance's class structure */
}

/* Initializing classes and instances */

+ (id)initialize;
- (id)init;

/* Creating, copying, and freeing instances */

+ (id)new;
+ (id)free;
- (id)free;
+ (id)alloc;
- (id)copy;
+ (id)allocFromZone:(void *)zone;
- (id)copyFromZone:(void *)zone;
- (void *)zone;

/* Identifying classes */

+ (id)class;
+ (id)superclass;
+ (const char *) name;
- (id)class;
- (id)superclass;
- (const char *) name;

/* Identifying and comparing instances */

- (id)self;
- (unsigned int) hash;
- (BOOL) isEqual:anObject;

/* Testing inheritance relationships */

- (BOOL) isKindOf: aClassObject;
- (BOOL) isMemberOf: aClassObject;
- (BOOL) isKindOfClassNamed: (const char *)aClassName;
- (BOOL) isMemberOfClassNamed: (const char *)aClassName;

/* Testing class functionality */

+ (BOOL) instancesRespondTo:(SEL)aSelector;
- (BOOL) respondsTo:(SEL)aSelector;

/* Testing protocol conformance */

- (BOOL) conformsTo: (Protocol *)aProtocolObject;
+ (BOOL) conformsTo: (Protocol *)aProtocolObject;

/* Obtaining method descriptors from protocols */

- (struct code_method_description *) descriptionForMethod:(SEL)aSel;
+ (struct code_method_description *) descriptionForInstanceMethod:(SEL)aSel;

/* Obtaining method handles */

- (IMP) methodFor:(SEL)aSelector;
+ (IMP) instanceMethodFor:(SEL)aSelector;

/* Sending messages determined at run time */

- (id)perform:(SEL)aSelector;
- (id)perform:(SEL)aSelector with:anObject;
- (id)perform:(SEL)aSelector with:object1 with:object2;

/* Posing */

+ (id)poseAs: aClassObject;

/* Enforcing intentions */
 
- (id)subclassResponsibility:(SEL)aSelector;
- (id)notImplemented:(SEL)aSelector;

/* Error handling */

- (id)doesNotRecognize:(SEL)aSelector;
- (id)error:(const char *)aString, ...;

/* Debugging */

- (void) printForDebugger:(void *)stream;

/* Archiving */

- (id)awake;
- (id)write:(void *)stream;
- (id)read:(void *)stream;
+ (int) version;
+ (id)setVersion: (int) aVersion;

/* Forwarding */

- (id)forward: (SEL)sel : (marg_list)args;
- (id)performv: (SEL)sel : (marg_list)args;

@end

/* Abstract Protocol for Archiving */

@interface Object (Archiving)

- (id)startArchiving: (void *)stream;
- (id)finishUnarchiving;

@end

/* Abstract Protocol for Dynamic Loading */

@interface Object (DynamicLoading)

//+ finishLoading:(headerType *)header;
struct mach_header;
+ (id)finishLoading:(struct mach_header *)header;
+ (id)startUnloading;

@end

#endif

#endif /* _code_OBJECT_H_ */
