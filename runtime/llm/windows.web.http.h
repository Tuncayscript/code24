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
#ifndef LLM_OS_Web_Http_H
#define LLM_OS_Web_Http_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Web.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.Sockets.2.h"
#include "llm/impl/Windows.Security.Cryptography.Certificates.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Web.Http.Filters.2.h"
#include "llm/impl/Windows.Web.Http.Headers.2.h"
#include "llm/impl/Windows.Web.Http.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpBufferContent) consume_Windows_Web_Http_IHttpBufferContentFactory<D>::CreateFromBuffer(llm::OS::Storage::Streams::IBuffer const& content) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpBufferContentFactory)->CreateFromBuffer(*(void**)(&content), &value));
        return llm::OS::Web::Http::HttpBufferContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpBufferContent) consume_Windows_Web_Http_IHttpBufferContentFactory<D>::CreateFromBufferWithOffset(llm::OS::Storage::Streams::IBuffer const& content, uint32_t offset, uint32_t count) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpBufferContentFactory)->CreateFromBufferWithOffset(*(void**)(&content), offset, count, &value));
        return llm::OS::Web::Http::HttpBufferContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::DeleteAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->DeleteAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::GetAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->GetAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::GetAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::HttpCompletionOption const& completionOption) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->GetWithOptionAsync(*(void**)(&uri), static_cast<int32_t>(completionOption), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IBuffer, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::GetBufferAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->GetBufferAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IBuffer, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IInputStream, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::GetInputStreamAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->GetInputStreamAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IInputStream, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<hstring, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::GetStringAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->GetStringAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<hstring, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::PostAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::IHttpContent const& content) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->PostAsync(*(void**)(&uri), *(void**)(&content), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::PutAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::IHttpContent const& content) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->PutAsync(*(void**)(&uri), *(void**)(&content), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::SendRequestAsync(llm::OS::Web::Http::HttpRequestMessage const& request) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->SendRequestAsync(*(void**)(&request), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient<D>::SendRequestAsync(llm::OS::Web::Http::HttpRequestMessage const& request, llm::OS::Web::Http::HttpCompletionOption const& completionOption) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->SendRequestWithOptionAsync(*(void**)(&request), static_cast<int32_t>(completionOption), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Headers::HttpRequestHeaderCollection) consume_Windows_Web_Http_IHttpClient<D>::DefaultRequestHeaders() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient)->get_DefaultRequestHeaders(&value));
        return llm::OS::Web::Http::Headers::HttpRequestHeaderCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryDeleteAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryDeleteAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryGetAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryGetAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryGetAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::HttpCompletionOption const& completionOption) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryGetAsync2(*(void**)(&uri), static_cast<int32_t>(completionOption), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetBufferResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryGetBufferAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryGetBufferAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetBufferResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetInputStreamResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryGetInputStreamAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryGetInputStreamAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetInputStreamResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetStringResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryGetStringAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryGetStringAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetStringResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryPostAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::IHttpContent const& content) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryPostAsync(*(void**)(&uri), *(void**)(&content), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TryPutAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Web::Http::IHttpContent const& content) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TryPutAsync(*(void**)(&uri), *(void**)(&content), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TrySendRequestAsync(llm::OS::Web::Http::HttpRequestMessage const& request) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TrySendRequestAsync(*(void**)(&request), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>) consume_Windows_Web_Http_IHttpClient2<D>::TrySendRequestAsync(llm::OS::Web::Http::HttpRequestMessage const& request, llm::OS::Web::Http::HttpCompletionOption const& completionOption) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient2)->TrySendRequestAsync2(*(void**)(&request), static_cast<int32_t>(completionOption), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpClient3<D>::DefaultPrivacyAnnotation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient3)->get_DefaultPrivacyAnnotation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpClient3<D>::DefaultPrivacyAnnotation(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClient3)->put_DefaultPrivacyAnnotation(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpClient) consume_Windows_Web_Http_IHttpClientFactory<D>::Create(llm::OS::Web::Http::Filters::IHttpFilter const& filter) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpClientFactory)->Create(*(void**)(&filter), &value));
        return llm::OS::Web::Http::HttpClient{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Headers::HttpContentHeaderCollection) consume_Windows_Web_Http_IHttpContent<D>::Headers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->get_Headers(&value));
        return llm::OS::Web::Http::Headers::HttpContentHeaderCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>) consume_Windows_Web_Http_IHttpContent<D>::BufferAllAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->BufferAllAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IBuffer, uint64_t>) consume_Windows_Web_Http_IHttpContent<D>::ReadAsBufferAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->ReadAsBufferAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IBuffer, uint64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IInputStream, uint64_t>) consume_Windows_Web_Http_IHttpContent<D>::ReadAsInputStreamAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->ReadAsInputStreamAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IInputStream, uint64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<hstring, uint64_t>) consume_Windows_Web_Http_IHttpContent<D>::ReadAsStringAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->ReadAsStringAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<hstring, uint64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpContent<D>::TryComputeLength(uint64_t& length) const
    {
        bool succeeded{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->TryComputeLength(&length, &succeeded));
        return succeeded;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>) consume_Windows_Web_Http_IHttpContent<D>::WriteToStreamAsync(llm::OS::Storage::Streams::IOutputStream const& outputStream) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpContent)->WriteToStreamAsync(*(void**)(&outputStream), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpCookie<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpCookie<D>::Domain() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_Domain(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpCookie<D>::Path() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_Path(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Web_Http_IHttpCookie<D>::Expires() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_Expires(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpCookie<D>::Expires(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->put_Expires(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpCookie<D>::HttpOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_HttpOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpCookie<D>::HttpOnly(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->put_HttpOnly(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpCookie<D>::Secure() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_Secure(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpCookie<D>::Secure(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->put_Secure(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpCookie<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->get_Value(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpCookie<D>::Value(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookie)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpCookie) consume_Windows_Web_Http_IHttpCookieFactory<D>::Create(param::hstring const& name, param::hstring const& domain, param::hstring const& path) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookieFactory)->Create(*(void**)(&name), *(void**)(&domain), *(void**)(&path), &value));
        return llm::OS::Web::Http::HttpCookie{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpCookieManager<D>::SetCookie(llm::OS::Web::Http::HttpCookie const& cookie) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookieManager)->SetCookie(*(void**)(&cookie), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpCookieManager<D>::SetCookie(llm::OS::Web::Http::HttpCookie const& cookie, bool thirdParty) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookieManager)->SetCookieWithThirdParty(*(void**)(&cookie), thirdParty, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpCookieManager<D>::DeleteCookie(llm::OS::Web::Http::HttpCookie const& cookie) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookieManager)->DeleteCookie(*(void**)(&cookie)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpCookieCollection) consume_Windows_Web_Http_IHttpCookieManager<D>::GetCookies(llm::OS::Foundation::Uri const& uri) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpCookieManager)->GetCookies(*(void**)(&uri), &result));
        return llm::OS::Web::Http::HttpCookieCollection{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpFormUrlEncodedContent) consume_Windows_Web_Http_IHttpFormUrlEncodedContentFactory<D>::Create(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const& content) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpFormUrlEncodedContentFactory)->Create(*(void**)(&content), &value));
        return llm::OS::Web::Http::HttpFormUrlEncodedContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Web_Http_IHttpGetBufferResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetBufferResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_IHttpGetBufferResult<D>::RequestMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetBufferResult)->get_RequestMessage(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_IHttpGetBufferResult<D>::ResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetBufferResult)->get_ResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpGetBufferResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetBufferResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Web_Http_IHttpGetBufferResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetBufferResult)->get_Value(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Web_Http_IHttpGetInputStreamResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetInputStreamResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_IHttpGetInputStreamResult<D>::RequestMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetInputStreamResult)->get_RequestMessage(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_IHttpGetInputStreamResult<D>::ResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetInputStreamResult)->get_ResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpGetInputStreamResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetInputStreamResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_Web_Http_IHttpGetInputStreamResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetInputStreamResult)->get_Value(&value));
        return llm::OS::Storage::Streams::IInputStream{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Web_Http_IHttpGetStringResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetStringResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_IHttpGetStringResult<D>::RequestMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetStringResult)->get_RequestMessage(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_IHttpGetStringResult<D>::ResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetStringResult)->get_ResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpGetStringResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetStringResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpGetStringResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpGetStringResult)->get_Value(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpMethod<D>::Method() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethod)->get_Method(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodFactory<D>::Create(param::hstring const& method) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodFactory)->Create(*(void**)(&method), &value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Delete() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Delete(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Get() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Get(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Head() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Head(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Options() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Options(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Patch() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Patch(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Post() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Post(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpMethodStatics<D>::Put() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMethodStatics)->get_Put(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpMultipartContent<D>::Add(llm::OS::Web::Http::IHttpContent const& content) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartContent)->Add(*(void**)(&content)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMultipartContent) consume_Windows_Web_Http_IHttpMultipartContentFactory<D>::CreateWithSubtype(param::hstring const& subtype) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartContentFactory)->CreateWithSubtype(*(void**)(&subtype), &value));
        return llm::OS::Web::Http::HttpMultipartContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMultipartContent) consume_Windows_Web_Http_IHttpMultipartContentFactory<D>::CreateWithSubtypeAndBoundary(param::hstring const& subtype, param::hstring const& boundary) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartContentFactory)->CreateWithSubtypeAndBoundary(*(void**)(&subtype), *(void**)(&boundary), &value));
        return llm::OS::Web::Http::HttpMultipartContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpMultipartFormDataContent<D>::Add(llm::OS::Web::Http::IHttpContent const& content) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartFormDataContent)->Add(*(void**)(&content)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpMultipartFormDataContent<D>::Add(llm::OS::Web::Http::IHttpContent const& content, param::hstring const& name) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartFormDataContent)->AddWithName(*(void**)(&content), *(void**)(&name)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpMultipartFormDataContent<D>::Add(llm::OS::Web::Http::IHttpContent const& content, param::hstring const& name, param::hstring const& fileName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartFormDataContent)->AddWithNameAndFileName(*(void**)(&content), *(void**)(&name), *(void**)(&fileName)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMultipartFormDataContent) consume_Windows_Web_Http_IHttpMultipartFormDataContentFactory<D>::CreateWithBoundary(param::hstring const& boundary) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpMultipartFormDataContentFactory)->CreateWithBoundary(*(void**)(&boundary), &value));
        return llm::OS::Web::Http::HttpMultipartFormDataContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::IHttpContent) consume_Windows_Web_Http_IHttpRequestMessage<D>::Content() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->get_Content(&value));
        return llm::OS::Web::Http::IHttpContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpRequestMessage<D>::Content(llm::OS::Web::Http::IHttpContent const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->put_Content(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Headers::HttpRequestHeaderCollection) consume_Windows_Web_Http_IHttpRequestMessage<D>::Headers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->get_Headers(&value));
        return llm::OS::Web::Http::Headers::HttpRequestHeaderCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpMethod) consume_Windows_Web_Http_IHttpRequestMessage<D>::Method() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->get_Method(&value));
        return llm::OS::Web::Http::HttpMethod{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpRequestMessage<D>::Method(llm::OS::Web::Http::HttpMethod const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->put_Method(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Web_Http_IHttpRequestMessage<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Web_Http_IHttpRequestMessage<D>::RequestUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->get_RequestUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpRequestMessage<D>::RequestUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->put_RequestUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpTransportInformation) consume_Windows_Web_Http_IHttpRequestMessage<D>::TransportInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage)->get_TransportInformation(&value));
        return llm::OS::Web::Http::HttpTransportInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpRequestMessage2<D>::PrivacyAnnotation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage2)->get_PrivacyAnnotation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpRequestMessage2<D>::PrivacyAnnotation(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessage2)->put_PrivacyAnnotation(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_IHttpRequestMessageFactory<D>::Create(llm::OS::Web::Http::HttpMethod const& method, llm::OS::Foundation::Uri const& uri) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestMessageFactory)->Create(*(void**)(&method), *(void**)(&uri), &value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Web_Http_IHttpRequestResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_IHttpRequestResult<D>::RequestMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestResult)->get_RequestMessage(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_IHttpRequestResult<D>::ResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestResult)->get_ResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpRequestResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpRequestResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::IHttpContent) consume_Windows_Web_Http_IHttpResponseMessage<D>::Content() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_Content(&value));
        return llm::OS::Web::Http::IHttpContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpResponseMessage<D>::Content(llm::OS::Web::Http::IHttpContent const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->put_Content(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::Headers::HttpResponseHeaderCollection) consume_Windows_Web_Http_IHttpResponseMessage<D>::Headers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_Headers(&value));
        return llm::OS::Web::Http::Headers::HttpResponseHeaderCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Web_Http_IHttpResponseMessage<D>::IsSuccessStatusCode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_IsSuccessStatusCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Web_Http_IHttpResponseMessage<D>::ReasonPhrase() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_ReasonPhrase(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpResponseMessage<D>::ReasonPhrase(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->put_ReasonPhrase(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_Web_Http_IHttpResponseMessage<D>::RequestMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_RequestMessage(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpResponseMessage<D>::RequestMessage(llm::OS::Web::Http::HttpRequestMessage const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->put_RequestMessage(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessageSource) consume_Windows_Web_Http_IHttpResponseMessage<D>::Source() const
    {
        llm::OS::Web::Http::HttpResponseMessageSource value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_Source(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpResponseMessage<D>::Source(llm::OS::Web::Http::HttpResponseMessageSource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->put_Source(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpStatusCode) consume_Windows_Web_Http_IHttpResponseMessage<D>::StatusCode() const
    {
        llm::OS::Web::Http::HttpStatusCode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_StatusCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpResponseMessage<D>::StatusCode(llm::OS::Web::Http::HttpStatusCode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->put_StatusCode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpVersion) consume_Windows_Web_Http_IHttpResponseMessage<D>::Version() const
    {
        llm::OS::Web::Http::HttpVersion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->get_Version(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Web_Http_IHttpResponseMessage<D>::Version(llm::OS::Web::Http::HttpVersion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->put_Version(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_IHttpResponseMessage<D>::EnsureSuccessStatusCode() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessage)->EnsureSuccessStatusCode(&result));
        return llm::OS::Web::Http::HttpResponseMessage{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_Web_Http_IHttpResponseMessageFactory<D>::Create(llm::OS::Web::Http::HttpStatusCode const& statusCode) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpResponseMessageFactory)->Create(static_cast<int32_t>(statusCode), &value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpStreamContent) consume_Windows_Web_Http_IHttpStreamContentFactory<D>::CreateFromInputStream(llm::OS::Storage::Streams::IInputStream const& content) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpStreamContentFactory)->CreateFromInputStream(*(void**)(&content), &value));
        return llm::OS::Web::Http::HttpStreamContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpStringContent) consume_Windows_Web_Http_IHttpStringContentFactory<D>::CreateFromString(param::hstring const& content) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpStringContentFactory)->CreateFromString(*(void**)(&content), &value));
        return llm::OS::Web::Http::HttpStringContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpStringContent) consume_Windows_Web_Http_IHttpStringContentFactory<D>::CreateFromStringWithEncoding(param::hstring const& content, llm::OS::Storage::Streams::UnicodeEncoding const& encoding) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpStringContentFactory)->CreateFromStringWithEncoding(*(void**)(&content), static_cast<int32_t>(encoding), &value));
        return llm::OS::Web::Http::HttpStringContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpStringContent) consume_Windows_Web_Http_IHttpStringContentFactory<D>::CreateFromStringWithEncodingAndMediaType(param::hstring const& content, llm::OS::Storage::Streams::UnicodeEncoding const& encoding, param::hstring const& mediaType) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpStringContentFactory)->CreateFromStringWithEncodingAndMediaType(*(void**)(&content), static_cast<int32_t>(encoding), *(void**)(&mediaType), &value));
        return llm::OS::Web::Http::HttpStringContent{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Cryptography::Certificates::Certificate) consume_Windows_Web_Http_IHttpTransportInformation<D>::ServerCertificate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpTransportInformation)->get_ServerCertificate(&value));
        return llm::OS::Security::Cryptography::Certificates::Certificate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::SocketSslErrorSeverity) consume_Windows_Web_Http_IHttpTransportInformation<D>::ServerCertificateErrorSeverity() const
    {
        llm::OS::Networking::Sockets::SocketSslErrorSeverity value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpTransportInformation)->get_ServerCertificateErrorSeverity(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Cryptography::Certificates::ChainValidationResult>) consume_Windows_Web_Http_IHttpTransportInformation<D>::ServerCertificateErrors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpTransportInformation)->get_ServerCertificateErrors(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Cryptography::Certificates::ChainValidationResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Cryptography::Certificates::Certificate>) consume_Windows_Web_Http_IHttpTransportInformation<D>::ServerIntermediateCertificates() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::Http::IHttpTransportInformation)->get_ServerIntermediateCertificates(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Cryptography::Certificates::Certificate>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpBufferContentFactory> : produce_base<D, llm::OS::Web::Http::IHttpBufferContentFactory>
    {
        int32_t __stdcall CreateFromBuffer(void* content, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpBufferContent>(this->shim().CreateFromBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromBufferWithOffset(void* content, uint32_t offset, uint32_t count, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpBufferContent>(this->shim().CreateFromBufferWithOffset(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&content), offset, count));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpClient> : produce_base<D, llm::OS::Web::Http::IHttpClient>
    {
        int32_t __stdcall DeleteAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().DeleteAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().GetAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetWithOptionAsync(void* uri, int32_t completionOption, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().GetAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::HttpCompletionOption const*>(&completionOption)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBufferAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IBuffer, llm::OS::Web::Http::HttpProgress>>(this->shim().GetBufferAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetInputStreamAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IInputStream, llm::OS::Web::Http::HttpProgress>>(this->shim().GetInputStreamAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetStringAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<hstring, llm::OS::Web::Http::HttpProgress>>(this->shim().GetStringAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PostAsync(void* uri, void* content, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().PostAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PutAsync(void* uri, void* content, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().PutAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendRequestAsync(void* request, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().SendRequestAsync(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendRequestWithOptionAsync(void* request, int32_t completionOption, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpResponseMessage, llm::OS::Web::Http::HttpProgress>>(this->shim().SendRequestAsync(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request), *reinterpret_cast<llm::OS::Web::Http::HttpCompletionOption const*>(&completionOption)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultRequestHeaders(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Headers::HttpRequestHeaderCollection>(this->shim().DefaultRequestHeaders());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpClient2> : produce_base<D, llm::OS::Web::Http::IHttpClient2>
    {
        int32_t __stdcall TryDeleteAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryDeleteAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryGetAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetAsync2(void* uri, int32_t completionOption, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryGetAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::HttpCompletionOption const*>(&completionOption)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetBufferAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetBufferResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryGetBufferAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetInputStreamAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetInputStreamResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryGetInputStreamAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetStringAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpGetStringResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryGetStringAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryPostAsync(void* uri, void* content, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryPostAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryPutAsync(void* uri, void* content, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TryPutAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri), *reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySendRequestAsync(void* request, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TrySendRequestAsync(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySendRequestAsync2(void* request, int32_t completionOption, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Web::Http::HttpRequestResult, llm::OS::Web::Http::HttpProgress>>(this->shim().TrySendRequestAsync(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request), *reinterpret_cast<llm::OS::Web::Http::HttpCompletionOption const*>(&completionOption)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpClient3> : produce_base<D, llm::OS::Web::Http::IHttpClient3>
    {
        int32_t __stdcall get_DefaultPrivacyAnnotation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DefaultPrivacyAnnotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DefaultPrivacyAnnotation(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultPrivacyAnnotation(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpClientFactory> : produce_base<D, llm::OS::Web::Http::IHttpClientFactory>
    {
        int32_t __stdcall Create(void* filter, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpClient>(this->shim().Create(*reinterpret_cast<llm::OS::Web::Http::Filters::IHttpFilter const*>(&filter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpContent> : produce_base<D, llm::OS::Web::Http::IHttpContent>
    {
        int32_t __stdcall get_Headers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Headers::HttpContentHeaderCollection>(this->shim().Headers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall BufferAllAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>>(this->shim().BufferAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadAsBufferAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IBuffer, uint64_t>>(this->shim().ReadAsBufferAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadAsInputStreamAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Storage::Streams::IInputStream, uint64_t>>(this->shim().ReadAsInputStreamAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadAsStringAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<hstring, uint64_t>>(this->shim().ReadAsStringAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryComputeLength(uint64_t* length, bool* succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_from<bool>(this->shim().TryComputeLength(*length));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall WriteToStreamAsync(void* outputStream, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<uint64_t, uint64_t>>(this->shim().WriteToStreamAsync(*reinterpret_cast<llm::OS::Storage::Streams::IOutputStream const*>(&outputStream)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpCookie> : produce_base<D, llm::OS::Web::Http::IHttpCookie>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Domain(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Domain());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Path(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Path());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Expires(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().Expires());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Expires(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Expires(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HttpOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HttpOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HttpOnly(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HttpOnly(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Secure(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Secure());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Secure(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Secure(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpCookieFactory> : produce_base<D, llm::OS::Web::Http::IHttpCookieFactory>
    {
        int32_t __stdcall Create(void* name, void* domain, void* path, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpCookie>(this->shim().Create(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<hstring const*>(&domain), *reinterpret_cast<hstring const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpCookieManager> : produce_base<D, llm::OS::Web::Http::IHttpCookieManager>
    {
        int32_t __stdcall SetCookie(void* cookie, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().SetCookie(*reinterpret_cast<llm::OS::Web::Http::HttpCookie const*>(&cookie)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCookieWithThirdParty(void* cookie, bool thirdParty, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().SetCookie(*reinterpret_cast<llm::OS::Web::Http::HttpCookie const*>(&cookie), thirdParty));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteCookie(void* cookie) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeleteCookie(*reinterpret_cast<llm::OS::Web::Http::HttpCookie const*>(&cookie));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCookies(void* uri, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Web::Http::HttpCookieCollection>(this->shim().GetCookies(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpFormUrlEncodedContentFactory> : produce_base<D, llm::OS::Web::Http::IHttpFormUrlEncodedContentFactory>
    {
        int32_t __stdcall Create(void* content, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpFormUrlEncodedContent>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpGetBufferResult> : produce_base<D, llm::OS::Web::Http::IHttpGetBufferResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().RequestMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().ResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpGetInputStreamResult> : produce_base<D, llm::OS::Web::Http::IHttpGetInputStreamResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().RequestMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().ResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpGetStringResult> : produce_base<D, llm::OS::Web::Http::IHttpGetStringResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().RequestMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().ResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMethod> : produce_base<D, llm::OS::Web::Http::IHttpMethod>
    {
        int32_t __stdcall get_Method(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Method());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMethodFactory> : produce_base<D, llm::OS::Web::Http::IHttpMethodFactory>
    {
        int32_t __stdcall Create(void* method, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Create(*reinterpret_cast<hstring const*>(&method)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMethodStatics> : produce_base<D, llm::OS::Web::Http::IHttpMethodStatics>
    {
        int32_t __stdcall get_Delete(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Delete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Get(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Get());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Head(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Head());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Options(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Options());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Patch(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Patch());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Post(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Post());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Put(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Put());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMultipartContent> : produce_base<D, llm::OS::Web::Http::IHttpMultipartContent>
    {
        int32_t __stdcall Add(void* content) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMultipartContentFactory> : produce_base<D, llm::OS::Web::Http::IHttpMultipartContentFactory>
    {
        int32_t __stdcall CreateWithSubtype(void* subtype, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMultipartContent>(this->shim().CreateWithSubtype(*reinterpret_cast<hstring const*>(&subtype)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithSubtypeAndBoundary(void* subtype, void* boundary, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMultipartContent>(this->shim().CreateWithSubtypeAndBoundary(*reinterpret_cast<hstring const*>(&subtype), *reinterpret_cast<hstring const*>(&boundary)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMultipartFormDataContent> : produce_base<D, llm::OS::Web::Http::IHttpMultipartFormDataContent>
    {
        int32_t __stdcall Add(void* content) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddWithName(void* content, void* name) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content), *reinterpret_cast<hstring const*>(&name));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddWithNameAndFileName(void* content, void* name, void* fileName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&content), *reinterpret_cast<hstring const*>(&name), *reinterpret_cast<hstring const*>(&fileName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpMultipartFormDataContentFactory> : produce_base<D, llm::OS::Web::Http::IHttpMultipartFormDataContentFactory>
    {
        int32_t __stdcall CreateWithBoundary(void* boundary, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMultipartFormDataContent>(this->shim().CreateWithBoundary(*reinterpret_cast<hstring const*>(&boundary)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpRequestMessage> : produce_base<D, llm::OS::Web::Http::IHttpRequestMessage>
    {
        int32_t __stdcall get_Content(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::IHttpContent>(this->shim().Content());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Content(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Headers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Headers::HttpRequestHeaderCollection>(this->shim().Headers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Method(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpMethod>(this->shim().Method());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Method(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Method(*reinterpret_cast<llm::OS::Web::Http::HttpMethod const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().RequestUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RequestUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransportInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpTransportInformation>(this->shim().TransportInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpRequestMessage2> : produce_base<D, llm::OS::Web::Http::IHttpRequestMessage2>
    {
        int32_t __stdcall get_PrivacyAnnotation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PrivacyAnnotation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PrivacyAnnotation(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrivacyAnnotation(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpRequestMessageFactory> : produce_base<D, llm::OS::Web::Http::IHttpRequestMessageFactory>
    {
        int32_t __stdcall Create(void* method, void* uri, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().Create(*reinterpret_cast<llm::OS::Web::Http::HttpMethod const*>(&method), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpRequestResult> : produce_base<D, llm::OS::Web::Http::IHttpRequestResult>
    {
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().RequestMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().ResponseMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpResponseMessage> : produce_base<D, llm::OS::Web::Http::IHttpResponseMessage>
    {
        int32_t __stdcall get_Content(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::IHttpContent>(this->shim().Content());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Content(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<llm::OS::Web::Http::IHttpContent const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Headers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::Headers::HttpResponseHeaderCollection>(this->shim().Headers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSuccessStatusCode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSuccessStatusCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReasonPhrase(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ReasonPhrase());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReasonPhrase(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReasonPhrase(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpRequestMessage>(this->shim().RequestMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RequestMessage(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMessage(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Source(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessageSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<llm::OS::Web::Http::HttpResponseMessageSource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StatusCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpStatusCode>(this->shim().StatusCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StatusCode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusCode(*reinterpret_cast<llm::OS::Web::Http::HttpStatusCode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Version(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpVersion>(this->shim().Version());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Version(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Version(*reinterpret_cast<llm::OS::Web::Http::HttpVersion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnsureSuccessStatusCode(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().EnsureSuccessStatusCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpResponseMessageFactory> : produce_base<D, llm::OS::Web::Http::IHttpResponseMessageFactory>
    {
        int32_t __stdcall Create(int32_t statusCode, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpResponseMessage>(this->shim().Create(*reinterpret_cast<llm::OS::Web::Http::HttpStatusCode const*>(&statusCode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpStreamContentFactory> : produce_base<D, llm::OS::Web::Http::IHttpStreamContentFactory>
    {
        int32_t __stdcall CreateFromInputStream(void* content, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpStreamContent>(this->shim().CreateFromInputStream(*reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpStringContentFactory> : produce_base<D, llm::OS::Web::Http::IHttpStringContentFactory>
    {
        int32_t __stdcall CreateFromString(void* content, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpStringContent>(this->shim().CreateFromString(*reinterpret_cast<hstring const*>(&content)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromStringWithEncoding(void* content, int32_t encoding, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpStringContent>(this->shim().CreateFromStringWithEncoding(*reinterpret_cast<hstring const*>(&content), *reinterpret_cast<llm::OS::Storage::Streams::UnicodeEncoding const*>(&encoding)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromStringWithEncodingAndMediaType(void* content, int32_t encoding, void* mediaType, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Web::Http::HttpStringContent>(this->shim().CreateFromStringWithEncodingAndMediaType(*reinterpret_cast<hstring const*>(&content), *reinterpret_cast<llm::OS::Storage::Streams::UnicodeEncoding const*>(&encoding), *reinterpret_cast<hstring const*>(&mediaType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::Http::IHttpTransportInformation> : produce_base<D, llm::OS::Web::Http::IHttpTransportInformation>
    {
        int32_t __stdcall get_ServerCertificate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Cryptography::Certificates::Certificate>(this->shim().ServerCertificate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServerCertificateErrorSeverity(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Sockets::SocketSslErrorSeverity>(this->shim().ServerCertificateErrorSeverity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServerCertificateErrors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Cryptography::Certificates::ChainValidationResult>>(this->shim().ServerCertificateErrors());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServerIntermediateCertificates(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Security::Cryptography::Certificates::Certificate>>(this->shim().ServerIntermediateCertificates());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Web::Http
{
    inline HttpBufferContent::HttpBufferContent(llm::OS::Storage::Streams::IBuffer const& content) :
        HttpBufferContent(impl::call_factory<HttpBufferContent, IHttpBufferContentFactory>([&](IHttpBufferContentFactory const& f) { return f.CreateFromBuffer(content); }))
    {
    }
    inline HttpBufferContent::HttpBufferContent(llm::OS::Storage::Streams::IBuffer const& content, uint32_t offset, uint32_t count) :
        HttpBufferContent(impl::call_factory<HttpBufferContent, IHttpBufferContentFactory>([&](IHttpBufferContentFactory const& f) { return f.CreateFromBufferWithOffset(content, offset, count); }))
    {
    }
    inline HttpClient::HttpClient() :
        HttpClient(impl::call_factory_cast<HttpClient(*)(llm::OS::Foundation::IActivationFactory const&), HttpClient>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<HttpClient>(); }))
    {
    }
    inline HttpClient::HttpClient(llm::OS::Web::Http::Filters::IHttpFilter const& filter) :
        HttpClient(impl::call_factory<HttpClient, IHttpClientFactory>([&](IHttpClientFactory const& f) { return f.Create(filter); }))
    {
    }
    inline HttpCookie::HttpCookie(param::hstring const& name, param::hstring const& domain, param::hstring const& path) :
        HttpCookie(impl::call_factory<HttpCookie, IHttpCookieFactory>([&](IHttpCookieFactory const& f) { return f.Create(name, domain, path); }))
    {
    }
    inline HttpFormUrlEncodedContent::HttpFormUrlEncodedContent(param::iterable<llm::OS::Foundation::Collections::IKeyValuePair<hstring, hstring>> const& content) :
        HttpFormUrlEncodedContent(impl::call_factory<HttpFormUrlEncodedContent, IHttpFormUrlEncodedContentFactory>([&](IHttpFormUrlEncodedContentFactory const& f) { return f.Create(content); }))
    {
    }
    inline HttpMethod::HttpMethod(param::hstring const& method) :
        HttpMethod(impl::call_factory<HttpMethod, IHttpMethodFactory>([&](IHttpMethodFactory const& f) { return f.Create(method); }))
    {
    }
    inline auto HttpMethod::Delete()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Delete(); });
    }
    inline auto HttpMethod::Get()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Get(); });
    }
    inline auto HttpMethod::Head()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Head(); });
    }
    inline auto HttpMethod::Options()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Options(); });
    }
    inline auto HttpMethod::Patch()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Patch(); });
    }
    inline auto HttpMethod::Post()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Post(); });
    }
    inline auto HttpMethod::Put()
    {
        return impl::call_factory_cast<llm::OS::Web::Http::HttpMethod(*)(IHttpMethodStatics const&), HttpMethod, IHttpMethodStatics>([](IHttpMethodStatics const& f) { return f.Put(); });
    }
    inline HttpMultipartContent::HttpMultipartContent() :
        HttpMultipartContent(impl::call_factory_cast<HttpMultipartContent(*)(llm::OS::Foundation::IActivationFactory const&), HttpMultipartContent>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<HttpMultipartContent>(); }))
    {
    }
    inline HttpMultipartContent::HttpMultipartContent(param::hstring const& subtype) :
        HttpMultipartContent(impl::call_factory<HttpMultipartContent, IHttpMultipartContentFactory>([&](IHttpMultipartContentFactory const& f) { return f.CreateWithSubtype(subtype); }))
    {
    }
    inline HttpMultipartContent::HttpMultipartContent(param::hstring const& subtype, param::hstring const& boundary) :
        HttpMultipartContent(impl::call_factory<HttpMultipartContent, IHttpMultipartContentFactory>([&](IHttpMultipartContentFactory const& f) { return f.CreateWithSubtypeAndBoundary(subtype, boundary); }))
    {
    }
    inline HttpMultipartFormDataContent::HttpMultipartFormDataContent() :
        HttpMultipartFormDataContent(impl::call_factory_cast<HttpMultipartFormDataContent(*)(llm::OS::Foundation::IActivationFactory const&), HttpMultipartFormDataContent>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<HttpMultipartFormDataContent>(); }))
    {
    }
    inline HttpMultipartFormDataContent::HttpMultipartFormDataContent(param::hstring const& boundary) :
        HttpMultipartFormDataContent(impl::call_factory<HttpMultipartFormDataContent, IHttpMultipartFormDataContentFactory>([&](IHttpMultipartFormDataContentFactory const& f) { return f.CreateWithBoundary(boundary); }))
    {
    }
    inline HttpRequestMessage::HttpRequestMessage() :
        HttpRequestMessage(impl::call_factory_cast<HttpRequestMessage(*)(llm::OS::Foundation::IActivationFactory const&), HttpRequestMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<HttpRequestMessage>(); }))
    {
    }
    inline HttpRequestMessage::HttpRequestMessage(llm::OS::Web::Http::HttpMethod const& method, llm::OS::Foundation::Uri const& uri) :
        HttpRequestMessage(impl::call_factory<HttpRequestMessage, IHttpRequestMessageFactory>([&](IHttpRequestMessageFactory const& f) { return f.Create(method, uri); }))
    {
    }
    inline HttpResponseMessage::HttpResponseMessage() :
        HttpResponseMessage(impl::call_factory_cast<HttpResponseMessage(*)(llm::OS::Foundation::IActivationFactory const&), HttpResponseMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<HttpResponseMessage>(); }))
    {
    }
    inline HttpResponseMessage::HttpResponseMessage(llm::OS::Web::Http::HttpStatusCode const& statusCode) :
        HttpResponseMessage(impl::call_factory<HttpResponseMessage, IHttpResponseMessageFactory>([&](IHttpResponseMessageFactory const& f) { return f.Create(statusCode); }))
    {
    }
    inline HttpStreamContent::HttpStreamContent(llm::OS::Storage::Streams::IInputStream const& content) :
        HttpStreamContent(impl::call_factory<HttpStreamContent, IHttpStreamContentFactory>([&](IHttpStreamContentFactory const& f) { return f.CreateFromInputStream(content); }))
    {
    }
    inline HttpStringContent::HttpStringContent(param::hstring const& content) :
        HttpStringContent(impl::call_factory<HttpStringContent, IHttpStringContentFactory>([&](IHttpStringContentFactory const& f) { return f.CreateFromString(content); }))
    {
    }
    inline HttpStringContent::HttpStringContent(param::hstring const& content, llm::OS::Storage::Streams::UnicodeEncoding const& encoding) :
        HttpStringContent(impl::call_factory<HttpStringContent, IHttpStringContentFactory>([&](IHttpStringContentFactory const& f) { return f.CreateFromStringWithEncoding(content, encoding); }))
    {
    }
    inline HttpStringContent::HttpStringContent(param::hstring const& content, llm::OS::Storage::Streams::UnicodeEncoding const& encoding, param::hstring const& mediaType) :
        HttpStringContent(impl::call_factory<HttpStringContent, IHttpStringContentFactory>([&](IHttpStringContentFactory const& f) { return f.CreateFromStringWithEncodingAndMediaType(content, encoding, mediaType); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Web::Http::IHttpBufferContentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpClient> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpClient2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpClient3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpClientFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpCookie> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpCookieFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpCookieManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpFormUrlEncodedContentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpGetBufferResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpGetInputStreamResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpGetStringResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMethod> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMethodFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMethodStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMultipartContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMultipartContentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMultipartFormDataContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpMultipartFormDataContentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpRequestMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpRequestMessage2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpRequestMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpResponseMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpResponseMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpStreamContentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpStringContentFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::IHttpTransportInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpBufferContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpClient> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpCookie> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpCookieCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpCookieManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpFormUrlEncodedContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpGetBufferResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpGetInputStreamResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpGetStringResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpMethod> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpMultipartContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpMultipartFormDataContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpRequestMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpRequestResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpResponseMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpStreamContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpStringContent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::Http::HttpTransportInformation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
    template<> struct formatter<llm::OS::Web::Http::HttpBufferContent, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpClient, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpCookie, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpFormUrlEncodedContent, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpGetBufferResult, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpGetInputStreamResult, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpGetStringResult, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpMethod, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpMultipartContent, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpMultipartFormDataContent, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpRequestMessage, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpRequestResult, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpResponseMessage, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpStreamContent, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpStringContent, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
    template<> struct formatter<llm::OS::Web::Http::HttpTransportInformation, wchar_t> : formatter<llm::OS::Foundation::IStringable, wchar_t> {};
#endif
}
#endif
