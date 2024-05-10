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

#ifndef RUNTIME_VM_BASE_ISOLATE_H_
#define RUNTIME_VM_BASE_ISOLATE_H_

#include "platform/assert.h"
#include "src/globals.h"

namespace Code {

class HandleScope;
class StackResource;
class Thread;
class Zone;

// A BaseIsolate contains just enough functionality to allocate
// StackResources.  This allows us to inline the StackResource
// constructor/destructor for performance.
class BaseIsolate {
 public:
#if defined(DEBUG)
  static void AssertCurrent(BaseIsolate* isolate);
#endif

 protected:
  BaseIsolate() {}

  ~BaseIsolate() {
    // Do not delete stack resources: top_resource_ and current_zone_.
  }

  Thread* scheduled_mutator_thread_ = nullptr;

  // Stores the saved [Thread] object of a mutator. Mutators may retain their
  // thread even when being descheduled (e.g. due to having an active stack).
  Thread* mutator_thread_ = nullptr;

 private:
  DISALLOW_COPY_AND_ASSIGN(BaseIsolate);
};

}  // namespace dart

#endif  // RUNTIME_VM_BASE_ISOLATE_H_
