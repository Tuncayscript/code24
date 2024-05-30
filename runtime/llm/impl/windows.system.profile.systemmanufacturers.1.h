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
#ifndef LLM_OS_System_Profile_SystemManufacturers_1_H
#define LLM_OS_System_Profile_SystemManufacturers_1_H
#include "llm/impl/Windows.System.Profile.SystemManufacturers.0.h"
LLM_EXPORT namespace llm:OS::System::Profile::SystemManufacturers
{
    struct __declspec(empty_bases) IOemSupportInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IOemSupportInfo>
    {
        IOemSupportInfo(std::nullptr_t = nullptr) noexcept {}
        IOemSupportInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmbiosInformationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISmbiosInformationStatics>
    {
        ISmbiosInformationStatics(std::nullptr_t = nullptr) noexcept {}
        ISmbiosInformationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemSupportDeviceInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemSupportDeviceInfo>
    {
        ISystemSupportDeviceInfo(std::nullptr_t = nullptr) noexcept {}
        ISystemSupportDeviceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemSupportInfoStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemSupportInfoStatics>
    {
        ISystemSupportInfoStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemSupportInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemSupportInfoStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemSupportInfoStatics2>
    {
        ISystemSupportInfoStatics2(std::nullptr_t = nullptr) noexcept {}
        ISystemSupportInfoStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
