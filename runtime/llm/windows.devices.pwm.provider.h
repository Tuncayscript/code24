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
#ifndef LLM_OS_Devices_Pwm_Provider_H
#define LLM_OS_Devices_Pwm_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Pwm.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Pwm.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::PinCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->get_PinCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::ActualFrequency() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->get_ActualFrequency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::SetDesiredFrequency(double frequency) const
    {
        double result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->SetDesiredFrequency(frequency, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::MaxFrequency() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->get_MaxFrequency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::MinFrequency() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->get_MinFrequency(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::AcquirePin(int32_t pin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->AcquirePin(pin));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::ReleasePin(int32_t pin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->ReleasePin(pin));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::EnablePin(int32_t pin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->EnablePin(pin));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::DisablePin(int32_t pin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->DisablePin(pin));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Pwm_Provider_IPwmControllerProvider<D>::SetPulseParameters(int32_t pin, double dutyCycle, bool invertPolarity) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider)->SetPulseParameters(pin, dutyCycle, invertPolarity));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>) consume_Windows_Devices_Pwm_Provider_IPwmProvider<D>::GetControllers() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Pwm::Provider::IPwmProvider)->GetControllers(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>{ result, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, llm::OS::Devices::Pwm::Provider::IPwmControllerProvider> : produce_base<D, llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>
    {
        int32_t __stdcall get_PinCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PinCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActualFrequency(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().ActualFrequency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDesiredFrequency(double frequency, double* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<double>(this->shim().SetDesiredFrequency(frequency));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxFrequency(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MaxFrequency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinFrequency(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().MinFrequency());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcquirePin(int32_t pin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcquirePin(pin);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReleasePin(int32_t pin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePin(pin);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnablePin(int32_t pin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnablePin(pin);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisablePin(int32_t pin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisablePin(pin);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPulseParameters(int32_t pin, double dutyCycle, bool invertPolarity) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPulseParameters(pin, dutyCycle, invertPolarity);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Devices::Pwm::Provider::IPwmProvider> : produce_base<D, llm::OS::Devices::Pwm::Provider::IPwmProvider>
    {
        int32_t __stdcall GetControllers(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>>(this->shim().GetControllers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Devices::Pwm::Provider
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Pwm::Provider::IPwmProvider> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
