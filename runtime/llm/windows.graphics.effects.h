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
#ifndef LLM_OS_Graphics_Effects_H
#define LLM_OS_Graphics_Effects_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Graphics.h"
#include "llm/impl/Windows.Graphics.Effects.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Graphics_Effects_IGraphicsEffect<D>::Name() const
    {
        void* name{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Effects::IGraphicsEffect)->get_Name(&name));
        return hstring{ name, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Graphics_Effects_IGraphicsEffect<D>::Name(param::hstring const& name) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Graphics::Effects::IGraphicsEffect)->put_Name(*(void**)(&name)));
    }
    template <typename D>
    struct produce<D, llm::OS::Graphics::Effects::IGraphicsEffect> : produce_base<D, llm::OS::Graphics::Effects::IGraphicsEffect>
    {
        int32_t __stdcall get_Name(void** name) noexcept final try
        {
            clear_abi(name);
            typename D::abi_guard guard(this->shim());
            *name = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* name) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&name));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Graphics::Effects::IGraphicsEffectSource> : produce_base<D, llm::OS::Graphics::Effects::IGraphicsEffectSource>
    {
    };
}
LLM_EXPORT namespace llm::OS::Graphics::Effects
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Graphics::Effects::IGraphicsEffect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Graphics::Effects::IGraphicsEffectSource> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
