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
#ifndef LLM_OS_Data_Html_H
#define LLM_OS_Data_Html_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Data.Html.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Data_Html_IHtmlUtilities<D>::ConvertToText(param::hstring const& html) const
    {
        void* text{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Html::IHtmlUtilities)->ConvertToText(*(void**)(&html), &text));
        return hstring{ text, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Html::IHtmlUtilities> : produce_base<D, llm::OS::Data::Html::IHtmlUtilities>
    {
        int32_t __stdcall ConvertToText(void* html, void** text) noexcept final try
        {
            clear_abi(text);
            typename D::abi_guard guard(this->shim());
            *text = detach_from<hstring>(this->shim().ConvertToText(*reinterpret_cast<hstring const*>(&html)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Data::Html
{
    inline auto HtmlUtilities::ConvertToText(param::hstring const& html)
    {
        return impl::call_factory<HtmlUtilities, IHtmlUtilities>([&](IHtmlUtilities const& f) { return f.ConvertToText(html); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Data::Html::IHtmlUtilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Html::HtmlUtilities> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
