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
// Date: Tuesday, June 25, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 
// Purpose: Generic Functions
//          Method table and lookup
//          GF constructor
//          Dispatch
//          Static Parameter Inference (SPI)
//          Method Specialization and Catching
//          Invoking type inference

#include <stdlib.h>
#include <string.h>
#include "code.h"
#include "language_internal.h"
#ifndef _OS_WINDOWS_
#include <unistd.h>
#endif
#include "language_assert.h"

// The compilation signature is not used to cache the method if the number of overlapping methods is greater than this
#define MAX_UNSPECIALIZED_CONFLICTS 32

#ifdef __cplusplus
extern "C" {
#endif

LANGUAGE_DLLEXPORT _Atomic(size_t) language_world_counter = 1; // uses atomic acquire/release
language_mutex_t world_counter_lock;
LANGUAGE_DLLEXPORT size_t language_get_world_counter(void) LANGUAGE_NOTSAFEPOINT
{
    language_task_t *ct = language_current_task;
    if (ct->ptls->in_pure_callback)
        return ~(size_t)0;
    return language_atomic_load_acquire(&language_world_counter);
}

LANGUAGE_DLLEXPORT size_t language_get_tls_world_age(void) LANGUAGE_NOTSAFEPOINT
{
    return language_current_task->world_age;
}

// Compute the maximum number of times to unroll Varargs{T}, based on
// m->max_varargs (if specified) or a heuristic based on the maximum
// number of non-varargs arguments in the provided method table.
//
// If provided, `may_increase` is set to 1 if the returned value is
// heuristic-based and has a chance of increasing in the future.
static size_t get_max_varargs(
        language_method_t *m,
        language_methtable_t *kwmt,
        language_methtable_t *mt,
        uint8_t *may_increase) LANGUAGE_NOTSAFEPOINT
{
    size_t max_varargs = 1;
    if (may_increase != NULL)
        *may_increase = 0;

    if (m->max_varargs != UINT8_MAX)
        max_varargs = m->max_varargs;
    else if (kwmt != NULL && kwmt != language_type_type_mt && kwmt != language_nonfunction_mt && kwmt != language_kwcall_mt) {
        if (may_increase != NULL)
            *may_increase = 1; // `max_args` can increase as new methods are inserted

        max_varargs = language_atomic_load_relaxed(&kwmt->max_args) + 2;
        if (mt == language_kwcall_mt)
            max_varargs += 2;
        max_varargs -= m->nargs;
    }
    return max_varargs;
}

/// ----- Handling for Julia callbacks ----- ///

LANGUAGE_DLLEXPORT int8_t language_is_in_pure_context(void)
{
    language_task_t *ct = language_current_task;
    return ct->ptls->in_pure_callback;
}

tracer_cb language_newmeth_tracer = NULL;
LANGUAGE_DLLEXPORT void language_register_newmeth_tracer(void (*callback)(language_method_t *tracee))
{
    language_newmeth_tracer = (tracer_cb)callback;
}

void language_call_tracer(tracer_cb callback, language_value_t *tracee)
{
    language_task_t *ct = language_current_task;
    int last_in = ct->ptls->in_pure_callback;
    LANGUAGE_TRY {
        ct->ptls->in_pure_callback = 1;
        callback(tracee);
        ct->ptls->in_pure_callback = last_in;
    }
    LANGUAGE_CATCH {
        ct->ptls->in_pure_callback = last_in;
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "WARNING: tracer callback function threw an error:\n");
        language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, language_current_exception(ct));
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
        languagebacktrace(); // written to STDERR_FILENO
    }
}

/// ----- Definitions for various internal TypeMaps ----- ///

static int8_t language_cachearg_offset(language_methtable_t *mt)
{
    return mt->offs;
}

/// ----- Insertion logic for special entries ----- ///


static uint_t speccache_hash(size_t idx, language_value_t *data)
{
    language_method_instance_t *ml = (language_method_instance_t*)language_svecref(data, idx); // This must always happen inside the lock
    language_value_t *sig = ml->specTypes;
    if (language_is_unionall(sig))
        sig = language_unwrap_unionall(sig);
    return ((language_datatype_t*)sig)->hash;
}

static int speccache_eq(size_t idx, const void *ty, language_value_t *data, uint_t hv)
{
    if (idx >= language_svec_len(data))
        return 0; // We got a OOB access, probably due to a data race
    language_method_instance_t *ml = (language_method_instance_t*)language_svecref(data, idx);
    language_value_t *sig = ml->specTypes;
    if (ty == sig)
        return 1;
    uint_t h2 = ((language_datatype_t*)(language_is_unionall(sig) ? language_unwrap_unionall(sig) : sig))->hash;
    if (h2 != hv)
        return 0;
    return language_types_equal(sig, (language_value_t*)ty);
}

// get or create the MethodInstance for a specialization
static language_method_instance_t *language_specializations_get_linfo_(language_method_t *m LANGUAGE_PROPAGATES_ROOT, language_value_t *type, language_svec_t *sparams, language_method_instance_t *mi_insert)
{
    if (m->sig == (language_value_t*)language_anytuple_type && language_atomic_load_relaxed(&m->unspecialized) != NULL && m != language_opaque_closure_method && !m->is_for_opaque_closure)
        return language_atomic_load_relaxed(&m->unspecialized); // handle builtin methods
    language_value_t *ut = language_is_unionall(type) ? language_unwrap_unionall(type) : type;
    LANGUAGE_TYPECHK(specializations, datatype, ut);
    uint_t hv = ((language_datatype_t*)ut)->hash;
    language_genericmemory_t *speckeyset = NULL;
    language_value_t *specializations = NULL;
    size_t i = -1, cl = 0, lastcl;
    for (int locked = 0; locked < 2; locked++) {
        if (locked) {
            if (!sparams) // can't insert without knowing this
                return NULL;
            LANGUAGE_LOCK(&m->writelock);
        }
        lastcl = cl;
        speckeyset = language_atomic_load_acquire(&m->speckeyset);
        specializations = language_atomic_load_relaxed(&m->specializations);
        if (specializations == (language_value_t*)language_emptysvec)
            continue;
        if (!language_is_svec(specializations)) {
            language_method_instance_t *mi = (language_method_instance_t*)specializations;
            if (language_types_equal(mi->specTypes, type)) {
                if (locked)
                    LANGUAGE_UNLOCK(&m->writelock);
                return mi;
            }
            continue;
        }
        cl = language_svec_len(specializations);
        if (hv) {
            ssize_t idx = language_smallintset_lookup(speckeyset, speccache_eq, type, specializations, hv, 0);
            if (idx != -1) {
                language_method_instance_t *mi = (language_method_instance_t*)language_svecref(specializations, idx);
                if (locked)
                    LANGUAGE_UNLOCK(&m->writelock);
                return mi;
            }
        }
        else {
            _Atomic(language_method_instance_t*) *data = (_Atomic(language_method_instance_t*)*)language_svec_data(specializations);
            LANGUAGE_GC_PUSH1(&specializations); // clang-sa doesn't realize this loop uses specializations
            // the last lastcl-i-1 elements are already checked when locked, so start search with the new elements only
            for (i += cl - lastcl; i > 0; i--) {
                language_method_instance_t *mi = language_atomic_load_relaxed(&data[i]);
                if ((language_value_t*)mi == language_nothing)
                    break;
                if (language_types_equal(mi->specTypes, type)) {
                    if (locked)
                        LANGUAGE_UNLOCK(&m->writelock);
                    LANGUAGE_GC_POP();
                    return mi;
                }
            }
            // i points to the first unchecked element, or the place to insert
            LANGUAGE_GC_POP();
        }
    }
    language_method_instance_t *mi = mi_insert ? mi_insert : language_get_specialized(m, type, sparams);
    if (specializations == (language_value_t*)language_emptysvec) {
        language_atomic_store_release(&m->specializations, (language_value_t*)mi);
        language_gc_wb(m, mi);
    }
    else {
        LANGUAGE_GC_PUSH1(&mi);
        if (!language_is_svec(specializations)) {
            language_method_instance_t *mi = (language_method_instance_t*)specializations;
            language_value_t *type = mi->specTypes;
            language_value_t *ut = language_is_unionall(type) ? language_unwrap_unionall(type) : type;
            uint_t hv = ((language_datatype_t*)ut)->hash;
            cl = 7;
            i = cl - 1;
            specializations = (language_value_t*)language_svec_fill(cl, language_nothing);
            language_svecset(specializations, hv ? 0 : i--, mi);
            language_atomic_store_release(&m->specializations, specializations);
            language_gc_wb(m, specializations);
            if (hv)
                language_smallintset_insert(&m->speckeyset, (language_value_t*)m, speccache_hash, 0, specializations);
        }
        if (hv) {
            _Atomic(language_method_instance_t*) *data = (_Atomic(language_method_instance_t*)*)language_svec_data(specializations);
            for (i = 0; i < cl; i++) {
                language_method_instance_t *mi = language_atomic_load_relaxed(&data[i]);
                if ((language_value_t*)mi == language_nothing)
                    break;
                assert(!language_types_equal(mi->specTypes, type));
            }
            // i points at the place to insert
        }
        if (hv ? (i + 1 >= cl || language_svecref(specializations, i + 1) != language_nothing) : (i <= 1 || language_svecref(specializations, i - 2) != language_nothing)) {
            size_t ncl = cl < 7 ? 7 : (cl*3)>>1;
            language_svec_t *nc = language_alloc_svec_uninit(ncl);
            if (i > 0)
                memcpy((char*)language_svec_data(nc), language_svec_data(specializations), sizeof(void*) * i);
            for (int j = 0; j < ncl - cl; j++)
                language_svecset(nc, j+i, language_nothing);
            if (i < cl)
                memcpy((char*)language_svec_data(nc) + sizeof(void*) * (i + ncl - cl),
                       (char*)language_svec_data(specializations) + sizeof(void*) * i,
                       sizeof(void*) * (cl - i));
            specializations = (language_value_t*)nc;
            language_atomic_store_release(&m->specializations, specializations);
            language_gc_wb(m, specializations);
            if (!hv)
                i += ncl - cl;
        }
        assert(language_svecref(specializations, i) == language_nothing);
        language_svecset(specializations, i, mi);
        if (hv)
            language_smallintset_insert(&m->speckeyset, (language_value_t*)m, speccache_hash, i, specializations);
        LANGUAGE_GC_POP();
    }
    LANGUAGE_UNLOCK(&m->writelock); // may gc
    return mi;
}

LANGUAGE_DLLEXPORT language_method_instance_t *language_specializations_get_linfo(language_method_t *m LANGUAGE_PROPAGATES_ROOT, language_value_t *type, language_svec_t *sparams)
{
    return language_specializations_get_linfo_(m, type, sparams, NULL);
}

language_method_instance_t *language_specializations_get_or_insert(language_method_instance_t *mi)
{
    language_method_t *m = mi->def.method;
    language_value_t *type = mi->specTypes;
    language_svec_t *sparams = mi->sparam_vals;
    return language_specializations_get_linfo_(m, type, sparams, mi);
}

LANGUAGE_DLLEXPORT language_value_t *language_specializations_lookup(language_method_t *m, language_value_t *type)
{
    language_value_t *mi = (language_value_t*)language_specializations_get_linfo(m, type, NULL);
    if (mi == NULL)
        return language_nothing;
    return mi;
}

LANGUAGE_DLLEXPORT language_value_t *language_methtable_lookup(language_methtable_t *mt, language_value_t *type, size_t world)
{
    // TODO: this is sort of an odd lookup strategy (and the only user of
    // language_typemap_assoc_by_type with subtype=0), while normally language_gf_invoke_lookup would be
    // expected to be used instead
    struct language_typemap_assoc search = {type, world, NULL};
    language_typemap_entry_t *sf = language_typemap_assoc_by_type(language_atomic_load_relaxed(&mt->defs), &search, language_cachearg_offset(mt), /*subtype*/0);
    if (!sf)
        return language_nothing;
    return sf->func.value;
}

// ----- MethodInstance specialization instantiation ----- //

language_datatype_t *language_mk_builtin_func(language_datatype_t *dt, const char *name, language_fptr_args_t fptr) LANGUAGE_GC_DISABLED
{
    language_sym_t *sname = language_symbol(name);
    if (dt == NULL) {
        language_value_t *f = language_new_generic_function_with_supertype(sname, language_core_module, language_builtin_type);
        language_set_const(language_core_module, sname, f);
        dt = (language_datatype_t*)language_typeof(f);
    }

    language_method_t *m = language_new_method_uninit(language_core_module);
    m->name = sname;
    m->module = language_core_module;
    m->isva = 1;
    m->nargs = 2;
    language_atomic_store_relaxed(&m->primary_world, 1);
    language_atomic_store_relaxed(&m->deleted_world, ~(size_t)0);
    m->sig = (language_value_t*)language_anytuple_type;
    m->slot_syms = language_an_empty_string;
    m->nospecialize = 0;
    m->nospecialize = ~m->nospecialize;

    language_methtable_t *mt = dt->name->mt;
    language_typemap_entry_t *newentry = NULL;
    LANGUAGE_GC_PUSH2(&m, &newentry);

    newentry = language_typemap_alloc(language_anytuple_type, NULL, language_emptysvec,
            (language_value_t*)m, language_atomic_load_relaxed(&m->primary_world), language_atomic_load_relaxed(&m->deleted_world));
    language_typemap_insert(&mt->defs, (language_value_t*)mt, newentry, language_cachearg_offset(mt));

    language_method_instance_t *mi = language_get_specialized(m, (language_value_t*)language_anytuple_type, language_emptysvec);
    language_atomic_store_relaxed(&m->unspecialized, mi);
    language_gc_wb(m, mi);

    language_code_instance_t *codeinst = language_new_codeinst(mi, language_nothing,
        (language_value_t*)language_any_type, (language_value_t*)language_any_type, language_nothing, language_nothing,
        0, 1, ~(size_t)0, 0, language_nothing, 0, NULL);
    language_mi_cache_insert(mi, codeinst);
    language_atomic_store_relaxed(&codeinst->specptr.fptr1, fptr);
    language_atomic_store_relaxed(&codeinst->invoke, language_fptr_args);

    newentry = language_typemap_alloc(language_anytuple_type, NULL, language_emptysvec,
            (language_value_t*)mi, 1, ~(size_t)0);
    language_typemap_insert(&mt->cache, (language_value_t*)mt, newentry, 0);

    mt->frozen = 1;
    LANGUAGE_GC_POP();
    return dt;
}

// run type inference on lambda "mi" for given argument types.
// returns the inferred source, and may cache the result in mi
// if successful, also updates the mi argument to describe the validity of this src
// if inference doesn't occur (or can't finish), returns NULL instead
language_code_instance_t *language_type_infer(language_method_instance_t *mi, size_t world, uint8_t source_mode)
{
    if (language_typeinf_func == NULL)
        return NULL;
    language_task_t *ct = language_current_task;
    if (ct->reentrant_timing & 0b1000) {
        // We must avoid attempting to re-enter inference here
        assert(0 && "attempted to enter inference while writing out image");
        abort();
    }
    // In case we use higher bits later, mask them out
    if ((ct->reentrant_timing & 0b1111) >= 0b110)
        return NULL;

    language_code_instance_t *ci = NULL;
#ifdef ENABLE_INFERENCE
    if (language_engine_hasreserved(mi, language_nothing)) // don't recur on a thread on the same MethodInstance--force it to interpret it until the inference has finished
        return NULL;
    LANGUAGE_TIMING(INFERENCE, INFERENCE);
    language_value_t **fargs;
    LANGUAGE_GC_PUSHARGS(fargs, 4);
    fargs[0] = (language_value_t*)language_typeinf_func;
    fargs[1] = (language_value_t*)mi;
    fargs[2] = language_box_ulong(world);
    fargs[3] = language_box_uint8(source_mode);

    language_timing_show_method_instance(mi, LANGUAGE_TIMING_DEFAULT_BLOCK);
#ifdef TRACE_INFERENCE
    if (mi->specTypes != (language_value_t*)language_emptytuple_type) {
        language_printf(LANGUAGE_STDERR,"inference on ");
        language_static_show_func_sig(LANGUAGE_STDERR, (language_value_t*)mi->specTypes);
        language_printf(LANGUAGE_STDERR, "\n");
    }
#endif
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    int last_pure = ct->ptls->in_pure_callback;
    ct->ptls->in_pure_callback = 0;
    size_t last_age = ct->world_age;
    ct->world_age = language_typeinf_world;
    // first bit is for reentrant timing,
    // so adding 1 to the bit above performs
    // inference reentrancy counter addition.
    // Note that this is only safe because
    // the counter varies from 0-3; if we
    // increase that limit, we'll need to
    // allocate another bit for the counter.
    ct->reentrant_timing += 0b10;
    LANGUAGE_TRY {
        ci = (language_code_instance_t*)language_apply(fargs, 4);
    }
    LANGUAGE_CATCH {
        language_value_t *e = language_current_exception(ct);
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "Internal error: during type inference of\n");
        language_static_show_func_sig((LANGUAGE_STREAM*)STDERR_FILENO, (language_value_t*)mi->specTypes);
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\nEncountered ");
        if (e == language_stackovf_exception) {
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "stack overflow.\n");
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "This might be caused by recursion over very long tuples or argument lists.\n");
        }
        else {
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "unexpected error in runtime:\n");
            language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, e);
            language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n");
            languagebacktrace(); // written to STDERR_FILENO
        }
        ci = NULL;
#ifndef LANGUAGE_NDEBUG
        abort();
#endif
    }
    ct->world_age = last_age;
    ct->reentrant_timing -= 0b10;
    ct->ptls->in_pure_callback = last_pure;
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;

    if (ci && !language_is_code_instance(ci)) {
        ci = NULL;
    }
    LANGUAGE_GC_POP();
#endif

    return ci;
}

// Attempt to run `Core.Compiler.code_typed` on the lambda "mi"
LANGUAGE_DLLEXPORT language_code_info_t *language_gdbcodetyped1(language_method_instance_t *mi, size_t world)
{
    language_task_t *ct = language_current_task;
    language_code_info_t *ci = NULL;
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    int last_pure = ct->ptls->in_pure_callback;
    ct->ptls->in_pure_callback = 0;
    size_t last_age = ct->world_age;
    ct->world_age = language_typeinf_world;
    language_value_t **fargs;
    LANGUAGE_GC_PUSHARGS(fargs, 4);
    language_module_t *CC = (language_module_t*)language_get_global(language_core_module, language_symbol("Compiler"));
    if (CC != NULL && language_is_module(CC)) {
        fargs[0] = language_get_global(CC, language_symbol("NativeInterpreter"));;
        fargs[1] = language_box_ulong(world);
        fargs[1] = language_apply(fargs, 2);
        fargs[0] = language_get_global(CC, language_symbol("typeinf_code"));
        fargs[2] = (language_value_t*)mi;
        fargs[3] = language_true;
        ci = (language_code_info_t*)language_apply(fargs, 4);
    }
    ct->world_age = last_age;
    ct->ptls->in_pure_callback = last_pure;
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;
    if (ci && !language_is_code_info(ci)) {
        ci = NULL;
    }
    LANGUAGE_GC_POP();
    return ci;
}

LANGUAGE_DLLEXPORT language_value_t *language_call_in_typeinf_world(language_value_t **args, int nargs)
{
    language_task_t *ct = language_current_task;
    size_t last_age = ct->world_age;
    ct->world_age = language_typeinf_world;
    language_value_t *ret = language_apply(args, nargs);
    ct->world_age = last_age;
    return ret;
}

LANGUAGE_DLLEXPORT language_code_instance_t *language_get_method_inferred(
        language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT, language_value_t *rettype,
        size_t min_world, size_t max_world, language_debuginfo_t *edges)
{
    language_value_t *owner = language_nothing; // TODO: owner should be arg
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mi->cache);
    while (codeinst) {
        if (language_atomic_load_relaxed(&codeinst->min_world) == min_world &&
            language_atomic_load_relaxed(&codeinst->max_world) == max_world &&
            language_egal(codeinst->owner, owner) &&
            language_egal(codeinst->rettype, rettype)) {
            if (edges == NULL)
                return codeinst;
            language_debuginfo_t *debuginfo = language_atomic_load_relaxed(&codeinst->debuginfo);
            if (edges == debuginfo)
                return codeinst;
            if (debuginfo == NULL && language_atomic_cmpswap_relaxed(&codeinst->debuginfo, &debuginfo, edges))
                return codeinst;
            if (debuginfo && language_egal((language_value_t*)debuginfo, (language_value_t*)edges))
                return codeinst;
        }
        codeinst = language_atomic_load_relaxed(&codeinst->next);
    }
    codeinst = language_new_codeinst(
        mi, owner, rettype, (language_value_t*)language_any_type, NULL, NULL,
        0, min_world, max_world, 0, language_nothing, 0, edges);
    language_mi_cache_insert(mi, codeinst);
    return codeinst;
}

LANGUAGE_DLLEXPORT int language_mi_cache_has_ci(language_method_instance_t *mi,
                                     language_code_instance_t *ci)
{
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mi->cache);
    while (codeinst) {
        if (codeinst == ci)
            return 1;
        codeinst = language_atomic_load_relaxed(&codeinst->next);
    }
    return 0;
}

LANGUAGE_DLLEXPORT language_code_instance_t *language_new_codeinst(
        language_method_instance_t *mi, language_value_t *owner,
        language_value_t *rettype, language_value_t *exctype,
        language_value_t *inferred_const, language_value_t *inferred,
        int32_t const_flags, size_t min_world, size_t max_world,
        uint32_t effects, language_value_t *analysis_results,
        uint8_t relocatability,
        language_debuginfo_t *edges /* , int absolute_max*/)
{
    language_task_t *ct = language_current_task;
    assert(min_world <= max_world && "attempting to set invalid world constraints");
    language_code_instance_t *codeinst = (language_code_instance_t*)language_gc_alloc(ct->ptls, sizeof(language_code_instance_t),
            language_code_instance_type);
    codeinst->def = mi;
    codeinst->owner = owner;
    language_atomic_store_relaxed(&codeinst->min_world, min_world);
    language_atomic_store_relaxed(&codeinst->max_world, max_world);
    codeinst->rettype = rettype;
    codeinst->exctype = exctype;
    language_atomic_store_release(&codeinst->inferred, inferred);
    if ((const_flags & 2) == 0)
        inferred_const = NULL;
    codeinst->rettype_const = inferred_const;
    language_atomic_store_relaxed(&codeinst->debuginfo, (language_value_t*)edges == language_nothing ? NULL : edges);
    language_atomic_store_relaxed(&codeinst->specptr.fptr, NULL);
    language_atomic_store_relaxed(&codeinst->invoke, NULL);
    if ((const_flags & 1) != 0) {
        assert(const_flags & 2);
        language_atomic_store_relaxed(&codeinst->invoke, language_fptr_const_return);
    }
    language_atomic_store_relaxed(&codeinst->specsigflags, 0);
    language_atomic_store_relaxed(&codeinst->precompile, 0);
    language_atomic_store_relaxed(&codeinst->next, NULL);
    language_atomic_store_relaxed(&codeinst->ipo_purity_bits, effects);
    codeinst->analysis_results = analysis_results;
    codeinst->relocatability = relocatability;
    return codeinst;
}

