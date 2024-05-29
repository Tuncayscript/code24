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
#ifndef LLM_OS_Devices_I2c_Provider_2_H
#define LLM_OS_Devices_I2c_Provider_2_H
#include "llm/impl/Windows.Devices.I2c.Provider.1.h"
LLM_EXPORT namespace llm::OS::Devices::I2c::Provider
{
    struct ProviderI2cTransferResult
    {
        llm::OS::Devices::I2c::Provider::ProviderI2cTransferStatus Status;
        uint32_t BytesTransferred;
    };
    inline bool operator==(ProviderI2cTransferResult const& left, ProviderI2cTransferResult const& right) noexcept
    {
        return left.Status == right.Status && left.BytesTransferred == right.BytesTransferred;
    }
    inline bool operator!=(ProviderI2cTransferResult const& left, ProviderI2cTransferResult const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ProviderI2cConnectionSettings : llm::OS::Devices::I2c::Provider::IProviderI2cConnectionSettings
    {
        ProviderI2cConnectionSettings(std::nullptr_t) noexcept {}
        ProviderI2cConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::I2c::Provider::IProviderI2cConnectionSettings(ptr, take_ownership_from_abi) {}
    };
}
#endif
