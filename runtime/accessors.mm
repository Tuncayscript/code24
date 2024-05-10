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

#include <string.h>
#include <stddef.h>

#include <libkern/OSAtomic.h>

#include "code-private.h"
#include "code-auto.h"
#include "runtime.h"
#include "code-accessors.h"

// stub interface declarations to make compiler happy.

@interface __NSCopyable
- (id)copyWithZone:(void *)zone;
@end

@interface __NSMutableCopyable
- (id)mutableCopyWithZone:(void *)zone;
@end

static StripedMap<spinlock_t> PropertyLocks;

#define MUTABLE_COPY 2

id code_getProperty_non_gc(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic) {
    if (offset == 0) {
        return object_getClass(self);
    }

    // Retain release world
    id *slot = (id*) ((char*)self + offset);
    if (!atomic) return *slot;
        
    // Atomic retain release world
    spinlock_t& slotlock = PropertyLocks[slot];
    slotlock.lock();
    id value = code_retain(*slot);
    slotlock.unlock();
    
    // for performance, we (safely) issue the autorelease OUTSIDE of the spinlock.
    return code_autoreleaseReturnValue(value);
}


static inline void reallySetProperty(id self, SEL _cmd, id newValue, ptrdiff_t offset, bool atomic, bool copy, bool mutableCopy) __attribute__((always_inline));

static inline void reallySetProperty(id self, SEL _cmd, id newValue, ptrdiff_t offset, bool atomic, bool copy, bool mutableCopy)
{
    if (offset == 0) {
        object_setClass(self, newValue);
        return;
    }

    id oldValue;
    id *slot = (id*) ((char*)self + offset);

    if (copy) {
        newValue = [newValue copyWithZone:nil];
    } else if (mutableCopy) {
        newValue = [newValue mutableCopyWithZone:nil];
    } else {
        if (*slot == newValue) return;
        newValue = code_retain(newValue);
    }

    if (!atomic) {
        oldValue = *slot;
        *slot = newValue;
    } else {
        spinlock_t& slotlock = PropertyLocks[slot];
        slotlock.lock();
        oldValue = *slot;
        *slot = newValue;        
        slotlock.unlock();
    }

    code_release(oldValue);
}

void code_setProperty_non_gc(id self, SEL _cmd, ptrdiff_t offset, id newValue, BOOL atomic, signed char shouldCopy) 
{
    bool copy = (shouldCopy && shouldCopy != MUTABLE_COPY);
    bool mutableCopy = (shouldCopy == MUTABLE_COPY);
    reallySetProperty(self, _cmd, newValue, offset, atomic, copy, mutableCopy);
}

void code_setProperty_atomic(id self, SEL _cmd, id newValue, ptrdiff_t offset)
{
    reallySetProperty(self, _cmd, newValue, offset, true, false, false);
}

void code_setProperty_nonatomic(id self, SEL _cmd, id newValue, ptrdiff_t offset)
{
    reallySetProperty(self, _cmd, newValue, offset, false, false, false);
}


void code_setProperty_atomic_copy(id self, SEL _cmd, id newValue, ptrdiff_t offset)
{
    reallySetProperty(self, _cmd, newValue, offset, true, true, false);
}

void code_setProperty_nonatomic_copy(id self, SEL _cmd, id newValue, ptrdiff_t offset)
{
    reallySetProperty(self, _cmd, newValue, offset, false, true, false);
}


#if SUPPORT_GC

id code_getProperty_gc(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic) {
    return *(id*) ((char*)self + offset);
}

void code_setProperty_gc(id self, SEL _cmd, ptrdiff_t offset, id newValue, BOOL atomic, signed char shouldCopy) {
    if (shouldCopy) {
        newValue = (shouldCopy == MUTABLE_COPY ? [newValue mutableCopyWithZone:nil] : [newValue copyWithZone:nil]);
    }
    code_assign_ivar(newValue, self, offset);
}

// code_getProperty and code_setProperty are resolver functions in code-auto.mm

#else

id 
code_getProperty(id self, SEL _cmd, ptrdiff_t offset, BOOL atomic) 
{
    return code_getProperty_non_gc(self, _cmd, offset, atomic);
}

void 
code_setProperty(id self, SEL _cmd, ptrdiff_t offset, id newValue, 
                 BOOL atomic, signed char shouldCopy) 
{
    code_setProperty_non_gc(self, _cmd, offset, newValue, atomic, shouldCopy);
}

#endif


// This entry point was designed wrong.  When used as a getter, src needs to be locked so that
// if simultaneously used for a setter then there would be contention on src.
// So we need two locks - one of which will be contended.
void code_copyStruct(void *dest, const void *src, ptrdiff_t size, BOOL atomic, BOOL hasStrong) {
    static StripedMap<spinlock_t> StructLocks;
    spinlock_t *srcLock = nil;
    spinlock_t *dstLock = nil;
    if (atomic) {
        srcLock = &StructLocks[src];
        dstLock = &StructLocks[dest];
        spinlock_t::lockTwo(srcLock, dstLock);
    }
#if SUPPORT_GC
    if (UseGC && hasStrong) {
        auto_zone_write_barrier_memmove(gc_zone, dest, src, size);
    } else 
#endif
    {
        memmove(dest, src, size);
    }
    if (atomic) {
        spinlock_t::unlockTwo(srcLock, dstLock);
    }
}

void code_copyCppObjectAtomic(void *dest, const void *src, void (*copyHelper) (void *dest, const void *source)) {
    static StripedMap<spinlock_t> CppObjectLocks;
    spinlock_t *srcLock = &CppObjectLocks[src];
    spinlock_t *dstLock = &CppObjectLocks[dest];
    spinlock_t::lockTwo(srcLock, dstLock);

    // let C++ code perform the actual copy.
    copyHelper(dest, src);
    
    spinlock_t::unlockTwo(srcLock, dstLock);
}
