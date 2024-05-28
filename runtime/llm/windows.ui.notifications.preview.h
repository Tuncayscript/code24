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
#ifndef LLM_OS_UI_Notifications_Preview_H
#define LLM_OS_UI_Notifications_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Notifications.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Notifications.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Notifications_Preview_IToastOcclusionManagerPreviewStatics<D>::SetToastWindowMargin(llm::OS::UI::WindowId const& appWindowId, double margin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics)->SetToastWindowMargin(impl::bind_in(appWindowId), margin));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics> : produce_base<D, llm::OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics>
    {
        int32_t __stdcall SetToastWindowMargin(struct struct_Windows_UI_WindowId appWindowId, double margin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetToastWindowMargin(*reinterpret_cast<llm::OS::UI::WindowId const*>(&appWindowId), margin);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Notifications::Preview
{
    inline auto ToastOcclusionManagerPreview::SetToastWindowMargin(llm::OS::UI::WindowId const& appWindowId, double margin)
    {
        impl::call_factory<ToastOcclusionManagerPreview, IToastOcclusionManagerPreviewStatics>([&](IToastOcclusionManagerPreviewStatics const& f) { return f.SetToastWindowMargin(appWindowId, margin); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Notifications::Preview::IToastOcclusionManagerPreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Notifications::Preview::ToastOcclusionManagerPreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
