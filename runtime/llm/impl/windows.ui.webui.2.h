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
#ifndef LLM_OS_UI_WebUI_2_H
#define LLM_OS_UI_WebUI_2_H
#include "llm/impl/Windows.ApplicationModel.1.h"
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.ApplicationModel.Background.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Graphics.Printing.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Web.UI.1.h"
#include "llm/impl/Windows.UI.WebUI.1.h"
LLM_EXPORT namespace llm:OS::UI::WebUI
{
    struct ActivatedEventHandler : llm:OS::Foundation::IUnknown
    {
        ActivatedEventHandler(std::nullptr_t = nullptr) noexcept {}
        ActivatedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ActivatedEventHandler(L lambda);
        template <typename F> ActivatedEventHandler(F* function);
        template <typename O, typename M> ActivatedEventHandler(O* object, M method);
        template <typename O, typename M> ActivatedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ActivatedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender, llm:OS::ApplicationModel::Activation::IActivatedEventArgs const& eventArgs) const;
    };
    struct BackgroundActivatedEventHandler : llm:OS::Foundation::IUnknown
    {
        BackgroundActivatedEventHandler(std::nullptr_t = nullptr) noexcept {}
        BackgroundActivatedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> BackgroundActivatedEventHandler(L lambda);
        template <typename F> BackgroundActivatedEventHandler(F* function);
        template <typename O, typename M> BackgroundActivatedEventHandler(O* object, M method);
        template <typename O, typename M> BackgroundActivatedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> BackgroundActivatedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender, llm:OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs const& eventArgs) const;
    };
    struct EnteredBackgroundEventHandler : llm:OS::Foundation::IUnknown
    {
        EnteredBackgroundEventHandler(std::nullptr_t = nullptr) noexcept {}
        EnteredBackgroundEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> EnteredBackgroundEventHandler(L lambda);
        template <typename F> EnteredBackgroundEventHandler(F* function);
        template <typename O, typename M> EnteredBackgroundEventHandler(O* object, M method);
        template <typename O, typename M> EnteredBackgroundEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> EnteredBackgroundEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender, llm:OS::ApplicationModel::IEnteredBackgroundEventArgs const& e) const;
    };
    struct LeavingBackgroundEventHandler : llm:OS::Foundation::IUnknown
    {
        LeavingBackgroundEventHandler(std::nullptr_t = nullptr) noexcept {}
        LeavingBackgroundEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> LeavingBackgroundEventHandler(L lambda);
        template <typename F> LeavingBackgroundEventHandler(F* function);
        template <typename O, typename M> LeavingBackgroundEventHandler(O* object, M method);
        template <typename O, typename M> LeavingBackgroundEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> LeavingBackgroundEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender, llm:OS::ApplicationModel::ILeavingBackgroundEventArgs const& e) const;
    };
    struct NavigatedEventHandler : llm:OS::Foundation::IUnknown
    {
        NavigatedEventHandler(std::nullptr_t = nullptr) noexcept {}
        NavigatedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> NavigatedEventHandler(L lambda);
        template <typename F> NavigatedEventHandler(F* function);
        template <typename O, typename M> NavigatedEventHandler(O* object, M method);
        template <typename O, typename M> NavigatedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> NavigatedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender, llm:OS::UI::WebUI::IWebUINavigatedEventArgs const& e) const;
    };
    struct ResumingEventHandler : llm:OS::Foundation::IUnknown
    {
        ResumingEventHandler(std::nullptr_t = nullptr) noexcept {}
        ResumingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> ResumingEventHandler(L lambda);
        template <typename F> ResumingEventHandler(F* function);
        template <typename O, typename M> ResumingEventHandler(O* object, M method);
        template <typename O, typename M> ResumingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> ResumingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender) const;
    };
    struct SuspendingEventHandler : llm:OS::Foundation::IUnknown
    {
        SuspendingEventHandler(std::nullptr_t = nullptr) noexcept {}
        SuspendingEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SuspendingEventHandler(L lambda);
        template <typename F> SuspendingEventHandler(F* function);
        template <typename O, typename M> SuspendingEventHandler(O* object, M method);
        template <typename O, typename M> SuspendingEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SuspendingEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Foundation::IInspectable const& sender, llm:OS::ApplicationModel::ISuspendingEventArgs const& e) const;
    };
    struct __declspec(empty_bases) ActivatedDeferral : llm:OS::UI::WebUI::IActivatedDeferral
    {
        ActivatedDeferral(std::nullptr_t) noexcept {}
        ActivatedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IActivatedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ActivatedOperation : llm:OS::UI::WebUI::IActivatedOperation
    {
        ActivatedOperation(std::nullptr_t) noexcept {}
        ActivatedOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IActivatedOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackgroundActivatedEventArgs : llm:OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs
    {
        BackgroundActivatedEventArgs(std::nullptr_t) noexcept {}
        BackgroundActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EnteredBackgroundEventArgs : llm:OS::ApplicationModel::IEnteredBackgroundEventArgs
    {
        EnteredBackgroundEventArgs(std::nullptr_t) noexcept {}
        EnteredBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::IEnteredBackgroundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HtmlPrintDocumentSource : llm:OS::UI::WebUI::IHtmlPrintDocumentSource,
        impl::require<HtmlPrintDocumentSource, llm:OS::Foundation::IClosable>
    {
        HtmlPrintDocumentSource(std::nullptr_t) noexcept {}
        HtmlPrintDocumentSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IHtmlPrintDocumentSource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LeavingBackgroundEventArgs : llm:OS::ApplicationModel::ILeavingBackgroundEventArgs
    {
        LeavingBackgroundEventArgs(std::nullptr_t) noexcept {}
        LeavingBackgroundEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::ILeavingBackgroundEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) NewWebUIViewCreatedEventArgs : llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs
    {
        NewWebUIViewCreatedEventArgs(std::nullptr_t) noexcept {}
        NewWebUIViewCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::INewWebUIViewCreatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SuspendingDeferral : llm:OS::ApplicationModel::ISuspendingDeferral
    {
        SuspendingDeferral(std::nullptr_t) noexcept {}
        SuspendingDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::ISuspendingDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SuspendingEventArgs : llm:OS::ApplicationModel::ISuspendingEventArgs
    {
        SuspendingEventArgs(std::nullptr_t) noexcept {}
        SuspendingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::ISuspendingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SuspendingOperation : llm:OS::ApplicationModel::ISuspendingOperation
    {
        SuspendingOperation(std::nullptr_t) noexcept {}
        SuspendingOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::ISuspendingOperation(ptr, take_ownership_from_abi) {}
    };
    struct WebUIApplication
    {
        WebUIApplication() = delete;
        static auto Activated(llm:OS::UI::WebUI::ActivatedEventHandler const& handler);
        using Activated_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Activated>;
        [[nodiscard]] static Activated_revoker Activated(auto_revoke_t, llm:OS::UI::WebUI::ActivatedEventHandler const& handler);
        static auto Activated(llm::event_token const& token);
        static auto Suspending(llm:OS::UI::WebUI::SuspendingEventHandler const& handler);
        using Suspending_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Suspending>;
        [[nodiscard]] static Suspending_revoker Suspending(auto_revoke_t, llm:OS::UI::WebUI::SuspendingEventHandler const& handler);
        static auto Suspending(llm::event_token const& token);
        static auto Resuming(llm:OS::UI::WebUI::ResumingEventHandler const& handler);
        using Resuming_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Resuming>;
        [[nodiscard]] static Resuming_revoker Resuming(auto_revoke_t, llm:OS::UI::WebUI::ResumingEventHandler const& handler);
        static auto Resuming(llm::event_token const& token);
        static auto Navigated(llm:OS::UI::WebUI::NavigatedEventHandler const& handler);
        using Navigated_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics>::remove_Navigated>;
        [[nodiscard]] static Navigated_revoker Navigated(auto_revoke_t, llm:OS::UI::WebUI::NavigatedEventHandler const& handler);
        static auto Navigated(llm::event_token const& token);
        static auto LeavingBackground(llm:OS::UI::WebUI::LeavingBackgroundEventHandler const& handler);
        using LeavingBackground_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics2, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics2>::remove_LeavingBackground>;
        [[nodiscard]] static LeavingBackground_revoker LeavingBackground(auto_revoke_t, llm:OS::UI::WebUI::LeavingBackgroundEventHandler const& handler);
        static auto LeavingBackground(llm::event_token const& token);
        static auto EnteredBackground(llm:OS::UI::WebUI::EnteredBackgroundEventHandler const& handler);
        using EnteredBackground_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics2, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics2>::remove_EnteredBackground>;
        [[nodiscard]] static EnteredBackground_revoker EnteredBackground(auto_revoke_t, llm:OS::UI::WebUI::EnteredBackgroundEventHandler const& handler);
        static auto EnteredBackground(llm::event_token const& token);
        static auto EnablePrelaunch(bool value);
        static auto RequestRestartAsync(param::hstring const& launchArguments);
        static auto RequestRestartForUserAsync(llm:OS::System::User const& user, param::hstring const& launchArguments);
        static auto NewWebUIViewCreated(llm:OS::Foundation::EventHandler<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler);
        using NewWebUIViewCreated_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics4, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics4>::remove_NewWebUIViewCreated>;
        [[nodiscard]] static NewWebUIViewCreated_revoker NewWebUIViewCreated(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler);
        static auto NewWebUIViewCreated(llm::event_token const& token);
        static auto BackgroundActivated(llm:OS::UI::WebUI::BackgroundActivatedEventHandler const& handler);
        using BackgroundActivated_revoker = impl::factory_event_revoker<llm:OS::UI::WebUI::IWebUIActivationStatics4, &impl::abi_t<llm:OS::UI::WebUI::IWebUIActivationStatics4>::remove_BackgroundActivated>;
        [[nodiscard]] static BackgroundActivated_revoker BackgroundActivated(auto_revoke_t, llm:OS::UI::WebUI::BackgroundActivatedEventHandler const& handler);
        static auto BackgroundActivated(llm::event_token const& token);
    };
    struct __declspec(empty_bases) WebUIAppointmentsProviderAddAppointmentActivatedEventArgs : llm:OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs,
        impl::require<WebUIAppointmentsProviderAddAppointmentActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIAppointmentsProviderAddAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIAppointmentsProviderAddAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs : llm:OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs,
        impl::require<WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs : llm:OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs,
        impl::require<WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs : llm:OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs,
        impl::require<WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs : llm:OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs,
        impl::require<WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WebUIBackgroundTaskInstance
    {
        WebUIBackgroundTaskInstance() = delete;
        [[nodiscard]] static auto Current();
    };
    struct __declspec(empty_bases) WebUIBackgroundTaskInstanceRuntimeClass : llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance,
        impl::require<WebUIBackgroundTaskInstanceRuntimeClass, llm:OS::ApplicationModel::Background::IBackgroundTaskInstance>
    {
        WebUIBackgroundTaskInstanceRuntimeClass(std::nullptr_t) noexcept {}
        WebUIBackgroundTaskInstanceRuntimeClass(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IWebUIBackgroundTaskInstance(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIBarcodeScannerPreviewActivatedEventArgs : llm:OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs,
        impl::require<WebUIBarcodeScannerPreviewActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIBarcodeScannerPreviewActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIBarcodeScannerPreviewActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUICachedFileUpdaterActivatedEventArgs : llm:OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs,
        impl::require<WebUICachedFileUpdaterActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUICachedFileUpdaterActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUICachedFileUpdaterActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUICameraSettingsActivatedEventArgs : llm:OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs,
        impl::require<WebUICameraSettingsActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUICameraSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUICameraSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUICommandLineActivatedEventArgs : llm:OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs,
        impl::require<WebUICommandLineActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUICommandLineActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUICommandLineActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactCallActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactCallActivatedEventArgs,
        impl::require<WebUIContactCallActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIContactCallActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactMapActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactMapActivatedEventArgs,
        impl::require<WebUIContactMapActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIContactMapActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactMapActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactMapActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactMessageActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs,
        impl::require<WebUIContactMessageActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIContactMessageActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactMessageActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactPanelActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs,
        impl::require<WebUIContactPanelActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIContactPanelActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactPanelActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactPickerActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs,
        impl::require<WebUIContactPickerActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIContactPickerActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactPickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactPostActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactPostActivatedEventArgs,
        impl::require<WebUIContactPostActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIContactPostActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactPostActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactPostActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIContactVideoCallActivatedEventArgs : llm:OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs,
        impl::require<WebUIContactVideoCallActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIContactVideoCallActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIContactVideoCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIDeviceActivatedEventArgs : llm:OS::ApplicationModel::Activation::IDeviceActivatedEventArgs,
        impl::require<WebUIDeviceActivatedEventArgs, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIDeviceActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIDeviceActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IDeviceActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIDevicePairingActivatedEventArgs : llm:OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs,
        impl::require<WebUIDevicePairingActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIDevicePairingActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIDevicePairingActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIDialReceiverActivatedEventArgs : llm:OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs,
        impl::require<WebUIDialReceiverActivatedEventArgs, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIDialReceiverActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIDialReceiverActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIFileActivatedEventArgs : llm:OS::ApplicationModel::Activation::IFileActivatedEventArgs,
        impl::require<WebUIFileActivatedEventArgs, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIFileActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIFileActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IFileActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIFileOpenPickerActivatedEventArgs : llm:OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs,
        impl::require<WebUIFileOpenPickerActivatedEventArgs, llm:OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIFileOpenPickerActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIFileOpenPickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIFileOpenPickerContinuationEventArgs : llm:OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs,
        impl::require<WebUIFileOpenPickerContinuationEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIFileOpenPickerContinuationEventArgs(std::nullptr_t) noexcept {}
        WebUIFileOpenPickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIFileSavePickerActivatedEventArgs : llm:OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs,
        impl::require<WebUIFileSavePickerActivatedEventArgs, llm:OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIFileSavePickerActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIFileSavePickerActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIFileSavePickerContinuationEventArgs : llm:OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs,
        impl::require<WebUIFileSavePickerContinuationEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIFileSavePickerContinuationEventArgs(std::nullptr_t) noexcept {}
        WebUIFileSavePickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIFolderPickerContinuationEventArgs : llm:OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs,
        impl::require<WebUIFolderPickerContinuationEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIFolderPickerContinuationEventArgs(std::nullptr_t) noexcept {}
        WebUIFolderPickerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUILaunchActivatedEventArgs : llm:OS::ApplicationModel::Activation::ILaunchActivatedEventArgs,
        impl::require<WebUILaunchActivatedEventArgs, llm:OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm:OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2>
    {
        WebUILaunchActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUILaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ILaunchActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUILockScreenActivatedEventArgs : llm:OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs,
        impl::require<WebUILockScreenActivatedEventArgs, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUILockScreenActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUILockScreenActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUILockScreenCallActivatedEventArgs : llm:OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs,
        impl::require<WebUILockScreenCallActivatedEventArgs, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUILockScreenCallActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUILockScreenCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUILockScreenComponentActivatedEventArgs : llm:OS::ApplicationModel::Activation::IActivatedEventArgs,
        impl::require<WebUILockScreenComponentActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUILockScreenComponentActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUILockScreenComponentActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUINavigatedDeferral : llm:OS::UI::WebUI::IWebUINavigatedDeferral
    {
        WebUINavigatedDeferral(std::nullptr_t) noexcept {}
        WebUINavigatedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IWebUINavigatedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUINavigatedEventArgs : llm:OS::UI::WebUI::IWebUINavigatedEventArgs
    {
        WebUINavigatedEventArgs(std::nullptr_t) noexcept {}
        WebUINavigatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IWebUINavigatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUINavigatedOperation : llm:OS::UI::WebUI::IWebUINavigatedOperation
    {
        WebUINavigatedOperation(std::nullptr_t) noexcept {}
        WebUINavigatedOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IWebUINavigatedOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIPhoneCallActivatedEventArgs : llm:OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs,
        impl::require<WebUIPhoneCallActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIPhoneCallActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIPhoneCallActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIPrint3DWorkflowActivatedEventArgs : llm:OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs,
        impl::require<WebUIPrint3DWorkflowActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIPrint3DWorkflowActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIPrint3DWorkflowActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIPrintTaskSettingsActivatedEventArgs : llm:OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs,
        impl::require<WebUIPrintTaskSettingsActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIPrintTaskSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIPrintTaskSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIPrintWorkflowForegroundTaskActivatedEventArgs : llm:OS::ApplicationModel::Activation::IActivatedEventArgs,
        impl::require<WebUIPrintWorkflowForegroundTaskActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIPrintWorkflowForegroundTaskActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIPrintWorkflowForegroundTaskActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIProtocolActivatedEventArgs : llm:OS::ApplicationModel::Activation::IProtocolActivatedEventArgs,
        impl::require<WebUIProtocolActivatedEventArgs, llm:OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIProtocolActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIProtocolActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IProtocolActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIProtocolForResultsActivatedEventArgs : llm:OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs,
        impl::require<WebUIProtocolForResultsActivatedEventArgs, llm:OS::ApplicationModel::Activation::IProtocolActivatedEventArgs, llm:OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIProtocolForResultsActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIProtocolForResultsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIRestrictedLaunchActivatedEventArgs : llm:OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs,
        impl::require<WebUIRestrictedLaunchActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIRestrictedLaunchActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIRestrictedLaunchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUISearchActivatedEventArgs : llm:OS::ApplicationModel::Activation::ISearchActivatedEventArgs,
        impl::require<WebUISearchActivatedEventArgs, llm:OS::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails, llm:OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUISearchActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUISearchActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::ISearchActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIShareTargetActivatedEventArgs : llm:OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs,
        impl::require<WebUIShareTargetActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIShareTargetActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIShareTargetActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIStartupTaskActivatedEventArgs : llm:OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs,
        impl::require<WebUIStartupTaskActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIStartupTaskActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIStartupTaskActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIToastNotificationActivatedEventArgs : llm:OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs,
        impl::require<WebUIToastNotificationActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIToastNotificationActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIToastNotificationActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIUserDataAccountProviderActivatedEventArgs : llm:OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs,
        impl::require<WebUIUserDataAccountProviderActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIUserDataAccountProviderActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIUserDataAccountProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIView : llm:OS::UI::WebUI::IWebUIView,
        impl::require<WebUIView, llm:OS::Web::UI::IWebViewControl, llm:OS::Web::UI::IWebViewControl2>
    {
        WebUIView(std::nullptr_t) noexcept {}
        WebUIView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::WebUI::IWebUIView(ptr, take_ownership_from_abi) {}
        static auto CreateAsync();
        static auto CreateAsync(llm:OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) WebUIVoiceCommandActivatedEventArgs : llm:OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs,
        impl::require<WebUIVoiceCommandActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIVoiceCommandActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIVoiceCommandActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIWalletActionActivatedEventArgs : llm:OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs,
        impl::require<WebUIWalletActionActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIWalletActionActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIWalletActionActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIWebAccountProviderActivatedEventArgs : llm:OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs,
        impl::require<WebUIWebAccountProviderActivatedEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        WebUIWebAccountProviderActivatedEventArgs(std::nullptr_t) noexcept {}
        WebUIWebAccountProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUIWebAuthenticationBrokerContinuationEventArgs : llm:OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs,
        impl::require<WebUIWebAuthenticationBrokerContinuationEventArgs, llm:OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        WebUIWebAuthenticationBrokerContinuationEventArgs(std::nullptr_t) noexcept {}
        WebUIWebAuthenticationBrokerContinuationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
