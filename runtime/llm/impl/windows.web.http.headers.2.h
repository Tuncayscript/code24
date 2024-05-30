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
#ifndef LLM_OS_Web_Http_Headers_2_H
#define LLM_OS_Web_Http_Headers_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Globalization.1.h"
#include "llm/impl/Windows.Web.Http.1.h"
#include "llm/impl/Windows.Web.Http.Headers.1.h"
LLM_EXPORT namespace llm::OS::Web::Http::Headers
{
    struct __declspec(empty_bases) HttpCacheDirectiveHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection,
        impl::require<HttpCacheDirectiveHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpNameValueHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpNameValueHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpCacheDirectiveHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpCacheDirectiveHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpCacheDirectiveHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpChallengeHeaderValue : llm::OS::Web::Http::Headers::IHttpChallengeHeaderValue,
        impl::require<HttpChallengeHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpChallengeHeaderValue(std::nullptr_t) noexcept {}
        HttpChallengeHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpChallengeHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpChallengeHeaderValue(param::hstring const& scheme);
        HttpChallengeHeaderValue(param::hstring const& scheme, param::hstring const& token);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpChallengeHeaderValue& challengeHeaderValue);
    };
    struct __declspec(empty_bases) HttpChallengeHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpChallengeHeaderValueCollection,
        impl::require<HttpChallengeHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpChallengeHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpChallengeHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpChallengeHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpChallengeHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpChallengeHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpConnectionOptionHeaderValue : llm::OS::Web::Http::Headers::IHttpConnectionOptionHeaderValue,
        impl::require<HttpConnectionOptionHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpConnectionOptionHeaderValue(std::nullptr_t) noexcept {}
        HttpConnectionOptionHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpConnectionOptionHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpConnectionOptionHeaderValue(param::hstring const& token);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpConnectionOptionHeaderValue& connectionOptionHeaderValue);
    };
    struct __declspec(empty_bases) HttpConnectionOptionHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection,
        impl::require<HttpConnectionOptionHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpConnectionOptionHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpConnectionOptionHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpConnectionOptionHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpConnectionOptionHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpConnectionOptionHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpContentCodingHeaderValue : llm::OS::Web::Http::Headers::IHttpContentCodingHeaderValue,
        impl::require<HttpContentCodingHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpContentCodingHeaderValue(std::nullptr_t) noexcept {}
        HttpContentCodingHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentCodingHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpContentCodingHeaderValue(param::hstring const& contentCoding);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpContentCodingHeaderValue& contentCodingHeaderValue);
    };
    struct __declspec(empty_bases) HttpContentCodingHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpContentCodingHeaderValueCollection,
        impl::require<HttpContentCodingHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpContentCodingHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpContentCodingHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpContentCodingHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpContentCodingHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentCodingHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpContentCodingWithQualityHeaderValue : llm::OS::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue,
        impl::require<HttpContentCodingWithQualityHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpContentCodingWithQualityHeaderValue(std::nullptr_t) noexcept {}
        HttpContentCodingWithQualityHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpContentCodingWithQualityHeaderValue(param::hstring const& contentCoding);
        HttpContentCodingWithQualityHeaderValue(param::hstring const& contentCoding, double quality);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue& contentCodingWithQualityHeaderValue);
    };
    struct __declspec(empty_bases) HttpContentCodingWithQualityHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection,
        impl::require<HttpContentCodingWithQualityHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpContentCodingWithQualityHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpContentCodingWithQualityHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpContentCodingWithQualityHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentCodingWithQualityHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpContentDispositionHeaderValue : llm::OS::Web::Http::Headers::IHttpContentDispositionHeaderValue,
        impl::require<HttpContentDispositionHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpContentDispositionHeaderValue(std::nullptr_t) noexcept {}
        HttpContentDispositionHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentDispositionHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpContentDispositionHeaderValue(param::hstring const& dispositionType);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpContentDispositionHeaderValue& contentDispositionHeaderValue);
    };
    struct __declspec(empty_bases) HttpContentHeaderCollection : llm::OS::Web::Http::Headers::IHttpContentHeaderCollection,
        impl::require<HttpContentHeaderCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>>, llm::OS::Foundation::Collections::IMap<hstring, hstring>, llm::OS::Foundation::IStringable>
    {
        HttpContentHeaderCollection(std::nullptr_t) noexcept {}
        HttpContentHeaderCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentHeaderCollection(ptr, take_ownership_from_abi) {}
        HttpContentHeaderCollection();
    };
    struct __declspec(empty_bases) HttpContentRangeHeaderValue : llm::OS::Web::Http::Headers::IHttpContentRangeHeaderValue,
        impl::require<HttpContentRangeHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpContentRangeHeaderValue(std::nullptr_t) noexcept {}
        HttpContentRangeHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpContentRangeHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpContentRangeHeaderValue(uint64_t length);
        HttpContentRangeHeaderValue(uint64_t from, uint64_t to);
        HttpContentRangeHeaderValue(uint64_t from, uint64_t to, uint64_t length);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpContentRangeHeaderValue& contentRangeHeaderValue);
    };
    struct __declspec(empty_bases) HttpCookiePairHeaderValue : llm::OS::Web::Http::Headers::IHttpCookiePairHeaderValue,
        impl::require<HttpCookiePairHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpCookiePairHeaderValue(std::nullptr_t) noexcept {}
        HttpCookiePairHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpCookiePairHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpCookiePairHeaderValue(param::hstring const& name);
        HttpCookiePairHeaderValue(param::hstring const& name, param::hstring const& value);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpCookiePairHeaderValue& cookiePairHeaderValue);
    };
    struct __declspec(empty_bases) HttpCookiePairHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpCookiePairHeaderValueCollection,
        impl::require<HttpCookiePairHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpCookiePairHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpCookiePairHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpCookiePairHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpCookiePairHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpCookiePairHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpCredentialsHeaderValue : llm::OS::Web::Http::Headers::IHttpCredentialsHeaderValue,
        impl::require<HttpCredentialsHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpCredentialsHeaderValue(std::nullptr_t) noexcept {}
        HttpCredentialsHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpCredentialsHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpCredentialsHeaderValue(param::hstring const& scheme);
        HttpCredentialsHeaderValue(param::hstring const& scheme, param::hstring const& token);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpCredentialsHeaderValue& credentialsHeaderValue);
    };
    struct __declspec(empty_bases) HttpDateOrDeltaHeaderValue : llm::OS::Web::Http::Headers::IHttpDateOrDeltaHeaderValue,
        impl::require<HttpDateOrDeltaHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpDateOrDeltaHeaderValue(std::nullptr_t) noexcept {}
        HttpDateOrDeltaHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpDateOrDeltaHeaderValue(ptr, take_ownership_from_abi) {}
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpDateOrDeltaHeaderValue& dateOrDeltaHeaderValue);
    };
    struct __declspec(empty_bases) HttpExpectationHeaderValue : llm::OS::Web::Http::Headers::IHttpExpectationHeaderValue,
        impl::require<HttpExpectationHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpExpectationHeaderValue(std::nullptr_t) noexcept {}
        HttpExpectationHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpExpectationHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpExpectationHeaderValue(param::hstring const& name);
        HttpExpectationHeaderValue(param::hstring const& name, param::hstring const& value);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpExpectationHeaderValue& expectationHeaderValue);
    };
    struct __declspec(empty_bases) HttpExpectationHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpExpectationHeaderValueCollection,
        impl::require<HttpExpectationHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpExpectationHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpExpectationHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpExpectationHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpExpectationHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpExpectationHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpLanguageHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpLanguageHeaderValueCollection,
        impl::require<HttpLanguageHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Globalization::Language>, llm::OS::Foundation::Collections::IVector<llm::OS::Globalization::Language>, llm::OS::Foundation::IStringable>
    {
        HttpLanguageHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpLanguageHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpLanguageHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpLanguageRangeWithQualityHeaderValue : llm::OS::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue,
        impl::require<HttpLanguageRangeWithQualityHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpLanguageRangeWithQualityHeaderValue(std::nullptr_t) noexcept {}
        HttpLanguageRangeWithQualityHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpLanguageRangeWithQualityHeaderValue(param::hstring const& languageRange);
        HttpLanguageRangeWithQualityHeaderValue(param::hstring const& languageRange, double quality);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue& languageRangeWithQualityHeaderValue);
    };
    struct __declspec(empty_bases) HttpLanguageRangeWithQualityHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection,
        impl::require<HttpLanguageRangeWithQualityHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpLanguageRangeWithQualityHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpLanguageRangeWithQualityHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpLanguageRangeWithQualityHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpLanguageRangeWithQualityHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpMediaTypeHeaderValue : llm::OS::Web::Http::Headers::IHttpMediaTypeHeaderValue,
        impl::require<HttpMediaTypeHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpMediaTypeHeaderValue(std::nullptr_t) noexcept {}
        HttpMediaTypeHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpMediaTypeHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpMediaTypeHeaderValue(param::hstring const& mediaType);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpMediaTypeHeaderValue& mediaTypeHeaderValue);
    };
    struct __declspec(empty_bases) HttpMediaTypeWithQualityHeaderValue : llm::OS::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue,
        impl::require<HttpMediaTypeWithQualityHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpMediaTypeWithQualityHeaderValue(std::nullptr_t) noexcept {}
        HttpMediaTypeWithQualityHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpMediaTypeWithQualityHeaderValue(param::hstring const& mediaType);
        HttpMediaTypeWithQualityHeaderValue(param::hstring const& mediaType, double quality);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue& mediaTypeWithQualityHeaderValue);
    };
    struct __declspec(empty_bases) HttpMediaTypeWithQualityHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection,
        impl::require<HttpMediaTypeWithQualityHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpMediaTypeWithQualityHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpMediaTypeWithQualityHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpMediaTypeWithQualityHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpMediaTypeWithQualityHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpMethodHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpMethodHeaderValueCollection,
        impl::require<HttpMethodHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::HttpMethod>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::HttpMethod>, llm::OS::Foundation::IStringable>
    {
        HttpMethodHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpMethodHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpMethodHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpNameValueHeaderValue : llm::OS::Web::Http::Headers::IHttpNameValueHeaderValue,
        impl::require<HttpNameValueHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpNameValueHeaderValue(std::nullptr_t) noexcept {}
        HttpNameValueHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpNameValueHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpNameValueHeaderValue(param::hstring const& name);
        HttpNameValueHeaderValue(param::hstring const& name, param::hstring const& value);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpNameValueHeaderValue& nameValueHeaderValue);
    };
    struct __declspec(empty_bases) HttpProductHeaderValue : llm::OS::Web::Http::Headers::IHttpProductHeaderValue,
        impl::require<HttpProductHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpProductHeaderValue(std::nullptr_t) noexcept {}
        HttpProductHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpProductHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpProductHeaderValue(param::hstring const& productName);
        HttpProductHeaderValue(param::hstring const& productName, param::hstring const& productVersion);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpProductHeaderValue& productHeaderValue);
    };
    struct __declspec(empty_bases) HttpProductInfoHeaderValue : llm::OS::Web::Http::Headers::IHttpProductInfoHeaderValue,
        impl::require<HttpProductInfoHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpProductInfoHeaderValue(std::nullptr_t) noexcept {}
        HttpProductInfoHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpProductInfoHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpProductInfoHeaderValue(param::hstring const& productComment);
        HttpProductInfoHeaderValue(param::hstring const& productName, param::hstring const& productVersion);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpProductInfoHeaderValue& productInfoHeaderValue);
    };
    struct __declspec(empty_bases) HttpProductInfoHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpProductInfoHeaderValueCollection,
        impl::require<HttpProductInfoHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpProductInfoHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpProductInfoHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpProductInfoHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpProductInfoHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpProductInfoHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpRequestHeaderCollection : llm::OS::Web::Http::Headers::IHttpRequestHeaderCollection,
        impl::require<HttpRequestHeaderCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>>, llm::OS::Foundation::Collections::IMap<hstring, hstring>, llm::OS::Foundation::IStringable>
    {
        HttpRequestHeaderCollection(std::nullptr_t) noexcept {}
        HttpRequestHeaderCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpRequestHeaderCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpResponseHeaderCollection : llm::OS::Web::Http::Headers::IHttpResponseHeaderCollection,
        impl::require<HttpResponseHeaderCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>>, llm::OS::Foundation::Collections::IMap<hstring, hstring>, llm::OS::Foundation::IStringable>
    {
        HttpResponseHeaderCollection(std::nullptr_t) noexcept {}
        HttpResponseHeaderCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpResponseHeaderCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) HttpTransferCodingHeaderValue : llm::OS::Web::Http::Headers::IHttpTransferCodingHeaderValue,
        impl::require<HttpTransferCodingHeaderValue, llm::OS::Foundation::IStringable>
    {
        HttpTransferCodingHeaderValue(std::nullptr_t) noexcept {}
        HttpTransferCodingHeaderValue(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpTransferCodingHeaderValue(ptr, take_ownership_from_abi) {}
        explicit HttpTransferCodingHeaderValue(param::hstring const& input);
        static auto Parse(param::hstring const& input);
        static auto TryParse(param::hstring const& input, llm::OS::Web::Http::Headers::HttpTransferCodingHeaderValue& transferCodingHeaderValue);
    };
    struct __declspec(empty_bases) HttpTransferCodingHeaderValueCollection : llm::OS::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection,
        impl::require<HttpTransferCodingHeaderValueCollection, llm::OS::Foundation::Collections::IIterable<llm::OS::Web::Http::Headers::HttpTransferCodingHeaderValue>, llm::OS::Foundation::Collections::IVector<llm::OS::Web::Http::Headers::HttpTransferCodingHeaderValue>, llm::OS::Foundation::IStringable>
    {
        HttpTransferCodingHeaderValueCollection(std::nullptr_t) noexcept {}
        HttpTransferCodingHeaderValueCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Web::Http::Headers::IHttpTransferCodingHeaderValueCollection(ptr, take_ownership_from_abi) {}
    };
}
#endif
