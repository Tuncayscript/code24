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

/*
  stackwalk.c
  utilities for walking the stack and looking up information about code addresses
*/
#include <inttypes.h>
#include "code.h"
#include "language_internal.h"
#include "threading.h"
#include "language_assert.h"

// define `language_unw_get` as a macro, since (like setjmp)
// returning from the callee function will invalidate the context
#ifdef _OS_WINDOWS_
uv_mutex_t language_in_stackwalk;
#define language_unw_get(context) (RtlCaptureContext(context), 0)
#elif !defined(LANGUAGE_DISABLE_LIBUNWIND)
#define language_unw_get(context) unw_getcontext(context)
#else
int language_unw_get(void *context) { return -1; }
#endif

#ifdef __cplusplus
extern "C" {
#endif

static int language_unw_init(bt_cursor_t *cursor, bt_context_t *context) LANGUAGE_NOTSAFEPOINT;
static int language_unw_step(bt_cursor_t *cursor, int from_signal_handler, uintptr_t *ip, uintptr_t *sp) LANGUAGE_NOTSAFEPOINT;

static language_gcframe_t *is_enter_interpreter_frame(language_gcframe_t **ppgcstack, uintptr_t sp) LANGUAGE_NOTSAFEPOINT
{
    language_gcframe_t *pgcstack = *ppgcstack;
    while (pgcstack != NULL) {
        language_gcframe_t *prev = pgcstack->prev;
        if (pgcstack->nroots & 2) { // tagged frame
            uintptr_t frame_fp = ((uintptr_t*)pgcstack)[-1];
            if (frame_fp != 0) { // check that frame was fully initialized
                if (frame_fp >= sp)
                    break; // stack grows down, so frame pointer is monotonically increasing
                *ppgcstack = prev;
                return pgcstack;
            }
        }
        *ppgcstack = pgcstack = prev;
    }
    return NULL;
}


// Record backtrace entries into bt_data by stepping cursor with language_unw_step
// until the outermost frame is encountered or the buffer bt_data is (close to)
// full. Returned instruction pointers are adjusted to point to the address of
// the call instruction. The first `skip` frames are not included in `bt_data`.
//
// `maxsize` is the size of the buffer `bt_data` (and `sp` if non-NULL). It
// must be at least `LANGUAGE_BT_MAX_ENTRY_SIZE + 1` to accommodate extended backtrace
// entries.  If `sp != NULL`, the stack pointer corresponding `bt_data[i]` is
// stored in `sp[i]`.
//
// `*ppgcstack` should be given if you want to record extended backtrace
// entries in `bt_data` for each julia interpreter frame.
//
// Flag `from_signal_handler==1` should be set if the cursor was obtained by
// asynchronously interrupting the code.
//
// language_unw_stepn will return 1 if there are more frames to come. The number of
// elements written to bt_data (and sp if non-NULL) are returned in bt_size.
static int language_unw_stepn(bt_cursor_t *cursor, language_bt_element_t *bt_data, size_t *bt_size,
                        uintptr_t *sp, size_t maxsize, int skip, language_gcframe_t **ppgcstack,
                        int from_signal_handler) LANGUAGE_NOTSAFEPOINT
{
    volatile size_t n = 0;
    volatile int need_more_space = 0;
    uintptr_t return_ip = 0;
    uintptr_t thesp = 0;
#if defined(_OS_WINDOWS_) && !defined(_CPU_X86_64_)
    uv_mutex_lock(&language_in_stackwalk);
    if (!from_signal_handler) {
        // Workaround 32-bit windows bug missing top frame
        // See for example https://bugs.chromium.org/p/crashpad/issues/detail?id=53
        skip--;
    }
#endif
#if !defined(_OS_WINDOWS_)
    language_jmp_buf *old_buf = language_get_safe_restore();
    language_jmp_buf buf;
    language_set_safe_restore(&buf);
    if (!language_setjmp(buf, 0)) {
#endif
        int have_more_frames = 1;
        while (have_more_frames) {
            if (n + LANGUAGE_BT_MAX_ENTRY_SIZE + 1 > maxsize) {
                // Postpone advancing the cursor: may need more space
                need_more_space = 1;
                break;
            }
            uintptr_t oldsp = thesp;
            have_more_frames = language_unw_step(cursor, from_signal_handler, &return_ip, &thesp);
            if (oldsp >= thesp && !language_running_under_rr(0)) {
                // The stack pointer is clearly bad, as it must grow downwards.
                // But sometimes the external unwinder doesn't check that.
                have_more_frames = 0;
            }
            if (return_ip == 0) {
                // The return address is clearly wrong, and while the unwinder
                // might try to continue (by popping another stack frame), that
                // likely won't work well, and it'll confuse the stack frame
                // separator detection logic (double-NULL).
                have_more_frames = 0;
            }
            if (skip > 0) {
                skip--;
                from_signal_handler = 0;
                continue;
            }
            // For the purposes of looking up debug info for functions, we want
            // to harvest addresses for the *call* instruction `call_ip` during
            // stack walking.  However, this information isn't directly
            // available. Instead, the stack walk discovers the address
            // `return_ip` which would be *returned to* as the stack is
            // unwound.
            //
            // To infer `call_ip` in full generality we need to understand each
            // platform ABI instruction pointer encoding and calling
            // conventions, noting that the latter may vary per stack frame.
            //
            // See also:
            // * The LLVM unwinder functions step() and setInfoBasedOnIPRegister()
            //   https://github.com/llvm/llvm-project/blob/master/libunwind/src/UnwindCursor.hpp
            // * The way that libunwind handles it in `unw_get_proc_name`:
            //   https://lists.nongnu.org/archive/html/libunwind-devel/2014-06/msg00025.html
            uintptr_t call_ip = return_ip;
            // ARM instruction pointer encoding uses the low bit as a flag for
            // thumb mode, which must be cleared before further use. (Note not
            // needed for ARM AArch64.) See
            // https://github.com/libunwind/libunwind/pull/131
            #ifdef _CPU_ARM_
            call_ip &= ~(uintptr_t)0x1;
            #endif
            // Now there's two main cases to adjust for:
            // * Normal stack frames where compilers emit a `call` instruction
            //   which we can get from the return address via `call_ip = return_ip - 1`.
            // * Code which was interrupted asynchronously (eg, via a signal)
            //   is expected to have `call_ip == return_ip`.
            if (!from_signal_handler)
                call_ip -= 1; // normal frame
            from_signal_handler = 0;
            if (call_ip == LANGUAGE_BT_NON_PTR_ENTRY || call_ip == 0) {
                // Never leave special marker in the bt data as it can corrupt the GC.
                have_more_frames = 0;
                call_ip = 0;
            }
            language_bt_element_t *bt_entry = bt_data + n;
            language_gcframe_t *pgcstack;
            if ((pgcstack = is_enter_interpreter_frame(ppgcstack, thesp))) {
                size_t add = language_capture_interp_frame(bt_entry, (void*)((char*)pgcstack - sizeof(void*)), maxsize - n);
                n += add;
                bt_entry += add;
                while ((pgcstack = is_enter_interpreter_frame(ppgcstack, thesp))) {
                    // If the compiler got inlining-happy, or the user tried to
                    // push multiple frames (or the unwinder got very
                    // confused), we could end up here. That doesn't happen
                    // now, so just ignore this possibility. If we want this,
                    // we can work on adding support for it later.
                }
            }
            bt_entry->uintptr = call_ip;
            if (sp)
                sp[n] = thesp;
            n++;
        }
        // NOTE: if we have some pgcstack entries remaining (because the
        // unwinder failed and returned !have_more_frames early), we could
        // consider still appending those frames here
#if !defined(_OS_WINDOWS_)
    }
    else {
        // The unwinding fails likely because a invalid memory read.
        // Back off one frame since it is likely invalid.
        // This seems to be good enough on x86 to make the LLVM debug info
        // reader happy.
        if (n > 0) n -= 1;
    }
    language_set_safe_restore(old_buf);
#endif
#if defined(_OS_WINDOWS_) && !defined(_CPU_X86_64_)
    uv_mutex_unlock(&language_in_stackwalk);
#endif
    *bt_size = n;
    return need_more_space;
}

NOINLINE size_t rec_backtrace_ctx(language_bt_element_t *bt_data, size_t maxsize,
                                  bt_context_t *context, language_gcframe_t *pgcstack) LANGUAGE_NOTSAFEPOINT
{
    bt_cursor_t cursor;
    if (!language_unw_init(&cursor, context))
        return 0;
    size_t bt_size = 0;
    language_unw_stepn(&cursor, bt_data, &bt_size, NULL, maxsize, 0, &pgcstack, 1);
    return bt_size;
}

// Record backtrace into buffer `bt_data`, using a maximum of `maxsize`
// elements, and returning the number of elements written.
//
// The first `skip` frames are omitted, in addition to omitting the frame from
// `rec_backtrace` itself.
NOINLINE size_t rec_backtrace(language_bt_element_t *bt_data, size_t maxsize, int skip)
{
    bt_context_t context;
    memset(&context, 0, sizeof(context));
    int r = language_unw_get(&context);
    if (r < 0)
        return 0;
    bt_cursor_t cursor;
    if (!language_unw_init(&cursor, &context) || maxsize == 0)
        return 0;
    language_gcframe_t *pgcstack = language_pgcstack;
    size_t bt_size = 0;
    language_unw_stepn(&cursor, bt_data, &bt_size, NULL, maxsize, skip + 1, &pgcstack, 0);
    return bt_size;
}

static language_value_t *array_ptr_void_type LANGUAGE_ALWAYS_LEAFTYPE = NULL;
// Return backtrace information as an svec of (bt1, bt2, [sp])
//
// The stack pointers `sp` are returned only when `returnsp` evaluates to true.
// bt1 contains raw backtrace entries, while bt2 exists to root any julia
// objects associated with the entries in bt1.
//
// The frame from language_backtrace_from_here will be skipped; set `skip > 0` to
// skip additional native frames from the start of the backtrace.
LANGUAGE_DLLEXPORT language_value_t *language_backtrace_from_here(int returnsp, int skip)
{
    language_array_t *ip = NULL;
    language_array_t *sp = NULL;
    language_array_t *bt2 = NULL;
    LANGUAGE_GC_PUSH3(&ip, &sp, &bt2);
    if (array_ptr_void_type == NULL) {
        array_ptr_void_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_voidpointer_type, language_box_long(1));
    }
    ip = language_alloc_array_1d(array_ptr_void_type, 0);
    sp = returnsp ? language_alloc_array_1d(array_ptr_void_type, 0) : NULL;
    bt2 = language_alloc_array_1d(language_array_any_type, 0);
    const size_t maxincr = 1000;
    bt_context_t context;
    bt_cursor_t cursor;
    memset(&context, 0, sizeof(context));
    int r = language_unw_get(&context);
    language_gcframe_t *pgcstack = language_pgcstack;
    if (r == 0 && language_unw_init(&cursor, &context)) {
        // Skip frame for language_backtrace_from_here itself
        skip += 1;
        size_t offset = 0;
        int have_more_frames = 1;
        while (have_more_frames) {
            language_array_grow_end(ip, maxincr);
            uintptr_t *sp_ptr = NULL;
            if (returnsp) {
                language_array_grow_end(sp, maxincr);
                sp_ptr = language_array_data(sp, uintptr_t) + offset;
            }
            size_t size_incr = 0;
            have_more_frames = language_unw_stepn(&cursor, language_array_data(ip, language_bt_element_t) + offset,
                                            &size_incr, sp_ptr, maxincr, skip, &pgcstack, 0);
            skip = 0;
            offset += size_incr;
        }
        language_array_del_end(ip, language_array_nrows(ip) - offset);
        if (returnsp)
            language_array_del_end(sp, language_array_nrows(sp) - offset);

        size_t n = 0;
        language_bt_element_t *bt_data = language_array_data(ip, language_bt_element_t);
        while (n < language_array_nrows(ip)) {
            language_bt_element_t *bt_entry = bt_data + n;
            if (!language_bt_is_native(bt_entry)) {
                size_t njlvals = language_bt_num_jlvals(bt_entry);
                for (size_t j = 0; j < njlvals; j++) {
                    language_value_t *v = language_bt_entry_jlvalue(bt_entry, j);
                    LANGUAGE_GC_PROMISE_ROOTED(v);
                    language_array_ptr_1d_push(bt2, v);
                }
            }
            n += language_bt_entry_size(bt_entry);
        }
    }
    language_value_t *bt = returnsp ? (language_value_t*)language_svec(3, ip, bt2, sp) : (language_value_t*)language_svec(2, ip, bt2);
    LANGUAGE_GC_POP();
    return bt;
}

