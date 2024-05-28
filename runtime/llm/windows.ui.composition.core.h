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
#ifndef LLM_OS_UI_Composition_Core_H
#define LLM_OS_UI_Composition_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Composition.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Composition.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Compositor) consume_Windows_UI_Composition_Core_ICompositorController<D>::Compositor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Core::ICompositorController)->get_Compositor(&value));
        return llm::OS::UI::Composition::Compositor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Core_ICompositorController<D>::Commit() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Core::ICompositorController)->Commit());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_Composition_Core_ICompositorController<D>::EnsurePreviousCommitCompletedAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Core::ICompositorController)->EnsurePreviousCommitCompletedAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Composition_Core_ICompositorController<D>::CommitNeeded(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::Core::CompositorController, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Core::ICompositorController)->add_CommitNeeded(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Composition_Core_ICompositorController<D>::CommitNeeded_revoker consume_Windows_UI_Composition_Core_ICompositorController<D>::CommitNeeded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::Core::CompositorController, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, CommitNeeded_revoker>(this, CommitNeeded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Core_ICompositorController<D>::CommitNeeded(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Composition::Core::ICompositorController)->remove_CommitNeeded(impl::bind_in(token));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Core::ICompositorController> : produce_base<D, llm::OS::UI::Composition::Core::ICompositorController>
    {
        int32_t __stdcall get_Compositor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Compositor>(this->shim().Compositor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Commit() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Commit();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnsurePreviousCommitCompletedAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().EnsurePreviousCommitCompletedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CommitNeeded(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CommitNeeded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::Core::CompositorController, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CommitNeeded(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommitNeeded(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Composition::Core
{
    inline CompositorController::CompositorController() :
        CompositorController(impl::call_factory_cast<CompositorController(*)(llm::OS::Foundation::IActivationFactory const&), CompositorController>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CompositorController>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Composition::Core::ICompositorController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Core::CompositorController> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
