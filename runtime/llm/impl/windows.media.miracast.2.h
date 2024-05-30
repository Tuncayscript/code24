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
#ifndef LLM_OS_Media_Miracast_2_H
#define LLM_OS_Media_Miracast_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Miracast.1.h"
LLM_EXPORT namespace llm:OS::Media::Miracast
{
    struct __declspec(empty_bases) MiracastReceiver : llm:OS::Media::Miracast::IMiracastReceiver
    {
        MiracastReceiver(std::nullptr_t) noexcept {}
        MiracastReceiver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiver(ptr, take_ownership_from_abi) {}
        MiracastReceiver();
    };
    struct __declspec(empty_bases) MiracastReceiverApplySettingsResult : llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult
    {
        MiracastReceiverApplySettingsResult(std::nullptr_t) noexcept {}
        MiracastReceiverApplySettingsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverConnection : llm:OS::Media::Miracast::IMiracastReceiverConnection,
        impl::require<MiracastReceiverConnection, llm:OS::Foundation::IClosable>
    {
        MiracastReceiverConnection(std::nullptr_t) noexcept {}
        MiracastReceiverConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverConnectionCreatedEventArgs : llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs
    {
        MiracastReceiverConnectionCreatedEventArgs(std::nullptr_t) noexcept {}
        MiracastReceiverConnectionCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverCursorImageChannel : llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel
    {
        MiracastReceiverCursorImageChannel(std::nullptr_t) noexcept {}
        MiracastReceiverCursorImageChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverCursorImageChannelSettings : llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings
    {
        MiracastReceiverCursorImageChannelSettings(std::nullptr_t) noexcept {}
        MiracastReceiverCursorImageChannelSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverDisconnectedEventArgs : llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs
    {
        MiracastReceiverDisconnectedEventArgs(std::nullptr_t) noexcept {}
        MiracastReceiverDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverGameControllerDevice : llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice
    {
        MiracastReceiverGameControllerDevice(std::nullptr_t) noexcept {}
        MiracastReceiverGameControllerDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverInputDevices : llm:OS::Media::Miracast::IMiracastReceiverInputDevices
    {
        MiracastReceiverInputDevices(std::nullptr_t) noexcept {}
        MiracastReceiverInputDevices(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverInputDevices(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverKeyboardDevice : llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice
    {
        MiracastReceiverKeyboardDevice(std::nullptr_t) noexcept {}
        MiracastReceiverKeyboardDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverMediaSourceCreatedEventArgs : llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs
    {
        MiracastReceiverMediaSourceCreatedEventArgs(std::nullptr_t) noexcept {}
        MiracastReceiverMediaSourceCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverSession : llm:OS::Media::Miracast::IMiracastReceiverSession,
        impl::require<MiracastReceiverSession, llm:OS::Foundation::IClosable>
    {
        MiracastReceiverSession(std::nullptr_t) noexcept {}
        MiracastReceiverSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverSessionStartResult : llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult
    {
        MiracastReceiverSessionStartResult(std::nullptr_t) noexcept {}
        MiracastReceiverSessionStartResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverSettings : llm:OS::Media::Miracast::IMiracastReceiverSettings
    {
        MiracastReceiverSettings(std::nullptr_t) noexcept {}
        MiracastReceiverSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverStatus : llm:OS::Media::Miracast::IMiracastReceiverStatus
    {
        MiracastReceiverStatus(std::nullptr_t) noexcept {}
        MiracastReceiverStatus(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverStatus(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverStreamControl : llm:OS::Media::Miracast::IMiracastReceiverStreamControl
    {
        MiracastReceiverStreamControl(std::nullptr_t) noexcept {}
        MiracastReceiverStreamControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverStreamControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastReceiverVideoStreamSettings : llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings
    {
        MiracastReceiverVideoStreamSettings(std::nullptr_t) noexcept {}
        MiracastReceiverVideoStreamSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MiracastTransmitter : llm:OS::Media::Miracast::IMiracastTransmitter
    {
        MiracastTransmitter(std::nullptr_t) noexcept {}
        MiracastTransmitter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Miracast::IMiracastTransmitter(ptr, take_ownership_from_abi) {}
    };
}
#endif
