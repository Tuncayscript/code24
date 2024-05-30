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
#ifndef LLM_OS_Management_Update_0_H
#define LLM_OS_Management_Update_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct EventRegistrationToken;
    struct HResult;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    struct ValueSet;
}
LLM_EXPORT namespace llm:OS::Management::Update
{
    enum class WindowsUpdateAdministratorOptions : uint32_t
    {
        None = 0,
        RequireAdministratorApprovalForScans = 0x1,
        RequireAdministratorApprovalForUpdates = 0x2,
        RequireAdministratorApprovalForActions = 0x4,
    };
    enum class WindowsUpdateAdministratorStatus : int32_t
    {
        Succeeded = 0,
        NoAdministratorRegistered = 1,
        OtherAdministratorIsRegistered = 2,
    };
    enum class WindowsUpdateAttentionRequiredReason : int32_t
    {
        None = 0,
        SeekerUpdate = 1,
        ReadyToReboot = 2,
        NeedNonMeteredNetwork = 3,
        NeedUserAgreementForMeteredNetwork = 4,
        NeedNetwork = 5,
        NeedMoreSpace = 6,
        BatterySaverEnabled = 7,
        NeedUserInteraction = 8,
        NeedUserAgreementForPolicy = 9,
        CompatibilityError = 10,
        NeedUserInteractionForEula = 11,
        NeedUserInteractionForCta = 12,
        Regulated = 13,
        ExternalReboot = 14,
        OtherUpdate = 15,
        BlockedByProvider = 16,
        BlockedByPostRebootFailure = 17,
        UserEngaged = 18,
        BlockedByBattery = 19,
        Exclusivity = 20,
        BlockedBySerialization = 21,
        ConflictClass = 22,
        BlockedByAdminApproval = 23,
        BlockedByTooManyAttempts = 24,
        BlockedByFailure = 25,
        Demotion = 26,
        BlockedByActiveHours = 27,
        ScheduledForMaintenance = 28,
        PolicyScheduledInstallTime = 29,
        BlockedByOobe = 30,
        DeferredDuringOobe = 31,
        DeferredForSustainableTime = 32,
    };
    struct IPreviewBuildsManager;
    struct IPreviewBuildsManagerStatics;
    struct IPreviewBuildsState;
    struct IWindowsUpdate;
    struct IWindowsUpdateActionCompletedEventArgs;
    struct IWindowsUpdateActionProgress;
    struct IWindowsUpdateActionResult;
    struct IWindowsUpdateAdministrator;
    struct IWindowsUpdateAdministratorStatics;
    struct IWindowsUpdateApprovalData;
    struct IWindowsUpdateAttentionRequiredInfo;
    struct IWindowsUpdateAttentionRequiredReasonChangedEventArgs;
    struct IWindowsUpdateGetAdministratorResult;
    struct IWindowsUpdateItem;
    struct IWindowsUpdateManager;
    struct IWindowsUpdateManagerFactory;
    struct IWindowsUpdateProgressChangedEventArgs;
    struct IWindowsUpdateRestartRequestOptions;
    struct IWindowsUpdateRestartRequestOptionsFactory;
    struct IWindowsUpdateScanCompletedEventArgs;
    struct PreviewBuildsManager;
    struct PreviewBuildsState;
    struct WindowsUpdate;
    struct WindowsUpdateActionCompletedEventArgs;
    struct WindowsUpdateActionProgress;
    struct WindowsUpdateActionResult;
    struct WindowsUpdateAdministrator;
    struct WindowsUpdateApprovalData;
    struct WindowsUpdateAttentionRequiredInfo;
    struct WindowsUpdateAttentionRequiredReasonChangedEventArgs;
    struct WindowsUpdateGetAdministratorResult;
    struct WindowsUpdateItem;
    struct WindowsUpdateManager;
    struct WindowsUpdateProgressChangedEventArgs;
    struct WindowsUpdateRestartRequestOptions;
    struct WindowsUpdateScanCompletedEventArgs;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Management::Update::IPreviewBuildsManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IPreviewBuildsManagerStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IPreviewBuildsState>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdate>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateActionProgress>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateActionResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateAdministrator>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateAdministratorStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateApprovalData>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateItem>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateManager>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateManagerFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Management::Update::PreviewBuildsManager>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::PreviewBuildsState>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdate>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateActionCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateActionProgress>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateActionResult>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateAdministrator>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateApprovalData>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateAttentionRequiredInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateGetAdministratorResult>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateItem>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateManager>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateProgressChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateRestartRequestOptions>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateScanCompletedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateAdministratorOptions>{ using type = enum_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateAdministratorStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Management::Update::WindowsUpdateAttentionRequiredReason>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::PreviewBuildsManager> = L"Windows.Management.Update.PreviewBuildsManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::PreviewBuildsState> = L"Windows.Management.Update.PreviewBuildsState";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdate> = L"Windows.Management.Update.WindowsUpdate";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateActionCompletedEventArgs> = L"Windows.Management.Update.WindowsUpdateActionCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateActionProgress> = L"Windows.Management.Update.WindowsUpdateActionProgress";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateActionResult> = L"Windows.Management.Update.WindowsUpdateActionResult";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateAdministrator> = L"Windows.Management.Update.WindowsUpdateAdministrator";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateApprovalData> = L"Windows.Management.Update.WindowsUpdateApprovalData";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateAttentionRequiredInfo> = L"Windows.Management.Update.WindowsUpdateAttentionRequiredInfo";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> = L"Windows.Management.Update.WindowsUpdateAttentionRequiredReasonChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateGetAdministratorResult> = L"Windows.Management.Update.WindowsUpdateGetAdministratorResult";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateItem> = L"Windows.Management.Update.WindowsUpdateItem";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateManager> = L"Windows.Management.Update.WindowsUpdateManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateProgressChangedEventArgs> = L"Windows.Management.Update.WindowsUpdateProgressChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateRestartRequestOptions> = L"Windows.Management.Update.WindowsUpdateRestartRequestOptions";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateScanCompletedEventArgs> = L"Windows.Management.Update.WindowsUpdateScanCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateAdministratorOptions> = L"Windows.Management.Update.WindowsUpdateAdministratorOptions";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateAdministratorStatus> = L"Windows.Management.Update.WindowsUpdateAdministratorStatus";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::WindowsUpdateAttentionRequiredReason> = L"Windows.Management.Update.WindowsUpdateAttentionRequiredReason";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IPreviewBuildsManager> = L"Windows.Management.Update.IPreviewBuildsManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IPreviewBuildsManagerStatics> = L"Windows.Management.Update.IPreviewBuildsManagerStatics";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IPreviewBuildsState> = L"Windows.Management.Update.IPreviewBuildsState";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdate> = L"Windows.Management.Update.IWindowsUpdate";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs> = L"Windows.Management.Update.IWindowsUpdateActionCompletedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateActionProgress> = L"Windows.Management.Update.IWindowsUpdateActionProgress";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateActionResult> = L"Windows.Management.Update.IWindowsUpdateActionResult";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateAdministrator> = L"Windows.Management.Update.IWindowsUpdateAdministrator";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateAdministratorStatics> = L"Windows.Management.Update.IWindowsUpdateAdministratorStatics";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateApprovalData> = L"Windows.Management.Update.IWindowsUpdateApprovalData";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo> = L"Windows.Management.Update.IWindowsUpdateAttentionRequiredInfo";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs> = L"Windows.Management.Update.IWindowsUpdateAttentionRequiredReasonChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult> = L"Windows.Management.Update.IWindowsUpdateGetAdministratorResult";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateItem> = L"Windows.Management.Update.IWindowsUpdateItem";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateManager> = L"Windows.Management.Update.IWindowsUpdateManager";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateManagerFactory> = L"Windows.Management.Update.IWindowsUpdateManagerFactory";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs> = L"Windows.Management.Update.IWindowsUpdateProgressChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions> = L"Windows.Management.Update.IWindowsUpdateRestartRequestOptions";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory> = L"Windows.Management.Update.IWindowsUpdateRestartRequestOptionsFactory";
    template <> inline constexpr auto& name_v<llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs> = L"Windows.Management.Update.IWindowsUpdateScanCompletedEventArgs";
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IPreviewBuildsManager>{ 0xFA07DD61,0x7E4F,0x59F7,{ 0x7C,0x9F,0xDE,0xF9,0x05,0x1C,0x5F,0x62 } }; // FA07DD61-7E4F-59F7-7C9F-DEF9051C5F62
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IPreviewBuildsManagerStatics>{ 0x3E422887,0xB112,0x5A70,{ 0x7D,0xA1,0x97,0xD7,0x8D,0x32,0xAA,0x29 } }; // 3E422887-B112-5A70-7DA1-97D78D32AA29
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IPreviewBuildsState>{ 0xA2F2903E,0xB223,0x5F63,{ 0x75,0x46,0x3E,0x8E,0xAC,0x07,0x0A,0x2E } }; // A2F2903E-B223-5F63-7546-3E8EAC070A2E
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdate>{ 0xC3C88DD7,0x0EF3,0x52B2,{ 0xA9,0xAD,0x66,0xBF,0xC6,0xBD,0x95,0x82 } }; // C3C88DD7-0EF3-52B2-A9AD-66BFC6BD9582
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs>{ 0x2C44B950,0xA655,0x5321,{ 0xAE,0xC1,0xAE,0xE7,0x62,0x92,0x21,0x31 } }; // 2C44B950-A655-5321-AEC1-AEE762922131
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateActionProgress>{ 0x83B22D8A,0x4BB0,0x549F,{ 0xBA,0x39,0x59,0x72,0x48,0x82,0xD1,0x37 } }; // 83B22D8A-4BB0-549F-BA39-59724882D137
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateActionResult>{ 0xE6692C62,0xF697,0x51B7,{ 0xAB,0x7F,0xE7,0x3E,0x5E,0x68,0x8F,0x12 } }; // E6692C62-F697-51B7-AB7F-E73E5E688F12
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateAdministrator>{ 0x7A60181C,0xBA1E,0x5CF9,{ 0xAA,0x65,0x30,0x41,0x20,0xB7,0x3D,0x72 } }; // 7A60181C-BA1E-5CF9-AA65-304120B73D72
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateAdministratorStatics>{ 0x013E6D36,0xEF69,0x53BC,{ 0x8D,0xB8,0xC4,0x03,0xBC,0xA5,0x50,0xED } }; // 013E6D36-EF69-53BC-8DB8-C403BCA550ED
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateApprovalData>{ 0xAADF5BFD,0x84DB,0x59BC,{ 0x85,0xE2,0xAD,0x4F,0xC1,0xF6,0x2F,0x7C } }; // AADF5BFD-84DB-59BC-85E2-AD4FC1F62F7C
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo>{ 0x44DF2579,0x74D3,0x5FFA,{ 0xB6,0xCE,0x09,0xE1,0x87,0xE1,0xE0,0xED } }; // 44DF2579-74D3-5FFA-B6CE-09E187E1E0ED
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs>{ 0x0627ABCA,0xDBB8,0x524A,{ 0xB1,0xD2,0xD9,0xDF,0x00,0x4E,0xEB,0x31 } }; // 0627ABCA-DBB8-524A-B1D2-D9DF004EEB31
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult>{ 0xBB39FFC4,0x2C42,0x5B1C,{ 0x89,0x95,0x34,0x33,0x41,0xC9,0x2C,0x50 } }; // BB39FFC4-2C42-5B1C-8995-343341C92C50
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateItem>{ 0xB222E44A,0x49B6,0x59BF,{ 0xA0,0x33,0xEF,0x61,0x7C,0xD7,0x3A,0x98 } }; // B222E44A-49B6-59BF-A033-EF617CD73A98
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateManager>{ 0x5DD966C0,0xA71A,0x5602,{ 0xBB,0xD0,0x09,0xA7,0x0E,0x45,0x73,0xFA } }; // 5DD966C0-A71A-5602-BBD0-09A70E4573FA
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateManagerFactory>{ 0x1B394DF8,0xDECB,0x5F44,{ 0xB4,0x7C,0x6C,0xCF,0x3B,0xCF,0xDB,0x37 } }; // 1B394DF8-DECB-5F44-B47C-6CCF3BCFDB37
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs>{ 0xBBFBDEEB,0x94C8,0x5AA7,{ 0xB0,0xFB,0x66,0xC6,0x7C,0x23,0x3B,0x0A } }; // BBFBDEEB-94C8-5AA7-B0FB-66C67C233B0A
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions>{ 0x38CFB7D3,0x4188,0x5222,{ 0x90,0x5C,0x6C,0x44,0x43,0xC9,0x51,0xEE } }; // 38CFB7D3-4188-5222-905C-6C4443C951EE
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory>{ 0x75F41D04,0x0E17,0x50D0,{ 0x8C,0x15,0x6B,0x9D,0x05,0x39,0xB3,0xA9 } }; // 75F41D04-0E17-50D0-8C15-6B9D0539B3A9
    template <> inline constexpr guid guid_v<llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs>{ 0x95B6953E,0xBA5C,0x5FE8,{ 0xB1,0x15,0x12,0xDE,0x18,0x4A,0x6B,0xB0 } }; // 95B6953E-BA5C-5FE8-B115-12DE184A6BB0
    template <> struct default_interface<llm:OS::Management::Update::PreviewBuildsManager>{ using type = llm:OS::Management::Update::IPreviewBuildsManager; };
    template <> struct default_interface<llm:OS::Management::Update::PreviewBuildsState>{ using type = llm:OS::Management::Update::IPreviewBuildsState; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdate>{ using type = llm:OS::Management::Update::IWindowsUpdate; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateActionCompletedEventArgs>{ using type = llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateActionProgress>{ using type = llm:OS::Management::Update::IWindowsUpdateActionProgress; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateActionResult>{ using type = llm:OS::Management::Update::IWindowsUpdateActionResult; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateAdministrator>{ using type = llm:OS::Management::Update::IWindowsUpdateAdministrator; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateApprovalData>{ using type = llm:OS::Management::Update::IWindowsUpdateApprovalData; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateAttentionRequiredInfo>{ using type = llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs>{ using type = llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateGetAdministratorResult>{ using type = llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateItem>{ using type = llm:OS::Management::Update::IWindowsUpdateItem; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateManager>{ using type = llm:OS::Management::Update::IWindowsUpdateManager; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateProgressChangedEventArgs>{ using type = llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateRestartRequestOptions>{ using type = llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions; };
    template <> struct default_interface<llm:OS::Management::Update::WindowsUpdateScanCompletedEventArgs>{ using type = llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs; };
    template <> struct abi<llm:OS::Management::Update::IPreviewBuildsManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ArePreviewBuildsAllowed(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ArePreviewBuildsAllowed(bool) noexcept = 0;
            virtual int32_t __stdcall GetCurrentState(void**) noexcept = 0;
            virtual int32_t __stdcall SyncAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IPreviewBuildsManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IPreviewBuildsState>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdate>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProviderId(void**) noexcept = 0;
            virtual int32_t __stdcall get_UpdateId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsFeatureUpdate(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsMinorImpact(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsSecurity(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsCritical(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsForOS(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDriver(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsMandatory(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsUrgent(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsSeeker(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MoreInfoUrl(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportUrl(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsEulaAccepted(bool*) noexcept = 0;
            virtual int32_t __stdcall get_EulaText(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(void**) noexcept = 0;
            virtual int32_t __stdcall get_AttentionRequiredInfo(void**) noexcept = 0;
            virtual int32_t __stdcall get_ActionResult(void**) noexcept = 0;
            virtual int32_t __stdcall get_CurrentAction(void**) noexcept = 0;
            virtual int32_t __stdcall get_ActionProgress(void**) noexcept = 0;
            virtual int32_t __stdcall GetPropertyValue(void*, void**) noexcept = 0;
            virtual int32_t __stdcall AcceptEula() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Update(void**) noexcept = 0;
            virtual int32_t __stdcall get_Action(void**) noexcept = 0;
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateActionProgress>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Action(void**) noexcept = 0;
            virtual int32_t __stdcall get_Progress(double*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateActionResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_Action(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateAdministrator>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall StartAdministratorScan() noexcept = 0;
            virtual int32_t __stdcall ApproveWindowsUpdateAction(void*, void*) noexcept = 0;
            virtual int32_t __stdcall RevokeWindowsUpdateActionApproval(void*, void*) noexcept = 0;
            virtual int32_t __stdcall ApproveWindowsUpdate(void*, void*) noexcept = 0;
            virtual int32_t __stdcall RevokeWindowsUpdateApproval(void*) noexcept = 0;
            virtual int32_t __stdcall GetUpdates(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateAdministratorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetRegisteredAdministrator(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterForAdministration(void*, uint32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall UnregisterForAdministration(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetRegisteredAdministratorName(void**) noexcept = 0;
            virtual int32_t __stdcall RequestRestart(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CancelRestartRequest(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateApprovalData>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Seeker(void**) noexcept = 0;
            virtual int32_t __stdcall put_Seeker(void*) noexcept = 0;
            virtual int32_t __stdcall get_AllowDownloadOnMetered(void**) noexcept = 0;
            virtual int32_t __stdcall put_AllowDownloadOnMetered(void*) noexcept = 0;
            virtual int32_t __stdcall get_ComplianceDeadlineInDays(void**) noexcept = 0;
            virtual int32_t __stdcall put_ComplianceDeadlineInDays(void*) noexcept = 0;
            virtual int32_t __stdcall get_ComplianceGracePeriodInDays(void**) noexcept = 0;
            virtual int32_t __stdcall put_ComplianceGracePeriodInDays(void*) noexcept = 0;
            virtual int32_t __stdcall get_OptOutOfAutoReboot(void**) noexcept = 0;
            virtual int32_t __stdcall put_OptOutOfAutoReboot(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Update(void**) noexcept = 0;
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Administrator(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateItem>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProviderId(void**) noexcept = 0;
            virtual int32_t __stdcall get_UpdateId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Timestamp(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall get_MoreInfoUrl(void**) noexcept = 0;
            virtual int32_t __stdcall get_Category(void**) noexcept = 0;
            virtual int32_t __stdcall get_Operation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ScanningStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ScanningStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_WorkingStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_WorkingStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ProgressChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ProgressChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AttentionRequiredReasonChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AttentionRequiredReasonChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ActionCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ActionCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ScanCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ScanCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_IsScanning(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsWorking(bool*) noexcept = 0;
            virtual int32_t __stdcall get_LastSuccessfulScanTimestamp(void**) noexcept = 0;
            virtual int32_t __stdcall GetApplicableUpdates(void**) noexcept = 0;
            virtual int32_t __stdcall GetMostRecentCompletedUpdates(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetMostRecentCompletedUpdatesAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall StartScan(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateManagerFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Update(void**) noexcept = 0;
            virtual int32_t __stdcall get_ActionProgress(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall get_MoreInfoUrl(void**) noexcept = 0;
            virtual int32_t __stdcall put_MoreInfoUrl(void*) noexcept = 0;
            virtual int32_t __stdcall get_ComplianceDeadlineInDays(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ComplianceDeadlineInDays(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ComplianceGracePeriodInDays(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_ComplianceGracePeriodInDays(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_OrganizationName(void**) noexcept = 0;
            virtual int32_t __stdcall put_OrganizationName(void*) noexcept = 0;
            virtual int32_t __stdcall get_OptOutOfAutoReboot(bool*) noexcept = 0;
            virtual int32_t __stdcall put_OptOutOfAutoReboot(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void*, void*, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProviderId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
            virtual int32_t __stdcall get_Updates(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Management_Update_IPreviewBuildsManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) ArePreviewBuildsAllowed() const;
        LLM_IMPL_AUTO(void) ArePreviewBuildsAllowed(bool value) const;
        LLM_IMPL_AUTO(llm:OS::Management::Update::PreviewBuildsState) GetCurrentState() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<bool>) SyncAsync() const;
    };
    template <> struct consume<llm:OS::Management::Update::IPreviewBuildsManager>
    {
        template <typename D> using type = consume_Windows_Management_Update_IPreviewBuildsManager<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IPreviewBuildsManagerStatics
    {
        LLM_IMPL_AUTO(llm:OS::Management::Update::PreviewBuildsManager) GetDefault() const;
        LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm:OS::Management::Update::IPreviewBuildsManagerStatics>
    {
        template <typename D> using type = consume_Windows_Management_Update_IPreviewBuildsManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IPreviewBuildsState
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::ValueSet) Properties() const;
    };
    template <> struct consume<llm:OS::Management::Update::IPreviewBuildsState>
    {
        template <typename D> using type = consume_Windows_Management_Update_IPreviewBuildsState<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdate
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProviderId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UpdateId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsFeatureUpdate() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMinorImpact() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSecurity() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCritical() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsForOS() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDriver() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMandatory() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsUrgent() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSeeker() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) MoreInfoUrl() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) SupportUrl() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEulaAccepted() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) EulaText() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::DateTime>) Deadline() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAttentionRequiredInfo) AttentionRequiredInfo() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateActionResult) ActionResult() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CurrentAction() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateActionProgress) ActionProgress() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IInspectable) GetPropertyValue(param::hstring const& propertyName) const;
        LLM_IMPL_AUTO(void) AcceptEula() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdate>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdate<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdate) Update() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Action() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateActionCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateActionProgress
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Action() const;
        [[nodiscard]] LLM_IMPL_AUTO(double) Progress() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateActionProgress>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateActionProgress<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateActionResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Timestamp() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Action() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateActionResult>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateActionResult<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateAdministrator
    {
        LLM_IMPL_AUTO(void) StartAdministratorScan() const;
        LLM_IMPL_AUTO(void) ApproveWindowsUpdateAction(param::hstring const& updateId, param::hstring const& action) const;
        LLM_IMPL_AUTO(void) RevokeWindowsUpdateActionApproval(param::hstring const& updateId, param::hstring const& action) const;
        LLM_IMPL_AUTO(void) ApproveWindowsUpdate(param::hstring const& updateId, llm:OS::Management::Update::WindowsUpdateApprovalData const& approvalData) const;
        LLM_IMPL_AUTO(void) RevokeWindowsUpdateApproval(param::hstring const& updateId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Management::Update::WindowsUpdate>) GetUpdates() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateAdministrator>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics
    {
        LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateGetAdministratorResult) GetRegisteredAdministrator(param::hstring const& organizationName) const;
        LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAdministratorStatus) RegisterForAdministration(param::hstring const& organizationName, llm:OS::Management::Update::WindowsUpdateAdministratorOptions const& options) const;
        LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAdministratorStatus) UnregisterForAdministration(param::hstring const& organizationName) const;
        LLM_IMPL_AUTO(hstring) GetRegisteredAdministratorName() const;
        LLM_IMPL_AUTO(hstring) RequestRestart(llm:OS::Management::Update::WindowsUpdateRestartRequestOptions const& restartOptions) const;
        LLM_IMPL_AUTO(void) CancelRestartRequest(param::hstring const& requestRestartToken) const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateAdministratorStatics>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateApprovalData
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<bool>) Seeker() const;
        LLM_IMPL_AUTO(void) Seeker(llm:OS::Foundation::IReference<bool> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<bool>) AllowDownloadOnMetered() const;
        LLM_IMPL_AUTO(void) AllowDownloadOnMetered(llm:OS::Foundation::IReference<bool> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<int32_t>) ComplianceDeadlineInDays() const;
        LLM_IMPL_AUTO(void) ComplianceDeadlineInDays(llm:OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<int32_t>) ComplianceGracePeriodInDays() const;
        LLM_IMPL_AUTO(void) ComplianceGracePeriodInDays(llm:OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<bool>) OptOutOfAutoReboot() const;
        LLM_IMPL_AUTO(void) OptOutOfAutoReboot(llm:OS::Foundation::IReference<bool> const& value) const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateApprovalData>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAttentionRequiredReason) Reason() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::DateTime>) Timestamp() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredInfo>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredReasonChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdate) Update() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAttentionRequiredReason) Reason() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredReasonChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateGetAdministratorResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAdministrator) Administrator() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateAdministratorStatus) Status() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateGetAdministratorResult>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateGetAdministratorResult<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateItem
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProviderId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UpdateId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) Timestamp() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) MoreInfoUrl() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Category() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Operation() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateItem>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateItem<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateManager
    {
        LLM_IMPL_AUTO(llm::event_token) ScanningStateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Foundation::IInspectable> const& handler) const;
        using ScanningStateChanged_revoker = impl::event_revoker<llm:OS::Management::Update::IWindowsUpdateManager, &impl::abi_t<llm:OS::Management::Update::IWindowsUpdateManager>::remove_ScanningStateChanged>;
        [[nodiscard]] ScanningStateChanged_revoker ScanningStateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ScanningStateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) WorkingStateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Foundation::IInspectable> const& handler) const;
        using WorkingStateChanged_revoker = impl::event_revoker<llm:OS::Management::Update::IWindowsUpdateManager, &impl::abi_t<llm:OS::Management::Update::IWindowsUpdateManager>::remove_WorkingStateChanged>;
        [[nodiscard]] WorkingStateChanged_revoker WorkingStateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) WorkingStateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ProgressChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateProgressChangedEventArgs> const& handler) const;
        using ProgressChanged_revoker = impl::event_revoker<llm:OS::Management::Update::IWindowsUpdateManager, &impl::abi_t<llm:OS::Management::Update::IWindowsUpdateManager>::remove_ProgressChanged>;
        [[nodiscard]] ProgressChanged_revoker ProgressChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateProgressChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ProgressChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AttentionRequiredReasonChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> const& handler) const;
        using AttentionRequiredReasonChanged_revoker = impl::event_revoker<llm:OS::Management::Update::IWindowsUpdateManager, &impl::abi_t<llm:OS::Management::Update::IWindowsUpdateManager>::remove_AttentionRequiredReasonChanged>;
        [[nodiscard]] AttentionRequiredReasonChanged_revoker AttentionRequiredReasonChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AttentionRequiredReasonChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ActionCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateActionCompletedEventArgs> const& handler) const;
        using ActionCompleted_revoker = impl::event_revoker<llm:OS::Management::Update::IWindowsUpdateManager, &impl::abi_t<llm:OS::Management::Update::IWindowsUpdateManager>::remove_ActionCompleted>;
        [[nodiscard]] ActionCompleted_revoker ActionCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateActionCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ActionCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ScanCompleted(llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateScanCompletedEventArgs> const& handler) const;
        using ScanCompleted_revoker = impl::event_revoker<llm:OS::Management::Update::IWindowsUpdateManager, &impl::abi_t<llm:OS::Management::Update::IWindowsUpdateManager>::remove_ScanCompleted>;
        [[nodiscard]] ScanCompleted_revoker ScanCompleted(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Management::Update::WindowsUpdateManager, llm:OS::Management::Update::WindowsUpdateScanCompletedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ScanCompleted(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsScanning() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsWorking() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::IReference<llm:OS::Foundation::DateTime>) LastSuccessfulScanTimestamp() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Management::Update::WindowsUpdate>) GetApplicableUpdates() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Management::Update::WindowsUpdateItem>) GetMostRecentCompletedUpdates(int32_t count) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Management::Update::WindowsUpdateItem>>) GetMostRecentCompletedUpdatesAsync(int32_t count) const;
        LLM_IMPL_AUTO(void) StartScan(bool userInitiated) const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateManager>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateManager<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateManagerFactory
    {
        LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateManager) CreateInstance(param::hstring const& clientId) const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateManagerFactory>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateManagerFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateProgressChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdate) Update() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateActionProgress) ActionProgress() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateProgressChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateProgressChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Uri) MoreInfoUrl() const;
        LLM_IMPL_AUTO(void) MoreInfoUrl(llm:OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ComplianceDeadlineInDays() const;
        LLM_IMPL_AUTO(void) ComplianceDeadlineInDays(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ComplianceGracePeriodInDays() const;
        LLM_IMPL_AUTO(void) ComplianceGracePeriodInDays(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OrganizationName() const;
        LLM_IMPL_AUTO(void) OrganizationName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) OptOutOfAutoReboot() const;
        LLM_IMPL_AUTO(void) OptOutOfAutoReboot(bool value) const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptions>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptionsFactory
    {
        LLM_IMPL_AUTO(llm:OS::Management::Update::WindowsUpdateRestartRequestOptions) CreateInstance(param::hstring const& title, param::hstring const& description, llm:OS::Foundation::Uri const& moreInfoUrl, int32_t complianceDeadlineInDays, int32_t complianceGracePeriodInDays) const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptionsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProviderId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Management::Update::WindowsUpdate>) Updates() const;
    };
    template <> struct consume<llm:OS::Management::Update::IWindowsUpdateScanCompletedEventArgs>
    {
        template <typename D> using type = consume_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs<D>;
    };
}
#endif
