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
#ifndef LLM_OS_ApplicationModel_UserDataTasks_DataProvider_2_H
#define LLM_OS_ApplicationModel_UserDataTasks_DataProvider_2_H
#include "llm/impl/Windows.ApplicationModel.UserDataTasks.DataProvider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataTasks::DataProvider
{
    struct __declspec(empty_bases) UserDataTaskDataProviderConnection : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskDataProviderConnection
    {
        UserDataTaskDataProviderConnection(std::nullptr_t) noexcept {}
        UserDataTaskDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskDataProviderConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskDataProviderTriggerDetails : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskDataProviderTriggerDetails
    {
        UserDataTaskDataProviderTriggerDetails(std::nullptr_t) noexcept {}
        UserDataTaskDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskDataProviderTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListCompleteTaskRequest : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCompleteTaskRequest
    {
        UserDataTaskListCompleteTaskRequest(std::nullptr_t) noexcept {}
        UserDataTaskListCompleteTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCompleteTaskRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListCompleteTaskRequestEventArgs : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCompleteTaskRequestEventArgs
    {
        UserDataTaskListCompleteTaskRequestEventArgs(std::nullptr_t) noexcept {}
        UserDataTaskListCompleteTaskRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCompleteTaskRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListCreateOrUpdateTaskRequest : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCreateOrUpdateTaskRequest
    {
        UserDataTaskListCreateOrUpdateTaskRequest(std::nullptr_t) noexcept {}
        UserDataTaskListCreateOrUpdateTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCreateOrUpdateTaskRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListCreateOrUpdateTaskRequestEventArgs : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCreateOrUpdateTaskRequestEventArgs
    {
        UserDataTaskListCreateOrUpdateTaskRequestEventArgs(std::nullptr_t) noexcept {}
        UserDataTaskListCreateOrUpdateTaskRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListCreateOrUpdateTaskRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListDeleteTaskRequest : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListDeleteTaskRequest
    {
        UserDataTaskListDeleteTaskRequest(std::nullptr_t) noexcept {}
        UserDataTaskListDeleteTaskRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListDeleteTaskRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListDeleteTaskRequestEventArgs : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListDeleteTaskRequestEventArgs
    {
        UserDataTaskListDeleteTaskRequestEventArgs(std::nullptr_t) noexcept {}
        UserDataTaskListDeleteTaskRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListDeleteTaskRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListSkipOccurrenceRequest : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSkipOccurrenceRequest
    {
        UserDataTaskListSkipOccurrenceRequest(std::nullptr_t) noexcept {}
        UserDataTaskListSkipOccurrenceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSkipOccurrenceRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListSkipOccurrenceRequestEventArgs : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSkipOccurrenceRequestEventArgs
    {
        UserDataTaskListSkipOccurrenceRequestEventArgs(std::nullptr_t) noexcept {}
        UserDataTaskListSkipOccurrenceRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSkipOccurrenceRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListSyncManagerSyncRequest : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSyncManagerSyncRequest
    {
        UserDataTaskListSyncManagerSyncRequest(std::nullptr_t) noexcept {}
        UserDataTaskListSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSyncManagerSyncRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListSyncManagerSyncRequestEventArgs : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSyncManagerSyncRequestEventArgs
    {
        UserDataTaskListSyncManagerSyncRequestEventArgs(std::nullptr_t) noexcept {}
        UserDataTaskListSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::DataProvider::IUserDataTaskListSyncManagerSyncRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