LANGUAGE_DLLEXPORT void language_update_codeinst(
        language_code_instance_t *codeinst, language_value_t *inferred,
        int32_t const_flags, size_t min_world, size_t max_world,
        uint32_t effects, language_value_t *analysis_results,
        uint8_t relocatability, language_debuginfo_t *edges /* , int absolute_max*/)
{
    codeinst->relocatability = relocatability;
    codeinst->analysis_results = analysis_results;
    language_gc_wb(codeinst, analysis_results);
    language_atomic_store_relaxed(&codeinst->ipo_purity_bits, effects);
    language_atomic_store_relaxed(&codeinst->debuginfo, edges);
    language_gc_wb(codeinst, edges);
    if ((const_flags & 1) != 0) {
        assert(codeinst->rettype_const);
        language_atomic_store_release(&codeinst->invoke, language_fptr_const_return);
    }
    language_atomic_store_release(&codeinst->inferred, inferred);
    language_gc_wb(codeinst, inferred);
    language_atomic_store_relaxed(&codeinst->min_world, min_world); // XXX: these should be unchanged?
    language_atomic_store_relaxed(&codeinst->max_world, max_world); // since the edges shouldn't change after language_fill_codeinst
}

LANGUAGE_DLLEXPORT void language_fill_codeinst(
        language_code_instance_t *codeinst,
        language_value_t *rettype, language_value_t *exctype,
        language_value_t *inferred_const,
        int32_t const_flags, size_t min_world, size_t max_world,
        uint32_t effects, language_value_t *analysis_results,
        language_debuginfo_t *edges /* , int absolute_max*/)
{
    assert(min_world <= max_world && "attempting to set invalid world constraints");
    codeinst->rettype = rettype;
    language_gc_wb(codeinst, rettype);
    codeinst->exctype = exctype;
    language_gc_wb(codeinst, exctype);
    if ((const_flags & 2) != 0) {
        codeinst->rettype_const = inferred_const;
        language_gc_wb(codeinst, inferred_const);
    }
    language_atomic_store_relaxed(&codeinst->debuginfo, (language_value_t*)edges == language_nothing ? NULL : edges);
    language_gc_wb(codeinst, edges);
    if ((const_flags & 1) != 0) {
        // TODO: may want to follow ordering restrictions here (see jitlayers.cpp)
        assert(const_flags & 2);
        language_atomic_store_release(&codeinst->invoke, language_fptr_const_return);
    }
    language_atomic_store_relaxed(&codeinst->ipo_purity_bits, effects);
    codeinst->analysis_results = analysis_results;
    assert(language_atomic_load_relaxed(&codeinst->min_world) == 1);
    assert(language_atomic_load_relaxed(&codeinst->max_world) == 0);
    language_atomic_store_release(&codeinst->min_world, min_world);
    language_atomic_store_release(&codeinst->max_world, max_world);
}

LANGUAGE_DLLEXPORT language_code_instance_t *language_new_codeinst_uninit(language_method_instance_t *mi, language_value_t *owner)
{
    language_code_instance_t *codeinst = language_new_codeinst(mi, owner, NULL, NULL, NULL, NULL, 0, 0, 0, 0, NULL, 0, NULL);
    language_atomic_store_relaxed(&codeinst->min_world, 1); // make temporarily invalid before returning, so that language_fill_codeinst is valid later
    return codeinst;
}

LANGUAGE_DLLEXPORT void language_mi_cache_insert(language_method_instance_t *mi LANGUAGE_ROOTING_ARGUMENT,
                                     language_code_instance_t *ci LANGUAGE_ROOTED_ARGUMENT LANGUAGE_MAYBE_UNROOTED)
{
    LANGUAGE_GC_PUSH1(&ci);
    if (language_is_method(mi->def.method))
        LANGUAGE_LOCK(&mi->def.method->writelock);
    language_code_instance_t *oldci = language_atomic_load_relaxed(&mi->cache);
    language_atomic_store_relaxed(&ci->next, oldci);
    if (oldci)
        language_gc_wb(ci, oldci);
    language_atomic_store_release(&mi->cache, ci);
    language_gc_wb(mi, ci);
    if (language_is_method(mi->def.method))
        LANGUAGE_UNLOCK(&mi->def.method->writelock);
    LANGUAGE_GC_POP();
    return;
}

LANGUAGE_DLLEXPORT int language_mi_try_insert(language_method_instance_t *mi LANGUAGE_ROOTING_ARGUMENT,
                                   language_code_instance_t *expected_ci,
                                   language_code_instance_t *ci LANGUAGE_ROOTED_ARGUMENT LANGUAGE_MAYBE_UNROOTED)
{
    LANGUAGE_GC_PUSH1(&ci);
    if (language_is_method(mi->def.method))
        LANGUAGE_LOCK(&mi->def.method->writelock);
    language_code_instance_t *oldci = language_atomic_load_relaxed(&mi->cache);
    int ret = 0;
    if (oldci == expected_ci) {
        language_atomic_store_relaxed(&ci->next, oldci);
        if (oldci)
            language_gc_wb(ci, oldci);
        language_atomic_store_release(&mi->cache, ci);
        language_gc_wb(mi, ci);
        ret = 1;
    }
    if (language_is_method(mi->def.method))
        LANGUAGE_UNLOCK(&mi->def.method->writelock);
    LANGUAGE_GC_POP();
    return ret;
}

static int get_method_unspec_list(language_typemap_entry_t *def, void *closure)
{
    size_t world = language_atomic_load_acquire(&language_world_counter);
    language_value_t *specializations = language_atomic_load_relaxed(&def->func.method->specializations);
    if (specializations == (language_value_t*)language_emptysvec)
        return 1;
    if (!language_is_svec(specializations)) {
        language_method_instance_t *mi = (language_method_instance_t*)specializations;
        assert(language_is_method_instance(mi));
        if (language_rettype_inferred_native(mi, world, world) == language_nothing)
            language_array_ptr_1d_push((language_array_t*)closure, (language_value_t*)mi);
        return 1;
    }
    size_t i, l = language_svec_len(specializations);
    LANGUAGE_GC_PUSH1(&specializations);
    for (i = 0; i < l; i++) {
        language_method_instance_t *mi = (language_method_instance_t*)language_svecref(specializations, i);
        if ((language_value_t*)mi != language_nothing) {
            assert(language_is_method_instance(mi));
            if (language_rettype_inferred_native(mi, world, world) == language_nothing)
                language_array_ptr_1d_push((language_array_t*)closure, (language_value_t*)mi);
        }
    }
    LANGUAGE_GC_POP();
    return 1;
}

int foreach_mtable_in_module(
        language_module_t *m,
        int (*visit)(language_methtable_t *mt, void *env),
        void *env)
{
    language_svec_t *table = language_atomic_load_relaxed(&m->bindings);
    for (size_t i = 0; i < language_svec_len(table); i++) {
        language_binding_t *b = (language_binding_t*)language_svecref(table, i);
        if ((void*)b == language_nothing)
            break;
        language_sym_t *name = b->globalref->name;
        if (language_atomic_load_relaxed(&b->owner) == b && b->constp) {
            language_value_t *v = language_atomic_load_relaxed(&b->value);
            if (v) {
                language_value_t *uw = language_unwrap_unionall(v);
                if (language_is_datatype(uw)) {
                    language_typename_t *tn = ((language_datatype_t*)uw)->name;
                    if (tn->module == m && tn->name == name && tn->wrapper == v) {
                        // this is the original/primary binding for the type (name/wrapper)
                        language_methtable_t *mt = tn->mt;
                        if (mt != NULL && (language_value_t*)mt != language_nothing && mt != language_type_type_mt && mt != language_nonfunction_mt) {
                            assert(mt->module == m);
                            if (!visit(mt, env))
                                return 0;
                        }
                    }
                }
                else if (language_is_module(v)) {
                    language_module_t *child = (language_module_t*)v;
                    if (child != m && child->parent == m && child->name == name) {
                        // this is the original/primary binding for the submodule
                        if (!foreach_mtable_in_module(child, visit, env))
                            return 0;
                    }
                }
                else if (language_is_mtable(v)) {
                    language_methtable_t *mt = (language_methtable_t*)v;
                    if (mt->module == m && mt->name == name) {
                        // this is probably an external method table here, so let's
                        // assume so as there is no way to precisely distinguish them
                        if (!visit(mt, env))
                            return 0;
                    }
                }
            }
        }
        table = language_atomic_load_relaxed(&m->bindings);
    }
    return 1;
}

int language_foreach_reachable_mtable(int (*visit)(language_methtable_t *mt, void *env), void *env)
{
    if (!visit(language_type_type_mt, env))
        return 0;
    if (!visit(language_nonfunction_mt, env))
        return 0;
    language_array_t *mod_array = language_get_loaded_modules();
    if (mod_array) {
        LANGUAGE_GC_PUSH1(&mod_array);
        int i;
        for (i = 0; i < language_array_nrows(mod_array); i++) {
            language_module_t *m = (language_module_t*)language_array_ptr_ref(mod_array, i);
            assert(language_is_module(m));
            if (m->parent == m) // some toplevel modules (really just Base) aren't actually
                if (!foreach_mtable_in_module(m, visit, env)) {
                    LANGUAGE_GC_POP();
                    return 0;
                }
        }
        LANGUAGE_GC_POP();
    }
    else {
        if (!foreach_mtable_in_module(language_main_module, visit, env))
            return 0;
        if (!foreach_mtable_in_module(language_core_module, visit, env))
            return 0;
    }
    return 1;
}

static int reset_mt_caches(language_methtable_t *mt, void *env)
{
    // removes all method caches
    // this might not be entirely safe (GC or MT), thus we only do it very early in bootstrapping
    if (!mt->frozen) { // make sure not to reset builtin functions
        language_atomic_store_release(&mt->leafcache, (language_genericmemory_t*)language_an_empty_memory_any);
        language_atomic_store_release(&mt->cache, language_nothing);
    }
    language_typemap_visitor(language_atomic_load_relaxed(&mt->defs), get_method_unspec_list, env);
    return 1;
}


language_function_t *language_typeinf_func LANGUAGE_GLOBALLY_ROOTED = NULL;
LANGUAGE_DLLEXPORT size_t language_typeinf_world = 1;

LANGUAGE_DLLEXPORT void language_set_typeinf_func(language_value_t *f)
{
    size_t newfunc = language_typeinf_world == 1 && language_typeinf_func == NULL;
    language_typeinf_func = (language_function_t*)f;
    language_typeinf_world = language_get_tls_world_age();
    int world = language_atomic_fetch_add(&language_world_counter, 1) + 1; // make type-inference the only thing in this world
    if (newfunc) {
        // give type inference a chance to see all of these
        // TODO: also reinfer if max_world != ~(size_t)0
        language_array_t *unspec = language_alloc_vec_any(0);
        LANGUAGE_GC_PUSH1(&unspec);
        language_foreach_reachable_mtable(reset_mt_caches, (void*)unspec);
        size_t i, l;
        for (i = 0, l = language_array_nrows(unspec); i < l; i++) {
            language_method_instance_t *mi = (language_method_instance_t*)language_array_ptr_ref(unspec, i);
            if (language_rettype_inferred_native(mi, world, world) == language_nothing)
                language_type_infer(mi, world, SOURCE_MODE_NOT_REQUIRED);
        }
        LANGUAGE_GC_POP();
    }
}

static int very_general_type(language_value_t *t)
{
    return (t == (language_value_t*)language_any_type || language_types_equal(t, (language_value_t*)language_type_type));
}

language_value_t *language_nth_slot_type(language_value_t *sig, size_t i) LANGUAGE_NOTSAFEPOINT
{
    sig = language_unwrap_unionall(sig);
    size_t len = language_nparams(sig);
    if (i < len-1)
        return language_tparam(sig, i);
    language_value_t *p = language_tparam(sig, len-1);
    if (language_is_vararg(p))
        p = language_unwrap_vararg(p);
    return p;
}

// if concrete_match returns false, the sig may specify `Type{T::DataType}`, while the `tt` contained DataType
// in this case, subtyping is wrong, and this may not actually match at runtime
// since it may instead match any kind of `Type{T::Type}`
//static int concrete_match(language_tupletype_t *tt, language_value_t *sig)
//{
//    size_t i, np;
//    for (i = 0, np = language_nparams(tt); i < np; i++) {
//        language_value_t *elt = language_tparam(tt, i);
//        language_value_t *decl_i = language_nth_slot_type((language_value_t*)sig, i);
//        if (language_is_kind(elt)) {
//            // check whether this match may be exact at runtime
//            if (!language_subtype(elt, decl_i))
//                return 0;
//        }
//    }
//    return 1;
//}

static language_value_t *inst_varargp_in_env(language_value_t *decl, language_svec_t *sparams)
{
    language_value_t *unw = language_unwrap_unionall(decl);
    language_value_t *vm = language_tparam(unw, language_nparams(unw) - 1);
    assert(language_is_vararg(vm));
    int nsp = language_svec_len(sparams);
    if (nsp > 0 && language_has_free_typevars(vm)) {
        LANGUAGE_GC_PUSH1(&vm);
        assert(language_subtype_env_size(decl) == nsp);
        vm = language_instantiate_type_in_env(vm, (language_unionall_t*)decl, language_svec_data(sparams));
        assert(language_is_vararg(vm));
        // rewrap_unionall(lastdeclt, sparams) if any sparams isa TypeVar
        // for example, `Tuple{Vararg{Union{Nothing,Int,Val{T}}}} where T`
        // and the user called it with `Tuple{Vararg{Union{Nothing,Int},N}}`, then T is unbound
        language_value_t **sp = language_svec_data(sparams);
        while (language_is_unionall(decl)) {
            language_tvar_t *v = (language_tvar_t*)*sp;
            if (language_is_typevar(v)) {
                // must unwrap and re-wrap Vararg object explicitly here since language_type_unionall handles it differently
                language_value_t *T = ((language_vararg_t*)vm)->T;
                language_value_t *N = ((language_vararg_t*)vm)->N;
                int T_has_tv = T && language_has_typevar(T, v);
                int N_has_tv = N && language_has_typevar(N, v); // n.b. LANGUAGE_VARARG_UNBOUND check means this should be false
                assert(!N_has_tv || N == (language_value_t*)v);
                vm = T_has_tv ? language_type_unionall(v, T) : T;
                if (N_has_tv)
                    N = NULL;
                vm = (language_value_t*)language_wrap_vararg(vm, N, 1, 0); // this cannot throw for these inputs
            }
            sp++;
            decl = ((language_unionall_t*)decl)->body;
            nsp--;
        }
        assert(nsp == 0);
        LANGUAGE_GC_POP();
    }
    return vm;
}

static language_value_t *ml_matches(language_methtable_t *mt,
                              language_tupletype_t *type, int lim, int include_ambiguous,
                              int intersections, size_t world, int cache_result,
                              size_t *min_valid, size_t *max_valid, int *ambig);

// get the compilation signature specialization for this method
static void language_compilation_sig(
    language_tupletype_t *const tt, // the original tupletype of the call (or DataType from precompile)
    language_svec_t *sparams,
    language_method_t *definition,
    intptr_t max_varargs,
    // output:
    language_svec_t **const newparams LANGUAGE_REQUIRE_ROOTED_SLOT)
{
    assert(language_is_tuple_type(tt));
    language_value_t *decl = definition->sig;
    size_t nargs = definition->nargs; // == language_nparams(language_unwrap_unionall(decl));
    size_t nspec = max_varargs + nargs;

    if (definition->generator) {
        // staged functions aren't optimized
        // so assume the caller was intelligent about calling us
        return;
    }

    if (decl == (language_value_t*)language_anytuple_type && language_atomic_load_relaxed(&definition->unspecialized)) {
        *newparams = language_anytuple_type->parameters; // handle builtin methods
        return;
    }

    // some early sanity checks
    size_t i, np = language_nparams(tt);
    switch (language_va_tuple_kind((language_datatype_t*)decl)) {
    case LANGUAGE_VARARG_NONE:
        if (language_is_va_tuple(tt))
            // odd
            return;
        if (np != nargs)
            // there are not enough input parameters to make this into a compilation sig
            return;
        break;
    case LANGUAGE_VARARG_INT:
    case LANGUAGE_VARARG_BOUND:
        if (language_is_va_tuple(tt))
            // the length needed is not known, but required for compilation
            return;
        if (np < nargs - 1)
            // there are not enough input parameters to make this into a compilation sig
            return;
        break;
    case LANGUAGE_VARARG_UNBOUND:
        if (np < nspec && language_is_va_tuple(tt))
            // there are insufficient given parameters for language_isa_compileable_sig now to like this type
            // (there were probably fewer methods defined when we first selected this signature, or
            //  the max varargs limit was not reached indicating the type is already fully-specialized)
            return;
        break;
    }

    language_value_t *type_i = NULL;
    LANGUAGE_GC_PUSH1(&type_i);
    for (i = 0; i < np; i++) {
        language_value_t *elt = language_tparam(tt, i);
        if (language_is_vararg(elt))
            elt = language_unwrap_vararg(elt);
        language_value_t *decl_i = language_nth_slot_type(decl, i);
        type_i = language_rewrap_unionall(decl_i, decl);
        size_t i_arg = (i < nargs - 1 ? i : nargs - 1);

        if (language_is_kind(type_i)) {
            // if we can prove the match was against the kind (not a Type)
            // we want to put that in the cache instead
            if (!*newparams) *newparams = language_svec_copy(tt->parameters);
            elt = type_i;
            language_svecset(*newparams, i, elt);
        }
        else if (language_is_type_type(elt)) {
            // if the declared type was not Any or Union{Type, ...},
            // then the match must been with the kind (e.g. UnionAll or DataType)
            // and the result of matching the type signature
            // needs to be restricted to the concrete type 'kind'
            language_value_t *kind = language_typeof(language_tparam0(elt));
            if (language_subtype(kind, type_i) && !language_subtype((language_value_t*)language_type_type, type_i)) {
                // if we can prove the match was against the kind (not a Type)
                // it's simpler (and thus better) to put that cache instead
                if (!*newparams) *newparams = language_svec_copy(tt->parameters);
                elt = kind;
                language_svecset(*newparams, i, elt);
            }
        }
        else if (language_is_kind(elt)) {
            // not triggered for isdispatchtuple(tt), this attempts to handle
            // some cases of adapting a random signature into a compilation signature
            // if we get a kind, where we don't expect to accept one, widen it to something more expected (Type{T})
            if (!(language_subtype(elt, type_i) && !language_subtype((language_value_t*)language_type_type, type_i))) {
                if (!*newparams) *newparams = language_svec_copy(tt->parameters);
                elt = (language_value_t*)language_type_type;
                language_svecset(*newparams, i, elt);
            }
        }


        if (language_is_kind(elt)) {
            // kind slots always need guard entries (checking for subtypes of Type)
            continue;
        }

        if (i_arg > 0 && i_arg <= sizeof(definition->nospecialize) * 8 &&
                (definition->nospecialize & (1 << (i_arg - 1)))) {
            if (!language_has_free_typevars(decl_i) && !language_is_kind(decl_i)) {
                if (decl_i != elt) {
                    if (!*newparams) *newparams = language_svec_copy(tt->parameters);
                    // n.b. it is possible here that !(elt <: decl_i), if elt was something unusual from intersection
                    // so this might narrow the result slightly, though still being compatible with the declared signature
                    language_svecset(*newparams, i, (language_value_t*)decl_i);
                }
                continue;
            }
        }

        if (language_types_equal(elt, (language_value_t*)language_type_type)) { // elt == Type{T} where T
            // not triggered for isdispatchtuple(tt), this attempts to handle
            // some cases of adapting a random signature into a compilation signature
        }
        else if (!language_is_datatype(elt) && language_subtype(elt, (language_value_t*)language_type_type)) { // elt <: Type{T}
            // not triggered for isdispatchtuple(tt), this attempts to handle
            // some cases of adapting a random signature into a compilation signature
            if (!*newparams) *newparams = language_svec_copy(tt->parameters);
            language_svecset(*newparams, i, language_type_type);
        }
        else if (language_is_type_type(elt)) { // elt isa Type{T}
            if (!language_has_free_typevars(decl_i) && very_general_type(type_i)) {
                /*
                  Here's a fairly simple heuristic: if this argument slot's
                  declared type is general (Type or Any),
                  then don't specialize for every Type that got passed.

                  Since every type x has its own type Type{x}, this would be
                  excessive specialization for an Any slot.

                  This may require guard entries due to other potential matches.
                  In particular, TypeConstructors are problematic because they can
                  be alternate representations of any type. Extensionally, TC == TC.body,
                  but typeof(TC) != typeof(TC.body). This creates an ambiguity:
                  Type{TC} is type-equal to Type{TC.body}, yet a slot
                  x::TypeConstructor matches the first but not the second, while
                  also matching all other TypeConstructors. This means neither
                  Type{TC} nor TypeConstructor is more specific.

                  But don't apply this heuristic if the argument is called (issue #36783).
                */
                int iscalled = i_arg > 0 && i_arg <= 8 && (definition->called & (1 << (i_arg - 1)));
                if (!iscalled) {
                    if (!*newparams) *newparams = language_svec_copy(tt->parameters);
                    language_svecset(*newparams, i, language_type_type);
                }
            }
            else if (language_is_type_type(language_tparam0(elt)) &&
                     // try to give up on specializing type parameters for Type{Type{Type{...}}}
                     (language_is_type_type(language_tparam0(language_tparam0(elt))) || !language_has_free_typevars(decl_i))) {
                /*
                  actual argument was Type{...}, we computed its type as
                  Type{Type{...}}. we like to avoid unbounded nesting here, so
                  compile (and hopefully cache) the signature as Type{T},
                  unless something more specific like Type{Type{Int32}} was
                  actually declared. this can be determined using a type
                  intersection.
                */
                if (!*newparams) *newparams = language_svec_copy(tt->parameters);
                if (i < nargs || !definition->isva) {
                    language_value_t *di = language_type_intersection(type_i, (language_value_t*)language_type_type);
                    assert(di != (language_value_t*)language_bottom_type);
                    // issue #11355: DataType has a UID and so would take precedence in the cache
                    if (language_is_kind(di))
                        language_svecset(*newparams, i, (language_value_t*)language_type_type);
                    else
                        language_svecset(*newparams, i, di);
                }
                else {
                    language_svecset(*newparams, i, (language_value_t*)language_type_type);
                }
            }
        }

        int notcalled_func = (i_arg > 0 && i_arg <= 8 && !(definition->called & (1 << (i_arg - 1))) &&
                              !language_has_free_typevars(decl_i) &&
                              language_subtype(elt, (language_value_t*)language_function_type));
        if (notcalled_func && (type_i == (language_value_t*)language_any_type ||
                               type_i == (language_value_t*)language_function_type ||
                               (language_is_uniontype(type_i) && // Base.Callable
                                ((((language_uniontype_t*)type_i)->a == (language_value_t*)language_function_type &&
                                  ((language_uniontype_t*)type_i)->b == (language_value_t*)language_type_type) ||
                                 (((language_uniontype_t*)type_i)->b == (language_value_t*)language_function_type &&
                                  ((language_uniontype_t*)type_i)->a == (language_value_t*)language_type_type))))) {
            // and attempt to despecialize types marked Function, Callable, or Any
            // when called with a subtype of Function but is not called
            if (!*newparams) *newparams = language_svec_copy(tt->parameters);
            language_svecset(*newparams, i, (language_value_t*)language_function_type);
        }
    }

    // for varargs methods, only specialize up to max_args.
    // in general, here we want to find the biggest type that's not a
    // supertype of any other method signatures. so far we are conservative
    // and the types we find should be bigger.
    if (np >= nspec && language_va_tuple_kind((language_datatype_t*)decl) == LANGUAGE_VARARG_UNBOUND) {
        if (!*newparams) *newparams = tt->parameters;
        if (max_varargs > 0) {
            type_i = language_svecref(*newparams, nspec - 2);
        } else {
            // If max varargs is zero, always specialize to (Any...) since
            // there is no preceding parameter to use for `type_i`
            type_i = language_bottom_type;
        }
        // if all subsequent arguments are subtypes of type_i, specialize
        // on that instead of decl. for example, if decl is
        // (Any...)
        // and type is
        // (Symbol, Symbol, Symbol)
        // then specialize as (Symbol...), but if type is
        // (Symbol, Int32, Expr)
        // then specialize as (Any...)
        size_t j = nspec - 1;
        int all_are_subtypes = 1;
        for (; j < language_svec_len(*newparams); j++) {
            language_value_t *paramj = language_svecref(*newparams, j);
            if (language_is_vararg(paramj))
                paramj = language_unwrap_vararg(paramj);
            if (!language_subtype(paramj, type_i)) {
                all_are_subtypes = 0;
                break;
            }
        }
        if (all_are_subtypes) {
            // avoid Vararg{Type{Type{...}}}
            if (language_is_type_type(type_i) && language_is_type_type(language_tparam0(type_i)))
                type_i = (language_value_t*)language_type_type;
            type_i = (language_value_t*)language_wrap_vararg(type_i, (language_value_t*)NULL, 1, 0); // this cannot throw for these inputs
        }
        else {
            type_i = inst_varargp_in_env(decl, sparams);
        }
        language_svec_t *limited = language_alloc_svec(nspec);
        size_t i;
        for (i = 0; i < nspec - 1; i++) {
            language_svecset(limited, i, language_svecref(*newparams, i));
        }
        language_svecset(limited, i, type_i);
        *newparams = limited;
    }
    LANGUAGE_GC_POP();
}

