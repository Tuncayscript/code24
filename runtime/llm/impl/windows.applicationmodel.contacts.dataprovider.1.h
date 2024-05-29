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
#ifndef LLM_OS_ApplicationModel_Contacts_DataProvider_1_H
#define LLM_OS_ApplicationModel_Contacts_DataProvider_1_H
#include "llm/impl/Windows.ApplicationModel.Contacts.DataProvider.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts::DataProvider
{
    struct __declspec(empty_bases) IContactDataProviderConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactDataProviderConnection>
    {
        IContactDataProviderConnection(std::nullptr_t = nullptr) noexcept {}
        IContactDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactDataProviderConnection2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactDataProviderConnection2>
    {
        IContactDataProviderConnection2(std::nullptr_t = nullptr) noexcept {}
        IContactDataProviderConnection2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactDataProviderTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactDataProviderTriggerDetails>
    {
        IContactDataProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IContactDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListCreateOrUpdateContactRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListCreateOrUpdateContactRequest>
    {
        IContactListCreateOrUpdateContactRequest(std::nullptr_t = nullptr) noexcept {}
        IContactListCreateOrUpdateContactRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListCreateOrUpdateContactRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListCreateOrUpdateContactRequestEventArgs>
    {
        IContactListCreateOrUpdateContactRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactListCreateOrUpdateContactRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListDeleteContactRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListDeleteContactRequest>
    {
        IContactListDeleteContactRequest(std::nullptr_t = nullptr) noexcept {}
        IContactListDeleteContactRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListDeleteContactRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListDeleteContactRequestEventArgs>
    {
        IContactListDeleteContactRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactListDeleteContactRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListServerSearchReadBatchRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListServerSearchReadBatchRequest>
    {
        IContactListServerSearchReadBatchRequest(std::nullptr_t = nullptr) noexcept {}
        IContactListServerSearchReadBatchRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListServerSearchReadBatchRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListServerSearchReadBatchRequestEventArgs>
    {
        IContactListServerSearchReadBatchRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactListServerSearchReadBatchRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListSyncManagerSyncRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListSyncManagerSyncRequest>
    {
        IContactListSyncManagerSyncRequest(std::nullptr_t = nullptr) noexcept {}
        IContactListSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListSyncManagerSyncRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListSyncManagerSyncRequestEventArgs>
    {
        IContactListSyncManagerSyncRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactListSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
