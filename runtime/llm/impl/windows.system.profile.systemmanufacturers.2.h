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
#ifndef LLM_OS_System_Profile_SystemManufacturers_2_H
#define LLM_OS_System_Profile_SystemManufacturers_2_H
#include "llm/impl/Windows.System.Profile.SystemManufacturers.1.h"
LLM_EXPORT namespace llm:OS::System::Profile::SystemManufacturers
{
    struct __declspec(empty_bases) OemSupportInfo : llm:OS::System::Profile::SystemManufacturers::IOemSupportInfo
    {
        OemSupportInfo(std::nullptr_t) noexcept {}
        OemSupportInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Profile::SystemManufacturers::IOemSupportInfo(ptr, take_ownership_from_abi) {}
    };
    struct SmbiosInformation
    {
        SmbiosInformation() = delete;
        [[nodiscard]] static auto SerialNumber();
    };
    struct __declspec(empty_bases) SystemSupportDeviceInfo : llm:OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo
    {
        SystemSupportDeviceInfo(std::nullptr_t) noexcept {}
        SystemSupportDeviceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Profile::SystemManufacturers::ISystemSupportDeviceInfo(ptr, take_ownership_from_abi) {}
    };
    struct SystemSupportInfo
    {
        SystemSupportInfo() = delete;
        [[nodiscard]] static auto LocalSystemEdition();
        [[nodiscard]] static auto OemSupportInfo();
        [[nodiscard]] static auto LocalDeviceInfo();
    };
}
#endif
