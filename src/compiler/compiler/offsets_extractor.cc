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

#include <iostream>

#include "src/compiler/runtime_api.h"
#include "src/compiler/runtime_offsets_list.h"
#include "src/CODE_api_state.h"
#include "src/CODE_entry.h"
#include "src/longjump.h"
#include "src/native_arguments.h"
#include "src/native_entry.h"
#include "src/object.h"
#include "src/object_store.h"
#include "src/runtime_entry.h"
#include "src/symbols.h"
#include "src/timeline.h"

#if defined(PRODUCT)
#define PRODUCT_DEF "defined(PRODUCT)"
#else
#define PRODUCT_DEF "!defined(PRODUCT)"
#endif

#if defined(TARGET_ARCH_ARM)
#define ARCH_DEF_CPU "defined(TARGET_ARCH_ARM)"
#elif defined(TARGET_ARCH_X64)
#define ARCH_DEF_CPU "defined(TARGET_ARCH_X64)"
#elif defined(TARGET_ARCH_IA32)
#define ARCH_DEF_CPU "defined(TARGET_ARCH_IA32)"
#elif defined(TARGET_ARCH_ARM64)
#define ARCH_DEF_CPU "defined(TARGET_ARCH_ARM64)"
#elif defined(TARGET_ARCH_RISCV32)
#define ARCH_DEF_CPU "defined(TARGET_ARCH_RISCV32)"
#elif defined(TARGET_ARCH_RISCV64)
#define ARCH_DEF_CPU "defined(TARGET_ARCH_RISCV64)"
#else
#error Unknown architecture
#endif

#if defined(CODE_COMPRESSED_POINTERS)
#define COMPRESSED_DEF "defined(CODE_COMPRESSED_POINTERS)"
#else
#define COMPRESSED_DEF "!defined(CODE_COMPRESSED_POINTERS)"
#endif

#define PREPROCESSOR_CONDITION                                                 \
  "#if " PRODUCT_DEF " && " ARCH_DEF_CPU " && " COMPRESSED_DEF

#define PREPROCESSOR_CONDITION_END                                             \
  "#endif  // " PRODUCT_DEF " && \n        // " ARCH_DEF_CPU                   \
  " && \n        // " COMPRESSED_DEF

