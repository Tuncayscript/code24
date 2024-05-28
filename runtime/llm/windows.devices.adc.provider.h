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
#ifndef LLM_OS_Devices_Adc_Provider_H
#define LLM_OS_Devices_Adc_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Adc.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Adc.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::ChannelCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->get_ChannelCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::ResolutionInBits() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->get_ResolutionInBits(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::MinValue() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->get_MinValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::MaxValue() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->get_MaxValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::ChannelMode() const
    {
        llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->get_ChannelMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::ChannelMode(llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->put_ChannelMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::IsChannelModeSupported(llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode const& channelMode) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->IsChannelModeSupported(static_cast<int32_t>(channelMode), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::AcquireChannel(int32_t channel) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->AcquireChannel(channel));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::ReleaseChannel(int32_t channel) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->ReleaseChannel(channel));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Adc_Provider_IAdcControllerProvider<D>::ReadValue(int32_t channelNumber) const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcControllerProvider)->ReadValue(channelNumber, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>) consume_Windows_Devices_Adc_Provider_IAdcProvider<D>::GetControllers() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Adc::Provider::IAdcProvider)->GetControllers(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>{ result, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, llm::OS::Devices::Adc::Provider::IAdcControllerProvider> : produce_base<D, llm::OS::Devices::Adc::Provider::IAdcControllerProvider>
    {
        int32_t __stdcall get_ChannelCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ChannelCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResolutionInBits(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ResolutionInBits());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinValue(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MinValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxValue(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode>(this->shim().ChannelMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ChannelMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ChannelMode(*reinterpret_cast<llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsChannelModeSupported(int32_t channelMode, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsChannelModeSupported(*reinterpret_cast<llm::OS::Devices::Adc::Provider::ProviderAdcChannelMode const*>(&channelMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquireChannel(int32_t channel) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcquireChannel(channel);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReleaseChannel(int32_t channel) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleaseChannel(channel);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadValue(int32_t channelNumber, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().ReadValue(channelNumber));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Devices::Adc::Provider::IAdcProvider> : produce_base<D, llm::OS::Devices::Adc::Provider::IAdcProvider>
    {
        int32_t __stdcall GetControllers(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>>(this->shim().GetControllers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Devices::Adc::Provider
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Adc::Provider::IAdcControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Adc::Provider::IAdcProvider> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
