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
#ifndef LLM_OS_ApplicationModel_UserDataTasks_2_H
#define LLM_OS_ApplicationModel_UserDataTasks_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.UserDataTasks.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataTasks
{
    struct __declspec(empty_bases) UserDataTask : llm::OS::ApplicationModel::UserDataTasks::IUserDataTask
    {
        UserDataTask(std::nullptr_t) noexcept {}
        UserDataTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTask(ptr, take_ownership_from_abi) {}
        UserDataTask();
    };
    struct __declspec(empty_bases) UserDataTaskBatch : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskBatch
    {
        UserDataTaskBatch(std::nullptr_t) noexcept {}
        UserDataTaskBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskBatch(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskList : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskList
    {
        UserDataTaskList(std::nullptr_t) noexcept {}
        UserDataTaskList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskList(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListLimitedWriteOperations : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskListLimitedWriteOperations
    {
        UserDataTaskListLimitedWriteOperations(std::nullptr_t) noexcept {}
        UserDataTaskListLimitedWriteOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskListLimitedWriteOperations(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskListSyncManager : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskListSyncManager
    {
        UserDataTaskListSyncManager(std::nullptr_t) noexcept {}
        UserDataTaskListSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskListSyncManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskManager : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskManager
    {
        UserDataTaskManager(std::nullptr_t) noexcept {}
        UserDataTaskManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) UserDataTaskQueryOptions : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskQueryOptions
    {
        UserDataTaskQueryOptions(std::nullptr_t) noexcept {}
        UserDataTaskQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskQueryOptions(ptr, take_ownership_from_abi) {}
        UserDataTaskQueryOptions();
    };
    struct __declspec(empty_bases) UserDataTaskReader : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskReader
    {
        UserDataTaskReader(std::nullptr_t) noexcept {}
        UserDataTaskReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataTaskRecurrenceProperties : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskRecurrenceProperties
    {
        UserDataTaskRecurrenceProperties(std::nullptr_t) noexcept {}
        UserDataTaskRecurrenceProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskRecurrenceProperties(ptr, take_ownership_from_abi) {}
        UserDataTaskRecurrenceProperties();
    };
    struct __declspec(empty_bases) UserDataTaskRegenerationProperties : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskRegenerationProperties
    {
        UserDataTaskRegenerationProperties(std::nullptr_t) noexcept {}
        UserDataTaskRegenerationProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskRegenerationProperties(ptr, take_ownership_from_abi) {}
        UserDataTaskRegenerationProperties();
    };
    struct __declspec(empty_bases) UserDataTaskStore : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskStore
    {
        UserDataTaskStore(std::nullptr_t) noexcept {}
        UserDataTaskStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserDataTasks::IUserDataTaskStore(ptr, take_ownership_from_abi) {}
    };
}
#endif
