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
#ifndef LLM_OS_ApplicationModel_Wallet_0_H
#define LLM_OS_ApplicationModel_Wallet_0_H
LLM_EXPORT namespace llm::OS::Devices::Geolocation
{
    struct BasicGeoposition;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename K, typename V> struct __declspec(empty_bases) IMap;
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Wallet
{
    enum class WalletActionKind : int32_t
    {
        OpenItem = 0,
        Transaction = 1,
        MoreTransactions = 2,
        Message = 3,
        Verb = 4,
    };
    enum class WalletBarcodeSymbology : int32_t
    {
        Invalid = 0,
        Upca = 1,
        Upce = 2,
        Ean13 = 3,
        Ean8 = 4,
        Itf = 5,
        Code39 = 6,
        Code128 = 7,
        Qr = 8,
        Pdf417 = 9,
        Aztec = 10,
        Custom = 100000,
    };
    enum class WalletDetailViewPosition : int32_t
    {
        Hidden = 0,
        HeaderField1 = 1,
        HeaderField2 = 2,
        PrimaryField1 = 3,
        PrimaryField2 = 4,
        SecondaryField1 = 5,
        SecondaryField2 = 6,
        SecondaryField3 = 7,
        SecondaryField4 = 8,
        SecondaryField5 = 9,
        CenterField1 = 10,
        FooterField1 = 11,
        FooterField2 = 12,
        FooterField3 = 13,
        FooterField4 = 14,
    };
    enum class WalletItemKind : int32_t
    {
        Invalid = 0,
        Deal = 1,
        General = 2,
        PaymentInstrument = 3,
        Ticket = 4,
        BoardingPass = 5,
        MembershipCard = 6,
    };
    enum class WalletSummaryViewPosition : int32_t
    {
        Hidden = 0,
        Field1 = 1,
        Field2 = 2,
    };
    struct IWalletBarcode;
    struct IWalletBarcodeFactory;
    struct IWalletItem;
    struct IWalletItemCustomProperty;
    struct IWalletItemCustomPropertyFactory;
    struct IWalletItemFactory;
    struct IWalletItemStore;
    struct IWalletItemStore2;
    struct IWalletManagerStatics;
    struct IWalletRelevantLocation;
    struct IWalletTransaction;
    struct IWalletVerb;
    struct IWalletVerbFactory;
    struct WalletBarcode;
    struct WalletItem;
    struct WalletItemCustomProperty;
    struct WalletItemStore;
    struct WalletManager;
    struct WalletRelevantLocation;
    struct WalletTransaction;
    struct WalletVerb;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletBarcode>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletBarcodeFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletItem>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletItemFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletItemStore>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletItemStore2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletTransaction>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletVerb>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::IWalletVerbFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletBarcode>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletItem>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletItemCustomProperty>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletItemStore>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletRelevantLocation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletTransaction>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletVerb>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletActionKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletBarcodeSymbology>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletDetailViewPosition>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletItemKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Wallet::WalletSummaryViewPosition>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletBarcode> = L"Windows.ApplicationModel.Wallet.WalletBarcode";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletItem> = L"Windows.ApplicationModel.Wallet.WalletItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletItemCustomProperty> = L"Windows.ApplicationModel.Wallet.WalletItemCustomProperty";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletItemStore> = L"Windows.ApplicationModel.Wallet.WalletItemStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletManager> = L"Windows.ApplicationModel.Wallet.WalletManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletRelevantLocation> = L"Windows.ApplicationModel.Wallet.WalletRelevantLocation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletTransaction> = L"Windows.ApplicationModel.Wallet.WalletTransaction";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletVerb> = L"Windows.ApplicationModel.Wallet.WalletVerb";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletActionKind> = L"Windows.ApplicationModel.Wallet.WalletActionKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletBarcodeSymbology> = L"Windows.ApplicationModel.Wallet.WalletBarcodeSymbology";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletDetailViewPosition> = L"Windows.ApplicationModel.Wallet.WalletDetailViewPosition";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletItemKind> = L"Windows.ApplicationModel.Wallet.WalletItemKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::WalletSummaryViewPosition> = L"Windows.ApplicationModel.Wallet.WalletSummaryViewPosition";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletBarcode> = L"Windows.ApplicationModel.Wallet.IWalletBarcode";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletBarcodeFactory> = L"Windows.ApplicationModel.Wallet.IWalletBarcodeFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletItem> = L"Windows.ApplicationModel.Wallet.IWalletItem";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty> = L"Windows.ApplicationModel.Wallet.IWalletItemCustomProperty";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory> = L"Windows.ApplicationModel.Wallet.IWalletItemCustomPropertyFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletItemFactory> = L"Windows.ApplicationModel.Wallet.IWalletItemFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletItemStore> = L"Windows.ApplicationModel.Wallet.IWalletItemStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletItemStore2> = L"Windows.ApplicationModel.Wallet.IWalletItemStore2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletManagerStatics> = L"Windows.ApplicationModel.Wallet.IWalletManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation> = L"Windows.ApplicationModel.Wallet.IWalletRelevantLocation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletTransaction> = L"Windows.ApplicationModel.Wallet.IWalletTransaction";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletVerb> = L"Windows.ApplicationModel.Wallet.IWalletVerb";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Wallet::IWalletVerbFactory> = L"Windows.ApplicationModel.Wallet.IWalletVerbFactory";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletBarcode>{ 0x4F857B29,0xDE80,0x4EA4,{ 0xA1,0xCD,0x81,0xCD,0x08,0x4D,0xAC,0x27 } }; // 4F857B29-DE80-4EA4-A1CD-81CD084DAC27
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletBarcodeFactory>{ 0x30117161,0xED9C,0x469E,{ 0xBB,0xFD,0x30,0x6C,0x95,0xEA,0x71,0x08 } }; // 30117161-ED9C-469E-BBFD-306C95EA7108
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletItem>{ 0x20B54BE8,0x118D,0x4EC4,{ 0x99,0x6C,0xB9,0x63,0xE7,0xBD,0x3E,0x74 } }; // 20B54BE8-118D-4EC4-996C-B963E7BD3E74
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty>{ 0xB94B40F3,0xFA00,0x40FD,{ 0x98,0xDC,0x9D,0xE4,0x66,0x97,0xF1,0xE7 } }; // B94B40F3-FA00-40FD-98DC-9DE46697F1E7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>{ 0xD0046A44,0x61A1,0x41AA,{ 0xB2,0x59,0xA5,0x61,0x0A,0xB5,0xD5,0x75 } }; // D0046A44-61A1-41AA-B259-A5610AB5D575
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletItemFactory>{ 0x53E27470,0x4F0B,0x4A3E,{ 0x99,0xE5,0x0B,0xBB,0x1E,0xAB,0x38,0xD4 } }; // 53E27470-4F0B-4A3E-99E5-0BBB1EAB38D4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletItemStore>{ 0x7160484B,0x6D49,0x48F8,{ 0x91,0xA9,0x40,0xA1,0xD0,0xF1,0x3E,0xF4 } }; // 7160484B-6D49-48F8-91A9-40A1D0F13EF4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletItemStore2>{ 0x65E682F0,0x7009,0x4A15,{ 0xBD,0x54,0x4F,0xFF,0x37,0x9B,0xFF,0xE2 } }; // 65E682F0-7009-4A15-BD54-4FFF379BFFE2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletManagerStatics>{ 0x5111D6B8,0xC9A4,0x4C64,{ 0xB4,0xDD,0xE1,0xE5,0x48,0x00,0x1C,0x0D } }; // 5111D6B8-C9A4-4C64-B4DD-E1E548001C0D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation>{ 0x9FD8782A,0xE3F9,0x4DE1,{ 0xBA,0xB3,0xBB,0x19,0x2E,0x46,0xB3,0xF3 } }; // 9FD8782A-E3F9-4DE1-BAB3-BB192E46B3F3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletTransaction>{ 0x40E1E940,0x2606,0x4519,{ 0x81,0xCB,0xBF,0xF1,0xC6,0x0D,0x1F,0x79 } }; // 40E1E940-2606-4519-81CB-BFF1C60D1F79
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletVerb>{ 0x17B826D6,0xE3C1,0x4C74,{ 0x8A,0x94,0x21,0x7A,0xAD,0xBC,0x48,0x84 } }; // 17B826D6-E3C1-4C74-8A94-217AADBC4884
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Wallet::IWalletVerbFactory>{ 0x76012771,0xBE58,0x4D5E,{ 0x83,0xED,0x58,0xB1,0x66,0x9C,0x7A,0xD9 } }; // 76012771-BE58-4D5E-83ED-58B1669C7AD9
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletBarcode>{ using type = llm::OS::ApplicationModel::Wallet::IWalletBarcode; };
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletItem>{ using type = llm::OS::ApplicationModel::Wallet::IWalletItem; };
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletItemCustomProperty>{ using type = llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty; };
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletItemStore>{ using type = llm::OS::ApplicationModel::Wallet::IWalletItemStore; };
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletRelevantLocation>{ using type = llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation; };
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletTransaction>{ using type = llm::OS::ApplicationModel::Wallet::IWalletTransaction; };
    template <> struct default_interface<llm::OS::ApplicationModel::Wallet::WalletVerb>{ using type = llm::OS::ApplicationModel::Wallet::IWalletVerb; };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletBarcode>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Symbology(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall GetImageAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletBarcodeFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWalletBarcode(int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCustomWalletBarcode(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsAcknowledged(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsAcknowledged(bool) noexcept = 0;
            virtual int32_t __stdcall get_IssuerDisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_IssuerDisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_LastUpdated(void**) noexcept = 0;
            virtual int32_t __stdcall put_LastUpdated(void*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Barcode(void**) noexcept = 0;
            virtual int32_t __stdcall put_Barcode(void*) noexcept = 0;
            virtual int32_t __stdcall get_ExpirationDate(void**) noexcept = 0;
            virtual int32_t __stdcall put_ExpirationDate(void*) noexcept = 0;
            virtual int32_t __stdcall get_Logo159x159(void**) noexcept = 0;
            virtual int32_t __stdcall put_Logo159x159(void*) noexcept = 0;
            virtual int32_t __stdcall get_Logo336x336(void**) noexcept = 0;
            virtual int32_t __stdcall put_Logo336x336(void*) noexcept = 0;
            virtual int32_t __stdcall get_Logo99x99(void**) noexcept = 0;
            virtual int32_t __stdcall put_Logo99x99(void*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayMessage(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayMessage(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisplayMessageLaunchable(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsDisplayMessageLaunchable(bool) noexcept = 0;
            virtual int32_t __stdcall get_LogoText(void**) noexcept = 0;
            virtual int32_t __stdcall put_LogoText(void*) noexcept = 0;
            virtual int32_t __stdcall get_HeaderColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_HeaderColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_BodyColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_BodyColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_HeaderFontColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_HeaderFontColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_BodyFontColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall put_BodyFontColor(struct struct_Windows_UI_Color) noexcept = 0;
            virtual int32_t __stdcall get_HeaderBackgroundImage(void**) noexcept = 0;
            virtual int32_t __stdcall put_HeaderBackgroundImage(void*) noexcept = 0;
            virtual int32_t __stdcall get_BodyBackgroundImage(void**) noexcept = 0;
            virtual int32_t __stdcall put_BodyBackgroundImage(void*) noexcept = 0;
            virtual int32_t __stdcall get_LogoImage(void**) noexcept = 0;
            virtual int32_t __stdcall put_LogoImage(void*) noexcept = 0;
            virtual int32_t __stdcall get_PromotionalImage(void**) noexcept = 0;
            virtual int32_t __stdcall put_PromotionalImage(void*) noexcept = 0;
            virtual int32_t __stdcall get_RelevantDate(void**) noexcept = 0;
            virtual int32_t __stdcall put_RelevantDate(void*) noexcept = 0;
            virtual int32_t __stdcall get_RelevantDateDisplayMessage(void**) noexcept = 0;
            virtual int32_t __stdcall put_RelevantDateDisplayMessage(void*) noexcept = 0;
            virtual int32_t __stdcall get_TransactionHistory(void**) noexcept = 0;
            virtual int32_t __stdcall get_RelevantLocations(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsMoreTransactionHistoryLaunchable(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsMoreTransactionHistoryLaunchable(bool) noexcept = 0;
            virtual int32_t __stdcall get_DisplayProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_Verbs(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
            virtual int32_t __stdcall get_AutoDetectLinks(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutoDetectLinks(bool) noexcept = 0;
            virtual int32_t __stdcall get_DetailViewPosition(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DetailViewPosition(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SummaryViewPosition(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SummaryViewPosition(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWalletItemCustomProperty(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletItemFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWalletItem(int32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletItemStore>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AddAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ClearAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetWalletItemAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetItemsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetItemsWithKindAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ImportItemAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ShowItemAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UpdateAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletItemStore2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ItemsChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ItemsChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestStoreAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Position(struct struct_Windows_Devices_Geolocation_BasicGeoposition*) noexcept = 0;
            virtual int32_t __stdcall put_Position(struct struct_Windows_Devices_Geolocation_BasicGeoposition) noexcept = 0;
            virtual int32_t __stdcall get_DisplayMessage(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayMessage(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletTransaction>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayAmount(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayAmount(void*) noexcept = 0;
            virtual int32_t __stdcall get_IgnoreTimeOfDay(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IgnoreTimeOfDay(bool) noexcept = 0;
            virtual int32_t __stdcall get_DisplayLocation(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayLocation(void*) noexcept = 0;
            virtual int32_t __stdcall get_TransactionDate(void**) noexcept = 0;
            virtual int32_t __stdcall put_TransactionDate(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsLaunchable(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsLaunchable(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletVerb>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Wallet::IWalletVerbFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWalletVerb(void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletBarcode
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletBarcodeSymbology) Symbology() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Value() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamReference>) GetImageAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletBarcode>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletBarcode<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletBarcodeFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletBarcode) CreateWalletBarcode(llm::OS::ApplicationModel::Wallet::WalletBarcodeSymbology const& symbology, param::hstring const& value) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletBarcode) CreateCustomWalletBarcode(llm::OS::Storage::Streams::IRandomAccessStreamReference const& streamToBarcodeImage) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletBarcodeFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletBarcodeFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAcknowledged() const;
        LLM_IMPL_AUTO(void) IsAcknowledged(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) IssuerDisplayName() const;
        LLM_IMPL_AUTO(void) IssuerDisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) LastUpdated() const;
        LLM_IMPL_AUTO(void) LastUpdated(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletItemKind) Kind() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletBarcode) Barcode() const;
        LLM_IMPL_AUTO(void) Barcode(llm::OS::ApplicationModel::Wallet::WalletBarcode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) ExpirationDate() const;
        LLM_IMPL_AUTO(void) ExpirationDate(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Logo159x159() const;
        LLM_IMPL_AUTO(void) Logo159x159(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Logo336x336() const;
        LLM_IMPL_AUTO(void) Logo336x336(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Logo99x99() const;
        LLM_IMPL_AUTO(void) Logo99x99(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayMessage() const;
        LLM_IMPL_AUTO(void) DisplayMessage(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisplayMessageLaunchable() const;
        LLM_IMPL_AUTO(void) IsDisplayMessageLaunchable(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LogoText() const;
        LLM_IMPL_AUTO(void) LogoText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) HeaderColor() const;
        LLM_IMPL_AUTO(void) HeaderColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) BodyColor() const;
        LLM_IMPL_AUTO(void) BodyColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) HeaderFontColor() const;
        LLM_IMPL_AUTO(void) HeaderFontColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) BodyFontColor() const;
        LLM_IMPL_AUTO(void) BodyFontColor(llm::OS::UI::Color const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) HeaderBackgroundImage() const;
        LLM_IMPL_AUTO(void) HeaderBackgroundImage(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) BodyBackgroundImage() const;
        LLM_IMPL_AUTO(void) BodyBackgroundImage(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) LogoImage() const;
        LLM_IMPL_AUTO(void) LogoImage(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) PromotionalImage() const;
        LLM_IMPL_AUTO(void) PromotionalImage(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) RelevantDate() const;
        LLM_IMPL_AUTO(void) RelevantDate(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RelevantDateDisplayMessage() const;
        LLM_IMPL_AUTO(void) RelevantDateDisplayMessage(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::ApplicationModel::Wallet::WalletTransaction>) TransactionHistory() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::ApplicationModel::Wallet::WalletRelevantLocation>) RelevantLocations() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMoreTransactionHistoryLaunchable() const;
        LLM_IMPL_AUTO(void) IsMoreTransactionHistoryLaunchable(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::ApplicationModel::Wallet::WalletItemCustomProperty>) DisplayProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::ApplicationModel::Wallet::WalletVerb>) Verbs() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletItem>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletItem<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletItemCustomProperty
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Value() const;
        LLM_IMPL_AUTO(void) Value(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutoDetectLinks() const;
        LLM_IMPL_AUTO(void) AutoDetectLinks(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletDetailViewPosition) DetailViewPosition() const;
        LLM_IMPL_AUTO(void) DetailViewPosition(llm::OS::ApplicationModel::Wallet::WalletDetailViewPosition const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletSummaryViewPosition) SummaryViewPosition() const;
        LLM_IMPL_AUTO(void) SummaryViewPosition(llm::OS::ApplicationModel::Wallet::WalletSummaryViewPosition const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletItemCustomProperty>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletItemCustomProperty<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletItemCustomPropertyFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletItemCustomProperty) CreateWalletItemCustomProperty(param::hstring const& name, param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletItemCustomPropertyFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletItemCustomPropertyFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletItemFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletItem) CreateWalletItem(llm::OS::ApplicationModel::Wallet::WalletItemKind const& kind, param::hstring const& displayName) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletItemFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletItemFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletItemStore
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) AddAsync(param::hstring const& id, llm::OS::ApplicationModel::Wallet::WalletItem const& item) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ClearAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItem>) GetWalletItemAsync(param::hstring const& id) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Wallet::WalletItem>>) GetItemsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Wallet::WalletItem>>) GetItemsAsync(llm::OS::ApplicationModel::Wallet::WalletItemKind const& kind) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItem>) ImportItemAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& stream) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteAsync(param::hstring const& id) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ShowAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ShowAsync(param::hstring const& id) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) UpdateAsync(llm::OS::ApplicationModel::Wallet::WalletItem const& item) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletItemStore>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletItemStore<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletItemStore2
    {
        LLM_IMPL_AUTO(llm::event_token) ItemsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::WalletItemStore, llm::OS::Foundation::IInspectable> const& handler) const;
        using ItemsChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Wallet::IWalletItemStore2, &impl::abi_t<llm::OS::ApplicationModel::Wallet::IWalletItemStore2>::remove_ItemsChanged>;
        [[nodiscard]] ItemsChanged_revoker ItemsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Wallet::WalletItemStore, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ItemsChanged(llm::event_token const& cookie) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletItemStore2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletItemStore2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Wallet::WalletItemStore>) RequestStoreAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletRelevantLocation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::Geolocation::BasicGeoposition) Position() const;
        LLM_IMPL_AUTO(void) Position(llm::OS::Devices::Geolocation::BasicGeoposition const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayMessage() const;
        LLM_IMPL_AUTO(void) DisplayMessage(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletRelevantLocation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletRelevantLocation<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletTransaction
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayAmount() const;
        LLM_IMPL_AUTO(void) DisplayAmount(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IgnoreTimeOfDay() const;
        LLM_IMPL_AUTO(void) IgnoreTimeOfDay(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayLocation() const;
        LLM_IMPL_AUTO(void) DisplayLocation(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) TransactionDate() const;
        LLM_IMPL_AUTO(void) TransactionDate(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsLaunchable() const;
        LLM_IMPL_AUTO(void) IsLaunchable(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletTransaction>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletTransaction<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletVerb
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletVerb>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletVerb<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Wallet_IWalletVerbFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletVerb) CreateWalletVerb(param::hstring const& name) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Wallet::IWalletVerbFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Wallet_IWalletVerbFactory<D>;
    };
}
#endif
