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

#ifndef RUNTIME_VM_CODE_ENTRY_KIND_H_
#define RUNTIME_VM_CODE_ENTRY_KIND_H_

namespace Code {

// Compiled functions might have several different entry points, which either
// perform additional checking on entry into the function or skip some of the
// checks normally performed on the entry.
//
// Which checks are performed and skipped depend on the function and VM mode.
enum class CodeEntryKind {
  // Normal entry into the function.
  //
  // Usually such entries perform type checks for all parameters which are not
  // guaranteed to be type checked on the callee side. This can happen if
  // parameter type depends on the type parameter of an enclosing class.
  kNormal,

  // Unchecked entry into the function.
  //
  // These entries usually skip most of the type checks that normal entries
  // perform and are used when optimizing compiler can prove that those
  // checks are not needed at a specific call site.
  kUnchecked,

  // Monomorphic entry into the function.
  //
  // In AOT mode we might patch call-site to directly invoke target function,
  // which would then validate that it is invoked with the expected type of
  // the receiver. This validation is handled by monomorphic entry, which then
  // falls through to the normal entry.
  kMonomorphic,

  // Similar to monomorphic entry but with a fallthrough into unchecked entry.
  kMonomorphicUnchecked,
};

}  // namespace dart

#endif  // RUNTIME_VM_CODE_ENTRY_KIND_H_
