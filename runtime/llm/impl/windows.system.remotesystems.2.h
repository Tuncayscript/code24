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
#ifndef LLM_OS_System_RemoteSystems_2_H
#define LLM_OS_System_RemoteSystems_2_H
#include "llm/impl/Windows.ApplicationModel.AppService.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.System.RemoteSystems.1.h"
LLM_EXPORT namespace llm:OS::System::RemoteSystems
{
    struct KnownRemoteSystemCapabilities
    {
        KnownRemoteSystemCapabilities() = delete;
        [[nodiscard]] static auto AppService();
        [[nodiscard]] static auto LaunchUri();
        [[nodiscard]] static auto RemoteSession();
        [[nodiscard]] static auto SpatialEntity();
    };
    struct __declspec(empty_bases) RemoteSystem : llm:OS::System::RemoteSystems::IRemoteSystem,
        impl::require<RemoteSystem, llm:OS::System::RemoteSystems::IRemoteSystem2, llm:OS::System::RemoteSystems::IRemoteSystem3, llm:OS::System::RemoteSystems::IRemoteSystem4, llm:OS::System::RemoteSystems::IRemoteSystem5, llm:OS::System::RemoteSystems::IRemoteSystem6>
    {
        RemoteSystem(std::nullptr_t) noexcept {}
        RemoteSystem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystem(ptr, take_ownership_from_abi) {}
        static auto FindByHostNameAsync(llm:OS::Networking::HostName const& hostName);
        static auto CreateWatcher();
        static auto CreateWatcher(param::iterable<llm:OS::System::RemoteSystems::IRemoteSystemFilter> const& filters);
        static auto RequestAccessAsync();
        static auto IsAuthorizationKindEnabled(llm:OS::System::RemoteSystems::RemoteSystemAuthorizationKind const& kind);
        static auto CreateWatcherForUser(llm:OS::System::User const& user);
        static auto CreateWatcherForUser(llm:OS::System::User const& user, param::iterable<llm:OS::System::RemoteSystems::IRemoteSystemFilter> const& filters);
    };
    struct __declspec(empty_bases) RemoteSystemAddedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemAddedEventArgs
    {
        RemoteSystemAddedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemApp : llm:OS::System::RemoteSystems::IRemoteSystemApp,
        impl::require<RemoteSystemApp, llm:OS::System::RemoteSystems::IRemoteSystemApp2>
    {
        RemoteSystemApp(std::nullptr_t) noexcept {}
        RemoteSystemApp(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemApp(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemAppRegistration : llm:OS::System::RemoteSystems::IRemoteSystemAppRegistration
    {
        RemoteSystemAppRegistration(std::nullptr_t) noexcept {}
        RemoteSystemAppRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemAppRegistration(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) RemoteSystemAuthorizationKindFilter : llm:OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter,
        impl::require<RemoteSystemAuthorizationKindFilter, llm:OS::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemAuthorizationKindFilter(std::nullptr_t) noexcept {}
        RemoteSystemAuthorizationKindFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemAuthorizationKindFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemAuthorizationKindFilter(llm:OS::System::RemoteSystems::RemoteSystemAuthorizationKind const& remoteSystemAuthorizationKind);
    };
    struct __declspec(empty_bases) RemoteSystemConnectionInfo : llm:OS::System::RemoteSystems::IRemoteSystemConnectionInfo
    {
        RemoteSystemConnectionInfo(std::nullptr_t) noexcept {}
        RemoteSystemConnectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemConnectionInfo(ptr, take_ownership_from_abi) {}
        static auto TryCreateFromAppServiceConnection(llm:OS::ApplicationModel::AppService::AppServiceConnection const& connection);
    };
    struct __declspec(empty_bases) RemoteSystemConnectionRequest : llm:OS::System::RemoteSystems::IRemoteSystemConnectionRequest,
        impl::require<RemoteSystemConnectionRequest, llm:OS::System::RemoteSystems::IRemoteSystemConnectionRequest2, llm:OS::System::RemoteSystems::IRemoteSystemConnectionRequest3>
    {
        RemoteSystemConnectionRequest(std::nullptr_t) noexcept {}
        RemoteSystemConnectionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemConnectionRequest(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemConnectionRequest(llm:OS::System::RemoteSystems::RemoteSystem const& remoteSystem);
        static auto CreateForApp(llm:OS::System::RemoteSystems::RemoteSystemApp const& remoteSystemApp);
        static auto CreateFromConnectionToken(param::hstring const& connectionToken);
        static auto CreateFromConnectionTokenForUser(llm:OS::System::User const& user, param::hstring const& connectionToken);
    };
    struct __declspec(empty_bases) RemoteSystemDiscoveryTypeFilter : llm:OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter,
        impl::require<RemoteSystemDiscoveryTypeFilter, llm:OS::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemDiscoveryTypeFilter(std::nullptr_t) noexcept {}
        RemoteSystemDiscoveryTypeFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemDiscoveryTypeFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemDiscoveryTypeFilter(llm:OS::System::RemoteSystems::RemoteSystemDiscoveryType const& discoveryType);
    };
    struct __declspec(empty_bases) RemoteSystemEnumerationCompletedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs
    {
        RemoteSystemEnumerationCompletedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemEnumerationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemEnumerationCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemKindFilter : llm:OS::System::RemoteSystems::IRemoteSystemKindFilter,
        impl::require<RemoteSystemKindFilter, llm:OS::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemKindFilter(std::nullptr_t) noexcept {}
        RemoteSystemKindFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemKindFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemKindFilter(param::iterable<hstring> const& remoteSystemKinds);
    };
    struct RemoteSystemKinds
    {
        RemoteSystemKinds() = delete;
        [[nodiscard]] static auto Phone();
        [[nodiscard]] static auto Hub();
        [[nodiscard]] static auto Holographic();
        [[nodiscard]] static auto Desktop();
        [[nodiscard]] static auto Xbox();
        [[nodiscard]] static auto Iot();
        [[nodiscard]] static auto Tablet();
        [[nodiscard]] static auto Laptop();
    };
    struct __declspec(empty_bases) RemoteSystemRemovedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemRemovedEventArgs
    {
        RemoteSystemRemovedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSession : llm:OS::System::RemoteSystems::IRemoteSystemSession,
        impl::require<RemoteSystemSession, llm:OS::Foundation::IClosable>
    {
        RemoteSystemSession(std::nullptr_t) noexcept {}
        RemoteSystemSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSession(ptr, take_ownership_from_abi) {}
        static auto CreateWatcher();
    };
    struct __declspec(empty_bases) RemoteSystemSessionAddedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs
    {
        RemoteSystemSessionAddedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionController : llm:OS::System::RemoteSystems::IRemoteSystemSessionController
    {
        RemoteSystemSessionController(std::nullptr_t) noexcept {}
        RemoteSystemSessionController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionController(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemSessionController(param::hstring const& displayName);
        RemoteSystemSessionController(param::hstring const& displayName, llm:OS::System::RemoteSystems::RemoteSystemSessionOptions const& options);
    };
    struct __declspec(empty_bases) RemoteSystemSessionCreationResult : llm:OS::System::RemoteSystems::IRemoteSystemSessionCreationResult
    {
        RemoteSystemSessionCreationResult(std::nullptr_t) noexcept {}
        RemoteSystemSessionCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionCreationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionDisconnectedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs
    {
        RemoteSystemSessionDisconnectedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionDisconnectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionDisconnectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionInfo : llm:OS::System::RemoteSystems::IRemoteSystemSessionInfo
    {
        RemoteSystemSessionInfo(std::nullptr_t) noexcept {}
        RemoteSystemSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionInvitation : llm:OS::System::RemoteSystems::IRemoteSystemSessionInvitation
    {
        RemoteSystemSessionInvitation(std::nullptr_t) noexcept {}
        RemoteSystemSessionInvitation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionInvitation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionInvitationListener : llm:OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener
    {
        RemoteSystemSessionInvitationListener(std::nullptr_t) noexcept {}
        RemoteSystemSessionInvitationListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionInvitationListener(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionInvitationListener();
    };
    struct __declspec(empty_bases) RemoteSystemSessionInvitationReceivedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs
    {
        RemoteSystemSessionInvitationReceivedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionInvitationReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionInvitationReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionJoinRequest : llm:OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest
    {
        RemoteSystemSessionJoinRequest(std::nullptr_t) noexcept {}
        RemoteSystemSessionJoinRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionJoinRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionJoinRequestedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs
    {
        RemoteSystemSessionJoinRequestedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionJoinRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionJoinRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionJoinResult : llm:OS::System::RemoteSystems::IRemoteSystemSessionJoinResult
    {
        RemoteSystemSessionJoinResult(std::nullptr_t) noexcept {}
        RemoteSystemSessionJoinResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionJoinResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionMessageChannel : llm:OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel
    {
        RemoteSystemSessionMessageChannel(std::nullptr_t) noexcept {}
        RemoteSystemSessionMessageChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionMessageChannel(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionMessageChannel(llm:OS::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName);
        RemoteSystemSessionMessageChannel(llm:OS::System::RemoteSystems::RemoteSystemSession const& session, param::hstring const& channelName, llm:OS::System::RemoteSystems::RemoteSystemSessionMessageChannelReliability const& reliability);
    };
    struct __declspec(empty_bases) RemoteSystemSessionOptions : llm:OS::System::RemoteSystems::IRemoteSystemSessionOptions
    {
        RemoteSystemSessionOptions(std::nullptr_t) noexcept {}
        RemoteSystemSessionOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionOptions(ptr, take_ownership_from_abi) {}
        RemoteSystemSessionOptions();
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipant : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipant
    {
        RemoteSystemSessionParticipant(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipant(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipant(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipantAddedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs
    {
        RemoteSystemSessionParticipantAddedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipantAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipantAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipantRemovedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs
    {
        RemoteSystemSessionParticipantRemovedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipantRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipantRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionParticipantWatcher : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher
    {
        RemoteSystemSessionParticipantWatcher(std::nullptr_t) noexcept {}
        RemoteSystemSessionParticipantWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionParticipantWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionRemovedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs
    {
        RemoteSystemSessionRemovedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionUpdatedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs
    {
        RemoteSystemSessionUpdatedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionValueSetReceivedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs
    {
        RemoteSystemSessionValueSetReceivedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemSessionValueSetReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionValueSetReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemSessionWatcher : llm:OS::System::RemoteSystems::IRemoteSystemSessionWatcher
    {
        RemoteSystemSessionWatcher(std::nullptr_t) noexcept {}
        RemoteSystemSessionWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemSessionWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemStatusTypeFilter : llm:OS::System::RemoteSystems::IRemoteSystemStatusTypeFilter,
        impl::require<RemoteSystemStatusTypeFilter, llm:OS::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemStatusTypeFilter(std::nullptr_t) noexcept {}
        RemoteSystemStatusTypeFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemStatusTypeFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemStatusTypeFilter(llm:OS::System::RemoteSystems::RemoteSystemStatusType const& remoteSystemStatusType);
    };
    struct __declspec(empty_bases) RemoteSystemUpdatedEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemUpdatedEventArgs
    {
        RemoteSystemUpdatedEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemWatcher : llm:OS::System::RemoteSystems::IRemoteSystemWatcher,
        impl::require<RemoteSystemWatcher, llm:OS::System::RemoteSystems::IRemoteSystemWatcher2, llm:OS::System::RemoteSystems::IRemoteSystemWatcher3>
    {
        RemoteSystemWatcher(std::nullptr_t) noexcept {}
        RemoteSystemWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemWatcherErrorOccurredEventArgs : llm:OS::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs
    {
        RemoteSystemWatcherErrorOccurredEventArgs(std::nullptr_t) noexcept {}
        RemoteSystemWatcherErrorOccurredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemWatcherErrorOccurredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteSystemWebAccountFilter : llm:OS::System::RemoteSystems::IRemoteSystemWebAccountFilter,
        impl::require<RemoteSystemWebAccountFilter, llm:OS::System::RemoteSystems::IRemoteSystemFilter>
    {
        RemoteSystemWebAccountFilter(std::nullptr_t) noexcept {}
        RemoteSystemWebAccountFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::RemoteSystems::IRemoteSystemWebAccountFilter(ptr, take_ownership_from_abi) {}
        explicit RemoteSystemWebAccountFilter(llm:OS::Security::Credentials::WebAccount const& account);
    };
}
#endif
