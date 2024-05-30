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
#ifndef LLM_OS_UI_Composition_2_H
#define LLM_OS_UI_Composition_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.Graphics.2.h"
#include "llm/impl/Windows.Graphics.Effects.2.h"
#include "llm/impl/Windows.UI.Composition.1.h"
LLM_EXPORT namespace llm:OS::UI::Composition
{
    struct InkTrailPoint
    {
        llm:OS::Foundation::Point Point;
        float Radius;
    };
    inline bool operator==(InkTrailPoint const& left, InkTrailPoint const& right) noexcept
    {
        return left.Point == right.Point && left.Radius == right.Radius;
    }
    inline bool operator!=(InkTrailPoint const& left, InkTrailPoint const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AmbientLight : llm:OS::UI::Composition::IAmbientLight,
        impl::base<AmbientLight, llm:OS::UI::Composition::CompositionLight, llm:OS::UI::Composition::CompositionObject>,
        impl::require<AmbientLight, llm:OS::UI::Composition::IAmbientLight2, llm:OS::UI::Composition::ICompositionLight, llm:OS::UI::Composition::ICompositionLight2, llm:OS::UI::Composition::ICompositionLight3, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        AmbientLight(std::nullptr_t) noexcept {}
        AmbientLight(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IAmbientLight(ptr, take_ownership_from_abi) {}
        using impl::consume_t<AmbientLight, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<AmbientLight, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) AnimationController : llm:OS::UI::Composition::IAnimationController,
        impl::base<AnimationController, llm:OS::UI::Composition::CompositionObject>,
        impl::require<AnimationController, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        AnimationController(std::nullptr_t) noexcept {}
        AnimationController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IAnimationController(ptr, take_ownership_from_abi) {}
        using impl::consume_t<AnimationController, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<AnimationController, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        [[nodiscard]] static auto MaxPlaybackRate();
        [[nodiscard]] static auto MinPlaybackRate();
    };
    struct __declspec(empty_bases) AnimationPropertyInfo : llm:OS::UI::Composition::IAnimationPropertyInfo,
        impl::base<AnimationPropertyInfo, llm:OS::UI::Composition::CompositionObject>,
        impl::require<AnimationPropertyInfo, llm:OS::UI::Composition::IAnimationPropertyInfo2, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        AnimationPropertyInfo(std::nullptr_t) noexcept {}
        AnimationPropertyInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IAnimationPropertyInfo(ptr, take_ownership_from_abi) {}
        using impl::consume_t<AnimationPropertyInfo, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<AnimationPropertyInfo, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) BackEasingFunction : llm:OS::UI::Composition::IBackEasingFunction,
        impl::base<BackEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<BackEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        BackEasingFunction(std::nullptr_t) noexcept {}
        BackEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IBackEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<BackEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<BackEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) BooleanKeyFrameAnimation : llm:OS::UI::Composition::IBooleanKeyFrameAnimation,
        impl::base<BooleanKeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<BooleanKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        BooleanKeyFrameAnimation(std::nullptr_t) noexcept {}
        BooleanKeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IBooleanKeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<BooleanKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<BooleanKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) BounceEasingFunction : llm:OS::UI::Composition::IBounceEasingFunction,
        impl::base<BounceEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<BounceEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        BounceEasingFunction(std::nullptr_t) noexcept {}
        BounceEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IBounceEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<BounceEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<BounceEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) BounceScalarNaturalMotionAnimation : llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation,
        impl::base<BounceScalarNaturalMotionAnimation, llm:OS::UI::Composition::ScalarNaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<BounceScalarNaturalMotionAnimation, llm:OS::UI::Composition::IScalarNaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        BounceScalarNaturalMotionAnimation(std::nullptr_t) noexcept {}
        BounceScalarNaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IBounceScalarNaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<BounceScalarNaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<BounceScalarNaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) BounceVector2NaturalMotionAnimation : llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation,
        impl::base<BounceVector2NaturalMotionAnimation, llm:OS::UI::Composition::Vector2NaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<BounceVector2NaturalMotionAnimation, llm:OS::UI::Composition::IVector2NaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        BounceVector2NaturalMotionAnimation(std::nullptr_t) noexcept {}
        BounceVector2NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IBounceVector2NaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<BounceVector2NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<BounceVector2NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) BounceVector3NaturalMotionAnimation : llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation,
        impl::base<BounceVector3NaturalMotionAnimation, llm:OS::UI::Composition::Vector3NaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<BounceVector3NaturalMotionAnimation, llm:OS::UI::Composition::IVector3NaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        BounceVector3NaturalMotionAnimation(std::nullptr_t) noexcept {}
        BounceVector3NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IBounceVector3NaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<BounceVector3NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<BounceVector3NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CircleEasingFunction : llm:OS::UI::Composition::ICircleEasingFunction,
        impl::base<CircleEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CircleEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CircleEasingFunction(std::nullptr_t) noexcept {}
        CircleEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICircleEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CircleEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CircleEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ColorKeyFrameAnimation : llm:OS::UI::Composition::IColorKeyFrameAnimation,
        impl::base<ColorKeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ColorKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ColorKeyFrameAnimation(std::nullptr_t) noexcept {}
        ColorKeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IColorKeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ColorKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ColorKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionAnimation : llm:OS::UI::Composition::ICompositionAnimation,
        impl::base<CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionAnimation(std::nullptr_t) noexcept {}
        CompositionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionAnimationGroup : llm:OS::UI::Composition::ICompositionAnimationGroup,
        impl::base<CompositionAnimationGroup, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionAnimationGroup, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::CompositionAnimation>, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionAnimationGroup(std::nullptr_t) noexcept {}
        CompositionAnimationGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionAnimationGroup(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionAnimationGroup, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionAnimationGroup, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionBackdropBrush : llm:OS::UI::Composition::ICompositionBackdropBrush,
        impl::base<CompositionBackdropBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionBackdropBrush, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionBackdropBrush(std::nullptr_t) noexcept {}
        CompositionBackdropBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionBackdropBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionBackdropBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionBackdropBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionBatchCompletedEventArgs : llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs,
        impl::base<CompositionBatchCompletedEventArgs, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionBatchCompletedEventArgs, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionBatchCompletedEventArgs(std::nullptr_t) noexcept {}
        CompositionBatchCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionBatchCompletedEventArgs(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionBatchCompletedEventArgs, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionBatchCompletedEventArgs, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionBrush : llm:OS::UI::Composition::ICompositionBrush,
        impl::base<CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionBrush(std::nullptr_t) noexcept {}
        CompositionBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionCapabilities : llm:OS::UI::Composition::ICompositionCapabilities
    {
        CompositionCapabilities(std::nullptr_t) noexcept {}
        CompositionCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionCapabilities(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) CompositionClip : llm:OS::UI::Composition::ICompositionClip,
        impl::base<CompositionClip, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionClip, llm:OS::UI::Composition::ICompositionClip2, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionClip(std::nullptr_t) noexcept {}
        CompositionClip(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionClip(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionClip, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionClip, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionColorBrush : llm:OS::UI::Composition::ICompositionColorBrush,
        impl::base<CompositionColorBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionColorBrush, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionColorBrush(std::nullptr_t) noexcept {}
        CompositionColorBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionColorBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionColorBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionColorBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionColorGradientStop : llm:OS::UI::Composition::ICompositionColorGradientStop,
        impl::base<CompositionColorGradientStop, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionColorGradientStop, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionColorGradientStop(std::nullptr_t) noexcept {}
        CompositionColorGradientStop(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionColorGradientStop(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionColorGradientStop, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionColorGradientStop, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionColorGradientStopCollection : llm:OS::UI::Composition::ICompositionColorGradientStopCollection,
        impl::require<CompositionColorGradientStopCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::CompositionColorGradientStop>, llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::CompositionColorGradientStop>>
    {
        CompositionColorGradientStopCollection(std::nullptr_t) noexcept {}
        CompositionColorGradientStopCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionColorGradientStopCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CompositionCommitBatch : llm:OS::UI::Composition::ICompositionCommitBatch,
        impl::base<CompositionCommitBatch, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionCommitBatch, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionCommitBatch(std::nullptr_t) noexcept {}
        CompositionCommitBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionCommitBatch(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionCommitBatch, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionCommitBatch, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionContainerShape : llm:OS::UI::Composition::ICompositionContainerShape,
        impl::base<CompositionContainerShape, llm:OS::UI::Composition::CompositionShape, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionContainerShape, llm:OS::UI::Composition::ICompositionShape, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionContainerShape(std::nullptr_t) noexcept {}
        CompositionContainerShape(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionContainerShape(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionContainerShape, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionContainerShape, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionDrawingSurface : llm:OS::UI::Composition::ICompositionDrawingSurface,
        impl::base<CompositionDrawingSurface, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionDrawingSurface, llm:OS::UI::Composition::ICompositionDrawingSurface2, llm:OS::UI::Composition::ICompositionSurface, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionDrawingSurface(std::nullptr_t) noexcept {}
        CompositionDrawingSurface(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionDrawingSurface(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionDrawingSurface, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionDrawingSurface, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionEasingFunction : llm:OS::UI::Composition::ICompositionEasingFunction,
        impl::base<CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionEasingFunction(std::nullptr_t) noexcept {}
        CompositionEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto CreateCubicBezierEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::Foundation::Numerics::float2 const& controlPoint1, llm:OS::Foundation::Numerics::float2 const& controlPoint2);
        static auto CreateLinearEasingFunction(llm:OS::UI::Composition::Compositor const& owner);
        static auto CreateStepEasingFunction(llm:OS::UI::Composition::Compositor const& owner);
        static auto CreateStepEasingFunction(llm:OS::UI::Composition::Compositor const& owner, int32_t stepCount);
        static auto CreateBackEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, float amplitude);
        static auto CreateBounceEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t bounces, float bounciness);
        static auto CreateCircleEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode);
        static auto CreateElasticEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, int32_t oscillations, float springiness);
        static auto CreateExponentialEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, float exponent);
        static auto CreatePowerEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode, float power);
        static auto CreateSineEasingFunction(llm:OS::UI::Composition::Compositor const& owner, llm:OS::UI::Composition::CompositionEasingFunctionMode const& mode);
    };
    struct __declspec(empty_bases) CompositionEffectBrush : llm:OS::UI::Composition::ICompositionEffectBrush,
        impl::base<CompositionEffectBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionEffectBrush, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionEffectBrush(std::nullptr_t) noexcept {}
        CompositionEffectBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionEffectBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionEffectBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionEffectBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionEffectFactory : llm:OS::UI::Composition::ICompositionEffectFactory,
        impl::base<CompositionEffectFactory, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionEffectFactory, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionEffectFactory(std::nullptr_t) noexcept {}
        CompositionEffectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionEffectFactory(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionEffectFactory, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionEffectFactory, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionEffectSourceParameter : llm:OS::UI::Composition::ICompositionEffectSourceParameter,
        impl::require<CompositionEffectSourceParameter, llm:OS::Graphics::Effects::IGraphicsEffectSource>
    {
        CompositionEffectSourceParameter(std::nullptr_t) noexcept {}
        CompositionEffectSourceParameter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionEffectSourceParameter(ptr, take_ownership_from_abi) {}
        explicit CompositionEffectSourceParameter(param::hstring const& name);
    };
    struct __declspec(empty_bases) CompositionEllipseGeometry : llm:OS::UI::Composition::ICompositionEllipseGeometry,
        impl::base<CompositionEllipseGeometry, llm:OS::UI::Composition::CompositionGeometry, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionEllipseGeometry, llm:OS::UI::Composition::ICompositionGeometry, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionEllipseGeometry(std::nullptr_t) noexcept {}
        CompositionEllipseGeometry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionEllipseGeometry(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionEllipseGeometry, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionEllipseGeometry, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionGeometricClip : llm:OS::UI::Composition::ICompositionGeometricClip,
        impl::base<CompositionGeometricClip, llm:OS::UI::Composition::CompositionClip, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionGeometricClip, llm:OS::UI::Composition::ICompositionClip, llm:OS::UI::Composition::ICompositionClip2, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionGeometricClip(std::nullptr_t) noexcept {}
        CompositionGeometricClip(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionGeometricClip(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionGeometricClip, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionGeometricClip, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionGeometry : llm:OS::UI::Composition::ICompositionGeometry,
        impl::base<CompositionGeometry, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionGeometry, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionGeometry(std::nullptr_t) noexcept {}
        CompositionGeometry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionGeometry(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionGeometry, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionGeometry, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionGradientBrush : llm:OS::UI::Composition::ICompositionGradientBrush,
        impl::base<CompositionGradientBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionGradientBrush, llm:OS::UI::Composition::ICompositionGradientBrush2, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionGradientBrush(std::nullptr_t) noexcept {}
        CompositionGradientBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionGradientBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionGradientBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionGradientBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionGraphicsDevice : llm:OS::UI::Composition::ICompositionGraphicsDevice,
        impl::base<CompositionGraphicsDevice, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionGraphicsDevice, llm:OS::UI::Composition::ICompositionGraphicsDevice2, llm:OS::UI::Composition::ICompositionGraphicsDevice3, llm:OS::UI::Composition::ICompositionGraphicsDevice4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionGraphicsDevice(std::nullptr_t) noexcept {}
        CompositionGraphicsDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionGraphicsDevice(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionGraphicsDevice, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionGraphicsDevice, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionLight : llm:OS::UI::Composition::ICompositionLight,
        impl::base<CompositionLight, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionLight, llm:OS::UI::Composition::ICompositionLight2, llm:OS::UI::Composition::ICompositionLight3, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionLight(std::nullptr_t) noexcept {}
        CompositionLight(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionLight(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionLight, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionLight, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionLineGeometry : llm:OS::UI::Composition::ICompositionLineGeometry,
        impl::base<CompositionLineGeometry, llm:OS::UI::Composition::CompositionGeometry, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionLineGeometry, llm:OS::UI::Composition::ICompositionGeometry, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionLineGeometry(std::nullptr_t) noexcept {}
        CompositionLineGeometry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionLineGeometry(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionLineGeometry, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionLineGeometry, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionLinearGradientBrush : llm:OS::UI::Composition::ICompositionLinearGradientBrush,
        impl::base<CompositionLinearGradientBrush, llm:OS::UI::Composition::CompositionGradientBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionLinearGradientBrush, llm:OS::UI::Composition::ICompositionGradientBrush, llm:OS::UI::Composition::ICompositionGradientBrush2, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionLinearGradientBrush(std::nullptr_t) noexcept {}
        CompositionLinearGradientBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionLinearGradientBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionLinearGradientBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionLinearGradientBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionMaskBrush : llm:OS::UI::Composition::ICompositionMaskBrush,
        impl::base<CompositionMaskBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionMaskBrush, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionMaskBrush(std::nullptr_t) noexcept {}
        CompositionMaskBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionMaskBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionMaskBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionMaskBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionMipmapSurface : llm:OS::UI::Composition::ICompositionMipmapSurface,
        impl::base<CompositionMipmapSurface, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionMipmapSurface, llm:OS::UI::Composition::ICompositionSurface, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionMipmapSurface(std::nullptr_t) noexcept {}
        CompositionMipmapSurface(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionMipmapSurface(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionMipmapSurface, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionMipmapSurface, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionNineGridBrush : llm:OS::UI::Composition::ICompositionNineGridBrush,
        impl::base<CompositionNineGridBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionNineGridBrush, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionNineGridBrush(std::nullptr_t) noexcept {}
        CompositionNineGridBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionNineGridBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionNineGridBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionNineGridBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionObject : llm:OS::UI::Composition::ICompositionObject,
        impl::require<CompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionObject(std::nullptr_t) noexcept {}
        CompositionObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionObject(ptr, take_ownership_from_abi) {}
        using llm:OS::UI::Composition::ICompositionObject::StartAnimation;
        using impl::consume_t<CompositionObject, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto StartAnimationWithIAnimationObject(llm:OS::UI::Composition::IAnimationObject const& target, param::hstring const& propertyName, llm:OS::UI::Composition::CompositionAnimation const& animation);
        static auto StartAnimationGroupWithIAnimationObject(llm:OS::UI::Composition::IAnimationObject const& target, llm:OS::UI::Composition::ICompositionAnimationBase const& animation);
    };
    struct __declspec(empty_bases) CompositionPath : llm:OS::UI::Composition::ICompositionPath,
        impl::require<CompositionPath, llm:OS::Graphics::IGeometrySource2D>
    {
        CompositionPath(std::nullptr_t) noexcept {}
        CompositionPath(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionPath(ptr, take_ownership_from_abi) {}
        explicit CompositionPath(llm:OS::Graphics::IGeometrySource2D const& source);
    };
    struct __declspec(empty_bases) CompositionPathGeometry : llm:OS::UI::Composition::ICompositionPathGeometry,
        impl::base<CompositionPathGeometry, llm:OS::UI::Composition::CompositionGeometry, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionPathGeometry, llm:OS::UI::Composition::ICompositionGeometry, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionPathGeometry(std::nullptr_t) noexcept {}
        CompositionPathGeometry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionPathGeometry(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionPathGeometry, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionPathGeometry, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionProjectedShadow : llm:OS::UI::Composition::ICompositionProjectedShadow,
        impl::base<CompositionProjectedShadow, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionProjectedShadow, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionProjectedShadow(std::nullptr_t) noexcept {}
        CompositionProjectedShadow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionProjectedShadow(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionProjectedShadow, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionProjectedShadow, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionProjectedShadowCaster : llm:OS::UI::Composition::ICompositionProjectedShadowCaster,
        impl::base<CompositionProjectedShadowCaster, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionProjectedShadowCaster, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionProjectedShadowCaster(std::nullptr_t) noexcept {}
        CompositionProjectedShadowCaster(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionProjectedShadowCaster(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionProjectedShadowCaster, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionProjectedShadowCaster, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionProjectedShadowCasterCollection : llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection,
        impl::base<CompositionProjectedShadowCasterCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionProjectedShadowCasterCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::CompositionProjectedShadowCaster>, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionProjectedShadowCasterCollection(std::nullptr_t) noexcept {}
        CompositionProjectedShadowCasterCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionProjectedShadowCasterCollection(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionProjectedShadowCasterCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionProjectedShadowCasterCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        [[nodiscard]] static auto MaxRespectedCasters();
    };
    struct __declspec(empty_bases) CompositionProjectedShadowReceiver : llm:OS::UI::Composition::ICompositionProjectedShadowReceiver,
        impl::base<CompositionProjectedShadowReceiver, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionProjectedShadowReceiver, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionProjectedShadowReceiver(std::nullptr_t) noexcept {}
        CompositionProjectedShadowReceiver(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionProjectedShadowReceiver(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionProjectedShadowReceiver, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionProjectedShadowReceiver, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionProjectedShadowReceiverUnorderedCollection : llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection,
        impl::base<CompositionProjectedShadowReceiverUnorderedCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionProjectedShadowReceiverUnorderedCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::CompositionProjectedShadowReceiver>, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionProjectedShadowReceiverUnorderedCollection(std::nullptr_t) noexcept {}
        CompositionProjectedShadowReceiverUnorderedCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionProjectedShadowReceiverUnorderedCollection(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionProjectedShadowReceiverUnorderedCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionProjectedShadowReceiverUnorderedCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionPropertySet : llm:OS::UI::Composition::ICompositionPropertySet,
        impl::base<CompositionPropertySet, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionPropertySet, llm:OS::UI::Composition::ICompositionPropertySet2, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionPropertySet(std::nullptr_t) noexcept {}
        CompositionPropertySet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionPropertySet(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionPropertySet, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionPropertySet, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionRadialGradientBrush : llm:OS::UI::Composition::ICompositionRadialGradientBrush,
        impl::base<CompositionRadialGradientBrush, llm:OS::UI::Composition::CompositionGradientBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionRadialGradientBrush, llm:OS::UI::Composition::ICompositionGradientBrush, llm:OS::UI::Composition::ICompositionGradientBrush2, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionRadialGradientBrush(std::nullptr_t) noexcept {}
        CompositionRadialGradientBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionRadialGradientBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionRadialGradientBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionRadialGradientBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionRectangleGeometry : llm:OS::UI::Composition::ICompositionRectangleGeometry,
        impl::base<CompositionRectangleGeometry, llm:OS::UI::Composition::CompositionGeometry, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionRectangleGeometry, llm:OS::UI::Composition::ICompositionGeometry, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionRectangleGeometry(std::nullptr_t) noexcept {}
        CompositionRectangleGeometry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionRectangleGeometry(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionRectangleGeometry, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionRectangleGeometry, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionRoundedRectangleGeometry : llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry,
        impl::base<CompositionRoundedRectangleGeometry, llm:OS::UI::Composition::CompositionGeometry, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionRoundedRectangleGeometry, llm:OS::UI::Composition::ICompositionGeometry, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionRoundedRectangleGeometry(std::nullptr_t) noexcept {}
        CompositionRoundedRectangleGeometry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionRoundedRectangleGeometry(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionRoundedRectangleGeometry, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionRoundedRectangleGeometry, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionScopedBatch : llm:OS::UI::Composition::ICompositionScopedBatch,
        impl::base<CompositionScopedBatch, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionScopedBatch, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionScopedBatch(std::nullptr_t) noexcept {}
        CompositionScopedBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionScopedBatch(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionScopedBatch, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionScopedBatch, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionShadow : llm:OS::UI::Composition::ICompositionShadow,
        impl::base<CompositionShadow, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionShadow, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionShadow(std::nullptr_t) noexcept {}
        CompositionShadow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionShadow(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionShadow, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionShadow, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionShape : llm:OS::UI::Composition::ICompositionShape,
        impl::base<CompositionShape, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionShape, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionShape(std::nullptr_t) noexcept {}
        CompositionShape(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionShape(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionShape, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionShape, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionShapeCollection : llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::CompositionShape>,
        impl::base<CompositionShapeCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionShapeCollection, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionShapeCollection(std::nullptr_t) noexcept {}
        CompositionShapeCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVector<llm:OS::UI::Composition::CompositionShape>(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionShapeCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionShapeCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionSpriteShape : llm:OS::UI::Composition::ICompositionSpriteShape,
        impl::base<CompositionSpriteShape, llm:OS::UI::Composition::CompositionShape, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionSpriteShape, llm:OS::UI::Composition::ICompositionShape, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionSpriteShape(std::nullptr_t) noexcept {}
        CompositionSpriteShape(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionSpriteShape(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionSpriteShape, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionSpriteShape, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionStrokeDashArray : llm:OS::Foundation::Collections::IVector<float>,
        impl::base<CompositionStrokeDashArray, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionStrokeDashArray, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionStrokeDashArray(std::nullptr_t) noexcept {}
        CompositionStrokeDashArray(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVector<float>(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionStrokeDashArray, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionStrokeDashArray, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionSurfaceBrush : llm:OS::UI::Composition::ICompositionSurfaceBrush,
        impl::base<CompositionSurfaceBrush, llm:OS::UI::Composition::CompositionBrush, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionSurfaceBrush, llm:OS::UI::Composition::ICompositionSurfaceBrush2, llm:OS::UI::Composition::ICompositionSurfaceBrush3, llm:OS::UI::Composition::ICompositionBrush, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionSurfaceBrush(std::nullptr_t) noexcept {}
        CompositionSurfaceBrush(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionSurfaceBrush(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionSurfaceBrush, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionSurfaceBrush, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionTarget : llm:OS::UI::Composition::ICompositionTarget,
        impl::base<CompositionTarget, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionTarget, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionTarget(std::nullptr_t) noexcept {}
        CompositionTarget(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionTarget(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionTarget, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionTarget, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionTexture : llm:OS::UI::Composition::ICompositionTexture,
        impl::base<CompositionTexture, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionTexture, llm:OS::UI::Composition::ICompositionSurface, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionTexture(std::nullptr_t) noexcept {}
        CompositionTexture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionTexture(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionTexture, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionTexture, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionTransform : llm:OS::UI::Composition::ICompositionTransform,
        impl::base<CompositionTransform, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionTransform, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionTransform(std::nullptr_t) noexcept {}
        CompositionTransform(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionTransform(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionTransform, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionTransform, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionViewBox : llm:OS::UI::Composition::ICompositionViewBox,
        impl::base<CompositionViewBox, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionViewBox, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionViewBox(std::nullptr_t) noexcept {}
        CompositionViewBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionViewBox(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionViewBox, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionViewBox, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionVirtualDrawingSurface : llm:OS::UI::Composition::ICompositionVirtualDrawingSurface,
        impl::base<CompositionVirtualDrawingSurface, llm:OS::UI::Composition::CompositionDrawingSurface, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionVirtualDrawingSurface, llm:OS::UI::Composition::ICompositionDrawingSurface, llm:OS::UI::Composition::ICompositionDrawingSurface2, llm:OS::UI::Composition::ICompositionSurface, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionVirtualDrawingSurface(std::nullptr_t) noexcept {}
        CompositionVirtualDrawingSurface(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionVirtualDrawingSurface(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionVirtualDrawingSurface, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionVirtualDrawingSurface, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CompositionVisualSurface : llm:OS::UI::Composition::ICompositionVisualSurface,
        impl::base<CompositionVisualSurface, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionVisualSurface, llm:OS::UI::Composition::ICompositionSurface, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionVisualSurface(std::nullptr_t) noexcept {}
        CompositionVisualSurface(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositionVisualSurface(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionVisualSurface, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionVisualSurface, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Compositor : llm:OS::UI::Composition::ICompositor,
        impl::require<Compositor, llm:OS::UI::Composition::ICompositor2, llm:OS::UI::Composition::ICompositor3, llm:OS::UI::Composition::ICompositor4, llm:OS::UI::Composition::ICompositor5, llm:OS::UI::Composition::ICompositor6, llm:OS::UI::Composition::ICompositorWithProjectedShadow, llm:OS::UI::Composition::ICompositorWithRadialGradient, llm:OS::UI::Composition::ICompositorWithVisualSurface, llm:OS::UI::Composition::ICompositor7, llm:OS::UI::Composition::ICompositorWithBlurredWallpaperBackdropBrush, llm:OS::UI::Composition::ICompositor8, llm:OS::Foundation::IClosable>
    {
        Compositor(std::nullptr_t) noexcept {}
        Compositor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICompositor(ptr, take_ownership_from_abi) {}
        Compositor();
        [[nodiscard]] static auto MaxGlobalPlaybackRate();
        [[nodiscard]] static auto MinGlobalPlaybackRate();
    };
    struct __declspec(empty_bases) ContainerVisual : llm:OS::UI::Composition::IContainerVisual,
        impl::base<ContainerVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ContainerVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ContainerVisual(std::nullptr_t) noexcept {}
        ContainerVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IContainerVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ContainerVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ContainerVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) CubicBezierEasingFunction : llm:OS::UI::Composition::ICubicBezierEasingFunction,
        impl::base<CubicBezierEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CubicBezierEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CubicBezierEasingFunction(std::nullptr_t) noexcept {}
        CubicBezierEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ICubicBezierEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CubicBezierEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CubicBezierEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) DelegatedInkTrailVisual : llm:OS::UI::Composition::IDelegatedInkTrailVisual,
        impl::base<DelegatedInkTrailVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<DelegatedInkTrailVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        DelegatedInkTrailVisual(std::nullptr_t) noexcept {}
        DelegatedInkTrailVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IDelegatedInkTrailVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<DelegatedInkTrailVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<DelegatedInkTrailVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
        static auto CreateForSwapChain(llm:OS::UI::Composition::Compositor const& compositor, llm:OS::UI::Composition::ICompositionSurface const& swapChain);
    };
    struct __declspec(empty_bases) DistantLight : llm:OS::UI::Composition::IDistantLight,
        impl::base<DistantLight, llm:OS::UI::Composition::CompositionLight, llm:OS::UI::Composition::CompositionObject>,
        impl::require<DistantLight, llm:OS::UI::Composition::IDistantLight2, llm:OS::UI::Composition::ICompositionLight, llm:OS::UI::Composition::ICompositionLight2, llm:OS::UI::Composition::ICompositionLight3, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        DistantLight(std::nullptr_t) noexcept {}
        DistantLight(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IDistantLight(ptr, take_ownership_from_abi) {}
        using impl::consume_t<DistantLight, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<DistantLight, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) DropShadow : llm:OS::UI::Composition::IDropShadow,
        impl::base<DropShadow, llm:OS::UI::Composition::CompositionShadow, llm:OS::UI::Composition::CompositionObject>,
        impl::require<DropShadow, llm:OS::UI::Composition::IDropShadow2, llm:OS::UI::Composition::ICompositionShadow, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        DropShadow(std::nullptr_t) noexcept {}
        DropShadow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IDropShadow(ptr, take_ownership_from_abi) {}
        using impl::consume_t<DropShadow, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<DropShadow, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ElasticEasingFunction : llm:OS::UI::Composition::IElasticEasingFunction,
        impl::base<ElasticEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ElasticEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ElasticEasingFunction(std::nullptr_t) noexcept {}
        ElasticEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IElasticEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ElasticEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ElasticEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ExponentialEasingFunction : llm:OS::UI::Composition::IExponentialEasingFunction,
        impl::base<ExponentialEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ExponentialEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ExponentialEasingFunction(std::nullptr_t) noexcept {}
        ExponentialEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IExponentialEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ExponentialEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ExponentialEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ExpressionAnimation : llm:OS::UI::Composition::IExpressionAnimation,
        impl::base<ExpressionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ExpressionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ExpressionAnimation(std::nullptr_t) noexcept {}
        ExpressionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IExpressionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ExpressionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ExpressionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ImplicitAnimationCollection : llm:OS::UI::Composition::IImplicitAnimationCollection,
        impl::base<ImplicitAnimationCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ImplicitAnimationCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, llm:OS::UI::Composition::ICompositionAnimationBase>>, llm:OS::Foundation::Collections::IMap<hstring, llm:OS::UI::Composition::ICompositionAnimationBase>, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ImplicitAnimationCollection(std::nullptr_t) noexcept {}
        ImplicitAnimationCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IImplicitAnimationCollection(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ImplicitAnimationCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ImplicitAnimationCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) InitialValueExpressionCollection : llm:OS::Foundation::Collections::IMap<hstring, hstring>,
        impl::base<InitialValueExpressionCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InitialValueExpressionCollection, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InitialValueExpressionCollection(std::nullptr_t) noexcept {}
        InitialValueExpressionCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IMap<hstring, hstring>(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InitialValueExpressionCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InitialValueExpressionCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) InsetClip : llm:OS::UI::Composition::IInsetClip,
        impl::base<InsetClip, llm:OS::UI::Composition::CompositionClip, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InsetClip, llm:OS::UI::Composition::ICompositionClip, llm:OS::UI::Composition::ICompositionClip2, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InsetClip(std::nullptr_t) noexcept {}
        InsetClip(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IInsetClip(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InsetClip, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InsetClip, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) KeyFrameAnimation : llm:OS::UI::Composition::IKeyFrameAnimation,
        impl::base<KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<KeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        KeyFrameAnimation(std::nullptr_t) noexcept {}
        KeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IKeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) LayerVisual : llm:OS::UI::Composition::ILayerVisual,
        impl::base<LayerVisual, llm:OS::UI::Composition::ContainerVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<LayerVisual, llm:OS::UI::Composition::ILayerVisual2, llm:OS::UI::Composition::IContainerVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        LayerVisual(std::nullptr_t) noexcept {}
        LayerVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ILayerVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<LayerVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<LayerVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) LinearEasingFunction : llm:OS::UI::Composition::ILinearEasingFunction,
        impl::base<LinearEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<LinearEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        LinearEasingFunction(std::nullptr_t) noexcept {}
        LinearEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ILinearEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<LinearEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<LinearEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) NaturalMotionAnimation : llm:OS::UI::Composition::INaturalMotionAnimation,
        impl::base<NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        NaturalMotionAnimation(std::nullptr_t) noexcept {}
        NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::INaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) PathKeyFrameAnimation : llm:OS::UI::Composition::IPathKeyFrameAnimation,
        impl::base<PathKeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<PathKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        PathKeyFrameAnimation(std::nullptr_t) noexcept {}
        PathKeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IPathKeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<PathKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<PathKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) PointLight : llm:OS::UI::Composition::IPointLight,
        impl::base<PointLight, llm:OS::UI::Composition::CompositionLight, llm:OS::UI::Composition::CompositionObject>,
        impl::require<PointLight, llm:OS::UI::Composition::IPointLight2, llm:OS::UI::Composition::IPointLight3, llm:OS::UI::Composition::ICompositionLight, llm:OS::UI::Composition::ICompositionLight2, llm:OS::UI::Composition::ICompositionLight3, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        PointLight(std::nullptr_t) noexcept {}
        PointLight(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IPointLight(ptr, take_ownership_from_abi) {}
        using impl::consume_t<PointLight, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<PointLight, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) PowerEasingFunction : llm:OS::UI::Composition::IPowerEasingFunction,
        impl::base<PowerEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<PowerEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        PowerEasingFunction(std::nullptr_t) noexcept {}
        PowerEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IPowerEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<PowerEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<PowerEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) QuaternionKeyFrameAnimation : llm:OS::UI::Composition::IQuaternionKeyFrameAnimation,
        impl::base<QuaternionKeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<QuaternionKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        QuaternionKeyFrameAnimation(std::nullptr_t) noexcept {}
        QuaternionKeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IQuaternionKeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<QuaternionKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<QuaternionKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) RectangleClip : llm:OS::UI::Composition::IRectangleClip,
        impl::base<RectangleClip, llm:OS::UI::Composition::CompositionClip, llm:OS::UI::Composition::CompositionObject>,
        impl::require<RectangleClip, llm:OS::UI::Composition::ICompositionClip, llm:OS::UI::Composition::ICompositionClip2, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        RectangleClip(std::nullptr_t) noexcept {}
        RectangleClip(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IRectangleClip(ptr, take_ownership_from_abi) {}
        using impl::consume_t<RectangleClip, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<RectangleClip, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) RedirectVisual : llm:OS::UI::Composition::IRedirectVisual,
        impl::base<RedirectVisual, llm:OS::UI::Composition::ContainerVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<RedirectVisual, llm:OS::UI::Composition::IContainerVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        RedirectVisual(std::nullptr_t) noexcept {}
        RedirectVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IRedirectVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<RedirectVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<RedirectVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) RenderingDeviceReplacedEventArgs : llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs,
        impl::base<RenderingDeviceReplacedEventArgs, llm:OS::UI::Composition::CompositionObject>,
        impl::require<RenderingDeviceReplacedEventArgs, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        RenderingDeviceReplacedEventArgs(std::nullptr_t) noexcept {}
        RenderingDeviceReplacedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IRenderingDeviceReplacedEventArgs(ptr, take_ownership_from_abi) {}
        using impl::consume_t<RenderingDeviceReplacedEventArgs, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<RenderingDeviceReplacedEventArgs, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ScalarKeyFrameAnimation : llm:OS::UI::Composition::IScalarKeyFrameAnimation,
        impl::base<ScalarKeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ScalarKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ScalarKeyFrameAnimation(std::nullptr_t) noexcept {}
        ScalarKeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IScalarKeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ScalarKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ScalarKeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ScalarNaturalMotionAnimation : llm:OS::UI::Composition::IScalarNaturalMotionAnimation,
        impl::base<ScalarNaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ScalarNaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ScalarNaturalMotionAnimation(std::nullptr_t) noexcept {}
        ScalarNaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IScalarNaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ScalarNaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ScalarNaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) ShapeVisual : llm:OS::UI::Composition::IShapeVisual,
        impl::base<ShapeVisual, llm:OS::UI::Composition::ContainerVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<ShapeVisual, llm:OS::UI::Composition::IContainerVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        ShapeVisual(std::nullptr_t) noexcept {}
        ShapeVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IShapeVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<ShapeVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<ShapeVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SineEasingFunction : llm:OS::UI::Composition::ISineEasingFunction,
        impl::base<SineEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SineEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SineEasingFunction(std::nullptr_t) noexcept {}
        SineEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ISineEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SineEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SineEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SpotLight : llm:OS::UI::Composition::ISpotLight,
        impl::base<SpotLight, llm:OS::UI::Composition::CompositionLight, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SpotLight, llm:OS::UI::Composition::ISpotLight2, llm:OS::UI::Composition::ISpotLight3, llm:OS::UI::Composition::ICompositionLight, llm:OS::UI::Composition::ICompositionLight2, llm:OS::UI::Composition::ICompositionLight3, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SpotLight(std::nullptr_t) noexcept {}
        SpotLight(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ISpotLight(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SpotLight, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SpotLight, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SpringScalarNaturalMotionAnimation : llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation,
        impl::base<SpringScalarNaturalMotionAnimation, llm:OS::UI::Composition::ScalarNaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SpringScalarNaturalMotionAnimation, llm:OS::UI::Composition::IScalarNaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SpringScalarNaturalMotionAnimation(std::nullptr_t) noexcept {}
        SpringScalarNaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ISpringScalarNaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SpringScalarNaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SpringScalarNaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SpringVector2NaturalMotionAnimation : llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation,
        impl::base<SpringVector2NaturalMotionAnimation, llm:OS::UI::Composition::Vector2NaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SpringVector2NaturalMotionAnimation, llm:OS::UI::Composition::IVector2NaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SpringVector2NaturalMotionAnimation(std::nullptr_t) noexcept {}
        SpringVector2NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ISpringVector2NaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SpringVector2NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SpringVector2NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SpringVector3NaturalMotionAnimation : llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation,
        impl::base<SpringVector3NaturalMotionAnimation, llm:OS::UI::Composition::Vector3NaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SpringVector3NaturalMotionAnimation, llm:OS::UI::Composition::IVector3NaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SpringVector3NaturalMotionAnimation(std::nullptr_t) noexcept {}
        SpringVector3NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ISpringVector3NaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SpringVector3NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SpringVector3NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) SpriteVisual : llm:OS::UI::Composition::ISpriteVisual,
        impl::base<SpriteVisual, llm:OS::UI::Composition::ContainerVisual, llm:OS::UI::Composition::Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<SpriteVisual, llm:OS::UI::Composition::ISpriteVisual2, llm:OS::UI::Composition::IContainerVisual, llm:OS::UI::Composition::IVisual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        SpriteVisual(std::nullptr_t) noexcept {}
        SpriteVisual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::ISpriteVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<SpriteVisual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<SpriteVisual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) StepEasingFunction : llm:OS::UI::Composition::IStepEasingFunction,
        impl::base<StepEasingFunction, llm:OS::UI::Composition::CompositionEasingFunction, llm:OS::UI::Composition::CompositionObject>,
        impl::require<StepEasingFunction, llm:OS::UI::Composition::ICompositionEasingFunction, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        StepEasingFunction(std::nullptr_t) noexcept {}
        StepEasingFunction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IStepEasingFunction(ptr, take_ownership_from_abi) {}
        using impl::consume_t<StepEasingFunction, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<StepEasingFunction, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Vector2KeyFrameAnimation : llm:OS::UI::Composition::IVector2KeyFrameAnimation,
        impl::base<Vector2KeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<Vector2KeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        Vector2KeyFrameAnimation(std::nullptr_t) noexcept {}
        Vector2KeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVector2KeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<Vector2KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<Vector2KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Vector2NaturalMotionAnimation : llm:OS::UI::Composition::IVector2NaturalMotionAnimation,
        impl::base<Vector2NaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<Vector2NaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        Vector2NaturalMotionAnimation(std::nullptr_t) noexcept {}
        Vector2NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVector2NaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<Vector2NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<Vector2NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Vector3KeyFrameAnimation : llm:OS::UI::Composition::IVector3KeyFrameAnimation,
        impl::base<Vector3KeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<Vector3KeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        Vector3KeyFrameAnimation(std::nullptr_t) noexcept {}
        Vector3KeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVector3KeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<Vector3KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<Vector3KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Vector3NaturalMotionAnimation : llm:OS::UI::Composition::IVector3NaturalMotionAnimation,
        impl::base<Vector3NaturalMotionAnimation, llm:OS::UI::Composition::NaturalMotionAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<Vector3NaturalMotionAnimation, llm:OS::UI::Composition::INaturalMotionAnimation, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        Vector3NaturalMotionAnimation(std::nullptr_t) noexcept {}
        Vector3NaturalMotionAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVector3NaturalMotionAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<Vector3NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<Vector3NaturalMotionAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Vector4KeyFrameAnimation : llm:OS::UI::Composition::IVector4KeyFrameAnimation,
        impl::base<Vector4KeyFrameAnimation, llm:OS::UI::Composition::KeyFrameAnimation, llm:OS::UI::Composition::CompositionAnimation, llm:OS::UI::Composition::CompositionObject>,
        impl::require<Vector4KeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation, llm:OS::UI::Composition::IKeyFrameAnimation2, llm:OS::UI::Composition::IKeyFrameAnimation3, llm:OS::UI::Composition::ICompositionAnimation, llm:OS::UI::Composition::ICompositionAnimation2, llm:OS::UI::Composition::ICompositionAnimation3, llm:OS::UI::Composition::ICompositionAnimation4, llm:OS::UI::Composition::ICompositionAnimationBase, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        Vector4KeyFrameAnimation(std::nullptr_t) noexcept {}
        Vector4KeyFrameAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVector4KeyFrameAnimation(ptr, take_ownership_from_abi) {}
        using impl::consume_t<Vector4KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<Vector4KeyFrameAnimation, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) Visual : llm:OS::UI::Composition::IVisual,
        impl::base<Visual, llm:OS::UI::Composition::CompositionObject>,
        impl::require<Visual, llm:OS::UI::Composition::IVisual2, llm:OS::UI::Composition::IVisual3, llm:OS::UI::Composition::IVisual4, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        Visual(std::nullptr_t) noexcept {}
        Visual(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVisual(ptr, take_ownership_from_abi) {}
        using impl::consume_t<Visual, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<Visual, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) VisualCollection : llm:OS::UI::Composition::IVisualCollection,
        impl::base<VisualCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<VisualCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::Visual>, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        VisualCollection(std::nullptr_t) noexcept {}
        VisualCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVisualCollection(ptr, take_ownership_from_abi) {}
        using impl::consume_t<VisualCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<VisualCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) VisualUnorderedCollection : llm:OS::UI::Composition::IVisualUnorderedCollection,
        impl::base<VisualUnorderedCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<VisualUnorderedCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::Visual>, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        VisualUnorderedCollection(std::nullptr_t) noexcept {}
        VisualUnorderedCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::IVisualUnorderedCollection(ptr, take_ownership_from_abi) {}
        using impl::consume_t<VisualUnorderedCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<VisualUnorderedCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
}
#endif
