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

#ifndef RUNTIME_VM_COMPILER_FRONTEND_PROLOGUE_BUILDER_H_
#define RUNTIME_VM_COMPILER_FRONTEND_PROLOGUE_BUILDER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/compiler/frontend/base_flow_graph_builder.h"

namespace Code {
namespace kernel {

// Responsible for building IR code for prologues of functions.
//
// This code handles initialization of local variables which the
// prologue needs to setup, including initialization of the:
//
//    * current context variable, from the passed closure object
//    * function_type_arguments variable, from the stack above fp
//    * raw parameter variables, from the stack above fp
//
// if needed.
//
// Furthermore it performs all necessary checks which could lead into a
// no-such-method bailout, including check that:
//
//    * the number of passed positional arguments is correct
//    * the names of passed named arguments are correct
//    * the number of function type arguments is correct
//
// if needed.
//
// Most of these things are done by interpreting the caller-supplied arguments
// descriptor.
class PrologueBuilder : public BaseFlowGraphBuilder {
 public:
  PrologueBuilder(const ParsedFunction* parsed_function,
                  intptr_t last_used_id,
                  bool compiling_for_osr,
                  bool is_inlining)
      : BaseFlowGraphBuilder(parsed_function, last_used_id),
        compiling_for_osr_(compiling_for_osr),
        is_inlining_(is_inlining) {}

  BlockEntryInstr* BuildPrologue(BlockEntryInstr* entry,
                                 PrologueInfo* prologue_info);

  Fragment BuildParameterHandling();

  static bool HasEmptyPrologue(const Function& function);
  static bool PrologueSkippableOnUncheckedEntry(const Function& function);

  intptr_t last_used_block_id() const { return last_used_block_id_; }

 private:
  Fragment BuildClosureContextHandling();

  Fragment BuildTypeArgumentsHandling();

  Fragment BuildClosureDelayedTypeArgumentsHandling();

  LocalVariable* ParameterVariable(intptr_t index) {
    return parsed_function_->RawParameterVariable(index);
  }

  const Instance& DefaultParameterValueAt(intptr_t i) {
    if (parsed_function_->default_parameter_values() != nullptr) {
      return parsed_function_->DefaultParameterValueAt(i);
    }
    // Only invocation dispatchers that have compile-time arguments
    // descriptors lack default parameter values (because their functions only
    // have optional named parameters, all of which are provided in calls.)
    ASSERT(has_saved_args_desc_array());
    return Instance::null_instance();
  }

  void SortOptionalNamedParametersInto(int* opt_param_position,
                                       int num_fixed_params,
                                       int num_params);

  bool compiling_for_osr_;
  bool is_inlining_;
};

}  // namespace kernel
}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_FRONTEND_PROLOGUE_BUILDER_H_
