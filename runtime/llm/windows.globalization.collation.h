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
#ifndef LLM_OS_Globalization_Collation_H
#define LLM_OS_Globalization_Collation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Globalization.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Globalization.Collation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_Collation_ICharacterGrouping<D>::First() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::Collation::ICharacterGrouping)->get_First(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_Collation_ICharacterGrouping<D>::Label() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::Collation::ICharacterGrouping)->get_Label(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Globalization_Collation_ICharacterGroupings<D>::Lookup(param::hstring const& text) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::Collation::ICharacterGroupings)->Lookup(*(void**)(&text), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::Collation::CharacterGroupings) consume_Windows_Globalization_Collation_ICharacterGroupingsFactory<D>::Create(param::hstring const& language) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Globalization::Collation::ICharacterGroupingsFactory)->Create(*(void**)(&language), &result));
        return llm::OS::Globalization::Collation::CharacterGroupings{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::Collation::ICharacterGrouping> : produce_base<D, llm::OS::Globalization::Collation::ICharacterGrouping>
    {
        int32_t __stdcall get_First(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().First());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Label(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Label());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::Collation::ICharacterGroupings> : produce_base<D, llm::OS::Globalization::Collation::ICharacterGroupings>
    {
        int32_t __stdcall Lookup(void* text, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().Lookup(*reinterpret_cast<hstring const*>(&text)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Globalization::Collation::ICharacterGroupingsFactory> : produce_base<D, llm::OS::Globalization::Collation::ICharacterGroupingsFactory>
    {
        int32_t __stdcall Create(void* language, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Globalization::Collation::CharacterGroupings>(this->shim().Create(*reinterpret_cast<hstring const*>(&language)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Globalization::Collation
{
    inline CharacterGroupings::CharacterGroupings() :
        CharacterGroupings(impl::call_factory_cast<CharacterGroupings(*)(llm::OS::Foundation::IActivationFactory const&), CharacterGroupings>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CharacterGroupings>(); }))
    {
    }
    inline CharacterGroupings::CharacterGroupings(param::hstring const& language) :
        CharacterGroupings(impl::call_factory<CharacterGroupings, ICharacterGroupingsFactory>([&](ICharacterGroupingsFactory const& f) { return f.Create(language); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Globalization::Collation::ICharacterGrouping> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::Collation::ICharacterGroupings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::Collation::ICharacterGroupingsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::Collation::CharacterGrouping> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Globalization::Collation::CharacterGroupings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
