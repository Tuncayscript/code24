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
#ifndef LLM_OS_System_Implementation_FileExplorer_H
#define LLM_OS_System_Implementation_FileExplorer_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Web.Http.2.h"
#include "llm/impl/Windows.System.Implementation.FileExplorer.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventReceivedEventArgs<D>::Json() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs)->get_Json(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventReceivedEventArgsFactory<D>::CreateInstance(param::hstring const& json) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory)->CreateInstance(*(void**)(&json), &value));
        return llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventSource<D>::EventReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource, llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource)->add_EventReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventSource<D>::EventReceived_revoker consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventSource<D>::EventReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource, llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, EventReceived_revoker>(this, EventReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderEventSource<D>::EventReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource)->remove_EventReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHandlerFactory<D>::GetHttpRequestProvider(param::hstring const& syncRootId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory)->GetHttpRequestProvider(*(void**)(&syncRootId), &result));
        return llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHandlerFactory<D>::GetEventSource(param::hstring const& syncRootId, param::hstring const& eventName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory)->GetEventSource(*(void**)(&syncRootId), *(void**)(&eventName), &result));
        return llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Web::Http::HttpResponseMessage>) consume_Windows_System_Implementation_FileExplorer_ISysStorageProviderHttpRequestProvider<D>::SendRequestAsync(llm::OS::Web::Http::HttpRequestMessage const& request) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider)->SendRequestAsync(*(void**)(&request), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Web::Http::HttpResponseMessage>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs> : produce_base<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs>
    {
        int32_t __stdcall get_Json(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Json());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory> : produce_base<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory>
    {
        int32_t __stdcall CreateInstance(void* json, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs>(this->shim().CreateInstance(*reinterpret_cast<hstring const*>(&json)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource> : produce_base<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>
    {
        int32_t __stdcall add_EventReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EventReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource, llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EventReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EventReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
    template <typename D>
    struct produce<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory> : produce_base<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory>
    {
        int32_t __stdcall GetHttpRequestProvider(void* syncRootId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider>(this->shim().GetHttpRequestProvider(*reinterpret_cast<hstring const*>(&syncRootId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetEventSource(void* syncRootId, void* eventName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource>(this->shim().GetEventSource(*reinterpret_cast<hstring const*>(&syncRootId), *reinterpret_cast<hstring const*>(&eventName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider> : produce_base<D, llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider>
    {
        int32_t __stdcall SendRequestAsync(void* request, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Web::Http::HttpResponseMessage>>(this->shim().SendRequestAsync(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::System::Implementation::FileExplorer
{
    inline SysStorageProviderEventReceivedEventArgs::SysStorageProviderEventReceivedEventArgs(param::hstring const& json) :
        SysStorageProviderEventReceivedEventArgs(impl::call_factory<SysStorageProviderEventReceivedEventArgs, ISysStorageProviderEventReceivedEventArgsFactory>([&](ISysStorageProviderEventReceivedEventArgsFactory const& f) { return f.CreateInstance(json); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventReceivedEventArgsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderEventSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHandlerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Implementation::FileExplorer::ISysStorageProviderHttpRequestProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Implementation::FileExplorer::SysStorageProviderEventReceivedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
