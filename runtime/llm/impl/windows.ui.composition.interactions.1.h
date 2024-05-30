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
#ifndef LLM_OS_UI_Composition_Interactions_1_H
#define LLM_OS_UI_Composition_Interactions_1_H
#include "llm/impl/Windows.UI.Composition.Interactions.0.h"
LLM_EXPORT namespace llm:OS::UI::Composition::Interactions
{
    struct __declspec(empty_bases) ICompositionConditionalValue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompositionConditionalValue>
    {
        ICompositionConditionalValue(std::nullptr_t = nullptr) noexcept {}
        ICompositionConditionalValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompositionConditionalValueStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompositionConditionalValueStatics>
    {
        ICompositionConditionalValueStatics(std::nullptr_t = nullptr) noexcept {}
        ICompositionConditionalValueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompositionInteractionSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompositionInteractionSource>
    {
        ICompositionInteractionSource(std::nullptr_t = nullptr) noexcept {}
        ICompositionInteractionSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICompositionInteractionSourceCollection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICompositionInteractionSourceCollection>
    {
        ICompositionInteractionSourceCollection(std::nullptr_t = nullptr) noexcept {}
        ICompositionInteractionSourceCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionSourceConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionSourceConfiguration>
    {
        IInteractionSourceConfiguration(std::nullptr_t = nullptr) noexcept {}
        IInteractionSourceConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTracker :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTracker>
    {
        IInteractionTracker(std::nullptr_t = nullptr) noexcept {}
        IInteractionTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTracker2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTracker2>
    {
        IInteractionTracker2(std::nullptr_t = nullptr) noexcept {}
        IInteractionTracker2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTracker3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTracker3>
    {
        IInteractionTracker3(std::nullptr_t = nullptr) noexcept {}
        IInteractionTracker3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTracker4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTracker4>
    {
        IInteractionTracker4(std::nullptr_t = nullptr) noexcept {}
        IInteractionTracker4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTracker5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTracker5>
    {
        IInteractionTracker5(std::nullptr_t = nullptr) noexcept {}
        IInteractionTracker5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerCustomAnimationStateEnteredArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerCustomAnimationStateEnteredArgs>
    {
        IInteractionTrackerCustomAnimationStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerCustomAnimationStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerCustomAnimationStateEnteredArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerCustomAnimationStateEnteredArgs2>
    {
        IInteractionTrackerCustomAnimationStateEnteredArgs2(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerCustomAnimationStateEnteredArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerIdleStateEnteredArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerIdleStateEnteredArgs>
    {
        IInteractionTrackerIdleStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerIdleStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerIdleStateEnteredArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerIdleStateEnteredArgs2>
    {
        IInteractionTrackerIdleStateEnteredArgs2(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerIdleStateEnteredArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaModifier :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaModifier>
    {
        IInteractionTrackerInertiaModifier(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaModifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaModifierFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaModifierFactory>
    {
        IInteractionTrackerInertiaModifierFactory(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaModifierFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaMotion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaMotion>
    {
        IInteractionTrackerInertiaMotion(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaMotion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaMotionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaMotionStatics>
    {
        IInteractionTrackerInertiaMotionStatics(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaMotionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaNaturalMotion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaNaturalMotion>
    {
        IInteractionTrackerInertiaNaturalMotion(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaNaturalMotion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaNaturalMotionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaNaturalMotionStatics>
    {
        IInteractionTrackerInertiaNaturalMotionStatics(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaNaturalMotionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaRestingValue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaRestingValue>
    {
        IInteractionTrackerInertiaRestingValue(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaRestingValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaRestingValueStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaRestingValueStatics>
    {
        IInteractionTrackerInertiaRestingValueStatics(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaRestingValueStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaStateEnteredArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaStateEnteredArgs>
    {
        IInteractionTrackerInertiaStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaStateEnteredArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaStateEnteredArgs2>
    {
        IInteractionTrackerInertiaStateEnteredArgs2(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaStateEnteredArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInertiaStateEnteredArgs3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInertiaStateEnteredArgs3>
    {
        IInteractionTrackerInertiaStateEnteredArgs3(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInertiaStateEnteredArgs3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInteractingStateEnteredArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInteractingStateEnteredArgs>
    {
        IInteractionTrackerInteractingStateEnteredArgs(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInteractingStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerInteractingStateEnteredArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerInteractingStateEnteredArgs2>
    {
        IInteractionTrackerInteractingStateEnteredArgs2(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerInteractingStateEnteredArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerOwner :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerOwner>
    {
        IInteractionTrackerOwner(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerOwner(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerRequestIgnoredArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerRequestIgnoredArgs>
    {
        IInteractionTrackerRequestIgnoredArgs(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerRequestIgnoredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerStatics>
    {
        IInteractionTrackerStatics(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerStatics2>
    {
        IInteractionTrackerStatics2(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerValuesChangedArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerValuesChangedArgs>
    {
        IInteractionTrackerValuesChangedArgs(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerValuesChangedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerVector2InertiaModifier :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerVector2InertiaModifier>
    {
        IInteractionTrackerVector2InertiaModifier(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerVector2InertiaModifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerVector2InertiaModifierFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerVector2InertiaModifierFactory>
    {
        IInteractionTrackerVector2InertiaModifierFactory(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerVector2InertiaModifierFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerVector2InertiaNaturalMotion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerVector2InertiaNaturalMotion>
    {
        IInteractionTrackerVector2InertiaNaturalMotion(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerVector2InertiaNaturalMotion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInteractionTrackerVector2InertiaNaturalMotionStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInteractionTrackerVector2InertiaNaturalMotionStatics>
    {
        IInteractionTrackerVector2InertiaNaturalMotionStatics(std::nullptr_t = nullptr) noexcept {}
        IInteractionTrackerVector2InertiaNaturalMotionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualInteractionSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualInteractionSource>
    {
        IVisualInteractionSource(std::nullptr_t = nullptr) noexcept {}
        IVisualInteractionSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualInteractionSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualInteractionSource2>
    {
        IVisualInteractionSource2(std::nullptr_t = nullptr) noexcept {}
        IVisualInteractionSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualInteractionSource3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualInteractionSource3>
    {
        IVisualInteractionSource3(std::nullptr_t = nullptr) noexcept {}
        IVisualInteractionSource3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualInteractionSourceObjectFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualInteractionSourceObjectFactory>
    {
        IVisualInteractionSourceObjectFactory(std::nullptr_t = nullptr) noexcept {}
        IVisualInteractionSourceObjectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualInteractionSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualInteractionSourceStatics>
    {
        IVisualInteractionSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IVisualInteractionSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualInteractionSourceStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualInteractionSourceStatics2>
    {
        IVisualInteractionSourceStatics2(std::nullptr_t = nullptr) noexcept {}
        IVisualInteractionSourceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
