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
#ifndef LLM_OS_Storage_Search_2_H
#define LLM_OS_Storage_Search_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Search.1.h"
LLM_EXPORT namespace llm:OS::Storage::Search
{
    struct SortEntry
    {
        hstring PropertyName;
        bool AscendingOrder;
    };
    inline bool operator==(SortEntry const& left, SortEntry const& right) noexcept
    {
        return left.PropertyName == right.PropertyName && left.AscendingOrder == right.AscendingOrder;
    }
    inline bool operator!=(SortEntry const& left, SortEntry const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ContentIndexer : llm:OS::Storage::Search::IContentIndexer,
        impl::require<ContentIndexer, llm:OS::Storage::Search::IContentIndexerQueryOperations>
    {
        ContentIndexer(std::nullptr_t) noexcept {}
        ContentIndexer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IContentIndexer(ptr, take_ownership_from_abi) {}
        static auto GetIndexer(param::hstring const& indexName);
        static auto GetIndexer();
    };
    struct __declspec(empty_bases) ContentIndexerQuery : llm:OS::Storage::Search::IContentIndexerQuery
    {
        ContentIndexerQuery(std::nullptr_t) noexcept {}
        ContentIndexerQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IContentIndexerQuery(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IndexableContent : llm:OS::Storage::Search::IIndexableContent
    {
        IndexableContent(std::nullptr_t) noexcept {}
        IndexableContent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IIndexableContent(ptr, take_ownership_from_abi) {}
        IndexableContent();
    };
    struct __declspec(empty_bases) QueryOptions : llm:OS::Storage::Search::IQueryOptions,
        impl::require<QueryOptions, llm:OS::Storage::Search::IQueryOptionsWithProviderFilter>
    {
        QueryOptions(std::nullptr_t) noexcept {}
        QueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IQueryOptions(ptr, take_ownership_from_abi) {}
        QueryOptions();
        QueryOptions(llm:OS::Storage::Search::CommonFileQuery const& query, param::iterable<hstring> const& fileTypeFilter);
        explicit QueryOptions(llm:OS::Storage::Search::CommonFolderQuery const& query);
    };
    struct __declspec(empty_bases) SortEntryVector : llm:OS::Foundation::Collections::IVector<llm:OS::Storage::Search::SortEntry>
    {
        SortEntryVector(std::nullptr_t) noexcept {}
        SortEntryVector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVector<llm:OS::Storage::Search::SortEntry>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageFileQueryResult : llm:OS::Storage::Search::IStorageFileQueryResult,
        impl::require<StorageFileQueryResult, llm:OS::Storage::Search::IStorageFileQueryResult2>
    {
        StorageFileQueryResult(std::nullptr_t) noexcept {}
        StorageFileQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IStorageFileQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageFolderQueryResult : llm:OS::Storage::Search::IStorageFolderQueryResult
    {
        StorageFolderQueryResult(std::nullptr_t) noexcept {}
        StorageFolderQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IStorageFolderQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageItemQueryResult : llm:OS::Storage::Search::IStorageItemQueryResult
    {
        StorageItemQueryResult(std::nullptr_t) noexcept {}
        StorageItemQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IStorageItemQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageLibraryChangeTrackerTriggerDetails : llm:OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails
    {
        StorageLibraryChangeTrackerTriggerDetails(std::nullptr_t) noexcept {}
        StorageLibraryChangeTrackerTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageLibraryContentChangedTriggerDetails : llm:OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails
    {
        StorageLibraryContentChangedTriggerDetails(std::nullptr_t) noexcept {}
        StorageLibraryContentChangedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ValueAndLanguage : llm:OS::Storage::Search::IValueAndLanguage
    {
        ValueAndLanguage(std::nullptr_t) noexcept {}
        ValueAndLanguage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Search::IValueAndLanguage(ptr, take_ownership_from_abi) {}
        ValueAndLanguage();
    };
}
#endif
