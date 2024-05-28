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
#ifndef LLM_OS_Devices_Lights_H
#define LLM_OS_Devices_Lights_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.Devices.Lights.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Lights_ILamp<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILamp<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILamp<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_Devices_Lights_ILamp<D>::BrightnessLevel() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->get_BrightnessLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILamp<D>::BrightnessLevel(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->put_BrightnessLevel(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILamp<D>::IsColorSettable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->get_IsColorSettable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Lights_ILamp<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILamp<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Lights_ILamp<D>::AvailabilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Lights::Lamp, llm::OS::Devices::Lights::LampAvailabilityChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->add_AvailabilityChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Lights_ILamp<D>::AvailabilityChanged_revoker consume_Windows_Devices_Lights_ILamp<D>::AvailabilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Lights::Lamp, llm::OS::Devices::Lights::LampAvailabilityChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AvailabilityChanged_revoker>(this, AvailabilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILamp<D>::AvailabilityChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILamp)->remove_AvailabilityChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Lights_ILampArray<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Lights_ILampArray<D>::HardwareVendorId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_HardwareVendorId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Lights_ILampArray<D>::HardwareProductId() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_HardwareProductId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Devices_Lights_ILampArray<D>::HardwareVersion() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_HardwareVersion(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Lights::LampArrayKind) consume_Windows_Devices_Lights_ILampArray<D>::LampArrayKind() const
    {
        llm::OS::Devices::Lights::LampArrayKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_LampArrayKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Lights_ILampArray<D>::LampCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_LampCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Lights_ILampArray<D>::MinUpdateInterval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_MinUpdateInterval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Devices_Lights_ILampArray<D>::BoundingBox() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_BoundingBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILampArray<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Lights_ILampArray<D>::BrightnessLevel() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_BrightnessLevel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::BrightnessLevel(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->put_BrightnessLevel(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILampArray<D>::IsConnected() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_IsConnected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILampArray<D>::SupportsVirtualKeys() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->get_SupportsVirtualKeys(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Lights::LampInfo) consume_Windows_Devices_Lights_ILampArray<D>::GetLampInfo(int32_t lampIndex) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->GetLampInfo(lampIndex, &result));
        return llm::OS::Devices::Lights::LampInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<int32_t>) consume_Windows_Devices_Lights_ILampArray<D>::GetIndicesForKey(llm::OS::System::VirtualKey const& key) const
    {
        uint32_t result_impl_size{};
        int32_t* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->GetIndicesForKey(static_cast<int32_t>(key), &result_impl_size, &result));
        return com_array<int32_t>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<int32_t>) consume_Windows_Devices_Lights_ILampArray<D>::GetIndicesForPurposes(llm::OS::Devices::Lights::LampPurposes const& purposes) const
    {
        uint32_t result_impl_size{};
        int32_t* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->GetIndicesForPurposes(static_cast<uint32_t>(purposes), &result_impl_size, &result));
        return com_array<int32_t>{ result, result_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetColor(llm::OS::UI::Color const& desiredColor) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetColor(impl::bind_in(desiredColor)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetColorForIndex(int32_t lampIndex, llm::OS::UI::Color const& desiredColor) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetColorForIndex(lampIndex, impl::bind_in(desiredColor)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetSingleColorForIndices(llm::OS::UI::Color const& desiredColor, array_view<int32_t const> lampIndexes) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetSingleColorForIndices(impl::bind_in(desiredColor), lampIndexes.size(), get_abi(lampIndexes)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetColorsForIndices(array_view<llm::OS::UI::Color const> desiredColors, array_view<int32_t const> lampIndexes) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetColorsForIndices(desiredColors.size(), get_abi(desiredColors), lampIndexes.size(), get_abi(lampIndexes)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetColorsForKey(llm::OS::UI::Color const& desiredColor, llm::OS::System::VirtualKey const& key) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetColorsForKey(impl::bind_in(desiredColor), static_cast<int32_t>(key)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetColorsForKeys(array_view<llm::OS::UI::Color const> desiredColors, array_view<llm::OS::System::VirtualKey const> keys) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetColorsForKeys(desiredColors.size(), get_abi(desiredColors), keys.size(), get_abi(keys)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray<D>::SetColorsForPurposes(llm::OS::UI::Color const& desiredColor, llm::OS::Devices::Lights::LampPurposes const& purposes) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SetColorsForPurposes(impl::bind_in(desiredColor), static_cast<uint32_t>(purposes)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Lights_ILampArray<D>::SendMessageAsync(int32_t messageId, llm::OS::Storage::Streams::IBuffer const& message) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->SendMessageAsync(messageId, *(void**)(&message), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>) consume_Windows_Devices_Lights_ILampArray<D>::RequestMessageAsync(int32_t messageId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray)->RequestMessageAsync(messageId, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILampArray2<D>::IsAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray2)->get_IsAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Lights_ILampArray2<D>::AvailabilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Lights::LampArray, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray2)->add_AvailabilityChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Lights_ILampArray2<D>::AvailabilityChanged_revoker consume_Windows_Devices_Lights_ILampArray2<D>::AvailabilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Lights::LampArray, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AvailabilityChanged_revoker>(this, AvailabilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Lights_ILampArray2<D>::AvailabilityChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArray2)->remove_AvailabilityChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Lights_ILampArrayStatics<D>::GetDeviceSelector() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArrayStatics)->GetDeviceSelector(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::LampArray>) consume_Windows_Devices_Lights_ILampArrayStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampArrayStatics)->FromIdAsync(*(void**)(&deviceId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::LampArray>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Lights_ILampAvailabilityChangedEventArgs<D>::IsAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampAvailabilityChangedEventArgs)->get_IsAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Lights_ILampInfo<D>::Index() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_Index(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Lights::LampPurposes) consume_Windows_Devices_Lights_ILampInfo<D>::Purposes() const
    {
        llm::OS::Devices::Lights::LampPurposes value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_Purposes(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_Devices_Lights_ILampInfo<D>::Position() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_Position(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Lights_ILampInfo<D>::RedLevelCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_RedLevelCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Lights_ILampInfo<D>::GreenLevelCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_GreenLevelCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Lights_ILampInfo<D>::BlueLevelCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_BlueLevelCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Lights_ILampInfo<D>::GainLevelCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_GainLevelCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_Devices_Lights_ILampInfo<D>::FixedColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_FixedColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Lights_ILampInfo<D>::GetNearestSupportedColor(llm::OS::UI::Color const& desiredColor) const
    {
        llm::OS::UI::Color result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->GetNearestSupportedColor(impl::bind_in(desiredColor), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Lights_ILampInfo<D>::UpdateLatency() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampInfo)->get_UpdateLatency(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Lights_ILampStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>) consume_Windows_Devices_Lights_ILampStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampStatics)->FromIdAsync(*(void**)(&deviceId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>) consume_Windows_Devices_Lights_ILampStatics<D>::GetDefaultAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Lights::ILampStatics)->GetDefaultAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILamp> : produce_base<D, llm::OS::Devices::Lights::ILamp>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BrightnessLevel(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BrightnessLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BrightnessLevel(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BrightnessLevel(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsColorSettable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsColorSettable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AvailabilityChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AvailabilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Lights::Lamp, llm::OS::Devices::Lights::LampAvailabilityChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailabilityChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailabilityChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILampArray> : produce_base<D, llm::OS::Devices::Lights::ILampArray>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareVendorId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().HardwareVendorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareProductId(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().HardwareProductId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HardwareVersion(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().HardwareVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LampArrayKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Lights::LampArrayKind>(this->shim().LampArrayKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LampCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().LampCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinUpdateInterval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().MinUpdateInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BoundingBox(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().BoundingBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BrightnessLevel(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().BrightnessLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BrightnessLevel(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BrightnessLevel(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsConnected(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConnected());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportsVirtualKeys(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SupportsVirtualKeys());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLampInfo(int32_t lampIndex, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Lights::LampInfo>(this->shim().GetLampInfo(lampIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIndicesForKey(int32_t key, uint32_t* __resultSize, int32_t** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetIndicesForKey(*reinterpret_cast<llm::OS::System::VirtualKey const*>(&key)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIndicesForPurposes(uint32_t purposes, uint32_t* __resultSize, int32_t** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            std::tie(*__resultSize, *result) = detach_abi(this->shim().GetIndicesForPurposes(*reinterpret_cast<llm::OS::Devices::Lights::LampPurposes const*>(&purposes)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColor(struct struct_Windows_UI_Color desiredColor) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColor(*reinterpret_cast<llm::OS::UI::Color const*>(&desiredColor));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorForIndex(int32_t lampIndex, struct struct_Windows_UI_Color desiredColor) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorForIndex(lampIndex, *reinterpret_cast<llm::OS::UI::Color const*>(&desiredColor));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSingleColorForIndices(struct struct_Windows_UI_Color desiredColor, uint32_t __lampIndexesSize, int32_t* lampIndexes) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSingleColorForIndices(*reinterpret_cast<llm::OS::UI::Color const*>(&desiredColor), array_view<int32_t const>(reinterpret_cast<int32_t const *>(lampIndexes), reinterpret_cast<int32_t const *>(lampIndexes) + __lampIndexesSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorsForIndices(uint32_t __desiredColorsSize, struct struct_Windows_UI_Color* desiredColors, uint32_t __lampIndexesSize, int32_t* lampIndexes) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorsForIndices(array_view<llm::OS::UI::Color const>(reinterpret_cast<llm::OS::UI::Color const *>(desiredColors), reinterpret_cast<llm::OS::UI::Color const *>(desiredColors) + __desiredColorsSize), array_view<int32_t const>(reinterpret_cast<int32_t const *>(lampIndexes), reinterpret_cast<int32_t const *>(lampIndexes) + __lampIndexesSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorsForKey(struct struct_Windows_UI_Color desiredColor, int32_t key) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorsForKey(*reinterpret_cast<llm::OS::UI::Color const*>(&desiredColor), *reinterpret_cast<llm::OS::System::VirtualKey const*>(&key));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorsForKeys(uint32_t __desiredColorsSize, struct struct_Windows_UI_Color* desiredColors, uint32_t __keysSize, int32_t* keys) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorsForKeys(array_view<llm::OS::UI::Color const>(reinterpret_cast<llm::OS::UI::Color const *>(desiredColors), reinterpret_cast<llm::OS::UI::Color const *>(desiredColors) + __desiredColorsSize), array_view<llm::OS::System::VirtualKey const>(reinterpret_cast<llm::OS::System::VirtualKey const *>(keys), reinterpret_cast<llm::OS::System::VirtualKey const *>(keys) + __keysSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorsForPurposes(struct struct_Windows_UI_Color desiredColor, uint32_t purposes) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorsForPurposes(*reinterpret_cast<llm::OS::UI::Color const*>(&desiredColor), *reinterpret_cast<llm::OS::Devices::Lights::LampPurposes const*>(&purposes));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendMessageAsync(int32_t messageId, void* message, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SendMessageAsync(messageId, *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestMessageAsync(int32_t messageId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>>(this->shim().RequestMessageAsync(messageId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILampArray2> : produce_base<D, llm::OS::Devices::Lights::ILampArray2>
    {
        int32_t __stdcall get_IsAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AvailabilityChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AvailabilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Lights::LampArray, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailabilityChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailabilityChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILampArrayStatics> : produce_base<D, llm::OS::Devices::Lights::ILampArrayStatics>
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
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::LampArray>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILampAvailabilityChangedEventArgs> : produce_base<D, llm::OS::Devices::Lights::ILampAvailabilityChangedEventArgs>
    {
        int32_t __stdcall get_IsAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILampInfo> : produce_base<D, llm::OS::Devices::Lights::ILampInfo>
    {
        int32_t __stdcall get_Index(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Index());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Purposes(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Lights::LampPurposes>(this->shim().Purposes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Position(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Position());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedLevelCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RedLevelCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GreenLevelCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().GreenLevelCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BlueLevelCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().BlueLevelCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GainLevelCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().GainLevelCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FixedColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().FixedColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNearestSupportedColor(struct struct_Windows_UI_Color desiredColor, struct struct_Windows_UI_Color* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Color>(this->shim().GetNearestSupportedColor(*reinterpret_cast<llm::OS::UI::Color const*>(&desiredColor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateLatency(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().UpdateLatency());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Lights::ILampStatics> : produce_base<D, llm::OS::Devices::Lights::ILampStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDefaultAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>>(this->shim().GetDefaultAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Lights
{
    constexpr auto operator|(LampPurposes const left, LampPurposes const right) noexcept
    {
        return static_cast<LampPurposes>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(LampPurposes& left, LampPurposes const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(LampPurposes const left, LampPurposes const right) noexcept
    {
        return static_cast<LampPurposes>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(LampPurposes& left, LampPurposes const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(LampPurposes const value) noexcept
    {
        return static_cast<LampPurposes>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(LampPurposes const left, LampPurposes const right) noexcept
    {
        return static_cast<LampPurposes>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(LampPurposes& left, LampPurposes const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto Lamp::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(ILampStatics const&), Lamp, ILampStatics>([](ILampStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto Lamp::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<Lamp, ILampStatics>([&](ILampStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto Lamp::GetDefaultAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Lights::Lamp>(*)(ILampStatics const&), Lamp, ILampStatics>([](ILampStatics const& f) { return f.GetDefaultAsync(); });
    }
    inline auto LampArray::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(ILampArrayStatics const&), LampArray, ILampArrayStatics>([](ILampArrayStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto LampArray::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<LampArray, ILampArrayStatics>([&](ILampArrayStatics const& f) { return f.FromIdAsync(deviceId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Lights::ILamp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::ILampArray> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::ILampArray2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::ILampArrayStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::ILampAvailabilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::ILampInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::ILampStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::Lamp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::LampArray> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::LampAvailabilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Lights::LampInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
