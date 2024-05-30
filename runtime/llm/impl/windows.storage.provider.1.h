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
#ifndef LLM_OS_Storage_Provider_1_H
#define LLM_OS_Storage_Provider_1_H
#include "llm/impl/Windows.Storage.Provider.0.h"
LLM_EXPORT namespace llm:OS::Storage::Provider
{
    struct __declspec(empty_bases) ICachedFileUpdaterStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileUpdaterStatics>
    {
        ICachedFileUpdaterStatics(std::nullptr_t = nullptr) noexcept {}
        ICachedFileUpdaterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICachedFileUpdaterUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileUpdaterUI>
    {
        ICachedFileUpdaterUI(std::nullptr_t = nullptr) noexcept {}
        ICachedFileUpdaterUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICachedFileUpdaterUI2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileUpdaterUI2>,
        impl::require<llm:OS::Storage::Provider::ICachedFileUpdaterUI2, llm:OS::Storage::Provider::ICachedFileUpdaterUI>
    {
        ICachedFileUpdaterUI2(std::nullptr_t = nullptr) noexcept {}
        ICachedFileUpdaterUI2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileUpdateRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileUpdateRequest>
    {
        IFileUpdateRequest(std::nullptr_t = nullptr) noexcept {}
        IFileUpdateRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileUpdateRequest2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileUpdateRequest2>,
        impl::require<llm:OS::Storage::Provider::IFileUpdateRequest2, llm:OS::Storage::Provider::IFileUpdateRequest>
    {
        IFileUpdateRequest2(std::nullptr_t = nullptr) noexcept {}
        IFileUpdateRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileUpdateRequestDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileUpdateRequestDeferral>
    {
        IFileUpdateRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        IFileUpdateRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileUpdateRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileUpdateRequestedEventArgs>
    {
        IFileUpdateRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileUpdateRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderFileTypeInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderFileTypeInfo>
    {
        IStorageProviderFileTypeInfo(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderFileTypeInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderFileTypeInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderFileTypeInfoFactory>
    {
        IStorageProviderFileTypeInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderFileTypeInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderGetContentInfoForPathResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderGetContentInfoForPathResult>
    {
        IStorageProviderGetContentInfoForPathResult(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderGetContentInfoForPathResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderGetPathForContentUriResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderGetPathForContentUriResult>
    {
        IStorageProviderGetPathForContentUriResult(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderGetPathForContentUriResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderItemPropertiesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderItemPropertiesStatics>
    {
        IStorageProviderItemPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderItemPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderItemProperty :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderItemProperty>
    {
        IStorageProviderItemProperty(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderItemProperty(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderItemPropertyDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderItemPropertyDefinition>
    {
        IStorageProviderItemPropertyDefinition(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderItemPropertyDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderItemPropertySource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderItemPropertySource>
    {
        IStorageProviderItemPropertySource(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderItemPropertySource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderKnownFolderEntry :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderKnownFolderEntry>
    {
        IStorageProviderKnownFolderEntry(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderKnownFolderEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderKnownFolderSyncInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderKnownFolderSyncInfo>
    {
        IStorageProviderKnownFolderSyncInfo(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderKnownFolderSyncInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderKnownFolderSyncInfoSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderKnownFolderSyncInfoSource>
    {
        IStorageProviderKnownFolderSyncInfoSource(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderKnownFolderSyncInfoSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderKnownFolderSyncInfoSourceFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderKnownFolderSyncInfoSourceFactory>
    {
        IStorageProviderKnownFolderSyncInfoSourceFactory(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderKnownFolderSyncInfoSourceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderKnownFolderSyncRequestArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderKnownFolderSyncRequestArgs>
    {
        IStorageProviderKnownFolderSyncRequestArgs(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderKnownFolderSyncRequestArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderMoreInfoUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderMoreInfoUI>
    {
        IStorageProviderMoreInfoUI(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderMoreInfoUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderPropertyCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderPropertyCapabilities>
    {
        IStorageProviderPropertyCapabilities(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderPropertyCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderQuotaUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderQuotaUI>
    {
        IStorageProviderQuotaUI(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderQuotaUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderStatusUI :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderStatusUI>
    {
        IStorageProviderStatusUI(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderStatusUI(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderStatusUISource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderStatusUISource>
    {
        IStorageProviderStatusUISource(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderStatusUISource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderStatusUISourceFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderStatusUISourceFactory>
    {
        IStorageProviderStatusUISourceFactory(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderStatusUISourceFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderSyncRootInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderSyncRootInfo>
    {
        IStorageProviderSyncRootInfo(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderSyncRootInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderSyncRootInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderSyncRootInfo2>
    {
        IStorageProviderSyncRootInfo2(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderSyncRootInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderSyncRootInfo3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderSyncRootInfo3>
    {
        IStorageProviderSyncRootInfo3(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderSyncRootInfo3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderSyncRootManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderSyncRootManagerStatics>
    {
        IStorageProviderSyncRootManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderSyncRootManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderSyncRootManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderSyncRootManagerStatics2>
    {
        IStorageProviderSyncRootManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderSyncRootManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderUICommand :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderUICommand>
    {
        IStorageProviderUICommand(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderUICommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProviderUriSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProviderUriSource>
    {
        IStorageProviderUriSource(std::nullptr_t = nullptr) noexcept {}
        IStorageProviderUriSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
