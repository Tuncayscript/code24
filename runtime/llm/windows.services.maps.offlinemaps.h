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
 * Contact with ITGSS, 640 N McCarthy Blvd, in the
 * city of Milpitas, zip code 95035, state of California.
 * or visit www.it-gss.com if you need additional information or have any
 * questions.
 *
 */

#pragma once
#ifndef LLM_OS_Services_Maps_OfflineMaps_H
#define LLM_OS_Services_Maps_OfflineMaps_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Services.Maps.h"
#include "llm/impl/Windows.Devices.Geolocation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Services.Maps.OfflineMaps.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStatus) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::Status() const
    {
        llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::EnclosingRegionName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->get_EnclosingRegionName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::EstimatedSizeInBytes() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->get_EstimatedSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::StatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->remove_StatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage, llm::OS::Foundation::IInspectable> const& value) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->add_StatusChanged(*(void**)(&value), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::StatusChanged_revoker consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage, llm::OS::Foundation::IInspectable> const& value) const
    {
        return impl::make_event_revoker<D, StatusChanged_revoker>(this, StatusChanged(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadResult>) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackage<D>::RequestStartDownloadAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage)->RequestStartDownloadAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryStatus) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackageQueryResult<D>::Status() const
    {
        llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage>) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackageQueryResult<D>::Packages() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult)->get_Packages(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadStatus) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackageStartDownloadResult<D>::Status() const
    {
        llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStartDownloadResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackageStatics<D>::FindPackagesAsync(llm::OS::Devices::Geolocation::Geopoint const& queryPoint) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStatics)->FindPackagesAsync(*(void**)(&queryPoint), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackageStatics<D>::FindPackagesInBoundingBoxAsync(llm::OS::Devices::Geolocation::GeoboundingBox const& queryBoundingBox) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStatics)->FindPackagesInBoundingBoxAsync(*(void**)(&queryBoundingBox), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>) consume_Windows_Services_Maps_OfflineMaps_IOfflineMapPackageStatics<D>::FindPackagesInGeocircleAsync(llm::OS::Devices::Geolocation::Geocircle const& queryCircle) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStatics)->FindPackagesInGeocircleAsync(*(void**)(&queryCircle), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage> : produce_base<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnclosingRegionName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnclosingRegionName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EstimatedSizeInBytes(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().EstimatedSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_StatusChanged(void* value, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage, llm::OS::Foundation::IInspectable> const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestStartDownloadAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadResult>>(this->shim().RequestStartDownloadAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult> : produce_base<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Packages(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage>>(this->shim().Packages());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStartDownloadResult> : produce_base<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStartDownloadResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStatics> : produce_base<D, llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStatics>
    {
        int32_t __stdcall FindPackagesAsync(void* queryPoint, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>>(this->shim().FindPackagesAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geopoint const*>(&queryPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindPackagesInBoundingBoxAsync(void* queryBoundingBox, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>>(this->shim().FindPackagesInBoundingBoxAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::GeoboundingBox const*>(&queryBoundingBox)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindPackagesInGeocircleAsync(void* queryCircle, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult>>(this->shim().FindPackagesInGeocircleAsync(*reinterpret_cast<llm::OS::Devices::Geolocation::Geocircle const*>(&queryCircle)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Services::Maps::OfflineMaps
{
    inline auto OfflineMapPackage::FindPackagesAsync(llm::OS::Devices::Geolocation::Geopoint const& queryPoint)
    {
        return impl::call_factory<OfflineMapPackage, IOfflineMapPackageStatics>([&](IOfflineMapPackageStatics const& f) { return f.FindPackagesAsync(queryPoint); });
    }
    inline auto OfflineMapPackage::FindPackagesInBoundingBoxAsync(llm::OS::Devices::Geolocation::GeoboundingBox const& queryBoundingBox)
    {
        return impl::call_factory<OfflineMapPackage, IOfflineMapPackageStatics>([&](IOfflineMapPackageStatics const& f) { return f.FindPackagesInBoundingBoxAsync(queryBoundingBox); });
    }
    inline auto OfflineMapPackage::FindPackagesInGeocircleAsync(llm::OS::Devices::Geolocation::Geocircle const& queryCircle)
    {
        return impl::call_factory<OfflineMapPackage, IOfflineMapPackageStatics>([&](IOfflineMapPackageStatics const& f) { return f.FindPackagesInGeocircleAsync(queryCircle); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStartDownloadResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::IOfflineMapPackageStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Services::Maps::OfflineMaps::OfflineMapPackageStartDownloadResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
