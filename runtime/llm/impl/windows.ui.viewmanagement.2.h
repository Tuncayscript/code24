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
#ifndef LLM_OS_UI_ViewManagement_2_H
#define LLM_OS_UI_ViewManagement_2_H
#include "llm/impl/Windows.Devices.Enumeration.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.UI.Core.1.h"
#include "llm/impl/Windows.UI.Popups.1.h"
#include "llm/impl/Windows.UI.ViewManagement.1.h"
LLM_EXPORT namespace llm:OS::UI::ViewManagement
{
    struct __declspec(empty_bases) AccessibilitySettings : llm:OS::UI::ViewManagement::IAccessibilitySettings
    {
        AccessibilitySettings(std::nullptr_t) noexcept {}
        AccessibilitySettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IAccessibilitySettings(ptr, take_ownership_from_abi) {}
        AccessibilitySettings();
    };
    struct __declspec(empty_bases) ActivationViewSwitcher : llm:OS::UI::ViewManagement::IActivationViewSwitcher
    {
        ActivationViewSwitcher(std::nullptr_t) noexcept {}
        ActivationViewSwitcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IActivationViewSwitcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ApplicationView : llm:OS::UI::ViewManagement::IApplicationView,
        impl::require<ApplicationView, llm:OS::UI::ViewManagement::IApplicationView2, llm:OS::UI::ViewManagement::IApplicationView3, llm:OS::UI::ViewManagement::IApplicationView4, llm:OS::UI::ViewManagement::IApplicationView7, llm:OS::UI::ViewManagement::IApplicationView9, llm:OS::UI::ViewManagement::IApplicationViewWithContext>
    {
        ApplicationView(std::nullptr_t) noexcept {}
        ApplicationView(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IApplicationView(ptr, take_ownership_from_abi) {}
        static auto TryUnsnapToFullscreen();
        static auto GetApplicationViewIdForWindow(llm:OS::UI::Core::ICoreWindow const& window);
        [[nodiscard]] static auto Value();
        static auto TryUnsnap();
        static auto GetForCurrentView();
        [[nodiscard]] static auto TerminateAppOnFinalViewClose();
        static auto TerminateAppOnFinalViewClose(bool value);
        [[nodiscard]] static auto PreferredLaunchWindowingMode();
        static auto PreferredLaunchWindowingMode(llm:OS::UI::ViewManagement::ApplicationViewWindowingMode const& value);
        [[nodiscard]] static auto PreferredLaunchViewSize();
        static auto PreferredLaunchViewSize(llm:OS::Foundation::Size const& value);
        static auto ClearAllPersistedState();
        static auto ClearPersistedState(param::hstring const& key);
    };
    struct __declspec(empty_bases) ApplicationViewConsolidatedEventArgs : llm:OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs,
        impl::require<ApplicationViewConsolidatedEventArgs, llm:OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs2>
    {
        ApplicationViewConsolidatedEventArgs(std::nullptr_t) noexcept {}
        ApplicationViewConsolidatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ApplicationViewScaling : llm:OS::UI::ViewManagement::IApplicationViewScaling
    {
        ApplicationViewScaling(std::nullptr_t) noexcept {}
        ApplicationViewScaling(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IApplicationViewScaling(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto DisableLayoutScaling();
        static auto TrySetDisableLayoutScaling(bool disableLayoutScaling);
    };
    struct ApplicationViewSwitcher
    {
        ApplicationViewSwitcher() = delete;
        static auto DisableShowingMainViewOnActivation();
        static auto TryShowAsStandaloneAsync(int32_t viewId);
        static auto TryShowAsStandaloneAsync(int32_t viewId, llm:OS::UI::ViewManagement::ViewSizePreference const& sizePreference);
        static auto TryShowAsStandaloneAsync(int32_t viewId, llm:OS::UI::ViewManagement::ViewSizePreference const& sizePreference, int32_t anchorViewId, llm:OS::UI::ViewManagement::ViewSizePreference const& anchorSizePreference);
        static auto SwitchAsync(int32_t viewId);
        static auto SwitchAsync(int32_t toViewId, int32_t fromViewId);
        static auto SwitchAsync(int32_t toViewId, int32_t fromViewId, llm:OS::UI::ViewManagement::ApplicationViewSwitchingOptions const& options);
        static auto PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, llm:OS::UI::ViewManagement::ApplicationViewSwitchingOptions const& options);
        static auto DisableSystemViewActivationPolicy();
        static auto TryShowAsViewModeAsync(int32_t viewId, llm:OS::UI::ViewManagement::ApplicationViewMode const& viewMode);
        static auto TryShowAsViewModeAsync(int32_t viewId, llm:OS::UI::ViewManagement::ApplicationViewMode const& viewMode, llm:OS::UI::ViewManagement::ViewModePreferences const& viewModePreferences);
    };
    struct __declspec(empty_bases) ApplicationViewTitleBar : llm:OS::UI::ViewManagement::IApplicationViewTitleBar
    {
        ApplicationViewTitleBar(std::nullptr_t) noexcept {}
        ApplicationViewTitleBar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IApplicationViewTitleBar(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ApplicationViewTransferContext : llm:OS::UI::ViewManagement::IApplicationViewTransferContext
    {
        ApplicationViewTransferContext(std::nullptr_t) noexcept {}
        ApplicationViewTransferContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IApplicationViewTransferContext(ptr, take_ownership_from_abi) {}
        ApplicationViewTransferContext();
        [[nodiscard]] static auto DataPackageFormatId();
    };
    struct __declspec(empty_bases) InputPane : llm:OS::UI::ViewManagement::IInputPane,
        impl::require<InputPane, llm:OS::UI::ViewManagement::IInputPane2, llm:OS::UI::ViewManagement::IInputPaneControl>
    {
        InputPane(std::nullptr_t) noexcept {}
        InputPane(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IInputPane(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto GetForUIContext(llm:OS::UI::UIContext const& context);
    };
    struct __declspec(empty_bases) InputPaneVisibilityEventArgs : llm:OS::UI::ViewManagement::IInputPaneVisibilityEventArgs
    {
        InputPaneVisibilityEventArgs(std::nullptr_t) noexcept {}
        InputPaneVisibilityEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IInputPaneVisibilityEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct ProjectionManager
    {
        ProjectionManager() = delete;
        static auto StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId);
        static auto SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId);
        static auto StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId);
        [[nodiscard]] static auto ProjectionDisplayAvailable();
        static auto ProjectionDisplayAvailableChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using ProjectionDisplayAvailableChanged_revoker = impl::factory_event_revoker<llm:OS::UI::ViewManagement::IProjectionManagerStatics, &impl::abi_t<llm:OS::UI::ViewManagement::IProjectionManagerStatics>::remove_ProjectionDisplayAvailableChanged>;
        [[nodiscard]] static ProjectionDisplayAvailableChanged_revoker ProjectionDisplayAvailableChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto ProjectionDisplayAvailableChanged(llm::event_token const& token);
        static auto StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm:OS::Devices::Enumeration::DeviceInformation const& displayDeviceInfo);
        static auto RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm:OS::Foundation::Rect const& selection);
        static auto RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm:OS::Foundation::Rect const& selection, llm:OS::UI::Popups::Placement const& prefferedPlacement);
        static auto GetDeviceSelector();
    };
    struct __declspec(empty_bases) StatusBar : llm:OS::UI::ViewManagement::IStatusBar
    {
        StatusBar(std::nullptr_t) noexcept {}
        StatusBar(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IStatusBar(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) StatusBarProgressIndicator : llm:OS::UI::ViewManagement::IStatusBarProgressIndicator
    {
        StatusBarProgressIndicator(std::nullptr_t) noexcept {}
        StatusBarProgressIndicator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IStatusBarProgressIndicator(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UISettings : llm:OS::UI::ViewManagement::IUISettings,
        impl::require<UISettings, llm:OS::UI::ViewManagement::IUISettings2, llm:OS::UI::ViewManagement::IUISettings3, llm:OS::UI::ViewManagement::IUISettings4, llm:OS::UI::ViewManagement::IUISettings5, llm:OS::UI::ViewManagement::IUISettings6>
    {
        UISettings(std::nullptr_t) noexcept {}
        UISettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IUISettings(ptr, take_ownership_from_abi) {}
        UISettings();
    };
    struct __declspec(empty_bases) UISettingsAnimationsEnabledChangedEventArgs : llm:OS::UI::ViewManagement::IUISettingsAnimationsEnabledChangedEventArgs
    {
        UISettingsAnimationsEnabledChangedEventArgs(std::nullptr_t) noexcept {}
        UISettingsAnimationsEnabledChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IUISettingsAnimationsEnabledChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UISettingsAutoHideScrollBarsChangedEventArgs : llm:OS::UI::ViewManagement::IUISettingsAutoHideScrollBarsChangedEventArgs
    {
        UISettingsAutoHideScrollBarsChangedEventArgs(std::nullptr_t) noexcept {}
        UISettingsAutoHideScrollBarsChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IUISettingsAutoHideScrollBarsChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UISettingsMessageDurationChangedEventArgs : llm:OS::UI::ViewManagement::IUISettingsMessageDurationChangedEventArgs
    {
        UISettingsMessageDurationChangedEventArgs(std::nullptr_t) noexcept {}
        UISettingsMessageDurationChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IUISettingsMessageDurationChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UIViewSettings : llm:OS::UI::ViewManagement::IUIViewSettings
    {
        UIViewSettings(std::nullptr_t) noexcept {}
        UIViewSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IUIViewSettings(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) ViewModePreferences : llm:OS::UI::ViewManagement::IViewModePreferences
    {
        ViewModePreferences(std::nullptr_t) noexcept {}
        ViewModePreferences(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::ViewManagement::IViewModePreferences(ptr, take_ownership_from_abi) {}
        static auto CreateDefault(llm:OS::UI::ViewManagement::ApplicationViewMode const& mode);
    };
}
#endif
