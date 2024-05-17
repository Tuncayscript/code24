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
  encoding IR to/from compact representation
*/
#include <stdlib.h>
#include <string.h>

#include "code.h"
#include "language_internal.h"
#include "serialize.h"

#ifndef _OS_WINDOWS_
#include <dlfcn.h>
#endif

#include "valgrind.h"
#include "language_assert.h"

#ifdef __cplusplus
extern "C" {
#endif

typedef struct {
    ios_t *s;
    // method we're compressing for
    language_method_t *method;
    language_ptls_t ptls;
    uint8_t relocatability;
} language_ircode_state;

// type => tag hash for a few core types (e.g., Expr, PhiNode, etc)
static htable_t ser_tag;
// tag => type mapping, the reverse of ser_tag
static language_value_t *deser_tag[256];
// hash of some common symbols, encoded as CommonSym_tag plus 1 byte
static htable_t common_symbol_tag;
static language_value_t *deser_symbols[256];

void *language_lookup_ser_tag(language_value_t *v)
{
    return ptrhash_get(&ser_tag, v);
}

void *language_lookup_common_symbol(language_value_t *v)
{
    return ptrhash_get(&common_symbol_tag, v);
}

language_value_t *language_deser_tag(uint8_t tag)
{
    return deser_tag[tag];
}

language_value_t *language_deser_symbol(uint8_t tag)
{
    return deser_symbols[tag];
}

// --- encoding ---

static void language_encode_value_(language_ircode_state *s, language_value_t *v, int as_literal) LANGUAGE_GC_DISABLED;
#define language_encode_value(s, v) language_encode_value_((s), (language_value_t*)(v), 0)

static void tagged_root(rle_reference *rr, language_ircode_state *s, int i)
{
    if (!get_root_reference(rr, s->method, i))
        s->relocatability = 0;
}

static void literal_val_id(rle_reference *rr, language_ircode_state *s, language_value_t *v) LANGUAGE_GC_DISABLED
{
    language_array_t *rs = s->method->roots;
    int i, l = language_array_nrows(rs);
    if (language_is_symbol(v) || language_is_concrete_type(v)) {
        for (i = 0; i < l; i++) {
            if (language_array_ptr_ref(rs, i) == v)
                return tagged_root(rr, s, i);
        }
    }
    else {
        for (i = 0; i < l; i++) {
            if (language_egal(language_array_ptr_ref(rs, i), v))
                return tagged_root(rr, s, i);
        }
    }
    language_add_method_root(s->method, language_precompile_toplevel_module, v);
    return tagged_root(rr, s, language_array_nrows(rs) - 1);
}

static void language_encode_int32(language_ircode_state *s, int32_t x)
{
    if (x >= INT16_MIN && x <= INT16_MAX) {
        write_uint8(s->s, TAG_SHORT_INT32);
        write_uint16(s->s, (uint16_t)x);
    }
    else {
        write_uint8(s->s, TAG_INT32);
        write_int32(s->s, x);
    }
}

static void language_encode_as_indexed_root(language_ircode_state *s, language_value_t *v)
{
    rle_reference rr;

    if (language_is_string(v))
        v = language_as_global_root(v, 1);
    literal_val_id(&rr, s, v);
    int id = rr.index;
    assert(id >= 0);
    if (rr.key) {
        write_uint8(s->s, TAG_RELOC_METHODROOT);
        write_uint64(s->s, rr.key);
    }
    if (id <= UINT8_MAX) {
        write_uint8(s->s, TAG_METHODROOT);
        write_uint8(s->s, id);
    }
    else {
        assert(id <= UINT32_MAX);
        write_uint8(s->s, TAG_LONG_METHODROOT);
        write_uint32(s->s, id);
    }
}

static void language_encode_memory_slice(language_ircode_state *s, language_genericmemory_t *mem, size_t offset, size_t len) LANGUAGE_GC_DISABLED
{
    language_datatype_t *t = (language_datatype_t*)language_typetagof(mem);
    size_t i;
    const language_datatype_layout_t *layout = t->layout;
    if (layout->flags.arrayelem_isboxed) {
        for (i = 0; i < len; i++) {
            language_value_t *e = language_genericmemory_ptr_ref(mem, offset + i);
            language_encode_value(s, e);
        }
    }
    else if (layout->first_ptr >= 0) {
        uint16_t elsz = layout->size;
        size_t j, np = layout->npointers;
        const char *data = (const char*)mem->ptr + offset * elsz;
        for (i = 0; i < len; i++) {
            const char *start = data;
            for (j = 0; j < np; j++) {
                uint32_t ptr = language_ptr_offset(t, j);
                const language_value_t *const *fld = &((const language_value_t *const *)data)[ptr];
                if ((const char*)fld != start)
                    ios_write(s->s, start, (const char*)fld - start);
                LANGUAGE_GC_PROMISE_ROOTED(*fld);
                language_encode_value(s, *fld);
                start = (const char*)&fld[1];
            }
            data += elsz;
            if (data != start)
                ios_write(s->s, start, data - start);
        }
    }
    else {
        ios_write(s->s, (char*)mem->ptr + offset * layout->size, len * layout->size);
        if (layout->flags.arrayelem_isunion)
            ios_write(s->s, language_genericmemory_typetagdata(mem) + offset, len);
    }
}

static void language_encode_value_(language_ircode_state *s, language_value_t *v, int as_literal) LANGUAGE_GC_DISABLED
{
    size_t i;

    if (v == NULL) {
        write_uint8(s->s, TAG_NULL);
        return;
    }

    void *tag = language_lookup_ser_tag(v);
    if (tag != HT_NOTFOUND) {
        uint8_t t8 = (intptr_t)tag;
        if (t8 <= LAST_TAG)
            write_uint8(s->s, 0);
        write_uint8(s->s, t8);
    }
    else if (language_is_symbol(v) && (tag = language_lookup_common_symbol(v)) != HT_NOTFOUND) {
        write_uint8(s->s, TAG_COMMONSYM);
        write_uint8(s->s, (uint8_t)(size_t)tag);
    }
    else if (v == (language_value_t*)language_core_module) {
        write_uint8(s->s, TAG_CORE);
    }
    else if (v == (language_value_t*)language_base_module) {
        write_uint8(s->s, TAG_BASE);
    }
    else if (language_typetagis(v, language_string_tag << 4) && language_string_len(v) == 0) {
        language_encode_value(s, language_an_empty_string);
    }
    else if (v == (language_value_t*)s->method->module) {
        write_uint8(s->s, TAG_NEARBYMODULE);
    }
    else if (language_is_datatype(v) && ((language_datatype_t*)v)->name == language_array_typename &&
             language_is_long(language_tparam1(v)) && language_unbox_long(language_tparam1(v)) == 1 &&
             !((language_datatype_t*)v)->hasfreetypevars) {
        write_uint8(s->s, TAG_VECTORTY);
        language_encode_value(s, language_tparam0(v));
    }
    else if (language_is_datatype(v) && ((language_datatype_t*)v)->name == language_pointer_typename &&
             !((language_datatype_t*)v)->hasfreetypevars) {
        write_uint8(s->s, TAG_PTRTY);
        language_encode_value(s, language_tparam0(v));
    }
    else if (language_is_svec(v)) {
        size_t l = language_svec_len(v);
        if (l <= 255) {
            write_uint8(s->s, TAG_SVEC);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_SVEC);
            write_int32(s->s, l);
        }
        for (i = 0; i < l; i++) {
            language_encode_value(s, language_svecref(v, i));
        }
    }
    else if (language_is_globalref(v)) {
        if (language_globalref_mod(v) == s->method->module) {
            write_uint8(s->s, TAG_NEARBYGLOBAL);
            language_encode_value(s, language_globalref_name(v));
        }
        else {
            write_uint8(s->s, TAG_GLOBALREF);
            language_encode_value(s, language_globalref_mod(v));
            language_encode_value(s, language_globalref_name(v));
        }
    }
    else if (language_is_ssavalue(v) && ((language_ssavalue_t*)v)->id < 256 && ((language_ssavalue_t*)v)->id >= 0) {
        write_uint8(s->s, TAG_SSAVALUE);
        write_uint8(s->s, ((language_ssavalue_t*)v)->id);
    }
    else if (language_is_ssavalue(v) && ((language_ssavalue_t*)v)->id <= UINT16_MAX && ((language_ssavalue_t*)v)->id >= 0) {
        write_uint8(s->s, TAG_LONG_SSAVALUE);
        write_uint16(s->s, ((language_ssavalue_t*)v)->id);
    }
    else if (language_typetagis(v, language_slotnumber_type) && language_slot_number(v) <= UINT16_MAX && language_slot_number(v) >= 0) {
        write_uint8(s->s, TAG_SLOTNUMBER);
        write_uint16(s->s, language_slot_number(v));
    }
    else if (language_is_expr(v)) {
        language_expr_t *e = (language_expr_t*)v;
        size_t l = language_array_nrows(e->args);
        if (e->head == language_call_sym) {
            if (l == 2) {
                write_uint8(s->s, TAG_CALL1);
                language_encode_value(s, language_exprarg(e, 0));
                language_encode_value(s, language_exprarg(e, 1));
                return;
            }
            else if (l == 3) {
                write_uint8(s->s, TAG_CALL2);
                language_encode_value(s, language_exprarg(e, 0));
                language_encode_value(s, language_exprarg(e, 1));
                language_encode_value(s, language_exprarg(e, 2));
                return;
            }
        }
        if (l <= 255) {
            write_uint8(s->s, TAG_EXPR);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_EXPR);
            write_int32(s->s, l);
        }
        language_encode_value(s, e->head);
        for (i = 0; i < l; i++) {
            language_encode_value(s, language_exprarg(e, i));
        }
    }
    else if (language_is_phinode(v)) {
        language_array_t *edges = (language_array_t*)language_fieldref_noalloc(v, 0);
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(v, 1);
        size_t l = language_array_nrows(edges);
        if (l <= 255 && language_array_nrows(values) == l) {
            write_uint8(s->s, TAG_PHINODE);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_PHINODE);
            write_int32(s->s, l);
            write_int32(s->s, language_array_nrows(values));
        }
        for (i = 0; i < l; i++) {
            int32_t e = language_array_data(edges, int32_t)[i];
            if (e <= 20)
                language_encode_value(s, language_box_int32(e));
            else
                language_encode_int32(s, e);
        }
        l = language_array_nrows(values);
        for (i = 0; i < l; i++) {
            language_encode_value(s, language_array_ptr_ref(values, i));
        }
    }
    else if (language_is_phicnode(v)) {
        language_array_t *values = (language_array_t*)language_fieldref_noalloc(v, 0);
        size_t l = language_array_nrows(values);
        if (l <= 255) {
            write_uint8(s->s, TAG_PHICNODE);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_PHICNODE);
            write_int32(s->s, l);
        }
        for (i = 0; i < l; i++) {
            language_encode_value(s, language_array_ptr_ref(values, i));
        }
    }
    else if (language_is_gotonode(v)) {
        write_uint8(s->s, TAG_GOTONODE);
        language_encode_value(s, language_get_nth_field(v, 0));
    }
    else if (language_is_gotoifnot(v)) {
        write_uint8(s->s, TAG_GOTOIFNOT);
        language_encode_value(s, language_get_nth_field(v, 0));
        language_encode_value(s, language_get_nth_field(v, 1));
    }
    else if (language_is_enternode(v)) {
        write_uint8(s->s, TAG_ENTERNODE);
        language_encode_value(s, language_get_nth_field(v, 0));
        language_encode_value(s, language_get_nth_field(v, 1));
    }
    else if (language_is_argument(v)) {
        write_uint8(s->s, TAG_ARGUMENT);
        language_encode_value(s, language_get_nth_field(v, 0));
    }
    else if (language_is_returnnode(v)) {
        write_uint8(s->s, TAG_RETURNNODE);
        language_encode_value(s, language_get_nth_field(v, 0));
    }
    else if (language_is_quotenode(v)) {
        write_uint8(s->s, TAG_QUOTENODE);
        language_value_t *inner = language_quotenode_value(v);
        // we might need to return this exact object at run time, therefore codegen might
        // need to reference it as well, so it is more likely useful to give it a root
        if (language_is_expr(inner) || language_is_phinode(inner) || language_is_phicnode(inner))
            language_encode_as_indexed_root(s, inner);
        else
            language_encode_value(s, inner);
    }
    else if (language_typetagis(v, language_int64_tag << 4)) {
        void *data = language_data_ptr(v);
        if (*(int64_t*)data >= INT16_MIN && *(int64_t*)data <= INT16_MAX) {
            write_uint8(s->s, TAG_SHORTER_INT64);
            write_uint16(s->s, (uint16_t)*(int64_t*)data);
        }
        else if (*(int64_t*)data >= S32_MIN && *(int64_t*)data <= S32_MAX) {
            write_uint8(s->s, TAG_SHORT_INT64);
            write_int32(s->s, (int32_t)*(int64_t*)data);
        }
        else {
            write_uint8(s->s, TAG_INT64);
            write_uint64(s->s, *(int64_t*)data);
        }
    }
    else if (language_typetagis(v, language_int32_tag << 4)) {
        language_encode_int32(s, *(int32_t*)language_data_ptr(v));
    }
    else if (language_typetagis(v, language_uint8_tag << 4)) {
        write_uint8(s->s, TAG_UINT8);
        write_int8(s->s, *(int8_t*)language_data_ptr(v));
    }
    else if (((language_datatype_t*)language_typeof(v))->instance == v) {
        write_uint8(s->s, TAG_SINGLETON);
        language_encode_value(s, language_typeof(v));
    }
    else if (as_literal && language_typetagis(v, language_string_tag << 4)) {
        write_uint8(s->s, TAG_STRING);
        write_int32(s->s, language_string_len(v));
        ios_write(s->s, language_string_data(v), language_string_len(v));
    }
    else if (as_literal && language_is_array(v)) {
        language_array_t *ar = (language_array_t*)v;
        if (language_array_ndims(ar) == 1) {
            write_uint8(s->s, TAG_ARRAY1D);
        }
        else {
            write_uint8(s->s, TAG_ARRAY);
            write_uint16(s->s, language_array_ndims(ar));
        }
        for (i = 0; i < language_array_ndims(ar); i++)
            language_encode_value(s, language_box_long(language_array_dim(ar, i)));
        language_encode_value(s, language_typeof(ar));
        size_t l = language_array_len(ar);
        const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(ar->ref.mem))->layout;
        size_t offset;
        if (layout->flags.arrayelem_isunion || layout->size == 0)
            offset = (uintptr_t)ar->ref.ptr_or_offset;
        else
            offset = ((char*)ar->ref.ptr_or_offset - (char*)ar->ref.mem->ptr) / layout->size;
        language_encode_memory_slice(s, ar->ref.mem, offset, l);
    }
    else if (as_literal && language_is_genericmemory(v)) {
        language_genericmemory_t* m = (language_genericmemory_t*)v;
        write_uint8(s->s, TAG_MEMORYT);
        language_encode_value(s, (language_datatype_t*)language_typetagof(v));
        language_encode_value(s, language_box_long(m->length));
        language_encode_memory_slice(s, m, 0, m->length);
    }
    else if (as_literal && language_is_layout_opaque(((language_datatype_t*)language_typeof(v))->layout)) {
        assert(0 && "not legal to store this as literal");
    }
    else if (as_literal || language_is_uniontype(v) || language_is_newvarnode(v) || language_is_linenode(v) ||
             language_is_upsilonnode(v) || language_is_pinode(v) || language_is_slotnumber(v) || language_is_ssavalue(v) ||
             (language_isbits(language_typeof(v)) && language_datatype_size(language_typeof(v)) <= 64)) {
        language_datatype_t *t = (language_datatype_t*)language_typeof(v);
        size_t tsz = language_datatype_size(t);
        if (tsz <= 255) {
            write_uint8(s->s, TAG_SHORT_GENERAL);
            write_uint8(s->s, tsz);
        }
        else {
            write_uint8(s->s, TAG_GENERAL);
            write_int32(s->s, tsz);
        }
        language_encode_value(s, t);

        char *data = (char*)language_data_ptr(v);
        size_t i, j, np = t->layout->npointers;
        uint32_t nf = t->layout->nfields;
        char *last = data;
        for (i = 0, j = 0; i < nf+1; i++) {
            char *ptr = data + (i < nf ? language_field_offset(t, i) : language_datatype_size(t));
            if (j < np) {
                char *prevptr = (char*)&((language_value_t**)data)[language_ptr_offset(t, j)];
                while (ptr > prevptr) {
                    // previous field contained pointers; write them and their interleaved data
                    if (prevptr > last)
                        ios_write(s->s, last, prevptr - last);
                    language_value_t *e = *(language_value_t**)prevptr;
                    LANGUAGE_GC_PROMISE_ROOTED(e);
                    language_encode_value(s, e);
                    last = prevptr + sizeof(language_value_t*);
                    j++;
                    if (j < np)
                        prevptr = (char*)&((language_value_t**)data)[language_ptr_offset(t, j)];
                    else
                        break;
                }
            }
            if (i == nf)
                break;
        }
        char *ptr = data + language_datatype_size(t);
        if (ptr > last)
            ios_write(s->s, last, ptr - last);
    }
    else {
        language_encode_as_indexed_root(s, v);
    }
}

