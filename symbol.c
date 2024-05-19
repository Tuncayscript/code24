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
  Symbol table
*/

#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "code.h"
#include "language_internal.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

static _Atomic(language_sym_t*) symtab = NULL;

#define MAX_SYM_LEN ((size_t)INTPTR_MAX - sizeof(language_taggedvalue_t) - sizeof(language_sym_t) - 1)

static uintptr_t hash_symbol(const char *str, size_t len) LANGUAGE_NOTSAFEPOINT
{
    uintptr_t oid = memhash(str, len) ^ ~(uintptr_t)0/3*2;
    // compute the same hash value as v1.6 and earlier, which used `hash_uint(3h - objectid(sym))`
    return inthash(-oid);
}

static size_t symbol_nbytes(size_t len) LANGUAGE_NOTSAFEPOINT
{
    return (sizeof(language_taggedvalue_t) + sizeof(language_sym_t) + len + 1 + 7) & -8;
}

static language_sym_t *mk_symbol(const char *str, size_t len) LANGUAGE_NOTSAFEPOINT
{
    language_sym_t *sym;
    size_t nb = symbol_nbytes(len);
    language_taggedvalue_t *tag = (language_taggedvalue_t*)language_gc_perm_alloc_nolock(nb, 0, sizeof(void*), 0);
    sym = (language_sym_t*)language_valueof(tag);
    // set to old marked so that we won't look at it in the GC or write barrier.
    language_set_typetagof(sym, language_symbol_tag, GC_OLD_MARKED);
    language_atomic_store_relaxed(&sym->left, NULL);
    language_atomic_store_relaxed(&sym->right, NULL);
    sym->hash = hash_symbol(str, len);
    memcpy(language_symbol_name(sym), str, len);
    language_symbol_name(sym)[len] = 0;
    return sym;
}

static language_sym_t *symtab_lookup(_Atomic(language_sym_t*) *ptree, const char *str, size_t len, _Atomic(language_sym_t*) **slot) LANGUAGE_NOTSAFEPOINT
{
    language_sym_t *node = language_atomic_load_relaxed(ptree); // consume
    uintptr_t h = hash_symbol(str, len);

    // Tree nodes sorted by major key of (int(hash)) and minor key of (str).
    while (node != NULL) {
        intptr_t x = (intptr_t)(h - node->hash);
        if (x == 0) {
            x = strncmp(str, language_symbol_name(node), len);
            if (x == 0 && language_symbol_name(node)[len] == 0) {
                if (slot != NULL)
                    *slot = ptree;
                return node;
            }
        }
        if (x < 0)
            ptree = &node->left;
        else
            ptree = &node->right;
        node = language_atomic_load_relaxed(ptree); // consume
    }
    if (slot != NULL)
        *slot = ptree;
    return node;
}

language_sym_t *_language_symbol(const char *str, size_t len) LANGUAGE_NOTSAFEPOINT // (or throw)
{
#ifndef __clang_gcanalyzer__
    // Hide the error throwing from the analyser since there isn't a way to express
    // "safepoint only when throwing error" currently.
    if (len > MAX_SYM_LEN)
        language_exceptionf(language_argumenterror_type, "Symbol name too long");
#endif
    assert(!memchr(str, 0, len));
    _Atomic(language_sym_t*) *slot;
    language_sym_t *node = symtab_lookup(&symtab, str, len, &slot);
    if (node == NULL) {
        uv_mutex_lock(&gc_perm_lock);
        // Someone might have updated it, check and look up again
        if (language_atomic_load_relaxed(slot) != NULL && (node = symtab_lookup(slot, str, len, &slot))) {
            uv_mutex_unlock(&gc_perm_lock);
            return node;
        }
        node = mk_symbol(str, len);
        language_atomic_store_release(slot, node);
        uv_mutex_unlock(&gc_perm_lock);
    }
    return node;
}

LANGUAGE_DLLEXPORT language_sym_t *language_symbol(const char *str) LANGUAGE_NOTSAFEPOINT // (or throw)
{
    return _language_symbol(str, strlen(str));
}

LANGUAGE_DLLEXPORT language_sym_t *language_symbol_lookup(const char *str) LANGUAGE_NOTSAFEPOINT
{
    return symtab_lookup(&symtab, str, strlen(str), NULL);
}

LANGUAGE_DLLEXPORT language_sym_t *language_symbol_n(const char *str, size_t len)
{
    if (memchr(str, 0, len))
        language_exceptionf(language_argumenterror_type, "Symbol name may not contain \\0");
    return _language_symbol(str, len);
}

LANGUAGE_DLLEXPORT language_sym_t *language_get_root_symbol(void)
{
    return language_atomic_load_relaxed(&symtab);
}

static _Atomic(uint32_t) gs_ctr = 0;  // TODO: per-module?
uint32_t language_get_gs_ctr(void) { return language_atomic_load_relaxed(&gs_ctr); }
void language_set_gs_ctr(uint32_t ctr) { language_atomic_store_relaxed(&gs_ctr, ctr); }

LANGUAGE_DLLEXPORT language_sym_t *language_gensym(void)
{
    char name[16];
    char *n;
    uint32_t ctr = language_atomic_fetch_add_relaxed(&gs_ctr, 1);
    n = uint2str(&name[2], sizeof(name)-2, ctr, 10);
    *(--n) = '#'; *(--n) = '#';
    return language_symbol(n);
}

LANGUAGE_DLLEXPORT language_sym_t *language_tagged_gensym(const char *str, size_t len)
{
    if (len == (size_t)-1) {
        len = strlen(str);
    }
    else if (memchr(str, 0, len)) {
        language_exceptionf(language_argumenterror_type, "Symbol name may not contain \\0");
    }
    char gs_name[14];
    size_t alloc_len = sizeof(gs_name) + len + 3;
    if (len > MAX_SYM_LEN || alloc_len > MAX_SYM_LEN)
        language_exceptionf(language_argumenterror_type, "Symbol name too long");
    char *name = (char*)(len >= 256 ? malloc_s(alloc_len) : alloca(alloc_len));
    char *n;
    name[0] = '#';
    name[1] = '#';
    name[2 + len] = '#';
    memcpy(name + 2, str, len);
    uint32_t ctr = language_atomic_fetch_add_relaxed(&gs_ctr, 1);
    n = uint2str(gs_name, sizeof(gs_name), ctr, 10);
    memcpy(name + 3 + len, n, sizeof(gs_name) - (n - gs_name));
    language_sym_t *sym = _language_symbol(name, alloc_len - (n - gs_name)- 1);
    if (len >= 256)
        free(name);
    return sym;
}

#ifdef __cplusplus
}
#endif