// compute whether this type signature is a possible return value from language_compilation_sig given a concrete-type for `tt`
LANGUAGE_DLLEXPORT int language_isa_compileable_sig(
    language_tupletype_t *type,
    language_svec_t *sparams,
    language_method_t *definition)
{
    language_value_t *decl = definition->sig;

    if (!language_is_datatype(type) || language_has_free_typevars((language_value_t*)type))
        return 0;
    if (definition->sig == (language_value_t*)language_anytuple_type && language_atomic_load_relaxed(&definition->unspecialized))
        return language_egal((language_value_t*)type, definition->sig); // handle builtin methods

    size_t i, np = language_nparams(type);
    size_t nargs = definition->nargs; // == language_nparams(language_unwrap_unionall(decl));
    if (np == 0)
        return nargs == 0;

    if (definition->generator) {
        // staged functions aren't optimized
        // so assume the caller was intelligent about calling us
        return (definition->isva ? np >= nargs - 1 : np == nargs) && type->isdispatchtuple;
    }

    // for varargs methods, only specialize up to max_args (>= nargs + 1).
    // in general, here we want to find the biggest type that's not a
    // supertype of any other method signatures. so far we are conservative
    // and the types we find should be bigger.
    if (definition->isva) {
        unsigned nspec_min = nargs + 1; // min number of arg values (including tail vararg)
        unsigned nspec_max = INT32_MAX; // max number of arg values (including tail vararg)
        language_methtable_t *mt = language_method_table_for(decl);
        language_methtable_t *kwmt = mt == language_kwcall_mt ? language_kwmethod_table_for(decl) : mt;
        if ((language_value_t*)mt != language_nothing) {
            // try to refine estimate of min and max
            uint8_t heuristic_used = 0;
            nspec_max = nspec_min = nargs + get_max_varargs(definition, kwmt, mt, &heuristic_used);
            if (heuristic_used)
                nspec_max = INT32_MAX; // new methods may be added, increasing nspec_min later
        }
        int isunbound = (language_va_tuple_kind((language_datatype_t*)decl) == LANGUAGE_VARARG_UNBOUND);
        if (language_is_vararg(language_tparam(type, np - 1))) {
            if (!isunbound || np < nspec_min || np > nspec_max)
                return 0;
        }
        else {
            if (np < nargs - 1 || (isunbound && np >= nspec_max))
                return 0;
        }
    }
    else if (np != nargs || language_is_vararg(language_tparam(type, np - 1))) {
        return 0;
    }

    language_value_t *type_i = NULL;
    LANGUAGE_GC_PUSH1(&type_i);
    for (i = 0; i < np; i++) {
        language_value_t *elt = language_tparam(type, i);
        size_t i_arg = (i < nargs - 1 ? i : nargs - 1);

        if (language_is_vararg(elt)) {
            type_i = inst_varargp_in_env(decl, sparams);
            if (language_has_free_typevars(type_i)) {
                LANGUAGE_GC_POP();
                return 0; // something went badly wrong?
            }
            if (language_egal(elt, type_i))
                continue; // elt could be chosen by inst_varargp_in_env for these sparams
            elt = language_unwrap_vararg(elt);
            if (language_is_type_type(elt) && language_is_type_type(language_tparam0(elt))) {
                LANGUAGE_GC_POP();
                return 0; // elt would be set equal to language_type_type instead
            }
            // else, elt also needs to meet the usual rules
        }

        language_value_t *decl_i = language_nth_slot_type(decl, i);
        type_i = language_rewrap_unionall(decl_i, decl);

        if (i_arg > 0 && i_arg <= sizeof(definition->nospecialize) * 8 &&
                (definition->nospecialize & (1 << (i_arg - 1)))) {
            if (!language_has_free_typevars(decl_i) && !language_is_kind(decl_i)) {
                if (language_egal(elt, decl_i))
                    continue;
                LANGUAGE_GC_POP();
                return 0;
            }
        }

        if (language_is_kind(elt)) {
            // kind slots always get guard entries (checking for subtypes of Type)
            if (language_subtype(elt, type_i) && !language_subtype((language_value_t*)language_type_type, type_i))
                continue;
            // TODO: other code paths that could reach here?
            LANGUAGE_GC_POP();
            return 0;
        }
        else if (language_is_kind(type_i)) {
            LANGUAGE_GC_POP();
            return 0;
        }

        if (language_is_type_type(language_unwrap_unionall(elt))) {
            int iscalled = (i_arg > 0 && i_arg <= 8 && (definition->called & (1 << (i_arg - 1)))) ||
                           language_has_free_typevars(decl_i);
            if (language_types_equal(elt, (language_value_t*)language_type_type)) {
                if (!iscalled && very_general_type(type_i))
                    continue;
                if (i >= nargs && definition->isva)
                    continue;
                LANGUAGE_GC_POP();
                return 0;
            }
            if (!iscalled && very_general_type(type_i)) {
                LANGUAGE_GC_POP();
                return 0;
            }
            if (!language_is_datatype(elt)) {
                LANGUAGE_GC_POP();
                return 0;
            }

            // if the declared type was not Any or Union{Type, ...},
            // then the match must been with kind, such as UnionAll or DataType,
            // and the result of matching the type signature
            // needs to be corrected to the concrete type 'kind' (and not to Type)
            language_value_t *kind = language_typeof(language_tparam0(elt));
            if (kind == language_bottom_type) {
                LANGUAGE_GC_POP();
                return 0; // Type{Union{}} gets normalized to typeof(Union{})
            }
            if (language_subtype(kind, type_i) && !language_subtype((language_value_t*)language_type_type, type_i)) {
                LANGUAGE_GC_POP();
                return 0; // gets turned into a kind
            }

            else if (language_is_type_type(language_tparam0(elt)) &&
                     // give up on specializing static parameters for Type{Type{Type{...}}}
                     (language_is_type_type(language_tparam0(language_tparam0(elt))) || !language_has_free_typevars(decl_i))) {
                /*
                  actual argument was Type{...}, we computed its type as
                  Type{Type{...}}. we must avoid unbounded nesting here, so
                  cache the signature as Type{T}, unless something more
                  specific like Type{Type{Int32}} was actually declared.
                  this can be determined using a type intersection.
                */
                if (i < nargs || !definition->isva) {
                    type_i = language_type_intersection(type_i, (language_value_t*)language_type_type);
                    assert(type_i != (language_value_t*)language_bottom_type);
                    if (language_is_kind(type_i)) {
                        LANGUAGE_GC_POP();
                        return 0;
                    }
                    else if (!language_types_equal(type_i, elt)) {
                        LANGUAGE_GC_POP();
                        return 0;
                    }
                    continue;
                }
                else {
                    LANGUAGE_GC_POP();
                    return 0;
                }
            }
            continue;
        }

        int notcalled_func = (i_arg > 0 && i_arg <= 8 && !(definition->called & (1 << (i_arg - 1))) &&
                              !language_has_free_typevars(decl_i) &&
                              language_subtype(elt, (language_value_t*)language_function_type));
        if (notcalled_func && (type_i == (language_value_t*)language_any_type ||
                               type_i == (language_value_t*)language_function_type ||
                               (language_is_uniontype(type_i) && // Base.Callable
                                ((((language_uniontype_t*)type_i)->a == (language_value_t*)language_function_type &&
                                  ((language_uniontype_t*)type_i)->b == (language_value_t*)language_type_type) ||
                                 (((language_uniontype_t*)type_i)->b == (language_value_t*)language_function_type &&
                                  ((language_uniontype_t*)type_i)->a == (language_value_t*)language_type_type))))) {
            // and attempt to despecialize types marked Function, Callable, or Any
            // when called with a subtype of Function but is not called
            if (elt == (language_value_t*)language_function_type)
                continue;
            LANGUAGE_GC_POP();
            return 0;
        }

        if (!language_is_concrete_type(elt)) {
            LANGUAGE_GC_POP();
            return 0;
        }
    }
    LANGUAGE_GC_POP();
    return 1;
}


static int concretesig_equal(language_value_t *tt, language_value_t *simplesig) LANGUAGE_NOTSAFEPOINT
{
    language_value_t **types = language_svec_data(((language_datatype_t*)tt)->parameters);
    language_value_t **sigs = language_svec_data(((language_datatype_t*)simplesig)->parameters);
    size_t i, lensig = language_nparams(simplesig);
    assert(lensig == language_nparams(tt));
    assert(lensig > 0 && !language_is_vararg(language_tparam(simplesig, lensig - 1)));
    for (i = 0; i < lensig; i++) {
        language_value_t *decl = sigs[i];
        language_value_t *a = types[i];
        if (a != decl && decl != (language_value_t*)language_any_type) {
            if (!(language_is_type_type(a) && language_typeof(language_tparam0(a)) == decl))
                return 0;
        }
    }
    return 1;
}

static inline language_typemap_entry_t *lookup_leafcache(language_genericmemory_t *leafcache LANGUAGE_PROPAGATES_ROOT, language_value_t *tt, size_t world) LANGUAGE_NOTSAFEPOINT
{
    language_typemap_entry_t *entry = (language_typemap_entry_t*)language_eqtable_get(leafcache, (language_value_t*)tt, NULL);
    if (entry) {
        do {
            if (language_atomic_load_relaxed(&entry->min_world) <= world && world <= language_atomic_load_relaxed(&entry->max_world)) {
                if (entry->simplesig == (void*)language_nothing || concretesig_equal(tt, (language_value_t*)entry->simplesig))
                    return entry;
            }
            entry = language_atomic_load_relaxed(&entry->next);
        } while ((language_value_t*)entry != language_nothing);
    }
    return NULL;
}

static language_method_instance_t *cache_method(
        language_methtable_t *mt, _Atomic(language_typemap_t*) *cache, language_value_t *parent LANGUAGE_PROPAGATES_ROOT,
        language_tupletype_t *tt, // the original tupletype of the signature
        language_method_t *definition,
        size_t world, size_t min_valid, size_t max_valid,
        language_svec_t *sparams)
{
    // caller must hold the mt->writelock
    // short-circuit (now that we hold the lock) if this entry is already present
    int8_t offs = mt ? language_cachearg_offset(mt) : 1;
    { // scope block
        if (mt) {
            language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
            language_typemap_entry_t *entry = lookup_leafcache(leafcache, (language_value_t*)tt, world);
            if (entry)
                return entry->func.linfo;
        }
        struct language_typemap_assoc search = {(language_value_t*)tt, world, NULL};
        language_typemap_entry_t *entry = language_typemap_assoc_by_type(language_atomic_load_relaxed(cache), &search, offs, /*subtype*/1);
        if (entry && entry->func.value)
            return entry->func.linfo;
    }

    language_value_t *temp = NULL;
    language_value_t *temp2 = NULL;
    language_value_t *temp3 = NULL;
    language_method_instance_t *newmeth = NULL;
    language_svec_t *newparams = NULL;
    LANGUAGE_GC_PUSH5(&temp, &temp2, &temp3, &newmeth, &newparams);

    // Consider if we can cache with the preferred compile signature
    // so that we can minimize the number of required cache entries.
    int cache_with_orig = 1;
    language_tupletype_t *compilationsig = tt;
    language_methtable_t *kwmt = mt == language_kwcall_mt ? language_kwmethod_table_for(definition->sig) : mt;
    intptr_t max_varargs = get_max_varargs(definition, kwmt, mt, NULL);
    language_compilation_sig(tt, sparams, definition, max_varargs, &newparams);
    if (newparams) {
        temp2 = language_apply_tuple_type(newparams, 1);
        // Now there may be a problem: the widened signature is more general
        // than just the given arguments, so it might conflict with another
        // definition that does not have cache instances yet. To fix this, we
        // may insert guard cache entries for all intersections of this
        // signature and definitions. Those guard entries will supersede this
        // one in conflicted cases, alerting us that there should actually be a
        // cache miss. Alternatively, we may use the original signature in the
        // cache, but use this return for compilation.
        //
        // In most cases `!language_isa_compileable_sig(tt, sparams, definition)`,
        // although for some cases, (notably Varargs)
        // we might choose a replacement type that's preferable but not strictly better
        int issubty;
        temp = language_type_intersection_env_s(temp2, (language_value_t*)definition->sig, &newparams, &issubty);
        assert(temp != (language_value_t*)language_bottom_type); (void)temp;
        if (language_egal((language_value_t*)newparams, (language_value_t*)sparams)) {
            cache_with_orig = !issubty;
            compilationsig = (language_datatype_t*)temp2;
        }
        newparams = NULL;
    }
    // TODO: maybe assert(language_isa_compileable_sig(compilationsig, sparams, definition));
    newmeth = language_specializations_get_linfo(definition, (language_value_t*)compilationsig, sparams);
    if (newmeth->cache_with_orig)
        cache_with_orig = 1;

    language_tupletype_t *cachett = tt;
    language_svec_t* guardsigs = language_emptysvec;
    if (!cache_with_orig && mt) {
        // now examine what will happen if we chose to use this sig in the cache
        size_t min_valid2 = 1;
        size_t max_valid2 = ~(size_t)0;
        temp = ml_matches(mt, compilationsig, MAX_UNSPECIALIZED_CONFLICTS, 1, 1, world, 0, &min_valid2, &max_valid2, NULL);
        int guards = 0;
        if (temp == language_nothing) {
            cache_with_orig = 1;
        }
        else {
            int unmatched_tvars = 0;
            size_t i, l = language_array_nrows(temp);
            for (i = 0; i < l; i++) {
                language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(temp, i);
                if (matc->method == definition)
                    continue;
                language_svec_t *env = matc->sparams;
                int k, l;
                for (k = 0, l = language_svec_len(env); k < l; k++) {
                    language_value_t *env_k = language_svecref(env, k);
                    if (language_is_typevar(env_k) || language_is_vararg(env_k)) {
                        unmatched_tvars = 1;
                        break;
                    }
                }
                if (unmatched_tvars || guards > MAX_UNSPECIALIZED_CONFLICTS) {
                    // if distinguishing a guard entry from the generalized signature
                    // would require matching type vars then bail out, since the
                    // method cache matching algorithm cannot do that.
                    //
                    // also bail if this requires too many guard entries
                    cache_with_orig = 1;
                    break;
                }
                guards++;
            }
        }
        if (!cache_with_orig && guards > 0) {
            // use guard entries as placeholders to prevent this cached method
            // from matching when another more specific definition also exists
            size_t i, l;
            guardsigs = language_alloc_svec(guards);
            temp3 = (language_value_t*)guardsigs;
            guards = 0;
            for (i = 0, l = language_array_nrows(temp); i < l; i++) {
                language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(temp, i);
                language_method_t *other = matc->method;
                if (other != definition) {
                    language_svecset(guardsigs, guards, matc->spec_types);
                    guards++;
                    // alternative approach: insert sentinel entry
                    //language_typemap_insert(cache, parent, (language_tupletype_t*)matc->spec_types,
                    //        NULL, language_emptysvec, /*guard*/NULL, language_cachearg_offset(mt), other->min_world, other->max_world);
                }
            }
            assert(guards == language_svec_len(guardsigs));
        }
        if (!cache_with_orig) {
            // determined above that there's no ambiguity in also using compilationsig as the cacheablesig
            min_valid = min_valid2;
            max_valid = max_valid2;
            cachett = compilationsig;
        }
        else {
            // do not revisit this decision
            newmeth->cache_with_orig = 1;
        }
    }

    // now scan `cachett` and ensure that `Type{T}` in the cache will be matched exactly by `typeof(T)`
    // and also reduce the complexity of rejecting this entry in the cache
    // by replacing non-simple types with language_any_type to build a new `type`
    // (for example, if the signature contains language_function_type)
    // TODO: this is also related to how we should handle partial matches
    //       (which currently might miss detection of a MethodError)
    language_tupletype_t *simplett = NULL;
    size_t i, np = language_nparams(cachett);
    newparams = NULL;
    for (i = 0; i < np; i++) {
        language_value_t *elt = language_svecref(cachett->parameters, i);
        if (language_is_vararg(elt)) {
        }
        else if (language_is_type_type(elt)) {
            // TODO: if (!language_is_singleton(elt)) ...
            language_value_t *kind = language_typeof(language_tparam0(elt));
            if (!newparams) newparams = language_svec_copy(cachett->parameters);
            language_svecset(newparams, i, kind);
        }
        else if (!language_is_concrete_type(elt)) { // for example, language_function_type or language_tuple_type
            if (!newparams) newparams = language_svec_copy(cachett->parameters);
            language_svecset(newparams, i, language_any_type);
        }
    }
    if (newparams) {
        simplett = (language_datatype_t*)language_apply_tuple_type(newparams, 1);
        temp2 = (language_value_t*)simplett;
    }

    // short-circuit if an existing entry is already present
    // that satisfies our requirements
    if (cachett != tt) {
        struct language_typemap_assoc search = {(language_value_t*)cachett, world, NULL};
        language_typemap_entry_t *entry = language_typemap_assoc_by_type(language_atomic_load_relaxed(cache), &search, offs, /*subtype*/1);
        if (entry && language_egal((language_value_t*)entry->simplesig, simplett ? (language_value_t*)simplett : language_nothing) &&
                language_egal((language_value_t*)guardsigs, (language_value_t*)entry->guardsigs)) {
            LANGUAGE_GC_POP();
            return entry->func.linfo;
        }
    }

    language_typemap_entry_t *newentry = language_typemap_alloc(cachett, simplett, guardsigs, (language_value_t*)newmeth, min_valid, max_valid);
    temp = (language_value_t*)newentry;
    if (mt && cachett == tt && language_svec_len(guardsigs) == 0 && tt->hash && !tt->hasfreetypevars) {
        // we check `tt->hash` exists, since otherwise the NamedTuple
        // constructor and `structdiff` method pollutes this lookup with a lot
        // of garbage in the linear table search
        if (language_lookup_cache_type_(tt) == NULL) {
            // if this type isn't normally in the cache, force it in there now
            // anyways so that we can depend on it as a token (especially since
            // we just cached it in memory as this method signature anyways)
            LANGUAGE_LOCK(&typecache_lock);
            if (language_lookup_cache_type_(tt) == NULL)
                language_cache_type_(tt);
            LANGUAGE_UNLOCK(&typecache_lock); // Might GC
        }
        language_genericmemory_t *oldcache = language_atomic_load_relaxed(&mt->leafcache);
        language_typemap_entry_t *old = (language_typemap_entry_t*)language_eqtable_get(oldcache, (language_value_t*)tt, language_nothing);
        language_atomic_store_relaxed(&newentry->next, old);
        language_gc_wb(newentry, old);
        language_genericmemory_t *newcache = language_eqtable_put(language_atomic_load_relaxed(&mt->leafcache), (language_value_t*)tt, (language_value_t*)newentry, NULL);
        if (newcache != oldcache) {
            language_atomic_store_release(&mt->leafcache, newcache);
            language_gc_wb(mt, newcache);
        }
    }
    else {
         language_typemap_insert(cache, parent, newentry, offs);
    }

    LANGUAGE_GC_POP();
    return newmeth;
}

static language_method_match_t *_gf_invoke_lookup(language_value_t *types LANGUAGE_PROPAGATES_ROOT, language_value_t *mt, size_t world, size_t *min_valid, size_t *max_valid);

static language_method_instance_t *language_mt_assoc_by_type(language_methtable_t *mt LANGUAGE_PROPAGATES_ROOT, language_datatype_t *tt LANGUAGE_MAYBE_UNROOTED, size_t world)
{
    language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
    language_typemap_entry_t *entry = lookup_leafcache(leafcache, (language_value_t*)tt, world);
    if (entry)
        return entry->func.linfo;
    LANGUAGE_TIMING(METHOD_LOOKUP_SLOW, METHOD_LOOKUP_SLOW);
    language_method_match_t *matc = NULL;
    LANGUAGE_GC_PUSH2(&tt, &matc);
    LANGUAGE_LOCK(&mt->writelock);
    assert(tt->isdispatchtuple || tt->hasfreetypevars);
    language_method_instance_t *mi = NULL;
    if (tt->isdispatchtuple) {
        language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
        language_typemap_entry_t *entry = lookup_leafcache(leafcache, (language_value_t*)tt, world);
        if (entry)
            mi = entry->func.linfo;
    }

    if (!mi) {
        struct language_typemap_assoc search = {(language_value_t*)tt, world, NULL};
        language_typemap_entry_t *entry = language_typemap_assoc_by_type(language_atomic_load_relaxed(&mt->cache), &search, language_cachearg_offset(mt), /*subtype*/1);
        if (entry)
            mi = entry->func.linfo;
    }

    if (!mi) {
        size_t min_valid = 0;
        size_t max_valid = ~(size_t)0;
        matc = _gf_invoke_lookup((language_value_t*)tt, language_nothing, world, &min_valid, &max_valid);
        if (matc) {
            language_method_t *m = matc->method;
            language_svec_t *env = matc->sparams;
            mi = cache_method(mt, &mt->cache, (language_value_t*)mt, tt, m, world, min_valid, max_valid, env);
        }
    }
    LANGUAGE_UNLOCK(&mt->writelock);
    LANGUAGE_GC_POP();
    return mi;
}


struct matches_env {
    struct typemap_intersection_env match;
    language_typemap_entry_t *newentry;
    language_value_t *shadowed;
    language_typemap_entry_t *replaced;
};

