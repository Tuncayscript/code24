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
#ifndef LLM_OS_Devices_Custom_1_H
#define LLM_OS_Devices_Custom_1_H
#include "llm/impl/Windows.Devices.Custom.0.h"
LLM_EXPORT namespace llm::OS::Devices::Custom
{
    struct __declspec(empty_bases) ICustomDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomDevice>
    {
        ICustomDevice(std::nullptr_t = nullptr) noexcept {}
        ICustomDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICustomDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICustomDeviceStatics>
    {
        ICustomDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        ICustomDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIOControlCode :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIOControlCode>
    {
        IIOControlCode(std::nullptr_t = nullptr) noexcept {}
        IIOControlCode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIOControlCodeFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IIOControlCodeFactory>
    {
        IIOControlCodeFactory(std::nullptr_t = nullptr) noexcept {}
        IIOControlCodeFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownDeviceTypesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownDeviceTypesStatics>
    {
        IKnownDeviceTypesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownDeviceTypesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
