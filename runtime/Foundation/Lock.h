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


#ifndef __NSLock_h_GNUSTEP_BASE_INCLUDE
#define __NSLock_h_GNUSTEP_BASE_INCLUDE
#import  <Base/VersionMacros.h>
#import  <Base/Config.h>

#import  <Object.h>

#if  defined(__cplusplus)
extern "C" {
#endif

/**
 * Protocol defining lock and unlock operations.
 */
@protocol NSLocking

/**
 *  Block until acquiring lock.
 */
- (void) lock;

/**
 *  Relinquish lock.
 */
- (void) unlock;

@end

/**
 * <p>Simplest lock for protecting critical sections of code.
 * </p>
 * <p>An <code>NSLock</code> is used in multi-threaded applications to protect
 * critical pieces of code. While one thread holds a lock within a piece of
 * code, another thread cannot execute that code until the first thread has
 * given up its hold on the lock. The limitation of <code>NSLock</code> is
 * that you can only lock an <code>NSLock</code> once and it must be unlocked
 * before it can be acquired again.<br /> Other lock classes, notably
 * [NSRecursiveLock], have different restrictions.
 * </p>
 */
GS_EXPORT_CLASS
@interface NSLock : NSObject <NSLocking>
{
#if	GS_EXPOSE(NSLock)
@protected
  gs_mutex_public_t	_mutex;
  NSString	*_name;
#endif
}

#if !NO_GNUSTEP
/** Report whether this lock is held by the current thread.<br />
 * Raises an exception if this is not supported by the system lock mechanism.
 */
- (BOOL) isLockedByCurrentThread;
#endif

/**
 *  Try to acquire lock and return before limit, YES if succeeded, NO if not.
 */
- (BOOL) lockBeforeDate: (NSDate*)limit;

/**
 *  Block until acquiring lock.
 */
- (void) lock;

/**
 *  Try to acquire lock and return immediately, YES if succeeded, NO if not.
 */
- (BOOL) tryLock;

/**
 *  Relinquish lock.
 */
- (void) unlock;


/** Return the name of the receiver or nil of none has been set.
 */
- (NSString*) name;

/** Sets the name of the receiver (for use in debugging).
 */
- (void) setName: (NSString*)name;
#endif

@end

/**
 * NSCondition provides an interface to POSIX condition variables.
 */
GS_EXPORT_CLASS
@interface NSCondition : NSObject <NSLocking>
{
#if	GS_EXPOSE(NSCondition)
@protected
  gs_cond_public_t	_condition;
  gs_mutex_public_t	_mutex;
  NSString	*_name;
#endif
}
/**
 * Blocks and atomically unlocks the receiver.
 * This method should only be called when the receiver is locked.
 * The caller will then block until the receiver is sent either a -signal
 * or -broadcast message from another thread.  At which
 * point, the calling thread will reacquire the lock.
 */
- (void) wait;

/**
 * Blocks the calling thread and acquires the lock, in the same way as -wait.
 * Returns YES if the condition is signaled, or NO if the timeout is reached.
 */
- (BOOL) waitUntilDate: (NSDate*)limit;

/**
 * Wakes wany one of the threads that are waiting on this condition.
 */
- (void) signal;

/**
 * Wakes all threads that are waiting on this condition.
 */
- (void) broadcast;

/**
 * Sets the name used for debugging messages.
 */
- (void) setName: (NSString*)newName;

/**
 * Returns the name used for debugging messages.
 */
- (NSString*) name;
@end

/**
 *  Lock that allows user to request it only when an internal integer
 *  condition is equal to a particular value.  The condition is set on
 *  initialization and whenever the lock is relinquished.
 */
GS_EXPORT_CLASS
@interface NSConditionLock : NSObject <NSLocking>
{
#if	GS_EXPOSE(NSConditionLock)
@protected
  NSCondition *_condition;
  int   _condition_value;
  NSString      *_name;
#endif
}

/**
 * Initialize lock with given condition.
 */
- (id) initWithCondition: (NSInteger)value;

/**
 * Return the current condition of the lock.
 */
- (NSInteger) condition;

#if !NO_GNUSTEP
/** Report whether this lock is held by the current thread.<br />
 * Raises an exception if this is not supported by the system lock mechanism.
 */
- (BOOL) isLockedByCurrentThread;
#endif

/*
 * Acquiring and releasing the lock.
 */

/**
 *  Acquire lock when it is available and the internal condition is equal to
 *  value.  Blocks until this occurs.
 */
- (void) lockWhenCondition: (NSInteger)value;

/**
 *  Relinquish the lock, setting internal condition to value.
 */
- (void) unlockWithCondition: (NSInteger)value;

/**
 *  Try to acquire lock regardless of condition and return immediately, YES if
 *  succeeded, NO if not.
 */
- (BOOL) tryLock;

/**
 *  Try to acquire lock if condition is equal to value and return immediately
 *  in any case, YES if succeeded, NO if not.
 */
- (BOOL) tryLockWhenCondition: (NSInteger)value;

/*
 * Acquiring the lock with a date condition.
 */

/**
 *  Try to acquire lock and return before limit, YES if succeeded, NO if not.
 */
- (BOOL) lockBeforeDate: (NSDate*)limit;

/**
 *  Try to acquire lock, when internal condition is equal to condition_to_meet,
 *  and return before limit, YES if succeeded, NO if not.
 */
- (BOOL) lockWhenCondition: (NSInteger)condition_to_meet
                beforeDate: (NSDate*)limitDate;

/**
 *  Block until acquiring lock.
 */
- (void) lock;

/**
 *  Relinquish lock.
 */
- (void) unlock;


/** Return the name of the receiver or nil of none has been set.
 */
- (NSString*) name;

/** Sets the name of the receiver (for use in debugging).
 */
- (void) setName: (NSString*)name;
#endif

@end


/**
 * Allows the lock to be recursively acquired by the same thread.
 *
 * If the same thread locks the mutex (n) times then that same 
 * thread must also unlock it (n) times before another thread 
 * can acquire the lock.
 */
GS_EXPORT_CLASS
@interface NSRecursiveLock : NSObject <NSLocking>
{
#if	GS_EXPOSE(NSRecursiveLock)
@protected
  gs_mutex_public_t	_mutex;
  NSString      *_name;
#endif
}

#if !NO_GNUSTEP
/** Report whether this lock is held by the current thread.<br />
 * Raises an exception if this is not supported by the system lock mechanism.
 */
- (BOOL) isLockedByCurrentThread;
#endif

/**
 *  Try to acquire lock regardless of condition and return immediately, YES if
 *  succeeded, NO if not.
 */
- (BOOL) tryLock;

/**
 *  Try to acquire lock and return before limit, YES if succeeded, NO if not.
 */
- (BOOL) lockBeforeDate: (NSDate*)limit;

/**
 *  Block until acquiring lock.
 */
- (void) lock;

/**
 *  Relinquish lock.
 */
- (void) unlock;


/** Return the name of the receiver or nil of none has been set.
 */
- (NSString*) name;

/** Sets the name of the receiver (for use in debugging).
 */
- (void) setName: (NSString*)name;
#endif

@end

#if !NO_GNUSTEP
typedef void NSLock_error_handler(id obj, SEL _cmd, BOOL stop, NSString *msg);
/** Code may replace this function pointer in order to intercept the normal
 * logging of a deadlock.
 */
GS_EXPORT NSLock_error_handler  *_NSLock_error_handler;

/** Controls tracing of locks for deadlocking.
 */
@interface      NSObject (GSTraceLocks)
/** Sets whether newly created lock objects (NSCondition, NSConditionLock,
 * NSLock, NSRecursiveLock but NOT NSDistributedLock) should be created so
 * that their use by threads is traced and deadlocks can be detected.<br />
 * Returns the old value of the setting.
 */
+ (BOOL) shouldCreateTraceableLocks: (BOOL)shouldTrace;

/** Creates and returns a single autoreleased traced condition.
 */
+ (NSCondition*) tracedCondition;

/** Creates and returns a single autoreleased traced condition lock.
 */
+ (NSConditionLock*) tracedConditionLockWithCondition: (NSInteger)value;

/** Creates and returns a single autoreleased traced lock.
 */
+ (NSLock*) tracedLock;

/** Creates and returns a single autoreleased traced recursive lock.
 */
+ (NSRecursiveLock*) tracedRecursiveLock;
@end
#endif

#if  defined(__cplusplus)
}
#endif

#if     !NO_GNUSTEP && !defined(GNUSTEP_BASE_INTERNAL)
#import <Base/NSLock+GNUstepBase.h>
#endif

#endif /* __NSLock_h_GNUSTEP_BASE_INCLUDE */

