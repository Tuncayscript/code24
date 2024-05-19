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

// Windows
// Note that this file is `#include`d by "signal-handling.c"
#include <mmsystem.h> // hidden by LEAN_AND_MEAN

static const size_t sig_stack_size = 131072; // 128k reserved for backtrace_fiber for stack overflow handling

// Copied from MINGW_FLOAT_H which may not be found due to a collision with the builtin gcc float.h
// eventually we can probably integrate this into OpenLibm.
#if defined(_COMPILER_GCC_)
void __cdecl __MINGW_NOTHROW _fpreset (void);
void __cdecl __MINGW_NOTHROW fpreset (void);
#else
void __cdecl _fpreset (void);
void __cdecl fpreset (void);
#endif
#define _FPE_INVALID        0x81
#define _FPE_DENORMAL       0x82
#define _FPE_ZERODIVIDE     0x83
#define _FPE_OVERFLOW       0x84
#define _FPE_UNDERFLOW      0x85
#define _FPE_INEXACT        0x86
#define _FPE_UNEMULATED     0x87
#define _FPE_SQRTNEG        0x88
#define _FPE_STACKOVERFLOW  0x8a
#define _FPE_STACKUNDERFLOW 0x8b
#define _FPE_EXPLICITGEN    0x8c    /* raise( SIGFPE ); */

static char *strsignal(int sig)
{
    switch (sig) {
    case SIGINT:         return "SIGINT"; break;
    case SIGILL:         return "SIGILL"; break;
    case SIGABRT_COMPAT: return "SIGABRT_COMPAT"; break;
    case SIGFPE:         return "SIGFPE"; break;
    case SIGSEGV:        return "SIGSEGV"; break;
    case SIGTERM:        return "SIGTERM"; break;
    case SIGBREAK:       return "SIGBREAK"; break;
    case SIGABRT:        return "SIGABRT"; break;
    }
    return "?";
}

static void language_try_throw_sigint(void)
{
    language_task_t *ct = language_current_task;
    language_safepoint_enable_sigint();
    language_wake_libuv();
    int force = language_check_force_sigint();
    if (force || (!ct->ptls->defer_signal && ct->ptls->io_wait)) {
        language_safepoint_consume_sigint();
        if (force)
            language_safe_printf("WARNING: Force throwing a SIGINT\n");
        // Force a throw
        language_clear_force_sigint();
        language_throw(language_interrupt_exception);
    }
}

void __cdecl crt_sig_handler(int sig, int num)
{
    CONTEXT Context;
    switch (sig) {
    case SIGFPE:
        fpreset();
        signal(SIGFPE, (void (__cdecl *)(int))crt_sig_handler);
        switch(num) {
        case _FPE_INVALID:
        case _FPE_OVERFLOW:
        case _FPE_UNDERFLOW:
        default:
            language_errorf("Unexpected FPE Error 0x%X", num);
            break;
        case _FPE_ZERODIVIDE:
            language_throw(language_diverror_exception);
            break;
        }
        break;
    case SIGINT:
        signal(SIGINT, (void (__cdecl *)(int))crt_sig_handler);
        if (!language_ignore_sigint()) {
            if (exit_on_sigint)
                language_exit(130); // 128 + SIGINT
            language_try_throw_sigint();
        }
        break;
    default: // SIGSEGV, SIGTERM, SIGILL, SIGABRT
        if (sig == SIGSEGV && language_get_safe_restore()) {
            signal(sig, (void (__cdecl *)(int))crt_sig_handler);
            language_sig_throw();
        }
        memset(&Context, 0, sizeof(Context));
        RtlCaptureContext(&Context);
        if (sig == SIGILL)
            language_show_sigill(&Context);
        language_critical_error(sig, 0, &Context, language_get_current_task());
        raise(sig);
    }
}

// StackOverflowException needs extra stack space to record the backtrace
// so we keep one around, shared by all threads
static uv_mutex_t backtrace_lock;
static win32_ucontext_t collect_backtrace_fiber;
static win32_ucontext_t error_return_fiber;
static PCONTEXT stkerror_ctx;
static language_ptls_t stkerror_ptls;
static int have_backtrace_fiber;
static void LANGUAGE_NORETURN start_backtrace_fiber(void)
{
    // collect the backtrace
    stkerror_ptls->bt_size =
        rec_backtrace_ctx(stkerror_ptls->bt_data, LANGUAGE_MAX_BT_SIZE, stkerror_ctx,
                          NULL /*current_task?*/);
    // switch back to the execution fiber
    language_setcontext(&error_return_fiber);
    abort();
}

