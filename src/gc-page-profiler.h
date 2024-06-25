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
// Date: Sunday, May 19, 2024
// Technology: C/C++20 - ISO/IEC 14882:2020(E) 

#ifndef GC_PAGE_PROFILER_H
#define GC_PAGE_PROFILER_H

#include "gc.h"

#ifdef __cplusplus
extern "C" {
#endif

#define GC_PAGE_PROFILER_SERIALIZER_INIT_CAPACITY (4096)

typedef struct {
    arraylist_t typestrs;
    char *data;
    int osize;
    char *buffers;
    size_t cursor;
    size_t capacity;
} gc_page_profiler_serializer_t;

// mutex for page profile
extern uv_mutex_t page_profile_lock;
// whether page profiling is enabled
extern int page_profile_enabled;

// Serializer functions
gc_page_profiler_serializer_t gc_page_serializer_create(void) LANGUAGE_NOTSAFEPOINT;
void gc_page_serializer_init(gc_page_profiler_serializer_t *serializer,
                             language_gc_pagemeta_t *pg) LANGUAGE_NOTSAFEPOINT;
void gc_page_serializer_destroy(gc_page_profiler_serializer_t *serializer) LANGUAGE_NOTSAFEPOINT;
void gc_page_serializer_write(gc_page_profiler_serializer_t *serializer,
                              const char *str) LANGUAGE_NOTSAFEPOINT;
// Page profile functions
#define GC_SERIALIZER_EMPTY ((const char *)0x1)
#define GC_SERIALIZER_GARBAGE ((const char *)0x2)
STATIC_INLINE void gc_page_profile_write_empty_page(gc_page_profiler_serializer_t *serializer,
                                 int enabled) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(enabled)) {
        gc_page_serializer_write(serializer, GC_SERIALIZER_EMPTY);
    }
}
STATIC_INLINE void gc_page_profile_write_garbage(gc_page_profiler_serializer_t *serializer,
                                                 int enabled) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(enabled)) {
        gc_page_serializer_write(serializer, GC_SERIALIZER_GARBAGE);
    }
}
STATIC_INLINE char *gc_page_profile_request_buffer(gc_page_profiler_serializer_t *serializer, size_t size) LANGUAGE_NOTSAFEPOINT
{
    while (serializer->cursor + size >= serializer->capacity) {
        serializer->capacity *= 2;
        serializer->buffers = (char *)realloc_s(serializer->buffers, serializer->capacity);
    }
    char *p = &serializer->buffers[serializer->cursor];
    memset(p, 0, size);
    serializer->cursor += size;
    return p;
}
STATIC_INLINE void gc_page_profile_write_live_obj(gc_page_profiler_serializer_t *serializer,
                                                  language_taggedvalue_t *v,
                                                  int enabled) LANGUAGE_NOTSAFEPOINT
{
    if (__unlikely(enabled)) {
        language_value_t *a = language_valueof(v);
        language_value_t *t = language_typeof(a);
        ios_t str_;
        int ios_need_close = 0;
        char *type_name = NULL;
        char *type_name_in_serializer = NULL;
        if (t == (language_value_t *)language_get_buff_tag()) {
            type_name = "Buffer";
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, strlen(type_name) + 1);
            strcpy(type_name_in_serializer, type_name);
        }
        else if (language_is_string(a)) {
            type_name = "String";
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, strlen(type_name) + 1);
            strcpy(type_name_in_serializer, type_name);
        }
        else if (language_is_symbol(a)) {
            type_name = language_symbol_name((language_sym_t *)a);
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, strlen(type_name) + 1);
            strcpy(type_name_in_serializer, type_name);
        }
        else if (language_is_simplevector(a)) {
            type_name = "SimpleVector";
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, strlen(type_name) + 1);
            strcpy(type_name_in_serializer, type_name);
        }
        else if (language_is_module(a)) {
            type_name = language_symbol_name_(((language_module_t *)a)->name);
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, strlen(type_name) + 1);
            strcpy(type_name_in_serializer, type_name);
        }
        else if (language_is_task(a)) {
            type_name = "Task";
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, strlen(type_name) + 1);
            strcpy(type_name_in_serializer, type_name);
        }
        else if (language_is_datatype(a)) {
            ios_need_close = 1;
            ios_mem(&str_, 0);
            LANGUAGE_STREAM *str = (LANGUAGE_STREAM *)&str_;
            language_static_show(str, a);
            type_name = str_.buf;
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, str_.size + 1);
            memcpy(type_name_in_serializer, type_name, str_.size);
        }
        else {
            ios_need_close = 1;
            ios_mem(&str_, 0);
            LANGUAGE_STREAM *str = (LANGUAGE_STREAM *)&str_;
            language_static_show(str, t);
            type_name = str_.buf;
            type_name_in_serializer =
                gc_page_profile_request_buffer(serializer, str_.size + 1);
            memcpy(type_name_in_serializer, type_name, str_.size);
        }
        gc_page_serializer_write(serializer, type_name_in_serializer);
        if (ios_need_close) {
            ios_close(&str_);
        }
        language_may_leak(type_name_in_serializer);
    }
}
void gc_enable_page_profile(void) LANGUAGE_NOTSAFEPOINT;
void gc_disable_page_profile(void) LANGUAGE_NOTSAFEPOINT;
int gc_page_profile_is_enabled(void) LANGUAGE_NOTSAFEPOINT;
void gc_page_profile_write_to_file(gc_page_profiler_serializer_t *serializer) LANGUAGE_NOTSAFEPOINT;

#ifdef __cplusplus
}
#endif

#endif // GC_PAGE_PROFILER_H
