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
#ifndef LLM_OS_Storage_BulkAccess_0_H
#define LLM_OS_Storage_BulkAccess_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Storage::FileProperties
{
    struct BasicProperties;
    struct DocumentProperties;
    struct ImageProperties;
    struct MusicProperties;
    struct StorageItemThumbnail;
    enum class ThumbnailMode : int32_t;
    enum class ThumbnailOptions : uint32_t;
    struct VideoProperties;
}
LLM_EXPORT namespace llm:OS::Storage::Search
{
    struct IStorageQueryResultBase;
}
LLM_EXPORT namespace llm:OS::Storage::BulkAccess
{
    struct IFileInformationFactory;
    struct IFileInformationFactoryFactory;
    struct IStorageItemInformation;
    struct FileInformation;
    struct FileInformationFactory;
    struct FolderInformation;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Storage::BulkAccess::IFileInformationFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::BulkAccess::IFileInformationFactoryFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::BulkAccess::IStorageItemInformation>{ using type = interface_category; };
    template <> struct category<llm:OS::Storage::BulkAccess::FileInformation>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::BulkAccess::FileInformationFactory>{ using type = class_category; };
    template <> struct category<llm:OS::Storage::BulkAccess::FolderInformation>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Storage::BulkAccess::FileInformation> = L"Windows.Storage.BulkAccess.FileInformation";
    template <> inline constexpr auto& name_v<llm:OS::Storage::BulkAccess::FileInformationFactory> = L"Windows.Storage.BulkAccess.FileInformationFactory";
    template <> inline constexpr auto& name_v<llm:OS::Storage::BulkAccess::FolderInformation> = L"Windows.Storage.BulkAccess.FolderInformation";
    template <> inline constexpr auto& name_v<llm:OS::Storage::BulkAccess::IFileInformationFactory> = L"Windows.Storage.BulkAccess.IFileInformationFactory";
    template <> inline constexpr auto& name_v<llm:OS::Storage::BulkAccess::IFileInformationFactoryFactory> = L"Windows.Storage.BulkAccess.IFileInformationFactoryFactory";
    template <> inline constexpr auto& name_v<llm:OS::Storage::BulkAccess::IStorageItemInformation> = L"Windows.Storage.BulkAccess.IStorageItemInformation";
    template <> inline constexpr guid guid_v<llm:OS::Storage::BulkAccess::IFileInformationFactory>{ 0x401D88BE,0x960F,0x4D6D,{ 0xA7,0xD0,0x1A,0x38,0x61,0xE7,0x6C,0x83 } }; // 401D88BE-960F-4D6D-A7D0-1A3861E76C83
    template <> inline constexpr guid guid_v<llm:OS::Storage::BulkAccess::IFileInformationFactoryFactory>{ 0x84EA0E7D,0xE4A2,0x4F00,{ 0x8A,0xFA,0xAF,0x5E,0x0F,0x82,0x6B,0xD5 } }; // 84EA0E7D-E4A2-4F00-8AFA-AF5E0F826BD5
    template <> inline constexpr guid guid_v<llm:OS::Storage::BulkAccess::IStorageItemInformation>{ 0x87A5CB8B,0x8972,0x4F40,{ 0x8D,0xE0,0xD8,0x6F,0xB1,0x79,0xD8,0xFA } }; // 87A5CB8B-8972-4F40-8DE0-D86FB179D8FA
    template <> struct default_interface<llm:OS::Storage::BulkAccess::FileInformation>{ using type = llm:OS::Storage::BulkAccess::IStorageItemInformation; };
    template <> struct default_interface<llm:OS::Storage::BulkAccess::FileInformationFactory>{ using type = llm:OS::Storage::BulkAccess::IFileInformationFactory; };
    template <> struct default_interface<llm:OS::Storage::BulkAccess::FolderInformation>{ using type = llm:OS::Storage::BulkAccess::IStorageItemInformation; };
    template <> struct abi<llm:OS::Storage::BulkAccess::IFileInformationFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetItemsAsync(uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetItemsAsyncDefaultStartAndCount(void**) noexcept = 0;
            virtual int32_t __stdcall GetFilesAsync(uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetFilesAsyncDefaultStartAndCount(void**) noexcept = 0;
            virtual int32_t __stdcall GetFoldersAsync(uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetFoldersAsyncDefaultStartAndCount(void**) noexcept = 0;
            virtual int32_t __stdcall GetVirtualizedItemsVector(void**) noexcept = 0;
            virtual int32_t __stdcall GetVirtualizedFilesVector(void**) noexcept = 0;
            virtual int32_t __stdcall GetVirtualizedFoldersVector(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::BulkAccess::IFileInformationFactoryFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithMode(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithModeAndSize(void*, int32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithModeAndSizeAndOptions(void*, int32_t, uint32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithModeAndSizeAndOptionsAndFlags(void*, int32_t, uint32_t, uint32_t, bool, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Storage::BulkAccess::IStorageItemInformation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MusicProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_VideoProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_ImageProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_BasicProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall add_ThumbnailUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ThumbnailUpdated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PropertiesUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PropertiesUpdated(llm::event_token) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Storage_BulkAccess_IFileInformationFactory
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::BulkAccess::IStorageItemInformation>>) GetItemsAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::BulkAccess::IStorageItemInformation>>) GetItemsAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::BulkAccess::FileInformation>>) GetFilesAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::BulkAccess::FileInformation>>) GetFilesAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::BulkAccess::FolderInformation>>) GetFoldersAsync(uint32_t startIndex, uint32_t maxItemsToRetrieve) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Storage::BulkAccess::FolderInformation>>) GetFoldersAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) GetVirtualizedItemsVector() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) GetVirtualizedFilesVector() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) GetVirtualizedFoldersVector() const;
    };
    template <> struct consume<llm:OS::Storage::BulkAccess::IFileInformationFactory>
    {
        template <typename D> using type = consume_Windows_Storage_BulkAccess_IFileInformationFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_BulkAccess_IFileInformationFactoryFactory
    {
        LLM_IMPL_AUTO(llm:OS::Storage::BulkAccess::FileInformationFactory) CreateWithMode(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode) const;
        LLM_IMPL_AUTO(llm:OS::Storage::BulkAccess::FileInformationFactory) CreateWithModeAndSize(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize) const;
        LLM_IMPL_AUTO(llm:OS::Storage::BulkAccess::FileInformationFactory) CreateWithModeAndSizeAndOptions(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm:OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions) const;
        LLM_IMPL_AUTO(llm:OS::Storage::BulkAccess::FileInformationFactory) CreateWithModeAndSizeAndOptionsAndFlags(llm:OS::Storage::Search::IStorageQueryResultBase const& queryResult, llm:OS::Storage::FileProperties::ThumbnailMode const& mode, uint32_t requestedThumbnailSize, llm:OS::Storage::FileProperties::ThumbnailOptions const& thumbnailOptions, bool delayLoad) const;
    };
    template <> struct consume<llm:OS::Storage::BulkAccess::IFileInformationFactoryFactory>
    {
        template <typename D> using type = consume_Windows_Storage_BulkAccess_IFileInformationFactoryFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Storage_BulkAccess_IStorageItemInformation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::FileProperties::MusicProperties) MusicProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::FileProperties::VideoProperties) VideoProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::FileProperties::ImageProperties) ImageProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::FileProperties::DocumentProperties) DocumentProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::FileProperties::BasicProperties) BasicProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::FileProperties::StorageItemThumbnail) Thumbnail() const;
        LLM_IMPL_AUTO(llm::event_token) ThumbnailUpdated(llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::BulkAccess::IStorageItemInformation, llm:OS::Foundation::IInspectable> const& changedHandler) const;
        using ThumbnailUpdated_revoker = impl::event_revoker<llm:OS::Storage::BulkAccess::IStorageItemInformation, &impl::abi_t<llm:OS::Storage::BulkAccess::IStorageItemInformation>::remove_ThumbnailUpdated>;
        [[nodiscard]] ThumbnailUpdated_revoker ThumbnailUpdated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::BulkAccess::IStorageItemInformation, llm:OS::Foundation::IInspectable> const& changedHandler) const;
        LLM_IMPL_AUTO(void) ThumbnailUpdated(llm::event_token const& eventCookie) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PropertiesUpdated(llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::BulkAccess::IStorageItemInformation, llm:OS::Foundation::IInspectable> const& changedHandler) const;
        using PropertiesUpdated_revoker = impl::event_revoker<llm:OS::Storage::BulkAccess::IStorageItemInformation, &impl::abi_t<llm:OS::Storage::BulkAccess::IStorageItemInformation>::remove_PropertiesUpdated>;
        [[nodiscard]] PropertiesUpdated_revoker PropertiesUpdated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Storage::BulkAccess::IStorageItemInformation, llm:OS::Foundation::IInspectable> const& changedHandler) const;
        LLM_IMPL_AUTO(void) PropertiesUpdated(llm::event_token const& eventCookie) const noexcept;
    };
    template <> struct consume<llm:OS::Storage::BulkAccess::IStorageItemInformation>
    {
        template <typename D> using type = consume_Windows_Storage_BulkAccess_IStorageItemInformation<D>;
    };
}
#endif