void restore_signals(void)
{
    // turn on ctrl-c handler
    SetConsoleCtrlHandler(NULL, 0);
}

void language_throw_in_ctx(language_task_t *ct, language_value_t *excpt, PCONTEXT ctxThread)
{
#if defined(_CPU_X86_64_)
    DWORD64 Rsp = (ctxThread->Rsp & (DWORD64)-16) - 8;
#elif defined(_CPU_X86_)
    DWORD32 Esp = (ctxThread->Esp & (DWORD32)-16) - 4;
#else
#error WIN16 not supported :P
#endif
    if (ct && !language_get_safe_restore()) {
        assert(excpt != NULL);
        language_ptls_t ptls = ct->ptls;
        ptls->bt_size = 0;
        if (excpt != language_stackovf_exception) {
            ptls->bt_size = rec_backtrace_ctx(ptls->bt_data, LANGUAGE_MAX_BT_SIZE, ctxThread,
                                              ct->gcstack);
        }
        else if (have_backtrace_fiber) {
            uv_mutex_lock(&backtrace_lock);
            stkerror_ctx = ctxThread;
            stkerror_ptls = ptls;
            language_swapcontext(&error_return_fiber, &collect_backtrace_fiber);
            uv_mutex_unlock(&backtrace_lock);
        }
        ptls->sig_exception = excpt;
    }
#if defined(_CPU_X86_64_)
    *(DWORD64*)Rsp = 0;
    ctxThread->Rsp = Rsp;
    ctxThread->Rip = (DWORD64)&language_sig_throw;
#elif defined(_CPU_X86_)
    *(DWORD32*)Esp = 0;
    ctxThread->Esp = Esp;
    ctxThread->Eip = (DWORD)&language_sig_throw;
#endif
}

HANDLE hMainThread = INVALID_HANDLE_VALUE;

// Try to throw the exception in the master thread.
static void language_try_deliver_sigint(void)
{
    language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[0];
    language_lock_profile();
    language_safepoint_enable_sigint();
    language_wake_libuv();
    if ((DWORD)-1 == SuspendThread(hMainThread)) {
        // error
        language_safe_printf("error: SuspendThread failed\n");
        language_unlock_profile();
        return;
    }
    language_unlock_profile();
    int force = language_check_force_sigint();
    if (force || (!ptls2->defer_signal && ptls2->io_wait)) {
        language_safepoint_consume_sigint();
        if (force)
            language_safe_printf("WARNING: Force throwing a SIGINT\n");
        // Force a throw
        language_clear_force_sigint();
        CONTEXT ctxThread;
        memset(&ctxThread, 0, sizeof(CONTEXT));
        ctxThread.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
        if (!GetThreadContext(hMainThread, &ctxThread)) {
            // error
            language_safe_printf("error: GetThreadContext failed\n");
            return;
        }
        language_task_t *ct = language_atomic_load_relaxed(&ptls2->current_task);
        language_throw_in_ctx(ct, language_interrupt_exception, &ctxThread);
        ctxThread.ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
        if (!SetThreadContext(hMainThread, &ctxThread)) {
            language_safe_printf("error: SetThreadContext failed\n");
            // error
            return;
        }
    }
    if ((DWORD)-1 == ResumeThread(hMainThread)) {
        language_safe_printf("error: ResumeThread failed\n");
        // error
        return;
    }
}

static BOOL WINAPI sigint_handler(DWORD wsig) //This needs winapi types to guarantee __stdcall
{
    int sig;
    //windows signals use different numbers from unix (raise)
    switch(wsig) {
        case CTRL_C_EVENT: sig = SIGINT; break;
        //case CTRL_BREAK_EVENT: sig = SIGTERM; break;
        // etc.
        default: sig = SIGTERM; break;
    }
    if (!language_ignore_sigint()) {
        if (exit_on_sigint)
            language_exit(128 + sig); // 128 + SIGINT
        language_try_deliver_sigint();
    }
    return 1;
}

