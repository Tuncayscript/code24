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
#ifndef LLM_OS_ApplicationModel_Email_DataProvider_2_H
#define LLM_OS_ApplicationModel_Email_DataProvider_2_H
#include "llm/impl/Windows.ApplicationModel.Email.DataProvider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Email::DataProvider
{
    struct __declspec(empty_bases) EmailDataProviderConnection : llm::OS::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection
    {
        EmailDataProviderConnection(std::nullptr_t) noexcept {}
        EmailDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailDataProviderConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailDataProviderTriggerDetails : llm::OS::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails
    {
        EmailDataProviderTriggerDetails(std::nullptr_t) noexcept {}
        EmailDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailDataProviderTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxCreateFolderRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest
    {
        EmailMailboxCreateFolderRequest(std::nullptr_t) noexcept {}
        EmailMailboxCreateFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxCreateFolderRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs
    {
        EmailMailboxCreateFolderRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxCreateFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxCreateFolderRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxDeleteFolderRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest
    {
        EmailMailboxDeleteFolderRequest(std::nullptr_t) noexcept {}
        EmailMailboxDeleteFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxDeleteFolderRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs
    {
        EmailMailboxDeleteFolderRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxDeleteFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDeleteFolderRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxDownloadAttachmentRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest
    {
        EmailMailboxDownloadAttachmentRequest(std::nullptr_t) noexcept {}
        EmailMailboxDownloadAttachmentRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxDownloadAttachmentRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs
    {
        EmailMailboxDownloadAttachmentRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxDownloadAttachmentRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadAttachmentRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxDownloadMessageRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest
    {
        EmailMailboxDownloadMessageRequest(std::nullptr_t) noexcept {}
        EmailMailboxDownloadMessageRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxDownloadMessageRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs
    {
        EmailMailboxDownloadMessageRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxDownloadMessageRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxDownloadMessageRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxEmptyFolderRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest
    {
        EmailMailboxEmptyFolderRequest(std::nullptr_t) noexcept {}
        EmailMailboxEmptyFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxEmptyFolderRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs
    {
        EmailMailboxEmptyFolderRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxEmptyFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxEmptyFolderRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxForwardMeetingRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest
    {
        EmailMailboxForwardMeetingRequest(std::nullptr_t) noexcept {}
        EmailMailboxForwardMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxForwardMeetingRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs
    {
        EmailMailboxForwardMeetingRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxForwardMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxForwardMeetingRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxGetAutoReplySettingsRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest
    {
        EmailMailboxGetAutoReplySettingsRequest(std::nullptr_t) noexcept {}
        EmailMailboxGetAutoReplySettingsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxGetAutoReplySettingsRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs
    {
        EmailMailboxGetAutoReplySettingsRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxGetAutoReplySettingsRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxGetAutoReplySettingsRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxMoveFolderRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest
    {
        EmailMailboxMoveFolderRequest(std::nullptr_t) noexcept {}
        EmailMailboxMoveFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxMoveFolderRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs
    {
        EmailMailboxMoveFolderRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxMoveFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxMoveFolderRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxProposeNewTimeForMeetingRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest
    {
        EmailMailboxProposeNewTimeForMeetingRequest(std::nullptr_t) noexcept {}
        EmailMailboxProposeNewTimeForMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxProposeNewTimeForMeetingRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs
    {
        EmailMailboxProposeNewTimeForMeetingRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxProposeNewTimeForMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxProposeNewTimeForMeetingRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxResolveRecipientsRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest
    {
        EmailMailboxResolveRecipientsRequest(std::nullptr_t) noexcept {}
        EmailMailboxResolveRecipientsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxResolveRecipientsRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs
    {
        EmailMailboxResolveRecipientsRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxResolveRecipientsRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxResolveRecipientsRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxServerSearchReadBatchRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest
    {
        EmailMailboxServerSearchReadBatchRequest(std::nullptr_t) noexcept {}
        EmailMailboxServerSearchReadBatchRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxServerSearchReadBatchRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs
    {
        EmailMailboxServerSearchReadBatchRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxServerSearchReadBatchRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxServerSearchReadBatchRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxSetAutoReplySettingsRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest
    {
        EmailMailboxSetAutoReplySettingsRequest(std::nullptr_t) noexcept {}
        EmailMailboxSetAutoReplySettingsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxSetAutoReplySettingsRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs
    {
        EmailMailboxSetAutoReplySettingsRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxSetAutoReplySettingsRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSetAutoReplySettingsRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxSyncManagerSyncRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest
    {
        EmailMailboxSyncManagerSyncRequest(std::nullptr_t) noexcept {}
        EmailMailboxSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxSyncManagerSyncRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs
    {
        EmailMailboxSyncManagerSyncRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxSyncManagerSyncRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxUpdateMeetingResponseRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest
    {
        EmailMailboxUpdateMeetingResponseRequest(std::nullptr_t) noexcept {}
        EmailMailboxUpdateMeetingResponseRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxUpdateMeetingResponseRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs
    {
        EmailMailboxUpdateMeetingResponseRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxUpdateMeetingResponseRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxUpdateMeetingResponseRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxValidateCertificatesRequest : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest
    {
        EmailMailboxValidateCertificatesRequest(std::nullptr_t) noexcept {}
        EmailMailboxValidateCertificatesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EmailMailboxValidateCertificatesRequestEventArgs : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs
    {
        EmailMailboxValidateCertificatesRequestEventArgs(std::nullptr_t) noexcept {}
        EmailMailboxValidateCertificatesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Email::DataProvider::IEmailMailboxValidateCertificatesRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
