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
#ifndef LLM_OS_UI_Composition_Diagnostics_H
#define LLM_OS_UI_Composition_Diagnostics_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Composition.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Composition.Diagnostics.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Diagnostics_ICompositionDebugHeatMaps<D>::Hide(llm::OS::UI::Composition::Visual const& subtree) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps)->Hide(*(void**)(&subtree)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Diagnostics_ICompositionDebugHeatMaps<D>::ShowMemoryUsage(llm::OS::UI::Composition::Visual const& subtree) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps)->ShowMemoryUsage(*(void**)(&subtree)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Diagnostics_ICompositionDebugHeatMaps<D>::ShowOverdraw(llm::OS::UI::Composition::Visual const& subtree, llm::OS::UI::Composition::Diagnostics::CompositionDebugOverdrawContentKinds const& contentKinds) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps)->ShowOverdraw(*(void**)(&subtree), static_cast<uint32_t>(contentKinds)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Diagnostics_ICompositionDebugHeatMaps<D>::ShowRedraw(llm::OS::UI::Composition::Visual const& subtree) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps)->ShowRedraw(*(void**)(&subtree)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps) consume_Windows_UI_Composition_Diagnostics_ICompositionDebugSettings<D>::HeatMaps() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettings)->get_HeatMaps(&value));
        return llm::OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Diagnostics::CompositionDebugSettings) consume_Windows_UI_Composition_Diagnostics_ICompositionDebugSettingsStatics<D>::TryGetSettings(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics)->TryGetSettings(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::Diagnostics::CompositionDebugSettings{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps> : produce_base<D, llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps>
    {
        int32_t __stdcall Hide(void* subtree) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hide(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&subtree));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowMemoryUsage(void* subtree) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowMemoryUsage(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&subtree));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowOverdraw(void* subtree, uint32_t contentKinds) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowOverdraw(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&subtree), *reinterpret_cast<llm::OS::UI::Composition::Diagnostics::CompositionDebugOverdrawContentKinds const*>(&contentKinds));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowRedraw(void* subtree) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowRedraw(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&subtree));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettings> : produce_base<D, llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettings>
    {
        int32_t __stdcall get_HeatMaps(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps>(this->shim().HeatMaps());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics> : produce_base<D, llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics>
    {
        int32_t __stdcall TryGetSettings(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Diagnostics::CompositionDebugSettings>(this->shim().TryGetSettings(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Composition::Diagnostics
{
    constexpr auto operator|(CompositionDebugOverdrawContentKinds const left, CompositionDebugOverdrawContentKinds const right) noexcept
    {
        return static_cast<CompositionDebugOverdrawContentKinds>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(CompositionDebugOverdrawContentKinds& left, CompositionDebugOverdrawContentKinds const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(CompositionDebugOverdrawContentKinds const left, CompositionDebugOverdrawContentKinds const right) noexcept
    {
        return static_cast<CompositionDebugOverdrawContentKinds>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(CompositionDebugOverdrawContentKinds& left, CompositionDebugOverdrawContentKinds const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(CompositionDebugOverdrawContentKinds const value) noexcept
    {
        return static_cast<CompositionDebugOverdrawContentKinds>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(CompositionDebugOverdrawContentKinds const left, CompositionDebugOverdrawContentKinds const right) noexcept
    {
        return static_cast<CompositionDebugOverdrawContentKinds>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(CompositionDebugOverdrawContentKinds& left, CompositionDebugOverdrawContentKinds const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto CompositionDebugSettings::TryGetSettings(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<CompositionDebugSettings, ICompositionDebugSettingsStatics>([&](ICompositionDebugSettingsStatics const& f) { return f.TryGetSettings(compositor); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Composition::Diagnostics::ICompositionDebugHeatMaps> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Diagnostics::ICompositionDebugSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Diagnostics::CompositionDebugHeatMaps> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Diagnostics::CompositionDebugSettings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
