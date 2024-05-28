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
#ifndef LLM_OS_System_Display_H
#define LLM_OS_System_Display_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.System.Display.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Display_IDisplayRequest<D>::RequestActive() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Display::IDisplayRequest)->RequestActive());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_System_Display_IDisplayRequest<D>::RequestRelease() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::Display::IDisplayRequest)->RequestRelease());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::Display::IDisplayRequest> : produce_base<D, llm::OS::System::Display::IDisplayRequest>
    {
        int32_t __stdcall RequestActive() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestActive();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestRelease() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestRelease();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::Display
{
    inline DisplayRequest::DisplayRequest() :
        DisplayRequest(impl::call_factory_cast<DisplayRequest(*)(llm::OS::Foundation::IActivationFactory const&), DisplayRequest>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DisplayRequest>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::Display::IDisplayRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::Display::DisplayRequest> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
