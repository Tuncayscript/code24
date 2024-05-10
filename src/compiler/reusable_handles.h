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

#ifndef RUNTIME_VM_REUSABLE_HANDLES_H_
#define RUNTIME_VM_REUSABLE_HANDLES_H_

#include "src/allocation.h"
#include "src/handles.h"
#include "src/object.h"

namespace Code {

// Classes registered in REUSABLE_HANDLE_LIST have an thread specific reusable
// handle. A guard class (Reusable*ClassName*HandleScope) should be used in
// regions of the virtual machine where the thread specific reusable handle
// of that type is used. The class asserts that we do not add code that will
// result in recursive uses of the class's reusable handle.
//
// Below is an example of a reusable array handle via the
// REUSABLE_*CLASSNAME*_HANDLESCOPE macro:
//
// {
//   REUSABLE_ARRAY_HANDLESCOPE(thread);
//   ....
//   ....
//   Array& funcs = reused_array_handle.Handle();
//   code that uses funcs
//   ....
// }
//

#if defined(DEBUG)
#define REUSABLE_SCOPE(name)                                                   \
  class Reusable##name##HandleScope : public StackResource {                   \
   public:                                                                     \
    explicit Reusable##name##HandleScope(Thread* thread = Thread::Current())   \
        : StackResource(thread), thread_(thread) {                             \
      ASSERT(!thread->reusable_##name##_handle_scope_active());                \
      thread->set_reusable_##name##_handle_scope_active(true);                 \
    }                                                                          \
    ~Reusable##name##HandleScope() {                                           \
      ASSERT(thread_->reusable_##name##_handle_scope_active());                \
      thread_->set_reusable_##name##_handle_scope_active(false);               \
      Handle().ptr_ = name::null();                                            \
    }                                                                          \
    name& Handle() const {                                                     \
      ASSERT(thread_->name##_handle_ != nullptr);                              \
      return *thread_->name##_handle_;                                         \
    }                                                                          \
                                                                               \
   private:                                                                    \
    Thread* thread_;                                                           \
    DISALLOW_COPY_AND_ASSIGN(Reusable##name##HandleScope);                     \
  };
#else
#define REUSABLE_SCOPE(name)                                                   \
  class Reusable##name##HandleScope : public ValueObject {                     \
   public:                                                                     \
    explicit Reusable##name##HandleScope(Thread* thread = Thread::Current())   \
        : handle_(thread->name##_handle_) {}                                   \
    ~Reusable##name##HandleScope() {                                           \
      handle_->ptr_ = name::null();                                            \
    }                                                                          \
    name& Handle() const {                                                     \
      ASSERT(handle_ != nullptr);                                              \
      return *handle_;                                                         \
    }                                                                          \
                                                                               \
   private:                                                                    \
    name* handle_;                                                             \
    DISALLOW_COPY_AND_ASSIGN(Reusable##name##HandleScope);                     \
  };
#endif  // defined(DEBUG)
REUSABLE_HANDLE_LIST(REUSABLE_SCOPE)
#undef REUSABLE_SCOPE

#define REUSABLE_ABSTRACT_TYPE_HANDLESCOPE(thread)                             \
  ReusableAbstractTypeHandleScope reused_abstract_type(thread);
#define REUSABLE_ARRAY_HANDLESCOPE(thread)                                     \
  ReusableArrayHandleScope reused_array_handle(thread);
#define REUSABLE_CLASS_HANDLESCOPE(thread)                                     \
  ReusableClassHandleScope reused_class_handle(thread);
#define REUSABLE_CODE_HANDLESCOPE(thread)                                      \
  ReusableCodeHandleScope reused_code_handle(thread);
#define REUSABLE_ERROR_HANDLESCOPE(thread)                                     \
  ReusableErrorHandleScope reused_error_handle(thread);
#define REUSABLE_EXCEPTION_HANDLERS_HANDLESCOPE(thread)                        \
  ReusableExceptionHandlersHandleScope reused_exception_handlers_handle(thread);
#define REUSABLE_FIELD_HANDLESCOPE(thread)                                     \
  ReusableFieldHandleScope reused_field_handle(thread);
#define REUSABLE_FUNCTION_HANDLESCOPE(thread)                                  \
  ReusableFunctionHandleScope reused_function_handle(thread);
#define REUSABLE_GROWABLE_OBJECT_ARRAY_HANDLESCOPE(thread)                     \
  ReusableGrowableObjectArrayHandleScope reused_growable_object_array_handle(  \
      thread)
#define REUSABLE_INSTANCE_HANDLESCOPE(thread)                                  \
  ReusableInstanceHandleScope reused_instance_handle(thread);
#define REUSABLE_LIBRARY_HANDLESCOPE(thread)                                   \
  ReusableLibraryHandleScope reused_library_handle(thread);
#define REUSABLE_LOADING_UNIT_HANDLESCOPE(thread)                              \
  ReusableLoadingUnitHandleScope reused_loading_unit_handle(thread);
#define REUSABLE_OBJECT_HANDLESCOPE(thread)                                    \
  ReusableObjectHandleScope reused_object_handle(thread);
#define REUSABLE_PC_DESCRIPTORS_HANDLESCOPE(thread)                            \
  ReusablePcDescriptorsHandleScope reused_pc_descriptors_handle(thread);
#define REUSABLE_SMI_HANDLESCOPE(thread)                                       \
  ReusableSmiHandleScope reused_smi_handle(thread);
#define REUSABLE_STRING_HANDLESCOPE(thread)                                    \
  ReusableStringHandleScope reused_string_handle(thread);
#define REUSABLE_TYPE_PARAMETERS_HANDLESCOPE(thread)                           \
  ReusableTypeParametersHandleScope reused_type_parameters_handle(thread);
#define REUSABLE_TYPE_ARGUMENTS_HANDLESCOPE(thread)                            \
  ReusableTypeArgumentsHandleScope reused_type_arguments_handle(thread);
#define REUSABLE_TYPE_PARAMETER_HANDLESCOPE(thread)                            \
  ReusableTypeParameterHandleScope reused_type_parameter(thread);
#define REUSABLE_WEAK_ARRAY_HANDLESCOPE(thread)                                \
  ReusableWeakArrayHandleScope reused_weak_array(thread);

}  // namespace dart

#endif  // RUNTIME_VM_REUSABLE_HANDLES_H_