LONG WINAPI language_exception_handler(struct _EXCEPTION_POINTERS *ExceptionInfo)
{
    if (ExceptionInfo->ExceptionRecord->ExceptionFlags != 0)
        return EXCEPTION_CONTINUE_SEARCH;
    language_task_t *ct = language_get_current_task();
    if (ct != NULL && ct->ptls != NULL && ct->ptls->gc_state != LANGUAGE_GC_STATE_WAITING) {
        language_ptls_t ptls = ct->ptls;
        switch (ExceptionInfo->ExceptionRecord->ExceptionCode) {
        case EXCEPTION_INT_DIVIDE_BY_ZERO:
            if (ct->eh != NULL) {
                fpreset();
                language_throw_in_ctx(ct, language_diverror_exception, ExceptionInfo->ContextRecord);
                return EXCEPTION_CONTINUE_EXECUTION;
            }
            break;
        case EXCEPTION_STACK_OVERFLOW:
            if (ct->eh != NULL) {
                ptls->needs_resetstkoflw = 1;
                language_throw_in_ctx(ct, language_stackovf_exception, ExceptionInfo->ContextRecord);
                return EXCEPTION_CONTINUE_EXECUTION;
            }
            break;
        case EXCEPTION_ACCESS_VIOLATION:
            if (language_addr_is_safepoint(ExceptionInfo->ExceptionRecord->ExceptionInformation[1])) {
                language_set_gc_and_wait();
                // Do not raise sigint on worker thread
                if (ptls->tid != 0)
                    return EXCEPTION_CONTINUE_EXECUTION;
                if (ptls->defer_signal) {
                    language_safepoint_defer_sigint();
                }
                else if (language_safepoint_consume_sigint()) {
                    language_clear_force_sigint();
                    language_throw_in_ctx(ct, language_interrupt_exception, ExceptionInfo->ContextRecord);
                }
                return EXCEPTION_CONTINUE_EXECUTION;
            }
            if (language_get_safe_restore()) {
                language_throw_in_ctx(NULL, NULL, ExceptionInfo->ContextRecord);
                return EXCEPTION_CONTINUE_EXECUTION;
            }
            if (ct->eh != NULL) {
                if (ExceptionInfo->ExceptionRecord->ExceptionInformation[0] == 1) { // writing to read-only memory (e.g. mmap)
                    language_throw_in_ctx(ct, language_readonlymemory_exception, ExceptionInfo->ContextRecord);
                    return EXCEPTION_CONTINUE_EXECUTION;
                }
            }
        default:
            break;
        }
    }
    if (ExceptionInfo->ExceptionRecord->ExceptionCode == EXCEPTION_ILLEGAL_INSTRUCTION) {
        language_safe_printf("\n");
        language_show_sigill(ExceptionInfo->ContextRecord);
    }
    language_safe_printf("\nPlease submit a bug report with steps to reproduce this fault, and any error messages that follow (in their entirety). Thanks.\nException: ");
    switch (ExceptionInfo->ExceptionRecord->ExceptionCode) {
    case EXCEPTION_ACCESS_VIOLATION:
        language_safe_printf("EXCEPTION_ACCESS_VIOLATION"); break;
    case EXCEPTION_ARRAY_BOUNDS_EXCEEDED:
        language_safe_printf("EXCEPTION_ARRAY_BOUNDS_EXCEEDED"); break;
    case EXCEPTION_BREAKPOINT:
        language_safe_printf("EXCEPTION_BREAKPOINT"); break;
    case EXCEPTION_DATATYPE_MISALIGNMENT:
        language_safe_printf("EXCEPTION_DATATYPE_MISALIGNMENT"); break;
    case EXCEPTION_FLT_DENORMAL_OPERAND:
        language_safe_printf("EXCEPTION_FLT_DENORMAL_OPERAND"); break;
    case EXCEPTION_FLT_DIVIDE_BY_ZERO:
        language_safe_printf("EXCEPTION_FLT_DIVIDE_BY_ZERO"); break;
    case EXCEPTION_FLT_INEXACT_RESULT:
        language_safe_printf("EXCEPTION_FLT_INEXACT_RESULT"); break;
    case EXCEPTION_FLT_INVALID_OPERATION:
        language_safe_printf("EXCEPTION_FLT_INVALID_OPERATION"); break;
    case EXCEPTION_FLT_OVERFLOW:
        language_safe_printf("EXCEPTION_FLT_OVERFLOW"); break;
    case EXCEPTION_FLT_STACK_CHECK:
        language_safe_printf("EXCEPTION_FLT_STACK_CHECK"); break;
    case EXCEPTION_FLT_UNDERFLOW:
        language_safe_printf("EXCEPTION_FLT_UNDERFLOW"); break;
    case EXCEPTION_ILLEGAL_INSTRUCTION:
        language_safe_printf("EXCEPTION_ILLEGAL_INSTRUCTION"); break;
    case EXCEPTION_IN_PAGE_ERROR:
        language_safe_printf("EXCEPTION_IN_PAGE_ERROR"); break;
    case EXCEPTION_INT_DIVIDE_BY_ZERO:
        language_safe_printf("EXCEPTION_INT_DIVIDE_BY_ZERO"); break;
    case EXCEPTION_INT_OVERFLOW:
        language_safe_printf("EXCEPTION_INT_OVERFLOW"); break;
    case EXCEPTION_INVALID_DISPOSITION:
        language_safe_printf("EXCEPTION_INVALID_DISPOSITION"); break;
    case EXCEPTION_NONCONTINUABLE_EXCEPTION:
        language_safe_printf("EXCEPTION_NONCONTINUABLE_EXCEPTION"); break;
    case EXCEPTION_PRIV_INSTRUCTION:
        language_safe_printf("EXCEPTION_PRIV_INSTRUCTION"); break;
    case EXCEPTION_SINGLE_STEP:
        language_safe_printf("EXCEPTION_SINGLE_STEP"); break;
    case EXCEPTION_STACK_OVERFLOW:
        language_safe_printf("EXCEPTION_STACK_OVERFLOW"); break;
    default:
        language_safe_printf("UNKNOWN"); break;
    }
    language_safe_printf(" at 0x%Ix -- ", (size_t)ExceptionInfo->ExceptionRecord->ExceptionAddress);
    language_print_native_codeloc((uintptr_t)ExceptionInfo->ExceptionRecord->ExceptionAddress);

    language_critical_error(0, 0, ExceptionInfo->ContextRecord, ct);
    static int recursion = 0;
    if (recursion++)
        exit(1);
    else
        language_exit(1);
}

