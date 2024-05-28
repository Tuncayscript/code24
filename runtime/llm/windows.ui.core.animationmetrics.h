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
#ifndef LLM_OS_UI_Core_AnimationMetrics_H
#define LLM_OS_UI_Core_AnimationMetrics_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Core.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.Core.AnimationMetrics.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation>) consume_Windows_UI_Core_AnimationMetrics_IAnimationDescription<D>::Animations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IAnimationDescription)->get_Animations(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Core_AnimationMetrics_IAnimationDescription<D>::StaggerDelay() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IAnimationDescription)->get_StaggerDelay(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Core_AnimationMetrics_IAnimationDescription<D>::StaggerDelayFactor() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IAnimationDescription)->get_StaggerDelayFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Core_AnimationMetrics_IAnimationDescription<D>::DelayLimit() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IAnimationDescription)->get_DelayLimit(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Core_AnimationMetrics_IAnimationDescription<D>::ZOrder() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IAnimationDescription)->get_ZOrder(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::AnimationMetrics::AnimationDescription) consume_Windows_UI_Core_AnimationMetrics_IAnimationDescriptionFactory<D>::CreateInstance(llm::OS::UI::Core::AnimationMetrics::AnimationEffect const& effect, llm::OS::UI::Core::AnimationMetrics::AnimationEffectTarget const& target) const
    {
        void* animation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IAnimationDescriptionFactory)->CreateInstance(static_cast<int32_t>(effect), static_cast<int32_t>(target), &animation));
        return llm::OS::UI::Core::AnimationMetrics::AnimationDescription{ animation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<float>) consume_Windows_UI_Core_AnimationMetrics_IOpacityAnimation<D>::InitialOpacity() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IOpacityAnimation)->get_InitialOpacity(&value));
        return llm::OS::Foundation::IReference<float>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Core_AnimationMetrics_IOpacityAnimation<D>::FinalOpacity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IOpacityAnimation)->get_FinalOpacity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::AnimationMetrics::PropertyAnimationType) consume_Windows_UI_Core_AnimationMetrics_IPropertyAnimation<D>::Type() const
    {
        llm::OS::UI::Core::AnimationMetrics::PropertyAnimationType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Core_AnimationMetrics_IPropertyAnimation<D>::Delay() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation)->get_Delay(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Core_AnimationMetrics_IPropertyAnimation<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_AnimationMetrics_IPropertyAnimation<D>::Control1() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation)->get_Control1(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_AnimationMetrics_IPropertyAnimation<D>::Control2() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation)->get_Control2(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<float>) consume_Windows_UI_Core_AnimationMetrics_IScaleAnimation<D>::InitialScaleX() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IScaleAnimation)->get_InitialScaleX(&value));
        return llm::OS::Foundation::IReference<float>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<float>) consume_Windows_UI_Core_AnimationMetrics_IScaleAnimation<D>::InitialScaleY() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IScaleAnimation)->get_InitialScaleY(&value));
        return llm::OS::Foundation::IReference<float>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Core_AnimationMetrics_IScaleAnimation<D>::FinalScaleX() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IScaleAnimation)->get_FinalScaleX(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Core_AnimationMetrics_IScaleAnimation<D>::FinalScaleY() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IScaleAnimation)->get_FinalScaleY(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_AnimationMetrics_IScaleAnimation<D>::NormalizedOrigin() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::AnimationMetrics::IScaleAnimation)->get_NormalizedOrigin(put_abi(value)));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::AnimationMetrics::IAnimationDescription> : produce_base<D, llm::OS::UI::Core::AnimationMetrics::IAnimationDescription>
    {
        int32_t __stdcall get_Animations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation>>(this->shim().Animations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StaggerDelay(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().StaggerDelay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StaggerDelayFactor(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().StaggerDelayFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DelayLimit(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DelayLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ZOrder(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ZOrder());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::AnimationMetrics::IAnimationDescriptionFactory> : produce_base<D, llm::OS::UI::Core::AnimationMetrics::IAnimationDescriptionFactory>
    {
        int32_t __stdcall CreateInstance(int32_t effect, int32_t target, void** animation) noexcept final try
        {
            clear_abi(animation);
            typename D::abi_guard guard(this->shim());
            *animation = detach_from<llm::OS::UI::Core::AnimationMetrics::AnimationDescription>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::UI::Core::AnimationMetrics::AnimationEffect const*>(&effect), *reinterpret_cast<llm::OS::UI::Core::AnimationMetrics::AnimationEffectTarget const*>(&target)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::AnimationMetrics::IOpacityAnimation> : produce_base<D, llm::OS::UI::Core::AnimationMetrics::IOpacityAnimation>
    {
        int32_t __stdcall get_InitialOpacity(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<float>>(this->shim().InitialOpacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FinalOpacity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().FinalOpacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation> : produce_base<D, llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::AnimationMetrics::PropertyAnimationType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Delay(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Delay());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Control1(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().Control1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Control2(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().Control2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::AnimationMetrics::IScaleAnimation> : produce_base<D, llm::OS::UI::Core::AnimationMetrics::IScaleAnimation>
    {
        int32_t __stdcall get_InitialScaleX(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<float>>(this->shim().InitialScaleX());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialScaleY(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<float>>(this->shim().InitialScaleY());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FinalScaleX(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().FinalScaleX());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FinalScaleY(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().FinalScaleY());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NormalizedOrigin(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().NormalizedOrigin());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Core::AnimationMetrics
{
    inline AnimationDescription::AnimationDescription(llm::OS::UI::Core::AnimationMetrics::AnimationEffect const& effect, llm::OS::UI::Core::AnimationMetrics::AnimationEffectTarget const& target) :
        AnimationDescription(impl::call_factory<AnimationDescription, IAnimationDescriptionFactory>([&](IAnimationDescriptionFactory const& f) { return f.CreateInstance(effect, target); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::IAnimationDescription> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::IAnimationDescriptionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::IOpacityAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::IPropertyAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::IScaleAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::AnimationDescription> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::OpacityAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::PropertyAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::ScaleAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AnimationMetrics::TranslationAnimation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
