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
#ifndef LLM_OS_ApplicationModel_SocialInfo_0_H
#define LLM_OS_ApplicationModel_SocialInfo_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct IAsyncAction;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Graphics::Imaging
{
    struct BitmapSize;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IInputStream;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo
{
    enum class SocialFeedItemStyle : int32_t
    {
        Default = 0,
        Photo = 1,
    };
    enum class SocialFeedKind : int32_t
    {
        HomeFeed = 0,
        ContactFeed = 1,
        Dashboard = 2,
    };
    enum class SocialFeedUpdateMode : int32_t
    {
        Append = 0,
        Replace = 1,
    };
    enum class SocialItemBadgeStyle : int32_t
    {
        Hidden = 0,
        Visible = 1,
        VisibleWithCount = 2,
    };
    struct ISocialFeedChildItem;
    struct ISocialFeedContent;
    struct ISocialFeedItem;
    struct ISocialFeedSharedItem;
    struct ISocialItemThumbnail;
    struct ISocialUserInfo;
    struct SocialFeedChildItem;
    struct SocialFeedContent;
    struct SocialFeedItem;
    struct SocialFeedSharedItem;
    struct SocialItemThumbnail;
    struct SocialUserInfo;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialUserInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem> = L"Windows.ApplicationModel.SocialInfo.SocialFeedChildItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent> = L"Windows.ApplicationModel.SocialInfo.SocialFeedContent";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem> = L"Windows.ApplicationModel.SocialInfo.SocialFeedItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem> = L"Windows.ApplicationModel.SocialInfo.SocialFeedSharedItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail> = L"Windows.ApplicationModel.SocialInfo.SocialItemThumbnail";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialUserInfo> = L"Windows.ApplicationModel.SocialInfo.SocialUserInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle> = L"Windows.ApplicationModel.SocialInfo.SocialFeedItemStyle";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedKind> = L"Windows.ApplicationModel.SocialInfo.SocialFeedKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode> = L"Windows.ApplicationModel.SocialInfo.SocialFeedUpdateMode";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle> = L"Windows.ApplicationModel.SocialInfo.SocialItemBadgeStyle";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem> = L"Windows.ApplicationModel.SocialInfo.ISocialFeedChildItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent> = L"Windows.ApplicationModel.SocialInfo.ISocialFeedContent";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem> = L"Windows.ApplicationModel.SocialInfo.ISocialFeedItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem> = L"Windows.ApplicationModel.SocialInfo.ISocialFeedSharedItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail> = L"Windows.ApplicationModel.SocialInfo.ISocialItemThumbnail";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo> = L"Windows.ApplicationModel.SocialInfo.ISocialUserInfo";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem>{ 0x0B6A985A,0xD59D,0x40BE,{ 0x98,0x0C,0x48,0x8A,0x2A,0xB3,0x0A,0x83 } }; // 0B6A985A-D59D-40BE-980C-488A2AB30A83
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent>{ 0xA234E429,0x3E39,0x494D,{ 0xA3,0x7C,0xF4,0x62,0xA2,0x49,0x45,0x14 } }; // A234E429-3E39-494D-A37C-F462A2494514
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem>{ 0x4F1392AB,0x1F72,0x4D33,{ 0xB6,0x95,0xDE,0x3E,0x1D,0xB6,0x03,0x17 } }; // 4F1392AB-1F72-4D33-B695-DE3E1DB60317
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem>{ 0x7BFB9E40,0xA6AA,0x45A7,{ 0x9F,0xF6,0x54,0xC4,0x21,0x05,0xDD,0x1F } }; // 7BFB9E40-A6AA-45A7-9FF6-54C42105DD1F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail>{ 0x5CBF831A,0x3F08,0x497F,{ 0x91,0x7F,0x57,0xE0,0x9D,0x84,0xB1,0x41 } }; // 5CBF831A-3F08-497F-917F-57E09D84B141
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo>{ 0x9E5E1BD1,0x90D0,0x4E1D,{ 0x95,0x54,0x84,0x4D,0x46,0x60,0x7F,0x61 } }; // 9E5E1BD1-90D0-4E1D-9554-844D46607F61
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem>{ using type = llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem; };
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::SocialFeedContent>{ using type = llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent; };
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem>{ using type = llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem; };
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem>{ using type = llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem; };
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>{ using type = llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail; };
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::SocialUserInfo>{ using type = llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo; };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Author(void**) noexcept = 0;
            virtual int32_t __stdcall get_PrimaryContent(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecondaryContent(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Timestamp(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnails(void**) noexcept = 0;
            virtual int32_t __stdcall get_SharedItem(void**) noexcept = 0;
            virtual int32_t __stdcall put_SharedItem(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Message(void**) noexcept = 0;
            virtual int32_t __stdcall put_Message(void*) noexcept = 0;
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Author(void**) noexcept = 0;
            virtual int32_t __stdcall get_PrimaryContent(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecondaryContent(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Timestamp(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnails(void**) noexcept = 0;
            virtual int32_t __stdcall get_SharedItem(void**) noexcept = 0;
            virtual int32_t __stdcall put_SharedItem(void*) noexcept = 0;
            virtual int32_t __stdcall get_BadgeStyle(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_BadgeStyle(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_BadgeCountValue(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_BadgeCountValue(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_RemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall put_RemoteId(void*) noexcept = 0;
            virtual int32_t __stdcall get_ChildItem(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChildItem(void*) noexcept = 0;
            virtual int32_t __stdcall get_Style(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Style(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OriginalSource(void**) noexcept = 0;
            virtual int32_t __stdcall put_OriginalSource(void*) noexcept = 0;
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Timestamp(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
            virtual int32_t __stdcall put_Thumbnail(void*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_ImageUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_ImageUri(void*) noexcept = 0;
            virtual int32_t __stdcall get_BitmapSize(struct struct_Windows_Graphics_Imaging_BitmapSize*) noexcept = 0;
            virtual int32_t __stdcall put_BitmapSize(struct struct_Windows_Graphics_Imaging_BitmapSize) noexcept = 0;
            virtual int32_t __stdcall SetImageAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_UserName(void**) noexcept = 0;
            virtual int32_t __stdcall put_UserName(void*) noexcept = 0;
            virtual int32_t __stdcall get_RemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall put_RemoteId(void*) noexcept = 0;
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialUserInfo) Author() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) PrimaryContent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) SecondaryContent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Timestamp() const;
        LLM_IMPL_AUTO(void) Timestamp(llm::OS::Foundation::DateTime const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>) Thumbnails() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem) SharedItem() const;
        LLM_IMPL_AUTO(void) SharedItem(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::ISocialFeedChildItem>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_ISocialFeedChildItem<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Message() const;
        LLM_IMPL_AUTO(void) Message(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::ISocialFeedContent>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_ISocialFeedContent<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialUserInfo) Author() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) PrimaryContent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) SecondaryContent() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Timestamp() const;
        LLM_IMPL_AUTO(void) Timestamp(llm::OS::Foundation::DateTime const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail>) Thumbnails() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem) SharedItem() const;
        LLM_IMPL_AUTO(void) SharedItem(llm::OS::ApplicationModel::SocialInfo::SocialFeedSharedItem const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle) BadgeStyle() const;
        LLM_IMPL_AUTO(void) BadgeStyle(llm::OS::ApplicationModel::SocialInfo::SocialItemBadgeStyle const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) BadgeCountValue() const;
        LLM_IMPL_AUTO(void) BadgeCountValue(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemoteId() const;
        LLM_IMPL_AUTO(void) RemoteId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem) ChildItem() const;
        LLM_IMPL_AUTO(void) ChildItem(llm::OS::ApplicationModel::SocialInfo::SocialFeedChildItem const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle) Style() const;
        LLM_IMPL_AUTO(void) Style(llm::OS::ApplicationModel::SocialInfo::SocialFeedItemStyle const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::ISocialFeedItem>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_ISocialFeedItem<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) OriginalSource() const;
        LLM_IMPL_AUTO(void) OriginalSource(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) Content() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Timestamp() const;
        LLM_IMPL_AUTO(void) Timestamp(llm::OS::Foundation::DateTime const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
        LLM_IMPL_AUTO(void) Thumbnail(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail) Thumbnail() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::ISocialFeedSharedItem>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_ISocialFeedSharedItem<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) ImageUri() const;
        LLM_IMPL_AUTO(void) ImageUri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) BitmapSize() const;
        LLM_IMPL_AUTO(void) BitmapSize(llm::OS::Graphics::Imaging::BitmapSize const& value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetImageAsync(llm::OS::Storage::Streams::IInputStream const& image) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::ISocialItemThumbnail>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_ISocialItemThumbnail<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserName() const;
        LLM_IMPL_AUTO(void) UserName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemoteId() const;
        LLM_IMPL_AUTO(void) RemoteId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::ISocialUserInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_ISocialUserInfo<D>;
    };
}
#endif
