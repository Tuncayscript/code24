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

#ifndef RUNTIME_VM_COMPILER_BACKEND_EVALUATOR_H_
#define RUNTIME_VM_COMPILER_BACKEND_EVALUATOR_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"
#include "src/compiler/backend/flow_graph.h"
#include "src/compiler/backend/il.h"
#include "src/compiler/backend/locations.h"

namespace Code {

// Namespace for static helper methods that evaluate constant expressions.
class Evaluator : public AllStatic {
 public:
  // Truncates the given int64 value based on the representation.
  static int64_t TruncateTo(int64_t v, Representation r);

  // Evaluates a binary integer operation and returns a pointer to a
  // canonicalized RawInteger.
  static IntegerPtr BinaryIntegerEvaluate(const Object& left,
                                          const Object& right,
                                          Token::Kind token_kind,
                                          bool is_truncating,
                                          Representation representation,
                                          Thread* thread);

  // Evaluates a unary integer operation and returns a pointer to a
  // canonicalized RawInteger.
  static IntegerPtr UnaryIntegerEvaluate(const Object& value,
                                         Token::Kind token_kind,
                                         Representation representation,
                                         Thread* thread);

  // Evaluates an `int.bitLength` operation and returns a pointer to a
  // canonicalized RawInteger.
  static IntegerPtr BitLengthEvaluate(const Object& value,
                                      Representation representation,
                                      Thread* thread);

  // Evaluates a unary double operation and returns the result.
  static double EvaluateUnaryDoubleOp(const double value,
                                      Token::Kind token_kind,
                                      Representation representation);

  // Evaluates a binary double operation and returns the result.
  static double EvaluateBinaryDoubleOp(const double left,
                                       const double right,
                                       Token::Kind token_kind,
                                       Representation representation);

  // Returns whether the value is an int64, and returns the int64 value
  // through the result parameter.
  static bool ToIntegerConstant(Value* value, int64_t* result);
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_EVALUATOR_H_
