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
#ifndef LLM_OS_Security_Authorization_AppCapabilityAccess_0_H
#define LLM_OS_Security_Authorization_AppCapabilityAccess_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::Security::Authorization::AppCapabilityAccess
{
    enum class AppCapabilityAccessStatus : int32_t
    {
        DeniedBySystem = 0,
        NotDeclaredByApp = 1,
        DeniedByUser = 2,
        UserPromptRequired = 3,
        Allowed = 4,
    };
    struct IAppCapability;
    struct IAppCapability2;
    struct IAppCapabilityAccessChangedEventArgs;
    struct IAppCapabilityStatics;
    struct AppCapability;
    struct AppCapabilityAccessChangedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability> = L"Windows.Security.Authorization.AppCapabilityAccess.AppCapability";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> = L"Windows.Security.Authorization.AppCapabilityAccess.AppCapabilityAccessChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus> = L"Windows.Security.Authorization.AppCapabilityAccess.AppCapabilityAccessStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability> = L"Windows.Security.Authorization.AppCapabilityAccess.IAppCapability";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability2> = L"Windows.Security.Authorization.AppCapabilityAccess.IAppCapability2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs> = L"Windows.Security.Authorization.AppCapabilityAccess.IAppCapabilityAccessChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics> = L"Windows.Security.Authorization.AppCapabilityAccess.IAppCapabilityStatics";
    template <> inline constexpr guid guid_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability>{ 0x4C49D915,0x8A2A,0x4295,{ 0x94,0x37,0x2D,0xF7,0xC3,0x96,0xAF,0xF4 } }; // 4C49D915-8A2A-4295-9437-2DF7C396AFF4
    template <> inline constexpr guid guid_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability2>{ 0x11C7CCB6,0xC74F,0x50A3,{ 0xB9,0x60,0x88,0x00,0x87,0x67,0xD9,0x39 } }; // 11C7CCB6-C74F-50A3-B960-88008767D939
    template <> inline constexpr guid guid_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs>{ 0x0A578D15,0xBDD7,0x457E,{ 0x8C,0xCA,0x6F,0x53,0xBD,0x2E,0x59,0x44 } }; // 0A578D15-BDD7-457E-8CCA-6F53BD2E5944
    template <> inline constexpr guid guid_v<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics>{ 0x7C353E2A,0x46EE,0x44E5,{ 0xAF,0x3D,0x6A,0xD3,0xFC,0x49,0xBD,0x22 } }; // 7C353E2A-46EE-44E5-AF3D-6AD3FC49BD22
    template <> struct default_interface<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability>{ using type = llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability; };
    template <> struct default_interface<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs>{ using type = llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs; };
    template <> struct abi<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CapabilityName(void**) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CheckAccess(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_AccessChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AccessChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayMessage(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayMessage(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestAccessForCapabilitiesAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestAccessForCapabilitiesForUserAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall Create(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithProcessIdForUser(void*, void*, uint32_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CapabilityName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::System::User) User() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>) RequestAccessAsync() const;
        LLM_IMPL_AUTO(llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus) CheckAccess() const;
        LLM_IMPL_AUTO(llm::event_token) AccessChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability, llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> const& handler) const;
        using AccessChanged_revoker = impl::event_revoker<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability, &impl::abi_t<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability>::remove_AccessChanged>;
        [[nodiscard]] AccessChanged_revoker AccessChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability, llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AccessChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability>
    {
        template <typename D> using type = consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayMessage() const;
        LLM_IMPL_AUTO(void) DisplayMessage(param::hstring const& value) const;
    };
    template <> struct consume<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapability2>
    {
        template <typename D> using type = consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapability2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityAccessChangedEventArgs
    {
    };
    template <> struct consume<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityAccessChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityAccessChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IMapView<hstring, llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>) RequestAccessForCapabilitiesAsync(param::async_iterable<hstring> const& capabilityNames) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IMapView<hstring, llm:OS::Security::Authorization::AppCapabilityAccess::AppCapabilityAccessStatus>>) RequestAccessForCapabilitiesForUserAsync(llm:OS::System::User const& user, param::async_iterable<hstring> const& capabilityNames) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability) Create(param::hstring const& capabilityName) const;
        LLM_IMPL_AUTO(llm:OS::Security::Authorization::AppCapabilityAccess::AppCapability) CreateWithProcessIdForUser(llm:OS::System::User const& user, param::hstring const& capabilityName, uint32_t pid) const;
    };
    template <> struct consume<llm:OS::Security::Authorization::AppCapabilityAccess::IAppCapabilityStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authorization_AppCapabilityAccess_IAppCapabilityStatics<D>;
    };
}
#endif
