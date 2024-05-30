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
#ifndef LLM_OS_Storage_2_H
#define LLM_OS_Storage_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Search.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Storage.1.h"
LLM_EXPORT namespace llm:OS::Storage
{
    struct ApplicationDataSetVersionHandler : llm:OS::Foundation::IUnknown
    {
        ApplicationDataSetVersionHandler(std::nullptr_t = nullptr) noexcept {}
        ApplicationDataSetVersionHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ApplicationDataSetVersionHandler(L lambda);
        template <typename F> ApplicationDataSetVersionHandler(F* function);
        template <typename O, typename M> ApplicationDataSetVersionHandler(O* object, M method);
        template <typename O, typename M> ApplicationDataSetVersionHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ApplicationDataSetVersionHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Storage::SetVersionRequest const& setVersionRequest) const;
    };
    struct StreamedFileDataRequestedHandler : llm:OS::Foundation::IUnknown
    {
        StreamedFileDataRequestedHandler(std::nullptr_t = nullptr) noexcept {}
        StreamedFileDataRequestedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> StreamedFileDataRequestedHandler(L lambda);
        template <typename F> StreamedFileDataRequestedHandler(F* function);
        template <typename O, typename M> StreamedFileDataRequestedHandler(O* object, M method);
        template <typename O, typename M> StreamedFileDataRequestedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> StreamedFileDataRequestedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Storage::StreamedFileDataRequest const& stream) const;
    };
    struct __declspec(empty_bases) AppDataPaths : llm:OS::Storage::IAppDataPaths
    {
        AppDataPaths(std::nullptr_t) noexcept {}
        AppDataPaths(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IAppDataPaths(ptr, take_ownership_from_abi) {}
        static auto GetForUser(llm:OS::System::User const& user);
        static auto GetDefault();
    };
    struct __declspec(empty_bases) ApplicationData : llm:OS::Storage::IApplicationData,
        impl::require<ApplicationData, llm:OS::Storage::IApplicationData2, llm:OS::Storage::IApplicationData3, llm:OS::Foundation::IClosable>
    {
        ApplicationData(std::nullptr_t) noexcept {}
        ApplicationData(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IApplicationData(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Current();
        static auto GetForUserAsync(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) ApplicationDataCompositeValue : llm:OS::Foundation::Collections::IPropertySet
    {
        ApplicationDataCompositeValue(std::nullptr_t) noexcept {}
        ApplicationDataCompositeValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IPropertySet(ptr, take_ownership_from_abi) {}
        ApplicationDataCompositeValue();
    };
    struct __declspec(empty_bases) ApplicationDataContainer : llm:OS::Storage::IApplicationDataContainer,
        impl::require<ApplicationDataContainer, llm:OS::Foundation::IClosable>
    {
        ApplicationDataContainer(std::nullptr_t) noexcept {}
        ApplicationDataContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IApplicationDataContainer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ApplicationDataContainerSettings : llm:OS::Foundation::Collections::IPropertySet
    {
        ApplicationDataContainerSettings(std::nullptr_t) noexcept {}
        ApplicationDataContainerSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IPropertySet(ptr, take_ownership_from_abi) {}
    };
    struct CachedFileManager
    {
        CachedFileManager() = delete;
        static auto DeferUpdates(llm:OS::Storage::IStorageFile const& file);
        static auto CompleteUpdatesAsync(llm:OS::Storage::IStorageFile const& file);
    };
    struct DownloadsFolder
    {
        DownloadsFolder() = delete;
        static auto CreateFileAsync(param::hstring const& desiredName);
        static auto CreateFolderAsync(param::hstring const& desiredName);
        static auto CreateFileAsync(param::hstring const& desiredName, llm:OS::Storage::CreationCollisionOption const& option);
        static auto CreateFolderAsync(param::hstring const& desiredName, llm:OS::Storage::CreationCollisionOption const& option);
        static auto CreateFileForUserAsync(llm:OS::System::User const& user, param::hstring const& desiredName);
        static auto CreateFolderForUserAsync(llm:OS::System::User const& user, param::hstring const& desiredName);
        static auto CreateFileForUserAsync(llm:OS::System::User const& user, param::hstring const& desiredName, llm:OS::Storage::CreationCollisionOption const& option);
        static auto CreateFolderForUserAsync(llm:OS::System::User const& user, param::hstring const& desiredName, llm:OS::Storage::CreationCollisionOption const& option);
    };
    struct FileIO
    {
        FileIO() = delete;
        static auto ReadTextAsync(llm:OS::Storage::IStorageFile const& file);
        static auto ReadTextAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto WriteTextAsync(llm:OS::Storage::IStorageFile const& file, param::hstring const& contents);
        static auto WriteTextAsync(llm:OS::Storage::IStorageFile const& file, param::hstring const& contents, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto AppendTextAsync(llm:OS::Storage::IStorageFile const& file, param::hstring const& contents);
        static auto AppendTextAsync(llm:OS::Storage::IStorageFile const& file, param::hstring const& contents, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto ReadLinesAsync(llm:OS::Storage::IStorageFile const& file);
        static auto ReadLinesAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto WriteLinesAsync(llm:OS::Storage::IStorageFile const& file, param::async_iterable<hstring> const& lines);
        static auto WriteLinesAsync(llm:OS::Storage::IStorageFile const& file, param::async_iterable<hstring> const& lines, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto AppendLinesAsync(llm:OS::Storage::IStorageFile const& file, param::async_iterable<hstring> const& lines);
        static auto AppendLinesAsync(llm:OS::Storage::IStorageFile const& file, param::async_iterable<hstring> const& lines, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto ReadBufferAsync(llm:OS::Storage::IStorageFile const& file);
        static auto WriteBufferAsync(llm:OS::Storage::IStorageFile const& file, llm:OS::Storage::Streams::IBuffer const& buffer);
        static auto WriteBytesAsync(llm:OS::Storage::IStorageFile const& file, array_view<uint8_t const> buffer);
    };
    struct KnownFolders
    {
        KnownFolders() = delete;
        [[nodiscard]] static auto CameraRoll();
        [[nodiscard]] static auto Playlists();
        [[nodiscard]] static auto SavedPictures();
        [[nodiscard]] static auto MusicLibrary();
        [[nodiscard]] static auto PicturesLibrary();
        [[nodiscard]] static auto VideosLibrary();
        [[nodiscard]] static auto DocumentsLibrary();
        [[nodiscard]] static auto HomeGroup();
        [[nodiscard]] static auto RemovableDevices();
        [[nodiscard]] static auto MediaServerDevices();
        [[nodiscard]] static auto Objects3D();
        [[nodiscard]] static auto AppCaptures();
        [[nodiscard]] static auto RecordedCalls();
        static auto GetFolderForUserAsync(llm:OS::System::User const& user, llm:OS::Storage::KnownFolderId const& folderId);
        static auto RequestAccessAsync(llm:OS::Storage::KnownFolderId const& folderId);
        static auto RequestAccessForUserAsync(llm:OS::System::User const& user, llm:OS::Storage::KnownFolderId const& folderId);
        static auto GetFolderAsync(llm:OS::Storage::KnownFolderId const& folderId);
    };
    struct PathIO
    {
        PathIO() = delete;
        static auto ReadTextAsync(param::hstring const& absolutePath);
        static auto ReadTextAsync(param::hstring const& absolutePath, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto WriteTextAsync(param::hstring const& absolutePath, param::hstring const& contents);
        static auto WriteTextAsync(param::hstring const& absolutePath, param::hstring const& contents, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto AppendTextAsync(param::hstring const& absolutePath, param::hstring const& contents);
        static auto AppendTextAsync(param::hstring const& absolutePath, param::hstring const& contents, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto ReadLinesAsync(param::hstring const& absolutePath);
        static auto ReadLinesAsync(param::hstring const& absolutePath, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto WriteLinesAsync(param::hstring const& absolutePath, param::async_iterable<hstring> const& lines);
        static auto WriteLinesAsync(param::hstring const& absolutePath, param::async_iterable<hstring> const& lines, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto AppendLinesAsync(param::hstring const& absolutePath, param::async_iterable<hstring> const& lines);
        static auto AppendLinesAsync(param::hstring const& absolutePath, param::async_iterable<hstring> const& lines, llm:OS::Storage::Streams::UnicodeEncoding const& encoding);
        static auto ReadBufferAsync(param::hstring const& absolutePath);
        static auto WriteBufferAsync(param::hstring const& absolutePath, llm:OS::Storage::Streams::IBuffer const& buffer);
        static auto WriteBytesAsync(param::hstring const& absolutePath, array_view<uint8_t const> buffer);
    };
    struct __declspec(empty_bases) SetVersionDeferral : llm:OS::Storage::ISetVersionDeferral
    {
        SetVersionDeferral(std::nullptr_t) noexcept {}
        SetVersionDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISetVersionDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SetVersionRequest : llm:OS::Storage::ISetVersionRequest
    {
        SetVersionRequest(std::nullptr_t) noexcept {}
        SetVersionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISetVersionRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageFile : llm:OS::Storage::IStorageFile,
        impl::require<StorageFile, llm:OS::Storage::IStorageItemProperties, llm:OS::Storage::IStorageItemProperties2, llm:OS::Storage::IStorageItem2, llm:OS::Storage::IStorageItemPropertiesWithProvider, llm:OS::Storage::IStorageFilePropertiesWithAvailability, llm:OS::Storage::IStorageFile2>
    {
        StorageFile(std::nullptr_t) noexcept {}
        StorageFile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageFile(ptr, take_ownership_from_abi) {}
        using llm:OS::Storage::IStorageFile::OpenAsync;
        using impl::consume_t<StorageFile, llm:OS::Storage::IStorageFile2>::OpenAsync;
        using llm:OS::Storage::IStorageFile::OpenTransactedWriteAsync;
        using impl::consume_t<StorageFile, llm:OS::Storage::IStorageFile2>::OpenTransactedWriteAsync;
        static auto GetFileFromPathAsync(param::hstring const& path);
        static auto GetFileFromApplicationUriAsync(llm:OS::Foundation::Uri const& uri);
        static auto CreateStreamedFileAsync(param::hstring const& displayNameWithExtension, llm:OS::Storage::StreamedFileDataRequestedHandler const& dataRequested, llm:OS::Storage::Streams::IRandomAccessStreamReference const& thumbnail);
        static auto ReplaceWithStreamedFileAsync(llm:OS::Storage::IStorageFile const& fileToReplace, llm:OS::Storage::StreamedFileDataRequestedHandler const& dataRequested, llm:OS::Storage::Streams::IRandomAccessStreamReference const& thumbnail);
        static auto CreateStreamedFileFromUriAsync(param::hstring const& displayNameWithExtension, llm:OS::Foundation::Uri const& uri, llm:OS::Storage::Streams::IRandomAccessStreamReference const& thumbnail);
        static auto ReplaceWithStreamedFileFromUriAsync(llm:OS::Storage::IStorageFile const& fileToReplace, llm:OS::Foundation::Uri const& uri, llm:OS::Storage::Streams::IRandomAccessStreamReference const& thumbnail);
        static auto GetFileFromPathForUserAsync(llm:OS::System::User const& user, param::hstring const& path);
    };
    struct __declspec(empty_bases) StorageFolder : llm:OS::Storage::IStorageFolder,
        impl::require<StorageFolder, llm:OS::Storage::Search::IStorageFolderQueryOperations, llm:OS::Storage::IStorageItemProperties, llm:OS::Storage::IStorageItemProperties2, llm:OS::Storage::IStorageItem2, llm:OS::Storage::IStorageFolder2, llm:OS::Storage::IStorageItemPropertiesWithProvider, llm:OS::Storage::IStorageFolder3>
    {
        StorageFolder(std::nullptr_t) noexcept {}
        StorageFolder(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageFolder(ptr, take_ownership_from_abi) {}
        using llm:OS::Storage::IStorageFolder::GetFilesAsync;
        using impl::consume_t<StorageFolder, llm:OS::Storage::Search::IStorageFolderQueryOperations>::GetFilesAsync;
        using llm:OS::Storage::IStorageFolder::GetFoldersAsync;
        using impl::consume_t<StorageFolder, llm:OS::Storage::Search::IStorageFolderQueryOperations>::GetFoldersAsync;
        using llm:OS::Storage::IStorageFolder::GetItemsAsync;
        using impl::consume_t<StorageFolder, llm:OS::Storage::Search::IStorageFolderQueryOperations>::GetItemsAsync;
        static auto GetFolderFromPathAsync(param::hstring const& path);
        static auto GetFolderFromPathForUserAsync(llm:OS::System::User const& user, param::hstring const& path);
    };
    struct __declspec(empty_bases) StorageLibrary : llm:OS::Storage::IStorageLibrary,
        impl::require<StorageLibrary, llm:OS::Storage::IStorageLibrary2, llm:OS::Storage::IStorageLibrary3>
    {
        StorageLibrary(std::nullptr_t) noexcept {}
        StorageLibrary(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageLibrary(ptr, take_ownership_from_abi) {}
        static auto GetLibraryAsync(llm:OS::Storage::KnownLibraryId const& libraryId);
        static auto GetLibraryForUserAsync(llm:OS::System::User const& user, llm:OS::Storage::KnownLibraryId const& libraryId);
    };
    struct __declspec(empty_bases) StorageLibraryChange : llm:OS::Storage::IStorageLibraryChange
    {
        StorageLibraryChange(std::nullptr_t) noexcept {}
        StorageLibraryChange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageLibraryChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageLibraryChangeReader : llm:OS::Storage::IStorageLibraryChangeReader,
        impl::require<StorageLibraryChangeReader, llm:OS::Storage::IStorageLibraryChangeReader2>
    {
        StorageLibraryChangeReader(std::nullptr_t) noexcept {}
        StorageLibraryChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageLibraryChangeReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageLibraryChangeTracker : llm:OS::Storage::IStorageLibraryChangeTracker,
        impl::require<StorageLibraryChangeTracker, llm:OS::Storage::IStorageLibraryChangeTracker2>
    {
        StorageLibraryChangeTracker(std::nullptr_t) noexcept {}
        StorageLibraryChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageLibraryChangeTracker(ptr, take_ownership_from_abi) {}
        using llm:OS::Storage::IStorageLibraryChangeTracker::Enable;
        using impl::consume_t<StorageLibraryChangeTracker, llm:OS::Storage::IStorageLibraryChangeTracker2>::Enable;
    };
    struct __declspec(empty_bases) StorageLibraryChangeTrackerOptions : llm:OS::Storage::IStorageLibraryChangeTrackerOptions
    {
        StorageLibraryChangeTrackerOptions(std::nullptr_t) noexcept {}
        StorageLibraryChangeTrackerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageLibraryChangeTrackerOptions(ptr, take_ownership_from_abi) {}
        StorageLibraryChangeTrackerOptions();
    };
    struct __declspec(empty_bases) StorageLibraryLastChangeId : llm:OS::Storage::IStorageLibraryLastChangeId
    {
        StorageLibraryLastChangeId(std::nullptr_t) noexcept {}
        StorageLibraryLastChangeId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageLibraryLastChangeId(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Unknown();
    };
    struct __declspec(empty_bases) StorageProvider : llm:OS::Storage::IStorageProvider,
        impl::require<StorageProvider, llm:OS::Storage::IStorageProvider2>
    {
        StorageProvider(std::nullptr_t) noexcept {}
        StorageProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageProvider(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StorageStreamTransaction : llm:OS::Storage::IStorageStreamTransaction
    {
        StorageStreamTransaction(std::nullptr_t) noexcept {}
        StorageStreamTransaction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IStorageStreamTransaction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamedFileDataRequest : llm:OS::Storage::Streams::IOutputStream,
        impl::require<StreamedFileDataRequest, llm:OS::Storage::IStreamedFileDataRequest>
    {
        StreamedFileDataRequest(std::nullptr_t) noexcept {}
        StreamedFileDataRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::Streams::IOutputStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemAudioProperties : llm:OS::Storage::ISystemAudioProperties
    {
        SystemAudioProperties(std::nullptr_t) noexcept {}
        SystemAudioProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemAudioProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemDataPaths : llm:OS::Storage::ISystemDataPaths
    {
        SystemDataPaths(std::nullptr_t) noexcept {}
        SystemDataPaths(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemDataPaths(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) SystemGPSProperties : llm:OS::Storage::ISystemGPSProperties
    {
        SystemGPSProperties(std::nullptr_t) noexcept {}
        SystemGPSProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemGPSProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemImageProperties : llm:OS::Storage::ISystemImageProperties
    {
        SystemImageProperties(std::nullptr_t) noexcept {}
        SystemImageProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemImageProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMediaProperties : llm:OS::Storage::ISystemMediaProperties
    {
        SystemMediaProperties(std::nullptr_t) noexcept {}
        SystemMediaProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemMediaProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemMusicProperties : llm:OS::Storage::ISystemMusicProperties
    {
        SystemMusicProperties(std::nullptr_t) noexcept {}
        SystemMusicProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemMusicProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemPhotoProperties : llm:OS::Storage::ISystemPhotoProperties
    {
        SystemPhotoProperties(std::nullptr_t) noexcept {}
        SystemPhotoProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemPhotoProperties(ptr, take_ownership_from_abi) {}
    };
    struct SystemProperties
    {
        SystemProperties() = delete;
        [[nodiscard]] static auto Author();
        [[nodiscard]] static auto Comment();
        [[nodiscard]] static auto ItemNameDisplay();
        [[nodiscard]] static auto Keywords();
        [[nodiscard]] static auto Rating();
        [[nodiscard]] static auto Title();
        [[nodiscard]] static auto Audio();
        [[nodiscard]] static auto GPS();
        [[nodiscard]] static auto Media();
        [[nodiscard]] static auto Music();
        [[nodiscard]] static auto Photo();
        [[nodiscard]] static auto Video();
        [[nodiscard]] static auto Image();
    };
    struct __declspec(empty_bases) SystemVideoProperties : llm:OS::Storage::ISystemVideoProperties
    {
        SystemVideoProperties(std::nullptr_t) noexcept {}
        SystemVideoProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::ISystemVideoProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataPaths : llm:OS::Storage::IUserDataPaths
    {
        UserDataPaths(std::nullptr_t) noexcept {}
        UserDataPaths(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Storage::IUserDataPaths(ptr, take_ownership_from_abi) {}
        static auto GetForUser(llm:OS::System::User const& user);
        static auto GetDefault();
    };
}
#endif
