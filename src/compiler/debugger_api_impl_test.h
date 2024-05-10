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

#ifndef RUNTIME_VM_DEBUGGER_API_IMPL_TEST_H_
#define RUNTIME_VM_DEBUGGER_API_IMPL_TEST_H_

#include "include/CODE_api.h"
#include "src/debugger.h"

namespace Code {

typedef struct _CODE_Breakpoint* CODE_Breakpoint;

typedef struct _CODE_StackTrace* CODE_StackTrace;

typedef struct _CODE_ActivationFrame* CODE_ActivationFrame;

/**
 * An id used to uniquely represent an Isolate in the debugger wire protocol
 * messages.
 */
typedef CODE_Port CODE_IsolateId;

/**
 * ILLEGAL_ISOLATE_ID is a number guaranteed never to be associated with a
 * valid isolate.
 */
#define ILLEGAL_ISOLATE_ID ILLEGAL_PORT

/**
 * Null value for breakpoint id. Guaranteed never to be associated
 * with a valid breakpoint.
 */
#define ILLEGAL_BREAKPOINT_ID 0

typedef void CODE_ExceptionThrownHandler(CODE_IsolateId isolate_id,
                                         CODE_Handle exception_object,
                                         CODE_StackTrace stack_trace);

typedef enum {
  kCreated = 0,
  kInterrupted,
  kShutdown,
} CODE_IsolateEvent;

/**
 * Represents a location in Dart code.
 */
typedef struct {
  CODE_Handle script_url;  // Url (string) of the script.
  int32_t library_id;      // Library in which the script is loaded.
  int32_t token_pos;       // Code address.
} CODE_CodeLocation;

typedef void CODE_IsolateEventHandler(CODE_IsolateId isolate_id,
                                      CODE_IsolateEvent kind);

typedef void CODE_PausedEventHandler(CODE_IsolateId isolate_id,
                                     intptr_t bp_id,
                                     const CODE_CodeLocation& location);

typedef void CODE_BreakpointResolvedHandler(CODE_IsolateId isolate_id,
                                            intptr_t bp_id,
                                            const CODE_CodeLocation& location);

/**
 * Returns true if the debugger can step into code of the given library.
 *
 * Requires there to be a current isolate.
 *
 * \return A handle to the True object if no error occurs.
 */
CODE_Handle CODE_GetLibraryDebuggable(intptr_t library_id, bool* is_debuggable);

/**
 * Requests that debugging be enabled for the given library.
 *
 * Requires there to be a current isolate.
 *
 * \return A handle to the True object if no error occurs.
 */
CODE_Handle CODE_SetLibraryDebuggable(intptr_t library_id, bool is_debuggable);

/**
 * Remove breakpoint with provided id.
 *
 * Requires there to be a current isolate.
 */
CODE_Handle CODE_RemoveBreakpoint(CODE_Handle breakpoint_id);
/**
 * Sets a breakpoint at line \line_number in \script_url, or the closest
 * following line (within the same function) where a breakpoint can be set.
 *
 * Requires there to be a current isolate.
 *
 * \return A handle containing the breakpoint id, which is an integer
 * value, or an error object if a breakpoint could not be set.
 */
CODE_Handle CODE_SetBreakpoint(CODE_Handle script_url, intptr_t line_number);

/**
 * Returns in \trace the current stack trace, or nullptr if the
 * VM is not paused.
 *
 * Requires there to be a current isolate.
 *
 * \return A valid handle if no error occurs during the operation.
 */
CODE_Handle CODE_GetStackTrace(CODE_StackTrace* trace);

/**
 * Returns in \trace the stack trace associated with the error given in \handle.
 *
 * Requires there to be a current isolate.
 *
 * \return A valid handle if no error occurs during the operation.
 */
CODE_Handle CODE_GetStackTraceFromError(CODE_Handle error,
                                        CODE_StackTrace* trace);

/**
 * Returns in \length the number of activation frames in the given
 * stack trace.
 *
 * Requires there to be a current isolate.
 *
 * \return A handle to the True object if no error occurs.
 */
CODE_Handle CODE_StackTraceLength(CODE_StackTrace trace, intptr_t* length);

/**
 * Returns in \frame the activation frame with index \frame_index.
 * The activation frame at the top of stack has index 0.
 *
 * Requires there to be a current isolate.
 *
 * \return A handle to the True object if no error occurs.
 */
CODE_Handle CODE_GetActivationFrame(CODE_StackTrace trace,
                                    int frame_index,
                                    CODE_ActivationFrame* frame);

/**
 * Returns information about the given activation frame.
 * \function_name receives a string handle with the qualified
 *    function name.
 * \script_url receives a string handle with the url of the
 *    source script that contains the frame's function.
 * \line_number receives the line number in the script.
 * \col_number receives the column number in the script, or -1 if column
 *    information is not available
 *
 * Any or all of the out parameters above may be nullptr.
 *
 * Requires there to be a current isolate.
 *
 * \return A valid handle if no error occurs during the operation.
 */
CODE_Handle CODE_ActivationFrameInfo(CODE_ActivationFrame activation_frame,
                                     CODE_Handle* function_name,
                                     CODE_Handle* script_url,
                                     intptr_t* line_number,
                                     intptr_t* column_number);

/**
 * Execute the expression given in string \expr in the context
 * of \lib_handle library, as if it were a top-level function in it.
 *
 * Requires there to be a current isolate.
 *
 * \return A handle to the computed value, or an error object if
 * the compilation of the expression fails, or if the evaluation throws
 * an error.
 */
CODE_Handle CODE_EvaluateStaticExpr(CODE_Handle lib_handle, CODE_Handle expr);

/**
 * Returns in \library_id the library id of the given \library.
 *
 * \return A valid handle if no error occurs during the operation.
 */
CODE_Handle CODE_LibraryId(CODE_Handle library, intptr_t* library_id);

}  // namespace dart

#endif  // RUNTIME_VM_DEBUGGER_API_IMPL_TEST_H_
