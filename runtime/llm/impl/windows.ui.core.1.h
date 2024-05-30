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
#ifndef LLM_OS_UI_Core_1_H
#define LLM_OS_UI_Core_1_H
#include "llm/impl/Windows.UI.Core.0.h"
LLM_EXPORT namespace llm:OS::UI::Core
{
    struct __declspec(empty_bases) IAcceleratorKeyEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAcceleratorKeyEventArgs>,
        impl::require<llm:OS::UI::Core::IAcceleratorKeyEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IAcceleratorKeyEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAcceleratorKeyEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAcceleratorKeyEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAcceleratorKeyEventArgs2>,
        impl::require<llm:OS::UI::Core::IAcceleratorKeyEventArgs2, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IAcceleratorKeyEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IAcceleratorKeyEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAutomationProviderRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAutomationProviderRequestedEventArgs>,
        impl::require<llm:OS::UI::Core::IAutomationProviderRequestedEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IAutomationProviderRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAutomationProviderRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBackRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IBackRequestedEventArgs>
    {
        IBackRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBackRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICharacterReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICharacterReceivedEventArgs>,
        impl::require<llm:OS::UI::Core::ICharacterReceivedEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        ICharacterReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICharacterReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IClosestInteractiveBoundsRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IClosestInteractiveBoundsRequestedEventArgs>
    {
        IClosestInteractiveBoundsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IClosestInteractiveBoundsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreAcceleratorKeys :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreAcceleratorKeys>
    {
        ICoreAcceleratorKeys(std::nullptr_t = nullptr) noexcept {}
        ICoreAcceleratorKeys(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreClosestInteractiveBoundsRequested :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreClosestInteractiveBoundsRequested>
    {
        ICoreClosestInteractiveBoundsRequested(std::nullptr_t = nullptr) noexcept {}
        ICoreClosestInteractiveBoundsRequested(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreComponentFocusable :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreComponentFocusable>
    {
        ICoreComponentFocusable(std::nullptr_t = nullptr) noexcept {}
        ICoreComponentFocusable(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreCursor :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreCursor>
    {
        ICoreCursor(std::nullptr_t = nullptr) noexcept {}
        ICoreCursor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreCursorFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreCursorFactory>
    {
        ICoreCursorFactory(std::nullptr_t = nullptr) noexcept {}
        ICoreCursorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDispatcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreDispatcher>,
        impl::require<llm:OS::UI::Core::ICoreDispatcher, llm:OS::UI::Core::ICoreAcceleratorKeys>
    {
        ICoreDispatcher(std::nullptr_t = nullptr) noexcept {}
        ICoreDispatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDispatcher2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreDispatcher2>
    {
        ICoreDispatcher2(std::nullptr_t = nullptr) noexcept {}
        ICoreDispatcher2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreDispatcherWithTaskPriority :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreDispatcherWithTaskPriority>
    {
        ICoreDispatcherWithTaskPriority(std::nullptr_t = nullptr) noexcept {}
        ICoreDispatcherWithTaskPriority(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreIndependentInputSourceController :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreIndependentInputSourceController>
    {
        ICoreIndependentInputSourceController(std::nullptr_t = nullptr) noexcept {}
        ICoreIndependentInputSourceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreIndependentInputSourceControllerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreIndependentInputSourceControllerStatics>
    {
        ICoreIndependentInputSourceControllerStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreIndependentInputSourceControllerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreInputSourceBase :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreInputSourceBase>
    {
        ICoreInputSourceBase(std::nullptr_t = nullptr) noexcept {}
        ICoreInputSourceBase(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreKeyboardInputSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreKeyboardInputSource>
    {
        ICoreKeyboardInputSource(std::nullptr_t = nullptr) noexcept {}
        ICoreKeyboardInputSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreKeyboardInputSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreKeyboardInputSource2>
    {
        ICoreKeyboardInputSource2(std::nullptr_t = nullptr) noexcept {}
        ICoreKeyboardInputSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICorePointerInputSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICorePointerInputSource>
    {
        ICorePointerInputSource(std::nullptr_t = nullptr) noexcept {}
        ICorePointerInputSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICorePointerInputSource2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICorePointerInputSource2>,
        impl::require<llm:OS::UI::Core::ICorePointerInputSource2, llm:OS::UI::Core::ICorePointerInputSource>
    {
        ICorePointerInputSource2(std::nullptr_t = nullptr) noexcept {}
        ICorePointerInputSource2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICorePointerRedirector :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICorePointerRedirector>
    {
        ICorePointerRedirector(std::nullptr_t = nullptr) noexcept {}
        ICorePointerRedirector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTouchHitTesting :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTouchHitTesting>
    {
        ICoreTouchHitTesting(std::nullptr_t = nullptr) noexcept {}
        ICoreTouchHitTesting(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindow :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindow>
    {
        ICoreWindow(std::nullptr_t = nullptr) noexcept {}
        ICoreWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindow2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindow2>
    {
        ICoreWindow2(std::nullptr_t = nullptr) noexcept {}
        ICoreWindow2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindow3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindow3>
    {
        ICoreWindow3(std::nullptr_t = nullptr) noexcept {}
        ICoreWindow3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindow4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindow4>
    {
        ICoreWindow4(std::nullptr_t = nullptr) noexcept {}
        ICoreWindow4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindow5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindow5>
    {
        ICoreWindow5(std::nullptr_t = nullptr) noexcept {}
        ICoreWindow5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowDialog :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowDialog>
    {
        ICoreWindowDialog(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowDialog(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowDialogFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowDialogFactory>
    {
        ICoreWindowDialogFactory(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowDialogFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowEventArgs>
    {
        ICoreWindowEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowFlyout :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowFlyout>
    {
        ICoreWindowFlyout(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowFlyout(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowFlyoutFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowFlyoutFactory>
    {
        ICoreWindowFlyoutFactory(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowFlyoutFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowPopupShowingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowPopupShowingEventArgs>
    {
        ICoreWindowPopupShowingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowPopupShowingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowResizeManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowResizeManager>
    {
        ICoreWindowResizeManager(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowResizeManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowResizeManagerLayoutCapability :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowResizeManagerLayoutCapability>
    {
        ICoreWindowResizeManagerLayoutCapability(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowResizeManagerLayoutCapability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowResizeManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowResizeManagerStatics>
    {
        ICoreWindowResizeManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowResizeManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowStatic :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowStatic>
    {
        ICoreWindowStatic(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowStatic(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowWithContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowWithContext>
    {
        ICoreWindowWithContext(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowWithContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IIdleDispatchedHandlerArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IIdleDispatchedHandlerArgs>
    {
        IIdleDispatchedHandlerArgs(std::nullptr_t = nullptr) noexcept {}
        IIdleDispatchedHandlerArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInitializeWithCoreWindow :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInitializeWithCoreWindow>
    {
        IInitializeWithCoreWindow(std::nullptr_t = nullptr) noexcept {}
        IInitializeWithCoreWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputEnabledEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputEnabledEventArgs>,
        impl::require<llm:OS::UI::Core::IInputEnabledEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IInputEnabledEventArgs(std::nullptr_t = nullptr) noexcept {}
        IInputEnabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyEventArgs>,
        impl::require<llm:OS::UI::Core::IKeyEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IKeyEventArgs(std::nullptr_t = nullptr) noexcept {}
        IKeyEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyEventArgs2>,
        impl::require<llm:OS::UI::Core::IKeyEventArgs2, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IKeyEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IKeyEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPointerEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPointerEventArgs>,
        impl::require<llm:OS::UI::Core::IPointerEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IPointerEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPointerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemNavigationManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemNavigationManager>
    {
        ISystemNavigationManager(std::nullptr_t = nullptr) noexcept {}
        ISystemNavigationManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemNavigationManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemNavigationManager2>
    {
        ISystemNavigationManager2(std::nullptr_t = nullptr) noexcept {}
        ISystemNavigationManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISystemNavigationManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISystemNavigationManagerStatics>
    {
        ISystemNavigationManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ISystemNavigationManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITouchHitTestingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITouchHitTestingEventArgs>,
        impl::require<llm:OS::UI::Core::ITouchHitTestingEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        ITouchHitTestingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ITouchHitTestingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisibilityChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisibilityChangedEventArgs>,
        impl::require<llm:OS::UI::Core::IVisibilityChangedEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IVisibilityChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVisibilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowActivatedEventArgs>,
        impl::require<llm:OS::UI::Core::IWindowActivatedEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IWindowActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowSizeChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowSizeChangedEventArgs>,
        impl::require<llm:OS::UI::Core::IWindowSizeChangedEventArgs, llm:OS::UI::Core::ICoreWindowEventArgs>
    {
        IWindowSizeChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowSizeChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
