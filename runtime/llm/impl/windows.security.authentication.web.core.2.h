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
#ifndef LLM_OS_Security_Authentication_Web_Core_2_H
#define LLM_OS_Security_Authentication_Web_Core_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Security.Authentication.Web.Core.1.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Web::Core
{
    struct __declspec(empty_bases) FindAllAccountsResult : llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult
    {
        FindAllAccountsResult(std::nullptr_t) noexcept {}
        FindAllAccountsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IFindAllAccountsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountEventArgs : llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs
    {
        WebAccountEventArgs(std::nullptr_t) noexcept {}
        WebAccountEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IWebAccountEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountMonitor : llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor,
        impl::require<WebAccountMonitor, llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor2>
    {
        WebAccountMonitor(std::nullptr_t) noexcept {}
        WebAccountMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IWebAccountMonitor(ptr, take_ownership_from_abi) {}
    };
    struct WebAuthenticationCoreManager
    {
        WebAuthenticationCoreManager() = delete;
        static auto GetTokenSilentlyAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request);
        static auto GetTokenSilentlyAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request, llm:OS::Security::Credentials::WebAccount const& webAccount);
        static auto RequestTokenAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request);
        static auto RequestTokenAsync(llm:OS::Security::Authentication::Web::Core::WebTokenRequest const& request, llm:OS::Security::Credentials::WebAccount const& webAccount);
        static auto FindAccountAsync(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& webAccountId);
        static auto FindAccountProviderAsync(param::hstring const& webAccountProviderId);
        static auto FindAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority);
        static auto FindAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority, llm:OS::System::User const& user);
        static auto CreateWebAccountMonitor(param::iterable<llm:OS::Security::Credentials::WebAccount> const& webAccounts);
        static auto FindAllAccountsAsync(llm:OS::Security::Credentials::WebAccountProvider const& provider);
        static auto FindAllAccountsAsync(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& clientId);
        static auto FindSystemAccountProviderAsync(param::hstring const& webAccountProviderId);
        static auto FindSystemAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority);
        static auto FindSystemAccountProviderAsync(param::hstring const& webAccountProviderId, param::hstring const& authority, llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) WebProviderError : llm:OS::Security::Authentication::Web::Core::IWebProviderError
    {
        WebProviderError(std::nullptr_t) noexcept {}
        WebProviderError(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IWebProviderError(ptr, take_ownership_from_abi) {}
        WebProviderError(uint32_t errorCode, param::hstring const& errorMessage);
    };
    struct __declspec(empty_bases) WebTokenRequest : llm:OS::Security::Authentication::Web::Core::IWebTokenRequest,
        impl::require<WebTokenRequest, llm:OS::Security::Authentication::Web::Core::IWebTokenRequest2, llm:OS::Security::Authentication::Web::Core::IWebTokenRequest3>
    {
        WebTokenRequest(std::nullptr_t) noexcept {}
        WebTokenRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IWebTokenRequest(ptr, take_ownership_from_abi) {}
        WebTokenRequest(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& scope, param::hstring const& clientId);
        WebTokenRequest(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& scope, param::hstring const& clientId, llm:OS::Security::Authentication::Web::Core::WebTokenRequestPromptType const& promptType);
        explicit WebTokenRequest(llm:OS::Security::Credentials::WebAccountProvider const& provider);
        WebTokenRequest(llm:OS::Security::Credentials::WebAccountProvider const& provider, param::hstring const& scope);
    };
    struct __declspec(empty_bases) WebTokenRequestResult : llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult
    {
        WebTokenRequestResult(std::nullptr_t) noexcept {}
        WebTokenRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IWebTokenRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebTokenResponse : llm:OS::Security::Authentication::Web::Core::IWebTokenResponse
    {
        WebTokenResponse(std::nullptr_t) noexcept {}
        WebTokenResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Core::IWebTokenResponse(ptr, take_ownership_from_abi) {}
        WebTokenResponse();
        explicit WebTokenResponse(param::hstring const& token);
        WebTokenResponse(param::hstring const& token, llm:OS::Security::Credentials::WebAccount const& webAccount);
        WebTokenResponse(param::hstring const& token, llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::Security::Authentication::Web::Core::WebProviderError const& error);
    };
}
#endif
