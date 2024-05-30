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
#ifndef LLM_OS_Storage_1_H
#define LLM_OS_Storage_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Storage.Streams.0.h"
#include "llm/impl/Windows.Storage.0.h"
LLM_EXPORT namespace llm:OS::Storage
{
    struct __declspec(empty_bases) IAppDataPaths :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDataPaths>
    {
        IAppDataPaths(std::nullptr_t = nullptr) noexcept {}
        IAppDataPaths(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppDataPathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppDataPathsStatics>
    {
        IAppDataPathsStatics(std::nullptr_t = nullptr) noexcept {}
        IAppDataPathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationData :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationData>
    {
        IApplicationData(std::nullptr_t = nullptr) noexcept {}
        IApplicationData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationData2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationData2>
    {
        IApplicationData2(std::nullptr_t = nullptr) noexcept {}
        IApplicationData2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationData3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationData3>
    {
        IApplicationData3(std::nullptr_t = nullptr) noexcept {}
        IApplicationData3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationDataContainer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationDataContainer>
    {
        IApplicationDataContainer(std::nullptr_t = nullptr) noexcept {}
        IApplicationDataContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationDataStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationDataStatics>
    {
        IApplicationDataStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationDataStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationDataStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationDataStatics2>
    {
        IApplicationDataStatics2(std::nullptr_t = nullptr) noexcept {}
        IApplicationDataStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICachedFileManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileManagerStatics>
    {
        ICachedFileManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICachedFileManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadsFolderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadsFolderStatics>
    {
        IDownloadsFolderStatics(std::nullptr_t = nullptr) noexcept {}
        IDownloadsFolderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDownloadsFolderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDownloadsFolderStatics2>
    {
        IDownloadsFolderStatics2(std::nullptr_t = nullptr) noexcept {}
        IDownloadsFolderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileIOStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFileIOStatics>
    {
        IFileIOStatics(std::nullptr_t = nullptr) noexcept {}
        IFileIOStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersCameraRollStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersCameraRollStatics>
    {
        IKnownFoldersCameraRollStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersCameraRollStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersPlaylistsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersPlaylistsStatics>
    {
        IKnownFoldersPlaylistsStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersPlaylistsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersSavedPicturesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersSavedPicturesStatics>
    {
        IKnownFoldersSavedPicturesStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersSavedPicturesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersStatics>
    {
        IKnownFoldersStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersStatics2>
    {
        IKnownFoldersStatics2(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersStatics3>
    {
        IKnownFoldersStatics3(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownFoldersStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKnownFoldersStatics4>
    {
        IKnownFoldersStatics4(std::nullptr_t = nullptr) noexcept {}
        IKnownFoldersStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPathIOStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPathIOStatics>
    {
        IPathIOStatics(std::nullptr_t = nullptr) noexcept {}
        IPathIOStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISetVersionDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISetVersionDeferral>
    {
        ISetVersionDeferral(std::nullptr_t = nullptr) noexcept {}
        ISetVersionDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISetVersionRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISetVersionRequest>
    {
        ISetVersionRequest(std::nullptr_t = nullptr) noexcept {}
        ISetVersionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFile>,
        impl::require<llm:OS::Storage::IStorageFile, llm:OS::Storage::IStorageItem, llm:OS::Storage::Streams::IRandomAccessStreamReference, llm:OS::Storage::Streams::IInputStreamReference>
    {
        IStorageFile(std::nullptr_t = nullptr) noexcept {}
        IStorageFile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFile2>
    {
        IStorageFile2(std::nullptr_t = nullptr) noexcept {}
        IStorageFile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFilePropertiesWithAvailability :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFilePropertiesWithAvailability>
    {
        IStorageFilePropertiesWithAvailability(std::nullptr_t = nullptr) noexcept {}
        IStorageFilePropertiesWithAvailability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFileStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFileStatics>
    {
        IStorageFileStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageFileStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFileStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFileStatics2>
    {
        IStorageFileStatics2(std::nullptr_t = nullptr) noexcept {}
        IStorageFileStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolder :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolder>,
        impl::require<llm:OS::Storage::IStorageFolder, llm:OS::Storage::IStorageItem>
    {
        IStorageFolder(std::nullptr_t = nullptr) noexcept {}
        IStorageFolder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolder2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolder2>
    {
        IStorageFolder2(std::nullptr_t = nullptr) noexcept {}
        IStorageFolder2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolder3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolder3>
    {
        IStorageFolder3(std::nullptr_t = nullptr) noexcept {}
        IStorageFolder3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolderStatics>
    {
        IStorageFolderStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageFolderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageFolderStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageFolderStatics2>
    {
        IStorageFolderStatics2(std::nullptr_t = nullptr) noexcept {}
        IStorageFolderStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItem>
    {
        IStorageItem(std::nullptr_t = nullptr) noexcept {}
        IStorageItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItem2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItem2>,
        impl::require<llm:OS::Storage::IStorageItem2, llm:OS::Storage::IStorageItem>
    {
        IStorageItem2(std::nullptr_t = nullptr) noexcept {}
        IStorageItem2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemProperties>
    {
        IStorageItemProperties(std::nullptr_t = nullptr) noexcept {}
        IStorageItemProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemProperties2>,
        impl::require<llm:OS::Storage::IStorageItemProperties2, llm:OS::Storage::IStorageItemProperties>
    {
        IStorageItemProperties2(std::nullptr_t = nullptr) noexcept {}
        IStorageItemProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageItemPropertiesWithProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageItemPropertiesWithProvider>,
        impl::require<llm:OS::Storage::IStorageItemPropertiesWithProvider, llm:OS::Storage::IStorageItemProperties>
    {
        IStorageItemPropertiesWithProvider(std::nullptr_t = nullptr) noexcept {}
        IStorageItemPropertiesWithProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibrary :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibrary>
    {
        IStorageLibrary(std::nullptr_t = nullptr) noexcept {}
        IStorageLibrary(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibrary2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibrary2>
    {
        IStorageLibrary2(std::nullptr_t = nullptr) noexcept {}
        IStorageLibrary2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibrary3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibrary3>
    {
        IStorageLibrary3(std::nullptr_t = nullptr) noexcept {}
        IStorageLibrary3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChange :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChange>
    {
        IStorageLibraryChange(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeReader :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeReader>
    {
        IStorageLibraryChangeReader(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeReader2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeReader2>
    {
        IStorageLibraryChangeReader2(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeReader2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeTracker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeTracker>
    {
        IStorageLibraryChangeTracker(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeTracker2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeTracker2>
    {
        IStorageLibraryChangeTracker2(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeTracker2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryChangeTrackerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryChangeTrackerOptions>
    {
        IStorageLibraryChangeTrackerOptions(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryChangeTrackerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryLastChangeId :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryLastChangeId>
    {
        IStorageLibraryLastChangeId(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryLastChangeId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryLastChangeIdStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryLastChangeIdStatics>
    {
        IStorageLibraryLastChangeIdStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryLastChangeIdStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryStatics>
    {
        IStorageLibraryStatics(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageLibraryStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageLibraryStatics2>
    {
        IStorageLibraryStatics2(std::nullptr_t = nullptr) noexcept {}
        IStorageLibraryStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProvider>
    {
        IStorageProvider(std::nullptr_t = nullptr) noexcept {}
        IStorageProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageProvider2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageProvider2>,
        impl::require<llm:OS::Storage::IStorageProvider2, llm:OS::Storage::IStorageProvider>
    {
        IStorageProvider2(std::nullptr_t = nullptr) noexcept {}
        IStorageProvider2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStorageStreamTransaction :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStorageStreamTransaction>,
        impl::require<llm:OS::Storage::IStorageStreamTransaction, llm:OS::Foundation::IClosable>
    {
        IStorageStreamTransaction(std::nullptr_t = nullptr) noexcept {}
        IStorageStreamTransaction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamedFileDataRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamedFileDataRequest>
    {
        IStreamedFileDataRequest(std::nullptr_t = nullptr) noexcept {}
        IStreamedFileDataRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemAudioProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemAudioProperties>
    {
        ISystemAudioProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemAudioProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemDataPaths :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemDataPaths>
    {
        ISystemDataPaths(std::nullptr_t = nullptr) noexcept {}
        ISystemDataPaths(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemDataPathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemDataPathsStatics>
    {
        ISystemDataPathsStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemDataPathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemGPSProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemGPSProperties>
    {
        ISystemGPSProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemGPSProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemImageProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemImageProperties>
    {
        ISystemImageProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemImageProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMediaProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMediaProperties>
    {
        ISystemMediaProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemMediaProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemMusicProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemMusicProperties>
    {
        ISystemMusicProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemMusicProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemPhotoProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemPhotoProperties>
    {
        ISystemPhotoProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemPhotoProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemProperties>
    {
        ISystemProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemVideoProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemVideoProperties>
    {
        ISystemVideoProperties(std::nullptr_t = nullptr) noexcept {}
        ISystemVideoProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataPaths :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataPaths>
    {
        IUserDataPaths(std::nullptr_t = nullptr) noexcept {}
        IUserDataPaths(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataPathsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataPathsStatics>
    {
        IUserDataPathsStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDataPathsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
