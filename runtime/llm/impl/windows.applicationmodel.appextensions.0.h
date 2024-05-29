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
#ifndef LLM_OS_ApplicationModel_AppExtensions_0_H
#define LLM_OS_ApplicationModel_AppExtensions_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel
{
    struct AppInfo;
    struct Package;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    struct IPropertySet;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Storage
{
    struct StorageFolder;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::AppExtensions
{
    struct IAppExtension;
    struct IAppExtension2;
    struct IAppExtensionCatalog;
    struct IAppExtensionCatalogStatics;
    struct IAppExtensionPackageInstalledEventArgs;
    struct IAppExtensionPackageStatusChangedEventArgs;
    struct IAppExtensionPackageUninstallingEventArgs;
    struct IAppExtensionPackageUpdatedEventArgs;
    struct IAppExtensionPackageUpdatingEventArgs;
    struct AppExtension;
    struct AppExtensionCatalog;
    struct AppExtensionPackageInstalledEventArgs;
    struct AppExtensionPackageStatusChangedEventArgs;
    struct AppExtensionPackageUninstallingEventArgs;
    struct AppExtensionPackageUpdatedEventArgs;
    struct AppExtensionPackageUpdatingEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtension>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtension2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtension>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtension> = L"Windows.ApplicationModel.AppExtensions.AppExtension";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog> = L"Windows.ApplicationModel.AppExtensions.AppExtensionCatalog";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> = L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageInstalledEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> = L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageStatusChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> = L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageUninstallingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> = L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageUpdatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> = L"Windows.ApplicationModel.AppExtensions.AppExtensionPackageUpdatingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtension> = L"Windows.ApplicationModel.AppExtensions.IAppExtension";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtension2> = L"Windows.ApplicationModel.AppExtensions.IAppExtension2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionCatalog";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionCatalogStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionPackageInstalledEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionPackageStatusChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionPackageUninstallingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionPackageUpdatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs> = L"Windows.ApplicationModel.AppExtensions.IAppExtensionPackageUpdatingEventArgs";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtension>{ 0x8450902C,0x15ED,0x4FAF,{ 0x93,0xEA,0x22,0x37,0xBB,0xF8,0xCB,0xD6 } }; // 8450902C-15ED-4FAF-93EA-2237BBF8CBD6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtension2>{ 0xAB3B15F0,0x14F9,0x4B9F,{ 0x94,0x19,0xA3,0x49,0xA2,0x42,0xEF,0x38 } }; // AB3B15F0-14F9-4B9F-9419-A349A242EF38
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>{ 0x97872032,0x8426,0x4AD1,{ 0x90,0x84,0x92,0xE8,0x8C,0x2D,0xA2,0x00 } }; // 97872032-8426-4AD1-9084-92E88C2DA200
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics>{ 0x3C36668A,0x5F18,0x4F0B,{ 0x9C,0xE5,0xCA,0xB6,0x1D,0x19,0x6F,0x11 } }; // 3C36668A-5F18-4F0B-9CE5-CAB61D196F11
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>{ 0x39E59234,0x3351,0x4A8D,{ 0x97,0x45,0xE7,0xD3,0xDD,0x45,0xBC,0x48 } }; // 39E59234-3351-4A8D-9745-E7D3DD45BC48
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>{ 0x1CE17433,0x1153,0x44FD,{ 0x87,0xB1,0x8A,0xE1,0x05,0x03,0x03,0xDF } }; // 1CE17433-1153-44FD-87B1-8AE1050303DF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>{ 0x60F160C5,0x171E,0x40FF,{ 0xAE,0x98,0xAB,0x2C,0x20,0xDD,0x4D,0x75 } }; // 60F160C5-171E-40FF-AE98-AB2C20DD4D75
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>{ 0x3A83C43F,0x797E,0x44B5,{ 0xBA,0x24,0xA4,0xC8,0xB5,0xA5,0x43,0xD7 } }; // 3A83C43F-797E-44B5-BA24-A4C8B5A543D7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>{ 0x7ED59329,0x1A65,0x4800,{ 0xA7,0x00,0xB3,0x21,0x00,0x9E,0x30,0x6A } }; // 7ED59329-1A65-4800-A700-B321009E306A
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtension>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtension; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs>{ using type = llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs; };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtension>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_AppInfo(void**) noexcept = 0;
            virtual int32_t __stdcall GetExtensionPropertiesAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetPublicFolderAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtension2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppUserModelId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindAllAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestRemovePackageAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall add_PackageInstalled(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageInstalled(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageUpdating(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageUpdating(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageUpdated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageUninstalling(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageUninstalling(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PackageStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PackageStatusChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Open(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppExtensionName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Extensions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppExtensionName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppExtensionName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppExtensionName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
            virtual int32_t __stdcall get_Extensions(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppExtensionName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Package(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtension
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppInfo) AppInfo() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IPropertySet>) GetExtensionPropertiesAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::StorageFolder>) GetPublicFolderAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtension>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtension<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtension2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppUserModelId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtension2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtension2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>>) FindAllAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestRemovePackageAsync(param::hstring const& packageFullName) const;
        LLM_IMPL_AUTO(llm::event_token) PackageInstalled(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> const& handler) const;
        using PackageInstalled_revoker = impl::event_revoker<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog, &impl::abi_t<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>::remove_PackageInstalled>;
        [[nodiscard]] PackageInstalled_revoker PackageInstalled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageInstalledEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageInstalled(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> const& handler) const;
        using PackageUpdating_revoker = impl::event_revoker<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog, &impl::abi_t<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>::remove_PackageUpdating>;
        [[nodiscard]] PackageUpdating_revoker PackageUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageUpdating(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> const& handler) const;
        using PackageUpdated_revoker = impl::event_revoker<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog, &impl::abi_t<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>::remove_PackageUpdated>;
        [[nodiscard]] PackageUpdated_revoker PackageUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUpdatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageUpdated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageUninstalling(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> const& handler) const;
        using PackageUninstalling_revoker = impl::event_revoker<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog, &impl::abi_t<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>::remove_PackageUninstalling>;
        [[nodiscard]] PackageUninstalling_revoker PackageUninstalling(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageUninstallingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageUninstalling(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PackageStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> const& handler) const;
        using PackageStatusChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog, &impl::abi_t<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>::remove_PackageStatusChanged>;
        [[nodiscard]] PackageStatusChanged_revoker PackageStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog, llm::OS::ApplicationModel::AppExtensions::AppExtensionPackageStatusChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) PackageStatusChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalog>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalog<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalogStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppExtensions::AppExtensionCatalog) Open(param::hstring const& appExtensionName) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionCatalogStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionCatalogStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageInstalledEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppExtensionName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>) Extensions() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageInstalledEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageInstalledEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageStatusChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppExtensionName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageStatusChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageStatusChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUninstallingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppExtensionName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUninstallingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUninstallingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppExtensionName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppExtensions::AppExtension>) Extensions() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatingEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppExtensionName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Package) Package() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::AppExtensions::IAppExtensionPackageUpdatingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_AppExtensions_IAppExtensionPackageUpdatingEventArgs<D>;
    };
}
#endif
