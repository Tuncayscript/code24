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
#ifndef LLM_OS_Media_Core_Preview_H
#define LLM_OS_Media_Core_Preview_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Media.Core.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Media.2.h"
#include "llm/impl/Windows.Media.Core.Preview.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SoundLevel) consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics<D>::SoundLevel() const
    {
        llm::OS::Media::SoundLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics)->get_SoundLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics<D>::SoundLevelChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics)->add_SoundLevelChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics<D>::SoundLevelChanged_revoker consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics<D>::SoundLevelChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, SoundLevelChanged_revoker>(this, SoundLevelChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Media_Core_Preview_ISoundLevelBrokerStatics<D>::SoundLevelChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics)->remove_SoundLevelChanged(impl::bind_in(token));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics> : produce_base<D, llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics>
    {
        int32_t __stdcall get_SoundLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SoundLevel>(this->shim().SoundLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SoundLevelChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SoundLevelChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SoundLevelChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SoundLevelChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Media::Core::Preview
{
    inline auto SoundLevelBroker::SoundLevel()
    {
        return impl::call_factory_cast<llm::OS::Media::SoundLevel(*)(ISoundLevelBrokerStatics const&), SoundLevelBroker, ISoundLevelBrokerStatics>([](ISoundLevelBrokerStatics const& f) { return f.SoundLevel(); });
    }
    inline auto SoundLevelBroker::SoundLevelChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<SoundLevelBroker, ISoundLevelBrokerStatics>([&](ISoundLevelBrokerStatics const& f) { return f.SoundLevelChanged(handler); });
    }
    inline SoundLevelBroker::SoundLevelChanged_revoker SoundLevelBroker::SoundLevelChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<SoundLevelBroker, llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics>();
        return { f, f.SoundLevelChanged(handler) };
    }
    inline auto SoundLevelBroker::SoundLevelChanged(llm::event_token const& token)
    {
        impl::call_factory<SoundLevelBroker, ISoundLevelBrokerStatics>([&](ISoundLevelBrokerStatics const& f) { return f.SoundLevelChanged(token); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Media::Core::Preview::ISoundLevelBrokerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Media::Core::Preview::SoundLevelBroker> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
