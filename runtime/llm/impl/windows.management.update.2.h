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
#ifndef LLM_OS_Management_Update_2_H
#define LLM_OS_Management_Update_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Management.Update.1.h"
LLM_EXPORT namespace llm:OS::Management::Update
{
    struct __declspec(empty_bases) PreviewBuildsManager : llm:OS::Management::Update::IPreviewBuildsManager
    {
        PreviewBuildsManager(std::nullptr_t) noexcept {}
        PreviewBuildsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IPreviewBuildsManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto IsSupported();
    };
    struct __declspec(empty_bases) PreviewBuildsState : llm:OS::Management::Update::IPreviewBuildsState
    {
        PreviewBuildsState(std::nullptr_t) noexcept {}
        PreviewBuildsState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IPreviewBuildsState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdate : llm:OS::Management::Update::IWindowsUpdate
    {
        WindowsUpdate(std::nullptr_t) noexcept {}
        WindowsUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateActionCompletedEventArgs : llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs
    {
        WindowsUpdateActionCompletedEventArgs(std::nullptr_t) noexcept {}
        WindowsUpdateActionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateActionProgress : llm:OS::Management::Update::IWindowsUpdateActionProgress
    {
        WindowsUpdateActionProgress(std::nullptr_t) noexcept {}
        WindowsUpdateActionProgress(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateActionProgress(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateActionResult : llm:OS::Management::Update::IWindowsUpdateActionResult
    {
        WindowsUpdateActionResult(std::nullptr_t) noexcept {}
        WindowsUpdateActionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateActionResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateAdministrator : llm:OS::Management::Update::IWindowsUpdateAdministrator
    {
        WindowsUpdateAdministrator(std::nullptr_t) noexcept {}
        WindowsUpdateAdministrator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateAdministrator(ptr, take_ownership_from_abi) {}
        static auto GetRegisteredAdministrator(param::hstring const& organizationName);
        static auto RegisterForAdministration(param::hstring const& organizationName, llm:OS::Management::Update::WindowsUpdateAdministratorOptions const& options);
        static auto UnregisterForAdministration(param::hstring const& organizationName);
        static auto GetRegisteredAdministratorName();
        static auto RequestRestart(llm:OS::Management::Update::WindowsUpdateRestartRequestOptions const& restartOptions);
        static auto CancelRestartRequest(param::hstring const& requestRestartToken);
    };
    struct __declspec(empty_bases) WindowsUpdateApprovalData : llm:OS::Management::Update::IWindowsUpdateApprovalData
    {
        WindowsUpdateApprovalData(std::nullptr_t) noexcept {}
        WindowsUpdateApprovalData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateApprovalData(ptr, take_ownership_from_abi) {}
        WindowsUpdateApprovalData();
    };
    struct __declspec(empty_bases) WindowsUpdateAttentionRequiredInfo : llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo
    {
        WindowsUpdateAttentionRequiredInfo(std::nullptr_t) noexcept {}
        WindowsUpdateAttentionRequiredInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateAttentionRequiredReasonChangedEventArgs : llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs
    {
        WindowsUpdateAttentionRequiredReasonChangedEventArgs(std::nullptr_t) noexcept {}
        WindowsUpdateAttentionRequiredReasonChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateGetAdministratorResult : llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult
    {
        WindowsUpdateGetAdministratorResult(std::nullptr_t) noexcept {}
        WindowsUpdateGetAdministratorResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateItem : llm:OS::Management::Update::IWindowsUpdateItem
    {
        WindowsUpdateItem(std::nullptr_t) noexcept {}
        WindowsUpdateItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateManager : llm:OS::Management::Update::IWindowsUpdateManager
    {
        WindowsUpdateManager(std::nullptr_t) noexcept {}
        WindowsUpdateManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateManager(ptr, take_ownership_from_abi) {}
        explicit WindowsUpdateManager(param::hstring const& clientId);
    };
    struct __declspec(empty_bases) WindowsUpdateProgressChangedEventArgs : llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs
    {
        WindowsUpdateProgressChangedEventArgs(std::nullptr_t) noexcept {}
        WindowsUpdateProgressChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowsUpdateRestartRequestOptions : llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions
    {
        WindowsUpdateRestartRequestOptions(std::nullptr_t) noexcept {}
        WindowsUpdateRestartRequestOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions(ptr, take_ownership_from_abi) {}
        WindowsUpdateRestartRequestOptions();
        WindowsUpdateRestartRequestOptions(param::hstring const& title, param::hstring const& description, llm:OS::Foundation::Uri const& moreInfoUrl, int32_t complianceDeadlineInDays, int32_t complianceGracePeriodInDays);
    };
    struct __declspec(empty_bases) WindowsUpdateScanCompletedEventArgs : llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs
    {
        WindowsUpdateScanCompletedEventArgs(std::nullptr_t) noexcept {}
        WindowsUpdateScanCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