static int get_intersect_visitor(language_typemap_entry_t *oldentry, struct typemap_intersection_env *closure0)
{
    struct matches_env *closure = container_of(closure0, struct matches_env, match);
    assert(oldentry != closure->newentry && "entry already added");
    assert(language_atomic_load_relaxed(&oldentry->min_world) <= language_atomic_load_relaxed(&closure->newentry->min_world) && "old method cannot be newer than new method");
    assert(language_atomic_load_relaxed(&oldentry->max_world) != language_atomic_load_relaxed(&closure->newentry->min_world) && "method cannot be added at the same time as method deleted");
    // don't need to consider other similar methods if this oldentry will always fully intersect with them and dominates all of them
    typemap_slurp_search(oldentry, &closure->match);
    language_method_t *oldmethod = oldentry->func.method;
    if (closure->match.issubty // e.g. language_subtype(closure->newentry.sig, oldentry->sig)
        && language_subtype(oldmethod->sig, (language_value_t*)closure->newentry->sig)) { // e.g. language_type_equal(closure->newentry->sig, oldentry->sig)
        if (closure->replaced == NULL || language_atomic_load_relaxed(&closure->replaced->min_world) < language_atomic_load_relaxed(&oldentry->min_world))
            closure->replaced = oldentry; // must pick the newest insertion (both are still valid)
    }
    if (closure->shadowed == NULL)
        closure->shadowed = (language_value_t*)language_alloc_vec_any(0);
    language_array_ptr_1d_push((language_array_t*)closure->shadowed, (language_value_t*)oldmethod);
    return 1;
}

static language_value_t *get_intersect_matches(language_typemap_t *defs, language_typemap_entry_t *newentry, language_typemap_entry_t **replaced, int8_t offs, size_t world)
{
    language_tupletype_t *type = newentry->sig;
    language_tupletype_t *ttypes = (language_tupletype_t*)language_unwrap_unionall((language_value_t*)type);
    size_t l = language_nparams(ttypes);
    language_value_t *va = NULL;
    if (l > 0) {
        va = language_tparam(ttypes, l - 1);
        if (language_is_vararg(va))
            va = language_unwrap_vararg(va);
        else
            va = NULL;
    }
    // search for all intersecting methods active in the previous world, to determine the changes needed to be made for the next world
    struct matches_env env = {{get_intersect_visitor, (language_value_t*)type, va, /* .search_slurp = */ 0,
            /* .min_valid = */ world, /* .max_valid = */ world,
            /* .ti = */ NULL, /* .env = */ language_emptysvec, /* .issubty = */ 0},
        /* .newentry = */ newentry, /* .shadowed */ NULL, /* .replaced */ NULL};
    LANGUAGE_GC_PUSH3(&env.match.env, &env.match.ti, &env.shadowed);
    language_typemap_intersection_visitor(defs, offs, &env.match);
    env.match.env = NULL;
    env.match.ti = NULL;
    *replaced = env.replaced;
    LANGUAGE_GC_POP();
    return env.shadowed;
}

void print_func_loc(LANGUAGE_STREAM *s, language_method_t *m)
{
    long lno = m->line;
    if (lno > 0) {
        char *fname = language_symbol_name((language_sym_t*)m->file);
        language_printf(s, " at %s:%ld", fname, lno);
    }
}

static void method_overwrite(language_typemap_entry_t *newentry, language_method_t *oldvalue)
{
    // method overwritten
    language_method_t *method = (language_method_t*)newentry->func.method;
    language_module_t *newmod = method->module;
    language_module_t *oldmod = oldvalue->module;
    language_datatype_t *dt = language_nth_argument_datatype(oldvalue->sig, 1);
    if (dt == (language_datatype_t*)language_typeof(language_kwcall_func))
        dt = language_nth_argument_datatype(oldvalue->sig, 3);
    int anon = dt && is_anonfn_typename(language_symbol_name(dt->name->name));
    if ((language_options.warn_overwrite == LANGUAGE_OPTIONS_WARN_OVERWRITE_ON) ||
        (language_options.incremental && language_generating_output()) || anon) {
        LANGUAGE_STREAM *s = LANGUAGE_STDERR;
        language_printf(s, "WARNING: Method definition ");
        language_static_show_func_sig(s, (language_value_t*)newentry->sig);
        language_printf(s, " in module %s", language_symbol_name(oldmod->name));
        print_func_loc(s, oldvalue);
        language_printf(s, " overwritten");
        if (oldmod != newmod)
            language_printf(s, " in module %s", language_symbol_name(newmod->name));
        if (method->line > 0 && method->line == oldvalue->line && method->file == oldvalue->file)
            language_printf(s, anon ? " on the same line" : " on the same line (check for duplicate calls to `include`)");
        else
            print_func_loc(s, method);
        language_printf(s, ".\n");
        language_uv_flush(s);
    }
    if (language_generating_output()) {
        language_printf(LANGUAGE_STDERR, "ERROR: Method overwriting is not permitted during Module precompilation. Use `__precompile__(false)` to opt-out of precompilation.\n");
        language_throw(language_precompilable_error);
    }
}

static void update_max_args(language_methtable_t *mt, language_value_t *type)
{
    if (mt == language_type_type_mt || mt == language_nonfunction_mt || mt == language_kwcall_mt)
        return;
    type = language_unwrap_unionall(type);
    assert(language_is_datatype(type));
    size_t na = language_nparams(type);
    if (language_va_tuple_kind((language_datatype_t*)type) == LANGUAGE_VARARG_UNBOUND)
        na--;
    // update occurs inside mt->writelock
    if (na > language_atomic_load_relaxed(&mt->max_args))
        language_atomic_store_relaxed(&mt->max_args, na);
}

language_array_t *_language_debug_method_invalidation LANGUAGE_GLOBALLY_ROOTED = NULL;
LANGUAGE_DLLEXPORT language_value_t *language_debug_method_invalidation(int state)
{
    /* After calling with `state = 1`, caller is responsible for
       holding a reference to the returned array until this is called
       again with `state = 0`. */
    if (state) {
        if (_language_debug_method_invalidation)
            return (language_value_t*) _language_debug_method_invalidation;
        _language_debug_method_invalidation = language_alloc_array_1d(language_array_any_type, 0);
        return (language_value_t*) _language_debug_method_invalidation;
    }
    _language_debug_method_invalidation = NULL;
    return language_nothing;
}

static void _invalidate_backedges(language_method_instance_t *replaced_mi, size_t max_world, int depth);

// recursively invalidate cached methods that had an edge to a replaced method
static void invalidate_method_instance(language_method_instance_t *replaced, size_t max_world, int depth)
{
    language_timing_counter_inc(LANGUAGE_TIMING_COUNTER_Invalidations, 1);
    if (_language_debug_method_invalidation) {
        language_value_t *boxeddepth = NULL;
        LANGUAGE_GC_PUSH1(&boxeddepth);
        language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)replaced);
        boxeddepth = language_box_int32(depth);
        language_array_ptr_1d_push(_language_debug_method_invalidation, boxeddepth);
        LANGUAGE_GC_POP();
    }
    //language_static_show(LANGUAGE_STDERR, (language_value_t*)replaced);
    if (!language_is_method(replaced->def.method))
        return; // shouldn't happen, but better to be safe
    LANGUAGE_LOCK(&replaced->def.method->writelock);
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&replaced->cache);
    while (codeinst) {
        if (language_atomic_load_relaxed(&codeinst->max_world) == ~(size_t)0) {
            assert(language_atomic_load_relaxed(&codeinst->min_world) - 1 <= max_world && "attempting to set illogical world constraints (probable race condition)");
            language_atomic_store_release(&codeinst->max_world, max_world);
        }
        assert(language_atomic_load_relaxed(&codeinst->max_world) <= max_world);
        codeinst = language_atomic_load_relaxed(&codeinst->next);
    }
    LANGUAGE_GC_PUSH1(&replaced);
    // recurse to all backedges to update their valid range also
    _invalidate_backedges(replaced, max_world, depth + 1);
    LANGUAGE_GC_POP();
    LANGUAGE_UNLOCK(&replaced->def.method->writelock);
}

static void _invalidate_backedges(language_method_instance_t *replaced_mi, size_t max_world, int depth) {
    language_array_t *backedges = replaced_mi->backedges;
    if (backedges) {
        // invalidate callers (if any)
        replaced_mi->backedges = NULL;
        LANGUAGE_GC_PUSH1(&backedges);
        size_t i = 0, l = language_array_nrows(backedges);
        language_method_instance_t *replaced;
        while (i < l) {
            i = get_next_edge(backedges, i, NULL, &replaced);
            invalidate_method_instance(replaced, max_world, depth);
        }
        LANGUAGE_GC_POP();
    }
}

// invalidate cached methods that overlap this definition
static void invalidate_backedges(language_method_instance_t *replaced_mi, size_t max_world, const char *why)
{
    LANGUAGE_LOCK(&replaced_mi->def.method->writelock);
    _invalidate_backedges(replaced_mi, max_world, 1);
    LANGUAGE_UNLOCK(&replaced_mi->def.method->writelock);
    if (why && _language_debug_method_invalidation) {
        language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)replaced_mi);
        language_value_t *loctag = language_cstr_to_string(why);
        LANGUAGE_GC_PUSH1(&loctag);
        language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
        LANGUAGE_GC_POP();
    }
}

// add a backedge from callee to caller
LANGUAGE_DLLEXPORT void language_method_instance_add_backedge(language_method_instance_t *callee, language_value_t *invokesig, language_method_instance_t *caller)
{
    LANGUAGE_LOCK(&callee->def.method->writelock);
    if (invokesig == language_nothing)
        invokesig = NULL;      // language uses `nothing` but C uses NULL (#undef)
    int found = 0;
    // TODO: use language_cache_type_(invokesig) like cache_method does to save memory
    if (!callee->backedges) {
        // lazy-init the backedges array
        callee->backedges = language_alloc_vec_any(0);
        language_gc_wb(callee, callee->backedges);
    }
    else {
        size_t i = 0, l = language_array_nrows(callee->backedges);
        for (i = 0; i < l; i++) {
            // optimized version of while (i < l) i = get_next_edge(callee->backedges, i, &invokeTypes, &mi);
            language_value_t *mi = language_array_ptr_ref(callee->backedges, i);
            if (mi != (language_value_t*)caller)
                continue;
            language_value_t *invokeTypes = i > 0 ? language_array_ptr_ref(callee->backedges, i - 1) : NULL;
            if (invokeTypes && language_is_method_instance(invokeTypes))
                invokeTypes = NULL;
            if ((invokesig == NULL && invokeTypes == NULL) ||
                (invokesig && invokeTypes && language_types_equal(invokesig, invokeTypes))) {
                found = 1;
                break;
            }
        }
    }
    if (!found)
        push_edge(callee->backedges, invokesig, caller);
    LANGUAGE_UNLOCK(&callee->def.method->writelock);
}

// add a backedge from a non-existent signature to caller
LANGUAGE_DLLEXPORT void language_method_table_add_backedge(language_methtable_t *mt, language_value_t *typ, language_value_t *caller)
{
    LANGUAGE_LOCK(&mt->writelock);
    if (!mt->backedges) {
        // lazy-init the backedges array
        mt->backedges = language_alloc_vec_any(2);
        language_gc_wb(mt, mt->backedges);
        language_array_ptr_set(mt->backedges, 0, typ);
        language_array_ptr_set(mt->backedges, 1, caller);
    }
    else {
        // check if the edge is already present and avoid adding a duplicate
        size_t i, l = language_array_nrows(mt->backedges);
        for (i = 1; i < l; i += 2) {
            if (language_array_ptr_ref(mt->backedges, i) == caller) {
                if (language_types_equal(language_array_ptr_ref(mt->backedges, i - 1), typ)) {
                    LANGUAGE_UNLOCK(&mt->writelock);
                    return;
                }
            }
        }
        // reuse an already cached instance of this type, if possible
        // TODO: use language_cache_type_(tt) like cache_method does, instead of this linear scan?
        for (i = 1; i < l; i += 2) {
            if (language_array_ptr_ref(mt->backedges, i) != caller) {
                if (language_types_equal(language_array_ptr_ref(mt->backedges, i - 1), typ)) {
                    typ = language_array_ptr_ref(mt->backedges, i - 1);
                    break;
                }
            }
        }
        language_array_ptr_1d_push(mt->backedges, typ);
        language_array_ptr_1d_push(mt->backedges, caller);
    }
    LANGUAGE_UNLOCK(&mt->writelock);
}

struct invalidate_mt_env {
    language_typemap_entry_t *newentry;
    language_array_t *shadowed;
    size_t max_world;
    int invalidated;
};
static int invalidate_mt_cache(language_typemap_entry_t *oldentry, void *closure0)
{
    struct invalidate_mt_env *env = (struct invalidate_mt_env*)closure0;
    LANGUAGE_GC_PROMISE_ROOTED(env->newentry);
    if (language_atomic_load_relaxed(&oldentry->max_world) == ~(size_t)0) {
        language_method_instance_t *mi = oldentry->func.linfo;
        int intersects = 0;
        language_method_instance_t **d = (language_method_instance_t**)language_array_ptr_data(env->shadowed);
        size_t i, n = language_array_nrows(env->shadowed);
        for (i = 0; i < n; i++) {
            if (mi == d[i]) {
                intersects = 1;
                break;
            }
        }
        if (intersects && (language_value_t*)oldentry->sig != mi->specTypes) {
            // the entry may point to a widened MethodInstance, in which case it is worthwhile to check if the new method
            // actually has any meaningful intersection with the old one
            intersects = !language_has_empty_intersection((language_value_t*)oldentry->sig, (language_value_t*)env->newentry->sig);
        }
        if (intersects && oldentry->guardsigs != language_emptysvec) {
            // similarly, if it already matches an existing guardsigs, this is already safe to keep
            size_t i, l;
            for (i = 0, l = language_svec_len(oldentry->guardsigs); i < l; i++) {
                // see corresponding code in language_typemap_entry_assoc_exact
                if (language_subtype((language_value_t*)env->newentry->sig, language_svecref(oldentry->guardsigs, i))) {
                    intersects = 0;
                    break;
                }
            }
        }
        if (intersects) {
            if (_language_debug_method_invalidation) {
                language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)mi);
                language_value_t *loctag = language_cstr_to_string("invalidate_mt_cache");
                LANGUAGE_GC_PUSH1(&loctag);
                language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
                LANGUAGE_GC_POP();
            }
            language_atomic_store_relaxed(&oldentry->max_world, env->max_world);
            env->invalidated = 1;
        }
    }
    return 1;
}

struct disable_mt_env {
    language_method_t *replaced;
    size_t max_world;
};
static int disable_mt_cache(language_typemap_entry_t *oldentry, void *closure0)
{
    struct disable_mt_env *env = (struct disable_mt_env*)closure0;
    if (language_atomic_load_relaxed(&oldentry->max_world) < ~(size_t)0)
        return 1;
    language_method_t *m = oldentry->func.linfo->def.method;
    if (m == env->replaced)
        language_atomic_store_relaxed(&oldentry->max_world, env->max_world);
    return 1;
}

static int typemap_search(language_typemap_entry_t *entry, void *closure)
{
    if ((void*)(entry->func.method) == *(language_method_t**)closure) {
        *(language_typemap_entry_t**)closure = entry;
        return 0;
    }
    return 1;
}

static language_typemap_entry_t *do_typemap_search(language_methtable_t *mt LANGUAGE_PROPAGATES_ROOT, language_method_t *method) {
    language_value_t *closure = (language_value_t*)(method);
    if (language_typemap_visitor(language_atomic_load_relaxed(&mt->defs), typemap_search, &closure))
        language_error("method not in method table");
    return (language_typemap_entry_t *)closure;
}

static void language_method_table_invalidate(language_methtable_t *mt, language_method_t *replaced, size_t max_world)
{
    if (language_options.incremental && language_generating_output())
        language_error("Method deletion is not possible during Module precompile.");
    assert(!replaced->is_for_opaque_closure);
    assert(language_atomic_load_relaxed(&language_world_counter) == max_world);
    // drop this method from mt->cache
    struct disable_mt_env mt_cache_env;
    mt_cache_env.max_world = max_world;
    mt_cache_env.replaced = replaced;
    language_typemap_visitor(language_atomic_load_relaxed(&mt->cache), disable_mt_cache, (void*)&mt_cache_env);
    language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
    size_t i, l = leafcache->length;
    for (i = 1; i < l; i += 2) {
        language_typemap_entry_t *oldentry = (language_typemap_entry_t*)language_genericmemory_ptr_ref(leafcache, i);
        if (oldentry) {
            while ((language_value_t*)oldentry != language_nothing) {
                disable_mt_cache(oldentry, (void*)&mt_cache_env);
                oldentry = language_atomic_load_relaxed(&oldentry->next);
            }
        }
    }
    // Invalidate the backedges
    int invalidated = 0;
    language_value_t *specializations = language_atomic_load_relaxed(&replaced->specializations);
    LANGUAGE_GC_PUSH1(&specializations);
    if (!language_is_svec(specializations))
        specializations = (language_value_t*)language_svec1(specializations);
    l = language_svec_len(specializations);
    for (i = 0; i < l; i++) {
        language_method_instance_t *mi = (language_method_instance_t*)language_svecref(specializations, i);
        if ((language_value_t*)mi != language_nothing) {
            invalidated = 1;
            invalidate_backedges(mi, max_world, "language_method_table_disable");
        }
    }
    LANGUAGE_GC_POP();
    // XXX: this might have resolved an ambiguity, for which we have not tracked the edge here,
    // and thus now introduce a mistake into inference
    if (invalidated && _language_debug_method_invalidation) {
        language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)replaced);
        language_value_t *loctag = language_cstr_to_string("language_method_table_disable");
        LANGUAGE_GC_PUSH1(&loctag);
        language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
        LANGUAGE_GC_POP();
    }
}

LANGUAGE_DLLEXPORT void language_method_table_disable(language_methtable_t *mt, language_method_t *method)
{
    language_typemap_entry_t *methodentry = do_typemap_search(mt, method);
    LANGUAGE_LOCK(&world_counter_lock);
    LANGUAGE_LOCK(&mt->writelock);
    // Narrow the world age on the method to make it uncallable
    size_t world = language_atomic_load_relaxed(&language_world_counter);
    assert(method == methodentry->func.method);
    assert(language_atomic_load_relaxed(&method->deleted_world) == ~(size_t)0);
    language_atomic_store_relaxed(&method->deleted_world, world);
    language_atomic_store_relaxed(&methodentry->max_world, world);
    language_method_table_invalidate(mt, method, world);
    language_atomic_store_release(&language_world_counter, world + 1);
    LANGUAGE_UNLOCK(&mt->writelock);
    LANGUAGE_UNLOCK(&world_counter_lock);
}

static int language_type_intersection2(language_value_t *t1, language_value_t *t2, language_value_t **isect LANGUAGE_REQUIRE_ROOTED_SLOT, language_value_t **isect2 LANGUAGE_REQUIRE_ROOTED_SLOT)
{
    *isect2 = NULL;
    int is_subty = 0;
    *isect = language_type_intersection_env_s(t1, t2, NULL, &is_subty);
    if (*isect == language_bottom_type)
        return 0;
    if (is_subty)
        return 1;
    // TODO: sometimes type intersection returns types with free variables
    if (language_has_free_typevars(t1) || language_has_free_typevars(t2))
        return 1;
    // determine if type-intersection can be convinced to give a better, non-bad answer
    // if the intersection was imprecise, see if we can do better by switching the types
    *isect2 = language_type_intersection(t2, t1);
    if (*isect2 == language_bottom_type) {
        *isect = language_bottom_type;
        *isect2 = NULL;
        return 0;
    }
    if (language_types_egal(*isect2, *isect)) {
        *isect2 = NULL;
    }
    return 1;
}

enum morespec_options {
    morespec_unknown,
    morespec_isnot,
    morespec_is
};

// check if `type` is replacing `m` with an ambiguity here, given other methods in `d` that already match it
static int is_replacing(char ambig, language_value_t *type, language_method_t *m, language_method_t *const *d, size_t n, language_value_t *isect, language_value_t *isect2, char *morespec)
{
    size_t k;
    for (k = 0; k < n; k++) {
        language_method_t *m2 = d[k];
        // see if m2 also fully covered this intersection
        if (m == m2 || !(language_subtype(isect, m2->sig) || (isect2 && language_subtype(isect2, m2->sig))))
            continue;
        if (morespec[k] == (char)morespec_unknown)
            morespec[k] = (char)(language_type_morespecific(m2->sig, type) ? morespec_is : morespec_isnot);
        if (morespec[k] == (char)morespec_is)
            // not actually shadowing this--m2 will still be better
            return 0;
        // if type is not more specific than m (thus now dominating it)
        // then there is a new ambiguity here,
        // since m2 was also a previous match over isect,
        // see if m was previously dominant over all m2
        // or if this was already ambiguous before
        if (ambig != morespec_is && !language_type_morespecific(m->sig, m2->sig)) {
            // m and m2 were previously ambiguous over the full intersection of mi with type, and will still be ambiguous with addition of type
            return 0;
        }
    }
    return 1;
}

language_typemap_entry_t *language_method_table_add(language_methtable_t *mt, language_method_t *method, language_tupletype_t *simpletype)
{
    LANGUAGE_TIMING(ADD_METHOD, ADD_METHOD);
    assert(language_is_method(method));
    assert(language_is_mtable(mt));
    language_timing_show_method(method, LANGUAGE_TIMING_DEFAULT_BLOCK);
    language_typemap_entry_t *newentry = NULL;
    LANGUAGE_GC_PUSH1(&newentry);
    LANGUAGE_LOCK(&mt->writelock);
    // add our new entry
    assert(language_atomic_load_relaxed(&method->primary_world) == ~(size_t)0); // min-world
    assert(language_atomic_load_relaxed(&method->deleted_world) == 1); // max-world
    newentry = language_typemap_alloc((language_tupletype_t*)method->sig, simpletype, language_emptysvec, (language_value_t*)method,
            language_atomic_load_relaxed(&method->primary_world), language_atomic_load_relaxed(&method->deleted_world));
    language_typemap_insert(&mt->defs, (language_value_t*)mt, newentry, language_cachearg_offset(mt));
    update_max_args(mt, method->sig);
    LANGUAGE_UNLOCK(&mt->writelock);
    LANGUAGE_GC_POP();
    return newentry;
}

