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
#ifndef LLM_OS_UI_Input_1_H
#define LLM_OS_UI_Input_1_H
#include "llm/impl/Windows.UI.Input.0.h"
LLM_EXPORT namespace llm:OS::UI::Input
{
    struct __declspec(empty_bases) IAttachableInputObject :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAttachableInputObject>
    {
        IAttachableInputObject(std::nullptr_t = nullptr) noexcept {}
        IAttachableInputObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAttachableInputObjectFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAttachableInputObjectFactory>
    {
        IAttachableInputObjectFactory(std::nullptr_t = nullptr) noexcept {}
        IAttachableInputObjectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICrossSlidingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICrossSlidingEventArgs>
    {
        ICrossSlidingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICrossSlidingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICrossSlidingEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICrossSlidingEventArgs2>
    {
        ICrossSlidingEventArgs2(std::nullptr_t = nullptr) noexcept {}
        ICrossSlidingEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDraggingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDraggingEventArgs>
    {
        IDraggingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDraggingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDraggingEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDraggingEventArgs2>
    {
        IDraggingEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IDraggingEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEdgeGesture :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEdgeGesture>
    {
        IEdgeGesture(std::nullptr_t = nullptr) noexcept {}
        IEdgeGesture(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEdgeGestureEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEdgeGestureEventArgs>
    {
        IEdgeGestureEventArgs(std::nullptr_t = nullptr) noexcept {}
        IEdgeGestureEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEdgeGestureStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEdgeGestureStatics>
    {
        IEdgeGestureStatics(std::nullptr_t = nullptr) noexcept {}
        IEdgeGestureStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGestureRecognizer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGestureRecognizer>
    {
        IGestureRecognizer(std::nullptr_t = nullptr) noexcept {}
        IGestureRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGestureRecognizer2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGestureRecognizer2>
    {
        IGestureRecognizer2(std::nullptr_t = nullptr) noexcept {}
        IGestureRecognizer2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHoldingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHoldingEventArgs>
    {
        IHoldingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IHoldingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHoldingEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHoldingEventArgs2>
    {
        IHoldingEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IHoldingEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputActivationListener :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputActivationListener>
    {
        IInputActivationListener(std::nullptr_t = nullptr) noexcept {}
        IInputActivationListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputActivationListenerActivationChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputActivationListenerActivationChangedEventArgs>
    {
        IInputActivationListenerActivationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IInputActivationListenerActivationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyboardDeliveryInterceptor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyboardDeliveryInterceptor>
    {
        IKeyboardDeliveryInterceptor(std::nullptr_t = nullptr) noexcept {}
        IKeyboardDeliveryInterceptor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyboardDeliveryInterceptorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyboardDeliveryInterceptorStatics>
    {
        IKeyboardDeliveryInterceptorStatics(std::nullptr_t = nullptr) noexcept {}
        IKeyboardDeliveryInterceptorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationCompletedEventArgs>
    {
        IManipulationCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IManipulationCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationCompletedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationCompletedEventArgs2>
    {
        IManipulationCompletedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IManipulationCompletedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationInertiaStartingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationInertiaStartingEventArgs>
    {
        IManipulationInertiaStartingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IManipulationInertiaStartingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationInertiaStartingEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationInertiaStartingEventArgs2>
    {
        IManipulationInertiaStartingEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IManipulationInertiaStartingEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationStartedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationStartedEventArgs>
    {
        IManipulationStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IManipulationStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationStartedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationStartedEventArgs2>
    {
        IManipulationStartedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IManipulationStartedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationUpdatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationUpdatedEventArgs>
    {
        IManipulationUpdatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IManipulationUpdatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IManipulationUpdatedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IManipulationUpdatedEventArgs2>
    {
        IManipulationUpdatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IManipulationUpdatedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMouseWheelParameters :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMouseWheelParameters>
    {
        IMouseWheelParameters(std::nullptr_t = nullptr) noexcept {}
        IMouseWheelParameters(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerPoint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerPoint>
    {
        IPointerPoint(std::nullptr_t = nullptr) noexcept {}
        IPointerPoint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerPointProperties :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerPointProperties>
    {
        IPointerPointProperties(std::nullptr_t = nullptr) noexcept {}
        IPointerPointProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerPointProperties2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerPointProperties2>
    {
        IPointerPointProperties2(std::nullptr_t = nullptr) noexcept {}
        IPointerPointProperties2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerPointStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerPointStatics>
    {
        IPointerPointStatics(std::nullptr_t = nullptr) noexcept {}
        IPointerPointStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerPointTransform :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerPointTransform>
    {
        IPointerPointTransform(std::nullptr_t = nullptr) noexcept {}
        IPointerPointTransform(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerVisualizationSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerVisualizationSettings>
    {
        IPointerVisualizationSettings(std::nullptr_t = nullptr) noexcept {}
        IPointerVisualizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerVisualizationSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerVisualizationSettingsStatics>
    {
        IPointerVisualizationSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IPointerVisualizationSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialController>
    {
        IRadialController(std::nullptr_t = nullptr) noexcept {}
        IRadialController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialController2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialController2>
    {
        IRadialController2(std::nullptr_t = nullptr) noexcept {}
        IRadialController2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerButtonClickedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerButtonClickedEventArgs>
    {
        IRadialControllerButtonClickedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerButtonClickedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerButtonClickedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerButtonClickedEventArgs2>
    {
        IRadialControllerButtonClickedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerButtonClickedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerButtonHoldingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerButtonHoldingEventArgs>
    {
        IRadialControllerButtonHoldingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerButtonHoldingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerButtonPressedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerButtonPressedEventArgs>
    {
        IRadialControllerButtonPressedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerButtonPressedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerButtonReleasedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerButtonReleasedEventArgs>
    {
        IRadialControllerButtonReleasedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerButtonReleasedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerConfiguration>
    {
        IRadialControllerConfiguration(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerConfiguration2>
    {
        IRadialControllerConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerConfigurationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerConfigurationStatics>
    {
        IRadialControllerConfigurationStatics(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerConfigurationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerConfigurationStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerConfigurationStatics2>
    {
        IRadialControllerConfigurationStatics2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerConfigurationStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerControlAcquiredEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerControlAcquiredEventArgs>
    {
        IRadialControllerControlAcquiredEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerControlAcquiredEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerControlAcquiredEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerControlAcquiredEventArgs2>
    {
        IRadialControllerControlAcquiredEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerControlAcquiredEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerMenu :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerMenu>
    {
        IRadialControllerMenu(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerMenu(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerMenuItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerMenuItem>
    {
        IRadialControllerMenuItem(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerMenuItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerMenuItemStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerMenuItemStatics>
    {
        IRadialControllerMenuItemStatics(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerMenuItemStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerMenuItemStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerMenuItemStatics2>
    {
        IRadialControllerMenuItemStatics2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerMenuItemStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerRotationChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerRotationChangedEventArgs>
    {
        IRadialControllerRotationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerRotationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerRotationChangedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerRotationChangedEventArgs2>
    {
        IRadialControllerRotationChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerRotationChangedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerScreenContact :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerScreenContact>
    {
        IRadialControllerScreenContact(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerScreenContact(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerScreenContactContinuedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerScreenContactContinuedEventArgs>
    {
        IRadialControllerScreenContactContinuedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerScreenContactContinuedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerScreenContactContinuedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerScreenContactContinuedEventArgs2>
    {
        IRadialControllerScreenContactContinuedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerScreenContactContinuedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerScreenContactEndedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerScreenContactEndedEventArgs>
    {
        IRadialControllerScreenContactEndedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerScreenContactEndedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerScreenContactStartedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerScreenContactStartedEventArgs>
    {
        IRadialControllerScreenContactStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerScreenContactStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerScreenContactStartedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerScreenContactStartedEventArgs2>
    {
        IRadialControllerScreenContactStartedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerScreenContactStartedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRadialControllerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRadialControllerStatics>
    {
        IRadialControllerStatics(std::nullptr_t = nullptr) noexcept {}
        IRadialControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRightTappedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRightTappedEventArgs>
    {
        IRightTappedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IRightTappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRightTappedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRightTappedEventArgs2>
    {
        IRightTappedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IRightTappedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemButtonEventController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemButtonEventController>
    {
        ISystemButtonEventController(std::nullptr_t = nullptr) noexcept {}
        ISystemButtonEventController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemButtonEventControllerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemButtonEventControllerStatics>
    {
        ISystemButtonEventControllerStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemButtonEventControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemFunctionButtonEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemFunctionButtonEventArgs>
    {
        ISystemFunctionButtonEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISystemFunctionButtonEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemFunctionLockChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemFunctionLockChangedEventArgs>
    {
        ISystemFunctionLockChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISystemFunctionLockChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemFunctionLockIndicatorChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemFunctionLockIndicatorChangedEventArgs>
    {
        ISystemFunctionLockIndicatorChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISystemFunctionLockIndicatorChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITappedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITappedEventArgs>
    {
        ITappedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITappedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITappedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITappedEventArgs2>
    {
        ITappedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        ITappedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
