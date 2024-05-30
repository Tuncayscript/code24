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
#ifndef LLM_OS_Storage_Provider_2_H
#define LLM_OS_Storage_Provider_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.Provider.1.h"
LLM_EXPORT namespace llm:OS::Storage::Provider
{
    struct StorageProviderKnownFolderSyncRequestedHandler : llm:OS::Foundation::IUnknown
    {
        StorageProviderKnownFolderSyncRequestedHandler(std::nullptr_t = nullptr) noexcept {}
        StorageProviderKnownFolderSyncRequestedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> StorageProviderKnownFolderSyncRequestedHandler(L lambda);
        template <typename F> StorageProviderKnownFolderSyncRequestedHandler(F* function);
        template <typename O, typename M> StorageProviderKnownFolderSyncRequestedHandler(O* object, M method);
        template <typename O, typename M> StorageProviderKnownFolderSyncRequestedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> StorageProviderKnownFolderSyncRequestedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Storage::Provider::StorageProviderKnownFolderSyncRequestArgs const& args) const;
    };
    struct CachedFileUpdater
    {
        CachedFileUpdater() = delete;
        static auto SetUpdateInformation(llm:OS::Storage::IStorageFile const& file, param::hstring const& contentId, llm:OS::Storage::Provider::ReadActivationMode const& readMode, llm:OS::Storage::Provider::WriteActivationMode const& writeMode, llm:OS::Storage::Provider::CachedFileOptions const& options);
    };
    struct __declspec(empty_bases) CachedFileUpdaterUI : llm:OS::Storage::Provider::ICachedFileUpdaterUI,
        impl::require<CachedFileUpdaterUI, llm:OS::Storage::Provider::ICachedFileUpdaterUI2>
    {
        CachedFileUpdaterUI(std::nullptr_t) noexcept {}
        CachedFileUpdaterUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::ICachedFileUpdaterUI(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileUpdateRequest : llm:OS::Storage::Provider::IFileUpdateRequest,
        impl::require<FileUpdateRequest, llm:OS::Storage::Provider::IFileUpdateRequest2>
    {
        FileUpdateRequest(std::nullptr_t) noexcept {}
        FileUpdateRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IFileUpdateRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileUpdateRequestDeferral : llm:OS::Storage::Provider::IFileUpdateRequestDeferral
    {
        FileUpdateRequestDeferral(std::nullptr_t) noexcept {}
        FileUpdateRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IFileUpdateRequestDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileUpdateRequestedEventArgs : llm:OS::Storage::Provider::IFileUpdateRequestedEventArgs
    {
        FileUpdateRequestedEventArgs(std::nullptr_t) noexcept {}
        FileUpdateRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IFileUpdateRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageProviderFileTypeInfo : llm:OS::Storage::Provider::IStorageProviderFileTypeInfo
    {
        StorageProviderFileTypeInfo(std::nullptr_t) noexcept {}
        StorageProviderFileTypeInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderFileTypeInfo(ptr, take_ownership_from_abi) {}
        StorageProviderFileTypeInfo(param::hstring const& fileExtension, param::hstring const& iconResource);
    };
    struct __declspec(empty_bases) StorageProviderGetContentInfoForPathResult : llm:OS::Storage::Provider::IStorageProviderGetContentInfoForPathResult
    {
        StorageProviderGetContentInfoForPathResult(std::nullptr_t) noexcept {}
        StorageProviderGetContentInfoForPathResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderGetContentInfoForPathResult(ptr, take_ownership_from_abi) {}
        StorageProviderGetContentInfoForPathResult();
    };
    struct __declspec(empty_bases) StorageProviderGetPathForContentUriResult : llm:OS::Storage::Provider::IStorageProviderGetPathForContentUriResult
    {
        StorageProviderGetPathForContentUriResult(std::nullptr_t) noexcept {}
        StorageProviderGetPathForContentUriResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderGetPathForContentUriResult(ptr, take_ownership_from_abi) {}
        StorageProviderGetPathForContentUriResult();
    };
    struct StorageProviderItemProperties
    {
        StorageProviderItemProperties() = delete;
        static auto SetAsync(llm:OS::Storage::IStorageItem const& item, param::async_iterable<llm:OS::Storage::Provider::StorageProviderItemProperty> const& itemProperties);
    };
    struct __declspec(empty_bases) StorageProviderItemProperty : llm:OS::Storage::Provider::IStorageProviderItemProperty
    {
        StorageProviderItemProperty(std::nullptr_t) noexcept {}
        StorageProviderItemProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderItemProperty(ptr, take_ownership_from_abi) {}
        StorageProviderItemProperty();
    };
    struct __declspec(empty_bases) StorageProviderItemPropertyDefinition : llm:OS::Storage::Provider::IStorageProviderItemPropertyDefinition
    {
        StorageProviderItemPropertyDefinition(std::nullptr_t) noexcept {}
        StorageProviderItemPropertyDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderItemPropertyDefinition(ptr, take_ownership_from_abi) {}
        StorageProviderItemPropertyDefinition();
    };
    struct __declspec(empty_bases) StorageProviderKnownFolderEntry : llm:OS::Storage::Provider::IStorageProviderKnownFolderEntry
    {
        StorageProviderKnownFolderEntry(std::nullptr_t) noexcept {}
        StorageProviderKnownFolderEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderKnownFolderEntry(ptr, take_ownership_from_abi) {}
        StorageProviderKnownFolderEntry();
    };
    struct __declspec(empty_bases) StorageProviderKnownFolderSyncInfo : llm:OS::Storage::Provider::IStorageProviderKnownFolderSyncInfo
    {
        StorageProviderKnownFolderSyncInfo(std::nullptr_t) noexcept {}
        StorageProviderKnownFolderSyncInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderKnownFolderSyncInfo(ptr, take_ownership_from_abi) {}
        StorageProviderKnownFolderSyncInfo();
    };
    struct __declspec(empty_bases) StorageProviderKnownFolderSyncRequestArgs : llm:OS::Storage::Provider::IStorageProviderKnownFolderSyncRequestArgs
    {
        StorageProviderKnownFolderSyncRequestArgs(std::nullptr_t) noexcept {}
        StorageProviderKnownFolderSyncRequestArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderKnownFolderSyncRequestArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageProviderMoreInfoUI : llm:OS::Storage::Provider::IStorageProviderMoreInfoUI
    {
        StorageProviderMoreInfoUI(std::nullptr_t) noexcept {}
        StorageProviderMoreInfoUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderMoreInfoUI(ptr, take_ownership_from_abi) {}
        StorageProviderMoreInfoUI();
    };
    struct __declspec(empty_bases) StorageProviderQuotaUI : llm:OS::Storage::Provider::IStorageProviderQuotaUI
    {
        StorageProviderQuotaUI(std::nullptr_t) noexcept {}
        StorageProviderQuotaUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderQuotaUI(ptr, take_ownership_from_abi) {}
        StorageProviderQuotaUI();
    };
    struct __declspec(empty_bases) StorageProviderStatusUI : llm:OS::Storage::Provider::IStorageProviderStatusUI
    {
        StorageProviderStatusUI(std::nullptr_t) noexcept {}
        StorageProviderStatusUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderStatusUI(ptr, take_ownership_from_abi) {}
        StorageProviderStatusUI();
    };
    struct __declspec(empty_bases) StorageProviderSyncRootInfo : llm:OS::Storage::Provider::IStorageProviderSyncRootInfo,
        impl::require<StorageProviderSyncRootInfo, llm:OS::Storage::Provider::IStorageProviderSyncRootInfo2, llm:OS::Storage::Provider::IStorageProviderSyncRootInfo3>
    {
        StorageProviderSyncRootInfo(std::nullptr_t) noexcept {}
        StorageProviderSyncRootInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Provider::IStorageProviderSyncRootInfo(ptr, take_ownership_from_abi) {}
        StorageProviderSyncRootInfo();
    };
    struct StorageProviderSyncRootManager
    {
        StorageProviderSyncRootManager() = delete;
        static auto Register(llm:OS::Storage::Provider::StorageProviderSyncRootInfo const& syncRootInformation);
        static auto Unregister(param::hstring const& id);
        static auto GetSyncRootInformationForFolder(llm:OS::Storage::IStorageFolder const& folder);
        static auto GetSyncRootInformationForId(param::hstring const& id);
        static auto GetCurrentSyncRoots();
        static auto IsSupported();
    };
}
#endif