LANGUAGE_DLLEXPORT void language_install_sigint_handler(void)
{
    SetConsoleCtrlHandler((PHANDLER_ROUTINE)sigint_handler,1);
}

static volatile HANDLE hBtThread = 0;

int language_thread_suspend_and_get_state(int tid, int timeout, bt_context_t *ctx)
{
    (void)timeout;
    language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[tid];
    if (ptls2 == NULL) // this thread is not alive
        return 0;
    language_task_t *ct2 = language_atomic_load_relaxed(&ptls2->current_task);
    if (ct2 == NULL) // this thread is already dead
        return 0;
    HANDLE hThread = ptls2->system_id;
    if ((DWORD)-1 == SuspendThread(hThread))
        return 0;
    assert(sizeof(*ctx) == sizeof(CONTEXT));
    memset(ctx, 0, sizeof(CONTEXT));
    ctx->ContextFlags = CONTEXT_CONTROL | CONTEXT_INTEGER;
    if (!GetThreadContext(hThread, ctx)) {
        if ((DWORD)-1 == ResumeThread(hThread))
            abort();
        return 0;
    }
    return 1;
}

void language_thread_resume(int tid)
{
    language_ptls_t ptls2 = language_atomic_load_relaxed(&language_all_tls_states)[tid];
    HANDLE hThread = ptls2->system_id;
    if ((DWORD)-1 == ResumeThread(hThread)) {
        fputs("failed to resume main thread! aborting.", stderr);
        abort();
    }
}

int language_lock_stackwalk(void)
{
    uv_mutex_lock(&language_in_stackwalk);
    language_lock_profile();
    return 0;
}

void language_unlock_stackwalk(int lockret)
{
    (void)lockret;
    language_unlock_profile();
    uv_mutex_unlock(&language_in_stackwalk);
}


static DWORD WINAPI profile_bt( LPVOID lparam )
{
    // Note: illegal to use code_* functions from this thread except for profiling-specific functions
    while (1) {
        DWORD timeout_ms = nsecprof / (GIGA / 1000);
        Sleep(timeout_ms > 0 ? timeout_ms : 1);
        if (running) {
            if (language_profile_is_buffer_full()) {
                language_profile_stop_timer(); // does not change the thread state
                SuspendThread(GetCurrentThread());
                continue;
            }
            else {
                // TODO: bring this up to parity with other OS by adding loop over tid here
                int lockret = language_lock_stackwalk();
                CONTEXT ctxThread;
                if (!language_thread_suspend_and_get_state(0, 0, &ctxThread)) {
                    language_unlock_stackwalk(lockret);
                    fputs("failed to suspend main thread. aborting profiling.", stderr);
                    language_profile_stop_timer();
                    break;
                }
                // Get backtrace data
                bt_size_cur += rec_backtrace_ctx((language_bt_element_t*)bt_data_prof + bt_size_cur,
                        bt_size_max - bt_size_cur - 1, &ctxThread, NULL);

                language_ptls_t ptls = language_atomic_load_relaxed(&language_all_tls_states)[0]; // given only profiling hMainThread

                // store threadid but add 1 as 0 is preserved to indicate end of block
                bt_data_prof[bt_size_cur++].uintptr = ptls->tid + 1;

                // store task id (never null)
                bt_data_prof[bt_size_cur++].jlvalue = (language_value_t*)language_atomic_load_relaxed(&ptls->current_task);

                // store cpu cycle clock
                bt_data_prof[bt_size_cur++].uintptr = cycleclock();

                // store whether thread is sleeping but add 1 as 0 is preserved to indicate end of block
                bt_data_prof[bt_size_cur++].uintptr = language_atomic_load_relaxed(&ptls->sleep_check_state) + 1;

                // Mark the end of this block with two 0's
                bt_data_prof[bt_size_cur++].uintptr = 0;
                bt_data_prof[bt_size_cur++].uintptr = 0;
                language_unlock_stackwalk(lockret);
                language_thread_resume(0);
                language_check_profile_autostop();
            }
        }
    }
    uv_mutex_unlock(&language_in_stackwalk);
    language_profile_stop_timer();
    hBtThread = NULL;
    return 0;
}

