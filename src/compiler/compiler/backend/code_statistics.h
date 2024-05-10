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

#ifndef RUNTIME_VM_COMPILER_BACKEND_CODE_STATISTICS_H_
#define RUNTIME_VM_COMPILER_BACKEND_CODE_STATISTICS_H_

#if defined(CODE_PRECOMPILED_RUNTIME)
#error "AOT runtime should not use compiler sources (including header files)"
#endif  // defined(CODE_PRECOMPILED_RUNTIME)

#include "src/compiler/assembler/assembler.h"
#include "src/compiler/backend/il.h"
#include "src/object.h"

namespace Code {

class CombinedCodeStatistics {
 public:
  // clang-format off
  enum EntryCounter {
#define DO(type, attrs) kTag##type,
    FOR_EACH_INSTRUCTION(DO)
#undef DO

#define DO(type, attrs) kTag##type##SlowPath,
    FOR_EACH_INSTRUCTION(DO)
#undef DO

    kTagAssertAssignableParameterCheck,
    kTagAssertAssignableInsertedByFrontend,
    kTagAssertAssignableFromSource,

    kTagCheckedEntry,
    kTagIntrinsics,

    kNumEntries,
  };
  // clang-format on

  CombinedCodeStatistics();

  void Begin(Instruction* instruction);
  void End(Instruction* instruction);

  void DumpStatistics();

  static EntryCounter SlowPathCounterFor(Instruction::Tag tag) {
    return static_cast<CombinedCodeStatistics::EntryCounter>(
        CombinedCodeStatistics::kTagGraphEntrySlowPath + tag);
  }

 private:
  friend class CodeStatistics;

  static int CompareEntries(const void* a, const void* b);

  typedef struct {
    const char* name;
    intptr_t bytes;
    intptr_t count;
  } Entry;

  Entry entries_[kNumEntries];
  intptr_t unaccounted_bytes_;
  intptr_t alignment_bytes_;
  intptr_t object_header_bytes_;
  intptr_t return_const_count_;
  intptr_t return_const_with_load_field_count_;
};

class CodeStatistics {
 public:
  explicit CodeStatistics(compiler::Assembler* assembler);

  void Begin(Instruction* instruction);
  void End(Instruction* instruction);

  void SpecialBegin(intptr_t tag);
  void SpecialEnd(intptr_t tag);

  void AppendTo(CombinedCodeStatistics* stat);

  void Finalize();

 private:
  static constexpr int kStackSize = 8;

  compiler::Assembler* assembler_;

  typedef struct {
    intptr_t bytes;
    intptr_t count;
  } Entry;

  Entry entries_[CombinedCodeStatistics::kNumEntries];
  intptr_t instruction_bytes_;
  intptr_t unaccounted_bytes_;
  intptr_t alignment_bytes_;

  intptr_t stack_[kStackSize];
  intptr_t stack_index_;
};

}  // namespace dart

#endif  // RUNTIME_VM_COMPILER_BACKEND_CODE_STATISTICS_H_
