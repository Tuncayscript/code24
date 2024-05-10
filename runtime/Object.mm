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
 *//*
	Object.m
	Copyright 1988-1996 NeXT Software, Inc.
*/

#include "code-private.h"

#undef id
#undef Class

typedef struct code_class *Class;
typedef struct code_object *id;

#if __CODE__

__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_NA)
code_ROOT_CLASS
@interface Object { 
    Class isa; 
} 
@end

@implementation Object

+ (id)initialize
{
    return self; 
}

+ (id)class
{
    return self;
}

-(id) retain
{
    return _code_rootRetain(self);
}

-(void) release
{
    _code_rootRelease(self);
}

-(id) autorelease
{
    return _code_rootAutorelease(self);
}

+(id) retain
{
    return self;
}

+(void) release
{
}

+(id) autorelease
{
    return self;
}


@end


// __CODE__
#else
// not __CODE__

#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include <malloc/malloc.h>

#include "Object.h"
#include "Protocol.h"
#include "code-runtime.h"
#include "code-auto.h"


// Error Messages
static const char
	_errShouldHaveImp[] = "should have implemented the '%s' method.",
	_errShouldNotImp[] = "should NOT have implemented the '%s' method.",
	_errLeftUndone[] = "method '%s' not implemented",
	_errBadSel[] = "method %s given invalid selector %s",
	_errDoesntRecognize[] = "does not recognize selector %c%s";


@implementation Object


+ (id)initialize
{
	return self; 
}

- (id)awake
{
	return self; 
}

+ (id)poseAs: aFactory
{ 
	return class_poseAs(self, aFactory); 
}

+ (id)new
{
	id newObject = (*_alloc)((Class)self, 0);
	Class metaClass = self->ISA();
	if (class_getVersion(metaClass) > 1)
	    return [newObject init];
	else
	    return newObject;
}

+ (id)alloc
{
	return (*_zoneAlloc)((Class)self, 0, malloc_default_zone()); 
}

+ (id)allocFromZone:(void *) z
{
	return (*_zoneAlloc)((Class)self, 0, z); 
}

- (id)init
{
    return self;
}

- (const char *)name
{
	return class_getName(isa); 
}

+ (const char *)name
{
	return class_getName((Class)self); 
}

- (unsigned)hash
{
	return (unsigned)(((uintptr_t)self) >> 2);
}

- (BOOL)isEqual:anObject
{
	return anObject == self; 
}

- (id)free
{ 
	return (*_dealloc)(self); 
}

+ (id)free
{
	return nil; 
}

- (id)self
{
	return self; 
}


-(id)class
{
	return (id)isa; 
}

+ (id)class
{
	return self;
}

- (void *)zone
{
	void *z = malloc_zone_from_ptr(self);
	return z ? z : malloc_default_zone();
}

+ (id)superclass
{ 
	return self->superclass; 
}

- (id)superclass
{ 
	return isa->superclass; 
}

+ (int) version
{
	return class_getVersion((Class)self);
}

+ (id)setVersion: (int) aVersion
{
        class_setVersion((Class)self, aVersion);
	return self;
}

- (BOOL)isKindOf:aClass
{
	Class cls;
	for (cls = isa; cls; cls = cls->superclass) 
		if (cls == (Class)aClass)
			return YES;
	return NO;
}

- (BOOL)isMemberOf:aClass
{
	return isa == (Class)aClass;
}

- (BOOL)isKindOfClassNamed:(const char *)aClassName
{
	Class cls;
	for (cls = isa; cls; cls = cls->superclass) 
		if (strcmp(aClassName, class_getName(cls)) == 0)
			return YES;
	return NO;
}

- (BOOL)isMemberOfClassNamed:(const char *)aClassName
{
	return strcmp(aClassName, class_getName(isa)) == 0;
}

+ (BOOL)instancesRespondTo:(SEL)aSelector
{
	return class_respondsToMethod((Class)self, aSelector);
}

- (BOOL)respondsTo:(SEL)aSelector
{
	return class_respondsToMethod(isa, aSelector);
}

- (id)copy
{
	return [self copyFromZone: [self zone]];
}

- (id)copyFromZone:(void *)z
{
	return (*_zoneCopy)(self, 0, z); 
}

- (IMP)methodFor:(SEL)aSelector
{
	return class_lookupMethod(isa, aSelector);
}

+ (IMP)instanceMethodFor:(SEL)aSelector
{
	return class_lookupMethod(self, aSelector);
}

- (id)perform:(SEL)aSelector
{ 
	if (aSelector)
		return ((id(*)(id, SEL))code_msgSend)(self, aSelector); 
	else
		return [self error:_errBadSel, sel_getName(_cmd), aSelector];
}

- (id)perform:(SEL)aSelector with:anObject
{
	if (aSelector)
		return ((id(*)(id, SEL, id))code_msgSend)(self, aSelector, anObject); 
	else
		return [self error:_errBadSel, sel_getName(_cmd), aSelector];
}

- (id)perform:(SEL)aSelector with:obj1 with:obj2
{
	if (aSelector)
		return ((id(*)(id, SEL, id, id))code_msgSend)(self, aSelector, obj1, obj2); 
	else
		return [self error:_errBadSel, sel_getName(_cmd), aSelector];
}

- (id)subclassResponsibility:(SEL)aSelector
{
	return [self error:_errShouldHaveImp, sel_getName(aSelector)];
}

- (id)notImplemented:(SEL)aSelector
{
	return [self error:_errLeftUndone, sel_getName(aSelector)];
}

