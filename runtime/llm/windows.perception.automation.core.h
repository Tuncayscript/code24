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
#ifndef LLM_OS_Perception_Automation_Core_H
#define LLM_OS_Perception_Automation_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Perception.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Perception.Automation.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Perception_Automation_Core_ICorePerceptionAutomationStatics<D>::SetActivationFactoryProvider(llm::OS::Foundation::IGetActivationFactory const& provider) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Perception::Automation::Core::ICorePerceptionAutomationStatics)->SetActivationFactoryProvider(*(void**)(&provider)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Perception::Automation::Core::ICorePerceptionAutomationStatics> : produce_base<D, llm::OS::Perception::Automation::Core::ICorePerceptionAutomationStatics>
    {
        int32_t __stdcall SetActivationFactoryProvider(void* provider) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetActivationFactoryProvider(*reinterpret_cast<llm::OS::Foundation::IGetActivationFactory const*>(&provider));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Perception::Automation::Core
{
    inline auto CorePerceptionAutomation::SetActivationFactoryProvider(llm::OS::Foundation::IGetActivationFactory const& provider)
    {
        impl::call_factory<CorePerceptionAutomation, ICorePerceptionAutomationStatics>([&](ICorePerceptionAutomationStatics const& f) { return f.SetActivationFactoryProvider(provider); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Perception::Automation::Core::ICorePerceptionAutomationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Perception::Automation::Core::CorePerceptionAutomation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
