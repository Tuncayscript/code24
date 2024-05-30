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
#ifndef LLM_OS_Security_EnterpriseData_2_H
#define LLM_OS_Security_EnterpriseData_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Security.EnterpriseData.1.h"
LLM_EXPORT namespace llm:OS::Security::EnterpriseData
{
    struct __declspec(empty_bases) BufferProtectUnprotectResult : llm:OS::Security::EnterpriseData::IBufferProtectUnprotectResult
    {
        BufferProtectUnprotectResult(std::nullptr_t) noexcept {}
        BufferProtectUnprotectResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IBufferProtectUnprotectResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DataProtectionInfo : llm:OS::Security::EnterpriseData::IDataProtectionInfo
    {
        DataProtectionInfo(std::nullptr_t) noexcept {}
        DataProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IDataProtectionInfo(ptr, take_ownership_from_abi) {}
    };
    struct DataProtectionManager
    {
        DataProtectionManager() = delete;
        static auto ProtectAsync(llm:OS::Storage::Streams::IBuffer const& data, param::hstring const& identity);
        static auto UnprotectAsync(llm:OS::Storage::Streams::IBuffer const& data);
        static auto ProtectStreamAsync(llm:OS::Storage::Streams::IInputStream const& unprotectedStream, param::hstring const& identity, llm:OS::Storage::Streams::IOutputStream const& protectedStream);
        static auto UnprotectStreamAsync(llm:OS::Storage::Streams::IInputStream const& protectedStream, llm:OS::Storage::Streams::IOutputStream const& unprotectedStream);
        static auto GetProtectionInfoAsync(llm:OS::Storage::Streams::IBuffer const& protectedData);
        static auto GetStreamProtectionInfoAsync(llm:OS::Storage::Streams::IInputStream const& protectedStream);
    };
    struct __declspec(empty_bases) FileProtectionInfo : llm:OS::Security::EnterpriseData::IFileProtectionInfo,
        impl::require<FileProtectionInfo, llm:OS::Security::EnterpriseData::IFileProtectionInfo2>
    {
        FileProtectionInfo(std::nullptr_t) noexcept {}
        FileProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IFileProtectionInfo(ptr, take_ownership_from_abi) {}
    };
    struct FileProtectionManager
    {
        FileProtectionManager() = delete;
        static auto ProtectAsync(llm:OS::Storage::IStorageItem const& target, param::hstring const& identity);
        static auto CopyProtectionAsync(llm:OS::Storage::IStorageItem const& source, llm:OS::Storage::IStorageItem const& target);
        static auto GetProtectionInfoAsync(llm:OS::Storage::IStorageItem const& source);
        static auto SaveFileAsContainerAsync(llm:OS::Storage::IStorageFile const& protectedFile);
        static auto LoadFileFromContainerAsync(llm:OS::Storage::IStorageFile const& containerFile);
        static auto LoadFileFromContainerAsync(llm:OS::Storage::IStorageFile const& containerFile, llm:OS::Storage::IStorageItem const& target);
        static auto CreateProtectedAndOpenAsync(llm:OS::Storage::IStorageFolder const& parentFolder, param::hstring const& desiredName, param::hstring const& identity, llm:OS::Storage::CreationCollisionOption const& collisionOption);
        static auto IsContainerAsync(llm:OS::Storage::IStorageFile const& file);
        static auto LoadFileFromContainerAsync(llm:OS::Storage::IStorageFile const& containerFile, llm:OS::Storage::IStorageItem const& target, llm:OS::Storage::NameCollisionOption const& collisionOption);
        static auto SaveFileAsContainerAsync(llm:OS::Storage::IStorageFile const& protectedFile, param::async_iterable<hstring> const& sharedWithIdentities);
        static auto UnprotectAsync(llm:OS::Storage::IStorageItem const& target);
        static auto UnprotectAsync(llm:OS::Storage::IStorageItem const& target, llm:OS::Security::EnterpriseData::FileUnprotectOptions const& options);
    };
    struct FileRevocationManager
    {
        FileRevocationManager() = delete;
        static auto ProtectAsync(llm:OS::Storage::IStorageItem const& storageItem, param::hstring const& enterpriseIdentity);
        static auto CopyProtectionAsync(llm:OS::Storage::IStorageItem const& sourceStorageItem, llm:OS::Storage::IStorageItem const& targetStorageItem);
        static auto Revoke(param::hstring const& enterpriseIdentity);
        static auto GetStatusAsync(llm:OS::Storage::IStorageItem const& storageItem);
    };
    struct __declspec(empty_bases) FileUnprotectOptions : llm:OS::Security::EnterpriseData::IFileUnprotectOptions
    {
        FileUnprotectOptions(std::nullptr_t) noexcept {}
        FileUnprotectOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IFileUnprotectOptions(ptr, take_ownership_from_abi) {}
        explicit FileUnprotectOptions(bool audit);
    };
    struct __declspec(empty_bases) ProtectedAccessResumedEventArgs : llm:OS::Security::EnterpriseData::IProtectedAccessResumedEventArgs
    {
        ProtectedAccessResumedEventArgs(std::nullptr_t) noexcept {}
        ProtectedAccessResumedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectedAccessResumedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectedAccessSuspendingEventArgs : llm:OS::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs
    {
        ProtectedAccessSuspendingEventArgs(std::nullptr_t) noexcept {}
        ProtectedAccessSuspendingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectedAccessSuspendingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectedContainerExportResult : llm:OS::Security::EnterpriseData::IProtectedContainerExportResult
    {
        ProtectedContainerExportResult(std::nullptr_t) noexcept {}
        ProtectedContainerExportResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectedContainerExportResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectedContainerImportResult : llm:OS::Security::EnterpriseData::IProtectedContainerImportResult
    {
        ProtectedContainerImportResult(std::nullptr_t) noexcept {}
        ProtectedContainerImportResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectedContainerImportResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectedContentRevokedEventArgs : llm:OS::Security::EnterpriseData::IProtectedContentRevokedEventArgs
    {
        ProtectedContentRevokedEventArgs(std::nullptr_t) noexcept {}
        ProtectedContentRevokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectedContentRevokedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectedFileCreateResult : llm:OS::Security::EnterpriseData::IProtectedFileCreateResult
    {
        ProtectedFileCreateResult(std::nullptr_t) noexcept {}
        ProtectedFileCreateResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectedFileCreateResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtectionPolicyAuditInfo : llm:OS::Security::EnterpriseData::IProtectionPolicyAuditInfo
    {
        ProtectionPolicyAuditInfo(std::nullptr_t) noexcept {}
        ProtectionPolicyAuditInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectionPolicyAuditInfo(ptr, take_ownership_from_abi) {}
        ProtectionPolicyAuditInfo(llm:OS::Security::EnterpriseData::ProtectionPolicyAuditAction const& action, param::hstring const& dataDescription, param::hstring const& sourceDescription, param::hstring const& targetDescription);
        ProtectionPolicyAuditInfo(llm:OS::Security::EnterpriseData::ProtectionPolicyAuditAction const& action, param::hstring const& dataDescription);
    };
    struct __declspec(empty_bases) ProtectionPolicyManager : llm:OS::Security::EnterpriseData::IProtectionPolicyManager,
        impl::require<ProtectionPolicyManager, llm:OS::Security::EnterpriseData::IProtectionPolicyManager2>
    {
        ProtectionPolicyManager(std::nullptr_t) noexcept {}
        ProtectionPolicyManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IProtectionPolicyManager(ptr, take_ownership_from_abi) {}
        static auto IsIdentityManaged(param::hstring const& identity);
        static auto TryApplyProcessUIPolicy(param::hstring const& identity);
        static auto ClearProcessUIPolicy();
        static auto CreateCurrentThreadNetworkContext(param::hstring const& identity);
        static auto GetPrimaryManagedIdentityForNetworkEndpointAsync(llm:OS::Networking::HostName const& endpointHost);
        static auto RevokeContent(param::hstring const& identity);
        static auto GetForCurrentView();
        static auto ProtectedAccessSuspending(llm:OS::Foundation::EventHandler<llm:OS::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> const& handler);
        using ProtectedAccessSuspending_revoker = impl::factory_event_revoker<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics, &impl::abi_t<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics>::remove_ProtectedAccessSuspending>;
        [[nodiscard]] static ProtectedAccessSuspending_revoker ProtectedAccessSuspending(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Security::EnterpriseData::ProtectedAccessSuspendingEventArgs> const& handler);
        static auto ProtectedAccessSuspending(llm::event_token const& token);
        static auto ProtectedAccessResumed(llm:OS::Foundation::EventHandler<llm:OS::Security::EnterpriseData::ProtectedAccessResumedEventArgs> const& handler);
        using ProtectedAccessResumed_revoker = impl::factory_event_revoker<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics, &impl::abi_t<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics>::remove_ProtectedAccessResumed>;
        [[nodiscard]] static ProtectedAccessResumed_revoker ProtectedAccessResumed(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Security::EnterpriseData::ProtectedAccessResumedEventArgs> const& handler);
        static auto ProtectedAccessResumed(llm::event_token const& token);
        static auto ProtectedContentRevoked(llm:OS::Foundation::EventHandler<llm:OS::Security::EnterpriseData::ProtectedContentRevokedEventArgs> const& handler);
        using ProtectedContentRevoked_revoker = impl::factory_event_revoker<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics, &impl::abi_t<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics>::remove_ProtectedContentRevoked>;
        [[nodiscard]] static ProtectedContentRevoked_revoker ProtectedContentRevoked(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Security::EnterpriseData::ProtectedContentRevokedEventArgs> const& handler);
        static auto ProtectedContentRevoked(llm::event_token const& token);
        static auto CheckAccess(param::hstring const& sourceIdentity, param::hstring const& targetIdentity);
        static auto RequestAccessAsync(param::hstring const& sourceIdentity, param::hstring const& targetIdentity);
        static auto HasContentBeenRevokedSince(param::hstring const& identity, llm:OS::Foundation::DateTime const& since);
        static auto CheckAccessForApp(param::hstring const& sourceIdentity, param::hstring const& appPackageFamilyName);
        static auto RequestAccessForAppAsync(param::hstring const& sourceIdentity, param::hstring const& appPackageFamilyName);
        static auto GetEnforcementLevel(param::hstring const& identity);
        static auto IsUserDecryptionAllowed(param::hstring const& identity);
        static auto IsProtectionUnderLockRequired(param::hstring const& identity);
        static auto PolicyChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using PolicyChanged_revoker = impl::factory_event_revoker<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics2, &impl::abi_t<llm:OS::Security::EnterpriseData::IProtectionPolicyManagerStatics2>::remove_PolicyChanged>;
        [[nodiscard]] static PolicyChanged_revoker PolicyChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto PolicyChanged(llm::event_token const& token);
        [[nodiscard]] static auto IsProtectionEnabled();
        static auto RequestAccessAsync(param::hstring const& sourceIdentity, param::hstring const& targetIdentity, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo);
        static auto RequestAccessAsync(param::hstring const& sourceIdentity, param::hstring const& targetIdentity, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo, param::hstring const& messageFromApp);
        static auto RequestAccessForAppAsync(param::hstring const& sourceIdentity, param::hstring const& appPackageFamilyName, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo);
        static auto RequestAccessForAppAsync(param::hstring const& sourceIdentity, param::hstring const& appPackageFamilyName, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo, param::hstring const& messageFromApp);
        static auto LogAuditEvent(param::hstring const& sourceIdentity, param::hstring const& targetIdentity, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo);
        static auto IsRoamableProtectionEnabled(param::hstring const& identity);
        static auto RequestAccessAsync(param::hstring const& sourceIdentity, param::hstring const& targetIdentity, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo, param::hstring const& messageFromApp, llm:OS::Security::EnterpriseData::ProtectionPolicyRequestAccessBehavior const& behavior);
        static auto RequestAccessForAppAsync(param::hstring const& sourceIdentity, param::hstring const& appPackageFamilyName, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo, param::hstring const& messageFromApp, llm:OS::Security::EnterpriseData::ProtectionPolicyRequestAccessBehavior const& behavior);
        static auto RequestAccessToFilesForAppAsync(param::async_iterable<llm:OS::Storage::IStorageItem> const& sourceItemList, param::hstring const& appPackageFamilyName, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo);
        static auto RequestAccessToFilesForAppAsync(param::async_iterable<llm:OS::Storage::IStorageItem> const& sourceItemList, param::hstring const& appPackageFamilyName, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo, param::hstring const& messageFromApp, llm:OS::Security::EnterpriseData::ProtectionPolicyRequestAccessBehavior const& behavior);
        static auto RequestAccessToFilesForProcessAsync(param::async_iterable<llm:OS::Storage::IStorageItem> const& sourceItemList, uint32_t processId, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo);
        static auto RequestAccessToFilesForProcessAsync(param::async_iterable<llm:OS::Storage::IStorageItem> const& sourceItemList, uint32_t processId, llm:OS::Security::EnterpriseData::ProtectionPolicyAuditInfo const& auditInfo, param::hstring const& messageFromApp, llm:OS::Security::EnterpriseData::ProtectionPolicyRequestAccessBehavior const& behavior);
        static auto IsFileProtectionRequiredAsync(llm:OS::Storage::IStorageItem const& target, param::hstring const& identity);
        static auto IsFileProtectionRequiredForNewFileAsync(llm:OS::Storage::IStorageFolder const& parentFolder, param::hstring const& identity, param::hstring const& desiredName);
        [[nodiscard]] static auto PrimaryManagedIdentity();
        static auto GetPrimaryManagedIdentityForIdentity(param::hstring const& identity);
    };
    struct __declspec(empty_bases) ThreadNetworkContext : llm:OS::Security::EnterpriseData::IThreadNetworkContext,
        impl::require<ThreadNetworkContext, llm:OS::Foundation::IClosable>
    {
        ThreadNetworkContext(std::nullptr_t) noexcept {}
        ThreadNetworkContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::EnterpriseData::IThreadNetworkContext(ptr, take_ownership_from_abi) {}
    };
}
#endif
