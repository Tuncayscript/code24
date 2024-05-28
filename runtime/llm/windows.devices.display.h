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
#ifndef LLM_OS_Devices_Display_H
#define LLM_OS_Devices_Display_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.2.h"
#include "llm/impl/Windows.Devices.Display.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_IDisplayMonitor<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_IDisplayMonitor<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorConnectionKind) consume_Windows_Devices_Display_IDisplayMonitor<D>::ConnectionKind() const
    {
        llm::OS::Devices::Display::DisplayMonitorConnectionKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_ConnectionKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorPhysicalConnectorKind) consume_Windows_Devices_Display_IDisplayMonitor<D>::PhysicalConnector() const
    {
        llm::OS::Devices::Display::DisplayMonitorPhysicalConnectorKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_PhysicalConnector(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_IDisplayMonitor<D>::DisplayAdapterDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_DisplayAdapterDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DisplayAdapterId) consume_Windows_Devices_Display_IDisplayMonitor<D>::DisplayAdapterId() const
    {
        llm::OS::Graphics::DisplayAdapterId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_DisplayAdapterId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Display_IDisplayMonitor<D>::DisplayAdapterTargetId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_DisplayAdapterTargetId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Display::DisplayMonitorUsageKind) consume_Windows_Devices_Display_IDisplayMonitor<D>::UsageKind() const
    {
        llm::OS::Devices::Display::DisplayMonitorUsageKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_UsageKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) consume_Windows_Devices_Display_IDisplayMonitor<D>::NativeResolutionInRawPixels() const
    {
        llm::OS::Graphics::SizeInt32 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_NativeResolutionInRawPixels(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Size>) consume_Windows_Devices_Display_IDisplayMonitor<D>::PhysicalSizeInInches() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_PhysicalSizeInInches(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Size>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Devices_Display_IDisplayMonitor<D>::RawDpiX() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_RawDpiX(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Devices_Display_IDisplayMonitor<D>::RawDpiY() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_RawDpiY(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Devices_Display_IDisplayMonitor<D>::RedPrimary() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_RedPrimary(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Devices_Display_IDisplayMonitor<D>::GreenPrimary() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_GreenPrimary(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Devices_Display_IDisplayMonitor<D>::BluePrimary() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_BluePrimary(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_Devices_Display_IDisplayMonitor<D>::WhitePoint() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_WhitePoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Devices_Display_IDisplayMonitor<D>::MaxLuminanceInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_MaxLuminanceInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Devices_Display_IDisplayMonitor<D>::MinLuminanceInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_MinLuminanceInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Devices_Display_IDisplayMonitor<D>::MaxAverageFullFrameLuminanceInNits() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->get_MaxAverageFullFrameLuminanceInNits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(com_array<uint8_t>) consume_Windows_Devices_Display_IDisplayMonitor<D>::GetDescriptor(llm::OS::Devices::Display::DisplayMonitorDescriptorKind const& descriptorKind) const
    {
        uint32_t result_impl_size{};
        uint8_t* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor)->GetDescriptor(static_cast<int32_t>(descriptorKind), &result_impl_size, &result));
        return com_array<uint8_t>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Display_IDisplayMonitor2<D>::IsDolbyVisionSupportedInHdrMode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitor2)->get_IsDolbyVisionSupportedInHdrMode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Display_IDisplayMonitorStatics<D>::GetDeviceSelector() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitorStatics)->GetDeviceSelector(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>) consume_Windows_Devices_Display_IDisplayMonitorStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitorStatics)->FromIdAsync(*(void**)(&deviceId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>) consume_Windows_Devices_Display_IDisplayMonitorStatics<D>::FromInterfaceIdAsync(param::hstring const& deviceInterfaceId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Display::IDisplayMonitorStatics)->FromInterfaceIdAsync(*(void**)(&deviceInterfaceId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::IDisplayMonitor> : produce_base<D, llm::OS::Devices::Display::IDisplayMonitor>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
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
        int32_t __stdcall get_ConnectionKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::DisplayMonitorConnectionKind>(this->shim().ConnectionKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhysicalConnector(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::DisplayMonitorPhysicalConnectorKind>(this->shim().PhysicalConnector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayAdapterDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayAdapterDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayAdapterId(struct struct_Windows_Graphics_DisplayAdapterId* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::DisplayAdapterId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DisplayAdapterId>(this->shim().DisplayAdapterId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayAdapterTargetId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().DisplayAdapterTargetId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UsageKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Display::DisplayMonitorUsageKind>(this->shim().UsageKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NativeResolutionInRawPixels(struct struct_Windows_Graphics_SizeInt32* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::SizeInt32>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::SizeInt32>(this->shim().NativeResolutionInRawPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhysicalSizeInInches(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Size>>(this->shim().PhysicalSizeInInches());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawDpiX(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RawDpiX());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RawDpiY(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RawDpiY());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedPrimary(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().RedPrimary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GreenPrimary(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().GreenPrimary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BluePrimary(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().BluePrimary());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WhitePoint(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().WhitePoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxLuminanceInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxLuminanceInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinLuminanceInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinLuminanceInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAverageFullFrameLuminanceInNits(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxAverageFullFrameLuminanceInNits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDescriptor(int32_t descriptorKind, uint32_t* __resultSize, uint8_t** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetDescriptor(*reinterpret_cast<llm::OS::Devices::Display::DisplayMonitorDescriptorKind const*>(&descriptorKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::IDisplayMonitor2> : produce_base<D, llm::OS::Devices::Display::IDisplayMonitor2>
    {
        int32_t __stdcall get_IsDolbyVisionSupportedInHdrMode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDolbyVisionSupportedInHdrMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Display::IDisplayMonitorStatics> : produce_base<D, llm::OS::Devices::Display::IDisplayMonitorStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromInterfaceIdAsync(void* deviceInterfaceId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Display::DisplayMonitor>>(this->shim().FromInterfaceIdAsync(*reinterpret_cast<hstring const*>(&deviceInterfaceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Display
{
    inline auto DisplayMonitor::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IDisplayMonitorStatics const&), DisplayMonitor, IDisplayMonitorStatics>([](IDisplayMonitorStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto DisplayMonitor::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<DisplayMonitor, IDisplayMonitorStatics>([&](IDisplayMonitorStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto DisplayMonitor::FromInterfaceIdAsync(param::hstring const& deviceInterfaceId)
    {
        return impl::call_factory<DisplayMonitor, IDisplayMonitorStatics>([&](IDisplayMonitorStatics const& f) { return f.FromInterfaceIdAsync(deviceInterfaceId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Display::IDisplayMonitor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::IDisplayMonitor2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::IDisplayMonitorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Display::DisplayMonitor> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
