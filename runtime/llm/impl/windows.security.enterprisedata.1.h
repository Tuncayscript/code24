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
#ifndef LLM_OS_Security_EnterpriseData_1_H
#define LLM_OS_Security_EnterpriseData_1_H
#include "llm/impl/Windows.Security.EnterpriseData.0.h"
LLM_EXPORT namespace llm:OS::Security::EnterpriseData
{
    struct __declspec(empty_bases) IBufferProtectUnprotectResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBufferProtectUnprotectResult>
    {
        IBufferProtectUnprotectResult(std::nullptr_t = nullptr) noexcept {}
        IBufferProtectUnprotectResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataProtectionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataProtectionInfo>
    {
        IDataProtectionInfo(std::nullptr_t = nullptr) noexcept {}
        IDataProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDataProtectionManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDataProtectionManagerStatics>
    {
        IDataProtectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IDataProtectionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileProtectionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileProtectionInfo>
    {
        IFileProtectionInfo(std::nullptr_t = nullptr) noexcept {}
        IFileProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileProtectionInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileProtectionInfo2>
    {
        IFileProtectionInfo2(std::nullptr_t = nullptr) noexcept {}
        IFileProtectionInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileProtectionManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileProtectionManagerStatics>
    {
        IFileProtectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IFileProtectionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileProtectionManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileProtectionManagerStatics2>
    {
        IFileProtectionManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IFileProtectionManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileProtectionManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileProtectionManagerStatics3>
    {
        IFileProtectionManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IFileProtectionManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileRevocationManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileRevocationManagerStatics>
    {
        IFileRevocationManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IFileRevocationManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileUnprotectOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileUnprotectOptions>
    {
        IFileUnprotectOptions(std::nullptr_t = nullptr) noexcept {}
        IFileUnprotectOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileUnprotectOptionsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileUnprotectOptionsFactory>
    {
        IFileUnprotectOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        IFileUnprotectOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectedAccessResumedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectedAccessResumedEventArgs>
    {
        IProtectedAccessResumedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IProtectedAccessResumedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectedAccessSuspendingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectedAccessSuspendingEventArgs>
    {
        IProtectedAccessSuspendingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IProtectedAccessSuspendingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectedContainerExportResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectedContainerExportResult>
    {
        IProtectedContainerExportResult(std::nullptr_t = nullptr) noexcept {}
        IProtectedContainerExportResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectedContainerImportResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectedContainerImportResult>
    {
        IProtectedContainerImportResult(std::nullptr_t = nullptr) noexcept {}
        IProtectedContainerImportResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectedContentRevokedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectedContentRevokedEventArgs>
    {
        IProtectedContentRevokedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IProtectedContentRevokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectedFileCreateResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectedFileCreateResult>
    {
        IProtectedFileCreateResult(std::nullptr_t = nullptr) noexcept {}
        IProtectedFileCreateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyAuditInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyAuditInfo>
    {
        IProtectionPolicyAuditInfo(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyAuditInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyAuditInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyAuditInfoFactory>
    {
        IProtectionPolicyAuditInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyAuditInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyManager>
    {
        IProtectionPolicyManager(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyManager2>
    {
        IProtectionPolicyManager2(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyManagerStatics>
    {
        IProtectionPolicyManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyManagerStatics2>
    {
        IProtectionPolicyManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyManagerStatics3>
    {
        IProtectionPolicyManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionPolicyManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionPolicyManagerStatics4>
    {
        IProtectionPolicyManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IProtectionPolicyManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IThreadNetworkContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IThreadNetworkContext>
    {
        IThreadNetworkContext(std::nullptr_t = nullptr) noexcept {}
        IThreadNetworkContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
