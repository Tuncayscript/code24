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
 */

// Bring in the curated lists of exported data and function symbols, then
// perform C preprocessor magic upon them to generate lists of declarations and
// functions to re-export our function symbols from libjulia-internal to libjulia.
#include "../src/jl_exported_data.inc"
#include "../src/jl_exported_funcs.inc"

// Define pointer data as `const void * $(name);`
#define XX(name)    LANGUAGE_DLLEXPORT const void * name;
LANGUAGE_EXPORTED_DATA_POINTERS(XX)
#undef XX

// Define symbol data as `$(type) $(name);`
#define XX(name, type)    LANGUAGE_DLLEXPORT type name;
LANGUAGE_EXPORTED_DATA_SYMBOLS(XX)
#undef XX

// define a copy of exported data
#define jl_max_tags 64
LANGUAGE_DLLEXPORT void *jl_small_typeof[(jl_max_tags << 4) / sizeof(void*)]; // 16-bit aligned, like the GC

// Declare list of exported functions (sans type)
#define XX(name)    LANGUAGE_DLLEXPORT void name(void);
typedef void (anonfunc)(void);
LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
#undef XX

// Define holder locations for function addresses as `const void * $(name)_addr = NULL;
#define XX(name)    LANGUAGE_HIDDEN anonfunc * name##_addr = NULL;
LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
#undef XX

// Generate lists of function names and addresses
#define XX(name)    "i" #name,
static const char *const jl_runtime_exported_func_names[] = {
    LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
    LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
    NULL
};
#undef XX

#define XX(name)    #name"_impl",
static const char *const jl_codegen_exported_func_names[] = {
    LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
    NULL
};
#undef XX

#define XX(name)    #name"_fallback",
static const char *const jl_codegen_fallback_func_names[] = {
    LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
    NULL
};
#undef XX

#define XX(name)    &name##_addr,
static anonfunc **const jl_runtime_exported_func_addrs[] = {
    LANGUAGE_RUNTIME_EXPORTED_FUNCS(XX)
#ifdef _OS_WINDOWS_
    LANGUAGE_RUNTIME_EXPORTED_FUNCS_WIN(XX)
#endif
    NULL
};
static anonfunc **const jl_codegen_exported_func_addrs[] = {
    LANGUAGE_CODEGEN_EXPORTED_FUNCS(XX)
    NULL
};
#undef XX