static void decode_backtrace(language_bt_element_t *bt_data, size_t bt_size,
                             language_array_t **btout LANGUAGE_REQUIRE_ROOTED_SLOT,
                             language_array_t **bt2out LANGUAGE_REQUIRE_ROOTED_SLOT)
{
    language_array_t *bt, *bt2;
    if (array_ptr_void_type == NULL) {
        array_ptr_void_type = language_apply_type2((language_value_t*)language_array_type, (language_value_t*)language_voidpointer_type, language_box_long(1));
    }
    bt = *btout = language_alloc_array_1d(array_ptr_void_type, bt_size);
    static_assert(sizeof(language_bt_element_t) == sizeof(void*),
                  "language_bt_element_t is presented as Ptr{Cvoid} on julia side");
    memcpy(language_array_data(bt, language_bt_element_t), bt_data, bt_size * sizeof(language_bt_element_t));
    bt2 = *bt2out = language_alloc_array_1d(language_array_any_type, 0);
    // Scan the backtrace buffer for any gc-managed values
    for (size_t i = 0; i < bt_size; i += language_bt_entry_size(bt_data + i)) {
        language_bt_element_t* bt_entry = bt_data + i;
        if (language_bt_is_native(bt_entry))
            continue;
        size_t njlvals = language_bt_num_jlvals(bt_entry);
        for (size_t j = 0; j < njlvals; j++) {
            language_value_t *v = language_bt_entry_jlvalue(bt_entry, j);
            LANGUAGE_GC_PROMISE_ROOTED(v);
            language_array_ptr_1d_push(bt2, v);
        }
    }
}

