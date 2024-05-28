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
#ifndef LLM_OS_Storage_Search_H
#define LLM_OS_Storage_Search_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Storage.h"
#include "llm/impl/Windows.Data.Text.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.FileProperties.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Storage.Search.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_Search_IContentIndexer<D>::AddAsync(llm::OS::Storage::Search::IIndexableContent const& indexableContent) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->AddAsync(*(void**)(&indexableContent), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_Search_IContentIndexer<D>::UpdateAsync(llm::OS::Storage::Search::IIndexableContent const& indexableContent) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->UpdateAsync(*(void**)(&indexableContent), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_Search_IContentIndexer<D>::DeleteAsync(param::hstring const& contentId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->DeleteAsync(*(void**)(&contentId), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_Search_IContentIndexer<D>::DeleteMultipleAsync(param::async_iterable<hstring> const& contentIds) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->DeleteMultipleAsync(*(void**)(&contentIds), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Storage_Search_IContentIndexer<D>::DeleteAllAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->DeleteAllAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>) consume_Windows_Storage_Search_IContentIndexer<D>::RetrievePropertiesAsync(param::hstring const& contentId, param::async_iterable<hstring> const& propertiesToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->RetrievePropertiesAsync(*(void**)(&contentId), *(void**)(&propertiesToRetrieve), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Storage_Search_IContentIndexer<D>::Revision() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexer)->get_Revision(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_Storage_Search_IContentIndexerQuery<D>::GetCountAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQuery)->GetCountAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>) consume_Windows_Storage_Search_IContentIndexerQuery<D>::GetPropertiesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQuery)->GetPropertiesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>) consume_Windows_Storage_Search_IContentIndexerQuery<D>::GetPropertiesAsync(uint32_t startIndex, uint32_t maxItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQuery)->GetPropertiesRangeAsync(startIndex, maxItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::Search::IIndexableContent>>) consume_Windows_Storage_Search_IContentIndexerQuery<D>::GetAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQuery)->GetAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::Search::IIndexableContent>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::Search::IIndexableContent>>) consume_Windows_Storage_Search_IContentIndexerQuery<D>::GetAsync(uint32_t startIndex, uint32_t maxItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQuery)->GetRangeAsync(startIndex, maxItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::Search::IIndexableContent>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_Storage_Search_IContentIndexerQuery<D>::QueryFolder() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQuery)->get_QueryFolder(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::ContentIndexerQuery) consume_Windows_Storage_Search_IContentIndexerQueryOperations<D>::CreateQuery(param::hstring const& searchFilter, param::iterable<hstring> const& propertiesToRetrieve, param::iterable<llm::OS::Storage::Search::SortEntry> const& sortOrder, param::hstring const& searchFilterLanguage) const
    {
        void* query{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQueryOperations)->CreateQueryWithSortOrderAndLanguage(*(void**)(&searchFilter), *(void**)(&propertiesToRetrieve), *(void**)(&sortOrder), *(void**)(&searchFilterLanguage), &query));
        return llm::OS::Storage::Search::ContentIndexerQuery{ query, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::ContentIndexerQuery) consume_Windows_Storage_Search_IContentIndexerQueryOperations<D>::CreateQuery(param::hstring const& searchFilter, param::iterable<hstring> const& propertiesToRetrieve, param::iterable<llm::OS::Storage::Search::SortEntry> const& sortOrder) const
    {
        void* query{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQueryOperations)->CreateQueryWithSortOrder(*(void**)(&searchFilter), *(void**)(&propertiesToRetrieve), *(void**)(&sortOrder), &query));
        return llm::OS::Storage::Search::ContentIndexerQuery{ query, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::ContentIndexerQuery) consume_Windows_Storage_Search_IContentIndexerQueryOperations<D>::CreateQuery(param::hstring const& searchFilter, param::iterable<hstring> const& propertiesToRetrieve) const
    {
        void* query{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerQueryOperations)->CreateQuery(*(void**)(&searchFilter), *(void**)(&propertiesToRetrieve), &query));
        return llm::OS::Storage::Search::ContentIndexerQuery{ query, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::ContentIndexer) consume_Windows_Storage_Search_IContentIndexerStatics<D>::GetIndexer(param::hstring const& indexName) const
    {
        void* index{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerStatics)->GetIndexerWithName(*(void**)(&indexName), &index));
        return llm::OS::Storage::Search::ContentIndexer{ index, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::ContentIndexer) consume_Windows_Storage_Search_IContentIndexerStatics<D>::GetIndexer() const
    {
        void* index{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IContentIndexerStatics)->GetIndexer(&index));
        return llm::OS::Storage::Search::ContentIndexer{ index, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IIndexableContent<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IIndexableContent<D>::Id(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->put_Id(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Storage_Search_IIndexableContent<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStream) consume_Windows_Storage_Search_IIndexableContent<D>::Stream() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->get_Stream(&value));
        return llm::OS::Storage::Streams::IRandomAccessStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IIndexableContent<D>::Stream(llm::OS::Storage::Streams::IRandomAccessStream const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->put_Stream(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IIndexableContent<D>::StreamContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->get_StreamContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IIndexableContent<D>::StreamContentType(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IIndexableContent)->put_StreamContentType(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_Search_IQueryOptions<D>::FileTypeFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_FileTypeFilter(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::FolderDepth) consume_Windows_Storage_Search_IQueryOptions<D>::FolderDepth() const
    {
        llm::OS::Storage::Search::FolderDepth value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_FolderDepth(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::FolderDepth(llm::OS::Storage::Search::FolderDepth const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->put_FolderDepth(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IQueryOptions<D>::ApplicationSearchFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_ApplicationSearchFilter(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::ApplicationSearchFilter(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->put_ApplicationSearchFilter(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IQueryOptions<D>::UserSearchFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_UserSearchFilter(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::UserSearchFilter(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->put_UserSearchFilter(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IQueryOptions<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::Language(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->put_Language(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::IndexerOption) consume_Windows_Storage_Search_IQueryOptions<D>::IndexerOption() const
    {
        llm::OS::Storage::Search::IndexerOption value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_IndexerOption(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::IndexerOption(llm::OS::Storage::Search::IndexerOption const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->put_IndexerOption(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Search::SortEntry>) consume_Windows_Storage_Search_IQueryOptions<D>::SortOrder() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_SortOrder(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Search::SortEntry>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IQueryOptions<D>::GroupPropertyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_GroupPropertyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::DateStackOption) consume_Windows_Storage_Search_IQueryOptions<D>::DateStackOption() const
    {
        llm::OS::Storage::Search::DateStackOption value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->get_DateStackOption(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IQueryOptions<D>::SaveToString() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->SaveToString(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::LoadFromString(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->LoadFromString(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::SetThumbnailPrefetch(llm::OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedSize, llm::OS::Storage::FileProperties::ThumbnailOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->SetThumbnailPrefetch(static_cast<int32_t>(mode), requestedSize, static_cast<uint32_t>(options)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IQueryOptions<D>::SetPropertyPrefetch(llm::OS::Storage::FileProperties::PropertyPrefetchOptions const& options, param::iterable<hstring> const& propertiesToRetrieve) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptions)->SetPropertyPrefetch(static_cast<uint32_t>(options), *(void**)(&propertiesToRetrieve)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::QueryOptions) consume_Windows_Storage_Search_IQueryOptionsFactory<D>::CreateCommonFileQuery(llm::OS::Storage::Search::CommonFileQuery const& query, param::iterable<hstring> const& fileTypeFilter) const
    {
        void* queryOptions{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptionsFactory)->CreateCommonFileQuery(static_cast<int32_t>(query), *(void**)(&fileTypeFilter), &queryOptions));
        return llm::OS::Storage::Search::QueryOptions{ queryOptions, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::QueryOptions) consume_Windows_Storage_Search_IQueryOptionsFactory<D>::CreateCommonFolderQuery(llm::OS::Storage::Search::CommonFolderQuery const& query) const
    {
        void* queryOptions{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptionsFactory)->CreateCommonFolderQuery(static_cast<int32_t>(query), &queryOptions));
        return llm::OS::Storage::Search::QueryOptions{ queryOptions, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Storage_Search_IQueryOptionsWithProviderFilter<D>::StorageProviderIdFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IQueryOptionsWithProviderFilter)->get_StorageProviderIdFilter(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>) consume_Windows_Storage_Search_IStorageFileQueryResult<D>::GetFilesAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFileQueryResult)->GetFilesAsync(startIndex, maxNumberOfItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>) consume_Windows_Storage_Search_IStorageFileQueryResult<D>::GetFilesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFileQueryResult)->GetFilesAsyncDefaultStartAndCount(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::Collections::IVectorView<llm::OS::Data::Text::TextSegment>>) consume_Windows_Storage_Search_IStorageFileQueryResult2<D>::GetMatchingPropertiesWithRanges(llm::OS::Storage::StorageFile const& file) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFileQueryResult2)->GetMatchingPropertiesWithRanges(*(void**)(&file), &result));
        return llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::Collections::IVectorView<llm::OS::Data::Text::TextSegment>>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Search::IndexedState>) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::GetIndexedStateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->GetIndexedStateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Search::IndexedState>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFileQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateFileQuery() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateFileQueryOverloadDefault(&value));
        return llm::OS::Storage::Search::StorageFileQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFileQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateFileQuery(llm::OS::Storage::Search::CommonFileQuery const& query) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateFileQuery(static_cast<int32_t>(query), &value));
        return llm::OS::Storage::Search::StorageFileQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFileQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateFileQueryWithOptions(llm::OS::Storage::Search::QueryOptions const& queryOptions) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateFileQueryWithOptions(*(void**)(&queryOptions), &value));
        return llm::OS::Storage::Search::StorageFileQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFolderQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateFolderQuery() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateFolderQueryOverloadDefault(&value));
        return llm::OS::Storage::Search::StorageFolderQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFolderQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateFolderQuery(llm::OS::Storage::Search::CommonFolderQuery const& query) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateFolderQuery(static_cast<int32_t>(query), &value));
        return llm::OS::Storage::Search::StorageFolderQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFolderQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateFolderQueryWithOptions(llm::OS::Storage::Search::QueryOptions const& queryOptions) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateFolderQueryWithOptions(*(void**)(&queryOptions), &value));
        return llm::OS::Storage::Search::StorageFolderQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageItemQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateItemQuery() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateItemQuery(&value));
        return llm::OS::Storage::Search::StorageItemQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageItemQueryResult) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::CreateItemQueryWithOptions(llm::OS::Storage::Search::QueryOptions const& queryOptions) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->CreateItemQueryWithOptions(*(void**)(&queryOptions), &value));
        return llm::OS::Storage::Search::StorageItemQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::GetFilesAsync(llm::OS::Storage::Search::CommonFileQuery const& query, uint32_t startIndex, uint32_t maxItemsToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->GetFilesAsync(static_cast<int32_t>(query), startIndex, maxItemsToRetrieve, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::GetFilesAsync(llm::OS::Storage::Search::CommonFileQuery const& query) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->GetFilesAsyncOverloadDefaultStartAndCount(static_cast<int32_t>(query), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::GetFoldersAsync(llm::OS::Storage::Search::CommonFolderQuery const& query, uint32_t startIndex, uint32_t maxItemsToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->GetFoldersAsync(static_cast<int32_t>(query), startIndex, maxItemsToRetrieve, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::GetFoldersAsync(llm::OS::Storage::Search::CommonFolderQuery const& query) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->GetFoldersAsyncOverloadDefaultStartAndCount(static_cast<int32_t>(query), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->GetItemsAsync(startIndex, maxItemsToRetrieve, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::AreQueryOptionsSupported(llm::OS::Storage::Search::QueryOptions const& queryOptions) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->AreQueryOptionsSupported(*(void**)(&queryOptions), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::IsCommonFolderQuerySupported(llm::OS::Storage::Search::CommonFolderQuery const& query) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->IsCommonFolderQuerySupported(static_cast<int32_t>(query), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Storage_Search_IStorageFolderQueryOperations<D>::IsCommonFileQuerySupported(llm::OS::Storage::Search::CommonFileQuery const& query) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryOperations)->IsCommonFileQuerySupported(static_cast<int32_t>(query), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>) consume_Windows_Storage_Search_IStorageFolderQueryResult<D>::GetFoldersAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryResult)->GetFoldersAsync(startIndex, maxNumberOfItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>) consume_Windows_Storage_Search_IStorageFolderQueryResult<D>::GetFoldersAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageFolderQueryResult)->GetFoldersAsyncDefaultStartAndCount(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>) consume_Windows_Storage_Search_IStorageItemQueryResult<D>::GetItemsAsync(uint32_t startIndex, uint32_t maxNumberOfItems) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageItemQueryResult)->GetItemsAsync(startIndex, maxNumberOfItems, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>) consume_Windows_Storage_Search_IStorageItemQueryResult<D>::GetItemsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageItemQueryResult)->GetItemsAsyncDefaultStartAndCount(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_Storage_Search_IStorageLibraryChangeTrackerTriggerDetails<D>::Folder() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails)->get_Folder(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageLibraryChangeTracker) consume_Windows_Storage_Search_IStorageLibraryChangeTrackerTriggerDetails<D>::ChangeTracker() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails)->get_ChangeTracker(&value));
        return llm::OS::Storage::StorageLibraryChangeTracker{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_Storage_Search_IStorageLibraryContentChangedTriggerDetails<D>::Folder() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails)->get_Folder(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageItemQueryResult) consume_Windows_Storage_Search_IStorageLibraryContentChangedTriggerDetails<D>::CreateModifiedSinceQuery(llm::OS::Foundation::DateTime const& lastQueryTime) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails)->CreateModifiedSinceQuery(impl::bind_in(lastQueryTime), &result));
        return llm::OS::Storage::Search::StorageItemQueryResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::GetItemCountAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->GetItemCountAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::Folder() const
    {
        void* container{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->get_Folder(&container));
        return llm::OS::Storage::StorageFolder{ container, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::ContentsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Search::IStorageQueryResultBase, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->add_ContentsChanged(*(void**)(&handler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Storage_Search_IStorageQueryResultBase<D>::ContentsChanged_revoker consume_Windows_Storage_Search_IStorageQueryResultBase<D>::ContentsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Search::IStorageQueryResultBase, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ContentsChanged_revoker>(this, ContentsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::ContentsChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->remove_ContentsChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::OptionsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Search::IStorageQueryResultBase, llm::OS::Foundation::IInspectable> const& changedHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->add_OptionsChanged(*(void**)(&changedHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Storage_Search_IStorageQueryResultBase<D>::OptionsChanged_revoker consume_Windows_Storage_Search_IStorageQueryResultBase<D>::OptionsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Search::IStorageQueryResultBase, llm::OS::Foundation::IInspectable> const& changedHandler) const
    {
        return impl::make_event_revoker<D, OptionsChanged_revoker>(this, OptionsChanged(changedHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::OptionsChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->remove_OptionsChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::FindStartIndexAsync(llm::OS::Foundation::IInspectable const& value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->FindStartIndexAsync(*(void**)(&value), &operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::QueryOptions) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::GetCurrentQueryOptions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->GetCurrentQueryOptions(&value));
        return llm::OS::Storage::Search::QueryOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IStorageQueryResultBase<D>::ApplyNewQueryOptions(llm::OS::Storage::Search::QueryOptions const& newQueryOptions) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IStorageQueryResultBase)->ApplyNewQueryOptions(*(void**)(&newQueryOptions)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Storage_Search_IValueAndLanguage<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IValueAndLanguage)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IValueAndLanguage<D>::Language(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IValueAndLanguage)->put_Language(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Storage_Search_IValueAndLanguage<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IValueAndLanguage)->get_Value(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Storage_Search_IValueAndLanguage<D>::Value(llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Storage::Search::IValueAndLanguage)->put_Value(*(void**)(&value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IContentIndexer> : produce_base<D, llm::OS::Storage::Search::IContentIndexer>
    {
        int32_t __stdcall AddAsync(void* indexableContent, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().AddAsync(*reinterpret_cast<llm::OS::Storage::Search::IIndexableContent const*>(&indexableContent)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateAsync(void* indexableContent, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().UpdateAsync(*reinterpret_cast<llm::OS::Storage::Search::IIndexableContent const*>(&indexableContent)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteAsync(void* contentId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteAsync(*reinterpret_cast<hstring const*>(&contentId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteMultipleAsync(void* contentIds, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteMultipleAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&contentIds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteAllAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RetrievePropertiesAsync(void* contentId, void* propertiesToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>(this->shim().RetrievePropertiesAsync(*reinterpret_cast<hstring const*>(&contentId), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Revision(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().Revision());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IContentIndexerQuery> : produce_base<D, llm::OS::Storage::Search::IContentIndexerQuery>
    {
        int32_t __stdcall GetCountAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPropertiesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>>(this->shim().GetPropertiesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPropertiesRangeAsync(uint32_t startIndex, uint32_t maxItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>>>(this->shim().GetPropertiesAsync(startIndex, maxItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::Search::IIndexableContent>>>(this->shim().GetAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRangeAsync(uint32_t startIndex, uint32_t maxItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::Search::IIndexableContent>>>(this->shim().GetAsync(startIndex, maxItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryFolder(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().QueryFolder());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IContentIndexerQueryOperations> : produce_base<D, llm::OS::Storage::Search::IContentIndexerQueryOperations>
    {
        int32_t __stdcall CreateQueryWithSortOrderAndLanguage(void* searchFilter, void* propertiesToRetrieve, void* sortOrder, void* searchFilterLanguage, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<llm::OS::Storage::Search::ContentIndexerQuery>(this->shim().CreateQuery(*reinterpret_cast<hstring const*>(&searchFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Storage::Search::SortEntry> const*>(&sortOrder), *reinterpret_cast<hstring const*>(&searchFilterLanguage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateQueryWithSortOrder(void* searchFilter, void* propertiesToRetrieve, void* sortOrder, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<llm::OS::Storage::Search::ContentIndexerQuery>(this->shim().CreateQuery(*reinterpret_cast<hstring const*>(&searchFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Storage::Search::SortEntry> const*>(&sortOrder)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateQuery(void* searchFilter, void* propertiesToRetrieve, void** query) noexcept final try
        {
            clear_abi(query);
            typename D::abi_guard guard(this->shim());
            *query = detach_from<llm::OS::Storage::Search::ContentIndexerQuery>(this->shim().CreateQuery(*reinterpret_cast<hstring const*>(&searchFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IContentIndexerStatics> : produce_base<D, llm::OS::Storage::Search::IContentIndexerStatics>
    {
        int32_t __stdcall GetIndexerWithName(void* indexName, void** index) noexcept final try
        {
            clear_abi(index);
            typename D::abi_guard guard(this->shim());
            *index = detach_from<llm::OS::Storage::Search::ContentIndexer>(this->shim().GetIndexer(*reinterpret_cast<hstring const*>(&indexName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIndexer(void** index) noexcept final try
        {
            clear_abi(index);
            typename D::abi_guard guard(this->shim());
            *index = detach_from<llm::OS::Storage::Search::ContentIndexer>(this->shim().GetIndexer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IIndexableContent> : produce_base<D, llm::OS::Storage::Search::IIndexableContent>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Id(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Id(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Stream(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStream>(this->shim().Stream());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Stream(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stream(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStream const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StreamContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().StreamContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StreamContentType(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StreamContentType(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IQueryOptions> : produce_base<D, llm::OS::Storage::Search::IQueryOptions>
    {
        int32_t __stdcall get_FileTypeFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().FileTypeFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FolderDepth(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::FolderDepth>(this->shim().FolderDepth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FolderDepth(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FolderDepth(*reinterpret_cast<llm::OS::Storage::Search::FolderDepth const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ApplicationSearchFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ApplicationSearchFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ApplicationSearchFilter(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplicationSearchFilter(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserSearchFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UserSearchFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_UserSearchFilter(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserSearchFilter(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Language(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IndexerOption(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::IndexerOption>(this->shim().IndexerOption());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IndexerOption(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IndexerOption(*reinterpret_cast<llm::OS::Storage::Search::IndexerOption const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SortOrder(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Search::SortEntry>>(this->shim().SortOrder());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GroupPropertyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GroupPropertyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DateStackOption(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::DateStackOption>(this->shim().DateStackOption());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveToString(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SaveToString());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LoadFromString(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LoadFromString(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetThumbnailPrefetch(int32_t mode, uint32_t requestedSize, uint32_t options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetThumbnailPrefetch(*reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailMode const*>(&mode), requestedSize, *reinterpret_cast<llm::OS::Storage::FileProperties::ThumbnailOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPropertyPrefetch(uint32_t options, void* propertiesToRetrieve) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPropertyPrefetch(*reinterpret_cast<llm::OS::Storage::FileProperties::PropertyPrefetchOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&propertiesToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IQueryOptionsFactory> : produce_base<D, llm::OS::Storage::Search::IQueryOptionsFactory>
    {
        int32_t __stdcall CreateCommonFileQuery(int32_t query, void* fileTypeFilter, void** queryOptions) noexcept final try
        {
            clear_abi(queryOptions);
            typename D::abi_guard guard(this->shim());
            *queryOptions = detach_from<llm::OS::Storage::Search::QueryOptions>(this->shim().CreateCommonFileQuery(*reinterpret_cast<llm::OS::Storage::Search::CommonFileQuery const*>(&query), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&fileTypeFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCommonFolderQuery(int32_t query, void** queryOptions) noexcept final try
        {
            clear_abi(queryOptions);
            typename D::abi_guard guard(this->shim());
            *queryOptions = detach_from<llm::OS::Storage::Search::QueryOptions>(this->shim().CreateCommonFolderQuery(*reinterpret_cast<llm::OS::Storage::Search::CommonFolderQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IQueryOptionsWithProviderFilter> : produce_base<D, llm::OS::Storage::Search::IQueryOptionsWithProviderFilter>
    {
        int32_t __stdcall get_StorageProviderIdFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().StorageProviderIdFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageFileQueryResult> : produce_base<D, llm::OS::Storage::Search::IStorageFileQueryResult>
    {
        int32_t __stdcall GetFilesAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>>(this->shim().GetFilesAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFilesAsyncDefaultStartAndCount(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>>(this->shim().GetFilesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageFileQueryResult2> : produce_base<D, llm::OS::Storage::Search::IStorageFileQueryResult2>
    {
        int32_t __stdcall GetMatchingPropertiesWithRanges(void* file, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::Collections::IVectorView<llm::OS::Data::Text::TextSegment>>>(this->shim().GetMatchingPropertiesWithRanges(*reinterpret_cast<llm::OS::Storage::StorageFile const*>(&file)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageFolderQueryOperations> : produce_base<D, llm::OS::Storage::Search::IStorageFolderQueryOperations>
    {
        int32_t __stdcall GetIndexedStateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Search::IndexedState>>(this->shim().GetIndexedStateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFileQueryOverloadDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFileQueryResult>(this->shim().CreateFileQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFileQuery(int32_t query, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFileQueryResult>(this->shim().CreateFileQuery(*reinterpret_cast<llm::OS::Storage::Search::CommonFileQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFileQueryWithOptions(void* queryOptions, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFileQueryResult>(this->shim().CreateFileQueryWithOptions(*reinterpret_cast<llm::OS::Storage::Search::QueryOptions const*>(&queryOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFolderQueryOverloadDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFolderQueryResult>(this->shim().CreateFolderQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFolderQuery(int32_t query, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFolderQueryResult>(this->shim().CreateFolderQuery(*reinterpret_cast<llm::OS::Storage::Search::CommonFolderQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFolderQueryWithOptions(void* queryOptions, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFolderQueryResult>(this->shim().CreateFolderQueryWithOptions(*reinterpret_cast<llm::OS::Storage::Search::QueryOptions const*>(&queryOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateItemQuery(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageItemQueryResult>(this->shim().CreateItemQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateItemQueryWithOptions(void* queryOptions, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageItemQueryResult>(this->shim().CreateItemQueryWithOptions(*reinterpret_cast<llm::OS::Storage::Search::QueryOptions const*>(&queryOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFilesAsync(int32_t query, uint32_t startIndex, uint32_t maxItemsToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>>(this->shim().GetFilesAsync(*reinterpret_cast<llm::OS::Storage::Search::CommonFileQuery const*>(&query), startIndex, maxItemsToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFilesAsyncOverloadDefaultStartAndCount(int32_t query, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>>(this->shim().GetFilesAsync(*reinterpret_cast<llm::OS::Storage::Search::CommonFileQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFoldersAsync(int32_t query, uint32_t startIndex, uint32_t maxItemsToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>>(this->shim().GetFoldersAsync(*reinterpret_cast<llm::OS::Storage::Search::CommonFolderQuery const*>(&query), startIndex, maxItemsToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFoldersAsyncOverloadDefaultStartAndCount(int32_t query, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>>(this->shim().GetFoldersAsync(*reinterpret_cast<llm::OS::Storage::Search::CommonFolderQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>>(this->shim().GetItemsAsync(startIndex, maxItemsToRetrieve));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AreQueryOptionsSupported(void* queryOptions, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AreQueryOptionsSupported(*reinterpret_cast<llm::OS::Storage::Search::QueryOptions const*>(&queryOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCommonFolderQuerySupported(int32_t query, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCommonFolderQuerySupported(*reinterpret_cast<llm::OS::Storage::Search::CommonFolderQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCommonFileQuerySupported(int32_t query, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCommonFileQuerySupported(*reinterpret_cast<llm::OS::Storage::Search::CommonFileQuery const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageFolderQueryResult> : produce_base<D, llm::OS::Storage::Search::IStorageFolderQueryResult>
    {
        int32_t __stdcall GetFoldersAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>>(this->shim().GetFoldersAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFoldersAsyncDefaultStartAndCount(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFolder>>>(this->shim().GetFoldersAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageItemQueryResult> : produce_base<D, llm::OS::Storage::Search::IStorageItemQueryResult>
    {
        int32_t __stdcall GetItemsAsync(uint32_t startIndex, uint32_t maxNumberOfItems, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>>(this->shim().GetItemsAsync(startIndex, maxNumberOfItems));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemsAsyncDefaultStartAndCount(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>>(this->shim().GetItemsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails> : produce_base<D, llm::OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails>
    {
        int32_t __stdcall get_Folder(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().Folder());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChangeTracker(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageLibraryChangeTracker>(this->shim().ChangeTracker());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails> : produce_base<D, llm::OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails>
    {
        int32_t __stdcall get_Folder(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().Folder());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateModifiedSinceQuery(int64_t lastQueryTime, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Search::StorageItemQueryResult>(this->shim().CreateModifiedSinceQuery(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&lastQueryTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IStorageQueryResultBase> : produce_base<D, llm::OS::Storage::Search::IStorageQueryResultBase>
    {
        int32_t __stdcall GetItemCountAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetItemCountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Folder(void** container) noexcept final try
        {
            clear_abi(container);
            typename D::abi_guard guard(this->shim());
            *container = detach_from<llm::OS::Storage::StorageFolder>(this->shim().Folder());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ContentsChanged(void* handler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().ContentsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Search::IStorageQueryResultBase, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ContentsChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ContentsChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall add_OptionsChanged(void* changedHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().OptionsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Storage::Search::IStorageQueryResultBase, llm::OS::Foundation::IInspectable> const*>(&changedHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OptionsChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionsChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall FindStartIndexAsync(void* value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().FindStartIndexAsync(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentQueryOptions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::QueryOptions>(this->shim().GetCurrentQueryOptions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApplyNewQueryOptions(void* newQueryOptions) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApplyNewQueryOptions(*reinterpret_cast<llm::OS::Storage::Search::QueryOptions const*>(&newQueryOptions));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Storage::Search::IValueAndLanguage> : produce_base<D, llm::OS::Storage::Search::IValueAndLanguage>
    {
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Language(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Language(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Storage::Search
{
    inline auto ContentIndexer::GetIndexer(param::hstring const& indexName)
    {
        return impl::call_factory<ContentIndexer, IContentIndexerStatics>([&](IContentIndexerStatics const& f) { return f.GetIndexer(indexName); });
    }
    inline auto ContentIndexer::GetIndexer()
    {
        return impl::call_factory_cast<llm::OS::Storage::Search::ContentIndexer(*)(IContentIndexerStatics const&), ContentIndexer, IContentIndexerStatics>([](IContentIndexerStatics const& f) { return f.GetIndexer(); });
    }
    inline IndexableContent::IndexableContent() :
        IndexableContent(impl::call_factory_cast<IndexableContent(*)(llm::OS::Foundation::IActivationFactory const&), IndexableContent>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<IndexableContent>(); }))
    {
    }
    inline QueryOptions::QueryOptions() :
        QueryOptions(impl::call_factory_cast<QueryOptions(*)(llm::OS::Foundation::IActivationFactory const&), QueryOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<QueryOptions>(); }))
    {
    }
    inline QueryOptions::QueryOptions(llm::OS::Storage::Search::CommonFileQuery const& query, param::iterable<hstring> const& fileTypeFilter) :
        QueryOptions(impl::call_factory<QueryOptions, IQueryOptionsFactory>([&](IQueryOptionsFactory const& f) { return f.CreateCommonFileQuery(query, fileTypeFilter); }))
    {
    }
    inline QueryOptions::QueryOptions(llm::OS::Storage::Search::CommonFolderQuery const& query) :
        QueryOptions(impl::call_factory<QueryOptions, IQueryOptionsFactory>([&](IQueryOptionsFactory const& f) { return f.CreateCommonFolderQuery(query); }))
    {
    }
    inline ValueAndLanguage::ValueAndLanguage() :
        ValueAndLanguage(impl::call_factory_cast<ValueAndLanguage(*)(llm::OS::Foundation::IActivationFactory const&), ValueAndLanguage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ValueAndLanguage>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Storage::Search::IContentIndexer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IContentIndexerQuery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IContentIndexerQueryOperations> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IContentIndexerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IIndexableContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IQueryOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IQueryOptionsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IQueryOptionsWithProviderFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageFileQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageFileQueryResult2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageFolderQueryOperations> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageFolderQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageItemQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageLibraryChangeTrackerTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageLibraryContentChangedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IStorageQueryResultBase> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IValueAndLanguage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::ContentIndexer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::ContentIndexerQuery> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::IndexableContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::QueryOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::SortEntryVector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::StorageFileQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::StorageFolderQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::StorageItemQueryResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::StorageLibraryChangeTrackerTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::StorageLibraryContentChangedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Storage::Search::ValueAndLanguage> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
