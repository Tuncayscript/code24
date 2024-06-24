/*
 * Copyright (c) 2024, NeXTech Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this code).
 *
 * Contact with NeXTech, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
//             Tural Ghuliev  (turalquliyev@it-gss.com)
// Date: Saturday, June 1, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 

#ifndef LANGUAGE_BUILTIN_PROTO_H
#define LANGUAGE_BUILTIN_PROTO_H

#ifdef __cplusplus
extern "C" {
#endif

// declarations for julia-callable builtin functions

#ifdef DEFINE_BUILTIN_GLOBALS
#define DECLARE_BUILTIN(name) \
    LANGUAGE_CALLABLE(jl_f_##name); \
    LANGUAGE_DLLEXPORT jl_value_t *jl_builtin_##name; \
    LANGUAGE_DLLEXPORT jl_fptr_args_t jl_f_##name##_addr = &jl_f_##name
#else
#define DECLARE_BUILTIN(name) \
    LANGUAGE_CALLABLE(jl_f_##name); \
    LANGUAGE_DLLEXPORT extern jl_value_t *jl_builtin_##name; \
    LANGUAGE_DLLEXPORT extern jl_fptr_args_t jl_f_##name##_addr
#endif

DECLARE_BUILTIN(_apply_iterate);
DECLARE_BUILTIN(_apply_pure);
DECLARE_BUILTIN(_call_in_world);
DECLARE_BUILTIN(_call_in_world_total);
DECLARE_BUILTIN(_call_latest);
DECLARE_BUILTIN(_compute_sparams);
DECLARE_BUILTIN(_expr);
DECLARE_BUILTIN(_svec_ref);
DECLARE_BUILTIN(_typebody);
DECLARE_BUILTIN(_typevar);
DECLARE_BUILTIN(applicable);
DECLARE_BUILTIN(apply_type);
DECLARE_BUILTIN(compilerbarrier);
DECLARE_BUILTIN(current_scope);
DECLARE_BUILTIN(donotdelete);
DECLARE_BUILTIN(fieldtype);
DECLARE_BUILTIN(finalizer);
DECLARE_BUILTIN(getfield);
DECLARE_BUILTIN(getglobal);
DECLARE_BUILTIN(ifelse);
DECLARE_BUILTIN(invoke);
DECLARE_BUILTIN(is);
DECLARE_BUILTIN(isa);
DECLARE_BUILTIN(isdefined);
DECLARE_BUILTIN(issubtype);
DECLARE_BUILTIN(memoryref);
DECLARE_BUILTIN(memoryref_isassigned);
DECLARE_BUILTIN(memoryrefget);
DECLARE_BUILTIN(memoryrefmodify);
DECLARE_BUILTIN(memoryrefoffset);
DECLARE_BUILTIN(memoryrefreplace);
DECLARE_BUILTIN(memoryrefset);
DECLARE_BUILTIN(memoryrefsetonce);
DECLARE_BUILTIN(memoryrefswap);
DECLARE_BUILTIN(modifyfield);
DECLARE_BUILTIN(modifyglobal);
DECLARE_BUILTIN(nfields);
DECLARE_BUILTIN(replacefield);
DECLARE_BUILTIN(replaceglobal);
DECLARE_BUILTIN(setfield);
DECLARE_BUILTIN(setfieldonce);
DECLARE_BUILTIN(setglobal);
DECLARE_BUILTIN(setglobalonce);
DECLARE_BUILTIN(sizeof);
DECLARE_BUILTIN(svec);
DECLARE_BUILTIN(swapfield);
DECLARE_BUILTIN(swapglobal);
DECLARE_BUILTIN(throw);
DECLARE_BUILTIN(tuple);
DECLARE_BUILTIN(typeassert);
DECLARE_BUILTIN(typeof);

LANGUAGE_CALLABLE(jl_f__structtype);
LANGUAGE_CALLABLE(jl_f__abstracttype);
LANGUAGE_CALLABLE(jl_f__primitivetype);
LANGUAGE_CALLABLE(jl_f__setsuper);
LANGUAGE_CALLABLE(jl_f__equiv_typedef);
LANGUAGE_CALLABLE(jl_f_get_binding_type);
LANGUAGE_CALLABLE(jl_f__compute_sparams);
LANGUAGE_CALLABLE(jl_f__svec_ref);
#ifdef __cplusplus
}
#endif

#endif