LANGUAGE_DLLEXPORT language_value_t *language_get_backtrace(void)
{
    LANGUAGE_TIMING(STACKWALK, STACKWALK_Backtrace);
    language_excstack_t *s = language_current_task->excstack;
    language_bt_element_t *bt_data = NULL;
    size_t bt_size = 0;
    if (s && s->top) {
        bt_data = language_excstack_bt_data(s, s->top);
        bt_size = language_excstack_bt_size(s, s->top);
    }
    language_array_t *bt = NULL, *bt2 = NULL;
    LANGUAGE_GC_PUSH2(&bt, &bt2);
    decode_backtrace(bt_data, bt_size, &bt, &bt2);
    language_svec_t *pair = language_svec2(bt, bt2);
    LANGUAGE_GC_POP();
    return (language_value_t*)pair;
}

// Return data from the exception stack for `task` as an array of Any, starting
// with the top of the stack and returning up to `max_entries`. If requested by
// setting the `include_bt` flag, backtrace data in bt,bt2 format is
// interleaved.
LANGUAGE_DLLEXPORT language_value_t *language_get_excstack(language_task_t* task, int include_bt, int max_entries)
{
    LANGUAGE_TYPECHK(current_exceptions, task, (language_value_t*)task);
    LANGUAGE_TIMING(STACKWALK, STACKWALK_Excstack);
    language_task_t *ct = language_current_task;
    if (task != ct && language_atomic_load_relaxed(&task->_state) == LANGUAGE_TASK_STATE_RUNNABLE) {
        language_error("Inspecting the exception stack of a task which might "
                 "be running concurrently isn't allowed.");
    }
    language_array_t *stack = NULL;
    language_array_t *bt = NULL;
    language_array_t *bt2 = NULL;
    LANGUAGE_GC_PUSH3(&stack, &bt, &bt2);
    stack = language_alloc_array_1d(language_array_any_type, 0);
    language_excstack_t *excstack = task->excstack;
    size_t itr = excstack ? excstack->top : 0;
    int i = 0;
    while (itr > 0 && i < max_entries) {
        language_array_ptr_1d_push(stack, language_excstack_exception(excstack, itr));
        if (include_bt) {
            decode_backtrace(language_excstack_bt_data(excstack, itr),
                             language_excstack_bt_size(excstack, itr),
                             &bt, &bt2);
            language_array_ptr_1d_push(stack, (language_value_t*)bt);
            language_array_ptr_1d_push(stack, (language_value_t*)bt2);
        }
        itr = language_excstack_next(excstack, itr);
        i++;
    }
    LANGUAGE_GC_POP();
    return (language_value_t*)stack;
}

#if defined(_OS_WINDOWS_)
// XXX: these caches should be per-thread
#ifdef _CPU_X86_64_
static UNWIND_HISTORY_TABLE HistoryTable;
#else
static struct {
    DWORD64 dwAddr;
    DWORD64 ImageBase;
} HistoryTable;
#endif
static PVOID CALLBACK JuliaFunctionTableAccess64(
        _In_  HANDLE hProcess,
        _In_  DWORD64 AddrBase)
{
    //language_printf(LANGUAGE_STDOUT, "lookup %d\n", AddrBase);
#ifdef _CPU_X86_64_
    DWORD64 ImageBase;
    PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(AddrBase, &ImageBase, &HistoryTable);
    if (fn)
        return fn;
    uv_mutex_lock(&language_in_stackwalk);
    PVOID ftable = SymFunctionTableAccess64(hProcess, AddrBase);
    uv_mutex_unlock(&language_in_stackwalk);
    return ftable;
#else
    return SymFunctionTableAccess64(hProcess, AddrBase);
#endif
}
static DWORD64 WINAPI JuliaGetModuleBase64(
        _In_  HANDLE hProcess,
        _In_  DWORD64 dwAddr)
{
    //language_printf(LANGUAGE_STDOUT, "lookup base %d\n", dwAddr);
#ifdef _CPU_X86_64_
    DWORD64 ImageBase;
    PRUNTIME_FUNCTION fn = RtlLookupFunctionEntry(dwAddr, &ImageBase, &HistoryTable);
    if (fn)
        return ImageBase;
    uv_mutex_lock(&language_in_stackwalk);
    DWORD64 fbase = SymGetModuleBase64(hProcess, dwAddr);
    uv_mutex_unlock(&language_in_stackwalk);
    return fbase;
#else
    if (dwAddr == HistoryTable.dwAddr)
        return HistoryTable.ImageBase;
    DWORD64 ImageBase = language_getUnwindInfo(dwAddr);
    if (ImageBase) {
        HistoryTable.dwAddr = dwAddr;
        HistoryTable.ImageBase = ImageBase;
        return ImageBase;
    }
    return SymGetModuleBase64(hProcess, dwAddr);
#endif
}

// Might be called from unmanaged thread.
volatile int needsSymRefreshModuleList;
BOOL (WINAPI *hSymRefreshModuleList)(HANDLE);

LANGUAGE_DLLEXPORT void language_refresh_dbg_module_list(void)
{
    if (needsSymRefreshModuleList && hSymRefreshModuleList != NULL) {
        hSymRefreshModuleList(GetCurrentProcess());
        needsSymRefreshModuleList = 0;
    }
}
static int language_unw_init(bt_cursor_t *cursor, bt_context_t *Context)
{
    int result;
    uv_mutex_lock(&language_in_stackwalk);
    language_refresh_dbg_module_list();
#if !defined(_CPU_X86_64_)
    memset(&cursor->stackframe, 0, sizeof(cursor->stackframe));
    cursor->stackframe.AddrPC.Offset = Context->Eip;
    cursor->stackframe.AddrStack.Offset = Context->Esp;
    cursor->stackframe.AddrFrame.Offset = Context->Ebp;
    cursor->stackframe.AddrPC.Mode = AddrModeFlat;
    cursor->stackframe.AddrStack.Mode = AddrModeFlat;
    cursor->stackframe.AddrFrame.Mode = AddrModeFlat;
    cursor->context = *Context;
    result = StackWalk64(IMAGE_FILE_MACHINE_I386, GetCurrentProcess(), hMainThread,
            &cursor->stackframe, &cursor->context, NULL, JuliaFunctionTableAccess64,
            JuliaGetModuleBase64, NULL);
#else
    *cursor = *Context;
    result = 1;
#endif
    uv_mutex_unlock(&language_in_stackwalk);
    return result;
}

static int readable_pointer(LPCVOID pointer)
{
    // Check whether the pointer is valid and executable before dereferencing
    // to avoid segfault while recording. See #10638.
    MEMORY_BASIC_INFORMATION mInfo;
    if (VirtualQuery(pointer, &mInfo, sizeof(MEMORY_BASIC_INFORMATION)) == 0)
        return 0;
    DWORD X = mInfo.AllocationProtect;
    if (!((X&PAGE_READONLY) || (X&PAGE_READWRITE) || (X&PAGE_WRITECOPY) || (X&PAGE_EXECUTE_READ)) ||
          (X&PAGE_GUARD) || (X&PAGE_NOACCESS))
        return 0;
    return 1;
}

