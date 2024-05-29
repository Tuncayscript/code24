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
#ifndef LLM_OS_ApplicationModel_UserDataTasks_DataProvider_1_H
#define LLM_OS_ApplicationModel_UserDataTasks_DataProvider_1_H
#include "llm/impl/Windows.ApplicationModel.UserDataTasks.DataProvider.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataTasks::DataProvider
{
    struct __declspec(empty_bases) IUserDataTaskDataProviderConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskDataProviderConnection>
    {
        IUserDataTaskDataProviderConnection(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskDataProviderTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskDataProviderTriggerDetails>
    {
        IUserDataTaskDataProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListCompleteTaskRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListCompleteTaskRequest>
    {
        IUserDataTaskListCompleteTaskRequest(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListCompleteTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListCompleteTaskRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListCompleteTaskRequestEventArgs>
    {
        IUserDataTaskListCompleteTaskRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListCompleteTaskRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListCreateOrUpdateTaskRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListCreateOrUpdateTaskRequest>
    {
        IUserDataTaskListCreateOrUpdateTaskRequest(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListCreateOrUpdateTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListCreateOrUpdateTaskRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListCreateOrUpdateTaskRequestEventArgs>
    {
        IUserDataTaskListCreateOrUpdateTaskRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListCreateOrUpdateTaskRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListDeleteTaskRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListDeleteTaskRequest>
    {
        IUserDataTaskListDeleteTaskRequest(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListDeleteTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListDeleteTaskRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListDeleteTaskRequestEventArgs>
    {
        IUserDataTaskListDeleteTaskRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListDeleteTaskRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListSkipOccurrenceRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListSkipOccurrenceRequest>
    {
        IUserDataTaskListSkipOccurrenceRequest(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListSkipOccurrenceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListSkipOccurrenceRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListSkipOccurrenceRequestEventArgs>
    {
        IUserDataTaskListSkipOccurrenceRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListSkipOccurrenceRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListSyncManagerSyncRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListSyncManagerSyncRequest>
    {
        IUserDataTaskListSyncManagerSyncRequest(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListSyncManagerSyncRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListSyncManagerSyncRequestEventArgs>
    {
        IUserDataTaskListSyncManagerSyncRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
