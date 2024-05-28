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
#ifndef LLM_OS_Devices_Portable_H
#define LLM_OS_Devices_Portable_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Devices.Portable.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Portable_IServiceDeviceStatics<D>::GetDeviceSelector(llm::OS::Devices::Portable::ServiceDeviceType const& serviceType) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Portable::IServiceDeviceStatics)->GetDeviceSelector(static_cast<int32_t>(serviceType), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Portable_IServiceDeviceStatics<D>::GetDeviceSelectorFromServiceId(llm::guid const& serviceId) const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Portable::IServiceDeviceStatics)->GetDeviceSelectorFromServiceId(impl::bind_in(serviceId), &selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_Devices_Portable_IStorageDeviceStatics<D>::FromId(param::hstring const& deviceId) const
    {
        void* deviceRoot{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Portable::IStorageDeviceStatics)->FromId(*(void**)(&deviceId), &deviceRoot));
        return llm::OS::Storage::StorageFolder{ deviceRoot, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Portable_IStorageDeviceStatics<D>::GetDeviceSelector() const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Portable::IStorageDeviceStatics)->GetDeviceSelector(&selector));
        return hstring{ selector, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Portable::IServiceDeviceStatics> : produce_base<D, llm::OS::Devices::Portable::IServiceDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(int32_t serviceType, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::OS::Devices::Portable::ServiceDeviceType const*>(&serviceType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelectorFromServiceId(llm::guid serviceId, void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelectorFromServiceId(*reinterpret_cast<llm::guid const*>(&serviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Portable::IStorageDeviceStatics> : produce_base<D, llm::OS::Devices::Portable::IStorageDeviceStatics>
    {
        int32_t __stdcall FromId(void* deviceId, void** deviceRoot) noexcept final try
        {
            clear_abi(deviceRoot);
            typename D::abi_guard guard(this->shim());
            *deviceRoot = detach_from<llm::OS::Storage::StorageFolder>(this->shim().FromId(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Portable
{
    inline auto ServiceDevice::GetDeviceSelector(llm::OS::Devices::Portable::ServiceDeviceType const& serviceType)
    {
        return impl::call_factory<ServiceDevice, IServiceDeviceStatics>([&](IServiceDeviceStatics const& f) { return f.GetDeviceSelector(serviceType); });
    }
    inline auto ServiceDevice::GetDeviceSelectorFromServiceId(llm::guid const& serviceId)
    {
        return impl::call_factory<ServiceDevice, IServiceDeviceStatics>([&](IServiceDeviceStatics const& f) { return f.GetDeviceSelectorFromServiceId(serviceId); });
    }
    inline auto StorageDevice::FromId(param::hstring const& deviceId)
    {
        return impl::call_factory<StorageDevice, IStorageDeviceStatics>([&](IStorageDeviceStatics const& f) { return f.FromId(deviceId); });
    }
    inline auto StorageDevice::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IStorageDeviceStatics const&), StorageDevice, IStorageDeviceStatics>([](IStorageDeviceStatics const& f) { return f.GetDeviceSelector(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Portable::IServiceDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Portable::IStorageDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Portable::ServiceDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Portable::StorageDevice> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
