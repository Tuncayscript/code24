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
#ifndef LLM_OS_Security_Authentication_Web_2_H
#define LLM_OS_Security_Authentication_Web_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Security.Authentication.Web.1.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Web
{
    struct WebAuthenticationBroker
    {
        WebAuthenticationBroker() = delete;
        static auto AuthenticateAsync(llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm:OS::Foundation::Uri const& requestUri, llm:OS::Foundation::Uri const& callbackUri);
        static auto AuthenticateAsync(llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm:OS::Foundation::Uri const& requestUri);
        static auto GetCurrentApplicationCallbackUri();
        static auto AuthenticateAndContinue(llm:OS::Foundation::Uri const& requestUri);
        static auto AuthenticateAndContinue(llm:OS::Foundation::Uri const& requestUri, llm:OS::Foundation::Uri const& callbackUri);
        static auto AuthenticateAndContinue(llm:OS::Foundation::Uri const& requestUri, llm:OS::Foundation::Uri const& callbackUri, llm:OS::Foundation::Collections::ValueSet const& continuationData, llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options);
        static auto AuthenticateSilentlyAsync(llm:OS::Foundation::Uri const& requestUri);
        static auto AuthenticateSilentlyAsync(llm:OS::Foundation::Uri const& requestUri, llm:OS::Security::Authentication::Web::WebAuthenticationOptions const& options);
    };
    struct __declspec(empty_bases) WebAuthenticationResult : llm:OS::Security::Authentication::Web::IWebAuthenticationResult
    {
        WebAuthenticationResult(std::nullptr_t) noexcept {}
        WebAuthenticationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Web::IWebAuthenticationResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
