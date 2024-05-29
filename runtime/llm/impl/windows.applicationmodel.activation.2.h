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
#ifndef LLM_OS_ApplicationModel_Activation_2_H
#define LLM_OS_ApplicationModel_Activation_2_H
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Activation
{
    struct __declspec(empty_bases) AppointmentsProviderAddAppointmentActivatedEventArgs : llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs,
        impl::require<AppointmentsProviderAddAppointmentActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        AppointmentsProviderAddAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
        AppointmentsProviderAddAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentsProviderRemoveAppointmentActivatedEventArgs : llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs,
        impl::require<AppointmentsProviderRemoveAppointmentActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        AppointmentsProviderRemoveAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
        AppointmentsProviderRemoveAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentsProviderReplaceAppointmentActivatedEventArgs : llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs,
        impl::require<AppointmentsProviderReplaceAppointmentActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        AppointmentsProviderReplaceAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
        AppointmentsProviderReplaceAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentsProviderShowAppointmentDetailsActivatedEventArgs : llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
        impl::require<AppointmentsProviderShowAppointmentDetailsActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        AppointmentsProviderShowAppointmentDetailsActivatedEventArgs(std::nullptr_t) noexcept {}
        AppointmentsProviderShowAppointmentDetailsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentsProviderShowTimeFrameActivatedEventArgs : llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs,
        impl::require<AppointmentsProviderShowTimeFrameActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        AppointmentsProviderShowTimeFrameActivatedEventArgs(std::nullptr_t) noexcept {}
        AppointmentsProviderShowTimeFrameActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundActivatedEventArgs : llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs
    {
        BackgroundActivatedEventArgs(std::nullptr_t) noexcept {}
        BackgroundActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerPreviewActivatedEventArgs : llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs,
        impl::require<BarcodeScannerPreviewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        BarcodeScannerPreviewActivatedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerPreviewActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CachedFileUpdaterActivatedEventArgs : llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs,
        impl::require<CachedFileUpdaterActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        CachedFileUpdaterActivatedEventArgs(std::nullptr_t) noexcept {}
        CachedFileUpdaterActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CameraSettingsActivatedEventArgs : llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs
    {
        CameraSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
        CameraSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CommandLineActivatedEventArgs : llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs,
        impl::require<CommandLineActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        CommandLineActivatedEventArgs(std::nullptr_t) noexcept {}
        CommandLineActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CommandLineActivationOperation : llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation
    {
        CommandLineActivationOperation(std::nullptr_t) noexcept {}
        CommandLineActivationOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactCallActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs
    {
        ContactCallActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactMapActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs
    {
        ContactMapActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactMapActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactMessageActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs
    {
        ContactMessageActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactMessageActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPanelActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs,
        impl::require<ContactPanelActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        ContactPanelActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactPanelActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPickerActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs
    {
        ContactPickerActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactPickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPostActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs
    {
        ContactPostActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactPostActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactVideoCallActivatedEventArgs : llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs
    {
        ContactVideoCallActivatedEventArgs(std::nullptr_t) noexcept {}
        ContactVideoCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeviceActivatedEventArgs : llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs,
        impl::require<DeviceActivatedEventArgs, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        DeviceActivatedEventArgs(std::nullptr_t) noexcept {}
        DeviceActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DevicePairingActivatedEventArgs : llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs,
        impl::require<DevicePairingActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        DevicePairingActivatedEventArgs(std::nullptr_t) noexcept {}
        DevicePairingActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DialReceiverActivatedEventArgs : llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs,
        impl::require<DialReceiverActivatedEventArgs, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        DialReceiverActivatedEventArgs(std::nullptr_t) noexcept {}
        DialReceiverActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileActivatedEventArgs : llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs,
        impl::require<FileActivatedEventArgs, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        FileActivatedEventArgs(std::nullptr_t) noexcept {}
        FileActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileOpenPickerActivatedEventArgs : llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs,
        impl::require<FileOpenPickerActivatedEventArgs, llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        FileOpenPickerActivatedEventArgs(std::nullptr_t) noexcept {}
        FileOpenPickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileOpenPickerContinuationEventArgs : llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs,
        impl::require<FileOpenPickerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        FileOpenPickerContinuationEventArgs(std::nullptr_t) noexcept {}
        FileOpenPickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileSavePickerActivatedEventArgs : llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs,
        impl::require<FileSavePickerActivatedEventArgs, llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        FileSavePickerActivatedEventArgs(std::nullptr_t) noexcept {}
        FileSavePickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FileSavePickerContinuationEventArgs : llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs,
        impl::require<FileSavePickerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        FileSavePickerContinuationEventArgs(std::nullptr_t) noexcept {}
        FileSavePickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FolderPickerContinuationEventArgs : llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs,
        impl::require<FolderPickerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        FolderPickerContinuationEventArgs(std::nullptr_t) noexcept {}
        FolderPickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LaunchActivatedEventArgs : llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs,
        impl::require<LaunchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        LaunchActivatedEventArgs(std::nullptr_t) noexcept {}
        LaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenActivatedEventArgs : llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs,
        impl::require<LockScreenActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        LockScreenActivatedEventArgs(std::nullptr_t) noexcept {}
        LockScreenActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenCallActivatedEventArgs : llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs,
        impl::require<LockScreenCallActivatedEventArgs, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider>
    {
        LockScreenCallActivatedEventArgs(std::nullptr_t) noexcept {}
        LockScreenCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenComponentActivatedEventArgs : llm::OS::ApplicationModel::Activation::IActivatedEventArgs
    {
        LockScreenComponentActivatedEventArgs(std::nullptr_t) noexcept {}
        LockScreenComponentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneCallActivatedEventArgs : llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs,
        impl::require<PhoneCallActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        PhoneCallActivatedEventArgs(std::nullptr_t) noexcept {}
        PhoneCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PickerReturnedActivatedEventArgs : llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs
    {
        PickerReturnedActivatedEventArgs(std::nullptr_t) noexcept {}
        PickerReturnedActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Print3DWorkflowActivatedEventArgs : llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs
    {
        Print3DWorkflowActivatedEventArgs(std::nullptr_t) noexcept {}
        Print3DWorkflowActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskSettingsActivatedEventArgs : llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs
    {
        PrintTaskSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
        PrintTaskSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtocolActivatedEventArgs : llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs,
        impl::require<ProtocolActivatedEventArgs, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        ProtocolActivatedEventArgs(std::nullptr_t) noexcept {}
        ProtocolActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProtocolForResultsActivatedEventArgs : llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs,
        impl::require<ProtocolForResultsActivatedEventArgs, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        ProtocolForResultsActivatedEventArgs(std::nullptr_t) noexcept {}
        ProtocolForResultsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RestrictedLaunchActivatedEventArgs : llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs,
        impl::require<RestrictedLaunchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        RestrictedLaunchActivatedEventArgs(std::nullptr_t) noexcept {}
        RestrictedLaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchActivatedEventArgs : llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs,
        impl::require<SearchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        SearchActivatedEventArgs(std::nullptr_t) noexcept {}
        SearchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareTargetActivatedEventArgs : llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs,
        impl::require<ShareTargetActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        ShareTargetActivatedEventArgs(std::nullptr_t) noexcept {}
        ShareTargetActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SplashScreen : llm::OS::ApplicationModel::Activation::ISplashScreen
    {
        SplashScreen(std::nullptr_t) noexcept {}
        SplashScreen(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ISplashScreen(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StartupTaskActivatedEventArgs : llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs,
        impl::require<StartupTaskActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        StartupTaskActivatedEventArgs(std::nullptr_t) noexcept {}
        StartupTaskActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TileActivatedInfo : llm::OS::ApplicationModel::Activation::ITileActivatedInfo
    {
        TileActivatedInfo(std::nullptr_t) noexcept {}
        TileActivatedInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::ITileActivatedInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ToastNotificationActivatedEventArgs : llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs,
        impl::require<ToastNotificationActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>
    {
        ToastNotificationActivatedEventArgs(std::nullptr_t) noexcept {}
        ToastNotificationActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserDataAccountProviderActivatedEventArgs : llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs
    {
        UserDataAccountProviderActivatedEventArgs(std::nullptr_t) noexcept {}
        UserDataAccountProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoiceCommandActivatedEventArgs : llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs,
        impl::require<VoiceCommandActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        VoiceCommandActivatedEventArgs(std::nullptr_t) noexcept {}
        VoiceCommandActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WalletActionActivatedEventArgs : llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs
    {
        WalletActionActivatedEventArgs(std::nullptr_t) noexcept {}
        WalletActionActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderActivatedEventArgs : llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs,
        impl::require<WebAccountProviderActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebAccountProviderActivatedEventArgs(std::nullptr_t) noexcept {}
        WebAccountProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAuthenticationBrokerContinuationEventArgs : llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs
    {
        WebAuthenticationBrokerContinuationEventArgs(std::nullptr_t) noexcept {}
        WebAuthenticationBrokerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
