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
#ifndef LLM_OS_Devices_I2c_1_H
#define LLM_OS_Devices_I2c_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.I2c.0.h"
LLM_EXPORT namespace llm::OS::Devices::I2c
{
    struct __declspec(empty_bases) II2cConnectionSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cConnectionSettings>
    {
        II2cConnectionSettings(std::nullptr_t = nullptr) noexcept {}
        II2cConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cConnectionSettingsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cConnectionSettingsFactory>
    {
        II2cConnectionSettingsFactory(std::nullptr_t = nullptr) noexcept {}
        II2cConnectionSettingsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cController>
    {
        II2cController(std::nullptr_t = nullptr) noexcept {}
        II2cController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cControllerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cControllerStatics>
    {
        II2cControllerStatics(std::nullptr_t = nullptr) noexcept {}
        II2cControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cDevice>,
        impl::require<llm::OS::Devices::I2c::II2cDevice, llm::OS::Foundation::IClosable>
    {
        II2cDevice(std::nullptr_t = nullptr) noexcept {}
        II2cDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) II2cDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<II2cDeviceStatics>
    {
        II2cDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        II2cDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
