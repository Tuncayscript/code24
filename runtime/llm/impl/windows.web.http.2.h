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
#ifndef LLM_OS_Web_Http_2_H
#define LLM_OS_Web_Http_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Web.Http.Filters.2.h"
#include "llm/impl/Windows.Web.Http.1.h"
LLM_EXPORT namespace llm::OS::Web::Http
{
    struct HttpProgress
    {
        llm::OS::Web::Http::HttpProgressStage Stage;
        uint64_t BytesSent;
        llm::OS::Foundation::IReference<uint64_t> TotalBytesToSend;
        uint64_t BytesReceived;
        llm::OS::Foundation::IReference<uint64_t> TotalBytesToReceive;
        uint32_t Retries;
    };
    inline bool operator==(HttpProgress const& left, HttpProgress const& right) noexcept
    {
        return left.Stage == right.Stage && left.BytesSent == right.BytesSent && left.TotalBytesToSend == right.TotalBytesToSend && left.BytesReceived == right.BytesReceived && left.TotalBytesToReceive == right.TotalBytesToReceive && left.Retries == right.Retries;
    }
    inline bool operator!=(HttpProgress const& left, HttpProgress const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) HttpBufferContent : llm::OS::Web::Http::IHttpContent,
        impl::require<HttpBufferContent, llm::OS::Foundation::IStringable>
    {
        HttpBufferContent(std::nullptr_t) noexcept {}
        HttpBufferContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpContent(ptr, take_ownership_from_abi) {}
        explicit HttpBufferContent(llm::OS::Storage::Streams::IBuffer const& content);
        HttpBufferContent(llm::OS::Storage::Streams::IBuffer const& content, uint32_t offset, uint32_t count);
    };
    struct __declspec(empty_bases) HttpClient : llm::OS::Web::Http::IHttpClient,
        impl::require<HttpClient, llm::OS::Web::Http::IHttpClient2, llm::OS::Web::Http::IHttpClient3, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpClient(std::nullptr_t) noexcept {}
        HttpClient(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpClient(ptr, take_ownership_from_abi) {}
        HttpClient();
        explicit HttpClient(llm::OS::Web::Http::Filters::IHttpFilter const& filter);
    };
    struct __declspec(empty_bases) HttpCookie : llm::OS::Web::Http::IHttpCookie,
        impl::require<HttpCookie, llm::OS::Foundation::IStringable>
    {
        HttpCookie(std::nullptr_t) noexcept {}
        HttpCookie(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpCookie(ptr, take_ownership_from_abi) {}
        HttpCookie(param::hstring const& name, param::hstring const& domain, param::hstring const& path);
    };
    struct __declspec(empty_bases) HttpCookieCollection : llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::HttpCookie>
    {
        HttpCookieCollection(std::nullptr_t) noexcept {}
        HttpCookieCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVectorView<llm::OS::Web::Http::HttpCookie>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpCookieManager : llm::OS::Web::Http::IHttpCookieManager
    {
        HttpCookieManager(std::nullptr_t) noexcept {}
        HttpCookieManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpCookieManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpFormUrlEncodedContent : llm::OS::Web::Http::IHttpContent,
        impl::require<HttpFormUrlEncodedContent, llm::OS::Foundation::IStringable>
    {
        HttpFormUrlEncodedContent(std::nullptr_t) noexcept {}
        HttpFormUrlEncodedContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpContent(ptr, take_ownership_from_abi) {}
        explicit HttpFormUrlEncodedContent(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const& content);
    };
    struct __declspec(empty_bases) HttpGetBufferResult : llm::OS::Web::Http::IHttpGetBufferResult,
        impl::require<HttpGetBufferResult, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpGetBufferResult(std::nullptr_t) noexcept {}
        HttpGetBufferResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpGetBufferResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpGetInputStreamResult : llm::OS::Web::Http::IHttpGetInputStreamResult,
        impl::require<HttpGetInputStreamResult, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpGetInputStreamResult(std::nullptr_t) noexcept {}
        HttpGetInputStreamResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpGetInputStreamResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpGetStringResult : llm::OS::Web::Http::IHttpGetStringResult,
        impl::require<HttpGetStringResult, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpGetStringResult(std::nullptr_t) noexcept {}
        HttpGetStringResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpGetStringResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpMethod : llm::OS::Web::Http::IHttpMethod,
        impl::require<HttpMethod, llm::OS::Foundation::IStringable>
    {
        HttpMethod(std::nullptr_t) noexcept {}
        HttpMethod(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpMethod(ptr, take_ownership_from_abi) {}
        explicit HttpMethod(param::hstring const& method);
        [[nodiscard]] static auto Delete();
        [[nodiscard]] static auto Get();
        [[nodiscard]] static auto Head();
        [[nodiscard]] static auto Options();
        [[nodiscard]] static auto Patch();
        [[nodiscard]] static auto Post();
        [[nodiscard]] static auto Put();
    };
    struct __declspec(empty_bases) HttpMultipartContent : llm::OS::Web::Http::IHttpContent,
        impl::require<HttpMultipartContent, llm::OS::Web::Http::IHttpMultipartContent, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::IHttpContent>, llm::OS::Foundation::IStringable>
    {
        HttpMultipartContent(std::nullptr_t) noexcept {}
        HttpMultipartContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpContent(ptr, take_ownership_from_abi) {}
        HttpMultipartContent();
        explicit HttpMultipartContent(param::hstring const& subtype);
        HttpMultipartContent(param::hstring const& subtype, param::hstring const& boundary);
    };
    struct __declspec(empty_bases) HttpMultipartFormDataContent : llm::OS::Web::Http::IHttpContent,
        impl::require<HttpMultipartFormDataContent, llm::OS::Web::Http::IHttpMultipartFormDataContent, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::IHttpContent>, llm::OS::Foundation::IStringable>
    {
        HttpMultipartFormDataContent(std::nullptr_t) noexcept {}
        HttpMultipartFormDataContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpContent(ptr, take_ownership_from_abi) {}
        HttpMultipartFormDataContent();
        explicit HttpMultipartFormDataContent(param::hstring const& boundary);
    };
    struct __declspec(empty_bases) HttpRequestMessage : llm::OS::Web::Http::IHttpRequestMessage,
        impl::require<HttpRequestMessage, llm::OS::Web::Http::IHttpRequestMessage2, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpRequestMessage(std::nullptr_t) noexcept {}
        HttpRequestMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpRequestMessage(ptr, take_ownership_from_abi) {}
        HttpRequestMessage();
        HttpRequestMessage(llm::OS::Web::Http::HttpMethod const& method, llm::OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) HttpRequestResult : llm::OS::Web::Http::IHttpRequestResult,
        impl::require<HttpRequestResult, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpRequestResult(std::nullptr_t) noexcept {}
        HttpRequestResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpRequestResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpResponseMessage : llm::OS::Web::Http::IHttpResponseMessage,
        impl::require<HttpResponseMessage, llm::OS::Foundation::IClosable, llm::OS::Foundation::IStringable>
    {
        HttpResponseMessage(std::nullptr_t) noexcept {}
        HttpResponseMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpResponseMessage(ptr, take_ownership_from_abi) {}
        HttpResponseMessage();
        explicit HttpResponseMessage(llm::OS::Web::Http::HttpStatusCode const& statusCode);
    };
    struct __declspec(empty_bases) HttpStreamContent : llm::OS::Web::Http::IHttpContent,
        impl::require<HttpStreamContent, llm::OS::Foundation::IStringable>
    {
        HttpStreamContent(std::nullptr_t) noexcept {}
        HttpStreamContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpContent(ptr, take_ownership_from_abi) {}
        explicit HttpStreamContent(llm::OS::Storage::Streams::IInputStream const& content);
    };
    struct __declspec(empty_bases) HttpStringContent : llm::OS::Web::Http::IHttpContent,
        impl::require<HttpStringContent, llm::OS::Foundation::IStringable>
    {
        HttpStringContent(std::nullptr_t) noexcept {}
        HttpStringContent(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpContent(ptr, take_ownership_from_abi) {}
        explicit HttpStringContent(param::hstring const& content);
        HttpStringContent(param::hstring const& content, llm::OS::Storage::Streams::UnicodeEncoding const& encoding);
        HttpStringContent(param::hstring const& content, llm::OS::Storage::Streams::UnicodeEncoding const& encoding, param::hstring const& mediaType);
    };
    struct __declspec(empty_bases) HttpTransportInformation : llm::OS::Web::Http::IHttpTransportInformation,
        impl::require<HttpTransportInformation, llm::OS::Foundation::IStringable>
    {
        HttpTransportInformation(std::nullptr_t) noexcept {}
        HttpTransportInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::IHttpTransportInformation(ptr, take_ownership_from_abi) {}
    };
}
#endif
