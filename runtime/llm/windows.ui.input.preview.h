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
#ifndef LLM_OS_UI_Input_Preview_H
#define LLM_OS_UI_Input_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Input.h"
#include "llm/impl/Windows.UI.Input.2.h"
#include "llm/impl/Windows.UI.WindowManagement.2.h"
#include "llm/impl/Windows.UI.Input.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::InputActivationListener) consume_Windows_UI_Input_Preview_IInputActivationListenerPreviewStatics<D>::CreateForApplicationWindow(llm::OS::UI::WindowManagement::AppWindow const& window) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Preview::IInputActivationListenerPreviewStatics)->CreateForApplicationWindow(*(void**)(&window), &result));
        return llm::OS::UI::Input::InputActivationListener{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Preview::IInputActivationListenerPreviewStatics> : produce_base<D, llm::OS::UI::Input::Preview::IInputActivationListenerPreviewStatics>
    {
        int32_t __stdcall CreateForApplicationWindow(void* window, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Input::InputActivationListener>(this->shim().CreateForApplicationWindow(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindow const*>(&window)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Input::Preview
{
    inline auto InputActivationListenerPreview::CreateForApplicationWindow(llm::OS::UI::WindowManagement::AppWindow const& window)
    {
        return impl::call_factory<InputActivationListenerPreview, IInputActivationListenerPreviewStatics>([&](IInputActivationListenerPreviewStatics const& f) { return f.CreateForApplicationWindow(window); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Input::Preview::IInputActivationListenerPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Preview::InputActivationListenerPreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