static int language_unw_step(bt_cursor_t *cursor, int from_signal_handler, uintptr_t *ip, uintptr_t *sp)
{
    // Might be called from unmanaged thread.
#ifndef _CPU_X86_64_
    *ip = (uintptr_t)cursor->stackframe.AddrPC.Offset;
    *sp = (uintptr_t)cursor->stackframe.AddrStack.Offset;
    if (*ip == 0) {
        if (!readable_pointer((LPCVOID)*sp))
            return 0;
        cursor->stackframe.AddrPC.Offset = *(DWORD32*)*sp;      // POP EIP (aka RET)
        cursor->stackframe.AddrStack.Offset += sizeof(void*);
        return cursor->stackframe.AddrPC.Offset != 0;
    }

    BOOL result = StackWalk64(IMAGE_FILE_MACHINE_I386, GetCurrentProcess(), hMainThread,
        &cursor->stackframe, &cursor->context, NULL, JuliaFunctionTableAccess64, JuliaGetModuleBase64, NULL);
    return result;
#else
    *ip = (uintptr_t)cursor->Rip;
    *sp = (uintptr_t)cursor->Rsp;
    if (*ip == 0 && from_signal_handler) {
        if (!readable_pointer((LPCVOID)*sp))
            return 0;
        cursor->Rip = *(DWORD64*)*sp;      // POP RIP (aka RET)
        cursor->Rsp += sizeof(void*);
        return cursor->Rip != 0;
    }

    DWORD64 ImageBase = JuliaGetModuleBase64(GetCurrentProcess(), cursor->Rip - !from_signal_handler);
    if (!ImageBase)
        return 0;

    PRUNTIME_FUNCTION FunctionEntry = (PRUNTIME_FUNCTION)JuliaFunctionTableAccess64(
        GetCurrentProcess(), cursor->Rip - !from_signal_handler);
    if (!FunctionEntry) {
        // Not code or bad unwind?
        return 0;
    }
    else {
        PVOID HandlerData;
        DWORD64 EstablisherFrame;
        (void)RtlVirtualUnwind(
                0 /*UNW_FLAG_NHANDLER*/,
                ImageBase,
                cursor->Rip,
                FunctionEntry,
                cursor,
                &HandlerData,
                &EstablisherFrame,
                NULL);
    }
    return cursor->Rip != 0;
#endif
}

#elif !defined(LANGUAGE_DISABLE_LIBUNWIND)
// stacktrace using libunwind

static int language_unw_init(bt_cursor_t *cursor, bt_context_t *context)
{
    return unw_init_local(cursor, context) == 0;
}

static int language_unw_step(bt_cursor_t *cursor, int from_signal_handler, uintptr_t *ip, uintptr_t *sp)
{
    (void)from_signal_handler; // libunwind also tracks this
    unw_word_t reg;
    if (unw_get_reg(cursor, UNW_REG_IP, &reg) < 0)
        return 0;
    *ip = reg;
    if (unw_get_reg(cursor, UNW_REG_SP, &reg) < 0)
        return 0;
    *sp = reg;
    return unw_step(cursor) > 0;
}

#ifdef LLVMLIBUNWIND
NOINLINE size_t rec_backtrace_ctx_dwarf(language_bt_element_t *bt_data, size_t maxsize,
                                        bt_context_t *context, language_gcframe_t *pgcstack)
{
    size_t bt_size = 0;
    bt_cursor_t cursor;
    if (unw_init_local_dwarf(&cursor, context) != UNW_ESUCCESS)
        return 0;
    language_unw_stepn(&cursor, bt_data, &bt_size, NULL, maxsize, 0, &pgcstack, 1);
    return bt_size;
}
#endif

#else
// stacktraces are disabled
static int language_unw_init(bt_cursor_t *cursor, bt_context_t *context)
{
    return 0;
}

static int language_unw_step(bt_cursor_t *cursor, int from_signal_handler, uintptr_t *ip, uintptr_t *sp)
{
    return 0;
}
#endif

LANGUAGE_DLLEXPORT language_value_t *language_lookup_code_address(void *ip, int skipC)
{
    language_task_t *ct = language_current_task;
    language_frame_t *frames = NULL;
    int8_t gc_state = language_gc_safe_enter(ct->ptls);
    int n = language_getFunctionInfo(&frames, (uintptr_t)ip, skipC, 0);
    language_gc_safe_leave(ct->ptls, gc_state);
    language_value_t *rs = (language_value_t*)language_alloc_svec(n);
    LANGUAGE_GC_PUSH1(&rs);
    for (int i = 0; i < n; i++) {
        language_frame_t frame = frames[i];
        language_value_t *r = (language_value_t*)language_alloc_svec(6);
        language_svecset(rs, i, r);
        if (frame.func_name)
            language_svecset(r, 0, language_symbol(frame.func_name));
        else
            language_svecset(r, 0, language_empty_sym);
        free(frame.func_name);
        if (frame.file_name)
            language_svecset(r, 1, language_symbol(frame.file_name));
        else
            language_svecset(r, 1, language_empty_sym);
        free(frame.file_name);
        language_svecset(r, 2, language_box_long(frame.line));
        language_svecset(r, 3, frame.linfo != NULL ? (language_value_t*)frame.linfo : language_nothing);
        language_svecset(r, 4, language_box_bool(frame.fromC));
        language_svecset(r, 5, language_box_bool(frame.inlined));
    }
    free(frames);
    LANGUAGE_GC_POP();
    return rs;
}

static void language_safe_print_codeloc(const char* func_name, const char* file_name,
                                  int line, int inlined) LANGUAGE_NOTSAFEPOINT
{
    const char *inlined_str = inlined ? " [inlined]" : "";
    if (line != -1) {
        language_safe_printf("%s at %s:%d%s\n", func_name, file_name, line, inlined_str);
    }
    else {
        language_safe_printf("%s at %s (unknown line)%s\n", func_name, file_name, inlined_str);
    }
}

// Print function, file and line containing native instruction pointer `ip` by
// looking up debug info. Prints multiple such frames when `ip` points to
// inlined code.
void language_print_native_codeloc(uintptr_t ip) LANGUAGE_NOTSAFEPOINT
{
    // This function is not allowed to reference any TLS variables since
    // it can be called from an unmanaged thread on OSX.
    // it means calling getFunctionInfo with noInline = 1
    language_frame_t *frames = NULL;
    int n = language_getFunctionInfo(&frames, ip, 0, 0);
    int i;

    for (i = 0; i < n; i++) {
        language_frame_t frame = frames[i];
        if (!frame.func_name) {
            language_safe_printf("unknown function (ip: %p)\n", (void*)ip);
        }
        else {
            language_safe_print_codeloc(frame.func_name, frame.file_name, frame.line, frame.inlined);
            free(frame.func_name);
            free(frame.file_name);
        }
    }
    free(frames);
}

const char *language_debuginfo_file1(language_debuginfo_t *debuginfo)
{
    language_value_t *def = debuginfo->def;
    if (language_is_method_instance(def))
        def = ((language_method_instance_t*)def)->def.value;
    if (language_is_method(def))
        def = (language_value_t*)((language_method_t*)def)->file;
    if (language_is_symbol(def))
        return language_symbol_name((language_sym_t*)def);
    return "<unknown>";
}

const char *language_debuginfo_file(language_debuginfo_t *debuginfo)
{
    language_debuginfo_t *linetable = debuginfo->linetable;
    while ((language_value_t*)linetable != language_nothing) {
        debuginfo = linetable;
        linetable = debuginfo->linetable;
    }
    return language_debuginfo_file1(debuginfo);
}

language_module_t *language_debuginfo_module1(language_value_t *debuginfo_def)
{
    if (language_is_method_instance(debuginfo_def))
        debuginfo_def = ((language_method_instance_t*)debuginfo_def)->def.value;
    if (language_is_method(debuginfo_def))
        debuginfo_def = (language_value_t*)((language_method_t*)debuginfo_def)->module;
    if (language_is_module(debuginfo_def))
        return (language_module_t*)debuginfo_def;
    return NULL;
}

