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
#ifndef LLM_OS_Media_DialProtocol_2_H
#define LLM_OS_Media_DialProtocol_2_H
#include "llm/impl/Windows.Devices.Enumeration.1.h"
#include "llm/impl/Windows.Media.DialProtocol.1.h"
LLM_EXPORT namespace llm:OS::Media::DialProtocol
{
    struct __declspec(empty_bases) DialApp : llm:OS::Media::DialProtocol::IDialApp
    {
        DialApp(std::nullptr_t) noexcept {}
        DialApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialApp(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialAppStateDetails : llm:OS::Media::DialProtocol::IDialAppStateDetails
    {
        DialAppStateDetails(std::nullptr_t) noexcept {}
        DialAppStateDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialAppStateDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialDevice : llm:OS::Media::DialProtocol::IDialDevice,
        impl::require<DialDevice, llm:OS::Media::DialProtocol::IDialDevice2>
    {
        DialDevice(std::nullptr_t) noexcept {}
        DialDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector(param::hstring const& appName);
        static auto FromIdAsync(param::hstring const& value);
        static auto DeviceInfoSupportsDialAsync(llm:OS::Devices::Enumeration::DeviceInformation const& device);
    };
    struct __declspec(empty_bases) DialDevicePicker : llm:OS::Media::DialProtocol::IDialDevicePicker
    {
        DialDevicePicker(std::nullptr_t) noexcept {}
        DialDevicePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialDevicePicker(ptr, take_ownership_from_abi) {}
        DialDevicePicker();
    };
    struct __declspec(empty_bases) DialDevicePickerFilter : llm:OS::Media::DialProtocol::IDialDevicePickerFilter
    {
        DialDevicePickerFilter(std::nullptr_t) noexcept {}
        DialDevicePickerFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialDevicePickerFilter(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialDeviceSelectedEventArgs : llm:OS::Media::DialProtocol::IDialDeviceSelectedEventArgs
    {
        DialDeviceSelectedEventArgs(std::nullptr_t) noexcept {}
        DialDeviceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialDeviceSelectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialDisconnectButtonClickedEventArgs : llm:OS::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs
    {
        DialDisconnectButtonClickedEventArgs(std::nullptr_t) noexcept {}
        DialDisconnectButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialDisconnectButtonClickedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialReceiverApp : llm:OS::Media::DialProtocol::IDialReceiverApp,
        impl::require<DialReceiverApp, llm:OS::Media::DialProtocol::IDialReceiverApp2>
    {
        DialReceiverApp(std::nullptr_t) noexcept {}
        DialReceiverApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::DialProtocol::IDialReceiverApp(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
    };
}
#endif
