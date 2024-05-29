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
#ifndef LLM_OS_Devices_SerialCommunication_2_H
#define LLM_OS_Devices_SerialCommunication_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.SerialCommunication.1.h"
LLM_EXPORT namespace llm::OS::Devices::SerialCommunication
{
    struct __declspec(empty_bases) ErrorReceivedEventArgs : llm::OS::Devices::SerialCommunication::IErrorReceivedEventArgs
    {
        ErrorReceivedEventArgs(std::nullptr_t) noexcept {}
        ErrorReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SerialCommunication::IErrorReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PinChangedEventArgs : llm::OS::Devices::SerialCommunication::IPinChangedEventArgs
    {
        PinChangedEventArgs(std::nullptr_t) noexcept {}
        PinChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SerialCommunication::IPinChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SerialDevice : llm::OS::Devices::SerialCommunication::ISerialDevice
    {
        SerialDevice(std::nullptr_t) noexcept {}
        SerialDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SerialCommunication::ISerialDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(param::hstring const& portName);
        static auto GetDeviceSelectorFromUsbVidPid(uint16_t vendorId, uint16_t productId);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
}
#endif
