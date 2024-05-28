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
#ifndef LLM_OS_Web_H
#define LLM_OS_Web_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Web.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>) consume_Windows_Web_IUriToStreamResolver<D>::UriToStreamAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::IUriToStreamResolver)->UriToStreamAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::WebErrorStatus) consume_Windows_Web_IWebErrorStatics<D>::GetStatus(int32_t hresult) const
    {
        llm::OS::Web::WebErrorStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Web::IWebErrorStatics)->GetStatus(hresult, reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D>
    struct produce<D, llm::OS::Web::IUriToStreamResolver> : produce_base<D, llm::OS::Web::IUriToStreamResolver>
    {
        int32_t __stdcall UriToStreamAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>>(this->shim().UriToStreamAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Web::IWebErrorStatics> : produce_base<D, llm::OS::Web::IWebErrorStatics>
    {
        int32_t __stdcall GetStatus(int32_t hresult, int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Web::WebErrorStatus>(this->shim().GetStatus(hresult));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Web
{
    inline auto WebError::GetStatus(int32_t hresult)
    {
        return impl::call_factory<WebError, IWebErrorStatics>([&](IWebErrorStatics const& f) { return f.GetStatus(hresult); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Web::IUriToStreamResolver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::IWebErrorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Web::WebError> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