void language_method_table_activate(language_methtable_t *mt, language_typemap_entry_t *newentry)
{
    LANGUAGE_TIMING(ADD_METHOD, ADD_METHOD);
    language_method_t *method = newentry->func.method;
    assert(language_is_mtable(mt));
    assert(language_is_method(method));
    language_timing_show_method(method, LANGUAGE_TIMING_DEFAULT_BLOCK);
    language_value_t *type = (language_value_t*)newentry->sig;
    language_value_t *oldvalue = NULL;
    language_array_t *oldmi = NULL;
    LANGUAGE_LOCK(&mt->writelock);
    size_t world = language_atomic_load_relaxed(&method->primary_world);
    assert(world == language_atomic_load_relaxed(&language_world_counter) + 1); // min-world
    assert(language_atomic_load_relaxed(&method->deleted_world) == ~(size_t)0); // max-world
    assert(language_atomic_load_relaxed(&newentry->min_world) == ~(size_t)0);
    assert(language_atomic_load_relaxed(&newentry->max_world) == 1);
    language_atomic_store_relaxed(&newentry->min_world, world);
    language_atomic_store_relaxed(&method->primary_world, world);
    size_t max_world = world - 1;
    language_value_t *loctag = NULL;  // debug info for invalidation
    language_value_t *isect = NULL;
    language_value_t *isect2 = NULL;
    language_value_t *isect3 = NULL;
    LANGUAGE_GC_PUSH6(&oldvalue, &oldmi, &loctag, &isect, &isect2, &isect3);
    language_typemap_entry_t *replaced = NULL;
    // then check what entries we replaced
    oldvalue = get_intersect_matches(language_atomic_load_relaxed(&mt->defs), newentry, &replaced, language_cachearg_offset(mt), max_world);
    int invalidated = 0;
    if (replaced) {
        oldvalue = (language_value_t*)replaced;
        invalidated = 1;
        method_overwrite(newentry, replaced->func.method);
        // this is an optimized version of below, given we know the type-intersection is exact
        language_method_table_invalidate(mt, replaced->func.method, max_world);
    }
    else {
        language_method_t *const *d;
        size_t j, n;
        if (oldvalue == NULL) {
            d = NULL;
            n = 0;
        }
        else {
            assert(language_is_array(oldvalue));
            d = (language_method_t**)language_array_ptr_data(oldvalue);
            n = language_array_nrows(oldvalue);
        }
        if (mt->backedges) {
            language_value_t **backedges = language_array_ptr_data(mt->backedges);
            size_t i, na = language_array_nrows(mt->backedges);
            size_t ins = 0;
            for (i = 1; i < na; i += 2) {
                language_value_t *backedgetyp = backedges[i - 1];
                int missing = 0;
                if (language_type_intersection2(backedgetyp, (language_value_t*)type, &isect, &isect2)) {
                    // See if the intersection was actually already fully
                    // covered, but that the new method is ambiguous.
                    //  -> no previous method: now there is one, need to update the missing edge
                    //  -> one+ previously matching method(s):
                    //    -> more specific then all of them: need to update the missing edge
                    //      -> some may have been ambiguous: now there is a replacement
                    //      -> some may have been called: now there is a replacement (also will be detected in the loop later)
                    //    -> less specific or ambiguous with any one of them: can ignore the missing edge (not missing)
                    //      -> some may have been ambiguous: still are
                    //      -> some may have been called: they may be partly replaced (will be detected in the loop later)
                    // c.f. `is_replacing`, which is a similar query, but with an existing method match to compare against
                    missing = 1;
                    size_t j;
                    for (j = 0; j < n; j++) {
                        language_method_t *m = d[j];
                        if (language_subtype(isect, m->sig) || (isect2 && language_subtype(isect2, m->sig))) {
                            // We now know that there actually was a previous
                            // method for this part of the type intersection.
                            if (!language_type_morespecific(type, m->sig)) {
                                missing = 0;
                                break;
                            }
                        }
                    }
                }
                if (missing) {
                    language_method_instance_t *backedge = (language_method_instance_t*)backedges[i];
                    invalidate_method_instance(backedge, max_world, 0);
                    invalidated = 1;
                    if (_language_debug_method_invalidation)
                        language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)backedgetyp);
                }
                else {
                    backedges[ins++] = backedges[i - 1];
                    backedges[ins++] = backedges[i - 0];
                }
            }
            if (ins == 0)
                mt->backedges = NULL;
            else
                language_array_del_end(mt->backedges, na - ins);
        }
        if (oldvalue) {
            oldmi = language_alloc_vec_any(0);
            char *morespec = (char*)alloca(n);
            memset(morespec, morespec_unknown, n);
            for (j = 0; j < n; j++) {
                language_method_t *m = d[j];
                if (morespec[j] == (char)morespec_is)
                    continue;
                loctag = language_atomic_load_relaxed(&m->specializations); // use loctag for a gcroot
                _Atomic(language_method_instance_t*) *data;
                size_t i, l;
                if (language_is_svec(loctag)) {
                    data = (_Atomic(language_method_instance_t*)*)language_svec_data(loctag);
                    l = language_svec_len(loctag);
                }
                else {
                    data = (_Atomic(language_method_instance_t*)*) &loctag;
                    l = 1;
                }
                enum morespec_options ambig = morespec_unknown;
                for (i = 0; i < l; i++) {
                    language_method_instance_t *mi = language_atomic_load_relaxed(&data[i]);
                    if ((language_value_t*)mi == language_nothing)
                        continue;
                    isect3 = language_type_intersection(m->sig, (language_value_t*)mi->specTypes);
                    if (language_type_intersection2(type, isect3, &isect, &isect2)) {
                        // TODO: this only checks pair-wise for ambiguities, but the ambiguities could arise from the interaction of multiple methods
                        // and thus might miss a case where we introduce an ambiguity between two existing methods
                        // We could instead work to sort this into 3 groups `morespecific .. ambiguous .. lesspecific`, with `type` in ambiguous,
                        // such that everything in `morespecific` dominates everything in `ambiguous`, and everything in `ambiguous` dominates everything in `lessspecific`
                        // And then compute where each isect falls, and whether it changed group--necessitating invalidation--or not.
                        if (morespec[j] == (char)morespec_unknown)
                            morespec[j] = (char)(language_type_morespecific(m->sig, type) ? morespec_is : morespec_isnot);
                        if (morespec[j] == (char)morespec_is)
                            // not actually shadowing--the existing method is still better
                            break;
                        if (ambig == morespec_unknown)
                            ambig = language_type_morespecific(type, m->sig) ? morespec_is : morespec_isnot;
                        // replacing a method--see if this really was the selected method previously
                        // over the intersection (not ambiguous) and the new method will be selected now (morespec_is)
                        int replaced_dispatch = is_replacing(ambig, type, m, d, n, isect, isect2, morespec);
                        // found that this specialization dispatch got replaced by m
                        // call invalidate_backedges(mi, max_world, "language_method_table_insert");
                        // but ignore invoke-type edges
                        language_array_t *backedges = mi->backedges;
                        if (backedges) {
                            size_t ib = 0, insb = 0, nb = language_array_nrows(backedges);
                            language_value_t *invokeTypes;
                            language_method_instance_t *caller;
                            while (ib < nb) {
                                ib = get_next_edge(backedges, ib, &invokeTypes, &caller);
                                int replaced_edge;
                                if (invokeTypes) {
                                    // n.b. normally we must have mi.specTypes <: invokeTypes <: m.sig (though it might not strictly hold), so we only need to check the other subtypes
                                    if (language_egal(invokeTypes, caller->def.method->sig))
                                        replaced_edge = 0; // if invokeTypes == m.sig, then the only way to change this invoke is to replace the method itself
                                    else
                                        replaced_edge = language_subtype(invokeTypes, type) && is_replacing(ambig, type, m, d, n, invokeTypes, NULL, morespec);
                                }
                                else {
                                    replaced_edge = replaced_dispatch;
                                }
                                if (replaced_edge) {
                                    invalidate_method_instance(caller, max_world, 1);
                                    invalidated = 1;
                                }
                                else {
                                    insb = set_next_edge(backedges, insb, invokeTypes, caller);
                                }
                            }
                            language_array_del_end(backedges, nb - insb);
                        }
                        language_array_ptr_1d_push(oldmi, (language_value_t*)mi);
                        if (_language_debug_method_invalidation && invalidated) {
                            language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)mi);
                            loctag = language_cstr_to_string("language_method_table_insert");
                            language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
                        }
                    }
                }
            }
            if (language_array_nrows(oldmi)) {
                // search mt->cache and leafcache and drop anything that might overlap with the new method
                // this is very cheap, so we don't mind being fairly conservative at over-approximating this
                struct invalidate_mt_env mt_cache_env;
                mt_cache_env.max_world = max_world;
                mt_cache_env.shadowed = oldmi;
                mt_cache_env.newentry = newentry;
                mt_cache_env.invalidated = 0;

                language_typemap_visitor(language_atomic_load_relaxed(&mt->cache), invalidate_mt_cache, (void*)&mt_cache_env);
                language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
                size_t i, l = leafcache->length;
                for (i = 1; i < l; i += 2) {
                    language_value_t *entry = language_genericmemory_ptr_ref(leafcache, i);
                    if (entry) {
                        while (entry != language_nothing) {
                            invalidate_mt_cache((language_typemap_entry_t*)entry, (void*)&mt_cache_env);
                            entry = (language_value_t*)language_atomic_load_relaxed(&((language_typemap_entry_t*)entry)->next);
                        }
                    }
                }
            }
        }
    }
    if (invalidated && _language_debug_method_invalidation) {
        language_array_ptr_1d_push(_language_debug_method_invalidation, (language_value_t*)method);
        loctag = language_cstr_to_string("language_method_table_insert");
        language_array_ptr_1d_push(_language_debug_method_invalidation, loctag);
    }
    language_atomic_store_relaxed(&newentry->max_world, language_atomic_load_relaxed(&method->deleted_world));
    LANGUAGE_UNLOCK(&mt->writelock);
    LANGUAGE_GC_POP();
}

LANGUAGE_DLLEXPORT void language_method_table_insert(language_methtable_t *mt, language_method_t *method, language_tupletype_t *simpletype)
{
    language_typemap_entry_t *newentry = language_method_table_add(mt, method, simpletype);
    LANGUAGE_GC_PUSH1(&newentry);
    LANGUAGE_LOCK(&world_counter_lock);
    size_t world = language_atomic_load_relaxed(&language_world_counter) + 1;
    language_atomic_store_relaxed(&method->primary_world, world);
    language_atomic_store_relaxed(&method->deleted_world, ~(size_t)0);
    language_method_table_activate(mt, newentry);
    language_atomic_store_release(&language_world_counter, world);
    LANGUAGE_UNLOCK(&world_counter_lock);
    LANGUAGE_GC_POP();
}

static void LANGUAGE_NORETURN language_method_error_bare(language_function_t *f, language_value_t *args, size_t world)
{
    if (language_methoderror_type) {
        language_value_t *e = language_new_struct_uninit(language_methoderror_type);
        struct language_method_error {
            language_value_t *f;
            language_value_t *args;
            size_t world;
        } *pe = (struct language_method_error*)e,
           ee = {f, args, world};
        *pe = ee;
        language_throw(e);
    }
    else {
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "A method error occurred before the base MethodError type was defined. Aborting...\n");
        language_static_show((LANGUAGE_STREAM*)STDERR_FILENO,(language_value_t*)f); language_printf((LANGUAGE_STREAM*)STDERR_FILENO," world %u\n", (unsigned)world);
        language_static_show((LANGUAGE_STREAM*)STDERR_FILENO,args); language_printf((LANGUAGE_STREAM*)STDERR_FILENO,"\n");
        language_ptls_t ptls = language_current_task->ptls;
        ptls->bt_size = rec_backtrace(ptls->bt_data, LANGUAGE_MAX_BT_SIZE, 0);
        language_critical_error(0, 0, NULL, language_current_task);
        abort();
    }
    // not reached
}

void LANGUAGE_NORETURN language_method_error(language_function_t *f, language_value_t **args, size_t na, size_t world)
{
    language_value_t *argtup = language_f_tuple(NULL, args, na - 1);
    LANGUAGE_GC_PUSH1(&argtup);
    language_method_error_bare(f, argtup, world);
    // not reached
}

language_tupletype_t *arg_type_tuple(language_value_t *arg1, language_value_t **args, size_t nargs)
{
    return language_inst_arg_tuple_type(arg1, args, nargs, 1);
}

static language_tupletype_t *lookup_arg_type_tuple(language_value_t *arg1 LANGUAGE_PROPAGATES_ROOT, language_value_t **args, size_t nargs)
{
    return language_lookup_arg_tuple_type(arg1, args, nargs, 1);
}

LANGUAGE_DLLEXPORT language_value_t *language_method_lookup_by_tt(language_tupletype_t *tt, size_t world, language_value_t *_mt)
{
    language_methtable_t *mt = NULL;
    if (_mt == language_nothing)
        mt = language_gf_ft_mtable(language_tparam0(tt));
    else {
        assert(language_isa(_mt, (language_value_t*)language_methtable_type));
        mt = (language_methtable_t*) _mt;
    }
    language_method_instance_t* mi = language_mt_assoc_by_type(mt, tt, world);
    if (!mi)
        return language_nothing;
    return (language_value_t*) mi;
}

LANGUAGE_DLLEXPORT language_method_instance_t *language_method_lookup(language_value_t **args, size_t nargs, size_t world)
{
    assert(nargs > 0 && "expected caller to handle this case");
    language_methtable_t *mt = language_gf_mtable(args[0]);
    language_typemap_t *cache = language_atomic_load_relaxed(&mt->cache); // XXX: gc root for this?
    language_typemap_entry_t *entry = language_typemap_assoc_exact(cache, args[0], &args[1], nargs, language_cachearg_offset(mt), world);
    if (entry)
        return entry->func.linfo;
    language_tupletype_t *tt = arg_type_tuple(args[0], &args[1], nargs);
    return language_mt_assoc_by_type(mt, tt, world);
}

// return a Vector{Any} of svecs, each describing a method match:
// Any[svec(tt, spvals, m, full), ...]
// tt is the intersection of the type argument and the method signature,
// spvals is any matched static parameter values, m is the Method,
// full is a boolean indicating if that method fully covers the input
//
// lim is the max # of methods to return. if there are more, returns language_false.
// Negative values stand for no limit.
// Unless lim == -1, remove matches that are unambiguously covered by earlier ones
LANGUAGE_DLLEXPORT language_value_t *language_matching_methods(language_tupletype_t *types, language_value_t *mt, int lim, int include_ambiguous,
                                             size_t world, size_t *min_valid, size_t *max_valid, int *ambig)
{
    if (ambig != NULL)
        *ambig = 0;
    language_value_t *unw = language_unwrap_unionall((language_value_t*)types);
    if (!language_is_tuple_type(unw))
        return (language_value_t*)language_an_empty_vec_any;
    if (unw == (language_value_t*)language_emptytuple_type || language_tparam0(unw) == language_bottom_type)
        return (language_value_t*)language_an_empty_vec_any;
    if (mt == language_nothing)
        mt = (language_value_t*)language_method_table_for(unw);
    if (mt == language_nothing)
        mt = NULL;
    return ml_matches((language_methtable_t*)mt, types, lim, include_ambiguous, 1, world, 1, min_valid, max_valid, ambig);
}

language_method_instance_t *language_get_unspecialized(language_method_t *def LANGUAGE_PROPAGATES_ROOT)
{
    // one unspecialized version of a function can be shared among all cached specializations
    if (!language_is_method(def) || def->source == NULL) {
        // generated functions might instead randomly just never get inferred, sorry
        return NULL;
    }
    language_method_instance_t *unspec = language_atomic_load_relaxed(&def->unspecialized);
    if (unspec == NULL) {
        LANGUAGE_LOCK(&def->writelock);
        unspec = language_atomic_load_relaxed(&def->unspecialized);
        if (unspec == NULL) {
            unspec = language_get_specialized(def, def->sig, language_emptysvec);
            language_atomic_store_release(&def->unspecialized, unspec);
            language_gc_wb(def, unspec);
        }
        LANGUAGE_UNLOCK(&def->writelock);
    }
    return unspec;
}

STATIC_INLINE language_value_t *_language_rettype_inferred(language_value_t *owner, language_method_instance_t *mi, size_t min_world, size_t max_world) LANGUAGE_NOTSAFEPOINT
{
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mi->cache);
    while (codeinst) {
        if (language_atomic_load_relaxed(&codeinst->min_world) <= min_world &&
            max_world <= language_atomic_load_relaxed(&codeinst->max_world) &&
            language_egal(codeinst->owner, owner)) {

            language_value_t *code = language_atomic_load_relaxed(&codeinst->inferred);
            if (code)
                return (language_value_t*)codeinst;
        }
        codeinst = language_atomic_load_relaxed(&codeinst->next);
    }
    return (language_value_t*)language_nothing;
}

LANGUAGE_DLLEXPORT language_value_t *language_rettype_inferred(language_value_t *owner, language_method_instance_t *mi, size_t min_world, size_t max_world) LANGUAGE_NOTSAFEPOINT
{
    return (language_value_t*)_language_rettype_inferred(owner, mi, min_world, max_world);
}

LANGUAGE_DLLEXPORT language_value_t *language_rettype_inferred_native(language_method_instance_t *mi, size_t min_world, size_t max_world) LANGUAGE_NOTSAFEPOINT
{
    return (language_value_t*)_language_rettype_inferred(language_nothing, mi, min_world, max_world);
}

LANGUAGE_DLLEXPORT language_value_t *(*const language_rettype_inferred_addr)(language_method_instance_t *mi, size_t min_world, size_t max_world) LANGUAGE_NOTSAFEPOINT = language_rettype_inferred_native;

language_code_instance_t *language_method_compiled(language_method_instance_t *mi, size_t world)
{
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mi->cache);
    for (; codeinst; codeinst = language_atomic_load_relaxed(&codeinst->next)) {
        if (codeinst->owner != language_nothing)
            continue;
        if (language_atomic_load_relaxed(&codeinst->min_world) <= world && world <= language_atomic_load_relaxed(&codeinst->max_world)) {
            if (language_atomic_load_relaxed(&codeinst->invoke) != NULL)
                return codeinst;
        }
    }
    return NULL;
}

// Opportunistic SOURCE_MODE_ABI cache lookup.
language_code_instance_t *language_method_inferred_with_abi(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT, size_t world)
{
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mi->cache);
    for (; codeinst; codeinst = language_atomic_load_relaxed(&codeinst->next)) {
        if (codeinst->owner != language_nothing)
            continue;

        if (language_atomic_load_relaxed(&codeinst->min_world) <= world && world <= language_atomic_load_relaxed(&codeinst->max_world)) {
            language_value_t *code = language_atomic_load_relaxed(&codeinst->inferred);
            if (code && (code != language_nothing || (language_atomic_load_relaxed(&codeinst->invoke) != NULL)))
                return codeinst;
        }
    }
    return NULL;
}

language_mutex_t precomp_statement_out_lock;

static void record_precompile_statement(language_method_instance_t *mi, double compilation_time)
{
    static ios_t f_precompile;
    static LANGUAGE_STREAM* s_precompile = NULL;
    language_method_t *def = mi->def.method;
    if (language_options.trace_compile == NULL)
        return;
    if (!language_is_method(def))
        return;

    LANGUAGE_LOCK(&precomp_statement_out_lock);
    if (s_precompile == NULL) {
        const char *t = language_options.trace_compile;
        if (!strncmp(t, "stderr", 6)) {
            s_precompile = LANGUAGE_STDERR;
        }
        else {
            if (ios_file(&f_precompile, t, 1, 1, 1, 1) == NULL)
                language_errorf("cannot open precompile statement file \"%s\" for writing", t);
            s_precompile = (LANGUAGE_STREAM*) &f_precompile;
        }
    }
    if (!language_has_free_typevars(mi->specTypes)) {
        if (language_options.trace_compile_timing)
            language_printf(s_precompile, "#= %6.1f ms =# ", compilation_time / 1e6);
        language_printf(s_precompile, "precompile(");
        language_static_show(s_precompile, mi->specTypes);
        language_printf(s_precompile, ")\n");
        if (s_precompile != LANGUAGE_STDERR)
            ios_flush(&f_precompile);
    }
    LANGUAGE_UNLOCK(&precomp_statement_out_lock);
}

language_method_instance_t *language_normalize_to_compilable_mi(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT);

