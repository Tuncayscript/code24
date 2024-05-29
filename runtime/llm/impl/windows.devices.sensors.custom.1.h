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
#ifndef LLM_OS_Devices_Sensors_Custom_1_H
#define LLM_OS_Devices_Sensors_Custom_1_H
#include "llm/impl/Windows.Devices.Sensors.Custom.0.h"
LLM_EXPORT namespace llm::OS::Devices::Sensors::Custom
{
    struct __declspec(empty_bases) ICustomSensor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSensor>
    {
        ICustomSensor(std::nullptr_t = nullptr) noexcept {}
        ICustomSensor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSensor2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSensor2>
    {
        ICustomSensor2(std::nullptr_t = nullptr) noexcept {}
        ICustomSensor2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSensorReading :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSensorReading>
    {
        ICustomSensorReading(std::nullptr_t = nullptr) noexcept {}
        ICustomSensorReading(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSensorReading2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSensorReading2>
    {
        ICustomSensorReading2(std::nullptr_t = nullptr) noexcept {}
        ICustomSensorReading2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSensorReadingChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSensorReadingChangedEventArgs>
    {
        ICustomSensorReadingChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICustomSensorReadingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomSensorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomSensorStatics>
    {
        ICustomSensorStatics(std::nullptr_t = nullptr) noexcept {}
        ICustomSensorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
