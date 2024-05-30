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
#ifndef LLM_OS_UI_Input_Spatial_2_H
#define LLM_OS_UI_Input_Spatial_2_H
#include "llm/impl/Windows.Perception.1.h"
#include "llm/impl/Windows.Perception.Spatial.1.h"
#include "llm/impl/Windows.UI.Input.Spatial.1.h"
LLM_EXPORT namespace llm:OS::UI::Input::Spatial
{
    struct __declspec(empty_bases) SpatialGestureRecognizer : llm:OS::UI::Input::Spatial::ISpatialGestureRecognizer
    {
        SpatialGestureRecognizer(std::nullptr_t) noexcept {}
        SpatialGestureRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialGestureRecognizer(ptr, take_ownership_from_abi) {}
        explicit SpatialGestureRecognizer(llm:OS::UI::Input::Spatial::SpatialGestureSettings const& settings);
    };
    struct __declspec(empty_bases) SpatialHoldCanceledEventArgs : llm:OS::UI::Input::Spatial::ISpatialHoldCanceledEventArgs
    {
        SpatialHoldCanceledEventArgs(std::nullptr_t) noexcept {}
        SpatialHoldCanceledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialHoldCanceledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialHoldCompletedEventArgs : llm:OS::UI::Input::Spatial::ISpatialHoldCompletedEventArgs
    {
        SpatialHoldCompletedEventArgs(std::nullptr_t) noexcept {}
        SpatialHoldCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialHoldCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialHoldStartedEventArgs : llm:OS::UI::Input::Spatial::ISpatialHoldStartedEventArgs
    {
        SpatialHoldStartedEventArgs(std::nullptr_t) noexcept {}
        SpatialHoldStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialHoldStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteraction : llm:OS::UI::Input::Spatial::ISpatialInteraction
    {
        SpatialInteraction(std::nullptr_t) noexcept {}
        SpatialInteraction(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteraction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionController : llm:OS::UI::Input::Spatial::ISpatialInteractionController,
        impl::require<SpatialInteractionController, llm:OS::UI::Input::Spatial::ISpatialInteractionController2, llm:OS::UI::Input::Spatial::ISpatialInteractionController3>
    {
        SpatialInteractionController(std::nullptr_t) noexcept {}
        SpatialInteractionController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionController(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionControllerProperties : llm:OS::UI::Input::Spatial::ISpatialInteractionControllerProperties
    {
        SpatialInteractionControllerProperties(std::nullptr_t) noexcept {}
        SpatialInteractionControllerProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionControllerProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionDetectedEventArgs : llm:OS::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs,
        impl::require<SpatialInteractionDetectedEventArgs, llm:OS::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs2>
    {
        SpatialInteractionDetectedEventArgs(std::nullptr_t) noexcept {}
        SpatialInteractionDetectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionDetectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionManager : llm:OS::UI::Input::Spatial::ISpatialInteractionManager
    {
        SpatialInteractionManager(std::nullptr_t) noexcept {}
        SpatialInteractionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto IsSourceKindSupported(llm:OS::UI::Input::Spatial::SpatialInteractionSourceKind const& kind);
    };
    struct __declspec(empty_bases) SpatialInteractionSource : llm:OS::UI::Input::Spatial::ISpatialInteractionSource,
        impl::require<SpatialInteractionSource, llm:OS::UI::Input::Spatial::ISpatialInteractionSource2, llm:OS::UI::Input::Spatial::ISpatialInteractionSource3, llm:OS::UI::Input::Spatial::ISpatialInteractionSource4>
    {
        SpatialInteractionSource(std::nullptr_t) noexcept {}
        SpatialInteractionSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionSource(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionSourceEventArgs : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceEventArgs,
        impl::require<SpatialInteractionSourceEventArgs, llm:OS::UI::Input::Spatial::ISpatialInteractionSourceEventArgs2>
    {
        SpatialInteractionSourceEventArgs(std::nullptr_t) noexcept {}
        SpatialInteractionSourceEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionSourceLocation : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceLocation,
        impl::require<SpatialInteractionSourceLocation, llm:OS::UI::Input::Spatial::ISpatialInteractionSourceLocation2, llm:OS::UI::Input::Spatial::ISpatialInteractionSourceLocation3>
    {
        SpatialInteractionSourceLocation(std::nullptr_t) noexcept {}
        SpatialInteractionSourceLocation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceLocation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionSourceProperties : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceProperties
    {
        SpatialInteractionSourceProperties(std::nullptr_t) noexcept {}
        SpatialInteractionSourceProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialInteractionSourceState : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceState,
        impl::require<SpatialInteractionSourceState, llm:OS::UI::Input::Spatial::ISpatialInteractionSourceState2, llm:OS::UI::Input::Spatial::ISpatialInteractionSourceState3>
    {
        SpatialInteractionSourceState(std::nullptr_t) noexcept {}
        SpatialInteractionSourceState(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialInteractionSourceState(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialManipulationCanceledEventArgs : llm:OS::UI::Input::Spatial::ISpatialManipulationCanceledEventArgs
    {
        SpatialManipulationCanceledEventArgs(std::nullptr_t) noexcept {}
        SpatialManipulationCanceledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialManipulationCanceledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialManipulationCompletedEventArgs : llm:OS::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs
    {
        SpatialManipulationCompletedEventArgs(std::nullptr_t) noexcept {}
        SpatialManipulationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialManipulationCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialManipulationDelta : llm:OS::UI::Input::Spatial::ISpatialManipulationDelta
    {
        SpatialManipulationDelta(std::nullptr_t) noexcept {}
        SpatialManipulationDelta(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialManipulationDelta(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialManipulationStartedEventArgs : llm:OS::UI::Input::Spatial::ISpatialManipulationStartedEventArgs
    {
        SpatialManipulationStartedEventArgs(std::nullptr_t) noexcept {}
        SpatialManipulationStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialManipulationStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialManipulationUpdatedEventArgs : llm:OS::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs
    {
        SpatialManipulationUpdatedEventArgs(std::nullptr_t) noexcept {}
        SpatialManipulationUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialManipulationUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialNavigationCanceledEventArgs : llm:OS::UI::Input::Spatial::ISpatialNavigationCanceledEventArgs
    {
        SpatialNavigationCanceledEventArgs(std::nullptr_t) noexcept {}
        SpatialNavigationCanceledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialNavigationCanceledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialNavigationCompletedEventArgs : llm:OS::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs
    {
        SpatialNavigationCompletedEventArgs(std::nullptr_t) noexcept {}
        SpatialNavigationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialNavigationCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialNavigationStartedEventArgs : llm:OS::UI::Input::Spatial::ISpatialNavigationStartedEventArgs
    {
        SpatialNavigationStartedEventArgs(std::nullptr_t) noexcept {}
        SpatialNavigationStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialNavigationStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialNavigationUpdatedEventArgs : llm:OS::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs
    {
        SpatialNavigationUpdatedEventArgs(std::nullptr_t) noexcept {}
        SpatialNavigationUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialNavigationUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialPointerInteractionSourcePose : llm:OS::UI::Input::Spatial::ISpatialPointerInteractionSourcePose,
        impl::require<SpatialPointerInteractionSourcePose, llm:OS::UI::Input::Spatial::ISpatialPointerInteractionSourcePose2>
    {
        SpatialPointerInteractionSourcePose(std::nullptr_t) noexcept {}
        SpatialPointerInteractionSourcePose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialPointerInteractionSourcePose(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialPointerPose : llm:OS::UI::Input::Spatial::ISpatialPointerPose,
        impl::require<SpatialPointerPose, llm:OS::UI::Input::Spatial::ISpatialPointerPose2, llm:OS::UI::Input::Spatial::ISpatialPointerPose3>
    {
        SpatialPointerPose(std::nullptr_t) noexcept {}
        SpatialPointerPose(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialPointerPose(ptr, take_ownership_from_abi) {}
        static auto TryGetAtTimestamp(llm:OS::Perception::Spatial::SpatialCoordinateSystem const& coordinateSystem, llm:OS::Perception::PerceptionTimestamp const& timestamp);
    };
    struct __declspec(empty_bases) SpatialRecognitionEndedEventArgs : llm:OS::UI::Input::Spatial::ISpatialRecognitionEndedEventArgs
    {
        SpatialRecognitionEndedEventArgs(std::nullptr_t) noexcept {}
        SpatialRecognitionEndedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialRecognitionEndedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialRecognitionStartedEventArgs : llm:OS::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs
    {
        SpatialRecognitionStartedEventArgs(std::nullptr_t) noexcept {}
        SpatialRecognitionStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialRecognitionStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpatialTappedEventArgs : llm:OS::UI::Input::Spatial::ISpatialTappedEventArgs
    {
        SpatialTappedEventArgs(std::nullptr_t) noexcept {}
        SpatialTappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::Spatial::ISpatialTappedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
