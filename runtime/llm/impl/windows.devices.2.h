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
#ifndef LLM_OS_Devices_2_H
#define LLM_OS_Devices_2_H
#include "llm/impl/Windows.Devices.Adc.Provider.1.h"
#include "llm/impl/Windows.Devices.Gpio.Provider.1.h"
#include "llm/impl/Windows.Devices.I2c.Provider.1.h"
#include "llm/impl/Windows.Devices.Pwm.Provider.1.h"
#include "llm/impl/Windows.Devices.Spi.Provider.1.h"
#include "llm/impl/Windows.Devices.1.h"
LLM_EXPORT namespace llm::OS::Devices
{
    struct __declspec(empty_bases) LowLevelDevicesAggregateProvider : llm::OS::Devices::ILowLevelDevicesAggregateProvider
    {
        LowLevelDevicesAggregateProvider(std::nullptr_t) noexcept {}
        LowLevelDevicesAggregateProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::ILowLevelDevicesAggregateProvider(ptr, take_ownership_from_abi) {}
        LowLevelDevicesAggregateProvider(llm::OS::Devices::Adc::Provider::IAdcControllerProvider const& adc, llm::OS::Devices::Pwm::Provider::IPwmControllerProvider const& pwm, llm::OS::Devices::Gpio::Provider::IGpioControllerProvider const& gpio, llm::OS::Devices::I2c::Provider::II2cControllerProvider const& i2c, llm::OS::Devices::Spi::Provider::ISpiControllerProvider const& spi);
    };
    struct __declspec(empty_bases) LowLevelDevicesController : llm::OS::Devices::ILowLevelDevicesController
    {
        LowLevelDevicesController(std::nullptr_t) noexcept {}
        LowLevelDevicesController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::ILowLevelDevicesController(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto DefaultProvider();
        static auto DefaultProvider(llm::OS::Devices::ILowLevelDevicesAggregateProvider const& value);
    };
}
#endif
