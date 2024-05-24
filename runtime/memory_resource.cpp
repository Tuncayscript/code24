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


#include <internal_shared.h>
#include <memory_resource>
#include <system_error>

_STD_BEGIN
namespace pmr {

    static memory_resource* _Default_resource{nullptr};

    extern "C" _CRT_SATELLITE_1 _Aligned_new_delete_resource_impl* __cdecl _Aligned_new_delete_resource() noexcept {
        return &const_cast<_Aligned_new_delete_resource_impl&>(
            _Immortalize_memcpy_image<_Aligned_new_delete_resource_impl>());
    }

    extern "C" _CRT_SATELLITE_1 _Unaligned_new_delete_resource_impl* __cdecl _Unaligned_new_delete_resource() noexcept {
        return &const_cast<_Unaligned_new_delete_resource_impl&>(
            _Immortalize_memcpy_image<_Unaligned_new_delete_resource_impl>());
    }

    extern "C" _CRT_SATELLITE_1 memory_resource* __cdecl _Aligned_get_default_resource() noexcept {
        memory_resource* const _Temp = __crt_interlocked_read_pointer(&_Default_resource);
        if (_Temp) {
            return _Temp;
        }

        return _Aligned_new_delete_resource();
    }

    extern "C" _CRT_SATELLITE_1 memory_resource* __cdecl _Unaligned_get_default_resource() noexcept {
        memory_resource* const _Temp = __crt_interlocked_read_pointer(&_Default_resource);
        if (_Temp) {
            return _Temp;
        }

        return _Unaligned_new_delete_resource();
    }

    extern "C" _CRT_SATELLITE_1 memory_resource* __cdecl _Aligned_set_default_resource(
        memory_resource* const _Resource) noexcept {
        memory_resource* const _Temp = __crt_interlocked_exchange_pointer(&_Default_resource, _Resource);
        if (_Temp) {
            return _Temp;
        }

        return _Aligned_new_delete_resource();
    }

    extern "C" _CRT_SATELLITE_1 memory_resource* __cdecl _Unaligned_set_default_resource(
        memory_resource* const _Resource) noexcept {
        memory_resource* const _Temp = __crt_interlocked_exchange_pointer(&_Default_resource, _Resource);
        if (_Temp) {
            return _Temp;
        }

        return _Unaligned_new_delete_resource();
    }

    extern "C" [[nodiscard]] _CRT_SATELLITE_1 memory_resource* __cdecl null_memory_resource() noexcept {
        class _Null_resource final : public _Identity_equal_resource {
            void* do_allocate(size_t, size_t) override { // Sorry, OOM!
                _Xbad_alloc();
            }
            void do_deallocate(void*, size_t, size_t) override {} // Nothing to do
        };

        return &const_cast<_Null_resource&>(_Immortalize_memcpy_image<_Null_resource>());
    }

} // namespace pmr
_STD_END
