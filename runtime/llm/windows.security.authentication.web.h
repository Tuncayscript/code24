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
#ifndef LLM_OS_Security_Authentication_Web_H
#define LLM_OS_Security_Authentication_Web_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Authentication.Web.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics<D>::AuthenticateAsync(llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm::OS::Foundation::Uri const& requestUri, llm::OS::Foundation::Uri const& callbackUri) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics)->AuthenticateWithCallbackUriAsync(static_cast<uint32_t>(options), *(void**)(&requestUri), *(void**)(&callbackUri), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics<D>::AuthenticateAsync(llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm::OS::Foundation::Uri const& requestUri) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics)->AuthenticateWithoutCallbackUriAsync(static_cast<uint32_t>(options), *(void**)(&requestUri), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics<D>::GetCurrentApplicationCallbackUri() const
    {
        void* callbackUri{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics)->GetCurrentApplicationCallbackUri(&callbackUri));
        return llm::OS::Foundation::Uri{ callbackUri, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2<D>::AuthenticateAndContinue(llm::OS::Foundation::Uri const& requestUri) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2)->AuthenticateAndContinue(*(void**)(&requestUri)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2<D>::AuthenticateAndContinue(llm::OS::Foundation::Uri const& requestUri, llm::OS::Foundation::Uri const& callbackUri) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2)->AuthenticateWithCallbackUriAndContinue(*(void**)(&requestUri), *(void**)(&callbackUri)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2<D>::AuthenticateAndContinue(llm::OS::Foundation::Uri const& requestUri, llm::OS::Foundation::Uri const& callbackUri, llm::OS::Foundation::Collections::ValueSet const& continuationData, llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2)->AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(*(void**)(&requestUri), *(void**)(&callbackUri), *(void**)(&continuationData), static_cast<uint32_t>(options)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2<D>::AuthenticateSilentlyAsync(llm::OS::Foundation::Uri const& requestUri) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2)->AuthenticateSilentlyAsync(*(void**)(&requestUri), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>) consume_Windows_Security_Authentication_Web_IWebAuthenticationBrokerStatics2<D>::AuthenticateSilentlyAsync(llm::OS::Foundation::Uri const& requestUri, llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2)->AuthenticateSilentlyWithOptionsAsync(*(void**)(&requestUri), static_cast<uint32_t>(options), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Security_Authentication_Web_IWebAuthenticationResult<D>::ResponseData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationResult)->get_ResponseData(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Web::WebAuthenticationStatus) consume_Windows_Security_Authentication_Web_IWebAuthenticationResult<D>::ResponseStatus() const
    {
        llm::OS::Security::Authentication::Web::WebAuthenticationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationResult)->get_ResponseStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Security_Authentication_Web_IWebAuthenticationResult<D>::ResponseErrorDetail() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Security::Authentication::Web::IWebAuthenticationResult)->get_ResponseErrorDetail(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics> : produce_base<D, llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics>
    {
        int32_t __stdcall AuthenticateWithCallbackUriAsync(uint32_t options, void* requestUri, void* callbackUri, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>>(this->shim().AuthenticateAsync(*reinterpret_cast<llm::OS::Security::Authentication::Web::WebAuthenticationOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&callbackUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AuthenticateWithoutCallbackUriAsync(uint32_t options, void* requestUri, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>>(this->shim().AuthenticateAsync(*reinterpret_cast<llm::OS::Security::Authentication::Web::WebAuthenticationOptions const*>(&options), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentApplicationCallbackUri(void** callbackUri) noexcept final try
        {
            clear_abi(callbackUri);
            typename D::abi_guard guard(this->shim());
            *callbackUri = detach_from<llm::OS::Foundation::Uri>(this->shim().GetCurrentApplicationCallbackUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2> : produce_base<D, llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2>
    {
        int32_t __stdcall AuthenticateAndContinue(void* requestUri) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticateAndContinue(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AuthenticateWithCallbackUriAndContinue(void* requestUri, void* callbackUri) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticateAndContinue(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&callbackUri));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AuthenticateWithCallbackUriContinuationDataAndOptionsAndContinue(void* requestUri, void* callbackUri, void* continuationData, uint32_t options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthenticateAndContinue(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&callbackUri), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&continuationData), *reinterpret_cast<llm::OS::Security::Authentication::Web::WebAuthenticationOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AuthenticateSilentlyAsync(void* requestUri, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>>(this->shim().AuthenticateSilentlyAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AuthenticateSilentlyWithOptionsAsync(void* requestUri, uint32_t options, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Security::Authentication::Web::WebAuthenticationResult>>(this->shim().AuthenticateSilentlyAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&requestUri), *reinterpret_cast<llm::OS::Security::Authentication::Web::WebAuthenticationOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Security::Authentication::Web::IWebAuthenticationResult> : produce_base<D, llm::OS::Security::Authentication::Web::IWebAuthenticationResult>
    {
        int32_t __stdcall get_ResponseData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ResponseData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Web::WebAuthenticationStatus>(this->shim().ResponseStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseErrorDetail(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ResponseErrorDetail());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Security::Authentication::Web
{
    constexpr auto operator|(WebAuthenticationOptions const left, WebAuthenticationOptions const right) noexcept
    {
        return static_cast<WebAuthenticationOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(WebAuthenticationOptions& left, WebAuthenticationOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(WebAuthenticationOptions const left, WebAuthenticationOptions const right) noexcept
    {
        return static_cast<WebAuthenticationOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(WebAuthenticationOptions& left, WebAuthenticationOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(WebAuthenticationOptions const value) noexcept
    {
        return static_cast<WebAuthenticationOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(WebAuthenticationOptions const left, WebAuthenticationOptions const right) noexcept
    {
        return static_cast<WebAuthenticationOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(WebAuthenticationOptions& left, WebAuthenticationOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto WebAuthenticationBroker::AuthenticateAsync(llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm::OS::Foundation::Uri const& requestUri, llm::OS::Foundation::Uri const& callbackUri)
    {
        return impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics>([&](IWebAuthenticationBrokerStatics const& f) { return f.AuthenticateAsync(options, requestUri, callbackUri); });
    }
    inline auto WebAuthenticationBroker::AuthenticateAsync(llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options, llm::OS::Foundation::Uri const& requestUri)
    {
        return impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics>([&](IWebAuthenticationBrokerStatics const& f) { return f.AuthenticateAsync(options, requestUri); });
    }
    inline auto WebAuthenticationBroker::GetCurrentApplicationCallbackUri()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Uri(*)(IWebAuthenticationBrokerStatics const&), WebAuthenticationBroker, IWebAuthenticationBrokerStatics>([](IWebAuthenticationBrokerStatics const& f) { return f.GetCurrentApplicationCallbackUri(); });
    }
    inline auto WebAuthenticationBroker::AuthenticateAndContinue(llm::OS::Foundation::Uri const& requestUri)
    {
        impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>([&](IWebAuthenticationBrokerStatics2 const& f) { return f.AuthenticateAndContinue(requestUri); });
    }
    inline auto WebAuthenticationBroker::AuthenticateAndContinue(llm::OS::Foundation::Uri const& requestUri, llm::OS::Foundation::Uri const& callbackUri)
    {
        impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>([&](IWebAuthenticationBrokerStatics2 const& f) { return f.AuthenticateAndContinue(requestUri, callbackUri); });
    }
    inline auto WebAuthenticationBroker::AuthenticateAndContinue(llm::OS::Foundation::Uri const& requestUri, llm::OS::Foundation::Uri const& callbackUri, llm::OS::Foundation::Collections::ValueSet const& continuationData, llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options)
    {
        impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>([&](IWebAuthenticationBrokerStatics2 const& f) { return f.AuthenticateAndContinue(requestUri, callbackUri, continuationData, options); });
    }
    inline auto WebAuthenticationBroker::AuthenticateSilentlyAsync(llm::OS::Foundation::Uri const& requestUri)
    {
        return impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>([&](IWebAuthenticationBrokerStatics2 const& f) { return f.AuthenticateSilentlyAsync(requestUri); });
    }
    inline auto WebAuthenticationBroker::AuthenticateSilentlyAsync(llm::OS::Foundation::Uri const& requestUri, llm::OS::Security::Authentication::Web::WebAuthenticationOptions const& options)
    {
        return impl::call_factory<WebAuthenticationBroker, IWebAuthenticationBrokerStatics2>([&](IWebAuthenticationBrokerStatics2 const& f) { return f.AuthenticateSilentlyAsync(requestUri, options); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Web::IWebAuthenticationBrokerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Web::IWebAuthenticationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Web::WebAuthenticationBroker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Security::Authentication::Web::WebAuthenticationResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
