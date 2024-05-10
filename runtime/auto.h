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

#ifndef AUTO_H_
#define AUTO_H_

#pragma GCC system_header

#include <runtime/code.h>
#include <malloc/malloc.h>
#include <stdint.h>
#include <stddef.h>
#include <string.h>
#include <Availability.h>
#include <TargetConditionals.h>

#if !TARGET_OS_WIN32
#include <sys/types.h>
#include <libkern/OSAtomic.h>
#else
#   define WINVER 0x0501		// target Windows XP and later
#   define _WIN32_WINNT 0x0501	// target Windows XP and later
#   define WIN32_LEAN_AND_MEAN
// workaround: windef.h typedefs BOOL as int
#   define BOOL WINBOOL
#   include <windows.h>
#   undef BOOL
#endif


/* code_collect() options */
enum {
    // choose one
    code_RATIO_COLLECTION        = (0 << 0),  // run "ratio" generational collections, then a full
    code_GENERATIONAL_COLLECTION = (1 << 0),  // run fast incremental collection
    code_FULL_COLLECTION         = (2 << 0),  // run full collection.
    code_EXHAUSTIVE_COLLECTION   = (3 << 0),  // run full collections until memory available stops improving
    
    code_COLLECT_IF_NEEDED       = (1 << 3), // run collection only if needed (allocation threshold exceeded)
    code_WAIT_UNTIL_DONE         = (1 << 4), // wait (when possible) for collection to end before returning (when collector is running on dedicated thread)
};

/* code_clear_stack() options */
enum {
    code_CLEAR_RESIDENT_STACK = (1 << 0)
};

#ifndef CODE_NO_GC


/* GC declarations */

/* Collection utilities */

CODE_EXPORT void code_collect(unsigned long options)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);
CODE_EXPORT BOOL code_collectingEnabled(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
CODE_EXPORT malloc_zone_t *code_collectableZone(void) 
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_NA);

/* GC configuration */

/* Tells collector to wait until specified bytes have been allocated before trying to collect again. */
CODE_EXPORT void code_setCollectionThreshold(size_t threshold)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

/* Tells collector to run a full collection for every ratio generational collections. */
CODE_EXPORT void code_setCollectionRatio(size_t ratio)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);

// 
// GC-safe compare-and-swap
//

/* Atomic update, with write barrier. */
CODE_EXPORT BOOL code_atomicCompareAndSwapPtr(id predicate, id replacement, volatile id *objectLocation) 
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA) code_ARC_UNAVAILABLE;
/* "Barrier" version also includes memory barrier. */
CODE_EXPORT BOOL code_atomicCompareAndSwapPtrBarrier(id predicate, id replacement, volatile id *objectLocation) 
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA) code_ARC_UNAVAILABLE;

// atomic update of a global variable
CODE_EXPORT BOOL code_atomicCompareAndSwapGlobal(id predicate, id replacement, volatile id *objectLocation)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA) code_ARC_UNAVAILABLE;
CODE_EXPORT BOOL code_atomicCompareAndSwapGlobalBarrier(id predicate, id replacement, volatile id *objectLocation)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA) code_ARC_UNAVAILABLE;
// atomic update of an instance variable
CODE_EXPORT BOOL code_atomicCompareAndSwapInstanceVariable(id predicate, id replacement, volatile id *objectLocation)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA) code_ARC_UNAVAILABLE;
CODE_EXPORT BOOL code_atomicCompareAndSwapInstanceVariableBarrier(id predicate, id replacement, volatile id *objectLocation)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA) code_ARC_UNAVAILABLE;


// 
// Read and write barriers
// 

CODE_EXPORT id code_assign_strongCast(id val, id *dest)
    __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);
CODE_EXPORT id code_assign_global(id val, id *dest)
    __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);
CODE_EXPORT id code_assign_threadlocal(id val, id *dest)
    __OSX_AVAILABLE_STARTING(__MAC_10_7, __IPHONE_NA);
CODE_EXPORT id code_assign_ivar(id value, id dest, ptrdiff_t offset)
    __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);
CODE_EXPORT void *code_memmove_collectable(void *dst, const void *src, size_t size)
    __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

