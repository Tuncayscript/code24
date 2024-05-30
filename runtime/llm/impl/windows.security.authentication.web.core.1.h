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
#ifndef LLM_OS_Security_Authentication_Web_Core_1_H
#define LLM_OS_Security_Authentication_Web_Core_1_H
#include "llm/impl/Windows.Security.Authentication.Web.Core.0.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Web::Core
{
    struct __declspec(empty_bases) IFindAllAccountsResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFindAllAccountsResult>
    {
        IFindAllAccountsResult(std::nullptr_t = nullptr) noexcept {}
        IFindAllAccountsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountEventArgs>
    {
        IWebAccountEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebAccountEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountMonitor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountMonitor>
    {
        IWebAccountMonitor(std::nullptr_t = nullptr) noexcept {}
        IWebAccountMonitor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAccountMonitor2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAccountMonitor2>
    {
        IWebAccountMonitor2(std::nullptr_t = nullptr) noexcept {}
        IWebAccountMonitor2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAuthenticationCoreManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAuthenticationCoreManagerStatics>
    {
        IWebAuthenticationCoreManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWebAuthenticationCoreManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAuthenticationCoreManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAuthenticationCoreManagerStatics2>,
        impl::require<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics2, llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
    {
        IWebAuthenticationCoreManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IWebAuthenticationCoreManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IWebAuthenticationCoreManagerStatics2, IWebAuthenticationCoreManagerStatics2>::FindAccountProviderAsync;
        using impl::consume_t<IWebAuthenticationCoreManagerStatics2, llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>::FindAccountProviderAsync;
    };
    struct __declspec(empty_bases) IWebAuthenticationCoreManagerStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAuthenticationCoreManagerStatics3>,
        impl::require<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics3, llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
    {
        IWebAuthenticationCoreManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IWebAuthenticationCoreManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebAuthenticationCoreManagerStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebAuthenticationCoreManagerStatics4>,
        impl::require<llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics4, llm:OS::Security::Authentication::Web::Core::IWebAuthenticationCoreManagerStatics>
    {
        IWebAuthenticationCoreManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IWebAuthenticationCoreManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderError :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderError>
    {
        IWebProviderError(std::nullptr_t = nullptr) noexcept {}
        IWebProviderError(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebProviderErrorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebProviderErrorFactory>
    {
        IWebProviderErrorFactory(std::nullptr_t = nullptr) noexcept {}
        IWebProviderErrorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenRequest>
    {
        IWebTokenRequest(std::nullptr_t = nullptr) noexcept {}
        IWebTokenRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenRequest2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenRequest2>
    {
        IWebTokenRequest2(std::nullptr_t = nullptr) noexcept {}
        IWebTokenRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenRequest3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenRequest3>
    {
        IWebTokenRequest3(std::nullptr_t = nullptr) noexcept {}
        IWebTokenRequest3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenRequestFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenRequestFactory>
    {
        IWebTokenRequestFactory(std::nullptr_t = nullptr) noexcept {}
        IWebTokenRequestFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenRequestResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenRequestResult>
    {
        IWebTokenRequestResult(std::nullptr_t = nullptr) noexcept {}
        IWebTokenRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenResponse :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenResponse>
    {
        IWebTokenResponse(std::nullptr_t = nullptr) noexcept {}
        IWebTokenResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebTokenResponseFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebTokenResponseFactory>
    {
        IWebTokenResponseFactory(std::nullptr_t = nullptr) noexcept {}
        IWebTokenResponseFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
