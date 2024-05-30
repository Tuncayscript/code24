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
#ifndef LLM_OS_Storage_BulkAccess_2_H
#define LLM_OS_Storage_BulkAccess_2_H
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Storage.FileProperties.1.h"
#include "llm/impl/Windows.Storage.Search.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Storage.BulkAccess.1.h"
LLM_EXPORT namespace llm:OS::Storage::BulkAccess
{
    struct __declspec(empty_bases) FileInformation : llm:OS::Storage::BulkAccess::IStorageItemInformation,
        impl::require<FileInformation, llm:OS::Storage::IStorageItem, llm:OS::Storage::Streams::IRandomAccessStreamReference, llm:OS::Storage::Streams::IInputStreamReference, llm:OS::Storage::IStorageFile, llm:OS::Storage::IStorageItemProperties, llm:OS::Storage::IStorageItem2, llm:OS::Storage::IStorageItemPropertiesWithProvider, llm:OS::Storage::IStorageFilePropertiesWithAvailability, llm:OS::Storage::IStorageFile2>
    {
        FileInformation(std::nullptr_t) noexcept {}
        FileInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::BulkAccess::IStorageItemInformation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<FileInformation, llm:OS::Storage::IStorageFile>::OpenAsync;
        using impl::consume_t<FileInformation, llm:OS::Storage::IStorageFile2>::OpenAsync;
        using impl::consume_t<FileInformation, llm:OS::Storage::IStorageFile>::OpenTransactedWriteAsync;
        using impl::consume_t<FileInformation, llm:OS::Storage::IStorageFile2>::OpenTransactedWriteAsync;
    };
    struct __declspec(empty_bases) FileInformationFactory : llm:OS::Storage::BulkAccess::IFileInformationFactory
    {
        FileInformationFactory(std::nullptr_t) noexcept {}
        FileInformationFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::BulkAccess::IFileInformationFactory(ptr, take_ownership_from_abi) {}
        FileInformationFactory(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode);
        FileInformationFactory(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize);
        FileInformationFactory(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm:OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions);
        FileInformationFactory(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm:OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions, bool delayLoad);
    };
    struct __declspec(empty_bases) FolderInformation : llm:OS::Storage::BulkAccess::IStorageItemInformation,
        impl::require<FolderInformation, llm:OS::Storage::IStorageItem, llm:OS::Storage::IStorageFolder, llm:OS::Storage::IStorageItemProperties, llm:OS::Storage::Search::IStorageFolderQueryOperations, llm:OS::Storage::IStorageItem2, llm:OS::Storage::IStorageFolder2, llm:OS::Storage::IStorageItemPropertiesWithProvider>
    {
        FolderInformation(std::nullptr_t) noexcept {}
        FolderInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::BulkAccess::IStorageItemInformation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<FolderInformation, llm:OS::Storage::IStorageFolder>::GetFilesAsync;
        using impl::consume_t<FolderInformation, llm:OS::Storage::Search::IStorageFolderQueryOperations>::GetFilesAsync;
        using impl::consume_t<FolderInformation, llm:OS::Storage::IStorageFolder>::GetFoldersAsync;
        using impl::consume_t<FolderInformation, llm:OS::Storage::Search::IStorageFolderQueryOperations>::GetFoldersAsync;
        using impl::consume_t<FolderInformation, llm:OS::Storage::IStorageFolder>::GetItemsAsync;
        using impl::consume_t<FolderInformation, llm:OS::Storage::Search::IStorageFolderQueryOperations>::GetItemsAsync;
    };
}
#endif
