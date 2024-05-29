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
#ifndef LLM_OS_ApplicationModel_Email_DataProvider_1_H
#define LLM_OS_ApplicationModel_Email_DataProvider_1_H
#include "llm/impl/Windows.ApplicationModel.Email.DataProvider.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Email::DataProvider
{
    struct __declspec(empty_bases) IEmailDataProviderConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailDataProviderConnection>
    {
        IEmailDataProviderConnection(std::nullptr_t = nullptr) noexcept {}
        IEmailDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailDataProviderTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailDataProviderTriggerDetails>
    {
        IEmailDataProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IEmailDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxCreateFolderRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxCreateFolderRequest>
    {
        IEmailMailboxCreateFolderRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxCreateFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxCreateFolderRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxCreateFolderRequestEventArgs>
    {
        IEmailMailboxCreateFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxCreateFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxDeleteFolderRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxDeleteFolderRequest>
    {
        IEmailMailboxDeleteFolderRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxDeleteFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxDeleteFolderRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxDeleteFolderRequestEventArgs>
    {
        IEmailMailboxDeleteFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxDeleteFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxDownloadAttachmentRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxDownloadAttachmentRequest>
    {
        IEmailMailboxDownloadAttachmentRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxDownloadAttachmentRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxDownloadAttachmentRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxDownloadAttachmentRequestEventArgs>
    {
        IEmailMailboxDownloadAttachmentRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxDownloadAttachmentRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxDownloadMessageRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxDownloadMessageRequest>
    {
        IEmailMailboxDownloadMessageRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxDownloadMessageRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxDownloadMessageRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxDownloadMessageRequestEventArgs>
    {
        IEmailMailboxDownloadMessageRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxDownloadMessageRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxEmptyFolderRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxEmptyFolderRequest>
    {
        IEmailMailboxEmptyFolderRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxEmptyFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxEmptyFolderRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxEmptyFolderRequestEventArgs>
    {
        IEmailMailboxEmptyFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxEmptyFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxForwardMeetingRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxForwardMeetingRequest>
    {
        IEmailMailboxForwardMeetingRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxForwardMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxForwardMeetingRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxForwardMeetingRequestEventArgs>
    {
        IEmailMailboxForwardMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxForwardMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxGetAutoReplySettingsRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxGetAutoReplySettingsRequest>
    {
        IEmailMailboxGetAutoReplySettingsRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxGetAutoReplySettingsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxGetAutoReplySettingsRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxGetAutoReplySettingsRequestEventArgs>
    {
        IEmailMailboxGetAutoReplySettingsRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxGetAutoReplySettingsRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxMoveFolderRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxMoveFolderRequest>
    {
        IEmailMailboxMoveFolderRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxMoveFolderRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxMoveFolderRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxMoveFolderRequestEventArgs>
    {
        IEmailMailboxMoveFolderRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxMoveFolderRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxProposeNewTimeForMeetingRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxProposeNewTimeForMeetingRequest>
    {
        IEmailMailboxProposeNewTimeForMeetingRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxProposeNewTimeForMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxProposeNewTimeForMeetingRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxProposeNewTimeForMeetingRequestEventArgs>
    {
        IEmailMailboxProposeNewTimeForMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxProposeNewTimeForMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxResolveRecipientsRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxResolveRecipientsRequest>
    {
        IEmailMailboxResolveRecipientsRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxResolveRecipientsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxResolveRecipientsRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxResolveRecipientsRequestEventArgs>
    {
        IEmailMailboxResolveRecipientsRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxResolveRecipientsRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxServerSearchReadBatchRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxServerSearchReadBatchRequest>
    {
        IEmailMailboxServerSearchReadBatchRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxServerSearchReadBatchRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxServerSearchReadBatchRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxServerSearchReadBatchRequestEventArgs>
    {
        IEmailMailboxServerSearchReadBatchRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxServerSearchReadBatchRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxSetAutoReplySettingsRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxSetAutoReplySettingsRequest>
    {
        IEmailMailboxSetAutoReplySettingsRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxSetAutoReplySettingsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxSetAutoReplySettingsRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxSetAutoReplySettingsRequestEventArgs>
    {
        IEmailMailboxSetAutoReplySettingsRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxSetAutoReplySettingsRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxSyncManagerSyncRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxSyncManagerSyncRequest>
    {
        IEmailMailboxSyncManagerSyncRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxSyncManagerSyncRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxSyncManagerSyncRequestEventArgs>
    {
        IEmailMailboxSyncManagerSyncRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxUpdateMeetingResponseRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxUpdateMeetingResponseRequest>
    {
        IEmailMailboxUpdateMeetingResponseRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxUpdateMeetingResponseRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxUpdateMeetingResponseRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxUpdateMeetingResponseRequestEventArgs>
    {
        IEmailMailboxUpdateMeetingResponseRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxUpdateMeetingResponseRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxValidateCertificatesRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxValidateCertificatesRequest>
    {
        IEmailMailboxValidateCertificatesRequest(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxValidateCertificatesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEmailMailboxValidateCertificatesRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IEmailMailboxValidateCertificatesRequestEventArgs>
    {
        IEmailMailboxValidateCertificatesRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEmailMailboxValidateCertificatesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
