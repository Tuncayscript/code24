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
#ifndef LLM_OS_UI_Xaml_Hosting_2_H
#define LLM_OS_UI_Xaml_Hosting_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.Composition.1.h"
#include "llm/impl/Windows.UI.WindowManagement.1.h"
#include "llm/impl/Windows.UI.Xaml.1.h"
#include "llm/impl/Windows.UI.Xaml.Controls.1.h"
#include "llm/impl/Windows.UI.Xaml.Controls.Primitives.1.h"
#include "llm/impl/Windows.UI.Xaml.Hosting.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Hosting
{
    struct __declspec(empty_bases) DesignerAppExitedEventArgs : llm::OS::UI::Xaml::Hosting::IDesignerAppExitedEventArgs
    {
        DesignerAppExitedEventArgs(std::nullptr_t) noexcept {}
        DesignerAppExitedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IDesignerAppExitedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DesignerAppManager : llm::OS::UI::Xaml::Hosting::IDesignerAppManager,
        impl::require<DesignerAppManager, llm::OS::Foundation::IClosable>
    {
        DesignerAppManager(std::nullptr_t) noexcept {}
        DesignerAppManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IDesignerAppManager(ptr, take_ownership_from_abi) {}
        explicit DesignerAppManager(param::hstring const& appUserModelId);
    };
    struct __declspec(empty_bases) DesignerAppView : llm::OS::UI::Xaml::Hosting::IDesignerAppView,
        impl::require<DesignerAppView, llm::OS::Foundation::IClosable>
    {
        DesignerAppView(std::nullptr_t) noexcept {}
        DesignerAppView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IDesignerAppView(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DesktopWindowXamlSource : llm::OS::UI::Xaml::Hosting::IDesktopWindowXamlSource,
        impl::require<DesktopWindowXamlSource, llm::OS::Foundation::IClosable>
    {
        DesktopWindowXamlSource(std::nullptr_t) noexcept {}
        DesktopWindowXamlSource(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IDesktopWindowXamlSource(ptr, take_ownership_from_abi) {}
        DesktopWindowXamlSource();
    };
    struct __declspec(empty_bases) DesktopWindowXamlSourceGotFocusEventArgs : llm::OS::UI::Xaml::Hosting::IDesktopWindowXamlSourceGotFocusEventArgs
    {
        DesktopWindowXamlSourceGotFocusEventArgs(std::nullptr_t) noexcept {}
        DesktopWindowXamlSourceGotFocusEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IDesktopWindowXamlSourceGotFocusEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DesktopWindowXamlSourceTakeFocusRequestedEventArgs : llm::OS::UI::Xaml::Hosting::IDesktopWindowXamlSourceTakeFocusRequestedEventArgs
    {
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs(std::nullptr_t) noexcept {}
        DesktopWindowXamlSourceTakeFocusRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IDesktopWindowXamlSourceTakeFocusRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ElementCompositionPreview : llm::OS::UI::Xaml::Hosting::IElementCompositionPreview
    {
        ElementCompositionPreview(std::nullptr_t) noexcept {}
        ElementCompositionPreview(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IElementCompositionPreview(ptr, take_ownership_from_abi) {}
        static auto GetElementVisual(llm::OS::UI::Xaml::UIElement const& element);
        static auto GetElementChildVisual(llm::OS::UI::Xaml::UIElement const& element);
        static auto SetElementChildVisual(llm::OS::UI::Xaml::UIElement const& element, llm::OS::UI::Composition::Visual const& visual);
        static auto GetScrollViewerManipulationPropertySet(llm::OS::UI::Xaml::Controls::ScrollViewer const& scrollViewer);
        static auto SetImplicitShowAnimation(llm::OS::UI::Xaml::UIElement const& element, llm::OS::UI::Composition::ICompositionAnimationBase const& animation);
        static auto SetImplicitHideAnimation(llm::OS::UI::Xaml::UIElement const& element, llm::OS::UI::Composition::ICompositionAnimationBase const& animation);
        static auto SetIsTranslationEnabled(llm::OS::UI::Xaml::UIElement const& element, bool value);
        static auto GetPointerPositionPropertySet(llm::OS::UI::Xaml::UIElement const& targetElement);
        static auto SetAppWindowContent(llm::OS::UI::WindowManagement::AppWindow const& appWindow, llm::OS::UI::Xaml::UIElement const& xamlContent);
        static auto GetAppWindowContent(llm::OS::UI::WindowManagement::AppWindow const& appWindow);
    };
    struct __declspec(empty_bases) WindowsXamlManager : llm::OS::UI::Xaml::Hosting::IWindowsXamlManager,
        impl::require<WindowsXamlManager, llm::OS::Foundation::IClosable>
    {
        WindowsXamlManager(std::nullptr_t) noexcept {}
        WindowsXamlManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IWindowsXamlManager(ptr, take_ownership_from_abi) {}
        static auto InitializeForCurrentThread();
    };
    struct __declspec(empty_bases) XamlSourceFocusNavigationRequest : llm::OS::UI::Xaml::Hosting::IXamlSourceFocusNavigationRequest
    {
        XamlSourceFocusNavigationRequest(std::nullptr_t) noexcept {}
        XamlSourceFocusNavigationRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IXamlSourceFocusNavigationRequest(ptr, take_ownership_from_abi) {}
        explicit XamlSourceFocusNavigationRequest(llm::OS::UI::Xaml::Hosting::XamlSourceFocusNavigationReason const& reason);
        XamlSourceFocusNavigationRequest(llm::OS::UI::Xaml::Hosting::XamlSourceFocusNavigationReason const& reason, llm::OS::Foundation::Rect const& hintRect);
        XamlSourceFocusNavigationRequest(llm::OS::UI::Xaml::Hosting::XamlSourceFocusNavigationReason const& reason, llm::OS::Foundation::Rect const& hintRect, llm::guid const& correlationId);
    };
    struct __declspec(empty_bases) XamlSourceFocusNavigationResult : llm::OS::UI::Xaml::Hosting::IXamlSourceFocusNavigationResult
    {
        XamlSourceFocusNavigationResult(std::nullptr_t) noexcept {}
        XamlSourceFocusNavigationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IXamlSourceFocusNavigationResult(ptr, take_ownership_from_abi) {}
        explicit XamlSourceFocusNavigationResult(bool focusMoved);
    };
    struct __declspec(empty_bases) XamlUIPresenter : llm::OS::UI::Xaml::Hosting::IXamlUIPresenter
    {
        XamlUIPresenter(std::nullptr_t) noexcept {}
        XamlUIPresenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Hosting::IXamlUIPresenter(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto CompleteTimelinesAutomatically();
        static auto CompleteTimelinesAutomatically(bool value);
        static auto SetHost(llm::OS::UI::Xaml::Hosting::IXamlUIPresenterHost const& host);
        static auto NotifyWindowSizeChanged();
        static auto GetFlyoutPlacementTargetInfo(llm::OS::UI::Xaml::FrameworkElement const& placementTarget, llm::OS::UI::Xaml::Controls::Primitives::FlyoutPlacementMode const& preferredPlacement, llm::OS::UI::Xaml::Controls::Primitives::FlyoutPlacementMode& targetPreferredPlacement, bool& allowFallbacks);
        static auto GetFlyoutPlacement(llm::OS::Foundation::Rect const& placementTargetBounds, llm::OS::Foundation::Size const& controlSize, llm::OS::Foundation::Size const& minControlSize, llm::OS::Foundation::Rect const& containerRect, llm::OS::UI::Xaml::Controls::Primitives::FlyoutPlacementMode const& targetPreferredPlacement, bool allowFallbacks, llm::OS::UI::Xaml::Controls::Primitives::FlyoutPlacementMode& chosenPlacement);
    };
}
#endif
