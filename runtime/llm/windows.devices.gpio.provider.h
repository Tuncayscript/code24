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
#ifndef LLM_OS_Devices_Gpio_Provider_H
#define LLM_OS_Devices_Gpio_Provider_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Gpio.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Gpio.Provider.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Gpio_Provider_IGpioControllerProvider<D>::PinCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioControllerProvider)->get_PinCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::IGpioPinProvider) consume_Windows_Devices_Gpio_Provider_IGpioControllerProvider<D>::OpenPinProvider(int32_t pin, llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode const& sharingMode) const
    {
        void* gpioPinProvider{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioControllerProvider)->OpenPinProvider(pin, static_cast<int32_t>(sharingMode), &gpioPinProvider));
        return llm::OS::Devices::Gpio::Provider::IGpioPinProvider{ gpioPinProvider, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::ValueChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Gpio::Provider::IGpioPinProvider, llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->add_ValueChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::ValueChanged_revoker consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::ValueChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Gpio::Provider::IGpioPinProvider, llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ValueChanged_revoker>(this, ValueChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::ValueChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->remove_ValueChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::DebounceTimeout() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->get_DebounceTimeout(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::DebounceTimeout(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->put_DebounceTimeout(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::PinNumber() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->get_PinNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::SharingMode() const
    {
        llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->get_SharingMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::IsDriveModeSupported(llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode const& driveMode) const
    {
        bool supported{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->IsDriveModeSupported(static_cast<int32_t>(driveMode), &supported));
        return supported;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::GetDriveMode() const
    {
        llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->GetDriveMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::SetDriveMode(llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->SetDriveMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::Write(llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->Write(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue) consume_Windows_Devices_Gpio_Provider_IGpioPinProvider<D>::Read() const
    {
        llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProvider)->Read(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge) consume_Windows_Devices_Gpio_Provider_IGpioPinProviderValueChangedEventArgs<D>::Edge() const
    {
        llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs)->get_Edge(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs) consume_Windows_Devices_Gpio_Provider_IGpioPinProviderValueChangedEventArgsFactory<D>::Create(llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge const& edge) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory)->Create(static_cast<int32_t>(edge), &value));
        return llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>) consume_Windows_Devices_Gpio_Provider_IGpioProvider<D>::GetControllers() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Gpio::Provider::IGpioProvider)->GetControllers(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>{ result, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, llm::OS::Devices::Gpio::Provider::IGpioControllerProvider> : produce_base<D, llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>
    {
        int32_t __stdcall get_PinCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PinCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenPinProvider(int32_t pin, int32_t sharingMode, void** gpioPinProvider) noexcept final try
        {
            clear_abi(gpioPinProvider);
            typename D::abi_guard guard(this->shim());
            *gpioPinProvider = detach_from<llm::OS::Devices::Gpio::Provider::IGpioPinProvider>(this->shim().OpenPinProvider(pin, *reinterpret_cast<llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode const*>(&sharingMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Devices::Gpio::Provider::IGpioPinProvider> : produce_base<D, llm::OS::Devices::Gpio::Provider::IGpioPinProvider>
    {
        int32_t __stdcall add_ValueChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ValueChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Gpio::Provider::IGpioPinProvider, llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ValueChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ValueChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_DebounceTimeout(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DebounceTimeout());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DebounceTimeout(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DebounceTimeout(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PinNumber(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PinNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Gpio::Provider::ProviderGpioSharingMode>(this->shim().SharingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsDriveModeSupported(int32_t driveMode, bool* supported) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *supported = detach_from<bool>(this->shim().IsDriveModeSupported(*reinterpret_cast<llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode const*>(&driveMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDriveMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode>(this->shim().GetDriveMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDriveMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDriveMode(*reinterpret_cast<llm::OS::Devices::Gpio::Provider::ProviderGpioPinDriveMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Write(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Write(*reinterpret_cast<llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Read(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Gpio::Provider::ProviderGpioPinValue>(this->shim().Read());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> : produce_base<D, llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs>
    {
        int32_t __stdcall get_Edge(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge>(this->shim().Edge());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory> : produce_base<D, llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory>
    {
        int32_t __stdcall Create(int32_t edge, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge const*>(&edge)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Gpio::Provider::IGpioProvider> : produce_base<D, llm::OS::Devices::Gpio::Provider::IGpioProvider>
    {
        int32_t __stdcall GetControllers(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>>(this->shim().GetControllers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::Devices::Gpio::Provider
{
    inline GpioPinProviderValueChangedEventArgs::GpioPinProviderValueChangedEventArgs(llm::OS::Devices::Gpio::Provider::ProviderGpioPinEdge const& edge) :
        GpioPinProviderValueChangedEventArgs(impl::call_factory<GpioPinProviderValueChangedEventArgs, IGpioPinProviderValueChangedEventArgsFactory>([&](IGpioPinProviderValueChangedEventArgsFactory const& f) { return f.Create(edge); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Gpio::Provider::IGpioPinProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Gpio::Provider::IGpioPinProviderValueChangedEventArgsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Gpio::Provider::IGpioProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Gpio::Provider::GpioPinProviderValueChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
