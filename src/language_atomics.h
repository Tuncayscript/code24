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
 */

#ifndef LANGUAGE_ATOMICS_H
#define LANGUAGE_ATOMICS_H

#if defined(__i386__) && defined(__GNUC__) && !defined(__SSE2__)
#  error Julia can only be built for architectures above Pentium 4. Pass -march=pentium4, or set MARCH=pentium4 and ensure that -march is not passed separately with an older architecture.
#endif

// Low-level atomic operations
#ifdef __cplusplus
#include <atomic>
using std::memory_order_relaxed;
using std::memory_order_consume;
using std::memory_order_acquire;
using std::memory_order_release;
using std::memory_order_acq_rel;
using std::memory_order_seq_cst;
using std::atomic_thread_fence;
using std::atomic_signal_fence;
using std::atomic_load;
using std::atomic_load_explicit;
using std::atomic_store;
using std::atomic_store_explicit;
using std::atomic_fetch_add;
using std::atomic_fetch_add_explicit;
using std::atomic_fetch_and;
using std::atomic_fetch_and_explicit;
using std::atomic_fetch_or;
using std::atomic_fetch_or_explicit;
using std::atomic_compare_exchange_strong;
using std::atomic_compare_exchange_strong_explicit;
using std::atomic_exchange;
using std::atomic_exchange_explicit;
extern "C" {
#define _Atomic(T) std::atomic<T>
#else
#include <stdatomic.h>
#endif
#include <signal.h> // for sig_atomic_t

#if defined(_CPU_X86_64_) || defined(_CPU_X86_)
#  include <immintrin.h>
#endif

enum language_memory_order {
    language_memory_order_unspecified = -2,
    language_memory_order_invalid = -1,
    language_memory_order_notatomic = 0,
    language_memory_order_unordered,
    language_memory_order_monotonic,
    language_memory_order_consume,
    language_memory_order_acquire,
    language_memory_order_release,
    language_memory_order_acq_rel,
    language_memory_order_seq_cst
};

/**
 * Cache line size
*/
#if (defined(_CPU_AARCH64_) && defined(_OS_DARWIN_)) || defined(_CPU_PPC64_)  // Apple silicon and PPC7+ have 128 byte cache lines
#define LANGUAGE_CACHE_BYTE_ALIGNMENT 128
#else
#define LANGUAGE_CACHE_BYTE_ALIGNMENT 64
#endif

/**
 * Thread synchronization primitives:
 *
 * These roughly follows the c11/c++11 memory model and the act as memory
 * barriers at both the compiler level and the hardware level.
 * The only exception is the GC safepoint and GC state transitions for which
 * we use only a compiler (signal) barrier and use the signal handler to do the
 * synchronization in order to lower the mutator overhead as much as possible.
 *
 * We use the compiler intrinsics to implement a similar API to the c11/c++11
 * one instead of using it directly because, we need interoperability between
 * code written in different languages. The current c++ standard (c++14) does
 * not allow using c11 atomic functions or types and there's currently no
 * guarantee that the two types are compatible (although most of them probably
 * are). We also need to access these atomic variables from the LLVM JIT code
 * which is very hard unless the layout of the object is fully specified.
 */

/**
 * On modern Intel and AMD platforms `lock orq` on the SP is faster than
 * `mfence`. GCC 11 did switch to this representation. See #48123
 */
#if defined(_CPU_X86_64_) && \
    ((defined(__GNUC__) && __GNUC__ < 11) || \
     (defined(__clang__)))
    #define language_fence() __asm__ volatile("lock orq $0 , (%rsp)")
#else
    #define language_fence() atomic_thread_fence(memory_order_seq_cst)
#endif
#define language_fence_release() atomic_thread_fence(memory_order_release)
#define language_signal_fence() atomic_signal_fence(memory_order_seq_cst)

#ifdef __cplusplus
}
// implicit conversion wasn't correctly specified 2017, so many compilers get
// this wrong thus we include the correct definitions here (with implicit
// conversion), instead of using the macro version
template<class T>
T language_atomic_load(std::atomic<T> *ptr)
{
     return std::atomic_load<T>(ptr);
}
template<class T>
T language_atomic_load_explicit(std::atomic<T> *ptr, std::memory_order order)
{
     return std::atomic_load_explicit<T>(ptr, order);
}
#define language_atomic_load_relaxed(ptr) language_atomic_load_explicit(ptr, memory_order_relaxed)
#define language_atomic_load_acquire(ptr) language_atomic_load_explicit(ptr, memory_order_acquire)
template<class T, class S>
void language_atomic_store(std::atomic<T> *ptr, S desired)
{
     std::atomic_store<T>(ptr, desired);
}
template<class T, class S>
void language_atomic_store_explicit(std::atomic<T> *ptr, S desired, std::memory_order order)
{
     std::atomic_store_explicit<T>(ptr, desired, order);
}
#define language_atomic_store_relaxed(ptr, val) language_atomic_store_explicit(ptr, val, memory_order_relaxed)
#define language_atomic_store_release(ptr, val) language_atomic_store_explicit(ptr, val, memory_order_release)
template<class T, class S>
T language_atomic_fetch_add(std::atomic<T> *ptr, S val)
{
     return std::atomic_fetch_add<T>(ptr, val);
}
template<class T, class S>
T language_atomic_fetch_add_explicit(std::atomic<T> *ptr, S val, std::memory_order order)
{
     return std::atomic_fetch_add_explicit<T>(ptr, val, order);
}
#define language_atomic_fetch_add_relaxed(ptr, val) language_atomic_fetch_add_explicit(ptr, val, memory_order_relaxed)
template<class T, class S>
T language_atomic_fetch_and(std::atomic<T> *ptr, S val)
{
     return std::atomic_fetch_and<T>(ptr, val);
}
template<class T, class S>
T language_atomic_fetch_and_explicit(std::atomic<T> *ptr, S val, std::memory_order order)
{
     return std::atomic_fetch_and_explicit<T>(ptr, val, order);
}
#define language_atomic_fetch_and_relaxed(ptr, val) language_atomic_fetch_and_explicit(ptr, val, memory_order_relaxed)
template<class T, class S>
T language_atomic_fetch_or(std::atomic<T> *ptr, S val)
{
     return std::atomic_fetch_or<T>(ptr, val);
}
template<class T, class S>
T language_atomic_fetch_or_explicit(std::atomic<T> *ptr, S val, std::memory_order order)
{
     return std::atomic_fetch_or_explicit<T>(ptr, val, order);
}
#define language_atomic_fetch_or_relaxed(ptr, val) language_atomic_fetch_or_explicit(ptr, val, memory_order_relaxed)
template<class T, class S>
bool language_atomic_cmpswap(std::atomic<T> *ptr, T *expected, S val)
{
     return std::atomic_compare_exchange_strong<T>(ptr, expected, val);
}
template<class T, class S>
bool language_atomic_cmpswap_explicit(std::atomic<T> *ptr, T *expected, S val, std::memory_order order)
{
     return std::atomic_compare_exchange_strong_explicit<T>(ptr, expected, val, order, order);
}
template<class T, class S>
bool language_atomic_cmpswap_acqrel(std::atomic<T> *ptr, T *expected, S val)
{
     return std::atomic_compare_exchange_strong_explicit<T>(ptr, expected, val, memory_order_acq_rel, memory_order_acquire);
}
template<class T, class S>
bool language_atomic_cmpswap_release(std::atomic<T> *ptr, T *expected, S val)
{
     return std::atomic_compare_exchange_strong_explicit<T>(ptr, expected, val, memory_order_release, memory_order_relaxed);
}
#define language_atomic_cmpswap_relaxed(ptr, expected, val) language_atomic_cmpswap_explicit(ptr, expected, val, memory_order_relaxed)
template<class T, class S>
T language_atomic_exchange(std::atomic<T> *ptr, S desired)
{
     return std::atomic_exchange<T>(ptr, desired);
}
template<class T, class S>
T language_atomic_exchange_explicit(std::atomic<T> *ptr, S desired, std::memory_order order)
{
     return std::atomic_exchange_explicit<T>(ptr, desired, order);
}
#define language_atomic_exchange_release(ptr, val) language_atomic_exchange_explicit(ptr, val, memory_order_reease)
#define language_atomic_exchange_relaxed(ptr, val) language_atomic_exchange_explicit(ptr, val, memory_order_relaxed)
extern "C" {
#else

#  define language_atomic_fetch_add_relaxed(obj, arg)         \
    atomic_fetch_add_explicit(obj, arg, memory_order_relaxed)
#  define language_atomic_fetch_add(obj, arg)                 \
    atomic_fetch_add(obj, arg)
#  define language_atomic_fetch_and_relaxed(obj, arg)         \
    atomic_fetch_and_explicit(obj, arg, memory_order_relaxed)
#  define language_atomic_fetch_and(obj, arg)                 \
    atomic_fetch_and(obj, arg)
#  define language_atomic_fetch_or_relaxed(obj, arg)          \
    atomic_fetch_or_explicit(obj, arg, __ATOMIC_RELAXED)
#  define language_atomic_fetch_or(obj, arg)                  \
    atomic_fetch_or(obj, arg)
#  define language_atomic_cmpswap(obj, expected, desired)     \
    atomic_compare_exchange_strong(obj, expected, desired)
#  define language_atomic_cmpswap_relaxed(obj, expected, desired) \
    atomic_compare_exchange_strong_explicit(obj, expected, desired, memory_order_relaxed, memory_order_relaxed)
#  define language_atomic_cmpswap_release(obj, expected, desired) \
    atomic_compare_exchange_strong_explicit(obj, expected, desired, memory_order_release, memory_order_relaxed)
#  define language_atomic_cmpswap_acqrel(obj, expected, desired) \
    atomic_compare_exchange_strong_explicit(obj, expected, desired, memory_order_acq_rel, memory_order_acquire)
// TODO: Maybe add language_atomic_cmpswap_weak for spin lock
#  define language_atomic_exchange(obj, desired)       \
    atomic_exchange(obj, desired)
#  define language_atomic_exchange_release(obj, desired)      \
    atomic_exchange_explicit(obj, desired, memory_order_release)
#  define language_atomic_exchange_relaxed(obj, desired)      \
    atomic_exchange_explicit(obj, desired, memory_order_relaxed)
#  define language_atomic_store(obj, val)                     \
    atomic_store(obj, val)
#  define language_atomic_store_relaxed(obj, val)             \
    atomic_store_explicit(obj, val, memory_order_relaxed)

#  if defined(__clang__) || !(defined(_CPU_X86_) || defined(_CPU_X86_64_))
// Clang doesn't have this bug...
#    define language_atomic_store_release(obj, val)           \
    atomic_store_explicit(obj, val, memory_order_release)
#  else
// Workaround a GCC bug when using store with release order by using the
// stronger version instead.
// https://gcc.gnu.org/bugzilla/show_bug.cgi?id=67458
// fixed in https://gcc.gnu.org/git/?p=gcc.git&a=commit;h=d8c40eff56f69877b33c697ded756d50fde90c27
#    define language_atomic_store_release(obj, val) do {      \
        language_signal_fence();                              \
        atomic_store_explicit(obj, val, memory_order_release);   \
    } while (0)
