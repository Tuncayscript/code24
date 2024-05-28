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
#ifndef LLM_OS_ApplicationModel_AppService_H
#define LLM_OS_ApplicationModel_AppService_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.System.RemoteSystems.2.h"
#include "llm/impl/Windows.ApplicationModel.AppService.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>) consume_Windows_ApplicationModel_AppService_IAppServiceCatalogStatics<D>::FindAppServiceProvidersAsync(param::hstring const& appServiceName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceCatalogStatics)->FindAppServiceProvidersAsync(*(void**)(&appServiceName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppService::AppServiceClosedStatus) consume_Windows_ApplicationModel_AppService_IAppServiceClosedEventArgs<D>::Status() const
    {
        llm::OS::ApplicationModel::AppService::AppServiceClosedStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceClosedEventArgs)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::AppServiceName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->get_AppServiceName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::AppServiceName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->put_AppServiceName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::PackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->get_PackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::PackageFamilyName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->put_PackageFamilyName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceConnectionStatus>) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::OpenAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->OpenAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceConnectionStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceResponse>) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::SendMessageAsync(llm::OS::Foundation::Collections::ValueSet const& message) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->SendMessageAsync(*(void**)(&message), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceResponse>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::RequestReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppService::AppServiceConnection, llm::OS::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->add_RequestReceived(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::RequestReceived_revoker consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::RequestReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppService::AppServiceConnection, llm::OS::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RequestReceived_revoker>(this, RequestReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::RequestReceived(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->remove_RequestReceived(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::ServiceClosed(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppService::AppServiceConnection, llm::OS::ApplicationModel::AppService::AppServiceClosedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->add_ServiceClosed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::ServiceClosed_revoker consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::ServiceClosed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppService::AppServiceConnection, llm::OS::ApplicationModel::AppService::AppServiceClosedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ServiceClosed_revoker>(this, ServiceClosed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppService_IAppServiceConnection<D>::ServiceClosed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection)->remove_ServiceClosed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceConnectionStatus>) consume_Windows_ApplicationModel_AppService_IAppServiceConnection2<D>::OpenRemoteAsync(llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& remoteSystemConnectionRequest) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection2)->OpenRemoteAsync(*(void**)(&remoteSystemConnectionRequest), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceConnectionStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_ApplicationModel_AppService_IAppServiceConnection2<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection2)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppService_IAppServiceConnection2<D>::User(llm::OS::System::User const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnection2)->put_User(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::StatelessAppServiceResponse>) consume_Windows_ApplicationModel_AppService_IAppServiceConnectionStatics<D>::SendStatelessMessageAsync(llm::OS::ApplicationModel::AppService::AppServiceConnection const& connection, llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& connectionRequest, llm::OS::Foundation::Collections::ValueSet const& message) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceConnectionStatics)->SendStatelessMessageAsync(*(void**)(&connection), *(void**)(&connectionRequest), *(void**)(&message), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::StatelessAppServiceResponse>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_AppService_IAppServiceDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_AppService_IAppServiceRequest<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceRequest)->get_Message(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceResponseStatus>) consume_Windows_ApplicationModel_AppService_IAppServiceRequest<D>::SendResponseAsync(llm::OS::Foundation::Collections::ValueSet const& message) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceRequest)->SendResponseAsync(*(void**)(&message), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceResponseStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppService::AppServiceRequest) consume_Windows_ApplicationModel_AppService_IAppServiceRequestReceivedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs)->get_Request(&value));
        return llm::OS::ApplicationModel::AppService::AppServiceRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppService::AppServiceDeferral) consume_Windows_ApplicationModel_AppService_IAppServiceRequestReceivedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs)->GetDeferral(&result));
        return llm::OS::ApplicationModel::AppService::AppServiceDeferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_AppService_IAppServiceResponse<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceResponse)->get_Message(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppService::AppServiceResponseStatus) consume_Windows_ApplicationModel_AppService_IAppServiceResponse<D>::Status() const
    {
        llm::OS::ApplicationModel::AppService::AppServiceResponseStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceResponse)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppService_IAppServiceTriggerDetails<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppService_IAppServiceTriggerDetails<D>::CallerPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails)->get_CallerPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppService::AppServiceConnection) consume_Windows_ApplicationModel_AppService_IAppServiceTriggerDetails<D>::AppServiceConnection() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails)->get_AppServiceConnection(&value));
        return llm::OS::ApplicationModel::AppService::AppServiceConnection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_AppService_IAppServiceTriggerDetails2<D>::IsRemoteSystemConnection() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails2)->get_IsRemoteSystemConnection(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_AppService_IAppServiceTriggerDetails3<D>::CheckCallerForCapabilityAsync(param::hstring const& capabilityName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails3)->CheckCallerForCapabilityAsync(*(void**)(&capabilityName), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_AppService_IAppServiceTriggerDetails4<D>::CallerRemoteConnectionToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails4)->get_CallerRemoteConnectionToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_AppService_IStatelessAppServiceResponse<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse)->get_Message(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::AppService::StatelessAppServiceResponseStatus) consume_Windows_ApplicationModel_AppService_IStatelessAppServiceResponse<D>::Status() const
    {
        llm::OS::ApplicationModel::AppService::StatelessAppServiceResponseStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceCatalogStatics> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceCatalogStatics>
    {
        int32_t __stdcall FindAppServiceProvidersAsync(void* appServiceName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::AppInfo>>>(this->shim().FindAppServiceProvidersAsync(*reinterpret_cast<hstring const*>(&appServiceName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceClosedEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceClosedEventArgs>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppService::AppServiceClosedStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceConnection> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceConnection>
    {
        int32_t __stdcall get_AppServiceName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppServiceName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AppServiceName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppServiceName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PackageFamilyName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PackageFamilyName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceConnectionStatus>>(this->shim().OpenAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendMessageAsync(void* message, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceResponse>>(this->shim().SendMessageAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RequestReceived(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RequestReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppService::AppServiceConnection, llm::OS::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RequestReceived(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestReceived(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ServiceClosed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ServiceClosed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::AppService::AppServiceConnection, llm::OS::ApplicationModel::AppService::AppServiceClosedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ServiceClosed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceClosed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceConnection2> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceConnection2>
    {
        int32_t __stdcall OpenRemoteAsync(void* remoteSystemConnectionRequest, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceConnectionStatus>>(this->shim().OpenRemoteAsync(*reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const*>(&remoteSystemConnectionRequest)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_User(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().User(*reinterpret_cast<llm::OS::System::User const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceConnectionStatics> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceConnectionStatics>
    {
        int32_t __stdcall SendStatelessMessageAsync(void* connection, void* connectionRequest, void* message, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::StatelessAppServiceResponse>>(this->shim().SendStatelessMessageAsync(*reinterpret_cast<llm::OS::ApplicationModel::AppService::AppServiceConnection const*>(&connection), *reinterpret_cast<llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const*>(&connectionRequest), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceDeferral> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceRequest> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceRequest>
    {
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendResponseAsync(void* message, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::AppService::AppServiceResponseStatus>>(this->shim().SendResponseAsync(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppService::AppServiceRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::AppService::AppServiceDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceResponse> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceResponse>
    {
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppService::AppServiceResponseStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallerPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallerPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppServiceConnection(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppService::AppServiceConnection>(this->shim().AppServiceConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails2> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails2>
    {
        int32_t __stdcall get_IsRemoteSystemConnection(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRemoteSystemConnection());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails3> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails3>
    {
        int32_t __stdcall CheckCallerForCapabilityAsync(void* capabilityName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().CheckCallerForCapabilityAsync(*reinterpret_cast<hstring const*>(&capabilityName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails4> : produce_base<D, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails4>
    {
        int32_t __stdcall get_CallerRemoteConnectionToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallerRemoteConnectionToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse> : produce_base<D, llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse>
    {
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::AppService::StatelessAppServiceResponseStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::AppService
{
    inline auto AppServiceCatalog::FindAppServiceProvidersAsync(param::hstring const& appServiceName)
    {
        return impl::call_factory<AppServiceCatalog, IAppServiceCatalogStatics>([&](IAppServiceCatalogStatics const& f) { return f.FindAppServiceProvidersAsync(appServiceName); });
    }
    inline AppServiceConnection::AppServiceConnection() :
        AppServiceConnection(impl::call_factory_cast<AppServiceConnection(*)(llm::OS::Foundation::IActivationFactory const&), AppServiceConnection>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AppServiceConnection>(); }))
    {
    }
    inline auto AppServiceConnection::SendStatelessMessageAsync(llm::OS::ApplicationModel::AppService::AppServiceConnection const& connection, llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& connectionRequest, llm::OS::Foundation::Collections::ValueSet const& message)
    {
        return impl::call_factory<AppServiceConnection, IAppServiceConnectionStatics>([&](IAppServiceConnectionStatics const& f) { return f.SendStatelessMessageAsync(connection, connectionRequest, message); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceCatalogStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceClosedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceConnection2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceConnectionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceResponse> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceCatalog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceClosedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceConnection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceRequestReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceResponse> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::AppServiceTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::AppService::StatelessAppServiceResponse> : llm::impl::hash_base {};
#ifdef __cpp_lib_format
#endif
}
#endif
