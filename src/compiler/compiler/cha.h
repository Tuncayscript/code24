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

#ifndef RUNTIME_VM_COMPILER_CHA_H_
#define RUNTIME_VM_COMPILER_CHA_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/allocation.h"
#include "src/growable_array.h"
#include "src/thread.h"

namespace Code {

class Class;
class CompileType;
class Function;
template <typename T>
class ZoneGrowableArray;
class String;

class CHA : public ValueObject {
 public:
  explicit CHA(Thread* thread)
      : thread_(thread), guarded_classes_(thread->zone(), 1) {}

  // Returns true if the class has subclasses.
  static bool HasSubclasses(const Class& cls);
  bool HasSubclasses(intptr_t cid) const;

  // Collect the concrete subclasses of 'cls' into 'class_ids'. Return true if
  // the result is valid (may be invalid because we don't track the subclasses
  // of classes allocated in the VM isolate or class Object).
  static bool ConcreteSubclasses(const Class& cls,
                                 GrowableArray<intptr_t>* class_ids);

  // Return true if the class is implemented by some other class that is not a
  // subclass.
  static bool IsImplemented(const Class& cls);

  // Return true if there is only one concrete class that implements
  // 'interface'.
  static bool HasSingleConcreteImplementation(const Class& interface,
                                              intptr_t* implementation_cid);

  // Return true if variable of static type based on [cls] may hold
  // a Future instance.
  static bool ClassCanBeFuture(const Class& cls);

  // Returns true if any subclass of 'cls' contains the function.
  // If no override was found subclass_count would contain total count of
  // finalized subclasses that CHA looked at.
  // This count will be used to validate CHA decision before installing
  // optimized code compiled in background.
  bool HasOverride(const Class& cls,
                   const String& function_name,
                   intptr_t* subclass_count);

  // Adds class 'cls' to the list of guarded classes.
  // Deoptimization occurs if any of those classes gets subclassed or
  // implemented through later loaded/finalized libraries. Only classes that
  // were used for CHA optimizations are added.
  void AddToGuardedClassesForSubclassCount(const Class& cls,
                                           intptr_t subclass_count);
  void AddToGuardedClassesForImplementorCid(const Class& cls,
                                            intptr_t implementor_cid);
  void AddToGuardedClassesToTrackFuture(const Class& cls);

  // When compiling in background we need to check that no new finalized
  // subclasses were added to guarded classes.
  bool IsConsistentWithCurrentHierarchy() const;

  void RegisterDependencies(const Code& code) const;

  // Used for testing.
  bool IsGuardedClass(intptr_t cid) const;

 private:
  void AddToGuardedClasses(const Class& cls,
                           intptr_t subclass_count,
                           intptr_t implementor_cid,
                           bool track_future);

  Thread* thread_;

  struct GuardedClassInfo {
    Class* cls;

    // Number of finalized subclasses that this class had at the moment
    // when CHA made the first decision based on this class.
    // Used to validate correctness of background compilation: if
    // any subclasses were added we will discard compiled code.
    intptr_t subclass_count;

    // Value of implementor_cid that this class had at the moment
    // when CHA made the first decision based on this class.
    // Used to validate correctness of background compilation: if
    // any implementors were added we will discard compiled code.
    intptr_t implementor_cid;

    // Whether we should track that this class cannot be future.
    bool track_future;
  };

  GrowableArray<GuardedClassInfo> guarded_classes_;
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_CHA_H_