#  endif
#  define language_atomic_load(obj)                   \
    atomic_load(obj)
#  define language_atomic_load_acquire(obj)           \
    atomic_load_explicit(obj, memory_order_acquire)
#ifdef _COMPILER_TSAN_ENABLED_
// For the sake of tsan, call these loads consume ordering since they will act
// as such on the processors we support while normally, the compiler would
// upgrade this to acquire ordering, which is strong (and slower) than we want.
#  define language_atomic_load_relaxed(obj)           \
    atomic_load_explicit(obj, memory_order_consume)
#else
#  define language_atomic_load_relaxed(obj)           \
    atomic_load_explicit(obj, memory_order_relaxed)
#endif
#endif

#ifdef __clang_gcanalyzer__
// for the purposes of the GC analyzer, we can turn these into non-atomic
// expressions with similar properties (for the sake of the analyzer, we don't
// care if it is an exact match for behavior)

#undef _Atomic
#define _Atomic(T) T

#undef language_atomic_exchange
#undef language_atomic_exchange_release
#undef language_atomic_exchange_relaxed
#define language_atomic_exchange(obj, desired) \
    (__extension__({ \
            __typeof__((obj)) p__analyzer__ = (obj); \
            __typeof__(*p__analyzer__) temp__analyzer__ = *p__analyzer__; \
            *p__analyzer__ = (desired); \
            temp__analyzer__; \
        }))
