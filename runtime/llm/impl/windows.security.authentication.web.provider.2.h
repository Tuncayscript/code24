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
#ifndef LLM_OS_Security_Authentication_Web_Provider_2_H
#define LLM_OS_Security_Authentication_Web_Provider_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Security.Authentication.Web.Core.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Web.Http.1.h"
#include "llm/impl/Windows.Security.Authentication.Web.Provider.1.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Web::Provider
{
    struct __declspec(empty_bases) WebAccountClientView : llm:OS::Security::Authentication::Web::Provider::IWebAccountClientView
    {
        WebAccountClientView(std::nullptr_t) noexcept {}
        WebAccountClientView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountClientView(ptr, take_ownership_from_abi) {}
        WebAccountClientView(llm:OS::Security::Authentication::Web::Provider::WebAccountClientViewType const& viewType, llm:OS::Foundation::Uri const& applicationCallbackUri);
        WebAccountClientView(llm:OS::Security::Authentication::Web::Provider::WebAccountClientViewType const& viewType, llm:OS::Foundation::Uri const& applicationCallbackUri, param::hstring const& accountPairwiseId);
    };
    struct WebAccountManager
    {
        WebAccountManager() = delete;
        static auto UpdateWebAccountPropertiesAsync(llm:OS::Security::Credentials::WebAccount const& webAccount, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& additionalProperties);
        static auto AddWebAccountAsync(param::hstring const& webAccountId, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& props);
        static auto DeleteWebAccountAsync(llm:OS::Security::Credentials::WebAccount const& webAccount);
        static auto FindAllProviderWebAccountsAsync();
        static auto PushCookiesAsync(llm:OS::Foundation::Uri const& uri, param::async_vector_view<llm:OS::Web::Http::HttpCookie> const& cookies);
        static auto SetViewAsync(llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::Security::Authentication::Web::Provider::WebAccountClientView const& view);
        static auto ClearViewAsync(llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::Foundation::Uri const& applicationCallbackUri);
        static auto GetViewsAsync(llm:OS::Security::Credentials::WebAccount const& webAccount);
        static auto SetWebAccountPictureAsync(llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::Storage::Streams::IRandomAccessStream const& webAccountPicture);
        static auto ClearWebAccountPictureAsync(llm:OS::Security::Credentials::WebAccount const& webAccount);
        static auto PullCookiesAsync(param::hstring const& uriString, param::hstring const& callerPFN);
        static auto FindAllProviderWebAccountsForUserAsync(llm:OS::System::User const& user);
        static auto AddWebAccountForUserAsync(llm:OS::System::User const& user, param::hstring const& webAccountId, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& props);
        static auto AddWebAccountForUserAsync(llm:OS::System::User const& user, param::hstring const& webAccountId, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& props, llm:OS::Security::Authentication::Web::Provider::WebAccountScope const& scope);
        static auto AddWebAccountForUserAsync(llm:OS::System::User const& user, param::hstring const& webAccountId, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& props, llm:OS::Security::Authentication::Web::Provider::WebAccountScope const& scope, param::hstring const& perUserWebAccountId);
        static auto InvalidateAppCacheForAllAccountsAsync();
        static auto InvalidateAppCacheForAccountAsync(llm:OS::Security::Credentials::WebAccount const& webAccount);
        static auto AddWebAccountAsync(param::hstring const& webAccountId, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& props, llm:OS::Security::Authentication::Web::Provider::WebAccountScope const& scope, param::hstring const& perUserWebAccountId);
        static auto SetPerAppToPerUserAccountAsync(llm:OS::Security::Credentials::WebAccount const& perAppAccount, param::hstring const& perUserWebAccountId);
        static auto GetPerUserFromPerAppAccountAsync(llm:OS::Security::Credentials::WebAccount const& perAppAccount);
        static auto ClearPerUserFromPerAppAccountAsync(llm:OS::Security::Credentials::WebAccount const& perAppAccount);
        static auto AddWebAccountAsync(param::hstring const& webAccountId, param::hstring const& webAccountUserName, param::async_map_view<hstring, hstring> const& props, llm:OS::Security::Authentication::Web::Provider::WebAccountScope const& scope);
        static auto SetScopeAsync(llm:OS::Security::Credentials::WebAccount const& webAccount, llm:OS::Security::Authentication::Web::Provider::WebAccountScope const& scope);
        static auto GetScope(llm:OS::Security::Credentials::WebAccount const& webAccount);
    };
    struct __declspec(empty_bases) WebAccountProviderAddAccountOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation
    {
        WebAccountProviderAddAccountOperation(std::nullptr_t) noexcept {}
        WebAccountProviderAddAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderDeleteAccountOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation,
        impl::require<WebAccountProviderDeleteAccountOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
    {
        WebAccountProviderDeleteAccountOperation(std::nullptr_t) noexcept {}
        WebAccountProviderDeleteAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderGetTokenSilentOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation,
        impl::require<WebAccountProviderGetTokenSilentOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation>
    {
        WebAccountProviderGetTokenSilentOperation(std::nullptr_t) noexcept {}
        WebAccountProviderGetTokenSilentOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderManageAccountOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation
    {
        WebAccountProviderManageAccountOperation(std::nullptr_t) noexcept {}
        WebAccountProviderManageAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderRequestTokenOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation,
        impl::require<WebAccountProviderRequestTokenOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation>
    {
        WebAccountProviderRequestTokenOperation(std::nullptr_t) noexcept {}
        WebAccountProviderRequestTokenOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderRetrieveCookiesOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation,
        impl::require<WebAccountProviderRetrieveCookiesOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
    {
        WebAccountProviderRetrieveCookiesOperation(std::nullptr_t) noexcept {}
        WebAccountProviderRetrieveCookiesOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderSignOutAccountOperation : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation,
        impl::require<WebAccountProviderSignOutAccountOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
    {
        WebAccountProviderSignOutAccountOperation(std::nullptr_t) noexcept {}
        WebAccountProviderSignOutAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebAccountProviderTriggerDetails : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects,
        impl::require<WebAccountProviderTriggerDetails, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects2>
    {
        WebAccountProviderTriggerDetails(std::nullptr_t) noexcept {}
        WebAccountProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebProviderTokenRequest : llm:OS::Security::Authentication::Web::Provider::IWebProviderTokenRequest,
        impl::require<WebProviderTokenRequest, llm:OS::Security::Authentication::Web::Provider::IWebProviderTokenRequest2, llm:OS::Security::Authentication::Web::Provider::IWebProviderTokenRequest3>
    {
        WebProviderTokenRequest(std::nullptr_t) noexcept {}
        WebProviderTokenRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebProviderTokenRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebProviderTokenResponse : llm:OS::Security::Authentication::Web::Provider::IWebProviderTokenResponse
    {
        WebProviderTokenResponse(std::nullptr_t) noexcept {}
        WebProviderTokenResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::Provider::IWebProviderTokenResponse(ptr, take_ownership_from_abi) {}
        explicit WebProviderTokenResponse(llm:OS::Security::Authentication::Web::Core::WebTokenResponse const& webTokenResponse);
    };
}
#endif
