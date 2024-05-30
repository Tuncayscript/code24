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
#ifndef LLM_OS_UI_ViewManagement_1_H
#define LLM_OS_UI_ViewManagement_1_H
#include "llm/impl/Windows.UI.ViewManagement.0.h"
LLM_EXPORT namespace llm:OS::UI::ViewManagement
{
    struct __declspec(empty_bases) IAccessibilitySettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAccessibilitySettings>
    {
        IAccessibilitySettings(std::nullptr_t = nullptr) noexcept {}
        IAccessibilitySettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IActivationViewSwitcher :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IActivationViewSwitcher>
    {
        IActivationViewSwitcher(std::nullptr_t = nullptr) noexcept {}
        IActivationViewSwitcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationView :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationView>
    {
        IApplicationView(std::nullptr_t = nullptr) noexcept {}
        IApplicationView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationView2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationView2>
    {
        IApplicationView2(std::nullptr_t = nullptr) noexcept {}
        IApplicationView2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationView3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationView3>
    {
        IApplicationView3(std::nullptr_t = nullptr) noexcept {}
        IApplicationView3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationView4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationView4>
    {
        IApplicationView4(std::nullptr_t = nullptr) noexcept {}
        IApplicationView4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationView7 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationView7>
    {
        IApplicationView7(std::nullptr_t = nullptr) noexcept {}
        IApplicationView7(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationView9 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationView9>
    {
        IApplicationView9(std::nullptr_t = nullptr) noexcept {}
        IApplicationView9(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewConsolidatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewConsolidatedEventArgs>
    {
        IApplicationViewConsolidatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewConsolidatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewConsolidatedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewConsolidatedEventArgs2>
    {
        IApplicationViewConsolidatedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewConsolidatedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewFullscreenStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewFullscreenStatics>
    {
        IApplicationViewFullscreenStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewFullscreenStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewInteropStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewInteropStatics>
    {
        IApplicationViewInteropStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewInteropStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewScaling :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewScaling>
    {
        IApplicationViewScaling(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewScaling(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewScalingStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewScalingStatics>
    {
        IApplicationViewScalingStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewScalingStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewStatics>
    {
        IApplicationViewStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewStatics2>
    {
        IApplicationViewStatics2(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewStatics3>
    {
        IApplicationViewStatics3(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewStatics4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewStatics4>
    {
        IApplicationViewStatics4(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewSwitcherStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewSwitcherStatics>
    {
        IApplicationViewSwitcherStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewSwitcherStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewSwitcherStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewSwitcherStatics2>
    {
        IApplicationViewSwitcherStatics2(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewSwitcherStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewSwitcherStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewSwitcherStatics3>
    {
        IApplicationViewSwitcherStatics3(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewSwitcherStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewTitleBar :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewTitleBar>
    {
        IApplicationViewTitleBar(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewTitleBar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewTransferContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewTransferContext>
    {
        IApplicationViewTransferContext(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewTransferContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewTransferContextStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewTransferContextStatics>
    {
        IApplicationViewTransferContextStatics(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewTransferContextStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IApplicationViewWithContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IApplicationViewWithContext>
    {
        IApplicationViewWithContext(std::nullptr_t = nullptr) noexcept {}
        IApplicationViewWithContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputPane :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputPane>
    {
        IInputPane(std::nullptr_t = nullptr) noexcept {}
        IInputPane(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputPane2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputPane2>
    {
        IInputPane2(std::nullptr_t = nullptr) noexcept {}
        IInputPane2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputPaneControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputPaneControl>
    {
        IInputPaneControl(std::nullptr_t = nullptr) noexcept {}
        IInputPaneControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputPaneStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputPaneStatics>
    {
        IInputPaneStatics(std::nullptr_t = nullptr) noexcept {}
        IInputPaneStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputPaneStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputPaneStatics2>
    {
        IInputPaneStatics2(std::nullptr_t = nullptr) noexcept {}
        IInputPaneStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInputPaneVisibilityEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInputPaneVisibilityEventArgs>
    {
        IInputPaneVisibilityEventArgs(std::nullptr_t = nullptr) noexcept {}
        IInputPaneVisibilityEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProjectionManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProjectionManagerStatics>
    {
        IProjectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IProjectionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProjectionManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProjectionManagerStatics2>
    {
        IProjectionManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IProjectionManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStatusBar :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStatusBar>
    {
        IStatusBar(std::nullptr_t = nullptr) noexcept {}
        IStatusBar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStatusBarProgressIndicator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStatusBarProgressIndicator>
    {
        IStatusBarProgressIndicator(std::nullptr_t = nullptr) noexcept {}
        IStatusBarProgressIndicator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStatusBarStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStatusBarStatics>
    {
        IStatusBarStatics(std::nullptr_t = nullptr) noexcept {}
        IStatusBarStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettings>
    {
        IUISettings(std::nullptr_t = nullptr) noexcept {}
        IUISettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettings2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettings2>
    {
        IUISettings2(std::nullptr_t = nullptr) noexcept {}
        IUISettings2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettings3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettings3>
    {
        IUISettings3(std::nullptr_t = nullptr) noexcept {}
        IUISettings3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettings4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettings4>
    {
        IUISettings4(std::nullptr_t = nullptr) noexcept {}
        IUISettings4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettings5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettings5>
    {
        IUISettings5(std::nullptr_t = nullptr) noexcept {}
        IUISettings5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettings6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettings6>
    {
        IUISettings6(std::nullptr_t = nullptr) noexcept {}
        IUISettings6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettingsAnimationsEnabledChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettingsAnimationsEnabledChangedEventArgs>
    {
        IUISettingsAnimationsEnabledChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUISettingsAnimationsEnabledChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettingsAutoHideScrollBarsChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettingsAutoHideScrollBarsChangedEventArgs>
    {
        IUISettingsAutoHideScrollBarsChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUISettingsAutoHideScrollBarsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUISettingsMessageDurationChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUISettingsMessageDurationChangedEventArgs>
    {
        IUISettingsMessageDurationChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUISettingsMessageDurationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUIViewSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUIViewSettings>
    {
        IUIViewSettings(std::nullptr_t = nullptr) noexcept {}
        IUIViewSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUIViewSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUIViewSettingsStatics>
    {
        IUIViewSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IUIViewSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IViewModePreferences :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IViewModePreferences>
    {
        IViewModePreferences(std::nullptr_t = nullptr) noexcept {}
        IViewModePreferences(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IViewModePreferencesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IViewModePreferencesStatics>
    {
        IViewModePreferencesStatics(std::nullptr_t = nullptr) noexcept {}
        IViewModePreferencesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
