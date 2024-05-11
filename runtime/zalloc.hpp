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
// Filename: zalloc.hpp
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Wednesday, May 11, 2024
// Purpose: Zone Allocator for Language
// Technology: C++20 - ISO/IEC 14882:2020(E)
// Description: Provides packed allocation for data structures the runtime almost never frees.

#ifndef ZALLOC_HPP
#define ZALLOC_HPP

#include <cstdint>
#include <atomic>
#include <cstdlib>

namespace Code {

// malloc always aligns to 16 bytes
#define MALLOC_ALIGNMENT 16

class AtomicQueue {
#if __LP64__
    using pair_t = __int128_t;
#else
    using pair_t = uint64_t;
#endif
    static constexpr auto relaxed = std::memory_order_relaxed;
    static constexpr auto release = std::memory_order_release;

    struct Entry {
        struct Entry *next;
    };

    union {
        struct {
            Entry        *head;
            unsigned long gen;
        };
        std::atomic<pair_t> atomic_pair;
        pair_t pair;
    };

public:
    AtomicQueue() : pair(0) {}

    void *pop();
    void push_list(void *_head, void *_tail);
    inline void push(void *head)
    {
        push_list(head, head);
    }
};

template<class T, bool useMalloc>
class Zone {
};

template<class T>
class Zone<T, false> {
    struct Element {
        Element *next;
        char buf[sizeof(T) - sizeof(void *)];
    } __attribute__((packed));

    static AtomicQueue _freelist;
    static T *alloc_slow();

public:
    static T *alloc();
    static void free(T *);
};

template<class T>
class Zone<T, true> {
public:
    static inline T *alloc() {
        return reinterpret_cast<T *>(::calloc(sizeof(T), 1));
    }
    static inline void free(T *ptr) {
        ::free(ptr);
    }
};

/*
 * This allocator returns always zeroed memory,
 * and the template needs to be instantiated in zalloc.mm
 */

template<class T>
T *zalloc()
{
    return Zone<T, sizeof(T) % MALLOC_ALIGNMENT == 0>::alloc();
}

template<class T>
void zfree(T *e)
{
    Zone<T, sizeof(T) % MALLOC_ALIGNMENT == 0>::free(e);
}

};

#endif
