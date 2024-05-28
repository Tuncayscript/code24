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
#ifndef LLM_OS_Devices_H
#define LLM_OS_Devices_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Devices.Adc.Provider.2.h"
#include "llm/impl/Windows.Devices.Gpio.Provider.2.h"
#include "llm/impl/Windows.Devices.I2c.Provider.2.h"
#include "llm/impl/Windows.Devices.Pwm.Provider.2.h"
#include "llm/impl/Windows.Devices.Spi.Provider.2.h"
#include "llm/impl/Windows.Devices.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Adc::Provider::IAdcControllerProvider) consume_Windows_Devices_ILowLevelDevicesAggregateProvider<D>::AdcControllerProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesAggregateProvider)->get_AdcControllerProvider(&value));
        return llm::OS::Devices::Adc::Provider::IAdcControllerProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Pwm::Provider::IPwmControllerProvider) consume_Windows_Devices_ILowLevelDevicesAggregateProvider<D>::PwmControllerProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesAggregateProvider)->get_PwmControllerProvider(&value));
        return llm::OS::Devices::Pwm::Provider::IPwmControllerProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Gpio::Provider::IGpioControllerProvider) consume_Windows_Devices_ILowLevelDevicesAggregateProvider<D>::GpioControllerProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesAggregateProvider)->get_GpioControllerProvider(&value));
        return llm::OS::Devices::Gpio::Provider::IGpioControllerProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::I2c::Provider::II2cControllerProvider) consume_Windows_Devices_ILowLevelDevicesAggregateProvider<D>::I2cControllerProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesAggregateProvider)->get_I2cControllerProvider(&value));
        return llm::OS::Devices::I2c::Provider::II2cControllerProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Spi::Provider::ISpiControllerProvider) consume_Windows_Devices_ILowLevelDevicesAggregateProvider<D>::SpiControllerProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesAggregateProvider)->get_SpiControllerProvider(&value));
        return llm::OS::Devices::Spi::Provider::ISpiControllerProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::LowLevelDevicesAggregateProvider) consume_Windows_Devices_ILowLevelDevicesAggregateProviderFactory<D>::Create(llm::OS::Devices::Adc::Provider::IAdcControllerProvider const& adc, llm::OS::Devices::Pwm::Provider::IPwmControllerProvider const& pwm, llm::OS::Devices::Gpio::Provider::IGpioControllerProvider const& gpio, llm::OS::Devices::I2c::Provider::II2cControllerProvider const& i2c, llm::OS::Devices::Spi::Provider::ISpiControllerProvider const& spi) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory)->Create(*(void**)(&adc), *(void**)(&pwm), *(void**)(&gpio), *(void**)(&i2c), *(void**)(&spi), &value));
        return llm::OS::Devices::LowLevelDevicesAggregateProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::ILowLevelDevicesAggregateProvider) consume_Windows_Devices_ILowLevelDevicesControllerStatics<D>::DefaultProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesControllerStatics)->get_DefaultProvider(&value));
        return llm::OS::Devices::ILowLevelDevicesAggregateProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_ILowLevelDevicesControllerStatics<D>::DefaultProvider(llm::OS::Devices::ILowLevelDevicesAggregateProvider const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::ILowLevelDevicesControllerStatics)->put_DefaultProvider(*(void**)(&value)));
    }
    template <typename D>
    struct produce<D, llm::OS::Devices::ILowLevelDevicesAggregateProvider> : produce_base<D, llm::OS::Devices::ILowLevelDevicesAggregateProvider>
    {
        int32_t __stdcall get_AdcControllerProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Adc::Provider::IAdcControllerProvider>(this->shim().AdcControllerProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PwmControllerProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider>(this->shim().PwmControllerProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GpioControllerProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider>(this->shim().GpioControllerProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_I2cControllerProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::I2c::Provider::II2cControllerProvider>(this->shim().I2cControllerProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpiControllerProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Spi::Provider::ISpiControllerProvider>(this->shim().SpiControllerProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory> : produce_base<D, llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory>
    {
        int32_t __stdcall Create(void* adc, void* pwm, void* gpio, void* i2c, void* spi, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::LowLevelDevicesAggregateProvider>(this->shim().Create(*reinterpret_cast<llm::OS::Devices::Adc::Provider::IAdcControllerProvider const*>(&adc), *reinterpret_cast<llm::OS::Devices::Pwm::Provider::IPwmControllerProvider const*>(&pwm), *reinterpret_cast<llm::OS::Devices::Gpio::Provider::IGpioControllerProvider const*>(&gpio), *reinterpret_cast<llm::OS::Devices::I2c::Provider::II2cControllerProvider const*>(&i2c), *reinterpret_cast<llm::OS::Devices::Spi::Provider::ISpiControllerProvider const*>(&spi)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::ILowLevelDevicesController> : produce_base<D, llm::OS::Devices::ILowLevelDevicesController>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::ILowLevelDevicesControllerStatics> : produce_base<D, llm::OS::Devices::ILowLevelDevicesControllerStatics>
    {
        int32_t __stdcall get_DefaultProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::ILowLevelDevicesAggregateProvider>(this->shim().DefaultProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DefaultProvider(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultProvider(*reinterpret_cast<llm::OS::Devices::ILowLevelDevicesAggregateProvider const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices
{
    inline LowLevelDevicesAggregateProvider::LowLevelDevicesAggregateProvider(llm::OS::Devices::Adc::Provider::IAdcControllerProvider const& adc, llm::OS::Devices::Pwm::Provider::IPwmControllerProvider const& pwm, llm::OS::Devices::Gpio::Provider::IGpioControllerProvider const& gpio, llm::OS::Devices::I2c::Provider::II2cControllerProvider const& i2c, llm::OS::Devices::Spi::Provider::ISpiControllerProvider const& spi) :
        LowLevelDevicesAggregateProvider(impl::call_factory<LowLevelDevicesAggregateProvider, ILowLevelDevicesAggregateProviderFactory>([&](ILowLevelDevicesAggregateProviderFactory const& f) { return f.Create(adc, pwm, gpio, i2c, spi); }))
    {
    }
    inline auto LowLevelDevicesController::DefaultProvider()
    {
        return impl::call_factory_cast<llm::OS::Devices::ILowLevelDevicesAggregateProvider(*)(ILowLevelDevicesControllerStatics const&), LowLevelDevicesController, ILowLevelDevicesControllerStatics>([](ILowLevelDevicesControllerStatics const& f) { return f.DefaultProvider(); });
    }
    inline auto LowLevelDevicesController::DefaultProvider(llm::OS::Devices::ILowLevelDevicesAggregateProvider const& value)
    {
        impl::call_factory<LowLevelDevicesController, ILowLevelDevicesControllerStatics>([&](ILowLevelDevicesControllerStatics const& f) { return f.DefaultProvider(value); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::ILowLevelDevicesAggregateProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::ILowLevelDevicesAggregateProviderFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::ILowLevelDevicesController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::ILowLevelDevicesControllerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::LowLevelDevicesAggregateProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::LowLevelDevicesController> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
