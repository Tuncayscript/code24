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
#ifndef LLM_OS_ApplicationModel_Chat_2_H
#define LLM_OS_ApplicationModel_Chat_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.ApplicationModel.Chat.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Chat
{
    struct __declspec(empty_bases) ChatCapabilities : llm::OS::ApplicationModel::Chat::IChatCapabilities
    {
        ChatCapabilities(std::nullptr_t) noexcept {}
        ChatCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct ChatCapabilitiesManager
    {
        ChatCapabilitiesManager() = delete;
        static auto GetCachedCapabilitiesAsync(param::hstring const& address);
        static auto GetCapabilitiesFromNetworkAsync(param::hstring const& address);
        static auto GetCachedCapabilitiesAsync(param::hstring const& address, param::hstring const& transportId);
        static auto GetCapabilitiesFromNetworkAsync(param::hstring const& address, param::hstring const& transportId);
    };
    struct __declspec(empty_bases) ChatConversation : llm::OS::ApplicationModel::Chat::IChatConversation,
        impl::require<ChatConversation, llm::OS::ApplicationModel::Chat::IChatConversation2, llm::OS::ApplicationModel::Chat::IChatItem>
    {
        ChatConversation(std::nullptr_t) noexcept {}
        ChatConversation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatConversation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatConversationReader : llm::OS::ApplicationModel::Chat::IChatConversationReader
    {
        ChatConversationReader(std::nullptr_t) noexcept {}
        ChatConversationReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatConversationReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatConversationThreadingInfo : llm::OS::ApplicationModel::Chat::IChatConversationThreadingInfo
    {
        ChatConversationThreadingInfo(std::nullptr_t) noexcept {}
        ChatConversationThreadingInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatConversationThreadingInfo(ptr, take_ownership_from_abi) {}
        ChatConversationThreadingInfo();
    };
    struct __declspec(empty_bases) ChatMessage : llm::OS::ApplicationModel::Chat::IChatMessage,
        impl::require<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage3, llm::OS::ApplicationModel::Chat::IChatMessage2, llm::OS::ApplicationModel::Chat::IChatMessage4, llm::OS::ApplicationModel::Chat::IChatItem>
    {
        ChatMessage(std::nullptr_t) noexcept {}
        ChatMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessage(ptr, take_ownership_from_abi) {}
        ChatMessage();
        using llm::OS::ApplicationModel::Chat::IChatMessage::From;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::From;
        using llm::OS::ApplicationModel::Chat::IChatMessage::IsForwardingDisabled;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::IsForwardingDisabled;
        using llm::OS::ApplicationModel::Chat::IChatMessage::IsIncoming;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::IsIncoming;
        using llm::OS::ApplicationModel::Chat::IChatMessage::IsRead;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::IsRead;
        using llm::OS::ApplicationModel::Chat::IChatMessage::LocalTimestamp;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::LocalTimestamp;
        using llm::OS::ApplicationModel::Chat::IChatMessage::NetworkTimestamp;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::NetworkTimestamp;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::RemoteId;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage3>::RemoteId;
        using llm::OS::ApplicationModel::Chat::IChatMessage::Status;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::Status;
        using llm::OS::ApplicationModel::Chat::IChatMessage::Subject;
        using impl::consume_t<ChatMessage, llm::OS::ApplicationModel::Chat::IChatMessage2>::Subject;
    };
    struct __declspec(empty_bases) ChatMessageAttachment : llm::OS::ApplicationModel::Chat::IChatMessageAttachment,
        impl::require<ChatMessageAttachment, llm::OS::ApplicationModel::Chat::IChatMessageAttachment2>
    {
        ChatMessageAttachment(std::nullptr_t) noexcept {}
        ChatMessageAttachment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageAttachment(ptr, take_ownership_from_abi) {}
        ChatMessageAttachment(param::hstring const& mimeType, llm::OS::Storage::Streams::IRandomAccessStreamReference const& dataStreamReference);
    };
    struct ChatMessageBlocking
    {
        ChatMessageBlocking() = delete;
        static auto MarkMessageAsBlockedAsync(param::hstring const& localChatMessageId, bool blocked);
    };
    struct __declspec(empty_bases) ChatMessageChange : llm::OS::ApplicationModel::Chat::IChatMessageChange
    {
        ChatMessageChange(std::nullptr_t) noexcept {}
        ChatMessageChange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageChangeReader : llm::OS::ApplicationModel::Chat::IChatMessageChangeReader
    {
        ChatMessageChangeReader(std::nullptr_t) noexcept {}
        ChatMessageChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageChangeReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageChangeTracker : llm::OS::ApplicationModel::Chat::IChatMessageChangeTracker
    {
        ChatMessageChangeTracker(std::nullptr_t) noexcept {}
        ChatMessageChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageChangeTracker(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageChangedDeferral : llm::OS::ApplicationModel::Chat::IChatMessageChangedDeferral
    {
        ChatMessageChangedDeferral(std::nullptr_t) noexcept {}
        ChatMessageChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageChangedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageChangedEventArgs : llm::OS::ApplicationModel::Chat::IChatMessageChangedEventArgs
    {
        ChatMessageChangedEventArgs(std::nullptr_t) noexcept {}
        ChatMessageChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct ChatMessageManager
    {
        ChatMessageManager() = delete;
        static auto RegisterTransportAsync();
        static auto GetTransportAsync(param::hstring const& transportId);
        static auto GetTransportsAsync();
        static auto RequestStoreAsync();
        static auto ShowComposeSmsMessageAsync(llm::OS::ApplicationModel::Chat::ChatMessage const& message);
        static auto ShowSmsSettings();
        static auto RequestSyncManagerAsync();
    };
    struct __declspec(empty_bases) ChatMessageNotificationTriggerDetails : llm::OS::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails,
        impl::require<ChatMessageNotificationTriggerDetails, llm::OS::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails2>
    {
        ChatMessageNotificationTriggerDetails(std::nullptr_t) noexcept {}
        ChatMessageNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageReader : llm::OS::ApplicationModel::Chat::IChatMessageReader,
        impl::require<ChatMessageReader, llm::OS::ApplicationModel::Chat::IChatMessageReader2>
    {
        ChatMessageReader(std::nullptr_t) noexcept {}
        ChatMessageReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageReader(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Chat::IChatMessageReader::ReadBatchAsync;
        using impl::consume_t<ChatMessageReader, llm::OS::ApplicationModel::Chat::IChatMessageReader2>::ReadBatchAsync;
    };
    struct __declspec(empty_bases) ChatMessageStore : llm::OS::ApplicationModel::Chat::IChatMessageStore,
        impl::require<ChatMessageStore, llm::OS::ApplicationModel::Chat::IChatMessageStore2, llm::OS::ApplicationModel::Chat::IChatMessageStore3>
    {
        ChatMessageStore(std::nullptr_t) noexcept {}
        ChatMessageStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageStoreChangedEventArgs : llm::OS::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs
    {
        ChatMessageStoreChangedEventArgs(std::nullptr_t) noexcept {}
        ChatMessageStoreChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageStoreChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageTransport : llm::OS::ApplicationModel::Chat::IChatMessageTransport,
        impl::require<ChatMessageTransport, llm::OS::ApplicationModel::Chat::IChatMessageTransport2>
    {
        ChatMessageTransport(std::nullptr_t) noexcept {}
        ChatMessageTransport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageTransport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageTransportConfiguration : llm::OS::ApplicationModel::Chat::IChatMessageTransportConfiguration
    {
        ChatMessageTransportConfiguration(std::nullptr_t) noexcept {}
        ChatMessageTransportConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageTransportConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatMessageValidationResult : llm::OS::ApplicationModel::Chat::IChatMessageValidationResult
    {
        ChatMessageValidationResult(std::nullptr_t) noexcept {}
        ChatMessageValidationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatMessageValidationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatQueryOptions : llm::OS::ApplicationModel::Chat::IChatQueryOptions
    {
        ChatQueryOptions(std::nullptr_t) noexcept {}
        ChatQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatQueryOptions(ptr, take_ownership_from_abi) {}
        ChatQueryOptions();
    };
    struct __declspec(empty_bases) ChatRecipientDeliveryInfo : llm::OS::ApplicationModel::Chat::IChatRecipientDeliveryInfo
    {
        ChatRecipientDeliveryInfo(std::nullptr_t) noexcept {}
        ChatRecipientDeliveryInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatRecipientDeliveryInfo(ptr, take_ownership_from_abi) {}
        ChatRecipientDeliveryInfo();
    };
    struct __declspec(empty_bases) ChatSearchReader : llm::OS::ApplicationModel::Chat::IChatSearchReader
    {
        ChatSearchReader(std::nullptr_t) noexcept {}
        ChatSearchReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatSearchReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatSyncConfiguration : llm::OS::ApplicationModel::Chat::IChatSyncConfiguration
    {
        ChatSyncConfiguration(std::nullptr_t) noexcept {}
        ChatSyncConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatSyncConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ChatSyncManager : llm::OS::ApplicationModel::Chat::IChatSyncManager
    {
        ChatSyncManager(std::nullptr_t) noexcept {}
        ChatSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IChatSyncManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsEndUserMessage : llm::OS::ApplicationModel::Chat::IRcsEndUserMessage
    {
        RcsEndUserMessage(std::nullptr_t) noexcept {}
        RcsEndUserMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsEndUserMessage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsEndUserMessageAction : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageAction
    {
        RcsEndUserMessageAction(std::nullptr_t) noexcept {}
        RcsEndUserMessageAction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsEndUserMessageAvailableEventArgs : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs
    {
        RcsEndUserMessageAvailableEventArgs(std::nullptr_t) noexcept {}
        RcsEndUserMessageAvailableEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageAvailableEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsEndUserMessageAvailableTriggerDetails : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails
    {
        RcsEndUserMessageAvailableTriggerDetails(std::nullptr_t) noexcept {}
        RcsEndUserMessageAvailableTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageAvailableTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsEndUserMessageManager : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageManager
    {
        RcsEndUserMessageManager(std::nullptr_t) noexcept {}
        RcsEndUserMessageManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsEndUserMessageManager(ptr, take_ownership_from_abi) {}
    };
    struct RcsManager
    {
        RcsManager() = delete;
        static auto GetEndUserMessageManager();
        static auto GetTransportsAsync();
        static auto GetTransportAsync(param::hstring const& transportId);
        static auto LeaveConversationAsync(llm::OS::ApplicationModel::Chat::ChatConversation const& conversation);
        static auto TransportListChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using TransportListChanged_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Chat::IRcsManagerStatics2, &impl::abi_t<llm::OS::ApplicationModel::Chat::IRcsManagerStatics2>::remove_TransportListChanged>;
        [[nodiscard]] static TransportListChanged_revoker TransportListChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto TransportListChanged(llm::event_token const& token);
    };
    struct __declspec(empty_bases) RcsServiceKindSupportedChangedEventArgs : llm::OS::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs
    {
        RcsServiceKindSupportedChangedEventArgs(std::nullptr_t) noexcept {}
        RcsServiceKindSupportedChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsServiceKindSupportedChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsTransport : llm::OS::ApplicationModel::Chat::IRcsTransport
    {
        RcsTransport(std::nullptr_t) noexcept {}
        RcsTransport(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsTransport(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RcsTransportConfiguration : llm::OS::ApplicationModel::Chat::IRcsTransportConfiguration
    {
        RcsTransportConfiguration(std::nullptr_t) noexcept {}
        RcsTransportConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRcsTransportConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RemoteParticipantComposingChangedEventArgs : llm::OS::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs
    {
        RemoteParticipantComposingChangedEventArgs(std::nullptr_t) noexcept {}
        RemoteParticipantComposingChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Chat::IRemoteParticipantComposingChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
