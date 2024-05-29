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
#ifndef LLM_OS_ApplicationModel_Core_2_H
#define LLM_OS_ApplicationModel_Core_2_H
#include "llm/impl/Windows.ApplicationModel.1.h"
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.Core.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Core
{
    struct __declspec(empty_bases) AppListEntry : llm::OS::ApplicationModel::Core::IAppListEntry,
        impl::require<AppListEntry, llm::OS::ApplicationModel::Core::IAppListEntry2, llm::OS::ApplicationModel::Core::IAppListEntry3, llm::OS::ApplicationModel::Core::IAppListEntry4>
    {
        AppListEntry(std::nullptr_t) noexcept {}
        AppListEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Core::IAppListEntry(ptr, take_ownership_from_abi) {}
    };
    struct CoreApplication
    {
        CoreApplication() = delete;
        [[nodiscard]] static auto Id();
        static auto Suspending(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::SuspendingEventArgs> const& handler);
        using Suspending_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplication, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplication>::remove_Suspending>;
        [[nodiscard]] static Suspending_revoker Suspending(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::SuspendingEventArgs> const& handler);
        static auto Suspending(llm::event_token const& token);
        static auto Resuming(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using Resuming_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplication, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplication>::remove_Resuming>;
        [[nodiscard]] static Resuming_revoker Resuming(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto Resuming(llm::event_token const& token);
        [[nodiscard]] static auto Properties();
        static auto GetCurrentView();
        static auto Run(llm::OS::ApplicationModel::Core::IFrameworkViewSource const& viewSource);
        static auto RunWithActivationFactories(llm::OS::Foundation::IGetActivationFactory const& activationFactoryCallback);
        static auto BackgroundActivated(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs> const& handler);
        using BackgroundActivated_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplication2, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplication2>::remove_BackgroundActivated>;
        [[nodiscard]] static BackgroundActivated_revoker BackgroundActivated(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs> const& handler);
        static auto BackgroundActivated(llm::event_token const& token);
        static auto LeavingBackground(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::LeavingBackgroundEventArgs> const& handler);
        using LeavingBackground_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplication2, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplication2>::remove_LeavingBackground>;
        [[nodiscard]] static LeavingBackground_revoker LeavingBackground(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::LeavingBackgroundEventArgs> const& handler);
        static auto LeavingBackground(llm::event_token const& token);
        static auto EnteredBackground(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::EnteredBackgroundEventArgs> const& handler);
        using EnteredBackground_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplication2, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplication2>::remove_EnteredBackground>;
        [[nodiscard]] static EnteredBackground_revoker EnteredBackground(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::EnteredBackgroundEventArgs> const& handler);
        static auto EnteredBackground(llm::event_token const& token);
        static auto EnablePrelaunch(bool value);
        static auto RequestRestartAsync(param::hstring const& launchArguments);
        static auto RequestRestartForUserAsync(llm::OS::System::User const& user, param::hstring const& launchArguments);
        static auto Exit();
        static auto Exiting(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using Exiting_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplicationExit, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplicationExit>::remove_Exiting>;
        [[nodiscard]] static Exiting_revoker Exiting(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto Exiting(llm::event_token const& token);
        static auto UnhandledErrorDetected(llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> const& handler);
        using UnhandledErrorDetected_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Core::ICoreApplicationUnhandledError, &impl::abi_t<llm::OS::ApplicationModel::Core::ICoreApplicationUnhandledError>::remove_UnhandledErrorDetected>;
        [[nodiscard]] static UnhandledErrorDetected_revoker UnhandledErrorDetected(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::ApplicationModel::Core::UnhandledErrorDetectedEventArgs> const& handler);
        static auto UnhandledErrorDetected(llm::event_token const& token);
        static auto IncrementApplicationUseCount();
        static auto DecrementApplicationUseCount();
        [[nodiscard]] static auto Views();
        static auto CreateNewView(param::hstring const& runtimeType, param::hstring const& entryPoint);
        [[nodiscard]] static auto MainView();
        static auto CreateNewView();
        static auto CreateNewView(llm::OS::ApplicationModel::Core::IFrameworkViewSource const& viewSource);
    };
    struct __declspec(empty_bases) CoreApplicationView : llm::OS::ApplicationModel::Core::ICoreApplicationView,
        impl::require<CoreApplicationView, llm::OS::ApplicationModel::Core::ICoreApplicationView2, llm::OS::ApplicationModel::Core::ICoreApplicationView3, llm::OS::ApplicationModel::Core::ICoreApplicationView5, llm::OS::ApplicationModel::Core::ICoreApplicationView6>
    {
        CoreApplicationView(std::nullptr_t) noexcept {}
        CoreApplicationView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Core::ICoreApplicationView(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreApplicationViewTitleBar : llm::OS::ApplicationModel::Core::ICoreApplicationViewTitleBar
    {
        CoreApplicationViewTitleBar(std::nullptr_t) noexcept {}
        CoreApplicationViewTitleBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Core::ICoreApplicationViewTitleBar(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HostedViewClosingEventArgs : llm::OS::ApplicationModel::Core::IHostedViewClosingEventArgs
    {
        HostedViewClosingEventArgs(std::nullptr_t) noexcept {}
        HostedViewClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Core::IHostedViewClosingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UnhandledError : llm::OS::ApplicationModel::Core::IUnhandledError
    {
        UnhandledError(std::nullptr_t) noexcept {}
        UnhandledError(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Core::IUnhandledError(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UnhandledErrorDetectedEventArgs : llm::OS::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs
    {
        UnhandledErrorDetectedEventArgs(std::nullptr_t) noexcept {}
        UnhandledErrorDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Core::IUnhandledErrorDetectedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
