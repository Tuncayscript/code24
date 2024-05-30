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
#ifndef LLM_OS_Services_Cortana_0_H
#define LLM_OS_Services_Cortana_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel::DataTransfer
{
    struct DataPackage;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Services::Cortana
{
    enum class CortanaPermission : int32_t
    {
        BrowsingHistory = 0,
        Calendar = 1,
        CallHistory = 2,
        Contacts = 3,
        Email = 4,
        InputPersonalization = 5,
        Location = 6,
        Messaging = 7,
        Microphone = 8,
        Personalization = 9,
        PhoneCall = 10,
    };
    enum class CortanaPermissionsChangeResult : int32_t
    {
        Success = 0,
        Unavailable = 1,
        DisabledByPolicy = 2,
    };
    struct ICortanaActionableInsights;
    struct ICortanaActionableInsightsOptions;
    struct ICortanaActionableInsightsStatics;
    struct ICortanaPermissionsManager;
    struct ICortanaPermissionsManagerStatics;
    struct ICortanaSettings;
    struct ICortanaSettingsStatics;
    struct CortanaActionableInsights;
    struct CortanaActionableInsightsOptions;
    struct CortanaPermissionsManager;
    struct CortanaSettings;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Services::Cortana::ICortanaActionableInsights>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::ICortanaActionableInsightsOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::ICortanaActionableInsightsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::ICortanaPermissionsManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::ICortanaPermissionsManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::ICortanaSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::ICortanaSettingsStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Services::Cortana::CortanaActionableInsights>{ using type = class_category; };
    template <> struct category<llm:OS::Services::Cortana::CortanaActionableInsightsOptions>{ using type = class_category; };
    template <> struct category<llm:OS::Services::Cortana::CortanaPermissionsManager>{ using type = class_category; };
    template <> struct category<llm:OS::Services::Cortana::CortanaSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Services::Cortana::CortanaPermission>{ using type = enum_category; };
    template <> struct category<llm:OS::Services::Cortana::CortanaPermissionsChangeResult>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::CortanaActionableInsights> = L"Windows.Services.Cortana.CortanaActionableInsights";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::CortanaActionableInsightsOptions> = L"Windows.Services.Cortana.CortanaActionableInsightsOptions";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::CortanaPermissionsManager> = L"Windows.Services.Cortana.CortanaPermissionsManager";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::CortanaSettings> = L"Windows.Services.Cortana.CortanaSettings";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::CortanaPermission> = L"Windows.Services.Cortana.CortanaPermission";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::CortanaPermissionsChangeResult> = L"Windows.Services.Cortana.CortanaPermissionsChangeResult";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaActionableInsights> = L"Windows.Services.Cortana.ICortanaActionableInsights";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaActionableInsightsOptions> = L"Windows.Services.Cortana.ICortanaActionableInsightsOptions";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaActionableInsightsStatics> = L"Windows.Services.Cortana.ICortanaActionableInsightsStatics";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaPermissionsManager> = L"Windows.Services.Cortana.ICortanaPermissionsManager";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaPermissionsManagerStatics> = L"Windows.Services.Cortana.ICortanaPermissionsManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaSettings> = L"Windows.Services.Cortana.ICortanaSettings";
    template <> inline constexpr auto& name_v<llm:OS::Services::Cortana::ICortanaSettingsStatics> = L"Windows.Services.Cortana.ICortanaSettingsStatics";
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaActionableInsights>{ 0x951EC6B1,0xFC83,0x586D,{ 0x8B,0x84,0x24,0x52,0xC8,0x98,0x16,0x25 } }; // 951EC6B1-FC83-586D-8B84-2452C8981625
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaActionableInsightsOptions>{ 0xAAC2BBCF,0x9782,0x5420,{ 0xB8,0x1E,0x7A,0xE5,0x6A,0xF3,0x18,0x15 } }; // AAC2BBCF-9782-5420-B81E-7AE56AF31815
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaActionableInsightsStatics>{ 0xB5DED412,0x9D2F,0x5CB5,{ 0x9B,0x05,0x35,0x6A,0x0B,0x83,0x6C,0x10 } }; // B5DED412-9D2F-5CB5-9B05-356A0B836C10
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaPermissionsManager>{ 0x191330E0,0x8695,0x438A,{ 0x95,0x45,0x3D,0xA4,0xE8,0x22,0xDD,0xB4 } }; // 191330E0-8695-438A-9545-3DA4E822DDB4
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaPermissionsManagerStatics>{ 0x76B1E67A,0xB045,0x4414,{ 0x9D,0x6D,0x2A,0xD3,0xA5,0xFE,0x3A,0x7E } }; // 76B1E67A-B045-4414-9D6D-2AD3A5FE3A7E
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaSettings>{ 0x54D571A7,0x8062,0x40F4,{ 0xAB,0xE7,0xDE,0xDF,0xD6,0x97,0xB0,0x19 } }; // 54D571A7-8062-40F4-ABE7-DEDFD697B019
    template <> inline constexpr guid guid_v<llm:OS::Services::Cortana::ICortanaSettingsStatics>{ 0x8B2CCD7E,0x2EC0,0x446D,{ 0x92,0x85,0x33,0xF0,0x7C,0xE8,0xAC,0x04 } }; // 8B2CCD7E-2EC0-446D-9285-33F07CE8AC04
    template <> struct default_interface<llm:OS::Services::Cortana::CortanaActionableInsights>{ using type = llm:OS::Services::Cortana::ICortanaActionableInsights; };
    template <> struct default_interface<llm:OS::Services::Cortana::CortanaActionableInsightsOptions>{ using type = llm:OS::Services::Cortana::ICortanaActionableInsightsOptions; };
    template <> struct default_interface<llm:OS::Services::Cortana::CortanaPermissionsManager>{ using type = llm:OS::Services::Cortana::ICortanaPermissionsManager; };
    template <> struct default_interface<llm:OS::Services::Cortana::CortanaSettings>{ using type = llm:OS::Services::Cortana::ICortanaSettings; };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaActionableInsights>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall IsAvailableAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ShowInsightsForImageAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowInsightsForImageWithOptionsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowInsightsForTextAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowInsightsForTextWithOptionsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowInsightsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowInsightsWithOptionsAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaActionableInsightsOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContentSourceWebLink(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContentSourceWebLink(void*) noexcept = 0;
            virtual int32_t __stdcall get_SurroundingText(void**) noexcept = 0;
            virtual int32_t __stdcall put_SurroundingText(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaActionableInsightsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaPermissionsManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall ArePermissionsGrantedAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GrantPermissionsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RevokePermissionsAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaPermissionsManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HasUserConsentToVoiceActivation(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsVoiceActivationEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsVoiceActivationEnabled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Services::Cortana::ICortanaSettingsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaActionableInsights
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) IsAvailableAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowInsightsForImageAsync(llm:OS::Storage::Streams::IRandomAccessStreamReference const& imageStream) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowInsightsForImageAsync(llm:OS::Storage::Streams::IRandomAccessStreamReference const& imageStream, llm:OS::Services::Cortana::CortanaActionableInsightsOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowInsightsForTextAsync(param::hstring const& text) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowInsightsForTextAsync(param::hstring const& text, llm:OS::Services::Cortana::CortanaActionableInsightsOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowInsightsAsync(llm:OS::ApplicationModel::DataTransfer::DataPackage const& datapackage) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowInsightsAsync(llm:OS::ApplicationModel::DataTransfer::DataPackage const& datapackage, llm:OS::Services::Cortana::CortanaActionableInsightsOptions const& options) const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaActionableInsights>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaActionableInsights<D>;
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaActionableInsightsOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) ContentSourceWebLink() const;
        LLM_IMPL_AUTO(void) ContentSourceWebLink(llm:OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SurroundingText() const;
        LLM_IMPL_AUTO(void) SurroundingText(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaActionableInsightsOptions>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaActionableInsightsOptions<D>;
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaActionableInsightsStatics
    {
        LLM_IMPL_AUTO(llm:OS::Services::Cortana::CortanaActionableInsights) GetDefault() const;
        LLM_IMPL_AUTO(llm:OS::Services::Cortana::CortanaActionableInsights) GetForUser(llm:OS::System::User const& user) const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaActionableInsightsStatics>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaActionableInsightsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaPermissionsManager
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) ArePermissionsGrantedAsync(param::async_iterable<llm:OS::Services::Cortana::CortanaPermission> const& permissions) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Services::Cortana::CortanaPermissionsChangeResult>) GrantPermissionsAsync(param::async_iterable<llm:OS::Services::Cortana::CortanaPermission> const& permissions) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Services::Cortana::CortanaPermissionsChangeResult>) RevokePermissionsAsync(param::async_iterable<llm:OS::Services::Cortana::CortanaPermission> const& permissions) const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaPermissionsManager>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaPermissionsManager<D>;
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaPermissionsManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Services::Cortana::CortanaPermissionsManager) GetDefault() const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaPermissionsManagerStatics>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaPermissionsManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasUserConsentToVoiceActivation() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVoiceActivationEnabled() const;
        LLM_IMPL_AUTO(void) IsVoiceActivationEnabled(bool value) const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaSettings>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Services_Cortana_ICortanaSettingsStatics
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
        LLM_IMPL_AUTO(llm:OS::Services::Cortana::CortanaSettings) GetDefault() const;
    };
    template <> struct consume<llm:OS::Services::Cortana::ICortanaSettingsStatics>
    {
        template <typename D> using type = consume_Windows_Services_Cortana_ICortanaSettingsStatics<D>;
    };
}
#endif
