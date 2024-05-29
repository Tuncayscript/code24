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
#ifndef LLM_OS_Devices_Spi_1_H
#define LLM_OS_Devices_Spi_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.Spi.0.h"
LLM_EXPORT namespace llm::OS::Devices::Spi
{
    struct __declspec(empty_bases) ISpiBusInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiBusInfo>
    {
        ISpiBusInfo(std::nullptr_t = nullptr) noexcept {}
        ISpiBusInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpiConnectionSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiConnectionSettings>
    {
        ISpiConnectionSettings(std::nullptr_t = nullptr) noexcept {}
        ISpiConnectionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpiConnectionSettingsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiConnectionSettingsFactory>
    {
        ISpiConnectionSettingsFactory(std::nullptr_t = nullptr) noexcept {}
        ISpiConnectionSettingsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpiController :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiController>
    {
        ISpiController(std::nullptr_t = nullptr) noexcept {}
        ISpiController(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpiControllerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiControllerStatics>
    {
        ISpiControllerStatics(std::nullptr_t = nullptr) noexcept {}
        ISpiControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpiDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiDevice>,
        impl::require<llm::OS::Devices::Spi::ISpiDevice, llm::OS::Foundation::IClosable>
    {
        ISpiDevice(std::nullptr_t = nullptr) noexcept {}
        ISpiDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpiDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISpiDeviceStatics>
    {
        ISpiDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        ISpiDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