CODE_EXPORT id code_read_weak(id *location)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);
CODE_EXPORT id code_assign_weak(id value, id *location)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);


//
// Thread management
// 

/* Register the calling thread with the garbage collector. */
CODE_EXPORT void code_registerThreadWithCollector(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);

/* Unregisters the calling thread with the garbage collector. 
   Unregistration also happens automatically at thread exit. */
CODE_EXPORT void code_unregisterThreadWithCollector(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);

/* To be called from code which must only execute on a registered thread. */
/* If the calling thread is unregistered then an error message is emitted and the thread is implicitly registered. */
CODE_EXPORT void code_assertRegisteredThreadWithCollector(void)
    __OSX_AVAILABLE_STARTING(__MAC_10_6, __IPHONE_NA);

/* Erases any stale references in unused parts of the stack. */
CODE_EXPORT void code_clear_stack(unsigned long options)
    __OSX_AVAILABLE_STARTING(__MAC_10_5, __IPHONE_NA);


//
// Finalization
// 

/* Returns true if object has been scheduled for finalization.  Can be used to avoid operations that may lead to resurrection, which are fatal. */
CODE_EXPORT BOOL code_is_finalized(void *ptr)
    __OSX_AVAILABLE_STARTING(__MAC_10_4, __IPHONE_NA);

// Deprcated. Tells runtime to issue finalize calls on the main thread only.
CODE_EXPORT void code_finalizeOnMainThread(Class cls)
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5,__MAC_10_5, __IPHONE_NA,__IPHONE_NA);


//
// Deprecated names. 
//

/* Deprecated. Use code_collectingEnabled() instead. */
CODE_EXPORT BOOL code_collecting_enabled(void)
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4,__MAC_10_5, __IPHONE_NA,__IPHONE_NA);
/* Deprecated. Use code_setCollectionThreshold() instead. */
CODE_EXPORT void code_set_collection_threshold(size_t threshold)
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4,__MAC_10_5, __IPHONE_NA,__IPHONE_NA);
/* Deprecated. Use code_setCollectionRatio() instead. */
CODE_EXPORT void code_set_collection_ratio(size_t ratio)
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4,__MAC_10_5, __IPHONE_NA,__IPHONE_NA);
/* Deprecated. Use code_startCollectorThread() instead. */
CODE_EXPORT void code_start_collector_thread(void)
    __OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4,__MAC_10_5, __IPHONE_NA,__IPHONE_NA);
/* Deprecated. No replacement. Formerly told the collector to run using a dedicated background thread. */
CODE_EXPORT void code_startCollectorThread(void)
__OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_5,__MAC_10_7, __IPHONE_NA,__IPHONE_NA);


/* Deprecated. Use class_createInstance() instead. */
CODE_EXPORT id code_allocate_object(Class cls, int extra)
__OSX_AVAILABLE_BUT_DEPRECATED(__MAC_10_4,__MAC_10_4, __IPHONE_NA,__IPHONE_NA);


/* !defined(code_NO_GC) */
#else
/* defined(code_NO_GC) */


/* Non-GC declarations */

static code_INLINE void code_collect(unsigned long options __unused) { }
static code_INLINE BOOL code_collectingEnabled(void) { return NO; }
#if TARGET_OS_MAC  &&  !TARGET_OS_EMBEDDED  &&  !TARGET_IPHONE_SIMULATOR
static code_INLINE malloc_zone_t *code_collectableZone(void) { return nil; }
#endif
static code_INLINE void code_setCollectionThreshold(size_t threshold __unused) { }
static code_INLINE void code_setCollectionRatio(size_t ratio __unused) { }
static code_INLINE void code_startCollectorThread(void) { }

#if __has_feature(code_arc)

/* Covers for GC memory operations are unavailable in ARC */

#else

#if TARGET_OS_WIN32
static code_INLINE BOOL code_atomicCompareAndSwapPtr(id predicate, id replacement, volatile id *objectLocation) 
    { void *original = InterlockedCompareExchangePointer((void * volatile *)objectLocation, (void *)replacement, (void *)predicate); return (original == predicate); }

