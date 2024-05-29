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
#ifndef LLM_OS_Devices_SerialCommunication_1_H
#define LLM_OS_Devices_SerialCommunication_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.SerialCommunication.0.h"
LLM_EXPORT namespace llm::OS::Devices::SerialCommunication
{
    struct __declspec(empty_bases) IErrorReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IErrorReceivedEventArgs>
    {
        IErrorReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IErrorReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPinChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPinChangedEventArgs>
    {
        IPinChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPinChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISerialDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISerialDevice>,
        impl::require<llm::OS::Devices::SerialCommunication::ISerialDevice, llm::OS::Foundation::IClosable>
    {
        ISerialDevice(std::nullptr_t = nullptr) noexcept {}
        ISerialDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISerialDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISerialDeviceStatics>
    {
        ISerialDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        ISerialDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
