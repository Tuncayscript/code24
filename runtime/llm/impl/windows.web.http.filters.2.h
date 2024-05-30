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
#ifndef LLM_OS_Web_Http_Filters_2_H
#define LLM_OS_Web_Http_Filters_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Web.Http.Filters.1.h"
LLM_EXPORT namespace llm::OS::Web::Http::Filters
{
    struct __declspec(empty_bases) HttpBaseProtocolFilter : llm::OS::Web::Http::Filters::IHttpBaseProtocolFilter,
        impl::require<HttpBaseProtocolFilter, llm::OS::Web::Http::Filters::IHttpBaseProtocolFilter2, llm::OS::Web::Http::Filters::IHttpBaseProtocolFilter3, llm::OS::Web::Http::Filters::IHttpBaseProtocolFilter4, llm::OS::Web::Http::Filters::IHttpBaseProtocolFilter5, llm::OS::Foundation::IClosable, llm::OS::Web::Http::Filters::IHttpFilter>
    {
        HttpBaseProtocolFilter(std::nullptr_t) noexcept {}
        HttpBaseProtocolFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Filters::IHttpBaseProtocolFilter(ptr, take_ownership_from_abi) {}
        HttpBaseProtocolFilter();
        static auto CreateForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) HttpCacheControl : llm::OS::Web::Http::Filters::IHttpCacheControl
    {
        HttpCacheControl(std::nullptr_t) noexcept {}
        HttpCacheControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Filters::IHttpCacheControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpServerCustomValidationRequestedEventArgs : llm::OS::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs
    {
        HttpServerCustomValidationRequestedEventArgs(std::nullptr_t) noexcept {}
        HttpServerCustomValidationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Filters::IHttpServerCustomValidationRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
