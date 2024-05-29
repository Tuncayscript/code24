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
#ifndef LLM_OS_Devices_Lights_1_H
#define LLM_OS_Devices_Lights_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Lights.0.h"
LLM_EXPORT namespace llm::OS::Devices::Lights
{
    struct __declspec(empty_bases) ILamp :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILamp>,
        impl::require<llm::OS::Devices::Lights::ILamp, llm::OS::Foundation::IClosable>
    {
        ILamp(std::nullptr_t = nullptr) noexcept {}
        ILamp(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArray :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArray>
    {
        ILampArray(std::nullptr_t = nullptr) noexcept {}
        ILampArray(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArray2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArray2>
    {
        ILampArray2(std::nullptr_t = nullptr) noexcept {}
        ILampArray2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampArrayStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampArrayStatics>
    {
        ILampArrayStatics(std::nullptr_t = nullptr) noexcept {}
        ILampArrayStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampAvailabilityChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampAvailabilityChangedEventArgs>
    {
        ILampAvailabilityChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILampAvailabilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampInfo>
    {
        ILampInfo(std::nullptr_t = nullptr) noexcept {}
        ILampInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILampStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILampStatics>
    {
        ILampStatics(std::nullptr_t = nullptr) noexcept {}
        ILampStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
