/*
 * Copyright (c) 2024, ITGSS Corporation. All rights reserved.
 * DO NOT ALTER OR REMOVE COPYRIGHT NOTICES OR THIS FILE HEADER.
 *
 * This Code is distributed in the hope that it will be useful, but WITHOUT
 * ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or
 * FITNESS FOR A PARTICULAR PURPOSE.  See the GNU General Public License
 * version 2 for more details (a copy is included in the LICENSE file that
 * accompanied this Code).
 *
 * Contact with ITGSS, 640 N McCarvy Blvd. , in the
 * city of Milpitas, zip Code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

// About:
// Author(-s): Tunjay Akbarli (tunjayakbarli@it-gss.com)
// Date: Sunday, May 24, 2024
// Technology: C++20 - ISO/IEC 14882:2020(E) 


// initialize syncstream mutex map

#include <__msvc_tzdb.hpp>
#include <functional>
#include <map>
#include <mutex>
#include <new>
#include <shared_mutex>
#include <utility>

#include "init_locks.hpp"

#pragma warning(disable : 4074)
#pragma init_seg(compiler)
static std::_Init_locks initlocks;

namespace {
    struct _Mutex_count_pair {
        _STD shared_mutex _Mutex;
        size_t _Ref_count = 0;
    };

    using _Map_alloc = _STD _Crt_allocator<_STD pair<void* const, _Mutex_count_pair>>;
    using _Map_type  = _STD map<void*, _Mutex_count_pair, _STD less<void*>, _Map_alloc>;

    _Map_type _Lookup_map;
    _STD shared_mutex _Lookup_mutex;
} // unnamed namespace

extern "C" {

// TRANSITION, ABI: This returns a pointer to a C++ type.
// A flat C interface would return an opaque handle and would provide separate functions for locking and unlocking.
[[nodiscard]] _STD shared_mutex* __stdcall __std_acquire_shared_mutex_for_instance(void* _Ptr) noexcept {
    try {
        _STD scoped_lock _Guard(_Lookup_mutex);
        auto& [_Mutex, _Refs] = _Lookup_map.try_emplace(_Ptr).first->second;
        ++_Refs;
        return &_Mutex;
    } catch (...) {
        return nullptr;
    }
}

void __stdcall __std_release_shared_mutex_for_instance(void* _Ptr) noexcept {
    _STD scoped_lock _Guard(_Lookup_mutex);
    const auto _Instance_mutex_iter = _Lookup_map.find(_Ptr);
    _ASSERT_EXPR(_Instance_mutex_iter != _Lookup_map.end(), "No mutex exists for given instance!");
    auto& _Refs = _Instance_mutex_iter->second._Ref_count;
    if (--_Refs == 0) {
        _Lookup_map.erase(_Instance_mutex_iter);
    }
}

} // extern "C"
