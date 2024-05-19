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

/*
  utility functions used by the runtime system, generated code, and Base library
*/
#include "platform.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <setjmp.h>
#include <sys/types.h>
#include <errno.h>
#include <fcntl.h>
#include <inttypes.h>
#if defined(_OS_WINDOWS_)
#include <malloc.h>
#else
#include <unistd.h>
#endif
#include <ctype.h>
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

// exceptions -----------------------------------------------------------------

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_error(const char *str)
{
    if (language_errorexception_type == NULL) {
        language_printf(LANGUAGE_STDERR, "ERROR: %s\n", str);
        language_exit(1);
    }
    language_value_t *msg = language_pchar_to_string((char*)str, strlen(str));
    LANGUAGE_GC_PUSH1(&msg);
    language_throw(language_new_struct(language_errorexception_type, msg));
}

extern int vasprintf(char **str, const char *fmt, va_list ap);

language_value_t *language_vexceptionf(language_datatype_t *exception_type,
                           const char *fmt, va_list args)
{
    if (exception_type == NULL) {
        language_printf(LANGUAGE_STDERR, "ERROR: ");
        language_vprintf(LANGUAGE_STDERR, fmt, args);
        language_printf(LANGUAGE_STDERR, "\n");
        language_exit(1);
    }
    char *str = NULL;
    int ok = vasprintf(&str, fmt, args);
    language_value_t *msg;
    if (ok < 0) {  // vasprintf failed
        msg = language_cstr_to_string("internal error: could not display error message");
    }
    else {
        msg = language_pchar_to_string(str, strlen(str));
        free(str);
    }
    LANGUAGE_GC_PUSH1(&msg);
    language_value_t *e = language_new_struct(exception_type, msg);
    LANGUAGE_GC_POP();
    return e;
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_errorf(const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    language_value_t *e = language_vexceptionf(language_errorexception_type, fmt, args);
    va_end(args);
    language_throw(e);
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_exceptionf(language_datatype_t *exception_type,
                                            const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    language_value_t *e = language_vexceptionf(exception_type, fmt, args);
    va_end(args);
    language_throw(e);
}

language_value_t *language_get_exceptionf(language_datatype_t *exception_type,
                              const char *fmt, ...)
{
    va_list args;
    va_start(args, fmt);
    language_value_t *e = language_vexceptionf(exception_type, fmt, args);
    va_end(args);
    return e;
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_too_few_args(const char *fname, int min)
{
    language_exceptionf(language_argumenterror_type, "%s: too few arguments (expected %d)", fname, min);
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_too_many_args(const char *fname, int max)
{
    language_exceptionf(language_argumenterror_type, "%s: too many arguments (expected %d)", fname, max);
}

// with function name / location description, plus extra context
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_type_error_rt(const char *fname, const char *context,
                                               language_value_t *expected LANGUAGE_MAYBE_UNROOTED,
                                               language_value_t *got LANGUAGE_MAYBE_UNROOTED)
{
    language_value_t *ctxt=NULL;
    LANGUAGE_GC_PUSH3(&ctxt, &expected, &got);
    ctxt = language_pchar_to_string((char*)context, strlen(context));
    language_value_t *ex = language_new_struct(language_typeerror_type, language_symbol(fname), ctxt, expected, got);
    language_throw(ex);
}

// with function name or description only
LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_type_error(const char *fname,
                                            language_value_t *expected LANGUAGE_MAYBE_UNROOTED,
                                            language_value_t *got LANGUAGE_MAYBE_UNROOTED)
{
    language_type_error_rt(fname, "", expected, got);
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_undefined_var_error(language_sym_t *var, language_value_t *scope)
{
    if (!language_undefvarerror_type) {
        const char *s1 = "";
        const char *s2 = "";
        if (scope) {
            if (language_is_symbol(scope)) {
                s1 = ", :";
                s2 = language_symbol_name((language_sym_t*)scope);
            }
            else if (language_is_module(scope)) {
                s1 = ", module ";
                s2 = language_symbol_name(((language_module_t*)scope)->name);
            }
            else {
                s1 = ", ";
                s2 = "unknown scope";
            }
        }
        language_errorf("UndefVarError(%s%s%s)", language_symbol_name(var), s1, s2);
    }
    LANGUAGE_GC_PUSH1(&scope);
    language_throw(language_new_struct(language_undefvarerror_type, var, scope));
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_has_no_field_error(language_sym_t *type_name, language_sym_t *var)
{
    language_errorf("type %s has no field %s", language_symbol_name(type_name), language_symbol_name(var));
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_atomic_error(char *str) // == language_exceptionf(language_atomicerror_type, "%s", str)
{
    language_value_t *msg = language_pchar_to_string((char*)str, strlen(str));
    LANGUAGE_GC_PUSH1(&msg);
    language_throw(language_new_struct(language_atomicerror_type, msg));
}


LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error(language_value_t *v, language_value_t *t)
{
    LANGUAGE_GC_PUSH2(&v, &t); // root arguments so the caller doesn't need to
    language_throw(language_new_struct((language_datatype_t*)language_boundserror_type, v, t));
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_v(language_value_t *v, language_value_t **idxs, size_t nidxs)
{
    language_value_t *t = NULL;
    // items in idxs are assumed to already be rooted
    LANGUAGE_GC_PUSH2(&v, &t); // root v so the caller doesn't need to
    t = language_f_tuple(NULL, idxs, nidxs);
    language_throw(language_new_struct((language_datatype_t*)language_boundserror_type, v, t));
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_tuple_int(language_value_t **v, size_t nv, size_t i)
{
    // values in v are expected to already be gc-rooted
    language_bounds_error_int(language_f_tuple(NULL, v, nv), i);
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_unboxed_int(void *data, language_value_t *vt, size_t i)
{
    language_value_t *t = NULL, *v = NULL;
    // data is expected to be gc-safe (either gc-rooted, or alloca)
    // vt is expected to be gc-rooted (in a linfo-root probably)
    LANGUAGE_GC_PUSH2(&v, &t);
    v = language_new_bits(vt, data);
    t = language_box_long(i);
    language_throw(language_new_struct((language_datatype_t*)language_boundserror_type, v, t));
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_int(language_value_t *v LANGUAGE_MAYBE_UNROOTED, size_t i)
{
    language_value_t *t = NULL;
    LANGUAGE_GC_PUSH2(&v, &t); // root arguments so the caller doesn't need to
    t = language_box_long(i);
    language_throw(language_new_struct((language_datatype_t*)language_boundserror_type, v, t));
}

LANGUAGE_DLLEXPORT void LANGUAGE_NORETURN language_bounds_error_ints(language_value_t *v LANGUAGE_MAYBE_UNROOTED,
                                                   size_t *idxs, size_t nidxs)
{
    size_t i;
    language_value_t *t = NULL;
    LANGUAGE_GC_PUSH2(&v, &t); // root arguments so the caller doesn't need to
    t = (language_value_t*)language_alloc_svec(nidxs);
    for (i = 0; i < nidxs; i++) {
        language_svecset(t, i, language_box_long(idxs[i]));
    }
    t = language_f_tuple(NULL, language_svec_data(t), nidxs);
    language_throw(language_new_struct((language_datatype_t*)language_boundserror_type, v, t));
}

LANGUAGE_DLLEXPORT void language_typeassert(language_value_t *x, language_value_t *t)
{
    if (!language_isa(x,t))
        language_type_error("typeassert", t, x);
}

#ifndef HAVE_SSP
LANGUAGE_DLLEXPORT uintptr_t __stack_chk_guard = (uintptr_t)0xBAD57ACCBAD67ACC; // 0xBADSTACKBADSTACK

LANGUAGE_DLLEXPORT void __stack_chk_fail(void)
{
    /* put your panic function or similar in here */
    fprintf(stderr, "fatal error: stack corruption detected\n");
    language_gc_debug_critical_error();
    abort(); // end with abort, since the compiler destroyed the stack upon entry to this function, there's no going back now
}
#endif

// exceptions -----------------------------------------------------------------

LANGUAGE_DLLEXPORT void language_enter_handler(language_task_t *ct, language_handler_t *eh)
{
    // Must have no safepoint
    eh->prev = ct->eh;
    eh->gcstack = ct->gcstack;
    eh->gc_state = language_atomic_load_relaxed(&ct->ptls->gc_state);
    eh->locks_len = ct->ptls->locks.len;
    eh->defer_signal = ct->ptls->defer_signal;
    eh->world_age = ct->world_age;
    ct->eh = eh;
#ifdef ENABLE_TIMINGS
    eh->timing_stack = ct->ptls->timing_stack;
#endif
}

// Restore thread local state to saved state in error handler `eh`.
// This is executed in two circumstances:
// * We leave a try block through normal control flow
// * An exception causes a nonlocal jump to the catch block. In this case
//   there's additional cleanup required, eg pushing the exception stack.
LANGUAGE_DLLEXPORT void language_eh_restore_state(language_task_t *ct, language_handler_t *eh)
{
#ifdef _OS_WINDOWS_
    if (ct->ptls->needs_resetstkoflw) {
        _resetstkoflw();
        ct->ptls->needs_resetstkoflw = 0;
    }
#endif
    // `eh` may be not equal to `ct->eh`. See `language_pop_handler`
    // This function should **NOT** have any safepoint before the ones at the
    // end.
    sig_atomic_t old_defer_signal = ct->ptls->defer_signal;
    ct->eh = eh->prev;
    ct->gcstack = eh->gcstack;
    small_arraylist_t *locks = &ct->ptls->locks;
    int unlocks = locks->len > eh->locks_len;
    if (unlocks) {
        for (size_t i = locks->len; i > eh->locks_len; i--)
            language_mutex_unlock_nogc((language_mutex_t*)locks->items[i - 1]);
        locks->len = eh->locks_len;
    }
    ct->world_age = eh->world_age;
    ct->ptls->defer_signal = eh->defer_signal;
    int8_t old_gc_state = language_atomic_load_relaxed(&ct->ptls->gc_state);
    if (old_gc_state != eh->gc_state)
        language_atomic_store_release(&ct->ptls->gc_state, eh->gc_state);
    if (!old_gc_state || !eh->gc_state) // it was or is unsafe now
        language_gc_safepoint_(ct->ptls);
    if (old_defer_signal && !eh->defer_signal)
        language_sigint_safepoint(ct->ptls);
    if (language_atomic_load_relaxed(&language_gc_have_pending_finalizers) &&
            unlocks && eh->locks_len == 0) {
        language_gc_run_pending_finalizers(ct);
    }
}

LANGUAGE_DLLEXPORT void language_eh_restore_state_noexcept(language_task_t *ct, language_handler_t *eh)
{
    assert(ct->gcstack == eh->gcstack && "Incorrect GC usage under try catch");
    ct->eh = eh->prev;
    ct->ptls->defer_signal = eh->defer_signal; // optional, but certain try-finally (in stream.jl) may be slightly harder to write without this
}

LANGUAGE_DLLEXPORT void language_pop_handler(language_task_t *ct, int n)
{
    if (__unlikely(n <= 0))
        return;
    language_handler_t *eh = ct->eh;
    while (--n > 0)
        eh = eh->prev;
    language_eh_restore_state(ct, eh);
}

LANGUAGE_DLLEXPORT void language_pop_handler_noexcept(language_task_t *ct, int n)
{
    if (__unlikely(n <= 0))
        return;
    language_handler_t *eh = ct->eh;
    while (--n > 0)
        eh = eh->prev;
    language_eh_restore_state_noexcept(ct, eh);
}

LANGUAGE_DLLEXPORT size_t language_excstack_state(language_task_t *ct) LANGUAGE_NOTSAFEPOINT
{
    language_excstack_t *s = ct->excstack;
    return s ? s->top : 0;
}

LANGUAGE_DLLEXPORT void language_restore_excstack(language_task_t *ct, size_t state) LANGUAGE_NOTSAFEPOINT
{
    language_excstack_t *s = ct->excstack;
    if (s) {
        assert(s->top >= state);
        s->top = state;
    }
}

static void language_copy_excstack(language_excstack_t *dest, language_excstack_t *src) LANGUAGE_NOTSAFEPOINT
{
    assert(dest->reserved_size >= src->top);
    memcpy(language_excstack_raw(dest), language_excstack_raw(src), sizeof(language_bt_element_t)*src->top);
    dest->top = src->top;
}

static void language_reserve_excstack(language_task_t *ct, language_excstack_t **stack LANGUAGE_REQUIRE_ROOTED_SLOT,
                                size_t reserved_size)
{
    language_excstack_t *s = *stack;
    if (s && s->reserved_size >= reserved_size)
        return;
    size_t bufsz = sizeof(language_excstack_t) + sizeof(uintptr_t)*reserved_size;
    language_excstack_t *new_s = (language_excstack_t*)language_gc_alloc_buf(ct->ptls, bufsz);
    new_s->top = 0;
    new_s->reserved_size = reserved_size;
    if (s)
        language_copy_excstack(new_s, s);
    *stack = new_s;
    language_gc_wb(ct, new_s);
}

void language_push_excstack(language_task_t *ct, language_excstack_t **stack LANGUAGE_REQUIRE_ROOTED_SLOT LANGUAGE_ROOTING_ARGUMENT,
                      language_value_t *exception LANGUAGE_ROOTED_ARGUMENT,
                      language_bt_element_t *bt_data, size_t bt_size)
{
    language_reserve_excstack(ct, stack, (*stack ? (*stack)->top : 0) + bt_size + 2);
    language_excstack_t *s = *stack;
    language_bt_element_t *rawstack = language_excstack_raw(s);
    memcpy(rawstack + s->top, bt_data, sizeof(language_bt_element_t)*bt_size);
    s->top += bt_size + 2;
    rawstack[s->top-2].uintptr = bt_size;
    rawstack[s->top-1].jlvalue = exception;
}

// conversion -----------------------------------------------------------------

LANGUAGE_DLLEXPORT void *(language_symbol_name)(language_sym_t *s)
{
    return language_symbol_name(s);
}

// WARNING: THIS FUNCTION IS NEVER CALLED BUT INLINE BY CCALL
LANGUAGE_DLLEXPORT void *language_array_ptr(language_array_t *a)
{
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(a->ref.mem))->layout;
    if (layout->flags.arrayelem_isunion || layout->size == 0)
        return (char*)a->ref.mem->ptr + (size_t)language_array_data_(a);
    return language_array_data_(a);
}
LANGUAGE_DLLEXPORT language_value_t *language_value_ptr(language_value_t *a)
{
    return a;
}

// optimization of setfield which bypasses boxing of the idx (and checking field type validity)
LANGUAGE_DLLEXPORT void language_set_nth_field(language_value_t *v, size_t idx0, language_value_t *rhs)
{
    language_datatype_t *st = (language_datatype_t*)language_typeof(v);
    if (!st->name->mutabl)
        language_errorf("setfield!: immutable struct of type %s cannot be changed", language_symbol_name(st->name->name));
    if (idx0 >= language_datatype_nfields(st))
        language_bounds_error_int(v, idx0 + 1);
    //language_value_t *ft = language_field_type(st, idx0);
    //if (!language_isa(rhs, ft)) {
    //    language_type_error("setfield!", ft, rhs);
    //}
    //int isatomic = language_field_isatomic(st, idx0);
    //if (isatomic) ...
    set_nth_field(st, v, idx0, rhs, 0);
}


// parsing --------------------------------------------------------------------

static int substr_isspace(char *p, char *pend)
{
    while (p != pend) {
        if (!isspace((unsigned char)*p)) {
            return 0;
        }
        p++;
    }
    return 1;
}

LANGUAGE_DLLEXPORT language_nullable_float64_t language_try_substrtod(char *str, size_t offset, size_t len)
{
    char *p;
    char *bstr = str+offset;
    char *pend = bstr+len;
    char *tofree = NULL;
    int hasvalue = 0;

    errno = 0;
    if (!(*pend == '\0' || isspace((unsigned char)*pend) || *pend == ',')) {
        // confusing data outside substring. must copy.
        char *newstr;
        if (len + 1 < language_page_size) {
            newstr = (char*)alloca(len + 1);
        }
        else {
            newstr = tofree = (char*)malloc_s(len + 1);
        }
        memcpy(newstr, bstr, len);
        newstr[len] = 0;
        bstr = newstr;
        pend = bstr+len;
    }
    double out = language_strtod_c(bstr, &p);

    if (errno==ERANGE && (out==0 || out==HUGE_VAL || out==-HUGE_VAL)) {
        hasvalue = 0;
    }
    else if (p == bstr) {
        hasvalue = 0;
    }
    else {
        // Deal with case where the substring might be something like "1 ",
        // which is OK, and "1 X", which we don't allow.
        hasvalue = substr_isspace(p, pend) ? 1 : 0;
    }

    if (__unlikely(tofree))
        free(tofree);

    language_nullable_float64_t ret = {(uint8_t)hasvalue, out};
    return ret;
}

LANGUAGE_DLLEXPORT int language_substrtod(char *str, size_t offset, size_t len, double *out)
{
    language_nullable_float64_t nd = language_try_substrtod(str, offset, len);
    if (0 != nd.hasvalue) {
        *out = nd.value;
        return 0;
    }
    return 1;
}

// MSVC pre-2013 did not define HUGE_VALF
#ifndef HUGE_VALF
#define HUGE_VALF (1e25f * 1e25f)
#endif

LANGUAGE_DLLEXPORT language_nullable_float32_t language_try_substrtof(char *str, size_t offset, size_t len)
{
    char *p;
    char *bstr = str+offset;
    char *pend = bstr+len;
    char *tofree = NULL;
    int hasvalue = 0;

    errno = 0;
    if (!(*pend == '\0' || isspace((unsigned char)*pend) || *pend == ',')) {
        // confusing data outside substring. must copy.
        char *newstr;
        if (len + 1 < language_page_size) {
            newstr = (char*)alloca(len + 1);
        }
        else {
            newstr = tofree = (char*)malloc_s(len + 1);
        }
        memcpy(newstr, bstr, len);
        newstr[len] = 0;
        bstr = newstr;
        pend = bstr+len;
    }
#if defined(_OS_WINDOWS_) && !defined(_COMPILER_GCC_)
    float out = (float)language_strtod_c(bstr, &p);
#else
    float out = language_strtof_c(bstr, &p);
#endif

    if (errno==ERANGE && (out==0 || out==HUGE_VALF || out==-HUGE_VALF)) {
        hasvalue = 0;
    }
    else if (p == bstr) {
        hasvalue = 0;
    }
    else {
        // Deal with case where the substring might be something like "1 ",
        // which is OK, and "1 X", which we don't allow.
        hasvalue = substr_isspace(p, pend) ? 1 : 0;
    }

    if (__unlikely(tofree))
        free(tofree);

    language_nullable_float32_t ret = {(uint8_t)hasvalue, out};
    return ret;
}

LANGUAGE_DLLEXPORT int language_substrtof(char *str, int offset, size_t len, float *out)
{
    language_nullable_float32_t nf = language_try_substrtof(str, offset, len);
    if (0 != nf.hasvalue) {
        *out = nf.value;
        return 0;
    }
    return 1;
}

// showing --------------------------------------------------------------------

LANGUAGE_DLLEXPORT void language_flush_cstdio(void) LANGUAGE_NOTSAFEPOINT
{
    fflush(stdout);
    fflush(stderr);
}

LANGUAGE_DLLEXPORT language_value_t *language_stderr_obj(void) LANGUAGE_NOTSAFEPOINT
{
    if (language_base_module == NULL)
        return NULL;
    language_binding_t *stderr_obj = language_get_module_binding(language_base_module, language_symbol("stderr"), 0);
    return stderr_obj ? language_atomic_load_relaxed(&stderr_obj->value) : NULL;
}

// toys for debugging ---------------------------------------------------------

struct recur_list {
    struct recur_list *prev;
    language_value_t *v;
};

static size_t language_static_show_x(LANGUAGE_STREAM *out, language_value_t *v, struct recur_list *depth, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT;
static size_t language_static_show_x_(LANGUAGE_STREAM *out, language_value_t *v, language_datatype_t *vt, struct recur_list *depth, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT;
static size_t language_static_show_next_(LANGUAGE_STREAM *out, language_value_t *v, language_value_t *prev, struct recur_list *depth, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT;

static size_t language_show_svec(LANGUAGE_STREAM *out, language_svec_t *t, const char *head, const char *opn, const char *cls, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT
{
    size_t i, n=0, len = language_svec_len(t);
    n += language_printf(out, "%s", head);
    n += language_printf(out, "%s", opn);
    for (i = 0; i < len; i++) {
        language_value_t *v = language_svecref(t,i);
        n += language_static_show_x(out, v, 0, ctx);
        if (i != len-1)
            n += language_printf(out, ", ");
    }
    n += language_printf(out, "%s", cls);
    return n;
}

LANGUAGE_DLLEXPORT int language_id_start_char(uint32_t wc) LANGUAGE_NOTSAFEPOINT;
LANGUAGE_DLLEXPORT int language_id_char(uint32_t wc) LANGUAGE_NOTSAFEPOINT;

LANGUAGE_DLLEXPORT int language_is_identifier(const char *str) LANGUAGE_NOTSAFEPOINT
{
    size_t i = 0;
    uint32_t wc = u8_nextchar(str, &i);
    if (!language_id_start_char(wc))
        return 0;
    while ((wc = u8_nextchar(str, &i)) != 0) {
        if (!language_id_char(wc))
            return 0;
    }
    return 1;
}

static language_datatype_t *nth_arg_datatype(language_value_t *a LANGUAGE_PROPAGATES_ROOT, int n) LANGUAGE_NOTSAFEPOINT
{
    if (language_is_datatype(a)) {
        if (n == 0)
            return (language_datatype_t*)a;
        if (language_is_tuple_type(a)) {
            if (language_nparams(a) < n)
                return NULL;
            return nth_arg_datatype(language_tparam(a, n - 1), 0);
        }
        return NULL;
    }
    else if (language_is_typevar(a)) {
        return nth_arg_datatype(((language_tvar_t*)a)->ub, n);
    }
    else if (language_is_unionall(a)) {
        return nth_arg_datatype(((language_unionall_t*)a)->body, n);
    }
    else if (language_is_uniontype(a)) {
        language_uniontype_t *u = (language_uniontype_t*)a;
        language_datatype_t *d1 = nth_arg_datatype(u->a, n);
        if (d1 == NULL) return NULL;
        language_datatype_t *d2 = nth_arg_datatype(u->b, n);
        if (d2 == NULL || d1->name != d2->name)
            return NULL;
        return d1;
    }
    return NULL;
}

// get DataType of first tuple element (if present), or NULL if cannot be determined
language_datatype_t *language_nth_argument_datatype(language_value_t *argtypes LANGUAGE_PROPAGATES_ROOT, int n) LANGUAGE_NOTSAFEPOINT
{
    return nth_arg_datatype(argtypes, n);
}

// get DataType implied by a single given type, or `nothing`
LANGUAGE_DLLEXPORT language_value_t *language_argument_datatype(language_value_t *argt LANGUAGE_PROPAGATES_ROOT) LANGUAGE_NOTSAFEPOINT
{
    language_datatype_t *dt = nth_arg_datatype(argt, 0);
    if (dt == NULL)
        return language_nothing;
    return (language_value_t*)dt;
}

static int is_globname_binding(language_value_t *v, language_datatype_t *dv) LANGUAGE_NOTSAFEPOINT
{
    language_sym_t *globname = dv->name->mt != NULL ? dv->name->mt->name : NULL;
    if (globname && dv->name->module) {
        language_binding_t *b = language_get_module_binding(dv->name->module, globname, 0);
        if (b && language_atomic_load_relaxed(&b->owner) && b->constp) {
            language_value_t *bv = language_atomic_load_relaxed(&b->value);
            // The `||` makes this function work for both function instances and function types.
            if (bv == v || language_typeof(bv) == v)
                return 1;
        }
    }
    return 0;
}

static int is_globfunction(language_value_t *v, language_datatype_t *dv, language_sym_t **globname_out) LANGUAGE_NOTSAFEPOINT
{
    language_sym_t *globname = dv->name->mt != NULL ? dv->name->mt->name : NULL;
    *globname_out = globname;
    if (globname && !strchr(language_symbol_name(globname), '#') && !strchr(language_symbol_name(globname), '@')) {
        return 1;
    }
    return 0;
}

static size_t language_static_show_string(LANGUAGE_STREAM *out, const char *str, size_t len, int wrap) LANGUAGE_NOTSAFEPOINT
{
    size_t n = 0;
    if (wrap)
        n += language_printf(out, "\"");
    if (!u8_isvalid(str, len)) {
        // alternate print algorithm that preserves data if it's not UTF-8
        static const char hexdig[] = "0123456789abcdef";
        for (size_t i = 0; i < len; i++) {
            uint8_t c = str[i];
            if (c == '\\' || c == '"' || c == '$')
                n += language_printf(out, "\\%c", c);
            else if (c >= 32 && c < 0x7f)
                n += language_printf(out, "%c", c);
            else
                n += language_printf(out, "\\x%c%c", hexdig[c>>4], hexdig[c&0xf]);
        }
    }
    else {
        int special = 0;
        for (size_t i = 0; i < len; i++) {
            uint8_t c = str[i];
            if (c < 32 || c == 0x7f || c == '\\' || c == '"' || c == '$') {
                special = 1;
                break;
            }
        }
        if (!special) {
            language_uv_puts(out, str, len);
            n += len;
        }
        else {
            char buf[512];
            size_t i = 0;
            while (i < len) {
                size_t r = u8_escape(buf, sizeof(buf), str, &i, len, "\"$", 0);
                language_uv_puts(out, buf, r - 1);
                n += r - 1;
            }
        }
    }
    if (wrap)
        n += language_printf(out, "\"");
    return n;
}

static size_t language_static_show_symbol(LANGUAGE_STREAM *out, language_sym_t *name) LANGUAGE_NOTSAFEPOINT
{
    size_t n = 0;
    const char *sn = language_symbol_name(name);
    int quoted = !language_is_identifier(sn) && !language_is_operator(sn);
    if (quoted) {
        n += language_printf(out, "var");
        // TODO: this is not quite right, since repr uses String escaping rules, and Symbol uses raw string rules
        n += language_static_show_string(out, sn, strlen(sn), 1);
    }
    else {
        n += language_printf(out, "%s", sn);
    }
    return n;
}

// `language_static_show()` cannot call `language_subtype()`, for the GC reasons
// explained in the comment on `language_static_show_x_()`, below.
// This function checks if `vt <: Function` without triggering GC.
static int language_static_is_function_(language_datatype_t *vt) LANGUAGE_NOTSAFEPOINT {
    if (!language_function_type) {  // Make sure there's a Function type defined.
        return 0;
    }
    int _iter_count = 0;  // To prevent infinite loops from corrupt type objects.
    while (vt != language_any_type) {
        if (vt == NULL) {
            return 0;
        } else if (_iter_count > 10000) {
            // We are very likely stuck in a cyclic datastructure, so we assume this is
            // _not_ a Function.
            return 0;
        } else if (vt == language_function_type) {
            return 1;
        }
        vt = vt->super;
        _iter_count += 1;
    }
    return 0;
}

// `v` might be pointing to a field inlined in a structure therefore
// `language_typeof(v)` may not be the same with `vt` and only `vt` should be
// used to determine the type of the value.
// This is necessary to make sure that this function doesn't allocate any
// memory through the Julia GC
static size_t language_static_show_x_(LANGUAGE_STREAM *out, language_value_t *v, language_datatype_t *vt,
                                struct recur_list *depth, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT
{
    size_t n = 0;
    if ((uintptr_t)vt < 4096U) {
        n += language_printf(out, "<?#%p::%p>", (void*)v, (void*)vt);
    }
    else if ((uintptr_t)v < 4096U) {
        n += language_printf(out, "<?#%p::", (void*)v);
        n += language_static_show_x(out, (language_value_t*)vt, depth, ctx);
        n += language_printf(out, ">");
    }
    else if (vt == (language_datatype_t*)language_buff_tag) {
        n += language_printf(out, "<?#%p::language_buff_tag marked memory>", (void*)v);
    }
    else if (vt == (language_datatype_t*)(uintptr_t)(0xbabababababababaull & ~15)) {
        n += language_printf(out, "<?#%p::baaaaaad>", (void*)v);
    }
    // These need to be special cased because they
    // exist only by pointer identity in early startup
    else if (v == (language_value_t*)language_simplevector_type) {
        n += language_printf(out, "Core.SimpleVector");
    }
    else if (v == (language_value_t*)language_typename_type) {
        n += language_printf(out, "Core.TypeName");
    }
    else if (v == (language_value_t*)language_symbol_type) {
        n += language_printf(out, "Symbol");
    }
    else if (v == (language_value_t*)language_methtable_type) {
        n += language_printf(out, "Core.MethodTable");
    }
    else if (v == (language_value_t*)language_any_type) {
        n += language_printf(out, "Any");
    }
    else if (v == (language_value_t*)language_type_type) {
        n += language_printf(out, "Type");
    }
    else if (vt == language_method_type) {
        language_method_t *m = (language_method_t*)v;
        n += language_static_show_func_sig(out, m->sig);
    }
    else if (vt == language_method_instance_type) {
        language_method_instance_t *li = (language_method_instance_t*)v;
        if (language_is_method(li->def.method)) {
            n += language_static_show_func_sig(out, li->specTypes);
            n += language_printf(out, " from ");
            n += language_static_show_func_sig(out, li->def.method->sig);
        }
        else {
            n += language_static_show_x(out, (language_value_t*)li->def.module, depth, ctx);
            n += language_printf(out, ".<toplevel thunk> -> ");
            n += language_static_show_x(out, language_atomic_load_relaxed(&language_cached_uninferred(
                language_atomic_load_relaxed(&li->cache), 1)->inferred), depth, ctx);
        }
    }
    else if (vt == language_typename_type) {
        n += language_static_show_x(out, language_unwrap_unionall(((language_typename_t*)v)->wrapper), depth, ctx);
        n += language_printf(out, ".name");
    }
    else if (vt == language_simplevector_type) {
        n += language_show_svec(out, (language_svec_t*)v, "svec", "(", ")", ctx);
    }
    else if (v == (language_value_t*)language_unionall_type) {
        // avoid printing `typeof(Type)` for `UnionAll`.
        n += language_printf(out, "UnionAll");
    }
    else if (vt == language_vararg_type) {
        language_vararg_t *vm = (language_vararg_t*)v;
        n += language_printf(out, "Vararg");
        if (vm->T) {
            n += language_printf(out, "{");
            n += language_static_show_x(out, vm->T, depth, ctx);
            if (vm->N) {
                n += language_printf(out, ", ");
                n += language_static_show_x(out, vm->N, depth, ctx);
            }
            n += language_printf(out, "}");
        }
    }
    else if (vt == language_datatype_type) {
        // typeof(v) == DataType, so v is a Type object.
        // Types are printed as a fully qualified name, with parameters, e.g.
        // `Base.Set{Int}`, and function types are printed as e.g. `typeof(Main.f)`
        language_datatype_t *dv = (language_datatype_t*)v;
        if (dv->name == language_tuple_typename) {
            if (dv == language_tuple_type)
                return language_printf(out, "Tuple");
            int taillen = 1, tlen = language_nparams(dv), i;
            for (i = tlen-2; i >= 0; i--) {
                if (language_tparam(dv, i) == language_tparam(dv, tlen-1))
                    taillen++;
                else
                    break;
            }
            if (taillen == tlen && taillen > 3) {
                n += language_printf(out, "NTuple{%d, ", tlen);
                n += language_static_show_x(out, language_tparam0(dv), depth, ctx);
                n += language_printf(out, "}");
            }
            else {
                n += language_printf(out, "Tuple{");
                for (i = 0; i < (taillen > 3 ? tlen-taillen : tlen); i++) {
                    if (i > 0)
                        n += language_printf(out, ", ");
                    n += language_static_show_x(out, language_tparam(dv, i), depth, ctx);
                }
                if (taillen > 3) {
                    n += language_printf(out, ", Vararg{");
                    n += language_static_show_x(out, language_tparam(dv, tlen-1), depth, ctx);
                    n += language_printf(out, ", %d}", taillen);
                }
                n += language_printf(out, "}");
            }
            return n;
        }
        if (language_genericmemory_type && dv->name == language_genericmemory_typename) {
            language_value_t *isatomic = language_tparam0(dv);
            language_value_t *el_type = language_tparam1(dv);
            language_value_t *addrspace = language_tparam2(dv);
            if (isatomic == (language_value_t*)language_not_atomic_sym && addrspace && language_is_addrspacecore(addrspace) && language_unbox_uint8(addrspace) == 0) {
                n += language_printf(out, "Memory{");
                n += language_static_show_x(out, el_type, depth, ctx);
                n += language_printf(out, "}");
                return n;
            }
        }
        if (ctx.quiet) {
            return language_static_show_symbol(out, dv->name->name);
        }
        language_sym_t *globname;
        int globfunc = is_globname_binding(v, dv) && is_globfunction(v, dv, &globname);
        language_sym_t *sym = globfunc ? globname : dv->name->name;
        char *sn = language_symbol_name(sym);
        size_t quote = 0;
        if (globfunc) {
            n += language_printf(out, "typeof(");
        }
        if (language_core_module && (dv->name->module != language_core_module || !language_module_exports_p(language_core_module, sym))) {
            n += language_static_show_x(out, (language_value_t*)dv->name->module, depth, ctx);
            n += language_printf(out, ".");
            size_t i = 0;
            if (globfunc && !language_id_start_char(u8_nextchar(sn, &i))) {
                n += language_printf(out, ":(");
                quote = 1;
            }
        }
        n += language_static_show_symbol(out, sym);
        if (globfunc) {
            n += language_printf(out, ")");
            if (quote) {
                n += language_printf(out, ")");
            }
        }
        if (dv->parameters && (language_value_t*)dv != dv->name->wrapper) {
            size_t j, tlen = language_nparams(dv);
            if (tlen > 0) {
                n += language_printf(out, "{");
                for (j = 0; j < tlen; j++) {
                    language_value_t *p = language_tparam(dv,j);
                    n += language_static_show_x(out, p, depth, ctx);
                    if (j != tlen-1)
                        n += language_printf(out, ", ");
                }
                n += language_printf(out, "}");
            }
        }
    }
    else if (vt == language_intrinsic_type) {
        int f = *(uint32_t*)language_data_ptr(v);
        n += language_printf(out, "#<intrinsic #%d %s>", f, language_intrinsic_name(f));
    }
    else if (vt == language_int64_type) {
        n += language_printf(out, "%" PRId64, *(int64_t*)v);
    }
    else if (vt == language_int32_type) {
        n += language_printf(out, "%" PRId32, *(int32_t*)v);
    }
    else if (vt == language_int16_type) {
        n += language_printf(out, "%" PRId16, *(int16_t*)v);
    }
    else if (vt == language_int8_type) {
        n += language_printf(out, "%" PRId8, *(int8_t*)v);
    }
    else if (vt == language_uint64_type) {
        n += language_printf(out, "0x%016" PRIx64, *(uint64_t*)v);
    }
    else if (vt == language_uint32_type) {
        n += language_printf(out, "0x%08" PRIx32, *(uint32_t*)v);
    }
    else if (vt == language_uint16_type) {
        n += language_printf(out, "0x%04" PRIx16, *(uint16_t*)v);
    }
    else if (vt == language_uint8_type) {
        n += language_printf(out, "0x%02" PRIx8, *(uint8_t*)v);
    }
    else if (language_pointer_type && language_is_cpointer_type((language_value_t*)vt)) {
#ifdef _P64
        n += language_printf(out, "0x%016" PRIx64, *(uint64_t*)v);
#else
        n += language_printf(out, "0x%08" PRIx32, *(uint32_t*)v);
#endif
    }
    else if (vt == language_float32_type) {
        n += language_printf(out, "%gf", *(float*)v);
    }
    else if (vt == language_float64_type) {
        n += language_printf(out, "%g", *(double*)v);
    }
    else if (vt == language_bool_type) {
        n += language_printf(out, "%s", *(uint8_t*)v ? "true" : "false");
    }
    else if (v == language_nothing || (language_nothing && (language_value_t*)vt == language_typeof(language_nothing))) {
        n += language_printf(out, "nothing");
    }
    else if (vt == language_string_type) {
        n += language_static_show_string(out, language_string_data(v), language_string_len(v), 1);
    }
    else if (v == language_bottom_type) {
        n += language_printf(out, "Union{}");
    }
    else if (vt == language_uniontype_type) {
        n += language_printf(out, "Union{");
        while (language_is_uniontype(v)) {
            // tail-recurse on b to flatten the printing of the Union structure in the common case
            n += language_static_show_x(out, ((language_uniontype_t*)v)->a, depth, ctx);
            n += language_printf(out, ", ");
            v = ((language_uniontype_t*)v)->b;
        }
        n += language_static_show_x(out, v, depth, ctx);
        n += language_printf(out, "}");
    }
    else if (vt == language_unionall_type) {
        language_unionall_t *ua = (language_unionall_t*)v;
        n += language_static_show_x(out, ua->body, depth, ctx);
        n += language_printf(out, " where ");
        n += language_static_show_x(out, (language_value_t*)ua->var, depth->prev, ctx);
    }
    else if (vt == language_typename_type) {
        n += language_printf(out, "typename(");
        n += language_static_show_x(out, language_unwrap_unionall(((language_typename_t*)v)->wrapper), depth, ctx);
        n += language_printf(out, ")");
    }
    else if (vt == language_tvar_type) {
        // show type-var bounds only if they aren't going to be printed by UnionAll later
        language_tvar_t *var = (language_tvar_t*)v;
        struct recur_list *p;
        int showbounds = 1;
        for (p = depth; p != NULL; p = p->prev) {
            if (language_is_unionall(p->v) && ((language_unionall_t*)p->v)->var == var) {
                showbounds = 0;
                break;
            }
        }
        language_value_t *lb = var->lb, *ub = var->ub;
        if (showbounds && lb != language_bottom_type) {
            // show type-var lower bound if it is defined
            int ua = language_is_unionall(lb);
            if (ua)
                n += language_printf(out, "(");
            n += language_static_show_x(out, lb, depth, ctx);
            if (ua)
                n += language_printf(out, ")");
            n += language_printf(out, "<:");
        }
        n += language_static_show_symbol(out, var->name);
        if (showbounds && (ub != (language_value_t*)language_any_type || lb != language_bottom_type)) {
            // show type-var upper bound if it is defined, or if we showed the lower bound
            int ua = language_is_unionall(ub);
            n += language_printf(out, "<:");
            if (ua)
                n += language_printf(out, "(");
            n += language_static_show_x(out, ub, depth, ctx);
            if (ua)
                n += language_printf(out, ")");
        }
    }
    else if (vt == language_module_type) {
        language_module_t *m = (language_module_t*)v;
        if (m->parent != m && m->parent != language_main_module) {
            n += language_static_show_x(out, (language_value_t*)m->parent, depth, ctx);
            n += language_printf(out, ".");
        }
        n += language_static_show_symbol(out, m->name);
    }
    else if (vt == language_symbol_type) {
        n += language_printf(out, ":");
        n += language_static_show_symbol(out, (language_sym_t*)v);
    }
    else if (vt == language_ssavalue_type) {
        n += language_printf(out, "SSAValue(%" PRIuPTR ")",
                       (uintptr_t)((language_ssavalue_t*)v)->id);
    }
    else if (vt == language_globalref_type) {
        n += language_static_show_x(out, (language_value_t*)language_globalref_mod(v), depth, ctx);
        language_sym_t *name = language_globalref_name(v);
        n += language_printf(out, ".");
        if (language_is_operator(language_symbol_name(name)))
            n += language_printf(out, ":(%s)", language_symbol_name(name));
        else
            n += language_static_show_symbol(out, name);
    }
    else if (vt == language_gotonode_type) {
        n += language_printf(out, "goto %" PRIuPTR, language_gotonode_label(v));
    }
    else if (vt == language_quotenode_type) {
        language_value_t *qv = *(language_value_t**)v;
        if (!language_is_symbol(qv)) {
            n += language_printf(out, "quote ");
        }
        else {
            n += language_printf(out, ":(");
        }
        n += language_static_show_x(out, qv, depth, ctx);
        if (!language_is_symbol(qv)) {
            n += language_printf(out, " end");
        }
        else {
            n += language_printf(out, ")");
        }
    }
    else if (vt == language_newvarnode_type) {
        n += language_printf(out, "<newvar ");
        n += language_static_show_x(out, *(language_value_t**)v, depth, ctx);
        n += language_printf(out, ">");
    }
    else if (vt == language_linenumbernode_type) {
        n += language_printf(out, "#= ");
        n += language_static_show_x(out, language_linenode_file(v), depth, ctx);
        n += language_printf(out, ":%" PRIuPTR " =#", language_linenode_line(v));
    }
    else if (vt == language_expr_type) {
        language_expr_t *e = (language_expr_t*)v;
        if (e->head == language_assign_sym && language_array_nrows(e->args) == 2) {
            n += language_static_show_x(out, language_exprarg(e, 0), depth, ctx);
            n += language_printf(out, " = ");
            n += language_static_show_x(out, language_exprarg(e, 1), depth, ctx);
        }
        else {
            n += language_printf(out, "Expr(");
            n += language_static_show_x(out, (language_value_t*)e->head, depth, ctx);
            size_t i, len = language_array_nrows(e->args);
            for (i = 0; i < len; i++) {
                n += language_printf(out, ", ");
                n += language_static_show_x(out, language_exprarg(e, i), depth, ctx);
            }
            n += language_printf(out, ")");
        }
    }
    else if (language_array_type && language_is_array_type(vt)) {
        n += language_printf(out, "Array{");
        language_value_t *el_type = language_tparam0(vt);
        n += language_static_show_x(out, el_type, depth, ctx);
        language_array_t *av = (language_array_t*)v;
        size_t i, ndims = language_array_ndims(v);
        n += language_printf(out, ", %" PRIdPTR "}(dims=(", ndims);
        if (ndims == 1)
            n += language_printf(out, "%" PRIdPTR ",", language_array_dim0(v));
        else
            for (i = 0; i < ndims; i++)
                n += language_printf(out, (i > 0 ? ", %" PRIdPTR : "%" PRIdPTR), language_array_dim(v, i));
        n += language_printf(out, "), mem=");
        n += language_static_show_x(out, (language_value_t*)av->ref.mem, depth, ctx);
        n += language_printf(out, ")");
    }
    else if (language_genericmemoryref_type && language_is_genericmemoryref_type(vt)) {
        language_genericmemoryref_t *ref = (language_genericmemoryref_t*)v;
        n += language_printf(out, "GenericMemoryRef(offset=");
        size_t offset = (size_t)ref->ptr_or_offset;
        if (ref->mem) {
            const language_datatype_layout_t *layout = ((language_datatype_t*)language_typeof(ref->mem))->layout;
            if (layout->size != 0 && !layout->flags.arrayelem_isunion)
                offset = ((char*)offset - (char*)ref->mem->ptr) / layout->size;
        }
        n += language_printf(out, "%" PRIdPTR, offset);
        n += language_printf(out, ", ptr_or_offset=%p, mem=", ref->ptr_or_offset);
        n += language_static_show_x(out, (language_value_t*)ref->mem, depth, ctx);
    }
    else if (language_genericmemory_type && language_is_genericmemory_type(vt)) {
        language_genericmemory_t *m = (language_genericmemory_t*)v;
        //language_value_t *isatomic = language_tparam0(vt);
        language_value_t *el_type = language_tparam1(vt);
        language_value_t *addrspace = language_tparam2(vt);
        n += language_static_show_x(out, (language_value_t*)vt, depth, ctx);
        size_t j, tlen = m->length;
        n += language_printf(out, "(%" PRIdPTR ", %p)[", tlen, m->ptr);
        if (!(addrspace && language_is_addrspacecore(addrspace) && language_unbox_uint8(addrspace) == 0)) {
            n += language_printf(out, "...]");
            return n;
        }
        const char *typetagdata = NULL;
        const language_datatype_layout_t *layout = vt->layout;
        int nlsep = 0;
        if (layout->flags.arrayelem_isboxed) {
            // print arrays with newlines, unless the elements are probably small
            for (j = 0; j < tlen; j++) {
                language_value_t **ptr = ((language_value_t**)m->ptr) + j;
                language_value_t *p = *ptr;
                if (p != NULL && (uintptr_t)p >= 4096U) {
                    language_value_t *p_ty = language_typeof(p);
                    if ((uintptr_t)p_ty >= 4096U) {
                        if (!language_isbits(p_ty)) {
                            nlsep = 1;
                            break;
                        }
                    }
                }
            }
        }
        else if (layout->flags.arrayelem_isunion) {
            typetagdata = language_genericmemory_typetagdata(m);
        }
        if (layout->size == 0 && tlen >= 3) {
            n += language_static_show_x_(out, (language_value_t*)m->ptr, (language_datatype_t*)el_type, depth, ctx);
            n += language_printf(out, ", ...");
        }
        else {
            if (nlsep && tlen > 1)
                n += language_printf(out, "\n  ");
            for (size_t j = 0; j < tlen; j++) {
                if (layout->flags.arrayelem_isboxed) {
                    language_value_t **ptr = ((language_value_t**)m->ptr) + j;
                    n += language_static_show_x(out, *ptr, depth, ctx);
                }
                else {
                    char *ptr = ((char*)m->ptr) + j * layout->size;
                    n += language_static_show_x_(out, (language_value_t*)ptr,
                            (language_datatype_t*)(typetagdata ? language_nth_union_component(el_type, typetagdata[j]) : el_type),
                            depth, ctx);
                }
                if (j != tlen - 1)
                    n += language_printf(out, nlsep ? ",\n  " : ", ");
            }
        }
        n += language_printf(out, "]");
    }
    else if (vt == language_loaderror_type) {
        n += language_printf(out, "LoadError(at ");
        n += language_static_show_x(out, *(language_value_t**)v, depth, ctx);
        // Access the field directly to avoid allocation
        n += language_printf(out, " line %" PRIdPTR, ((intptr_t*)v)[1]);
        n += language_printf(out, ": ");
        n += language_static_show_x(out, ((language_value_t**)v)[2], depth, ctx);
        n += language_printf(out, ")");
    }
    else if (vt == language_errorexception_type) {
        n += language_printf(out, "ErrorException(");
        n += language_static_show_x(out, *(language_value_t**)v, depth, ctx);
        n += language_printf(out, ")");
    }
    else if (language_static_is_function_(vt) && is_globname_binding(v, (language_datatype_t*)vt)) {
        // v is function instance (an instance of a Function type).
        language_datatype_t *dv = (language_datatype_t*)vt;
        language_sym_t *sym;
        int globfunc = is_globfunction(v, dv, &sym);
        int quote = 0;
        if (language_core_module && (dv->name->module != language_core_module || !language_module_exports_p(language_core_module, sym))) {
            n += language_static_show_x(out, (language_value_t*)dv->name->module, depth, ctx);
            n += language_printf(out, ".");

            size_t i = 0;
            char *sn = language_symbol_name(sym);
            if (globfunc && !language_id_start_char(u8_nextchar(sn, &i))) {
                n += language_printf(out, ":(");
                quote = 1;
            }
        }

        n += language_static_show_symbol(out, sym);

        if (globfunc) {
            if (quote) {
                n += language_printf(out, ")");
            }
        }
    }
    else if (language_datatype_type && language_is_datatype(vt)) {
        // typeof(v) isa DataType, so v is an *instance of* a type that is a Datatype,
        // meaning v is e.g. an instance of a struct. These are printed as a call to a
        // type constructor, such as e.g. `Base.UnitRange{Int64}(start=1, stop=2)`
        int istuple = language_is_tuple_type(vt), isnamedtuple = language_is_namedtuple_type(vt);
        size_t tlen = language_datatype_nfields(vt);
        if (isnamedtuple) {
            if (tlen == 0)
                n += language_printf(out, "NamedTuple");
        }
        else if (!istuple) {
            n += language_static_show_x(out, (language_value_t*)vt, depth, ctx);
        }
        n += language_printf(out, "(");
        size_t nb = language_datatype_size(vt);
        if (nb > 0 && tlen == 0) {
            uint8_t *data = (uint8_t*)v;
            n += language_printf(out, "0x");
            for(int i = nb - 1; i >= 0; --i)
                n += language_printf(out, "%02" PRIx8, data[i]);
        }
        else {
            size_t i = 0;
            if (vt == language_typemap_entry_type)
                i = 1;
            language_value_t *names = isnamedtuple ? language_tparam0(vt) : (language_value_t*)language_field_names(vt);
            for (; i < tlen; i++) {
                if (!istuple) {
                    language_sym_t *fname = (language_sym_t*)(isnamedtuple ? language_fieldref_noalloc(names, i) : language_svecref(names, i));
                    if (fname == NULL || !language_is_symbol(fname))
                        n += language_static_show_x(out, (language_value_t*)fname, depth, ctx);
                    else if (language_is_operator(language_symbol_name(fname)))
                        n += language_printf(out, "(%s)", language_symbol_name(fname));
                    else
                        n += language_static_show_symbol(out, fname);
                    n += language_printf(out, "=");
                }
                size_t offs = language_field_offset(vt, i);
                char *fld_ptr = (char*)v + offs;
                if (language_field_isptr(vt, i)) {
                    n += language_static_show_x(out, *(language_value_t**)fld_ptr, depth, ctx);
                }
                else {
                    language_datatype_t *ft = (language_datatype_t*)language_field_type_concrete(vt, i);
                    if (language_is_uniontype(ft)) {
                        uint8_t sel = ((uint8_t*)fld_ptr)[language_field_size(vt, i) - 1];
                        ft = (language_datatype_t*)language_nth_union_component((language_value_t*)ft, sel);
                    }
                    n += language_static_show_x_(out, (language_value_t*)fld_ptr, ft, depth, ctx);
                }
                if ((istuple || isnamedtuple) && tlen == 1)
                    n += language_printf(out, ",");
                else if (i != tlen - 1)
                    n += language_printf(out, ", ");
            }
            if (vt == language_typemap_entry_type) {
                n += language_printf(out, ", next=↩︎\n  ");
                language_value_t *next = (language_value_t*)language_atomic_load_relaxed(&((language_typemap_entry_t*)v)->next);
                n += language_static_show_next_(out, next, v, depth, ctx);
            }
        }
        n += language_printf(out, ")");
    }
    else {
        n += language_printf(out, "<?#%p::", (void*)v);
        n += language_static_show_x(out, (language_value_t*)vt, depth, ctx);
        n += language_printf(out, ">");
    }
    return n;
}

static size_t language_static_show_x(LANGUAGE_STREAM *out, language_value_t *v, struct recur_list *depth, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT
{
    // show values without calling a julia method or allocating through the GC
    return language_static_show_next_(out, v, NULL, depth, ctx);
}

static size_t language_static_show_next_(LANGUAGE_STREAM *out, language_value_t *v, language_value_t *prev, struct recur_list *depth, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT
{
    // helper for showing a typemap list by following the next pointers
    // while being careful about avoiding any recursion due to malformed (circular) references
    if (v == NULL) {
        return language_printf(out, "#<null>");
    }
    else if ((uintptr_t)v < 4096U) {
        return language_printf(out, "#<%d>", (int)(uintptr_t)v);
    }
    unsigned int dist = 1;
    struct recur_list this_item = {depth, v},
                      *newdepth = &this_item,
                      *p = depth;
    while (p) {
        if (language_typetagis(v, language_typemap_entry_type) && newdepth == &this_item) {
            language_value_t *m = p->v;
            unsigned nid = 1;
            while (m && language_typetagis(m, language_typemap_entry_type)) {
                if (m == v) {
                    return language_printf(out, "<typemap reference #%u @-%u ", nid, dist) +
                           language_static_show_x(out, (language_value_t*)((language_typemap_entry_t*)m)->sig, depth, ctx) +
                           language_printf(out, ">");
                }
                if (m == prev) {
                    newdepth = depth;
                    break;
                }
                // verify that we aren't trying to follow a circular list
                // by following the list again, and ensuring this is the only link to next
                language_value_t *mnext = (language_value_t*)language_atomic_load_relaxed(&((language_typemap_entry_t*)m)->next);
                language_value_t *m2 = p->v;
                if (m2 == mnext)
                    break;
                while (m2 && language_typetagis(m2, language_typemap_entry_type)) {
                    language_value_t *mnext2 = (language_value_t*)language_atomic_load_relaxed(&((language_typemap_entry_t*)m2)->next);
                    if (mnext2 == mnext) {
                        if (m2 != m)
                            mnext = NULL;
                        break;
                    }
                    m2 = mnext2;
                }
                m = mnext;
                nid++;
            }
        }
        if (p->v == v)
            return language_printf(out, "<circular reference @-%u>", dist);
        dist++;
        p = p->prev;
    }
    return language_static_show_x_(out, v, (language_datatype_t*)language_typeof(v), newdepth, ctx);
}

LANGUAGE_DLLEXPORT size_t language_static_show(LANGUAGE_STREAM *out, language_value_t *v) LANGUAGE_NOTSAFEPOINT
{
    language_static_show_config_t ctx = { /* quiet */ 0 };
    return language_static_show_x(out, v, 0, ctx);
}

LANGUAGE_DLLEXPORT size_t language_static_show_func_sig(LANGUAGE_STREAM *s, language_value_t *type) LANGUAGE_NOTSAFEPOINT
{
    language_static_show_config_t ctx = { /* quiet */ 0 };
    return language_static_show_func_sig_(s, type, ctx);
}

size_t language_static_show_func_sig_(LANGUAGE_STREAM *s, language_value_t *type, language_static_show_config_t ctx) LANGUAGE_NOTSAFEPOINT
{
    size_t n = 0;
    size_t i;
    language_value_t *ftype = (language_value_t*)language_nth_argument_datatype(type, 1);
    if (ftype == NULL)
        return language_static_show(s, type);
    language_unionall_t *tvars = (language_unionall_t*)type;
    int nvars = language_subtype_env_size(type);
    struct recur_list *depth = NULL;
    if (nvars > 0)  {
        depth = (struct recur_list*)alloca(sizeof(struct recur_list) * nvars);
        for (i = 0; i < nvars; i++) {
            depth[i].prev = i == 0 ? NULL : &depth[i - 1];
            depth[i].v = type;
            type = ((language_unionall_t*)type)->body;
        }
        depth += nvars - 1;
    }
    if (!language_is_datatype(type)) {
        n += language_static_show(s, type);
        return n;
    }
    if ((language_nparams(ftype) == 0 || ftype == ((language_datatype_t*)ftype)->name->wrapper) &&
            ((language_datatype_t*)ftype)->name->mt != language_type_type_mt &&
            ((language_datatype_t*)ftype)->name->mt != language_nonfunction_mt) {
        n += language_static_show_symbol(s, ((language_datatype_t*)ftype)->name->mt->name);
    }
    else {
        n += language_printf(s, "(::");
        n += language_static_show_x(s, ftype, depth, ctx);
        n += language_printf(s, ")");
    }
    size_t tl = language_nparams(type);
    n += language_printf(s, "(");
    for (i = 1; i < tl; i++) {
        language_value_t *tp = language_tparam(type, i);
        if (i != tl - 1) {
            n += language_static_show_x(s, tp, depth, ctx);
            n += language_printf(s, ", ");
        }
        else {
            if (language_vararg_kind(tp) == LANGUAGE_VARARG_UNBOUND) {
                tp = language_unwrap_vararg(tp);
                if (language_is_unionall(tp))
                    n += language_printf(s, "(");
                n += language_static_show_x(s, tp, depth, ctx);
                if (language_is_unionall(tp))
                    n += language_printf(s, ")");
                n += language_printf(s, "...");
            }
            else {
                n += language_static_show_x(s, tp, depth, ctx);
            }
        }
    }
    n += language_printf(s, ")");
    if (language_is_unionall(tvars)) {
        depth -= nvars - 1;
        int first = 1;
        n += language_printf(s, " where {");
        while (language_is_unionall(tvars)) {
            if (!first)
                n += language_printf(s, ", ");
            n += language_static_show_x(s, (language_value_t*)tvars->var, first ? NULL : depth,  ctx);
            tvars = (language_unionall_t*)tvars->body;
            if (!first)
                depth += 1;
            first = 0;
        }
        n += language_printf(s, "}");
    }
    return n;
}

LANGUAGE_DLLEXPORT void code_(void *language_value) LANGUAGE_NOTSAFEPOINT
{
    language_jmp_buf *old_buf = language_get_safe_restore();
    language_jmp_buf buf;
    language_set_safe_restore(&buf);
    if (!language_setjmp(buf, 0)) {
        language_static_show((LANGUAGE_STREAM*)STDERR_FILENO, (language_value_t*)language_value);
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO,"\n");
    }
    else {
        language_printf((LANGUAGE_STREAM*)STDERR_FILENO, "\n!!! ERROR in code_ -- ABORTING !!!\n");
    }
    language_set_safe_restore(old_buf);
}

LANGUAGE_DLLEXPORT void language_breakpoint(language_value_t *v)
{
    // put a breakpoint in your debugger here
}

LANGUAGE_DLLEXPORT void language_test_failure_breakpoint(language_value_t *v)
{
    // put a breakpoint in your debugger here
}

// logging tools --------------------------------------------------------------

void language_log(int level, language_value_t *module, language_value_t *group, language_value_t *id,
            language_value_t *file, language_value_t *line, language_value_t *kwargs,
            language_value_t *msg)
{
    static language_value_t *logmsg_func = NULL;
    if (!logmsg_func && language_base_module) {
        language_value_t *corelogging = language_get_global(language_base_module, language_symbol("CoreLogging"));
        if (corelogging && language_is_module(corelogging)) {
            logmsg_func = language_get_global((language_module_t*)corelogging, language_symbol("logmsg_shim"));
        }
    }
    if (!logmsg_func) {
        ios_t str_;
        ios_mem(&str_, 300);
        LANGUAGE_STREAM* str = (LANGUAGE_STREAM*)&str_;
        if (language_is_string(msg)) {
            language_uv_puts(str, language_string_data(msg), language_string_len(msg));
        }
        else if (language_is_symbol(msg)) {
            language_printf(str, "%s", language_symbol_name((language_sym_t*)msg));
        }
        language_printf(str, "\n@ ");
        if (language_is_string(file)) {
            language_static_show_string(str, language_string_data(file), language_string_len(file), 0);
        }
        else if (language_is_symbol(file)) {
            language_static_show_string(str, language_symbol_name((language_sym_t*)file), strlen(language_symbol_name((language_sym_t*)file)), 0);
        }
        language_printf(str, ":");
        language_static_show(str, line);
        language_safe_printf("%s [Fallback logging]: %.*s\n",
                       level < LANGUAGE_LOGLEVEL_INFO ? "Debug" :
                       level < LANGUAGE_LOGLEVEL_WARN ? "Info" :
                       level < LANGUAGE_LOGLEVEL_ERROR ? "Warning" : "Error",
                       (int)str_.size, str_.buf);
        ios_close(&str_);
        return;
    }
    language_value_t **args;
    const int nargs = 9;
    LANGUAGE_GC_PUSHARGS(args, nargs);
    args[0] = logmsg_func;
    args[1] = language_box_long(level);
    args[2] = msg;
    // Would some of the language_nothing here be better as `missing` instead?
    args[3] = module ? module  : language_nothing;
    args[4] = group  ? group   : language_nothing;
    args[5] = id     ? id      : language_nothing;
    args[6] = file   ? file    : language_nothing;
    args[7] = line   ? line    : language_nothing;
    args[8] = kwargs ? kwargs  : (language_value_t*)language_alloc_vec_any(0);
    language_apply(args, nargs);
    LANGUAGE_GC_POP();
}

#ifdef __cplusplus
}
#endif
