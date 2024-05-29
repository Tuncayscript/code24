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
#ifndef LLM_OS_ApplicationModel_Wallet_System_0_H
#define LLM_OS_ApplicationModel_Wallet_System_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::Wallet
{
    struct WalletItem;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Wallet::System
{
    enum class WalletItemAppAssociation : int32_t
    {
        None = 0,
        AppInstalled = 1,
        AppNotInstalled = 2,
    };
    struct IWalletItemSystemStore;
    struct IWalletItemSystemStore2;
    struct IWalletManagerSystemStatics;
    struct WalletItemSystemStore;
    struct WalletManagerSystem;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::System::WalletManagerSystem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::System::WalletItemAppAssociation>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore> = L"Windows.ApplicationModel.Wallet.System.WalletItemSystemStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::System::WalletManagerSystem> = L"Windows.ApplicationModel.Wallet.System.WalletManagerSystem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::System::WalletItemAppAssociation> = L"Windows.ApplicationModel.Wallet.System.WalletItemAppAssociation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore> = L"Windows.ApplicationModel.Wallet.System.IWalletItemSystemStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2> = L"Windows.ApplicationModel.Wallet.System.IWalletItemSystemStore2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics> = L"Windows.ApplicationModel.Wallet.System.IWalletManagerSystemStatics";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore>{ 0x522E2BFF,0x96A2,0x4A17,{ 0x8D,0x19,0xFE,0x1D,0x9F,0x83,0x75,0x61 } }; // 522E2BFF-96A2-4A17-8D19-FE1D9F837561
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2>{ 0xF98D3A4E,0xBE00,0x4FDD,{ 0x97,0x34,0x6C,0x11,0x3C,0x1A,0xC1,0xCB } }; // F98D3A4E-BE00-4FDD-9734-6C113C1AC1CB
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>{ 0xBEE8EB89,0x2634,0x4B9A,{ 0x8B,0x23,0xEE,0x89,0x03,0xC9,0x1F,0xE0 } }; // BEE8EB89-2634-4B9A-8B23-EE8903C91FE0
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>{ using type = llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore; };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetItemsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ImportItemAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAppStatusForItem(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall LaunchAppForItemAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ItemsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ItemsChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestStoreAsync(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Wallet::WalletItem>>) GetItemsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteAsync(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItem>) ImportItemAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& stream) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::System::WalletItemAppAssociation) GetAppStatusForItem(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) LaunchAppForItemAsync(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore2
    {
        LLM_IMPL_AUTO(llm::event_token) ItemsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore, llm::OS::Foundation::IInspectable> const& handler) const;
        using ItemsChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2, &impl::abi_t<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2>::remove_ItemsChanged>;
        [[nodiscard]] ItemsChanged_revoker ItemsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ItemsChanged(llm::event_token const& cookie) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::System::IWalletItemSystemStore2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_System_IWalletItemSystemStore2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_System_IWalletManagerSystemStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::System::WalletItemSystemStore>) RequestStoreAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::System::IWalletManagerSystemStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_System_IWalletManagerSystemStatics<D>;
    };
}
#endif
