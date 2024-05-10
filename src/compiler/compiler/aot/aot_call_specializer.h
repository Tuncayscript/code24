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

#ifndef RUNTIME_VM_COMPILER_AOT_AOT_CALL_SPECIALIZER_H_
#define RUNTIME_VM_COMPILER_AOT_AOT_CALL_SPECIALIZER_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/compiler/call_specializer.h"

namespace Code {

class Precompiler;
class SpeculativeInliningPolicy;

class AotCallSpecializer : public CallSpecializer {
 public:
  AotCallSpecializer(Precompiler* precompiler,
                     FlowGraph* flow_graph,
                     SpeculativeInliningPolicy* speculative_policy);

  virtual ~AotCallSpecializer() {}

  virtual void VisitInstanceCall(InstanceCallInstr* instr);
  virtual void VisitStaticCall(StaticCallInstr* instr);
  virtual void VisitPolymorphicInstanceCall(
      PolymorphicInstanceCallInstr* instr);

  virtual bool TryReplaceInstanceOfWithRangeCheck(InstanceCallInstr* call,
                                                  const AbstractType& type);

 private:
  // Attempt to build ICData for call using propagated class-ids.
  virtual bool TryCreateICData(InstanceCallInstr* call);

  bool TryCreateICDataForUniqueTarget(InstanceCallInstr* call);

  bool RecognizeRuntimeTypeGetter(InstanceCallInstr* call);
  bool TryReplaceWithHaveSameRuntimeType(TemplateDartCall<0>* call);

  bool TryInlineFieldAccess(InstanceCallInstr* call);
  bool TryInlineFieldAccess(StaticCallInstr* call);

  bool IsSupportedIntOperandForStaticDoubleOp(CompileType* operand_type);
  Value* PrepareStaticOpInput(Value* input, intptr_t cid, Instruction* call);

  CompileType BuildStrengthenedReceiverType(Value* input, intptr_t cid);

  bool TryOptimizeInstanceCallUsingStaticTypes(InstanceCallInstr* instr);

  virtual bool TryOptimizeStaticCallUsingStaticTypes(StaticCallInstr* call);

  // If a call can be dispatched through the global dispatch table, replace
  // it by a dispatch table call.
  void TryReplaceWithDispatchTableCall(InstanceCallBaseInstr* call);
  const Function& InterfaceTargetForTableDispatch(InstanceCallBaseInstr* call);

  // Try to replace a call with a more specialized instruction working on
  // integers (e.g. BinaryInt64OpInstr, EqualityCompareInstr,
  // RelationalOpInstr)
  bool TryOptimizeIntegerOperation(TemplateDartCall<0>* call, Token::Kind kind);

  // Try to replace a call with a more specialized instruction working on
  // doubles (e.g. BinaryDoubleOpInstr, EqualityCompareInstr,
  // RelationalOpInstr)
  bool TryOptimizeDoubleOperation(TemplateDartCall<0>* call, Token::Kind kind);

  // Check if o.m(...) [call] is actually an invocation through a getter
  // o.get:m().call(...) given that the receiver of the call is a subclass
  // of the [receiver_class]. If it is - then expand it into
  // o.get:m.call(...) to avoid hitting dispatch through noSuchMethod.
  bool TryExpandCallThroughGetter(const Class& receiver_class,
                                  InstanceCallInstr* call);

  Definition* TryOptimizeDivisionOperation(TemplateDartCall<0>* instr,
                                           Token::Kind op_kind,
                                           Value* left_value,
                                           Value* right_value);

  virtual void ReplaceInstanceCallsWithDispatchTableCalls();

  Precompiler* precompiler_;

  bool has_unique_no_such_method_;

  DISALLOW_COPY_AND_ASSIGN(AotCallSpecializer);
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_AOT_AOT_CALL_SPECIALIZER_H_
