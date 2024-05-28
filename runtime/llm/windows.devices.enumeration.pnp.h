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
#ifndef LLM_OS_Devices_Enumeration_Pnp_H
#define LLM_OS_Devices_Enumeration_Pnp_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.Enumeration.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Devices.Enumeration.Pnp.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::Pnp::PnpObjectType) consume_Windows_Devices_Enumeration_Pnp_IPnpObject<D>::Type() const
    {
        llm::OS::Devices::Enumeration::Pnp::PnpObjectType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObject)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_Pnp_IPnpObject<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObject)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Enumeration_Pnp_IPnpObject<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObject)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObject<D>::Update(llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate const& updateInfo) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObject)->Update(*(void**)(&updateInfo)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObject>) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectStatics<D>::CreateFromIdAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::hstring const& id, param::async_iterable<hstring> const& requestedProperties) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics)->CreateFromIdAsync(static_cast<int32_t>(type), *(void**)(&id), *(void**)(&requestedProperties), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObject>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection>) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectStatics<D>::FindAllAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::async_iterable<hstring> const& requestedProperties) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics)->FindAllAsync(static_cast<int32_t>(type), *(void**)(&requestedProperties), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection>) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectStatics<D>::FindAllAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::async_iterable<hstring> const& requestedProperties, param::hstring const& aqsFilter) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics)->FindAllAsyncAqsFilter(static_cast<int32_t>(type), *(void**)(&requestedProperties), *(void**)(&aqsFilter), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectStatics<D>::CreateWatcher(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::iterable<hstring> const& requestedProperties) const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics)->CreateWatcher(static_cast<int32_t>(type), *(void**)(&requestedProperties), &watcher));
        return llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectStatics<D>::CreateWatcher(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::iterable<hstring> const& requestedProperties, param::hstring const& aqsFilter) const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics)->CreateWatcherAqsFilter(static_cast<int32_t>(type), *(void**)(&requestedProperties), *(void**)(&aqsFilter), &watcher));
        return llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::Pnp::PnpObjectType) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectUpdate<D>::Type() const
    {
        llm::OS::Devices::Enumeration::Pnp::PnpObjectType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectUpdate<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectUpdate<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObject> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Added_revoker consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObject> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->add_Updated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Updated_revoker consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> const& handler) const
    {
        return impl::make_event_revoker<D, Updated_revoker>(this, Updated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Updated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->remove_Updated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Removed_revoker consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::EnumerationCompleted_revoker consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Stopped_revoker consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcherStatus) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceWatcherStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_Pnp_IPnpObjectWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher)->Stop());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::Pnp::IPnpObject> : produce_base<D, llm::OS::Devices::Enumeration::Pnp::IPnpObject>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::Pnp::PnpObjectType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Update(void* updateInfo) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate const*>(&updateInfo));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics> : produce_base<D, llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics>
    {
        int32_t __stdcall CreateFromIdAsync(int32_t type, void* id, void* requestedProperties, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObject>>(this->shim().CreateFromIdAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::Pnp::PnpObjectType const*>(&type), *reinterpret_cast<hstring const*>(&id), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&requestedProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(int32_t type, void* requestedProperties, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection>>(this->shim().FindAllAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::Pnp::PnpObjectType const*>(&type), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&requestedProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncAqsFilter(int32_t type, void* requestedProperties, void* aqsFilter, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection>>(this->shim().FindAllAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::Pnp::PnpObjectType const*>(&type), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&requestedProperties), *reinterpret_cast<hstring const*>(&aqsFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcher(int32_t type, void* requestedProperties, void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher>(this->shim().CreateWatcher(*reinterpret_cast<llm::OS::Devices::Enumeration::Pnp::PnpObjectType const*>(&type), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&requestedProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherAqsFilter(int32_t type, void* requestedProperties, void* aqsFilter, void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher>(this->shim().CreateWatcher(*reinterpret_cast<llm::OS::Devices::Enumeration::Pnp::PnpObjectType const*>(&type), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&requestedProperties), *reinterpret_cast<hstring const*>(&aqsFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate> : produce_base<D, llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::Pnp::PnpObjectType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher> : produce_base<D, llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher>
    {
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObject> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Added(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Updated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Updated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Updated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Removed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Devices::Enumeration::DeviceWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Enumeration::Pnp
{
    inline auto PnpObject::CreateFromIdAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::hstring const& id, param::async_iterable<hstring> const& requestedProperties)
    {
        return impl::call_factory<PnpObject, IPnpObjectStatics>([&](IPnpObjectStatics const& f) { return f.CreateFromIdAsync(type, id, requestedProperties); });
    }
    inline auto PnpObject::FindAllAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::async_iterable<hstring> const& requestedProperties)
    {
        return impl::call_factory<PnpObject, IPnpObjectStatics>([&](IPnpObjectStatics const& f) { return f.FindAllAsync(type, requestedProperties); });
    }
    inline auto PnpObject::FindAllAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::async_iterable<hstring> const& requestedProperties, param::hstring const& aqsFilter)
    {
        return impl::call_factory<PnpObject, IPnpObjectStatics>([&](IPnpObjectStatics const& f) { return f.FindAllAsync(type, requestedProperties, aqsFilter); });
    }
    inline auto PnpObject::CreateWatcher(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::iterable<hstring> const& requestedProperties)
    {
        return impl::call_factory<PnpObject, IPnpObjectStatics>([&](IPnpObjectStatics const& f) { return f.CreateWatcher(type, requestedProperties); });
    }
    inline auto PnpObject::CreateWatcher(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::iterable<hstring> const& requestedProperties, param::hstring const& aqsFilter)
    {
        return impl::call_factory<PnpObject, IPnpObjectStatics>([&](IPnpObjectStatics const& f) { return f.CreateWatcher(type, requestedProperties, aqsFilter); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::IPnpObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::IPnpObjectStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::PnpObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::PnpObjectCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::PnpObjectUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::Pnp::PnpObjectWatcher> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
