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

#include "win32_ucontext.h"

#define WIN32_LEAN_AND_MEAN
#include <windows.h>

#ifdef __cplusplus
extern "C" {
#endif

extern LONG WINAPI language_exception_handler(struct _EXCEPTION_POINTERS *ExceptionInfo);

// Instead of using ntdll!_except_handler4, we call directly to our UnhandledExceptionFilter.
// This seems to work better, since it's unclear if we have made a valid frame
// that meets the expectations of that internal functions.
LANGUAGE_DLLEXPORT EXCEPTION_DISPOSITION NTAPI __language_personality(
        PEXCEPTION_RECORD ExceptionRecord,
        void *EstablisherFrame,
        PCONTEXT ContextRecord,
        void *DispatcherContext)
{
    EXCEPTION_POINTERS ExceptionInfo;
    ExceptionInfo.ExceptionRecord = ExceptionRecord;
    ExceptionInfo.ContextRecord = ContextRecord;

    EXCEPTION_DISPOSITION rval;
    switch (language_exception_handler(&ExceptionInfo)) {
        case EXCEPTION_EXECUTE_HANDLER:
            rval = ExceptionExecuteHandler;
            break;
        case EXCEPTION_CONTINUE_EXECUTION:
            rval = ExceptionContinueExecution;
            break;
        case EXCEPTION_CONTINUE_SEARCH: LANGUAGE_FALLTHROUGH;
        default:
            rval = ExceptionContinueSearch;
            break;
    }

    return rval;
}


void language_makecontext(win32_ucontext_t *ucp, void (*func)(void))
{
    char *stack_top = (char*)ucp->uc_stack.ss_sp + ucp->uc_stack.ss_size;
#if defined(_CPU_X86_64_)
    stack_top -= 0x20; // shadow stack
#elif defined(_CPU_X86_)
    // install unhandled SEH EXCEPTION_REGISTRATION_RECORD at top of stack
    static PEXCEPTION_ROUTINE UnHandler;
    if (UnHandler == NULL) {
        PEXCEPTION_REGISTRATION_RECORD fs0 = (PEXCEPTION_REGISTRATION_RECORD)__readfsdword(0x0);
        while (fs0->Next != (PEXCEPTION_REGISTRATION_RECORD)0xFFFFFFFF)
            fs0 = fs0->Next;
        UnHandler = fs0->Handler;
    }
    stack_top -= 0x20;
    PEXCEPTION_REGISTRATION_RECORD Registration = (PEXCEPTION_REGISTRATION_RECORD)stack_top;
    Registration[0].Next = &Registration[1];
    Registration[0].Handler = &__language_personality;
    Registration[1].Next = (PEXCEPTION_REGISTRATION_RECORD)0xFFFFFFFF;
    Registration[1].Handler = UnHandler;
#endif
    stack_top -= sizeof(void*);
    *(void**)stack_top = 0; // push rta
    stack_top -= sizeof(void*); // stack space for ret
    _JUMP_BUFFER *jmpbuf = (_JUMP_BUFFER*)&ucp->uc_mcontext;
#if defined(_CPU_X86_64_)
    jmpbuf->Rip = (unsigned long long)func;
    jmpbuf->Rsp = (unsigned long long)stack_top;
    jmpbuf->Rbp = 0;
    jmpbuf->Frame = ~(uint64_t)0; // SEH frame
#elif defined(_CPU_X86_)
    jmpbuf->Eip = (unsigned long)func;
    jmpbuf->Esp = (unsigned long)stack_top;
    jmpbuf->Ebp = 0;
    jmpbuf->Registration = (unsigned long)&Registration[0]; // SEH frame
#else
#error language_makecontext not defined for CPU type
#endif
}

#ifdef __cplusplus
}
#endif
