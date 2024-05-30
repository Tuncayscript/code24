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
#ifndef LLM_OS_UI_WebUI_0_H
#define LLM_OS_UI_WebUI_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel
{
    struct IEnteredBackgroundEventArgs;
    struct ILeavingBackgroundEventArgs;
    struct ISuspendingDeferral;
    struct ISuspendingEventArgs;
    struct ISuspendingOperation;
}
LLM_EXPORT namespace llm:OS::ApplicationModel::Activation
{
    struct IActivatedEventArgs;
    struct IAppointmentsProviderAddAppointmentActivatedEventArgs;
    struct IAppointmentsProviderRemoveAppointmentActivatedEventArgs;
    struct IAppointmentsProviderReplaceAppointmentActivatedEventArgs;
    struct IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
    struct IAppointmentsProviderShowTimeFrameActivatedEventArgs;
    struct IBackgroundActivatedEventArgs;
    struct IBarcodeScannerPreviewActivatedEventArgs;
    struct ICachedFileUpdaterActivatedEventArgs;
    struct ICameraSettingsActivatedEventArgs;
    struct ICommandLineActivatedEventArgs;
    struct IContactCallActivatedEventArgs;
    struct IContactMapActivatedEventArgs;
    struct IContactMessageActivatedEventArgs;
    struct IContactPanelActivatedEventArgs;
    struct IContactPickerActivatedEventArgs;
    struct IContactPostActivatedEventArgs;
    struct IContactVideoCallActivatedEventArgs;
    struct IDeviceActivatedEventArgs;
    struct IDevicePairingActivatedEventArgs;
    struct IDialReceiverActivatedEventArgs;
    struct IFileActivatedEventArgs;
    struct IFileOpenPickerActivatedEventArgs;
    struct IFileOpenPickerContinuationEventArgs;
    struct IFileSavePickerActivatedEventArgs;
    struct IFileSavePickerContinuationEventArgs;
    struct IFolderPickerContinuationEventArgs;
    struct ILaunchActivatedEventArgs;
    struct ILockScreenActivatedEventArgs;
    struct ILockScreenCallActivatedEventArgs;
    struct IPhoneCallActivatedEventArgs;
    struct IPrint3DWorkflowActivatedEventArgs;
    struct IPrintTaskSettingsActivatedEventArgs;
    struct IProtocolActivatedEventArgs;
    struct IProtocolForResultsActivatedEventArgs;
    struct IRestrictedLaunchActivatedEventArgs;
    struct ISearchActivatedEventArgs;
    struct IShareTargetActivatedEventArgs;
    struct IStartupTaskActivatedEventArgs;
    struct IToastNotificationActivatedEventArgs;
    struct IUserDataAccountProviderActivatedEventArgs;
    struct IVoiceCommandActivatedEventArgs;
    struct IWalletActionActivatedEventArgs;
    struct IWebAccountProviderActivatedEventArgs;
    struct IWebAuthenticationBrokerContinuationEventArgs;
}
LLM_EXPORT namespace llm:OS::ApplicationModel::Core
{
    enum class AppRestartFailureReason : int32_t;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm:OS::System
{
    struct User;
}
LLM_EXPORT namespace llm:OS::UI::WebUI
{
    enum class PrintContent : int32_t
    {
        AllPages = 0,
        CurrentPage = 1,
        CustomPageRange = 2,
        CurrentSelection = 3,
    };
    struct IActivatedDeferral;
    struct IActivatedEventArgsDeferral;
    struct IActivatedOperation;
    struct IHtmlPrintDocumentSource;
    struct INewWebUIViewCreatedEventArgs;
    struct IWebUIActivationStatics;
    struct IWebUIActivationStatics2;
    struct IWebUIActivationStatics3;
    struct IWebUIActivationStatics4;
    struct IWebUIBackgroundTaskInstance;
    struct IWebUIBackgroundTaskInstanceStatics;
    struct IWebUINavigatedDeferral;
    struct IWebUINavigatedEventArgs;
    struct IWebUINavigatedOperation;
    struct IWebUIView;
    struct IWebUIViewStatics;
    struct ActivatedDeferral;
    struct ActivatedOperation;
    struct BackgroundActivatedEventArgs;
    struct EnteredBackgroundEventArgs;
    struct HtmlPrintDocumentSource;
    struct LeavingBackgroundEventArgs;
    struct NewWebUIViewCreatedEventArgs;
    struct SuspendingDeferral;
    struct SuspendingEventArgs;
    struct SuspendingOperation;
    struct WebUIApplication;
    struct WebUIAppointmentsProviderAddAppointmentActivatedEventArgs;
    struct WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs;
    struct WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs;
    struct WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs;
    struct WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs;
    struct WebUIBackgroundTaskInstance;
    struct WebUIBackgroundTaskInstanceRuntimeClass;
    struct WebUIBarcodeScannerPreviewActivatedEventArgs;
    struct WebUICachedFileUpdaterActivatedEventArgs;
    struct WebUICameraSettingsActivatedEventArgs;
    struct WebUICommandLineActivatedEventArgs;
    struct WebUIContactCallActivatedEventArgs;
    struct WebUIContactMapActivatedEventArgs;
    struct WebUIContactMessageActivatedEventArgs;
    struct WebUIContactPanelActivatedEventArgs;
    struct WebUIContactPickerActivatedEventArgs;
    struct WebUIContactPostActivatedEventArgs;
    struct WebUIContactVideoCallActivatedEventArgs;
    struct WebUIDeviceActivatedEventArgs;
    struct WebUIDevicePairingActivatedEventArgs;
    struct WebUIDialReceiverActivatedEventArgs;
    struct WebUIFileActivatedEventArgs;
    struct WebUIFileOpenPickerActivatedEventArgs;
    struct WebUIFileOpenPickerContinuationEventArgs;
    struct WebUIFileSavePickerActivatedEventArgs;
    struct WebUIFileSavePickerContinuationEventArgs;
    struct WebUIFolderPickerContinuationEventArgs;
    struct WebUILaunchActivatedEventArgs;
    struct WebUILockScreenActivatedEventArgs;
    struct WebUILockScreenCallActivatedEventArgs;
    struct WebUILockScreenComponentActivatedEventArgs;
    struct WebUINavigatedDeferral;
    struct WebUINavigatedEventArgs;
    struct WebUINavigatedOperation;
    struct WebUIPhoneCallActivatedEventArgs;
    struct WebUIPrint3DWorkflowActivatedEventArgs;
    struct WebUIPrintTaskSettingsActivatedEventArgs;
    struct WebUIPrintWorkflowForegroundTaskActivatedEventArgs;
    struct WebUIProtocolActivatedEventArgs;
    struct WebUIProtocolForResultsActivatedEventArgs;
    struct WebUIRestrictedLaunchActivatedEventArgs;
    struct WebUISearchActivatedEventArgs;
    struct WebUIShareTargetActivatedEventArgs;
    struct WebUIStartupTaskActivatedEventArgs;
    struct WebUIToastNotificationActivatedEventArgs;
    struct WebUIUserDataAccountProviderActivatedEventArgs;
    struct WebUIView;
    struct WebUIVoiceCommandActivatedEventArgs;
    struct WebUIWalletActionActivatedEventArgs;
    struct WebUIWebAccountProviderActivatedEventArgs;
    struct WebUIWebAuthenticationBrokerContinuationEventArgs;
    struct ActivatedEventHandler;
    struct BackgroundActivatedEventHandler;
    struct EnteredBackgroundEventHandler;
    struct LeavingBackgroundEventHandler;
    struct NavigatedEventHandler;
    struct ResumingEventHandler;
    struct SuspendingEventHandler;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::WebUI::IActivatedDeferral>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IActivatedEventArgsDeferral>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IActivatedOperation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IHtmlPrintDocumentSource>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIActivationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIActivationStatics2>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIActivationStatics3>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIActivationStatics4>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUINavigatedDeferral>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUINavigatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUINavigatedOperation>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIView>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::IWebUIViewStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::WebUI::ActivatedDeferral>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::ActivatedOperation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::BackgroundActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::EnteredBackgroundEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::HtmlPrintDocumentSource>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::LeavingBackgroundEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::SuspendingDeferral>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::SuspendingEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::SuspendingOperation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIApplication>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIBackgroundTaskInstance>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIBarcodeScannerPreviewActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUICameraSettingsActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUICommandLineActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactCallActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactMapActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactMessageActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactPanelActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactPickerActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactPostActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIContactVideoCallActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIDeviceActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIDevicePairingActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIDialReceiverActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIFileActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIFileSavePickerActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIFileSavePickerContinuationEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIFolderPickerContinuationEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUILaunchActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUILockScreenActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUILockScreenCallActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUILockScreenComponentActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUINavigatedDeferral>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUINavigatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUINavigatedOperation>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIPhoneCallActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIPrint3DWorkflowActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIPrintTaskSettingsActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIPrintWorkflowForegroundTaskActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIProtocolActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUISearchActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIShareTargetActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIStartupTaskActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIToastNotificationActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIView>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIVoiceCommandActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIWalletActionActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::UI::WebUI::PrintContent>{ using type = enum_category; };
    template <> struct category<llm:OS::UI::WebUI::ActivatedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::UI::WebUI::BackgroundActivatedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::UI::WebUI::EnteredBackgroundEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::UI::WebUI::LeavingBackgroundEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::UI::WebUI::NavigatedEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::UI::WebUI::ResumingEventHandler>{ using type = delegate_category; };
    template <> struct category<llm:OS::UI::WebUI::SuspendingEventHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::ActivatedDeferral> = L"Windows.UI.WebUI.ActivatedDeferral";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::ActivatedOperation> = L"Windows.UI.WebUI.ActivatedOperation";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::BackgroundActivatedEventArgs> = L"Windows.UI.WebUI.BackgroundActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::EnteredBackgroundEventArgs> = L"Windows.UI.WebUI.EnteredBackgroundEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::HtmlPrintDocumentSource> = L"Windows.UI.WebUI.HtmlPrintDocumentSource";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::LeavingBackgroundEventArgs> = L"Windows.UI.WebUI.LeavingBackgroundEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs> = L"Windows.UI.WebUI.NewWebUIViewCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::SuspendingDeferral> = L"Windows.UI.WebUI.SuspendingDeferral";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::SuspendingEventArgs> = L"Windows.UI.WebUI.SuspendingEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::SuspendingOperation> = L"Windows.UI.WebUI.SuspendingOperation";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIApplication> = L"Windows.UI.WebUI.WebUIApplication";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs> = L"Windows.UI.WebUI.WebUIAppointmentsProviderAddAppointmentActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs> = L"Windows.UI.WebUI.WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs> = L"Windows.UI.WebUI.WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> = L"Windows.UI.WebUI.WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs> = L"Windows.UI.WebUI.WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIBackgroundTaskInstance> = L"Windows.UI.WebUI.WebUIBackgroundTaskInstance";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass> = L"Windows.UI.WebUI.WebUIBackgroundTaskInstanceRuntimeClass";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIBarcodeScannerPreviewActivatedEventArgs> = L"Windows.UI.WebUI.WebUIBarcodeScannerPreviewActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs> = L"Windows.UI.WebUI.WebUICachedFileUpdaterActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUICameraSettingsActivatedEventArgs> = L"Windows.UI.WebUI.WebUICameraSettingsActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUICommandLineActivatedEventArgs> = L"Windows.UI.WebUI.WebUICommandLineActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactCallActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactCallActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactMapActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactMapActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactMessageActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactMessageActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactPanelActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactPanelActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactPickerActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactPickerActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactPostActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactPostActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIContactVideoCallActivatedEventArgs> = L"Windows.UI.WebUI.WebUIContactVideoCallActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIDeviceActivatedEventArgs> = L"Windows.UI.WebUI.WebUIDeviceActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIDevicePairingActivatedEventArgs> = L"Windows.UI.WebUI.WebUIDevicePairingActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIDialReceiverActivatedEventArgs> = L"Windows.UI.WebUI.WebUIDialReceiverActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIFileActivatedEventArgs> = L"Windows.UI.WebUI.WebUIFileActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs> = L"Windows.UI.WebUI.WebUIFileOpenPickerActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs> = L"Windows.UI.WebUI.WebUIFileOpenPickerContinuationEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIFileSavePickerActivatedEventArgs> = L"Windows.UI.WebUI.WebUIFileSavePickerActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIFileSavePickerContinuationEventArgs> = L"Windows.UI.WebUI.WebUIFileSavePickerContinuationEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIFolderPickerContinuationEventArgs> = L"Windows.UI.WebUI.WebUIFolderPickerContinuationEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUILaunchActivatedEventArgs> = L"Windows.UI.WebUI.WebUILaunchActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUILockScreenActivatedEventArgs> = L"Windows.UI.WebUI.WebUILockScreenActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUILockScreenCallActivatedEventArgs> = L"Windows.UI.WebUI.WebUILockScreenCallActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUILockScreenComponentActivatedEventArgs> = L"Windows.UI.WebUI.WebUILockScreenComponentActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUINavigatedDeferral> = L"Windows.UI.WebUI.WebUINavigatedDeferral";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUINavigatedEventArgs> = L"Windows.UI.WebUI.WebUINavigatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUINavigatedOperation> = L"Windows.UI.WebUI.WebUINavigatedOperation";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIPhoneCallActivatedEventArgs> = L"Windows.UI.WebUI.WebUIPhoneCallActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIPrint3DWorkflowActivatedEventArgs> = L"Windows.UI.WebUI.WebUIPrint3DWorkflowActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIPrintTaskSettingsActivatedEventArgs> = L"Windows.UI.WebUI.WebUIPrintTaskSettingsActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIPrintWorkflowForegroundTaskActivatedEventArgs> = L"Windows.UI.WebUI.WebUIPrintWorkflowForegroundTaskActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIProtocolActivatedEventArgs> = L"Windows.UI.WebUI.WebUIProtocolActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs> = L"Windows.UI.WebUI.WebUIProtocolForResultsActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs> = L"Windows.UI.WebUI.WebUIRestrictedLaunchActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUISearchActivatedEventArgs> = L"Windows.UI.WebUI.WebUISearchActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIShareTargetActivatedEventArgs> = L"Windows.UI.WebUI.WebUIShareTargetActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIStartupTaskActivatedEventArgs> = L"Windows.UI.WebUI.WebUIStartupTaskActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIToastNotificationActivatedEventArgs> = L"Windows.UI.WebUI.WebUIToastNotificationActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs> = L"Windows.UI.WebUI.WebUIUserDataAccountProviderActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIView> = L"Windows.UI.WebUI.WebUIView";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIVoiceCommandActivatedEventArgs> = L"Windows.UI.WebUI.WebUIVoiceCommandActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIWalletActionActivatedEventArgs> = L"Windows.UI.WebUI.WebUIWalletActionActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs> = L"Windows.UI.WebUI.WebUIWebAccountProviderActivatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs> = L"Windows.UI.WebUI.WebUIWebAuthenticationBrokerContinuationEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::PrintContent> = L"Windows.UI.WebUI.PrintContent";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IActivatedDeferral> = L"Windows.UI.WebUI.IActivatedDeferral";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IActivatedEventArgsDeferral> = L"Windows.UI.WebUI.IActivatedEventArgsDeferral";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IActivatedOperation> = L"Windows.UI.WebUI.IActivatedOperation";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IHtmlPrintDocumentSource> = L"Windows.UI.WebUI.IHtmlPrintDocumentSource";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs> = L"Windows.UI.WebUI.INewWebUIViewCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIActivationStatics> = L"Windows.UI.WebUI.IWebUIActivationStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIActivationStatics2> = L"Windows.UI.WebUI.IWebUIActivationStatics2";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIActivationStatics3> = L"Windows.UI.WebUI.IWebUIActivationStatics3";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIActivationStatics4> = L"Windows.UI.WebUI.IWebUIActivationStatics4";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance> = L"Windows.UI.WebUI.IWebUIBackgroundTaskInstance";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics> = L"Windows.UI.WebUI.IWebUIBackgroundTaskInstanceStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUINavigatedDeferral> = L"Windows.UI.WebUI.IWebUINavigatedDeferral";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUINavigatedEventArgs> = L"Windows.UI.WebUI.IWebUINavigatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUINavigatedOperation> = L"Windows.UI.WebUI.IWebUINavigatedOperation";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIView> = L"Windows.UI.WebUI.IWebUIView";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::IWebUIViewStatics> = L"Windows.UI.WebUI.IWebUIViewStatics";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::ActivatedEventHandler> = L"Windows.UI.WebUI.ActivatedEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::BackgroundActivatedEventHandler> = L"Windows.UI.WebUI.BackgroundActivatedEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::EnteredBackgroundEventHandler> = L"Windows.UI.WebUI.EnteredBackgroundEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::LeavingBackgroundEventHandler> = L"Windows.UI.WebUI.LeavingBackgroundEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::NavigatedEventHandler> = L"Windows.UI.WebUI.NavigatedEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::ResumingEventHandler> = L"Windows.UI.WebUI.ResumingEventHandler";
    template <> inline constexpr auto& name_v<llm:OS::UI::WebUI::SuspendingEventHandler> = L"Windows.UI.WebUI.SuspendingEventHandler";
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IActivatedDeferral>{ 0xC3BD1978,0xA431,0x49D8,{ 0xA7,0x6A,0x39,0x5A,0x4E,0x03,0xDC,0xF3 } }; // C3BD1978-A431-49D8-A76A-395A4E03DCF3
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IActivatedEventArgsDeferral>{ 0xCA6D5F74,0x63C2,0x44A6,{ 0xB9,0x7B,0xD9,0xA0,0x3C,0x20,0xBC,0x9B } }; // CA6D5F74-63C2-44A6-B97B-D9A03C20BC9B
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IActivatedOperation>{ 0xB6A0B4BC,0xC6CA,0x42FD,{ 0x98,0x18,0x71,0x90,0x4E,0x45,0xFE,0xD7 } }; // B6A0B4BC-C6CA-42FD-9818-71904E45FED7
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IHtmlPrintDocumentSource>{ 0xCEA6469A,0x0E05,0x467A,{ 0xAB,0xC9,0x36,0xEC,0x1D,0x4C,0xDC,0xB6 } }; // CEA6469A-0E05-467A-ABC9-36EC1D4CDCB6
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs>{ 0xE8E1B216,0xBE2B,0x4C9E,{ 0x85,0xE7,0x08,0x31,0x43,0xEC,0x4B,0xE7 } }; // E8E1B216-BE2B-4C9E-85E7-083143EC4BE7
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIActivationStatics>{ 0x351B86BD,0x43B3,0x482B,{ 0x85,0xDB,0x35,0xD8,0x7B,0x51,0x7A,0xD9 } }; // 351B86BD-43B3-482B-85DB-35D87B517AD9
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIActivationStatics2>{ 0xC8E88696,0x4D78,0x4AA4,{ 0x8F,0x06,0x2A,0x9E,0xAD,0xC6,0xC4,0x0A } }; // C8E88696-4D78-4AA4-8F06-2A9EADC6C40A
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIActivationStatics3>{ 0x91ABB686,0x1AF5,0x4445,{ 0xB4,0x9F,0x94,0x59,0xF4,0x0F,0xC8,0xDE } }; // 91ABB686-1AF5-4445-B49F-9459F40FC8DE
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIActivationStatics4>{ 0x5E391429,0x183F,0x478D,{ 0x8A,0x25,0x67,0xF8,0x0D,0x03,0x93,0x5B } }; // 5E391429-183F-478D-8A25-67F80D03935B
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance>{ 0x23F12C25,0xE2F7,0x4741,{ 0xBC,0x9C,0x39,0x45,0x95,0xDE,0x24,0xDC } }; // 23F12C25-E2F7-4741-BC9C-394595DE24DC
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics>{ 0x9C7A5291,0x19AE,0x4CA3,{ 0xB9,0x4B,0xFE,0x4E,0xC7,0x44,0xA7,0x40 } }; // 9C7A5291-19AE-4CA3-B94B-FE4EC744A740
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUINavigatedDeferral>{ 0xD804204D,0x831F,0x46E2,{ 0xB4,0x32,0x3A,0xFC,0xE2,0x11,0xF9,0x62 } }; // D804204D-831F-46E2-B432-3AFCE211F962
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUINavigatedEventArgs>{ 0xA75841B8,0x2499,0x4030,{ 0xA6,0x9D,0x15,0xD2,0xD9,0xCF,0xE5,0x24 } }; // A75841B8-2499-4030-A69D-15D2D9CFE524
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUINavigatedOperation>{ 0x7A965F08,0x8182,0x4A89,{ 0xAB,0x67,0x84,0x92,0xE8,0x75,0x0D,0x4B } }; // 7A965F08-8182-4A89-AB67-8492E8750D4B
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIView>{ 0x6783F64F,0x52DA,0x4FD7,{ 0xBE,0x69,0x8E,0xF6,0x28,0x4B,0x42,0x3C } }; // 6783F64F-52DA-4FD7-BE69-8EF6284B423C
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::IWebUIViewStatics>{ 0xB591E668,0x8E59,0x44F9,{ 0x88,0x03,0x1B,0x24,0xC9,0x14,0x9D,0x30 } }; // B591E668-8E59-44F9-8803-1B24C9149D30
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::ActivatedEventHandler>{ 0x50F1E730,0xC5D1,0x4B6B,{ 0x9A,0xDB,0x8A,0x11,0x75,0x6B,0xE2,0x9C } }; // 50F1E730-C5D1-4B6B-9ADB-8A11756BE29C
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::BackgroundActivatedEventHandler>{ 0xEDB19FBB,0x0761,0x47CC,{ 0x9A,0x77,0x24,0xD7,0x07,0x29,0x65,0xCA } }; // EDB19FBB-0761-47CC-9A77-24D7072965CA
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::EnteredBackgroundEventHandler>{ 0x2B09A173,0xB68E,0x4DEF,{ 0x88,0xC1,0x8D,0xE8,0x4E,0x5A,0xAB,0x2F } }; // 2B09A173-B68E-4DEF-88C1-8DE84E5AAB2F
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::LeavingBackgroundEventHandler>{ 0x00B4CCD9,0x7A9C,0x4B6B,{ 0x9A,0xC4,0x13,0x47,0x4F,0x26,0x8B,0xC4 } }; // 00B4CCD9-7A9C-4B6B-9AC4-13474F268BC4
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::NavigatedEventHandler>{ 0x7AF46FE6,0x40CA,0x4E49,{ 0xA7,0xD6,0xDB,0xDB,0x33,0x0C,0xD1,0xA3 } }; // 7AF46FE6-40CA-4E49-A7D6-DBDB330CD1A3
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::ResumingEventHandler>{ 0x26599BA9,0xA22D,0x4806,{ 0xA7,0x28,0xAC,0xAD,0xC1,0xD0,0x75,0xFA } }; // 26599BA9-A22D-4806-A728-ACADC1D075FA
    template <> inline constexpr guid guid_v<llm:OS::UI::WebUI::SuspendingEventHandler>{ 0x509C429C,0x78E2,0x4883,{ 0xAB,0xC8,0x89,0x60,0xDC,0xDE,0x1B,0x5C } }; // 509C429C-78E2-4883-ABC8-8960DCDE1B5C
    template <> struct default_interface<llm:OS::UI::WebUI::ActivatedDeferral>{ using type = llm:OS::UI::WebUI::IActivatedDeferral; };
    template <> struct default_interface<llm:OS::UI::WebUI::ActivatedOperation>{ using type = llm:OS::UI::WebUI::IActivatedOperation; };
    template <> struct default_interface<llm:OS::UI::WebUI::BackgroundActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::EnteredBackgroundEventArgs>{ using type = llm:OS::ApplicationModel::IEnteredBackgroundEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::HtmlPrintDocumentSource>{ using type = llm:OS::UI::WebUI::IHtmlPrintDocumentSource; };
    template <> struct default_interface<llm:OS::UI::WebUI::LeavingBackgroundEventArgs>{ using type = llm:OS::ApplicationModel::ILeavingBackgroundEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs>{ using type = llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::SuspendingDeferral>{ using type = llm:OS::ApplicationModel::ISuspendingDeferral; };
    template <> struct default_interface<llm:OS::UI::WebUI::SuspendingEventArgs>{ using type = llm:OS::ApplicationModel::ISuspendingEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::SuspendingOperation>{ using type = llm:OS::ApplicationModel::ISuspendingOperation; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass>{ using type = llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIBarcodeScannerPreviewActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUICameraSettingsActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUICommandLineActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactCallActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactCallActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactMapActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactMapActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactMessageActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactPanelActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactPickerActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactPostActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactPostActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIContactVideoCallActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIDeviceActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IDeviceActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIDevicePairingActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIDialReceiverActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIFileActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IFileActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIFileSavePickerActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIFileSavePickerContinuationEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIFolderPickerContinuationEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUILaunchActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ILaunchActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUILockScreenActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUILockScreenCallActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUILockScreenComponentActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUINavigatedDeferral>{ using type = llm:OS::UI::WebUI::IWebUINavigatedDeferral; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUINavigatedEventArgs>{ using type = llm:OS::UI::WebUI::IWebUINavigatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUINavigatedOperation>{ using type = llm:OS::UI::WebUI::IWebUINavigatedOperation; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIPhoneCallActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIPrint3DWorkflowActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIPrintTaskSettingsActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIPrintWorkflowForegroundTaskActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIProtocolActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IProtocolActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUISearchActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::ISearchActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIShareTargetActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIStartupTaskActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIToastNotificationActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIView>{ using type = llm:OS::UI::WebUI::IWebUIView; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIVoiceCommandActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIWalletActionActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs; };
    template <> struct default_interface<llm:OS::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs>{ using type = llm:OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs; };
    template <> struct abi<llm:OS::UI::WebUI::IActivatedDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivatedOperation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IActivatedOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IHtmlPrintDocumentSource>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Content(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Content(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_LeftMargin(float*) noexcept = 0;
            virtual int32_t __stdcall put_LeftMargin(float) noexcept = 0;
            virtual int32_t __stdcall get_TopMargin(float*) noexcept = 0;
            virtual int32_t __stdcall put_TopMargin(float) noexcept = 0;
            virtual int32_t __stdcall get_RightMargin(float*) noexcept = 0;
            virtual int32_t __stdcall put_RightMargin(float) noexcept = 0;
            virtual int32_t __stdcall get_BottomMargin(float*) noexcept = 0;
            virtual int32_t __stdcall put_BottomMargin(float) noexcept = 0;
            virtual int32_t __stdcall get_EnableHeaderFooter(bool*) noexcept = 0;
            virtual int32_t __stdcall put_EnableHeaderFooter(bool) noexcept = 0;
            virtual int32_t __stdcall get_ShrinkToFit(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ShrinkToFit(bool) noexcept = 0;
            virtual int32_t __stdcall get_PercentScale(float*) noexcept = 0;
            virtual int32_t __stdcall put_PercentScale(float) noexcept = 0;
            virtual int32_t __stdcall get_PageRange(void**) noexcept = 0;
            virtual int32_t __stdcall TrySetPageRange(void*, bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_WebUIView(void**) noexcept = 0;
            virtual int32_t __stdcall get_ActivatedEventArgs(void**) noexcept = 0;
            virtual int32_t __stdcall get_HasPendingNavigate(bool*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIActivationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_Activated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Activated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Suspending(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Suspending(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Resuming(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Resuming(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Navigated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Navigated(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIActivationStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_LeavingBackground(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LeavingBackground(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnteredBackground(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnteredBackground(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall EnablePrelaunch(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIActivationStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestRestartAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestRestartForUserAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIActivationStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_NewWebUIViewCreated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_NewWebUIViewCreated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_BackgroundActivated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_BackgroundActivated(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Succeeded(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Succeeded(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Current(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUINavigatedDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUINavigatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_NavigatedOperation(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUINavigatedOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIView>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ApplicationViewId(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_Closed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Activated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Activated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_IgnoreApplicationContentUriRulesNavigationRestrictions(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IgnoreApplicationContentUriRulesNavigationRestrictions(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::IWebUIViewStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithUriAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::ActivatedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::BackgroundActivatedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::EnteredBackgroundEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::LeavingBackgroundEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::NavigatedEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::ResumingEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::WebUI::SuspendingEventHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IActivatedDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IActivatedDeferral>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IActivatedDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IActivatedEventArgsDeferral
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::WebUI::ActivatedOperation) ActivatedOperation() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IActivatedEventArgsDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IActivatedOperation
    {
        LLM_IMPL_AUTO(llm:OS::UI::WebUI::ActivatedDeferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IActivatedOperation>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IActivatedOperation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IHtmlPrintDocumentSource
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::WebUI::PrintContent) Content() const;
        LLM_IMPL_AUTO(void) Content(llm:OS::UI::WebUI::PrintContent const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) LeftMargin() const;
        LLM_IMPL_AUTO(void) LeftMargin(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) TopMargin() const;
        LLM_IMPL_AUTO(void) TopMargin(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) RightMargin() const;
        LLM_IMPL_AUTO(void) RightMargin(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) BottomMargin() const;
        LLM_IMPL_AUTO(void) BottomMargin(float value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) EnableHeaderFooter() const;
        LLM_IMPL_AUTO(void) EnableHeaderFooter(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ShrinkToFit() const;
        LLM_IMPL_AUTO(void) ShrinkToFit(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(float) PercentScale() const;
        LLM_IMPL_AUTO(void) PercentScale(float scalePercent) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PageRange() const;
        LLM_IMPL_AUTO(bool) TrySetPageRange(param::hstring const& strPageRange) const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IHtmlPrintDocumentSource>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_INewWebUIViewCreatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::WebUI::WebUIView) WebUIView() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::ApplicationModel::Activation::IActivatedEventArgs) ActivatedEventArgs() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasPendingNavigate() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_INewWebUIViewCreatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIActivationStatics
    {
        LLM_IMPL_AUTO(llm::event_token) Activated(llm:OS::UI::WebUI::ActivatedEventHandler const& handler) const;
        using Activated_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Activated>;
        [[nodiscard]] Activated_revoker Activated(auto_revoke_t, llm:OS::UI::WebUI::ActivatedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Activated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Suspending(llm:OS::UI::WebUI::SuspendingEventHandler const& handler) const;
        using Suspending_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Suspending>;
        [[nodiscard]] Suspending_revoker Suspending(auto_revoke_t, llm:OS::UI::WebUI::SuspendingEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Suspending(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Resuming(llm:OS::UI::WebUI::ResumingEventHandler const& handler) const;
        using Resuming_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Resuming>;
        [[nodiscard]] Resuming_revoker Resuming(auto_revoke_t, llm:OS::UI::WebUI::ResumingEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Resuming(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Navigated(llm:OS::UI::WebUI::NavigatedEventHandler const& handler) const;
        using Navigated_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Navigated>;
        [[nodiscard]] Navigated_revoker Navigated(auto_revoke_t, llm:OS::UI::WebUI::NavigatedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) Navigated(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIActivationStatics>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIActivationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIActivationStatics2
    {
        LLM_IMPL_AUTO(llm::event_token) LeavingBackground(llm:OS::UI::WebUI::LeavingBackgroundEventHandler const& handler) const;
        using LeavingBackground_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics2, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics2>::remove_LeavingBackground>;
        [[nodiscard]] LeavingBackground_revoker LeavingBackground(auto_revoke_t, llm:OS::UI::WebUI::LeavingBackgroundEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) LeavingBackground(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnteredBackground(llm:OS::UI::WebUI::EnteredBackgroundEventHandler const& handler) const;
        using EnteredBackground_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics2, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics2>::remove_EnteredBackground>;
        [[nodiscard]] EnteredBackground_revoker EnteredBackground(auto_revoke_t, llm:OS::UI::WebUI::EnteredBackgroundEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) EnteredBackground(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) EnablePrelaunch(bool value) const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIActivationStatics2>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIActivationStatics3
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::ApplicationModel::Core::AppRestartFailureReason>) RequestRestartAsync(param::hstring const& launchArguments) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::ApplicationModel::Core::AppRestartFailureReason>) RequestRestartForUserAsync(llm:OS::System::User const& user, param::hstring const& launchArguments) const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIActivationStatics3>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIActivationStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIActivationStatics4
    {
        LLM_IMPL_AUTO(llm::event_token) NewWebUIViewCreated(llm:OS::Foundation::EventHandler<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler) const;
        using NewWebUIViewCreated_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics4, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics4>::remove_NewWebUIViewCreated>;
        [[nodiscard]] NewWebUIViewCreated_revoker NewWebUIViewCreated(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) NewWebUIViewCreated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) BackgroundActivated(llm:OS::UI::WebUI::BackgroundActivatedEventHandler const& handler) const;
        using BackgroundActivated_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics4, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics4>::remove_BackgroundActivated>;
        [[nodiscard]] BackgroundActivated_revoker BackgroundActivated(auto_revoke_t, llm:OS::UI::WebUI::BackgroundActivatedEventHandler const& handler) const;
        LLM_IMPL_AUTO(void) BackgroundActivated(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIActivationStatics4>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstance
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Succeeded() const;
        LLM_IMPL_AUTO(void) Succeeded(bool succeeded) const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstance<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstanceStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance) Current() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstanceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUINavigatedDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUINavigatedDeferral>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUINavigatedDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUINavigatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::WebUI::WebUINavigatedOperation) NavigatedOperation() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUINavigatedEventArgs>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUINavigatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUINavigatedOperation
    {
        LLM_IMPL_AUTO(llm:OS::UI::WebUI::WebUINavigatedDeferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUINavigatedOperation>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUINavigatedOperation<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIView
    {
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ApplicationViewId() const;
        LLM_IMPL_AUTO(llm::event_token) Closed(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::WebUI::WebUIView, llm:OS::Foundation::IInspectable> const& handler) const;
        using Closed_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIView, &impl::abi_t<llm:OS::UI::WebUI::IWebUIView>::remove_Closed>;
        [[nodiscard]] Closed_revoker Closed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::WebUI::WebUIView, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Closed(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Activated(llm:OS::Foundation::TypedEventHandler<llm:OS::UI::WebUI::WebUIView, llm:OS::ApplicationModel::Activation::IActivatedEventArgs> const& handler) const;
        using Activated_revoker = impl::event_revoker<llm:OS::UI::WebUI::IWebUIView, &impl::abi_t<llm:OS::UI::WebUI::IWebUIView>::remove_Activated>;
        [[nodiscard]] Activated_revoker Activated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::UI::WebUI::WebUIView, llm:OS::ApplicationModel::Activation::IActivatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Activated(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IgnoreApplicationContentUriRulesNavigationRestrictions() const;
        LLM_IMPL_AUTO(void) IgnoreApplicationContentUriRulesNavigationRestrictions(bool value) const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIView>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIView<D>;
    };
    template <typename D>
    struct consume_Windows_UI_WebUI_IWebUIViewStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::WebUI::WebUIView>) CreateAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::UI::WebUI::WebUIView>) CreateAsync(llm:OS::Foundation::Uri const& uri) const;
    };
    template <> struct consume<llm:OS::UI::WebUI::IWebUIViewStatics>
    {
        template <typename D> using type = consume_Windows_UI_WebUI_IWebUIViewStatics<D>;
    };
}
#endif
