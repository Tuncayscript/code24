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
#ifndef LLM_OS_ApplicationModel_UserDataTasks_1_H
#define LLM_OS_ApplicationModel_UserDataTasks_1_H
#include "llm/impl/Windows.ApplicationModel.UserDataTasks.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserDataTasks
{
    struct __declspec(empty_bases) IUserDataTask :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTask>
    {
        IUserDataTask(std::nullptr_t = nullptr) noexcept {}
        IUserDataTask(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskBatch :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskBatch>
    {
        IUserDataTaskBatch(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskList :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskList>
    {
        IUserDataTaskList(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListLimitedWriteOperations :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListLimitedWriteOperations>
    {
        IUserDataTaskListLimitedWriteOperations(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListLimitedWriteOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskListSyncManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskListSyncManager>
    {
        IUserDataTaskListSyncManager(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskListSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskManager>
    {
        IUserDataTaskManager(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskManagerStatics>
    {
        IUserDataTaskManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskQueryOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskQueryOptions>
    {
        IUserDataTaskQueryOptions(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskReader>
    {
        IUserDataTaskReader(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskRecurrenceProperties :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskRecurrenceProperties>
    {
        IUserDataTaskRecurrenceProperties(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskRecurrenceProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskRegenerationProperties :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskRegenerationProperties>
    {
        IUserDataTaskRegenerationProperties(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskRegenerationProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataTaskStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataTaskStore>
    {
        IUserDataTaskStore(std::nullptr_t = nullptr) noexcept {}
        IUserDataTaskStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
