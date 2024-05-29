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
#ifndef LLM_OS_ApplicationModel_Contacts_DataProvider_2_H
#define LLM_OS_ApplicationModel_Contacts_DataProvider_2_H
#include "llm/impl/Windows.ApplicationModel.Contacts.DataProvider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts::DataProvider
{
    struct __declspec(empty_bases) ContactDataProviderConnection : llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection,
        impl::require<ContactDataProviderConnection, llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection2>
    {
        ContactDataProviderConnection(std::nullptr_t) noexcept {}
        ContactDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactDataProviderTriggerDetails : llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails
    {
        ContactDataProviderTriggerDetails(std::nullptr_t) noexcept {}
        ContactDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactDataProviderTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListCreateOrUpdateContactRequest : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest
    {
        ContactListCreateOrUpdateContactRequest(std::nullptr_t) noexcept {}
        ContactListCreateOrUpdateContactRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListCreateOrUpdateContactRequestEventArgs : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs
    {
        ContactListCreateOrUpdateContactRequestEventArgs(std::nullptr_t) noexcept {}
        ContactListCreateOrUpdateContactRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListCreateOrUpdateContactRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListDeleteContactRequest : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest
    {
        ContactListDeleteContactRequest(std::nullptr_t) noexcept {}
        ContactListDeleteContactRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListDeleteContactRequestEventArgs : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs
    {
        ContactListDeleteContactRequestEventArgs(std::nullptr_t) noexcept {}
        ContactListDeleteContactRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListDeleteContactRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListServerSearchReadBatchRequest : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest
    {
        ContactListServerSearchReadBatchRequest(std::nullptr_t) noexcept {}
        ContactListServerSearchReadBatchRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListServerSearchReadBatchRequestEventArgs : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs
    {
        ContactListServerSearchReadBatchRequestEventArgs(std::nullptr_t) noexcept {}
        ContactListServerSearchReadBatchRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListServerSearchReadBatchRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListSyncManagerSyncRequest : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest
    {
        ContactListSyncManagerSyncRequest(std::nullptr_t) noexcept {}
        ContactListSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListSyncManagerSyncRequestEventArgs : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs
    {
        ContactListSyncManagerSyncRequestEventArgs(std::nullptr_t) noexcept {}
        ContactListSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::DataProvider::IContactListSyncManagerSyncRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
