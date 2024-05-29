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
#ifndef LLM_OS_ApplicationModel_Email_2_H
#define LLM_OS_ApplicationModel_Email_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.Email.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Email
{
    struct __declspec(empty_bases) EmailAttachment : llm::OS::ApplicationModel::Email::IEmailAttachment,
        impl::require<EmailAttachment, llm::OS::ApplicationModel::Email::IEmailAttachment2>
    {
        EmailAttachment(std::nullptr_t) noexcept {}
        EmailAttachment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailAttachment(ptr, take_ownership_from_abi) {}
        EmailAttachment();
        EmailAttachment(param::hstring const& fileName, llm::OS::Storage::Streams::IRandomAccessStreamReference const& data);
        EmailAttachment(param::hstring const& fileName, llm::OS::Storage::Streams::IRandomAccessStreamReference const& data, param::hstring const& mimeType);
    };
    struct __declspec(empty_bases) EmailConversation : llm::OS::ApplicationModel::Email::IEmailConversation
    {
        EmailConversation(std::nullptr_t) noexcept {}
        EmailConversation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailConversation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailConversationBatch : llm::OS::ApplicationModel::Email::IEmailConversationBatch
    {
        EmailConversationBatch(std::nullptr_t) noexcept {}
        EmailConversationBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailConversationBatch(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailConversationReader : llm::OS::ApplicationModel::Email::IEmailConversationReader
    {
        EmailConversationReader(std::nullptr_t) noexcept {}
        EmailConversationReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailConversationReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailFolder : llm::OS::ApplicationModel::Email::IEmailFolder
    {
        EmailFolder(std::nullptr_t) noexcept {}
        EmailFolder(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailFolder(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailIrmInfo : llm::OS::ApplicationModel::Email::IEmailIrmInfo
    {
        EmailIrmInfo(std::nullptr_t) noexcept {}
        EmailIrmInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailIrmInfo(ptr, take_ownership_from_abi) {}
        EmailIrmInfo();
        EmailIrmInfo(llm::OS::Foundation::DateTime const& expiration, llm::OS::ApplicationModel::Email::EmailIrmTemplate const& irmTemplate);
    };
    struct __declspec(empty_bases) EmailIrmTemplate : llm::OS::ApplicationModel::Email::IEmailIrmTemplate
    {
        EmailIrmTemplate(std::nullptr_t) noexcept {}
        EmailIrmTemplate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailIrmTemplate(ptr, take_ownership_from_abi) {}
        EmailIrmTemplate();
        EmailIrmTemplate(param::hstring const& id, param::hstring const& name, param::hstring const& description);
    };
    struct __declspec(empty_bases) EmailItemCounts : llm::OS::ApplicationModel::Email::IEmailItemCounts
    {
        EmailItemCounts(std::nullptr_t) noexcept {}
        EmailItemCounts(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailItemCounts(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailbox : llm::OS::ApplicationModel::Email::IEmailMailbox,
        impl::require<EmailMailbox, llm::OS::ApplicationModel::Email::IEmailMailbox2, llm::OS::ApplicationModel::Email::IEmailMailbox3, llm::OS::ApplicationModel::Email::IEmailMailbox4, llm::OS::ApplicationModel::Email::IEmailMailbox5>
    {
        EmailMailbox(std::nullptr_t) noexcept {}
        EmailMailbox(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailbox(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxAction : llm::OS::ApplicationModel::Email::IEmailMailboxAction
    {
        EmailMailboxAction(std::nullptr_t) noexcept {}
        EmailMailboxAction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxAutoReply : llm::OS::ApplicationModel::Email::IEmailMailboxAutoReply
    {
        EmailMailboxAutoReply(std::nullptr_t) noexcept {}
        EmailMailboxAutoReply(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxAutoReply(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxAutoReplySettings : llm::OS::ApplicationModel::Email::IEmailMailboxAutoReplySettings
    {
        EmailMailboxAutoReplySettings(std::nullptr_t) noexcept {}
        EmailMailboxAutoReplySettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxAutoReplySettings(ptr, take_ownership_from_abi) {}
        EmailMailboxAutoReplySettings();
    };
    struct __declspec(empty_bases) EmailMailboxCapabilities : llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities,
        impl::require<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>
    {
        EmailMailboxCapabilities(std::nullptr_t) noexcept {}
        EmailMailboxCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities(ptr, take_ownership_from_abi) {}
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanCreateFolder;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanCreateFolder;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanDeleteFolder;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanDeleteFolder;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanEmptyFolder;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanEmptyFolder;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanForwardMeetings;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanForwardMeetings;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanGetAndSetExternalAutoReplies;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanGetAndSetExternalAutoReplies;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanGetAndSetInternalAutoReplies;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanGetAndSetInternalAutoReplies;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanMoveFolder;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanMoveFolder;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanProposeNewTimeForMeetings;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanProposeNewTimeForMeetings;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanResolveRecipients;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanResolveRecipients;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanServerSearchFolders;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanServerSearchFolders;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanServerSearchMailbox;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanServerSearchMailbox;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanSmartSend;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanSmartSend;
        using llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities::CanUpdateMeetingResponses;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanUpdateMeetingResponses;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities2>::CanValidateCertificates;
        using impl::consume_t<EmailMailboxCapabilities, llm::OS::ApplicationModel::Email::IEmailMailboxCapabilities3>::CanValidateCertificates;
    };
    struct __declspec(empty_bases) EmailMailboxChange : llm::OS::ApplicationModel::Email::IEmailMailboxChange
    {
        EmailMailboxChange(std::nullptr_t) noexcept {}
        EmailMailboxChange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxChangeReader : llm::OS::ApplicationModel::Email::IEmailMailboxChangeReader
    {
        EmailMailboxChangeReader(std::nullptr_t) noexcept {}
        EmailMailboxChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxChangeReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxChangeTracker : llm::OS::ApplicationModel::Email::IEmailMailboxChangeTracker
    {
        EmailMailboxChangeTracker(std::nullptr_t) noexcept {}
        EmailMailboxChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxChangeTracker(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxChangedDeferral : llm::OS::ApplicationModel::Email::IEmailMailboxChangedDeferral
    {
        EmailMailboxChangedDeferral(std::nullptr_t) noexcept {}
        EmailMailboxChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxChangedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxChangedEventArgs : llm::OS::ApplicationModel::Email::IEmailMailboxChangedEventArgs
    {
        EmailMailboxChangedEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxCreateFolderResult : llm::OS::ApplicationModel::Email::IEmailMailboxCreateFolderResult
    {
        EmailMailboxCreateFolderResult(std::nullptr_t) noexcept {}
        EmailMailboxCreateFolderResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxCreateFolderResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxPolicies : llm::OS::ApplicationModel::Email::IEmailMailboxPolicies,
        impl::require<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies2, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>
    {
        EmailMailboxPolicies(std::nullptr_t) noexcept {}
        EmailMailboxPolicies(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxPolicies(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Email::IEmailMailboxPolicies::AllowSmimeSoftCertificates;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>::AllowSmimeSoftCertificates;
        using llm::OS::ApplicationModel::Email::IEmailMailboxPolicies::AllowedSmimeEncryptionAlgorithmNegotiation;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>::AllowedSmimeEncryptionAlgorithmNegotiation;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies2>::MustEncryptSmimeMessages;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>::MustEncryptSmimeMessages;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies2>::MustSignSmimeMessages;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>::MustSignSmimeMessages;
        using llm::OS::ApplicationModel::Email::IEmailMailboxPolicies::RequiredSmimeEncryptionAlgorithm;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>::RequiredSmimeEncryptionAlgorithm;
        using llm::OS::ApplicationModel::Email::IEmailMailboxPolicies::RequiredSmimeSigningAlgorithm;
        using impl::consume_t<EmailMailboxPolicies, llm::OS::ApplicationModel::Email::IEmailMailboxPolicies3>::RequiredSmimeSigningAlgorithm;
    };
    struct __declspec(empty_bases) EmailMailboxSyncManager : llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager,
        impl::require<EmailMailboxSyncManager, llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager2>
    {
        EmailMailboxSyncManager(std::nullptr_t) noexcept {}
        EmailMailboxSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager::LastAttemptedSyncTime;
        using impl::consume_t<EmailMailboxSyncManager, llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager2>::LastAttemptedSyncTime;
        using llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager::LastSuccessfulSyncTime;
        using impl::consume_t<EmailMailboxSyncManager, llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager2>::LastSuccessfulSyncTime;
        using llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager::Status;
        using impl::consume_t<EmailMailboxSyncManager, llm::OS::ApplicationModel::Email::IEmailMailboxSyncManager2>::Status;
    };
    struct EmailManager
    {
        EmailManager() = delete;
        static auto ShowComposeNewEmailAsync(llm::OS::ApplicationModel::Email::EmailMessage const& message);
        static auto RequestStoreAsync(llm::OS::ApplicationModel::Email::EmailStoreAccessType const& accessType);
        static auto GetForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) EmailManagerForUser : llm::OS::ApplicationModel::Email::IEmailManagerForUser
    {
        EmailManagerForUser(std::nullptr_t) noexcept {}
        EmailManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMeetingInfo : llm::OS::ApplicationModel::Email::IEmailMeetingInfo,
        impl::require<EmailMeetingInfo, llm::OS::ApplicationModel::Email::IEmailMeetingInfo2>
    {
        EmailMeetingInfo(std::nullptr_t) noexcept {}
        EmailMeetingInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMeetingInfo(ptr, take_ownership_from_abi) {}
        EmailMeetingInfo();
    };
    struct __declspec(empty_bases) EmailMessage : llm::OS::ApplicationModel::Email::IEmailMessage,
        impl::require<EmailMessage, llm::OS::ApplicationModel::Email::IEmailMessage2, llm::OS::ApplicationModel::Email::IEmailMessage3, llm::OS::ApplicationModel::Email::IEmailMessage4>
    {
        EmailMessage(std::nullptr_t) noexcept {}
        EmailMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMessage(ptr, take_ownership_from_abi) {}
        EmailMessage();
    };
    struct __declspec(empty_bases) EmailMessageBatch : llm::OS::ApplicationModel::Email::IEmailMessageBatch
    {
        EmailMessageBatch(std::nullptr_t) noexcept {}
        EmailMessageBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMessageBatch(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMessageReader : llm::OS::ApplicationModel::Email::IEmailMessageReader
    {
        EmailMessageReader(std::nullptr_t) noexcept {}
        EmailMessageReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailMessageReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailQueryOptions : llm::OS::ApplicationModel::Email::IEmailQueryOptions
    {
        EmailQueryOptions(std::nullptr_t) noexcept {}
        EmailQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailQueryOptions(ptr, take_ownership_from_abi) {}
        EmailQueryOptions();
        explicit EmailQueryOptions(param::hstring const& text);
        EmailQueryOptions(param::hstring const& text, llm::OS::ApplicationModel::Email::EmailQuerySearchFields const& fields);
    };
    struct __declspec(empty_bases) EmailQueryTextSearch : llm::OS::ApplicationModel::Email::IEmailQueryTextSearch
    {
        EmailQueryTextSearch(std::nullptr_t) noexcept {}
        EmailQueryTextSearch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailQueryTextSearch(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailRecipient : llm::OS::ApplicationModel::Email::IEmailRecipient
    {
        EmailRecipient(std::nullptr_t) noexcept {}
        EmailRecipient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailRecipient(ptr, take_ownership_from_abi) {}
        EmailRecipient();
        explicit EmailRecipient(param::hstring const& address);
        EmailRecipient(param::hstring const& address, param::hstring const& name);
    };
    struct __declspec(empty_bases) EmailRecipientResolutionResult : llm::OS::ApplicationModel::Email::IEmailRecipientResolutionResult,
        impl::require<EmailRecipientResolutionResult, llm::OS::ApplicationModel::Email::IEmailRecipientResolutionResult2>
    {
        EmailRecipientResolutionResult(std::nullptr_t) noexcept {}
        EmailRecipientResolutionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailRecipientResolutionResult(ptr, take_ownership_from_abi) {}
        EmailRecipientResolutionResult();
        using llm::OS::ApplicationModel::Email::IEmailRecipientResolutionResult::Status;
        using impl::consume_t<EmailRecipientResolutionResult, llm::OS::ApplicationModel::Email::IEmailRecipientResolutionResult2>::Status;
    };
    struct __declspec(empty_bases) EmailStore : llm::OS::ApplicationModel::Email::IEmailStore
    {
        EmailStore(std::nullptr_t) noexcept {}
        EmailStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailStoreNotificationTriggerDetails : llm::OS::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails
    {
        EmailStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
        EmailStoreNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::IEmailStoreNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
}
#endif