static code_INLINE BOOL code_atomicCompareAndSwapPtrBarrier(id predicate, id replacement, volatile id *objectLocation) 
    { void *original = InterlockedCompareExchangePointer((void * volatile *)objectLocation, (void *)replacement, (void *)predicate); return (original == predicate); }
#else
static code_INLINE BOOL code_atomicCompareAndSwapPtr(id predicate, id replacement, volatile id *objectLocation) 
    { return OSAtomicCompareAndSwapPtr((void *)predicate, (void *)replacement, (void * volatile *)objectLocation); }

static code_INLINE BOOL code_atomicCompareAndSwapPtrBarrier(id predicate, id replacement, volatile id *objectLocation) 
    { return OSAtomicCompareAndSwapPtrBarrier((void *)predicate, (void *)replacement, (void * volatile *)objectLocation); }
#endif

static code_INLINE BOOL code_atomicCompareAndSwapGlobal(id predicate, id replacement, volatile id *objectLocation) 
    { return code_atomicCompareAndSwapPtr(predicate, replacement, objectLocation); }

static code_INLINE BOOL code_atomicCompareAndSwapGlobalBarrier(id predicate, id replacement, volatile id *objectLocation) 
    { return code_atomicCompareAndSwapPtrBarrier(predicate, replacement, objectLocation); }

static code_INLINE BOOL code_atomicCompareAndSwapInstanceVariable(id predicate, id replacement, volatile id *objectLocation) 
    { return code_atomicCompareAndSwapPtr(predicate, replacement, objectLocation); }

static code_INLINE BOOL code_atomicCompareAndSwapInstanceVariableBarrier(id predicate, id replacement, volatile id *objectLocation) 
    { return code_atomicCompareAndSwapPtrBarrier(predicate, replacement, objectLocation); }


static code_INLINE id code_assign_strongCast(id val, id *dest) 
    { return (*dest = val); }

static code_INLINE id code_assign_global(id val, id *dest) 
    { return (*dest = val); }

static code_INLINE id code_assign_threadlocal(id val, id *dest) 
    { return (*dest = val); }

static code_INLINE id code_assign_ivar(id val, id dest, ptrdiff_t offset) 
    { return (*(id*)((char *)dest+offset) = val); }

static code_INLINE id code_read_weak(id *location) 
    { return *location; }

static code_INLINE id code_assign_weak(id value, id *location) 
    { return (*location = value); }

/* MRC */
#endif

static code_INLINE void *code_memmove_collectable(void *dst, const void *src, size_t size) 
    { return memmove(dst, src, size); }

static code_INLINE void code_finalizeOnMainThread(Class cls __unused) { }
static code_INLINE BOOL code_is_finalized(void *ptr __unused) { return NO; }
static code_INLINE void code_clear_stack(unsigned long options __unused) { }

static code_INLINE BOOL code_collecting_enabled(void) { return NO; }
static code_INLINE void code_set_collection_threshold(size_t threshold __unused) { } 
static code_INLINE void code_set_collection_ratio(size_t ratio __unused) { } 
static code_INLINE void code_start_collector_thread(void) { }

#if __has_feature(code_arc)
extern id code_allocate_object(Class cls, int extra) UNAVAILABLE_ATTRIBUTE;
#else
CODE_EXPORT id class_createInstance(Class cls, size_t extraBytes)
    __OSX_AVAILABLE_STARTING(__MAC_10_0, __IPHONE_2_0);
static code_INLINE id code_allocate_object(Class cls, int extra) 
    { return class_createInstance(cls, extra); }
#endif

static code_INLINE void code_registerThreadWithCollector() { }
static code_INLINE void code_unregisterThreadWithCollector() { }
static code_INLINE void code_assertRegisteredThreadWithCollector() { }

/* defined(code_NO_GC) */
#endif


#if TARGET_OS_EMBEDDED
enum {
    code_GENERATIONAL = (1 << 0)
};
static code_INLINE void code_collect_if_needed(unsigned long options) __attribute__((deprecated));
static code_INLINE void code_collect_if_needed(unsigned long options __unused) { }
#endif

#endif
