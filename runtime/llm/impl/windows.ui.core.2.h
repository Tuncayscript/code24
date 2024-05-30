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
#ifndef LLM_OS_UI_Core_2_H
#define LLM_OS_UI_Core_2_H
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Core.1.h"
LLM_EXPORT namespace llm:OS::UI::Core
{
    struct DispatchedHandler : llm:OS::Foundation::IUnknown
    {
        DispatchedHandler(std::nullptr_t = nullptr) noexcept {}
        DispatchedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DispatchedHandler(L lambda);
        template <typename F> DispatchedHandler(F* function);
        template <typename O, typename M> DispatchedHandler(O* object, M method);
        template <typename O, typename M> DispatchedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DispatchedHandler(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    struct IdleDispatchedHandler : llm:OS::Foundation::IUnknown
    {
        IdleDispatchedHandler(std::nullptr_t = nullptr) noexcept {}
        IdleDispatchedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> IdleDispatchedHandler(L lambda);
        template <typename F> IdleDispatchedHandler(F* function);
        template <typename O, typename M> IdleDispatchedHandler(O* object, M method);
        template <typename O, typename M> IdleDispatchedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> IdleDispatchedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::UI::Core::IdleDispatchedHandlerArgs const& e) const;
    };
    struct CorePhysicalKeyStatus
    {
        uint32_t RepeatCount;
        uint32_t ScanCode;
        bool IsExtendedKey;
        bool IsMenuKeyDown;
        bool WasKeyDown;
        bool IsKeyReleased;
    };
    inline bool operator==(CorePhysicalKeyStatus const& left, CorePhysicalKeyStatus const& right) noexcept
    {
        return left.RepeatCount == right.RepeatCount && left.ScanCode == right.ScanCode && left.IsExtendedKey == right.IsExtendedKey && left.IsMenuKeyDown == right.IsMenuKeyDown && left.WasKeyDown == right.WasKeyDown && left.IsKeyReleased == right.IsKeyReleased;
    }
    inline bool operator!=(CorePhysicalKeyStatus const& left, CorePhysicalKeyStatus const& right) noexcept
    {
        return !(left == right);
    }
    struct CoreProximityEvaluation
    {
        int32_t Score;
        llm:OS::Foundation::Point AdjustedPoint;
    };
    inline bool operator==(CoreProximityEvaluation const& left, CoreProximityEvaluation const& right) noexcept
    {
        return left.Score == right.Score && left.AdjustedPoint == right.AdjustedPoint;
    }
    inline bool operator!=(CoreProximityEvaluation const& left, CoreProximityEvaluation const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AcceleratorKeyEventArgs : llm:OS::UI::Core::IAcceleratorKeyEventArgs,
        impl::require<AcceleratorKeyEventArgs, llm:OS::UI::Core::IAcceleratorKeyEventArgs2>
    {
        AcceleratorKeyEventArgs(std::nullptr_t) noexcept {}
        AcceleratorKeyEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IAcceleratorKeyEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AutomationProviderRequestedEventArgs : llm:OS::UI::Core::IAutomationProviderRequestedEventArgs
    {
        AutomationProviderRequestedEventArgs(std::nullptr_t) noexcept {}
        AutomationProviderRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IAutomationProviderRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BackRequestedEventArgs : llm:OS::UI::Core::IBackRequestedEventArgs
    {
        BackRequestedEventArgs(std::nullptr_t) noexcept {}
        BackRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IBackRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CharacterReceivedEventArgs : llm:OS::UI::Core::ICharacterReceivedEventArgs
    {
        CharacterReceivedEventArgs(std::nullptr_t) noexcept {}
        CharacterReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICharacterReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ClosestInteractiveBoundsRequestedEventArgs : llm:OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs
    {
        ClosestInteractiveBoundsRequestedEventArgs(std::nullptr_t) noexcept {}
        ClosestInteractiveBoundsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreAcceleratorKeys : llm:OS::UI::Core::ICoreAcceleratorKeys
    {
        CoreAcceleratorKeys(std::nullptr_t) noexcept {}
        CoreAcceleratorKeys(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreAcceleratorKeys(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreComponentInputSource : llm:OS::UI::Core::ICoreInputSourceBase,
        impl::require<CoreComponentInputSource, llm:OS::UI::Core::ICorePointerInputSource, llm:OS::UI::Core::ICoreKeyboardInputSource, llm:OS::UI::Core::ICoreComponentFocusable, llm:OS::UI::Core::ICoreTouchHitTesting, llm:OS::UI::Core::ICoreClosestInteractiveBoundsRequested, llm:OS::UI::Core::ICoreKeyboardInputSource2, llm:OS::UI::Core::ICorePointerInputSource2>
    {
        CoreComponentInputSource(std::nullptr_t) noexcept {}
        CoreComponentInputSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreInputSourceBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreCursor : llm:OS::UI::Core::ICoreCursor
    {
        CoreCursor(std::nullptr_t) noexcept {}
        CoreCursor(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreCursor(ptr, take_ownership_from_abi) {}
        CoreCursor(llm:OS::UI::Core::CoreCursorType const& type, uint32_t id);
    };
    struct __declspec(empty_bases) CoreDispatcher : llm:OS::UI::Core::ICoreDispatcher,
        impl::require<CoreDispatcher, llm:OS::UI::Core::ICoreDispatcherWithTaskPriority, llm:OS::UI::Core::ICoreDispatcher2>
    {
        CoreDispatcher(std::nullptr_t) noexcept {}
        CoreDispatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreDispatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreIndependentInputSource : llm:OS::UI::Core::ICoreInputSourceBase,
        impl::require<CoreIndependentInputSource, llm:OS::UI::Core::ICorePointerInputSource, llm:OS::UI::Core::ICorePointerInputSource2, llm:OS::UI::Core::ICorePointerRedirector>
    {
        CoreIndependentInputSource(std::nullptr_t) noexcept {}
        CoreIndependentInputSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreInputSourceBase(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreIndependentInputSourceController : llm:OS::UI::Core::ICoreIndependentInputSourceController,
        impl::require<CoreIndependentInputSourceController, llm:OS::Foundation::IClosable>
    {
        CoreIndependentInputSourceController(std::nullptr_t) noexcept {}
        CoreIndependentInputSourceController(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreIndependentInputSourceController(ptr, take_ownership_from_abi) {}
        static auto CreateForVisual(llm:OS::UI::Composition::Visual const& visual);
        static auto CreateForIVisualElement(llm:OS::UI::Composition::IVisualElement const& visualElement);
    };
    struct __declspec(empty_bases) CoreWindow : llm:OS::UI::Core::ICoreWindow,
        impl::require<CoreWindow, llm:OS::UI::Core::ICoreWindow2, llm:OS::UI::Core::ICorePointerRedirector, llm:OS::UI::Core::ICoreWindow3, llm:OS::UI::Core::ICoreWindow4, llm:OS::UI::Core::ICoreWindow5, llm:OS::UI::Core::ICoreWindowWithContext>
    {
        CoreWindow(std::nullptr_t) noexcept {}
        CoreWindow(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreWindow(ptr, take_ownership_from_abi) {}
        using llm:OS::UI::Core::ICoreWindow::PointerPosition;
        using impl::consume_t<CoreWindow, llm:OS::UI::Core::ICoreWindow2>::PointerPosition;
        static auto GetForCurrentThread();
    };
    struct __declspec(empty_bases) CoreWindowDialog : llm:OS::UI::Core::ICoreWindowDialog
    {
        CoreWindowDialog(std::nullptr_t) noexcept {}
        CoreWindowDialog(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreWindowDialog(ptr, take_ownership_from_abi) {}
        CoreWindowDialog();
        explicit CoreWindowDialog(param::hstring const& title);
    };
    struct __declspec(empty_bases) CoreWindowEventArgs : llm:OS::UI::Core::ICoreWindowEventArgs
    {
        CoreWindowEventArgs(std::nullptr_t) noexcept {}
        CoreWindowEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreWindowEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreWindowFlyout : llm:OS::UI::Core::ICoreWindowFlyout
    {
        CoreWindowFlyout(std::nullptr_t) noexcept {}
        CoreWindowFlyout(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreWindowFlyout(ptr, take_ownership_from_abi) {}
        explicit CoreWindowFlyout(llm:OS::Foundation::Point const& position);
        CoreWindowFlyout(llm:OS::Foundation::Point const& position, param::hstring const& title);
    };
    struct __declspec(empty_bases) CoreWindowPopupShowingEventArgs : llm:OS::UI::Core::ICoreWindowPopupShowingEventArgs
    {
        CoreWindowPopupShowingEventArgs(std::nullptr_t) noexcept {}
        CoreWindowPopupShowingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreWindowPopupShowingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreWindowResizeManager : llm:OS::UI::Core::ICoreWindowResizeManager,
        impl::require<CoreWindowResizeManager, llm:OS::UI::Core::ICoreWindowResizeManagerLayoutCapability>
    {
        CoreWindowResizeManager(std::nullptr_t) noexcept {}
        CoreWindowResizeManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ICoreWindowResizeManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) IdleDispatchedHandlerArgs : llm:OS::UI::Core::IIdleDispatchedHandlerArgs
    {
        IdleDispatchedHandlerArgs(std::nullptr_t) noexcept {}
        IdleDispatchedHandlerArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IIdleDispatchedHandlerArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) InputEnabledEventArgs : llm:OS::UI::Core::IInputEnabledEventArgs
    {
        InputEnabledEventArgs(std::nullptr_t) noexcept {}
        InputEnabledEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IInputEnabledEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeyEventArgs : llm:OS::UI::Core::IKeyEventArgs,
        impl::require<KeyEventArgs, llm:OS::UI::Core::IKeyEventArgs2>
    {
        KeyEventArgs(std::nullptr_t) noexcept {}
        KeyEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IKeyEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PointerEventArgs : llm:OS::UI::Core::IPointerEventArgs
    {
        PointerEventArgs(std::nullptr_t) noexcept {}
        PointerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IPointerEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemNavigationManager : llm:OS::UI::Core::ISystemNavigationManager,
        impl::require<SystemNavigationManager, llm:OS::UI::Core::ISystemNavigationManager2>
    {
        SystemNavigationManager(std::nullptr_t) noexcept {}
        SystemNavigationManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ISystemNavigationManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) TouchHitTestingEventArgs : llm:OS::UI::Core::ITouchHitTestingEventArgs
    {
        TouchHitTestingEventArgs(std::nullptr_t) noexcept {}
        TouchHitTestingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::ITouchHitTestingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VisibilityChangedEventArgs : llm:OS::UI::Core::IVisibilityChangedEventArgs
    {
        VisibilityChangedEventArgs(std::nullptr_t) noexcept {}
        VisibilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IVisibilityChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowActivatedEventArgs : llm:OS::UI::Core::IWindowActivatedEventArgs
    {
        WindowActivatedEventArgs(std::nullptr_t) noexcept {}
        WindowActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IWindowActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowSizeChangedEventArgs : llm:OS::UI::Core::IWindowSizeChangedEventArgs
    {
        WindowSizeChangedEventArgs(std::nullptr_t) noexcept {}
        WindowSizeChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Core::IWindowSizeChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
