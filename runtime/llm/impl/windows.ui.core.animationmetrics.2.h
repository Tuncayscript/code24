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
#ifndef LLM_OS_UI_Core_AnimationMetrics_2_H
#define LLM_OS_UI_Core_AnimationMetrics_2_H
#include "llm/impl/Windows.UI.Core.AnimationMetrics.1.h"
LLM_EXPORT namespace llm:OS::UI::Core::AnimationMetrics
{
    struct __declspec(empty_bases) AnimationDescription : llm:OS::UI::Core::AnimationMetrics::IAnimationDescription
    {
        AnimationDescription(std::nullptr_t) noexcept {}
        AnimationDescription(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::AnimationMetrics::IAnimationDescription(ptr, take_ownership_from_abi) {}
        AnimationDescription(llm:OS::UI::Core::AnimationMetrics::AnimationEffect const& effect, llm:OS::UI::Core::AnimationMetrics::AnimationEffectTarget const& target);
    };
    struct __declspec(empty_bases) OpacityAnimation : llm:OS::UI::Core::AnimationMetrics::IOpacityAnimation
    {
        OpacityAnimation(std::nullptr_t) noexcept {}
        OpacityAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::AnimationMetrics::IOpacityAnimation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PropertyAnimation : llm:OS::UI::Core::AnimationMetrics::IPropertyAnimation
    {
        PropertyAnimation(std::nullptr_t) noexcept {}
        PropertyAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::AnimationMetrics::IPropertyAnimation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ScaleAnimation : llm:OS::UI::Core::AnimationMetrics::IScaleAnimation
    {
        ScaleAnimation(std::nullptr_t) noexcept {}
        ScaleAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::AnimationMetrics::IScaleAnimation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TranslationAnimation : llm:OS::UI::Core::AnimationMetrics::IPropertyAnimation
    {
        TranslationAnimation(std::nullptr_t) noexcept {}
        TranslationAnimation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::AnimationMetrics::IPropertyAnimation(ptr, take_ownership_from_abi) {}
    };
}
#endif
