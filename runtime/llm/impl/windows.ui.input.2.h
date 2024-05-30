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
#ifndef LLM_OS_UI_Input_2_H
#define LLM_OS_UI_Input_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.Input.1.h"
LLM_EXPORT namespace llm:OS::UI::Input
{
    struct CrossSlideThresholds
    {
        float SelectionStart;
        float SpeedBumpStart;
        float SpeedBumpEnd;
        float RearrangeStart;
    };
    inline bool operator==(CrossSlideThresholds const& left, CrossSlideThresholds const& right) noexcept
    {
        return left.SelectionStart == right.SelectionStart && left.SpeedBumpStart == right.SpeedBumpStart && left.SpeedBumpEnd == right.SpeedBumpEnd && left.RearrangeStart == right.RearrangeStart;
    }
    inline bool operator!=(CrossSlideThresholds const& left, CrossSlideThresholds const& right) noexcept
    {
        return !(left == right);
    }
    struct ManipulationDelta
    {
        llm:OS::Foundation::Point Translation;
        float Scale;
        float Rotation;
        float Expansion;
    };
    inline bool operator==(ManipulationDelta const& left, ManipulationDelta const& right) noexcept
    {
        return left.Translation == right.Translation && left.Scale == right.Scale && left.Rotation == right.Rotation && left.Expansion == right.Expansion;
    }
    inline bool operator!=(ManipulationDelta const& left, ManipulationDelta const& right) noexcept
    {
        return !(left == right);
    }
    struct ManipulationVelocities
    {
        llm:OS::Foundation::Point Linear;
        float Angular;
        float Expansion;
    };
    inline bool operator==(ManipulationVelocities const& left, ManipulationVelocities const& right) noexcept
    {
        return left.Linear == right.Linear && left.Angular == right.Angular && left.Expansion == right.Expansion;
    }
    inline bool operator!=(ManipulationVelocities const& left, ManipulationVelocities const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AttachableInputObject : llm:OS::UI::Input::IAttachableInputObject,
        impl::require<AttachableInputObject, llm:OS::Foundation::IClosable>
    {
        AttachableInputObject(std::nullptr_t) noexcept {}
        AttachableInputObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IAttachableInputObject(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CrossSlidingEventArgs : llm:OS::UI::Input::ICrossSlidingEventArgs,
        impl::require<CrossSlidingEventArgs, llm:OS::UI::Input::ICrossSlidingEventArgs2>
    {
        CrossSlidingEventArgs(std::nullptr_t) noexcept {}
        CrossSlidingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::ICrossSlidingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DraggingEventArgs : llm:OS::UI::Input::IDraggingEventArgs,
        impl::require<DraggingEventArgs, llm:OS::UI::Input::IDraggingEventArgs2>
    {
        DraggingEventArgs(std::nullptr_t) noexcept {}
        DraggingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IDraggingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) EdgeGesture : llm:OS::UI::Input::IEdgeGesture
    {
        EdgeGesture(std::nullptr_t) noexcept {}
        EdgeGesture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IEdgeGesture(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) EdgeGestureEventArgs : llm:OS::UI::Input::IEdgeGestureEventArgs
    {
        EdgeGestureEventArgs(std::nullptr_t) noexcept {}
        EdgeGestureEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IEdgeGestureEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GestureRecognizer : llm:OS::UI::Input::IGestureRecognizer,
        impl::require<GestureRecognizer, llm:OS::UI::Input::IGestureRecognizer2>
    {
        GestureRecognizer(std::nullptr_t) noexcept {}
        GestureRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IGestureRecognizer(ptr, take_ownership_from_abi) {}
        GestureRecognizer();
    };
    struct __declspec(empty_bases) HoldingEventArgs : llm:OS::UI::Input::IHoldingEventArgs,
        impl::require<HoldingEventArgs, llm:OS::UI::Input::IHoldingEventArgs2>
    {
        HoldingEventArgs(std::nullptr_t) noexcept {}
        HoldingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IHoldingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InputActivationListener : llm:OS::UI::Input::IInputActivationListener,
        impl::base<InputActivationListener, llm:OS::UI::Input::AttachableInputObject>,
        impl::require<InputActivationListener, llm:OS::UI::Input::IAttachableInputObject, llm:OS::Foundation::IClosable>
    {
        InputActivationListener(std::nullptr_t) noexcept {}
        InputActivationListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IInputActivationListener(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InputActivationListenerActivationChangedEventArgs : llm:OS::UI::Input::IInputActivationListenerActivationChangedEventArgs
    {
        InputActivationListenerActivationChangedEventArgs(std::nullptr_t) noexcept {}
        InputActivationListenerActivationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IInputActivationListenerActivationChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeyboardDeliveryInterceptor : llm:OS::UI::Input::IKeyboardDeliveryInterceptor
    {
        KeyboardDeliveryInterceptor(std::nullptr_t) noexcept {}
        KeyboardDeliveryInterceptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IKeyboardDeliveryInterceptor(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) ManipulationCompletedEventArgs : llm:OS::UI::Input::IManipulationCompletedEventArgs,
        impl::require<ManipulationCompletedEventArgs, llm:OS::UI::Input::IManipulationCompletedEventArgs2>
    {
        ManipulationCompletedEventArgs(std::nullptr_t) noexcept {}
        ManipulationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IManipulationCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ManipulationInertiaStartingEventArgs : llm:OS::UI::Input::IManipulationInertiaStartingEventArgs,
        impl::require<ManipulationInertiaStartingEventArgs, llm:OS::UI::Input::IManipulationInertiaStartingEventArgs2>
    {
        ManipulationInertiaStartingEventArgs(std::nullptr_t) noexcept {}
        ManipulationInertiaStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IManipulationInertiaStartingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ManipulationStartedEventArgs : llm:OS::UI::Input::IManipulationStartedEventArgs,
        impl::require<ManipulationStartedEventArgs, llm:OS::UI::Input::IManipulationStartedEventArgs2>
    {
        ManipulationStartedEventArgs(std::nullptr_t) noexcept {}
        ManipulationStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IManipulationStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ManipulationUpdatedEventArgs : llm:OS::UI::Input::IManipulationUpdatedEventArgs,
        impl::require<ManipulationUpdatedEventArgs, llm:OS::UI::Input::IManipulationUpdatedEventArgs2>
    {
        ManipulationUpdatedEventArgs(std::nullptr_t) noexcept {}
        ManipulationUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IManipulationUpdatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MouseWheelParameters : llm:OS::UI::Input::IMouseWheelParameters
    {
        MouseWheelParameters(std::nullptr_t) noexcept {}
        MouseWheelParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IMouseWheelParameters(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PointerPoint : llm:OS::UI::Input::IPointerPoint
    {
        PointerPoint(std::nullptr_t) noexcept {}
        PointerPoint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IPointerPoint(ptr, take_ownership_from_abi) {}
        static auto GetCurrentPoint(uint32_t pointerId);
        static auto GetIntermediatePoints(uint32_t pointerId);
        static auto GetCurrentPoint(uint32_t pointerId, llm:OS::UI::Input::IPointerPointTransform const& transform);
        static auto GetIntermediatePoints(uint32_t pointerId, llm:OS::UI::Input::IPointerPointTransform const& transform);
    };
    struct __declspec(empty_bases) PointerPointProperties : llm:OS::UI::Input::IPointerPointProperties,
        impl::require<PointerPointProperties, llm:OS::UI::Input::IPointerPointProperties2>
    {
        PointerPointProperties(std::nullptr_t) noexcept {}
        PointerPointProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IPointerPointProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PointerVisualizationSettings : llm:OS::UI::Input::IPointerVisualizationSettings
    {
        PointerVisualizationSettings(std::nullptr_t) noexcept {}
        PointerVisualizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IPointerVisualizationSettings(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) RadialController : llm:OS::UI::Input::IRadialController,
        impl::require<RadialController, llm:OS::UI::Input::IRadialController2>
    {
        RadialController(std::nullptr_t) noexcept {}
        RadialController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialController(ptr, take_ownership_from_abi) {}
        static auto IsSupported();
        static auto CreateForCurrentView();
    };
    struct __declspec(empty_bases) RadialControllerButtonClickedEventArgs : llm:OS::UI::Input::IRadialControllerButtonClickedEventArgs,
        impl::require<RadialControllerButtonClickedEventArgs, llm:OS::UI::Input::IRadialControllerButtonClickedEventArgs2>
    {
        RadialControllerButtonClickedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerButtonClickedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerButtonHoldingEventArgs : llm:OS::UI::Input::IRadialControllerButtonHoldingEventArgs
    {
        RadialControllerButtonHoldingEventArgs(std::nullptr_t) noexcept {}
        RadialControllerButtonHoldingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerButtonHoldingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerButtonPressedEventArgs : llm:OS::UI::Input::IRadialControllerButtonPressedEventArgs
    {
        RadialControllerButtonPressedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerButtonPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerButtonPressedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerButtonReleasedEventArgs : llm:OS::UI::Input::IRadialControllerButtonReleasedEventArgs
    {
        RadialControllerButtonReleasedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerButtonReleasedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerButtonReleasedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerConfiguration : llm:OS::UI::Input::IRadialControllerConfiguration,
        impl::require<RadialControllerConfiguration, llm:OS::UI::Input::IRadialControllerConfiguration2>
    {
        RadialControllerConfiguration(std::nullptr_t) noexcept {}
        RadialControllerConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerConfiguration(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto AppController(llm:OS::UI::Input::RadialController const& value);
        [[nodiscard]] static auto AppController();
        static auto IsAppControllerEnabled(bool value);
        [[nodiscard]] static auto IsAppControllerEnabled();
    };
    struct __declspec(empty_bases) RadialControllerControlAcquiredEventArgs : llm:OS::UI::Input::IRadialControllerControlAcquiredEventArgs,
        impl::require<RadialControllerControlAcquiredEventArgs, llm:OS::UI::Input::IRadialControllerControlAcquiredEventArgs2>
    {
        RadialControllerControlAcquiredEventArgs(std::nullptr_t) noexcept {}
        RadialControllerControlAcquiredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerControlAcquiredEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerMenu : llm:OS::UI::Input::IRadialControllerMenu
    {
        RadialControllerMenu(std::nullptr_t) noexcept {}
        RadialControllerMenu(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerMenu(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerMenuItem : llm:OS::UI::Input::IRadialControllerMenuItem
    {
        RadialControllerMenuItem(std::nullptr_t) noexcept {}
        RadialControllerMenuItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerMenuItem(ptr, take_ownership_from_abi) {}
        static auto CreateFromIcon(param::hstring const& displayText, llm:OS::Storage::Streams::RandomAccessStreamReference const& icon);
        static auto CreateFromKnownIcon(param::hstring const& displayText, llm:OS::UI::Input::RadialControllerMenuKnownIcon const& value);
        static auto CreateFromFontGlyph(param::hstring const& displayText, param::hstring const& glyph, param::hstring const& fontFamily);
        static auto CreateFromFontGlyph(param::hstring const& displayText, param::hstring const& glyph, param::hstring const& fontFamily, llm:OS::Foundation::Uri const& fontUri);
    };
    struct __declspec(empty_bases) RadialControllerRotationChangedEventArgs : llm:OS::UI::Input::IRadialControllerRotationChangedEventArgs,
        impl::require<RadialControllerRotationChangedEventArgs, llm:OS::UI::Input::IRadialControllerRotationChangedEventArgs2>
    {
        RadialControllerRotationChangedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerRotationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerRotationChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerScreenContact : llm:OS::UI::Input::IRadialControllerScreenContact
    {
        RadialControllerScreenContact(std::nullptr_t) noexcept {}
        RadialControllerScreenContact(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerScreenContact(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerScreenContactContinuedEventArgs : llm:OS::UI::Input::IRadialControllerScreenContactContinuedEventArgs,
        impl::require<RadialControllerScreenContactContinuedEventArgs, llm:OS::UI::Input::IRadialControllerScreenContactContinuedEventArgs2>
    {
        RadialControllerScreenContactContinuedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerScreenContactContinuedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerScreenContactContinuedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerScreenContactEndedEventArgs : llm:OS::UI::Input::IRadialControllerScreenContactEndedEventArgs
    {
        RadialControllerScreenContactEndedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerScreenContactEndedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerScreenContactEndedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RadialControllerScreenContactStartedEventArgs : llm:OS::UI::Input::IRadialControllerScreenContactStartedEventArgs,
        impl::require<RadialControllerScreenContactStartedEventArgs, llm:OS::UI::Input::IRadialControllerScreenContactStartedEventArgs2>
    {
        RadialControllerScreenContactStartedEventArgs(std::nullptr_t) noexcept {}
        RadialControllerScreenContactStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRadialControllerScreenContactStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RightTappedEventArgs : llm:OS::UI::Input::IRightTappedEventArgs,
        impl::require<RightTappedEventArgs, llm:OS::UI::Input::IRightTappedEventArgs2>
    {
        RightTappedEventArgs(std::nullptr_t) noexcept {}
        RightTappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::IRightTappedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemButtonEventController : llm:OS::UI::Input::ISystemButtonEventController,
        impl::base<SystemButtonEventController, llm:OS::UI::Input::AttachableInputObject>,
        impl::require<SystemButtonEventController, llm:OS::UI::Input::IAttachableInputObject, llm:OS::Foundation::IClosable>
    {
        SystemButtonEventController(std::nullptr_t) noexcept {}
        SystemButtonEventController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::ISystemButtonEventController(ptr, take_ownership_from_abi) {}
        static auto CreateForDispatcherQueue(llm:OS::System::DispatcherQueue const& queue);
    };
    struct __declspec(empty_bases) SystemFunctionButtonEventArgs : llm:OS::UI::Input::ISystemFunctionButtonEventArgs
    {
        SystemFunctionButtonEventArgs(std::nullptr_t) noexcept {}
        SystemFunctionButtonEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::ISystemFunctionButtonEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemFunctionLockChangedEventArgs : llm:OS::UI::Input::ISystemFunctionLockChangedEventArgs
    {
        SystemFunctionLockChangedEventArgs(std::nullptr_t) noexcept {}
        SystemFunctionLockChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::ISystemFunctionLockChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemFunctionLockIndicatorChangedEventArgs : llm:OS::UI::Input::ISystemFunctionLockIndicatorChangedEventArgs
    {
        SystemFunctionLockIndicatorChangedEventArgs(std::nullptr_t) noexcept {}
        SystemFunctionLockIndicatorChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::ISystemFunctionLockIndicatorChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TappedEventArgs : llm:OS::UI::Input::ITappedEventArgs,
        impl::require<TappedEventArgs, llm:OS::UI::Input::ITappedEventArgs2>
    {
        TappedEventArgs(std::nullptr_t) noexcept {}
        TappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Input::ITappedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
