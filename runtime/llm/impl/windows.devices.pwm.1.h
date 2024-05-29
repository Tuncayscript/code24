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
#ifndef LLM_OS_Devices_Pwm_1_H
#define LLM_OS_Devices_Pwm_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Pwm.0.h"
LLM_EXPORT namespace llm::OS::Devices::Pwm
{
    struct __declspec(empty_bases) IPwmController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPwmController>
    {
        IPwmController(std::nullptr_t = nullptr) noexcept {}
        IPwmController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPwmControllerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPwmControllerStatics>
    {
        IPwmControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IPwmControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPwmControllerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPwmControllerStatics2>
    {
        IPwmControllerStatics2(std::nullptr_t = nullptr) noexcept {}
        IPwmControllerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPwmControllerStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPwmControllerStatics3>
    {
        IPwmControllerStatics3(std::nullptr_t = nullptr) noexcept {}
        IPwmControllerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPwmPin :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPwmPin>,
        impl::require<llm::OS::Devices::Pwm::IPwmPin, llm::OS::Foundation::IClosable>
    {
        IPwmPin(std::nullptr_t = nullptr) noexcept {}
        IPwmPin(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
