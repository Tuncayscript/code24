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
#ifndef LLM_OS_Devices_Custom_2_H
#define LLM_OS_Devices_Custom_2_H
#include "llm/impl/Windows.Devices.Custom.1.h"
LLM_EXPORT namespace llm::OS::Devices::Custom
{
    struct __declspec(empty_bases) CustomDevice : llm::OS::Devices::Custom::ICustomDevice
    {
        CustomDevice(std::nullptr_t) noexcept {}
        CustomDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Custom::ICustomDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector(llm::guid const& classGuid);
        static auto FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::Custom::DeviceAccessMode const& desiredAccess, llm::OS::Devices::Custom::DeviceSharingMode const& sharingMode);
    };
    struct __declspec(empty_bases) IOControlCode : llm::OS::Devices::Custom::IIOControlCode
    {
        IOControlCode(std::nullptr_t) noexcept {}
        IOControlCode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Custom::IIOControlCode(ptr, take_ownership_from_abi) {}
        IOControlCode(uint16_t deviceType, uint16_t function, llm::OS::Devices::Custom::IOControlAccessMode const& accessMode, llm::OS::Devices::Custom::IOControlBufferingMethod const& bufferingMethod);
    };
    struct KnownDeviceTypes
    {
        KnownDeviceTypes() = delete;
        [[nodiscard]] static auto Unknown();
    };
}
#endif