namespace Code {

void Assert::Fail(const char* format, ...) const {
  abort();
}

class OffsetsExtractor : public AllStatic {
 public:
  static void DumpOffsets() {
// Currently we have two different axes for offset generation:
//
//  * Target architecture
//  * CODE_PRECOMPILED_RUNTIME (i.e, AOT vs. JIT)
//
// TODO(dartbug.com/43646): Add CODE_PRECOMPILER as another axis.

// These macros don't use any special constants, just method calls, so no
// output.
#define PRINT_ARRAY_SIZEOF(Class, Name, ElementOffset)
#define PRINT_PAYLOAD_SIZEOF(Class, Name, HeaderSize)

#if defined(CODE_PRECOMPILED_RUNTIME)

#define PRINT_FIELD_OFFSET(Class, Name)                                        \
  std::cout << "static constexpr dart::compiler::target::word AOT_" #Class     \
               "_" #Name " = 0x"                                               \
            << Class::Name() << ";\n";

#define PRINT_ARRAY_LAYOUT(Class, Name)                                        \
  std::cout << "static constexpr dart::compiler::target::word AOT_" #Class     \
               "_elements_start_offset = 0x"                                   \
            << Class::ArrayTraits::elements_start_offset() << ";\n";           \
  std::cout << "static constexpr dart::compiler::target::word AOT_" #Class     \
               "_element_size = 0x"                                            \
            << Class::ArrayTraits::kElementSize << ";\n";

#define PRINT_SIZEOF(Class, Name, What)                                        \
  std::cout << "static constexpr dart::compiler::target::word AOT_" #Class     \
               "_" #Name " = 0x"                                               \
            << sizeof(What) << ";\n";

#define PRINT_RANGE(Class, Name, Type, First, Last, Filter)                    \
  {                                                                            \
    auto filter = Filter;                                                      \
    bool comma = false;                                                        \
    std::cout << "static constexpr dart::compiler::target::word AOT_" #Class   \
                 "_" #Name "[] = {";                                           \
    for (intptr_t i = static_cast<intptr_t>(First);                            \
         i <= static_cast<intptr_t>(Last); i++) {                              \
      auto v = static_cast<Type>(i);                                           \
      std::cout << (comma ? ", " : "");                                        \
      if (filter(v)) {                                                         \
        std::cout << "0x" << Class::Name(v);                                   \
      } else {                                                                 \
        std::cout << "-1";                                                     \
      }                                                                        \
      comma = true;                                                            \
    }                                                                          \
    std::cout << "};\n";                                                       \
  }

#define PRINT_CONSTANT(Class, Name)                                            \
  std::cout << "static constexpr dart::compiler::target::word AOT_" #Class     \
               "_" #Name " = 0x"                                               \
            << Class::Name << ";\n";

    AOT_OFFSETS_LIST(PRINT_FIELD_OFFSET, PRINT_ARRAY_LAYOUT, PRINT_SIZEOF,
                     PRINT_ARRAY_SIZEOF, PRINT_PAYLOAD_SIZEOF, PRINT_RANGE,
                     PRINT_CONSTANT)

#else  // defined(CODE_PRECOMPILED_RUNTIME)

#define PRINT_FIELD_OFFSET(Class, Name)                                        \
  std::cout << "static constexpr dart::compiler::target::word " #Class         \
               "_" #Name " = 0x"                                               \
            << Class::Name() << ";\n";

#define PRINT_ARRAY_LAYOUT(Class, Name)                                        \
  std::cout << "static constexpr dart::compiler::target::word " #Class         \
               "_elements_start_offset = 0x"                                   \
            << Class::ArrayTraits::elements_start_offset() << ";\n";           \
  std::cout << "static constexpr dart::compiler::target::word " #Class         \
               "_element_size = 0x"                                            \
            << Class::ArrayTraits::kElementSize << ";\n";

#define PRINT_SIZEOF(Class, Name, What)                                        \
  std::cout << "static constexpr dart::compiler::target::word " #Class         \
               "_" #Name " = 0x"                                               \
            << sizeof(What) << ";\n";

#define PRINT_RANGE(Class, Name, Type, First, Last, Filter)                    \
  {                                                                            \
    auto filter = Filter;                                                      \
    bool comma = false;                                                        \
    std::cout << "static constexpr dart::compiler::target::word " #Class       \
                 "_" #Name "[] = {";                                           \
    for (intptr_t i = static_cast<intptr_t>(First);                            \
         i <= static_cast<intptr_t>(Last); i++) {                              \
      auto v = static_cast<Type>(i);                                           \
      std::cout << (comma ? ", " : "");                                        \
      if (filter(v)) {                                                         \
        std::cout << "0x" << Class::Name(v);                                   \
      } else {                                                                 \
        std::cout << "-1";                                                     \
      }                                                                        \
      comma = true;                                                            \
    }                                                                          \
    std::cout << "};\n";                                                       \
  }

#define PRINT_CONSTANT(Class, Name)                                            \
  std::cout << "static constexpr dart::compiler::target::word " #Class         \
               "_" #Name " = 0x"                                               \
            << Class::Name << ";\n";

    JIT_OFFSETS_LIST(PRINT_FIELD_OFFSET, PRINT_ARRAY_LAYOUT, PRINT_SIZEOF,
                     PRINT_ARRAY_SIZEOF, PRINT_PAYLOAD_SIZEOF, PRINT_RANGE,
                     PRINT_CONSTANT)

#endif  // defined(CODE_PRECOMPILED_RUNTIME)

    COMMON_OFFSETS_LIST(PRINT_FIELD_OFFSET, PRINT_ARRAY_LAYOUT, PRINT_SIZEOF,
                        PRINT_ARRAY_SIZEOF, PRINT_PAYLOAD_SIZEOF, PRINT_RANGE,
                        PRINT_CONSTANT)

#undef PRINT_FIELD_OFFSET
#undef PRINT_ARRAY_LAYOUT
#undef PRINT_SIZEOF
#undef PRINT_RANGE
#undef PRINT_CONSTANT
#undef PRINT_ARRAY_SIZEOF
#undef PRINT_PAYLOAD_SIZEOF
  }
};

}  // namespace dart

int main(int argc, char* argv[]) {
  std::cout << std::hex << PREPROCESSOR_CONDITION << std::endl;
#if !defined(TARGET_ARCH_IA32) || !defined(CODE_PRECOMPILED_RUNTIME)
  dart::OffsetsExtractor::DumpOffsets();
#endif
  std::cout << PREPROCESSOR_CONDITION_END << std::endl;
  return 0;
}