const char *language_debuginfo_name(language_value_t *func)
{
    if (func == NULL)
        return "macro expansion";
    if (language_is_method_instance(func))
        func = ((language_method_instance_t*)func)->def.value;
    if (language_is_method(func))
        func = (language_value_t*)((language_method_t*)func)->name;
    if (language_is_symbol(func))
        return language_symbol_name((language_sym_t*)func);
    if (language_is_module(func))
        return "top-level scope";
    return "<unknown>";
}

// func == module : top-level
// func == NULL : macro expansion
static void language_print_debugloc(language_debuginfo_t *debuginfo, language_value_t *func, size_t ip, int inlined) LANGUAGE_NOTSAFEPOINT
{
    if (!language_is_symbol(debuginfo->def)) // this is a path or
        func = debuginfo->def; // this is inlined code
    struct language_codeloc_t stmt = language_uncompress1_codeloc(debuginfo->codelocs, ip);
    intptr_t edges_idx = stmt.to;
    if (edges_idx) {
        language_debuginfo_t *edge = (language_debuginfo_t*)language_svecref(debuginfo->edges, edges_idx - 1);
        assert(language_typetagis(edge, language_debuginfo_type));
        language_print_debugloc(edge, NULL, stmt.pc, 1);
    }
    intptr_t ip2 = stmt.line;
    if (ip2 >= 0 && ip > 0 && (language_value_t*)debuginfo->linetable != language_nothing) {
        language_print_debugloc(debuginfo->linetable, func, ip2, 0);
    }
    else {
        if (ip2 < 0) // set broken debug info to ignored
            ip2 = 0;
        const char *func_name = language_debuginfo_name(func);
        const char *file = language_debuginfo_file(debuginfo);
        language_safe_print_codeloc(func_name, file, ip2, inlined);
    }
}

// Print code location for backtrace buffer entry at *bt_entry
void language_print_bt_entry_codeloc(language_bt_element_t *bt_entry) LANGUAGE_NOTSAFEPOINT
{
    if (language_bt_is_native(bt_entry)) {
        language_print_native_codeloc(bt_entry[0].uintptr);
    }
    else if (language_bt_entry_tag(bt_entry) == LANGUAGE_BT_INTERP_FRAME_TAG) {
        size_t ip = language_bt_entry_header(bt_entry); // zero-indexed
        language_value_t *code = language_bt_entry_jlvalue(bt_entry, 0);
        language_value_t *def = (language_value_t*)language_core_module; // just used as a token here that isa Module
        if (language_is_code_instance(code)) {
            language_code_instance_t *ci = (language_code_instance_t*)code;
            def = (language_value_t*)ci->def;
            code = language_atomic_load_relaxed(&ci->inferred);
        } else if (language_is_method_instance(code)) {
            language_method_instance_t *mi = (language_method_instance_t*)code;
            def = code;
            // When interpreting a method instance, need to unwrap to find the code info
            code = mi->def.method->source;
        }
        if (language_is_code_info(code)) {
            language_code_info_t *src = (language_code_info_t*)code;
            // See also the debug info handling in codegen.cpp.
            language_print_debugloc(src->debuginfo, def, ip + 1, 0);
        }
        else {
            // If we're using this function something bad has already happened;
            // be a bit defensive to avoid crashing while reporting the crash.
            language_safe_printf("No code info - unknown interpreter state!\n");
        }
    }
    else {
        language_safe_printf("Non-native bt entry with tag and header bits 0x%" PRIxPTR "\n",
                       bt_entry[1].uintptr);
    }
}


#ifdef _OS_LINUX_
#if defined(__GLIBC__) && defined(_CPU_AARCH64_)
#define LONG_JMP_SP_ENV_SLOT 13
static uintptr_t language_longjmp_xor_key;
// GLIBC mangles the function pointers in jmp_buf (used in {set,long}*jmp
// functions) by XORing them with a random key.  For AArch64 it is a global
// variable rather than a TCB one (as for x86_64/powerpc).  We obtain the key by
// issuing a setjmp and XORing the SP pointer values to derive the key.
static void JuliaInitializeLongjmpXorKey(void)
{
    // 1. Call REAL(setjmp), which stores the mangled SP in env.
    jmp_buf env;
    _setjmp(env);

    // 2. Retrieve vanilla/mangled SP.
    uintptr_t sp;
    asm("mov  %0, sp" : "=r" (sp));
    uintptr_t mangled_sp = ((uintptr_t*)&env)[LONG_JMP_SP_ENV_SLOT];

    // 3. xor SPs to obtain key.
    language_longjmp_xor_key = mangled_sp ^ sp;
}
#endif

LANGUAGE_UNUSED static uintptr_t ptr_demangle(uintptr_t p) LANGUAGE_NOTSAFEPOINT
{
#if defined(__GLIBC__)
#if defined(_CPU_X86_)
// from https://github.com/bminor/glibc/blame/master/sysdeps/unix/sysv/linux/i386/sysdep.h
// last changed for GLIBC_2.6 on 2007-02-01
    asm(" rorl $9, %0\n"
        " xorl %%gs:0x18, %0"
        : "=r"(p) : "0"(p) : );
#elif defined(_CPU_X86_64_)
// from https://github.com/bminor/glibc/blame/master/sysdeps/unix/sysv/linux/i386/sysdep.h
    asm(" rorq $17, %0\n"
        " xorq %%fs:0x30, %0"
        : "=r"(p) : "0"(p) : );
#elif defined(_CPU_AARCH64_)
// from https://github.com/bminor/glibc/blame/master/sysdeps/unix/sysv/linux/aarch64/sysdep.h
// We need to use a trick like this (from GCC/LLVM TSAN) to get access to it:
// https://github.com/llvm/llvm-project/commit/daa3ebce283a753f280c549cdb103fbb2972f08e
    static pthread_once_t once = PTHREAD_ONCE_INIT;
    pthread_once(&once, &JuliaInitializeLongjmpXorKey);
    p ^= language_longjmp_xor_key;
#elif defined(_CPU_ARM_)
// from https://github.com/bminor/glibc/blame/master/sysdeps/unix/sysv/linux/arm/sysdep.h
    ; // nothing to do
#endif
#endif
    return p;
}
#endif

// n.b. musl does not mangle pointers, but intentionally makes that impossible
// to determine (https://www.openwall.com/lists/musl/2013/03/29/13) so we do
// not support musl here.

// n.b. We have not looked at other libc (e.g. ulibc), though they are probably
// often compatible with glibc (perhaps with or without pointer mangling).


#ifdef _OS_DARWIN_
// from https://github.com/apple/darwin-xnu/blame/main/libsyscall/os/tsd.h
#define __TSD_PTR_MUNGE 7

#if defined(__i386__) || defined(__x86_64__)

#if defined(__has_attribute)
#if __has_attribute(address_space)
#define OS_GS_RELATIVE  __attribute__((address_space(256)))
#endif
#endif

#ifdef OS_GS_RELATIVE
#define _os_tsd_get_base() ((void * OS_GS_RELATIVE *)0)
#else
__attribute__((always_inline))
static __inline__ void*
_os_tsd_get_direct(unsigned long slot)
{
    void *ret;
    __asm__("mov %%gs:%1, %0" : "=r" (ret) : "m" (*(void **)(slot * sizeof(void *))));
    return ret;
}
#endif