language_code_instance_t *language_compile_method_internal(language_method_instance_t *mi, size_t world)
{
    // quick check if we already have a compiled result
    language_code_instance_t *codeinst = language_method_compiled(mi, world);
    if (codeinst)
        return codeinst;

    // if mi has a better (wider) signature preferred for compilation use that
    // instead and just copy it here for caching
    language_method_instance_t *mi2 = language_normalize_to_compilable_mi(mi);
    if (mi2 != mi) {
        language_code_instance_t *codeinst2 = language_compile_method_internal(mi2, world);
        language_code_instance_t *codeinst = language_get_method_inferred(
                mi, codeinst2->rettype,
                language_atomic_load_relaxed(&codeinst2->min_world), language_atomic_load_relaxed(&codeinst2->max_world),
                language_atomic_load_relaxed(&codeinst2->debuginfo));
        if (language_atomic_load_relaxed(&codeinst->invoke) == NULL) {
            codeinst->rettype_const = codeinst2->rettype_const;
            language_gc_wb(codeinst, codeinst->rettype_const);
            uint8_t specsigflags = language_atomic_load_acquire(&codeinst2->specsigflags);
            language_callptr_t invoke = language_atomic_load_acquire(&codeinst2->invoke);
            void *fptr = language_atomic_load_relaxed(&codeinst2->specptr.fptr);
            if (fptr != NULL) {
                while (!(specsigflags & 0b10)) {
                    language_cpu_pause();
                    specsigflags = language_atomic_load_acquire(&codeinst2->specsigflags);
                }
                invoke = language_atomic_load_relaxed(&codeinst2->invoke);
                void *prev_fptr = NULL;
                // see jitlayers.cpp for the ordering restrictions here
                if (language_atomic_cmpswap_acqrel(&codeinst->specptr.fptr, &prev_fptr, fptr)) {
                    language_atomic_store_relaxed(&codeinst->specsigflags, specsigflags & 0b1);
                    language_atomic_store_release(&codeinst->invoke, invoke);
                    // unspec is probably not specsig, but might be using specptr
                    language_atomic_store_release(&codeinst->specsigflags, specsigflags & ~0b1); // clear specsig flag
                } else {
                    // someone else already compiled it
                    while (!(language_atomic_load_acquire(&codeinst->specsigflags) & 0b10)) {
                        language_cpu_pause();
                    }
                    // codeinst is now set up fully, safe to return
                }
            } else {
                language_callptr_t prev = NULL;
                language_atomic_cmpswap_acqrel(&codeinst->invoke, &prev, invoke);
            }
        }
        // don't call record_precompile_statement here, since we already compiled it as mi2 which is better
        return codeinst;
    }

    int compile_option = language_options.compile_enabled;
    language_method_t *def = mi->def.method;
    // disabling compilation per-module can override global setting
    if (language_is_method(def)) {
        int mod_setting = language_get_module_compile(((language_method_t*)def)->module);
        if (mod_setting == LANGUAGE_OPTIONS_COMPILE_OFF ||
            mod_setting == LANGUAGE_OPTIONS_COMPILE_MIN)
            compile_option = ((language_method_t*)def)->module->compile;
    }

    // if compilation is disabled or source is unavailable, try calling unspecialized version
    if (compile_option == LANGUAGE_OPTIONS_COMPILE_OFF ||
        compile_option == LANGUAGE_OPTIONS_COMPILE_MIN ||
        (language_is_method(def) && def->source == language_nothing)) {
        // copy fptr from the template method definition
        if (language_is_method(def)) {
            language_method_instance_t *unspecmi = language_atomic_load_relaxed(&def->unspecialized);
            if (unspecmi) {
                language_code_instance_t *unspec = language_atomic_load_relaxed(&unspecmi->cache);
                language_callptr_t unspec_invoke = NULL;
                if (unspec && (unspec_invoke = language_atomic_load_acquire(&unspec->invoke))) {
                    language_code_instance_t *codeinst = language_new_codeinst(mi, language_nothing,
                        (language_value_t*)language_any_type, (language_value_t*)language_any_type, NULL, NULL,
                        0, 1, ~(size_t)0, 0, language_nothing, 0, NULL);
                    void *unspec_fptr = language_atomic_load_relaxed(&unspec->specptr.fptr);
                    if (unspec_fptr) {
                        // wait until invoke and specsigflags are properly set
                        while (!(language_atomic_load_acquire(&unspec->specsigflags) & 0b10)) {
                            language_cpu_pause();
                        }
                        unspec_invoke = language_atomic_load_relaxed(&unspec->invoke);
                    }
                    language_atomic_store_release(&codeinst->specptr.fptr, unspec_fptr);
                    codeinst->rettype_const = unspec->rettype_const;
                    language_atomic_store_release(&codeinst->invoke, unspec_invoke);
                    language_mi_cache_insert(mi, codeinst);
                    record_precompile_statement(mi, 0);
                    return codeinst;
                }
            }
        }
    }

    // if that didn't work and compilation is off, try running in the interpreter
    if (compile_option == LANGUAGE_OPTIONS_COMPILE_OFF ||
        compile_option == LANGUAGE_OPTIONS_COMPILE_MIN) {
        language_code_info_t *src = language_code_for_interpreter(mi, world);
        if (!language_code_requires_compiler(src, 0)) {
            language_code_instance_t *codeinst = language_new_codeinst(mi, language_nothing,
                (language_value_t*)language_any_type, (language_value_t*)language_any_type, NULL, NULL,
                0, 1, ~(size_t)0, 0, language_nothing, 0, NULL);
            language_atomic_store_release(&codeinst->invoke, language_fptr_interpret_call);
            language_mi_cache_insert(mi, codeinst);
            record_precompile_statement(mi, 0);
            return codeinst;
        }
        if (compile_option == LANGUAGE_OPTIONS_COMPILE_OFF) {
            language_printf(LANGUAGE_STDERR, "No compiled code available for ");
            language_static_show(LANGUAGE_STDERR, (language_value_t*)mi);
            language_printf(LANGUAGE_STDERR, " : sysimg may not have been built with --compile=all\n");
        }
    }

    // Ok, compilation is enabled. We'll need to try to compile something (probably).
    // Try to find a codeinst we have already inferred (e.g. while we were compiling
    // something else).
    codeinst = language_method_inferred_with_abi(mi, world);

    // Everything from here on is considered (user facing) compile time
    uint64_t start = language_typeinf_timing_begin();
    int is_recompile = language_atomic_load_relaxed(&mi->cache) != NULL;

    // This codeinst hasn't been previously inferred do that now
    // language_type_infer will internally do a cache lookup and language_engine_reserve call
    // to synchronize this across threads
    if (!codeinst) {
        // Don't bother inferring toplevel thunks or macros - the performance cost of inference is likely
        // to significantly exceed the actual runtime.
        int should_skip_inference = !language_is_method(mi->def.method) || language_symbol_name(mi->def.method->name)[0] == '@';

        if (!should_skip_inference) {
            codeinst = language_type_infer(mi, world, SOURCE_MODE_ABI);
        }
    }

    if (codeinst) {
        if (language_atomic_load_acquire(&codeinst->invoke) != NULL) {
            language_typeinf_timing_end(start, is_recompile);
            // Already compiled - e.g. constabi, or compiled by a different thread while we were waiting.
            return codeinst;
        }

        LANGUAGE_GC_PUSH1(&codeinst);
        double compile_time = language_hrtime();
        int did_compile = language_compile_codeinst(codeinst);
        compile_time = language_hrtime() - compile_time;

        if (language_atomic_load_relaxed(&codeinst->invoke) == NULL) {
            // Something went wrong. Bail to the fallback path.
            codeinst = NULL;
        }
        else if (did_compile) {
            record_precompile_statement(mi, compile_time);
        }
        LANGUAGE_GC_POP();
    }
    if (!codeinst) {
        language_method_instance_t *unspec = language_get_unspecialized(def);
        if (unspec == NULL)
            unspec = mi;
        language_code_instance_t *ucache = language_get_method_inferred(unspec, (language_value_t*)language_any_type, 1, ~(size_t)0, NULL);
        // ask codegen to make the fptr for unspec
        language_callptr_t ucache_invoke = language_atomic_load_acquire(&ucache->invoke);
        if (ucache_invoke == NULL) {
            if ((!language_is_method(def) || def->source == language_nothing) &&
                !language_cached_uninferred(language_atomic_load_relaxed(&ucache->def->cache), world)) {
                language_throw(language_new_struct(language_missingcodeerror_type, (language_value_t*)mi));
            }
            language_generate_fptr_for_unspecialized(ucache);
            ucache_invoke = language_atomic_load_acquire(&ucache->invoke);
        }
        assert(ucache_invoke != NULL);
        if (ucache_invoke != language_fptr_sparam &&
            ucache_invoke != language_fptr_interpret_call) {
            // only these care about the exact specTypes, otherwise we can use it directly
            language_typeinf_timing_end(start, is_recompile);
            return ucache;
        }
        codeinst = language_new_codeinst(mi, language_nothing,
            (language_value_t*)language_any_type, (language_value_t*)language_any_type, NULL, NULL,
            0, 1, ~(size_t)0, 0, language_nothing, 0, NULL);
        void *unspec_fptr = language_atomic_load_relaxed(&ucache->specptr.fptr);
        if (unspec_fptr) {
            // wait until invoke and specsigflags are properly set
            while (!(language_atomic_load_acquire(&ucache->specsigflags) & 0b10)) {
                language_cpu_pause();
            }
            ucache_invoke = language_atomic_load_relaxed(&ucache->invoke);
        }
        // unspec is always not specsig, but might use specptr
        language_atomic_store_relaxed(&codeinst->specsigflags, language_atomic_load_relaxed(&ucache->specsigflags) & 0b10);
        language_atomic_store_relaxed(&codeinst->specptr.fptr, unspec_fptr);
        codeinst->rettype_const = ucache->rettype_const;
        language_atomic_store_release(&codeinst->invoke, ucache_invoke);
        language_mi_cache_insert(mi, codeinst);
    }
    language_atomic_store_relaxed(&codeinst->precompile, 1);
    language_typeinf_timing_end(start, is_recompile);
    return codeinst;
}

language_value_t *language_fptr_const_return(language_value_t *f, language_value_t **args, uint32_t nargs, language_code_instance_t *m)
{
    return m->rettype_const;
}

language_value_t *language_fptr_args(language_value_t *f, language_value_t **args, uint32_t nargs, language_code_instance_t *m)
{
    language_fptr_args_t invoke = language_atomic_load_relaxed(&m->specptr.fptr1);
    assert(invoke && "Forgot to set specptr for language_fptr_args!");
    return invoke(f, args, nargs);
}

language_value_t *language_fptr_sparam(language_value_t *f, language_value_t **args, uint32_t nargs, language_code_instance_t *m)
{
    language_svec_t *sparams = m->def->sparam_vals;
    assert(sparams != language_emptysvec);
    language_fptr_sparam_t invoke = language_atomic_load_relaxed(&m->specptr.fptr3);
    assert(invoke && "Forgot to set specptr for language_fptr_sparam!");
    return invoke(f, args, nargs, sparams);
}

LANGUAGE_DLLEXPORT const language_callptr_t language_fptr_args_addr = &language_fptr_args;

LANGUAGE_DLLEXPORT const language_callptr_t language_fptr_const_return_addr = &language_fptr_const_return;

LANGUAGE_DLLEXPORT const language_callptr_t language_fptr_sparam_addr = &language_fptr_sparam;

LANGUAGE_DLLEXPORT const language_callptr_t language_f_opaque_closure_call_addr = (language_callptr_t)&language_f_opaque_closure_call;

// Return the index of the invoke api, if known
LANGUAGE_DLLEXPORT int32_t language_invoke_api(language_code_instance_t *codeinst)
{
    language_callptr_t f = language_atomic_load_relaxed(&codeinst->invoke);
    if (f == NULL)
        return 0;
    if (f == &language_fptr_args)
        return 1;
    if (f == &language_fptr_const_return)
        return 2;
    if (f == &language_fptr_sparam)
        return 3;
    if (f == &language_fptr_interpret_call)
        return 4;
    return -1;
}

LANGUAGE_DLLEXPORT language_value_t *language_normalize_to_compilable_sig(language_methtable_t *mt, language_tupletype_t *ti, language_svec_t *env, language_method_t *m,
                                                        int return_if_compileable)
{
    language_tupletype_t *tt = NULL;
    language_svec_t *newparams = NULL;
    LANGUAGE_GC_PUSH2(&tt, &newparams);
    language_methtable_t *kwmt = mt == language_kwcall_mt ? language_kwmethod_table_for(m->sig) : mt;
    intptr_t max_varargs = get_max_varargs(m, kwmt, mt, NULL);
    language_compilation_sig(ti, env, m, max_varargs, &newparams);
    int is_compileable = ((language_datatype_t*)ti)->isdispatchtuple;
    if (newparams) {
        tt = (language_datatype_t*)language_apply_tuple_type(newparams, 1);
        if (!is_compileable) {
            // compute new env, if used below
            language_value_t *ti = language_type_intersection_env((language_value_t*)tt, (language_value_t*)m->sig, &newparams);
            assert(ti != language_bottom_type); (void)ti;
            env = newparams;
        }
    }
    else {
        tt = ti;
    }
    if (!is_compileable)
        is_compileable = language_isa_compileable_sig(tt, env, m);
    LANGUAGE_GC_POP();
    return (!return_if_compileable || is_compileable) ? (language_value_t*)tt : language_nothing;
}

language_method_instance_t *language_normalize_to_compilable_mi(language_method_instance_t *mi LANGUAGE_PROPAGATES_ROOT)
{
    language_method_t *def = mi->def.method;
    if (!language_is_method(def) || !language_is_datatype(mi->specTypes))
        return mi;
    language_methtable_t *mt = language_method_get_table(def);
    if ((language_value_t*)mt == language_nothing)
        return mi;
    language_value_t *compilationsig = language_normalize_to_compilable_sig(mt, (language_datatype_t*)mi->specTypes, mi->sparam_vals, def, 1);
    if (compilationsig == language_nothing || language_egal(compilationsig, mi->specTypes))
        return mi;
    language_svec_t *env = NULL;
    LANGUAGE_GC_PUSH2(&compilationsig, &env);
    language_value_t *ti = language_type_intersection_env((language_value_t*)compilationsig, (language_value_t*)def->sig, &env);
    assert(ti != language_bottom_type); (void)ti;
    mi = language_specializations_get_linfo(def, (language_value_t*)compilationsig, env);
    LANGUAGE_GC_POP();
    return mi;
}

// return a MethodInstance for a compileable method_match
language_method_instance_t *language_method_match_to_mi(language_method_match_t *match, size_t world, size_t min_valid, size_t max_valid, int mt_cache)
{
    language_method_t *m = match->method;
    language_svec_t *env = match->sparams;
    language_tupletype_t *ti = match->spec_types;
    language_method_instance_t *mi = NULL;
    if (language_is_datatype(ti)) {
        language_methtable_t *mt = language_method_get_table(m);
        if ((language_value_t*)mt != language_nothing) {
            // get the specialization, possibly also caching it
            if (mt_cache && ((language_datatype_t*)ti)->isdispatchtuple) {
                // Since we also use this presence in the cache
                // to trigger compilation when producing `.ji` files,
                // inject it there now if we think it will be
                // used via dispatch later (e.g. because it was hinted via a call to `precompile`)
                LANGUAGE_LOCK(&mt->writelock);
                mi = cache_method(mt, &mt->cache, (language_value_t*)mt, ti, m, world, min_valid, max_valid, env);
                LANGUAGE_UNLOCK(&mt->writelock);
            }
            else {
                language_value_t *tt = language_normalize_to_compilable_sig(mt, ti, env, m, 1);
                if (tt != language_nothing) {
                    LANGUAGE_GC_PUSH2(&tt, &env);
                    if (!language_egal(tt, (language_value_t*)ti)) {
                        language_value_t *ti = language_type_intersection_env((language_value_t*)tt, (language_value_t*)m->sig, &env);
                        assert(ti != language_bottom_type); (void)ti;
                    }
                    mi = language_specializations_get_linfo(m, (language_value_t*)tt, env);
                    LANGUAGE_GC_POP();
                }
            }
        }
    }
    return mi;
}

// compile-time method lookup
language_method_instance_t *language_get_specialization1(language_tupletype_t *types LANGUAGE_PROPAGATES_ROOT, size_t world, size_t *min_valid, size_t *max_valid, int mt_cache)
{
    if (language_has_free_typevars((language_value_t*)types))
        return NULL; // don't poison the cache due to a malformed query
    if (!language_has_concrete_subtype((language_value_t*)types))
        return NULL;

    // find if exactly 1 method matches (issue #7302)
    size_t min_valid2 = 1;
    size_t max_valid2 = ~(size_t)0;
    int ambig = 0;
    language_value_t *matches = language_matching_methods(types, language_nothing, 1, 1, world, &min_valid2, &max_valid2, &ambig);
    if (*min_valid < min_valid2)
        *min_valid = min_valid2;
    if (*max_valid > max_valid2)
        *max_valid = max_valid2;
    if (matches == language_nothing || language_array_nrows(matches) != 1 || ambig)
        return NULL;
    LANGUAGE_GC_PUSH1(&matches);
    language_method_match_t *match = (language_method_match_t*)language_array_ptr_ref(matches, 0);
    language_method_instance_t *mi = language_method_match_to_mi(match, world, min_valid2, max_valid2, mt_cache);
    LANGUAGE_GC_POP();
    return mi;
}

// Get a MethodInstance for a precompile() call. This uses a special kind of lookup that
// tries to find a method for which the requested signature is compileable.
static language_method_instance_t *language_get_compile_hint_specialization(language_tupletype_t *types LANGUAGE_PROPAGATES_ROOT, size_t world, size_t *min_valid, size_t *max_valid, int mt_cache)
{
    if (language_has_free_typevars((language_value_t*)types))
        return NULL; // don't poison the cache due to a malformed query
    if (!language_has_concrete_subtype((language_value_t*)types))
        return NULL;

    size_t min_valid2 = 1;
    size_t max_valid2 = ~(size_t)0;
    int ambig = 0;
    language_value_t *matches = language_matching_methods(types, language_nothing, -1, 0, world, &min_valid2, &max_valid2, &ambig);
    if (*min_valid < min_valid2)
        *min_valid = min_valid2;
    if (*max_valid > max_valid2)
        *max_valid = max_valid2;
    size_t i, n = language_array_nrows(matches);
    if (n == 0)
        return NULL;
    LANGUAGE_GC_PUSH1(&matches);
    language_method_match_t *match = NULL;
    if (n == 1) {
        match = (language_method_match_t*)language_array_ptr_ref(matches, 0);
    }
    else if (language_is_datatype(types)) {
        // first, select methods for which `types` is compileable
        size_t count = 0;
        for (i = 0; i < n; i++) {
            language_method_match_t *match1 = (language_method_match_t*)language_array_ptr_ref(matches, i);
            if (language_isa_compileable_sig(types, match1->sparams, match1->method))
                language_array_ptr_set(matches, count++, (language_value_t*)match1);
        }
        language_array_del_end((language_array_t*)matches, n - count);
        n = count;
        // now remove methods that are more specific than others in the list.
        // this is because the intent of precompiling e.g. f(::DataType) is to
        // compile that exact method if it exists, and not lots of f(::Type{X}) methods
        int exclude;
        count = 0;
        for (i = 0; i < n; i++) {
            language_method_match_t *match1 = (language_method_match_t*)language_array_ptr_ref(matches, i);
            exclude = 0;
            for (size_t j = n-1; j > i; j--) {  // more general methods maybe more likely to be at end
                language_method_match_t *match2 = (language_method_match_t*)language_array_ptr_ref(matches, j);
                if (language_method_morespecific(match1->method, match2->method)) {
                    exclude = 1;
                    break;
                }
            }
            if (!exclude)
                language_array_ptr_set(matches, count++, (language_value_t*)match1);
            if (count > 1)
                break;
        }
        // at this point if there are 0 matches left we found nothing, or if there are
        // more than one the request is ambiguous and we ignore it.
        if (count == 1)
            match = (language_method_match_t*)language_array_ptr_ref(matches, 0);
    }
    language_method_instance_t *mi = NULL;
    if (match != NULL)
        mi = language_method_match_to_mi(match, world, min_valid2, max_valid2, mt_cache);
    LANGUAGE_GC_POP();
    return mi;
}

static void _generate_from_hint(language_method_instance_t *mi, size_t world)
{
    language_value_t *codeinst = language_rettype_inferred_native(mi, world, world);
    if (codeinst == language_nothing) {
        (void)language_type_infer(mi, world, SOURCE_MODE_NOT_REQUIRED);
        codeinst = language_rettype_inferred_native(mi, world, world);
    }
    if (codeinst != language_nothing) {
        if (language_atomic_load_relaxed(&((language_code_instance_t*)codeinst)->invoke) == language_fptr_const_return)
            return; // probably not a good idea to generate code
        language_atomic_store_relaxed(&((language_code_instance_t*)codeinst)->precompile, 1);
    }
}

static void language_compile_now(language_method_instance_t *mi)
{
    size_t world = language_atomic_load_acquire(&language_world_counter);
    size_t tworld = language_typeinf_world;
    _generate_from_hint(mi, world);
    if (language_typeinf_func && language_atomic_load_relaxed(&mi->def.method->primary_world) <= tworld) {
        // if it's part of the compiler, also attempt to compile for the compiler world too
        _generate_from_hint(mi, tworld);
    }
}

LANGUAGE_DLLEXPORT void language_compile_method_instance(language_method_instance_t *mi, language_tupletype_t *types, size_t world)
{
    size_t tworld = language_typeinf_world;
    language_atomic_store_relaxed(&mi->precompiled, 1);
    if (language_generating_output()) {
        language_compile_now(mi);
        // In addition to full compilation of the compilation-signature, if `types` is more specific (e.g. due to nospecialize),
        // also run inference now on the original `types`, since that may help us guide inference to find
        // additional useful methods that should be compiled
        //ALT: if (language_is_datatype(types) && ((language_datatype_t*)types)->isdispatchtuple && !language_egal(mi->specTypes, types))
        //ALT: if (language_subtype(types, mi->specTypes))
        if (types && !language_subtype(mi->specTypes, (language_value_t*)types)) {
            language_svec_t *tpenv2 = language_emptysvec;
            language_value_t *types2 = NULL;
            LANGUAGE_GC_PUSH2(&tpenv2, &types2);
            types2 = language_type_intersection_env((language_value_t*)types, (language_value_t*)mi->def.method->sig, &tpenv2);
            language_method_instance_t *mi2 = language_specializations_get_linfo(mi->def.method, (language_value_t*)types2, tpenv2);
            LANGUAGE_GC_POP();
            language_atomic_store_relaxed(&mi2->precompiled, 1);
            if (language_rettype_inferred_native(mi2, world, world) == language_nothing)
                (void)language_type_infer(mi2, world, SOURCE_MODE_NOT_REQUIRED);
            if (language_typeinf_func && language_atomic_load_relaxed(&mi->def.method->primary_world) <= tworld) {
                if (language_rettype_inferred_native(mi2, tworld, tworld) == language_nothing)
                    (void)language_type_infer(mi2, tworld, SOURCE_MODE_NOT_REQUIRED);
            }
        }
    }
    else {
        // Otherwise (this branch), assuming we are at runtime (normal JIT) and
        // we should generate the native code immediately in preparation for use.
        (void)language_compile_method_internal(mi, world);
    }
}

LANGUAGE_DLLEXPORT int language_compile_hint(language_tupletype_t *types)
{
    size_t world = language_atomic_load_acquire(&language_world_counter);
    size_t min_valid = 0;
    size_t max_valid = ~(size_t)0;
    language_method_instance_t *mi = language_get_compile_hint_specialization(types, world, &min_valid, &max_valid, 1);
    if (mi == NULL)
        return 0;
    LANGUAGE_GC_PROMISE_ROOTED(mi);
    language_compile_method_instance(mi, types, world);
    return 1;
}

// add type of `f` to front of argument tuple type
language_value_t *language_argtype_with_function(language_value_t *f, language_value_t *types0)
{
    return language_argtype_with_function_type(language_is_type(f) ? (language_value_t*)language_wrap_Type(f) : language_typeof(f), types0);
}

language_value_t *language_argtype_with_function_type(language_value_t *ft LANGUAGE_MAYBE_UNROOTED, language_value_t *types0)
{
    language_value_t *types = language_unwrap_unionall(types0);
    size_t l = language_nparams(types);
    language_value_t *tt = NULL;
    LANGUAGE_GC_PUSH2(&tt, &ft);
    tt = (language_value_t*)language_alloc_svec(1+l);
    language_svecset(tt, 0, ft);
    for (size_t i = 0; i < l; i++)
        language_svecset(tt, i+1, language_tparam(types,i));
    tt = (language_value_t*)language_apply_tuple_type((language_svec_t*)tt, 1);
    tt = language_rewrap_unionall_(tt, types0);
    LANGUAGE_GC_POP();
    return tt;
}

#ifdef LANGUAGE_TRACE
static int trace_en = 0;
static int error_en = 1;
static void __attribute__ ((unused)) enable_trace(int x) { trace_en=x; }
static void show_call(language_value_t *F, language_value_t **args, uint32_t nargs)
{
    language_static_show(LANGUAGE_STDOUT, F);
    language_printf(LANGUAGE_STDOUT, "(");
    for(size_t i=0; i < nargs; i++) {
        if (i > 0) language_printf(LANGUAGE_STDOUT, ", ");
        language_static_show(LANGUAGE_STDOUT, language_typeof(args[i]));
    }
    language_printf(LANGUAGE_STDOUT, ")");
}
#endif

STATIC_INLINE language_value_t *verify_type(language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    assert(v && language_typeof(v) && language_typeof(language_typeof(v)) == (language_value_t*)language_datatype_type);
    return v;
}

STATIC_INLINE language_value_t *_language_invoke(language_value_t *F, language_value_t **args, uint32_t nargs, language_method_instance_t *mfunc, size_t world)
{
    // manually inlined copy of language_method_compiled
    language_code_instance_t *codeinst = language_atomic_load_relaxed(&mfunc->cache);
    while (codeinst) {
        if (language_atomic_load_relaxed(&codeinst->min_world) <= world && world <= language_atomic_load_relaxed(&codeinst->max_world)) {
            language_callptr_t invoke = language_atomic_load_acquire(&codeinst->invoke);
            if (invoke != NULL) {
                language_value_t *res = invoke(F, args, nargs, codeinst);
                return verify_type(res);
            }
        }
        codeinst = language_atomic_load_relaxed(&codeinst->next);
    }
    int64_t last_alloc = language_options.malloc_log ? language_gc_diff_total_bytes() : 0;
    int last_errno = errno;
#ifdef _OS_WINDOWS_
    DWORD last_error = GetLastError();
#endif
    codeinst = language_compile_method_internal(mfunc, world);
#ifdef _OS_WINDOWS_
    SetLastError(last_error);
#endif
    errno = last_errno;
    if (language_options.malloc_log)
        language_gc_sync_total_bytes(last_alloc); // discard allocation count from compilation
    language_callptr_t invoke = language_atomic_load_acquire(&codeinst->invoke);
    language_value_t *res = invoke(F, args, nargs, codeinst);
    return verify_type(res);
}