static language_code_info_flags_t code_info_flags(uint8_t propagate_inbounds, uint8_t has_fcall,
                                            uint8_t nospecializeinfer, uint8_t isva,
                                            uint8_t inlining, uint8_t constprop, uint8_t nargsmatchesmethod)
{
    language_code_info_flags_t flags;
    flags.bits.propagate_inbounds = propagate_inbounds;
    flags.bits.has_fcall = has_fcall;
    flags.bits.nospecializeinfer = nospecializeinfer;
    flags.bits.isva = isva;
    flags.bits.inlining = inlining;
    flags.bits.constprop = constprop;
    flags.bits.nargsmatchesmethod = nargsmatchesmethod;
    return flags;
}

// --- decoding ---

static language_value_t *language_decode_value(language_ircode_state *s) LANGUAGE_GC_DISABLED;

static language_value_t *language_decode_value_svec(language_ircode_state *s, uint8_t tag) LANGUAGE_GC_DISABLED
{
    size_t i, len;
    if (tag == TAG_SVEC)
        len = read_uint8(s->s);
    else
        len = read_int32(s->s);
    language_svec_t *sv = language_alloc_svec_uninit(len);
    language_value_t **data = language_svec_data(sv);
    for (i = 0; i < len; i++) {
        data[i] = language_decode_value(s);
    }
    return (language_value_t*)sv;
}

