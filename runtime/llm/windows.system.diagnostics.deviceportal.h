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
#ifndef LLM_OS_System_Diagnostics_DevicePortal_H
#define LLM_OS_System_Diagnostics_DevicePortal_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.Diagnostics.h"
#include "llm/impl/Windows.ApplicationModel.AppService.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.Sockets.2.h"
#include "llm/impl/Windows.Web.Http.2.h"
#include "llm/impl/Windows.System.Diagnostics.DevicePortal.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection)->add_Closed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::Closed_revoker consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Closed_revoker>(this, Closed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::Closed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection)->remove_Closed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::RequestReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection)->add_RequestReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::RequestReceived_revoker consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::RequestReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RequestReceived_revoker>(this, RequestReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnection<D>::RequestReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection)->remove_RequestReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionClosedEventArgs<D>::Reason() const
    {
        llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpRequestMessage) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionRequestReceivedEventArgs<D>::RequestMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs)->get_RequestMessage(&value));
        return llm::OS::Web::Http::HttpRequestMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Web::Http::HttpResponseMessage) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionRequestReceivedEventArgs<D>::ResponseMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs)->get_ResponseMessage(&value));
        return llm::OS::Web::Http::HttpResponseMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalConnectionStatics<D>::GetForAppServiceConnection(llm::OS::ApplicationModel::AppService::AppServiceConnection const& appServiceConnection) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics)->GetForAppServiceConnection(*(void**)(&appServiceConnection), &value));
        return llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::ServerMessageWebSocket) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>::GetServerMessageWebSocketForRequest(llm::OS::Web::Http::HttpRequestMessage const& request) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection)->GetServerMessageWebSocketForRequest(*(void**)(&request), &result));
        return llm::OS::Networking::Sockets::ServerMessageWebSocket{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::ServerMessageWebSocket) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>::GetServerMessageWebSocketForRequest(llm::OS::Web::Http::HttpRequestMessage const& request, llm::OS::Networking::Sockets::SocketMessageType const& messageType, param::hstring const& protocol) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection)->GetServerMessageWebSocketForRequest2(*(void**)(&request), static_cast<int32_t>(messageType), *(void**)(&protocol), &result));
        return llm::OS::Networking::Sockets::ServerMessageWebSocket{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::ServerMessageWebSocket) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>::GetServerMessageWebSocketForRequest(llm::OS::Web::Http::HttpRequestMessage const& request, llm::OS::Networking::Sockets::SocketMessageType const& messageType, param::hstring const& protocol, uint32_t outboundBufferSizeInBytes, uint32_t maxMessageSize, llm::OS::Networking::Sockets::MessageWebSocketReceiveMode const& receiveMode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection)->GetServerMessageWebSocketForRequest3(*(void**)(&request), static_cast<int32_t>(messageType), *(void**)(&protocol), outboundBufferSizeInBytes, maxMessageSize, static_cast<int32_t>(receiveMode), &result));
        return llm::OS::Networking::Sockets::ServerMessageWebSocket{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::ServerStreamWebSocket) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>::GetServerStreamWebSocketForRequest(llm::OS::Web::Http::HttpRequestMessage const& request) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection)->GetServerStreamWebSocketForRequest(*(void**)(&request), &result));
        return llm::OS::Networking::Sockets::ServerStreamWebSocket{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::ServerStreamWebSocket) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnection<D>::GetServerStreamWebSocketForRequest(llm::OS::Web::Http::HttpRequestMessage const& request, param::hstring const& protocol, uint32_t outboundBufferSizeInBytes, bool noDelay) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection)->GetServerStreamWebSocketForRequest2(*(void**)(&request), *(void**)(&protocol), outboundBufferSizeInBytes, noDelay, &result));
        return llm::OS::Networking::Sockets::ServerStreamWebSocket{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs<D>::IsWebSocketUpgradeRequest() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs)->get_IsWebSocketUpgradeRequest(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs<D>::WebSocketProtocolsRequested() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs)->get_WebSocketProtocolsRequested(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_System_Diagnostics_DevicePortal_IDevicePortalWebSocketConnectionRequestReceivedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection> : produce_base<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection>
    {
        int32_t __stdcall add_Closed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Closed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_RequestReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RequestReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection, llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RequestReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs> : produce_base<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs> : produce_base<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs>
    {
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
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics> : produce_base<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics>
    {
        int32_t __stdcall GetForAppServiceConnection(void* appServiceConnection, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection>(this->shim().GetForAppServiceConnection(*reinterpret_cast<llm::OS::ApplicationModel::AppService::AppServiceConnection const*>(&appServiceConnection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection> : produce_base<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection>
    {
        int32_t __stdcall GetServerMessageWebSocketForRequest(void* request, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Sockets::ServerMessageWebSocket>(this->shim().GetServerMessageWebSocketForRequest(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetServerMessageWebSocketForRequest2(void* request, int32_t messageType, void* protocol, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Sockets::ServerMessageWebSocket>(this->shim().GetServerMessageWebSocketForRequest(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request), *reinterpret_cast<llm::OS::Networking::Sockets::SocketMessageType const*>(&messageType), *reinterpret_cast<hstring const*>(&protocol)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetServerMessageWebSocketForRequest3(void* request, int32_t messageType, void* protocol, uint32_t outboundBufferSizeInBytes, uint32_t maxMessageSize, int32_t receiveMode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Sockets::ServerMessageWebSocket>(this->shim().GetServerMessageWebSocketForRequest(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request), *reinterpret_cast<llm::OS::Networking::Sockets::SocketMessageType const*>(&messageType), *reinterpret_cast<hstring const*>(&protocol), outboundBufferSizeInBytes, maxMessageSize, *reinterpret_cast<llm::OS::Networking::Sockets::MessageWebSocketReceiveMode const*>(&receiveMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetServerStreamWebSocketForRequest(void* request, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Sockets::ServerStreamWebSocket>(this->shim().GetServerStreamWebSocketForRequest(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetServerStreamWebSocketForRequest2(void* request, void* protocol, uint32_t outboundBufferSizeInBytes, bool noDelay, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Sockets::ServerStreamWebSocket>(this->shim().GetServerStreamWebSocketForRequest(*reinterpret_cast<llm::OS::Web::Http::HttpRequestMessage const*>(&request), *reinterpret_cast<hstring const*>(&protocol), outboundBufferSizeInBytes, noDelay));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs> : produce_base<D, llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs>
    {
        int32_t __stdcall get_IsWebSocketUpgradeRequest(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsWebSocketUpgradeRequest());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WebSocketProtocolsRequested(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().WebSocketProtocolsRequested());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Diagnostics::DevicePortal
{
    inline auto DevicePortalConnection::GetForAppServiceConnection(llm::OS::ApplicationModel::AppService::AppServiceConnection const& appServiceConnection)
    {
        return impl::call_factory<DevicePortalConnection, IDevicePortalConnectionStatics>([&](IDevicePortalConnectionStatics const& f) { return f.GetForAppServiceConnection(appServiceConnection); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionClosedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionRequestReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::IDevicePortalConnectionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::IDevicePortalWebSocketConnectionRequestReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionClosedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Diagnostics::DevicePortal::DevicePortalConnectionRequestReceivedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
