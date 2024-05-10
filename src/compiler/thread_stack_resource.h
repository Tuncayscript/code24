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

#ifndef RUNTIME_VM_THREAD_STACK_RESOURCE_H_
#define RUNTIME_VM_THREAD_STACK_RESOURCE_H_

#include <type_traits>
#include <utility>

#include "src/allocation.h"
#include "src/globals.h"

namespace Code {

class Isolate;
class IsolateGroup;
class ThreadState;
class Thread;

class ThreadStackResource : public StackResource {
 public:
  explicit ThreadStackResource(Thread* T)
      : StackResource(reinterpret_cast<ThreadState*>(T)) {}

  ~ThreadStackResource();

  Thread* thread() const {
    return reinterpret_cast<Thread*>(StackResource::thread());
  }
  Isolate* isolate() const;
  IsolateGroup* isolate_group() const;
};

template <typename T, typename... Args>
class AsThreadStackResource : public ThreadStackResource {
 public:
  static_assert(!std::is_base_of<StackResource, T>::value);
  explicit AsThreadStackResource(Thread* thread, Args&&... args)
      : ThreadStackResource(thread),
        member_(thread, std::forward<Args>(args)...) {}
  ~AsThreadStackResource() {}

 private:
  T member_;
};

}  // namespace dart

#endif  // RUNTIME_VM_THREAD_STACK_RESOURCE_H_
