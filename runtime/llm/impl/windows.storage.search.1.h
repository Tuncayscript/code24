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
#ifndef LLM_OS_Storage_Search_1_H
#define LLM_OS_Storage_Search_1_H
#include "llm/impl/Windows.Storage.Search.0.h"
LLM_EXPORT namespace llm:OS::Storage::Search
{
    struct __declspec(empty_bases) IContentIndexer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentIndexer>
    {
        IContentIndexer(std::nullptr_t = nullptr) noexcept {}
        IContentIndexer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentIndexerQuery :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentIndexerQuery>
    {
        IContentIndexerQuery(std::nullptr_t = nullptr) noexcept {}
        IContentIndexerQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentIndexerQueryOperations :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentIndexerQueryOperations>
    {
        IContentIndexerQueryOperations(std::nullptr_t = nullptr) noexcept {}
        IContentIndexerQueryOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContentIndexerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentIndexerStatics>
    {
        IContentIndexerStatics(std::nullptr_t = nullptr) noexcept {}
        IContentIndexerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIndexableContent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIndexableContent>
    {
        IIndexableContent(std::nullptr_t = nullptr) noexcept {}
        IIndexableContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IQueryOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IQueryOptions>
    {
        IQueryOptions(std::nullptr_t = nullptr) noexcept {}
        IQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IQueryOptionsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IQueryOptionsFactory>
    {
        IQueryOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        IQueryOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IQueryOptionsWithProviderFilter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IQueryOptionsWithProviderFilter>
    {
        IQueryOptionsWithProviderFilter(std::nullptr_t = nullptr) noexcept {}
        IQueryOptionsWithProviderFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFileQueryResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFileQueryResult>,
        impl::require<llm:OS::Storage::Search::IStorageFileQueryResult, llm:OS::Storage::Search::IStorageQueryResultBase>
    {
        IStorageFileQueryResult(std::nullptr_t = nullptr) noexcept {}
        IStorageFileQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFileQueryResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFileQueryResult2>,
        impl::require<llm:OS::Storage::Search::IStorageFileQueryResult2, llm:OS::Storage::Search::IStorageQueryResultBase>
    {
        IStorageFileQueryResult2(std::nullptr_t = nullptr) noexcept {}
        IStorageFileQueryResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolderQueryOperations :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolderQueryOperations>
    {
        IStorageFolderQueryOperations(std::nullptr_t = nullptr) noexcept {}
        IStorageFolderQueryOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolderQueryResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolderQueryResult>,
        impl::require<llm:OS::Storage::Search::IStorageFolderQueryResult, llm:OS::Storage::Search::IStorageQueryResultBase>
    {
        IStorageFolderQueryResult(std::nullptr_t = nullptr) noexcept {}
        IStorageFolderQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemQueryResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemQueryResult>,
        impl::require<llm:OS::Storage::Search::IStorageItemQueryResult, llm:OS::Storage::Search::IStorageQueryResultBase>
    {
        IStorageItemQueryResult(std::nullptr_t = nullptr) noexcept {}
        IStorageItemQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeTrackerTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeTrackerTriggerDetails>
    {
        IStorageLibraryChangeTrackerTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeTrackerTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryContentChangedTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryContentChangedTriggerDetails>
    {
        IStorageLibraryContentChangedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryContentChangedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageQueryResultBase :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageQueryResultBase>
    {
        IStorageQueryResultBase(std::nullptr_t = nullptr) noexcept {}
        IStorageQueryResultBase(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IValueAndLanguage :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IValueAndLanguage>
    {
        IValueAndLanguage(std::nullptr_t = nullptr) noexcept {}
        IValueAndLanguage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