#elif defined(__arm__) || defined(__arm64__)
// Unconditionally defined ptrauth_strip (instead of using the ptrauth.h header)
// since libsystem will likely be compiled with -mbranch-protection, and we currently are not.
// code from https://github.com/llvm/llvm-project/blob/7714e0317520207572168388f22012dd9e152e9e/compiler-rt/lib/sanitizer_common/sanitizer_ptrauth.h
static inline uint64_t ptrauth_strip(uint64_t __value, unsigned int __key) LANGUAGE_NOTSAFEPOINT {
  // On the stack the link register is protected with Pointer
  // Authentication Code when compiled with -mbranch-protection.
  // Let's strip the PAC unconditionally because xpaclri is in the NOP space,
  // so will do nothing when it is not enabled or not available.
  uint64_t ret;
  asm volatile(
      "mov x30, %1\n\t"
      "hint #7\n\t"  // xpaclri
      "mov %0, x30\n\t"
      : "=r"(ret)
      : "r"(__value)
      : "x30");
  return ret;
}

__attribute__((always_inline, pure))
static __inline__ void**
_os_tsd_get_base(void) LANGUAGE_NOTSAFEPOINT
{
#if defined(__arm__)
    uintptr_t tsd;
    __asm__("mrc p15, 0, %0, c13, c0, 3\n"
            "bic %0, %0, #0x3\n" : "=r" (tsd));
    /* lower 2-bits contain CPU number */
#elif defined(__arm64__)
    uint64_t tsd;
    __asm__("mrs %0, TPIDRRO_EL0\n"
            "bic %0, %0, #0x7\n" : "=r" (tsd));
    /* lower 3-bits contain CPU number */
#endif

    return (void**)(uintptr_t)tsd;
}
#define _os_tsd_get_base()  _os_tsd_get_base()
#endif

#ifdef _os_tsd_get_base
__attribute__((always_inline))
static __inline__ void*
_os_tsd_get_direct(unsigned long slot) LANGUAGE_NOTSAFEPOINT
{
    return _os_tsd_get_base()[slot];
}
#endif

__attribute__((always_inline, pure))
static __inline__ uintptr_t
_os_ptr_munge_token(void) LANGUAGE_NOTSAFEPOINT
{
    return (uintptr_t)_os_tsd_get_direct(__TSD_PTR_MUNGE);
}

__attribute__((always_inline, pure))
LANGUAGE_UNUSED static __inline__ uintptr_t
_os_ptr_munge(uintptr_t ptr) LANGUAGE_NOTSAFEPOINT
{
    return ptr ^ _os_ptr_munge_token();
}
#define _OS_PTR_UNMUNGE(_ptr) _os_ptr_munge((uintptr_t)(_ptr))
#endif


extern bt_context_t *language_to_bt_context(void *sigctx);

