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
#ifndef LLM_OS_Media_Import_0_H
#define LLM_OS_Media_Import_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult, typename TProgress> struct __declspec(empty_bases) IAsyncOperationWithProgress;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct IStorageFolder;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm:OS::Media::Import
{
    enum class PhotoImportAccessMode : int32_t
    {
        ReadWrite = 0,
        ReadOnly = 1,
        ReadAndDelete = 2,
    };
    enum class PhotoImportConnectionTransport : int32_t
    {
        Unknown = 0,
        Usb = 1,
        IP = 2,
        Bluetooth = 3,
    };
    enum class PhotoImportContentType : int32_t
    {
        Unknown = 0,
        Image = 1,
        Video = 2,
    };
    enum class PhotoImportContentTypeFilter : int32_t
    {
        OnlyImages = 0,
        OnlyVideos = 1,
        ImagesAndVideos = 2,
        ImagesAndVideosFromCameraRoll = 3,
    };
    enum class PhotoImportImportMode : int32_t
    {
        ImportEverything = 0,
        IgnoreSidecars = 1,
        IgnoreSiblings = 2,
        IgnoreSidecarsAndSiblings = 3,
    };
    enum class PhotoImportItemSelectionMode : int32_t
    {
        SelectAll = 0,
        SelectNone = 1,
        SelectNew = 2,
    };
    enum class PhotoImportPowerSource : int32_t
    {
        Unknown = 0,
        Battery = 1,
        External = 2,
    };
    enum class PhotoImportSourceType : int32_t
    {
        Generic = 0,
        Camera = 1,
        MediaPlayer = 2,
        Phone = 3,
        Video = 4,
        PersonalInfoManager = 5,
        AudioRecorder = 6,
    };
    enum class PhotoImportStage : int32_t
    {
        NotStarted = 0,
        FindingItems = 1,
        ImportingItems = 2,
        DeletingImportedItemsFromSource = 3,
    };
    enum class PhotoImportStorageMediumType : int32_t
    {
        Undefined = 0,
        Fixed = 1,
        Removable = 2,
    };
    enum class PhotoImportSubfolderCreationMode : int32_t
    {
        DoNotCreateSubfolders = 0,
        CreateSubfoldersFromFileDate = 1,
        CreateSubfoldersFromExifDate = 2,
        KeepOriginalFolderStructure = 3,
    };
    enum class PhotoImportSubfolderDateFormat : int32_t
    {
        Year = 0,
        YearMonth = 1,
        YearMonthDay = 2,
    };
    struct IPhotoImportDeleteImportedItemsFromSourceResult;
    struct IPhotoImportFindItemsResult;
    struct IPhotoImportFindItemsResult2;
    struct IPhotoImportImportItemsResult;
    struct IPhotoImportItem;
    struct IPhotoImportItem2;
    struct IPhotoImportItemImportedEventArgs;
    struct IPhotoImportManagerStatics;
    struct IPhotoImportOperation;
    struct IPhotoImportSelectionChangedEventArgs;
    struct IPhotoImportSession;
    struct IPhotoImportSession2;
    struct IPhotoImportSidecar;
    struct IPhotoImportSource;
    struct IPhotoImportSourceStatics;
    struct IPhotoImportStorageMedium;
    struct IPhotoImportVideoSegment;
    struct PhotoImportDeleteImportedItemsFromSourceResult;
    struct PhotoImportFindItemsResult;
    struct PhotoImportImportItemsResult;
    struct PhotoImportItem;
    struct PhotoImportItemImportedEventArgs;
    struct PhotoImportManager;
    struct PhotoImportOperation;
    struct PhotoImportSelectionChangedEventArgs;
    struct PhotoImportSession;
    struct PhotoImportSidecar;
    struct PhotoImportSource;
    struct PhotoImportStorageMedium;
    struct PhotoImportVideoSegment;
    struct PhotoImportProgress;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportFindItemsResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportFindItemsResult2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportImportItemsResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportItem>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportItem2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportItemImportedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportOperation>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportSession>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportSession2>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportSidecar>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportSource>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportSourceStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportStorageMedium>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::IPhotoImportVideoSegment>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportFindItemsResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportImportItemsResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportItem>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportItemImportedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportManager>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportOperation>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSelectionChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSession>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSidecar>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSource>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportStorageMedium>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportVideoSegment>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportAccessMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportConnectionTransport>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportContentType>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportContentTypeFilter>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportImportMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportItemSelectionMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportPowerSource>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSourceType>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportStage>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportStorageMediumType>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSubfolderCreationMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportSubfolderDateFormat>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Import::PhotoImportProgress>{ using type = struct_category<uint32_t, uint32_t, uint64_t, uint64_t, double>; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult> = L"Windows.Media.Import.PhotoImportDeleteImportedItemsFromSourceResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportFindItemsResult> = L"Windows.Media.Import.PhotoImportFindItemsResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportImportItemsResult> = L"Windows.Media.Import.PhotoImportImportItemsResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportItem> = L"Windows.Media.Import.PhotoImportItem";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportItemImportedEventArgs> = L"Windows.Media.Import.PhotoImportItemImportedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportManager> = L"Windows.Media.Import.PhotoImportManager";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportOperation> = L"Windows.Media.Import.PhotoImportOperation";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSelectionChangedEventArgs> = L"Windows.Media.Import.PhotoImportSelectionChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSession> = L"Windows.Media.Import.PhotoImportSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSidecar> = L"Windows.Media.Import.PhotoImportSidecar";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSource> = L"Windows.Media.Import.PhotoImportSource";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportStorageMedium> = L"Windows.Media.Import.PhotoImportStorageMedium";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportVideoSegment> = L"Windows.Media.Import.PhotoImportVideoSegment";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportAccessMode> = L"Windows.Media.Import.PhotoImportAccessMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportConnectionTransport> = L"Windows.Media.Import.PhotoImportConnectionTransport";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportContentType> = L"Windows.Media.Import.PhotoImportContentType";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportContentTypeFilter> = L"Windows.Media.Import.PhotoImportContentTypeFilter";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportImportMode> = L"Windows.Media.Import.PhotoImportImportMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportItemSelectionMode> = L"Windows.Media.Import.PhotoImportItemSelectionMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportPowerSource> = L"Windows.Media.Import.PhotoImportPowerSource";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSourceType> = L"Windows.Media.Import.PhotoImportSourceType";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportStage> = L"Windows.Media.Import.PhotoImportStage";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportStorageMediumType> = L"Windows.Media.Import.PhotoImportStorageMediumType";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSubfolderCreationMode> = L"Windows.Media.Import.PhotoImportSubfolderCreationMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportSubfolderDateFormat> = L"Windows.Media.Import.PhotoImportSubfolderDateFormat";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::PhotoImportProgress> = L"Windows.Media.Import.PhotoImportProgress";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult> = L"Windows.Media.Import.IPhotoImportDeleteImportedItemsFromSourceResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportFindItemsResult> = L"Windows.Media.Import.IPhotoImportFindItemsResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportFindItemsResult2> = L"Windows.Media.Import.IPhotoImportFindItemsResult2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportImportItemsResult> = L"Windows.Media.Import.IPhotoImportImportItemsResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportItem> = L"Windows.Media.Import.IPhotoImportItem";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportItem2> = L"Windows.Media.Import.IPhotoImportItem2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportItemImportedEventArgs> = L"Windows.Media.Import.IPhotoImportItemImportedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportManagerStatics> = L"Windows.Media.Import.IPhotoImportManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportOperation> = L"Windows.Media.Import.IPhotoImportOperation";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs> = L"Windows.Media.Import.IPhotoImportSelectionChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportSession> = L"Windows.Media.Import.IPhotoImportSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportSession2> = L"Windows.Media.Import.IPhotoImportSession2";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportSidecar> = L"Windows.Media.Import.IPhotoImportSidecar";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportSource> = L"Windows.Media.Import.IPhotoImportSource";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportSourceStatics> = L"Windows.Media.Import.IPhotoImportSourceStatics";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportStorageMedium> = L"Windows.Media.Import.IPhotoImportStorageMedium";
    template <> inline constexpr auto& name_v<llm:OS::Media::Import::IPhotoImportVideoSegment> = L"Windows.Media.Import.IPhotoImportVideoSegment";
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>{ 0xF4E112F8,0x843D,0x428A,{ 0xA1,0xA6,0x81,0x51,0x02,0x92,0xB0,0xAE } }; // F4E112F8-843D-428A-A1A6-81510292B0AE
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportFindItemsResult>{ 0x3915E647,0x6C78,0x492B,{ 0x84,0x4E,0x8F,0xE5,0xE8,0xF6,0xBF,0xB9 } }; // 3915E647-6C78-492B-844E-8FE5E8F6BFB9
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportFindItemsResult2>{ 0xFBDD6A3B,0xECF9,0x406A,{ 0x81,0x5E,0x50,0x15,0x62,0x5B,0x0A,0x88 } }; // FBDD6A3B-ECF9-406A-815E-5015625B0A88
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportImportItemsResult>{ 0xE4D4F478,0xD419,0x4443,{ 0xA8,0x4E,0xF0,0x6A,0x85,0x0C,0x0B,0x00 } }; // E4D4F478-D419-4443-A84E-F06A850C0B00
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportItem>{ 0xA9D07E76,0x9BFC,0x43B8,{ 0xB3,0x56,0x63,0x3B,0x6A,0x98,0x8C,0x9E } }; // A9D07E76-9BFC-43B8-B356-633B6A988C9E
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportItem2>{ 0xF1053505,0xF53B,0x46A3,{ 0x9E,0x30,0x36,0x10,0x79,0x1A,0x91,0x10 } }; // F1053505-F53B-46A3-9E30-3610791A9110
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportItemImportedEventArgs>{ 0x42CB2FDD,0x7D68,0x47B5,{ 0xBC,0x7C,0xCE,0xB7,0x3E,0x0C,0x77,0xDC } }; // 42CB2FDD-7D68-47B5-BC7C-CEB73E0C77DC
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportManagerStatics>{ 0x2771903D,0xA046,0x4F06,{ 0x9B,0x9C,0xBF,0xD6,0x62,0xE8,0x32,0x87 } }; // 2771903D-A046-4F06-9B9C-BFD662E83287
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportOperation>{ 0xD9F797E4,0xA09A,0x4EE4,{ 0xA4,0xB1,0x20,0x94,0x02,0x77,0xA5,0xBE } }; // D9F797E4-A09A-4EE4-A4B1-20940277A5BE
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs>{ 0x10461782,0xFA9D,0x4C30,{ 0x8B,0xC9,0x4D,0x64,0x91,0x15,0x72,0xD5 } }; // 10461782-FA9D-4C30-8BC9-4D64911572D5
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportSession>{ 0xAA63916E,0xECDB,0x4EFE,{ 0x94,0xC6,0x5F,0x5C,0xAF,0xE3,0x4C,0xFB } }; // AA63916E-ECDB-4EFE-94C6-5F5CAFE34CFB
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportSession2>{ 0x2A526710,0x3EC6,0x469D,{ 0xA3,0x75,0x2B,0x9F,0x47,0x85,0x39,0x1E } }; // 2A526710-3EC6-469D-A375-2B9F4785391E
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportSidecar>{ 0x46D7D757,0xF802,0x44C7,{ 0x9C,0x98,0x7A,0x71,0xF4,0xBC,0x14,0x86 } }; // 46D7D757-F802-44C7-9C98-7A71F4BC1486
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportSource>{ 0x1F8EA35E,0x145B,0x4CD6,{ 0x87,0xF1,0x54,0x96,0x5A,0x98,0x2F,0xEF } }; // 1F8EA35E-145B-4CD6-87F1-54965A982FEF
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportSourceStatics>{ 0x0528E586,0x32D8,0x467C,{ 0x8C,0xEE,0x23,0xA1,0xB2,0xF4,0x3E,0x85 } }; // 0528E586-32D8-467C-8CEE-23A1B2F43E85
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportStorageMedium>{ 0xF2B9B093,0xFC85,0x487F,{ 0x87,0xC2,0x58,0xD6,0x75,0xD0,0x5B,0x07 } }; // F2B9B093-FC85-487F-87C2-58D675D05B07
    template <> inline constexpr guid guid_v<llm:OS::Media::Import::IPhotoImportVideoSegment>{ 0x623C0289,0x321A,0x41D8,{ 0x91,0x66,0x8C,0x62,0xA3,0x33,0x27,0x6C } }; // 623C0289-321A-41D8-9166-8C62A333276C
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult>{ using type = llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportFindItemsResult>{ using type = llm:OS::Media::Import::IPhotoImportFindItemsResult; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportImportItemsResult>{ using type = llm:OS::Media::Import::IPhotoImportImportItemsResult; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportItem>{ using type = llm:OS::Media::Import::IPhotoImportItem; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportItemImportedEventArgs>{ using type = llm:OS::Media::Import::IPhotoImportItemImportedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportOperation>{ using type = llm:OS::Media::Import::IPhotoImportOperation; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportSelectionChangedEventArgs>{ using type = llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportSession>{ using type = llm:OS::Media::Import::IPhotoImportSession; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportSidecar>{ using type = llm:OS::Media::Import::IPhotoImportSidecar; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportSource>{ using type = llm:OS::Media::Import::IPhotoImportSource; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportStorageMedium>{ using type = llm:OS::Media::Import::IPhotoImportStorageMedium; };
    template <> struct default_interface<llm:OS::Media::Import::PhotoImportVideoSegment>{ using type = llm:OS::Media::Import::IPhotoImportVideoSegment; };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Session(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasSucceeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_DeletedItems(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhotosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PhotosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_VideosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_VideosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SidecarsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SidecarsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SiblingsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SiblingsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalSizeInBytes(uint64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportFindItemsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Session(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasSucceeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_FoundItems(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhotosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PhotosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_VideosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_VideosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SidecarsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SidecarsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SiblingsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SiblingsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall SelectAll() noexcept = 0;
            virtual int32_t __stdcall SelectNone() noexcept = 0;
            virtual int32_t __stdcall SelectNewAsync(void**) noexcept = 0;
            virtual int32_t __stdcall SetImportMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ImportMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedPhotosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedPhotosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedVideosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedVideosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedSidecarsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedSidecarsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedSiblingsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedSiblingsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedTotalCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SelectedTotalSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall add_SelectionChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SelectionChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall ImportItemsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_ItemImported(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ItemImported(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportFindItemsResult2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddItemsInDateRangeToSelection(int64_t, int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportImportItemsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Session(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasSucceeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ImportedItems(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhotosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PhotosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_VideosCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_VideosSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SidecarsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SidecarsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_SiblingsCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SiblingsSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalCount(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TotalSizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall DeleteImportedItemsFromSourceAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_ItemKey(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_ContentType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Date(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Sibling(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sidecars(void**) noexcept = 0;
            virtual int32_t __stdcall get_VideoSegments(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsSelected(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSelected(bool) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall get_ImportedFileNames(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeletedFileNames(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportItem2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Path(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportItemImportedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ImportedItem(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupportedAsync(void**) noexcept = 0;
            virtual int32_t __stdcall FindAllSourcesAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetPendingOperations(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Stage(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Session(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContinueFindingItemsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContinueImportingItemsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContinueDeletingImportedItemsFromSourceAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSelectionEmpty(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Source(void**) noexcept = 0;
            virtual int32_t __stdcall get_SessionId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall put_DestinationFolder(void*) noexcept = 0;
            virtual int32_t __stdcall get_DestinationFolder(void**) noexcept = 0;
            virtual int32_t __stdcall put_AppendSessionDateToDestinationFolder(bool) noexcept = 0;
            virtual int32_t __stdcall get_AppendSessionDateToDestinationFolder(bool*) noexcept = 0;
            virtual int32_t __stdcall put_SubfolderCreationMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SubfolderCreationMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DestinationFileNamePrefix(void*) noexcept = 0;
            virtual int32_t __stdcall get_DestinationFileNamePrefix(void**) noexcept = 0;
            virtual int32_t __stdcall FindItemsAsync(int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportSession2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_SubfolderDateFormat(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SubfolderDateFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RememberDeselectedItems(bool) noexcept = 0;
            virtual int32_t __stdcall get_RememberDeselectedItems(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportSidecar>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_SizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Date(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_Manufacturer(void**) noexcept = 0;
            virtual int32_t __stdcall get_Model(void**) noexcept = 0;
            virtual int32_t __stdcall get_SerialNumber(void**) noexcept = 0;
            virtual int32_t __stdcall get_ConnectionProtocol(void**) noexcept = 0;
            virtual int32_t __stdcall get_ConnectionTransport(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PowerSource(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_BatteryLevelPercent(void**) noexcept = 0;
            virtual int32_t __stdcall get_DateTime(void**) noexcept = 0;
            virtual int32_t __stdcall get_StorageMedia(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsLocked(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsMassStorage(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall CreateImportSession(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportSourceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FromFolderAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportStorageMedium>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_SerialNumber(void**) noexcept = 0;
            virtual int32_t __stdcall get_StorageMediumType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedAccessMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_CapacityInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_AvailableSpaceInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall Refresh() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Import::IPhotoImportVideoSegment>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_SizeInBytes(uint64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Date(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Sibling(void**) noexcept = 0;
            virtual int32_t __stdcall get_Sidecars(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSession) Session() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasSucceeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportItem>) DeletedItems() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PhotosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PhotosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) VideosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) VideosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SidecarsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SidecarsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SiblingsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SiblingsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TotalCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalSizeInBytes() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportDeleteImportedItemsFromSourceResult>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportDeleteImportedItemsFromSourceResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportFindItemsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSession) Session() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasSucceeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportItem>) FoundItems() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PhotosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PhotosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) VideosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) VideosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SidecarsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SidecarsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SiblingsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SiblingsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TotalCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalSizeInBytes() const;
        LLM_IMPL_AUTO(void) SelectAll() const;
        LLM_IMPL_AUTO(void) SelectNone() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SelectNewAsync() const;
        LLM_IMPL_AUTO(void) SetImportMode(llm:OS::Media::Import::PhotoImportImportMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportImportMode) ImportMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SelectedPhotosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SelectedPhotosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SelectedVideosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SelectedVideosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SelectedSidecarsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SelectedSidecarsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SelectedSiblingsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SelectedSiblingsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SelectedTotalCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SelectedTotalSizeInBytes() const;
        LLM_IMPL_AUTO(llm::event_token) SelectionChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Import::PhotoImportFindItemsResult, llm:OS::Media::Import::PhotoImportSelectionChangedEventArgs> const& value) const;
        using SelectionChanged_revoker = impl::event_revoker<llm:OS::Media::Import::IPhotoImportFindItemsResult, &impl::abi_t<llm:OS::Media::Import::IPhotoImportFindItemsResult>::remove_SelectionChanged>;
        [[nodiscard]] SelectionChanged_revoker SelectionChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Import::PhotoImportFindItemsResult, llm:OS::Media::Import::PhotoImportSelectionChangedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) SelectionChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Import::PhotoImportImportItemsResult, llm:OS::Media::Import::PhotoImportProgress>) ImportItemsAsync() const;
        LLM_IMPL_AUTO(llm::event_token) ItemImported(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Import::PhotoImportFindItemsResult, llm:OS::Media::Import::PhotoImportItemImportedEventArgs> const& value) const;
        using ItemImported_revoker = impl::event_revoker<llm:OS::Media::Import::IPhotoImportFindItemsResult, &impl::abi_t<llm:OS::Media::Import::IPhotoImportFindItemsResult>::remove_ItemImported>;
        [[nodiscard]] ItemImported_revoker ItemImported(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Import::PhotoImportFindItemsResult, llm:OS::Media::Import::PhotoImportItemImportedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) ItemImported(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportFindItemsResult>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportFindItemsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportFindItemsResult2
    {
        LLM_IMPL_AUTO(void) AddItemsInDateRangeToSelection(llm:OS::Foundation::DateTime const& rangeStart, llm:OS::Foundation::TimeSpan const& rangeLength) const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportFindItemsResult2>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportFindItemsResult2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportImportItemsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSession) Session() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasSucceeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportItem>) ImportedItems() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) PhotosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) PhotosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) VideosCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) VideosSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SidecarsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SidecarsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) SiblingsCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SiblingsSizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TotalCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) TotalSizeInBytes() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>) DeleteImportedItemsFromSourceAsync() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportImportItemsResult>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportImportItemsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) ItemKey() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportContentType) ContentType() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Date() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSidecar) Sibling() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportSidecar>) Sidecars() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportVideoSegment>) VideoSegments() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSelected() const;
        LLM_IMPL_AUTO(void) IsSelected(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamReference) Thumbnail() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) ImportedFileNames() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<hstring>) DeletedFileNames() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportItem>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportItem<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportItem2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Path() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportItem2>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportItem2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportItemImportedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportItem) ImportedItem() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportItemImportedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportItemImportedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) IsSupportedAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportSource>>) FindAllSourcesAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportOperation>) GetPendingOperations() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportManagerStatics>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportOperation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportStage) Stage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSession) Session() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Import::PhotoImportFindItemsResult, uint32_t>) ContinueFindingItemsAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Import::PhotoImportImportItemsResult, llm:OS::Media::Import::PhotoImportProgress>) ContinueImportingItemsAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Import::PhotoImportDeleteImportedItemsFromSourceResult, double>) ContinueDeletingImportedItemsFromSourceAsync() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportOperation>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportOperation<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportSelectionChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSelectionEmpty() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportSelectionChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportSelectionChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportSession
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSource) Source() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) SessionId() const;
        LLM_IMPL_AUTO(void) DestinationFolder(llm:OS::Storage::IStorageFolder const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::IStorageFolder) DestinationFolder() const;
        LLM_IMPL_AUTO(void) AppendSessionDateToDestinationFolder(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AppendSessionDateToDestinationFolder() const;
        LLM_IMPL_AUTO(void) SubfolderCreationMode(llm:OS::Media::Import::PhotoImportSubfolderCreationMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSubfolderCreationMode) SubfolderCreationMode() const;
        LLM_IMPL_AUTO(void) DestinationFileNamePrefix(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DestinationFileNamePrefix() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperationWithProgress<llm:OS::Media::Import::PhotoImportFindItemsResult, uint32_t>) FindItemsAsync(llm:OS::Media::Import::PhotoImportContentTypeFilter const& contentTypeFilter, llm:OS::Media::Import::PhotoImportItemSelectionMode const& itemSelectionMode) const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportSession>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportSession<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportSession2
    {
        LLM_IMPL_AUTO(void) SubfolderDateFormat(llm:OS::Media::Import::PhotoImportSubfolderDateFormat const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSubfolderDateFormat) SubfolderDateFormat() const;
        LLM_IMPL_AUTO(void) RememberDeselectedItems(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) RememberDeselectedItems() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportSession2>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportSession2<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportSidecar
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Date() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportSidecar>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportSidecar<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportSource
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Manufacturer() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Model() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SerialNumber() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ConnectionProtocol() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportConnectionTransport) ConnectionTransport() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSourceType) Type() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportPowerSource) PowerSource() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) BatteryLevelPercent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::DateTime>) DateTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportStorageMedium>) StorageMedia() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<bool>) IsLocked() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMassStorage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamReference) Thumbnail() const;
        LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSession) CreateImportSession() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportSource>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportSource<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportSourceStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Import::PhotoImportSource>) FromIdAsync(param::hstring const& sourceId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Import::PhotoImportSource>) FromFolderAsync(llm:OS::Storage::IStorageFolder const& sourceRootFolder) const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportSourceStatics>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportSourceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportStorageMedium
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SerialNumber() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportStorageMediumType) StorageMediumType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportAccessMode) SupportedAccessMode() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) CapacityInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) AvailableSpaceInBytes() const;
        LLM_IMPL_AUTO(void) Refresh() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportStorageMedium>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportStorageMedium<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Import_IPhotoImportVideoSegment
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint64_t) SizeInBytes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Date() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Import::PhotoImportSidecar) Sibling() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Import::PhotoImportSidecar>) Sidecars() const;
    };
    template <> struct consume<llm:OS::Media::Import::IPhotoImportVideoSegment>
    {
        template <typename D> using type = consume_Windows_Media_Import_IPhotoImportVideoSegment<D>;
    };
    struct struct_Windows_Media_Import_PhotoImportProgress
    {
        uint32_t ItemsImported;
        uint32_t TotalItemsToImport;
        uint64_t BytesImported;
        uint64_t TotalBytesToImport;
        double ImportProgress;
    };
    template <> struct abi<Windows::Media::Import::PhotoImportProgress>
    {
        using type = struct_Windows_Media_Import_PhotoImportProgress;
    };
}
#endif
