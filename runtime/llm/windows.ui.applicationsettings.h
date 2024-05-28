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
#ifndef LLM_OS_UI_ApplicationSettings_H
#define LLM_OS_UI_ApplicationSettings_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.UI.ApplicationSettings.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPane<D>::AccountCommandsRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ApplicationSettings::AccountsSettingsPane, llm::OS::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPane)->add_AccountCommandsRequested(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_ApplicationSettings_IAccountsSettingsPane<D>::AccountCommandsRequested_revoker consume_Windows_UI_ApplicationSettings_IAccountsSettingsPane<D>::AccountCommandsRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ApplicationSettings::AccountsSettingsPane, llm::OS::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AccountCommandsRequested_revoker>(this, AccountCommandsRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPane<D>::AccountCommandsRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPane)->remove_AccountCommandsRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::WebAccountProviderCommand>) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::WebAccountProviderCommands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->get_WebAccountProviderCommands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::WebAccountProviderCommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::WebAccountCommand>) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::WebAccountCommands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->get_WebAccountCommands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::WebAccountCommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::CredentialCommand>) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::CredentialCommands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->get_CredentialCommands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::CredentialCommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::SettingsCommand>) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::Commands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->get_Commands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::SettingsCommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::HeaderText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->get_HeaderText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::HeaderText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->put_HeaderText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs)->GetDeferral(&deferral));
        return llm::OS::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneCommandsRequestedEventArgs2<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs2)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneEventDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::AccountsSettingsPane) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneStatics<D>::GetForCurrentView() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics)->GetForCurrentView(&current));
        return llm::OS::UI::ApplicationSettings::AccountsSettingsPane{ current, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneStatics<D>::Show() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics)->Show());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneStatics2<D>::ShowManageAccountsAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics2)->ShowManageAccountsAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneStatics2<D>::ShowAddAccountAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics2)->ShowAddAccountAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneStatics3<D>::ShowManageAccountsForUserAsync(llm::OS::System::User const& user) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics3)->ShowManageAccountsForUserAsync(*(void**)(&user), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ApplicationSettings_IAccountsSettingsPaneStatics3<D>::ShowAddAccountForUserAsync(llm::OS::System::User const& user) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics3)->ShowAddAccountForUserAsync(*(void**)(&user), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_UI_ApplicationSettings_ICredentialCommand<D>::PasswordCredential() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ICredentialCommand)->get_PasswordCredential(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler) consume_Windows_UI_ApplicationSettings_ICredentialCommand<D>::CredentialDeleted() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ICredentialCommand)->get_CredentialDeleted(&value));
        return llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::CredentialCommand) consume_Windows_UI_ApplicationSettings_ICredentialCommandFactory<D>::CreateCredentialCommand(llm::OS::Security::Credentials::PasswordCredential const& passwordCredential) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ICredentialCommandFactory)->CreateCredentialCommand(*(void**)(&passwordCredential), &instance));
        return llm::OS::UI::ApplicationSettings::CredentialCommand{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::CredentialCommand) consume_Windows_UI_ApplicationSettings_ICredentialCommandFactory<D>::CreateCredentialCommandWithHandler(llm::OS::Security::Credentials::PasswordCredential const& passwordCredential, llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler const& deleted) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ICredentialCommandFactory)->CreateCredentialCommandWithHandler(*(void**)(&passwordCredential), *(void**)(&deleted), &instance));
        return llm::OS::UI::ApplicationSettings::CredentialCommand{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::SettingsCommand) consume_Windows_UI_ApplicationSettings_ISettingsCommandFactory<D>::CreateSettingsCommand(llm::OS::Foundation::IInspectable const& settingsCommandId, param::hstring const& label, llm::OS::UI::Popups::UICommandInvokedHandler const& handler) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsCommandFactory)->CreateSettingsCommand(*(void**)(&settingsCommandId), *(void**)(&label), *(void**)(&handler), &instance));
        return llm::OS::UI::ApplicationSettings::SettingsCommand{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::SettingsCommand) consume_Windows_UI_ApplicationSettings_ISettingsCommandStatics<D>::AccountsCommand() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsCommandStatics)->get_AccountsCommand(&value));
        return llm::OS::UI::ApplicationSettings::SettingsCommand{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ApplicationSettings_ISettingsPane<D>::CommandsRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ApplicationSettings::SettingsPane, llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPane)->add_CommandsRequested(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_ApplicationSettings_ISettingsPane<D>::CommandsRequested_revoker consume_Windows_UI_ApplicationSettings_ISettingsPane<D>::CommandsRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ApplicationSettings::SettingsPane, llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CommandsRequested_revoker>(this, CommandsRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ApplicationSettings_ISettingsPane<D>::CommandsRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPane)->remove_CommandsRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::SettingsCommand>) consume_Windows_UI_ApplicationSettings_ISettingsPaneCommandsRequest<D>::ApplicationCommands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequest)->get_ApplicationCommands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::SettingsCommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequest) consume_Windows_UI_ApplicationSettings_ISettingsPaneCommandsRequestedEventArgs<D>::Request() const
    {
        void* request{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs)->get_Request(&request));
        return llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequest{ request, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::SettingsPane) consume_Windows_UI_ApplicationSettings_ISettingsPaneStatics<D>::GetForCurrentView() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPaneStatics)->GetForCurrentView(&current));
        return llm::OS::UI::ApplicationSettings::SettingsPane{ current, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ApplicationSettings_ISettingsPaneStatics<D>::Show() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPaneStatics)->Show());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::SettingsEdgeLocation) consume_Windows_UI_ApplicationSettings_ISettingsPaneStatics<D>::Edge() const
    {
        llm::OS::UI::ApplicationSettings::SettingsEdgeLocation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::ISettingsPaneStatics)->get_Edge(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::WebAccount) consume_Windows_UI_ApplicationSettings_IWebAccountCommand<D>::WebAccount() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountCommand)->get_WebAccount(&value));
        return llm::OS::Security::Credentials::WebAccount{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler) consume_Windows_UI_ApplicationSettings_IWebAccountCommand<D>::Invoked() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountCommand)->get_Invoked(&value));
        return llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::SupportedWebAccountActions) consume_Windows_UI_ApplicationSettings_IWebAccountCommand<D>::Actions() const
    {
        llm::OS::UI::ApplicationSettings::SupportedWebAccountActions value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountCommand)->get_Actions(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::WebAccountCommand) consume_Windows_UI_ApplicationSettings_IWebAccountCommandFactory<D>::CreateWebAccountCommand(llm::OS::Security::Credentials::WebAccount const& webAccount, llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler const& invoked, llm::OS::UI::ApplicationSettings::SupportedWebAccountActions const& actions) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountCommandFactory)->CreateWebAccountCommand(*(void**)(&webAccount), *(void**)(&invoked), static_cast<uint32_t>(actions), &instance));
        return llm::OS::UI::ApplicationSettings::WebAccountCommand{ instance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::WebAccountAction) consume_Windows_UI_ApplicationSettings_IWebAccountInvokedArgs<D>::Action() const
    {
        llm::OS::UI::ApplicationSettings::WebAccountAction action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountInvokedArgs)->get_Action(reinterpret_cast<int32_t*>(&action)));
        return action;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::WebAccountProvider) consume_Windows_UI_ApplicationSettings_IWebAccountProviderCommand<D>::WebAccountProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountProviderCommand)->get_WebAccountProvider(&value));
        return llm::OS::Security::Credentials::WebAccountProvider{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler) consume_Windows_UI_ApplicationSettings_IWebAccountProviderCommand<D>::Invoked() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountProviderCommand)->get_Invoked(&value));
        return llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ApplicationSettings::WebAccountProviderCommand) consume_Windows_UI_ApplicationSettings_IWebAccountProviderCommandFactory<D>::CreateWebAccountProviderCommand(llm::OS::Security::Credentials::WebAccountProvider const& webAccountProvider, llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler const& invoked) const
    {
        void* instance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ApplicationSettings::IWebAccountProviderCommandFactory)->CreateWebAccountProviderCommand(*(void**)(&webAccountProvider), *(void**)(&invoked), &instance));
        return llm::OS::UI::ApplicationSettings::WebAccountProviderCommand{ instance, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler, H> final : implements_delegate<llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* command) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::UI::ApplicationSettings::CredentialCommand const*>(&command));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler, H> final : implements_delegate<llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* command, void* args) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::UI::ApplicationSettings::WebAccountCommand const*>(&command), *reinterpret_cast<llm::OS::UI::ApplicationSettings::WebAccountInvokedArgs const*>(&args));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler, H> final : implements_delegate<llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* command) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::UI::ApplicationSettings::WebAccountProviderCommand const*>(&command));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPane> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPane>
    {
        int32_t __stdcall add_AccountCommandsRequested(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AccountCommandsRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ApplicationSettings::AccountsSettingsPane, llm::OS::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccountCommandsRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountCommandsRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs>
    {
        int32_t __stdcall get_WebAccountProviderCommands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::WebAccountProviderCommand>>(this->shim().WebAccountProviderCommands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WebAccountCommands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::WebAccountCommand>>(this->shim().WebAccountCommands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CredentialCommands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::CredentialCommand>>(this->shim().CredentialCommands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Commands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::SettingsCommand>>(this->shim().Commands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HeaderText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HeaderText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HeaderText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HeaderText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs2> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs2>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics>
    {
        int32_t __stdcall GetForCurrentView(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::UI::ApplicationSettings::AccountsSettingsPane>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Show() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics2>
    {
        int32_t __stdcall ShowManageAccountsAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowManageAccountsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAddAccountAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAddAccountAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics3> : produce_base<D, llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics3>
    {
        int32_t __stdcall ShowManageAccountsForUserAsync(void* user, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowManageAccountsForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAddAccountForUserAsync(void* user, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAddAccountForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ICredentialCommand> : produce_base<D, llm::OS::UI::ApplicationSettings::ICredentialCommand>
    {
        int32_t __stdcall get_PasswordCredential(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().PasswordCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CredentialDeleted(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler>(this->shim().CredentialDeleted());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ICredentialCommandFactory> : produce_base<D, llm::OS::UI::ApplicationSettings::ICredentialCommandFactory>
    {
        int32_t __stdcall CreateCredentialCommand(void* passwordCredential, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::UI::ApplicationSettings::CredentialCommand>(this->shim().CreateCredentialCommand(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCredentialCommandWithHandler(void* passwordCredential, void* deleted, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::UI::ApplicationSettings::CredentialCommand>(this->shim().CreateCredentialCommandWithHandler(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential), *reinterpret_cast<llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler const*>(&deleted)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ISettingsCommandFactory> : produce_base<D, llm::OS::UI::ApplicationSettings::ISettingsCommandFactory>
    {
        int32_t __stdcall CreateSettingsCommand(void* settingsCommandId, void* label, void* handler, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::UI::ApplicationSettings::SettingsCommand>(this->shim().CreateSettingsCommand(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&settingsCommandId), *reinterpret_cast<hstring const*>(&label), *reinterpret_cast<llm::OS::UI::Popups::UICommandInvokedHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ISettingsCommandStatics> : produce_base<D, llm::OS::UI::ApplicationSettings::ISettingsCommandStatics>
    {
        int32_t __stdcall get_AccountsCommand(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ApplicationSettings::SettingsCommand>(this->shim().AccountsCommand());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ISettingsPane> : produce_base<D, llm::OS::UI::ApplicationSettings::ISettingsPane>
    {
        int32_t __stdcall add_CommandsRequested(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().CommandsRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ApplicationSettings::SettingsPane, llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CommandsRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommandsRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequest> : produce_base<D, llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequest>
    {
        int32_t __stdcall get_ApplicationCommands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::ApplicationSettings::SettingsCommand>>(this->shim().ApplicationCommands());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs> : produce_base<D, llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** request) noexcept final try
        {
            clear_abi(request);
            typename D::abi_guard guard(this->shim());
            *request = detach_from<llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::ISettingsPaneStatics> : produce_base<D, llm::OS::UI::ApplicationSettings::ISettingsPaneStatics>
    {
        int32_t __stdcall GetForCurrentView(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::UI::ApplicationSettings::SettingsPane>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Show() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Edge(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ApplicationSettings::SettingsEdgeLocation>(this->shim().Edge());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IWebAccountCommand> : produce_base<D, llm::OS::UI::ApplicationSettings::IWebAccountCommand>
    {
        int32_t __stdcall get_WebAccount(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::WebAccount>(this->shim().WebAccount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Invoked(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler>(this->shim().Invoked());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Actions(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ApplicationSettings::SupportedWebAccountActions>(this->shim().Actions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IWebAccountCommandFactory> : produce_base<D, llm::OS::UI::ApplicationSettings::IWebAccountCommandFactory>
    {
        int32_t __stdcall CreateWebAccountCommand(void* webAccount, void* invoked, uint32_t actions, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::UI::ApplicationSettings::WebAccountCommand>(this->shim().CreateWebAccountCommand(*reinterpret_cast<llm::OS::Security::Credentials::WebAccount const*>(&webAccount), *reinterpret_cast<llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler const*>(&invoked), *reinterpret_cast<llm::OS::UI::ApplicationSettings::SupportedWebAccountActions const*>(&actions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IWebAccountInvokedArgs> : produce_base<D, llm::OS::UI::ApplicationSettings::IWebAccountInvokedArgs>
    {
        int32_t __stdcall get_Action(int32_t* action) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::UI::ApplicationSettings::WebAccountAction>(this->shim().Action());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IWebAccountProviderCommand> : produce_base<D, llm::OS::UI::ApplicationSettings::IWebAccountProviderCommand>
    {
        int32_t __stdcall get_WebAccountProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::WebAccountProvider>(this->shim().WebAccountProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Invoked(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler>(this->shim().Invoked());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ApplicationSettings::IWebAccountProviderCommandFactory> : produce_base<D, llm::OS::UI::ApplicationSettings::IWebAccountProviderCommandFactory>
    {
        int32_t __stdcall CreateWebAccountProviderCommand(void* webAccountProvider, void* invoked, void** instance) noexcept final try
        {
            clear_abi(instance);
            typename D::abi_guard guard(this->shim());
            *instance = detach_from<llm::OS::UI::ApplicationSettings::WebAccountProviderCommand>(this->shim().CreateWebAccountProviderCommand(*reinterpret_cast<llm::OS::Security::Credentials::WebAccountProvider const*>(&webAccountProvider), *reinterpret_cast<llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler const*>(&invoked)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::ApplicationSettings
{
    constexpr auto operator|(SupportedWebAccountActions const left, SupportedWebAccountActions const right) noexcept
    {
        return static_cast<SupportedWebAccountActions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(SupportedWebAccountActions& left, SupportedWebAccountActions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(SupportedWebAccountActions const left, SupportedWebAccountActions const right) noexcept
    {
        return static_cast<SupportedWebAccountActions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(SupportedWebAccountActions& left, SupportedWebAccountActions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(SupportedWebAccountActions const value) noexcept
    {
        return static_cast<SupportedWebAccountActions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(SupportedWebAccountActions const left, SupportedWebAccountActions const right) noexcept
    {
        return static_cast<SupportedWebAccountActions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(SupportedWebAccountActions& left, SupportedWebAccountActions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto AccountsSettingsPane::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ApplicationSettings::AccountsSettingsPane(*)(IAccountsSettingsPaneStatics const&), AccountsSettingsPane, IAccountsSettingsPaneStatics>([](IAccountsSettingsPaneStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto AccountsSettingsPane::Show()
    {
        impl::call_factory_cast<void(*)(IAccountsSettingsPaneStatics const&), AccountsSettingsPane, IAccountsSettingsPaneStatics>([](IAccountsSettingsPaneStatics const& f) { return f.Show(); });
    }
    inline auto AccountsSettingsPane::ShowManageAccountsAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncAction(*)(IAccountsSettingsPaneStatics2 const&), AccountsSettingsPane, IAccountsSettingsPaneStatics2>([](IAccountsSettingsPaneStatics2 const& f) { return f.ShowManageAccountsAsync(); });
    }
    inline auto AccountsSettingsPane::ShowAddAccountAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncAction(*)(IAccountsSettingsPaneStatics2 const&), AccountsSettingsPane, IAccountsSettingsPaneStatics2>([](IAccountsSettingsPaneStatics2 const& f) { return f.ShowAddAccountAsync(); });
    }
    inline auto AccountsSettingsPane::ShowManageAccountsForUserAsync(llm::OS::System::User const& user)
    {
        return impl::call_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics3>([&](IAccountsSettingsPaneStatics3 const& f) { return f.ShowManageAccountsForUserAsync(user); });
    }
    inline auto AccountsSettingsPane::ShowAddAccountForUserAsync(llm::OS::System::User const& user)
    {
        return impl::call_factory<AccountsSettingsPane, IAccountsSettingsPaneStatics3>([&](IAccountsSettingsPaneStatics3 const& f) { return f.ShowAddAccountForUserAsync(user); });
    }
    inline CredentialCommand::CredentialCommand(llm::OS::Security::Credentials::PasswordCredential const& passwordCredential) :
        CredentialCommand(impl::call_factory<CredentialCommand, ICredentialCommandFactory>([&](ICredentialCommandFactory const& f) { return f.CreateCredentialCommand(passwordCredential); }))
    {
    }
    inline CredentialCommand::CredentialCommand(llm::OS::Security::Credentials::PasswordCredential const& passwordCredential, llm::OS::UI::ApplicationSettings::CredentialCommandCredentialDeletedHandler const& deleted) :
        CredentialCommand(impl::call_factory<CredentialCommand, ICredentialCommandFactory>([&](ICredentialCommandFactory const& f) { return f.CreateCredentialCommandWithHandler(passwordCredential, deleted); }))
    {
    }
    inline SettingsCommand::SettingsCommand(llm::OS::Foundation::IInspectable const& settingsCommandId, param::hstring const& label, llm::OS::UI::Popups::UICommandInvokedHandler const& handler) :
        SettingsCommand(impl::call_factory<SettingsCommand, ISettingsCommandFactory>([&](ISettingsCommandFactory const& f) { return f.CreateSettingsCommand(settingsCommandId, label, handler); }))
    {
    }
    inline auto SettingsCommand::AccountsCommand()
    {
        return impl::call_factory_cast<llm::OS::UI::ApplicationSettings::SettingsCommand(*)(ISettingsCommandStatics const&), SettingsCommand, ISettingsCommandStatics>([](ISettingsCommandStatics const& f) { return f.AccountsCommand(); });
    }
    inline auto SettingsPane::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ApplicationSettings::SettingsPane(*)(ISettingsPaneStatics const&), SettingsPane, ISettingsPaneStatics>([](ISettingsPaneStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto SettingsPane::Show()
    {
        impl::call_factory_cast<void(*)(ISettingsPaneStatics const&), SettingsPane, ISettingsPaneStatics>([](ISettingsPaneStatics const& f) { return f.Show(); });
    }
    inline auto SettingsPane::Edge()
    {
        return impl::call_factory_cast<llm::OS::UI::ApplicationSettings::SettingsEdgeLocation(*)(ISettingsPaneStatics const&), SettingsPane, ISettingsPaneStatics>([](ISettingsPaneStatics const& f) { return f.Edge(); });
    }
    inline WebAccountCommand::WebAccountCommand(llm::OS::Security::Credentials::WebAccount const& webAccount, llm::OS::UI::ApplicationSettings::WebAccountCommandInvokedHandler const& invoked, llm::OS::UI::ApplicationSettings::SupportedWebAccountActions const& actions) :
        WebAccountCommand(impl::call_factory<WebAccountCommand, IWebAccountCommandFactory>([&](IWebAccountCommandFactory const& f) { return f.CreateWebAccountCommand(webAccount, invoked, actions); }))
    {
    }
    inline WebAccountProviderCommand::WebAccountProviderCommand(llm::OS::Security::Credentials::WebAccountProvider const& webAccountProvider, llm::OS::UI::ApplicationSettings::WebAccountProviderCommandInvokedHandler const& invoked) :
        WebAccountProviderCommand(impl::call_factory<WebAccountProviderCommand, IWebAccountProviderCommandFactory>([&](IWebAccountProviderCommandFactory const& f) { return f.CreateWebAccountProviderCommand(webAccountProvider, invoked); }))
    {
    }
    template <typename L> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(L handler) :
        CredentialCommandCredentialDeletedHandler(impl::make_delegate<CredentialCommandCredentialDeletedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(F* handler) :
        CredentialCommandCredentialDeletedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(O* object, M method) :
        CredentialCommandCredentialDeletedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(com_ptr<O>&& object, M method) :
        CredentialCommandCredentialDeletedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> CredentialCommandCredentialDeletedHandler::CredentialCommandCredentialDeletedHandler(weak_ref<O>&& object, M method) :
        CredentialCommandCredentialDeletedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto CredentialCommandCredentialDeletedHandler::operator()(llm::OS::UI::ApplicationSettings::CredentialCommand const& command) const
    {
        check_hresult((*(impl::abi_t<CredentialCommandCredentialDeletedHandler>**)this)->Invoke(*(void**)(&command)));
    }
    template <typename L> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(L handler) :
        WebAccountCommandInvokedHandler(impl::make_delegate<WebAccountCommandInvokedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(F* handler) :
        WebAccountCommandInvokedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(O* object, M method) :
        WebAccountCommandInvokedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(com_ptr<O>&& object, M method) :
        WebAccountCommandInvokedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> WebAccountCommandInvokedHandler::WebAccountCommandInvokedHandler(weak_ref<O>&& object, M method) :
        WebAccountCommandInvokedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto WebAccountCommandInvokedHandler::operator()(llm::OS::UI::ApplicationSettings::WebAccountCommand const& command, llm::OS::UI::ApplicationSettings::WebAccountInvokedArgs const& args) const
    {
        check_hresult((*(impl::abi_t<WebAccountCommandInvokedHandler>**)this)->Invoke(*(void**)(&command), *(void**)(&args)));
    }
    template <typename L> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(L handler) :
        WebAccountProviderCommandInvokedHandler(impl::make_delegate<WebAccountProviderCommandInvokedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(F* handler) :
        WebAccountProviderCommandInvokedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(O* object, M method) :
        WebAccountProviderCommandInvokedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(com_ptr<O>&& object, M method) :
        WebAccountProviderCommandInvokedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> WebAccountProviderCommandInvokedHandler::WebAccountProviderCommandInvokedHandler(weak_ref<O>&& object, M method) :
        WebAccountProviderCommandInvokedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto WebAccountProviderCommandInvokedHandler::operator()(llm::OS::UI::ApplicationSettings::WebAccountProviderCommand const& command) const
    {
        check_hresult((*(impl::abi_t<WebAccountProviderCommandInvokedHandler>**)this)->Invoke(*(void**)(&command)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneCommandsRequestedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneEventDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IAccountsSettingsPaneStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ICredentialCommand> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ICredentialCommandFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ISettingsCommandFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ISettingsCommandStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ISettingsPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ISettingsPaneCommandsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::ISettingsPaneStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IWebAccountCommand> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IWebAccountCommandFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IWebAccountInvokedArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IWebAccountProviderCommand> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::IWebAccountProviderCommandFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::AccountsSettingsPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::AccountsSettingsPaneCommandsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::AccountsSettingsPaneEventDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::CredentialCommand> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::SettingsCommand> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::SettingsPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::SettingsPaneCommandsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::WebAccountCommand> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::WebAccountInvokedArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ApplicationSettings::WebAccountProviderCommand> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