static void language_rec_backtrace(language_task_t *t) LANGUAGE_NOTSAFEPOINT
{
    language_task_t *ct = language_current_task;
    language_ptls_t ptls = ct->ptls;
    ptls->bt_size = 0;
    if (t == ct) {
        ptls->bt_size = rec_backtrace(ptls->bt_data, LANGUAGE_MAX_BT_SIZE, 0);
        return;
    }
    bt_context_t *context = NULL;
    bt_context_t c;
    int16_t old = -1;
    while (!language_atomic_cmpswap(&t->tid, &old, ptls->tid) && old != ptls->tid) {
        int lockret = language_lock_stackwalk();
        // if this task is already running somewhere, we need to stop the thread it is running on and query its state
        if (!language_thread_suspend_and_get_state(old, 0, &c)) {
            language_unlock_stackwalk(lockret);
            return;
        }
        language_unlock_stackwalk(lockret);
        if (language_atomic_load_relaxed(&t->tid) == old) {
            language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[old];
            if (ptls2->previous_task == t || // we might print the wrong stack here, since we can't know whether we executed the swapcontext yet or not, but it at least avoids trying to access the state inside uc_mcontext which might not be set yet
                (ptls2->previous_task == NULL && language_atomic_load_relaxed(&ptls2->current_task) == t)) { // this case should be always accurate
                // use the thread context for the unwind state
                context = &c;
            }
            break;
        }
        // got the wrong thread stopped, try again
        language_thread_resume(old);
    }
    if (context == NULL && (!t->copy_stack && t->started && t->stkbuf != NULL)) {
        // need to read the context from the task stored state
#if defined(_OS_WINDOWS_)
        memset(&c, 0, sizeof(c));
        _JUMP_BUFFER *mctx = (_JUMP_BUFFER*)&t->ctx.ctx.uc_mcontext;
#if defined(_CPU_X86_64_)
        c.Rbx = mctx->Rbx;
        c.Rsp = mctx->Rsp;
        c.Rbp = mctx->Rbp;
        c.Rsi = mctx->Rsi;
        c.Rdi = mctx->Rdi;
        c.R12 = mctx->R12;
        c.R13 = mctx->R13;
        c.R14 = mctx->R14;
        c.R15 = mctx->R15;
        c.Rip = mctx->Rip;
        memcpy(&c.Xmm6, &mctx->Xmm6, 10 * sizeof(mctx->Xmm6)); // Xmm6-Xmm15
#else
        c.Eip = mctx->Eip;
        c.Esp = mctx->Esp;
        c.Ebp = mctx->Ebp;
#endif
        context = &c;
#elif defined(LANGUAGE_HAVE_UNW_CONTEXT)
        context = &t->ctx.ctx;
#elif defined(LANGUAGE_HAVE_UCONTEXT)
        context = language_to_bt_context(&t->ctx.ctx);
#elif defined(LANGUAGE_HAVE_ASM)
        memset(&c, 0, sizeof(c));
     #if defined(_OS_LINUX_) && defined(__GLIBC__)
        __jmp_buf *mctx = &t->ctx.ctx.uc_mcontext->__jmpbuf;
        mcontext_t *mc = &c.uc_mcontext;
      #if defined(_CPU_X86_)
        // https://github.com/bminor/glibc/blame/master/sysdeps/i386/__longjmp.S
        // https://github.com/bminor/glibc/blame/master/sysdeps/i386/jmpbuf-offsets.h
        // https://github.com/bminor/musl/blame/master/src/setjmp/i386/longjmp.s
        mc->gregs[REG_EBX] = (*mctx)[0];
        mc->gregs[REG_ESI] = (*mctx)[1];
        mc->gregs[REG_EDI] = (*mctx)[2];
        mc->gregs[REG_EBP] = (*mctx)[3];
        mc->gregs[REG_ESP] = (*mctx)[4];
        mc->gregs[REG_EIP] = (*mctx)[5];
        // ifdef PTR_DEMANGLE ?
        mc->gregs[REG_ESP] = ptr_demangle(mc->gregs[REG_ESP]);
        mc->gregs[REG_EIP] = ptr_demangle(mc->gregs[REG_EIP]);
        context = &c;
      #elif defined(_CPU_X86_64_)
        // https://github.com/bminor/glibc/blame/master/sysdeps/x86_64/__longjmp.S
        // https://github.com/bminor/glibc/blame/master/sysdeps/x86_64/jmpbuf-offsets.h
        // https://github.com/bminor/musl/blame/master/src/setjmp/x86_64/setjmp.s
        mc->gregs[REG_RBX] = (*mctx)[0];
        mc->gregs[REG_RBP] = (*mctx)[1];
        mc->gregs[REG_R12] = (*mctx)[2];
        mc->gregs[REG_R13] = (*mctx)[3];
        mc->gregs[REG_R14] = (*mctx)[4];
        mc->gregs[REG_R15] = (*mctx)[5];
        mc->gregs[REG_RSP] = (*mctx)[6];
        mc->gregs[REG_RIP] = (*mctx)[7];
        // ifdef PTR_DEMANGLE ?
        mc->gregs[REG_RBP] = ptr_demangle(mc->gregs[REG_RBP]);
        mc->gregs[REG_RSP] = ptr_demangle(mc->gregs[REG_RSP]);
        mc->gregs[REG_RIP] = ptr_demangle(mc->gregs[REG_RIP]);
        context = &c;
      #elif defined(_CPU_ARM_)
        // https://github.com/bminor/glibc/blame/master/sysdeps/arm/__longjmp.S
        // https://github.com/bminor/glibc/blame/master/sysdeps/arm/include/bits/setjmp.h
        // https://github.com/bminor/musl/blame/master/src/setjmp/arm/longjmp.S
        mc->arm_sp = (*mctx)[0];
        mc->arm_lr = (*mctx)[1];
        mc->arm_r4 = (*mctx)[2]; // aka v1
        mc->arm_r5 = (*mctx)[3]; // aka v2
        mc->arm_r6 = (*mctx)[4]; // aka v3
        mc->arm_r7 = (*mctx)[5]; // aka v4
        mc->arm_r8 = (*mctx)[6]; // aka v5
        mc->arm_r9 = (*mctx)[7]; // aka v6 aka sb
        mc->arm_r10 = (*mctx)[8]; // aka v7 aka sl
        mc->arm_fp = (*mctx)[10]; // aka v8 aka r11
        // ifdef PTR_DEMANGLE ?
        mc->arm_sp = ptr_demangle(mc->arm_sp);
        mc->arm_lr = ptr_demangle(mc->arm_lr);
        mc->arm_pc = mc->arm_lr;
        context = &c;
      #elif defined(_CPU_AARCH64_)
        // https://github.com/bminor/glibc/blame/master/sysdeps/aarch64/__longjmp.S
        // https://github.com/bminor/glibc/blame/master/sysdeps/aarch64/jmpbuf-offsets.h
        // https://github.com/bminor/musl/blame/master/src/setjmp/aarch64/longjmp.s
        // https://github.com/libunwind/libunwind/blob/ec171c9ba7ea3abb2a1383cee2988a7abd483a1f/src/aarch64/unwind_i.h#L62
        unw_fpsimd_context_t *mcfp = (unw_fpsimd_context_t*)&mc->__reserved;
        mc->regs[19] = (*mctx)[0];
        mc->regs[20] = (*mctx)[1];
        mc->regs[21] = (*mctx)[2];
        mc->regs[22] = (*mctx)[3];
        mc->regs[23] = (*mctx)[4];
        mc->regs[24] = (*mctx)[5];
        mc->regs[25] = (*mctx)[6];
        mc->regs[26] = (*mctx)[7];
        mc->regs[27] = (*mctx)[8];
        mc->regs[28] = (*mctx)[9];
        mc->regs[29] = (*mctx)[10]; // aka fp
        mc->regs[30] = (*mctx)[11]; // aka lr
        // Yes, they did skip 12 why writing the code originally; and, no, I do not know why.
        mc->sp = (*mctx)[13];
        mcfp->vregs[7] = (*mctx)[14]; // aka d8
        mcfp->vregs[8] = (*mctx)[15]; // aka d9
        mcfp->vregs[9] = (*mctx)[16]; // aka d10
        mcfp->vregs[10] = (*mctx)[17]; // aka d11
        mcfp->vregs[11] = (*mctx)[18]; // aka d12
        mcfp->vregs[12] = (*mctx)[19]; // aka d13
        mcfp->vregs[13] = (*mctx)[20]; // aka d14
        mcfp->vregs[14] = (*mctx)[21]; // aka d15
        // ifdef PTR_DEMANGLE ?
        mc->sp = ptr_demangle(mc->sp);
        mc->regs[30] = ptr_demangle(mc->regs[30]);
        mc->pc = mc->regs[30];
        context = &c;
      #else
       #pragma message("language_rec_backtrace not defined for ASM/SETJMP on unknown linux")
       (void)mc;
       (void)c;
       (void)mctx;
      #endif
     #elif defined(_OS_DARWIN_)
        sigjmp_buf *mctx = &t->ctx.ctx.uc_mcontext;
      #if defined(_CPU_X86_64_)
        // from https://github.com/apple/darwin-libplatform/blob/main/src/setjmp/x86_64/_setjmp.s
        x86_thread_state64_t *mc = (x86_thread_state64_t*)&c;
        mc->__rbx = ((uint64_t*)mctx)[0];
        mc->__rbp = ((uint64_t*)mctx)[1];
        mc->__rsp = ((uint64_t*)mctx)[2];
        mc->__r12 = ((uint64_t*)mctx)[3];
        mc->__r13 = ((uint64_t*)mctx)[4];
        mc->__r14 = ((uint64_t*)mctx)[5];
        mc->__r15 = ((uint64_t*)mctx)[6];
        mc->__rip = ((uint64_t*)mctx)[7];
        // added in libsystem_platform 177.200.16 (macOS Mojave 10.14.3)
        // prior to that _os_ptr_munge_token was (hopefully) typically 0,
        // so x ^ 0 == x and this is a no-op
        mc->__rbp = _OS_PTR_UNMUNGE(mc->__rbp);
        mc->__rsp = _OS_PTR_UNMUNGE(mc->__rsp);
        mc->__rip = _OS_PTR_UNMUNGE(mc->__rip);
        context = &c;
      #elif defined(_CPU_AARCH64_)
        // from https://github.com/apple/darwin-libplatform/blob/main/src/setjmp/arm64/setjmp.s
        // https://github.com/apple/darwin-xnu/blob/main/osfmk/mach/arm/_structs.h
        // https://github.com/llvm/llvm-project/blob/7714e0317520207572168388f22012dd9e152e9e/libunwind/src/Registers.hpp -> Registers_arm64
        arm_thread_state64_t *mc = (arm_thread_state64_t*)&c;
        mc->__x[19] = ((uint64_t*)mctx)[0];
        mc->__x[20] = ((uint64_t*)mctx)[1];
        mc->__x[21] = ((uint64_t*)mctx)[2];
        mc->__x[22] = ((uint64_t*)mctx)[3];
        mc->__x[23] = ((uint64_t*)mctx)[4];
        mc->__x[24] = ((uint64_t*)mctx)[5];
        mc->__x[25] = ((uint64_t*)mctx)[6];
        mc->__x[26] = ((uint64_t*)mctx)[7];
        mc->__x[27] = ((uint64_t*)mctx)[8];
        mc->__x[28] = ((uint64_t*)mctx)[9];
        mc->__x[10] = ((uint64_t*)mctx)[10];
        mc->__x[11] = ((uint64_t*)mctx)[11];
        mc->__x[12] = ((uint64_t*)mctx)[12];
        // 13 is reserved/unused
        double *mcfp = (double*)&mc[1];
        mcfp[7] = ((uint64_t*)mctx)[14]; // aka d8
        mcfp[8] = ((uint64_t*)mctx)[15]; // aka d9
        mcfp[9] = ((uint64_t*)mctx)[16]; // aka d10
        mcfp[10] = ((uint64_t*)mctx)[17]; // aka d11
        mcfp[11] = ((uint64_t*)mctx)[18]; // aka d12
        mcfp[12] = ((uint64_t*)mctx)[19]; // aka d13
        mcfp[13] = ((uint64_t*)mctx)[20]; // aka d14
        mcfp[14] = ((uint64_t*)mctx)[21]; // aka d15
        mc->__fp = _OS_PTR_UNMUNGE(mc->__x[10]);
        mc->__lr = _OS_PTR_UNMUNGE(mc->__x[11]);
        mc->__x[12] = _OS_PTR_UNMUNGE(mc->__x[12]);
        mc->__sp = mc->__x[12];
        // libunwind is broken for signed-pointers, but perhaps best not to leave the signed pointer lying around either
        mc->__pc = ptrauth_strip(mc->__lr, 0);
        mc->__pad = 0; // aka __ra_sign_state = not signed
        context = &c;
      #else
       #pragma message("language_rec_backtrace not defined for ASM/SETJMP on unknown darwin")
        (void)mctx;
        (void)c;
      #endif
     #elif defined(_OS_FREEBSD_) && defined(_CPU_X86_64_)
        sigjmp_buf *mctx = &t->ctx.ctx.uc_mcontext;
        mcontext_t *mc = &c.uc_mcontext;
        // https://github.com/freebsd/freebsd-src/blob/releng/13.1/lib/libc/amd64/gen/_setjmp.S
        mc->mc_rip = ((long*)mctx)[0];
        mc->mc_rbx = ((long*)mctx)[1];
        mc->mc_rsp = ((long*)mctx)[2];
        mc->mc_rbp = ((long*)mctx)[3];
        mc->mc_r12 = ((long*)mctx)[4];
        mc->mc_r13 = ((long*)mctx)[5];
        mc->mc_r14 = ((long*)mctx)[6];
        mc->mc_r15 = ((long*)mctx)[7];
        context = &c;
     #else
      #pragma message("language_rec_backtrace not defined for ASM/SETJMP on unknown system")
      (void)c;
     #endif
#elif defined(LANGUAGE_HAVE_SIGALTSTACK)
     #pragma message("language_rec_backtrace not defined for SIGALTSTACK")
#else
     #pragma message("language_rec_backtrace not defined for unknown task system")
#endif
    }
    if (context)
        ptls->bt_size = rec_backtrace_ctx(ptls->bt_data, LANGUAGE_MAX_BT_SIZE, context,  t->gcstack);
    if (old == -1)
        language_atomic_store_relaxed(&t->tid, old);
    else if (old != ptls->tid)
        language_thread_resume(old);
}