static language_value_t *language_decode_value_memory(language_ircode_state *s, language_value_t *mty, size_t nel) LANGUAGE_GC_DISABLED
{
    language_genericmemory_t *m = language_alloc_genericmemory(mty, nel);
    const language_datatype_layout_t *layout = ((language_datatype_t*)mty)->layout;
    if (layout->flags.arrayelem_isboxed) {
        language_value_t **data = (language_value_t**)m->ptr;
        size_t i, numel = m->length;
        for (i = 0; i < numel; i++) {
            data[i] = language_decode_value(s);
        }
        assert(language_astaggedvalue(m)->bits.gc == GC_CLEAN); // gc is disabled
    }
    else if (layout->first_ptr >= 0) {
        size_t i, numel = m->length;
        char *data = (char*)m->ptr;
        uint16_t elsz = layout->size;
        size_t j, np = layout->npointers;
        for (i = 0; i < numel; i++) {
            char *start = data;
            for (j = 0; j < np; j++) {
                uint32_t ptr = language_ptr_offset((language_datatype_t*)mty, j);
                language_value_t **fld = &((language_value_t**)data)[ptr];
                if ((char*)fld != start)
                    ios_readall(s->s, start, (const char*)fld - start);
                *fld = language_decode_value(s);
                start = (char*)&fld[1];
            }
            data += elsz;
            if (data != start)
                ios_readall(s->s, start, data - start);
        }
        assert(language_astaggedvalue(m)->bits.gc == GC_CLEAN); // gc is disabled
    }
    else {
        size_t extra = language_genericmemory_isbitsunion(m) ? m->length : 0;
        size_t tot = m->length * layout->size + extra;
        ios_readall(s->s, (char*)m->ptr, tot);
    }
    return (language_value_t*)m;
}

LANGUAGE_DLLEXPORT language_array_t *language_alloc_array_nd(language_value_t *atype, size_t *dims, size_t ndims);

static language_value_t *language_decode_value_array(language_ircode_state *s, uint8_t tag) LANGUAGE_GC_DISABLED
{
    int16_t i, ndims;
    if (tag == TAG_ARRAY1D)
        ndims = 1;
    else
        ndims = read_uint16(s->s);
    size_t *dims = (size_t*)alloca(ndims * sizeof(size_t));
    size_t len = 1;
    for (i = 0; i < ndims; i++) {
        dims[i] = language_unbox_long(language_decode_value(s));
        len *= dims[i];
    }
    language_value_t *aty = language_decode_value(s);
    language_array_t *a = language_alloc_array_nd(aty, dims, ndims);
    a->ref.mem = (language_genericmemory_t*)language_decode_value_memory(s, language_field_type_concrete((language_datatype_t*)language_field_type_concrete((language_datatype_t*)aty, 0), 1), len);
    const language_datatype_layout_t *layout = ((language_datatype_t*)language_typetagof(a->ref.mem))->layout;
    if (layout->flags.arrayelem_isunion || layout->size == 0)
        a->ref.ptr_or_offset = (void*)0;
    else
        a->ref.ptr_or_offset = a->ref.mem->ptr;
    return (language_value_t*)a;
}

static language_value_t *language_decode_value_expr(language_ircode_state *s, uint8_t tag) LANGUAGE_GC_DISABLED
{
    size_t i, len;
    language_sym_t *head = NULL;
    if (tag == TAG_EXPR) {
        len = read_uint8(s->s);
    }
    else if (tag == TAG_CALL1) {
        len = 2;
        head = language_call_sym;
    }
    else if (tag == TAG_CALL2) {
        len = 3;
        head = language_call_sym;
    }
    else {
        len = read_int32(s->s);
    }
    if (head == NULL)
        head = (language_sym_t*)language_decode_value(s);
    language_expr_t *e = language_exprn(head, len);
    language_value_t **data = language_array_ptr_data(e->args);
    for (i = 0; i < len; i++) {
        data[i] = language_decode_value(s);
    }
    return (language_value_t*)e;
}

