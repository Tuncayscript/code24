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
#ifndef LLM_OS_Networking_PushNotifications_1_H
#define LLM_OS_Networking_PushNotifications_1_H
#include "llm/impl/Windows.Networking.PushNotifications.0.h"
LLM_EXPORT namespace llm:OS::Networking::PushNotifications
{
    struct __declspec(empty_bases) IPushNotificationChannel :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannel>
    {
        IPushNotificationChannel(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelManagerForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelManagerForUser>
    {
        IPushNotificationChannelManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelManagerForUser2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelManagerForUser2>
    {
        IPushNotificationChannelManagerForUser2(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelManagerForUser2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelManagerStatics>
    {
        IPushNotificationChannelManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelManagerStatics2>
    {
        IPushNotificationChannelManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelManagerStatics3>
    {
        IPushNotificationChannelManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelManagerStatics4>
    {
        IPushNotificationChannelManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationChannelsRevokedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationChannelsRevokedEventArgs>
    {
        IPushNotificationChannelsRevokedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationChannelsRevokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPushNotificationReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPushNotificationReceivedEventArgs>
    {
        IPushNotificationReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPushNotificationReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRawNotification :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRawNotification>
    {
        IRawNotification(std::nullptr_t = nullptr) noexcept {}
        IRawNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRawNotification2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRawNotification2>
    {
        IRawNotification2(std::nullptr_t = nullptr) noexcept {}
        IRawNotification2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRawNotification3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRawNotification3>
    {
        IRawNotification3(std::nullptr_t = nullptr) noexcept {}
        IRawNotification3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
