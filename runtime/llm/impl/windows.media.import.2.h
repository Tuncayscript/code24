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
#ifndef LLM_OS_Media_Import_2_H
#define LLM_OS_Media_Import_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Media.Import.1.h"
LLM_EXPORT namespace llm:OS::Media::Import
{
    struct PhotoImportProgress
    {
        uint32_t ItemsImported;
        uint32_t TotalItemsToImport;
        uint64_t BytesImported;
        uint64_t TotalBytesToImport;
        double ImportProgress;
    };
    inline bool operator==(PhotoImportProgress const& left, PhotoImportProgress const& right) noexcept
    {
        return left.ItemsImported == right.ItemsImported && left.TotalItemsToImport == right.TotalItemsToImport && left.BytesImported == right.BytesImported && left.TotalBytesToImport == right.TotalBytesToImport && left.ImportProgress == right.ImportProgress;
    }
    inline bool operator!=(PhotoImportProgress const& left, PhotoImportProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) PhotoImportDeleteImportedItemsFromSourceResult : llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult
    {
        PhotoImportDeleteImportedItemsFromSourceResult(std::nullptr_t) noexcept {}
        PhotoImportDeleteImportedItemsFromSourceResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportFindItemsResult : llm:OS::Media::Import::IPhotoImportFindItemsResult,
        impl::require<PhotoImportFindItemsResult, llm:OS::Media::Import::IPhotoImportFindItemsResult2>
    {
        PhotoImportFindItemsResult(std::nullptr_t) noexcept {}
        PhotoImportFindItemsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportFindItemsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportImportItemsResult : llm:OS::Media::Import::IPhotoImportImportItemsResult
    {
        PhotoImportImportItemsResult(std::nullptr_t) noexcept {}
        PhotoImportImportItemsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportImportItemsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportItem : llm:OS::Media::Import::IPhotoImportItem,
        impl::require<PhotoImportItem, llm:OS::Media::Import::IPhotoImportItem2>
    {
        PhotoImportItem(std::nullptr_t) noexcept {}
        PhotoImportItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportItemImportedEventArgs : llm:OS::Media::Import::IPhotoImportItemImportedEventArgs
    {
        PhotoImportItemImportedEventArgs(std::nullptr_t) noexcept {}
        PhotoImportItemImportedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportItemImportedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct PhotoImportManager
    {
        PhotoImportManager() = delete;
        static auto IsSupportedAsync();
        static auto FindAllSourcesAsync();
        static auto GetPendingOperations();
    };
    struct __declspec(empty_bases) PhotoImportOperation : llm:OS::Media::Import::IPhotoImportOperation
    {
        PhotoImportOperation(std::nullptr_t) noexcept {}
        PhotoImportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportSelectionChangedEventArgs : llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs
    {
        PhotoImportSelectionChangedEventArgs(std::nullptr_t) noexcept {}
        PhotoImportSelectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportSession : llm:OS::Media::Import::IPhotoImportSession,
        impl::require<PhotoImportSession, llm:OS::Media::Import::IPhotoImportSession2>
    {
        PhotoImportSession(std::nullptr_t) noexcept {}
        PhotoImportSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportSidecar : llm:OS::Media::Import::IPhotoImportSidecar
    {
        PhotoImportSidecar(std::nullptr_t) noexcept {}
        PhotoImportSidecar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportSidecar(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportSource : llm:OS::Media::Import::IPhotoImportSource
    {
        PhotoImportSource(std::nullptr_t) noexcept {}
        PhotoImportSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportSource(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(param::hstring const& sourceId);
        static auto FromFolderAsync(llm:OS::Storage::IStorageFolder const& sourceRootFolder);
    };
    struct __declspec(empty_bases) PhotoImportStorageMedium : llm:OS::Media::Import::IPhotoImportStorageMedium
    {
        PhotoImportStorageMedium(std::nullptr_t) noexcept {}
        PhotoImportStorageMedium(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportStorageMedium(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhotoImportVideoSegment : llm:OS::Media::Import::IPhotoImportVideoSegment
    {
        PhotoImportVideoSegment(std::nullptr_t) noexcept {}
        PhotoImportVideoSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::Import::IPhotoImportVideoSegment(ptr, take_ownership_from_abi) {}
    };
}
#endif
