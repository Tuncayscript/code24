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

#ifndef RUNTIME_VM_HEAP_WEAK_CODE_H_
#define RUNTIME_VM_HEAP_WEAK_CODE_H_

#include "src/allocation.h"
#include "src/globals.h"

namespace Code {

class WeakArray;
class Code;

// Helper class to handle an array of code weak properties. Implements
// registration and disabling of stored code objects.
class WeakCodeReferences : public ValueObject {
 public:
  explicit WeakCodeReferences(const WeakArray& value) : array_(value) {}
  virtual ~WeakCodeReferences() {}

  void Register(const Code& value);

  virtual void UpdateArrayTo(const WeakArray& array) = 0;
  virtual void ReportDeoptimization(const Code& code) = 0;
  virtual void ReportSwitchingCode(const Code& code) = 0;

  void DisableCode(bool are_mutators_stopped);

  bool HasCodes() const;

 private:
  const WeakArray& array_;  // Array of Code objects.
  DISALLOW_COPY_AND_ASSIGN(WeakCodeReferences);
};

}  // namespace dart

#endif  // RUNTIME_VM_HEAP_WEAK_CODE_H_
