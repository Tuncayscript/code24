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
#ifndef LLM_OS_UI_ViewManagement_H
#define LLM_OS_UI_ViewManagement_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.UI.WindowManagement.2.h"
#include "llm/impl/Windows.UI.ViewManagement.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IAccessibilitySettings<D>::HighContrast() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IAccessibilitySettings)->get_HighContrast(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ViewManagement_IAccessibilitySettings<D>::HighContrastScheme() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IAccessibilitySettings)->get_HighContrastScheme(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IAccessibilitySettings<D>::HighContrastChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::AccessibilitySettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IAccessibilitySettings)->add_HighContrastChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IAccessibilitySettings<D>::HighContrastChanged_revoker consume_Windows_UI_ViewManagement_IAccessibilitySettings<D>::HighContrastChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::AccessibilitySettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, HighContrastChanged_revoker>(this, HighContrastChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IAccessibilitySettings<D>::HighContrastChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IAccessibilitySettings)->remove_HighContrastChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IActivationViewSwitcher<D>::ShowAsStandaloneAsync(int32_t viewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IActivationViewSwitcher)->ShowAsStandaloneAsync(viewId, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IActivationViewSwitcher<D>::ShowAsStandaloneAsync(int32_t viewId, llm::OS::UI::ViewManagement::ViewSizePreference const& sizePreference) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IActivationViewSwitcher)->ShowAsStandaloneWithSizePreferenceAsync(viewId, static_cast<int32_t>(sizePreference), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IActivationViewSwitcher<D>::IsViewPresentedOnActivationVirtualDesktop(int32_t viewId) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IActivationViewSwitcher)->IsViewPresentedOnActivationVirtualDesktop(viewId, &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationViewOrientation) consume_Windows_UI_ViewManagement_IApplicationView<D>::Orientation() const
    {
        llm::OS::UI::ViewManagement::ApplicationViewOrientation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_Orientation(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView<D>::AdjacentToLeftDisplayEdge() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_AdjacentToLeftDisplayEdge(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView<D>::AdjacentToRightDisplayEdge() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_AdjacentToRightDisplayEdge(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView<D>::IsFullScreen() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_IsFullScreen(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView<D>::IsOnLockScreen() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_IsOnLockScreen(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView<D>::IsScreenCaptureEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_IsScreenCaptureEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView<D>::IsScreenCaptureEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->put_IsScreenCaptureEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ViewManagement_IApplicationView<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_ViewManagement_IApplicationView<D>::Id() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->get_Id(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IApplicationView<D>::Consolidated(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::ApplicationView, llm::OS::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->add_Consolidated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IApplicationView<D>::Consolidated_revoker consume_Windows_UI_ViewManagement_IApplicationView<D>::Consolidated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::ApplicationView, llm::OS::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Consolidated_revoker>(this, Consolidated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView<D>::Consolidated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView)->remove_Consolidated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView2<D>::SuppressSystemOverlays() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->get_SuppressSystemOverlays(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView2<D>::SuppressSystemOverlays(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->put_SuppressSystemOverlays(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_ViewManagement_IApplicationView2<D>::VisibleBounds() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->get_VisibleBounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IApplicationView2<D>::VisibleBoundsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::ApplicationView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->add_VisibleBoundsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IApplicationView2<D>::VisibleBoundsChanged_revoker consume_Windows_UI_ViewManagement_IApplicationView2<D>::VisibleBoundsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::ApplicationView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, VisibleBoundsChanged_revoker>(this, VisibleBoundsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView2<D>::VisibleBoundsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->remove_VisibleBoundsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView2<D>::SetDesiredBoundsMode(llm::OS::UI::ViewManagement::ApplicationViewBoundsMode const& boundsMode) const
    {
        bool success{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->SetDesiredBoundsMode(static_cast<int32_t>(boundsMode), &success));
        return success;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationViewBoundsMode) consume_Windows_UI_ViewManagement_IApplicationView2<D>::DesiredBoundsMode() const
    {
        llm::OS::UI::ViewManagement::ApplicationViewBoundsMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView2)->get_DesiredBoundsMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationViewTitleBar) consume_Windows_UI_ViewManagement_IApplicationView3<D>::TitleBar() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->get_TitleBar(&value));
        return llm::OS::UI::ViewManagement::ApplicationViewTitleBar{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::FullScreenSystemOverlayMode) consume_Windows_UI_ViewManagement_IApplicationView3<D>::FullScreenSystemOverlayMode() const
    {
        llm::OS::UI::ViewManagement::FullScreenSystemOverlayMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->get_FullScreenSystemOverlayMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView3<D>::FullScreenSystemOverlayMode(llm::OS::UI::ViewManagement::FullScreenSystemOverlayMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->put_FullScreenSystemOverlayMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView3<D>::IsFullScreenMode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->get_IsFullScreenMode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView3<D>::TryEnterFullScreenMode() const
    {
        bool success{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->TryEnterFullScreenMode(&success));
        return success;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView3<D>::ExitFullScreenMode() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->ExitFullScreenMode());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView3<D>::ShowStandardSystemOverlays() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->ShowStandardSystemOverlays());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView3<D>::TryResizeView(llm::OS::Foundation::Size const& value) const
    {
        bool success{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->TryResizeView(impl::bind_in(value), &success));
        return success;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView3<D>::SetPreferredMinSize(llm::OS::Foundation::Size const& minSize) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView3)->SetPreferredMinSize(impl::bind_in(minSize)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationViewMode) consume_Windows_UI_ViewManagement_IApplicationView4<D>::ViewMode() const
    {
        llm::OS::UI::ViewManagement::ApplicationViewMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView4)->get_ViewMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationView4<D>::IsViewModeSupported(llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode) const
    {
        bool isViewModeSupported{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView4)->IsViewModeSupported(static_cast<int32_t>(viewMode), &isViewModeSupported));
        return isViewModeSupported;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationView4<D>::TryEnterViewModeAsync(llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView4)->TryEnterViewModeAsync(static_cast<int32_t>(viewMode), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationView4<D>::TryEnterViewModeAsync(llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode, llm::OS::UI::ViewManagement::ViewModePreferences const& viewModePreferences) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView4)->TryEnterViewModeWithPreferencesAsync(static_cast<int32_t>(viewMode), *(void**)(&viewModePreferences), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationView4<D>::TryConsolidateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView4)->TryConsolidateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ViewManagement_IApplicationView7<D>::PersistedStateId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView7)->get_PersistedStateId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationView7<D>::PersistedStateId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView7)->put_PersistedStateId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) consume_Windows_UI_ViewManagement_IApplicationView9<D>::WindowingEnvironment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView9)->get_WindowingEnvironment(&value));
        return llm::OS::UI::WindowManagement::WindowingEnvironment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>) consume_Windows_UI_ViewManagement_IApplicationView9<D>::GetDisplayRegions() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationView9)->GetDisplayRegions(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewConsolidatedEventArgs<D>::IsUserInitiated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs)->get_IsUserInitiated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewConsolidatedEventArgs2<D>::IsAppInitiated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs2)->get_IsAppInitiated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewFullscreenStatics<D>::TryUnsnapToFullscreen() const
    {
        bool success{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewFullscreenStatics)->TryUnsnapToFullscreen(&success));
        return success;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_ViewManagement_IApplicationViewInteropStatics<D>::GetApplicationViewIdForWindow(llm::OS::UI::Core::ICoreWindow const& window) const
    {
        int32_t id{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewInteropStatics)->GetApplicationViewIdForWindow(*(void**)(&window), &id));
        return id;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewScalingStatics<D>::DisableLayoutScaling() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewScalingStatics)->get_DisableLayoutScaling(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewScalingStatics<D>::TrySetDisableLayoutScaling(bool disableLayoutScaling) const
    {
        bool success{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewScalingStatics)->TrySetDisableLayoutScaling(disableLayoutScaling, &success));
        return success;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationViewState) consume_Windows_UI_ViewManagement_IApplicationViewStatics<D>::Value() const
    {
        llm::OS::UI::ViewManagement::ApplicationViewState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics)->get_Value(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewStatics<D>::TryUnsnap() const
    {
        bool success{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics)->TryUnsnap(&success));
        return success;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationView) consume_Windows_UI_ViewManagement_IApplicationViewStatics2<D>::GetForCurrentView() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics2)->GetForCurrentView(&current));
        return llm::OS::UI::ViewManagement::ApplicationView{ current, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IApplicationViewStatics2<D>::TerminateAppOnFinalViewClose() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics2)->get_TerminateAppOnFinalViewClose(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewStatics2<D>::TerminateAppOnFinalViewClose(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics2)->put_TerminateAppOnFinalViewClose(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ApplicationViewWindowingMode) consume_Windows_UI_ViewManagement_IApplicationViewStatics3<D>::PreferredLaunchWindowingMode() const
    {
        llm::OS::UI::ViewManagement::ApplicationViewWindowingMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics3)->get_PreferredLaunchWindowingMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewStatics3<D>::PreferredLaunchWindowingMode(llm::OS::UI::ViewManagement::ApplicationViewWindowingMode const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics3)->put_PreferredLaunchWindowingMode(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_ViewManagement_IApplicationViewStatics3<D>::PreferredLaunchViewSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics3)->get_PreferredLaunchViewSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewStatics3<D>::PreferredLaunchViewSize(llm::OS::Foundation::Size const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics3)->put_PreferredLaunchViewSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewStatics4<D>::ClearAllPersistedState() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics4)->ClearAllPersistedState());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewStatics4<D>::ClearPersistedState(param::hstring const& key) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewStatics4)->ClearPersistedState(*(void**)(&key)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::DisableShowingMainViewOnActivation() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->DisableShowingMainViewOnActivation());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::TryShowAsStandaloneAsync(int32_t viewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->TryShowAsStandaloneAsync(viewId, &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::TryShowAsStandaloneAsync(int32_t viewId, llm::OS::UI::ViewManagement::ViewSizePreference const& sizePreference) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->TryShowAsStandaloneWithSizePreferenceAsync(viewId, static_cast<int32_t>(sizePreference), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::TryShowAsStandaloneAsync(int32_t viewId, llm::OS::UI::ViewManagement::ViewSizePreference const& sizePreference, int32_t anchorViewId, llm::OS::UI::ViewManagement::ViewSizePreference const& anchorSizePreference) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->TryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync(viewId, static_cast<int32_t>(sizePreference), anchorViewId, static_cast<int32_t>(anchorSizePreference), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::SwitchAsync(int32_t viewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->SwitchAsync(viewId, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::SwitchAsync(int32_t toViewId, int32_t fromViewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->SwitchFromViewAsync(toViewId, fromViewId, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::SwitchAsync(int32_t toViewId, int32_t fromViewId, llm::OS::UI::ViewManagement::ApplicationViewSwitchingOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->SwitchFromViewWithOptionsAsync(toViewId, fromViewId, static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics<D>::PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, llm::OS::UI::ViewManagement::ApplicationViewSwitchingOptions const& options) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics)->PrepareForCustomAnimatedSwitchAsync(toViewId, fromViewId, static_cast<uint32_t>(options), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics2<D>::DisableSystemViewActivationPolicy() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics2)->DisableSystemViewActivationPolicy());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics3<D>::TryShowAsViewModeAsync(int32_t viewId, llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics3)->TryShowAsViewModeAsync(viewId, static_cast<int32_t>(viewMode), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IApplicationViewSwitcherStatics3<D>::TryShowAsViewModeAsync(int32_t viewId, llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode, llm::OS::UI::ViewManagement::ViewModePreferences const& viewModePreferences) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics3)->TryShowAsViewModeWithPreferencesAsync(viewId, static_cast<int32_t>(viewMode), *(void**)(&viewModePreferences), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::BackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_BackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::BackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_BackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonHoverForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonHoverForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonHoverForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonHoverForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonHoverBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonHoverBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonHoverBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonHoverBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonPressedForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonPressedForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonPressedForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonPressedForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonPressedBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonPressedBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonPressedBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonPressedBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::InactiveForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_InactiveForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::InactiveForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_InactiveForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::InactiveBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_InactiveBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::InactiveBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_InactiveBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonInactiveForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonInactiveForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonInactiveForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonInactiveForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonInactiveBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->put_ButtonInactiveBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IApplicationViewTitleBar<D>::ButtonInactiveBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTitleBar)->get_ButtonInactiveBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_ViewManagement_IApplicationViewTransferContext<D>::ViewId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTransferContext)->get_ViewId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IApplicationViewTransferContext<D>::ViewId(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTransferContext)->put_ViewId(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ViewManagement_IApplicationViewTransferContextStatics<D>::DataPackageFormatId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewTransferContextStatics)->get_DataPackageFormatId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIContext) consume_Windows_UI_ViewManagement_IApplicationViewWithContext<D>::UIContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IApplicationViewWithContext)->get_UIContext(&value));
        return llm::OS::UI::UIContext{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IInputPane<D>::Showing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::InputPane, llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane)->add_Showing(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IInputPane<D>::Showing_revoker consume_Windows_UI_ViewManagement_IInputPane<D>::Showing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::InputPane, llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Showing_revoker>(this, Showing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IInputPane<D>::Showing(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane)->remove_Showing(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IInputPane<D>::Hiding(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::InputPane, llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane)->add_Hiding(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IInputPane<D>::Hiding_revoker consume_Windows_UI_ViewManagement_IInputPane<D>::Hiding(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::InputPane, llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Hiding_revoker>(this, Hiding(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IInputPane<D>::Hiding(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane)->remove_Hiding(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_ViewManagement_IInputPane<D>::OccludedRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane)->get_OccludedRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IInputPane2<D>::TryShow() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane2)->TryShow(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IInputPane2<D>::TryHide() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPane2)->TryHide(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IInputPaneControl<D>::Visible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneControl)->get_Visible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IInputPaneControl<D>::Visible(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneControl)->put_Visible(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::InputPane) consume_Windows_UI_ViewManagement_IInputPaneStatics<D>::GetForCurrentView() const
    {
        void* inputPane{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneStatics)->GetForCurrentView(&inputPane));
        return llm::OS::UI::ViewManagement::InputPane{ inputPane, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::InputPane) consume_Windows_UI_ViewManagement_IInputPaneStatics2<D>::GetForUIContext(llm::OS::UI::UIContext const& context) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneStatics2)->GetForUIContext(*(void**)(&context), &result));
        return llm::OS::UI::ViewManagement::InputPane{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_ViewManagement_IInputPaneVisibilityEventArgs<D>::OccludedRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneVisibilityEventArgs)->get_OccludedRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IInputPaneVisibilityEventArgs<D>::EnsuredFocusedElementInView(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneVisibilityEventArgs)->put_EnsuredFocusedElementInView(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IInputPaneVisibilityEventArgs<D>::EnsuredFocusedElementInView() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IInputPaneVisibilityEventArgs)->get_EnsuredFocusedElementInView(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics)->StartProjectingAsync(projectionViewId, anchorViewId, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics)->SwapDisplaysForViewsAsync(projectionViewId, anchorViewId, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics)->StopProjectingAsync(projectionViewId, anchorViewId, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::ProjectionDisplayAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics)->get_ProjectionDisplayAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics)->add_ProjectionDisplayAvailableChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged_revoker consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ProjectionDisplayAvailableChanged_revoker>(this, ProjectionDisplayAvailableChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IProjectionManagerStatics<D>::ProjectionDisplayAvailableChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics)->remove_ProjectionDisplayAvailableChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IProjectionManagerStatics2<D>::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Devices::Enumeration::DeviceInformation const& displayDeviceInfo) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics2)->StartProjectingWithDeviceInfoAsync(projectionViewId, anchorViewId, *(void**)(&displayDeviceInfo), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IProjectionManagerStatics2<D>::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Foundation::Rect const& selection) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics2)->RequestStartProjectingAsync(projectionViewId, anchorViewId, impl::bind_in(selection), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_ViewManagement_IProjectionManagerStatics2<D>::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& prefferedPlacement) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics2)->RequestStartProjectingWithPlacementAsync(projectionViewId, anchorViewId, impl::bind_in(selection), static_cast<int32_t>(prefferedPlacement), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ViewManagement_IProjectionManagerStatics2<D>::GetDeviceSelector() const
    {
        void* selector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IProjectionManagerStatics2)->GetDeviceSelector(&selector));
        return hstring{ selector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IStatusBar<D>::ShowAsync() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->ShowAsync(&returnValue));
        return llm::OS::Foundation::IAsyncAction{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IStatusBar<D>::HideAsync() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->HideAsync(&returnValue));
        return llm::OS::Foundation::IAsyncAction{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_UI_ViewManagement_IStatusBar<D>::BackgroundOpacity() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->get_BackgroundOpacity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBar<D>::BackgroundOpacity(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->put_BackgroundOpacity(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IStatusBar<D>::ForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->get_ForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBar<D>::ForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->put_ForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_ViewManagement_IStatusBar<D>::BackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->get_BackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBar<D>::BackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->put_BackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::StatusBarProgressIndicator) consume_Windows_UI_ViewManagement_IStatusBar<D>::ProgressIndicator() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->get_ProgressIndicator(&value));
        return llm::OS::UI::ViewManagement::StatusBarProgressIndicator{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_ViewManagement_IStatusBar<D>::OccludedRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->get_OccludedRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IStatusBar<D>::Showing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::StatusBar, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->add_Showing(*(void**)(&eventHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IStatusBar<D>::Showing_revoker consume_Windows_UI_ViewManagement_IStatusBar<D>::Showing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::StatusBar, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        return impl::make_event_revoker<D, Showing_revoker>(this, Showing(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBar<D>::Showing(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->remove_Showing(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IStatusBar<D>::Hiding(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::StatusBar, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->add_Hiding(*(void**)(&eventHandler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IStatusBar<D>::Hiding_revoker consume_Windows_UI_ViewManagement_IStatusBar<D>::Hiding(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::StatusBar, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        return impl::make_event_revoker<D, Hiding_revoker>(this, Hiding(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBar<D>::Hiding(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBar)->remove_Hiding(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IStatusBarProgressIndicator<D>::ShowAsync() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarProgressIndicator)->ShowAsync(&returnValue));
        return llm::OS::Foundation::IAsyncAction{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_ViewManagement_IStatusBarProgressIndicator<D>::HideAsync() const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarProgressIndicator)->HideAsync(&returnValue));
        return llm::OS::Foundation::IAsyncAction{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_ViewManagement_IStatusBarProgressIndicator<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarProgressIndicator)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBarProgressIndicator<D>::Text(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarProgressIndicator)->put_Text(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_UI_ViewManagement_IStatusBarProgressIndicator<D>::ProgressValue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarProgressIndicator)->get_ProgressValue(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IStatusBarProgressIndicator<D>::ProgressValue(llm::OS::Foundation::IReference<double> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarProgressIndicator)->put_ProgressValue(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::StatusBar) consume_Windows_UI_ViewManagement_IStatusBarStatics<D>::GetForCurrentView() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IStatusBarStatics)->GetForCurrentView(&value));
        return llm::OS::UI::ViewManagement::StatusBar{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::HandPreference) consume_Windows_UI_ViewManagement_IUISettings<D>::HandPreference() const
    {
        llm::OS::UI::ViewManagement::HandPreference value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_HandPreference(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_ViewManagement_IUISettings<D>::CursorSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_CursorSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_ViewManagement_IUISettings<D>::ScrollBarSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_ScrollBarSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_ViewManagement_IUISettings<D>::ScrollBarArrowSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_ScrollBarArrowSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_ViewManagement_IUISettings<D>::ScrollBarThumbBoxSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_ScrollBarThumbBoxSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_ViewManagement_IUISettings<D>::MessageDuration() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_MessageDuration(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IUISettings<D>::AnimationsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_AnimationsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IUISettings<D>::CaretBrowsingEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_CaretBrowsingEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_ViewManagement_IUISettings<D>::CaretBlinkRate() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_CaretBlinkRate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_ViewManagement_IUISettings<D>::CaretWidth() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_CaretWidth(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_ViewManagement_IUISettings<D>::DoubleClickTime() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_DoubleClickTime(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_ViewManagement_IUISettings<D>::MouseHoverTime() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->get_MouseHoverTime(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_ViewManagement_IUISettings<D>::UIElementColor(llm::OS::UI::ViewManagement::UIElementType const& desiredElement) const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings)->UIElementColor(static_cast<int32_t>(desiredElement), put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_UI_ViewManagement_IUISettings2<D>::TextScaleFactor() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings2)->get_TextScaleFactor(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IUISettings2<D>::TextScaleFactorChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings2)->add_TextScaleFactorChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IUISettings2<D>::TextScaleFactorChanged_revoker consume_Windows_UI_ViewManagement_IUISettings2<D>::TextScaleFactorChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, TextScaleFactorChanged_revoker>(this, TextScaleFactorChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IUISettings2<D>::TextScaleFactorChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings2)->remove_TextScaleFactorChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_ViewManagement_IUISettings3<D>::GetColorValue(llm::OS::UI::ViewManagement::UIColorType const& desiredColor) const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings3)->GetColorValue(static_cast<int32_t>(desiredColor), put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IUISettings3<D>::ColorValuesChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings3)->add_ColorValuesChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IUISettings3<D>::ColorValuesChanged_revoker consume_Windows_UI_ViewManagement_IUISettings3<D>::ColorValuesChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ColorValuesChanged_revoker>(this, ColorValuesChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IUISettings3<D>::ColorValuesChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings3)->remove_ColorValuesChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IUISettings4<D>::AdvancedEffectsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings4)->get_AdvancedEffectsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IUISettings4<D>::AdvancedEffectsEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings4)->add_AdvancedEffectsEnabledChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IUISettings4<D>::AdvancedEffectsEnabledChanged_revoker consume_Windows_UI_ViewManagement_IUISettings4<D>::AdvancedEffectsEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, AdvancedEffectsEnabledChanged_revoker>(this, AdvancedEffectsEnabledChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IUISettings4<D>::AdvancedEffectsEnabledChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings4)->remove_AdvancedEffectsEnabledChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_IUISettings5<D>::AutoHideScrollBars() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings5)->get_AutoHideScrollBars(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IUISettings5<D>::AutoHideScrollBarsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsAutoHideScrollBarsChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings5)->add_AutoHideScrollBarsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IUISettings5<D>::AutoHideScrollBarsChanged_revoker consume_Windows_UI_ViewManagement_IUISettings5<D>::AutoHideScrollBarsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsAutoHideScrollBarsChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AutoHideScrollBarsChanged_revoker>(this, AutoHideScrollBarsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IUISettings5<D>::AutoHideScrollBarsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings5)->remove_AutoHideScrollBarsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IUISettings6<D>::AnimationsEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsAnimationsEnabledChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings6)->add_AnimationsEnabledChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IUISettings6<D>::AnimationsEnabledChanged_revoker consume_Windows_UI_ViewManagement_IUISettings6<D>::AnimationsEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsAnimationsEnabledChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AnimationsEnabledChanged_revoker>(this, AnimationsEnabledChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IUISettings6<D>::AnimationsEnabledChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings6)->remove_AnimationsEnabledChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_IUISettings6<D>::MessageDurationChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsMessageDurationChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings6)->add_MessageDurationChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_IUISettings6<D>::MessageDurationChanged_revoker consume_Windows_UI_ViewManagement_IUISettings6<D>::MessageDurationChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsMessageDurationChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, MessageDurationChanged_revoker>(this, MessageDurationChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IUISettings6<D>::MessageDurationChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUISettings6)->remove_MessageDurationChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::UserInteractionMode) consume_Windows_UI_ViewManagement_IUIViewSettings<D>::UserInteractionMode() const
    {
        llm::OS::UI::ViewManagement::UserInteractionMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUIViewSettings)->get_UserInteractionMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::UIViewSettings) consume_Windows_UI_ViewManagement_IUIViewSettingsStatics<D>::GetForCurrentView() const
    {
        void* current{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IUIViewSettingsStatics)->GetForCurrentView(&current));
        return llm::OS::UI::ViewManagement::UIViewSettings{ current, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ViewSizePreference) consume_Windows_UI_ViewManagement_IViewModePreferences<D>::ViewSizePreference() const
    {
        llm::OS::UI::ViewManagement::ViewSizePreference value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IViewModePreferences)->get_ViewSizePreference(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IViewModePreferences<D>::ViewSizePreference(llm::OS::UI::ViewManagement::ViewSizePreference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IViewModePreferences)->put_ViewSizePreference(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_ViewManagement_IViewModePreferences<D>::CustomSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IViewModePreferences)->get_CustomSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_IViewModePreferences<D>::CustomSize(llm::OS::Foundation::Size const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IViewModePreferences)->put_CustomSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ViewModePreferences) consume_Windows_UI_ViewManagement_IViewModePreferencesStatics<D>::CreateDefault(llm::OS::UI::ViewManagement::ApplicationViewMode const& mode) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::IViewModePreferencesStatics)->CreateDefault(static_cast<int32_t>(mode), &result));
        return llm::OS::UI::ViewManagement::ViewModePreferences{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IAccessibilitySettings> : produce_base<D, llm::OS::UI::ViewManagement::IAccessibilitySettings>
    {
        int32_t __stdcall get_HighContrast(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HighContrast());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HighContrastScheme(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HighContrastScheme());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_HighContrastChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().HighContrastChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::AccessibilitySettings, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_HighContrastChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HighContrastChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IActivationViewSwitcher> : produce_base<D, llm::OS::UI::ViewManagement::IActivationViewSwitcher>
    {
        int32_t __stdcall ShowAsStandaloneAsync(int32_t viewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAsStandaloneAsync(viewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAsStandaloneWithSizePreferenceAsync(int32_t viewId, int32_t sizePreference, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAsStandaloneAsync(viewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ViewSizePreference const*>(&sizePreference)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsViewPresentedOnActivationVirtualDesktop(int32_t viewId, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsViewPresentedOnActivationVirtualDesktop(viewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationView> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationView>
    {
        int32_t __stdcall get_Orientation(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ApplicationViewOrientation>(this->shim().Orientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdjacentToLeftDisplayEdge(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AdjacentToLeftDisplayEdge());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdjacentToRightDisplayEdge(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AdjacentToRightDisplayEdge());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsFullScreen(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFullScreen());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsOnLockScreen(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsOnLockScreen());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsScreenCaptureEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsScreenCaptureEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsScreenCaptureEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsScreenCaptureEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Consolidated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Consolidated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::ApplicationView, llm::OS::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Consolidated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Consolidated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationView2> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationView2>
    {
        int32_t __stdcall get_SuppressSystemOverlays(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SuppressSystemOverlays());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SuppressSystemOverlays(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuppressSystemOverlays(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VisibleBounds(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().VisibleBounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_VisibleBoundsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VisibleBoundsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::ApplicationView, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VisibleBoundsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibleBoundsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall SetDesiredBoundsMode(int32_t boundsMode, bool* success) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_from<bool>(this->shim().SetDesiredBoundsMode(*reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewBoundsMode const*>(&boundsMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DesiredBoundsMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ApplicationViewBoundsMode>(this->shim().DesiredBoundsMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationView3> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationView3>
    {
        int32_t __stdcall get_TitleBar(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ApplicationViewTitleBar>(this->shim().TitleBar());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FullScreenSystemOverlayMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::FullScreenSystemOverlayMode>(this->shim().FullScreenSystemOverlayMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FullScreenSystemOverlayMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FullScreenSystemOverlayMode(*reinterpret_cast<llm::OS::UI::ViewManagement::FullScreenSystemOverlayMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsFullScreenMode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFullScreenMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnterFullScreenMode(bool* success) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_from<bool>(this->shim().TryEnterFullScreenMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ExitFullScreenMode() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitFullScreenMode();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowStandardSystemOverlays() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowStandardSystemOverlays();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryResizeView(llm::OS::Foundation::Size value, bool* success) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_from<bool>(this->shim().TryResizeView(*reinterpret_cast<llm::OS::Foundation::Size const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPreferredMinSize(llm::OS::Foundation::Size minSize) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreferredMinSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&minSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationView4> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationView4>
    {
        int32_t __stdcall get_ViewMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ApplicationViewMode>(this->shim().ViewMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsViewModeSupported(int32_t viewMode, bool* isViewModeSupported) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *isViewModeSupported = detach_from<bool>(this->shim().IsViewModeSupported(*reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewMode const*>(&viewMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnterViewModeAsync(int32_t viewMode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryEnterViewModeAsync(*reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewMode const*>(&viewMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryEnterViewModeWithPreferencesAsync(int32_t viewMode, void* viewModePreferences, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryEnterViewModeAsync(*reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewMode const*>(&viewMode), *reinterpret_cast<llm::OS::UI::ViewManagement::ViewModePreferences const*>(&viewModePreferences)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryConsolidateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryConsolidateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationView7> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationView7>
    {
        int32_t __stdcall get_PersistedStateId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PersistedStateId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PersistedStateId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PersistedStateId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationView9> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationView9>
    {
        int32_t __stdcall get_WindowingEnvironment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::WindowingEnvironment>(this->shim().WindowingEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDisplayRegions(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>>(this->shim().GetDisplayRegions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs>
    {
        int32_t __stdcall get_IsUserInitiated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsUserInitiated());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs2> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs2>
    {
        int32_t __stdcall get_IsAppInitiated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAppInitiated());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewFullscreenStatics> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewFullscreenStatics>
    {
        int32_t __stdcall TryUnsnapToFullscreen(bool* success) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_from<bool>(this->shim().TryUnsnapToFullscreen());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewInteropStatics> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewInteropStatics>
    {
        int32_t __stdcall GetApplicationViewIdForWindow(void* window, int32_t* id) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *id = detach_from<int32_t>(this->shim().GetApplicationViewIdForWindow(*reinterpret_cast<llm::OS::UI::Core::ICoreWindow const*>(&window)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewScaling> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewScaling>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewScalingStatics> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewScalingStatics>
    {
        int32_t __stdcall get_DisableLayoutScaling(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DisableLayoutScaling());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetDisableLayoutScaling(bool disableLayoutScaling, bool* success) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_from<bool>(this->shim().TrySetDisableLayoutScaling(disableLayoutScaling));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewStatics> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewStatics>
    {
        int32_t __stdcall get_Value(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ApplicationViewState>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryUnsnap(bool* success) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *success = detach_from<bool>(this->shim().TryUnsnap());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewStatics2> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewStatics2>
    {
        int32_t __stdcall GetForCurrentView(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::UI::ViewManagement::ApplicationView>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TerminateAppOnFinalViewClose(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().TerminateAppOnFinalViewClose());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TerminateAppOnFinalViewClose(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateAppOnFinalViewClose(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewStatics3> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewStatics3>
    {
        int32_t __stdcall get_PreferredLaunchWindowingMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ApplicationViewWindowingMode>(this->shim().PreferredLaunchWindowingMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredLaunchWindowingMode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredLaunchWindowingMode(*reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewWindowingMode const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredLaunchViewSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().PreferredLaunchViewSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredLaunchViewSize(llm::OS::Foundation::Size value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredLaunchViewSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewStatics4> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewStatics4>
    {
        int32_t __stdcall ClearAllPersistedState() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearAllPersistedState();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearPersistedState(void* key) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearPersistedState(*reinterpret_cast<hstring const*>(&key));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics>
    {
        int32_t __stdcall DisableShowingMainViewOnActivation() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableShowingMainViewOnActivation();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowAsStandaloneAsync(int32_t viewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryShowAsStandaloneAsync(viewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowAsStandaloneWithSizePreferenceAsync(int32_t viewId, int32_t sizePreference, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryShowAsStandaloneAsync(viewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ViewSizePreference const*>(&sizePreference)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowAsStandaloneWithAnchorViewAndSizePreferenceAsync(int32_t viewId, int32_t sizePreference, int32_t anchorViewId, int32_t anchorSizePreference, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryShowAsStandaloneAsync(viewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ViewSizePreference const*>(&sizePreference), anchorViewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ViewSizePreference const*>(&anchorSizePreference)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SwitchAsync(int32_t viewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SwitchAsync(viewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SwitchFromViewAsync(int32_t toViewId, int32_t fromViewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SwitchAsync(toViewId, fromViewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SwitchFromViewWithOptionsAsync(int32_t toViewId, int32_t fromViewId, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SwitchAsync(toViewId, fromViewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewSwitchingOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, uint32_t options, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().PrepareForCustomAnimatedSwitchAsync(toViewId, fromViewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewSwitchingOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics2> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics2>
    {
        int32_t __stdcall DisableSystemViewActivationPolicy() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableSystemViewActivationPolicy();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics3> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics3>
    {
        int32_t __stdcall TryShowAsViewModeAsync(int32_t viewId, int32_t viewMode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryShowAsViewModeAsync(viewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewMode const*>(&viewMode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowAsViewModeWithPreferencesAsync(int32_t viewId, int32_t viewMode, void* viewModePreferences, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryShowAsViewModeAsync(viewId, *reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewMode const*>(&viewMode), *reinterpret_cast<llm::OS::UI::ViewManagement::ViewModePreferences const*>(&viewModePreferences)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewTitleBar> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewTitleBar>
    {
        int32_t __stdcall put_ForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonBackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonBackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonHoverForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonHoverForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonHoverForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonHoverForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonHoverBackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonHoverBackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonHoverBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonHoverBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonPressedForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonPressedForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonPressedForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonPressedForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonPressedBackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonPressedBackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonPressedBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonPressedBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InactiveForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InactiveForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InactiveForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().InactiveForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InactiveBackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InactiveBackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InactiveBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().InactiveBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonInactiveForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonInactiveForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonInactiveForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonInactiveForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ButtonInactiveBackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ButtonInactiveBackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ButtonInactiveBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonInactiveBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewTransferContext> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewTransferContext>
    {
        int32_t __stdcall get_ViewId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ViewId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewId(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewId(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewTransferContextStatics> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewTransferContextStatics>
    {
        int32_t __stdcall get_DataPackageFormatId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DataPackageFormatId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IApplicationViewWithContext> : produce_base<D, llm::OS::UI::ViewManagement::IApplicationViewWithContext>
    {
        int32_t __stdcall get_UIContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIContext>(this->shim().UIContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IInputPane> : produce_base<D, llm::OS::UI::ViewManagement::IInputPane>
    {
        int32_t __stdcall add_Showing(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Showing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::InputPane, llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Showing(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Hiding(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Hiding(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::InputPane, llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Hiding(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hiding(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_OccludedRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().OccludedRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IInputPane2> : produce_base<D, llm::OS::UI::ViewManagement::IInputPane2>
    {
        int32_t __stdcall TryShow(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryShow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryHide(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryHide());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IInputPaneControl> : produce_base<D, llm::OS::UI::ViewManagement::IInputPaneControl>
    {
        int32_t __stdcall get_Visible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Visible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Visible(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Visible(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IInputPaneStatics> : produce_base<D, llm::OS::UI::ViewManagement::IInputPaneStatics>
    {
        int32_t __stdcall GetForCurrentView(void** inputPane) noexcept final try
        {
            clear_abi(inputPane);
            typename D::abi_guard guard(this->shim());
            *inputPane = detach_from<llm::OS::UI::ViewManagement::InputPane>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IInputPaneStatics2> : produce_base<D, llm::OS::UI::ViewManagement::IInputPaneStatics2>
    {
        int32_t __stdcall GetForUIContext(void* context, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::ViewManagement::InputPane>(this->shim().GetForUIContext(*reinterpret_cast<llm::OS::UI::UIContext const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IInputPaneVisibilityEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::IInputPaneVisibilityEventArgs>
    {
        int32_t __stdcall get_OccludedRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().OccludedRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EnsuredFocusedElementInView(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnsuredFocusedElementInView(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnsuredFocusedElementInView(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().EnsuredFocusedElementInView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IProjectionManagerStatics> : produce_base<D, llm::OS::UI::ViewManagement::IProjectionManagerStatics>
    {
        int32_t __stdcall StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StartProjectingAsync(projectionViewId, anchorViewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SwapDisplaysForViewsAsync(projectionViewId, anchorViewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StopProjectingAsync(projectionViewId, anchorViewId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProjectionDisplayAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ProjectionDisplayAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ProjectionDisplayAvailableChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ProjectionDisplayAvailableChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ProjectionDisplayAvailableChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProjectionDisplayAvailableChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IProjectionManagerStatics2> : produce_base<D, llm::OS::UI::ViewManagement::IProjectionManagerStatics2>
    {
        int32_t __stdcall StartProjectingWithDeviceInfoAsync(int32_t projectionViewId, int32_t anchorViewId, void* displayDeviceInfo, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().StartProjectingAsync(projectionViewId, anchorViewId, *reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&displayDeviceInfo)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Foundation::Rect selection, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestStartProjectingAsync(projectionViewId, anchorViewId, *reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestStartProjectingWithPlacementAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Foundation::Rect selection, int32_t prefferedPlacement, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestStartProjectingAsync(projectionViewId, anchorViewId, *reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&prefferedPlacement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceSelector(void** selector) noexcept final try
        {
            clear_abi(selector);
            typename D::abi_guard guard(this->shim());
            *selector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IStatusBar> : produce_base<D, llm::OS::UI::ViewManagement::IStatusBar>
    {
        int32_t __stdcall ShowAsync(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HideAsync(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().HideAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundOpacity(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().BackgroundOpacity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundOpacity(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundOpacity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ForegroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundColor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::UI::Color> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProgressIndicator(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::StatusBarProgressIndicator>(this->shim().ProgressIndicator());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OccludedRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().OccludedRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Showing(void* eventHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Showing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::StatusBar, llm::OS::Foundation::IInspectable> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Showing(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Hiding(void* eventHandler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Hiding(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::StatusBar, llm::OS::Foundation::IInspectable> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Hiding(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hiding(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IStatusBarProgressIndicator> : produce_base<D, llm::OS::UI::ViewManagement::IStatusBarProgressIndicator>
    {
        int32_t __stdcall ShowAsync(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ShowAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HideAsync(void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().HideAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Text(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProgressValue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ProgressValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProgressValue(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProgressValue(*reinterpret_cast<llm::OS::Foundation::IReference<double> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IStatusBarStatics> : produce_base<D, llm::OS::UI::ViewManagement::IStatusBarStatics>
    {
        int32_t __stdcall GetForCurrentView(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::StatusBar>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettings> : produce_base<D, llm::OS::UI::ViewManagement::IUISettings>
    {
        int32_t __stdcall get_HandPreference(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::HandPreference>(this->shim().HandPreference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CursorSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().CursorSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScrollBarSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().ScrollBarSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScrollBarArrowSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().ScrollBarArrowSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ScrollBarThumbBoxSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().ScrollBarThumbBoxSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageDuration(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MessageDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AnimationsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AnimationsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CaretBrowsingEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CaretBrowsingEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CaretBlinkRate(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().CaretBlinkRate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CaretWidth(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().CaretWidth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DoubleClickTime(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().DoubleClickTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MouseHoverTime(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MouseHoverTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UIElementColor(int32_t desiredElement, struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().UIElementColor(*reinterpret_cast<llm::OS::UI::ViewManagement::UIElementType const*>(&desiredElement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettings2> : produce_base<D, llm::OS::UI::ViewManagement::IUISettings2>
    {
        int32_t __stdcall get_TextScaleFactor(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().TextScaleFactor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_TextScaleFactorChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().TextScaleFactorChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TextScaleFactorChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextScaleFactorChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettings3> : produce_base<D, llm::OS::UI::ViewManagement::IUISettings3>
    {
        int32_t __stdcall GetColorValue(int32_t desiredColor, struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().GetColorValue(*reinterpret_cast<llm::OS::UI::ViewManagement::UIColorType const*>(&desiredColor)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ColorValuesChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().ColorValuesChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ColorValuesChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ColorValuesChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettings4> : produce_base<D, llm::OS::UI::ViewManagement::IUISettings4>
    {
        int32_t __stdcall get_AdvancedEffectsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AdvancedEffectsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AdvancedEffectsEnabledChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AdvancedEffectsEnabledChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AdvancedEffectsEnabledChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AdvancedEffectsEnabledChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettings5> : produce_base<D, llm::OS::UI::ViewManagement::IUISettings5>
    {
        int32_t __stdcall get_AutoHideScrollBars(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AutoHideScrollBars());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AutoHideScrollBarsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AutoHideScrollBarsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsAutoHideScrollBarsChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AutoHideScrollBarsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutoHideScrollBarsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettings6> : produce_base<D, llm::OS::UI::ViewManagement::IUISettings6>
    {
        int32_t __stdcall add_AnimationsEnabledChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AnimationsEnabledChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsAnimationsEnabledChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AnimationsEnabledChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AnimationsEnabledChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_MessageDurationChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().MessageDurationChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::UISettings, llm::OS::UI::ViewManagement::UISettingsMessageDurationChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MessageDurationChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageDurationChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettingsAnimationsEnabledChangedEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::IUISettingsAnimationsEnabledChangedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettingsAutoHideScrollBarsChangedEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::IUISettingsAutoHideScrollBarsChangedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUISettingsMessageDurationChangedEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::IUISettingsMessageDurationChangedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUIViewSettings> : produce_base<D, llm::OS::UI::ViewManagement::IUIViewSettings>
    {
        int32_t __stdcall get_UserInteractionMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::UserInteractionMode>(this->shim().UserInteractionMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IUIViewSettingsStatics> : produce_base<D, llm::OS::UI::ViewManagement::IUIViewSettingsStatics>
    {
        int32_t __stdcall GetForCurrentView(void** current) noexcept final try
        {
            clear_abi(current);
            typename D::abi_guard guard(this->shim());
            *current = detach_from<llm::OS::UI::ViewManagement::UIViewSettings>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IViewModePreferences> : produce_base<D, llm::OS::UI::ViewManagement::IViewModePreferences>
    {
        int32_t __stdcall get_ViewSizePreference(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ViewSizePreference>(this->shim().ViewSizePreference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ViewSizePreference(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ViewSizePreference(*reinterpret_cast<llm::OS::UI::ViewManagement::ViewSizePreference const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().CustomSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CustomSize(llm::OS::Foundation::Size value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::IViewModePreferencesStatics> : produce_base<D, llm::OS::UI::ViewManagement::IViewModePreferencesStatics>
    {
        int32_t __stdcall CreateDefault(int32_t mode, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::ViewManagement::ViewModePreferences>(this->shim().CreateDefault(*reinterpret_cast<llm::OS::UI::ViewManagement::ApplicationViewMode const*>(&mode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::ViewManagement
{
    constexpr auto operator|(ApplicationViewSwitchingOptions const left, ApplicationViewSwitchingOptions const right) noexcept
    {
        return static_cast<ApplicationViewSwitchingOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(ApplicationViewSwitchingOptions& left, ApplicationViewSwitchingOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(ApplicationViewSwitchingOptions const left, ApplicationViewSwitchingOptions const right) noexcept
    {
        return static_cast<ApplicationViewSwitchingOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(ApplicationViewSwitchingOptions& left, ApplicationViewSwitchingOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(ApplicationViewSwitchingOptions const value) noexcept
    {
        return static_cast<ApplicationViewSwitchingOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(ApplicationViewSwitchingOptions const left, ApplicationViewSwitchingOptions const right) noexcept
    {
        return static_cast<ApplicationViewSwitchingOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(ApplicationViewSwitchingOptions& left, ApplicationViewSwitchingOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline AccessibilitySettings::AccessibilitySettings() :
        AccessibilitySettings(impl::call_factory_cast<AccessibilitySettings(*)(llm::OS::Foundation::IActivationFactory const&), AccessibilitySettings>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AccessibilitySettings>(); }))
    {
    }
    inline auto ApplicationView::TryUnsnapToFullscreen()
    {
        return impl::call_factory_cast<bool(*)(IApplicationViewFullscreenStatics const&), ApplicationView, IApplicationViewFullscreenStatics>([](IApplicationViewFullscreenStatics const& f) { return f.TryUnsnapToFullscreen(); });
    }
    inline auto ApplicationView::GetApplicationViewIdForWindow(llm::OS::UI::Core::ICoreWindow const& window)
    {
        return impl::call_factory<ApplicationView, IApplicationViewInteropStatics>([&](IApplicationViewInteropStatics const& f) { return f.GetApplicationViewIdForWindow(window); });
    }
    inline auto ApplicationView::Value()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::ApplicationViewState(*)(IApplicationViewStatics const&), ApplicationView, IApplicationViewStatics>([](IApplicationViewStatics const& f) { return f.Value(); });
    }
    inline auto ApplicationView::TryUnsnap()
    {
        return impl::call_factory_cast<bool(*)(IApplicationViewStatics const&), ApplicationView, IApplicationViewStatics>([](IApplicationViewStatics const& f) { return f.TryUnsnap(); });
    }
    inline auto ApplicationView::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::ApplicationView(*)(IApplicationViewStatics2 const&), ApplicationView, IApplicationViewStatics2>([](IApplicationViewStatics2 const& f) { return f.GetForCurrentView(); });
    }
    inline auto ApplicationView::TerminateAppOnFinalViewClose()
    {
        return impl::call_factory_cast<bool(*)(IApplicationViewStatics2 const&), ApplicationView, IApplicationViewStatics2>([](IApplicationViewStatics2 const& f) { return f.TerminateAppOnFinalViewClose(); });
    }
    inline auto ApplicationView::TerminateAppOnFinalViewClose(bool value)
    {
        impl::call_factory<ApplicationView, IApplicationViewStatics2>([&](IApplicationViewStatics2 const& f) { return f.TerminateAppOnFinalViewClose(value); });
    }
    inline auto ApplicationView::PreferredLaunchWindowingMode()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::ApplicationViewWindowingMode(*)(IApplicationViewStatics3 const&), ApplicationView, IApplicationViewStatics3>([](IApplicationViewStatics3 const& f) { return f.PreferredLaunchWindowingMode(); });
    }
    inline auto ApplicationView::PreferredLaunchWindowingMode(llm::OS::UI::ViewManagement::ApplicationViewWindowingMode const& value)
    {
        impl::call_factory<ApplicationView, IApplicationViewStatics3>([&](IApplicationViewStatics3 const& f) { return f.PreferredLaunchWindowingMode(value); });
    }
    inline auto ApplicationView::PreferredLaunchViewSize()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Size(*)(IApplicationViewStatics3 const&), ApplicationView, IApplicationViewStatics3>([](IApplicationViewStatics3 const& f) { return f.PreferredLaunchViewSize(); });
    }
    inline auto ApplicationView::PreferredLaunchViewSize(llm::OS::Foundation::Size const& value)
    {
        impl::call_factory<ApplicationView, IApplicationViewStatics3>([&](IApplicationViewStatics3 const& f) { return f.PreferredLaunchViewSize(value); });
    }
    inline auto ApplicationView::ClearAllPersistedState()
    {
        impl::call_factory_cast<void(*)(IApplicationViewStatics4 const&), ApplicationView, IApplicationViewStatics4>([](IApplicationViewStatics4 const& f) { return f.ClearAllPersistedState(); });
    }
    inline auto ApplicationView::ClearPersistedState(param::hstring const& key)
    {
        impl::call_factory<ApplicationView, IApplicationViewStatics4>([&](IApplicationViewStatics4 const& f) { return f.ClearPersistedState(key); });
    }
    inline auto ApplicationViewScaling::DisableLayoutScaling()
    {
        return impl::call_factory_cast<bool(*)(IApplicationViewScalingStatics const&), ApplicationViewScaling, IApplicationViewScalingStatics>([](IApplicationViewScalingStatics const& f) { return f.DisableLayoutScaling(); });
    }
    inline auto ApplicationViewScaling::TrySetDisableLayoutScaling(bool disableLayoutScaling)
    {
        return impl::call_factory<ApplicationViewScaling, IApplicationViewScalingStatics>([&](IApplicationViewScalingStatics const& f) { return f.TrySetDisableLayoutScaling(disableLayoutScaling); });
    }
    inline auto ApplicationViewSwitcher::DisableShowingMainViewOnActivation()
    {
        impl::call_factory_cast<void(*)(IApplicationViewSwitcherStatics const&), ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([](IApplicationViewSwitcherStatics const& f) { return f.DisableShowingMainViewOnActivation(); });
    }
    inline auto ApplicationViewSwitcher::TryShowAsStandaloneAsync(int32_t viewId)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.TryShowAsStandaloneAsync(viewId); });
    }
    inline auto ApplicationViewSwitcher::TryShowAsStandaloneAsync(int32_t viewId, llm::OS::UI::ViewManagement::ViewSizePreference const& sizePreference)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.TryShowAsStandaloneAsync(viewId, sizePreference); });
    }
    inline auto ApplicationViewSwitcher::TryShowAsStandaloneAsync(int32_t viewId, llm::OS::UI::ViewManagement::ViewSizePreference const& sizePreference, int32_t anchorViewId, llm::OS::UI::ViewManagement::ViewSizePreference const& anchorSizePreference)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.TryShowAsStandaloneAsync(viewId, sizePreference, anchorViewId, anchorSizePreference); });
    }
    inline auto ApplicationViewSwitcher::SwitchAsync(int32_t viewId)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.SwitchAsync(viewId); });
    }
    inline auto ApplicationViewSwitcher::SwitchAsync(int32_t toViewId, int32_t fromViewId)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.SwitchAsync(toViewId, fromViewId); });
    }
    inline auto ApplicationViewSwitcher::SwitchAsync(int32_t toViewId, int32_t fromViewId, llm::OS::UI::ViewManagement::ApplicationViewSwitchingOptions const& options)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.SwitchAsync(toViewId, fromViewId, options); });
    }
    inline auto ApplicationViewSwitcher::PrepareForCustomAnimatedSwitchAsync(int32_t toViewId, int32_t fromViewId, llm::OS::UI::ViewManagement::ApplicationViewSwitchingOptions const& options)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics>([&](IApplicationViewSwitcherStatics const& f) { return f.PrepareForCustomAnimatedSwitchAsync(toViewId, fromViewId, options); });
    }
    inline auto ApplicationViewSwitcher::DisableSystemViewActivationPolicy()
    {
        impl::call_factory_cast<void(*)(IApplicationViewSwitcherStatics2 const&), ApplicationViewSwitcher, IApplicationViewSwitcherStatics2>([](IApplicationViewSwitcherStatics2 const& f) { return f.DisableSystemViewActivationPolicy(); });
    }
    inline auto ApplicationViewSwitcher::TryShowAsViewModeAsync(int32_t viewId, llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics3>([&](IApplicationViewSwitcherStatics3 const& f) { return f.TryShowAsViewModeAsync(viewId, viewMode); });
    }
    inline auto ApplicationViewSwitcher::TryShowAsViewModeAsync(int32_t viewId, llm::OS::UI::ViewManagement::ApplicationViewMode const& viewMode, llm::OS::UI::ViewManagement::ViewModePreferences const& viewModePreferences)
    {
        return impl::call_factory<ApplicationViewSwitcher, IApplicationViewSwitcherStatics3>([&](IApplicationViewSwitcherStatics3 const& f) { return f.TryShowAsViewModeAsync(viewId, viewMode, viewModePreferences); });
    }
    inline ApplicationViewTransferContext::ApplicationViewTransferContext() :
        ApplicationViewTransferContext(impl::call_factory_cast<ApplicationViewTransferContext(*)(llm::OS::Foundation::IActivationFactory const&), ApplicationViewTransferContext>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ApplicationViewTransferContext>(); }))
    {
    }
    inline auto ApplicationViewTransferContext::DataPackageFormatId()
    {
        return impl::call_factory_cast<hstring(*)(IApplicationViewTransferContextStatics const&), ApplicationViewTransferContext, IApplicationViewTransferContextStatics>([](IApplicationViewTransferContextStatics const& f) { return f.DataPackageFormatId(); });
    }
    inline auto InputPane::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::InputPane(*)(IInputPaneStatics const&), InputPane, IInputPaneStatics>([](IInputPaneStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto InputPane::GetForUIContext(llm::OS::UI::UIContext const& context)
    {
        return impl::call_factory<InputPane, IInputPaneStatics2>([&](IInputPaneStatics2 const& f) { return f.GetForUIContext(context); });
    }
    inline auto ProjectionManager::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics>([&](IProjectionManagerStatics const& f) { return f.StartProjectingAsync(projectionViewId, anchorViewId); });
    }
    inline auto ProjectionManager::SwapDisplaysForViewsAsync(int32_t projectionViewId, int32_t anchorViewId)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics>([&](IProjectionManagerStatics const& f) { return f.SwapDisplaysForViewsAsync(projectionViewId, anchorViewId); });
    }
    inline auto ProjectionManager::StopProjectingAsync(int32_t projectionViewId, int32_t anchorViewId)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics>([&](IProjectionManagerStatics const& f) { return f.StopProjectingAsync(projectionViewId, anchorViewId); });
    }
    inline auto ProjectionManager::ProjectionDisplayAvailable()
    {
        return impl::call_factory_cast<bool(*)(IProjectionManagerStatics const&), ProjectionManager, IProjectionManagerStatics>([](IProjectionManagerStatics const& f) { return f.ProjectionDisplayAvailable(); });
    }
    inline auto ProjectionManager::ProjectionDisplayAvailableChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics>([&](IProjectionManagerStatics const& f) { return f.ProjectionDisplayAvailableChanged(handler); });
    }
    inline ProjectionManager::ProjectionDisplayAvailableChanged_revoker ProjectionManager::ProjectionDisplayAvailableChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<ProjectionManager, llm::OS::UI::ViewManagement::IProjectionManagerStatics>();
        return { f, f.ProjectionDisplayAvailableChanged(handler) };
    }
    inline auto ProjectionManager::ProjectionDisplayAvailableChanged(llm::event_token const& token)
    {
        impl::call_factory<ProjectionManager, IProjectionManagerStatics>([&](IProjectionManagerStatics const& f) { return f.ProjectionDisplayAvailableChanged(token); });
    }
    inline auto ProjectionManager::StartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Devices::Enumeration::DeviceInformation const& displayDeviceInfo)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics2>([&](IProjectionManagerStatics2 const& f) { return f.StartProjectingAsync(projectionViewId, anchorViewId, displayDeviceInfo); });
    }
    inline auto ProjectionManager::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Foundation::Rect const& selection)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics2>([&](IProjectionManagerStatics2 const& f) { return f.RequestStartProjectingAsync(projectionViewId, anchorViewId, selection); });
    }
    inline auto ProjectionManager::RequestStartProjectingAsync(int32_t projectionViewId, int32_t anchorViewId, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& prefferedPlacement)
    {
        return impl::call_factory<ProjectionManager, IProjectionManagerStatics2>([&](IProjectionManagerStatics2 const& f) { return f.RequestStartProjectingAsync(projectionViewId, anchorViewId, selection, prefferedPlacement); });
    }
    inline auto ProjectionManager::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IProjectionManagerStatics2 const&), ProjectionManager, IProjectionManagerStatics2>([](IProjectionManagerStatics2 const& f) { return f.GetDeviceSelector(); });
    }
    inline auto StatusBar::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::StatusBar(*)(IStatusBarStatics const&), StatusBar, IStatusBarStatics>([](IStatusBarStatics const& f) { return f.GetForCurrentView(); });
    }
    inline UISettings::UISettings() :
        UISettings(impl::call_factory_cast<UISettings(*)(llm::OS::Foundation::IActivationFactory const&), UISettings>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<UISettings>(); }))
    {
    }
    inline auto UIViewSettings::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::UIViewSettings(*)(IUIViewSettingsStatics const&), UIViewSettings, IUIViewSettingsStatics>([](IUIViewSettingsStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto ViewModePreferences::CreateDefault(llm::OS::UI::ViewManagement::ApplicationViewMode const& mode)
    {
        return impl::call_factory<ViewModePreferences, IViewModePreferencesStatics>([&](IViewModePreferencesStatics const& f) { return f.CreateDefault(mode); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::ViewManagement::IAccessibilitySettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IActivationViewSwitcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationView2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationView3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationView4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationView7> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationView9> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewConsolidatedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewFullscreenStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewInteropStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewScaling> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewScalingStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewStatics4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewSwitcherStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewTitleBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewTransferContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewTransferContextStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IApplicationViewWithContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IInputPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IInputPane2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IInputPaneControl> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IInputPaneStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IInputPaneStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IInputPaneVisibilityEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IProjectionManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IProjectionManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IStatusBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IStatusBarProgressIndicator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IStatusBarStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettings2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettings3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettings4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettings5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettings6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettingsAnimationsEnabledChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettingsAutoHideScrollBarsChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUISettingsMessageDurationChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUIViewSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IUIViewSettingsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IViewModePreferences> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::IViewModePreferencesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::AccessibilitySettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ActivationViewSwitcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ApplicationView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ApplicationViewConsolidatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ApplicationViewScaling> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ApplicationViewSwitcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ApplicationViewTitleBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ApplicationViewTransferContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::InputPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::InputPaneVisibilityEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ProjectionManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::StatusBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::StatusBarProgressIndicator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::UISettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::UISettingsAnimationsEnabledChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::UISettingsAutoHideScrollBarsChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::UISettingsMessageDurationChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::UIViewSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::ViewModePreferences> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
