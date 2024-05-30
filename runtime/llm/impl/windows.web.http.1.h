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
#ifndef LLM_OS_Web_Http_1_H
#define LLM_OS_Web_Http_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Web.Http.0.h"
LLM_EXPORT namespace llm::OS::Web::Http
{
    struct __declspec(empty_bases) IHttpBufferContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpBufferContentFactory>
    {
        IHttpBufferContentFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpBufferContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpClient :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpClient>
    {
        IHttpClient(std::nullptr_t = nullptr) noexcept {}
        IHttpClient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpClient2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpClient2>
    {
        IHttpClient2(std::nullptr_t = nullptr) noexcept {}
        IHttpClient2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpClient3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpClient3>
    {
        IHttpClient3(std::nullptr_t = nullptr) noexcept {}
        IHttpClient3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpClientFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpClientFactory>
    {
        IHttpClientFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpClientFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpContent :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpContent>,
        impl::require<llm::OS::Web::Http::IHttpContent, llm::OS::Foundation::IClosable>
    {
        IHttpContent(std::nullptr_t = nullptr) noexcept {}
        IHttpContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpCookie :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpCookie>
    {
        IHttpCookie(std::nullptr_t = nullptr) noexcept {}
        IHttpCookie(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpCookieFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpCookieFactory>
    {
        IHttpCookieFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpCookieFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpCookieManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpCookieManager>
    {
        IHttpCookieManager(std::nullptr_t = nullptr) noexcept {}
        IHttpCookieManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpFormUrlEncodedContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpFormUrlEncodedContentFactory>
    {
        IHttpFormUrlEncodedContentFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpFormUrlEncodedContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpGetBufferResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpGetBufferResult>
    {
        IHttpGetBufferResult(std::nullptr_t = nullptr) noexcept {}
        IHttpGetBufferResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpGetInputStreamResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpGetInputStreamResult>
    {
        IHttpGetInputStreamResult(std::nullptr_t = nullptr) noexcept {}
        IHttpGetInputStreamResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpGetStringResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpGetStringResult>
    {
        IHttpGetStringResult(std::nullptr_t = nullptr) noexcept {}
        IHttpGetStringResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMethod :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMethod>
    {
        IHttpMethod(std::nullptr_t = nullptr) noexcept {}
        IHttpMethod(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMethodFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMethodFactory>
    {
        IHttpMethodFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpMethodFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMethodStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMethodStatics>
    {
        IHttpMethodStatics(std::nullptr_t = nullptr) noexcept {}
        IHttpMethodStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMultipartContent :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMultipartContent>
    {
        IHttpMultipartContent(std::nullptr_t = nullptr) noexcept {}
        IHttpMultipartContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMultipartContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMultipartContentFactory>
    {
        IHttpMultipartContentFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpMultipartContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMultipartFormDataContent :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMultipartFormDataContent>
    {
        IHttpMultipartFormDataContent(std::nullptr_t = nullptr) noexcept {}
        IHttpMultipartFormDataContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpMultipartFormDataContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpMultipartFormDataContentFactory>
    {
        IHttpMultipartFormDataContentFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpMultipartFormDataContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpRequestMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpRequestMessage>
    {
        IHttpRequestMessage(std::nullptr_t = nullptr) noexcept {}
        IHttpRequestMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpRequestMessage2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpRequestMessage2>
    {
        IHttpRequestMessage2(std::nullptr_t = nullptr) noexcept {}
        IHttpRequestMessage2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpRequestMessageFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpRequestMessageFactory>
    {
        IHttpRequestMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpRequestMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpRequestResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpRequestResult>
    {
        IHttpRequestResult(std::nullptr_t = nullptr) noexcept {}
        IHttpRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpResponseMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpResponseMessage>
    {
        IHttpResponseMessage(std::nullptr_t = nullptr) noexcept {}
        IHttpResponseMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpResponseMessageFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpResponseMessageFactory>
    {
        IHttpResponseMessageFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpResponseMessageFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpStreamContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpStreamContentFactory>
    {
        IHttpStreamContentFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpStreamContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpStringContentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpStringContentFactory>
    {
        IHttpStringContentFactory(std::nullptr_t = nullptr) noexcept {}
        IHttpStringContentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHttpTransportInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IHttpTransportInformation>
    {
        IHttpTransportInformation(std::nullptr_t = nullptr) noexcept {}
        IHttpTransportInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