static volatile TIMECAPS timecaps;

LANGUAGE_DLLEXPORT int language_profile_start_timer(void)
{
    if (hBtThread == NULL) {

        TIMECAPS _timecaps;
        if (MMSYSERR_NOERROR != timeGetDevCaps(&_timecaps, sizeof(_timecaps))) {
            fputs("failed to get timer resolution", stderr);
            return -2;
        }
        timecaps = _timecaps;

        hBtThread = CreateThread(
            NULL,                   // default security attributes
            0,                      // use default stack size
            profile_bt,             // thread function name
            0,                      // argument to thread function
            0,                      // use default creation flags
            0);                     // returns the thread identifier
        if (hBtThread == NULL)
            return -1;
        (void)SetThreadPriority(hBtThread, THREAD_PRIORITY_ABOVE_NORMAL);
    }
    else {
        if ((DWORD)-1 == ResumeThread(hBtThread)) {
            fputs("failed to resume profiling thread.", stderr);
            return -2;
        }
    }
    if (running == 0) {
        // Failure to change the timer resolution is not fatal. However, it is important to
        // ensure that the timeBeginPeriod/timeEndPeriod is paired.
        if (TIMERR_NOERROR != timeBeginPeriod(timecaps.wPeriodMin))
            timecaps.wPeriodMin = 0;
    }
    running = 1; // set `running` finally
    return 0;
}
LANGUAGE_DLLEXPORT void language_profile_stop_timer(void)
{
    if (running && timecaps.wPeriodMin)
        timeEndPeriod(timecaps.wPeriodMin);
    running = 0;
}

void language_install_default_signal_handlers(void)
{
    if (signal(SIGFPE, (void (__cdecl *)(int))crt_sig_handler) == SIG_ERR) {
        language_error("fatal error: Couldn't set SIGFPE");
    }
    if (signal(SIGILL, (void (__cdecl *)(int))crt_sig_handler) == SIG_ERR) {
        language_error("fatal error: Couldn't set SIGILL");
    }
    if (signal(SIGINT, (void (__cdecl *)(int))crt_sig_handler) == SIG_ERR) {
        language_error("fatal error: Couldn't set SIGINT");
    }
    if (signal(SIGSEGV, (void (__cdecl *)(int))crt_sig_handler) == SIG_ERR) {
        language_error("fatal error: Couldn't set SIGSEGV");
    }
    if (signal(SIGTERM, (void (__cdecl *)(int))crt_sig_handler) == SIG_ERR) {
        language_error("fatal error: Couldn't set SIGTERM");
    }
    if (signal(SIGABRT, (void (__cdecl *)(int))crt_sig_handler) == SIG_ERR) {
        language_error("fatal error: Couldn't set SIGABRT");
    }
    SetUnhandledExceptionFilter(language_exception_handler);
}

void language_install_thread_signal_handler(language_ptls_t ptls)
{
    if (!have_backtrace_fiber) {
        size_t ssize = sig_stack_size;
        void *stk = language_malloc_stack(&ssize, NULL);
        if (stk == NULL)
            language_errorf("fatal error allocating signal stack: mmap: %s", strerror(errno));
        collect_backtrace_fiber.uc_stack.ss_sp = (void*)stk;
        collect_backtrace_fiber.uc_stack.ss_size = ssize;
        language_makecontext(&collect_backtrace_fiber, start_backtrace_fiber);
        uv_mutex_init(&backtrace_lock);
        have_backtrace_fiber = 1;
    }
}
