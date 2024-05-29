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
#ifndef LLM_OS_Devices_Gpio_Provider_1_H
#define LLM_OS_Devices_Gpio_Provider_1_H
#include "llm/impl/Windows.Devices.Gpio.Provider.0.h"
LLM_EXPORT namespace llm::OS::Devices::Gpio::Provider
{
    struct __declspec(empty_bases) IGpioControllerProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioControllerProvider>
    {
        IGpioControllerProvider(std::nullptr_t = nullptr) noexcept {}
        IGpioControllerProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioPinProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioPinProvider>
    {
        IGpioPinProvider(std::nullptr_t = nullptr) noexcept {}
        IGpioPinProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioPinProviderValueChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioPinProviderValueChangedEventArgs>
    {
        IGpioPinProviderValueChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGpioPinProviderValueChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioPinProviderValueChangedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioPinProviderValueChangedEventArgsFactory>
    {
        IGpioPinProviderValueChangedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IGpioPinProviderValueChangedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioProvider>
    {
        IGpioProvider(std::nullptr_t = nullptr) noexcept {}
        IGpioProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