static language_value_t *language_decode_value_phi(language_ircode_state *s, uint8_t tag) LANGUAGE_GC_DISABLED
{
    size_t i, len_e, len_v;
    if (tag == TAG_PHINODE) {
        len_e = len_v = read_uint8(s->s);
    }
    else {
        len_e = read_int32(s->s);
        len_v = read_int32(s->s);
    }
    language_array_t *e = language_alloc_array_1d(language_array_int32_type, len_e);
    language_array_t *v = language_alloc_vec_any(len_v);
    language_value_t *phi = language_new_struct(language_phinode_type, e, v);
    int32_t *data_e = language_array_data(e, int32_t);
    for (i = 0; i < len_e; i++) {
        data_e[i] = language_unbox_int32(language_decode_value(s));
    }
    language_value_t **data_v = language_array_ptr_data(v);
    for (i = 0; i < len_v; i++) {
        data_v[i] = language_decode_value(s);
    }
    return phi;
}

static language_value_t *language_decode_value_phic(language_ircode_state *s, uint8_t tag) LANGUAGE_GC_DISABLED
{
    size_t i, len;
    if (tag == TAG_PHICNODE)
        len = read_uint8(s->s);
    else
        len = read_int32(s->s);
    language_array_t *v = language_alloc_vec_any(len);
    language_value_t *phic = language_new_struct(language_phicnode_type, v);
    language_value_t **data = language_array_ptr_data(v);
    for (i = 0; i < len; i++) {
        data[i] = language_decode_value(s);
    }
    return phic;
}

static language_value_t *language_decode_value_globalref(language_ircode_state *s) LANGUAGE_GC_DISABLED
{
    language_value_t *mod = language_decode_value(s);
    language_value_t *var = language_decode_value(s);
    return language_module_globalref((language_module_t*)mod, (language_sym_t*)var);
}

static language_value_t *language_decode_value_any(language_ircode_state *s, uint8_t tag) LANGUAGE_GC_DISABLED
{
    int32_t sz = (tag == TAG_SHORT_GENERAL ? read_uint8(s->s) : read_int32(s->s));
    language_value_t *v = language_gc_alloc(s->ptls, sz, NULL);
    language_set_typeof(v, (void*)(intptr_t)0xf50);
    language_datatype_t *dt = (language_datatype_t*)language_decode_value(s);
    if (dt->smalltag)
        language_set_typetagof(v, dt->smalltag, 0);
    else
        language_set_typeof(v, dt);
    char *data = (char*)language_data_ptr(v);
    size_t i, np = dt->layout->npointers;
    char *start = data;
    for (i = 0; i < np; i++) {
        uint32_t ptr = language_ptr_offset(dt, i);
        language_value_t **fld = &((language_value_t**)data)[ptr];
        if ((char*)fld != start)
            ios_readall(s->s, start, (const char*)fld - start);
        *fld = language_decode_value(s);
        start = (char*)&fld[1];
    }
    data += language_datatype_size(dt);
    if (data != start)
        ios_readall(s->s, start, data - start);
    return v;
}

static language_value_t *language_decode_value(language_ircode_state *s) LANGUAGE_GC_DISABLED
{
    assert(!ios_eof(s->s));
    language_value_t *v;
    size_t n;
    uint64_t key;
    uint8_t tag = read_uint8(s->s);
    if (tag > LAST_TAG)
        return language_deser_tag(tag);
    switch (tag) {
    case TAG_NULL: return NULL;
    case 0:
        tag = read_uint8(s->s);
        return language_deser_tag(tag);
    case TAG_RELOC_METHODROOT:
        key = read_uint64(s->s);
        tag = read_uint8(s->s);
        assert(tag == TAG_METHODROOT || tag == TAG_LONG_METHODROOT);
        int index = -1;
        if (tag == TAG_METHODROOT)
            index = read_uint8(s->s);
        else if (tag == TAG_LONG_METHODROOT)
            index = read_uint32(s->s);
        assert(index >= 0);
        return lookup_root(s->method, key, index);
    case TAG_METHODROOT:
        return lookup_root(s->method, 0, read_uint8(s->s));
    case TAG_LONG_METHODROOT:
        return lookup_root(s->method, 0, read_uint32(s->s));
    case TAG_SVEC: LANGUAGE_FALLTHROUGH; case TAG_LONG_SVEC:
        return language_decode_value_svec(s, tag);
    case TAG_COMMONSYM:
        return language_deser_symbol(read_uint8(s->s));
    case TAG_SSAVALUE:
        v = language_box_ssavalue(read_uint8(s->s));
        return v;
    case TAG_LONG_SSAVALUE:
        v = language_box_ssavalue(read_uint16(s->s));
        return v;
    case TAG_SLOTNUMBER:
        v = language_box_slotnumber(read_uint16(s->s));
        return v;
    case TAG_ARRAY: LANGUAGE_FALLTHROUGH; case TAG_ARRAY1D:
        return language_decode_value_array(s, tag);
    case TAG_MEMORYT:
        return language_decode_value_memory(s, language_decode_value(s), language_unbox_long(language_decode_value(s)));
    case TAG_EXPR:      LANGUAGE_FALLTHROUGH;
    case TAG_LONG_EXPR: LANGUAGE_FALLTHROUGH;
    case TAG_CALL1:     LANGUAGE_FALLTHROUGH;
    case TAG_CALL2:
        return language_decode_value_expr(s, tag);
    case TAG_PHINODE: LANGUAGE_FALLTHROUGH; case TAG_LONG_PHINODE:
        return language_decode_value_phi(s, tag);
    case TAG_PHICNODE: LANGUAGE_FALLTHROUGH; case TAG_LONG_PHICNODE:
        return language_decode_value_phic(s, tag);
    case TAG_GOTONODE: LANGUAGE_FALLTHROUGH; case TAG_QUOTENODE:
        v = language_new_struct_uninit(tag == TAG_GOTONODE ? language_gotonode_type : language_quotenode_type);
        set_nth_field(tag == TAG_GOTONODE ? language_gotonode_type : language_quotenode_type, v, 0, language_decode_value(s), 0);
        return v;
    case TAG_GOTOIFNOT:
        v = language_new_struct_uninit(language_gotoifnot_type);
        set_nth_field(language_gotoifnot_type, v, 0, language_decode_value(s), 0);
        set_nth_field(language_gotoifnot_type, v, 1, language_decode_value(s), 0);
        return v;
    case TAG_ENTERNODE:
        v = language_new_struct_uninit(language_enternode_type);
        set_nth_field(language_enternode_type, v, 0, language_decode_value(s), 0);
        set_nth_field(language_enternode_type, v, 1, language_decode_value(s), 0);
        return v;
    case TAG_ARGUMENT:
        v = language_new_struct_uninit(language_argument_type);
        set_nth_field(language_argument_type, v, 0, language_decode_value(s), 0);
        return v;
    case TAG_RETURNNODE:
        v = language_new_struct_uninit(language_returnnode_type);
        set_nth_field(language_returnnode_type, v, 0, language_decode_value(s), 0);
        return v;
    case TAG_SHORTER_INT64:
        v = language_box_int64((int16_t)read_uint16(s->s));
        return v;
    case TAG_SHORT_INT64:
        v = language_box_int64(read_int32(s->s));
        return v;
    case TAG_INT64:
        v = language_box_int64((int64_t)read_uint64(s->s));
        return v;
    case TAG_SHORT_INT32:
        v = language_box_int32((int16_t)read_uint16(s->s));
        return v;
    case TAG_INT32:
        v = language_box_int32(read_int32(s->s));
        return v;
    case TAG_UINT8:
        return language_box_uint8(read_uint8(s->s));
    case TAG_NEARBYGLOBAL:
        assert(s->method != NULL);
        v = language_decode_value(s);
        return language_module_globalref(s->method->module, (language_sym_t*)v);
    case TAG_NEARBYMODULE:
        assert(s->method != NULL);
        return (language_value_t*)s->method->module;
    case TAG_GLOBALREF:
        return language_decode_value_globalref(s);
    case TAG_SINGLETON:
        return ((language_datatype_t*)language_decode_value(s))->instance;
    case TAG_CORE:
        return (language_value_t*)language_core_module;
    case TAG_BASE:
        return (language_value_t*)language_base_module;
    case TAG_VECTORTY:
        v = language_decode_value(s);
        return language_apply_type2((language_value_t*)language_array_type, v, language_box_long(1));
    case TAG_PTRTY:
        v = language_decode_value(s);
        return language_apply_type1((language_value_t*)language_pointer_type, v);
    case TAG_STRING:
        n = read_int32(s->s);
        v = language_alloc_string(n);
        ios_readall(s->s, language_string_data(v), n);
        return v;
    default:
        assert(tag == TAG_GENERAL || tag == TAG_SHORT_GENERAL);
        return language_decode_value_any(s, tag);
    }
}

