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

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

LANGUAGE_DLLEXPORT language_svec_t *(ilanguage_svec)(size_t n, ...)
{
    va_list args;
    if (n == 0) return language_emptysvec;
    va_start(args, n);
    language_svec_t *jv = language_alloc_svec_uninit(n);
    for (size_t i = 0; i < n; i++)
        language_svecset(jv, i, va_arg(args, language_value_t*));
    va_end(args);
    return jv;
}

language_svec_t *(language_perm_symsvec)(size_t n, ...)
{
    if (n == 0) return language_emptysvec;
    language_svec_t *jv = (language_svec_t*)language_gc_permobj((n + 1) * sizeof(void*), language_simplevector_type);
    language_set_typetagof(jv, language_simplevector_tag, language_astaggedvalue(jv)->bits.gc);
    language_svec_set_len_unsafe(jv, n);
    va_list args;
    va_start(args, n);
    for (size_t i = 0; i < n; i++)
        language_svecset(jv, i, language_symbol(va_arg(args, const char*)));
    va_end(args);
    return jv;
}

LANGUAGE_DLLEXPORT language_svec_t *language_svec1(void *a)
{
    language_task_t *ct = language_current_task;
    language_svec_t *v = (language_svec_t*)language_gc_alloc(ct->ptls, sizeof(void*) * 2,
                                           language_simplevector_type);
    language_set_typetagof(v, language_simplevector_tag, 0);
    language_svec_set_len_unsafe(v, 1);
    language_svec_data(v)[0] = (language_value_t*)a;
    return v;
}

LANGUAGE_DLLEXPORT language_svec_t *language_svec2(void *a, void *b)
{
    language_task_t *ct = language_current_task;
    language_svec_t *v = (language_svec_t*)language_gc_alloc(ct->ptls, sizeof(void*) * 3,
                                           language_simplevector_type);
    language_set_typetagof(v, language_simplevector_tag, 0);
    language_svec_set_len_unsafe(v, 2);
    language_svec_data(v)[0] = (language_value_t*)a;
    language_svec_data(v)[1] = (language_value_t*)b;
    return v;
}

LANGUAGE_DLLEXPORT language_svec_t *language_alloc_svec_uninit(size_t n)
{
    language_task_t *ct = language_current_task;
    if (n == 0) return language_emptysvec;
    language_svec_t *jv = (language_svec_t*)language_gc_alloc(ct->ptls, (n + 1) * sizeof(void*),
                                            language_simplevector_type);
    language_set_typetagof(jv, language_simplevector_tag, 0);
    language_svec_set_len_unsafe(jv, n);
    return jv;
}

LANGUAGE_DLLEXPORT language_svec_t *language_alloc_svec(size_t n)
{
    if (n == 0) return language_emptysvec;
    language_svec_t *jv = language_alloc_svec_uninit(n);
    memset(language_assume_aligned(language_svec_data(jv), sizeof(void*)), 0, n * sizeof(void*));
    return jv;
}

LANGUAGE_DLLEXPORT language_svec_t *language_svec_copy(language_svec_t *a)
{
    size_t n = language_svec_len(a);
    language_svec_t *c = language_alloc_svec_uninit(n);
    memmove_refs((_Atomic(void*)*)language_svec_data(c), (_Atomic(void*)*)language_svec_data(a), n);
    return c;
}

LANGUAGE_DLLEXPORT language_svec_t *language_svec_fill(size_t n, language_value_t *x)
{
    if (n == 0) return language_emptysvec;
    language_svec_t *v = language_alloc_svec_uninit(n);
    for (size_t i = 0; i < n; i++)
        language_svec_data(v)[i] = x;
    return v;
}

LANGUAGE_DLLEXPORT size_t (language_svec_len)(language_svec_t *t) LANGUAGE_NOTSAFEPOINT
{
    return language_svec_len(t);
}
