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
#ifndef LLM_OS_UI_Composition_Interactions_2_H
#define LLM_OS_UI_Composition_Interactions_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.Composition.Interactions.1.h"
LLM_EXPORT namespace llm:OS::UI::Composition::Interactions
{
    struct __declspec(empty_bases) CompositionConditionalValue : llm:OS::UI::Composition::Interactions::ICompositionConditionalValue,
        impl::base<CompositionConditionalValue, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionConditionalValue, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionConditionalValue(std::nullptr_t) noexcept {}
        CompositionConditionalValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::ICompositionConditionalValue(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionConditionalValue, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionConditionalValue, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) CompositionInteractionSourceCollection : llm:OS::UI::Composition::Interactions::ICompositionInteractionSourceCollection,
        impl::base<CompositionInteractionSourceCollection, llm:OS::UI::Composition::CompositionObject>,
        impl::require<CompositionInteractionSourceCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Composition::Interactions::ICompositionInteractionSource>, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        CompositionInteractionSourceCollection(std::nullptr_t) noexcept {}
        CompositionInteractionSourceCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::ICompositionInteractionSourceCollection(ptr, take_ownership_from_abi) {}
        using impl::consume_t<CompositionInteractionSourceCollection, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<CompositionInteractionSourceCollection, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) InteractionSourceConfiguration : llm:OS::UI::Composition::Interactions::IInteractionSourceConfiguration,
        impl::base<InteractionSourceConfiguration, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionSourceConfiguration, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionSourceConfiguration(std::nullptr_t) noexcept {}
        InteractionSourceConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionSourceConfiguration(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionSourceConfiguration, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionSourceConfiguration, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) InteractionTracker : llm:OS::UI::Composition::Interactions::IInteractionTracker,
        impl::base<InteractionTracker, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTracker, llm:OS::UI::Composition::Interactions::IInteractionTracker2, llm:OS::UI::Composition::Interactions::IInteractionTracker3, llm:OS::UI::Composition::Interactions::IInteractionTracker4, llm:OS::UI::Composition::Interactions::IInteractionTracker5, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTracker(std::nullptr_t) noexcept {}
        InteractionTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTracker(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTracker, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTracker, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        using llm:OS::UI::Composition::Interactions::IInteractionTracker::TryUpdatePosition;
        using impl::consume_t<InteractionTracker, llm:OS::UI::Composition::Interactions::IInteractionTracker4>::TryUpdatePosition;
        using impl::consume_t<InteractionTracker, llm:OS::UI::Composition::Interactions::IInteractionTracker5>::TryUpdatePosition;
        using llm:OS::UI::Composition::Interactions::IInteractionTracker::TryUpdatePositionBy;
        using impl::consume_t<InteractionTracker, llm:OS::UI::Composition::Interactions::IInteractionTracker4>::TryUpdatePositionBy;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
        static auto CreateWithOwner(llm:OS::UI::Composition::Compositor const& compositor, llm:OS::UI::Composition::Interactions::IInteractionTrackerOwner const& owner);
        static auto SetBindingMode(llm:OS::UI::Composition::Interactions::InteractionTracker const& boundTracker1, llm:OS::UI::Composition::Interactions::InteractionTracker const& boundTracker2, llm:OS::UI::Composition::Interactions::InteractionBindingAxisModes const& axisMode);
        static auto GetBindingMode(llm:OS::UI::Composition::Interactions::InteractionTracker const& boundTracker1, llm:OS::UI::Composition::Interactions::InteractionTracker const& boundTracker2);
    };
    struct __declspec(empty_bases) InteractionTrackerCustomAnimationStateEnteredArgs : llm:OS::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs,
        impl::require<InteractionTrackerCustomAnimationStateEnteredArgs, llm:OS::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs2>
    {
        InteractionTrackerCustomAnimationStateEnteredArgs(std::nullptr_t) noexcept {}
        InteractionTrackerCustomAnimationStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerCustomAnimationStateEnteredArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InteractionTrackerIdleStateEnteredArgs : llm:OS::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs,
        impl::require<InteractionTrackerIdleStateEnteredArgs, llm:OS::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs2>
    {
        InteractionTrackerIdleStateEnteredArgs(std::nullptr_t) noexcept {}
        InteractionTrackerIdleStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerIdleStateEnteredArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InteractionTrackerInertiaModifier : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaModifier,
        impl::base<InteractionTrackerInertiaModifier, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTrackerInertiaModifier, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTrackerInertiaModifier(std::nullptr_t) noexcept {}
        InteractionTrackerInertiaModifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaModifier(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTrackerInertiaModifier, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTrackerInertiaModifier, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) InteractionTrackerInertiaMotion : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaMotion,
        impl::base<InteractionTrackerInertiaMotion, llm:OS::UI::Composition::Interactions::InteractionTrackerInertiaModifier, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTrackerInertiaMotion, llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaModifier, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTrackerInertiaMotion(std::nullptr_t) noexcept {}
        InteractionTrackerInertiaMotion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaMotion(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTrackerInertiaMotion, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTrackerInertiaMotion, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) InteractionTrackerInertiaNaturalMotion : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaNaturalMotion,
        impl::base<InteractionTrackerInertiaNaturalMotion, llm:OS::UI::Composition::Interactions::InteractionTrackerInertiaModifier, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTrackerInertiaNaturalMotion, llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaModifier, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTrackerInertiaNaturalMotion(std::nullptr_t) noexcept {}
        InteractionTrackerInertiaNaturalMotion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaNaturalMotion(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTrackerInertiaNaturalMotion, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTrackerInertiaNaturalMotion, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) InteractionTrackerInertiaRestingValue : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue,
        impl::base<InteractionTrackerInertiaRestingValue, llm:OS::UI::Composition::Interactions::InteractionTrackerInertiaModifier, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTrackerInertiaRestingValue, llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaModifier, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTrackerInertiaRestingValue(std::nullptr_t) noexcept {}
        InteractionTrackerInertiaRestingValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaRestingValue(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTrackerInertiaRestingValue, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTrackerInertiaRestingValue, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) InteractionTrackerInertiaStateEnteredArgs : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs,
        impl::require<InteractionTrackerInertiaStateEnteredArgs, llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs2, llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs3>
    {
        InteractionTrackerInertiaStateEnteredArgs(std::nullptr_t) noexcept {}
        InteractionTrackerInertiaStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerInertiaStateEnteredArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InteractionTrackerInteractingStateEnteredArgs : llm:OS::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs,
        impl::require<InteractionTrackerInteractingStateEnteredArgs, llm:OS::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs2>
    {
        InteractionTrackerInteractingStateEnteredArgs(std::nullptr_t) noexcept {}
        InteractionTrackerInteractingStateEnteredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerInteractingStateEnteredArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InteractionTrackerRequestIgnoredArgs : llm:OS::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs
    {
        InteractionTrackerRequestIgnoredArgs(std::nullptr_t) noexcept {}
        InteractionTrackerRequestIgnoredArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerRequestIgnoredArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InteractionTrackerValuesChangedArgs : llm:OS::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs
    {
        InteractionTrackerValuesChangedArgs(std::nullptr_t) noexcept {}
        InteractionTrackerValuesChangedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerValuesChangedArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InteractionTrackerVector2InertiaModifier : llm:OS::UI::Composition::Interactions::IInteractionTrackerVector2InertiaModifier,
        impl::base<InteractionTrackerVector2InertiaModifier, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTrackerVector2InertiaModifier, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTrackerVector2InertiaModifier(std::nullptr_t) noexcept {}
        InteractionTrackerVector2InertiaModifier(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerVector2InertiaModifier(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTrackerVector2InertiaModifier, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTrackerVector2InertiaModifier, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
    };
    struct __declspec(empty_bases) InteractionTrackerVector2InertiaNaturalMotion : llm:OS::UI::Composition::Interactions::IInteractionTrackerVector2InertiaNaturalMotion,
        impl::base<InteractionTrackerVector2InertiaNaturalMotion, llm:OS::UI::Composition::Interactions::InteractionTrackerVector2InertiaModifier, llm:OS::UI::Composition::CompositionObject>,
        impl::require<InteractionTrackerVector2InertiaNaturalMotion, llm:OS::UI::Composition::Interactions::IInteractionTrackerVector2InertiaModifier, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        InteractionTrackerVector2InertiaNaturalMotion(std::nullptr_t) noexcept {}
        InteractionTrackerVector2InertiaNaturalMotion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IInteractionTrackerVector2InertiaNaturalMotion(ptr, take_ownership_from_abi) {}
        using impl::consume_t<InteractionTrackerVector2InertiaNaturalMotion, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<InteractionTrackerVector2InertiaNaturalMotion, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Compositor const& compositor);
    };
    struct __declspec(empty_bases) VisualInteractionSource : llm:OS::UI::Composition::Interactions::IVisualInteractionSource,
        impl::base<VisualInteractionSource, llm:OS::UI::Composition::CompositionObject>,
        impl::require<VisualInteractionSource, llm:OS::UI::Composition::Interactions::IVisualInteractionSource2, llm:OS::UI::Composition::Interactions::IVisualInteractionSource3, llm:OS::UI::Composition::Interactions::ICompositionInteractionSource, llm:OS::UI::Composition::ICompositionObject, llm:OS::UI::Composition::ICompositionObject2, llm:OS::UI::Composition::ICompositionObject3, llm:OS::UI::Composition::ICompositionObject4, llm:OS::UI::Composition::ICompositionObject5, llm:OS::Foundation::IClosable, llm:OS::UI::Composition::IAnimationObject>
    {
        VisualInteractionSource(std::nullptr_t) noexcept {}
        VisualInteractionSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Composition::Interactions::IVisualInteractionSource(ptr, take_ownership_from_abi) {}
        using impl::consume_t<VisualInteractionSource, llm:OS::UI::Composition::ICompositionObject>::StartAnimation;
        using impl::consume_t<VisualInteractionSource, llm:OS::UI::Composition::ICompositionObject5>::StartAnimation;
        static auto Create(llm:OS::UI::Composition::Visual const& source);
        static auto CreateFromIVisualElement(llm:OS::UI::Composition::IVisualElement const& source);
    };
}
#endif
