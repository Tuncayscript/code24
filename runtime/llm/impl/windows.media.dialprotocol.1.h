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
#ifndef LLM_OS_Media_DialProtocol_1_H
#define LLM_OS_Media_DialProtocol_1_H
#include "llm/impl/Windows.Media.DialProtocol.0.h"
LLM_EXPORT namespace llm:OS::Media::DialProtocol
{
    struct __declspec(empty_bases) IDialApp :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialApp>
    {
        IDialApp(std::nullptr_t = nullptr) noexcept {}
        IDialApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialAppStateDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialAppStateDetails>
    {
        IDialAppStateDetails(std::nullptr_t = nullptr) noexcept {}
        IDialAppStateDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDevice :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDevice>
    {
        IDialDevice(std::nullptr_t = nullptr) noexcept {}
        IDialDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDevice2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDevice2>
    {
        IDialDevice2(std::nullptr_t = nullptr) noexcept {}
        IDialDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDevicePicker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDevicePicker>
    {
        IDialDevicePicker(std::nullptr_t = nullptr) noexcept {}
        IDialDevicePicker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDevicePickerFilter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDevicePickerFilter>
    {
        IDialDevicePickerFilter(std::nullptr_t = nullptr) noexcept {}
        IDialDevicePickerFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDeviceSelectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDeviceSelectedEventArgs>
    {
        IDialDeviceSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDialDeviceSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDeviceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDeviceStatics>
    {
        IDialDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IDialDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialDisconnectButtonClickedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialDisconnectButtonClickedEventArgs>
    {
        IDialDisconnectButtonClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDialDisconnectButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialReceiverApp :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialReceiverApp>
    {
        IDialReceiverApp(std::nullptr_t = nullptr) noexcept {}
        IDialReceiverApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialReceiverApp2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialReceiverApp2>
    {
        IDialReceiverApp2(std::nullptr_t = nullptr) noexcept {}
        IDialReceiverApp2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialReceiverAppStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDialReceiverAppStatics>
    {
        IDialReceiverAppStatics(std::nullptr_t = nullptr) noexcept {}
        IDialReceiverAppStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
