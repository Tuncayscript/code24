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

#ifndef RUNTIME_VM_FLAGS_H_
#define RUNTIME_VM_FLAGS_H_

#include "platform/assert.h"
#include "src/flag_list.h"
#include "src/globals.h"

typedef const char* charp;

#define DECLARE_FLAG(type, name) extern type FLAG_##name

#define DEFINE_FLAG(type, name, default_value, comment)                        \
  type FLAG_##name =                                                           \
      Flags::Register_##type(&FLAG_##name, #name, default_value, comment);

#define DEFINE_FLAG_HANDLER(handler, name, comment)                            \
  bool DUMMY_##name = Flags::RegisterFlagHandler(handler, #name, comment);

#define DEFINE_OPTION_HANDLER(handler, name, comment)                          \
  bool DUMMY_##name = Flags::RegisterOptionHandler(handler, #name, comment);

namespace Code {

typedef void (*FlagHandler)(bool value);
typedef void (*OptionHandler)(const char* value);

// Forward declarations.
class Flag;
class JSONArray;
class JSONStream;

class Flags {
 public:
  static bool Register_bool(bool* addr,
                            const char* name,
                            bool default_value,
                            const char* comment);

  static int Register_int(int* addr,
                          const char* name,
                          int default_value,
                          const char* comment);

  static uint64_t Register_uint64_t(uint64_t* addr,
                                    const char* name,
                                    uint64_t default_value,
                                    const char* comment);

  static const char* Register_charp(charp* addr,
                                    const char* name,
                                    const char* default_value,
                                    const char* comment);

  static bool RegisterFlagHandler(FlagHandler handler,
                                  const char* name,
                                  const char* comment);

  static bool RegisterOptionHandler(OptionHandler handler,
                                    const char* name,
                                    const char* comment);

  static char* ProcessCommandLineFlags(int argc, const char** argv);

  static Flag* Lookup(const char* name);

  static bool IsSet(const char* name);

  static bool Initialized() { return initialized_; }

  static void Cleanup();

#ifndef PRODUCT
  static void PrintJSON(JSONStream* js);
#endif  // !PRODUCT

  static bool SetFlag(const char* name, const char* value, const char** error);

 private:
  static Flag** flags_;
  static intptr_t capacity_;
  static intptr_t num_flags_;

  static bool initialized_;

  static void AddFlag(Flag* flag);

  static bool SetFlagFromString(Flag* flag, const char* argument);

  static void Parse(const char* option);

  static int CompareFlagNames(const void* left, const void* right);

  static void PrintFlags();

#ifndef PRODUCT
  static void PrintFlagToJSONArray(JSONArray* jsarr, const Flag* flag);
#endif  // !PRODUCT

  // Testing needs direct access to private methods.
  friend void CODE_TestParseFlags();

  DISALLOW_ALLOCATION();
  DISALLOW_IMPLICIT_CONSTRUCTORS(Flags);
};

#define PRODUCT_FLAG_MACRO(name, type, default_value, comment)                 \
  extern type FLAG_##name;

#if defined(DEBUG)
#define DEBUG_FLAG_MACRO(name, type, default_value, comment)                   \
  extern type FLAG_##name;
#else  // defined(DEBUG)
#define DEBUG_FLAG_MACRO(name, type, default_value, comment)                   \
  const type FLAG_##name = default_value;
#endif  // defined(DEBUG)

#if defined(PRODUCT) && defined(CODE_PRECOMPILED_RUNTIME)
#define RELEASE_FLAG_MACRO(name, product_value, type, default_value, comment)  \
  const type FLAG_##name = product_value;
#define PRECOMPILE_FLAG_MACRO(name, precompiled_value, product_value, type,    \
                              default_value, comment)                          \
  const type FLAG_##name = precompiled_value;

#elif defined(PRODUCT)  // !PRECOMPILED
#define RELEASE_FLAG_MACRO(name, product_value, type, default_value, comment)  \
  const type FLAG_##name = product_value;
#define PRECOMPILE_FLAG_MACRO(name, precompiled_value, product_value, type,    \
                              default_value, comment)                          \
  const type FLAG_##name = product_value;

#elif defined(CODE_PRECOMPILED_RUNTIME)  // !PRODUCT
#define RELEASE_FLAG_MACRO(name, product_value, type, default_value, comment)  \
  extern type FLAG_##name;
#define PRECOMPILE_FLAG_MACRO(name, precompiled_value, product_value, type,    \
                              default_value, comment)                          \
  const type FLAG_##name = precompiled_value;

#else  // !PRODUCT && !PRECOMPILED
#define RELEASE_FLAG_MACRO(name, product_value, type, default_value, comment)  \
  extern type FLAG_##name;
#define PRECOMPILE_FLAG_MACRO(name, precompiled_value, product_value, type,    \
                              default_value, comment)                          \
  extern type FLAG_##name;

#endif

// Now declare all flags here.
FLAG_LIST(PRODUCT_FLAG_MACRO,
          RELEASE_FLAG_MACRO,
          PRECOMPILE_FLAG_MACRO,
          DEBUG_FLAG_MACRO)

#undef RELEASE_FLAG_MACRO
#undef DEBUG_FLAG_MACRO
#undef PRODUCT_FLAG_MACRO
#undef PRECOMPILE_FLAG_MACRO

}  // namespace dart

#endif  // RUNTIME_VM_FLAGS_H_
