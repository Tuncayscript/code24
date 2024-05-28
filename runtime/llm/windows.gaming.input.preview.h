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
#ifndef LLM_OS_Gaming_Input_Preview_H
#define LLM_OS_Gaming_Input_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Gaming.Input.h"
#include "llm/impl/Windows.Gaming.Input.Custom.2.h"
#include "llm/impl/Windows.Gaming.Input.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_Input_Preview_IGameControllerProviderInfoStatics<D>::GetParentProviderId(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics)->GetParentProviderId(*(void**)(&provider), &value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Gaming_Input_Preview_IGameControllerProviderInfoStatics<D>::GetProviderId(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics)->GetProviderId(*(void**)(&provider), &value));
        return hstring{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics> : produce_base<D, llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics>
    {
        int32_t __stdcall GetParentProviderId(void* provider, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetParentProviderId(*reinterpret_cast<llm::OS::Gaming::Input::Custom::IGameControllerProvider const*>(&provider)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetProviderId(void* provider, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetProviderId(*reinterpret_cast<llm::OS::Gaming::Input::Custom::IGameControllerProvider const*>(&provider)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Gaming::Input::Preview
{
    inline auto GameControllerProviderInfo::GetParentProviderId(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider)
    {
        return impl::call_factory<GameControllerProviderInfo, IGameControllerProviderInfoStatics>([&](IGameControllerProviderInfoStatics const& f) { return f.GetParentProviderId(provider); });
    }
    inline auto GameControllerProviderInfo::GetProviderId(llm::OS::Gaming::Input::Custom::IGameControllerProvider const& provider)
    {
        return impl::call_factory<GameControllerProviderInfo, IGameControllerProviderInfoStatics>([&](IGameControllerProviderInfoStatics const& f) { return f.GetProviderId(provider); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Gaming::Input::Preview::IGameControllerProviderInfoStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Gaming::Input::Preview::GameControllerProviderInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
