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
#ifndef LLM_OS_Security_Authentication_Web_Provider_1_H
#define LLM_OS_Security_Authentication_Web_Provider_1_H
#include "llm/impl/Windows.Security.Authentication.Web.Provider.0.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Web::Provider
{
    struct __declspec(empty_bases) IWebAccountClientView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountClientView>
    {
        IWebAccountClientView(std::nullptr_t = nullptr) noexcept {}
        IWebAccountClientView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountClientViewFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountClientViewFactory>
    {
        IWebAccountClientViewFactory(std::nullptr_t = nullptr) noexcept {}
        IWebAccountClientViewFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountManagerStatics>
    {
        IWebAccountManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWebAccountManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountManagerStatics2>
    {
        IWebAccountManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IWebAccountManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountManagerStatics3>
    {
        IWebAccountManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IWebAccountManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountManagerStatics4>
    {
        IWebAccountManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IWebAccountManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountMapManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountMapManagerStatics>
    {
        IWebAccountMapManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWebAccountMapManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderAddAccountOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderAddAccountOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderAddAccountOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
    {
        IWebAccountProviderAddAccountOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderAddAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderBaseReportOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderBaseReportOperation>
    {
        IWebAccountProviderBaseReportOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderBaseReportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderDeleteAccountOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderDeleteAccountOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderDeleteAccountOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
    {
        IWebAccountProviderDeleteAccountOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderDeleteAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderManageAccountOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderManageAccountOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderManageAccountOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
    {
        IWebAccountProviderManageAccountOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderManageAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderOperation>
    {
        IWebAccountProviderOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderRetrieveCookiesOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderRetrieveCookiesOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderRetrieveCookiesOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
    {
        IWebAccountProviderRetrieveCookiesOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderRetrieveCookiesOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderSignOutAccountOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderSignOutAccountOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderSignOutAccountOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
    {
        IWebAccountProviderSignOutAccountOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderSignOutAccountOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderSilentReportOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderSilentReportOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderSilentReportOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
    {
        IWebAccountProviderSilentReportOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderSilentReportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderTokenObjects :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderTokenObjects>
    {
        IWebAccountProviderTokenObjects(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderTokenObjects(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderTokenObjects2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderTokenObjects2>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects2, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenObjects>
    {
        IWebAccountProviderTokenObjects2(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderTokenObjects2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderTokenOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderTokenOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderTokenOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>
    {
        IWebAccountProviderTokenOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderTokenOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountProviderUIReportOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountProviderUIReportOperation>,
        impl::require<llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderUIReportOperation, llm:OS::Security::Authentication::Web::Provider::IWebAccountProviderBaseReportOperation>
    {
        IWebAccountProviderUIReportOperation(std::nullptr_t = nullptr) noexcept {}
        IWebAccountProviderUIReportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountScopeManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountScopeManagerStatics>
    {
        IWebAccountScopeManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWebAccountScopeManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderTokenRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderTokenRequest>
    {
        IWebProviderTokenRequest(std::nullptr_t = nullptr) noexcept {}
        IWebProviderTokenRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderTokenRequest2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderTokenRequest2>
    {
        IWebProviderTokenRequest2(std::nullptr_t = nullptr) noexcept {}
        IWebProviderTokenRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderTokenRequest3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderTokenRequest3>
    {
        IWebProviderTokenRequest3(std::nullptr_t = nullptr) noexcept {}
        IWebProviderTokenRequest3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderTokenResponse :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderTokenResponse>
    {
        IWebProviderTokenResponse(std::nullptr_t = nullptr) noexcept {}
        IWebProviderTokenResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderTokenResponseFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderTokenResponseFactory>
    {
        IWebProviderTokenResponseFactory(std::nullptr_t = nullptr) noexcept {}
        IWebProviderTokenResponseFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
