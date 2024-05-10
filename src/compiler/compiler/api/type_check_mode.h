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

#ifndef RUNTIME_VM_COMPILER_API_TYPE_CHECK_MODE_H_
#define RUNTIME_VM_COMPILER_API_TYPE_CHECK_MODE_H_

namespace Code {

// Invocation mode for TypeCheck runtime entry that describes
// where we are calling it from.
enum TypeCheckMode {
  // TypeCheck is invoked from LazySpecializeTypeTest stub.
  // It should replace stub on the type with a specialized version.
  kTypeCheckFromLazySpecializeStub,

  // TypeCheck is invoked from the SlowTypeTest stub.
  // This means that cache can be lazily created (if needed)
  // and dst_name can be fetched from the pool.
  kTypeCheckFromSlowStub,

  // TypeCheck is invoked from normal inline AssertAssignable.
  // Both cache and dst_name must be already populated.
  kTypeCheckFromInline
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_API_TYPE_CHECK_MODE_H_
