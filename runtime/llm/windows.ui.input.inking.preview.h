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
#ifndef LLM_OS_UI_Input_Inking_Preview_H
#define LLM_OS_UI_Input_Inking_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Input.Inking.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Input.Inking.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview) consume_Windows_UI_Input_Inking_Preview_IPalmRejectionDelayZonePreviewStatics<D>::CreateForVisual(llm::OS::UI::Composition::Visual const& inputPanelVisual, llm::OS::Foundation::Rect const& inputPanelRect) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics)->CreateForVisual(*(void**)(&inputPanelVisual), impl::bind_in(inputPanelRect), &result));
        return llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview) consume_Windows_UI_Input_Inking_Preview_IPalmRejectionDelayZonePreviewStatics<D>::CreateForVisual(llm::OS::UI::Composition::Visual const& inputPanelVisual, llm::OS::Foundation::Rect const& inputPanelRect, llm::OS::UI::Composition::Visual const& viewportVisual, llm::OS::Foundation::Rect const& viewportRect) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics)->CreateForVisualWithViewportClip(*(void**)(&inputPanelVisual), impl::bind_in(inputPanelRect), *(void**)(&viewportVisual), impl::bind_in(viewportRect), &result));
        return llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview> : produce_base<D, llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics> : produce_base<D, llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics>
    {
        int32_t __stdcall CreateForVisual(void* inputPanelVisual, llm::OS::Foundation::Rect inputPanelRect, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview>(this->shim().CreateForVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&inputPanelVisual), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&inputPanelRect)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateForVisualWithViewportClip(void* inputPanelVisual, llm::OS::Foundation::Rect inputPanelRect, void* viewportVisual, llm::OS::Foundation::Rect viewportRect, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview>(this->shim().CreateForVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&inputPanelVisual), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&inputPanelRect), *reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&viewportVisual), *reinterpret_cast<llm::OS::Foundation::Rect const*>(&viewportRect)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Input::Inking::Preview
{
    inline auto PalmRejectionDelayZonePreview::CreateForVisual(llm::OS::UI::Composition::Visual const& inputPanelVisual, llm::OS::Foundation::Rect const& inputPanelRect)
    {
        return impl::call_factory<PalmRejectionDelayZonePreview, IPalmRejectionDelayZonePreviewStatics>([&](IPalmRejectionDelayZonePreviewStatics const& f) { return f.CreateForVisual(inputPanelVisual, inputPanelRect); });
    }
    inline auto PalmRejectionDelayZonePreview::CreateForVisual(llm::OS::UI::Composition::Visual const& inputPanelVisual, llm::OS::Foundation::Rect const& inputPanelRect, llm::OS::UI::Composition::Visual const& viewportVisual, llm::OS::Foundation::Rect const& viewportRect)
    {
        return impl::call_factory<PalmRejectionDelayZonePreview, IPalmRejectionDelayZonePreviewStatics>([&](IPalmRejectionDelayZonePreviewStatics const& f) { return f.CreateForVisual(inputPanelVisual, inputPanelRect, viewportVisual, viewportRect); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreview> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Preview::IPalmRejectionDelayZonePreviewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Preview::PalmRejectionDelayZonePreview> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
