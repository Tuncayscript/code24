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
#ifndef LLM_OS_UI_Accessibility_H
#define LLM_OS_UI_Accessibility_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Accessibility.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Accessibility_IScreenReaderPositionChangedEventArgs<D>::ScreenPositionInRawPixels() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs)->get_ScreenPositionInRawPixels(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Accessibility_IScreenReaderPositionChangedEventArgs<D>::IsReadingText() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs)->get_IsReadingText(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs) consume_Windows_UI_Accessibility_IScreenReaderService<D>::CurrentScreenReaderPosition() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Accessibility::IScreenReaderService)->get_CurrentScreenReaderPosition(&value));
        return llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Accessibility_IScreenReaderService<D>::ScreenReaderPositionChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Accessibility::ScreenReaderService, llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Accessibility::IScreenReaderService)->add_ScreenReaderPositionChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Accessibility_IScreenReaderService<D>::ScreenReaderPositionChanged_revoker consume_Windows_UI_Accessibility_IScreenReaderService<D>::ScreenReaderPositionChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Accessibility::ScreenReaderService, llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ScreenReaderPositionChanged_revoker>(this, ScreenReaderPositionChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Accessibility_IScreenReaderService<D>::ScreenReaderPositionChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Accessibility::IScreenReaderService)->remove_ScreenReaderPositionChanged(impl::bind_in(token));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs> : produce_base<D, llm::OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs>
    {
        int32_t __stdcall get_ScreenPositionInRawPixels(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().ScreenPositionInRawPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsReadingText(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadingText());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Accessibility::IScreenReaderService> : produce_base<D, llm::OS::UI::Accessibility::IScreenReaderService>
    {
        int32_t __stdcall get_CurrentScreenReaderPosition(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs>(this->shim().CurrentScreenReaderPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ScreenReaderPositionChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ScreenReaderPositionChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Accessibility::ScreenReaderService, llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ScreenReaderPositionChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScreenReaderPositionChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Accessibility
{
    inline ScreenReaderService::ScreenReaderService() :
        ScreenReaderService(impl::call_factory_cast<ScreenReaderService(*)(llm::OS::Foundation::IActivationFactory const&), ScreenReaderService>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ScreenReaderService>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Accessibility::IScreenReaderService> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Accessibility::ScreenReaderPositionChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Accessibility::ScreenReaderService> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
