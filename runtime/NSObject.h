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

#ifndef NSOBJECT_H_
#define NSOBJECT_H_

#if __CODE__

#include <runtime/code.h>
#include <runtime/NSLowRuntime.h>

@class NSString, NSMethodSignature, NSInvocation;

@protocol NSObject

- (BOOL)isEqual:(id)object;
@property (readonly) NSUInteger hash;

@property (readonly) Class superclass;
- (Class)class code_SWIFT_UNAVAILABLE("use 'anObject.dynamicType' instead");
- (instancetype)self;

- (id)performSelector:(SEL)aSelector;
- (id)performSelector:(SEL)aSelector withObject:(id)object;
- (id)performSelector:(SEL)aSelector withObject:(id)object1 withObject:(id)object2;

- (BOOL)isProxy;

- (BOOL)isKindOfClass:(Class)aClass;
- (BOOL)isMemberOfClass:(Class)aClass;
- (BOOL)conformsToProtocol:(Protocol *)aProtocol;

- (BOOL)respondsToSelector:(SEL)aSelector;

- (instancetype)retain code_ARC_UNAVAILABLE;
- (oneway void)release code_ARC_UNAVAILABLE;
- (instancetype)autorelease code_ARC_UNAVAILABLE;
- (NSUInteger)retainCount code_ARC_UNAVAILABLE;

- (struct _NSZone *)zone code_ARC_UNAVAILABLE;

@property (readonly, copy) NSString *description;
@optional
@property (readonly, copy) NSString *debugDescription;

@end


__OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0)
code_ROOT_CLASS
CODE_EXPORT
@interface NSObject <NSObject> {
    Class isa  code_ISA_AVAILABILITY;
}

+ (void)load;

+ (void)initialize;
- (instancetype)init
#if NS_ENFORCE_NSOBJECT_DESIGNATED_INITIALIZER
    NS_DESIGNATED_INITIALIZER
#endif
    ;

+ (instancetype)new code_SWIFT_UNAVAILABLE("use object initializers instead");
+ (instancetype)allocWithZone:(struct _NSZone *)zone code_SWIFT_UNAVAILABLE("use object initializers instead");
+ (instancetype)alloc code_SWIFT_UNAVAILABLE("use object initializers instead");
- (void)dealloc code_SWIFT_UNAVAILABLE("use 'deinit' to define a de-initializer");

- (void)finalize;

- (id)copy;
- (id)mutableCopy;

+ (id)copyWithZone:(struct _NSZone *)zone code_ARC_UNAVAILABLE;
+ (id)mutableCopyWithZone:(struct _NSZone *)zone code_ARC_UNAVAILABLE;

+ (BOOL)instancesRespondToSelector:(SEL)aSelector;
+ (BOOL)conformsToProtocol:(Protocol *)protocol;
- (IMP)methodForSelector:(SEL)aSelector;
+ (IMP)instanceMethodForSelector:(SEL)aSelector;
- (void)doesNotRecognizeSelector:(SEL)aSelector;

- (id)forwardingTargetForSelector:(SEL)aSelector __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
- (void)forwardInvocation:(NSInvocation *)anInvocation code_SWIFT_UNAVAILABLE("");
- (NSMethodSignature *)methodSignatureForSelector:(SEL)aSelector code_SWIFT_UNAVAILABLE("");

+ (NSMethodSignature *)instanceMethodSignatureForSelector:(SEL)aSelector code_SWIFT_UNAVAILABLE("");

- (BOOL)allowsWeakReference UNAVAILABLE_ATTRIBUTE;
- (BOOL)retainWeakReference UNAVAILABLE_ATTRIBUTE;

+ (BOOL)isSubclassOfClass:(Class)aClass;

+ (BOOL)resolveClassMethod:(SEL)sel __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);
+ (BOOL)resolveInstanceMethod:(SEL)sel __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_2_0);

+ (NSUInteger)hash;
+ (Class)superclass;
+ (Class)class code_SWIFT_UNAVAILABLE("use 'aClass.self' instead");
+ (NSString *)description;
+ (NSString *)debugDescription;

@end

#endif

#endif
