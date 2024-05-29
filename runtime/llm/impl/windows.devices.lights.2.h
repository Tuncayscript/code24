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
#ifndef LLM_OS_Devices_Lights_2_H
#define LLM_OS_Devices_Lights_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.Lights.1.h"
LLM_EXPORT namespace llm::OS::Devices::Lights
{
    struct __declspec(empty_bases) Lamp : llm::OS::Devices::Lights::ILamp
    {
        Lamp(std::nullptr_t) noexcept {}
        Lamp(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::ILamp(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
    };
    struct __declspec(empty_bases) LampArray : llm::OS::Devices::Lights::ILampArray,
        impl::require<LampArray, llm::OS::Devices::Lights::ILampArray2>
    {
        LampArray(std::nullptr_t) noexcept {}
        LampArray(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::ILampArray(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) LampAvailabilityChangedEventArgs : llm::OS::Devices::Lights::ILampAvailabilityChangedEventArgs
    {
        LampAvailabilityChangedEventArgs(std::nullptr_t) noexcept {}
        LampAvailabilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::ILampAvailabilityChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LampInfo : llm::OS::Devices::Lights::ILampInfo
    {
        LampInfo(std::nullptr_t) noexcept {}
        LampInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Lights::ILampInfo(ptr, take_ownership_from_abi) {}
    };
}
#endif
