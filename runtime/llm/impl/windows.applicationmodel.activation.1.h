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
#ifndef LLM_OS_ApplicationModel_Activation_1_H
#define LLM_OS_ApplicationModel_Activation_1_H
#include "llm/impl/Windows.ApplicationModel.Activation.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Activation
{
    struct __declspec(empty_bases) IActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IActivatedEventArgs>
    {
        IActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActivatedEventArgsWithUser :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IActivatedEventArgsWithUser>,
        impl::require<llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IActivatedEventArgsWithUser(std::nullptr_t = nullptr) noexcept {}
        IActivatedEventArgsWithUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IApplicationViewActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentsProviderActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentsProviderActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IAppointmentsProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentsProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentsProviderAddAppointmentActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentsProviderAddAppointmentActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
    {
        IAppointmentsProviderAddAppointmentActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentsProviderAddAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentsProviderRemoveAppointmentActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentsProviderRemoveAppointmentActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
    {
        IAppointmentsProviderRemoveAppointmentActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentsProviderRemoveAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentsProviderReplaceAppointmentActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentsProviderReplaceAppointmentActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
    {
        IAppointmentsProviderReplaceAppointmentActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentsProviderReplaceAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
    {
        IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentsProviderShowTimeFrameActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentsProviderShowTimeFrameActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
    {
        IAppointmentsProviderShowTimeFrameActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentsProviderShowTimeFrameActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackgroundActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBackgroundActivatedEventArgs>
    {
        IBackgroundActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBackgroundActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerPreviewActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerPreviewActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IBarcodeScannerPreviewActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerPreviewActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICachedFileUpdaterActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICachedFileUpdaterActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        ICachedFileUpdaterActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICachedFileUpdaterActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICameraSettingsActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICameraSettingsActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        ICameraSettingsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICameraSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommandLineActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommandLineActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        ICommandLineActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICommandLineActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommandLineActivationOperation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommandLineActivationOperation>
    {
        ICommandLineActivationOperation(std::nullptr_t = nullptr) noexcept {}
        ICommandLineActivationOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IContactActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactCallActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactCallActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs>
    {
        IContactCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactMapActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactMapActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs>
    {
        IContactMapActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactMapActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactMessageActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactMessageActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs>
    {
        IContactMessageActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactMessageActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPanelActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPanelActivatedEventArgs>
    {
        IContactPanelActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactPanelActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPickerActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPickerActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IContactPickerActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactPickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPostActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPostActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs>
    {
        IContactPostActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactPostActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactVideoCallActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactVideoCallActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs>
    {
        IContactVideoCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactVideoCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactsProviderActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactsProviderActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContactsProviderActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IContactsProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactsProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContinuationActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContinuationActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IContinuationActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContinuationActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDeviceActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDeviceActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IDeviceActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDeviceActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDevicePairingActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDevicePairingActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IDevicePairingActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDevicePairingActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDialReceiverActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDialReceiverActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs>
    {
        IDialReceiverActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDialReceiverActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IFileActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileActivatedEventArgsWithCallerPackageFamilyName :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileActivatedEventArgsWithCallerPackageFamilyName>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IFileActivatedEventArgsWithCallerPackageFamilyName(std::nullptr_t = nullptr) noexcept {}
        IFileActivatedEventArgsWithCallerPackageFamilyName(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileActivatedEventArgsWithNeighboringFiles :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileActivatedEventArgsWithNeighboringFiles>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs>
    {
        IFileActivatedEventArgsWithNeighboringFiles(std::nullptr_t = nullptr) noexcept {}
        IFileActivatedEventArgsWithNeighboringFiles(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPickerActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IFileOpenPickerActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPickerActivatedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerActivatedEventArgs2>
    {
        IFileOpenPickerActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerActivatedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileOpenPickerContinuationEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileOpenPickerContinuationEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs>
    {
        IFileOpenPickerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileOpenPickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePickerActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePickerActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IFileSavePickerActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileSavePickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePickerActivatedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePickerActivatedEventArgs2>
    {
        IFileSavePickerActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IFileSavePickerActivatedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFileSavePickerContinuationEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFileSavePickerContinuationEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs>
    {
        IFileSavePickerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFileSavePickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFolderPickerContinuationEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFolderPickerContinuationEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs>
    {
        IFolderPickerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
        IFolderPickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILaunchActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILaunchActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        ILaunchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILaunchActivatedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILaunchActivatedEventArgs2>,
        impl::require<llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs>
    {
        ILaunchActivatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        ILaunchActivatedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        ILockScreenActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILockScreenActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenCallActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenCallActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs>
    {
        ILockScreenCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILockScreenCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IPhoneCallActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPickerReturnedActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPickerReturnedActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IPickerReturnedActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPickerReturnedActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrelaunchActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrelaunchActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IPrelaunchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrelaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DWorkflowActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DWorkflowActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IPrint3DWorkflowActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DWorkflowActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskSettingsActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskSettingsActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IPrintTaskSettingsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtocolActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProtocolActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IProtocolActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IProtocolActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>,
        impl::require<llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData(std::nullptr_t = nullptr) noexcept {}
        IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtocolForResultsActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IProtocolForResultsActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IProtocolForResultsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IProtocolForResultsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRestrictedLaunchActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IRestrictedLaunchActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IRestrictedLaunchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRestrictedLaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        ISearchActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISearchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchActivatedEventArgsWithLinguisticDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchActivatedEventArgsWithLinguisticDetails>
    {
        ISearchActivatedEventArgsWithLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
        ISearchActivatedEventArgsWithLinguisticDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareTargetActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareTargetActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IShareTargetActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IShareTargetActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISplashScreen :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISplashScreen>
    {
        ISplashScreen(std::nullptr_t = nullptr) noexcept {}
        ISplashScreen(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStartupTaskActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStartupTaskActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IStartupTaskActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IStartupTaskActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileActivatedInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITileActivatedInfo>
    {
        ITileActivatedInfo(std::nullptr_t = nullptr) noexcept {}
        ITileActivatedInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IToastNotificationActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IToastNotificationActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IToastNotificationActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IToastNotificationActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataAccountProviderActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAccountProviderActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IUserDataAccountProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataAccountProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IViewSwitcherProvider :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IViewSwitcherProvider>,
        impl::require<llm::OS::ApplicationModel::Activation::IViewSwitcherProvider, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IViewSwitcherProvider(std::nullptr_t = nullptr) noexcept {}
        IViewSwitcherProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IVoiceCommandActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWalletActionActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWalletActionActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IWalletActionActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWalletActionActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderActivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderActivatedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IWebAccountProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAuthenticationBrokerContinuationEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebAuthenticationBrokerContinuationEventArgs>,
        impl::require<llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs, llm::OS::ApplicationModel::Activation::IActivatedEventArgs, llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs>
    {
        IWebAuthenticationBrokerContinuationEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebAuthenticationBrokerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
