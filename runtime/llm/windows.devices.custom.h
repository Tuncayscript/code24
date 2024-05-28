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
#ifndef LLM_OS_Devices_Custom_H
#define LLM_OS_Devices_Custom_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Custom.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_Devices_Custom_ICustomDevice<D>::InputStream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::ICustomDevice)->get_InputStream(&value));
        return llm::OS::Storage::Streams::IInputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IOutputStream) consume_Windows_Devices_Custom_ICustomDevice<D>::OutputStream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::ICustomDevice)->get_OutputStream(&value));
        return llm::OS::Storage::Streams::IOutputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_Devices_Custom_ICustomDevice<D>::SendIOControlAsync(llm::OS::Devices::Custom::IIOControlCode const& ioControlCode, llm::OS::Storage::Streams::IBuffer const& inputBuffer, llm::OS::Storage::Streams::IBuffer const& outputBuffer) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::ICustomDevice)->SendIOControlAsync(*(void**)(&ioControlCode), *(void**)(&inputBuffer), *(void**)(&outputBuffer), &operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Devices_Custom_ICustomDevice<D>::TrySendIOControlAsync(llm::OS::Devices::Custom::IIOControlCode const& ioControlCode, llm::OS::Storage::Streams::IBuffer const& inputBuffer, llm::OS::Storage::Streams::IBuffer const& outputBuffer) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::ICustomDevice)->TrySendIOControlAsync(*(void**)(&ioControlCode), *(void**)(&inputBuffer), *(void**)(&outputBuffer), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Custom_ICustomDeviceStatics<D>::GetDeviceSelector(llm::guid const& classGuid) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::ICustomDeviceStatics)->GetDeviceSelector(impl::bind_in(classGuid), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Custom::CustomDevice>) consume_Windows_Devices_Custom_ICustomDeviceStatics<D>::FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::Custom::DeviceAccessMode const& desiredAccess, llm::OS::Devices::Custom::DeviceSharingMode const& sharingMode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::ICustomDeviceStatics)->FromIdAsync(*(void**)(&deviceId), static_cast<int32_t>(desiredAccess), static_cast<int32_t>(sharingMode), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Custom::CustomDevice>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Custom::IOControlAccessMode) consume_Windows_Devices_Custom_IIOControlCode<D>::AccessMode() const
    {
        llm::OS::Devices::Custom::IOControlAccessMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IIOControlCode)->get_AccessMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Custom::IOControlBufferingMethod) consume_Windows_Devices_Custom_IIOControlCode<D>::BufferingMethod() const
    {
        llm::OS::Devices::Custom::IOControlBufferingMethod value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IIOControlCode)->get_BufferingMethod(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Custom_IIOControlCode<D>::Function() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IIOControlCode)->get_Function(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Custom_IIOControlCode<D>::DeviceType() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IIOControlCode)->get_DeviceType(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Custom_IIOControlCode<D>::ControlCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IIOControlCode)->get_ControlCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Custom::IOControlCode) consume_Windows_Devices_Custom_IIOControlCodeFactory<D>::CreateIOControlCode(uint16_t deviceType, uint16_t function, llm::OS::Devices::Custom::IOControlAccessMode const& accessMode, llm::OS::Devices::Custom::IOControlBufferingMethod const& bufferingMethod) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IIOControlCodeFactory)->CreateIOControlCode(deviceType, function, static_cast<int32_t>(accessMode), static_cast<int32_t>(bufferingMethod), &instance));
        return llm::OS::Devices::Custom::IOControlCode{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Custom_IKnownDeviceTypesStatics<D>::Unknown() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Custom::IKnownDeviceTypesStatics)->get_Unknown(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Custom::ICustomDevice> : produce_base<D, llm::OS::Devices::Custom::ICustomDevice>
    {
        int32_t __stdcall get_InputStream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().InputStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OutputStream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IOutputStream>(this->shim().OutputStream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendIOControlAsync(void* ioControlCode, void* inputBuffer, void* outputBuffer, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().SendIOControlAsync(*reinterpret_cast<llm::OS::Devices::Custom::IIOControlCode const*>(&ioControlCode), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&inputBuffer), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&outputBuffer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySendIOControlAsync(void* ioControlCode, void* inputBuffer, void* outputBuffer, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TrySendIOControlAsync(*reinterpret_cast<llm::OS::Devices::Custom::IIOControlCode const*>(&ioControlCode), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&inputBuffer), *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&outputBuffer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Custom::ICustomDeviceStatics> : produce_base<D, llm::OS::Devices::Custom::ICustomDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(llm::guid classGuid, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::guid const*>(&classGuid)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, int32_t desiredAccess, int32_t sharingMode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Custom::CustomDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Devices::Custom::DeviceAccessMode const*>(&desiredAccess), *reinterpret_cast<llm::OS::Devices::Custom::DeviceSharingMode const*>(&sharingMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Custom::IIOControlCode> : produce_base<D, llm::OS::Devices::Custom::IIOControlCode>
    {
        int32_t __stdcall get_AccessMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Custom::IOControlAccessMode>(this->shim().AccessMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BufferingMethod(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Custom::IOControlBufferingMethod>(this->shim().BufferingMethod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Function(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().Function());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceType(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().DeviceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ControlCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ControlCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Custom::IIOControlCodeFactory> : produce_base<D, llm::OS::Devices::Custom::IIOControlCodeFactory>
    {
        int32_t __stdcall CreateIOControlCode(uint16_t deviceType, uint16_t function, int32_t accessMode, int32_t bufferingMethod, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::Devices::Custom::IOControlCode>(this->shim().CreateIOControlCode(deviceType, function, *reinterpret_cast<llm::OS::Devices::Custom::IOControlAccessMode const*>(&accessMode), *reinterpret_cast<llm::OS::Devices::Custom::IOControlBufferingMethod const*>(&bufferingMethod)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Custom::IKnownDeviceTypesStatics> : produce_base<D, llm::OS::Devices::Custom::IKnownDeviceTypesStatics>
    {
        int32_t __stdcall get_Unknown(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().Unknown());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Custom
{
    inline auto CustomDevice::GetDeviceSelector(llm::guid const& classGuid)
    {
        return impl::call_factory<CustomDevice, ICustomDeviceStatics>([&](ICustomDeviceStatics const& f) { return f.GetDeviceSelector(classGuid); });
    }
    inline auto CustomDevice::FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::Custom::DeviceAccessMode const& desiredAccess, llm::OS::Devices::Custom::DeviceSharingMode const& sharingMode)
    {
        return impl::call_factory<CustomDevice, ICustomDeviceStatics>([&](ICustomDeviceStatics const& f) { return f.FromIdAsync(deviceId, desiredAccess, sharingMode); });
    }
    inline IOControlCode::IOControlCode(uint16_t deviceType, uint16_t function, llm::OS::Devices::Custom::IOControlAccessMode const& accessMode, llm::OS::Devices::Custom::IOControlBufferingMethod const& bufferingMethod) :
        IOControlCode(impl::call_factory<IOControlCode, IIOControlCodeFactory>([&](IIOControlCodeFactory const& f) { return f.CreateIOControlCode(deviceType, function, accessMode, bufferingMethod); }))
    {
    }
    inline auto KnownDeviceTypes::Unknown()
    {
        return impl::call_factory_cast<uint16_t(*)(IKnownDeviceTypesStatics const&), KnownDeviceTypes, IKnownDeviceTypesStatics>([](IKnownDeviceTypesStatics const& f) { return f.Unknown(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Custom::ICustomDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::ICustomDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::IIOControlCode> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::IIOControlCodeFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::IKnownDeviceTypesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::CustomDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::IOControlCode> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Custom::KnownDeviceTypes> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
