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

#ifndef RUNTIME_VM_COMPILER_FRONTEND_CONSTANT_READER_H_
#define RUNTIME_VM_COMPILER_FRONTEND_CONSTANT_READER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/compiler/frontend/kernel_translation_helper.h"
#include "src/hash_table.h"
#include "src/object.h"

namespace Code {
namespace kernel {

// Reads and caches constants from the kernel constant pool.
class ConstantReader {
 public:
  ConstantReader(KernelReaderHelper* helper, ActiveClass* active_class);

  virtual ~ConstantReader() {}

  bool IsPragmaInstanceConstant(intptr_t constant_index,
                                intptr_t* pragma_name_constant_index,
                                intptr_t* pragma_options_constant_index);
  bool IsStringConstant(intptr_t constant_index, const char* name);
  bool GetStringConstant(intptr_t constant_index, String* out_value);

  InstancePtr ReadConstantInitializer();
  InstancePtr ReadConstantExpression();
  ObjectPtr ReadAnnotations();

  // Peeks to see if constant at the given index will evaluate to
  // instance of the given clazz.
  bool IsInstanceConstant(intptr_t constant_index, const Class& clazz);

  // Reads a constant at the given index (possibly by recursing
  // into sub-constants).
  InstancePtr ReadConstant(intptr_t constant_index);

  intptr_t NumConstants();

 private:
  InstancePtr ReadConstantInternal(intptr_t constant_index);
  intptr_t NavigateToIndex(KernelReaderHelper* reader, intptr_t constant_index);
  intptr_t NumConstants(KernelReaderHelper* reader);

  ScriptPtr Script() {
    if (active_class_ != nullptr) {
      return active_class_->ActiveScript();
    }
    return Script::null();
  }

  KernelReaderHelper* helper_;
  Zone* zone_;
  TranslationHelper& translation_helper_;
  ActiveClass* active_class_;
  Object& result_;

  DISALLOW_COPY_AND_ASSIGN(ConstantReader);
};

}  // namespace kernel
}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FRONTEND_CONSTANT_READER_H_
