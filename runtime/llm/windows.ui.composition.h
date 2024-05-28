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
#ifndef LLM_OS_UI_Composition_H
#define LLM_OS_UI_Composition_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.2.h"
#include "llm/impl/Windows.Graphics.DirectX.2.h"
#include "llm/impl/Windows.Graphics.Effects.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_IAmbientLight<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAmbientLight)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAmbientLight<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAmbientLight)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IAmbientLight2<D>::Intensity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAmbientLight2)->get_Intensity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAmbientLight2<D>::Intensity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAmbientLight2)->put_Intensity(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IAnimationController<D>::PlaybackRate() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->get_PlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationController<D>::PlaybackRate(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->put_PlaybackRate(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IAnimationController<D>::Progress() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationController<D>::Progress(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->put_Progress(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationControllerProgressBehavior) consume_Windows_UI_Composition_IAnimationController<D>::ProgressBehavior() const
    {
        llm::OS::UI::Composition::AnimationControllerProgressBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->get_ProgressBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationController<D>::ProgressBehavior(llm::OS::UI::Composition::AnimationControllerProgressBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->put_ProgressBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationController<D>::Pause() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->Pause());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationController<D>::Resume() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationController)->Resume());
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IAnimationControllerStatics<D>::MaxPlaybackRate() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationControllerStatics)->get_MaxPlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IAnimationControllerStatics<D>::MinPlaybackRate() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationControllerStatics)->get_MinPlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationObject<D>::PopulatePropertyInfo(param::hstring const& propertyName, llm::OS::UI::Composition::AnimationPropertyInfo const& propertyInfo) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationObject)->PopulatePropertyInfo(*(void**)(&propertyName), *(void**)(&propertyInfo)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationPropertyAccessMode) consume_Windows_UI_Composition_IAnimationPropertyInfo<D>::AccessMode() const
    {
        llm::OS::UI::Composition::AnimationPropertyAccessMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationPropertyInfo)->get_AccessMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IAnimationPropertyInfo<D>::AccessMode(llm::OS::UI::Composition::AnimationPropertyAccessMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationPropertyInfo)->put_AccessMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionObject) consume_Windows_UI_Composition_IAnimationPropertyInfo2<D>::GetResolvedCompositionObject() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationPropertyInfo2)->GetResolvedCompositionObject(&result));
        return llm::OS::UI::Composition::CompositionObject{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Composition_IAnimationPropertyInfo2<D>::GetResolvedCompositionObjectProperty() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IAnimationPropertyInfo2)->GetResolvedCompositionObjectProperty(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_IBackEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBackEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBackEasingFunction<D>::Amplitude() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBackEasingFunction)->get_Amplitude(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBooleanKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBooleanKeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_IBounceEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IBounceEasingFunction<D>::Bounces() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceEasingFunction)->get_Bounces(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceEasingFunction<D>::Bounciness() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceEasingFunction)->get_Bounciness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceScalarNaturalMotionAnimation<D>::Acceleration() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation)->get_Acceleration(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBounceScalarNaturalMotionAnimation<D>::Acceleration(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation)->put_Acceleration(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceScalarNaturalMotionAnimation<D>::Restitution() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation)->get_Restitution(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBounceScalarNaturalMotionAnimation<D>::Restitution(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation)->put_Restitution(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceVector2NaturalMotionAnimation<D>::Acceleration() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation)->get_Acceleration(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBounceVector2NaturalMotionAnimation<D>::Acceleration(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation)->put_Acceleration(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceVector2NaturalMotionAnimation<D>::Restitution() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation)->get_Restitution(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBounceVector2NaturalMotionAnimation<D>::Restitution(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation)->put_Restitution(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceVector3NaturalMotionAnimation<D>::Acceleration() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation)->get_Acceleration(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBounceVector3NaturalMotionAnimation<D>::Acceleration(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation)->put_Acceleration(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IBounceVector3NaturalMotionAnimation<D>::Restitution() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation)->get_Restitution(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IBounceVector3NaturalMotionAnimation<D>::Restitution(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation)->put_Restitution(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_ICircleEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICircleEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorSpace) consume_Windows_UI_Composition_IColorKeyFrameAnimation<D>::InterpolationColorSpace() const
    {
        llm::OS::UI::Composition::CompositionColorSpace value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IColorKeyFrameAnimation)->get_InterpolationColorSpace(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IColorKeyFrameAnimation<D>::InterpolationColorSpace(llm::OS::UI::Composition::CompositionColorSpace const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IColorKeyFrameAnimation)->put_InterpolationColorSpace(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IColorKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IColorKeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IColorKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::UI::Color const& value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IColorKeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, impl::bind_in(value), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::ClearAllParameters() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->ClearAllParameters());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::ClearParameter(param::hstring const& key) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->ClearParameter(*(void**)(&key)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetColorParameter(param::hstring const& key, llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetColorParameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetMatrix3x2Parameter(param::hstring const& key, llm::OS::Foundation::Numerics::float3x2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetMatrix3x2Parameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetMatrix4x4Parameter(param::hstring const& key, llm::OS::Foundation::Numerics::float4x4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetMatrix4x4Parameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetQuaternionParameter(param::hstring const& key, llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetQuaternionParameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetReferenceParameter(param::hstring const& key, llm::OS::UI::Composition::CompositionObject const& compositionObject) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetReferenceParameter(*(void**)(&key), *(void**)(&compositionObject)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetScalarParameter(param::hstring const& key, float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetScalarParameter(*(void**)(&key), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetVector2Parameter(param::hstring const& key, llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetVector2Parameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetVector3Parameter(param::hstring const& key, llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetVector3Parameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation<D>::SetVector4Parameter(param::hstring const& key, llm::OS::Foundation::Numerics::float4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation)->SetVector4Parameter(*(void**)(&key), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation2<D>::SetBooleanParameter(param::hstring const& key, bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation2)->SetBooleanParameter(*(void**)(&key), value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Composition_ICompositionAnimation2<D>::Target() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation2)->get_Target(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation2<D>::Target(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation2)->put_Target(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::InitialValueExpressionCollection) consume_Windows_UI_Composition_ICompositionAnimation3<D>::InitialValueExpressions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation3)->get_InitialValueExpressions(&value));
        return llm::OS::UI::Composition::InitialValueExpressionCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimation4<D>::SetExpressionReferenceParameter(param::hstring const& parameterName, llm::OS::UI::Composition::IAnimationObject const& source) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimation4)->SetExpressionReferenceParameter(*(void**)(&parameterName), *(void**)(&source)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_ICompositionAnimationGroup<D>::Count() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimationGroup)->get_Count(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimationGroup<D>::Add(llm::OS::UI::Composition::CompositionAnimation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimationGroup)->Add(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimationGroup<D>::Remove(llm::OS::UI::Composition::CompositionAnimation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimationGroup)->Remove(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionAnimationGroup<D>::RemoveAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionAnimationGroup)->RemoveAll());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionCapabilities<D>::AreEffectsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCapabilities)->AreEffectsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionCapabilities<D>::AreEffectsFast() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCapabilities)->AreEffectsFast(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Composition_ICompositionCapabilities<D>::Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::CompositionCapabilities, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCapabilities)->add_Changed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Composition_ICompositionCapabilities<D>::Changed_revoker consume_Windows_UI_Composition_ICompositionCapabilities<D>::Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::CompositionCapabilities, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Changed_revoker>(this, Changed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionCapabilities<D>::Changed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCapabilities)->remove_Changed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionCapabilities) consume_Windows_UI_Composition_ICompositionCapabilitiesStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCapabilitiesStatics)->GetForCurrentView(&result));
        return llm::OS::UI::Composition::CompositionCapabilities{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionClip2<D>::AnchorPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_AnchorPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::AnchorPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_AnchorPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionClip2<D>::CenterPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_CenterPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::CenterPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_CenterPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionClip2<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionClip2<D>::RotationAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_RotationAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::RotationAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_RotationAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionClip2<D>::RotationAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_RotationAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::RotationAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_RotationAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionClip2<D>::Scale() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_Scale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::Scale(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_Scale(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3x2) consume_Windows_UI_Composition_ICompositionClip2<D>::TransformMatrix() const
    {
        llm::OS::Foundation::Numerics::float3x2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->get_TransformMatrix(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionClip2<D>::TransformMatrix(llm::OS::Foundation::Numerics::float3x2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionClip2)->put_TransformMatrix(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_ICompositionColorBrush<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionColorBrush)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionColorBrush<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionColorBrush)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_ICompositionColorGradientStop<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionColorGradientStop)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionColorGradientStop<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionColorGradientStop)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionColorGradientStop<D>::Offset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionColorGradientStop)->get_Offset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionColorGradientStop<D>::Offset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionColorGradientStop)->put_Offset(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionCommitBatch<D>::IsActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCommitBatch)->get_IsActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionCommitBatch<D>::IsEnded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCommitBatch)->get_IsEnded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Composition_ICompositionCommitBatch<D>::Completed(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCommitBatch)->add_Completed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Composition_ICompositionCommitBatch<D>::Completed_revoker consume_Windows_UI_Composition_ICompositionCommitBatch<D>::Completed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Completed_revoker>(this, Completed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionCommitBatch<D>::Completed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionCommitBatch)->remove_Completed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionShapeCollection) consume_Windows_UI_Composition_ICompositionContainerShape<D>::Shapes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionContainerShape)->get_Shapes(&value));
        return llm::OS::UI::Composition::CompositionShapeCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXAlphaMode) consume_Windows_UI_Composition_ICompositionDrawingSurface<D>::AlphaMode() const
    {
        llm::OS::Graphics::DirectX::DirectXAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface)->get_AlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_UI_Composition_ICompositionDrawingSurface<D>::PixelFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface)->get_PixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Composition_ICompositionDrawingSurface<D>::Size() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>::SizeInt32() const
    {
        llm::OS::Graphics::SizeInt32 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface2)->get_SizeInt32(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>::Resize(llm::OS::Graphics::SizeInt32 const& sizePixels) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface2)->Resize(impl::bind_in(sizePixels)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>::Scroll(llm::OS::Graphics::PointInt32 const& offset) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface2)->Scroll(impl::bind_in(offset)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>::Scroll(llm::OS::Graphics::PointInt32 const& offset, llm::OS::Graphics::RectInt32 const& scrollRect) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface2)->ScrollRect(impl::bind_in(offset), impl::bind_in(scrollRect)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>::ScrollWithClip(llm::OS::Graphics::PointInt32 const& offset, llm::OS::Graphics::RectInt32 const& clipRect) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface2)->ScrollWithClip(impl::bind_in(offset), impl::bind_in(clipRect)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionDrawingSurface2<D>::ScrollWithClip(llm::OS::Graphics::PointInt32 const& offset, llm::OS::Graphics::RectInt32 const& clipRect, llm::OS::Graphics::RectInt32 const& scrollRect) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionDrawingSurface2)->ScrollRectWithClip(impl::bind_in(offset), impl::bind_in(clipRect), impl::bind_in(scrollRect)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CubicBezierEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateCubicBezierEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::Foundation::Numerics::float2 const& controlPoint1, llm::OS::Foundation::Numerics::float2 const& controlPoint2) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateCubicBezierEasingFunction(*(void**)(&owner), impl::bind_in(controlPoint1), impl::bind_in(controlPoint2), &result));
        return llm::OS::UI::Composition::CubicBezierEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::LinearEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateLinearEasingFunction(llm::OS::UI::Composition::Compositor const& owner) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateLinearEasingFunction(*(void**)(&owner), &result));
        return llm::OS::UI::Composition::LinearEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::StepEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateStepEasingFunction(llm::OS::UI::Composition::Compositor const& owner) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateStepEasingFunction(*(void**)(&owner), &result));
        return llm::OS::UI::Composition::StepEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::StepEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateStepEasingFunction(llm::OS::UI::Composition::Compositor const& owner, int32_t stepCount) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateStepEasingFunctionWithStepCount(*(void**)(&owner), stepCount, &result));
        return llm::OS::UI::Composition::StepEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::BackEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateBackEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, float amplitude) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateBackEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), amplitude, &result));
        return llm::OS::UI::Composition::BackEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::BounceEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateBounceEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t bounces, float bounciness) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateBounceEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), bounces, bounciness, &result));
        return llm::OS::UI::Composition::BounceEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CircleEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateCircleEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateCircleEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), &result));
        return llm::OS::UI::Composition::CircleEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ElasticEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateElasticEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t oscillations, float springiness) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateElasticEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), oscillations, springiness, &result));
        return llm::OS::UI::Composition::ElasticEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ExponentialEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateExponentialEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, float exponent) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateExponentialEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), exponent, &result));
        return llm::OS::UI::Composition::ExponentialEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::PowerEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreatePowerEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, float power) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreatePowerEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), power, &result));
        return llm::OS::UI::Composition::PowerEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::SineEasingFunction) consume_Windows_UI_Composition_ICompositionEasingFunctionStatics<D>::CreateSineEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEasingFunctionStatics)->CreateSineEasingFunction(*(void**)(&owner), static_cast<int32_t>(mode), &result));
        return llm::OS::UI::Composition::SineEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionEffectBrush<D>::GetSourceParameter(param::hstring const& name) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectBrush)->GetSourceParameter(*(void**)(&name), &result));
        return llm::OS::UI::Composition::CompositionBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionEffectBrush<D>::SetSourceParameter(param::hstring const& name, llm::OS::UI::Composition::CompositionBrush const& source) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectBrush)->SetSourceParameter(*(void**)(&name), *(void**)(&source)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEffectBrush) consume_Windows_UI_Composition_ICompositionEffectFactory<D>::CreateBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectFactory)->CreateBrush(&result));
        return llm::OS::UI::Composition::CompositionEffectBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_UI_Composition_ICompositionEffectFactory<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectFactory)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEffectFactoryLoadStatus) consume_Windows_UI_Composition_ICompositionEffectFactory<D>::LoadStatus() const
    {
        llm::OS::UI::Composition::CompositionEffectFactoryLoadStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectFactory)->get_LoadStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Composition_ICompositionEffectSourceParameter<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectSourceParameter)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEffectSourceParameter) consume_Windows_UI_Composition_ICompositionEffectSourceParameterFactory<D>::Create(param::hstring const& name) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEffectSourceParameterFactory)->Create(*(void**)(&name), &value));
        return llm::OS::UI::Composition::CompositionEffectSourceParameter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionEllipseGeometry<D>::Center() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEllipseGeometry)->get_Center(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionEllipseGeometry<D>::Center(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEllipseGeometry)->put_Center(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionEllipseGeometry<D>::Radius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEllipseGeometry)->get_Radius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionEllipseGeometry<D>::Radius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionEllipseGeometry)->put_Radius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGeometry) consume_Windows_UI_Composition_ICompositionGeometricClip<D>::Geometry() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometricClip)->get_Geometry(&value));
        return llm::OS::UI::Composition::CompositionGeometry{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGeometricClip<D>::Geometry(llm::OS::UI::Composition::CompositionGeometry const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometricClip)->put_Geometry(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionViewBox) consume_Windows_UI_Composition_ICompositionGeometricClip<D>::ViewBox() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometricClip)->get_ViewBox(&value));
        return llm::OS::UI::Composition::CompositionViewBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGeometricClip<D>::ViewBox(llm::OS::UI::Composition::CompositionViewBox const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometricClip)->put_ViewBox(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionGeometry<D>::TrimEnd() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometry)->get_TrimEnd(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGeometry<D>::TrimEnd(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometry)->put_TrimEnd(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionGeometry<D>::TrimOffset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometry)->get_TrimOffset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGeometry<D>::TrimOffset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometry)->put_TrimOffset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionGeometry<D>::TrimStart() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometry)->get_TrimStart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGeometry<D>::TrimStart(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGeometry)->put_TrimStart(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::AnchorPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_AnchorPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::AnchorPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_AnchorPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::CenterPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_CenterPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::CenterPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_CenterPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorGradientStopCollection) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::ColorStops() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_ColorStops(&value));
        return llm::OS::UI::Composition::CompositionColorGradientStopCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGradientExtendMode) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::ExtendMode() const
    {
        llm::OS::UI::Composition::CompositionGradientExtendMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_ExtendMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::ExtendMode(llm::OS::UI::Composition::CompositionGradientExtendMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_ExtendMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorSpace) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::InterpolationSpace() const
    {
        llm::OS::UI::Composition::CompositionColorSpace value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_InterpolationSpace(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::InterpolationSpace(llm::OS::UI::Composition::CompositionColorSpace const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_InterpolationSpace(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::RotationAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_RotationAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::RotationAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_RotationAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::RotationAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_RotationAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::RotationAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_RotationAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::Scale() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_Scale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::Scale(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_Scale(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3x2) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::TransformMatrix() const
    {
        llm::OS::Foundation::Numerics::float3x2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->get_TransformMatrix(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush<D>::TransformMatrix(llm::OS::Foundation::Numerics::float3x2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush)->put_TransformMatrix(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionMappingMode) consume_Windows_UI_Composition_ICompositionGradientBrush2<D>::MappingMode() const
    {
        llm::OS::UI::Composition::CompositionMappingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush2)->get_MappingMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGradientBrush2<D>::MappingMode(llm::OS::UI::Composition::CompositionMappingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGradientBrush2)->put_MappingMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionDrawingSurface) consume_Windows_UI_Composition_ICompositionGraphicsDevice<D>::CreateDrawingSurface(llm::OS::Foundation::Size const& sizePixels, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice)->CreateDrawingSurface(impl::bind_in(sizePixels), static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), &result));
        return llm::OS::UI::Composition::CompositionDrawingSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Composition_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::CompositionGraphicsDevice, llm::OS::UI::Composition::RenderingDeviceReplacedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice)->add_RenderingDeviceReplaced(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Composition_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced_revoker consume_Windows_UI_Composition_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::CompositionGraphicsDevice, llm::OS::UI::Composition::RenderingDeviceReplacedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, RenderingDeviceReplaced_revoker>(this, RenderingDeviceReplaced(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGraphicsDevice<D>::RenderingDeviceReplaced(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice)->remove_RenderingDeviceReplaced(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionDrawingSurface) consume_Windows_UI_Composition_ICompositionGraphicsDevice2<D>::CreateDrawingSurface2(llm::OS::Graphics::SizeInt32 const& sizePixels, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice2)->CreateDrawingSurface2(impl::bind_in(sizePixels), static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), &result));
        return llm::OS::UI::Composition::CompositionDrawingSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionVirtualDrawingSurface) consume_Windows_UI_Composition_ICompositionGraphicsDevice2<D>::CreateVirtualDrawingSurface(llm::OS::Graphics::SizeInt32 const& sizePixels, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice2)->CreateVirtualDrawingSurface(impl::bind_in(sizePixels), static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), &result));
        return llm::OS::UI::Composition::CompositionVirtualDrawingSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionMipmapSurface) consume_Windows_UI_Composition_ICompositionGraphicsDevice3<D>::CreateMipmapSurface(llm::OS::Graphics::SizeInt32 const& sizePixels, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice3)->CreateMipmapSurface(impl::bind_in(sizePixels), static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), &result));
        return llm::OS::UI::Composition::CompositionMipmapSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionGraphicsDevice3<D>::Trim() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice3)->Trim());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Composition::ICompositionSurface>) consume_Windows_UI_Composition_ICompositionGraphicsDevice4<D>::CaptureAsync(llm::OS::UI::Composition::Visual const& captureVisual, llm::OS::Graphics::SizeInt32 const& size, llm::OS::Graphics::DirectX::DirectXPixelFormat const& pixelFormat, llm::OS::Graphics::DirectX::DirectXAlphaMode const& alphaMode, float sdrBoost) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionGraphicsDevice4)->CaptureAsync(*(void**)(&captureVisual), impl::bind_in(size), static_cast<int32_t>(pixelFormat), static_cast<int32_t>(alphaMode), sdrBoost, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Composition::ICompositionSurface>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::VisualUnorderedCollection) consume_Windows_UI_Composition_ICompositionLight<D>::Targets() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLight)->get_Targets(&value));
        return llm::OS::UI::Composition::VisualUnorderedCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::VisualUnorderedCollection) consume_Windows_UI_Composition_ICompositionLight2<D>::ExclusionsFromTargets() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLight2)->get_ExclusionsFromTargets(&value));
        return llm::OS::UI::Composition::VisualUnorderedCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionLight3<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLight3)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionLight3<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLight3)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionLineGeometry<D>::Start() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLineGeometry)->get_Start(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionLineGeometry<D>::Start(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLineGeometry)->put_Start(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionLineGeometry<D>::End() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLineGeometry)->get_End(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionLineGeometry<D>::End(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLineGeometry)->put_End(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionLinearGradientBrush<D>::EndPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLinearGradientBrush)->get_EndPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionLinearGradientBrush<D>::EndPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLinearGradientBrush)->put_EndPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionLinearGradientBrush<D>::StartPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLinearGradientBrush)->get_StartPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionLinearGradientBrush<D>::StartPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionLinearGradientBrush)->put_StartPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionMaskBrush<D>::Mask() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMaskBrush)->get_Mask(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionMaskBrush<D>::Mask(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMaskBrush)->put_Mask(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionMaskBrush<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMaskBrush)->get_Source(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionMaskBrush<D>::Source(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMaskBrush)->put_Source(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Composition_ICompositionMipmapSurface<D>::LevelCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMipmapSurface)->get_LevelCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXAlphaMode) consume_Windows_UI_Composition_ICompositionMipmapSurface<D>::AlphaMode() const
    {
        llm::OS::Graphics::DirectX::DirectXAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMipmapSurface)->get_AlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXPixelFormat) consume_Windows_UI_Composition_ICompositionMipmapSurface<D>::PixelFormat() const
    {
        llm::OS::Graphics::DirectX::DirectXPixelFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMipmapSurface)->get_PixelFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::SizeInt32) consume_Windows_UI_Composition_ICompositionMipmapSurface<D>::SizeInt32() const
    {
        llm::OS::Graphics::SizeInt32 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMipmapSurface)->get_SizeInt32(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionDrawingSurface) consume_Windows_UI_Composition_ICompositionMipmapSurface<D>::GetDrawingSurfaceForLevel(uint32_t level) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionMipmapSurface)->GetDrawingSurfaceForLevel(level, &result));
        return llm::OS::UI::Composition::CompositionDrawingSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::BottomInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_BottomInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::BottomInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_BottomInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::BottomInsetScale() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_BottomInsetScale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::BottomInsetScale(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_BottomInsetScale(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::IsCenterHollow() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_IsCenterHollow(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::IsCenterHollow(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_IsCenterHollow(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::LeftInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_LeftInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::LeftInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_LeftInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::LeftInsetScale() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_LeftInsetScale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::LeftInsetScale(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_LeftInsetScale(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::RightInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_RightInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::RightInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_RightInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::RightInsetScale() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_RightInsetScale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::RightInsetScale(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_RightInsetScale(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_Source(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::Source(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_Source(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::TopInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_TopInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::TopInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_TopInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::TopInsetScale() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->get_TopInsetScale(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::TopInsetScale(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->put_TopInsetScale(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::SetInsets(float inset) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->SetInsets(inset));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::SetInsets(float left, float top, float right, float bottom) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->SetInsetsWithValues(left, top, right, bottom));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::SetInsetScales(float scale) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->SetInsetScales(scale));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionNineGridBrush<D>::SetInsetScales(float left, float top, float right, float bottom) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionNineGridBrush)->SetInsetScalesWithValues(left, top, right, bottom));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Compositor) consume_Windows_UI_Composition_ICompositionObject<D>::Compositor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject)->get_Compositor(&value));
        return llm::OS::UI::Composition::Compositor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcher) consume_Windows_UI_Composition_ICompositionObject<D>::Dispatcher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject)->get_Dispatcher(&value));
        return llm::OS::UI::Core::CoreDispatcher{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionPropertySet) consume_Windows_UI_Composition_ICompositionObject<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject)->get_Properties(&value));
        return llm::OS::UI::Composition::CompositionPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject<D>::StartAnimation(param::hstring const& propertyName, llm::OS::UI::Composition::CompositionAnimation const& animation) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject)->StartAnimation(*(void**)(&propertyName), *(void**)(&animation)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject<D>::StopAnimation(param::hstring const& propertyName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject)->StopAnimation(*(void**)(&propertyName)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Composition_ICompositionObject2<D>::Comment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject2)->get_Comment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject2<D>::Comment(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject2)->put_Comment(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ImplicitAnimationCollection) consume_Windows_UI_Composition_ICompositionObject2<D>::ImplicitAnimations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject2)->get_ImplicitAnimations(&value));
        return llm::OS::UI::Composition::ImplicitAnimationCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject2<D>::ImplicitAnimations(llm::OS::UI::Composition::ImplicitAnimationCollection const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject2)->put_ImplicitAnimations(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject2<D>::StartAnimationGroup(llm::OS::UI::Composition::ICompositionAnimationBase const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject2)->StartAnimationGroup(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject2<D>::StopAnimationGroup(llm::OS::UI::Composition::ICompositionAnimationBase const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject2)->StopAnimationGroup(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_UI_Composition_ICompositionObject3<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject3)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationController) consume_Windows_UI_Composition_ICompositionObject4<D>::TryGetAnimationController(param::hstring const& propertyName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject4)->TryGetAnimationController(*(void**)(&propertyName), &result));
        return llm::OS::UI::Composition::AnimationController{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObject5<D>::StartAnimation(param::hstring const& propertyName, llm::OS::UI::Composition::CompositionAnimation const& animation, llm::OS::UI::Composition::AnimationController const& animationController) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObject5)->StartAnimationWithController(*(void**)(&propertyName), *(void**)(&animation), *(void**)(&animationController)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObjectStatics<D>::StartAnimationWithIAnimationObject(llm::OS::UI::Composition::IAnimationObject const& target, param::hstring const& propertyName, llm::OS::UI::Composition::CompositionAnimation const& animation) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObjectStatics)->StartAnimationWithIAnimationObject(*(void**)(&target), *(void**)(&propertyName), *(void**)(&animation)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionObjectStatics<D>::StartAnimationGroupWithIAnimationObject(llm::OS::UI::Composition::IAnimationObject const& target, llm::OS::UI::Composition::ICompositionAnimationBase const& animation) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionObjectStatics)->StartAnimationGroupWithIAnimationObject(*(void**)(&target), *(void**)(&animation)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionPath) consume_Windows_UI_Composition_ICompositionPathFactory<D>::Create(llm::OS::Graphics::IGeometrySource2D const& source) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPathFactory)->Create(*(void**)(&source), &value));
        return llm::OS::UI::Composition::CompositionPath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionPath) consume_Windows_UI_Composition_ICompositionPathGeometry<D>::Path() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPathGeometry)->get_Path(&value));
        return llm::OS::UI::Composition::CompositionPath{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPathGeometry<D>::Path(llm::OS::UI::Composition::CompositionPath const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPathGeometry)->put_Path(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::BlurRadiusMultiplier() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->get_BlurRadiusMultiplier(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::BlurRadiusMultiplier(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->put_BlurRadiusMultiplier(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionProjectedShadowCasterCollection) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::Casters() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->get_Casters(&value));
        return llm::OS::UI::Composition::CompositionProjectedShadowCasterCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionLight) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::LightSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->get_LightSource(&value));
        return llm::OS::UI::Composition::CompositionLight{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::LightSource(llm::OS::UI::Composition::CompositionLight const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->put_LightSource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::MaxBlurRadius() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->get_MaxBlurRadius(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::MaxBlurRadius(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->put_MaxBlurRadius(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::MinBlurRadius() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->get_MinBlurRadius(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::MinBlurRadius(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->put_MinBlurRadius(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection) consume_Windows_UI_Composition_ICompositionProjectedShadow<D>::Receivers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadow)->get_Receivers(&value));
        return llm::OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionProjectedShadowCaster<D>::Brush() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCaster)->get_Brush(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCaster<D>::Brush(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCaster)->put_Brush(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_ICompositionProjectedShadowCaster<D>::CastingVisual() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCaster)->get_CastingVisual(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCaster<D>::CastingVisual(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCaster)->put_CastingVisual(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::Count() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->get_Count(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::InsertAbove(llm::OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster, llm::OS::UI::Composition::CompositionProjectedShadowCaster const& reference) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->InsertAbove(*(void**)(&newCaster), *(void**)(&reference)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::InsertAtBottom(llm::OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->InsertAtBottom(*(void**)(&newCaster)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::InsertAtTop(llm::OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->InsertAtTop(*(void**)(&newCaster)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::InsertBelow(llm::OS::UI::Composition::CompositionProjectedShadowCaster const& newCaster, llm::OS::UI::Composition::CompositionProjectedShadowCaster const& reference) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->InsertBelow(*(void**)(&newCaster), *(void**)(&reference)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::Remove(llm::OS::UI::Composition::CompositionProjectedShadowCaster const& caster) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->Remove(*(void**)(&caster)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollection<D>::RemoveAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection)->RemoveAll());
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_ICompositionProjectedShadowCasterCollectionStatics<D>::MaxRespectedCasters() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics)->get_MaxRespectedCasters(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_ICompositionProjectedShadowReceiver<D>::ReceivingVisual() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowReceiver)->get_ReceivingVisual(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowReceiver<D>::ReceivingVisual(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowReceiver)->put_ReceivingVisual(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowReceiverUnorderedCollection<D>::Add(llm::OS::UI::Composition::CompositionProjectedShadowReceiver const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection)->Add(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_ICompositionProjectedShadowReceiverUnorderedCollection<D>::Count() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection)->get_Count(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowReceiverUnorderedCollection<D>::Remove(llm::OS::UI::Composition::CompositionProjectedShadowReceiver const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection)->Remove(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionProjectedShadowReceiverUnorderedCollection<D>::RemoveAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection)->RemoveAll());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertColor(param::hstring const& propertyName, llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertColor(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertMatrix3x2(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float3x2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertMatrix3x2(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertMatrix4x4(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float4x4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertMatrix4x4(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertQuaternion(param::hstring const& propertyName, llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertQuaternion(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertScalar(param::hstring const& propertyName, float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertScalar(*(void**)(&propertyName), value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertVector2(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertVector2(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertVector3(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertVector3(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet<D>::InsertVector4(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->InsertVector4(*(void**)(&propertyName), impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetColor(param::hstring const& propertyName, llm::OS::UI::Color& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetColor(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetMatrix3x2(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float3x2& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetMatrix3x2(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetMatrix4x4(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float4x4& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetMatrix4x4(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetQuaternion(param::hstring const& propertyName, llm::OS::Foundation::Numerics::quaternion& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetQuaternion(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetScalar(param::hstring const& propertyName, float& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetScalar(*(void**)(&propertyName), &value, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetVector2(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float2& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetVector2(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetVector3(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float3& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetVector3(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet<D>::TryGetVector4(param::hstring const& propertyName, llm::OS::Foundation::Numerics::float4& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet)->TryGetVector4(*(void**)(&propertyName), impl::bind_out(value), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionPropertySet2<D>::InsertBoolean(param::hstring const& propertyName, bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet2)->InsertBoolean(*(void**)(&propertyName), value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGetValueStatus) consume_Windows_UI_Composition_ICompositionPropertySet2<D>::TryGetBoolean(param::hstring const& propertyName, bool& value) const
    {
        llm::OS::UI::Composition::CompositionGetValueStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionPropertySet2)->TryGetBoolean(*(void**)(&propertyName), &value, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>::EllipseCenter() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRadialGradientBrush)->get_EllipseCenter(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>::EllipseCenter(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRadialGradientBrush)->put_EllipseCenter(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>::EllipseRadius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRadialGradientBrush)->get_EllipseRadius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>::EllipseRadius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRadialGradientBrush)->put_EllipseRadius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>::GradientOriginOffset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRadialGradientBrush)->get_GradientOriginOffset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRadialGradientBrush<D>::GradientOriginOffset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRadialGradientBrush)->put_GradientOriginOffset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRectangleGeometry<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRectangleGeometry)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRectangleGeometry<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRectangleGeometry)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRectangleGeometry<D>::Size() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRectangleGeometry)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRectangleGeometry<D>::Size(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRectangleGeometry)->put_Size(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>::CornerRadius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry)->get_CornerRadius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>::CornerRadius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry)->put_CornerRadius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>::Size() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionRoundedRectangleGeometry<D>::Size(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry)->put_Size(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::IsActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->get_IsActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::IsEnded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->get_IsEnded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::End() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->End());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::Resume() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->Resume());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::Suspend() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->Suspend());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::Completed(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->add_Completed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Composition_ICompositionScopedBatch<D>::Completed_revoker consume_Windows_UI_Composition_ICompositionScopedBatch<D>::Completed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Completed_revoker>(this, Completed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionScopedBatch<D>::Completed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionScopedBatch)->remove_Completed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionShape<D>::CenterPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->get_CenterPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionShape<D>::CenterPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->put_CenterPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionShape<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionShape<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionShape<D>::RotationAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->get_RotationAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionShape<D>::RotationAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->put_RotationAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionShape<D>::RotationAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->get_RotationAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionShape<D>::RotationAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->put_RotationAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionShape<D>::Scale() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->get_Scale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionShape<D>::Scale(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->put_Scale(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3x2) consume_Windows_UI_Composition_ICompositionShape<D>::TransformMatrix() const
    {
        llm::OS::Foundation::Numerics::float3x2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->get_TransformMatrix(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionShape<D>::TransformMatrix(llm::OS::Foundation::Numerics::float3x2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionShape)->put_TransformMatrix(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::FillBrush() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_FillBrush(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::FillBrush(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_FillBrush(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGeometry) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::Geometry() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_Geometry(&value));
        return llm::OS::UI::Composition::CompositionGeometry{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::Geometry(llm::OS::UI::Composition::CompositionGeometry const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_Geometry(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::IsStrokeNonScaling() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_IsStrokeNonScaling(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::IsStrokeNonScaling(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_IsStrokeNonScaling(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeBrush() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeBrush(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeBrush(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeBrush(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStrokeDashArray) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeDashArray() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeDashArray(&value));
        return llm::OS::UI::Composition::CompositionStrokeDashArray{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStrokeCap) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeDashCap() const
    {
        llm::OS::UI::Composition::CompositionStrokeCap value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeDashCap(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeDashCap(llm::OS::UI::Composition::CompositionStrokeCap const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeDashCap(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeDashOffset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeDashOffset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeDashOffset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeDashOffset(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStrokeCap) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeEndCap() const
    {
        llm::OS::UI::Composition::CompositionStrokeCap value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeEndCap(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeEndCap(llm::OS::UI::Composition::CompositionStrokeCap const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeEndCap(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStrokeLineJoin) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeLineJoin() const
    {
        llm::OS::UI::Composition::CompositionStrokeLineJoin value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeLineJoin(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeLineJoin(llm::OS::UI::Composition::CompositionStrokeLineJoin const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeLineJoin(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeMiterLimit() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeMiterLimit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeMiterLimit(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeMiterLimit(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStrokeCap) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeStartCap() const
    {
        llm::OS::UI::Composition::CompositionStrokeCap value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeStartCap(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeStartCap(llm::OS::UI::Composition::CompositionStrokeCap const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeStartCap(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeThickness() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->get_StrokeThickness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSpriteShape<D>::StrokeThickness(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSpriteShape)->put_StrokeThickness(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ICompositionSupportsSystemBackdrop<D>::SystemBackdrop() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSupportsSystemBackdrop)->get_SystemBackdrop(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSupportsSystemBackdrop<D>::SystemBackdrop(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSupportsSystemBackdrop)->put_SystemBackdrop(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBitmapInterpolationMode) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::BitmapInterpolationMode() const
    {
        llm::OS::UI::Composition::CompositionBitmapInterpolationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->get_BitmapInterpolationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::BitmapInterpolationMode(llm::OS::UI::Composition::CompositionBitmapInterpolationMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->put_BitmapInterpolationMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::HorizontalAlignmentRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->get_HorizontalAlignmentRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::HorizontalAlignmentRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->put_HorizontalAlignmentRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStretch) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::Stretch() const
    {
        llm::OS::UI::Composition::CompositionStretch value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->get_Stretch(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::Stretch(llm::OS::UI::Composition::CompositionStretch const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->put_Stretch(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ICompositionSurface) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::Surface() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->get_Surface(&value));
        return llm::OS::UI::Composition::ICompositionSurface{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::Surface(llm::OS::UI::Composition::ICompositionSurface const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->put_Surface(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::VerticalAlignmentRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->get_VerticalAlignmentRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush<D>::VerticalAlignmentRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush)->put_VerticalAlignmentRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::AnchorPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_AnchorPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::AnchorPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_AnchorPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::CenterPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_CenterPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::CenterPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_CenterPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::RotationAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_RotationAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::RotationAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_RotationAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::RotationAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_RotationAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::RotationAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_RotationAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::Scale() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_Scale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::Scale(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_Scale(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3x2) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::TransformMatrix() const
    {
        llm::OS::Foundation::Numerics::float3x2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->get_TransformMatrix(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush2<D>::TransformMatrix(llm::OS::Foundation::Numerics::float3x2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush2)->put_TransformMatrix(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_ICompositionSurfaceBrush3<D>::SnapToPixels() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush3)->get_SnapToPixels(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionSurfaceBrush3<D>::SnapToPixels(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceBrush3)->put_SnapToPixels(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ICompositionSurface) consume_Windows_UI_Composition_ICompositionSurfaceFacade<D>::GetRealSurface() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionSurfaceFacade)->GetRealSurface(&result));
        return llm::OS::UI::Composition::ICompositionSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_ICompositionTarget<D>::Root() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTarget)->get_Root(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionTarget<D>::Root(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTarget)->put_Root(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::RectInt32) consume_Windows_UI_Composition_ICompositionTexture<D>::SourceRect() const
    {
        llm::OS::Graphics::RectInt32 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTexture)->get_SourceRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionTexture<D>::SourceRect(llm::OS::Graphics::RectInt32 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTexture)->put_SourceRect(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXAlphaMode) consume_Windows_UI_Composition_ICompositionTexture<D>::AlphaMode() const
    {
        llm::OS::Graphics::DirectX::DirectXAlphaMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTexture)->get_AlphaMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionTexture<D>::AlphaMode(llm::OS::Graphics::DirectX::DirectXAlphaMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTexture)->put_AlphaMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::DirectX::DirectXColorSpace) consume_Windows_UI_Composition_ICompositionTexture<D>::ColorSpace() const
    {
        llm::OS::Graphics::DirectX::DirectXColorSpace value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTexture)->get_ColorSpace(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionTexture<D>::ColorSpace(llm::OS::Graphics::DirectX::DirectXColorSpace const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionTexture)->put_ColorSpace(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionViewBox<D>::HorizontalAlignmentRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->get_HorizontalAlignmentRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionViewBox<D>::HorizontalAlignmentRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->put_HorizontalAlignmentRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionViewBox<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionViewBox<D>::Offset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionViewBox<D>::Size() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionViewBox<D>::Size(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->put_Size(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionStretch) consume_Windows_UI_Composition_ICompositionViewBox<D>::Stretch() const
    {
        llm::OS::UI::Composition::CompositionStretch value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->get_Stretch(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionViewBox<D>::Stretch(llm::OS::UI::Composition::CompositionStretch const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->put_Stretch(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositionViewBox<D>::VerticalAlignmentRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->get_VerticalAlignmentRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionViewBox<D>::VerticalAlignmentRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionViewBox)->put_VerticalAlignmentRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionVirtualDrawingSurface<D>::Trim(array_view<llm::OS::Graphics::RectInt32 const> rects) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVirtualDrawingSurface)->Trim(rects.size(), get_abi(rects)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_ICompositionVisualSurface<D>::SourceVisual() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVisualSurface)->get_SourceVisual(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionVisualSurface<D>::SourceVisual(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVisualSurface)->put_SourceVisual(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionVisualSurface<D>::SourceOffset() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVisualSurface)->get_SourceOffset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionVisualSurface<D>::SourceOffset(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVisualSurface)->put_SourceOffset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICompositionVisualSurface<D>::SourceSize() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVisualSurface)->get_SourceSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositionVisualSurface<D>::SourceSize(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositionVisualSurface)->put_SourceSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ColorKeyFrameAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateColorKeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateColorKeyFrameAnimation(&result));
        return llm::OS::UI::Composition::ColorKeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorBrush) consume_Windows_UI_Composition_ICompositor<D>::CreateColorBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateColorBrush(&result));
        return llm::OS::UI::Composition::CompositionColorBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorBrush) consume_Windows_UI_Composition_ICompositor<D>::CreateColorBrush(llm::OS::UI::Color const& color) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateColorBrushWithColor(impl::bind_in(color), &result));
        return llm::OS::UI::Composition::CompositionColorBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ContainerVisual) consume_Windows_UI_Composition_ICompositor<D>::CreateContainerVisual() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateContainerVisual(&result));
        return llm::OS::UI::Composition::ContainerVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CubicBezierEasingFunction) consume_Windows_UI_Composition_ICompositor<D>::CreateCubicBezierEasingFunction(llm::OS::Foundation::Numerics::float2 const& controlPoint1, llm::OS::Foundation::Numerics::float2 const& controlPoint2) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateCubicBezierEasingFunction(impl::bind_in(controlPoint1), impl::bind_in(controlPoint2), &result));
        return llm::OS::UI::Composition::CubicBezierEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEffectFactory) consume_Windows_UI_Composition_ICompositor<D>::CreateEffectFactory(llm::OS::Graphics::Effects::IGraphicsEffect const& graphicsEffect) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateEffectFactory(*(void**)(&graphicsEffect), &result));
        return llm::OS::UI::Composition::CompositionEffectFactory{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEffectFactory) consume_Windows_UI_Composition_ICompositor<D>::CreateEffectFactory(llm::OS::Graphics::Effects::IGraphicsEffect const& graphicsEffect, param::iterable<hstring> const& animatableProperties) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateEffectFactoryWithProperties(*(void**)(&graphicsEffect), *(void**)(&animatableProperties), &result));
        return llm::OS::UI::Composition::CompositionEffectFactory{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ExpressionAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateExpressionAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateExpressionAnimation(&result));
        return llm::OS::UI::Composition::ExpressionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ExpressionAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateExpressionAnimation(param::hstring const& expression) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateExpressionAnimationWithExpression(*(void**)(&expression), &result));
        return llm::OS::UI::Composition::ExpressionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::InsetClip) consume_Windows_UI_Composition_ICompositor<D>::CreateInsetClip() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateInsetClip(&result));
        return llm::OS::UI::Composition::InsetClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::InsetClip) consume_Windows_UI_Composition_ICompositor<D>::CreateInsetClip(float leftInset, float topInset, float rightInset, float bottomInset) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateInsetClipWithInsets(leftInset, topInset, rightInset, bottomInset, &result));
        return llm::OS::UI::Composition::InsetClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::LinearEasingFunction) consume_Windows_UI_Composition_ICompositor<D>::CreateLinearEasingFunction() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateLinearEasingFunction(&result));
        return llm::OS::UI::Composition::LinearEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionPropertySet) consume_Windows_UI_Composition_ICompositor<D>::CreatePropertySet() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreatePropertySet(&result));
        return llm::OS::UI::Composition::CompositionPropertySet{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::QuaternionKeyFrameAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateQuaternionKeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateQuaternionKeyFrameAnimation(&result));
        return llm::OS::UI::Composition::QuaternionKeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ScalarKeyFrameAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateScalarKeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateScalarKeyFrameAnimation(&result));
        return llm::OS::UI::Composition::ScalarKeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionScopedBatch) consume_Windows_UI_Composition_ICompositor<D>::CreateScopedBatch(llm::OS::UI::Composition::CompositionBatchTypes const& batchType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateScopedBatch(static_cast<uint32_t>(batchType), &result));
        return llm::OS::UI::Composition::CompositionScopedBatch{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::SpriteVisual) consume_Windows_UI_Composition_ICompositor<D>::CreateSpriteVisual() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateSpriteVisual(&result));
        return llm::OS::UI::Composition::SpriteVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionSurfaceBrush) consume_Windows_UI_Composition_ICompositor<D>::CreateSurfaceBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateSurfaceBrush(&result));
        return llm::OS::UI::Composition::CompositionSurfaceBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionSurfaceBrush) consume_Windows_UI_Composition_ICompositor<D>::CreateSurfaceBrush(llm::OS::UI::Composition::ICompositionSurface const& surface) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateSurfaceBrushWithSurface(*(void**)(&surface), &result));
        return llm::OS::UI::Composition::CompositionSurfaceBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionTarget) consume_Windows_UI_Composition_ICompositor<D>::CreateTargetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateTargetForCurrentView(&result));
        return llm::OS::UI::Composition::CompositionTarget{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Vector2KeyFrameAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateVector2KeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateVector2KeyFrameAnimation(&result));
        return llm::OS::UI::Composition::Vector2KeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Vector3KeyFrameAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateVector3KeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateVector3KeyFrameAnimation(&result));
        return llm::OS::UI::Composition::Vector3KeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Vector4KeyFrameAnimation) consume_Windows_UI_Composition_ICompositor<D>::CreateVector4KeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->CreateVector4KeyFrameAnimation(&result));
        return llm::OS::UI::Composition::Vector4KeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionCommitBatch) consume_Windows_UI_Composition_ICompositor<D>::GetCommitBatch(llm::OS::UI::Composition::CompositionBatchTypes const& batchType) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor)->GetCommitBatch(static_cast<uint32_t>(batchType), &result));
        return llm::OS::UI::Composition::CompositionCommitBatch{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AmbientLight) consume_Windows_UI_Composition_ICompositor2<D>::CreateAmbientLight() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateAmbientLight(&result));
        return llm::OS::UI::Composition::AmbientLight{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionAnimationGroup) consume_Windows_UI_Composition_ICompositor2<D>::CreateAnimationGroup() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateAnimationGroup(&result));
        return llm::OS::UI::Composition::CompositionAnimationGroup{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBackdropBrush) consume_Windows_UI_Composition_ICompositor2<D>::CreateBackdropBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateBackdropBrush(&result));
        return llm::OS::UI::Composition::CompositionBackdropBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::DistantLight) consume_Windows_UI_Composition_ICompositor2<D>::CreateDistantLight() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateDistantLight(&result));
        return llm::OS::UI::Composition::DistantLight{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::DropShadow) consume_Windows_UI_Composition_ICompositor2<D>::CreateDropShadow() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateDropShadow(&result));
        return llm::OS::UI::Composition::DropShadow{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ImplicitAnimationCollection) consume_Windows_UI_Composition_ICompositor2<D>::CreateImplicitAnimationCollection() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateImplicitAnimationCollection(&result));
        return llm::OS::UI::Composition::ImplicitAnimationCollection{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::LayerVisual) consume_Windows_UI_Composition_ICompositor2<D>::CreateLayerVisual() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateLayerVisual(&result));
        return llm::OS::UI::Composition::LayerVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionMaskBrush) consume_Windows_UI_Composition_ICompositor2<D>::CreateMaskBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateMaskBrush(&result));
        return llm::OS::UI::Composition::CompositionMaskBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionNineGridBrush) consume_Windows_UI_Composition_ICompositor2<D>::CreateNineGridBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateNineGridBrush(&result));
        return llm::OS::UI::Composition::CompositionNineGridBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::PointLight) consume_Windows_UI_Composition_ICompositor2<D>::CreatePointLight() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreatePointLight(&result));
        return llm::OS::UI::Composition::PointLight{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::SpotLight) consume_Windows_UI_Composition_ICompositor2<D>::CreateSpotLight() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateSpotLight(&result));
        return llm::OS::UI::Composition::SpotLight{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::StepEasingFunction) consume_Windows_UI_Composition_ICompositor2<D>::CreateStepEasingFunction() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateStepEasingFunction(&result));
        return llm::OS::UI::Composition::StepEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::StepEasingFunction) consume_Windows_UI_Composition_ICompositor2<D>::CreateStepEasingFunction(int32_t stepCount) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor2)->CreateStepEasingFunctionWithStepCount(stepCount, &result));
        return llm::OS::UI::Composition::StepEasingFunction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBackdropBrush) consume_Windows_UI_Composition_ICompositor3<D>::CreateHostBackdropBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor3)->CreateHostBackdropBrush(&result));
        return llm::OS::UI::Composition::CompositionBackdropBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorGradientStop) consume_Windows_UI_Composition_ICompositor4<D>::CreateColorGradientStop() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor4)->CreateColorGradientStop(&result));
        return llm::OS::UI::Composition::CompositionColorGradientStop{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionColorGradientStop) consume_Windows_UI_Composition_ICompositor4<D>::CreateColorGradientStop(float offset, llm::OS::UI::Color const& color) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor4)->CreateColorGradientStopWithOffsetAndColor(offset, impl::bind_in(color), &result));
        return llm::OS::UI::Composition::CompositionColorGradientStop{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionLinearGradientBrush) consume_Windows_UI_Composition_ICompositor4<D>::CreateLinearGradientBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor4)->CreateLinearGradientBrush(&result));
        return llm::OS::UI::Composition::CompositionLinearGradientBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::SpringScalarNaturalMotionAnimation) consume_Windows_UI_Composition_ICompositor4<D>::CreateSpringScalarAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor4)->CreateSpringScalarAnimation(&result));
        return llm::OS::UI::Composition::SpringScalarNaturalMotionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::SpringVector2NaturalMotionAnimation) consume_Windows_UI_Composition_ICompositor4<D>::CreateSpringVector2Animation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor4)->CreateSpringVector2Animation(&result));
        return llm::OS::UI::Composition::SpringVector2NaturalMotionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::SpringVector3NaturalMotionAnimation) consume_Windows_UI_Composition_ICompositor4<D>::CreateSpringVector3Animation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor4)->CreateSpringVector3Animation(&result));
        return llm::OS::UI::Composition::SpringVector3NaturalMotionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Composition_ICompositor5<D>::Comment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->get_Comment(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositor5<D>::Comment(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->put_Comment(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositor5<D>::GlobalPlaybackRate() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->get_GlobalPlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ICompositor5<D>::GlobalPlaybackRate(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->put_GlobalPlaybackRate(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::BounceScalarNaturalMotionAnimation) consume_Windows_UI_Composition_ICompositor5<D>::CreateBounceScalarAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateBounceScalarAnimation(&result));
        return llm::OS::UI::Composition::BounceScalarNaturalMotionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::BounceVector2NaturalMotionAnimation) consume_Windows_UI_Composition_ICompositor5<D>::CreateBounceVector2Animation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateBounceVector2Animation(&result));
        return llm::OS::UI::Composition::BounceVector2NaturalMotionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::BounceVector3NaturalMotionAnimation) consume_Windows_UI_Composition_ICompositor5<D>::CreateBounceVector3Animation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateBounceVector3Animation(&result));
        return llm::OS::UI::Composition::BounceVector3NaturalMotionAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionContainerShape) consume_Windows_UI_Composition_ICompositor5<D>::CreateContainerShape() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateContainerShape(&result));
        return llm::OS::UI::Composition::CompositionContainerShape{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEllipseGeometry) consume_Windows_UI_Composition_ICompositor5<D>::CreateEllipseGeometry() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateEllipseGeometry(&result));
        return llm::OS::UI::Composition::CompositionEllipseGeometry{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionLineGeometry) consume_Windows_UI_Composition_ICompositor5<D>::CreateLineGeometry() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateLineGeometry(&result));
        return llm::OS::UI::Composition::CompositionLineGeometry{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionPathGeometry) consume_Windows_UI_Composition_ICompositor5<D>::CreatePathGeometry() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreatePathGeometry(&result));
        return llm::OS::UI::Composition::CompositionPathGeometry{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionPathGeometry) consume_Windows_UI_Composition_ICompositor5<D>::CreatePathGeometry(llm::OS::UI::Composition::CompositionPath const& path) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreatePathGeometryWithPath(*(void**)(&path), &result));
        return llm::OS::UI::Composition::CompositionPathGeometry{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::PathKeyFrameAnimation) consume_Windows_UI_Composition_ICompositor5<D>::CreatePathKeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreatePathKeyFrameAnimation(&result));
        return llm::OS::UI::Composition::PathKeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionRectangleGeometry) consume_Windows_UI_Composition_ICompositor5<D>::CreateRectangleGeometry() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateRectangleGeometry(&result));
        return llm::OS::UI::Composition::CompositionRectangleGeometry{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionRoundedRectangleGeometry) consume_Windows_UI_Composition_ICompositor5<D>::CreateRoundedRectangleGeometry() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateRoundedRectangleGeometry(&result));
        return llm::OS::UI::Composition::CompositionRoundedRectangleGeometry{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ShapeVisual) consume_Windows_UI_Composition_ICompositor5<D>::CreateShapeVisual() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateShapeVisual(&result));
        return llm::OS::UI::Composition::ShapeVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionSpriteShape) consume_Windows_UI_Composition_ICompositor5<D>::CreateSpriteShape() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateSpriteShape(&result));
        return llm::OS::UI::Composition::CompositionSpriteShape{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionSpriteShape) consume_Windows_UI_Composition_ICompositor5<D>::CreateSpriteShape(llm::OS::UI::Composition::CompositionGeometry const& geometry) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateSpriteShapeWithGeometry(*(void**)(&geometry), &result));
        return llm::OS::UI::Composition::CompositionSpriteShape{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionViewBox) consume_Windows_UI_Composition_ICompositor5<D>::CreateViewBox() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->CreateViewBox(&result));
        return llm::OS::UI::Composition::CompositionViewBox{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_Composition_ICompositor5<D>::RequestCommitAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor5)->RequestCommitAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGeometricClip) consume_Windows_UI_Composition_ICompositor6<D>::CreateGeometricClip() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor6)->CreateGeometricClip(&result));
        return llm::OS::UI::Composition::CompositionGeometricClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGeometricClip) consume_Windows_UI_Composition_ICompositor6<D>::CreateGeometricClip(llm::OS::UI::Composition::CompositionGeometry const& geometry) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor6)->CreateGeometricClipWithGeometry(*(void**)(&geometry), &result));
        return llm::OS::UI::Composition::CompositionGeometricClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::RedirectVisual) consume_Windows_UI_Composition_ICompositor6<D>::CreateRedirectVisual() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor6)->CreateRedirectVisual(&result));
        return llm::OS::UI::Composition::RedirectVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::RedirectVisual) consume_Windows_UI_Composition_ICompositor6<D>::CreateRedirectVisual(llm::OS::UI::Composition::Visual const& source) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor6)->CreateRedirectVisualWithSourceVisual(*(void**)(&source), &result));
        return llm::OS::UI::Composition::RedirectVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::BooleanKeyFrameAnimation) consume_Windows_UI_Composition_ICompositor6<D>::CreateBooleanKeyFrameAnimation() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor6)->CreateBooleanKeyFrameAnimation(&result));
        return llm::OS::UI::Composition::BooleanKeyFrameAnimation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_UI_Composition_ICompositor7<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor7)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationPropertyInfo) consume_Windows_UI_Composition_ICompositor7<D>::CreateAnimationPropertyInfo() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor7)->CreateAnimationPropertyInfo(&result));
        return llm::OS::UI::Composition::AnimationPropertyInfo{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::RectangleClip) consume_Windows_UI_Composition_ICompositor7<D>::CreateRectangleClip() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor7)->CreateRectangleClip(&result));
        return llm::OS::UI::Composition::RectangleClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::RectangleClip) consume_Windows_UI_Composition_ICompositor7<D>::CreateRectangleClip(float left, float top, float right, float bottom) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor7)->CreateRectangleClipWithSides(left, top, right, bottom, &result));
        return llm::OS::UI::Composition::RectangleClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::RectangleClip) consume_Windows_UI_Composition_ICompositor7<D>::CreateRectangleClip(float left, float top, float right, float bottom, llm::OS::Foundation::Numerics::float2 const& topLeftRadius, llm::OS::Foundation::Numerics::float2 const& topRightRadius, llm::OS::Foundation::Numerics::float2 const& bottomRightRadius, llm::OS::Foundation::Numerics::float2 const& bottomLeftRadius) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor7)->CreateRectangleClipWithSidesAndRadius(left, top, right, bottom, impl::bind_in(topLeftRadius), impl::bind_in(topRightRadius), impl::bind_in(bottomRightRadius), impl::bind_in(bottomLeftRadius), &result));
        return llm::OS::UI::Composition::RectangleClip{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationController) consume_Windows_UI_Composition_ICompositor8<D>::CreateAnimationController() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositor8)->CreateAnimationController(&result));
        return llm::OS::UI::Composition::AnimationController{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositorStatics<D>::MaxGlobalPlaybackRate() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorStatics)->get_MaxGlobalPlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ICompositorStatics<D>::MinGlobalPlaybackRate() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorStatics)->get_MinGlobalPlaybackRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBackdropBrush) consume_Windows_UI_Composition_ICompositorWithBlurredWallpaperBackdropBrush<D>::TryCreateBlurredWallpaperBackdropBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush)->TryCreateBlurredWallpaperBackdropBrush(&result));
        return llm::OS::UI::Composition::CompositionBackdropBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionProjectedShadowCaster) consume_Windows_UI_Composition_ICompositorWithProjectedShadow<D>::CreateProjectedShadowCaster() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorWithProjectedShadow)->CreateProjectedShadowCaster(&result));
        return llm::OS::UI::Composition::CompositionProjectedShadowCaster{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionProjectedShadow) consume_Windows_UI_Composition_ICompositorWithProjectedShadow<D>::CreateProjectedShadow() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorWithProjectedShadow)->CreateProjectedShadow(&result));
        return llm::OS::UI::Composition::CompositionProjectedShadow{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionProjectedShadowReceiver) consume_Windows_UI_Composition_ICompositorWithProjectedShadow<D>::CreateProjectedShadowReceiver() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorWithProjectedShadow)->CreateProjectedShadowReceiver(&result));
        return llm::OS::UI::Composition::CompositionProjectedShadowReceiver{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionRadialGradientBrush) consume_Windows_UI_Composition_ICompositorWithRadialGradient<D>::CreateRadialGradientBrush() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorWithRadialGradient)->CreateRadialGradientBrush(&result));
        return llm::OS::UI::Composition::CompositionRadialGradientBrush{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionVisualSurface) consume_Windows_UI_Composition_ICompositorWithVisualSurface<D>::CreateVisualSurface() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICompositorWithVisualSurface)->CreateVisualSurface(&result));
        return llm::OS::UI::Composition::CompositionVisualSurface{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::VisualCollection) consume_Windows_UI_Composition_IContainerVisual<D>::Children() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IContainerVisual)->get_Children(&value));
        return llm::OS::UI::Composition::VisualCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICubicBezierEasingFunction<D>::ControlPoint1() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICubicBezierEasingFunction)->get_ControlPoint1(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_ICubicBezierEasingFunction<D>::ControlPoint2() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ICubicBezierEasingFunction)->get_ControlPoint2(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Composition_IDelegatedInkTrailVisual<D>::AddTrailPoints(array_view<llm::OS::UI::Composition::InkTrailPoint const> inkPoints) const
    {
        uint32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDelegatedInkTrailVisual)->AddTrailPoints(inkPoints.size(), get_abi(inkPoints), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Composition_IDelegatedInkTrailVisual<D>::AddTrailPointsWithPrediction(array_view<llm::OS::UI::Composition::InkTrailPoint const> inkPoints, array_view<llm::OS::UI::Composition::InkTrailPoint const> predictedInkPoints) const
    {
        uint32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDelegatedInkTrailVisual)->AddTrailPointsWithPrediction(inkPoints.size(), get_abi(inkPoints), predictedInkPoints.size(), get_abi(predictedInkPoints), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDelegatedInkTrailVisual<D>::RemoveTrailPoints(uint32_t generationId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDelegatedInkTrailVisual)->RemoveTrailPoints(generationId));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDelegatedInkTrailVisual<D>::StartNewTrail(llm::OS::UI::Color const& color) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDelegatedInkTrailVisual)->StartNewTrail(impl::bind_in(color)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::DelegatedInkTrailVisual) consume_Windows_UI_Composition_IDelegatedInkTrailVisualStatics<D>::Create(llm::OS::UI::Composition::Compositor const& compositor) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDelegatedInkTrailVisualStatics)->Create(*(void**)(&compositor), &result));
        return llm::OS::UI::Composition::DelegatedInkTrailVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::DelegatedInkTrailVisual) consume_Windows_UI_Composition_IDelegatedInkTrailVisualStatics<D>::CreateForSwapChain(llm::OS::UI::Composition::Compositor const& compositor, llm::OS::UI::Composition::ICompositionSurface const& swapChain) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDelegatedInkTrailVisualStatics)->CreateForSwapChain(*(void**)(&compositor), *(void**)(&swapChain), &result));
        return llm::OS::UI::Composition::DelegatedInkTrailVisual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_IDistantLight<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDistantLight<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_IDistantLight<D>::CoordinateSpace() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight)->get_CoordinateSpace(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDistantLight<D>::CoordinateSpace(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight)->put_CoordinateSpace(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IDistantLight<D>::Direction() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight)->get_Direction(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDistantLight<D>::Direction(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight)->put_Direction(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IDistantLight2<D>::Intensity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight2)->get_Intensity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDistantLight2<D>::Intensity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDistantLight2)->put_Intensity(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IDropShadow<D>::BlurRadius() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->get_BlurRadius(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDropShadow<D>::BlurRadius(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->put_BlurRadius(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_IDropShadow<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDropShadow<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_IDropShadow<D>::Mask() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->get_Mask(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDropShadow<D>::Mask(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->put_Mask(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IDropShadow<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDropShadow<D>::Offset(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IDropShadow<D>::Opacity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->get_Opacity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDropShadow<D>::Opacity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow)->put_Opacity(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionDropShadowSourcePolicy) consume_Windows_UI_Composition_IDropShadow2<D>::SourcePolicy() const
    {
        llm::OS::UI::Composition::CompositionDropShadowSourcePolicy value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow2)->get_SourcePolicy(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IDropShadow2<D>::SourcePolicy(llm::OS::UI::Composition::CompositionDropShadowSourcePolicy const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IDropShadow2)->put_SourcePolicy(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_IElasticEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IElasticEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IElasticEasingFunction<D>::Oscillations() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IElasticEasingFunction)->get_Oscillations(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IElasticEasingFunction<D>::Springiness() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IElasticEasingFunction)->get_Springiness(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_IExponentialEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IExponentialEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IExponentialEasingFunction<D>::Exponent() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IExponentialEasingFunction)->get_Exponent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Composition_IExpressionAnimation<D>::Expression() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IExpressionAnimation)->get_Expression(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IExpressionAnimation<D>::Expression(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IExpressionAnimation)->put_Expression(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IInsetClip<D>::BottomInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->get_BottomInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IInsetClip<D>::BottomInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->put_BottomInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IInsetClip<D>::LeftInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->get_LeftInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IInsetClip<D>::LeftInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->put_LeftInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IInsetClip<D>::RightInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->get_RightInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IInsetClip<D>::RightInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->put_RightInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IInsetClip<D>::TopInset() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->get_TopInset(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IInsetClip<D>::TopInset(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IInsetClip)->put_TopInset(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::DelayTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->get_DelayTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::DelayTime(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->put_DelayTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::Duration(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->put_Duration(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationIterationBehavior) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::IterationBehavior() const
    {
        llm::OS::UI::Composition::AnimationIterationBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->get_IterationBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::IterationBehavior(llm::OS::UI::Composition::AnimationIterationBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->put_IterationBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::IterationCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->get_IterationCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::IterationCount(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->put_IterationCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::KeyFrameCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->get_KeyFrameCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationStopBehavior) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::StopBehavior() const
    {
        llm::OS::UI::Composition::AnimationStopBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->get_StopBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::StopBehavior(llm::OS::UI::Composition::AnimationStopBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->put_StopBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::InsertExpressionKeyFrame(float normalizedProgressKey, param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->InsertExpressionKeyFrame(normalizedProgressKey, *(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation<D>::InsertExpressionKeyFrame(float normalizedProgressKey, param::hstring const& value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation)->InsertExpressionKeyFrameWithEasingFunction(normalizedProgressKey, *(void**)(&value), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationDirection) consume_Windows_UI_Composition_IKeyFrameAnimation2<D>::Direction() const
    {
        llm::OS::UI::Composition::AnimationDirection value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation2)->get_Direction(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation2<D>::Direction(llm::OS::UI::Composition::AnimationDirection const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation2)->put_Direction(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationDelayBehavior) consume_Windows_UI_Composition_IKeyFrameAnimation3<D>::DelayBehavior() const
    {
        llm::OS::UI::Composition::AnimationDelayBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation3)->get_DelayBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IKeyFrameAnimation3<D>::DelayBehavior(llm::OS::UI::Composition::AnimationDelayBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IKeyFrameAnimation3)->put_DelayBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEffectBrush) consume_Windows_UI_Composition_ILayerVisual<D>::Effect() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ILayerVisual)->get_Effect(&value));
        return llm::OS::UI::Composition::CompositionEffectBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ILayerVisual<D>::Effect(llm::OS::UI::Composition::CompositionEffectBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ILayerVisual)->put_Effect(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionShadow) consume_Windows_UI_Composition_ILayerVisual2<D>::Shadow() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ILayerVisual2)->get_Shadow(&value));
        return llm::OS::UI::Composition::CompositionShadow{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ILayerVisual2<D>::Shadow(llm::OS::UI::Composition::CompositionShadow const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ILayerVisual2)->put_Shadow(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationDelayBehavior) consume_Windows_UI_Composition_INaturalMotionAnimation<D>::DelayBehavior() const
    {
        llm::OS::UI::Composition::AnimationDelayBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::INaturalMotionAnimation)->get_DelayBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_INaturalMotionAnimation<D>::DelayBehavior(llm::OS::UI::Composition::AnimationDelayBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::INaturalMotionAnimation)->put_DelayBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Composition_INaturalMotionAnimation<D>::DelayTime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::INaturalMotionAnimation)->get_DelayTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_INaturalMotionAnimation<D>::DelayTime(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::INaturalMotionAnimation)->put_DelayTime(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::AnimationStopBehavior) consume_Windows_UI_Composition_INaturalMotionAnimation<D>::StopBehavior() const
    {
        llm::OS::UI::Composition::AnimationStopBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::INaturalMotionAnimation)->get_StopBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_INaturalMotionAnimation<D>::StopBehavior(llm::OS::UI::Composition::AnimationStopBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::INaturalMotionAnimation)->put_StopBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPathKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::UI::Composition::CompositionPath const& path) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPathKeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, *(void**)(&path)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPathKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::UI::Composition::CompositionPath const& path, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPathKeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, *(void**)(&path), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_IPointLight<D>::Color() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->get_Color(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight<D>::Color(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->put_Color(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPointLight<D>::ConstantAttenuation() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->get_ConstantAttenuation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight<D>::ConstantAttenuation(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->put_ConstantAttenuation(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_IPointLight<D>::CoordinateSpace() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->get_CoordinateSpace(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight<D>::CoordinateSpace(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->put_CoordinateSpace(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPointLight<D>::LinearAttenuation() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->get_LinearAttenuation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight<D>::LinearAttenuation(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->put_LinearAttenuation(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IPointLight<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight<D>::Offset(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPointLight<D>::QuadraticAttenuation() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->get_QuadraticAttenuation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight<D>::QuadraticAttenuation(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight)->put_QuadraticAttenuation(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPointLight2<D>::Intensity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight2)->get_Intensity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight2<D>::Intensity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight2)->put_Intensity(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPointLight3<D>::MinAttenuationCutoff() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight3)->get_MinAttenuationCutoff(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight3<D>::MinAttenuationCutoff(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight3)->put_MinAttenuationCutoff(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPointLight3<D>::MaxAttenuationCutoff() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight3)->get_MaxAttenuationCutoff(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IPointLight3<D>::MaxAttenuationCutoff(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPointLight3)->put_MaxAttenuationCutoff(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_IPowerEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPowerEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IPowerEasingFunction<D>::Power() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IPowerEasingFunction)->get_Power(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IQuaternionKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IQuaternionKeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IQuaternionKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::quaternion const& value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IQuaternionKeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, impl::bind_in(value), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IRectangleClip<D>::Bottom() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_Bottom(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::Bottom(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_Bottom(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IRectangleClip<D>::BottomLeftRadius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_BottomLeftRadius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::BottomLeftRadius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_BottomLeftRadius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IRectangleClip<D>::BottomRightRadius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_BottomRightRadius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::BottomRightRadius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_BottomRightRadius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IRectangleClip<D>::Left() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_Left(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::Left(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_Left(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IRectangleClip<D>::Right() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_Right(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::Right(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_Right(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IRectangleClip<D>::Top() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_Top(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::Top(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_Top(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IRectangleClip<D>::TopLeftRadius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_TopLeftRadius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::TopLeftRadius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_TopLeftRadius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IRectangleClip<D>::TopRightRadius() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->get_TopRightRadius(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRectangleClip<D>::TopRightRadius(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRectangleClip)->put_TopRightRadius(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_IRedirectVisual<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRedirectVisual)->get_Source(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IRedirectVisual<D>::Source(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRedirectVisual)->put_Source(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionGraphicsDevice) consume_Windows_UI_Composition_IRenderingDeviceReplacedEventArgs<D>::GraphicsDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IRenderingDeviceReplacedEventArgs)->get_GraphicsDevice(&value));
        return llm::OS::UI::Composition::CompositionGraphicsDevice{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IScalarKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarKeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IScalarKeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, float value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarKeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, value, *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<float>) consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>::FinalValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarNaturalMotionAnimation)->get_FinalValue(&value));
        return llm::OS::Foundation::IReference<float>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>::FinalValue(llm::OS::Foundation::IReference<float> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarNaturalMotionAnimation)->put_FinalValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<float>) consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>::InitialValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarNaturalMotionAnimation)->get_InitialValue(&value));
        return llm::OS::Foundation::IReference<float>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>::InitialValue(llm::OS::Foundation::IReference<float> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarNaturalMotionAnimation)->put_InitialValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>::InitialVelocity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarNaturalMotionAnimation)->get_InitialVelocity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IScalarNaturalMotionAnimation<D>::InitialVelocity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IScalarNaturalMotionAnimation)->put_InitialVelocity(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionShapeCollection) consume_Windows_UI_Composition_IShapeVisual<D>::Shapes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IShapeVisual)->get_Shapes(&value));
        return llm::OS::UI::Composition::CompositionShapeCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionViewBox) consume_Windows_UI_Composition_IShapeVisual<D>::ViewBox() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IShapeVisual)->get_ViewBox(&value));
        return llm::OS::UI::Composition::CompositionViewBox{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IShapeVisual<D>::ViewBox(llm::OS::UI::Composition::CompositionViewBox const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IShapeVisual)->put_ViewBox(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionEasingFunctionMode) consume_Windows_UI_Composition_ISineEasingFunction<D>::Mode() const
    {
        llm::OS::UI::Composition::CompositionEasingFunctionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISineEasingFunction)->get_Mode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::ConstantAttenuation() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_ConstantAttenuation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::ConstantAttenuation(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_ConstantAttenuation(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_ISpotLight<D>::CoordinateSpace() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_CoordinateSpace(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::CoordinateSpace(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_CoordinateSpace(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_ISpotLight<D>::Direction() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_Direction(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::Direction(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_Direction(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::InnerConeAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_InnerConeAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::InnerConeAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_InnerConeAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::InnerConeAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_InnerConeAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::InnerConeAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_InnerConeAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_ISpotLight<D>::InnerConeColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_InnerConeColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::InnerConeColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_InnerConeColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::LinearAttenuation() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_LinearAttenuation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::LinearAttenuation(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_LinearAttenuation(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_ISpotLight<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::Offset(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::OuterConeAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_OuterConeAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::OuterConeAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_OuterConeAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::OuterConeAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_OuterConeAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::OuterConeAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_OuterConeAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_Composition_ISpotLight<D>::OuterConeColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_OuterConeColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::OuterConeColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_OuterConeColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight<D>::QuadraticAttenuation() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->get_QuadraticAttenuation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight<D>::QuadraticAttenuation(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight)->put_QuadraticAttenuation(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight2<D>::InnerConeIntensity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight2)->get_InnerConeIntensity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight2<D>::InnerConeIntensity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight2)->put_InnerConeIntensity(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight2<D>::OuterConeIntensity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight2)->get_OuterConeIntensity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight2<D>::OuterConeIntensity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight2)->put_OuterConeIntensity(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight3<D>::MinAttenuationCutoff() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight3)->get_MinAttenuationCutoff(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight3<D>::MinAttenuationCutoff(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight3)->put_MinAttenuationCutoff(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpotLight3<D>::MaxAttenuationCutoff() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight3)->get_MaxAttenuationCutoff(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpotLight3<D>::MaxAttenuationCutoff(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpotLight3)->put_MaxAttenuationCutoff(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpringScalarNaturalMotionAnimation<D>::DampingRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation)->get_DampingRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpringScalarNaturalMotionAnimation<D>::DampingRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation)->put_DampingRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Composition_ISpringScalarNaturalMotionAnimation<D>::Period() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation)->get_Period(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpringScalarNaturalMotionAnimation<D>::Period(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation)->put_Period(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpringVector2NaturalMotionAnimation<D>::DampingRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation)->get_DampingRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpringVector2NaturalMotionAnimation<D>::DampingRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation)->put_DampingRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Composition_ISpringVector2NaturalMotionAnimation<D>::Period() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation)->get_Period(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpringVector2NaturalMotionAnimation<D>::Period(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation)->put_Period(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_ISpringVector3NaturalMotionAnimation<D>::DampingRatio() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation)->get_DampingRatio(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpringVector3NaturalMotionAnimation<D>::DampingRatio(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation)->put_DampingRatio(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_Composition_ISpringVector3NaturalMotionAnimation<D>::Period() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation)->get_Period(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpringVector3NaturalMotionAnimation<D>::Period(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation)->put_Period(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBrush) consume_Windows_UI_Composition_ISpriteVisual<D>::Brush() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpriteVisual)->get_Brush(&value));
        return llm::OS::UI::Composition::CompositionBrush{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpriteVisual<D>::Brush(llm::OS::UI::Composition::CompositionBrush const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpriteVisual)->put_Brush(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionShadow) consume_Windows_UI_Composition_ISpriteVisual2<D>::Shadow() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpriteVisual2)->get_Shadow(&value));
        return llm::OS::UI::Composition::CompositionShadow{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_ISpriteVisual2<D>::Shadow(llm::OS::UI::Composition::CompositionShadow const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::ISpriteVisual2)->put_Shadow(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IStepEasingFunction<D>::FinalStep() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->get_FinalStep(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IStepEasingFunction<D>::FinalStep(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->put_FinalStep(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IStepEasingFunction<D>::InitialStep() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->get_InitialStep(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IStepEasingFunction<D>::InitialStep(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->put_InitialStep(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_IStepEasingFunction<D>::IsFinalStepSingleFrame() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->get_IsFinalStepSingleFrame(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IStepEasingFunction<D>::IsFinalStepSingleFrame(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->put_IsFinalStepSingleFrame(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_IStepEasingFunction<D>::IsInitialStepSingleFrame() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->get_IsInitialStepSingleFrame(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IStepEasingFunction<D>::IsInitialStepSingleFrame(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->put_IsInitialStepSingleFrame(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IStepEasingFunction<D>::StepCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->get_StepCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IStepEasingFunction<D>::StepCount(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IStepEasingFunction)->put_StepCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector2KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2KeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector2KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float2 const& value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2KeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, impl::bind_in(value), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2>) consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>::FinalValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2NaturalMotionAnimation)->get_FinalValue(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>::FinalValue(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2NaturalMotionAnimation)->put_FinalValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2>) consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>::InitialValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2NaturalMotionAnimation)->get_InitialValue(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>::InitialValue(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2NaturalMotionAnimation)->put_InitialValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>::InitialVelocity() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2NaturalMotionAnimation)->get_InitialVelocity(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector2NaturalMotionAnimation<D>::InitialVelocity(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector2NaturalMotionAnimation)->put_InitialVelocity(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector3KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3KeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector3KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float3 const& value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3KeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, impl::bind_in(value), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3>) consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>::FinalValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3NaturalMotionAnimation)->get_FinalValue(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>::FinalValue(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3NaturalMotionAnimation)->put_FinalValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3>) consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>::InitialValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3NaturalMotionAnimation)->get_InitialValue(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>::InitialValue(llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3NaturalMotionAnimation)->put_InitialValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>::InitialVelocity() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3NaturalMotionAnimation)->get_InitialVelocity(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector3NaturalMotionAnimation<D>::InitialVelocity(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector3NaturalMotionAnimation)->put_InitialVelocity(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector4KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector4KeyFrameAnimation)->InsertKeyFrame(normalizedProgressKey, impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVector4KeyFrameAnimation<D>::InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float4 const& value, llm::OS::UI::Composition::CompositionEasingFunction const& easingFunction) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVector4KeyFrameAnimation)->InsertKeyFrameWithEasingFunction(normalizedProgressKey, impl::bind_in(value), *(void**)(&easingFunction)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IVisual<D>::AnchorPoint() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_AnchorPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::AnchorPoint(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_AnchorPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBackfaceVisibility) consume_Windows_UI_Composition_IVisual<D>::BackfaceVisibility() const
    {
        llm::OS::UI::Composition::CompositionBackfaceVisibility value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_BackfaceVisibility(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::BackfaceVisibility(llm::OS::UI::Composition::CompositionBackfaceVisibility const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_BackfaceVisibility(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionBorderMode) consume_Windows_UI_Composition_IVisual<D>::BorderMode() const
    {
        llm::OS::UI::Composition::CompositionBorderMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_BorderMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::BorderMode(llm::OS::UI::Composition::CompositionBorderMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_BorderMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IVisual<D>::CenterPoint() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_CenterPoint(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::CenterPoint(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_CenterPoint(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionClip) consume_Windows_UI_Composition_IVisual<D>::Clip() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Clip(&value));
        return llm::OS::UI::Composition::CompositionClip{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::Clip(llm::OS::UI::Composition::CompositionClip const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_Clip(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::CompositionCompositeMode) consume_Windows_UI_Composition_IVisual<D>::CompositeMode() const
    {
        llm::OS::UI::Composition::CompositionCompositeMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_CompositeMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::CompositeMode(llm::OS::UI::Composition::CompositionCompositeMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_CompositeMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_IVisual<D>::IsVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_IsVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::IsVisible(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_IsVisible(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IVisual<D>::Offset() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::Offset(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_Offset(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IVisual<D>::Opacity() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Opacity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::Opacity(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_Opacity(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::quaternion) consume_Windows_UI_Composition_IVisual<D>::Orientation() const
    {
        llm::OS::Foundation::Numerics::quaternion value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Orientation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::Orientation(llm::OS::Foundation::Numerics::quaternion const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_Orientation(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ContainerVisual) consume_Windows_UI_Composition_IVisual<D>::Parent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Parent(&value));
        return llm::OS::UI::Composition::ContainerVisual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IVisual<D>::RotationAngle() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_RotationAngle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::RotationAngle(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_RotationAngle(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_Composition_IVisual<D>::RotationAngleInDegrees() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_RotationAngleInDegrees(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::RotationAngleInDegrees(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_RotationAngleInDegrees(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IVisual<D>::RotationAxis() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_RotationAxis(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::RotationAxis(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_RotationAxis(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IVisual<D>::Scale() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Scale(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::Scale(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_Scale(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IVisual<D>::Size() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::Size(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_Size(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float4x4) consume_Windows_UI_Composition_IVisual<D>::TransformMatrix() const
    {
        llm::OS::Foundation::Numerics::float4x4 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->get_TransformMatrix(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual<D>::TransformMatrix(llm::OS::Foundation::Numerics::float4x4 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual)->put_TransformMatrix(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_IVisual2<D>::ParentForTransform() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual2)->get_ParentForTransform(&value));
        return llm::OS::UI::Composition::Visual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual2<D>::ParentForTransform(llm::OS::UI::Composition::Visual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual2)->put_ParentForTransform(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3) consume_Windows_UI_Composition_IVisual2<D>::RelativeOffsetAdjustment() const
    {
        llm::OS::Foundation::Numerics::float3 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual2)->get_RelativeOffsetAdjustment(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual2<D>::RelativeOffsetAdjustment(llm::OS::Foundation::Numerics::float3 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual2)->put_RelativeOffsetAdjustment(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float2) consume_Windows_UI_Composition_IVisual2<D>::RelativeSizeAdjustment() const
    {
        llm::OS::Foundation::Numerics::float2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual2)->get_RelativeSizeAdjustment(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual2<D>::RelativeSizeAdjustment(llm::OS::Foundation::Numerics::float2 const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual2)->put_RelativeSizeAdjustment(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_IVisual3<D>::IsHitTestVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual3)->get_IsHitTestVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual3<D>::IsHitTestVisible(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual3)->put_IsHitTestVisible(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Composition_IVisual4<D>::IsPixelSnappingEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual4)->get_IsPixelSnappingEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisual4<D>::IsPixelSnappingEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisual4)->put_IsPixelSnappingEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IVisualCollection<D>::Count() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->get_Count(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualCollection<D>::InsertAbove(llm::OS::UI::Composition::Visual const& newChild, llm::OS::UI::Composition::Visual const& sibling) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->InsertAbove(*(void**)(&newChild), *(void**)(&sibling)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualCollection<D>::InsertAtBottom(llm::OS::UI::Composition::Visual const& newChild) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->InsertAtBottom(*(void**)(&newChild)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualCollection<D>::InsertAtTop(llm::OS::UI::Composition::Visual const& newChild) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->InsertAtTop(*(void**)(&newChild)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualCollection<D>::InsertBelow(llm::OS::UI::Composition::Visual const& newChild, llm::OS::UI::Composition::Visual const& sibling) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->InsertBelow(*(void**)(&newChild), *(void**)(&sibling)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualCollection<D>::Remove(llm::OS::UI::Composition::Visual const& child) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->Remove(*(void**)(&child)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualCollection<D>::RemoveAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualCollection)->RemoveAll());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::Visual) consume_Windows_UI_Composition_IVisualElement2<D>::GetVisualInternal() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualElement2)->GetVisualInternal(&result));
        return llm::OS::UI::Composition::Visual{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Composition_IVisualUnorderedCollection<D>::Count() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualUnorderedCollection)->get_Count(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualUnorderedCollection<D>::Add(llm::OS::UI::Composition::Visual const& newVisual) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualUnorderedCollection)->Add(*(void**)(&newVisual)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualUnorderedCollection<D>::Remove(llm::OS::UI::Composition::Visual const& visual) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualUnorderedCollection)->Remove(*(void**)(&visual)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Composition_IVisualUnorderedCollection<D>::RemoveAll() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Composition::IVisualUnorderedCollection)->RemoveAll());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAmbientLight> : produce_base<D, llm::OS::UI::Composition::IAmbientLight>
    {
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAmbientLight2> : produce_base<D, llm::OS::UI::Composition::IAmbientLight2>
    {
        int32_t __stdcall get_Intensity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Intensity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Intensity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Intensity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAnimationController> : produce_base<D, llm::OS::UI::Composition::IAnimationController>
    {
        int32_t __stdcall get_PlaybackRate(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().PlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PlaybackRate(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaybackRate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Progress(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Progress(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProgressBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationControllerProgressBehavior>(this->shim().ProgressBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProgressBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProgressBehavior(*reinterpret_cast<llm::OS::UI::Composition::AnimationControllerProgressBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Pause() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Pause();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Resume() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAnimationControllerStatics> : produce_base<D, llm::OS::UI::Composition::IAnimationControllerStatics>
    {
        int32_t __stdcall get_MaxPlaybackRate(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxPlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinPlaybackRate(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinPlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAnimationObject> : produce_base<D, llm::OS::UI::Composition::IAnimationObject>
    {
        int32_t __stdcall PopulatePropertyInfo(void* propertyName, void* propertyInfo) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PopulatePropertyInfo(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::UI::Composition::AnimationPropertyInfo const*>(&propertyInfo));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAnimationPropertyInfo> : produce_base<D, llm::OS::UI::Composition::IAnimationPropertyInfo>
    {
        int32_t __stdcall get_AccessMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationPropertyAccessMode>(this->shim().AccessMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AccessMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessMode(*reinterpret_cast<llm::OS::UI::Composition::AnimationPropertyAccessMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IAnimationPropertyInfo2> : produce_base<D, llm::OS::UI::Composition::IAnimationPropertyInfo2>
    {
        int32_t __stdcall GetResolvedCompositionObject(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionObject>(this->shim().GetResolvedCompositionObject());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetResolvedCompositionObjectProperty(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetResolvedCompositionObjectProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IBackEasingFunction> : produce_base<D, llm::OS::UI::Composition::IBackEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Amplitude(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Amplitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IBooleanKeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IBooleanKeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IBounceEasingFunction> : produce_base<D, llm::OS::UI::Composition::IBounceEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bounces(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Bounces());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bounciness(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Bounciness());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation>
    {
        int32_t __stdcall get_Acceleration(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Acceleration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Acceleration(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Acceleration(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Restitution(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Restitution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Restitution(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restitution(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation>
    {
        int32_t __stdcall get_Acceleration(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Acceleration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Acceleration(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Acceleration(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Restitution(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Restitution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Restitution(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restitution(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation>
    {
        int32_t __stdcall get_Acceleration(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Acceleration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Acceleration(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Acceleration(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Restitution(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Restitution());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Restitution(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Restitution(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICircleEasingFunction> : produce_base<D, llm::OS::UI::Composition::ICircleEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IColorKeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IColorKeyFrameAnimation>
    {
        int32_t __stdcall get_InterpolationColorSpace(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionColorSpace>(this->shim().InterpolationColorSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InterpolationColorSpace(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InterpolationColorSpace(*reinterpret_cast<llm::OS::UI::Composition::CompositionColorSpace const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, struct struct_Windows_UI_Color value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::UI::Color const*>(&value), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimation> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimation>
    {
        int32_t __stdcall ClearAllParameters() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAllParameters();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearParameter(void* key) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearParameter(*reinterpret_cast<hstring const*>(&key));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetColorParameter(void* key, struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetColorParameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetMatrix3x2Parameter(void* key, llm::OS::Foundation::Numerics::float3x2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMatrix3x2Parameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetMatrix4x4Parameter(void* key, llm::OS::Foundation::Numerics::float4x4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMatrix4x4Parameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::Foundation::Numerics::float4x4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetQuaternionParameter(void* key, llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetQuaternionParameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetReferenceParameter(void* key, void* compositionObject) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetReferenceParameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::UI::Composition::CompositionObject const*>(&compositionObject));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetScalarParameter(void* key, float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetScalarParameter(*reinterpret_cast<hstring const*>(&key), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetVector2Parameter(void* key, llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVector2Parameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetVector3Parameter(void* key, llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVector3Parameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetVector4Parameter(void* key, llm::OS::Foundation::Numerics::float4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetVector4Parameter(*reinterpret_cast<hstring const*>(&key), *reinterpret_cast<llm::OS::Foundation::Numerics::float4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimation2> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimation2>
    {
        int32_t __stdcall SetBooleanParameter(void* key, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetBooleanParameter(*reinterpret_cast<hstring const*>(&key), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Target(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Target());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Target(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Target(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimation3> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimation3>
    {
        int32_t __stdcall get_InitialValueExpressions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::InitialValueExpressionCollection>(this->shim().InitialValueExpressions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimation4> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimation4>
    {
        int32_t __stdcall SetExpressionReferenceParameter(void* parameterName, void* source) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetExpressionReferenceParameter(*reinterpret_cast<hstring const*>(&parameterName), *reinterpret_cast<llm::OS::UI::Composition::IAnimationObject const*>(&source));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimationBase> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimationBase>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimationFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionAnimationGroup> : produce_base<D, llm::OS::UI::Composition::ICompositionAnimationGroup>
    {
        int32_t __stdcall get_Count(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Count());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Add(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::UI::Composition::CompositionAnimation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<llm::OS::UI::Composition::CompositionAnimation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionBackdropBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionBackdropBrush>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionBatchCompletedEventArgs> : produce_base<D, llm::OS::UI::Composition::ICompositionBatchCompletedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionBrush>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionBrushFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionBrushFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionCapabilities> : produce_base<D, llm::OS::UI::Composition::ICompositionCapabilities>
    {
        int32_t __stdcall AreEffectsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().AreEffectsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AreEffectsFast(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().AreEffectsFast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Changed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Changed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::CompositionCapabilities, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Changed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Changed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionCapabilitiesStatics> : produce_base<D, llm::OS::UI::Composition::ICompositionCapabilitiesStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionCapabilities>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionClip> : produce_base<D, llm::OS::UI::Composition::ICompositionClip>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionClip2> : produce_base<D, llm::OS::UI::Composition::ICompositionClip2>
    {
        int32_t __stdcall get_AnchorPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().AnchorPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AnchorPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CenterPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().CenterPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CenterPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Scale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransformMatrix(llm::OS::Foundation::Numerics::float3x2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3x2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3x2>(this->shim().TransformMatrix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransformMatrix(llm::OS::Foundation::Numerics::float3x2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionClipFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionClipFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionColorBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionColorBrush>
    {
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionColorGradientStop> : produce_base<D, llm::OS::UI::Composition::ICompositionColorGradientStop>
    {
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionColorGradientStopCollection> : produce_base<D, llm::OS::UI::Composition::ICompositionColorGradientStopCollection>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionCommitBatch> : produce_base<D, llm::OS::UI::Composition::ICompositionCommitBatch>
    {
        int32_t __stdcall get_IsActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Completed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Completed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionContainerShape> : produce_base<D, llm::OS::UI::Composition::ICompositionContainerShape>
    {
        int32_t __stdcall get_Shapes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionShapeCollection>(this->shim().Shapes());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionDrawingSurface> : produce_base<D, llm::OS::UI::Composition::ICompositionDrawingSurface>
    {
        int32_t __stdcall get_AlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXAlphaMode>(this->shim().AlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().PixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionDrawingSurface2> : produce_base<D, llm::OS::UI::Composition::ICompositionDrawingSurface2>
    {
        int32_t __stdcall get_SizeInt32(struct struct_Windows_Graphics_SizeInt32* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::SizeInt32>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::SizeInt32>(this->shim().SizeInt32());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Resize(struct struct_Windows_Graphics_SizeInt32 sizePixels) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resize(*reinterpret_cast<llm::OS::Graphics::SizeInt32 const*>(&sizePixels));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Scroll(struct struct_Windows_Graphics_PointInt32 offset) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scroll(*reinterpret_cast<llm::OS::Graphics::PointInt32 const*>(&offset));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScrollRect(struct struct_Windows_Graphics_PointInt32 offset, struct struct_Windows_Graphics_RectInt32 scrollRect) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scroll(*reinterpret_cast<llm::OS::Graphics::PointInt32 const*>(&offset), *reinterpret_cast<llm::OS::Graphics::RectInt32 const*>(&scrollRect));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScrollWithClip(struct struct_Windows_Graphics_PointInt32 offset, struct struct_Windows_Graphics_RectInt32 clipRect) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScrollWithClip(*reinterpret_cast<llm::OS::Graphics::PointInt32 const*>(&offset), *reinterpret_cast<llm::OS::Graphics::RectInt32 const*>(&clipRect));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScrollRectWithClip(struct struct_Windows_Graphics_PointInt32 offset, struct struct_Windows_Graphics_RectInt32 clipRect, struct struct_Windows_Graphics_RectInt32 scrollRect) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScrollWithClip(*reinterpret_cast<llm::OS::Graphics::PointInt32 const*>(&offset), *reinterpret_cast<llm::OS::Graphics::RectInt32 const*>(&clipRect), *reinterpret_cast<llm::OS::Graphics::RectInt32 const*>(&scrollRect));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionDrawingSurfaceFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionDrawingSurfaceFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEasingFunction> : produce_base<D, llm::OS::UI::Composition::ICompositionEasingFunction>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEasingFunctionFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionEasingFunctionFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEasingFunctionStatics> : produce_base<D, llm::OS::UI::Composition::ICompositionEasingFunctionStatics>
    {
        int32_t __stdcall CreateCubicBezierEasingFunction(void* owner, llm::OS::Foundation::Numerics::float2 controlPoint1, llm::OS::Foundation::Numerics::float2 controlPoint2, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CubicBezierEasingFunction>(this->shim().CreateCubicBezierEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&controlPoint1), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&controlPoint2)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateLinearEasingFunction(void* owner, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::LinearEasingFunction>(this->shim().CreateLinearEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStepEasingFunction(void* owner, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::StepEasingFunction>(this->shim().CreateStepEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStepEasingFunctionWithStepCount(void* owner, int32_t stepCount, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::StepEasingFunction>(this->shim().CreateStepEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), stepCount));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBackEasingFunction(void* owner, int32_t mode, float amplitude, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::BackEasingFunction>(this->shim().CreateBackEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode), amplitude));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBounceEasingFunction(void* owner, int32_t mode, int32_t bounces, float bounciness, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::BounceEasingFunction>(this->shim().CreateBounceEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode), bounces, bounciness));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCircleEasingFunction(void* owner, int32_t mode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CircleEasingFunction>(this->shim().CreateCircleEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateElasticEasingFunction(void* owner, int32_t mode, int32_t oscillations, float springiness, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ElasticEasingFunction>(this->shim().CreateElasticEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode), oscillations, springiness));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateExponentialEasingFunction(void* owner, int32_t mode, float exponent, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ExponentialEasingFunction>(this->shim().CreateExponentialEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode), exponent));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePowerEasingFunction(void* owner, int32_t mode, float power, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::PowerEasingFunction>(this->shim().CreatePowerEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode), power));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSineEasingFunction(void* owner, int32_t mode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::SineEasingFunction>(this->shim().CreateSineEasingFunction(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&owner), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunctionMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEffectBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionEffectBrush>
    {
        int32_t __stdcall GetSourceParameter(void* name, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().GetSourceParameter(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSourceParameter(void* name, void* source) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSourceParameter(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&source));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEffectFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionEffectFactory>
    {
        int32_t __stdcall CreateBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionEffectBrush>(this->shim().CreateBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LoadStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEffectFactoryLoadStatus>(this->shim().LoadStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEffectSourceParameter> : produce_base<D, llm::OS::UI::Composition::ICompositionEffectSourceParameter>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEffectSourceParameterFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionEffectSourceParameterFactory>
    {
        int32_t __stdcall Create(void* name, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEffectSourceParameter>(this->shim().Create(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionEllipseGeometry> : produce_base<D, llm::OS::UI::Composition::ICompositionEllipseGeometry>
    {
        int32_t __stdcall get_Center(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Center());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Center(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Center(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Radius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Radius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Radius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Radius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGeometricClip> : produce_base<D, llm::OS::UI::Composition::ICompositionGeometricClip>
    {
        int32_t __stdcall get_Geometry(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionGeometry>(this->shim().Geometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Geometry(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Geometry(*reinterpret_cast<llm::OS::UI::Composition::CompositionGeometry const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ViewBox(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionViewBox>(this->shim().ViewBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewBox(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewBox(*reinterpret_cast<llm::OS::UI::Composition::CompositionViewBox const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGeometry> : produce_base<D, llm::OS::UI::Composition::ICompositionGeometry>
    {
        int32_t __stdcall get_TrimEnd(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TrimEnd());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimEnd(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimEnd(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimOffset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TrimOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimOffset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimOffset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrimStart(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TrimStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TrimStart(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TrimStart(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGeometryFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionGeometryFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGradientBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionGradientBrush>
    {
        int32_t __stdcall get_AnchorPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().AnchorPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AnchorPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CenterPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().CenterPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CenterPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorStops(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionColorGradientStopCollection>(this->shim().ColorStops());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionGradientExtendMode>(this->shim().ExtendMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExtendMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendMode(*reinterpret_cast<llm::OS::UI::Composition::CompositionGradientExtendMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InterpolationSpace(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionColorSpace>(this->shim().InterpolationSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InterpolationSpace(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InterpolationSpace(*reinterpret_cast<llm::OS::UI::Composition::CompositionColorSpace const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Scale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransformMatrix(llm::OS::Foundation::Numerics::float3x2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3x2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3x2>(this->shim().TransformMatrix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransformMatrix(llm::OS::Foundation::Numerics::float3x2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGradientBrush2> : produce_base<D, llm::OS::UI::Composition::ICompositionGradientBrush2>
    {
        int32_t __stdcall get_MappingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionMappingMode>(this->shim().MappingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MappingMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MappingMode(*reinterpret_cast<llm::OS::UI::Composition::CompositionMappingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGradientBrushFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionGradientBrushFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGraphicsDevice> : produce_base<D, llm::OS::UI::Composition::ICompositionGraphicsDevice>
    {
        int32_t __stdcall CreateDrawingSurface(llm::OS::Foundation::Size sizePixels, int32_t pixelFormat, int32_t alphaMode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionDrawingSurface>(this->shim().CreateDrawingSurface(*reinterpret_cast<llm::OS::Foundation::Size const*>(&sizePixels), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXAlphaMode const*>(&alphaMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_RenderingDeviceReplaced(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().RenderingDeviceReplaced(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Composition::CompositionGraphicsDevice, llm::OS::UI::Composition::RenderingDeviceReplacedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_RenderingDeviceReplaced(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RenderingDeviceReplaced(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGraphicsDevice2> : produce_base<D, llm::OS::UI::Composition::ICompositionGraphicsDevice2>
    {
        int32_t __stdcall CreateDrawingSurface2(struct struct_Windows_Graphics_SizeInt32 sizePixels, int32_t pixelFormat, int32_t alphaMode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionDrawingSurface>(this->shim().CreateDrawingSurface2(*reinterpret_cast<llm::OS::Graphics::SizeInt32 const*>(&sizePixels), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXAlphaMode const*>(&alphaMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateVirtualDrawingSurface(struct struct_Windows_Graphics_SizeInt32 sizePixels, int32_t pixelFormat, int32_t alphaMode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionVirtualDrawingSurface>(this->shim().CreateVirtualDrawingSurface(*reinterpret_cast<llm::OS::Graphics::SizeInt32 const*>(&sizePixels), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXAlphaMode const*>(&alphaMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGraphicsDevice3> : produce_base<D, llm::OS::UI::Composition::ICompositionGraphicsDevice3>
    {
        int32_t __stdcall CreateMipmapSurface(struct struct_Windows_Graphics_SizeInt32 sizePixels, int32_t pixelFormat, int32_t alphaMode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionMipmapSurface>(this->shim().CreateMipmapSurface(*reinterpret_cast<llm::OS::Graphics::SizeInt32 const*>(&sizePixels), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXAlphaMode const*>(&alphaMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Trim() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Trim();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionGraphicsDevice4> : produce_base<D, llm::OS::UI::Composition::ICompositionGraphicsDevice4>
    {
        int32_t __stdcall CaptureAsync(void* captureVisual, struct struct_Windows_Graphics_SizeInt32 size, int32_t pixelFormat, int32_t alphaMode, float sdrBoost, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Composition::ICompositionSurface>>(this->shim().CaptureAsync(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&captureVisual), *reinterpret_cast<llm::OS::Graphics::SizeInt32 const*>(&size), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXPixelFormat const*>(&pixelFormat), *reinterpret_cast<llm::OS::Graphics::DirectX::DirectXAlphaMode const*>(&alphaMode), sdrBoost));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionLight> : produce_base<D, llm::OS::UI::Composition::ICompositionLight>
    {
        int32_t __stdcall get_Targets(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::VisualUnorderedCollection>(this->shim().Targets());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionLight2> : produce_base<D, llm::OS::UI::Composition::ICompositionLight2>
    {
        int32_t __stdcall get_ExclusionsFromTargets(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::VisualUnorderedCollection>(this->shim().ExclusionsFromTargets());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionLight3> : produce_base<D, llm::OS::UI::Composition::ICompositionLight3>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionLightFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionLightFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionLineGeometry> : produce_base<D, llm::OS::UI::Composition::ICompositionLineGeometry>
    {
        int32_t __stdcall get_Start(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Start());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Start(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_End(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().End());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_End(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().End(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionLinearGradientBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionLinearGradientBrush>
    {
        int32_t __stdcall get_EndPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().EndPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EndPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EndPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StartPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().StartPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StartPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionMaskBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionMaskBrush>
    {
        int32_t __stdcall get_Mask(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().Mask());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mask(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mask(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionMipmapSurface> : produce_base<D, llm::OS::UI::Composition::ICompositionMipmapSurface>
    {
        int32_t __stdcall get_LevelCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().LevelCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXAlphaMode>(this->shim().AlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PixelFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXPixelFormat>(this->shim().PixelFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SizeInt32(struct struct_Windows_Graphics_SizeInt32* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::SizeInt32>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::SizeInt32>(this->shim().SizeInt32());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDrawingSurfaceForLevel(uint32_t level, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionDrawingSurface>(this->shim().GetDrawingSurfaceForLevel(level));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionNineGridBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionNineGridBrush>
    {
        int32_t __stdcall get_BottomInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BottomInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BottomInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BottomInsetScale(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BottomInsetScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BottomInsetScale(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomInsetScale(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCenterHollow(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCenterHollow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsCenterHollow(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsCenterHollow(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LeftInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LeftInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LeftInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LeftInsetScale(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LeftInsetScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LeftInsetScale(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftInsetScale(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RightInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RightInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RightInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RightInsetScale(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RightInsetScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RightInsetScale(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightInsetScale(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TopInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TopInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TopInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TopInsetScale(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TopInsetScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TopInsetScale(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopInsetScale(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInsets(float inset) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsets(inset);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInsetsWithValues(float left, float top, float right, float bottom) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsets(left, top, right, bottom);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInsetScales(float scale) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsetScales(scale);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetInsetScalesWithValues(float left, float top, float right, float bottom) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetInsetScales(left, top, right, bottom);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObject> : produce_base<D, llm::OS::UI::Composition::ICompositionObject>
    {
        int32_t __stdcall get_Compositor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Compositor>(this->shim().Compositor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Dispatcher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreDispatcher>(this->shim().Dispatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionPropertySet>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAnimation(void* propertyName, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimation(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::UI::Composition::CompositionAnimation const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAnimation(void* propertyName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAnimation(*reinterpret_cast<hstring const*>(&propertyName));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObject2> : produce_base<D, llm::OS::UI::Composition::ICompositionObject2>
    {
        int32_t __stdcall get_Comment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Comment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Comment(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Comment(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImplicitAnimations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::ImplicitAnimationCollection>(this->shim().ImplicitAnimations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ImplicitAnimations(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ImplicitAnimations(*reinterpret_cast<llm::OS::UI::Composition::ImplicitAnimationCollection const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAnimationGroup(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimationGroup(*reinterpret_cast<llm::OS::UI::Composition::ICompositionAnimationBase const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopAnimationGroup(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopAnimationGroup(*reinterpret_cast<llm::OS::UI::Composition::ICompositionAnimationBase const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObject3> : produce_base<D, llm::OS::UI::Composition::ICompositionObject3>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObject4> : produce_base<D, llm::OS::UI::Composition::ICompositionObject4>
    {
        int32_t __stdcall TryGetAnimationController(void* propertyName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::AnimationController>(this->shim().TryGetAnimationController(*reinterpret_cast<hstring const*>(&propertyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObject5> : produce_base<D, llm::OS::UI::Composition::ICompositionObject5>
    {
        int32_t __stdcall StartAnimationWithController(void* propertyName, void* animation, void* animationController) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimation(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::UI::Composition::CompositionAnimation const*>(&animation), *reinterpret_cast<llm::OS::UI::Composition::AnimationController const*>(&animationController));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObjectFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionObjectFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionObjectStatics> : produce_base<D, llm::OS::UI::Composition::ICompositionObjectStatics>
    {
        int32_t __stdcall StartAnimationWithIAnimationObject(void* target, void* propertyName, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimationWithIAnimationObject(*reinterpret_cast<llm::OS::UI::Composition::IAnimationObject const*>(&target), *reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::UI::Composition::CompositionAnimation const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartAnimationGroupWithIAnimationObject(void* target, void* animation) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAnimationGroupWithIAnimationObject(*reinterpret_cast<llm::OS::UI::Composition::IAnimationObject const*>(&target), *reinterpret_cast<llm::OS::UI::Composition::ICompositionAnimationBase const*>(&animation));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionPath> : produce_base<D, llm::OS::UI::Composition::ICompositionPath>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionPathFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionPathFactory>
    {
        int32_t __stdcall Create(void* source, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionPath>(this->shim().Create(*reinterpret_cast<llm::OS::Graphics::IGeometrySource2D const*>(&source)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionPathGeometry> : produce_base<D, llm::OS::UI::Composition::ICompositionPathGeometry>
    {
        int32_t __stdcall get_Path(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionPath>(this->shim().Path());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Path(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Path(*reinterpret_cast<llm::OS::UI::Composition::CompositionPath const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionProjectedShadow> : produce_base<D, llm::OS::UI::Composition::ICompositionProjectedShadow>
    {
        int32_t __stdcall get_BlurRadiusMultiplier(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BlurRadiusMultiplier());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BlurRadiusMultiplier(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlurRadiusMultiplier(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Casters(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionProjectedShadowCasterCollection>(this->shim().Casters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LightSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionLight>(this->shim().LightSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LightSource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LightSource(*reinterpret_cast<llm::OS::UI::Composition::CompositionLight const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxBlurRadius(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxBlurRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxBlurRadius(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxBlurRadius(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinBlurRadius(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinBlurRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MinBlurRadius(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinBlurRadius(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Receivers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection>(this->shim().Receivers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionProjectedShadowCaster> : produce_base<D, llm::OS::UI::Composition::ICompositionProjectedShadowCaster>
    {
        int32_t __stdcall get_Brush(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().Brush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Brush(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Brush(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CastingVisual(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().CastingVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CastingVisual(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CastingVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection> : produce_base<D, llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection>
    {
        int32_t __stdcall get_Count(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Count());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertAbove(void* newCaster, void* reference) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAbove(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&newCaster), *reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&reference));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertAtBottom(void* newCaster) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAtBottom(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&newCaster));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertAtTop(void* newCaster) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAtTop(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&newCaster));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertBelow(void* newCaster, void* reference) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertBelow(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&newCaster), *reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&reference));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* caster) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowCaster const*>(&caster));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics> : produce_base<D, llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics>
    {
        int32_t __stdcall get_MaxRespectedCasters(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MaxRespectedCasters());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionProjectedShadowReceiver> : produce_base<D, llm::OS::UI::Composition::ICompositionProjectedShadowReceiver>
    {
        int32_t __stdcall get_ReceivingVisual(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().ReceivingVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ReceivingVisual(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReceivingVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection> : produce_base<D, llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection>
    {
        int32_t __stdcall Add(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowReceiver const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Count(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Count());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<llm::OS::UI::Composition::CompositionProjectedShadowReceiver const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionPropertySet> : produce_base<D, llm::OS::UI::Composition::ICompositionPropertySet>
    {
        int32_t __stdcall InsertColor(void* propertyName, struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertColor(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertMatrix3x2(void* propertyName, llm::OS::Foundation::Numerics::float3x2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertMatrix3x2(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertMatrix4x4(void* propertyName, llm::OS::Foundation::Numerics::float4x4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertMatrix4x4(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float4x4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertQuaternion(void* propertyName, llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertQuaternion(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertScalar(void* propertyName, float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertScalar(*reinterpret_cast<hstring const*>(&propertyName), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertVector2(void* propertyName, llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertVector2(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertVector3(void* propertyName, llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertVector3(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertVector4(void* propertyName, llm::OS::Foundation::Numerics::float4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertVector4(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetColor(void* propertyName, struct struct_Windows_UI_Color* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetColor(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::UI::Color*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetMatrix3x2(void* propertyName, llm::OS::Foundation::Numerics::float3x2* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3x2>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetMatrix3x2(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float3x2*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetMatrix4x4(void* propertyName, llm::OS::Foundation::Numerics::float4x4* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetMatrix4x4(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float4x4*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetQuaternion(void* propertyName, llm::OS::Foundation::Numerics::quaternion* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetQuaternion(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetScalar(void* propertyName, float* value, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetScalar(*reinterpret_cast<hstring const*>(&propertyName), *value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetVector2(void* propertyName, llm::OS::Foundation::Numerics::float2* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetVector2(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float2*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetVector3(void* propertyName, llm::OS::Foundation::Numerics::float3* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetVector3(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float3*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetVector4(void* propertyName, llm::OS::Foundation::Numerics::float4* value, int32_t* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4>(value);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetVector4(*reinterpret_cast<hstring const*>(&propertyName), *reinterpret_cast<llm::OS::Foundation::Numerics::float4*>(value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionPropertySet2> : produce_base<D, llm::OS::UI::Composition::ICompositionPropertySet2>
    {
        int32_t __stdcall InsertBoolean(void* propertyName, bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertBoolean(*reinterpret_cast<hstring const*>(&propertyName), value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryGetBoolean(void* propertyName, bool* value, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGetValueStatus>(this->shim().TryGetBoolean(*reinterpret_cast<hstring const*>(&propertyName), *value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionRadialGradientBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionRadialGradientBrush>
    {
        int32_t __stdcall get_EllipseCenter(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().EllipseCenter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EllipseCenter(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EllipseCenter(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EllipseRadius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().EllipseRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EllipseRadius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EllipseRadius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GradientOriginOffset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().GradientOriginOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_GradientOriginOffset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GradientOriginOffset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionRectangleGeometry> : produce_base<D, llm::OS::UI::Composition::ICompositionRectangleGeometry>
    {
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Size(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry> : produce_base<D, llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry>
    {
        int32_t __stdcall get_CornerRadius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().CornerRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CornerRadius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CornerRadius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Size(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionScopedBatch> : produce_base<D, llm::OS::UI::Composition::ICompositionScopedBatch>
    {
        int32_t __stdcall get_IsActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall End() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().End();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Resume() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resume();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Suspend() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Suspend();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Completed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Completed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Completed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Completed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionShadow> : produce_base<D, llm::OS::UI::Composition::ICompositionShadow>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionShadowFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionShadowFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionShape> : produce_base<D, llm::OS::UI::Composition::ICompositionShape>
    {
        int32_t __stdcall get_CenterPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().CenterPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CenterPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Scale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransformMatrix(llm::OS::Foundation::Numerics::float3x2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3x2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3x2>(this->shim().TransformMatrix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransformMatrix(llm::OS::Foundation::Numerics::float3x2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionShapeFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionShapeFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSpriteShape> : produce_base<D, llm::OS::UI::Composition::ICompositionSpriteShape>
    {
        int32_t __stdcall get_FillBrush(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().FillBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FillBrush(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FillBrush(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Geometry(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionGeometry>(this->shim().Geometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Geometry(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Geometry(*reinterpret_cast<llm::OS::UI::Composition::CompositionGeometry const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsStrokeNonScaling(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsStrokeNonScaling());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsStrokeNonScaling(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsStrokeNonScaling(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeBrush(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().StrokeBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeBrush(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeBrush(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeDashArray(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStrokeDashArray>(this->shim().StrokeDashArray());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeDashCap(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStrokeCap>(this->shim().StrokeDashCap());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeDashCap(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashCap(*reinterpret_cast<llm::OS::UI::Composition::CompositionStrokeCap const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeDashOffset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().StrokeDashOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeDashOffset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeDashOffset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeEndCap(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStrokeCap>(this->shim().StrokeEndCap());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeEndCap(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeEndCap(*reinterpret_cast<llm::OS::UI::Composition::CompositionStrokeCap const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeLineJoin(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStrokeLineJoin>(this->shim().StrokeLineJoin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeLineJoin(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeLineJoin(*reinterpret_cast<llm::OS::UI::Composition::CompositionStrokeLineJoin const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeMiterLimit(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().StrokeMiterLimit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeMiterLimit(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeMiterLimit(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeStartCap(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStrokeCap>(this->shim().StrokeStartCap());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeStartCap(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeStartCap(*reinterpret_cast<llm::OS::UI::Composition::CompositionStrokeCap const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StrokeThickness(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().StrokeThickness());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StrokeThickness(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StrokeThickness(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSupportsSystemBackdrop> : produce_base<D, llm::OS::UI::Composition::ICompositionSupportsSystemBackdrop>
    {
        int32_t __stdcall get_SystemBackdrop(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().SystemBackdrop());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SystemBackdrop(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemBackdrop(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSurface> : produce_base<D, llm::OS::UI::Composition::ICompositionSurface>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSurfaceBrush> : produce_base<D, llm::OS::UI::Composition::ICompositionSurfaceBrush>
    {
        int32_t __stdcall get_BitmapInterpolationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBitmapInterpolationMode>(this->shim().BitmapInterpolationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BitmapInterpolationMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BitmapInterpolationMode(*reinterpret_cast<llm::OS::UI::Composition::CompositionBitmapInterpolationMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HorizontalAlignmentRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().HorizontalAlignmentRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HorizontalAlignmentRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalAlignmentRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Stretch(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStretch>(this->shim().Stretch());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Stretch(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stretch(*reinterpret_cast<llm::OS::UI::Composition::CompositionStretch const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Surface(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::ICompositionSurface>(this->shim().Surface());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Surface(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Surface(*reinterpret_cast<llm::OS::UI::Composition::ICompositionSurface const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VerticalAlignmentRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().VerticalAlignmentRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VerticalAlignmentRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VerticalAlignmentRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSurfaceBrush2> : produce_base<D, llm::OS::UI::Composition::ICompositionSurfaceBrush2>
    {
        int32_t __stdcall get_AnchorPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().AnchorPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AnchorPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CenterPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().CenterPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CenterPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Scale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransformMatrix(llm::OS::Foundation::Numerics::float3x2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3x2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3x2>(this->shim().TransformMatrix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransformMatrix(llm::OS::Foundation::Numerics::float3x2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSurfaceBrush3> : produce_base<D, llm::OS::UI::Composition::ICompositionSurfaceBrush3>
    {
        int32_t __stdcall get_SnapToPixels(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SnapToPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SnapToPixels(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SnapToPixels(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionSurfaceFacade> : produce_base<D, llm::OS::UI::Composition::ICompositionSurfaceFacade>
    {
        int32_t __stdcall GetRealSurface(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ICompositionSurface>(this->shim().GetRealSurface());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionTarget> : produce_base<D, llm::OS::UI::Composition::ICompositionTarget>
    {
        int32_t __stdcall get_Root(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().Root());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Root(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Root(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionTargetFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionTargetFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionTexture> : produce_base<D, llm::OS::UI::Composition::ICompositionTexture>
    {
        int32_t __stdcall get_SourceRect(struct struct_Windows_Graphics_RectInt32* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::RectInt32>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::RectInt32>(this->shim().SourceRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceRect(struct struct_Windows_Graphics_RectInt32 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceRect(*reinterpret_cast<llm::OS::Graphics::RectInt32 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlphaMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXAlphaMode>(this->shim().AlphaMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AlphaMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlphaMode(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXAlphaMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ColorSpace(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::DirectX::DirectXColorSpace>(this->shim().ColorSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ColorSpace(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorSpace(*reinterpret_cast<llm::OS::Graphics::DirectX::DirectXColorSpace const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionTextureFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionTextureFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionTransform> : produce_base<D, llm::OS::UI::Composition::ICompositionTransform>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionTransformFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionTransformFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionViewBox> : produce_base<D, llm::OS::UI::Composition::ICompositionViewBox>
    {
        int32_t __stdcall get_HorizontalAlignmentRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().HorizontalAlignmentRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_HorizontalAlignmentRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HorizontalAlignmentRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Size(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Stretch(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionStretch>(this->shim().Stretch());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Stretch(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stretch(*reinterpret_cast<llm::OS::UI::Composition::CompositionStretch const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VerticalAlignmentRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().VerticalAlignmentRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VerticalAlignmentRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VerticalAlignmentRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionVirtualDrawingSurface> : produce_base<D, llm::OS::UI::Composition::ICompositionVirtualDrawingSurface>
    {
        int32_t __stdcall Trim(uint32_t __rectsSize, struct struct_Windows_Graphics_RectInt32* rects) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Trim(array_view<llm::OS::Graphics::RectInt32 const>(reinterpret_cast<llm::OS::Graphics::RectInt32 const *>(rects), reinterpret_cast<llm::OS::Graphics::RectInt32 const *>(rects) + __rectsSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory> : produce_base<D, llm::OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositionVisualSurface> : produce_base<D, llm::OS::UI::Composition::ICompositionVisualSurface>
    {
        int32_t __stdcall get_SourceVisual(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().SourceVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceVisual(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceOffset(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().SourceOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceOffset(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceOffset(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SourceSize(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().SourceSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourceSize(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourceSize(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor> : produce_base<D, llm::OS::UI::Composition::ICompositor>
    {
        int32_t __stdcall CreateColorKeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ColorKeyFrameAnimation>(this->shim().CreateColorKeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateColorBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionColorBrush>(this->shim().CreateColorBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateColorBrushWithColor(struct struct_Windows_UI_Color color, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionColorBrush>(this->shim().CreateColorBrush(*reinterpret_cast<llm::OS::UI::Color const*>(&color)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainerVisual(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ContainerVisual>(this->shim().CreateContainerVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateCubicBezierEasingFunction(llm::OS::Foundation::Numerics::float2 controlPoint1, llm::OS::Foundation::Numerics::float2 controlPoint2, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CubicBezierEasingFunction>(this->shim().CreateCubicBezierEasingFunction(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&controlPoint1), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&controlPoint2)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEffectFactory(void* graphicsEffect, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionEffectFactory>(this->shim().CreateEffectFactory(*reinterpret_cast<llm::OS::Graphics::Effects::IGraphicsEffect const*>(&graphicsEffect)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEffectFactoryWithProperties(void* graphicsEffect, void* animatableProperties, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionEffectFactory>(this->shim().CreateEffectFactory(*reinterpret_cast<llm::OS::Graphics::Effects::IGraphicsEffect const*>(&graphicsEffect), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&animatableProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateExpressionAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ExpressionAnimation>(this->shim().CreateExpressionAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateExpressionAnimationWithExpression(void* expression, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ExpressionAnimation>(this->shim().CreateExpressionAnimation(*reinterpret_cast<hstring const*>(&expression)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInsetClip(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::InsetClip>(this->shim().CreateInsetClip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInsetClipWithInsets(float leftInset, float topInset, float rightInset, float bottomInset, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::InsetClip>(this->shim().CreateInsetClip(leftInset, topInset, rightInset, bottomInset));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateLinearEasingFunction(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::LinearEasingFunction>(this->shim().CreateLinearEasingFunction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePropertySet(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionPropertySet>(this->shim().CreatePropertySet());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateQuaternionKeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::QuaternionKeyFrameAnimation>(this->shim().CreateQuaternionKeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateScalarKeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ScalarKeyFrameAnimation>(this->shim().CreateScalarKeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateScopedBatch(uint32_t batchType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionScopedBatch>(this->shim().CreateScopedBatch(*reinterpret_cast<llm::OS::UI::Composition::CompositionBatchTypes const*>(&batchType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpriteVisual(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::SpriteVisual>(this->shim().CreateSpriteVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSurfaceBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionSurfaceBrush>(this->shim().CreateSurfaceBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSurfaceBrushWithSurface(void* surface, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionSurfaceBrush>(this->shim().CreateSurfaceBrush(*reinterpret_cast<llm::OS::UI::Composition::ICompositionSurface const*>(&surface)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateTargetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionTarget>(this->shim().CreateTargetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateVector2KeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Vector2KeyFrameAnimation>(this->shim().CreateVector2KeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateVector3KeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Vector3KeyFrameAnimation>(this->shim().CreateVector3KeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateVector4KeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Vector4KeyFrameAnimation>(this->shim().CreateVector4KeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCommitBatch(uint32_t batchType, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionCommitBatch>(this->shim().GetCommitBatch(*reinterpret_cast<llm::OS::UI::Composition::CompositionBatchTypes const*>(&batchType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor2> : produce_base<D, llm::OS::UI::Composition::ICompositor2>
    {
        int32_t __stdcall CreateAmbientLight(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::AmbientLight>(this->shim().CreateAmbientLight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAnimationGroup(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionAnimationGroup>(this->shim().CreateAnimationGroup());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBackdropBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionBackdropBrush>(this->shim().CreateBackdropBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDistantLight(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::DistantLight>(this->shim().CreateDistantLight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateDropShadow(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::DropShadow>(this->shim().CreateDropShadow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateImplicitAnimationCollection(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ImplicitAnimationCollection>(this->shim().CreateImplicitAnimationCollection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateLayerVisual(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::LayerVisual>(this->shim().CreateLayerVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateMaskBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionMaskBrush>(this->shim().CreateMaskBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateNineGridBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionNineGridBrush>(this->shim().CreateNineGridBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePointLight(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::PointLight>(this->shim().CreatePointLight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpotLight(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::SpotLight>(this->shim().CreateSpotLight());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStepEasingFunction(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::StepEasingFunction>(this->shim().CreateStepEasingFunction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateStepEasingFunctionWithStepCount(int32_t stepCount, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::StepEasingFunction>(this->shim().CreateStepEasingFunction(stepCount));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor3> : produce_base<D, llm::OS::UI::Composition::ICompositor3>
    {
        int32_t __stdcall CreateHostBackdropBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionBackdropBrush>(this->shim().CreateHostBackdropBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor4> : produce_base<D, llm::OS::UI::Composition::ICompositor4>
    {
        int32_t __stdcall CreateColorGradientStop(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionColorGradientStop>(this->shim().CreateColorGradientStop());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateColorGradientStopWithOffsetAndColor(float offset, struct struct_Windows_UI_Color color, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionColorGradientStop>(this->shim().CreateColorGradientStop(offset, *reinterpret_cast<llm::OS::UI::Color const*>(&color)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateLinearGradientBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionLinearGradientBrush>(this->shim().CreateLinearGradientBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpringScalarAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::SpringScalarNaturalMotionAnimation>(this->shim().CreateSpringScalarAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpringVector2Animation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::SpringVector2NaturalMotionAnimation>(this->shim().CreateSpringVector2Animation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpringVector3Animation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::SpringVector3NaturalMotionAnimation>(this->shim().CreateSpringVector3Animation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor5> : produce_base<D, llm::OS::UI::Composition::ICompositor5>
    {
        int32_t __stdcall get_Comment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Comment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Comment(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Comment(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GlobalPlaybackRate(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().GlobalPlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_GlobalPlaybackRate(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GlobalPlaybackRate(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBounceScalarAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::BounceScalarNaturalMotionAnimation>(this->shim().CreateBounceScalarAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBounceVector2Animation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::BounceVector2NaturalMotionAnimation>(this->shim().CreateBounceVector2Animation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBounceVector3Animation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::BounceVector3NaturalMotionAnimation>(this->shim().CreateBounceVector3Animation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateContainerShape(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionContainerShape>(this->shim().CreateContainerShape());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEllipseGeometry(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionEllipseGeometry>(this->shim().CreateEllipseGeometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateLineGeometry(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionLineGeometry>(this->shim().CreateLineGeometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePathGeometry(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionPathGeometry>(this->shim().CreatePathGeometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePathGeometryWithPath(void* path, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionPathGeometry>(this->shim().CreatePathGeometry(*reinterpret_cast<llm::OS::UI::Composition::CompositionPath const*>(&path)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePathKeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::PathKeyFrameAnimation>(this->shim().CreatePathKeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRectangleGeometry(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionRectangleGeometry>(this->shim().CreateRectangleGeometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRoundedRectangleGeometry(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionRoundedRectangleGeometry>(this->shim().CreateRoundedRectangleGeometry());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateShapeVisual(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::ShapeVisual>(this->shim().CreateShapeVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpriteShape(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionSpriteShape>(this->shim().CreateSpriteShape());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSpriteShapeWithGeometry(void* geometry, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionSpriteShape>(this->shim().CreateSpriteShape(*reinterpret_cast<llm::OS::UI::Composition::CompositionGeometry const*>(&geometry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateViewBox(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionViewBox>(this->shim().CreateViewBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCommitAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RequestCommitAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor6> : produce_base<D, llm::OS::UI::Composition::ICompositor6>
    {
        int32_t __stdcall CreateGeometricClip(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGeometricClip>(this->shim().CreateGeometricClip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateGeometricClipWithGeometry(void* geometry, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionGeometricClip>(this->shim().CreateGeometricClip(*reinterpret_cast<llm::OS::UI::Composition::CompositionGeometry const*>(&geometry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRedirectVisual(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::RedirectVisual>(this->shim().CreateRedirectVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRedirectVisualWithSourceVisual(void* source, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::RedirectVisual>(this->shim().CreateRedirectVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&source)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateBooleanKeyFrameAnimation(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::BooleanKeyFrameAnimation>(this->shim().CreateBooleanKeyFrameAnimation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor7> : produce_base<D, llm::OS::UI::Composition::ICompositor7>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAnimationPropertyInfo(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::AnimationPropertyInfo>(this->shim().CreateAnimationPropertyInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRectangleClip(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::RectangleClip>(this->shim().CreateRectangleClip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRectangleClipWithSides(float left, float top, float right, float bottom, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::RectangleClip>(this->shim().CreateRectangleClip(left, top, right, bottom));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateRectangleClipWithSidesAndRadius(float left, float top, float right, float bottom, llm::OS::Foundation::Numerics::float2 topLeftRadius, llm::OS::Foundation::Numerics::float2 topRightRadius, llm::OS::Foundation::Numerics::float2 bottomRightRadius, llm::OS::Foundation::Numerics::float2 bottomLeftRadius, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::RectangleClip>(this->shim().CreateRectangleClip(left, top, right, bottom, *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&topLeftRadius), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&topRightRadius), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&bottomRightRadius), *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&bottomLeftRadius)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositor8> : produce_base<D, llm::OS::UI::Composition::ICompositor8>
    {
        int32_t __stdcall CreateAnimationController(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::AnimationController>(this->shim().CreateAnimationController());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositorStatics> : produce_base<D, llm::OS::UI::Composition::ICompositorStatics>
    {
        int32_t __stdcall get_MaxGlobalPlaybackRate(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxGlobalPlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinGlobalPlaybackRate(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinGlobalPlaybackRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush> : produce_base<D, llm::OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush>
    {
        int32_t __stdcall TryCreateBlurredWallpaperBackdropBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionBackdropBrush>(this->shim().TryCreateBlurredWallpaperBackdropBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositorWithProjectedShadow> : produce_base<D, llm::OS::UI::Composition::ICompositorWithProjectedShadow>
    {
        int32_t __stdcall CreateProjectedShadowCaster(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionProjectedShadowCaster>(this->shim().CreateProjectedShadowCaster());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateProjectedShadow(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionProjectedShadow>(this->shim().CreateProjectedShadow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateProjectedShadowReceiver(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionProjectedShadowReceiver>(this->shim().CreateProjectedShadowReceiver());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositorWithRadialGradient> : produce_base<D, llm::OS::UI::Composition::ICompositorWithRadialGradient>
    {
        int32_t __stdcall CreateRadialGradientBrush(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionRadialGradientBrush>(this->shim().CreateRadialGradientBrush());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICompositorWithVisualSurface> : produce_base<D, llm::OS::UI::Composition::ICompositorWithVisualSurface>
    {
        int32_t __stdcall CreateVisualSurface(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::CompositionVisualSurface>(this->shim().CreateVisualSurface());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IContainerVisual> : produce_base<D, llm::OS::UI::Composition::IContainerVisual>
    {
        int32_t __stdcall get_Children(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::VisualCollection>(this->shim().Children());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IContainerVisualFactory> : produce_base<D, llm::OS::UI::Composition::IContainerVisualFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ICubicBezierEasingFunction> : produce_base<D, llm::OS::UI::Composition::ICubicBezierEasingFunction>
    {
        int32_t __stdcall get_ControlPoint1(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().ControlPoint1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ControlPoint2(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().ControlPoint2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IDelegatedInkTrailVisual> : produce_base<D, llm::OS::UI::Composition::IDelegatedInkTrailVisual>
    {
        int32_t __stdcall AddTrailPoints(uint32_t __inkPointsSize, struct struct_Windows_UI_Composition_InkTrailPoint* inkPoints, uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<uint32_t>(this->shim().AddTrailPoints(array_view<llm::OS::UI::Composition::InkTrailPoint const>(reinterpret_cast<llm::OS::UI::Composition::InkTrailPoint const *>(inkPoints), reinterpret_cast<llm::OS::UI::Composition::InkTrailPoint const *>(inkPoints) + __inkPointsSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddTrailPointsWithPrediction(uint32_t __inkPointsSize, struct struct_Windows_UI_Composition_InkTrailPoint* inkPoints, uint32_t __predictedInkPointsSize, struct struct_Windows_UI_Composition_InkTrailPoint* predictedInkPoints, uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<uint32_t>(this->shim().AddTrailPointsWithPrediction(array_view<llm::OS::UI::Composition::InkTrailPoint const>(reinterpret_cast<llm::OS::UI::Composition::InkTrailPoint const *>(inkPoints), reinterpret_cast<llm::OS::UI::Composition::InkTrailPoint const *>(inkPoints) + __inkPointsSize), array_view<llm::OS::UI::Composition::InkTrailPoint const>(reinterpret_cast<llm::OS::UI::Composition::InkTrailPoint const *>(predictedInkPoints), reinterpret_cast<llm::OS::UI::Composition::InkTrailPoint const *>(predictedInkPoints) + __predictedInkPointsSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveTrailPoints(uint32_t generationId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveTrailPoints(generationId);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartNewTrail(struct struct_Windows_UI_Color color) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartNewTrail(*reinterpret_cast<llm::OS::UI::Color const*>(&color));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IDelegatedInkTrailVisualStatics> : produce_base<D, llm::OS::UI::Composition::IDelegatedInkTrailVisualStatics>
    {
        int32_t __stdcall Create(void* compositor, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::DelegatedInkTrailVisual>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateForSwapChain(void* compositor, void* swapChain, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::DelegatedInkTrailVisual>(this->shim().CreateForSwapChain(*reinterpret_cast<llm::OS::UI::Composition::Compositor const*>(&compositor), *reinterpret_cast<llm::OS::UI::Composition::ICompositionSurface const*>(&swapChain)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IDistantLight> : produce_base<D, llm::OS::UI::Composition::IDistantLight>
    {
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSpace(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().CoordinateSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CoordinateSpace(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CoordinateSpace(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Direction(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Direction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Direction(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IDistantLight2> : produce_base<D, llm::OS::UI::Composition::IDistantLight2>
    {
        int32_t __stdcall get_Intensity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Intensity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Intensity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Intensity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IDropShadow> : produce_base<D, llm::OS::UI::Composition::IDropShadow>
    {
        int32_t __stdcall get_BlurRadius(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BlurRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BlurRadius(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BlurRadius(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Mask(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().Mask());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Mask(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Mask(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Opacity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Opacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Opacity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IDropShadow2> : produce_base<D, llm::OS::UI::Composition::IDropShadow2>
    {
        int32_t __stdcall get_SourcePolicy(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionDropShadowSourcePolicy>(this->shim().SourcePolicy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SourcePolicy(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SourcePolicy(*reinterpret_cast<llm::OS::UI::Composition::CompositionDropShadowSourcePolicy const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IElasticEasingFunction> : produce_base<D, llm::OS::UI::Composition::IElasticEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Oscillations(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Oscillations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Springiness(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Springiness());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IExponentialEasingFunction> : produce_base<D, llm::OS::UI::Composition::IExponentialEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Exponent(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Exponent());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IExpressionAnimation> : produce_base<D, llm::OS::UI::Composition::IExpressionAnimation>
    {
        int32_t __stdcall get_Expression(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Expression());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Expression(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Expression(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IImplicitAnimationCollection> : produce_base<D, llm::OS::UI::Composition::IImplicitAnimationCollection>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IInsetClip> : produce_base<D, llm::OS::UI::Composition::IInsetClip>
    {
        int32_t __stdcall get_BottomInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BottomInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BottomInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LeftInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LeftInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LeftInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RightInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RightInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RightInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TopInset(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TopInset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TopInset(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopInset(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IKeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IKeyFrameAnimation>
    {
        int32_t __stdcall get_DelayTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DelayTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DelayTime(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DelayTime(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
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
        int32_t __stdcall put_Duration(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Duration(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IterationBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationIterationBehavior>(this->shim().IterationBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IterationBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IterationBehavior(*reinterpret_cast<llm::OS::UI::Composition::AnimationIterationBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IterationCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().IterationCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IterationCount(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IterationCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyFrameCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().KeyFrameCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StopBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationStopBehavior>(this->shim().StopBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StopBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopBehavior(*reinterpret_cast<llm::OS::UI::Composition::AnimationStopBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertExpressionKeyFrame(float normalizedProgressKey, void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertExpressionKeyFrame(normalizedProgressKey, *reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertExpressionKeyFrameWithEasingFunction(float normalizedProgressKey, void* value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertExpressionKeyFrame(normalizedProgressKey, *reinterpret_cast<hstring const*>(&value), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IKeyFrameAnimation2> : produce_base<D, llm::OS::UI::Composition::IKeyFrameAnimation2>
    {
        int32_t __stdcall get_Direction(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationDirection>(this->shim().Direction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Direction(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(*reinterpret_cast<llm::OS::UI::Composition::AnimationDirection const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IKeyFrameAnimation3> : produce_base<D, llm::OS::UI::Composition::IKeyFrameAnimation3>
    {
        int32_t __stdcall get_DelayBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationDelayBehavior>(this->shim().DelayBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DelayBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DelayBehavior(*reinterpret_cast<llm::OS::UI::Composition::AnimationDelayBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IKeyFrameAnimationFactory> : produce_base<D, llm::OS::UI::Composition::IKeyFrameAnimationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ILayerVisual> : produce_base<D, llm::OS::UI::Composition::ILayerVisual>
    {
        int32_t __stdcall get_Effect(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEffectBrush>(this->shim().Effect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Effect(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Effect(*reinterpret_cast<llm::OS::UI::Composition::CompositionEffectBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ILayerVisual2> : produce_base<D, llm::OS::UI::Composition::ILayerVisual2>
    {
        int32_t __stdcall get_Shadow(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionShadow>(this->shim().Shadow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Shadow(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Shadow(*reinterpret_cast<llm::OS::UI::Composition::CompositionShadow const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ILinearEasingFunction> : produce_base<D, llm::OS::UI::Composition::ILinearEasingFunction>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::INaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::INaturalMotionAnimation>
    {
        int32_t __stdcall get_DelayBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationDelayBehavior>(this->shim().DelayBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DelayBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DelayBehavior(*reinterpret_cast<llm::OS::UI::Composition::AnimationDelayBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DelayTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().DelayTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DelayTime(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DelayTime(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StopBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::AnimationStopBehavior>(this->shim().StopBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StopBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopBehavior(*reinterpret_cast<llm::OS::UI::Composition::AnimationStopBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::INaturalMotionAnimationFactory> : produce_base<D, llm::OS::UI::Composition::INaturalMotionAnimationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IPathKeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IPathKeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, void* path) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::UI::Composition::CompositionPath const*>(&path));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, void* path, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::UI::Composition::CompositionPath const*>(&path), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IPointLight> : produce_base<D, llm::OS::UI::Composition::IPointLight>
    {
        int32_t __stdcall get_Color(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().Color());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Color(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Color(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConstantAttenuation(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().ConstantAttenuation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ConstantAttenuation(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConstantAttenuation(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSpace(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().CoordinateSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CoordinateSpace(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CoordinateSpace(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LinearAttenuation(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LinearAttenuation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LinearAttenuation(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LinearAttenuation(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QuadraticAttenuation(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().QuadraticAttenuation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_QuadraticAttenuation(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuadraticAttenuation(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IPointLight2> : produce_base<D, llm::OS::UI::Composition::IPointLight2>
    {
        int32_t __stdcall get_Intensity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Intensity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Intensity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Intensity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IPointLight3> : produce_base<D, llm::OS::UI::Composition::IPointLight3>
    {
        int32_t __stdcall get_MinAttenuationCutoff(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinAttenuationCutoff());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MinAttenuationCutoff(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinAttenuationCutoff(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAttenuationCutoff(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxAttenuationCutoff());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxAttenuationCutoff(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAttenuationCutoff(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IPowerEasingFunction> : produce_base<D, llm::OS::UI::Composition::IPowerEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Power(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Power());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IQuaternionKeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IQuaternionKeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, llm::OS::Foundation::Numerics::quaternion value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IRectangleClip> : produce_base<D, llm::OS::UI::Composition::IRectangleClip>
    {
        int32_t __stdcall get_Bottom(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Bottom());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Bottom(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bottom(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BottomLeftRadius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().BottomLeftRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BottomLeftRadius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomLeftRadius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BottomRightRadius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().BottomRightRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BottomRightRadius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomRightRadius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Left(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Left());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Left(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Left(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Right(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Right());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Right(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Right(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Top(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Top());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Top(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Top(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TopLeftRadius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().TopLeftRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TopLeftRadius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopLeftRadius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TopRightRadius(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().TopRightRadius());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TopRightRadius(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopRightRadius(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IRedirectVisual> : produce_base<D, llm::OS::UI::Composition::IRedirectVisual>
    {
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Source(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Source(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IRenderingDeviceReplacedEventArgs> : produce_base<D, llm::OS::UI::Composition::IRenderingDeviceReplacedEventArgs>
    {
        int32_t __stdcall get_GraphicsDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionGraphicsDevice>(this->shim().GraphicsDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IScalarKeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IScalarKeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, float value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, value, *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IScalarNaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::IScalarNaturalMotionAnimation>
    {
        int32_t __stdcall get_FinalValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<float>>(this->shim().FinalValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FinalValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FinalValue(*reinterpret_cast<llm::OS::Foundation::IReference<float> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<float>>(this->shim().InitialValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialValue(*reinterpret_cast<llm::OS::Foundation::IReference<float> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialVelocity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().InitialVelocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialVelocity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialVelocity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IScalarNaturalMotionAnimationFactory> : produce_base<D, llm::OS::UI::Composition::IScalarNaturalMotionAnimationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IShapeVisual> : produce_base<D, llm::OS::UI::Composition::IShapeVisual>
    {
        int32_t __stdcall get_Shapes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionShapeCollection>(this->shim().Shapes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ViewBox(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionViewBox>(this->shim().ViewBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewBox(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewBox(*reinterpret_cast<llm::OS::UI::Composition::CompositionViewBox const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISineEasingFunction> : produce_base<D, llm::OS::UI::Composition::ISineEasingFunction>
    {
        int32_t __stdcall get_Mode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionEasingFunctionMode>(this->shim().Mode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpotLight> : produce_base<D, llm::OS::UI::Composition::ISpotLight>
    {
        int32_t __stdcall get_ConstantAttenuation(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().ConstantAttenuation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ConstantAttenuation(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConstantAttenuation(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CoordinateSpace(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().CoordinateSpace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CoordinateSpace(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CoordinateSpace(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Direction(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Direction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Direction(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Direction(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InnerConeAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().InnerConeAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InnerConeAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InnerConeAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().InnerConeAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InnerConeAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InnerConeColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().InnerConeColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InnerConeColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LinearAttenuation(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LinearAttenuation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LinearAttenuation(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LinearAttenuation(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OuterConeAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().OuterConeAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OuterConeAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OuterConeAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().OuterConeAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OuterConeAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OuterConeColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().OuterConeColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OuterConeColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QuadraticAttenuation(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().QuadraticAttenuation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_QuadraticAttenuation(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuadraticAttenuation(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpotLight2> : produce_base<D, llm::OS::UI::Composition::ISpotLight2>
    {
        int32_t __stdcall get_InnerConeIntensity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().InnerConeIntensity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InnerConeIntensity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InnerConeIntensity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OuterConeIntensity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().OuterConeIntensity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OuterConeIntensity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuterConeIntensity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpotLight3> : produce_base<D, llm::OS::UI::Composition::ISpotLight3>
    {
        int32_t __stdcall get_MinAttenuationCutoff(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MinAttenuationCutoff());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MinAttenuationCutoff(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MinAttenuationCutoff(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxAttenuationCutoff(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().MaxAttenuationCutoff());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxAttenuationCutoff(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxAttenuationCutoff(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation>
    {
        int32_t __stdcall get_DampingRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().DampingRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DampingRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DampingRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Period(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Period());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Period(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Period(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation>
    {
        int32_t __stdcall get_DampingRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().DampingRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DampingRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DampingRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Period(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Period());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Period(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Period(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation>
    {
        int32_t __stdcall get_DampingRatio(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().DampingRatio());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DampingRatio(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DampingRatio(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Period(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Period());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Period(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Period(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpriteVisual> : produce_base<D, llm::OS::UI::Composition::ISpriteVisual>
    {
        int32_t __stdcall get_Brush(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBrush>(this->shim().Brush());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Brush(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Brush(*reinterpret_cast<llm::OS::UI::Composition::CompositionBrush const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::ISpriteVisual2> : produce_base<D, llm::OS::UI::Composition::ISpriteVisual2>
    {
        int32_t __stdcall get_Shadow(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionShadow>(this->shim().Shadow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Shadow(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Shadow(*reinterpret_cast<llm::OS::UI::Composition::CompositionShadow const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IStepEasingFunction> : produce_base<D, llm::OS::UI::Composition::IStepEasingFunction>
    {
        int32_t __stdcall get_FinalStep(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().FinalStep());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FinalStep(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FinalStep(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialStep(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().InitialStep());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialStep(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialStep(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsFinalStepSingleFrame(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFinalStepSingleFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsFinalStepSingleFrame(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsFinalStepSingleFrame(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInitialStepSingleFrame(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInitialStepSingleFrame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInitialStepSingleFrame(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInitialStepSingleFrame(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StepCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().StepCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_StepCount(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StepCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector2KeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IVector2KeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, llm::OS::Foundation::Numerics::float2 value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector2NaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::IVector2NaturalMotionAnimation>
    {
        int32_t __stdcall get_FinalValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2>>(this->shim().FinalValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FinalValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FinalValue(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2>>(this->shim().InitialValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialValue(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float2> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialVelocity(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().InitialVelocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialVelocity(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialVelocity(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector2NaturalMotionAnimationFactory> : produce_base<D, llm::OS::UI::Composition::IVector2NaturalMotionAnimationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector3KeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IVector3KeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, llm::OS::Foundation::Numerics::float3 value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector3NaturalMotionAnimation> : produce_base<D, llm::OS::UI::Composition::IVector3NaturalMotionAnimation>
    {
        int32_t __stdcall get_FinalValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3>>(this->shim().FinalValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FinalValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FinalValue(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3>>(this->shim().InitialValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialValue(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Foundation::Numerics::float3> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialVelocity(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().InitialVelocity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InitialVelocity(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialVelocity(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector3NaturalMotionAnimationFactory> : produce_base<D, llm::OS::UI::Composition::IVector3NaturalMotionAnimationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVector4KeyFrameAnimation> : produce_base<D, llm::OS::UI::Composition::IVector4KeyFrameAnimation>
    {
        int32_t __stdcall InsertKeyFrame(float normalizedProgressKey, llm::OS::Foundation::Numerics::float4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::float4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertKeyFrameWithEasingFunction(float normalizedProgressKey, llm::OS::Foundation::Numerics::float4 value, void* easingFunction) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertKeyFrame(normalizedProgressKey, *reinterpret_cast<llm::OS::Foundation::Numerics::float4 const*>(&value), *reinterpret_cast<llm::OS::UI::Composition::CompositionEasingFunction const*>(&easingFunction));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisual> : produce_base<D, llm::OS::UI::Composition::IVisual>
    {
        int32_t __stdcall get_AnchorPoint(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().AnchorPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AnchorPoint(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnchorPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackfaceVisibility(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBackfaceVisibility>(this->shim().BackfaceVisibility());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackfaceVisibility(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackfaceVisibility(*reinterpret_cast<llm::OS::UI::Composition::CompositionBackfaceVisibility const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BorderMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionBorderMode>(this->shim().BorderMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BorderMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BorderMode(*reinterpret_cast<llm::OS::UI::Composition::CompositionBorderMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CenterPoint(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().CenterPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CenterPoint(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CenterPoint(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Clip(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionClip>(this->shim().Clip());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Clip(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clip(*reinterpret_cast<llm::OS::UI::Composition::CompositionClip const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CompositeMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::CompositionCompositeMode>(this->shim().CompositeMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CompositeMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositeMode(*reinterpret_cast<llm::OS::UI::Composition::CompositionCompositeMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsVisible(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsVisible(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Offset(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Offset(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Opacity(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().Opacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Opacity(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Opacity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Orientation(llm::OS::Foundation::Numerics::quaternion* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::quaternion>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::quaternion>(this->shim().Orientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Orientation(llm::OS::Foundation::Numerics::quaternion value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Orientation(*reinterpret_cast<llm::OS::Foundation::Numerics::quaternion const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Parent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::ContainerVisual>(this->shim().Parent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngle(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngle(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngle(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAngleInDegrees(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RotationAngleInDegrees());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAngleInDegrees(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAngleInDegrees(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RotationAxis(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().RotationAxis());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RotationAxis(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RotationAxis(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Scale(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().Scale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Scale(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Scale(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Size(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Size(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransformMatrix(llm::OS::Foundation::Numerics::float4x4* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float4x4>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float4x4>(this->shim().TransformMatrix());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransformMatrix(llm::OS::Foundation::Numerics::float4x4 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransformMatrix(*reinterpret_cast<llm::OS::Foundation::Numerics::float4x4 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisual2> : produce_base<D, llm::OS::UI::Composition::IVisual2>
    {
        int32_t __stdcall get_ParentForTransform(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::Visual>(this->shim().ParentForTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ParentForTransform(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ParentForTransform(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RelativeOffsetAdjustment(llm::OS::Foundation::Numerics::float3* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3>(this->shim().RelativeOffsetAdjustment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RelativeOffsetAdjustment(llm::OS::Foundation::Numerics::float3 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeOffsetAdjustment(*reinterpret_cast<llm::OS::Foundation::Numerics::float3 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RelativeSizeAdjustment(llm::OS::Foundation::Numerics::float2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float2>(this->shim().RelativeSizeAdjustment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RelativeSizeAdjustment(llm::OS::Foundation::Numerics::float2 value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RelativeSizeAdjustment(*reinterpret_cast<llm::OS::Foundation::Numerics::float2 const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisual3> : produce_base<D, llm::OS::UI::Composition::IVisual3>
    {
        int32_t __stdcall get_IsHitTestVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsHitTestVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsHitTestVisible(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsHitTestVisible(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisual4> : produce_base<D, llm::OS::UI::Composition::IVisual4>
    {
        int32_t __stdcall get_IsPixelSnappingEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPixelSnappingEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsPixelSnappingEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPixelSnappingEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisualCollection> : produce_base<D, llm::OS::UI::Composition::IVisualCollection>
    {
        int32_t __stdcall get_Count(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Count());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertAbove(void* newChild, void* sibling) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAbove(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&newChild), *reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&sibling));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertAtBottom(void* newChild) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAtBottom(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&newChild));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertAtTop(void* newChild) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertAtTop(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&newChild));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InsertBelow(void* newChild, void* sibling) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InsertBelow(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&newChild), *reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&sibling));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* child) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&child));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisualElement> : produce_base<D, llm::OS::UI::Composition::IVisualElement>
    {
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisualElement2> : produce_base<D, llm::OS::UI::Composition::IVisualElement2>
    {
        int32_t __stdcall GetVisualInternal(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Composition::Visual>(this->shim().GetVisualInternal());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisualFactory> : produce_base<D, llm::OS::UI::Composition::IVisualFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Composition::IVisualUnorderedCollection> : produce_base<D, llm::OS::UI::Composition::IVisualUnorderedCollection>
    {
        int32_t __stdcall get_Count(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Count());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Add(void* newVisual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Add(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&newVisual));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Remove(void* visual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Remove(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&visual));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAll() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveAll();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Composition
{
    constexpr auto operator|(CompositionBatchTypes const left, CompositionBatchTypes const right) noexcept
    {
        return static_cast<CompositionBatchTypes>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(CompositionBatchTypes& left, CompositionBatchTypes const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(CompositionBatchTypes const left, CompositionBatchTypes const right) noexcept
    {
        return static_cast<CompositionBatchTypes>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(CompositionBatchTypes& left, CompositionBatchTypes const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(CompositionBatchTypes const value) noexcept
    {
        return static_cast<CompositionBatchTypes>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(CompositionBatchTypes const left, CompositionBatchTypes const right) noexcept
    {
        return static_cast<CompositionBatchTypes>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(CompositionBatchTypes& left, CompositionBatchTypes const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto AnimationController::MaxPlaybackRate()
    {
        return impl::call_factory_cast<float(*)(IAnimationControllerStatics const&), AnimationController, IAnimationControllerStatics>([](IAnimationControllerStatics const& f) { return f.MaxPlaybackRate(); });
    }
    inline auto AnimationController::MinPlaybackRate()
    {
        return impl::call_factory_cast<float(*)(IAnimationControllerStatics const&), AnimationController, IAnimationControllerStatics>([](IAnimationControllerStatics const& f) { return f.MinPlaybackRate(); });
    }
    inline auto CompositionCapabilities::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::Composition::CompositionCapabilities(*)(ICompositionCapabilitiesStatics const&), CompositionCapabilities, ICompositionCapabilitiesStatics>([](ICompositionCapabilitiesStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto CompositionEasingFunction::CreateCubicBezierEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::Foundation::Numerics::float2 const& controlPoint1, llm::OS::Foundation::Numerics::float2 const& controlPoint2)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateCubicBezierEasingFunction(owner, controlPoint1, controlPoint2); });
    }
    inline auto CompositionEasingFunction::CreateLinearEasingFunction(llm::OS::UI::Composition::Compositor const& owner)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateLinearEasingFunction(owner); });
    }
    inline auto CompositionEasingFunction::CreateStepEasingFunction(llm::OS::UI::Composition::Compositor const& owner)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateStepEasingFunction(owner); });
    }
    inline auto CompositionEasingFunction::CreateStepEasingFunction(llm::OS::UI::Composition::Compositor const& owner, int32_t stepCount)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateStepEasingFunction(owner, stepCount); });
    }
    inline auto CompositionEasingFunction::CreateBackEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, float amplitude)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateBackEasingFunction(owner, mode, amplitude); });
    }
    inline auto CompositionEasingFunction::CreateBounceEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t bounces, float bounciness)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateBounceEasingFunction(owner, mode, bounces, bounciness); });
    }
    inline auto CompositionEasingFunction::CreateCircleEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateCircleEasingFunction(owner, mode); });
    }
    inline auto CompositionEasingFunction::CreateElasticEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t oscillations, float springiness)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateElasticEasingFunction(owner, mode, oscillations, springiness); });
    }
    inline auto CompositionEasingFunction::CreateExponentialEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, float exponent)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateExponentialEasingFunction(owner, mode, exponent); });
    }
    inline auto CompositionEasingFunction::CreatePowerEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode, float power)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreatePowerEasingFunction(owner, mode, power); });
    }
    inline auto CompositionEasingFunction::CreateSineEasingFunction(llm::OS::UI::Composition::Compositor const& owner, llm::OS::UI::Composition::CompositionEasingFunctionMode const& mode)
    {
        return impl::call_factory<CompositionEasingFunction, ICompositionEasingFunctionStatics>([&](ICompositionEasingFunctionStatics const& f) { return f.CreateSineEasingFunction(owner, mode); });
    }
    inline CompositionEffectSourceParameter::CompositionEffectSourceParameter(param::hstring const& name) :
        CompositionEffectSourceParameter(impl::call_factory<CompositionEffectSourceParameter, ICompositionEffectSourceParameterFactory>([&](ICompositionEffectSourceParameterFactory const& f) { return f.Create(name); }))
    {
    }
    inline auto CompositionObject::StartAnimationWithIAnimationObject(llm::OS::UI::Composition::IAnimationObject const& target, param::hstring const& propertyName, llm::OS::UI::Composition::CompositionAnimation const& animation)
    {
        impl::call_factory<CompositionObject, ICompositionObjectStatics>([&](ICompositionObjectStatics const& f) { return f.StartAnimationWithIAnimationObject(target, propertyName, animation); });
    }
    inline auto CompositionObject::StartAnimationGroupWithIAnimationObject(llm::OS::UI::Composition::IAnimationObject const& target, llm::OS::UI::Composition::ICompositionAnimationBase const& animation)
    {
        impl::call_factory<CompositionObject, ICompositionObjectStatics>([&](ICompositionObjectStatics const& f) { return f.StartAnimationGroupWithIAnimationObject(target, animation); });
    }
    inline CompositionPath::CompositionPath(llm::OS::Graphics::IGeometrySource2D const& source) :
        CompositionPath(impl::call_factory<CompositionPath, ICompositionPathFactory>([&](ICompositionPathFactory const& f) { return f.Create(source); }))
    {
    }
    inline auto CompositionProjectedShadowCasterCollection::MaxRespectedCasters()
    {
        return impl::call_factory_cast<int32_t(*)(ICompositionProjectedShadowCasterCollectionStatics const&), CompositionProjectedShadowCasterCollection, ICompositionProjectedShadowCasterCollectionStatics>([](ICompositionProjectedShadowCasterCollectionStatics const& f) { return f.MaxRespectedCasters(); });
    }
    inline Compositor::Compositor() :
        Compositor(impl::call_factory_cast<Compositor(*)(llm::OS::Foundation::IActivationFactory const&), Compositor>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<Compositor>(); }))
    {
    }
    inline auto Compositor::MaxGlobalPlaybackRate()
    {
        return impl::call_factory_cast<float(*)(ICompositorStatics const&), Compositor, ICompositorStatics>([](ICompositorStatics const& f) { return f.MaxGlobalPlaybackRate(); });
    }
    inline auto Compositor::MinGlobalPlaybackRate()
    {
        return impl::call_factory_cast<float(*)(ICompositorStatics const&), Compositor, ICompositorStatics>([](ICompositorStatics const& f) { return f.MinGlobalPlaybackRate(); });
    }
    inline auto DelegatedInkTrailVisual::Create(llm::OS::UI::Composition::Compositor const& compositor)
    {
        return impl::call_factory<DelegatedInkTrailVisual, IDelegatedInkTrailVisualStatics>([&](IDelegatedInkTrailVisualStatics const& f) { return f.Create(compositor); });
    }
    inline auto DelegatedInkTrailVisual::CreateForSwapChain(llm::OS::UI::Composition::Compositor const& compositor, llm::OS::UI::Composition::ICompositionSurface const& swapChain)
    {
        return impl::call_factory<DelegatedInkTrailVisual, IDelegatedInkTrailVisualStatics>([&](IDelegatedInkTrailVisualStatics const& f) { return f.CreateForSwapChain(compositor, swapChain); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Composition::IAmbientLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IAmbientLight2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IAnimationController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IAnimationControllerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IAnimationObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IAnimationPropertyInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IAnimationPropertyInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IBackEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IBooleanKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IBounceEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IBounceScalarNaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IBounceVector2NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IBounceVector3NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICircleEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IColorKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimation4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimationBase> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionAnimationGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionBackdropBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionBatchCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionBrushFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionCapabilitiesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionClip2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionClipFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionColorBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionColorGradientStop> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionColorGradientStopCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionCommitBatch> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionContainerShape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionDrawingSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionDrawingSurface2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionDrawingSurfaceFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEasingFunctionFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEasingFunctionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEffectBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEffectFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEffectSourceParameter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEffectSourceParameterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionEllipseGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGeometricClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGeometryFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGradientBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGradientBrush2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGradientBrushFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGraphicsDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGraphicsDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGraphicsDevice3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionGraphicsDevice4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionLight2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionLight3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionLightFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionLineGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionLinearGradientBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionMaskBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionMipmapSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionNineGridBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObject2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObject3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObject4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObject5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObjectFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionObjectStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionPath> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionPathFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionPathGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionProjectedShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionProjectedShadowCaster> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionProjectedShadowCasterCollectionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionProjectedShadowReceiver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionPropertySet> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionPropertySet2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionRadialGradientBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionRectangleGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionRoundedRectangleGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionScopedBatch> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionShadowFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionShape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionShapeFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSpriteShape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSupportsSystemBackdrop> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSurfaceBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSurfaceBrush2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSurfaceBrush3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionSurfaceFacade> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionTarget> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionTargetFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionTexture> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionTextureFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionTransform> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionTransformFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionViewBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionVirtualDrawingSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionVirtualDrawingSurfaceFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositionVisualSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor7> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositor8> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositorWithProjectedShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositorWithRadialGradient> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICompositorWithVisualSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IContainerVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IContainerVisualFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ICubicBezierEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IDelegatedInkTrailVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IDelegatedInkTrailVisualStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IDistantLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IDistantLight2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IDropShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IDropShadow2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IElasticEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IExponentialEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IExpressionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IImplicitAnimationCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IInsetClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IKeyFrameAnimation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IKeyFrameAnimation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IKeyFrameAnimationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ILayerVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ILayerVisual2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ILinearEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::INaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::INaturalMotionAnimationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IPathKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IPointLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IPointLight2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IPointLight3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IPowerEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IQuaternionKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IRectangleClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IRedirectVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IRenderingDeviceReplacedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IScalarKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IScalarNaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IScalarNaturalMotionAnimationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IShapeVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISineEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpotLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpotLight2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpotLight3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpringScalarNaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpringVector2NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpringVector3NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpriteVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ISpriteVisual2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IStepEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector2KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector2NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector2NaturalMotionAnimationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector3KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector3NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector3NaturalMotionAnimationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVector4KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisual2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisual3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisual4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisualCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisualElement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisualElement2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisualFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::IVisualUnorderedCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::AmbientLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::AnimationController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::AnimationPropertyInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::BackEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::BooleanKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::BounceEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::BounceScalarNaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::BounceVector2NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::BounceVector3NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CircleEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ColorKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionAnimationGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionBackdropBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionBatchCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionCapabilities> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionColorBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionColorGradientStop> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionColorGradientStopCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionCommitBatch> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionContainerShape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionDrawingSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionEffectBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionEffectFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionEffectSourceParameter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionEllipseGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionGeometricClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionGradientBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionGraphicsDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionLineGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionLinearGradientBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionMaskBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionMipmapSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionNineGridBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionObject> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionPath> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionPathGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionProjectedShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionProjectedShadowCaster> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionProjectedShadowCasterCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionProjectedShadowReceiver> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionProjectedShadowReceiverUnorderedCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionPropertySet> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionRadialGradientBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionRectangleGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionRoundedRectangleGeometry> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionScopedBatch> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionShape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionShapeCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionSpriteShape> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionStrokeDashArray> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionSurfaceBrush> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionTarget> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionTexture> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionTransform> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionViewBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionVirtualDrawingSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CompositionVisualSurface> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Compositor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ContainerVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::CubicBezierEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::DelegatedInkTrailVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::DistantLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::DropShadow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ElasticEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ExponentialEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ExpressionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ImplicitAnimationCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::InitialValueExpressionCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::InsetClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::LayerVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::LinearEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::PathKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::PointLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::PowerEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::QuaternionKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::RectangleClip> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::RedirectVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::RenderingDeviceReplacedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ScalarKeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ScalarNaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::ShapeVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::SineEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::SpotLight> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::SpringScalarNaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::SpringVector2NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::SpringVector3NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::SpriteVisual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::StepEasingFunction> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Vector2KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Vector2NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Vector3KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Vector3NaturalMotionAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Vector4KeyFrameAnimation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::Visual> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::VisualCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Composition::VisualUnorderedCollection> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