LANGUAGE_DLLEXPORT language_value_t *language_invoke(language_value_t *F, language_value_t **args, uint32_t nargs, language_method_instance_t *mfunc)
{
    size_t world = language_current_task->world_age;
    return _language_invoke(F, args, nargs, mfunc, world);
}

STATIC_INLINE int sig_match_fast(language_value_t *arg1t, language_value_t **args, language_value_t **sig, size_t n)
{
    // NOTE: This function is a huge performance hot spot!!
    if (arg1t != sig[0])
        return 0;
    size_t i;
    for (i = 1; i < n; i++) {
        language_value_t *decl = sig[i];
        language_value_t *a = args[i - 1];
        if (language_typeof(a) != decl) {
            /*
              we are only matching concrete types here, and those types are
              hash-consed, so pointer comparison should work.
            */
            return 0;
        }
    }
    return 1;
}

_Atomic(language_typemap_entry_t*) call_cache[N_CALL_CACHE] LANGUAGE_GLOBALLY_ROOTED;
static _Atomic(uint8_t) pick_which[N_CALL_CACHE];
#ifdef LANGUAGE_GF_PROFILE
size_t ncalls;
void call_cache_stats()
{
    int pick_which_stat[4] = {0, 0, 0, 0};
    int i, count = 0;
    for (i = 0; i < N_CALL_CACHE; i++) {
        if (language_atomic_load_relaxed(&call_cache[i]))
            count++;
        ++pick_which_stat[language_atomic_load_relaxed(&pick_which[i]) & 3];
    }
    language_safe_printf("cache occupied: %d / %d; pick_which stats: {%d, %d, %d, %d}\n",
            count, N_CALL_CACHE,
            pick_which_stat[0], pick_which_stat[1], pick_which_stat[2], pick_which_stat[3]);
}
#endif

STATIC_INLINE language_method_instance_t *language_lookup_generic_(language_value_t *F, language_value_t **args, uint32_t nargs,
                                                       uint32_t callsite, size_t world)
{
#ifdef LANGUAGE_GF_PROFILE
    ncalls++;
#endif
#ifdef LANGUAGE_TRACE
    int traceen = trace_en; //&& ((char*)&mt < language_stack_hi-6000000);
    if (traceen)
        show_call(F, args, nargs);
#endif
    nargs++; // add F to argument count
    language_value_t *FT = language_typeof(F);

    /*
      search order:
      check associative hash based on callsite address for leafsig match
      look at concrete signatures
      if there is an exact match, return it
      otherwise look for a matching generic signature
      if no concrete or generic match, raise error
      if no generic match, use the concrete one even if inexact
      otherwise instantiate the generic method and use it
    */
    // compute the entry hashes
    // use different parts of the value
    // so that a collision across all of
    // them is less likely
    uint32_t cache_idx[4] = {
        (callsite) & (N_CALL_CACHE - 1),
        (callsite >> 8) & (N_CALL_CACHE - 1),
        (callsite >> 16) & (N_CALL_CACHE - 1),
        (callsite >> 24 | callsite << 8) & (N_CALL_CACHE - 1)};
    language_typemap_entry_t *entry = NULL;
    language_methtable_t *mt = NULL;
    int i;
    // check each cache entry to see if it matches
    //#pragma unroll
    //for (i = 0; i < 4; i++) {
    //    LOOP_BODY(i);
    //}
#define LOOP_BODY(_i) do { \
            i = _i; \
            entry = language_atomic_load_relaxed(&call_cache[cache_idx[i]]); \
            if (entry && nargs == language_svec_len(entry->sig->parameters) && \
                sig_match_fast(FT, args, language_svec_data(entry->sig->parameters), nargs) && \
                world >= language_atomic_load_relaxed(&entry->min_world) && world <= language_atomic_load_relaxed(&entry->max_world)) { \
                goto have_entry; \
            } \
        } while (0);
    LOOP_BODY(0);
    LOOP_BODY(1);
    LOOP_BODY(2);
    LOOP_BODY(3);
#undef LOOP_BODY
    i = 4;
    language_tupletype_t *tt = NULL;
    int64_t last_alloc = 0;
    if (i == 4) {
        // if no method was found in the associative cache, check the full cache
        LANGUAGE_TIMING(METHOD_LOOKUP_FAST, METHOD_LOOKUP_FAST);
        mt = language_gf_mtable(F);
        language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
        entry = NULL;
        if (leafcache != (language_genericmemory_t*)language_an_empty_memory_any &&
                language_typetagis(language_atomic_load_relaxed(&mt->cache), language_typemap_level_type)) {
            // hashing args is expensive, but looking at mt->cache is probably even more expensive
            tt = lookup_arg_type_tuple(F, args, nargs);
            if (tt != NULL)
                entry = lookup_leafcache(leafcache, (language_value_t*)tt, world);
        }
        if (entry == NULL) {
            language_typemap_t *cache = language_atomic_load_relaxed(&mt->cache); // XXX: gc root required?
            entry = language_typemap_assoc_exact(cache, F, args, nargs, language_cachearg_offset(mt), world);
            if (entry == NULL) {
                last_alloc = language_options.malloc_log ? language_gc_diff_total_bytes() : 0;
                if (tt == NULL) {
                    tt = arg_type_tuple(F, args, nargs);
                    entry = lookup_leafcache(leafcache, (language_value_t*)tt, world);
                }
            }
        }
        if (entry != NULL && entry->isleafsig && entry->simplesig == (void*)language_nothing && entry->guardsigs == language_emptysvec) {
            // put the entry into the cache if it's valid for a leafsig lookup,
            // using pick_which to slightly randomize where it ends up
            // (intentionally not atomically synchronized, since we're just using it for randomness)
            // TODO: use the thread's `cong` instead as a source of randomness
            int which = language_atomic_load_relaxed(&pick_which[cache_idx[0]]) + 1;
            language_atomic_store_relaxed(&pick_which[cache_idx[0]], which);
            language_atomic_store_release(&call_cache[cache_idx[which & 3]], entry);
        }
    }

    language_method_instance_t *mfunc;
    if (entry) {
have_entry:
        mfunc = entry->func.linfo;
    }
    else {
        assert(tt);
        // cache miss case
        mfunc = language_mt_assoc_by_type(mt, tt, world);
        if (language_options.malloc_log)
            language_gc_sync_total_bytes(last_alloc); // discard allocation count from compilation
        if (mfunc == NULL) {
#ifdef LANGUAGE_TRACE
            if (error_en)
                show_call(F, args, nargs);
#endif
            language_method_error(F, args, nargs, world);
            // unreachable
        }
    }

#ifdef LANGUAGE_TRACE
    if (traceen)
        language_printf(LANGUAGE_STDOUT, " at %s:%d\n", language_symbol_name(mfunc->def.method->file), mfunc->def.method->line);
#endif
    return mfunc;
}

LANGUAGE_DLLEXPORT language_value_t *language_apply_generic(language_value_t *F, language_value_t **args, uint32_t nargs)
{
    size_t world = language_current_task->world_age;
    language_method_instance_t *mfunc = language_lookup_generic_(F, args, nargs,
                                                     language_int32hash_fast(language_return_address()),
                                                     world);
    LANGUAGE_GC_PROMISE_ROOTED(mfunc);
    return _language_invoke(F, args, nargs, mfunc, world);
}

static language_method_match_t *_gf_invoke_lookup(language_value_t *types LANGUAGE_PROPAGATES_ROOT, language_value_t *mt, size_t world, size_t *min_valid, size_t *max_valid)
{
    language_value_t *unw = language_unwrap_unionall((language_value_t*)types);
    if (!language_is_tuple_type(unw))
        return NULL;
    if (language_tparam0(unw) == language_bottom_type)
        return NULL;
    if (mt == language_nothing)
        mt = (language_value_t*)language_method_table_for(unw);
    if (mt == language_nothing)
        mt = NULL;
    language_value_t *matches = ml_matches((language_methtable_t*)mt, (language_tupletype_t*)types, 1, 0, 0, world, 1, min_valid, max_valid, NULL);
    if (matches == language_nothing || language_array_nrows(matches) != 1)
        return NULL;
    language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(matches, 0);
    return matc;
}

LANGUAGE_DLLEXPORT language_value_t *language_gf_invoke_lookup(language_value_t *types, language_value_t *mt, size_t world)
{
    // Deprecated: Use language_gf_invoke_lookup_worlds for future development
    size_t min_valid = 0;
    size_t max_valid = ~(size_t)0;
    language_method_match_t *matc = _gf_invoke_lookup(types, mt, world, &min_valid, &max_valid);
    if (matc == NULL)
        return language_nothing;
    return (language_value_t*)matc->method;
}


LANGUAGE_DLLEXPORT language_value_t *language_gf_invoke_lookup_worlds(language_value_t *types, language_value_t *mt, size_t world, size_t *min_world, size_t *max_world)
{
    language_method_match_t *matc = _gf_invoke_lookup(types, mt, world, min_world, max_world);
    if (matc == NULL)
        return language_nothing;
    return (language_value_t*)matc;
}

// invoke()
// this does method dispatch with a set of types to match other than the
// types of the actual arguments. this means it sometimes does NOT call the
// most specific method for the argument types, so we need different logic.
// first we use the given types to look up a definition, then we perform
// caching and specialization within just that definition.
// every definition has its own private method table for this purpose.
//
// NOTE: assumes argument type is a subtype of the lookup type.
language_value_t *language_gf_invoke(language_value_t *types0, language_value_t *gf, language_value_t **args, size_t nargs)
{
    size_t world = language_current_task->world_age;
    language_value_t *types = NULL;
    LANGUAGE_GC_PUSH1(&types);
    types = language_argtype_with_function((language_value_t*)gf, types0);
    language_method_t *method = (language_method_t*)language_gf_invoke_lookup(types, language_nothing, world);
    LANGUAGE_GC_PROMISE_ROOTED(method);

    if ((language_value_t*)method == language_nothing) {
        language_method_error_bare(gf, types0, world);
        // unreachable
    }

    // now we have found the matching definition.
    // next look for or create a specialization of this definition.
    LANGUAGE_GC_POP();
    return language_gf_invoke_by_method(method, gf, args, nargs);
}

language_value_t *language_gf_invoke_by_method(language_method_t *method, language_value_t *gf, language_value_t **args, size_t nargs)
{
    language_method_instance_t *mfunc = NULL;
    language_typemap_entry_t *tm = NULL;
    language_typemap_t *invokes = language_atomic_load_relaxed(&method->invokes);
    if (invokes != language_nothing)
        tm = language_typemap_assoc_exact(invokes, gf, args, nargs, 1, 1);
    if (tm) {
        mfunc = tm->func.linfo;
    }
    else {
        int64_t last_alloc = language_options.malloc_log ? language_gc_diff_total_bytes() : 0;
        language_svec_t *tpenv = language_emptysvec;
        language_tupletype_t *tt = NULL;
        LANGUAGE_GC_PUSH2(&tpenv, &tt);
        LANGUAGE_LOCK(&method->writelock);
        invokes = language_atomic_load_relaxed(&method->invokes);
        tm = language_typemap_assoc_exact(invokes, gf, args, nargs, 1, 1);
        if (tm) {
            mfunc = tm->func.linfo;
        }
        else {
            tt = arg_type_tuple(gf, args, nargs);
            if (language_is_unionall(method->sig)) {
                int sub = language_subtype_matching((language_value_t*)tt, (language_value_t*)method->sig, &tpenv);
                assert(sub); (void)sub;
            }

            mfunc = cache_method(NULL, &method->invokes, (language_value_t*)method, tt, method, 1, 1, ~(size_t)0, tpenv);
        }
        LANGUAGE_UNLOCK(&method->writelock);
        LANGUAGE_GC_POP();
        if (language_options.malloc_log)
            language_gc_sync_total_bytes(last_alloc); // discard allocation count from compilation
    }
    LANGUAGE_GC_PROMISE_ROOTED(mfunc);
    size_t world = language_current_task->world_age;
    return _language_invoke(gf, args, nargs - 1, mfunc, world);
}

// Return value is rooted globally
language_function_t *language_new_generic_function_with_supertype(language_sym_t *name, language_module_t *module, language_datatype_t *st)
{
    // type name is function name prefixed with #
    size_t l = strlen(language_symbol_name(name));
    char *prefixed;
    prefixed = (char*)malloc_s(l+2);
    prefixed[0] = '#';
    strcpy(&prefixed[1], language_symbol_name(name));
    language_sym_t *tname = language_symbol(prefixed);
    free(prefixed);
    language_datatype_t *ftype = (language_datatype_t*)language_new_datatype(
            tname, module, st, language_emptysvec, language_emptysvec, language_emptysvec, language_emptysvec,
            0, 0, 0);
    assert(language_is_datatype(ftype));
    LANGUAGE_GC_PUSH1(&ftype);
    ftype->name->mt->name = name;
    language_gc_wb(ftype->name->mt, name);
    language_set_const(module, tname, (language_value_t*)ftype);
    language_value_t *f = language_new_struct(ftype);
    ftype->instance = f;
    language_gc_wb(ftype, f);
    LANGUAGE_GC_POP();
    return (language_function_t*)f;
}

language_function_t *language_new_generic_function(language_sym_t *name, language_module_t *module)
{
    return language_new_generic_function_with_supertype(name, module, language_function_type);
}

struct ml_matches_env {
    // inputs:
    struct typemap_intersection_env match;
    int intersections;
    size_t world;
    int lim;
    int include_ambiguous;
    // results:
    language_value_t *t; // array of method matches
    language_method_match_t *matc; // current working method match
};

enum SIGNATURE_FULLY_COVERS {
    NOT_FULLY_COVERS = 0,
    FULLY_COVERS = 1,
    SENTINEL    = 2,
};

static language_method_match_t *make_method_match(language_tupletype_t *spec_types, language_svec_t *sparams, language_method_t *method, enum SIGNATURE_FULLY_COVERS fully_covers)
{
    language_task_t *ct = language_current_task;
    language_method_match_t *match = (language_method_match_t*)language_gc_alloc(ct->ptls, sizeof(language_method_match_t), language_method_match_type);
    match->spec_types = spec_types;
    match->sparams = sparams;
    match->method = method;
    match->fully_covers = fully_covers;
    return match;
}

static int ml_matches_visitor(language_typemap_entry_t *ml, struct typemap_intersection_env *closure0)
{
    struct ml_matches_env *closure = container_of(closure0, struct ml_matches_env, match);
    if (closure->intersections == 0 && !closure0->issubty)
        return 1;
    size_t min_world = language_atomic_load_relaxed(&ml->min_world);
    size_t max_world = language_atomic_load_relaxed(&ml->max_world);
    if (closure->world < min_world) {
        // ignore method table entries that are part of a later world
        if (closure->match.max_valid >= min_world)
            closure->match.max_valid = min_world - 1;
        return 1;
    }
    else if (closure->world > max_world) {
        // ignore method table entries that have been replaced in the current world
        if (closure->match.min_valid <= max_world)
            closure->match.min_valid = max_world + 1;
        return 1;
    }
    language_method_t *meth = ml->func.method;
    if (closure->lim >= 0 && language_is_dispatch_tupletype(meth->sig)) {
        int replaced = 0;
        // check if this is replaced, in which case we need to avoid double-counting it against the limit
        // (although it will figure out later which one to keep and return)
        size_t len = language_array_nrows(closure->t);
        for (int i = 0; i < len; i++) {
            if (language_types_equal(((language_method_match_t*)language_array_ptr_ref(closure->t, i))->method->sig, meth->sig)) {
                replaced = 1;
                break;
            }
        }
        if (!replaced) {
            if (closure->lim == 0)
                return 0;
            closure->lim--;
        }
    }
    // don't need to consider other similar methods if this ml will always fully intersect with them and dominates all of them
    if (!closure->include_ambiguous || closure->lim != -1)
        typemap_slurp_search(ml, &closure->match);
    closure->matc = make_method_match((language_tupletype_t*)closure->match.ti,
        closure->match.env, meth,
        closure->match.issubty ? FULLY_COVERS : NOT_FULLY_COVERS);
    size_t len = language_array_nrows(closure->t);
    if (len == 0) {
        closure->t = (language_value_t*)language_alloc_vec_any(1);
        language_array_ptr_set(closure->t, 0, (language_value_t*)closure->matc);
    }
    else {
        language_array_ptr_1d_push((language_array_t*)closure->t, (language_value_t*)closure->matc);
    }
    return 1;
}

static int ml_mtable_visitor(language_methtable_t *mt, void *closure0)
{
    struct typemap_intersection_env* env = (struct typemap_intersection_env*)closure0;
    return language_typemap_intersection_visitor(language_atomic_load_relaxed(&mt->defs), language_cachearg_offset(mt), env);
}

// Visit the candidate methods, starting from t[idx], to determine a possible valid sort ordering,
// where every morespecific method appears before any method which it has a common
// intersection with but is not partly ambiguous with (ambiguity is transitive, particularly
// if lim==-1, although morespecific is not transitive).
// Implements Tarjan's SCC (strongly connected components) algorithm, simplified to remove the count variable
// Inputs:
//  * `t`: the array of vertexes (method matches)
//  * `idx`: the next vertex to add to the output
//  * `visited`: the state of the algorithm for each vertex in `t`: either 1 if we visited it already or 1+depth if we are visiting it now
//  * `stack`: the state of the algorithm for the current vertex (up to length equal to `t`): the list of all vertexes currently in the depth-first path or in the current SCC
//  * `result`: the output of the algorithm, a sorted list of vertexes (up to length `lim`)
//  * `allambig`: a list of all vertexes with an ambiguity (up to length equal to `t`), discovered while running the rest of the algorithm
//  * `lim`: either -1 for unlimited matches, or the maximum length for `result` before returning failure (return -1).
//           If specified as -1, this will return extra matches that would have been elided from the list because they were already covered by an earlier match.
//           This gives a sort of maximal set of matching methods (up to the first minmax method).
//           If specified as -1, the sorting will also include all "weak" edges (every ambiguous pair) which will create much larger ambiguity cycles,
//           resulting in a less accurate sort order and much less accurate `*has_ambiguity` result.
//  * `include_ambiguous`: whether to filter out fully ambiguous matches from `result`
//  * `*has_ambiguity`: whether the algorithm does not need to compute if there is an unresolved ambiguity
//  * `*found_minmax`: whether there is a minmax method already found, so future fully_covers matches should be ignored
// Outputs:
//  * `*has_ambiguity`: whether the caller should check if there remains an unresolved ambiguity (in `allambig`)
// Returns:
//  * -1: too many matches for lim, other outputs are undefined
//  *  0: the child(ren) have been added to the output
//  * 1+: the children are part of this SCC (up to this depth)
// TODO: convert this function into an iterative call, rather than recursive
static int sort_mlmatches(language_array_t *t, size_t idx, arraylist_t *visited, arraylist_t *stack, arraylist_t *result, arraylist_t *allambig, int lim, int include_ambiguous, int *has_ambiguity, int *found_minmax)
{
    size_t cycle = (size_t)visited->items[idx];
    if (cycle != 0)
        return cycle - 1; // depth remaining
    language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(t, idx);
    language_method_t *m = matc->method;
    language_value_t *ti = (language_value_t*)matc->spec_types;
    int subt = matc->fully_covers != NOT_FULLY_COVERS; // language_subtype((language_value_t*)type, (language_value_t*)m->sig)
    // first check if this new method is actually already fully covered by an
    // existing match and we can just ignore this entry quickly
    size_t result_len = 0;
    if (subt) {
        if (*found_minmax == 2)
            visited->items[idx] = (void*)1;
    }
    else if (lim != -1) {
        for (; result_len < result->len; result_len++) {
            size_t idx2 = (size_t)result->items[result_len];
            language_method_match_t *matc2 = (language_method_match_t*)language_array_ptr_ref(t, idx2);
            language_method_t *m2 = matc2->method;
            if (language_subtype(ti, m2->sig)) {
                if (include_ambiguous) {
                    if (!language_method_morespecific(m2, m))
                        continue;
                }
                visited->items[idx] = (void*)1;
                break;
            }
        }
    }
    if ((size_t)visited->items[idx] == 1)
        return 0;
    arraylist_push(stack, (void*)idx);
    size_t depth = stack->len;
    visited->items[idx] = (void*)(1 + depth);
    cycle = depth;
    int addambig = 0;
    int mayexclude = 0;
    // First visit all "strong" edges where the child is definitely better.
    // This likely won't hit any cycles, but might (because morespecific is not transitive).
    // Along the way, record if we hit any ambiguities-we may need to track those later.
    for (size_t childidx = 0; childidx < language_array_nrows(t); childidx++) {
        if (childidx == idx)
            continue;
        int child_cycle = (size_t)visited->items[childidx];
        if (child_cycle == 1)
            continue; // already handled
        if (child_cycle != 0 && child_cycle - 1 >= cycle)
            continue; // already part of this cycle
        language_method_match_t *matc2 = (language_method_match_t*)language_array_ptr_ref(t, childidx);
        language_method_t *m2 = matc2->method;
        int subt2 = matc2->fully_covers == FULLY_COVERS; // language_subtype((language_value_t*)type, (language_value_t*)m2->sig)
        // TODO: we could change this to language_has_empty_intersection(ti, (language_value_t*)matc2->spec_types);
        // since we only care about sorting of the intersections the user asked us about
        if (!subt2 && language_has_empty_intersection(m2->sig, m->sig))
            continue;
        int msp = language_method_morespecific(m, m2);
        int msp2 = !msp && language_method_morespecific(m2, m);
        if (!msp) {
            if (subt || !include_ambiguous || (lim != -1 && msp2)) {
                if (subt2 || language_subtype((language_value_t*)ti, m2->sig)) {
                    // this may be filtered out as fully intersected, if applicable later
                    mayexclude = 1;
                }
            }
            if (!msp2) {
                addambig = 1; // record there is a least one previously-undetected ambiguity that may need to be investigated later (between m and m2)
            }
        }
        if (lim == -1 ? msp : !msp2) // include only strong or also weak edges, depending on whether the result size is limited
            continue;
        // m2 is (lim!=-1 ? better : not-worse), so attempt to visit it first
        // if limited, then we want to visit only better edges, because that results in finding k best matches quickest
        // if not limited, then we want to visit all edges, since that results in finding the largest SCC cycles, which requires doing the fewest intersections
        child_cycle = sort_mlmatches(t, childidx, visited, stack, result, allambig, lim, include_ambiguous, has_ambiguity, found_minmax);
        if (child_cycle == -1)
            return -1;
        if (child_cycle && child_cycle < cycle) {
            // record the cycle will resolve at depth "cycle"
            cycle = child_cycle;
        }
        if (stack->len == depth) {
            // if this child resolved without hitting a cycle, then there is
            // some probability that this method is already fully covered now
            // (same check as before), and we can delete this vertex now without
            // anyone noticing (too much)
            if (subt) {
                if (*found_minmax == 2)
                    visited->items[idx] = (void*)1;
            }
            else if (lim != -1) {
                for (; result_len < result->len; result_len++) {
                    size_t idx2 = (size_t)result->items[result_len];
                    language_method_match_t *matc2 = (language_method_match_t*)language_array_ptr_ref(t, idx2);
                    language_method_t *m2 = matc2->method;
                    if (language_subtype(ti, m2->sig)) {
                        if (include_ambiguous) {
                            if (!language_method_morespecific(m2, m))
                                continue;
                        }
                        visited->items[idx] = (void*)1;
                        break;
                    }
                }
            }
            if ((size_t)visited->items[idx] == 1) {
                // n.b. cycle might be < depth, if we had a cycle with a child
                // idx, but since we are on the top of the stack, nobody
                // observed that and so we are content to ignore this
                size_t childidx = (size_t)arraylist_pop(stack);
                assert(childidx == idx); (void)childidx;
                assert(!subt || *found_minmax == 2);
                return 0;
            }
        }
    }
    if (matc->fully_covers == NOT_FULLY_COVERS && addambig)
        arraylist_push(allambig, (void*)idx);
    if (cycle != depth)
        return cycle;
    result_len = result->len;
    if (stack->len == depth) {
        // Found one "best" method to add right now. But we might exclude it if
        // we determined earlier that we had that option.
        if (mayexclude) {
            if (!subt || *found_minmax == 2)
                visited->items[idx] = (void*)1;
        }
    }
    else {
        // We have a set of ambiguous methods. Record that.
        // This is greatly over-approximated for lim==-1
        *has_ambiguity = 1;
        // If we followed weak edges above, then this also fully closed the ambiguity cycle
        if (lim == -1)
            addambig = 0;
        // If we're only returning possible matches, now filter out this method
        // if its intersection is fully ambiguous in this SCC group.
        // This is a repeat of the "first check", now that we have completed the cycle analysis
        for (size_t i = depth - 1; i < stack->len; i++) {
            size_t childidx = (size_t)stack->items[i];
            language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(t, childidx);
            language_value_t *ti = (language_value_t*)matc->spec_types;
            int subt = matc->fully_covers != NOT_FULLY_COVERS; // language_subtype((language_value_t*)type, (language_value_t*)m->sig)
            if ((size_t)visited->items[childidx] == 1) {
                assert(subt);
                continue;
            }
            assert(visited->items[childidx] == (void*)(2 + i));
            // if we only followed strong edges before above
            // check also if this set has an unresolved ambiguity missing from it
            if (lim != -1 && !addambig) {
                for (size_t j = 0; j < allambig->len; j++) {
                    if ((size_t)allambig->items[j] == childidx) {
                        addambig = 1;
                        break;
                    }
                }
            }
            // always remove fully_covers matches after the first minmax ambiguity group is handled
            if (subt) {
                if (*found_minmax)
                    visited->items[childidx] = (void*)1;
                continue;
            }
            else if (lim != -1) {
                // when limited, don't include this match if it was covered by an earlier one
                for (size_t result_len = 0; result_len < result->len; result_len++) {
                    size_t idx2 = (size_t)result->items[result_len];
                    language_method_match_t *matc2 = (language_method_match_t*)language_array_ptr_ref(t, idx2);
                    language_method_t *m2 = matc2->method;
                    if (language_subtype(ti, m2->sig)) {
                        if (include_ambiguous) {
                            if (!language_method_morespecific(m2, m))
                                continue;
                        }
                        visited->items[childidx] = (void*)1;
                        break;
                    }
                }
            }
        }
        if (!include_ambiguous && lim == -1) {
            for (size_t i = depth - 1; i < stack->len; i++) {
                size_t childidx = (size_t)stack->items[i];
                if ((size_t)visited->items[childidx] == 1)
                    continue;
                language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(t, childidx);
                language_method_t *m = matc->method;
                language_value_t *ti = (language_value_t*)matc->spec_types;
                for (size_t j = depth - 1; j < stack->len; j++) {
                    if (i == j)
                        continue;
                    size_t idx2 = (size_t)stack->items[j];
                    language_method_match_t *matc2 = (language_method_match_t*)language_array_ptr_ref(t, idx2);
                    language_method_t *m2 = matc2->method;
                    int subt2 = matc2->fully_covers == FULLY_COVERS; // language_subtype((language_value_t*)type, (language_value_t*)m2->sig)
                    // if their intersection contributes to the ambiguity cycle
                    // and the contribution of m is fully ambiguous with the portion of the cycle from m2
                    if (subt2 || language_subtype((language_value_t*)ti, m2->sig)) {
                        // but they aren't themselves simply ordered (here
                        // we don't consider that a third method might be
                        // disrupting that ordering and just consider them
                        // pairwise to keep this simple).
                        if (!language_method_morespecific(m, m2) && !language_method_morespecific(m2, m)) {
                            visited->items[childidx] = (void*)-1;
                            break;
                        }
                    }
                }
            }
        }
    }
    // copy this cycle into the results
    for (size_t i = depth - 1; i < stack->len; i++) {
        size_t childidx = (size_t)stack->items[i];
        if ((size_t)visited->items[childidx] == 1)
            continue;
        if ((size_t)visited->items[childidx] != -1) {
            assert(visited->items[childidx] == (void*)(2 + i));
            visited->items[childidx] = (void*)-1;
            if (lim == -1 || result->len < lim)
                arraylist_push(result, (void*)childidx);
            else
                return -1;
        }
    }
    // now finally cleanup the stack
    while (stack->len >= depth) {
        size_t childidx = (size_t)arraylist_pop(stack);
        // always remove fully_covers matches after the first minmax ambiguity group is handled
        //language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(t, childidx);
        if (matc->fully_covers != NOT_FULLY_COVERS && !addambig)
            *found_minmax = 2;
        if (visited->items[childidx] != (void*)-1)
            continue;
        visited->items[childidx] = (void*)1;
    }
    return 0;
}


