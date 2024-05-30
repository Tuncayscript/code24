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
#ifndef LLM_OS_Management_Update_1_H
#define LLM_OS_Management_Update_1_H
#include "llm/impl/Windows.Management.Update.0.h"
LLM_EXPORT namespace llm:OS::Management::Update
{
    struct __declspec(empty_bases) IPreviewBuildsManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewBuildsManager>
    {
        IPreviewBuildsManager(std::nullptr_t = nullptr) noexcept {}
        IPreviewBuildsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewBuildsManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewBuildsManagerStatics>
    {
        IPreviewBuildsManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPreviewBuildsManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPreviewBuildsState :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPreviewBuildsState>
    {
        IPreviewBuildsState(std::nullptr_t = nullptr) noexcept {}
        IPreviewBuildsState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdate :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdate>
    {
        IWindowsUpdate(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateActionCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateActionCompletedEventArgs>
    {
        IWindowsUpdateActionCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateActionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateActionProgress :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateActionProgress>
    {
        IWindowsUpdateActionProgress(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateActionProgress(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateActionResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateActionResult>
    {
        IWindowsUpdateActionResult(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateActionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateAdministrator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateAdministrator>
    {
        IWindowsUpdateAdministrator(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateAdministrator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateAdministratorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateAdministratorStatics>
    {
        IWindowsUpdateAdministratorStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateAdministratorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateApprovalData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateApprovalData>
    {
        IWindowsUpdateApprovalData(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateApprovalData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateAttentionRequiredInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateAttentionRequiredInfo>
    {
        IWindowsUpdateAttentionRequiredInfo(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateAttentionRequiredInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateAttentionRequiredReasonChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateAttentionRequiredReasonChangedEventArgs>
    {
        IWindowsUpdateAttentionRequiredReasonChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateAttentionRequiredReasonChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateGetAdministratorResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateGetAdministratorResult>
    {
        IWindowsUpdateGetAdministratorResult(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateGetAdministratorResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateItem>
    {
        IWindowsUpdateItem(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateManager>
    {
        IWindowsUpdateManager(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateManagerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateManagerFactory>
    {
        IWindowsUpdateManagerFactory(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateManagerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateProgressChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateProgressChangedEventArgs>
    {
        IWindowsUpdateProgressChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateProgressChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateRestartRequestOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateRestartRequestOptions>
    {
        IWindowsUpdateRestartRequestOptions(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateRestartRequestOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateRestartRequestOptionsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateRestartRequestOptionsFactory>
    {
        IWindowsUpdateRestartRequestOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateRestartRequestOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowsUpdateScanCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowsUpdateScanCompletedEventArgs>
    {
        IWindowsUpdateScanCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowsUpdateScanCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