#define language_atomic_exchange_release language_atomic_exchange
#define language_atomic_exchange_relaxed language_atomic_exchange

#undef language_atomic_cmpswap
#undef language_atomic_cmpswap_acqrel
#undef language_atomic_cmpswap_release
#undef language_atomic_cmpswap_relaxed
#define language_atomic_cmpswap(obj, expected, desired) \
    (__extension__({ \
            __typeof__((obj)) p__analyzer__ = (obj); \
            __typeof__(*p__analyzer__) temp__analyzer__ = *p__analyzer__; \
            __typeof__((expected)) x__analyzer__ = (expected); \
            int eq__analyzer__ = memcmp(&temp__analyzer__, x__analyzer__, sizeof(temp__analyzer__)) == 0; \
            if (eq__analyzer__) \
                *p__analyzer__ = (desired); \
            else \
                *x__analyzer__ = temp__analyzer__; \
            eq__analyzer__; \
        }))
#define language_atomic_cmpswap_acqrel language_atomic_cmpswap
#define language_atomic_cmpswap_release language_atomic_cmpswap
#define language_atomic_cmpswap_relaxed language_atomic_cmpswap

#undef language_atomic_store
#undef language_atomic_store_release
#undef language_atomic_store_relaxed
#define language_atomic_store(obj, val)         (*(obj) = (val))
#define language_atomic_store_release language_atomic_store
#define language_atomic_store_relaxed language_atomic_store

