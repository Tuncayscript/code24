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
#ifndef LLM_OS_Devices_Spi_2_H
#define LLM_OS_Devices_Spi_2_H
#include "llm/impl/Windows.Devices.Spi.Provider.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Spi.1.h"
LLM_EXPORT namespace llm::OS::Devices::Spi
{
    struct __declspec(empty_bases) SpiBusInfo : llm::OS::Devices::Spi::ISpiBusInfo
    {
        SpiBusInfo(std::nullptr_t) noexcept {}
        SpiBusInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Spi::ISpiBusInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpiConnectionSettings : llm::OS::Devices::Spi::ISpiConnectionSettings
    {
        SpiConnectionSettings(std::nullptr_t) noexcept {}
        SpiConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Spi::ISpiConnectionSettings(ptr, take_ownership_from_abi) {}
        explicit SpiConnectionSettings(int32_t chipSelectLine);
    };
    struct __declspec(empty_bases) SpiController : llm::OS::Devices::Spi::ISpiController
    {
        SpiController(std::nullptr_t) noexcept {}
        SpiController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Spi::ISpiController(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto GetControllersAsync(llm::OS::Devices::Spi::Provider::ISpiProvider const& provider);
    };
    struct __declspec(empty_bases) SpiDevice : llm::OS::Devices::Spi::ISpiDevice
    {
        SpiDevice(std::nullptr_t) noexcept {}
        SpiDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Spi::ISpiDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(param::hstring const& friendlyName);
        static auto GetBusInfo(param::hstring const& busId);
        static auto FromIdAsync(param::hstring const& busId, llm::OS::Devices::Spi::SpiConnectionSettings const& settings);
    };
}
#endif