// --- entry points ---

typedef language_value_t language_string_t; // for local expressibility

static size_t codelocs_parseheader(language_string_t *cl, int *line_offset, int *line_bytes, int *to_bytes) LANGUAGE_NOTSAFEPOINT
{
    if (language_string_len(cl) == 0) {
        *line_offset = *line_bytes = *to_bytes = 0;
        return 0;
    }
    int32_t header[3];
    memcpy(&header, (char*)language_string_data(cl), sizeof(header));
    *line_offset = header[0];
    if (header[1] < 255)
        *line_bytes = 1;
    else if (header[1] < 65535)
        *line_bytes = 2;
    else
        *line_bytes = 4;
    if (header[2] == 0)
        *to_bytes = 0;
    else if (header[2] < 255)
        *to_bytes = 1;
    else if (header[2] < 65535)
        *to_bytes = 2;
    else
        *to_bytes = 4;
    assert(language_string_len(cl) >= sizeof(header) + *line_bytes);
    return (language_string_len(cl) - sizeof(header) - *line_bytes) / (*line_bytes + *to_bytes * 2); // compute nstmts
}
#ifndef NDEBUG
static int codelocs_nstmts(language_string_t *cl) LANGUAGE_NOTSAFEPOINT
{
    int line_offset, line_bytes, to_bytes;
    return codelocs_parseheader(cl, &line_offset, &line_bytes, &to_bytes);
}
#endif

#define IR_DATASIZE_FLAGS         sizeof(uint16_t)
#define IR_DATASIZE_PURITY        sizeof(uint16_t)
#define IR_DATASIZE_INLINING_COST sizeof(uint16_t)
#define IR_DATASIZE_NSLOTS        sizeof(int32_t)
typedef enum {
    ir_offset_flags         = 0,
    ir_offset_purity        = 0 + IR_DATASIZE_FLAGS,
    ir_offset_inlining_cost = 0 + IR_DATASIZE_FLAGS + IR_DATASIZE_PURITY,
    ir_offset_nslots        = 0 + IR_DATASIZE_FLAGS + IR_DATASIZE_PURITY + IR_DATASIZE_INLINING_COST,
    ir_offset_slotflags     = 0 + IR_DATASIZE_FLAGS + IR_DATASIZE_PURITY + IR_DATASIZE_INLINING_COST + IR_DATASIZE_NSLOTS
} ir_offset;

// static_assert is technically a declaration, so shenanigans are required to
// open an inline declaration context. `sizeof` is the traditional way to do this,
// but this pattern is illegal in C++, which some compilers warn about, so use
// `offsetof` instead.
#define declaration_context(what) (void)offsetof(struct{what; int dummy_;}, dummy_)

