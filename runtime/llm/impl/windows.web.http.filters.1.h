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
#ifndef LLM_OS_Web_Http_Filters_1_H
#define LLM_OS_Web_Http_Filters_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Web.Http.Filters.0.h"
LLM_EXPORT namespace llm::OS::Web::Http::Filters
{
    struct __declspec(empty_bases) IHttpBaseProtocolFilter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBaseProtocolFilter>
    {
        IHttpBaseProtocolFilter(std::nullptr_t = nullptr) noexcept {}
        IHttpBaseProtocolFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpBaseProtocolFilter2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBaseProtocolFilter2>
    {
        IHttpBaseProtocolFilter2(std::nullptr_t = nullptr) noexcept {}
        IHttpBaseProtocolFilter2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpBaseProtocolFilter3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBaseProtocolFilter3>
    {
        IHttpBaseProtocolFilter3(std::nullptr_t = nullptr) noexcept {}
        IHttpBaseProtocolFilter3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpBaseProtocolFilter4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBaseProtocolFilter4>
    {
        IHttpBaseProtocolFilter4(std::nullptr_t = nullptr) noexcept {}
        IHttpBaseProtocolFilter4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpBaseProtocolFilter5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBaseProtocolFilter5>
    {
        IHttpBaseProtocolFilter5(std::nullptr_t = nullptr) noexcept {}
        IHttpBaseProtocolFilter5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpBaseProtocolFilterStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBaseProtocolFilterStatics>
    {
        IHttpBaseProtocolFilterStatics(std::nullptr_t = nullptr) noexcept {}
        IHttpBaseProtocolFilterStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpCacheControl :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpCacheControl>
    {
        IHttpCacheControl(std::nullptr_t = nullptr) noexcept {}
        IHttpCacheControl(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpFilter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpFilter>,
        impl::require<llm::OS::Web::Http::Filters::IHttpFilter, llm::OS::Foundation::IClosable>
    {
        IHttpFilter(std::nullptr_t = nullptr) noexcept {}
        IHttpFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpServerCustomValidationRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpServerCustomValidationRequestedEventArgs>
    {
        IHttpServerCustomValidationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHttpServerCustomValidationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
