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
#ifndef LLM_OS_Media_Miracast_1_H
#define LLM_OS_Media_Miracast_1_H
#include "llm/impl/Windows.Media.Miracast.0.h"
LLM_EXPORT namespace llm:OS::Media::Miracast
{
    struct __declspec(empty_bases) IMiracastReceiver :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiver>
    {
        IMiracastReceiver(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverApplySettingsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverApplySettingsResult>
    {
        IMiracastReceiverApplySettingsResult(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverApplySettingsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverConnection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverConnection>
    {
        IMiracastReceiverConnection(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverConnectionCreatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverConnectionCreatedEventArgs>
    {
        IMiracastReceiverConnectionCreatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverConnectionCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverCursorImageChannel :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverCursorImageChannel>
    {
        IMiracastReceiverCursorImageChannel(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverCursorImageChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverCursorImageChannelSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverCursorImageChannelSettings>
    {
        IMiracastReceiverCursorImageChannelSettings(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverCursorImageChannelSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverDisconnectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverDisconnectedEventArgs>
    {
        IMiracastReceiverDisconnectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverGameControllerDevice :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverGameControllerDevice>
    {
        IMiracastReceiverGameControllerDevice(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverGameControllerDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverInputDevices :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverInputDevices>
    {
        IMiracastReceiverInputDevices(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverInputDevices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverKeyboardDevice :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverKeyboardDevice>
    {
        IMiracastReceiverKeyboardDevice(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverKeyboardDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverMediaSourceCreatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverMediaSourceCreatedEventArgs>
    {
        IMiracastReceiverMediaSourceCreatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverMediaSourceCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverSession>
    {
        IMiracastReceiverSession(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverSessionStartResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverSessionStartResult>
    {
        IMiracastReceiverSessionStartResult(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverSessionStartResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverSettings>
    {
        IMiracastReceiverSettings(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverStatus :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverStatus>
    {
        IMiracastReceiverStatus(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverStreamControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverStreamControl>
    {
        IMiracastReceiverStreamControl(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverStreamControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastReceiverVideoStreamSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastReceiverVideoStreamSettings>
    {
        IMiracastReceiverVideoStreamSettings(std::nullptr_t = nullptr) noexcept {}
        IMiracastReceiverVideoStreamSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMiracastTransmitter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMiracastTransmitter>
    {
        IMiracastTransmitter(std::nullptr_t = nullptr) noexcept {}
        IMiracastTransmitter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
