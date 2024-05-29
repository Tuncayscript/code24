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
#ifndef LLM_OS_Devices_Sensors_Custom_2_H
#define LLM_OS_Devices_Sensors_Custom_2_H
#include "llm/impl/Windows.Devices.Sensors.Custom.1.h"
LLM_EXPORT namespace llm::OS::Devices::Sensors::Custom
{
    struct __declspec(empty_bases) CustomSensor : llm::OS::Devices::Sensors::Custom::ICustomSensor,
        impl::require<CustomSensor, llm::OS::Devices::Sensors::Custom::ICustomSensor2>
    {
        CustomSensor(std::nullptr_t) noexcept {}
        CustomSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::Custom::ICustomSensor(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector(llm::guid const& interfaceId);
        static auto FromIdAsync(param::hstring const& sensorId);
    };
    struct __declspec(empty_bases) CustomSensorReading : llm::OS::Devices::Sensors::Custom::ICustomSensorReading,
        impl::require<CustomSensorReading, llm::OS::Devices::Sensors::Custom::ICustomSensorReading2>
    {
        CustomSensorReading(std::nullptr_t) noexcept {}
        CustomSensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::Custom::ICustomSensorReading(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CustomSensorReadingChangedEventArgs : llm::OS::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs
    {
        CustomSensorReadingChangedEventArgs(std::nullptr_t) noexcept {}
        CustomSensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sensors::Custom::ICustomSensorReadingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
