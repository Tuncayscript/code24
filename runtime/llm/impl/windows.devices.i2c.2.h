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
#ifndef LLM_OS_Devices_I2c_2_H
#define LLM_OS_Devices_I2c_2_H
#include "llm/impl/Windows.Devices.I2c.Provider.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Devices.I2c.1.h"
LLM_EXPORT namespace llm::OS::Devices::I2c
{
    struct I2cTransferResult
    {
        llm::OS::Devices::I2c::I2cTransferStatus Status;
        uint32_t BytesTransferred;
    };
    inline bool operator==(I2cTransferResult const& left, I2cTransferResult const& right) noexcept
    {
        return left.Status == right.Status && left.BytesTransferred == right.BytesTransferred;
    }
    inline bool operator!=(I2cTransferResult const& left, I2cTransferResult const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) I2cConnectionSettings : llm::OS::Devices::I2c::II2cConnectionSettings
    {
        I2cConnectionSettings(std::nullptr_t) noexcept {}
        I2cConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::I2c::II2cConnectionSettings(ptr, take_ownership_from_abi) {}
        explicit I2cConnectionSettings(int32_t slaveAddress);
    };
    struct __declspec(empty_bases) I2cController : llm::OS::Devices::I2c::II2cController
    {
        I2cController(std::nullptr_t) noexcept {}
        I2cController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::I2c::II2cController(ptr, take_ownership_from_abi) {}
        static auto GetControllersAsync(llm::OS::Devices::I2c::Provider::II2cProvider const& provider);
        static auto GetDefaultAsync();
    };
    struct __declspec(empty_bases) I2cDevice : llm::OS::Devices::I2c::II2cDevice
    {
        I2cDevice(std::nullptr_t) noexcept {}
        I2cDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::I2c::II2cDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(param::hstring const& friendlyName);
        static auto FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::I2c::I2cConnectionSettings const& settings);
    };
}
#endif
