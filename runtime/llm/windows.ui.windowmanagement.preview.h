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
#ifndef LLM_OS_UI_WindowManagement_Preview_H
#define LLM_OS_UI_WindowManagement_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.WindowManagement.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.WindowManagement.2.h"
#include "llm/impl/Windows.UI.WindowManagement.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_Preview_IWindowManagementPreviewStatics<D>::SetPreferredMinSize(llm::OS::UI::WindowManagement::AppWindow const& window, llm::OS::Foundation::Size const& preferredFrameMinSize) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics)->SetPreferredMinSize(*(void**)(&window), impl::bind_in(preferredFrameMinSize)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview> : produce_base<D, llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics> : produce_base<D, llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics>
    {
        int32_t __stdcall SetPreferredMinSize(void* window, llm::OS::Foundation::Size preferredFrameMinSize) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreferredMinSize(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindow const*>(&window), *reinterpret_cast<llm::OS::Foundation::Size const*>(&preferredFrameMinSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::WindowManagement::Preview
{
    inline auto WindowManagementPreview::SetPreferredMinSize(llm::OS::UI::WindowManagement::AppWindow const& window, llm::OS::Foundation::Size const& preferredFrameMinSize)
    {
        impl::call_factory<WindowManagementPreview, IWindowManagementPreviewStatics>([&](IWindowManagementPreviewStatics const& f) { return f.SetPreferredMinSize(window, preferredFrameMinSize); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::Preview::IWindowManagementPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::Preview::WindowManagementPreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
