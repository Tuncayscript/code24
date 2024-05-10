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

#include <include/CODE_api.h>
#include "include/CODE_tools_api.h"

#include "src/class_finalizer.h"
#include "src/compiler/jit/compiler.h"
#include "src/CODE_api_impl.h"
#include "src/CODE_api_state.h"
#include "src/debugger.h"
#include "src/debugger_api_impl_test.h"
#include "src/isolate.h"
#include "src/object_store.h"
#include "src/symbols.h"

namespace Code {

// Facilitate quick access to the current zone once we have the current thread.
#define Z (T->zone())

#ifndef PRODUCT

#define UNWRAP_AND_CHECK_PARAM(type, var, param)                               \
  type& var = type::Handle();                                                  \
  do {                                                                         \
    const Object& tmp = Object::Handle(Api::UnwrapHandle(param));              \
    if (tmp.IsNull()) {                                                        \
      return Api::NewError("%s expects argument '%s' to be non-null.",         \
                           CURRENT_FUNC, #param);                              \
    } else if (tmp.IsApiError()) {                                             \
      return param;                                                            \
    } else if (!tmp.Is##type()) {                                              \
      return Api::NewError("%s expects argument '%s' to be of type %s.",       \
                           CURRENT_FUNC, #param, #type);                       \
    }                                                                          \
    var ^= tmp.ptr();                                                          \
  } while (0)

#define CHECK_AND_CAST(type, var, param)                                       \
  type* var = nullptr;                                                         \
  do {                                                                         \
    if (param == nullptr) {                                                    \
      return Api::NewError("%s expects argument '%s' to be non-null.",         \
                           CURRENT_FUNC, #param);                              \
    }                                                                          \
    var = reinterpret_cast<type*>(param);                                      \
  } while (0)

#define CHECK_NOT_NULL(param)                                                  \
  if (param == nullptr) {                                                      \
    return Api::NewError("%s expects argument '%s' to be non-null.",           \
                         CURRENT_FUNC, #param);                                \
  }

#define CHECK_DEBUGGER(isolate)                                                \
  if (isolate->debugger() == nullptr) {                                        \
    return Api::NewError("%s requires debugger support.", CURRENT_FUNC);       \
  }

CODE_Handle CODE_StackTraceLength(CODE_StackTrace trace, intptr_t* length) {
  DARTSCOPE(Thread::Current());
  CHECK_NOT_NULL(length);
  CHECK_AND_CAST(DebuggerStackTrace, stack_trace, trace);
  *length = stack_trace->Length();
  return Api::Success();
}

CODE_Handle CODE_GetActivationFrame(CODE_StackTrace trace,
                                    int frame_index,
                                    CODE_ActivationFrame* frame) {
  DARTSCOPE(Thread::Current());
  CHECK_NOT_NULL(frame);
  CHECK_AND_CAST(DebuggerStackTrace, stack_trace, trace);
  if ((frame_index < 0) || (frame_index >= stack_trace->Length())) {
    return Api::NewError("argument 'frame_index' is out of range for %s",
                         CURRENT_FUNC);
  }
  *frame =
      reinterpret_cast<CODE_ActivationFrame>(stack_trace->FrameAt(frame_index));
  return Api::Success();
}

CODE_Handle CODE_GetStackTrace(CODE_StackTrace* trace) {
  DARTSCOPE(Thread::Current());
  Isolate* I = T->isolate();
  CHECK_DEBUGGER(I);
  CHECK_NOT_NULL(trace);
  *trace = reinterpret_cast<CODE_StackTrace>(DebuggerStackTrace::Collect());
  return Api::Success();
}

CODE_Handle CODE_GetStackTraceFromError(CODE_Handle handle,
                                        CODE_StackTrace* trace) {
  DARTSCOPE(Thread::Current());
  CHECK_DEBUGGER(T->isolate());
  CHECK_NOT_NULL(trace);
  const Object& obj = Object::Handle(Z, Api::UnwrapHandle(handle));
  if (obj.IsUnhandledException()) {
    const UnhandledException& error = UnhandledException::Cast(obj);
    StackTrace& CODE_stacktrace = StackTrace::Handle(Z);
    CODE_stacktrace ^= error.stacktrace();
    if (CODE_stacktrace.IsNull()) {
      *trace = nullptr;
    } else {
      *trace = reinterpret_cast<CODE_StackTrace>(
          DebuggerStackTrace::From(CODE_stacktrace));
    }
    return Api::Success();
  } else {
    return Api::NewError(
        "Can only get stacktraces from error handles or "
        "instances of Error.");
  }
}

CODE_Handle CODE_ActivationFrameInfo(CODE_ActivationFrame activation_frame,
                                     CODE_Handle* function_name,
                                     CODE_Handle* script_url,
                                     intptr_t* line_number,
                                     intptr_t* column_number) {
  DARTSCOPE(Thread::Current());
  CHECK_AND_CAST(ActivationFrame, frame, activation_frame);
  if (function_name != nullptr) {
    *function_name = Api::NewHandle(T, frame->QualifiedFunctionName());
  }
  if (script_url != nullptr) {
    *script_url = Api::NewHandle(T, frame->SourceUrl());
  }
  if (line_number != nullptr) {
    *line_number = frame->LineNumber();
  }
  if (column_number != nullptr) {
    *column_number = frame->ColumnNumber();
  }
  return Api::Success();
}

CODE_Handle CODE_SetBreakpoint(CODE_Handle script_url_in,
                               intptr_t line_number) {
  Breakpoint* bpt;
  {
    DARTSCOPE(Thread::Current());
    Isolate* I = T->isolate();
    CHECK_DEBUGGER(I);
    UNWRAP_AND_CHECK_PARAM(String, script_url, script_url_in);

    Debugger* debugger = I->debugger();
    bpt = debugger->SetBreakpointAtLineCol(script_url, line_number, -1);
    if (bpt == nullptr) {
      return Api::NewError("%s: could not set breakpoint at line %" Pd
                           " in '%s'",
                           CURRENT_FUNC, line_number, script_url.ToCString());
    }
  }
  return CODE_NewInteger(bpt->id());
}

CODE_Handle CODE_RemoveBreakpoint(CODE_Handle breakpoint_id_in) {
  DARTSCOPE(Thread::Current());
  Isolate* I = T->isolate();
  CHECK_DEBUGGER(I);
  UNWRAP_AND_CHECK_PARAM(Integer, breakpoint_id, breakpoint_id_in);
  I->debugger()->RemoveBreakpoint(breakpoint_id.AsInt64Value());
  return Api::Success();
}

CODE_Handle CODE_EvaluateStaticExpr(CODE_Handle lib_handle,
                                    CODE_Handle expr_in) {
  DARTSCOPE(Thread::Current());
  CHECK_DEBUGGER(T->isolate());

  const Object& target = Object::Handle(Z, Api::UnwrapHandle(lib_handle));
  if (target.IsError()) return lib_handle;
  if (target.IsNull()) {
    return Api::NewError("%s expects argument 'target' to be non-null",
                         CURRENT_FUNC);
  }
  const Library& lib = Library::Cast(target);
  UNWRAP_AND_CHECK_PARAM(String, expr, expr_in);

  if (!KernelIsolate::IsRunning()) {
    UNREACHABLE();
  } else {
    CODE_KernelCompilationResult compilation_result =
        KernelIsolate::CompileExpressionToKernel(
            /* platform_kernel= */ nullptr, /* platform_kernel_size= */ 0,
            expr.ToCString(),
            /* definitions= */ Array::empty_array(),
            /* definition_types= */ Array::empty_array(),
            /* type_definitions= */ Array::empty_array(),
            /* type_bounds= */ Array::empty_array(),
            /* type_defaults= */ Array::empty_array(),
            String::Handle(lib.url()).ToCString(),
            /* klass= */ nullptr,
            /* method= */ nullptr,
            /* token_pos= */ TokenPosition::kNoSource,
            /* script_uri= */ String::Handle(lib.url()).ToCString(),
            /* is_static= */ true);
    if (compilation_result.status != CODE_KernelCompilationStatus_Ok) {
      return Api::NewError("Failed to compile expression.");
    }

    const ExternalTypedData& kernel_buffer =
        ExternalTypedData::Handle(ExternalTypedData::NewFinalizeWithFree(
            const_cast<uint8_t*>(compilation_result.kernel),
            compilation_result.kernel_size));

    CODE_Handle result = Api::NewHandle(
        T,
        lib.EvaluateCompiledExpression(kernel_buffer,
                                       /* type_definitions= */
                                       Array::empty_array(),
                                       /* param_values= */
                                       Array::empty_array(),
                                       /* type_param_values= */
                                       TypeArguments::null_type_arguments()));
    return result;
  }
}

CODE_Handle CODE_LibraryId(CODE_Handle library, intptr_t* library_id) {
  DARTSCOPE(Thread::Current());
  const Library& lib = Api::UnwrapLibraryHandle(Z, library);
  if (lib.IsNull()) {
    RETURN_TYPE_ERROR(Z, library, Library);
  }
  if (library_id == nullptr) {
    RETURN_NULL_ERROR(library_id);
  }
  *library_id = lib.index();
  return Api::Success();
}

CODE_Handle CODE_GetLibraryDebuggable(intptr_t library_id,
                                      bool* is_debuggable) {
  DARTSCOPE(Thread::Current());
  CHECK_NOT_NULL(is_debuggable);
  const Library& lib = Library::Handle(Library::GetLibrary(library_id));
  if (lib.IsNull()) {
    return Api::NewError("%s: %" Pd " is not a valid library id", CURRENT_FUNC,
                         library_id);
  }
  *is_debuggable = lib.IsDebuggable();
  return Api::Success();
}

CODE_Handle CODE_SetLibraryDebuggable(intptr_t library_id, bool is_debuggable) {
  DARTSCOPE(Thread::Current());
  const Library& lib = Library::Handle(Z, Library::GetLibrary(library_id));
  if (lib.IsNull()) {
    return Api::NewError("%s: %" Pd " is not a valid library id", CURRENT_FUNC,
                         library_id);
  }
  lib.set_debuggable(is_debuggable);
  return Api::Success();
}

#endif  // !PRODUCT

}  // namespace dart