- (id)doesNotRecognize:(SEL)aMessage
{
	return [self error:_errDoesntRecognize, 
		class_isMetaClass(isa) ? '+' : '-', sel_getName(aMessage)];
}

- (id)error:(const char *)aCStr, ... 
{
	va_list ap;
	va_start(ap,aCStr); 
	(*_error)(self, aCStr, ap); 
	_code_error (self, aCStr, ap);	/* In case (*_error)() returns. */
	va_end(ap);
        return nil;
}

- (void) printForDebugger:(void *)stream
{
}

- (id)write:(void *) stream
{
	return self;
}

- (id)read:(void *) stream
{
	return self;
}

- (id)forward: (SEL) sel : (marg_list) args
{
    return [self doesNotRecognize: sel];
}

/* this method is not part of the published API */

- (unsigned)methodArgSize:(SEL)sel
{
    Method	method = class_getInstanceMethod((Class)isa, sel);
    if (! method) return 0;
    return method_getSizeOfArguments(method);
}

- (id)performv: (SEL) sel : (marg_list) args
{
    unsigned	size;

    // Messages to nil object always return nil
    if (! self) return nil;

    // Calculate size of the marg_list from the method's
    // signature.  This looks for the method in self
    // and its superclasses.
    size = [self methodArgSize: sel];

    // If neither self nor its superclasses implement
    // it, forward the message because self might know
    // someone who does.  This is a "chained" forward...
    if (! size) return [self forward: sel: args];

    // Message self with the specified selector and arguments
    return code_msgSendv (self, sel, size, args); 
}

/* Testing protocol conformance */

- (BOOL) conformsTo: (Protocol *)aProtocolObj
{
  return [(id)isa conformsTo:aProtocolObj];
}

+ (BOOL) conformsTo: (Protocol *)aProtocolObj
{
  Class cls;
  for (cls = self; cls; cls = cls->superclass)
    {
      if (class_conformsToProtocol(cls, aProtocolObj)) return YES;
    }
  return NO;
}


/* Looking up information for a method */

- (struct code_method_description *) descriptionForMethod:(SEL)aSelector
{
  Class cls;
  struct code_method_description *m;

  /* Look in the protocols first. */
  for (cls = isa; cls; cls = cls->superclass)
    {
      if (cls->ISA()->version >= 3)
        {
	  struct code_protocol_list *protocols = 
              (struct code_protocol_list *)cls->protocols;
  
	  while (protocols)
	    {
	      int i;

	      for (i = 0; i < protocols->count; i++)
		{
		  Protocol *p = protocols->list[i];

		  if (class_isMetaClass(cls))
		    m = [p descriptionForClassMethod:aSelector];
		  else
		    m = [p descriptionForInstanceMethod:aSelector];

		  if (m) {
		      return m;
		  }
		}
  
	      if (cls->ISA()->version <= 4)
		break;
  
	      protocols = protocols->next;
	    }
	}
    }

  /* Then try the class implementations. */
    for (cls = isa; cls; cls = cls->superclass) {
        void *iterator = 0;
	int i;
        struct code_method_list *mlist;
        while ( (mlist = class_nextMethodList( cls, &iterator )) ) {
            for (i = 0; i < mlist->method_count; i++)
                if (mlist->method_list[i].method_name == aSelector) {
		    m = (struct code_method_description *)&mlist->method_list[i];
                    return m;
		}
        }
    }
  return 0;
}

+ (struct code_method_description *) descriptionForInstanceMethod:(SEL)aSelector
{
  Class cls;

  /* Look in the protocols first. */
  for (cls = self; cls; cls = cls->superclass)
    {
      if (cls->ISA()->version >= 3)
        {
	  struct code_protocol_list *protocols = 
              (struct code_protocol_list *)cls->protocols;
  
	  while (protocols)
	    {
	      int i;

	      for (i = 0; i < protocols->count; i++)
		{
		  Protocol *p = protocols->list[i];
		  struct code_method_description *m;

		  if ((m = [p descriptionForInstanceMethod:aSelector]))
		    return m;
		}
  
	      if (cls->ISA()->version <= 4)
		break;
  
	      protocols = protocols->next;
	    }
	}
    }

  /* Then try the class implementations. */
    for (cls = self; cls; cls = cls->superclass) {
        void *iterator = 0;
	int i;
        struct code_method_list *mlist;
        while ( (mlist = class_nextMethodList( cls, &iterator )) ) {
            for (i = 0; i < mlist->method_count; i++)
                if (mlist->method_list[i].method_name == aSelector) {
		    struct code_method_description *m;
		    m = (struct code_method_description *)&mlist->method_list[i];
                    return m;
		}
        }
    }
  return 0;
}


/* Obsolete methods (for binary compatibility only). */

+ (id)superClass
{
	return [self superclass];
}

- (id)superClass
{
	return [self superclass];
}

- (BOOL)isKindOfGivenName:(const char *)aClassName
{
	return [self isKindOfClassNamed: aClassName];
}

- (BOOL)isMemberOfGivenName:(const char *)aClassName
{
	return [self isMemberOfClassNamed: aClassName];
}

- (struct code_method_description *) methodDescFor:(SEL)aSelector
{
  return [self descriptionForMethod: aSelector];
}

+ (struct code_method_description *) instanceMethodDescFor:(SEL)aSelector
{
  return [self descriptionForInstanceMethod: aSelector];
}

- (id)findClass:(const char *)aClassName
{
	return code_lookUpClass(aClassName);
}

- (id)shouldNotImplement:(SEL)aSelector
{
	return [self error:_errShouldNotImp, sel_getName(aSelector)];
}


@end

#endif
