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
#ifndef LLM_OS_Devices_Gpio_1_H
#define LLM_OS_Devices_Gpio_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Gpio.0.h"
LLM_EXPORT namespace llm::OS::Devices::Gpio
{
    struct __declspec(empty_bases) IGpioChangeCounter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioChangeCounter>,
        impl::require<llm::OS::Devices::Gpio::IGpioChangeCounter, llm::OS::Foundation::IClosable>
    {
        IGpioChangeCounter(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeCounter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioChangeCounterFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioChangeCounterFactory>
    {
        IGpioChangeCounterFactory(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeCounterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioChangeReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioChangeReader>,
        impl::require<llm::OS::Devices::Gpio::IGpioChangeReader, llm::OS::Foundation::IClosable>
    {
        IGpioChangeReader(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioChangeReaderFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioChangeReaderFactory>
    {
        IGpioChangeReaderFactory(std::nullptr_t = nullptr) noexcept {}
        IGpioChangeReaderFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioController>
    {
        IGpioController(std::nullptr_t = nullptr) noexcept {}
        IGpioController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioControllerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioControllerStatics>
    {
        IGpioControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IGpioControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioControllerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioControllerStatics2>
    {
        IGpioControllerStatics2(std::nullptr_t = nullptr) noexcept {}
        IGpioControllerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioPin :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioPin>,
        impl::require<llm::OS::Devices::Gpio::IGpioPin, llm::OS::Foundation::IClosable>
    {
        IGpioPin(std::nullptr_t = nullptr) noexcept {}
        IGpioPin(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGpioPinValueChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IGpioPinValueChangedEventArgs>
    {
        IGpioPinValueChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGpioPinValueChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
