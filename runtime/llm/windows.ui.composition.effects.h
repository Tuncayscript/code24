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
#ifndef LLM_OS_UI_Composition_Effects_H
#define LLM_OS_UI_Composition_Effects_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Composition.h"
#include "llm/impl/Windows.Graphics.Effects.2.h"
#include "llm/impl/Windows.UI.Composition.Effects.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::AmbientAmount() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->get_AmbientAmount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::AmbientAmount(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->put_AmbientAmount(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::DiffuseAmount() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->get_DiffuseAmount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::DiffuseAmount(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->put_DiffuseAmount(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Effects::IGraphicsEffectSource) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::NormalMapSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->get_NormalMapSource(&value));
        return llm::OS::Graphics::Effects::IGraphicsEffectSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::NormalMapSource(llm::OS::Graphics::Effects::IGraphicsEffectSource const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->put_NormalMapSource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::SpecularAmount() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->get_SpecularAmount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::SpecularAmount(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->put_SpecularAmount(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::SpecularShine() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->get_SpecularShine(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Effects_ISceneLightingEffect<D>::SpecularShine(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect)->put_SpecularShine(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Effects::SceneLightingEffectReflectanceModel) consume_Windows_UI_Composition_Effects_ISceneLightingEffect2<D>::ReflectanceModel() const
    {
        llm::OS::UI::Composition::Effects::SceneLightingEffectReflectanceModel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect2)->get_ReflectanceModel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_Effects_ISceneLightingEffect2<D>::ReflectanceModel(llm::OS::UI::Composition::Effects::SceneLightingEffectReflectanceModel const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::Effects::ISceneLightingEffect2)->put_ReflectanceModel(static_cast<int32_t>(value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Effects::ISceneLightingEffect> : produce_base<D, llm::OS::UI::Composition::Effects::ISceneLightingEffect>
    {
        int32_t __stdcall get_AmbientAmount(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().AmbientAmount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AmbientAmount(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AmbientAmount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DiffuseAmount(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().DiffuseAmount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DiffuseAmount(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DiffuseAmount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NormalMapSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Effects::IGraphicsEffectSource>(this->shim().NormalMapSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NormalMapSource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NormalMapSource(*reinterpret_cast<llm::OS::Graphics::Effects::IGraphicsEffectSource const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpecularAmount(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().SpecularAmount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SpecularAmount(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpecularAmount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SpecularShine(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().SpecularShine());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SpecularShine(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SpecularShine(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::Effects::ISceneLightingEffect2> : produce_base<D, llm::OS::UI::Composition::Effects::ISceneLightingEffect2>
    {
        int32_t __stdcall get_ReflectanceModel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Effects::SceneLightingEffectReflectanceModel>(this->shim().ReflectanceModel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReflectanceModel(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReflectanceModel(*reinterpret_cast<llm::OS::UI::Composition::Effects::SceneLightingEffectReflectanceModel const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Composition::Effects
{
    inline SceneLightingEffect::SceneLightingEffect() :
        SceneLightingEffect(impl::call_factory_cast<SceneLightingEffect(*)(llm::OS::Foundation::IActivationFactory const&), SceneLightingEffect>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SceneLightingEffect>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Composition::Effects::ISceneLightingEffect> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Effects::ISceneLightingEffect2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Effects::SceneLightingEffect> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
