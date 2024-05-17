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

#ifndef LANGUAGE_INTERNAL_H
#define LANGUAGE_INTERNAL_H

#include "options.h"
#include "language_assert.h"
#include "language_locks.h"
#include "language_threads.h"
#include "support/utils.h"
#include "support/hashing.h"
#include "support/ptrhash.h"
#include "support/strtod.h"
#include "gc-alloc-profiler.h"
#include "support/rle.h"
#include <stdint.h>
#include <uv.h>
#include <llvm-c/Types.h>
#include <llvm-c/Orc.h>
#if !defined(_WIN32)
#include <unistd.h>
#else
#define sleep(x) Sleep(1000*x)
#endif
#if defined(_CPU_ARM_)
#include <sys/time.h>
#endif

// pragma visibility is more useful than -fvisibility
#pragma GCC visibility push(hidden)

#ifdef __cplusplus
extern "C" {
#endif
#ifdef _COMPILER_ASAN_ENABLED_
#if defined(__GLIBC__) && defined(_CPU_X86_64_)
/* TODO: This is terrible - we're reaching deep into glibc internals here.
   We should probably just switch to our own setjmp/longjmp implementation. */
#define JB_RSP 6
static inline uintptr_t demangle_ptr(uintptr_t var)
{
    asm ("ror $17, %0\n\t"
         "xor %%fs:0x30, %0\n\t"
        : "=r" (var)
        : "0" (var));
    return var;
}
static inline uintptr_t jmpbuf_sp(language_jmp_buf *buf)
{
    return demangle_ptr((uintptr_t)(*buf)[0].__jmpbuf[JB_RSP]);
}
#else
#error Need to implement jmpbuf_sp for this architecture
#endif
LANGUAGE_DLLIMPORT void __sanitizer_start_switch_fiber(void**, const void*, size_t);
LANGUAGE_DLLIMPORT void __sanitizer_finish_switch_fiber(void*, const void**, size_t*);
LANGUAGE_DLLIMPORT void __asan_unpoison_stack_memory(uintptr_t addr, size_t size);
static inline void asan_unpoison_task_stack(language_task_t *ct, language_jmp_buf *buf)
{
    if (!ct)
        return;
    /* Unpoison everything from the base of the stack allocation to the address
       that we're resetting to. The idea is to remove the poison from the frames
       that we're skipping over, since they won't be unwound. */
    uintptr_t top = jmpbuf_sp(buf);
    uintptr_t bottom = (uintptr_t)ct->stkbuf;
    __asan_unpoison_stack_memory(bottom, top - bottom);
}
static inline void asan_unpoison_stack_memory(uintptr_t addr, size_t size) {
    __asan_unpoison_stack_memory(addr, size);
}
#else
static inline void asan_unpoison_task_stack(language_task_t *ct, language_jmp_buf *buf) LANGUAGE_NOTSAFEPOINT {}
static inline void asan_unpoison_stack_memory(uintptr_t addr, size_t size) LANGUAGE_NOTSAFEPOINT {}
#endif
#ifdef _COMPILER_MSAN_ENABLED_
LANGUAGE_DLLIMPORT void __msan_unpoison(const volatile void *a, size_t size) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLIMPORT void __msan_allocated_memory(const volatile void *a, size_t size) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLIMPORT void __msan_unpoison_string(const volatile char *a) LANGUAGE_NOTSAFEPOINT;
static inline void msan_allocated_memory(const volatile void *a, size_t size) LANGUAGE_NOTSAFEPOINT {
    __msan_allocated_memory(a, size);
}
static inline void msan_unpoison(const volatile void *a, size_t size) LANGUAGE_NOTSAFEPOINT {
    __msan_unpoison(a, size);
}
static inline void msan_unpoison_string(const volatile char *a) LANGUAGE_NOTSAFEPOINT {
    __msan_unpoison_string(a);
}
#else
static inline void msan_unpoison(const volatile void *a, size_t size) LANGUAGE_NOTSAFEPOINT {}
static inline void msan_allocated_memory(const volatile void *a, size_t size) LANGUAGE_NOTSAFEPOINT {}
static inline void msan_unpoison_string(const volatile char *a) LANGUAGE_NOTSAFEPOINT {}
#endif
#ifdef _COMPILER_TSAN_ENABLED_
LANGUAGE_DLLIMPORT void *__tsan_create_fiber(unsigned flags);
LANGUAGE_DLLIMPORT void *__tsan_get_current_fiber(void);
LANGUAGE_DLLIMPORT void __tsan_destroy_fiber(void *fiber);
LANGUAGE_DLLIMPORT void __tsan_switch_to_fiber(void *fiber, unsigned flags);
#endif

#ifndef alignof
#  ifndef __cplusplus
#    ifdef __GNUC__
#      define alignof _Alignof
#    else
#      define alignof(...) 1
#    endif
#  endif
#endif

#if defined(__GLIBC__) && defined(JULIA_HAS_IFUNC_SUPPORT)
// Make sure both the compiler and the glibc supports it.
// Only enable this on known working glibc versions.
#  if (defined(_CPU_X86_) || defined(_CPU_X86_64_)) && __GLIBC_PREREQ(2, 12)
#    define LANGUAGE_USE_IFUNC 1
#  elif (defined(_CPU_ARM_) || defined(_CPU_AARCH64_)) && __GLIBC_PREREQ(2, 18)
// This is the oldest tested version that supports ifunc.
#    define LANGUAGE_USE_IFUNC 1
#  endif
// TODO: PPC probably supports ifunc on some glibc versions too
#endif
// Make sure LANGUAGE_USE_IFUNC is always defined to catch include errors.
#ifndef LANGUAGE_USE_IFUNC
#  define LANGUAGE_USE_IFUNC 0
#endif

// If we've smashed the stack, (and not just normal NORETURN)
// this will smash stack-unwind too
#ifdef _OS_WINDOWS_
#if defined(_CPU_X86_64_)
    // install the unhandled exception handler at the top of our stack
    // to call directly into our personality handler
#define CFI_NORETURN \
    asm volatile ("\t.seh_handler __language_personality, @except\n\t.text");
#else
#define CFI_NORETURN
#endif
#else
// wipe out the call-stack unwind capability beyond this function
// (we are noreturn, so it is not a total lie)
#if defined(_CPU_X86_64_)
// per nongnu libunwind: "x86_64 ABI specifies that end of call-chain is marked with a NULL RBP or undefined return address"
// so we do all 3, to be extra certain of it
#define CFI_NORETURN \
    asm volatile ("\t.cfi_undefined rip"); \
    asm volatile ("\t.cfi_undefined rbp"); \
    asm volatile ("\t.cfi_return_column rbp");
#else
    // per nongnu libunwind: "DWARF spec says undefined return address location means end of stack"
    // we use whatever happens to be register 1 on this platform for this
#define CFI_NORETURN \
    asm volatile ("\t.cfi_undefined 1"); \
    asm volatile ("\t.cfi_return_column 1");
#endif
#endif

extern LANGUAGE_DLLEXPORT uintptr_t __stack_chk_guard;

// If this is detected in a backtrace of segfault, it means the functions
// that use this value must be reworked into their async form with cb arg
// provided and with LANGUAGE_UV_LOCK used around the calls
static uv_loop_t *const unused_uv_loop_arg = (uv_loop_t *)0xBAD10;

extern language_mutex_t language_uv_mutex;
extern _Atomic(int) language_uv_n_waiters;
void LANGUAGE_UV_LOCK(void);
#define LANGUAGE_UV_UNLOCK() LANGUAGE_UNLOCK(&language_uv_mutex)
extern _Atomic(unsigned) _threadedregion;
extern _Atomic(uint16_t) io_loop_tid;

int language_running_under_rr(int recheck) LANGUAGE_NOTSAFEPOINT;

//--------------------------------------------------
// timers
// Returns time in nanosec
LANGUAGE_DLLEXPORT uint64_t language_hrtime(void) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT double language_get_profile_peek_duration(void);
LANGUAGE_DLLEXPORT void language_set_profile_peek_duration(double);

LANGUAGE_DLLEXPORT void language_init_profile_lock(void);
LANGUAGE_DLLEXPORT uintptr_t language_lock_profile_rd_held(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_lock_profile(void) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER;
LANGUAGE_DLLEXPORT void language_unlock_profile(void) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_LEAVE;
LANGUAGE_DLLEXPORT void language_lock_profile_wr(void) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER;
LANGUAGE_DLLEXPORT void language_unlock_profile_wr(void) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_LEAVE;
int language_lock_stackwalk(void) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_ENTER;
void language_unlock_stackwalk(int lockret) LANGUAGE_NOTSAFEPOINT LANGUAGE_NOTSAFEPOINT_LEAVE;

// number of cycles since power-on
static inline uint64_t cycleclock(void) LANGUAGE_NOTSAFEPOINT
{
#if defined(_CPU_X86_64_)
    // This is nopl 0(%rax, %rax, 1), but assembler are inconsistent about whether
    // they emit that as a 4 or 5 byte sequence and we need to be guaranteed to use
    // the 5 byte one.
#define NOP5_OVERRIDE_NOP ".byte 0x0f, 0x1f, 0x44, 0x00, 0x00\n\t"
    uint64_t low, high;
    // This instruction sequence is promised by rr to be patchable. rr can usually
    // also patch `rdtsc` in regular code, but without the preceding nop, there could
    // be an interfering branch into the middle of rr's patch region. Using this
    // sequence prevents a massive rr-induced slowdown if the compiler happens to emit
    // an unlucky pattern. See https://github.com/rr-debugger/rr/pull/3580.
    __asm__ volatile(NOP5_OVERRIDE_NOP "rdtsc" : "=a"(low), "=d"(high));
    return (high << 32) | low;
#elif defined(_CPU_X86_)
    int64_t ret;
    __asm__ volatile("rdtsc" : "=A"(ret));
    return ret;
#elif defined(_CPU_AARCH64_)
    // System timer of ARMv8 runs at a different frequency than the CPU's.
    // The frequency is fixed, typically in the range 1-50MHz.  It can be
    // read at CNTFRQ special register.  We assume the OS has set up
    // the virtual timer properly.
    int64_t virtual_timer_value;
    __asm__ volatile("mrs %0, cntvct_el0" : "=r"(virtual_timer_value));
    return virtual_timer_value;
#elif defined(_CPU_ARM_)
    // V6 is the earliest arch that has a standard cyclecount
#if (__ARM_ARCH >= 6)
    uint32_t pmccntr;
    uint32_t pmuseren;
    uint32_t pmcntenset;
    // Read the user mode perf monitor counter access permissions.
    asm volatile("mrc p15, 0, %0, c9, c14, 0" : "=r"(pmuseren));
    if (pmuseren & 1) {  // Allows reading perfmon counters for user mode code.
        asm volatile("mrc p15, 0, %0, c9, c12, 1" : "=r"(pmcntenset));
        if (pmcntenset & 0x80000000ul) {  // Is it counting?
            asm volatile("mrc p15, 0, %0, c9, c13, 0" : "=r"(pmccntr));
            // The counter is set up to count every 64th cycle
            return (int64_t)(pmccntr) * 64;  // Should optimize to << 6
        }
    }
#endif
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (int64_t)(tv.tv_sec) * 1000000 + tv.tv_usec;
#elif defined(_CPU_PPC64_)
    // This returns a time-base, which is not always precisely a cycle-count.
    // https://reviews.llvm.org/D78084
    int64_t tb;
    asm volatile("mfspr %0, 268" : "=r" (tb));
    return tb;
#else
    #warning No cycleclock() definition for your platform
    // copy from https://github.com/google/benchmark/blob/v1.5.0/src/cycleclock.h
    return 0;
#endif
}

#include "timing.h"

extern LANGUAGE_DLLEXPORT uint64_t language_typeinf_timing_begin(void) LANGUAGE_NOTSAFEPOINT;
extern LANGUAGE_DLLEXPORT void language_typeinf_timing_end(uint64_t start, int is_recompile) LANGUAGE_NOTSAFEPOINT;

// Global *atomic* integers controlling *process-wide* measurement of compilation time.
extern LANGUAGE_DLLEXPORT _Atomic(uint8_t) language_measure_compile_time_enabled;
extern LANGUAGE_DLLEXPORT _Atomic(uint64_t) language_cumulative_compile_time;
extern LANGUAGE_DLLEXPORT _Atomic(uint64_t) language_cumulative_recompile_time;

#define language_return_address() ((uintptr_t)__builtin_return_address(0))

STATIC_INLINE uint32_t language_int32hash_fast(uint32_t a)
{
//    a = (a+0x7ed55d16) + (a<<12);
//    a = (a^0xc761c23c) ^ (a>>19);
//    a = (a+0x165667b1) + (a<<5);
//    a = (a+0xd3a2646c) ^ (a<<9);
//    a = (a+0xfd7046c5) + (a<<3);
//    a = (a^0xb55a4f09) ^ (a>>16);
    return a;  // identity hashing seems to work well enough here
}


// this is a version of memcpy that preserves atomic memory ordering
// which makes it safe to use for objects that can contain memory references
// without risk of creating pointers out of thin air
// TODO: replace with LLVM's llvm.memmove.element.unordered.atomic.p0i8.p0i8.i32
//       aka `__llvm_memmove_element_unordered_atomic_8` (for 64 bit)
static inline void memmove_refs(_Atomic(void*) *dstp, _Atomic(void*) *srcp, size_t n) LANGUAGE_NOTSAFEPOINT
{
    size_t i;
    if (dstp < srcp || dstp > srcp + n) {
        for (i = 0; i < n; i++) {
            language_atomic_store_release(dstp + i, language_atomic_load_relaxed(srcp + i));
        }
    }
    else {
        for (i = 0; i < n; i++) {
            language_atomic_store_release(dstp + n - i - 1, language_atomic_load_relaxed(srcp + n - i - 1));
        }
    }
}

static inline void memassign_safe(int hasptr, char *dst, const language_value_t *src, size_t nb) LANGUAGE_NOTSAFEPOINT
{
    assert(nb == language_datatype_size(language_typeof(src)));
    if (hasptr) {
        size_t nptr = nb / sizeof(void*);
        memmove_refs((_Atomic(void*)*)dst, (_Atomic(void*)*)src, nptr);
        nb -= nptr * sizeof(void*);
        if (__likely(nb == 0))
            return;
        src = (language_value_t*)((char*)src + nptr * sizeof(void*));
        dst = dst + nptr * sizeof(void*);
    }
    else if (nb >= 16) {
        memcpy(dst, language_assume_aligned(src, 16), nb);
        return;
    }
    memcpy(dst, language_assume_aligned(src, sizeof(void*)), nb);
}

// -- gc.c -- //

#define GC_CLEAN  0 // freshly allocated
#define GC_MARKED 1 // reachable and young
#define GC_OLD    2 // if it is reachable it will be marked as old
#define GC_OLD_MARKED (GC_OLD | GC_MARKED) // reachable and old
#define GC_IN_IMAGE 4

// useful constants
extern LANGUAGE_DLLIMPORT language_methtable_t *language_type_type_mt LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLIMPORT language_methtable_t *language_nonfunction_mt LANGUAGE_GLOBALLY_ROOTED;
extern language_methtable_t *language_kwcall_mt LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLEXPORT language_method_t *language_opaque_closure_method LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLEXPORT _Atomic(size_t) language_world_counter;
extern language_debuginfo_t *language_nulldebuginfo LANGUAGE_GLOBALLY_ROOTED;

typedef void (*tracer_cb)(language_value_t *tracee);
extern tracer_cb language_newmeth_tracer;
void language_call_tracer(tracer_cb callback, language_value_t *tracee);
void print_func_loc(LANGUAGE_STREAM *s, language_method_t *m);
extern language_array_t *_language_debug_method_invalidation LANGUAGE_GLOBALLY_ROOTED;
LANGUAGE_DLLEXPORT extern arraylist_t language_linkage_blobs; // external linkage: sysimg/pkgimages
LANGUAGE_DLLEXPORT extern arraylist_t language_image_relocs;  // external linkage: sysimg/pkgimages
LANGUAGE_DLLEXPORT extern arraylist_t language_top_mods;  // external linkage: sysimg/pkgimages
extern arraylist_t eytzinger_image_tree;
extern arraylist_t eytzinger_idxs;

extern LANGUAGE_DLLEXPORT size_t language_page_size;
extern language_function_t *language_typeinf_func LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLEXPORT size_t language_typeinf_world;
extern _Atomic(language_typemap_entry_t*) call_cache[N_CALL_CACHE] LANGUAGE_GLOBALLY_ROOTED;

LANGUAGE_DLLEXPORT extern int language_lineno;
LANGUAGE_DLLEXPORT extern const char *language_filename;

language_value_t *language_gc_pool_alloc_noinline(language_ptls_t ptls, int pool_offset,
                                   int osize);
language_value_t *language_gc_big_alloc_noinline(language_ptls_t ptls, size_t allocsz);
LANGUAGE_DLLEXPORT int language_gc_classify_pools(size_t sz, int *osize) LANGUAGE_NOTSAFEPOINT;
extern uv_mutex_t gc_perm_lock;
void *language_gc_perm_alloc_nolock(size_t sz, int zero,
    unsigned align, unsigned offset) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void *language_gc_perm_alloc(size_t sz, int zero,
    unsigned align, unsigned offset) LANGUAGE_NOTSAFEPOINT;
void gc_sweep_sysimg(void);


// pools are 16376 bytes large (GC_POOL_SZ - GC_PAGE_OFFSET)
static const int language_gc_sizeclasses[] = {
#ifdef _P64
    8,
#elif MAX_ALIGN > 4
    // ARM and PowerPC have max alignment larger than pointer,
    // make sure allocation of size 8 has that alignment.
    4, 8,
#else
    4, 8, 12,
#endif

    // 16 pools at 8-byte spacing
    // the 8-byte aligned pools are only used for Strings
    16, 24, 32, 40, 48, 56, 64, 72, 80, 88, 96, 104, 112, 120, 128, 136,
    // 8 pools at 16-byte spacing
    144, 160, 176, 192, 208, 224, 240, 256,

    // the following tables are computed for maximum packing efficiency via the formula:
    // pg = GC_SMALL_PAGE ? 2^12 : 2^14
    // sz = (div.(pg-8, rng).÷16)*16; hcat(sz, (pg-8).÷sz, pg .- (pg-8).÷sz.*sz)'

#ifdef GC_SMALL_PAGE
    // rng = 15:-1:2 (14 pools)
    272, 288, 304, 336, 368, 400, 448, 496, 576, 672, 816, 1008, 1360, 2032
//  15, 14, 13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, /pool
//  16, 64, 144, 64, 48, 96, 64, 128, 64, 64, 16, 64, 16, 32, bytes lost
#else
    // rng = 60:-4:32 (8 pools)
    272, 288, 304, 336, 368, 400, 448, 496,
//  60, 56, 53, 48, 44, 40, 36, 33, /pool
//  64, 256, 272, 256, 192, 384, 256,  16, bytes lost

    // rng = 30:-2:16 (8 pools)
    544, 576, 624, 672, 736, 816, 896, 1008,
//  30, 28, 26, 24, 22, 20, 18, 16, /pool
//  64, 256, 160, 256, 192,  64, 256, 256, bytes lost

    // rng = 15:-1:8 (8 pools)
    1088, 1168, 1248, 1360, 1488, 1632, 1808, 2032
//   15, 14, 13, 12, 11, 10, 9, 8, /pool
//   64, 32, 160, 64, 16, 64, 112,  128, bytes lost
#endif
};
#ifdef GC_SMALL_PAGE
#ifdef _P64
#  define LANGUAGE_GC_N_POOLS 39
#elif MAX_ALIGN == 8
#  define LANGUAGE_GC_N_POOLS 40
#else
#  define LANGUAGE_GC_N_POOLS 41
#endif
#else
#ifdef _P64
#  define LANGUAGE_GC_N_POOLS 49
#elif MAX_ALIGN == 8
#  define LANGUAGE_GC_N_POOLS 50
#else
#  define LANGUAGE_GC_N_POOLS 51
#endif
#endif
static_assert(sizeof(language_gc_sizeclasses) / sizeof(language_gc_sizeclasses[0]) == LANGUAGE_GC_N_POOLS, "");

STATIC_INLINE int language_gc_alignment(size_t sz) LANGUAGE_NOTSAFEPOINT
{
    if (sz == 0)
        return sizeof(void*);
#ifdef _P64
    (void)sz;
    return 16;
#elif MAX_ALIGN == 8
    return sz <= 4 ? 8 : 16;
#else
    // szclass 8
    if (sz <= 4)
        return 8;
    // szclass 12
    if (sz <= 8)
        return 4;
    // szclass 16+
    return 16;
#endif
}
LANGUAGE_DLLEXPORT int language_alignment(size_t sz) LANGUAGE_NOTSAFEPOINT;

// the following table is computed as:
// [searchsortedfirst(language_gc_sizeclasses, i) - 1 for i = 0:16:language_gc_sizeclasses[end]]
static const uint8_t szclass_table[] =
#ifdef GC_SMALL_PAGE
    {0,1,3,5,7,9,11,13,15,17,18,19,20,21,22,23,24,25,26,27,28,28,29,29,30,30,31,31,31,32,32,32,33,33,33,33,33,34,34,34,34,34,34,35,35,35,35,35,35,35,35,35,36,36,36,36,36,36,36,36,36,36,36,36,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,37,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38,38};
#else
    {0,1,3,5,7,9,11,13,15,17,18,19,20,21,22,23,24,25,26,27,28,28,29,29,30,30,31,31,31,32,32,32,33,33,33,34,34,35,35,35,36,36,36,37,37,37,37,38,38,38,38,38,39,39,39,39,39,40,40,40,40,40,40,40,41,41,41,41,41,42,42,42,42,42,43,43,43,43,43,44,44,44,44,44,44,44,45,45,45,45,45,45,45,45,46,46,46,46,46,46,46,46,46,47,47,47,47,47,47,47,47,47,47,47,48,48,48,48,48,48,48,48,48,48,48,48,48,48};
#endif
static_assert(sizeof(szclass_table) == 128, "");

STATIC_INLINE uint8_t LANGUAGE_CONST_FUNC language_gc_szclass(unsigned sz) LANGUAGE_NOTSAFEPOINT
{
    assert(sz <= 2032);
#ifdef _P64
    if (sz <= 8)
        return 0;
    const int N = 0;
#elif MAX_ALIGN == 8
    if (sz <= 8)
        return (sz >= 4 ? 1 : 0);
    const int N = 1;
#else
    if (sz <= 12)
        return (sz >= 8 ? 2 : (sz >= 4 ? 1 : 0));
    const int N = 2;
#endif
    uint8_t klass = szclass_table[(sz + 15) / 16];
    return klass + N;
}

STATIC_INLINE uint8_t LANGUAGE_CONST_FUNC language_gc_szclass_align8(unsigned sz) LANGUAGE_NOTSAFEPOINT
{
    if (sz >= 16 && sz <= 152) {
#ifdef _P64
        const int N = 0;
#elif MAX_ALIGN == 8
        const int N = 1;
#else
        const int N = 2;
#endif
        return (sz + 7)/8 - 1 + N;
    }
    return language_gc_szclass(sz);
}

#define LANGUAGE_SMALL_BYTE_ALIGNMENT 16
// LANGUAGE_HEAP_ALIGNMENT is the maximum alignment that the GC can provide
#define LANGUAGE_HEAP_ALIGNMENT LANGUAGE_SMALL_BYTE_ALIGNMENT
#define GC_MAX_SZCLASS (2032-sizeof(void*))
static_assert(ARRAY_CACHE_ALIGN_THRESHOLD > GC_MAX_SZCLASS, "");

STATIC_INLINE language_value_t *language_gc_alloc_(language_ptls_t ptls, size_t sz, void *ty)
{
    language_value_t *v;
    const size_t allocsz = sz + sizeof(language_taggedvalue_t);
    if (sz <= GC_MAX_SZCLASS) {
        int pool_id = language_gc_szclass(allocsz);
        language_gc_pool_t *p = &ptls->heap.norm_pools[pool_id];
        int osize = language_gc_sizeclasses[pool_id];
        // We call `language_gc_pool_alloc_noinline` instead of `language_gc_pool_alloc` to avoid double-counting in
        // the Allocations Profiler. (See https://github.com/JuliaLang/julia/pull/43868 for more details.)
        v = language_gc_pool_alloc_noinline(ptls, (char*)p - (char*)ptls, osize);
    }
    else {
        if (allocsz < sz) // overflow in adding offs, size was "negative"
            language_throw(language_memory_exception);
        v = language_gc_big_alloc_noinline(ptls, allocsz);
    }
    language_set_typeof(v, ty);
    maybe_record_alloc_to_profile(v, sz, (language_datatype_t*)ty);
    return v;
}

/* Programming style note: When using language_gc_alloc, do not LANGUAGE_GC_PUSH it into a
 * gc frame, until it has been fully initialized. An uninitialized value in a
 * gc frame can crash upon encountering the first safepoint. By delaying use of
 * the LANGUAGE_GC_PUSH macro until the value has been initialized, any accidental
 * safepoints will be caught by the GC analyzer.
 */
LANGUAGE_DLLEXPORT language_value_t *language_gc_alloc(language_ptls_t ptls, size_t sz, void *ty);
// On GCC, only inline when sz is constant
#ifdef __GNUC__
#  define language_gc_alloc(ptls, sz, ty)  \
    (__builtin_constant_p(sz) ?      \
     language_gc_alloc_(ptls, sz, ty) :    \
     (language_gc_alloc)(ptls, sz, ty))
#else
#  define language_gc_alloc(ptls, sz, ty) language_gc_alloc_(ptls, sz, ty)
#endif

// language_buff_tag must be an actual pointer here, so it cannot be confused for an actual type reference.
// defined as uint64_t[3] so that we can get the right alignment of this and a "type tag" on it
const extern uint64_t _language_buff_tag[3];
#define language_buff_tag ((uintptr_t)LLT_ALIGN((uintptr_t)&_language_buff_tag[1],16))
LANGUAGE_DLLEXPORT uintptr_t language_get_buff_tag(void) LANGUAGE_NOTSAFEPOINT;

typedef void language_gc_tracked_buffer_t; // For the benefit of the static analyzer
STATIC_INLINE language_gc_tracked_buffer_t *language_gc_alloc_buf(language_ptls_t ptls, size_t sz)
{
    return language_gc_alloc(ptls, sz, (void*)language_buff_tag);
}

STATIC_INLINE language_value_t *language_gc_permobj(size_t sz, void *ty) LANGUAGE_NOTSAFEPOINT
{
    const size_t allocsz = sz + sizeof(language_taggedvalue_t);
    unsigned align = (sz == 0 ? sizeof(void*) : (allocsz <= sizeof(void*) * 2 ?
                                                 sizeof(void*) * 2 : 16));
    language_taggedvalue_t *o = (language_taggedvalue_t*)language_gc_perm_alloc(allocsz, 0, align,
                                                              sizeof(void*) % align);
    uintptr_t tag = (uintptr_t)ty;
    o->header = tag | GC_OLD_MARKED;
    return language_valueof(o);
}
language_value_t *language_permbox8(language_datatype_t *t, uintptr_t tag, uint8_t x);
language_value_t *language_permbox32(language_datatype_t *t, uintptr_t tag, uint32_t x);
language_svec_t *language_perm_symsvec(size_t n, ...);

// this sizeof(__VA_ARGS__) trick can't be computed until C11, but that only matters to Clang in some situations
#if !defined(__clang_analyzer__) && !(defined(_COMPILER_ASAN_ENABLED_) || defined(_COMPILER_TSAN_ENABLED_))
#ifdef _COMPILER_GCC_
#define language_perm_symsvec(n, ...) \
    (language_perm_symsvec)(__extension__({                                         \
            static_assert(                                                    \
                n == sizeof((char *[]){ __VA_ARGS__ })/sizeof(char *),        \
                "Number of passed arguments does not match expected number"); \
            n;                                                                \
        }), __VA_ARGS__)
#ifdef language_svec
#undef language_svec
#define language_svec(n, ...) \
    (ilanguage_svec)(__extension__({                                                \
            static_assert(                                                    \
                n == sizeof((void *[]){ __VA_ARGS__ })/sizeof(void *),        \
                "Number of passed arguments does not match expected number"); \
            n;                                                                \
        }), __VA_ARGS__)
#else
#define language_svec(n, ...) \
    (language_svec)(__extension__({                                                 \
            static_assert(                                                    \
                n == sizeof((void *[]){ __VA_ARGS__ })/sizeof(void *),        \
                "Number of passed arguments does not match expected number"); \
            n;                                                                \
        }), __VA_ARGS__)
#endif
#endif
#endif

language_value_t *language_gc_realloc_string(language_value_t *s, size_t sz);
LANGUAGE_DLLEXPORT void *language_gc_counted_malloc(size_t sz);

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_throw_out_of_memory_error(void);


LANGUAGE_DLLEXPORT int64_t language_gc_diff_total_bytes(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int64_t language_gc_sync_total_bytes(int64_t offset) LANGUAGE_NOTSAFEPOINT;
void language_gc_track_malloced_array(language_ptls_t ptls, language_array_t *a) LANGUAGE_NOTSAFEPOINT;
void language_gc_track_malloced_genericmemory(language_ptls_t ptls, language_genericmemory_t *m, int isaligned) LANGUAGE_NOTSAFEPOINT;
size_t language_genericmemory_nbytes(language_genericmemory_t *a) LANGUAGE_NOTSAFEPOINT;
void language_gc_count_allocd(size_t sz) LANGUAGE_NOTSAFEPOINT;
void language_gc_count_freed(size_t sz) LANGUAGE_NOTSAFEPOINT;
void language_gc_run_all_finalizers(language_task_t *ct);
void language_release_task_stack(language_ptls_t ptls, language_task_t *task);
void language_gc_add_finalizer_(language_ptls_t ptls, void *v, void *f) LANGUAGE_NOTSAFEPOINT;

void language_gc_debug_print_status(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gc_debug_critical_error(void) LANGUAGE_NOTSAFEPOINT;
void language_print_gc_stats(LANGUAGE_STREAM *s);
void language_gc_reset_alloc_count(void);
uint32_t language_get_gs_ctr(void);
void language_set_gs_ctr(uint32_t ctr);

typedef struct _language_static_show_config_t { uint8_t quiet; } language_static_show_config_t;
size_t language_static_show_func_sig_(LANGUAGE_STREAM *s, language_value_t *type, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT;

STATIC_INLINE language_value_t *undefref_check(language_datatype_t *dt, language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
     if (dt->layout->first_ptr >= 0) {
        language_value_t *nullp = ((language_value_t**)v)[dt->layout->first_ptr];
        if (__unlikely(nullp == NULL))
            return NULL;
    }
    return v;
}

// -- helper types -- //

typedef struct {
    uint16_t propagate_inbounds:1;
    uint16_t has_fcall:1;
    uint16_t nospecializeinfer:1;
    uint16_t isva:1;
    uint16_t nargsmatchesmethod:1;
    uint16_t inlining:2; // 0 = use heuristic; 1 = aggressive; 2 = none
    uint16_t constprop:2; // 0 = use heuristic; 1 = aggressive; 2 = none
} language_code_info_flags_bitfield_t;

typedef union {
    language_code_info_flags_bitfield_t bits;
    uint16_t packed;
} language_code_info_flags_t;

// -- functions -- //

// Also defined in typeinfer.jl - See documentation there.
#define SOURCE_MODE_NOT_REQUIRED            0x0
#define SOURCE_MODE_ABI                     0x1
#define SOURCE_MODE_FORCE_SOURCE            0x2
#define SOURCE_MODE_FORCE_SOURCE_UNCACHED   0x3

LANGUAGE_DLLEXPORT language_code_instance_t *language_type_infer(language_method_instance_t *li, size_t world, int force, uint8_t source_mode);
LANGUAGE_DLLEXPORT language_code_instance_t *language_compile_method_internal(language_method_instance_t *meth LANGUAGE_PROPAGATES_ROOT, size_t world);
LANGUAGE_DLLEXPORT language_code_instance_t *language_get_method_inferred(
        language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT, language_value_t *rettype,
        size_t min_world, size_t max_world, language_debuginfo_t *edges);
language_method_instance_t *language_get_unspecialized(language_method_t *def LANGUAGE_PROPAGATES_ROOT);

LANGUAGE_DLLEXPORT language_code_instance_t *language_new_codeinst(
        language_method_instance_t *mi, language_value_t *owner,
        language_value_t *rettype, language_value_t *exctype,
        language_value_t *inferred_const, language_value_t *inferred,
        int32_t const_flags, size_t min_world, size_t max_world,
        uint32_t ipo_effects, uint32_t effects, language_value_t *analysis_results,
        uint8_t relocatability, language_debuginfo_t *edges /* , int absolute_max*/);

LANGUAGE_DLLEXPORT const char *language_debuginfo_file(language_debuginfo_t *debuginfo) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT const char *language_debuginfo_file1(language_debuginfo_t *debuginfo) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_module_t *language_debuginfo_module1(language_value_t *debuginfo_def) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT const char *language_debuginfo_name(language_value_t *func) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT void language_compile_method_instance(language_method_instance_t *mi, language_tupletype_t *types, size_t world);
LANGUAGE_DLLEXPORT int language_compile_hint(language_tupletype_t *types);
language_code_info_t *language_code_for_interpreter(language_method_instance_t *lam LANGUAGE_PROPAGATES_ROOT, size_t world);
language_value_t *language_code_or_ci_for_interpreter(language_method_instance_t *lam LANGUAGE_PROPAGATES_ROOT, size_t world);
int language_code_requires_compiler(language_code_info_t *src, int include_force_compile);
language_code_info_t *language_new_code_info_from_ir(language_expr_t *ast);
LANGUAGE_DLLEXPORT language_code_info_t *language_new_code_info_uninit(void);
LANGUAGE_DLLEXPORT void language_resolve_globals_in_ir(language_array_t *stmts, language_module_t *m, language_svec_t *sparam_vals,
                                           int binding_effects);

int get_next_edge(language_array_t *list, int i, language_value_t** invokesig, language_method_instance_t **caller) LANGUAGE_NOTSAFEPOINT;
int set_next_edge(language_array_t *list, int i, language_value_t *invokesig, language_method_instance_t *caller);
void push_edge(language_array_t *list, language_value_t *invokesig, language_method_instance_t *caller);

LANGUAGE_DLLEXPORT void language_add_method_root(language_method_t *m, language_module_t *mod, language_value_t* root);
void language_append_method_roots(language_method_t *m, uint64_t modid, language_array_t* roots);
int get_root_reference(rle_reference *rr, language_method_t *m, size_t i) LANGUAGE_NOTSAFEPOINT;
language_value_t *lookup_root(language_method_t *m, uint64_t key, int index) LANGUAGE_NOTSAFEPOINT;
int nroots_with_key(language_method_t *m, uint64_t key) LANGUAGE_NOTSAFEPOINT;

int language_valid_type_param(language_value_t *v);

LANGUAGE_DLLEXPORT language_value_t *language_apply_2va(language_value_t *f, language_value_t **args, uint32_t nargs);

void LANGUAGE_NORETURN language_method_error(language_function_t *f, language_value_t **args, size_t na, size_t world);
LANGUAGE_DLLEXPORT language_value_t *language_get_exceptionf(language_datatype_t *exception_type, const char *fmt, ...);

LANGUAGE_DLLEXPORT void language_typeassert(language_value_t *x, language_value_t *t);

#define LANGUAGE_CALLABLE(name)                                               \
    LANGUAGE_DLLEXPORT language_value_t *name(language_value_t *F, language_value_t **args, uint32_t nargs)

LANGUAGE_CALLABLE(language_f_tuple);
LANGUAGE_CALLABLE(language_f_intrinsic_call);
LANGUAGE_CALLABLE(language_f_opaque_closure_call);
void language_install_default_signal_handlers(void);
void restore_signals(void);
void language_install_thread_signal_handler(language_ptls_t ptls);

LANGUAGE_DLLEXPORT language_fptr_args_t language_get_builtin_fptr(language_datatype_t *dt);

extern uv_loop_t *language_io_loop;
LANGUAGE_DLLEXPORT void language_uv_flush(uv_stream_t *stream);

typedef struct language_typeenv_t {
    language_tvar_t *var;
    language_value_t *val;
    struct language_typeenv_t *prev;
} language_typeenv_t;

int language_tuple_isa(language_value_t **child, size_t cl, language_datatype_t *pdt);
int language_tuple1_isa(language_value_t *child1, language_value_t **child, size_t cl, language_datatype_t *pdt);

enum atomic_kind {
    isatomic_none = 0,
    isatomic_object = 1,
    isatomic_field = 2
};

LANGUAGE_DLLEXPORT int language_has_intersect_type_not_kind(language_value_t *t);
int language_subtype_invariant(language_value_t *a, language_value_t *b, int ta);
int language_has_concrete_subtype(language_value_t *typ);
language_tupletype_t *language_inst_arg_tuple_type(language_value_t *arg1, language_value_t **args, size_t nargs, int leaf);
language_tupletype_t *language_lookup_arg_tuple_type(language_value_t *arg1 LANGUAGE_PROPAGATES_ROOT, language_value_t **args, size_t nargs, int leaf);
LANGUAGE_DLLEXPORT void language_method_table_insert(language_methtable_t *mt, language_method_t *method, language_tupletype_t *simpletype);
void language_method_table_activate(language_methtable_t *mt, language_typemap_entry_t *newentry);
language_typemap_entry_t *language_method_table_add(language_methtable_t *mt, language_method_t *method, language_tupletype_t *simpletype);
language_datatype_t *language_mk_builtin_func(language_datatype_t *dt, const char *name, language_fptr_args_t fptr) LANGUAGE_GC_DISABLED;
int language_obviously_unequal(language_value_t *a, language_value_t *b);
int language_has_bound_typevars(language_value_t *v, language_typeenv_t *env) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_array_t *language_find_free_typevars(language_value_t *v);
int language_has_fixed_layout(language_datatype_t *t);
LANGUAGE_DLLEXPORT int language_struct_try_layout(language_datatype_t *dt);
LANGUAGE_DLLEXPORT int language_type_mappable_to_c(language_value_t *ty);
language_svec_t *language_outer_unionall_vars(language_value_t *u);
language_value_t *language_type_intersection_env_s(language_value_t *a, language_value_t *b, language_svec_t **penv, int *issubty);
language_value_t *language_type_intersection_env(language_value_t *a, language_value_t *b, language_svec_t **penv);
int language_subtype_matching(language_value_t *a, language_value_t *b, language_svec_t **penv);
LANGUAGE_DLLEXPORT int language_types_egal(language_value_t *a, language_value_t *b) LANGUAGE_NOTSAFEPOINT;
// specificity comparison assuming !(a <: b) and !(b <: a)
LANGUAGE_DLLEXPORT int language_type_morespecific_no_subtype(language_value_t *a, language_value_t *b);
language_value_t *language_instantiate_type_with(language_value_t *t, language_value_t **env, size_t n);
LANGUAGE_DLLEXPORT language_value_t *language_instantiate_type_in_env(language_value_t *ty, language_unionall_t *env, language_value_t **vals);
language_value_t *language_substitute_var(language_value_t *t, language_tvar_t *var, language_value_t *val);
language_value_t *language_substitute_var_nothrow(language_value_t *t, language_tvar_t *var, language_value_t *val);
language_unionall_t *language_rename_unionall(language_unionall_t *u);
LANGUAGE_DLLEXPORT language_value_t *language_unwrap_unionall(language_value_t *v LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_rewrap_unionall(language_value_t *t, language_value_t *u);
LANGUAGE_DLLEXPORT language_value_t *language_rewrap_unionall_(language_value_t *t, language_value_t *u);
int language_count_union_components(language_value_t *v);
LANGUAGE_DLLEXPORT language_value_t *language_nth_union_component(language_value_t *v LANGUAGE_PROPAGATES_ROOT, int i) LANGUAGE_NOTSAFEPOINT;
int language_find_union_component(language_value_t *haystack, language_value_t *needle, unsigned *nth) LANGUAGE_NOTSAFEPOINT;
language_datatype_t *language_new_abstracttype(language_value_t *name, language_module_t *module,
                                   language_datatype_t *super, language_svec_t *parameters);
language_datatype_t *language_new_uninitialized_datatype(void);
void language_precompute_memoized_dt(language_datatype_t *dt, int cacheable);
LANGUAGE_DLLEXPORT language_datatype_t *language_wrap_Type(language_value_t *t);  // x -> Type{x}
language_vararg_t *language_wrap_vararg(language_value_t *t, language_value_t *n, int check, int nothrow);
void language_reinstantiate_inner_types(language_datatype_t *t);
language_datatype_t *language_lookup_cache_type_(language_datatype_t *type);
void language_cache_type_(language_datatype_t *type);
language_svec_t *cache_rehash_set(language_svec_t *a, size_t newsz);
void set_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *rhs, int isatomic) LANGUAGE_NOTSAFEPOINT;
language_value_t *swap_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *rhs, int isatomic);
language_value_t *modify_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *op, language_value_t *rhs, int isatomic);
language_value_t *replace_nth_field(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *expected, language_value_t *rhs, int isatomic);
int set_nth_fieldonce(language_datatype_t *st, language_value_t *v, size_t i, language_value_t *rhs, int isatomic);
language_value_t *swap_bits(language_value_t *ty, char *v, uint8_t *psel, language_value_t *parent, language_value_t *rhs, enum atomic_kind isatomic);
language_value_t *replace_value(language_value_t *ty, _Atomic(language_value_t*) *p, language_value_t *parent, language_value_t *expected, language_value_t *rhs, int isatomic, language_module_t *mod, language_sym_t *name);
language_value_t *replace_bits(language_value_t *ty, char *p, uint8_t *psel, language_value_t *parent, language_value_t *expected, language_value_t *rhs, enum atomic_kind isatomic);
language_value_t *modify_value(language_value_t *ty, _Atomic(language_value_t*) *p, language_value_t *parent, language_value_t *op, language_value_t *rhs, int isatomic, language_module_t *mod, language_sym_t *name);
language_value_t *modify_bits(language_value_t *ty, char *p, uint8_t *psel, language_value_t *parent, language_value_t *op, language_value_t *rhs, enum atomic_kind isatomic);
int setonce_bits(language_datatype_t *rty, char *p, language_value_t *owner, language_value_t *rhs, enum atomic_kind isatomic);
language_expr_t *language_exprn(language_sym_t *head, size_t n);
language_function_t *language_new_generic_function(language_sym_t *name, language_module_t *module);
language_function_t *language_new_generic_function_with_supertype(language_sym_t *name, language_module_t *module, language_datatype_t *st);
int language_foreach_reachable_mtable(int (*visit)(language_methtable_t *mt, void *env), void *env);
int foreach_mtable_in_module(language_module_t *m, int (*visit)(language_methtable_t *mt, void *env), void *env);
void language_init_main_module(void);
LANGUAGE_DLLEXPORT int language_is_submodule(language_module_t *child, language_module_t *parent) LANGUAGE_NOTSAFEPOINT;
language_array_t *language_get_loaded_modules(void);
LANGUAGE_DLLEXPORT int language_datatype_isinlinealloc(language_datatype_t *ty, int pointerfree);
int language_type_equality_is_identity(language_value_t *t1, language_value_t *t2) LANGUAGE_NOTSAFEPOINT;

void language_eval_global_expr(language_module_t *m, language_expr_t *ex, int set_type);
LANGUAGE_DLLEXPORT language_value_t *language_toplevel_eval_flex(language_module_t *m, language_value_t *e, int fast, int expanded, const char **toplevel_filename, int *toplevel_lineno);

language_value_t *language_eval_global_var(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *e);
language_value_t *language_interpret_opaque_closure(language_opaque_closure_t *clos, language_value_t **args, size_t nargs);
language_value_t *language_interpret_toplevel_thunk(language_module_t *m, language_code_info_t *src);
language_value_t *language_interpret_toplevel_expr_in(language_module_t *m, language_value_t *e,
                                          language_code_info_t *src,
                                          language_svec_t *sparam_vals);
LANGUAGE_DLLEXPORT int language_is_toplevel_only_expr(language_value_t *e) LANGUAGE_NOTSAFEPOINT;
language_value_t *language_call_scm_on_ast_and_loc(const char *funcname, language_value_t *expr,
                                       language_module_t *inmodule, const char *file, int line);

LANGUAGE_DLLEXPORT language_value_t *language_method_lookup_by_tt(language_tupletype_t *tt, size_t world, language_value_t *_mt);
LANGUAGE_DLLEXPORT language_method_instance_t *language_method_lookup(language_value_t **args, size_t nargs, size_t world);

language_value_t *language_gf_invoke_by_method(language_method_t *method, language_value_t *gf, language_value_t **args, size_t nargs);
language_value_t *language_gf_invoke(language_value_t *types, language_value_t *f, language_value_t **args, size_t nargs);
LANGUAGE_DLLEXPORT language_value_t *language_gf_invoke_lookup_worlds(language_value_t *types, language_value_t *mt, size_t world, size_t *min_world, size_t *max_world);
LANGUAGE_DLLEXPORT language_value_t *language_matching_methods(language_tupletype_t *types, language_value_t *mt, int lim, int include_ambiguous,
                                             size_t world, size_t *min_valid, size_t *max_valid, int *ambig);
LANGUAGE_DLLEXPORT language_value_t *language_gf_invoke_lookup_worlds(language_value_t *types, language_value_t *mt, size_t world, size_t *min_world, size_t *max_world);


language_datatype_t *language_nth_argument_datatype(language_value_t *argtypes LANGUAGE_PROPAGATES_ROOT, int n) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_argument_datatype(language_value_t *argt LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_methtable_t *language_method_table_for(
    language_value_t *argtypes LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
language_methtable_t *language_kwmethod_table_for(
    language_value_t *argtypes LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_methtable_t *language_method_get_table(
    language_method_t *method LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT int language_pointer_egal(language_value_t *t);
LANGUAGE_DLLEXPORT language_value_t *language_nth_slot_type(language_value_t *sig LANGUAGE_PROPAGATES_ROOT, size_t i) LANGUAGE_NOTSAFEPOINT;
void language_compute_field_offsets(language_datatype_t *st);
void language_module_run_initializer(language_module_t *m);
LANGUAGE_DLLEXPORT language_binding_t *language_get_module_binding(language_module_t *m LANGUAGE_PROPAGATES_ROOT, language_sym_t *var, int alloc);
LANGUAGE_DLLEXPORT void language_binding_deprecation_warning(language_module_t *m, language_sym_t *sym, language_binding_t *b);
extern language_array_t *language_module_init_order LANGUAGE_GLOBALLY_ROOTED;
extern htable_t language_current_modules LANGUAGE_GLOBALLY_ROOTED;
extern LANGUAGE_DLLEXPORT language_module_t *language_precompile_toplevel_module LANGUAGE_GLOBALLY_ROOTED;
extern language_genericmemory_t *language_global_roots_list LANGUAGE_GLOBALLY_ROOTED;
extern language_genericmemory_t *language_global_roots_keyset LANGUAGE_GLOBALLY_ROOTED;
LANGUAGE_DLLEXPORT int language_is_globally_rooted(language_value_t *val LANGUAGE_MAYBE_UNROOTED) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_as_global_root(language_value_t *val, int insert) LANGUAGE_GLOBALLY_ROOTED;

language_opaque_closure_t *language_new_opaque_closure(language_tupletype_t *argt, language_value_t *rt_lb, language_value_t *rt_ub,
    language_value_t *source,  language_value_t **env, size_t nenv, int do_compile);
language_method_t *language_make_opaque_closure_method(language_module_t *module, language_value_t *name,
    int nargs, language_value_t *functionloc, language_code_info_t *ci, int isva, int isinferred);
LANGUAGE_DLLEXPORT int language_is_valid_oc_argtype(language_tupletype_t *argt, language_method_t *source);

STATIC_INLINE int is_anonfn_typename(char *name)
{
    if (name[0] != '#' || name[1] == '#')
        return 0;
    char *other = strrchr(name, '#');
    return other > &name[1] && other[1] > '0' && other[1] <= '9';
}

// Each tuple can exist in one of 4 Vararg states:
//   NONE: no vararg                            Tuple{Int,Float32}
//   INT: vararg with integer length            Tuple{Int,Vararg{Float32,2}}
//   BOUND: vararg with bound TypeVar length    Tuple{Int,Vararg{Float32,N}}
//   UNBOUND: vararg with unbound length        Tuple{Int,Vararg{Float32}}
typedef enum {
    LANGUAGE_VARARG_NONE    = 0,
    LANGUAGE_VARARG_INT     = 1,
    LANGUAGE_VARARG_BOUND   = 2,
    LANGUAGE_VARARG_UNBOUND = 3
} language_vararg_kind_t;

STATIC_INLINE language_value_t *language_unwrap_vararg(language_vararg_t *v LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_vararg((language_value_t*)v));
    language_value_t *T = ((language_vararg_t*)v)->T;
    return T ? T : (language_value_t*)language_any_type;
}
#define language_unwrap_vararg(v) (language_unwrap_vararg)((language_vararg_t *)v)

STATIC_INLINE language_value_t *language_unwrap_vararg_num(language_vararg_t *v LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_vararg((language_value_t*)v));
    return ((language_vararg_t*)v)->N;
}
#define language_unwrap_vararg_num(v) (language_unwrap_vararg_num)((language_vararg_t *)v)

STATIC_INLINE language_vararg_kind_t language_vararg_kind(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    if (!language_is_vararg(v))
        return LANGUAGE_VARARG_NONE;
    language_vararg_t *vm = (language_vararg_t *)v;
    if (!vm->N)
        return LANGUAGE_VARARG_UNBOUND;
    if (language_is_long(vm->N))
        return LANGUAGE_VARARG_INT;
    return LANGUAGE_VARARG_BOUND;
}

STATIC_INLINE int language_is_va_tuple(language_datatype_t *t) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_tuple_type(t));
    size_t l = language_svec_len(t->parameters);
    return (l>0 && language_is_vararg(language_tparam(t,l-1)));
}

STATIC_INLINE size_t language_vararg_length(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_vararg(v));
    language_value_t *len = language_unwrap_vararg_num(v);
    assert(language_is_long(len));
    return language_unbox_long(len);
}

STATIC_INLINE language_vararg_kind_t language_va_tuple_kind(language_datatype_t *t) LANGUAGE_NOTSAFEPOINT
{
    t = (language_datatype_t*)language_unwrap_unionall((language_value_t*)t);
    assert(language_is_tuple_type(t));
    size_t l = language_svec_len(t->parameters);
    if (l == 0)
        return LANGUAGE_VARARG_NONE;
    return language_vararg_kind(language_tparam(t,l-1));
}

// -- init.c -- //

void language_init_types(void) LANGUAGE_GC_DISABLED;
void language_init_box_caches(void);
void language_init_flisp(void);
void language_init_common_symbols(void);
void language_init_primitives(void) LANGUAGE_GC_DISABLED;
void language_init_llvm(void);
void language_init_runtime_ccall(void);
void language_init_intrinsic_functions(void);
void language_init_intrinsic_properties(void);
void language_init_tasks(void) LANGUAGE_GC_DISABLED;
void language_init_stack_limits(int ismaster, void **stack_hi, void **stack_lo) LANGUAGE_NOTSAFEPOINT;
language_task_t *language_init_root_task(language_ptls_t ptls, void *stack_lo, void *stack_hi);
void language_init_serializer(void);
void language_gc_init(void);
void language_init_uv(void);
void language_init_thread_heap(language_ptls_t ptls) LANGUAGE_NOTSAFEPOINT;
void language_init_int32_int64_cache(void);
LANGUAGE_DLLEXPORT void language_init_options(void);

void language_set_base_ctx(char *__stk);

extern LANGUAGE_DLLEXPORT ssize_t language_tls_offset;
extern LANGUAGE_DLLEXPORT const int language_tls_elf_support;
void language_init_threading(void);
void language_start_threads(void);

// Whether the GC is running
extern char *language_safepoint_pages;
STATIC_INLINE int language_addr_is_safepoint(uintptr_t addr)
{
    uintptr_t safepoint_addr = (uintptr_t)language_safepoint_pages;
    return addr >= safepoint_addr && addr < safepoint_addr + language_page_size * 4;
}
extern _Atomic(uint32_t) language_gc_running;
extern _Atomic(uint32_t) language_gc_disable_counter;
// All the functions are safe to be called from within a signal handler
// provided that the thread will not be interrupted by another asynchronous
// signal.
// Initialize the safepoint
void language_safepoint_init(void);
// Start the GC, return `1` if the thread should be running the GC.
// Otherwise, the thread will wait in this function until the GC finishes on
// another thread and return `0`.
// The caller should have saved the `gc_state` and set it to `WAITING`
// before calling this function. If the calling thread is to run the GC,
// it should also wait for the mutator threads to hit a safepoint **AFTER**
// this function returns
int language_safepoint_start_gc(void);
// Can only be called by the thread that have got a `1` return value from
// `language_safepoint_start_gc()`. This disables the safepoint (for GC,
// the `mprotect` may not be removed if there's pending SIGINT) and wake
// up waiting threads if there's any.
// The caller should restore `gc_state` **AFTER** calling this function.
void language_safepoint_end_gc(void);
// Wait for the GC to finish
// This function does **NOT** modify the `gc_state` to inform the GC thread
// The caller should set it **BEFORE** calling this function.
void language_safepoint_wait_gc(void) LANGUAGE_NOTSAFEPOINT;
void language_safepoint_wait_thread_resume(void) LANGUAGE_NOTSAFEPOINT;

// Set pending sigint and enable the mechanisms to deliver the sigint.
void language_safepoint_enable_sigint(void);
// If the safepoint is enabled to deliver sigint, disable it
// so that the thread won't repeatedly trigger it in a sigatomic region
// while not being able to actually throw the exception.
void language_safepoint_defer_sigint(void);
// Clear the sigint pending flag and disable the mechanism to deliver sigint.
// Return `1` if the sigint should be delivered and `0` if there's no sigint
// to be delivered.
int language_safepoint_consume_sigint(void);
void language_wake_libuv(void) LANGUAGE_NOTSAFEPOINT;

void language_set_pgcstack(language_gcframe_t **) LANGUAGE_NOTSAFEPOINT;
#if defined(_OS_DARWIN_)
typedef pthread_key_t language_pgcstack_key_t;
#elif defined(_OS_WINDOWS_)
typedef DWORD language_pgcstack_key_t;
#else
typedef language_gcframe_t ***(*language_pgcstack_key_t)(void) LANGUAGE_NOTSAFEPOINT;
#endif
LANGUAGE_DLLEXPORT void language_pgcstack_getkey(language_get_pgcstack_func **f, language_pgcstack_key_t *k) LANGUAGE_NOTSAFEPOINT;

#if !defined(_OS_WINDOWS_) && !defined(__APPLE__) && !defined(LANGUAGE_DISABLE_LIBUNWIND)
extern pthread_mutex_t in_signal_lock;
#endif

void language_set_gc_and_wait(void); // n.b. not used on _OS_DARWIN_

// Query if a Julia object is if a permalloc region (due to part of a sys- pkg-image)
STATIC_INLINE size_t n_linkage_blobs(void) LANGUAGE_NOTSAFEPOINT
{
    return language_image_relocs.len;
}

size_t external_blob_index(language_value_t *v) LANGUAGE_NOTSAFEPOINT;

// Query if this object is perm-allocated in an image.
LANGUAGE_DLLEXPORT uint8_t language_object_in_image(language_value_t* v) LANGUAGE_NOTSAFEPOINT;

// the first argument to language_idtable_rehash is used to return a value
// make sure it is rooted if it is used after the function returns
LANGUAGE_DLLEXPORT language_genericmemory_t *language_idtable_rehash(language_genericmemory_t *a, size_t newsz);
_Atomic(language_value_t*) *language_table_peek_bp(language_genericmemory_t *a, language_value_t *key) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT language_method_t *language_new_method_uninit(language_module_t*);

LANGUAGE_DLLEXPORT language_methtable_t *language_new_method_table(language_sym_t *name, language_module_t *module);
LANGUAGE_DLLEXPORT language_method_instance_t *language_get_specialization1(language_tupletype_t *types, size_t world, size_t *min_valid, size_t *max_valid, int mt_cache);
language_method_instance_t *language_get_specialized(language_method_t *m, language_value_t *types, language_svec_t *sp);
LANGUAGE_DLLEXPORT language_value_t *language_rettype_inferred(language_value_t *owner, language_method_instance_t *li LANGUAGE_PROPAGATES_ROOT, size_t min_world, size_t max_world);
LANGUAGE_DLLEXPORT language_value_t *language_rettype_inferred_native(language_method_instance_t *mi, size_t min_world, size_t max_world) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_code_instance_t *language_method_compiled(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT, size_t world) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_code_instance_t *language_method_inferred_with_abi(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT, size_t world) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_value_t *language_methtable_lookup(language_methtable_t *mt LANGUAGE_PROPAGATES_ROOT, language_value_t *type, size_t world);
LANGUAGE_DLLEXPORT language_method_instance_t *language_specializations_get_linfo(
    language_method_t *m LANGUAGE_PROPAGATES_ROOT, language_value_t *type, language_svec_t *sparams);
language_method_instance_t *language_specializations_get_or_insert(language_method_instance_t *mi_ins);
LANGUAGE_DLLEXPORT void language_method_instance_add_backedge(language_method_instance_t *callee, language_value_t *invokesig, language_method_instance_t *caller);
LANGUAGE_DLLEXPORT void language_method_table_add_backedge(language_methtable_t *mt, language_value_t *typ, language_value_t *caller);
LANGUAGE_DLLEXPORT void language_mi_cache_insert(language_method_instance_t *mi LANGUAGE_ROOTING_ARGUMENT,
                                     language_code_instance_t *ci LANGUAGE_ROOTED_ARGUMENT LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT int language_mi_try_insert(language_method_instance_t *mi LANGUAGE_ROOTING_ARGUMENT,
                                   language_code_instance_t *expected_ci,
                                   language_code_instance_t *ci LANGUAGE_ROOTED_ARGUMENT LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT int language_mi_cache_has_ci(language_method_instance_t *mi, language_code_instance_t *ci) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_code_instance_t *language_cached_uninferred(language_code_instance_t *codeinst, size_t world);
LANGUAGE_DLLEXPORT language_code_instance_t *language_cache_uninferred(language_method_instance_t *mi, language_code_instance_t *checked, size_t world, language_code_instance_t *newci LANGUAGE_MAYBE_UNROOTED);
LANGUAGE_DLLEXPORT language_code_instance_t *language_new_codeinst_for_uninferred(language_method_instance_t *mi, language_code_info_t *src);
LANGUAGE_DLLEXPORT extern language_value_t *(*const language_rettype_inferred_addr)(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT, size_t min_world, size_t max_world) LANGUAGE_NOTSAFEPOINT;

uint32_t language_module_next_counter(language_module_t *m) LANGUAGE_NOTSAFEPOINT;
language_tupletype_t *arg_type_tuple(language_value_t *arg1, language_value_t **args, size_t nargs);

LANGUAGE_DLLEXPORT int language_has_meta(language_array_t *body, language_sym_t *sym) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT language_value_t *language_parse(const char *text, size_t text_len, language_value_t *filename,
                                  size_t lineno, size_t offset, language_value_t *options);

//--------------------------------------------------
// Backtraces

// Backtrace buffers:
//
// A backtrace buffer conceptually contains a stack of instruction pointers
// ordered from the inner-most frame to the outermost. We store them in a
// special raw format for two reasons:
//
//   * Efficiency: Every `throw()` must populate the trace so it must be as
//     efficient as possible.
//   * Signal safety: For signal-based exceptions such as StackOverflowError
//     the trace buffer needs to be filled from a signal handler where most
//     operations are not allowed (including malloc) so we choose a flat
//     preallocated buffer.
//
// The raw buffer layout contains "frame entries" composed of one or several
// values of type `language_bt_element_t`. From the point of view of the GC, an entry
// is either:
//
// 1. A single instruction pointer to native code, not GC-managed.
// 2. An "extended entry": a mixture of raw data and pointers to julia objects
//    which must be treated as GC roots.
//
// A single extended entry is serialized using multiple elements from the raw
// buffer; if `e` is the pointer to the first slot we have:
//
//   e[0]  LANGUAGE_BT_NON_PTR_ENTRY  - Special marker to distinguish extended entries
//   e[1]  descriptor           - A bit packed uintptr_t containing a tag and
//                                the number of GC- managed and non-managed values
//   e[2+j]                     - GC managed data
//   e[2+ngc+i]                 - Non-GC-managed data
//
// The format of `descriptor` is, from LSB to MSB:
//   0:2     ngc     Number of GC-managed pointers for this frame entry
//   3:5     nptr    Number of non-GC-managed buffer elements
//   6:9     tag     Entry type
//   10:...  header  Entry-specific header data
typedef struct _language_bt_element_t {
    union {
        uintptr_t   uintptr; // Metadata or native instruction ptr
        language_value_t* jlvalue; // Pointer to GC-managed value
    };
} language_bt_element_t;

#define LANGUAGE_BT_NON_PTR_ENTRY (((uintptr_t)0)-1)
// Maximum size for an extended backtrace entry (likely significantly larger
// than the actual size of 3-4 for an interpreter frame)
#define LANGUAGE_BT_MAX_ENTRY_SIZE 16

STATIC_INLINE int language_bt_is_native(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    return bt_entry[0].uintptr != LANGUAGE_BT_NON_PTR_ENTRY;
}

// Extended backtrace entry header packing; the bit packing is done manually
// for precise layout control for interop with julia side.
STATIC_INLINE uintptr_t language_bt_entry_descriptor(int ngc, int nptr,
                                               int tag, uintptr_t header) LANGUAGE_NOTSAFEPOINT
{
    assert(((ngc & 0x7) == ngc) && ((nptr & 0x7) == nptr) && ((tag & 0xf) == tag));
    return (ngc & 0x7) | (nptr & 0x7) << 3 | (tag & 0xf) << 6 | header << 10;
}

// Unpacking of extended backtrace entry data
STATIC_INLINE size_t language_bt_num_jlvals(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    assert(!language_bt_is_native(bt_entry));
    return bt_entry[1].uintptr & 0x7;
}
STATIC_INLINE size_t language_bt_num_uintvals(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    assert(!language_bt_is_native(bt_entry));
    return (bt_entry[1].uintptr >> 3) & 0x7;
}
STATIC_INLINE int language_bt_entry_tag(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    assert(!language_bt_is_native(bt_entry));
    return (bt_entry[1].uintptr >> 6) & 0xf;
}
STATIC_INLINE uintptr_t language_bt_entry_header(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    assert(!language_bt_is_native(bt_entry));
    return bt_entry[1].uintptr >> 10;
}

// Return `i`th GC-managed pointer for extended backtrace entry
// The returned value is rooted for the lifetime of the parent exception stack.
STATIC_INLINE language_value_t *language_bt_entry_jlvalue(language_bt_element_t *bt_entry, size_t i) LANGUAGE_NOTSAFEPOINT
{
    return bt_entry[2 + i].jlvalue;
}

#define LANGUAGE_BT_INTERP_FRAME_TAG    1  // An interpreter frame

// Number of bt elements in frame.
STATIC_INLINE size_t language_bt_entry_size(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    return language_bt_is_native(bt_entry) ?
        1 : 2 + language_bt_num_jlvals(bt_entry) + language_bt_num_uintvals(bt_entry);
}

//------------------------------
// Stack walking and debug info lookup

// Function metadata arising from debug info lookup of instruction pointer
typedef struct {
    char *func_name;
    char *file_name;
    int line;
    language_method_instance_t *linfo;
    int fromC;
    int inlined;
} language_frame_t;

#ifdef _OS_WINDOWS_
#include <dbghelp.h>
LANGUAGE_DLLEXPORT EXCEPTION_DISPOSITION NTAPI __language_personality(
        PEXCEPTION_RECORD ExceptionRecord, void *EstablisherFrame, PCONTEXT ContextRecord, void *DispatcherContext);
extern HANDLE hMainThread;
typedef CONTEXT bt_context_t;
#if defined(_CPU_X86_64_)
typedef CONTEXT bt_cursor_t;
#else
typedef struct {
    STACKFRAME64 stackframe;
    CONTEXT context;
} bt_cursor_t;
#endif
extern LANGUAGE_DLLEXPORT uv_mutex_t language_in_stackwalk;
#elif !defined(LANGUAGE_DISABLE_LIBUNWIND)
// This gives unwind only local unwinding options ==> faster code
#  define UNW_LOCAL_ONLY
#pragma GCC visibility push(default)
#  include <libunwind.h>
#pragma GCC visibility pop
typedef unw_context_t bt_context_t;
typedef unw_cursor_t bt_cursor_t;
#  if (!defined(SYSTEM_LIBUNWIND) || UNW_VERSION_MAJOR > 1 ||   \
       (UNW_VERSION_MAJOR == 1 && UNW_VERSION_MINOR != 0 && UNW_VERSION_MINOR != 1))
// Enable our memory manager only for libunwind with our patch or
// on a newer release
#    define LANGUAGE_UNW_HAS_FORMAT_IP 1
#  endif
#else
// Unwinding is disabled
typedef int bt_context_t;
typedef int bt_cursor_t;
#endif
size_t rec_backtrace(language_bt_element_t *bt_data, size_t maxsize, int skip) LANGUAGE_NOTSAFEPOINT;
// Record backtrace from a signal handler. `ctx` is the context of the code
// which was asynchronously interrupted.
size_t rec_backtrace_ctx(language_bt_element_t *bt_data, size_t maxsize, bt_context_t *ctx,
                         language_gcframe_t *pgcstack) LANGUAGE_NOTSAFEPOINT;
#ifdef LLVMLIBUNWIND
size_t rec_backtrace_ctx_dwarf(language_bt_element_t *bt_data, size_t maxsize, bt_context_t *ctx, language_gcframe_t *pgcstack) LANGUAGE_NOTSAFEPOINT;
#endif
LANGUAGE_DLLEXPORT language_value_t *language_get_backtrace(void);
void language_critical_error(int sig, int si_code, bt_context_t *context, language_task_t *ct);
LANGUAGE_DLLEXPORT void language_raise_debugger(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_gdblookup(void* ip) LANGUAGE_NOTSAFEPOINT;
void language_print_native_codeloc(uintptr_t ip) LANGUAGE_NOTSAFEPOINT;
void language_print_bt_entry_codeloc(language_bt_element_t *bt_data) LANGUAGE_NOTSAFEPOINT;
#ifdef _OS_WINDOWS_
LANGUAGE_DLLEXPORT void language_refresh_dbg_module_list(void);
#endif
int language_thread_suspend_and_get_state(int tid, int timeout, bt_context_t *ctx) LANGUAGE_NOTSAFEPOINT;
void language_thread_resume(int tid) LANGUAGE_NOTSAFEPOINT;

// *to is NULL or malloc'd pointer, from is allowed to be NULL
STATIC_INLINE char *language_copy_str(char **to, const char *from) LANGUAGE_NOTSAFEPOINT
{
    if (!from) {
        free(*to);
        *to = NULL;
        return NULL;
    }
    size_t len = strlen(from) + 1;
    *to = (char*)realloc_s(*to, len);
    memcpy(*to, from, len);
    return *to;
}

LANGUAGE_DLLEXPORT size_t language_capture_interp_frame(language_bt_element_t *bt_data,
        void *frameend, size_t space_remaining) LANGUAGE_NOTSAFEPOINT;

//--------------------------------------------------
// Exception stack access and manipulation

// Exception stack: a stack of pairs of (exception,raw_backtrace).
// The stack may be traversed and accessed with the functions below.
struct _language_excstack_t { // typedef in code.h
    size_t top;
    size_t reserved_size;
    // Pack all stack entries into a growable buffer to amortize allocation
    // across repeated exception handling.
    // Layout: [bt_data1... bt_size1 exc1  bt_data2... bt_size2 exc2  ..]
    // language_bt_element_t data[]; // Access with language_excstack_raw
};

STATIC_INLINE language_bt_element_t *language_excstack_raw(language_excstack_t *stack) LANGUAGE_NOTSAFEPOINT
{
    return (language_bt_element_t*)(stack + 1);
}

// Exception stack access
STATIC_INLINE language_value_t *language_excstack_exception(language_excstack_t *stack LANGUAGE_PROPAGATES_ROOT,
                                                size_t itr) LANGUAGE_NOTSAFEPOINT
{
    return language_excstack_raw(stack)[itr-1].jlvalue;
}
STATIC_INLINE size_t language_excstack_bt_size(language_excstack_t *stack, size_t itr) LANGUAGE_NOTSAFEPOINT
{
    return language_excstack_raw(stack)[itr-2].uintptr;
}
STATIC_INLINE language_bt_element_t *language_excstack_bt_data(language_excstack_t *stack, size_t itr) LANGUAGE_NOTSAFEPOINT
{
    return language_excstack_raw(stack) + itr-2 - language_excstack_bt_size(stack, itr);
}
// Exception stack iteration (start at itr=stack->top, stop at itr=0)
STATIC_INLINE size_t language_excstack_next(language_excstack_t *stack, size_t itr) LANGUAGE_NOTSAFEPOINT
{
    return itr-2 - language_excstack_bt_size(stack, itr);
}
// Exception stack manipulation
void language_push_excstack(language_task_t *ct, language_excstack_t **stack LANGUAGE_REQUIRE_ROOTED_SLOT LANGUAGE_ROOTING_ARGUMENT,
                      language_value_t *exception LANGUAGE_ROOTED_ARGUMENT,
                      language_bt_element_t *bt_data, size_t bt_size);

//--------------------------------------------------
// congruential random number generator
// for a small amount of thread-local randomness

STATIC_INLINE uint64_t cong(uint64_t max, uint64_t *seed) LANGUAGE_NOTSAFEPOINT
{
    if (max == 0)
        return 0;
    uint64_t mask = ~(uint64_t)0;
    --max;
    mask >>= __builtin_clzll(max|1);
    uint64_t x;
    do {
        *seed = 69069 * (*seed) + 362437;
        x = *seed & mask;
    } while (x > max);
    return x;
}
LANGUAGE_DLLEXPORT uint64_t language_rand(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_srand(uint64_t) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_init_rand(void);

LANGUAGE_DLLEXPORT extern void *language_exe_handle;
LANGUAGE_DLLEXPORT extern void *language_liblanguage_handle;
LANGUAGE_DLLEXPORT extern void *language_liblanguage_internal_handle;
LANGUAGE_DLLEXPORT extern void *language_RTLD_DEFAULT_handle;

#if defined(_OS_WINDOWS_)
LANGUAGE_DLLEXPORT extern const char *language_crtdll_basename;
extern void *language_ntdll_handle;
extern void *language_kernel32_handle;
extern void *language_crtdll_handle;
extern void *language_winsock_handle;
void win32_formatmessage(DWORD code, char *reason, int len) LANGUAGE_NOTSAFEPOINT;
#endif

LANGUAGE_DLLEXPORT void *language_get_library_(const char *f_lib, int throw_err);
void *language_find_dynamic_library_by_addr(void *symbol);
#define language_get_library(f_lib) language_get_library_(f_lib, 1)
LANGUAGE_DLLEXPORT void *language_load_and_lookup(const char *f_lib, const char *f_name, _Atomic(void*) *hnd);
LANGUAGE_DLLEXPORT void *language_lazy_load_and_lookup(language_value_t *lib_val, const char *f_name);
LANGUAGE_DLLEXPORT language_value_t *language_get_cfunction_trampoline(
    language_value_t *fobj, language_datatype_t *result, htable_t *cache, language_svec_t *fill,
    void *(*init_trampoline)(void *tramp, void **nval),
    language_unionall_t *env, language_value_t **vals);


// Special filenames used to refer to internal julia libraries
#define LANGUAGE_EXE_LIBNAME                  ((const char*)1)
#define LANGUAGE_LIBJULIA_DL_LIBNAME          ((const char*)2)
#define LANGUAGE_LIBJULIA_INTERNAL_DL_LIBNAME ((const char*)3)
LANGUAGE_DLLEXPORT const char *language_dlfind(const char *name);

// libuv wrappers:
LANGUAGE_DLLEXPORT int language_fs_rename(const char *src_path, const char *dst_path);

// -- Runtime intrinsics -- //
LANGUAGE_DLLEXPORT const char *language_intrinsic_name(int f) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT unsigned language_intrinsic_nargs(int f) LANGUAGE_NOTSAFEPOINT;

STATIC_INLINE int is_valid_intrinsic_elptr(language_value_t *ety)
{
    return ety == (language_value_t*)language_any_type || (language_is_concrete_type(ety) && !language_is_layout_opaque(((language_datatype_t*)ety)->layout) && !language_is_array_type(ety));
}
LANGUAGE_DLLEXPORT language_value_t *language_bitcast(language_value_t *ty, language_value_t *v);
LANGUAGE_DLLEXPORT language_value_t *language_pointerref(language_value_t *p, language_value_t *i, language_value_t *align);
LANGUAGE_DLLEXPORT language_value_t *language_pointerset(language_value_t *p, language_value_t *x, language_value_t *align, language_value_t *i);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_fence(language_value_t *order);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerref(language_value_t *p, language_value_t *order);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerset(language_value_t *p, language_value_t *x, language_value_t *order);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerswap(language_value_t *p, language_value_t *x, language_value_t *order);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointermodify(language_value_t *p, language_value_t *f, language_value_t *x, language_value_t *order);
LANGUAGE_DLLEXPORT language_value_t *language_atomic_pointerreplace(language_value_t *p, language_value_t *x, language_value_t *expected, language_value_t *success_order, language_value_t *failure_order);
LANGUAGE_DLLEXPORT language_value_t *language_cglobal(language_value_t *v, language_value_t *ty);
LANGUAGE_DLLEXPORT language_value_t *language_cglobal_auto(language_value_t *v);

LANGUAGE_DLLEXPORT language_value_t *language_neg_int(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_add_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_sub_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_mul_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_sdiv_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_udiv_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_srem_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_urem_int(language_value_t *a, language_value_t *b);

LANGUAGE_DLLEXPORT language_value_t *language_add_ptr(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_sub_ptr(language_value_t *a, language_value_t *b);

LANGUAGE_DLLEXPORT language_value_t *language_neg_float(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_add_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_sub_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_mul_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_div_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_fma_float(language_value_t *a, language_value_t *b, language_value_t *c);
LANGUAGE_DLLEXPORT language_value_t *language_muladd_float(language_value_t *a, language_value_t *b, language_value_t *c);

LANGUAGE_DLLEXPORT language_value_t *language_eq_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_ne_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_slt_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_ult_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_sle_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_ule_int(language_value_t *a, language_value_t *b);

LANGUAGE_DLLEXPORT language_value_t *language_eq_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_ne_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_lt_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_le_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_fpiseq(language_value_t *a, language_value_t *b);

LANGUAGE_DLLEXPORT language_value_t *language_not_int(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_and_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_or_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_xor_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_shl_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_lshr_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_ashr_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_bswap_int(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_ctpop_int(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_ctlz_int(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_cttz_int(language_value_t *a);

LANGUAGE_DLLEXPORT language_value_t *language_sext_int(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_zext_int(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_trunc_int(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_sitofp(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_uitofp(language_value_t *ty, language_value_t *a);

LANGUAGE_DLLEXPORT language_value_t *language_fptoui(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_fptosi(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_fptrunc(language_value_t *ty, language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_fpext(language_value_t *ty, language_value_t *a);

LANGUAGE_DLLEXPORT language_value_t *language_checked_sadd_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_uadd_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_ssub_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_usub_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_smul_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_umul_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_sdiv_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_udiv_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_srem_int(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_checked_urem_int(language_value_t *a, language_value_t *b);

LANGUAGE_DLLEXPORT language_value_t *language_ceil_llvm(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_floor_llvm(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_trunc_llvm(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_rint_llvm(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_sqrt_llvm(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_sqrt_llvm_fast(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_abs_float(language_value_t *a);
LANGUAGE_DLLEXPORT language_value_t *language_copysign_float(language_value_t *a, language_value_t *b);
LANGUAGE_DLLEXPORT language_value_t *language_flipsign_int(language_value_t *a, language_value_t *b);

LANGUAGE_DLLEXPORT language_value_t *language_have_fma(language_value_t *a);
LANGUAGE_DLLEXPORT int language_stored_inline(language_value_t *el_type);
LANGUAGE_DLLEXPORT language_value_t *(language_array_data_owner)(language_array_t *a);
LANGUAGE_DLLEXPORT language_array_t *language_array_copy(language_array_t *ary);

LANGUAGE_DLLEXPORT uintptr_t language_object_id_(uintptr_t tv, language_value_t *v) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT void language_set_next_task(language_task_t *task) LANGUAGE_NOTSAFEPOINT;

// -- synchronization utilities -- //

extern language_mutex_t typecache_lock;
extern LANGUAGE_DLLEXPORT language_mutex_t language_codegen_lock;

#if defined(__APPLE__)
void language_mach_gc_end(void) LANGUAGE_NOTSAFEPOINT;
void language_safepoint_resume_thread_mach(language_ptls_t ptls2, int16_t tid2) LANGUAGE_NOTSAFEPOINT;
#endif

// -- smallintset.c -- //

typedef uint_t (*smallintset_hash)(size_t val, language_value_t *data);
typedef int (*smallintset_eq)(size_t val, const void *key, language_value_t *data, uint_t hv);
ssize_t language_smallintset_lookup(language_genericmemory_t *cache, smallintset_eq eq, const void *key, language_value_t *data, uint_t hv, int pop);
void language_smallintset_insert(_Atomic(language_genericmemory_t*) *pcache, language_value_t *parent, smallintset_hash hash, size_t val, language_value_t *data);
language_genericmemory_t* smallintset_rehash(language_genericmemory_t* a, smallintset_hash hash, language_value_t *data, size_t newsz, size_t np);
void smallintset_empty(const language_genericmemory_t *a) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT language_genericmemory_t *language_idset_rehash(language_genericmemory_t *keys, language_genericmemory_t *idxs, size_t newsz);
LANGUAGE_DLLEXPORT ssize_t language_idset_peek_bp(language_genericmemory_t *keys, language_genericmemory_t *idxs, language_value_t *key) LANGUAGE_NOTSAFEPOINT;
language_value_t *language_idset_get(language_genericmemory_t *keys LANGUAGE_PROPAGATES_ROOT, language_genericmemory_t *idxs, language_value_t *key) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT language_genericmemory_t *language_idset_put_key(language_genericmemory_t *keys, language_value_t *key, ssize_t *newidx);
LANGUAGE_DLLEXPORT language_genericmemory_t *language_idset_put_idx(language_genericmemory_t *keys, language_genericmemory_t *idxs, ssize_t idx);
LANGUAGE_DLLEXPORT ssize_t language_idset_pop(language_genericmemory_t *keys, language_genericmemory_t *idxs, language_value_t *key) LANGUAGE_NOTSAFEPOINT;

// -- typemap.c -- //

void language_typemap_insert(_Atomic(language_typemap_t*) *cache, language_value_t *parent,
        language_typemap_entry_t *newrec, int8_t offs);
language_typemap_entry_t *language_typemap_alloc(
        language_tupletype_t *type, language_tupletype_t *simpletype, language_svec_t *guardsigs,
        language_value_t *newvalue, size_t min_world, size_t max_world);

struct language_typemap_assoc {
    // inputs
    language_value_t *const types;
    size_t const world;
    // outputs
    language_svec_t *env; // subtype env (initialize to null to perform intersection without an environment)
};

language_typemap_entry_t *language_typemap_assoc_by_type(
        language_typemap_t *ml_or_cache LANGUAGE_PROPAGATES_ROOT,
        struct language_typemap_assoc *search,
        int8_t offs, uint8_t subtype);

language_typemap_entry_t *language_typemap_level_assoc_exact(language_typemap_level_t *cache, language_value_t *arg1, language_value_t **args, size_t n, int8_t offs, size_t world);
language_typemap_entry_t *language_typemap_entry_assoc_exact(language_typemap_entry_t *mn, language_value_t *arg1, language_value_t **args, size_t n, size_t world);
STATIC_INLINE language_typemap_entry_t *language_typemap_assoc_exact(
    language_typemap_t *ml_or_cache LANGUAGE_PROPAGATES_ROOT,
    language_value_t *arg1, language_value_t **args, size_t n, int8_t offs, size_t world)
{
    // NOTE: This function is a huge performance hot spot!!
    if (language_typeof(ml_or_cache) == (language_value_t *)language_typemap_entry_type) {
        return language_typemap_entry_assoc_exact(
            (language_typemap_entry_t *)ml_or_cache, arg1, args, n, world);
    }
    else if (language_typeof(ml_or_cache) == (language_value_t*)language_typemap_level_type) {
        return language_typemap_level_assoc_exact(
            (language_typemap_level_t *)ml_or_cache, arg1, args, n, offs, world);
    }
    return NULL;
}
typedef int (*language_typemap_visitor_fptr)(language_typemap_entry_t *l, void *closure);
int language_typemap_visitor(language_typemap_t *a, language_typemap_visitor_fptr fptr, void *closure);

struct typemap_intersection_env;
typedef int (*language_typemap_intersection_visitor_fptr)(language_typemap_entry_t *l, struct typemap_intersection_env *closure);
struct typemap_intersection_env {
    // input values
    language_typemap_intersection_visitor_fptr const fptr; // fptr to call on a match
    language_value_t *const type; // type to match
    language_value_t *const va; // the tparam0 for the vararg in type, if applicable (or NULL)
    size_t search_slurp;
    // output values
    size_t min_valid;
    size_t max_valid;
    language_value_t *ti; // intersection type
    language_svec_t *env; // intersection env (initialize to null to perform intersection without an environment)
    int issubty;    // if `a <: b` is true in `intersect(a,b)`
};
int language_typemap_intersection_visitor(language_typemap_t *a, int offs, struct typemap_intersection_env *closure);
void typemap_slurp_search(language_typemap_entry_t *ml, struct typemap_intersection_env *closure);

// -- simplevector.c -- //

// check whether the specified number of arguments is compatible with the
// specified number of parameters of the tuple type
LANGUAGE_DLLEXPORT int language_tupletype_length_compat(language_value_t *v, size_t nargs) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT language_value_t *language_argtype_with_function(language_value_t *f, language_value_t *types0);
LANGUAGE_DLLEXPORT language_value_t *language_argtype_with_function_type(language_value_t *ft LANGUAGE_MAYBE_UNROOTED, language_value_t *types0);

LANGUAGE_DLLEXPORT unsigned language_special_vector_alignment(size_t nfields, language_value_t *field_type);

void register_eh_frames(uint8_t *Addr, size_t Size);
void deregister_eh_frames(uint8_t *Addr, size_t Size);

STATIC_INLINE void *language_get_frame_addr(void)
{
#ifdef __GNUC__
    return __builtin_frame_address(0);
#else
    void *dummy = NULL;
    // The mask is to suppress the compiler warning about returning
    // address of local variable
    return (void*)((uintptr_t)&dummy & ~(uintptr_t)15);
#endif
}

// Log `msg` to the current logger by calling CoreLogging.logmsg_shim() on the
// julia side. If any of module, group, id, file or line are NULL, these will
// be passed to the julia side as `nothing`.  If `kwargs` is NULL an empty set
// of keyword arguments will be passed.
void language_log(int level, language_value_t *module, language_value_t *group, language_value_t *id,
            language_value_t *file, language_value_t *line, language_value_t *kwargs,
            language_value_t *msg);

LANGUAGE_DLLEXPORT int language_isabspath(const char *in) LANGUAGE_NOTSAFEPOINT;

extern LANGUAGE_DLLEXPORT language_sym_t *language_call_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_invoke_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_invoke_modify_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_empty_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_top_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_module_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_slot_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_export_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_public_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_import_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_toplevel_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_quote_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_line_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_incomplete_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_goto_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_goto_ifnot_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_return_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_lineinfo_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_lambda_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_assign_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_binding_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_globalref_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_do_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_method_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_core_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_enter_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_leave_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_pop_exception_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_exc_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_error_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_new_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_using_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_splatnew_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_block_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_new_opaque_closure_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_opaque_closure_method_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_const_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_thunk_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_foreigncall_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_as_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_global_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_local_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_list_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_dot_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_newvar_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_boundscheck_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_inbounds_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_copyast_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_cfunction_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_loopinfo_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_meta_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_inert_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_polly_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_unused_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_static_parameter_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_inline_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_noinline_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_generated_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_generated_only_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_isdefined_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_propagate_inbounds_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_specialize_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_aggressive_constprop_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_no_constprop_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_purity_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_nospecialize_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_nospecializeinfer_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_macrocall_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_colon_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_hygienicscope_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_throw_undef_if_not_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_getfield_undefref_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_gc_preserve_begin_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_gc_preserve_end_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_coverageeffect_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_escape_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_aliasscope_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_popaliasscope_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_optlevel_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_thismodule_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_eval_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_include_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_atom_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_statement_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_all_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_compile_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_force_compile_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_infer_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_max_methods_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_atomic_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_not_atomic_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_unordered_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_monotonic_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_acquire_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_release_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_acquire_release_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_sequentially_consistent_sym;
extern LANGUAGE_DLLEXPORT language_sym_t *language_uninferred_sym;

LANGUAGE_DLLEXPORT enum language_memory_order language_get_atomic_order(language_sym_t *order, char loading, char storing);
LANGUAGE_DLLEXPORT enum language_memory_order language_get_atomic_order_checked(language_sym_t *order, char loading, char storing);

struct _language_image_fptrs_t;

LANGUAGE_DLLEXPORT void language_write_coverage_data(const char*);
void language_write_malloc_log(void);

#if language_has_builtin(__builtin_unreachable) || defined(_COMPILER_GCC_) || defined(_COMPILER_INTEL_)
#  define language_unreachable() __builtin_unreachable()
#else
#  define language_unreachable() ((void)language_assume(0))
#endif

language_sym_t *_language_symbol(const char *str, size_t len) LANGUAGE_NOTSAFEPOINT;

// Tools for locally disabling spurious compiler warnings
//
// Particular calls which are used elsewhere in the code include:
//
// * LANGUAGE_GCC_IGNORE_START(-Wclobbered) - gcc misidentifies some variables which
//   are used inside a LANGUAGE_TRY as being "clobbered" if LANGUAGE_CATCH is entered. This
//   warning is spurious if the variable is not modified inside the LANGUAGE_TRY.
//   See https://gcc.gnu.org/bugzilla/show_bug.cgi?id=65041
#ifdef _COMPILER_GCC_
#define LANGUAGE_DO_PRAGMA(s) _Pragma(#s)
#define LANGUAGE_GCC_IGNORE_START(warning) \
    LANGUAGE_DO_PRAGMA(GCC diagnostic push) \
    LANGUAGE_DO_PRAGMA(GCC diagnostic ignored warning)
#define LANGUAGE_GCC_IGNORE_STOP \
    LANGUAGE_DO_PRAGMA(GCC diagnostic pop)
#else
#define LANGUAGE_GCC_IGNORE_START(w)
#define LANGUAGE_GCC_IGNORE_STOP
#endif // _COMPILER_GCC_

#ifdef __clang_gcanalyzer__
  // Not a safepoint (so it doesn't free other values), but an artificial use.
  // Usually this is unnecessary because the analyzer can see all real uses,
  // but sometimes real uses are harder for the analyzer to see, or it may
  // give up before it sees it, so this can be helpful to be explicit.
  void LANGUAGE_GC_ASSERT_LIVE(language_value_t *v) LANGUAGE_NOTSAFEPOINT;
#else
  #define LANGUAGE_GC_ASSERT_LIVE(x) (void)(x)
#endif

#ifdef _OS_WINDOWS_
// On Windows, weak symbols do not default to 0 due to a GCC bug
// (https://gcc.gnu.org/bugzilla/show_bug.cgi?id=90826), use symbol
// aliases with a known value instead.
#define LANGUAGE_WEAK_SYMBOL_OR_ALIAS_DEFAULT(sym) __attribute__((weak,alias(#sym)))
#define LANGUAGE_WEAK_SYMBOL_DEFAULT(sym) &sym
#else
#define LANGUAGE_WEAK_SYMBOL_OR_ALIAS_DEFAULT(sym) __attribute__((weak))
#define LANGUAGE_WEAK_SYMBOL_DEFAULT(sym) NULL
#endif

//LANGUAGE_DLLEXPORT float language__gnu_h2f_ieee(half param) LANGUAGE_NOTSAFEPOINT;
//LANGUAGE_DLLEXPORT half language__gnu_f2h_ieee(float param) LANGUAGE_NOTSAFEPOINT;
//LANGUAGE_DLLEXPORT half language__truncdfhf2(double param) LANGUAGE_NOTSAFEPOINT;
//LANGUAGE_DLLEXPORT float language__truncsfbf2(float param) LANGUAGE_NOTSAFEPOINT;
//LANGUAGE_DLLEXPORT float language__truncdfbf2(double param) LANGUAGE_NOTSAFEPOINT;
//LANGUAGE_DLLEXPORT double language__extendhfdf2(half n) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT uint32_t language_crc32c(uint32_t crc, const char *buf, size_t len);

// -- exports from codegen -- //

#define IR_FLAG_INBOUNDS 0x01

LANGUAGE_DLLIMPORT void language_generate_fptr_for_unspecialized(language_code_instance_t *unspec);
LANGUAGE_DLLIMPORT int language_compile_codeinst(language_code_instance_t *unspec);
LANGUAGE_DLLIMPORT int language_compile_extern_c(LLVMOrcThreadSafeModuleRef llvmmod, void *params, void *sysimg, language_value_t *declrt, language_value_t *sigt);

typedef struct {
    LLVMOrcThreadSafeModuleRef TSM;
    LLVMValueRef F;
} language_llvmf_dump_t;

LANGUAGE_DLLIMPORT language_value_t *language_dump_method_asm(language_method_instance_t *linfo, size_t world,
        char emit_mc, char getwrapper, const char* asm_variant, const char *debuginfo, char binary);
LANGUAGE_DLLIMPORT void language_get_llvmf_defn(language_llvmf_dump_t* dump, language_method_instance_t *linfo, size_t world, char getwrapper, char optimize, const language_cgparams_t params);
LANGUAGE_DLLIMPORT language_value_t *language_dump_fptr_asm(uint64_t fptr, char emit_mc, const char* asm_variant, const char *debuginfo, char binary);
LANGUAGE_DLLIMPORT language_value_t *language_dump_function_ir(language_llvmf_dump_t *dump, char strip_ir_metadata, char dump_module, const char *debuginfo);
LANGUAGE_DLLIMPORT language_value_t *language_dump_function_asm(language_llvmf_dump_t *dump, char emit_mc, const char* asm_variant, const char *debuginfo, char binary, char raw);

LANGUAGE_DLLIMPORT void *language_create_native(language_array_t *methods, LLVMOrcThreadSafeModuleRef llvmmod, const language_cgparams_t *cgparams, int policy, int imaging_mode, int cache, size_t world);
LANGUAGE_DLLIMPORT void language_dump_native(void *native_code,
        const char *bc_fname, const char *unopt_bc_fname, const char *obj_fname, const char *asm_fname,
        ios_t *z, ios_t *s, language_emission_params_t *params);
LANGUAGE_DLLIMPORT void language_get_llvm_gvs(void *native_code, arraylist_t *gvs);
LANGUAGE_DLLIMPORT void language_get_llvm_external_fns(void *native_code, arraylist_t *gvs);
LANGUAGE_DLLIMPORT void language_get_function_id(void *native_code, language_code_instance_t *ncode,
        int32_t *func_idx, int32_t *specfunc_idx);
LANGUAGE_DLLIMPORT void language_register_fptrs(uint64_t image_base, const struct _language_image_fptrs_t *fptrs,
                                    language_method_instance_t **linfos, size_t n);

LANGUAGE_DLLIMPORT void language_init_codegen(void);
LANGUAGE_DLLIMPORT void language_teardown_codegen(void) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLIMPORT int language_getFunctionInfo(language_frame_t **frames, uintptr_t pointer, int skipC, int noInline) LANGUAGE_NOTSAFEPOINT;
// n.b. this might be called from unmanaged thread:
LANGUAGE_DLLIMPORT uint64_t language_getUnwindInfo(uint64_t dwBase);

#ifdef __cplusplus
}
#endif

#pragma GCC visibility pop


#ifdef USE_DTRACE
// Generated file, needs to be searched in include paths so that the builddir
// retains priority
#include <uprobes.h.gen>

// uprobes.h.gen on systems with DTrace, is auto-generated to include
// `LANGUAGE_PROBE_{PROBE}` and `LANGUAGE_PROBE_{PROBE}_ENABLED()` macros for every probe
// defined in uprobes.d
//
// If the arguments to `LANGUAGE_PROBE_{PROBE}` are expensive to compute, the call to
// these functions must be guarded by a LANGUAGE_PROBE_{PROBE}_ENABLED() check, to
// minimize performance impact when probing is off. As an example:
//
//    if (LANGUAGE_PROBE_GC_STOP_THE_WORLD_ENABLED())
//        LANGUAGE_PROBE_GC_STOP_THE_WORLD();

#else
// define a dummy version of the probe functions
#define LANGUAGE_PROBE_GC_BEGIN(collection) do ; while (0)
#define LANGUAGE_PROBE_GC_STOP_THE_WORLD() do ; while (0)
#define LANGUAGE_PROBE_GC_MARK_BEGIN() do ; while (0)
#define LANGUAGE_PROBE_GC_MARK_END(scanned_bytes, perm_scanned_bytes) do ; while (0)
#define LANGUAGE_PROBE_GC_SWEEP_BEGIN(full) do ; while (0)
#define LANGUAGE_PROBE_GC_SWEEP_END() do ; while (0)
#define LANGUAGE_PROBE_GC_END() do ; while (0)
#define LANGUAGE_PROBE_GC_FINALIZER() do ; while (0)
#define LANGUAGE_PROBE_RT_RUN_TASK(task) do ; while (0)
#define LANGUAGE_PROBE_RT_PAUSE_TASK(task) do ; while (0)
#define LANGUAGE_PROBE_RT_NEW_TASK(parent, child) do ; while (0)
#define LANGUAGE_PROBE_RT_START_TASK(task) do ; while (0)
#define LANGUAGE_PROBE_RT_FINISH_TASK(task) do ; while (0)
#define LANGUAGE_PROBE_RT_START_PROCESS_EVENTS(task) do ; while (0)
#define LANGUAGE_PROBE_RT_FINISH_PROCESS_EVENTS(task) do ; while (0)
#define LANGUAGE_PROBE_RT_TASKQ_INSERT(ptls, task) do ; while (0)
#define LANGUAGE_PROBE_RT_TASKQ_GET(ptls, task) do ; while (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_WAKE(other, old_state) do ; while (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_WAKEUP(ptls) do ; while (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_SLEEP(ptls) do ; while (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_TASKQ_WAKE(ptls) do ; while (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_TASK_WAKE(ptls) do ; while (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_UV_WAKE(ptls) do ; while (0)

#define LANGUAGE_PROBE_GC_BEGIN_ENABLED() (0)
#define LANGUAGE_PROBE_GC_STOP_THE_WORLD_ENABLED() (0)
#define LANGUAGE_PROBE_GC_MARK_BEGIN_ENABLED() (0)
#define LANGUAGE_PROBE_GC_MARK_END_ENABLED() (0)
#define LANGUAGE_PROBE_GC_SWEEP_BEGIN_ENABLED() (0)
#define LANGUAGE_PROBE_GC_SWEEP_END_ENABLED()  (0)
#define LANGUAGE_PROBE_GC_END_ENABLED() (0)
#define LANGUAGE_PROBE_GC_FINALIZER_ENABLED() (0)
#define LANGUAGE_PROBE_RT_RUN_TASK_ENABLED() (0)
#define LANGUAGE_PROBE_RT_PAUSE_TASK_ENABLED() (0)
#define LANGUAGE_PROBE_RT_NEW_TASK_ENABLED() (0)
#define LANGUAGE_PROBE_RT_START_TASK_ENABLED() (0)
#define LANGUAGE_PROBE_RT_FINISH_TASK_ENABLED() (0)
#define LANGUAGE_PROBE_RT_START_PROCESS_EVENTS_ENABLED() (0)
#define LANGUAGE_PROBE_RT_FINISH_PROCESS_EVENTS_ENABLED() (0)
#define LANGUAGE_PROBE_RT_TASKQ_INSERT_ENABLED() (0)
#define LANGUAGE_PROBE_RT_TASKQ_GET_ENABLED() (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_WAKE_ENABLED() (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_WAKEUP_ENABLED() (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_SLEEP_ENABLED() (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_TASKQ_WAKE_ENABLED() (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_TASK_WAKE_ENABLED() (0)
#define LANGUAGE_PROBE_RT_SLEEP_CHECK_UV_WAKE_ENABLED() (0)
#endif

#endif