#undef language_atomic_load
#undef language_atomic_load_acquire
#undef language_atomic_load_relaxed
#define language_atomic_load(obj)         (*(obj))
#define language_atomic_load_acquire language_atomic_load
#define language_atomic_load_relaxed language_atomic_load

#undef language_atomic_fetch_add
#undef language_atomic_fetch_and
#undef language_atomic_fetch_or
#undef language_atomic_fetch_add_relaxed
#undef language_atomic_fetch_and_relaxed
#undef language_atomic_fetch_or_relaxed
#define language_atomic_fetch_add(obj, val) \
    (__extension__({ \
            __typeof__((obj)) p__analyzer__ = (obj); \
            __typeof__(*p__analyzer__) temp__analyzer__ = *p__analyzer__; \
            *(p__analyzer__) = temp__analyzer__ + (val); \
            temp__analyzer__; \
        }))
#define language_atomic_fetch_and(obj, val) \
    (__extension__({ \
            __typeof__((obj)) p__analyzer__ = (obj); \
            __typeof__(*p__analyzer__) temp__analyzer__ = *p__analyzer__; \
            *(p__analyzer__) = temp__analyzer__ & (val); \
            temp__analyzer__; \
        }))
#define language_atomic_fetch_or(obj, val) \
    (__extension__({ \
            __typeof__((obj)) p__analyzer__ = (obj); \
            __typeof__(*p__analyzer__) temp__analyzer__ = *p__analyzer__; \
            *(p__analyzer__) = temp__analyzer__ | (val); \
            temp__analyzer__; \
        }))
#define language_atomic_fetch_add_relaxed language_atomic_fetch_add
#define language_atomic_fetch_and_relaxed language_atomic_fetch_and
#define language_atomic_fetch_or_relaxed language_atomic_fetch_or

#endif


#ifdef __cplusplus
}
#endif

#endif // LANGUAGE_ATOMICS_H
