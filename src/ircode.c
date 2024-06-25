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
// Technology: C/C++20 - ISO/IEC 14882:2020(E) a
// Purpose: Encoding IR to/from compact representation

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
    code_method_t *method;
    code_ptls_t ptls;
    uint8_t relocatability;
} code_ircode_state;

// type => tag hash for a few core types (e.g., Expr, PhiNode, etc)
static htable_t ser_tag;
// tag => type mapping, the reverse of ser_tag
static code_value_t *deser_tag[256];
// hash of some common symbols, encoded as CommonSym_tag plus 1 byte
static htable_t common_symbol_tag;
static code_value_t *deser_symbols[256];

void *code_lookup_ser_tag(code_value_t *v)
{
    return ptrhash_get(&ser_tag, v);
}

void *code_lookup_common_symbol(code_value_t *v)
{
    return ptrhash_get(&common_symbol_tag, v);
}

code_value_t *code_deser_tag(uint8_t tag)
{
    return deser_tag[tag];
}

code_value_t *code_deser_symbol(uint8_t tag)
{
    return deser_symbols[tag];
}

// --- encoding ---

static void code_encode_value_(code_ircode_state *s, code_value_t *v, int as_literal) CODE_GC_DISABLED;
#define code_encode_value(s, v) code_encode_value_((s), (code_value_t*)(v), 0)

static void tagged_root(rle_reference *rr, code_ircode_state *s, int i)
{
    if (!get_root_reference(rr, s->method, i))
        s->relocatability = 0;
}

static void literal_val_id(rle_reference *rr, code_ircode_state *s, code_value_t *v) CODE_GC_DISABLED
{
    code_array_t *rs = s->method->roots;
    int i, l = code_array_nrows(rs);
    if (code_is_symbol(v) || code_is_concrete_type(v)) {
        for (i = 0; i < l; i++) {
            if (code_array_ptr_ref(rs, i) == v)
                return tagged_root(rr, s, i);
        }
    }
    else {
        for (i = 0; i < l; i++) {
            if (code_egal(code_array_ptr_ref(rs, i), v))
                return tagged_root(rr, s, i);
        }
    }
    code_add_method_root(s->method, code_precompile_toplevel_module, v);
    return tagged_root(rr, s, code_array_nrows(rs) - 1);
}

static void code_encode_int32(code_ircode_state *s, int32_t x)
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