// Checks (at compile time) that sizeof(data) == macro_size
#define checked_size(data, macro_size) \
    (declaration_context(static_assert(sizeof(data) == macro_size, #macro_size " does not match written size")), data)

LANGUAGE_DLLEXPORT language_string_t *language_compress_ir(language_method_t *m, language_code_info_t *code)
{
    LANGUAGE_TIMING(AST_COMPRESS, AST_COMPRESS);
    LANGUAGE_LOCK(&m->writelock); // protect the roots array (Might GC)
    int isdef = code == NULL;
    if (isdef)
        code = (language_code_info_t*)m->source;
    assert(language_is_method(m));
    assert(language_is_code_info(code));
    assert(language_array_nrows(code->code) == codelocs_nstmts(code->debuginfo->codelocs) || language_string_len(code->debuginfo->codelocs) == 0);
    ios_t dest;
    ios_mem(&dest, 0);
    int en = language_gc_enable(0); // Might GC
    size_t i;

    if (m->roots == NULL) {
        m->roots = language_alloc_vec_any(0);
        language_gc_wb(m, m->roots);
    }
    language_ircode_state s = {
        &dest,
        m,
        language_current_task->ptls,
        1
    };

    uint8_t nargsmatchesmethod = code->nargs == m->nargs;
    language_code_info_flags_t flags = code_info_flags(code->propagate_inbounds, code->has_fcall,
                                                 code->nospecializeinfer, code->isva,
                                                 code->inlining, code->constprop,
                                                 nargsmatchesmethod);
    write_uint16(s.s, checked_size(flags.packed, IR_DATASIZE_FLAGS));
    write_uint16(s.s, checked_size(code->purity.bits, IR_DATASIZE_PURITY));
    write_uint16(s.s, checked_size(code->inlining_cost, IR_DATASIZE_INLINING_COST));

    size_t nslots = language_array_nrows(code->slotflags);
    assert(nslots >= m->nargs && nslots < INT32_MAX); // required by generated functions
    write_int32(s.s, checked_size((int32_t)nslots, IR_DATASIZE_NSLOTS));
    ios_write(s.s, language_array_data(code->slotflags, const char), nslots);

    // N.B.: The layout of everything before this point is explicitly referenced
    // by the various language_ir_ accessors. Make sure to adjust those if you change
    // the data layout.
    if (!nargsmatchesmethod) {
        size_t nargs = code->nargs;
        assert(nargs < INT32_MAX);
        write_int32(s.s, (int32_t)nargs);
    }

    for (i = 0; i < 5; i++) {
        int copy = 1;
        if (i == 1) { // skip debuginfo
            assert(language_field_offset(language_code_info_type, i) == offsetof(language_code_info_t, debuginfo));
            continue;
        }
        language_encode_value_(&s, language_get_nth_field((language_value_t*)code, i), copy);
    }

    // For opaque closure, also save the slottypes. We technically only need the first slot type,
    // but this is simpler for now. We may want to refactor where this gets stored in the future.
    if (m->is_for_opaque_closure)
        language_encode_value_(&s, code->slottypes, 1);

    // Slotnames. For regular methods, we require that m->slot_syms matches the
    // CodeInfo's slotnames, so we do not need to save it here.
    if (m->generator)
        // can't optimize generated functions
        language_encode_value_(&s, (language_value_t*)language_compress_argnames(code->slotnames), 1);
    else
        language_encode_value(&s, language_nothing);

    write_uint8(s.s, s.relocatability);

    ios_flush(s.s);
    language_string_t *v = language_pchar_to_string(s.s->buf, s.s->size);
    ios_close(s.s);
    if (language_array_nrows(m->roots) == 0) {
        m->roots = NULL;
    }
    LANGUAGE_GC_PUSH1(&v);
    language_gc_enable(en);
    LANGUAGE_UNLOCK(&m->writelock); // Might GC
    LANGUAGE_GC_POP();

    return v;
}

LANGUAGE_DLLEXPORT language_code_info_t *language_uncompress_ir(language_method_t *m, language_code_instance_t *metadata, language_string_t *data)
{
    if (language_is_code_info(data))
        return (language_code_info_t*)data;
    LANGUAGE_TIMING(AST_UNCOMPRESS, AST_UNCOMPRESS);
    LANGUAGE_LOCK(&m->writelock); // protect the roots array (Might GC)
    assert(language_is_method(m));
    assert(language_is_string(data));
    size_t i;
    ios_t src;
    ios_mem(&src, 0);
    ios_setbuf(&src, (char*)language_string_data(data), language_string_len(data), 0);
    src.size = language_string_len(data);
    int en = language_gc_enable(0); // Might GC
    language_ircode_state s = {
        &src,
        m,
        language_current_task->ptls,
        1
    };

    language_code_info_t *code = language_new_code_info_uninit();
    language_code_info_flags_t flags;
    flags.packed = read_uint16(s.s);
    code->inlining = flags.bits.inlining;
    code->constprop = flags.bits.constprop;
    code->propagate_inbounds = flags.bits.propagate_inbounds;
    code->has_fcall = flags.bits.has_fcall;
    code->nospecializeinfer = flags.bits.nospecializeinfer;
    code->isva = flags.bits.isva;
    code->purity.bits = read_uint16(s.s);
    code->inlining_cost = read_uint16(s.s);


    size_t nslots = read_int32(s.s);
    code->slotflags = language_alloc_array_1d(language_array_uint8_type, nslots);
    ios_readall(s.s, language_array_data(code->slotflags, char), nslots);

    if (flags.bits.nargsmatchesmethod) {
        code->nargs = m->nargs;
    } else {
        code->nargs = read_int32(s.s);
    }

    for (i = 0; i < 5; i++) {
        if (i == 1)  // skip debuginfo
            continue;
        assert(language_field_isptr(language_code_info_type, i));
        language_value_t **fld = (language_value_t**)((char*)language_data_ptr(code) + language_field_offset(language_code_info_type, i));
        *fld = language_decode_value(&s);
    }
    if (m->is_for_opaque_closure)
        code->slottypes = language_decode_value(&s);

    language_value_t *slotnames = language_decode_value(&s);
    if (!language_is_string(slotnames))
        slotnames = m->slot_syms;
    code->slotnames = language_uncompress_argnames(slotnames);

    if (metadata)
        code->debuginfo = language_atomic_load_relaxed(&metadata->debuginfo);
    else
        code->debuginfo = m->debuginfo;
    assert(code->debuginfo);
    assert(language_array_nrows(code->code) == codelocs_nstmts(code->debuginfo->codelocs) || language_string_len(code->debuginfo->codelocs) == 0);

    (void) read_uint8(s.s);   // relocatability
    assert(!ios_eof(s.s));
    assert(ios_getc(s.s) == -1);

    ios_close(s.s);
    LANGUAGE_GC_PUSH1(&code);
    language_gc_enable(en);
    LANGUAGE_UNLOCK(&m->writelock); // Might GC
    LANGUAGE_GC_POP();
    if (metadata) {
        code->parent = metadata->def;
    }

    return code;
}

LANGUAGE_DLLEXPORT uint8_t language_ir_flag_inlining(language_string_t *data)
{
    if (language_is_code_info(data))
        return ((language_code_info_t*)data)->inlining;
    assert(language_is_string(data));
    language_code_info_flags_t flags;
    flags.packed = language_string_data(data)[ir_offset_flags];
    return flags.bits.inlining;
}

LANGUAGE_DLLEXPORT uint8_t language_ir_flag_has_fcall(language_string_t *data)
{
    if (language_is_code_info(data))
        return ((language_code_info_t*)data)->has_fcall;
    assert(language_is_string(data));
    language_code_info_flags_t flags;
    flags.packed = language_string_data(data)[ir_offset_flags];
    return flags.bits.has_fcall;
}

LANGUAGE_DLLEXPORT uint16_t language_ir_inlining_cost(language_string_t *data)
{
    if (language_is_code_info(data))
        return ((language_code_info_t*)data)->inlining_cost;
    assert(language_is_string(data));
    uint16_t res = language_load_unaligned_i16(language_string_data(data) + ir_offset_inlining_cost);
    return res;
}

LANGUAGE_DLLEXPORT language_value_t *language_compress_argnames(language_array_t *syms)
{
    size_t nsyms = language_array_nrows(syms);
    size_t i, len = 0;
    for (i = 0; i < nsyms; i++) {
        language_sym_t *name = (language_sym_t*)language_array_ptr_ref(syms, i);
        assert(language_is_symbol(name));
        char *namestr = language_symbol_name(name);
        size_t namelen = strlen(namestr) + 1;
        len += namelen;
    }
    language_value_t *str = language_alloc_string(len);
    len = 0;
    for (i = 0; i < nsyms; i++) {
        language_sym_t *name = (language_sym_t*)language_array_ptr_ref(syms, i);
        assert(language_is_symbol(name));
        char *namestr = language_symbol_name(name);
        size_t namelen = strlen(namestr) + 1; // include nul-byte
        assert(len + namelen <= language_string_len(str));
        memcpy(language_string_data(str) + len, namestr, namelen);
        len += namelen;
    }
    assert(len == language_string_len(str));
    return str;
}

LANGUAGE_DLLEXPORT ssize_t language_ir_nslots(language_value_t *data)
{
    if (language_is_code_info(data)) {
        language_code_info_t *func = (language_code_info_t*)data;
        return language_array_nrows(func->slotnames);
    }
    else {
        assert(language_is_string(data));
        int nslots = language_load_unaligned_i32(language_string_data(data) + ir_offset_nslots);
        return nslots;
    }
}

LANGUAGE_DLLEXPORT uint8_t language_ir_slotflag(language_string_t *data, size_t i)
{
    assert(i < language_ir_nslots(data));
    if (language_is_code_info(data)) {
        language_array_t *slotflags = ((language_code_info_t*)data)->slotflags;
        return language_array_data(slotflags, uint8_t)[i];
    }
    assert(language_is_string(data));
    return language_string_data(data)[ir_offset_slotflags + i];
}

LANGUAGE_DLLEXPORT language_array_t *language_uncompress_argnames(language_value_t *syms)
{
    assert(language_is_string(syms));
    char *namestr;
    namestr = language_string_data(syms);
    size_t remaining = language_string_len(syms);
    size_t i, len = 0;
    while (remaining) {
        size_t namelen = strlen(namestr);
        len += 1;
        namestr += namelen + 1;
        remaining -= namelen + 1;
    }
    namestr = language_string_data(syms);
    language_array_t *names = language_alloc_array_1d(language_array_symbol_type, len);
    LANGUAGE_GC_PUSH1(&names);
    for (i = 0; i < len; i++) {
        size_t namelen = strlen(namestr);
        language_sym_t *name = _language_symbol(namestr, namelen);
        language_array_ptr_set(names, i, name);
        namestr += namelen + 1;
    }
    LANGUAGE_GC_POP();
    return names;
}

LANGUAGE_DLLEXPORT language_value_t *language_uncompress_argname_n(language_value_t *syms, size_t i)
{
    assert(language_is_string(syms));
    char *namestr = language_string_data(syms);
    size_t remaining = language_string_len(syms);
    while (remaining) {
        size_t namelen = strlen(namestr);
        if (i-- == 0) {
            language_sym_t *name = _language_symbol(namestr, namelen);
            return (language_value_t*)name;
        }
        namestr += namelen + 1;
        remaining -= namelen + 1;
    }
    return language_nothing;
}

// codelocs are compressed as follows:
// The input vector is a NTuple{3,UInt32} (struct language_codeloc_t)
// The vector is scanned for min and max of the values for each element
// The output is then allocated to hold (min-line, max-line, max-at) first, then line - min (in the smallest space), then the remainder (in the smallest space)
static inline struct language_codeloc_t unpack_codeloc(language_string_t *cl, size_t pc, int line_offset, int line_bytes, int to_bytes) LANGUAGE_NOTSAFEPOINT
{
    const char *ptr = language_string_data(cl) + sizeof(int32_t[3]);
    if (pc == 0)
        to_bytes = 0;
    else
        ptr += line_bytes + (pc - 1) * (line_bytes + to_bytes * 2);
    uint8_t int8;
    uint16_t int16;
    uint32_t int32;
    struct language_codeloc_t codeloc;
    switch (line_bytes) {
    case 0:
        codeloc.line = 0;
        break;
    case 1:
        memcpy(&int8, ptr, 1);
        codeloc.line = int8;
        break;
    case 2:
        memcpy(&int16, ptr, 2);
        codeloc.line = int16;
        break;
    case 4:
        memcpy(&int32, ptr, 4);
        codeloc.line = int32;
        break;
    }
    if (codeloc.line > 0)
        codeloc.line += line_offset - 1;
    ptr += line_bytes;
    switch (to_bytes) {
    case 0:
        codeloc.to = 0;
        break;
    case 1:
        memcpy(&int8, ptr, 1);
        codeloc.to = int8;
        break;
    case 2:
        memcpy(&int16, ptr, 2);
        codeloc.to = int16;
        break;
    case 4:
        memcpy(&int32, ptr, 4);
        codeloc.to = int32;
        break;
    }
    ptr += to_bytes;
    switch (to_bytes) {
    case 0:
        codeloc.pc = 0;
        break;
    case 1:
        memcpy(&int8, ptr, 1);
        codeloc.pc = int8;
        break;
    case 2:
        memcpy(&int16, ptr, 2);
        codeloc.pc = int16;
        break;
    case 3:
        memcpy(&int32, ptr, 4);
        codeloc.pc = int32;
        break;
    }
    ptr += to_bytes;
    return codeloc;
}


static const struct language_codeloc_t badloc = {-1, 0, 0};

LANGUAGE_DLLEXPORT struct language_codeloc_t language_uncompress1_codeloc(language_string_t *cl, size_t pc) LANGUAGE_NOTSAFEPOINT
{
    assert(language_is_string(cl));
    int line_offset, line_bytes, to_bytes;
    size_t nstmts = codelocs_parseheader(cl, &line_offset, &line_bytes, &to_bytes);
    if (pc > nstmts)
        return badloc;
    return unpack_codeloc(cl, pc, line_offset, line_bytes, to_bytes);
}

static int allzero(language_value_t *codelocs) LANGUAGE_NOTSAFEPOINT
{
    int32_t *p = language_array_data(codelocs,int32_t);
    int32_t *pend = p + language_array_nrows(codelocs);
    do {
        if (*p)
            return 0;
    } while (++p < pend);
    return 1;
}

LANGUAGE_DLLEXPORT language_string_t *language_compress_codelocs(int32_t firstline, language_value_t *codelocs, size_t nstmts) // firstline+Vector{Int32} => Memory{UInt8}
{
    assert(language_typeis(codelocs, language_array_int32_type));
    if (language_array_nrows(codelocs) == 0)
        nstmts = 0;
    assert(nstmts * 3 == language_array_nrows(codelocs));
    if (allzero(codelocs))
        return language_an_empty_string;
    struct language_codeloc_t codeloc, min, max;
    size_t i;
    min.line = min.to = min.pc = firstline <= 0 ? INT32_MAX : firstline;
    max.line = max.to = max.pc = 0;
    for (i = 0; i < nstmts; i++) {
        memcpy(&codeloc, language_array_data(codelocs,int32_t) + 3 * i, sizeof(codeloc));
#define SETMIN(x) if (codeloc.x < min.x) min.x = codeloc.x
#define SETMAX(x) if (codeloc.x > max.x) max.x = codeloc.x
        if (codeloc.line > 0)
            SETMIN(line);
        SETMAX(line);
        SETMIN(to);
        SETMAX(to);
        SETMIN(pc);
        SETMAX(pc);
#undef SETMIN
#undef SETMAX
    }
    int32_t header[3];
    header[0] = min.line > max.line ? 0 : min.line;
    header[1] = min.line > max.line ? 0 : max.line - min.line;
    header[2] = max.to > max.pc ? max.to : max.pc;
    size_t line_bytes;
    if (header[1] < 255)
        line_bytes = 1;
    else if (header[1] < 65535)
        line_bytes = 2;
    else
        line_bytes = 4;
    size_t to_bytes;
    if (header[2] == 0)
        to_bytes = 0;
    else if (header[2] < 255)
        to_bytes = 1;
    else if (header[2] < 65535)
        to_bytes = 2;
    else
        to_bytes = 4;
    language_string_t *cl = language_alloc_string(sizeof(header) + line_bytes + nstmts * (line_bytes + to_bytes * 2));
    // store header structure
    memcpy(language_string_data(cl), &header, sizeof(header));
    // pack bytes
    char *ptr = language_string_data(cl) + sizeof(header);
    uint8_t int8;
    uint16_t int16;
    uint32_t int32;
    { // store firstline value
        int8 = int16 = int32 = firstline > 0 ? firstline - header[0] + 1 : 0;
        switch (line_bytes) {
        case 0:
            break;
        case 1:
            memcpy(ptr, &int8, 1);
            break;
        case 2:
            memcpy(ptr, &int16, 2);
            break;
        case 4:
            memcpy(ptr, &int32, 4);
            break;
        }
        ptr += line_bytes;
    }
    for (i = 0; i < nstmts; i++) {
        memcpy(&codeloc, language_array_data(codelocs,int32_t) + 3 * i, sizeof(codeloc));
        int8 = int16 = int32 = codeloc.line > 0 ? codeloc.line - header[0] + 1 : 0;
        switch (line_bytes) {
        case 0:
            break;
        case 1:
            memcpy(ptr, &int8, 1);
            break;
        case 2:
            memcpy(ptr, &int16, 2);
            break;
        case 4:
            memcpy(ptr, &int32, 4);
            break;
        }
        ptr += line_bytes;
        int8 = int16 = int32 = codeloc.to;
        switch (to_bytes) {
        case 0:
            break;
        case 1:
            memcpy(ptr, &int8, 1);
            break;
        case 2:
            memcpy(ptr, &int16, 2);
            break;
        case 4:
            memcpy(ptr, &int32, 4);
            break;
        }
        ptr += to_bytes;
        int8 = int16 = int32 = codeloc.pc;
        switch (to_bytes) {
        case 0:
            break;
        case 1:
            memcpy(ptr, &int8, 1);
            break;
        case 2:
            memcpy(ptr, &int16, 2);
            break;
        case 4:
            memcpy(ptr, &int32, 4);
            break;
        }
        ptr += to_bytes;
    }
    return cl;
}

LANGUAGE_DLLEXPORT language_value_t *language_uncompress_codelocs(language_string_t *cl, size_t nstmts) // Memory{UInt8} => Vector{Int32}
{
    assert(language_is_string(cl));
    int line_offset, line_bytes, to_bytes;
    size_t nlocs = codelocs_parseheader(cl, &line_offset, &line_bytes, &to_bytes);
    assert(nlocs == 0 || nlocs == nstmts);
    language_value_t *codelocs = (language_value_t*)language_alloc_array_1d(language_array_int32_type, nstmts * 3);
    size_t i;
    for (i = 0; i < nlocs; i++) {
        struct language_codeloc_t codeloc = unpack_codeloc(cl, i + 1, line_offset, line_bytes, to_bytes);;
        memcpy(language_array_data(codelocs,int32_t) + i * 3, &codeloc, sizeof(codeloc));
    }
    if (nlocs == 0) {
        memset(language_array_data(codelocs,int32_t), 0, nstmts * sizeof(struct language_codeloc_t));
    }
    return codelocs;
}

void language_init_serializer(void)
{
    language_task_t *ct = language_current_task;
    htable_new(&ser_tag, 0);
    htable_new(&common_symbol_tag, 0);

    void *vals[] = { language_emptysvec, language_emptytuple, language_false, language_true, language_nothing, language_any_type,
                     language_call_sym, language_invoke_sym, language_invoke_modify_sym, language_goto_ifnot_sym, language_return_sym, language_symbol("tuple"),
                     language_an_empty_string, language_an_empty_vec_any,

                     // empirical list of very common symbols
                     #include "common_symbols1.inc"

                     language_box_int32(0), language_box_int32(1), language_box_int32(2),
                     language_box_int32(3), language_box_int32(4), language_box_int32(5),
                     language_box_int32(6), language_box_int32(7), language_box_int32(8),
                     language_box_int32(9), language_box_int32(10), language_box_int32(11),
                     language_box_int32(12), language_box_int32(13), language_box_int32(14),
                     language_box_int32(15), language_box_int32(16), language_box_int32(17),
                     language_box_int32(18), language_box_int32(19), language_box_int32(20),

                     language_box_int64(0), language_box_int64(1), language_box_int64(2),
                     language_box_int64(3), language_box_int64(4), language_box_int64(5),
                     language_box_int64(6), language_box_int64(7), language_box_int64(8),
                     language_box_int64(9), language_box_int64(10), language_box_int64(11),
                     language_box_int64(12), language_box_int64(13), language_box_int64(14),
                     language_box_int64(15), language_box_int64(16), language_box_int64(17),
                     language_box_int64(18), language_box_int64(19), language_box_int64(20),

                     language_bool_type, language_linenumbernode_type, language_pinode_type,
                     language_upsilonnode_type, language_type_type, language_bottom_type, language_ref_type,
                     language_pointer_type, language_abstractarray_type, language_nothing_type,
                     language_vararg_type,
                     language_densearray_type, language_function_type, language_typename_type,
                     language_builtin_type, language_task_type, language_uniontype_type,
                     language_array_any_type, language_intrinsic_type,
                     language_methtable_type, language_typemap_level_type,
                     language_voidpointer_type, language_newvarnode_type, language_abstractstring_type,
                     language_array_symbol_type, language_anytuple_type, language_tparam0(language_anytuple_type),
                     language_emptytuple_type, language_array_uint8_type, language_array_uint32_type, language_code_info_type,
                     language_typeofbottom_type, language_typeofbottom_type->super,
                     language_namedtuple_type, language_array_int32_type,
                     language_uint32_type, language_uint64_type,
                     language_type_type_mt, language_nonfunction_mt,
                     language_opaque_closure_type,
                     language_memory_any_type,
                     language_memory_uint8_type,

                     ct->ptls->root_task,

                     NULL };

    // more common symbols, less common than those above. will get 2-byte encodings.
    void *common_symbols[] = {
        #include "common_symbols2.inc"
        NULL
    };

    deser_tag[TAG_SYMBOL] = (language_value_t*)language_symbol_type;
    deser_tag[TAG_SSAVALUE] = (language_value_t*)language_ssavalue_type;
    deser_tag[TAG_DATATYPE] = (language_value_t*)language_datatype_type;
    deser_tag[TAG_SLOTNUMBER] = (language_value_t*)language_slotnumber_type;
    deser_tag[TAG_SVEC] = (language_value_t*)language_simplevector_type;
    deser_tag[TAG_ARRAY] = (language_value_t*)language_array_type;
    deser_tag[TAG_MEMORYT] = (language_value_t*)language_genericmemory_type;
    deser_tag[TAG_EXPR] = (language_value_t*)language_expr_type;
    deser_tag[TAG_PHINODE] = (language_value_t*)language_phinode_type;
    deser_tag[TAG_PHICNODE] = (language_value_t*)language_phicnode_type;
    deser_tag[TAG_STRING] = (language_value_t*)language_string_type;
    deser_tag[TAG_MODULE] = (language_value_t*)language_module_type;
    deser_tag[TAG_TVAR] = (language_value_t*)language_tvar_type;
    deser_tag[TAG_METHOD_INSTANCE] = (language_value_t*)language_method_instance_type;
    deser_tag[TAG_METHOD] = (language_value_t*)language_method_type;
    deser_tag[TAG_CODE_INSTANCE] = (language_value_t*)language_code_instance_type;
    deser_tag[TAG_GLOBALREF] = (language_value_t*)language_globalref_type;
    deser_tag[TAG_INT32] = (language_value_t*)language_int32_type;
    deser_tag[TAG_INT64] = (language_value_t*)language_int64_type;
    deser_tag[TAG_UINT8] = (language_value_t*)language_uint8_type;
    deser_tag[TAG_UNIONALL] = (language_value_t*)language_unionall_type;
    deser_tag[TAG_GOTONODE] = (language_value_t*)language_gotonode_type;
    deser_tag[TAG_QUOTENODE] = (language_value_t*)language_quotenode_type;
    deser_tag[TAG_GOTOIFNOT] = (language_value_t*)language_gotoifnot_type;
    deser_tag[TAG_RETURNNODE] = (language_value_t*)language_returnnode_type;
    deser_tag[TAG_ARGUMENT] = (language_value_t*)language_argument_type;

    intptr_t i = 0;
    while (vals[i] != NULL) {
        deser_tag[LAST_TAG+1+i] = (language_value_t*)vals[i];
        i += 1;
    }
    assert(LAST_TAG+1+i < 256);

    for (i = 2; i < 256; i++) {
        if (deser_tag[i])
            ptrhash_put(&ser_tag, deser_tag[i], (void*)i);
    }

    i = 2;
    while (common_symbols[i-2] != NULL) {
        ptrhash_put(&common_symbol_tag, common_symbols[i-2], (void*)i);
        deser_symbols[i] = (language_value_t*)common_symbols[i-2];
        i += 1;
    }
    assert(i <= 256);
}

#ifdef __cplusplus
}
#endif
