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

#ifndef RUNTIME_VM_CODE_OBSERVERS_H_
#define RUNTIME_VM_CODE_OBSERVERS_H_

#include "src/allocation.h"
#include "src/globals.h"

#include "include/CODE_api.h"

#if !defined(PRODUCT)
namespace Code {

class CodeComments;

// Object observing code creation events. Used by external profilers and
// debuggers to map address ranges to function names.
class CodeObserver {
 public:
  CodeObserver() {}

  virtual ~CodeObserver() {}

  // Returns true if this observer is active and should be notified
  // about newly created code objects.
  virtual bool IsActive() const = 0;

  // Notify code observer about a newly created code object with the
  // given properties.
  virtual void Notify(const char* name,
                      uword base,
                      uword prologue_offset,
                      uword size,
                      bool optimized,
                      const CodeComments* comments) = 0;

 private:
  DISALLOW_COPY_AND_ASSIGN(CodeObserver);
};

class Mutex;

class CodeObservers : public AllStatic {
 public:
  static void Init();

  static void RegisterExternal(CODE_CodeObserver observer);

  static void Register(CodeObserver* observer);

  // Notify all active code observers about a newly created code object.
  static void NotifyAll(const char* name,
                        uword base,
                        uword prologue_offset,
                        uword size,
                        bool optimized,
                        const CodeComments* comments);

  // Returns true if there is at least one active code observer.
  static bool AreActive();

  static void Cleanup();

  static Mutex* mutex() { return mutex_; }

 private:
  static Mutex* mutex_;
  static intptr_t observers_length_;
  static CodeObserver** observers_;
};

}  // namespace dart
#endif  // !defined(PRODUCT)

#endif  // RUNTIME_VM_CODE_OBSERVERS_H_
