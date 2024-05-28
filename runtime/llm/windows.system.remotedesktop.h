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
#ifndef LLM_OS_System_RemoteDesktop_H
#define LLM_OS_System_RemoteDesktop_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.System.h"
#include "llm/impl/Windows.System.RemoteDesktop.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_System_RemoteDesktop_IInteractiveSessionStatics<D>::IsRemote() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::System::RemoteDesktop::IInteractiveSessionStatics)->get_IsRemote(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::System::RemoteDesktop::IInteractiveSessionStatics> : produce_base<D, llm::OS::System::RemoteDesktop::IInteractiveSessionStatics>
    {
        int32_t __stdcall get_IsRemote(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsRemote());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::System::RemoteDesktop
{
    inline auto InteractiveSession::IsRemote()
    {
        return impl::call_factory_cast<bool(*)(IInteractiveSessionStatics const&), InteractiveSession, IInteractiveSessionStatics>([](IInteractiveSessionStatics const& f) { return f.IsRemote(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::System::RemoteDesktop::IInteractiveSessionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::System::RemoteDesktop::InteractiveSession> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
