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
#ifndef LLM_OS_Media_ContentRestrictions_0_H
#define LLM_OS_Media_ContentRestrictions_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm:OS::Media::ContentRestrictions
{
    enum class ContentAccessRestrictionLevel : int32_t
    {
        Allow = 0,
        Warn = 1,
        Block = 2,
        Hide = 3,
    };
    enum class RatedContentCategory : int32_t
    {
        General = 0,
        Application = 1,
        Game = 2,
        Movie = 3,
        Television = 4,
        Music = 5,
    };
    struct IContentRestrictionsBrowsePolicy;
    struct IRatedContentDescription;
    struct IRatedContentDescriptionFactory;
    struct IRatedContentRestrictions;
    struct IRatedContentRestrictionsFactory;
    struct ContentRestrictionsBrowsePolicy;
    struct RatedContentDescription;
    struct RatedContentRestrictions;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::IRatedContentDescription>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::IRatedContentDescriptionFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>{ using type = class_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::RatedContentDescription>{ using type = class_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::RatedContentRestrictions>{ using type = class_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::ContentAccessRestrictionLevel>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::ContentRestrictions::RatedContentCategory>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy> = L"Windows.Media.ContentRestrictions.ContentRestrictionsBrowsePolicy";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::RatedContentDescription> = L"Windows.Media.ContentRestrictions.RatedContentDescription";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::RatedContentRestrictions> = L"Windows.Media.ContentRestrictions.RatedContentRestrictions";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::ContentAccessRestrictionLevel> = L"Windows.Media.ContentRestrictions.ContentAccessRestrictionLevel";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::RatedContentCategory> = L"Windows.Media.ContentRestrictions.RatedContentCategory";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy> = L"Windows.Media.ContentRestrictions.IContentRestrictionsBrowsePolicy";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::IRatedContentDescription> = L"Windows.Media.ContentRestrictions.IRatedContentDescription";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::IRatedContentDescriptionFactory> = L"Windows.Media.ContentRestrictions.IRatedContentDescriptionFactory";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions> = L"Windows.Media.ContentRestrictions.IRatedContentRestrictions";
    template <> inline constexpr auto& name_v<llm:OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory> = L"Windows.Media.ContentRestrictions.IRatedContentRestrictionsFactory";
    template <> inline constexpr guid guid_v<llm:OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>{ 0x8C0133A4,0x442E,0x461A,{ 0x87,0x57,0xFA,0xD2,0xF5,0xBD,0x37,0xE4 } }; // 8C0133A4-442E-461A-8757-FAD2F5BD37E4
    template <> inline constexpr guid guid_v<llm:OS::Media::ContentRestrictions::IRatedContentDescription>{ 0x694866DF,0x66B2,0x4DC3,{ 0x96,0xB1,0xF0,0x90,0xEE,0xDE,0xE2,0x55 } }; // 694866DF-66B2-4DC3-96B1-F090EEDEE255
    template <> inline constexpr guid guid_v<llm:OS::Media::ContentRestrictions::IRatedContentDescriptionFactory>{ 0x2E38DF62,0x9B90,0x4FA6,{ 0x89,0xC1,0x4B,0x8D,0x2F,0xFB,0x35,0x73 } }; // 2E38DF62-9B90-4FA6-89C1-4B8D2FFB3573
    template <> inline constexpr guid guid_v<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions>{ 0x3F7F23CB,0xBA07,0x4401,{ 0xA4,0x9D,0x8B,0x92,0x22,0x20,0x57,0x23 } }; // 3F7F23CB-BA07-4401-A49D-8B9222205723
    template <> inline constexpr guid guid_v<llm:OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory>{ 0xFB4B2996,0xC3BD,0x4910,{ 0x96,0x19,0x97,0xCF,0xD0,0x69,0x4D,0x56 } }; // FB4B2996-C3BD-4910-9619-97CFD0694D56
    template <> struct default_interface<llm:OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>{ using type = llm:OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy; };
    template <> struct default_interface<llm:OS::Media::ContentRestrictions::RatedContentDescription>{ using type = llm:OS::Media::ContentRestrictions::IRatedContentDescription; };
    template <> struct default_interface<llm:OS::Media::ContentRestrictions::RatedContentRestrictions>{ using type = llm:OS::Media::ContentRestrictions::IRatedContentRestrictions; };
    template <> struct abi<llm:OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_GeographicRegion(void**) noexcept = 0;
            virtual int32_t __stdcall get_MaxBrowsableAgeRating(void**) noexcept = 0;
            virtual int32_t __stdcall get_PreferredAgeRating(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::ContentRestrictions::IRatedContentDescription>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall put_Id(void*) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Image(void**) noexcept = 0;
            virtual int32_t __stdcall put_Image(void*) noexcept = 0;
            virtual int32_t __stdcall get_Category(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Category(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Ratings(void**) noexcept = 0;
            virtual int32_t __stdcall put_Ratings(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::ContentRestrictions::IRatedContentDescriptionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetBrowsePolicyAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetRestrictionLevelAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestContentAccessAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall add_RestrictionsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RestrictionsChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithMaxAgeRating(uint32_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_ContentRestrictions_IContentRestrictionsBrowsePolicy
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) GeographicRegion() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) MaxBrowsableAgeRating() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<uint32_t>) PreferredAgeRating() const;
    };
    template <> struct consume<llm:OS::Media::ContentRestrictions::IContentRestrictionsBrowsePolicy>
    {
        template <typename D> using type = consume_Windows_Media_ContentRestrictions_IContentRestrictionsBrowsePolicy<D>;
    };
    template <typename D>
    struct consume_Windows_Media_ContentRestrictions_IRatedContentDescription
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        LLM_IMPL_AUTO(void) Id(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamReference) Image() const;
        LLM_IMPL_AUTO(void) Image(llm:OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::ContentRestrictions::RatedContentCategory) Category() const;
        LLM_IMPL_AUTO(void) Category(llm:OS::Media::ContentRestrictions::RatedContentCategory const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVector<hstring>) Ratings() const;
        LLM_IMPL_AUTO(void) Ratings(param::vector<hstring> const& value) const;
    };
    template <> struct consume<llm:OS::Media::ContentRestrictions::IRatedContentDescription>
    {
        template <typename D> using type = consume_Windows_Media_ContentRestrictions_IRatedContentDescription<D>;
    };
    template <typename D>
    struct consume_Windows_Media_ContentRestrictions_IRatedContentDescriptionFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::ContentRestrictions::RatedContentDescription) Create(param::hstring const& id, param::hstring const& title, llm:OS::Media::ContentRestrictions::RatedContentCategory const& category) const;
    };
    template <> struct consume<llm:OS::Media::ContentRestrictions::IRatedContentDescriptionFactory>
    {
        template <typename D> using type = consume_Windows_Media_ContentRestrictions_IRatedContentDescriptionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::ContentRestrictions::ContentRestrictionsBrowsePolicy>) GetBrowsePolicyAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::ContentRestrictions::ContentAccessRestrictionLevel>) GetRestrictionLevelAsync(llm:OS::Media::ContentRestrictions::RatedContentDescription const& RatedContentDescription) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) RequestContentAccessAsync(llm:OS::Media::ContentRestrictions::RatedContentDescription const& RatedContentDescription) const;
        LLM_IMPL_AUTO(llm::event_token) RestrictionsChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        using RestrictionsChanged_revoker = impl::event_revoker<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions, &impl::abi_t<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions>::remove_RestrictionsChanged>;
        [[nodiscard]] RestrictionsChanged_revoker RestrictionsChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) RestrictionsChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::ContentRestrictions::IRatedContentRestrictions>
    {
        template <typename D> using type = consume_Windows_Media_ContentRestrictions_IRatedContentRestrictions<D>;
    };
    template <typename D>
    struct consume_Windows_Media_ContentRestrictions_IRatedContentRestrictionsFactory
    {
        LLM_IMPL_AUTO(llm:OS::Media::ContentRestrictions::RatedContentRestrictions) CreateWithMaxAgeRating(uint32_t maxAgeRating) const;
    };
    template <> struct consume<llm:OS::Media::ContentRestrictions::IRatedContentRestrictionsFactory>
    {
        template <typename D> using type = consume_Windows_Media_ContentRestrictions_IRatedContentRestrictionsFactory<D>;
    };
}
#endif
