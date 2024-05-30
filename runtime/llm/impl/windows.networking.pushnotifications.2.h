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
#ifndef LLM_OS_Networking_PushNotifications_2_H
#define LLM_OS_Networking_PushNotifications_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Networking.PushNotifications.1.h"
LLM_EXPORT namespace llm:OS::Networking::PushNotifications
{
    struct __declspec(empty_bases) PushNotificationChannel : llm:OS::Networking::PushNotifications::IPushNotificationChannel
    {
        PushNotificationChannel(std::nullptr_t) noexcept {}
        PushNotificationChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::PushNotifications::IPushNotificationChannel(ptr, take_ownership_from_abi) {}
    };
    struct PushNotificationChannelManager
    {
        PushNotificationChannelManager() = delete;
        static auto CreatePushNotificationChannelForApplicationAsync();
        static auto CreatePushNotificationChannelForApplicationAsync(param::hstring const& applicationId);
        static auto CreatePushNotificationChannelForSecondaryTileAsync(param::hstring const& tileId);
        static auto GetForUser(llm:OS::System::User const& user);
        static auto GetDefault();
        static auto ChannelsRevoked(llm:OS::Foundation::EventHandler<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs> const& handler);
        using ChannelsRevoked_revoker = impl::factory_event_revoker<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4, &impl::abi_t<llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerStatics4>::remove_ChannelsRevoked>;
        [[nodiscard]] static ChannelsRevoked_revoker ChannelsRevoked(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Networking::PushNotifications::PushNotificationChannelsRevokedEventArgs> const& handler);
        static auto ChannelsRevoked(llm::event_token const& token);
    };
    struct __declspec(empty_bases) PushNotificationChannelManagerForUser : llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser,
        impl::require<PushNotificationChannelManagerForUser, llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser2>
    {
        PushNotificationChannelManagerForUser(std::nullptr_t) noexcept {}
        PushNotificationChannelManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::PushNotifications::IPushNotificationChannelManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PushNotificationChannelsRevokedEventArgs : llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs
    {
        PushNotificationChannelsRevokedEventArgs(std::nullptr_t) noexcept {}
        PushNotificationChannelsRevokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::PushNotifications::IPushNotificationChannelsRevokedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PushNotificationReceivedEventArgs : llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs
    {
        PushNotificationReceivedEventArgs(std::nullptr_t) noexcept {}
        PushNotificationReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::PushNotifications::IPushNotificationReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RawNotification : llm:OS::Networking::PushNotifications::IRawNotification,
        impl::require<RawNotification, llm:OS::Networking::PushNotifications::IRawNotification2, llm:OS::Networking::PushNotifications::IRawNotification3>
    {
        RawNotification(std::nullptr_t) noexcept {}
        RawNotification(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::PushNotifications::IRawNotification(ptr, take_ownership_from_abi) {}
    };
}
#endif