static void code_encode_as_indexed_root(code_ircode_state *s, code_value_t *v)
{
    rle_reference rr;

    if (code_is_string(v))
        v = code_as_global_root(v, 1);
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

static void code_encode_memory_slice(code_ircode_state *s, code_genericmemory_t *mem, size_t offset, size_t len) CODE_GC_DISABLED
{
    code_datatype_t *t = (code_datatype_t*)code_typetagof(mem);
    size_t i;
    const code_datatype_layout_t *layout = t->layout;
    if (layout->flags.arrayelem_isboxed) {
        for (i = 0; i < len; i++) {
            code_value_t *e = code_genericmemory_ptr_ref(mem, offset + i);
            code_encode_value(s, e);
        }
    }
    else if (layout->first_ptr >= 0) {
        uint16_t elsz = layout->size;
        size_t j, np = layout->npointers;
        const char *data = (const char*)mem->ptr + offset * elsz;
        for (i = 0; i < len; i++) {
            const char *start = data;
            for (j = 0; j < np; j++) {
                uint32_t ptr = code_ptr_offset(t, j);
                const code_value_t *const *fld = &((const code_value_t *const *)data)[ptr];
                if ((const char*)fld != start)
                    ios_write(s->s, start, (const char*)fld - start);
                CODE_GC_PROMISE_ROOTED(*fld);
                code_encode_value(s, *fld);
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
            ios_write(s->s, code_genericmemory_typetagdata(mem) + offset, len);
    }
}

static void code_encode_value_(code_ircode_state *s, code_value_t *v, int as_literal) CODE_GC_DISABLED
{
    size_t i;

    if (v == NULL) {
        write_uint8(s->s, TAG_NULL);
        return;
    }

    void *tag = code_lookup_ser_tag(v);
    if (tag != HT_NOTFOUND) {
        uint8_t t8 = (intptr_t)tag;
        if (t8 <= LAST_TAG)
            write_uint8(s->s, 0);
        write_uint8(s->s, t8);
    }
    else if (code_is_symbol(v) && (tag = code_lookup_common_symbol(v)) != HT_NOTFOUND) {
        write_uint8(s->s, TAG_COMMONSYM);
        write_uint8(s->s, (uint8_t)(size_t)tag);
    }
    else if (v == (code_value_t*)code_core_module) {
        write_uint8(s->s, TAG_CORE);
    }
    else if (v == (code_value_t*)code_base_module) {
        write_uint8(s->s, TAG_BASE);
    }
    else if (code_typetagis(v, code_string_tag << 4) && code_string_len(v) == 0) {
        code_encode_value(s, code_an_empty_string);
    }
    else if (v == (code_value_t*)s->method->module) {
        write_uint8(s->s, TAG_NEARBYMODULE);
    }
    else if (code_is_datatype(v) && ((code_datatype_t*)v)->name == code_array_typename &&
             code_is_long(code_tparam1(v)) && code_unbox_long(code_tparam1(v)) == 1 &&
             !((code_datatype_t*)v)->hasfreetypevars) {
        write_uint8(s->s, TAG_VECTORTY);
        code_encode_value(s, code_tparam0(v));
    }
    else if (code_is_datatype(v) && ((code_datatype_t*)v)->name == code_pointer_typename &&
             !((code_datatype_t*)v)->hasfreetypevars) {
        write_uint8(s->s, TAG_PTRTY);
        code_encode_value(s, code_tparam0(v));
    }
    else if (code_is_svec(v)) {
        size_t l = code_svec_len(v);
        if (l <= 255) {
            write_uint8(s->s, TAG_SVEC);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_SVEC);
            write_int32(s->s, l);
        }
        for (i = 0; i < l; i++) {
            code_encode_value(s, code_svecref(v, i));
        }
    }
    else if (code_is_globalref(v)) {
        if (code_globalref_mod(v) == s->method->module) {
            write_uint8(s->s, TAG_NEARBYGLOBAL);
            code_encode_value(s, code_globalref_name(v));
        }
        else {
            write_uint8(s->s, TAG_GLOBALREF);
            code_encode_value(s, code_globalref_mod(v));
            code_encode_value(s, code_globalref_name(v));
        }
    }
    else if (code_is_ssavalue(v) && ((code_ssavalue_t*)v)->id < 256 && ((code_ssavalue_t*)v)->id >= 0) {
        write_uint8(s->s, TAG_SSAVALUE);
        write_uint8(s->s, ((code_ssavalue_t*)v)->id);
    }
    else if (code_is_ssavalue(v) && ((code_ssavalue_t*)v)->id <= UINT16_MAX && ((code_ssavalue_t*)v)->id >= 0) {
        write_uint8(s->s, TAG_LONG_SSAVALUE);
        write_uint16(s->s, ((code_ssavalue_t*)v)->id);
    }
    else if (code_typetagis(v, code_slotnumber_type) && code_slot_number(v) <= UINT16_MAX && code_slot_number(v) >= 0) {
        write_uint8(s->s, TAG_SLOTNUMBER);
        write_uint16(s->s, code_slot_number(v));
    }
    else if (code_is_expr(v)) {
        code_expr_t *e = (code_expr_t*)v;
        size_t l = code_array_nrows(e->args);
        if (e->head == code_call_sym) {
            if (l == 2) {
                write_uint8(s->s, TAG_CALL1);
                code_encode_value(s, code_exprarg(e, 0));
                code_encode_value(s, code_exprarg(e, 1));
                return;
            }
            else if (l == 3) {
                write_uint8(s->s, TAG_CALL2);
                code_encode_value(s, code_exprarg(e, 0));
                code_encode_value(s, code_exprarg(e, 1));
                code_encode_value(s, code_exprarg(e, 2));
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
        code_encode_value(s, e->head);
        for (i = 0; i < l; i++) {
            code_encode_value(s, code_exprarg(e, i));
        }
    }
    else if (code_is_phinode(v)) {
        code_array_t *edges = (code_array_t*)code_fieldref_noalloc(v, 0);
        code_array_t *values = (code_array_t*)code_fieldref_noalloc(v, 1);
        size_t l = code_array_nrows(edges);
        if (l <= 255 && code_array_nrows(values) == l) {
            write_uint8(s->s, TAG_PHINODE);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_PHINODE);
            write_int32(s->s, l);
            write_int32(s->s, code_array_nrows(values));
        }
        for (i = 0; i < l; i++) {
            int32_t e = code_array_data(edges, int32_t)[i];
            if (e <= 20)
                code_encode_value(s, code_box_int32(e));
            else
                code_encode_int32(s, e);
        }
        l = code_array_nrows(values);
        for (i = 0; i < l; i++) {
            code_encode_value(s, code_array_ptr_ref(values, i));
        }
    }
    else if (code_is_phicnode(v)) {
        code_array_t *values = (code_array_t*)code_fieldref_noalloc(v, 0);
        size_t l = code_array_nrows(values);
        if (l <= 255) {
            write_uint8(s->s, TAG_PHICNODE);
            write_uint8(s->s, (uint8_t)l);
        }
        else {
            write_uint8(s->s, TAG_LONG_PHICNODE);
            write_int32(s->s, l);
        }
        for (i = 0; i < l; i++) {
            code_encode_value(s, code_array_ptr_ref(values, i));
        }
    }
    else if (code_is_gotonode(v)) {
        write_uint8(s->s, TAG_GOTONODE);
        code_encode_value(s, code_get_nth_field(v, 0));
    }
    else if (code_is_gotoifnot(v)) {
        write_uint8(s->s, TAG_GOTOIFNOT);
        code_encode_value(s, code_get_nth_field(v, 0));
        code_encode_value(s, code_get_nth_field(v, 1));
    }
    else if (code_is_enternode(v)) {
        write_uint8(s->s, TAG_ENTERNODE);
        code_encode_value(s, code_get_nth_field(v, 0));
        code_encode_value(s, code_get_nth_field(v, 1));
    }
    else if (code_is_argument(v)) {
        write_uint8(s->s, TAG_ARGUMENT);
        code_encode_value(s, code_get_nth_field(v, 0));
    }
    else if (code_is_returnnode(v)) {
        write_uint8(s->s, TAG_RETURNNODE);
        code_encode_value(s, code_get_nth_field(v, 0));
    }
    else if (code_is_quotenode(v)) {
        write_uint8(s->s, TAG_QUOTENODE);
        code_value_t *inner = code_quotenode_value(v);
        // we might need to return this exact object at run time, therefore codegen might
        // need to reference it as well, so it is more likely useful to give it a root
        if (code_is_expr(inner) || code_is_phinode(inner) || code_is_phicnode(inner))
            code_encode_as_indexed_root(s, inner);
        else
            code_encode_value(s, inner);
    }
    else if (code_typetagis(v, code_int64_tag << 4)) {
        void *data = code_data_ptr(v);
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
    else if (code_typetagis(v, code_int32_tag << 4)) {
        code_encode_int32(s, *(int32_t*)code_data_ptr(v));
    }
    else if (code_typetagis(v, code_uint8_tag << 4)) {
        write_uint8(s->s, TAG_UINT8);
        write_int8(s->s, *(int8_t*)code_data_ptr(v));
    }
    else if (((code_datatype_t*)code_typeof(v))->instance == v) {
        write_uint8(s->s, TAG_SINGLETON);
        code_encode_value(s, code_typeof(v));
    }
    else if (as_literal && code_typetagis(v, code_string_tag << 4)) {
        write_uint8(s->s, TAG_STRING);
        write_int32(s->s, code_string_len(v));
        ios_write(s->s, code_string_data(v), code_string_len(v));
    }
    else if (as_literal && code_is_array(v)) {
        code_array_t *ar = (code_array_t*)v;
        if (code_array_ndims(ar) == 1) {
            write_uint8(s->s, TAG_ARRAY1D);
        }
        else {
            write_uint8(s->s, TAG_ARRAY);
            write_uint16(s->s, code_array_ndims(ar));
        }
        for (i = 0; i < code_array_ndims(ar); i++)
            code_encode_value(s, code_box_long(code_array_dim(ar, i)));
        code_encode_value(s, code_typeof(ar));
        size_t l = code_array_len(ar);
        const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(ar->ref.mem))->layout;
        size_t offset;
        if (layout->flags.arrayelem_isunion || layout->size == 0)
            offset = (uintptr_t)ar->ref.ptr_or_offset;
        else
            offset = ((char*)ar->ref.ptr_or_offset - (char*)ar->ref.mem->ptr) / layout->size;
        code_encode_memory_slice(s, ar->ref.mem, offset, l);
    }
    else if (as_literal && code_is_genericmemory(v)) {
        code_genericmemory_t* m = (code_genericmemory_t*)v;
        write_uint8(s->s, TAG_MEMORYT);
        code_encode_value(s, (code_datatype_t*)code_typetagof(v));
        code_encode_value(s, code_box_long(m->length));
        code_encode_memory_slice(s, m, 0, m->length);
    }
    else if (as_literal && code_is_layout_opaque(((code_datatype_t*)code_typeof(v))->layout)) {
        assert(0 && "not legal to store this as literal");
    }
    else if (as_literal || code_is_uniontype(v) || code_is_newvarnode(v) || code_is_linenode(v) ||
             code_is_upsilonnode(v) || code_is_pinode(v) || code_is_slotnumber(v) || code_is_ssavalue(v) ||
             (code_isbits(code_typeof(v)) && code_datatype_size(code_typeof(v)) <= 64)) {
        code_datatype_t *t = (code_datatype_t*)code_typeof(v);
        size_t tsz = code_datatype_size(t);
        if (tsz <= 255) {
            write_uint8(s->s, TAG_SHORT_GENERAL);
            write_uint8(s->s, tsz);
        }
        else {
            write_uint8(s->s, TAG_GENERAL);
            write_int32(s->s, tsz);
        }
        code_encode_value(s, t);

        char *data = (char*)code_data_ptr(v);
        size_t i, j, np = t->layout->npointers;
        uint32_t nf = t->layout->nfields;
        char *last = data;
        for (i = 0, j = 0; i < nf+1; i++) {
            char *ptr = data + (i < nf ? code_field_offset(t, i) : code_datatype_size(t));
            if (j < np) {
                char *prevptr = (char*)&((code_value_t**)data)[code_ptr_offset(t, j)];
                while (ptr > prevptr) {
                    // previous field contained pointers; write them and their interleaved data
                    if (prevptr > last)
                        ios_write(s->s, last, prevptr - last);
                    code_value_t *e = *(code_value_t**)prevptr;
                    CODE_GC_PROMISE_ROOTED(e);
                    code_encode_value(s, e);
                    last = prevptr + sizeof(code_value_t*);
                    j++;
                    if (j < np)
                        prevptr = (char*)&((code_value_t**)data)[code_ptr_offset(t, j)];
                    else
                        break;
                }
            }
            if (i == nf)
                break;
        }
        char *ptr = data + code_datatype_size(t);
        if (ptr > last)
            ios_write(s->s, last, ptr - last);
    }
    else {
        code_encode_as_indexed_root(s, v);
    }
}

static code_code_info_flags_t code_info_flags(uint8_t propagate_inbounds, uint8_t has_fcall,
                                            uint8_t nospecializeinfer, uint8_t isva,
                                            uint8_t inlining, uint8_t constprop, uint8_t nargsmatchesmethod)
{
    code_code_info_flags_t flags;
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

static code_value_t *code_decode_value(code_ircode_state *s) CODE_GC_DISABLED;

static code_value_t *code_decode_value_svec(code_ircode_state *s, uint8_t tag) CODE_GC_DISABLED
{
    size_t i, len;
    if (tag == TAG_SVEC)
        len = read_uint8(s->s);
    else
        len = read_int32(s->s);
    code_svec_t *sv = code_alloc_svec_uninit(len);
    code_value_t **data = code_svec_data(sv);
    for (i = 0; i < len; i++) {
        data[i] = code_decode_value(s);
    }
    return (code_value_t*)sv;
}

static code_value_t *code_decode_value_memory(code_ircode_state *s, code_value_t *mty, size_t nel) CODE_GC_DISABLED
{
    code_genericmemory_t *m = code_alloc_genericmemory(mty, nel);
    const code_datatype_layout_t *layout = ((code_datatype_t*)mty)->layout;
    if (layout->flags.arrayelem_isboxed) {
        code_value_t **data = (code_value_t**)m->ptr;
        size_t i, numel = m->length;
        for (i = 0; i < numel; i++) {
            data[i] = code_decode_value(s);
        }
        assert(code_astaggedvalue(m)->bits.gc == GC_CLEAN); // gc is disabled
    }
    else if (layout->first_ptr >= 0) {
        size_t i, numel = m->length;
        char *data = (char*)m->ptr;
        uint16_t elsz = layout->size;
        size_t j, np = layout->npointers;
        for (i = 0; i < numel; i++) {
            char *start = data;
            for (j = 0; j < np; j++) {
                uint32_t ptr = code_ptr_offset((code_datatype_t*)mty, j);
                code_value_t **fld = &((code_value_t**)data)[ptr];
                if ((char*)fld != start)
                    ios_readall(s->s, start, (const char*)fld - start);
                *fld = code_decode_value(s);
                start = (char*)&fld[1];
            }
            data += elsz;
            if (data != start)
                ios_readall(s->s, start, data - start);
        }
        assert(code_astaggedvalue(m)->bits.gc == GC_CLEAN); // gc is disabled
    }
    else {
        size_t extra = code_genericmemory_isbitsunion(m) ? m->length : 0;
        size_t tot = m->length * layout->size + extra;
        ios_readall(s->s, (char*)m->ptr, tot);
    }
    return (code_value_t*)m;
}

CODE_DLLEXPORT code_array_t *code_alloc_array_nd(code_value_t *atype, size_t *dims, size_t ndims);

static code_value_t *code_decode_value_array(code_ircode_state *s, uint8_t tag) CODE_GC_DISABLED
{
    int16_t i, ndims;
    if (tag == TAG_ARRAY1D)
        ndims = 1;
    else
        ndims = read_uint16(s->s);
    size_t *dims = (size_t*)alloca(ndims * sizeof(size_t));
    size_t len = 1;
    for (i = 0; i < ndims; i++) {
        dims[i] = code_unbox_long(code_decode_value(s));
        len *= dims[i];
    }
    code_value_t *aty = code_decode_value(s);
    code_array_t *a = code_alloc_array_nd(aty, dims, ndims);
    a->ref.mem = (code_genericmemory_t*)code_decode_value_memory(s, code_field_type_concrete((code_datatype_t*)code_field_type_concrete((code_datatype_t*)aty, 0), 1), len);
    const code_datatype_layout_t *layout = ((code_datatype_t*)code_typetagof(a->ref.mem))->layout;
    if (layout->flags.arrayelem_isunion || layout->size == 0)
        a->ref.ptr_or_offset = (void*)0;
    else
        a->ref.ptr_or_offset = a->ref.mem->ptr;
    return (code_value_t*)a;
}

static code_value_t *code_decode_value_expr(code_ircode_state *s, uint8_t tag) CODE_GC_DISABLED
{
    size_t i, len;
    code_sym_t *head = NULL;
    if (tag == TAG_EXPR) {
        len = read_uint8(s->s);
    }
    else if (tag == TAG_CALL1) {
        len = 2;
        head = code_call_sym;
    }
    else if (tag == TAG_CALL2) {
        len = 3;
        head = code_call_sym;
    }
    else {
        len = read_int32(s->s);
    }
    if (head == NULL)
        head = (code_sym_t*)code_decode_value(s);
    code_expr_t *e = code_exprn(head, len);
    code_value_t **data = code_array_ptr_data(e->args);
    for (i = 0; i < len; i++) {
        data[i] = code_decode_value(s);
    }
    return (code_value_t*)e;
}

static code_value_t *code_decode_value_phi(code_ircode_state *s, uint8_t tag) CODE_GC_DISABLED
{
    size_t i, len_e, len_v;
    if (tag == TAG_PHINODE) {
        len_e = len_v = read_uint8(s->s);
    }
    else {
        len_e = read_int32(s->s);
        len_v = read_int32(s->s);
    }
    code_array_t *e = code_alloc_array_1d(code_array_int32_type, len_e);
    code_array_t *v = code_alloc_vec_any(len_v);
    code_value_t *phi = code_new_struct(code_phinode_type, e, v);
    int32_t *data_e = code_array_data(e, int32_t);
    for (i = 0; i < len_e; i++) {
        data_e[i] = code_unbox_int32(code_decode_value(s));
    }
    code_value_t **data_v = code_array_ptr_data(v);
    for (i = 0; i < len_v; i++) {
        data_v[i] = code_decode_value(s);
    }
    return phi;
}

static code_value_t *code_decode_value_phic(code_ircode_state *s, uint8_t tag) CODE_GC_DISABLED
{
    size_t i, len;
    if (tag == TAG_PHICNODE)
        len = read_uint8(s->s);
    else
        len = read_int32(s->s);
    code_array_t *v = code_alloc_vec_any(len);
    code_value_t *phic = code_new_struct(code_phicnode_type, v);
    code_value_t **data = code_array_ptr_data(v);
    for (i = 0; i < len; i++) {
        data[i] = code_decode_value(s);
    }
    return phic;
}

static code_value_t *code_decode_value_globalref(code_ircode_state *s) CODE_GC_DISABLED
{
    code_value_t *mod = code_decode_value(s);
    code_value_t *var = code_decode_value(s);
    return code_module_globalref((code_module_t*)mod, (code_sym_t*)var);
}

static code_value_t *code_decode_value_any(code_ircode_state *s, uint8_t tag) CODE_GC_DISABLED
{
    int32_t sz = (tag == TAG_SHORT_GENERAL ? read_uint8(s->s) : read_int32(s->s));
    code_value_t *v = code_gc_alloc(s->ptls, sz, NULL);
    code_set_typeof(v, (void*)(intptr_t)0xf50);
    code_datatype_t *dt = (code_datatype_t*)code_decode_value(s);
    if (dt->smalltag)
        code_set_typetagof(v, dt->smalltag, 0);
    else
        code_set_typeof(v, dt);
    char *data = (char*)code_data_ptr(v);
    size_t i, np = dt->layout->npointers;
    char *start = data;
    for (i = 0; i < np; i++) {
        uint32_t ptr = code_ptr_offset(dt, i);
        code_value_t **fld = &((code_value_t**)data)[ptr];
        if ((char*)fld != start)
            ios_readall(s->s, start, (const char*)fld - start);
        *fld = code_decode_value(s);
        start = (char*)&fld[1];
    }
    data += code_datatype_size(dt);
    if (data != start)
        ios_readall(s->s, start, data - start);
    return v;
}

static code_value_t *code_decode_value(code_ircode_state *s) CODE_GC_DISABLED
{
    assert(!ios_eof(s->s));
    code_value_t *v;
    size_t n;
    uint64_t key;
    uint8_t tag = read_uint8(s->s);
    if (tag > LAST_TAG)
        return code_deser_tag(tag);
    switch (tag) {
    case TAG_NULL: return NULL;
    case 0:
        tag = read_uint8(s->s);
        return code_deser_tag(tag);
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
    case TAG_SVEC: CODE_FALLTHROUGH; case TAG_LONG_SVEC:
        return code_decode_value_svec(s, tag);
    case TAG_COMMONSYM:
        return code_deser_symbol(read_uint8(s->s));
    case TAG_SSAVALUE:
        v = code_box_ssavalue(read_uint8(s->s));
        return v;
    case TAG_LONG_SSAVALUE:
        v = code_box_ssavalue(read_uint16(s->s));
        return v;
    case TAG_SLOTNUMBER:
        v = code_box_slotnumber(read_uint16(s->s));
        return v;
    case TAG_ARRAY: CODE_FALLTHROUGH; case TAG_ARRAY1D:
        return code_decode_value_array(s, tag);
    case TAG_MEMORYT:
        return code_decode_value_memory(s, code_decode_value(s), code_unbox_long(code_decode_value(s)));
    case TAG_EXPR:      CODE_FALLTHROUGH;
    case TAG_LONG_EXPR: CODE_FALLTHROUGH;
    case TAG_CALL1:     CODE_FALLTHROUGH;
    case TAG_CALL2:
        return code_decode_value_expr(s, tag);
    case TAG_PHINODE: CODE_FALLTHROUGH; case TAG_LONG_PHINODE:
        return code_decode_value_phi(s, tag);
    case TAG_PHICNODE: CODE_FALLTHROUGH; case TAG_LONG_PHICNODE:
        return code_decode_value_phic(s, tag);
    case TAG_GOTONODE: CODE_FALLTHROUGH; case TAG_QUOTENODE:
        v = code_new_struct_uninit(tag == TAG_GOTONODE ? code_gotonode_type : code_quotenode_type);
        set_nth_field(tag == TAG_GOTONODE ? code_gotonode_type : code_quotenode_type, v, 0, code_decode_value(s), 0);
        return v;
    case TAG_GOTOIFNOT:
        v = code_new_struct_uninit(code_gotoifnot_type);
        set_nth_field(code_gotoifnot_type, v, 0, code_decode_value(s), 0);
        set_nth_field(code_gotoifnot_type, v, 1, code_decode_value(s), 0);
        return v;
    case TAG_ENTERNODE:
        v = code_new_struct_uninit(code_enternode_type);
        set_nth_field(code_enternode_type, v, 0, code_decode_value(s), 0);
        set_nth_field(code_enternode_type, v, 1, code_decode_value(s), 0);
        return v;
    case TAG_ARGUMENT:
        v = code_new_struct_uninit(code_argument_type);
        set_nth_field(code_argument_type, v, 0, code_decode_value(s), 0);
        return v;
    case TAG_RETURNNODE:
        v = code_new_struct_uninit(code_returnnode_type);
        set_nth_field(code_returnnode_type, v, 0, code_decode_value(s), 0);
        return v;
    case TAG_SHORTER_INT64:
        v = code_box_int64((int16_t)read_uint16(s->s));
        return v;
    case TAG_SHORT_INT64:
        v = code_box_int64(read_int32(s->s));
        return v;
    case TAG_INT64:
        v = code_box_int64((int64_t)read_uint64(s->s));
        return v;
    case TAG_SHORT_INT32:
        v = code_box_int32((int16_t)read_uint16(s->s));
        return v;
    case TAG_INT32:
        v = code_box_int32(read_int32(s->s));
        return v;
    case TAG_UINT8:
        return code_box_uint8(read_uint8(s->s));
    case TAG_NEARBYGLOBAL:
        assert(s->method != NULL);
        v = code_decode_value(s);
        return code_module_globalref(s->method->module, (code_sym_t*)v);
    case TAG_NEARBYMODULE:
        assert(s->method != NULL);
        return (code_value_t*)s->method->module;
    case TAG_GLOBALREF:
        return code_decode_value_globalref(s);
    case TAG_SINGLETON:
        return ((code_datatype_t*)code_decode_value(s))->instance;
    case TAG_CORE:
        return (code_value_t*)code_core_module;
    case TAG_BASE:
        return (code_value_t*)code_base_module;
    case TAG_VECTORTY:
        v = code_decode_value(s);
        return code_apply_type2((code_value_t*)code_array_type, v, code_box_long(1));
    case TAG_PTRTY:
        v = code_decode_value(s);
        return code_apply_type1((code_value_t*)code_pointer_type, v);
    case TAG_STRING:
        n = read_int32(s->s);
        v = code_alloc_string(n);
        ios_readall(s->s, code_string_data(v), n);
        return v;
    default:
        assert(tag == TAG_GENERAL || tag == TAG_SHORT_GENERAL);
        return code_decode_value_any(s, tag);
    }
}

// --- entry points ---

typedef code_value_t code_string_t; // for local expressibility

static size_t codelocs_parseheader(code_string_t *cl, int *line_offset, int *line_bytes, int *to_bytes) CODE_NOTSAFEPOINT
{
    if (code_string_len(cl) == 0) {
        *line_offset = *line_bytes = *to_bytes = 0;
        return 0;
    }
    int32_t header[3];
    memcpy(&header, (char*)code_string_data(cl), sizeof(header));
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
    assert(code_string_len(cl) >= sizeof(header) + *line_bytes);
    return (code_string_len(cl) - sizeof(header) - *line_bytes) / (*line_bytes + *to_bytes * 2); // compute nstmts
}
#ifndef NDEBUG
static int codelocs_nstmts(code_string_t *cl) CODE_NOTSAFEPOINT
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

CODE_DLLEXPORT code_string_t *code_compress_ir(code_method_t *m, code_code_info_t *code)
{
    CODE_TIMING(AST_COMPRESS, AST_COMPRESS);
    CODE_LOCK(&m->writelock); // protect the roots array (Might GC)
    int isdef = code == NULL;
    if (isdef)
        code = (code_code_info_t*)m->source;
    assert(code_is_method(m));
    assert(code_is_code_info(code));
    assert(code_array_nrows(code->code) == codelocs_nstmts(code->debuginfo->codelocs) || code_string_len(code->debuginfo->codelocs) == 0);
    ios_t dest;
    ios_mem(&dest, 0);
    int en = code_gc_enable(0); // Might GC
    size_t i;

    if (m->roots == NULL) {
        m->roots = code_alloc_vec_any(0);
        code_gc_wb(m, m->roots);
    }
    code_ircode_state s = {
        &dest,
        m,
        code_current_task->ptls,
        1
    };

    uint8_t nargsmatchesmethod = code->nargs == m->nargs;
    code_code_info_flags_t flags = code_info_flags(code->propagate_inbounds, code->has_fcall,
                                                 code->nospecializeinfer, code->isva,
                                                 code->inlining, code->constprop,
                                                 nargsmatchesmethod);
    write_uint16(s.s, checked_size(flags.packed, IR_DATASIZE_FLAGS));
    write_uint16(s.s, checked_size(code->purity.bits, IR_DATASIZE_PURITY));
    write_uint16(s.s, checked_size(code->inlining_cost, IR_DATASIZE_INLINING_COST));

    size_t nslots = code_array_nrows(code->slotflags);
    assert(nslots >= m->nargs && nslots < INT32_MAX); // required by generated functions
    write_int32(s.s, checked_size((int32_t)nslots, IR_DATASIZE_NSLOTS));
    ios_write(s.s, code_array_data(code->slotflags, const char), nslots);

    // N.B.: The layout of everything before this point is explicitly referenced
    // by the various code_ir_ accessors. Make sure to adjust those if you change
    // the data layout.
    if (!nargsmatchesmethod) {
        size_t nargs = code->nargs;
        assert(nargs < INT32_MAX);
        write_int32(s.s, (int32_t)nargs);
    }

    for (i = 0; i < 5; i++) {
        int copy = 1;
        if (i == 1) { // skip debuginfo
            assert(code_field_offset(code_code_info_type, i) == offsetof(code_code_info_t, debuginfo));
            continue;
        }
        code_encode_value_(&s, code_get_nth_field((code_value_t*)code, i), copy);
    }

    // For opaque closure, also save the slottypes. We technically only need the first slot type,
    // but this is simpler for now. We may want to refactor where this gets stored in the future.
    if (m->is_for_opaque_closure)
        code_encode_value_(&s, code->slottypes, 1);

    // Slotnames. For regular methods, we require that m->slot_syms matches the
    // CodeInfo's slotnames, so we do not need to save it here.
    if (m->generator)
        // can't optimize generated functions
        code_encode_value_(&s, (code_value_t*)code_compress_argnames(code->slotnames), 1);
    else
        code_encode_value(&s, code_nothing);

    write_uint8(s.s, s.relocatability);

    ios_flush(s.s);
    code_string_t *v = code_pchar_to_string(s.s->buf, s.s->size);
    ios_close(s.s);
    if (code_array_nrows(m->roots) == 0) {
        m->roots = NULL;
    }
    CODE_GC_PUSH1(&v);
    code_gc_enable(en);
    CODE_UNLOCK(&m->writelock); // Might GC
    CODE_GC_POP();

    return v;
}

CODE_DLLEXPORT code_code_info_t *code_uncompress_ir(code_method_t *m, code_code_instance_t *metadata, code_string_t *data)
{
    if (code_is_code_info(data))
        return (code_code_info_t*)data;
    CODE_TIMING(AST_UNCOMPRESS, AST_UNCOMPRESS);
    CODE_LOCK(&m->writelock); // protect the roots array (Might GC)
    assert(code_is_method(m));
    assert(code_is_string(data));
    size_t i;
    ios_t src;
    ios_mem(&src, 0);
    ios_setbuf(&src, (char*)code_string_data(data), code_string_len(data), 0);
    src.size = code_string_len(data);
    int en = code_gc_enable(0); // Might GC
    code_ircode_state s = {
        &src,
        m,
        code_current_task->ptls,
        1
    };

    code_code_info_t *code = code_new_code_info_uninit();
    code_code_info_flags_t flags;
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
    code->slotflags = code_alloc_array_1d(code_array_uint8_type, nslots);
    ios_readall(s.s, code_array_data(code->slotflags, char), nslots);

    if (flags.bits.nargsmatchesmethod) {
        code->nargs = m->nargs;
    } else {
        code->nargs = read_int32(s.s);
    }

    for (i = 0; i < 5; i++) {
        if (i == 1)  // skip debuginfo
            continue;
        assert(code_field_isptr(code_code_info_type, i));
        code_value_t **fld = (code_value_t**)((char*)code_data_ptr(code) + code_field_offset(code_code_info_type, i));
        *fld = code_decode_value(&s);
    }
    if (m->is_for_opaque_closure)
        code->slottypes = code_decode_value(&s);

    code_value_t *slotnames = code_decode_value(&s);
    if (!code_is_string(slotnames))
        slotnames = m->slot_syms;
    code->slotnames = code_uncompress_argnames(slotnames);

    if (metadata)
        code->debuginfo = code_atomic_load_relaxed(&metadata->debuginfo);
    else
        code->debuginfo = m->debuginfo;
    assert(code->debuginfo);
    assert(code_array_nrows(code->code) == codelocs_nstmts(code->debuginfo->codelocs) || code_string_len(code->debuginfo->codelocs) == 0);

    (void) read_uint8(s.s);   // relocatability
    assert(!ios_eof(s.s));
    assert(ios_getc(s.s) == -1);

    ios_close(s.s);
    CODE_GC_PUSH1(&code);
    code_gc_enable(en);
    CODE_UNLOCK(&m->writelock); // Might GC
    CODE_GC_POP();
    if (metadata) {
        code->parent = metadata->def;
        code_gc_wb(code, code->parent);
        code->rettype = metadata->rettype;
        code_gc_wb(code, code->rettype);
        code->min_world = code_atomic_load_relaxed(&metadata->min_world);
        code->max_world = code_atomic_load_relaxed(&metadata->max_world);
    }

    return code;
}

CODE_DLLEXPORT uint8_t code_ir_flag_inlining(code_string_t *data)
{
    if (code_is_code_info(data))
        return ((code_code_info_t*)data)->inlining;
    assert(code_is_string(data));
    code_code_info_flags_t flags;
    flags.packed = code_string_data(data)[ir_offset_flags];
    return flags.bits.inlining;
}

CODE_DLLEXPORT uint8_t code_ir_flag_has_fcall(code_string_t *data)
{
    if (code_is_code_info(data))
        return ((code_code_info_t*)data)->has_fcall;
    assert(code_is_string(data));
    code_code_info_flags_t flags;
    flags.packed = code_string_data(data)[ir_offset_flags];
    return flags.bits.has_fcall;
}

CODE_DLLEXPORT uint16_t code_ir_inlining_cost(code_string_t *data)
{
    if (code_is_code_info(data))
        return ((code_code_info_t*)data)->inlining_cost;
    assert(code_is_string(data));
    uint16_t res = code_load_unaligned_i16(code_string_data(data) + ir_offset_inlining_cost);
    return res;
}

CODE_DLLEXPORT code_value_t *code_compress_argnames(code_array_t *syms)
{
    size_t nsyms = code_array_nrows(syms);
    size_t i, len = 0;
    for (i = 0; i < nsyms; i++) {
        code_sym_t *name = (code_sym_t*)code_array_ptr_ref(syms, i);
        assert(code_is_symbol(name));
        char *namestr = code_symbol_name(name);
        size_t namelen = strlen(namestr) + 1;
        len += namelen;
    }
    code_value_t *str = code_alloc_string(len);
    len = 0;
    for (i = 0; i < nsyms; i++) {
        code_sym_t *name = (code_sym_t*)code_array_ptr_ref(syms, i);
        assert(code_is_symbol(name));
        char *namestr = code_symbol_name(name);
        size_t namelen = strlen(namestr) + 1; // include nul-byte
        assert(len + namelen <= code_string_len(str));
        memcpy(code_string_data(str) + len, namestr, namelen);
        len += namelen;
    }
    assert(len == code_string_len(str));
    return str;
}

CODE_DLLEXPORT ssize_t code_ir_nslots(code_value_t *data)
{
    if (code_is_code_info(data)) {
        code_code_info_t *func = (code_code_info_t*)data;
        return code_array_nrows(func->slotnames);
    }
    else {
        assert(code_is_string(data));
        int nslots = code_load_unaligned_i32(code_string_data(data) + ir_offset_nslots);
        return nslots;
    }
}

CODE_DLLEXPORT uint8_t code_ir_slotflag(code_string_t *data, size_t i)
{
    assert(i < code_ir_nslots(data));
    if (code_is_code_info(data)) {
        code_array_t *slotflags = ((code_code_info_t*)data)->slotflags;
        return code_array_data(slotflags, uint8_t)[i];
    }
    assert(code_is_string(data));
    return code_string_data(data)[ir_offset_slotflags + i];
}

CODE_DLLEXPORT code_array_t *code_uncompress_argnames(code_value_t *syms)
{
    assert(code_is_string(syms));
    char *namestr;
    namestr = code_string_data(syms);
    size_t remaining = code_string_len(syms);
    size_t i, len = 0;
    while (remaining) {
        size_t namelen = strlen(namestr);
        len += 1;
        namestr += namelen + 1;
        remaining -= namelen + 1;
    }
    namestr = code_string_data(syms);
    code_array_t *names = code_alloc_array_1d(code_array_symbol_type, len);
    CODE_GC_PUSH1(&names);
    for (i = 0; i < len; i++) {
        size_t namelen = strlen(namestr);
        code_sym_t *name = _code_symbol(namestr, namelen);
        code_array_ptr_set(names, i, name);
        namestr += namelen + 1;
    }
    CODE_GC_POP();
    return names;
}

CODE_DLLEXPORT code_value_t *code_uncompress_argname_n(code_value_t *syms, size_t i)
{
    assert(code_is_string(syms));
    char *namestr = code_string_data(syms);
    size_t remaining = code_string_len(syms);
    while (remaining) {
        size_t namelen = strlen(namestr);
        if (i-- == 0) {
            code_sym_t *name = _code_symbol(namestr, namelen);
            return (code_value_t*)name;
        }
        namestr += namelen + 1;
        remaining -= namelen + 1;
    }
    return code_nothing;
}

// codelocs are compressed as follows:
// The input vector is a NTuple{3,UInt32} (struct code_codeloc_t)
// The vector is scanned for min and max of the values for each element
// The output is then allocated to hold (min-line, max-line, max-at) first, then line - min (in the smallest space), then the remainder (in the smallest space)
static inline struct code_codeloc_t unpack_codeloc(code_string_t *cl, size_t pc, int line_offset, int line_bytes, int to_bytes) CODE_NOTSAFEPOINT
{
    const char *ptr = code_string_data(cl) + sizeof(int32_t[3]);
    if (pc == 0)
        to_bytes = 0;
    else
        ptr += line_bytes + (pc - 1) * (line_bytes + to_bytes * 2);
    uint8_t int8;
    uint16_t int16;
    uint32_t int32;
    struct code_codeloc_t codeloc;
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


static const struct code_codeloc_t badloc = {-1, 0, 0};

CODE_DLLEXPORT struct code_codeloc_t code_uncompress1_codeloc(code_string_t *cl, size_t pc) CODE_NOTSAFEPOINT
{
    assert(code_is_string(cl));
    int line_offset, line_bytes, to_bytes;
    size_t nstmts = codelocs_parseheader(cl, &line_offset, &line_bytes, &to_bytes);
    if (pc > nstmts)
        return badloc;
    return unpack_codeloc(cl, pc, line_offset, line_bytes, to_bytes);
}

static int allzero(code_value_t *codelocs) CODE_NOTSAFEPOINT
{
    int32_t *p = code_array_data(codelocs,int32_t);
    int32_t *pend = p + code_array_nrows(codelocs);
    do {
        if (*p)
            return 0;
    } while (++p < pend);
    return 1;
}

CODE_DLLEXPORT code_string_t *code_compress_codelocs(int32_t firstline, code_value_t *codelocs, size_t nstmts) // firstline+Vector{Int32} => Memory{UInt8}
{
    assert(code_typeis(codelocs, code_array_int32_type));
    if (code_array_nrows(codelocs) == 0)
        nstmts = 0;
    assert(nstmts * 3 == code_array_nrows(codelocs));
    if (allzero(codelocs))
        return code_an_empty_string;
    struct code_codeloc_t codeloc, min, max;
    size_t i;
    min.line = min.to = min.pc = firstline <= 0 ? INT32_MAX : firstline;
    max.line = max.to = max.pc = 0;
    for (i = 0; i < nstmts; i++) {
        memcpy(&codeloc, code_array_data(codelocs,int32_t) + 3 * i, sizeof(codeloc));
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
    code_string_t *cl = code_alloc_string(sizeof(header) + line_bytes + nstmts * (line_bytes + to_bytes * 2));
    // store header structure
    memcpy(code_string_data(cl), &header, sizeof(header));
    // pack bytes
    char *ptr = code_string_data(cl) + sizeof(header);
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
        memcpy(&codeloc, code_array_data(codelocs,int32_t) + 3 * i, sizeof(codeloc));
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

CODE_DLLEXPORT code_value_t *code_uncompress_codelocs(code_string_t *cl, size_t nstmts) // Memory{UInt8} => Vector{Int32}
{
    assert(code_is_string(cl));
    int line_offset, line_bytes, to_bytes;
    size_t nlocs = codelocs_parseheader(cl, &line_offset, &line_bytes, &to_bytes);
    assert(nlocs == 0 || nlocs == nstmts);
    code_value_t *codelocs = (code_value_t*)code_alloc_array_1d(code_array_int32_type, nstmts * 3);
    size_t i;
    for (i = 0; i < nlocs; i++) {
        struct code_codeloc_t codeloc = unpack_codeloc(cl, i + 1, line_offset, line_bytes, to_bytes);;
        memcpy(code_array_data(codelocs,int32_t) + i * 3, &codeloc, sizeof(codeloc));
    }
    if (nlocs == 0) {
        memset(code_array_data(codelocs,int32_t), 0, nstmts * sizeof(struct code_codeloc_t));
    }
    return codelocs;
}

void code_init_serializer(void)
{
    code_task_t *ct = code_current_task;
    htable_new(&ser_tag, 0);
    htable_new(&common_symbol_tag, 0);

    void *vals[] = { code_emptysvec, code_emptytuple, code_false, code_true, code_nothing, code_any_type,
                     code_call_sym, code_invoke_sym, code_invoke_modify_sym, code_goto_ifnot_sym, code_return_sym, code_symbol("tuple"),
                     code_an_empty_string, code_an_empty_vec_any,

                     // empirical list of very common symbols
                     #include "common_symbols1.inc"

                     code_box_int32(0), code_box_int32(1), code_box_int32(2),
                     code_box_int32(3), code_box_int32(4), code_box_int32(5),
                     code_box_int32(6), code_box_int32(7), code_box_int32(8),
                     code_box_int32(9), code_box_int32(10), code_box_int32(11),
                     code_box_int32(12), code_box_int32(13), code_box_int32(14),
                     code_box_int32(15), code_box_int32(16), code_box_int32(17),
                     code_box_int32(18), code_box_int32(19), code_box_int32(20),

                     code_box_int64(0), code_box_int64(1), code_box_int64(2),
                     code_box_int64(3), code_box_int64(4), code_box_int64(5),
                     code_box_int64(6), code_box_int64(7), code_box_int64(8),
                     code_box_int64(9), code_box_int64(10), code_box_int64(11),
                     code_box_int64(12), code_box_int64(13), code_box_int64(14),
                     code_box_int64(15), code_box_int64(16), code_box_int64(17),
                     code_box_int64(18), code_box_int64(19), code_box_int64(20),

                     code_bool_type, code_linenumbernode_type, code_pinode_type,
                     code_upsilonnode_type, code_type_type, code_bottom_type, code_ref_type,
                     code_pointer_type, code_abstractarray_type, code_nothing_type,
                     code_vararg_type,
                     code_densearray_type, code_function_type, code_typename_type,
                     code_builtin_type, code_task_type, code_uniontype_type,
                     code_array_any_type, code_intrinsic_type,
                     code_methtable_type, code_typemap_level_type,
                     code_voidpointer_type, code_newvarnode_type, code_abstractstring_type,
                     code_array_symbol_type, code_anytuple_type, code_tparam0(code_anytuple_type),
                     code_emptytuple_type, code_array_uint8_type, code_array_uint32_type, code_code_info_type,
                     code_typeofbottom_type, code_typeofbottom_type->super,
                     code_namedtuple_type, code_array_int32_type,
                     code_uint32_type, code_uint64_type,
                     code_type_type_mt, code_nonfunction_mt,
                     code_opaque_closure_type,
                     code_memory_any_type,
                     code_memory_uint8_type,

                     ct->ptls->root_task,

                     NULL };

    // more common symbols, less common than those above. will get 2-byte encodings.
    void *common_symbols[] = {
        #include "common_symbols2.inc"
        NULL
    };

    deser_tag[TAG_SYMBOL] = (code_value_t*)code_symbol_type;
    deser_tag[TAG_SSAVALUE] = (code_value_t*)code_ssavalue_type;
    deser_tag[TAG_DATATYPE] = (code_value_t*)code_datatype_type;
    deser_tag[TAG_SLOTNUMBER] = (code_value_t*)code_slotnumber_type;
    deser_tag[TAG_SVEC] = (code_value_t*)code_simplevector_type;
    deser_tag[TAG_ARRAY] = (code_value_t*)code_array_type;
    deser_tag[TAG_MEMORYT] = (code_value_t*)code_genericmemory_type;
    deser_tag[TAG_EXPR] = (code_value_t*)code_expr_type;
    deser_tag[TAG_PHINODE] = (code_value_t*)code_phinode_type;
    deser_tag[TAG_PHICNODE] = (code_value_t*)code_phicnode_type;
    deser_tag[TAG_STRING] = (code_value_t*)code_string_type;
    deser_tag[TAG_MODULE] = (code_value_t*)code_module_type;
    deser_tag[TAG_TVAR] = (code_value_t*)code_tvar_type;
    deser_tag[TAG_METHOD_INSTANCE] = (code_value_t*)code_method_instance_type;
    deser_tag[TAG_METHOD] = (code_value_t*)code_method_type;
    deser_tag[TAG_CODE_INSTANCE] = (code_value_t*)code_code_instance_type;
    deser_tag[TAG_GLOBALREF] = (code_value_t*)code_globalref_type;
    deser_tag[TAG_INT32] = (code_value_t*)code_int32_type;
    deser_tag[TAG_INT64] = (code_value_t*)code_int64_type;
    deser_tag[TAG_UINT8] = (code_value_t*)code_uint8_type;
    deser_tag[TAG_UNIONALL] = (code_value_t*)code_unionall_type;
    deser_tag[TAG_GOTONODE] = (code_value_t*)code_gotonode_type;
    deser_tag[TAG_QUOTENODE] = (code_value_t*)code_quotenode_type;
    deser_tag[TAG_GOTOIFNOT] = (code_value_t*)code_gotoifnot_type;
    deser_tag[TAG_RETURNNODE] = (code_value_t*)code_returnnode_type;
    deser_tag[TAG_ARGUMENT] = (code_value_t*)code_argument_type;

    intptr_t i = 0;
    while (vals[i] != NULL) {
        deser_tag[LAST_TAG+1+i] = (code_value_t*)vals[i];
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
        deser_symbols[i] = (code_value_t*)common_symbols[i-2];
        i += 1;
    }
    assert(i <= 256);
}

#ifdef __cplusplus
}
#endif
