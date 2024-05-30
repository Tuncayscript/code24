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
#ifndef LLM_OS_UI_ApplicationSettings_2_H
#define LLM_OS_UI_ApplicationSettings_2_H
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.UI.Popups.1.h"
#include "llm/impl/Windows.UI.ApplicationSettings.1.h"
LLM_EXPORT namespace llm:OS::UI::ApplicationSettings
{
    struct CredentialCommandCredentialDeletedHandler : llm:OS::Foundation::IUnknown
    {
        CredentialCommandCredentialDeletedHandler(std::nullptr_t = nullptr) noexcept {}
        CredentialCommandCredentialDeletedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> CredentialCommandCredentialDeletedHandler(L lambda);
        template <typename F> CredentialCommandCredentialDeletedHandler(F* function);
        template <typename O, typename M> CredentialCommandCredentialDeletedHandler(O* object, M method);
        template <typename O, typename M> CredentialCommandCredentialDeletedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> CredentialCommandCredentialDeletedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::UI::ApplicationSettings::CredentialCommand const& command) const;
    };
    struct WebAccountCommandInvokedHandler : llm:OS::Foundation::IUnknown
    {
        WebAccountCommandInvokedHandler(std::nullptr_t = nullptr) noexcept {}
        WebAccountCommandInvokedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WebAccountCommandInvokedHandler(L lambda);
        template <typename F> WebAccountCommandInvokedHandler(F* function);
        template <typename O, typename M> WebAccountCommandInvokedHandler(O* object, M method);
        template <typename O, typename M> WebAccountCommandInvokedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WebAccountCommandInvokedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::UI::ApplicationSettings::WebAccountCommand const& command, llm:OS::UI::ApplicationSettings::WebAccountInvokedArgs const& args) const;
    };
    struct WebAccountProviderCommandInvokedHandler : llm:OS::Foundation::IUnknown
    {
        WebAccountProviderCommandInvokedHandler(std::nullptr_t = nullptr) noexcept {}
        WebAccountProviderCommandInvokedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WebAccountProviderCommandInvokedHandler(L lambda);
        template <typename F> WebAccountProviderCommandInvokedHandler(F* function);
        template <typename O, typename M> WebAccountProviderCommandInvokedHandler(O* object, M method);
        template <typename O, typename M> WebAccountProviderCommandInvokedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WebAccountProviderCommandInvokedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::UI::ApplicationSettings::WebAccountProviderCommand const& command) const;
    };
    struct __declspec(empty_bases) AccountsSettingsPane : llm:OS::UI::ApplicationSettings::IAccountsSettingsPane
    {
        AccountsSettingsPane(std::nullptr_t) noexcept {}
        AccountsSettingsPane(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::IAccountsSettingsPane(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto Show();
        static auto ShowManageAccountsAsync();
        static auto ShowAddAccountAsync();
        static auto ShowManageAccountsForUserAsync(llm:OS::System::User const& user);
        static auto ShowAddAccountForUserAsync(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) AccountsSettingsPaneCommandsRequestedEventArgs : llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs,
        impl::require<AccountsSettingsPaneCommandsRequestedEventArgs, llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs2>
    {
        AccountsSettingsPaneCommandsRequestedEventArgs(std::nullptr_t) noexcept {}
        AccountsSettingsPaneCommandsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AccountsSettingsPaneEventDeferral : llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral
    {
        AccountsSettingsPaneEventDeferral(std::nullptr_t) noexcept {}
        AccountsSettingsPaneEventDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CredentialCommand : llm:OS::UI::ApplicationSettings::ICredentialCommand
    {
        CredentialCommand(std::nullptr_t) noexcept {}
        CredentialCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::ICredentialCommand(ptr, take_ownership_from_abi) {}
        explicit CredentialCommand(llm:OS::Security::Credentials::PasswordCredential const& passwordCredential);
        CredentialCommand(llm:OS::Security::Credentials::PasswordCredential const& passwordCredential, llm:OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler const& deleted);
    };
    struct __declspec(empty_bases) SettingsCommand : llm:OS::UI::Popups::IUICommand
    {
        SettingsCommand(std::nullptr_t) noexcept {}
        SettingsCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Popups::IUICommand(ptr, take_ownership_from_abi) {}
        SettingsCommand(llm:OS::Foundation::IInspectable const& settingsCommandId, param::hstring const& label, llm:OS::UI::Popups::UICommandInvokedHandler const& handler);
        [[nodiscard]] static auto AccountsCommand();
    };
    struct __declspec(empty_bases) SettingsPane : llm:OS::UI::ApplicationSettings::ISettingsPane
    {
        SettingsPane(std::nullptr_t) noexcept {}
        SettingsPane(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::ISettingsPane(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto Show();
        [[nodiscard]] static auto Edge();
    };
    struct __declspec(empty_bases) SettingsPaneCommandsRequest : llm:OS::UI::ApplicationSettings::ISettingsPaneCommandsRequest
    {
        SettingsPaneCommandsRequest(std::nullptr_t) noexcept {}
        SettingsPaneCommandsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::ISettingsPaneCommandsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SettingsPaneCommandsRequestedEventArgs : llm:OS::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs
    {
        SettingsPaneCommandsRequestedEventArgs(std::nullptr_t) noexcept {}
        SettingsPaneCommandsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountCommand : llm:OS::UI::ApplicationSettings::IWebAccountCommand
    {
        WebAccountCommand(std::nullptr_t) noexcept {}
        WebAccountCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::IWebAccountCommand(ptr, take_ownership_from_abi) {}
        WebAccountCommand(llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler const& invoked, llm:OS::UI::ApplicationSettings::SupportedWebAccountActions const& actions);
    };
    struct __declspec(empty_bases) WebAccountInvokedArgs : llm:OS::UI::ApplicationSettings::IWebAccountInvokedArgs
    {
        WebAccountInvokedArgs(std::nullptr_t) noexcept {}
        WebAccountInvokedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::IWebAccountInvokedArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderCommand : llm:OS::UI::ApplicationSettings::IWebAccountProviderCommand
    {
        WebAccountProviderCommand(std::nullptr_t) noexcept {}
        WebAccountProviderCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ApplicationSettings::IWebAccountProviderCommand(ptr, take_ownership_from_abi) {}
        WebAccountProviderCommand(llm:OS::Security::Credentials::WebAccountProvider const& webAccountProvider, llm:OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler const& invoked);
    };
}
#endif
