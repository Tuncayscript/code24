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
#ifndef LLM_OS_UI_Core_Preview_H
#define LLM_OS_UI_Core_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Core.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.WindowManagement.2.h"
#include "llm/impl/Windows.UI.Core.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Core_Preview_ICoreAppWindowPreviewStatics<D>::GetIdFromWindow(llm::OS::UI::WindowManagement::AppWindow const& window) const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ICoreAppWindowPreviewStatics)->GetIdFromWindow(*(void**)(&window), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Core_Preview_ISystemNavigationCloseRequestedPreviewEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview<D>::CloseRequested(llm::OS::Foundation::EventHandler<llm::OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ISystemNavigationManagerPreview)->add_CloseRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview<D>::CloseRequested_revoker consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview<D>::CloseRequested(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CloseRequested_revoker>(this, CloseRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreview<D>::CloseRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ISystemNavigationManagerPreview)->remove_CloseRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::Preview::SystemNavigationManagerPreview) consume_Windows_UI_Core_Preview_ISystemNavigationManagerPreviewStatics<D>::GetForCurrentView() const
    {
        void* loader{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics)->GetForCurrentView(&loader));
        return llm::OS::UI::Core::Preview::SystemNavigationManagerPreview{ loader, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::Preview::ICoreAppWindowPreview> : produce_base<D, llm::OS::UI::Core::Preview::ICoreAppWindowPreview>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::Preview::ICoreAppWindowPreviewStatics> : produce_base<D, llm::OS::UI::Core::Preview::ICoreAppWindowPreviewStatics>
    {
        int32_t __stdcall GetIdFromWindow(void* window, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetIdFromWindow(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindow const*>(&window)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs> : produce_base<D, llm::OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs>
    {
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::Preview::ISystemNavigationManagerPreview> : produce_base<D, llm::OS::UI::Core::Preview::ISystemNavigationManagerPreview>
    {
        int32_t __stdcall add_CloseRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CloseRequested(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CloseRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics> : produce_base<D, llm::OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics>
    {
        int32_t __stdcall GetForCurrentView(void** loader) noexcept final try
        {
            clear_abi(loader);
            typename D::abi_guard guard(this->shim());
            *loader = detach_from<llm::OS::UI::Core::Preview::SystemNavigationManagerPreview>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Core::Preview
{
    inline auto CoreAppWindowPreview::GetIdFromWindow(llm::OS::UI::WindowManagement::AppWindow const& window)
    {
        return impl::call_factory<CoreAppWindowPreview, ICoreAppWindowPreviewStatics>([&](ICoreAppWindowPreviewStatics const& f) { return f.GetIdFromWindow(window); });
    }
    inline auto SystemNavigationManagerPreview::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::Core::Preview::SystemNavigationManagerPreview(*)(ISystemNavigationManagerPreviewStatics const&), SystemNavigationManagerPreview, ISystemNavigationManagerPreviewStatics>([](ISystemNavigationManagerPreviewStatics const& f) { return f.GetForCurrentView(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Core::Preview::ICoreAppWindowPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::ICoreAppWindowPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::ISystemNavigationCloseRequestedPreviewEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::ISystemNavigationManagerPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::ISystemNavigationManagerPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::CoreAppWindowPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::SystemNavigationCloseRequestedPreviewEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::Preview::SystemNavigationManagerPreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