// This is the collect form of calling language_typemap_intersection_visitor
// with optimizations to skip fully shadowed methods.
//
// Returns a match as an array of svec(argtypes, static_params, Method, fully-covers).
//
// See below for the meaning of lim.
//
// fully-covers is a Bool indicating subtyping, though temporarily it may be
// tri-values, with `nothing` indicating a match that is not a subtype, but
// which is dominated by one which is (and thus should be excluded unless ambiguous)
static language_value_t *ml_matches(language_methtable_t *mt,
                              language_tupletype_t *type, int lim, int include_ambiguous,
                              int intersections, size_t world, int cache_result,
                              size_t *min_valid, size_t *max_valid, int *ambig)
{
    if (world > language_atomic_load_acquire(&language_world_counter))
        return language_nothing; // the future is not enumerable
    LANGUAGE_TIMING(METHOD_MATCH, METHOD_MATCH);
    int has_ambiguity = 0;
    language_value_t *unw = language_unwrap_unionall((language_value_t*)type);
    assert(language_is_datatype(unw));
    size_t l = language_svec_len(((language_datatype_t*)unw)->parameters);
    language_value_t *va = NULL;
    if (l > 0) {
        va = language_tparam(unw, l - 1);
        if (language_is_vararg(va))
            va = language_unwrap_vararg(va);
        else
            va = NULL;
    }
    struct ml_matches_env env = {{ml_matches_visitor, (language_value_t*)type, va, /* .search_slurp = */ 0,
            /* .min_valid = */ *min_valid, /* .max_valid = */ *max_valid,
            /* .ti = */ NULL, /* .env = */ language_emptysvec, /* .issubty = */ 0},
        intersections, world, lim, include_ambiguous, /* .t = */ language_an_empty_vec_any,
        /* .matc = */ NULL};
    struct language_typemap_assoc search = {(language_value_t*)type, world, language_emptysvec};
    language_value_t *isect2 = NULL;
    LANGUAGE_GC_PUSH6(&env.t, &env.matc, &env.match.env, &search.env, &env.match.ti, &isect2);

    if (mt) {
        // check the leaf cache if this type can be in there
        if (((language_datatype_t*)unw)->isdispatchtuple) {
            language_genericmemory_t *leafcache = language_atomic_load_relaxed(&mt->leafcache);
            language_typemap_entry_t *entry = lookup_leafcache(leafcache, (language_value_t*)type, world);
            if (entry) {
                language_method_instance_t *mi = entry->func.linfo;
                language_method_t *meth = mi->def.method;
                if (!language_is_unionall(meth->sig)) {
                    env.match.env = language_emptysvec;
                    env.match.ti = unw;
                }
                else if (language_egal((language_value_t*)type, mi->specTypes)) {
                    env.match.env = mi->sparam_vals;
                    env.match.ti = mi->specTypes;
                }
                else {
                    // this just calls language_subtype_env (since we know that `type <: meth->sig` by transitivity)
                    env.match.ti = language_type_intersection_env((language_value_t*)type, (language_value_t*)meth->sig, &env.match.env);
                }
                env.matc = make_method_match((language_tupletype_t*)env.match.ti,
                    env.match.env, meth, FULLY_COVERS);
                env.t = (language_value_t*)language_alloc_vec_any(1);
                language_array_ptr_set(env.t, 0, env.matc);
                size_t min_world = language_atomic_load_relaxed(&entry->min_world);
                size_t max_world = language_atomic_load_relaxed(&entry->max_world);
                if (*min_valid < min_world)
                    *min_valid = min_world;
                if (*max_valid > max_world)
                    *max_valid = max_world;
                LANGUAGE_GC_POP();
                return env.t;
            }
        }
        // then check the full cache if it seems profitable
        if (((language_datatype_t*)unw)->isdispatchtuple) {
            language_typemap_entry_t *entry = language_typemap_assoc_by_type(language_atomic_load_relaxed(&mt->cache), &search, language_cachearg_offset(mt), /*subtype*/1);
            if (entry && (((language_datatype_t*)unw)->isdispatchtuple || entry->guardsigs == language_emptysvec)) {
                language_method_instance_t *mi = entry->func.linfo;
                language_method_t *meth = mi->def.method;
                if (!language_is_unionall(meth->sig) && ((language_datatype_t*)unw)->isdispatchtuple) {
                    env.match.env = language_emptysvec;
                    env.match.ti = unw;
                }
                else {
                    // this just calls language_subtype_env (since we know that `type <: meth->sig` by transitivity)
                    env.match.ti = language_type_intersection_env((language_value_t*)type, (language_value_t*)meth->sig, &env.match.env);
                }
                env.matc = make_method_match((language_tupletype_t*)env.match.ti,
                    env.match.env, meth, FULLY_COVERS);
                env.t = (language_value_t*)language_alloc_vec_any(1);
                language_array_ptr_set(env.t, 0, env.matc);
                size_t min_world = language_atomic_load_relaxed(&entry->min_world);
                size_t max_world = language_atomic_load_relaxed(&entry->max_world);
                if (*min_valid < min_world)
                    *min_valid = min_world;
                if (*max_valid > max_world)
                    *max_valid = max_world;
                LANGUAGE_GC_POP();
                return env.t;
            }
        }
        if (!ml_mtable_visitor(mt, &env.match)) {
            LANGUAGE_GC_POP();
            // if we return early, set only the min/max valid collected from matching
            *min_valid = env.match.min_valid;
            *max_valid = env.match.max_valid;
            return language_nothing;
        }
    }
    else {
        // else: scan everything
        if (!language_foreach_reachable_mtable(ml_mtable_visitor, &env.match)) {
            LANGUAGE_GC_POP();
            // if we return early, set only the min/max valid collected from matching
            *min_valid = env.match.min_valid;
            *max_valid = env.match.max_valid;
            return language_nothing;
        }
    }
    // if we return early, set only the min/max valid collected from matching
    *min_valid = env.match.min_valid;
    *max_valid = env.match.max_valid;
    // done with many of these values now
    env.match.ti = NULL; env.matc = NULL; env.match.env = NULL; search.env = NULL;
    size_t i, j, len = language_array_nrows(env.t);
    language_method_match_t *minmax = NULL;
    int minmax_ambig = 0;
    int all_subtypes = 1;
    if (len > 1) {
        // first try to pre-process the results to find the most specific
        // result that fully covers the input, since we can do this in linear
        // time, and the rest is O(n^2)
        //   - first find a candidate for the best of these method results
        for (i = 0; i < len; i++) {
            language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, i);
            if (matc->fully_covers == FULLY_COVERS) {
                language_method_t *m = matc->method;
                if (minmax != NULL) {
                    language_method_t *minmaxm = minmax->method;
                    if (language_method_morespecific(minmaxm, m))
                        continue;
                }
                minmax = matc;
            }
            else {
                all_subtypes = 0;
            }
        }
        //   - then see if it dominated all of the other choices
        if (minmax != NULL) {
            for (i = 0; i < len; i++) {
                language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, i);
                if (matc == minmax)
                    break;
                if (matc->fully_covers == FULLY_COVERS) {
                    language_method_t *m = matc->method;
                    language_method_t *minmaxm = minmax->method;
                    if (!language_method_morespecific(minmaxm, m)) {
                        minmax_ambig = 1;
                        minmax = NULL;
                        has_ambiguity = 1;
                        break;
                    }
                }
            }
        }
        //   - it may even dominate some choices that are not subtypes!
        //     move those into the subtype group, where we're filter them out shortly after
        //     (potentially avoiding reporting these as an ambiguity, and
        //     potentially allowing us to hit the next fast path)
        //   - we could always check here if *any* FULLY_COVERS method is
        //     more-specific (instead of just considering minmax), but that may
        //     cost much extra and is less likely to help us hit a fast path
        //     (we will look for this later, when we compute ambig_groupid, for
        //     correctness)
        if (!all_subtypes && minmax != NULL) {
            language_method_t *minmaxm = minmax->method;
            all_subtypes = 1;
            for (i = 0; i < len; i++) {
                language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, i);
                if (matc->fully_covers != FULLY_COVERS) {
                    language_method_t *m = matc->method;
                    if (language_method_morespecific(minmaxm, m))
                        matc->fully_covers = SENTINEL; // put a sentinel value here for sorting
                    else
                        all_subtypes = 0;
                }
            }
        }
        //    - now we might have a fast-return here, if we see that
        //      we've already processed all of the possible outputs
        if (all_subtypes) {
            if (minmax_ambig) {
                if (!include_ambiguous) {
                    len = 0;
                    env.t = language_an_empty_vec_any;
                }
                else if (lim == 1) {
                    LANGUAGE_GC_POP();
                    return language_nothing;
                }
            }
            else {
                assert(minmax != NULL);
                language_array_ptr_set(env.t, 0, minmax);
                language_array_del_end((language_array_t*)env.t, len - 1);
                len = 1;
            }
        }
        if (minmax && lim == 0) {
            // protect some later algorithms from underflow
            LANGUAGE_GC_POP();
            return language_nothing;
        }
    }
    if (len > 1) {
        arraylist_t stack, visited, result, allambig;
        arraylist_new(&result, lim != -1 && lim < len ? lim : len);
        arraylist_new(&stack, 0);
        arraylist_new(&visited, len);
        arraylist_new(&allambig, len);
        arraylist_grow(&visited, len);
        memset(visited.items, 0, len * sizeof(size_t));
        // if we had a minmax method (any subtypes), now may now be able to
        // quickly cleanup some of methods
        int found_minmax = 0;
        if (minmax != NULL)
            found_minmax = 2;
        else if (minmax_ambig && !include_ambiguous)
            found_minmax = 1;
        if (ambig == NULL) // if we don't care about the result, set it now so we won't bother attempting to compute it accurately later
            has_ambiguity = 1;
        for (i = 0; i < len; i++) {
            assert(visited.items[i] == (void*)0 || visited.items[i] == (void*)1);
            language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, i);
            if (matc->fully_covers != NOT_FULLY_COVERS && found_minmax) {
                // this was already handled above and below, so we won't learn anything new
                // by visiting it and it might be a bit costly
                continue;
            }
            int child_cycle = sort_mlmatches((language_array_t*)env.t, i, &visited, &stack, &result, &allambig, lim == -1 || minmax == NULL ? lim : lim - 1, include_ambiguous, &has_ambiguity, &found_minmax);
            if (child_cycle == -1) {
                arraylist_free(&allambig);
                arraylist_free(&visited);
                arraylist_free(&stack);
                arraylist_free(&result);
                LANGUAGE_GC_POP();
                return language_nothing;
            }
            assert(child_cycle == 0); (void)child_cycle;
            assert(stack.len == 0);
            assert(visited.items[i] == (void*)1);
        }
        // now compute whether there were ambiguities left in this cycle
        if (has_ambiguity == 0 && allambig.len > 0) {
            if (lim == -1) {
                // lim is over-approximated, so has_ambiguities is too
                has_ambiguity = 1;
            }
            else {
                // go back and find the additional ambiguous methods and temporary add them to the stack
                // (potentially duplicating them from lower on the stack to here)
                language_value_t *ti = NULL;
                language_value_t *isect2 = NULL;
                LANGUAGE_GC_PUSH2(&ti, &isect2);
                for (size_t i = 0; i < allambig.len; i++) {
                    size_t idx = (size_t)allambig.items[i];
                    language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, idx);
                    language_method_t *m = matc->method;
                    int subt = matc->fully_covers == FULLY_COVERS; // language_subtype((language_value_t*)type, (language_value_t*)m->sig)
                    for (size_t idx2 = 0; idx2 < language_array_nrows(env.t); idx2++) {
                        if (idx2 == idx)
                            continue;
                        // laborious test, checking for existence and coverage of another method (m3)
                        // outside of the ambiguity group that dominates any ambiguous methods,
                        // and means we can ignore this for has_ambiguity
                        // (has_ambiguity is overestimated for lim==-1, since we don't compute skipped matches either)
                        // n.b. even if we skipped them earlier, they still might
                        // contribute to the ambiguities (due to lock of transitivity of
                        // morespecific over subtyping)
                        // TODO: we could improve this result by checking if the removal of some
                        // edge earlier means that this subgraph is now well-ordered and then be
                        // allowed to ignore these vertexes entirely here
                        language_method_match_t *matc2 = (language_method_match_t*)language_array_ptr_ref(env.t, idx2);
                        language_method_t *m2 = matc2->method;
                        int subt2 = matc2->fully_covers == FULLY_COVERS; // language_subtype((language_value_t*)type, (language_value_t*)m2->sig)
                        if (subt) {
                            ti = (language_value_t*)matc2->spec_types;
                            isect2 = NULL;
                        }
                        else if (subt2) {
                            ti = (language_value_t*)matc->spec_types;
                            isect2 = NULL;
                        }
                        else {
                            language_type_intersection2((language_value_t*)matc->spec_types, (language_value_t*)matc2->spec_types, &ti, &isect2);
                        }
                        // if their intersection contributes to the ambiguity cycle
                        if (ti == language_bottom_type)
                            continue;
                        // and they aren't themselves simply ordered
                        if (language_method_morespecific(m, m2) || language_method_morespecific(m2, m))
                            continue;
                        // now look for a third method m3 that dominated these and that fully covered this intersection already
                        size_t k;
                        for (k = 0; k < result.len; k++) {
                            size_t idx3 = (size_t)result.items[k];
                            if (idx3 == idx || idx3 == idx2) {
                                has_ambiguity = 1;
                                break;
                            }
                            language_method_match_t *matc3 = (language_method_match_t*)language_array_ptr_ref(env.t, idx3);
                            language_method_t *m3 = matc3->method;
                            if ((language_subtype(ti, m3->sig) || (isect2 && language_subtype(isect2, m3->sig)))
                                    && language_method_morespecific(m3, m) && language_method_morespecific(m3, m2)) {
                                //if (language_subtype(matc->spec_types, ti) || language_subtype(matc->spec_types, matc3->m3->sig))
                                //    // check if it covered not only this intersection, but all intersections with matc
                                //    // if so, we do not need to check all of them separately
                                //    j = len;
                                break;
                            }
                        }
                        if (k == result.len)
                            has_ambiguity = 1;
                        isect2 = NULL;
                        ti = NULL;
                        if (has_ambiguity)
                            break;
                    }
                    if (has_ambiguity)
                        break;
                }
                LANGUAGE_GC_POP();
            }
        }
        arraylist_free(&allambig);
        arraylist_free(&visited);
        arraylist_free(&stack);
        for (j = 0; j < result.len; j++) {
            i = (size_t)result.items[j];
            language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, i);
            // remove our sentinel entry markers
            if (matc->fully_covers == SENTINEL)
                matc->fully_covers = NOT_FULLY_COVERS;
            result.items[j] = (void*)matc;
        }
        if (minmax) {
            arraylist_push(&result, minmax);
            j++;
        }
        memcpy(language_array_data(env.t, language_method_match_t*), result.items, j * sizeof(language_method_match_t*));
        arraylist_free(&result);
        if (j != len)
            language_array_del_end((language_array_t*)env.t, len - j);
        len = j;
    }
    for (j = 0; j < len; j++) {
        language_method_match_t *matc = (language_method_match_t*)language_array_ptr_ref(env.t, j);
        language_method_t *m = matc->method;
        // method applicability is the same as typemapentry applicability
        size_t min_world = language_atomic_load_relaxed(&m->primary_world);
        size_t max_world = language_atomic_load_relaxed(&m->deleted_world);
        // intersect the env valid range with method lookup's inclusive valid range
        if (env.match.min_valid < min_world)
            env.match.min_valid = min_world;
        if (env.match.max_valid > max_world)
            env.match.max_valid = max_world;
    }
    if (mt && cache_result && ((language_datatype_t*)unw)->isdispatchtuple) { // cache_result parameter keeps this from being recursive
        if (len == 1 && !has_ambiguity) {
            env.matc = (language_method_match_t*)language_array_ptr_ref(env.t, 0);
            language_method_t *meth = env.matc->method;
            language_svec_t *tpenv = env.matc->sparams;
            LANGUAGE_LOCK(&mt->writelock);
            cache_method(mt, &mt->cache, (language_value_t*)mt, (language_tupletype_t*)unw, meth, world, env.match.min_valid, env.match.max_valid, tpenv);
            LANGUAGE_UNLOCK(&mt->writelock);
        }
    }
    *min_valid = env.match.min_valid;
    *max_valid = env.match.max_valid;
    if (ambig != NULL)
        *ambig = has_ambiguity;
    LANGUAGE_GC_POP();
    if (lim >= 0 && len > lim)
        return language_nothing;
    return env.t;
}

// see if it might be possible to construct an instance of `typ`
// if n_uninitialized == 0, but a fieldtype is Union{},
// that type will not be constructable, for example, tested recursively
int language_has_concrete_subtype(language_value_t *typ)
{
    if (typ == language_bottom_type)
        return 0;
    typ = language_unwrap_unionall(typ);
    if (language_is_vararg(typ))
        typ = language_unwrap_vararg(typ);
    if (!language_is_datatype(typ))
        return 1;
    return ((language_datatype_t*)typ)->has_concrete_subtype;
}

LANGUAGE_DLLEXPORT uint64_t language_typeinf_timing_begin(void)
{
    language_task_t *ct = language_current_task;
    if (ct->reentrant_timing & 1)
        return 0;
    ct->reentrant_timing |= 1;
    return language_hrtime();
}

LANGUAGE_DLLEXPORT void language_typeinf_timing_end(uint64_t start, int is_recompile)
{
    if (!start)
        return;
    language_task_t *ct = language_current_task;
    ct->reentrant_timing &= ~1u;
    if (language_atomic_load_relaxed(&language_measure_compile_time_enabled)) {
        uint64_t inftime = language_hrtime() - start;
        language_atomic_fetch_add_relaxed(&language_cumulative_compile_time, inftime);
        if (is_recompile) {
            language_atomic_fetch_add_relaxed(&language_cumulative_recompile_time, inftime);
        }
    }
}

#ifdef __cplusplus
}
#endif
