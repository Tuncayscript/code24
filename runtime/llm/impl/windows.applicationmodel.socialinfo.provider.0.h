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
#ifndef LLM_OS_ApplicationModel_SocialInfo_Provider_0_H
#define LLM_OS_ApplicationModel_SocialInfo_Provider_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo
{
    struct SocialFeedContent;
    struct SocialFeedItem;
    enum class SocialFeedKind : int32_t;
    enum class SocialFeedUpdateMode : int32_t;
    struct SocialItemThumbnail;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::SocialInfo::Provider
{
    struct ISocialDashboardItemUpdater;
    struct ISocialFeedUpdater;
    struct ISocialInfoProviderManagerStatics;
    struct SocialDashboardItemUpdater;
    struct SocialFeedUpdater;
    struct SocialInfoProviderManager;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::SocialInfo::Provider::SocialInfoProviderManager>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater> = L"Windows.ApplicationModel.SocialInfo.Provider.SocialDashboardItemUpdater";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater> = L"Windows.ApplicationModel.SocialInfo.Provider.SocialFeedUpdater";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::Provider::SocialInfoProviderManager> = L"Windows.ApplicationModel.SocialInfo.Provider.SocialInfoProviderManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater> = L"Windows.ApplicationModel.SocialInfo.Provider.ISocialDashboardItemUpdater";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater> = L"Windows.ApplicationModel.SocialInfo.Provider.ISocialFeedUpdater";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics> = L"Windows.ApplicationModel.SocialInfo.Provider.ISocialInfoProviderManagerStatics";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>{ 0x3CDE9DC9,0x4800,0x46CD,{ 0x86,0x9B,0x19,0x73,0xEC,0x68,0x5B,0xDE } }; // 3CDE9DC9-4800-46CD-869B-1973EC685BDE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>{ 0x7A0C0AA7,0xED89,0x4BD5,{ 0xA8,0xD9,0x15,0xF4,0xD9,0x86,0x1C,0x10 } }; // 7A0C0AA7-ED89-4BD5-A8D9-15F4D9861C10
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>{ 0x1B88E52B,0x7787,0x48D6,{ 0xAA,0x12,0xD8,0xE8,0xF4,0x7A,0xB8,0x5A } }; // 1B88E52B-7787-48D6-AA12-D8E8F47AB85A
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>{ using type = llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater; };
    template <> struct default_interface<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>{ using type = llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater; };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OwnerRemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Content(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_Timestamp(int64_t) noexcept = 0;
            virtual int32_t __stdcall put_Thumbnail(void*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall CommitAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_TargetUri(void**) noexcept = 0;
            virtual int32_t __stdcall put_TargetUri(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OwnerRemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Items(void**) noexcept = 0;
            virtual int32_t __stdcall CommitAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateSocialFeedUpdaterAsync(int32_t, int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateDashboardItemUpdaterAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UpdateBadgeCountValue(void*, int32_t) noexcept = 0;
            virtual int32_t __stdcall ReportNewContentAvailable(void*, int32_t) noexcept = 0;
            virtual int32_t __stdcall ProvisionAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DeprovisionAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OwnerRemoteId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedContent) Content() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Timestamp() const;
        LLM_IMPL_AUTO(void) Timestamp(llm::OS::Foundation::DateTime const& value) const;
        LLM_IMPL_AUTO(void) Thumbnail(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialItemThumbnail) Thumbnail() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) CommitAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) TargetUri() const;
        LLM_IMPL_AUTO(void) TargetUri(llm::OS::Foundation::Uri const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialDashboardItemUpdater>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialDashboardItemUpdater<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialFeedUpdater
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OwnerRemoteId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::SocialInfo::SocialFeedKind) Kind() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::SocialInfo::SocialFeedItem>) Items() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) CommitAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialFeedUpdater>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialFeedUpdater<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialFeedUpdater>) CreateSocialFeedUpdaterAsync(llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind, llm::OS::ApplicationModel::SocialInfo::SocialFeedUpdateMode const& mode, param::hstring const& ownerRemoteId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::SocialInfo::Provider::SocialDashboardItemUpdater>) CreateDashboardItemUpdaterAsync(param::hstring const& ownerRemoteId) const;
        LLM_IMPL_AUTO(void) UpdateBadgeCountValue(param::hstring const& itemRemoteId, int32_t newCount) const;
        LLM_IMPL_AUTO(void) ReportNewContentAvailable(param::hstring const& contactRemoteId, llm::OS::ApplicationModel::SocialInfo::SocialFeedKind const& kind) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) ProvisionAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeprovisionAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::SocialInfo::Provider::ISocialInfoProviderManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_SocialInfo_Provider_ISocialInfoProviderManagerStatics<D>;
    };
}
#endif
