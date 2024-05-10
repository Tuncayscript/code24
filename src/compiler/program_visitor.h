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

#ifndef RUNTIME_VM_PROGRAM_VISITOR_H_
#define RUNTIME_VM_PROGRAM_VISITOR_H_

#if !defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"

namespace Code {

// Currently, we have three types of abstract visitors that can be extended and
// used for program walking:
//
// * ClassVisitor, a visitor for classes in the program.
// * FunctionVisitor, a visitor for functions in the program.
// * CodeVisitor, a visitor for code objects in the program.
//
// To find the functions in a program, we must traverse the classes in the
// program, and similarly for code objects and functions. Thus, each
// FunctionVisitor is also a ClassVisitor, and each CodeVisitor is also a
// FunctionVisitor (and thus a ClassVisitor).
//
// Only the most specific visitor method is abstract. Derived visitors have a
// default empty implementation for base visitor methods to limit boilerplate
// needed when extending. For example, subclasses of CodeVisitor that only do
// per-Code work do not need to add empty implementations for VisitClass and
// VisitFunction.
//
// There are no guarantees for the order in which objects of a given type will
// be visited, but each object will be visited only once. In addition, each
// object is visited before any visitable sub-objects it contains. For example,
// this means a FunctionVisitor with a VisitClass implementation that drops
// methods from a class will not visit the dropped methods unless they are also
// found via another source of function objects.
//
// Note that WalkProgram only visits objects in the isolate heap. Deduplicating
// visitors that want to use VM objects as canonical when possible should
// instead add the appropriate VM objects first in their constructor.

class Class;
class Code;
class Function;

class CodeVisitor;
class FunctionVisitor;

class ClassVisitor : public ValueObject {
 public:
  virtual ~ClassVisitor() {}

  virtual bool IsFunctionVisitor() const { return false; }
  const FunctionVisitor* AsFunctionVisitor() const {
    return const_cast<FunctionVisitor*>(
        const_cast<ClassVisitor*>(this)->AsFunctionVisitor());
  }
  FunctionVisitor* AsFunctionVisitor() {
    if (!IsFunctionVisitor()) return nullptr;
    return reinterpret_cast<FunctionVisitor*>(this);
  }

  virtual bool IsCodeVisitor() const { return false; }
  const CodeVisitor* AsCodeVisitor() const {
    return const_cast<CodeVisitor*>(
        const_cast<ClassVisitor*>(this)->AsCodeVisitor());
  }
  CodeVisitor* AsCodeVisitor() {
    if (!IsCodeVisitor()) return nullptr;
    return reinterpret_cast<CodeVisitor*>(this);
  }

  virtual void VisitClass(const Class& cls) = 0;
};

class FunctionVisitor : public ClassVisitor {
 public:
  bool IsFunctionVisitor() const { return true; }
  virtual void VisitClass(const Class& cls) {}
  virtual void VisitFunction(const Function& function) = 0;
};

class CodeVisitor : public FunctionVisitor {
 public:
  bool IsCodeVisitor() const { return true; }
  virtual void VisitFunction(const Function& function) {}
  virtual void VisitCode(const Code& code) = 0;
};

class Thread;
class IsolateGroup;

class ProgramVisitor : public AllStatic {
 public:
  // Walks all non-null class, function, and code objects in the program as
  // necessary for the given visitor.
  static void WalkProgram(Zone* zone,
                          IsolateGroup* isolate_group,
                          ClassVisitor* visitor);

  static void Dedup(Thread* thread);
#if defined(CODE_PRECOMPILER)
  static void AssignUnits(Thread* thread);
  static uint32_t Hash(Thread* thread);
#endif

 private:
  static void BindStaticCalls(Thread* thread);
  static void ShareMegamorphicBuckets(Thread* thread);
  static void NormalizeAndDedupCompressedStackMaps(Thread* thread);
  static void DedupPcDescriptors(Thread* thread);
  static void DedupDeoptEntries(Thread* thread);
#if defined(CODE_PRECOMPILER)
  static void DedupCatchEntryMovesMaps(Thread* thread);
  static void DedupUnlinkedCalls(Thread* thread);
  static void PruneSubclasses(Thread* thread);
#endif
  static void DedupCodeSourceMaps(Thread* thread);
  static void DedupLists(Thread* thread);
  static void DedupInstructions(Thread* thread);
};

}  // namespace dart

#endif  // !defined(CODE_PRECOMPILED_RUNTIME)

#endif  // RUNTIME_VM_PROGRAM_VISITOR_H_
