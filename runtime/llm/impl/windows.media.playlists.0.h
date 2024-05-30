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
#ifndef LLM_OS_Media_Playlists_0_H
#define LLM_OS_Media_Playlists_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Storage
{
    struct IStorageFile;
    struct IStorageFolder;
    enum class NameCollisionOption : int32_t;
    struct StorageFile;
}
LLM_EXPORT namespace llm:OS::Media::Playlists
{
    enum class PlaylistFormat : int32_t
    {
        WindowsMedia = 0,
        Zune = 1,
        M3u = 2,
    };
    struct IPlaylist;
    struct IPlaylistStatics;
    struct Playlist;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Playlists::IPlaylist>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Playlists::IPlaylistStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Playlists::Playlist>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Playlists::PlaylistFormat>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Playlists::Playlist> = L"Windows.Media.Playlists.Playlist";
    template <> inline constexpr auto& name_v<llm:OS::Media::Playlists::PlaylistFormat> = L"Windows.Media.Playlists.PlaylistFormat";
    template <> inline constexpr auto& name_v<llm:OS::Media::Playlists::IPlaylist> = L"Windows.Media.Playlists.IPlaylist";
    template <> inline constexpr auto& name_v<llm:OS::Media::Playlists::IPlaylistStatics> = L"Windows.Media.Playlists.IPlaylistStatics";
    template <> inline constexpr guid guid_v<llm:OS::Media::Playlists::IPlaylist>{ 0x803736F5,0xCF44,0x4D97,{ 0x83,0xB3,0x7A,0x08,0x9E,0x9A,0xB6,0x63 } }; // 803736F5-CF44-4D97-83B3-7A089E9AB663
    template <> inline constexpr guid guid_v<llm:OS::Media::Playlists::IPlaylistStatics>{ 0xC5C331CD,0x81F9,0x4FF3,{ 0x95,0xB9,0x70,0xB6,0xFF,0x04,0x6B,0x68 } }; // C5C331CD-81F9-4FF3-95B9-70B6FF046B68
    template <> struct default_interface<llm:OS::Media::Playlists::Playlist>{ using type = llm:OS::Media::Playlists::IPlaylist; };
    template <> struct abi<llm:OS::Media::Playlists::IPlaylist>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Files(void**) noexcept = 0;
            virtual int32_t __stdcall SaveAsync(void**) noexcept = 0;
            virtual int32_t __stdcall SaveAsAsync(void*, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SaveAsWithFormatAsync(void*, void*, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Playlists::IPlaylistStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall LoadAsync(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Playlists_IPlaylist
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<llm:OS::Storage::StorageFile>) Files() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SaveAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::StorageFile>) SaveAsAsync(llm:OS::Storage::IStorageFolder const& saveLocation, param::hstring const& desiredName, llm:OS::Storage::NameCollisionOption const& option) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Storage::StorageFile>) SaveAsAsync(llm:OS::Storage::IStorageFolder const& saveLocation, param::hstring const& desiredName, llm:OS::Storage::NameCollisionOption const& option, llm:OS::Media::Playlists::PlaylistFormat const& playlistFormat) const;
    };
    template <> struct consume<llm:OS::Media::Playlists::IPlaylist>
    {
        template <typename D> using type = consume_Windows_Media_Playlists_IPlaylist<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Playlists_IPlaylistStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Playlists::Playlist>) LoadAsync(llm:OS::Storage::IStorageFile const& file) const;
    };
    template <> struct consume<llm:OS::Media::Playlists::IPlaylistStatics>
    {
        template <typename D> using type = consume_Windows_Media_Playlists_IPlaylistStatics<D>;
    };
}
#endif
