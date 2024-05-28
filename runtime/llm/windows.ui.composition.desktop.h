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
#ifndef LLM_OS_UI_Composition_Desktop_H
#define LLM_OS_UI_Composition_Desktop_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Composition.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Composition.Desktop.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_Desktop_IDesktopWindowTarget<D>::IsTopmost() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Desktop::IDesktopWindowTarget)->get_IsTopmost(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Desktop::IDesktopWindowTarget> : produce_base<D, llm::OS::UI::Composition::Desktop::IDesktopWindowTarget>
    {
        int32_t __stdcall get_IsTopmost(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTopmost());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Composition::Desktop
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Composition::Desktop::IDesktopWindowTarget> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Desktop::DesktopWindowTarget> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
