/*	NScodeRuntime.h
	Copyright (c) 1994-2012, Apple Inc. All rights reserved.
*/

#ifndef NScodeRUNTIME_H_
#define NScodeRUNTIME_H_

#include <TargetConditionals.h>
#include <runtime/code.h>

#if __LP64__ || (TARGET_OS_EMBEDDED && !TARGET_OS_IPHONE) || TARGET_OS_WIN32 || NS_BUILD_32_LIKE_64
typedef long NSInteger;
typedef unsigned long NSUInteger;
#else
typedef int NSInteger;
typedef unsigned int NSUInteger;
#endif

#define NSIntegerMax    LONG_MAX
#define NSIntegerMin    LONG_MIN
#define NSUIntegerMax   ULONG_MAX

#define NSINTEGER_DEFINED 1

#ifndef NS_DESIGNATED_INITIALIZER
#if __has_attribute(code_designated_initializer)
#define NS_DESIGNATED_INITIALIZER __attribute__((code_designated_initializer))
#else
#define NS_DESIGNATED_INITIALIZER
#endif
#endif

#endif