//--------------------------------------------------
// Tools for interactive debugging in gdb

LANGUAGE_DLLEXPORT void language_gdblookup(void* ip)
{
    language_print_native_codeloc((uintptr_t)ip);
}

// Print backtrace for current exception in catch block
LANGUAGE_DLLEXPORT void jlbacktrace(void) LANGUAGE_NOTSAFEPOINT
{
    language_task_t *ct = language_current_task;
    if (ct->ptls == NULL)
        return;
    language_excstack_t *s = ct->excstack;
    if (!s)
        return;
    size_t i, bt_size = language_excstack_bt_size(s, s->top);
    language_bt_element_t *bt_data = language_excstack_bt_data(s, s->top);
    for (i = 0; i < bt_size; i += language_bt_entry_size(bt_data + i)) {
        language_print_bt_entry_codeloc(bt_data + i);
    }
}

// Print backtrace for specified task to language_safe_printf stderr
LANGUAGE_DLLEXPORT void jlbacktracet(language_task_t *t) LANGUAGE_NOTSAFEPOINT
{
    language_task_t *ct = language_current_task;
    language_ptls_t ptls = ct->ptls;
    language_rec_backtrace(t);
    size_t i, bt_size = ptls->bt_size;
    language_bt_element_t *bt_data = ptls->bt_data;
    for (i = 0; i < bt_size; i += language_bt_entry_size(bt_data + i)) {
        language_print_bt_entry_codeloc(bt_data + i);
    }
}

LANGUAGE_DLLEXPORT void language_print_backtrace(void) LANGUAGE_NOTSAFEPOINT
{
    jlbacktrace();
}

extern int gc_first_tid;

// Print backtraces for all live tasks, for all threads, to language_safe_printf stderr
LANGUAGE_DLLEXPORT void language_print_task_backtraces(int show_done) LANGUAGE_NOTSAFEPOINT
{
    size_t nthreads = language_atomic_load_acquire(&language_n_threads);
    language_ptls_t *allstates = language_atomic_load_relaxed(&language_all_tls_states);
    for (size_t i = 0; i < nthreads; i++) {
        // skip GC threads since they don't have tasks
        if (gc_first_tid <= i && i < gc_first_tid + language_n_gcthreads) {
            continue;
        }
        language_ptls_t ptls2 = allstates[i];
        if (ptls2 == NULL) {
            continue;
        }
        small_arraylist_t *live_tasks = &ptls2->heap.live_tasks;
        size_t n = mtarraylist_length(live_tasks);
        int t_state = LANGUAGE_TASK_STATE_DONE;
        language_task_t *t = ptls2->root_task;
        if (t != NULL)
            t_state = language_atomic_load_relaxed(&t->_state);
        language_safe_printf("==== Thread %d created %zu live tasks\n",
                ptls2->tid + 1, n + (t_state != LANGUAGE_TASK_STATE_DONE));
        if (show_done || t_state != LANGUAGE_TASK_STATE_DONE) {
            language_safe_printf("     ---- Root task (%p)\n", ptls2->root_task);
            if (t != NULL) {
                language_safe_printf("          (sticky: %d, started: %d, state: %d, tid: %d)\n",
                        t->sticky, t->started, t_state,
                        language_atomic_load_relaxed(&t->tid) + 1);
                if (t->stkbuf != NULL) {
                    jlbacktracet(t);
                }
                else {
                    language_safe_printf("      no stack\n");
                }
            }
            language_safe_printf("     ---- End root task\n");
        }

        for (size_t j = 0; j < n; j++) {
            language_task_t *t = (language_task_t*)mtarraylist_get(live_tasks, j);
            if (t == NULL)
                continue;
            int t_state = language_atomic_load_relaxed(&t->_state);
            if (!show_done && t_state == LANGUAGE_TASK_STATE_DONE)
                continue;
            language_safe_printf("     ---- Task %zu (%p)\n", j + 1, t);
            // n.b. this information might not be consistent with the stack printing after it, since it could start running or change tid, etc.
            language_safe_printf("          (sticky: %d, started: %d, state: %d, tid: %d)\n",
                    t->sticky, t->started, t_state,
                    language_atomic_load_relaxed(&t->tid) + 1);
            if (t->stkbuf != NULL)
                jlbacktracet(t);
            else
                language_safe_printf("      no stack\n");
            language_safe_printf("     ---- End task %zu\n", j + 1);
        }
        language_safe_printf("==== End thread %d\n", ptls2->tid + 1);
    }
    language_safe_printf("==== Done\n");
}

#ifdef __cplusplus
}
#endif
