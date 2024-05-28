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
#ifndef LLM_OS_ApplicationModel_ExtendedExecution_H
#define LLM_OS_ApplicationModel_ExtendedExecution_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.ApplicationModel.ExtendedExecution.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionRevokedEventArgs<D>::Reason() const
    {
        llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Reason() const
    {
        llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Reason(llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->put_Reason(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::PercentProgress() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->get_PercentProgress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::PercentProgress(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->put_PercentProgress(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Revoked(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->add_Revoked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Revoked_revoker consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Revoked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Revoked_revoker>(this, Revoked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::Revoked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->remove_Revoked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>) consume_Windows_ApplicationModel_ExtendedExecution_IExtendedExecutionSession<D>::RequestExtensionAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession)->RequestExtensionAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs> : produce_base<D, llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession> : produce_base<D, llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Reason(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Reason(*reinterpret_cast<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionReason const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PercentProgress(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PercentProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PercentProgress(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PercentProgress(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Revoked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Revoked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Revoked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Revoked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall RequestExtensionAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionResult>>(this->shim().RequestExtensionAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::ExtendedExecution
{
    inline ExtendedExecutionSession::ExtendedExecutionSession() :
        ExtendedExecutionSession(impl::call_factory_cast<ExtendedExecutionSession(*)(llm::OS::Foundation::IActivationFactory const&), ExtendedExecutionSession>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ExtendedExecutionSession>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionRevokedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ExtendedExecution::IExtendedExecutionSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionRevokedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ExtendedExecution::ExtendedExecutionSession> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
