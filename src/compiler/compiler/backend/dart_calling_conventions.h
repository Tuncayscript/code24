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

#ifndef RUNTIME_VM_COMPILER_BACKEND_CODE_CALLING_CONVENTIONS_H_
#define RUNTIME_VM_COMPILER_BACKEND_CODE_CALLING_CONVENTIONS_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include <utility>

#include "platform/globals.h"
#include "platform/growable_array.h"
#include "src/compiler/backend/locations.h"

namespace Code {

class Function;

namespace compiler {

// Array which for every parameter (or argument) contains its expected
// |Location| and its |Representation|.
using ParameterInfoArray = GrowableArray<std::pair<Location, Representation>>;

// For a call to the |target| function with |argc| arguments compute
// amount of stack space needed to pass all arguments in words.
//
// If |parameter_info| is not |nullptr| then it will be populated to
// describe expected location and representation of each argument.
//
// If |should_assign_stack_locations| is |false| then only arguments
// which will be passsed in registers have their locations computed.
// This does not affect return value: it is always equal to the
// number of words needed for all arguments which are passed on the stack.
intptr_t ComputeCallingConvention(
    Zone* zone,
    const Function& target,
    intptr_t argc,
    std::function<Representation(intptr_t)> argument_rep,
    bool should_assign_stack_locations,
    ParameterInfoArray* parameter_info);

}  // namespace compiler

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_CODE_CALLING_CONVENTIONS_H_
