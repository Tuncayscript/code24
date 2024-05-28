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
#ifndef LLM_OS_UI_WindowManagement_H
#define LLM_OS_UI_WindowManagement_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.WindowManagement.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIContentRoot) consume_Windows_UI_WindowManagement_IAppWindow<D>::Content() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_Content(&value));
        return llm::OS::UI::UIContentRoot{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_UI_WindowManagement_IAppWindow<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowFrame) consume_Windows_UI_WindowManagement_IAppWindow<D>::Frame() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_Frame(&value));
        return llm::OS::UI::WindowManagement::AppWindowFrame{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindow<D>::IsVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_IsVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_WindowManagement_IAppWindow<D>::PersistedStateId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_PersistedStateId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::PersistedStateId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->put_PersistedStateId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPresenter) consume_Windows_UI_WindowManagement_IAppWindow<D>::Presenter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_Presenter(&value));
        return llm::OS::UI::WindowManagement::AppWindowPresenter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_WindowManagement_IAppWindow<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowTitleBar) consume_Windows_UI_WindowManagement_IAppWindow<D>::TitleBar() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_TitleBar(&value));
        return llm::OS::UI::WindowManagement::AppWindowTitleBar{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIContext) consume_Windows_UI_WindowManagement_IAppWindow<D>::UIContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_UIContext(&value));
        return llm::OS::UI::UIContext{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) consume_Windows_UI_WindowManagement_IAppWindow<D>::WindowingEnvironment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->get_WindowingEnvironment(&value));
        return llm::OS::UI::WindowManagement::WindowingEnvironment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_WindowManagement_IAppWindow<D>::CloseAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->CloseAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPlacement) consume_Windows_UI_WindowManagement_IAppWindow<D>::GetPlacement() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->GetPlacement(&result));
        return llm::OS::UI::WindowManagement::AppWindowPlacement{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>) consume_Windows_UI_WindowManagement_IAppWindow<D>::GetDisplayRegions() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->GetDisplayRegions(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestMoveToDisplayRegion(llm::OS::UI::WindowManagement::DisplayRegion const& displayRegion) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestMoveToDisplayRegion(*(void**)(&displayRegion)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestMoveAdjacentToCurrentView() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestMoveAdjacentToCurrentView());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestMoveAdjacentToWindow(llm::OS::UI::WindowManagement::AppWindow const& anchorWindow) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestMoveAdjacentToWindow(*(void**)(&anchorWindow)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestMoveRelativeToWindowContent(llm::OS::UI::WindowManagement::AppWindow const& anchorWindow, llm::OS::Foundation::Point const& contentOffset) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestMoveRelativeToWindowContent(*(void**)(&anchorWindow), impl::bind_in(contentOffset)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestMoveRelativeToCurrentViewContent(llm::OS::Foundation::Point const& contentOffset) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestMoveRelativeToCurrentViewContent(impl::bind_in(contentOffset)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestMoveRelativeToDisplayRegion(llm::OS::UI::WindowManagement::DisplayRegion const& displayRegion, llm::OS::Foundation::Point const& displayRegionOffset) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestMoveRelativeToDisplayRegion(*(void**)(&displayRegion), impl::bind_in(displayRegionOffset)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::RequestSize(llm::OS::Foundation::Size const& frameSize) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->RequestSize(impl::bind_in(frameSize)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_WindowManagement_IAppWindow<D>::TryShowAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->TryShowAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WindowManagement_IAppWindow<D>::Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->add_Changed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WindowManagement_IAppWindow<D>::Changed_revoker consume_Windows_UI_WindowManagement_IAppWindow<D>::Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Changed_revoker>(this, Changed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::Changed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->remove_Changed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WindowManagement_IAppWindow<D>::Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->add_Closed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WindowManagement_IAppWindow<D>::Closed_revoker consume_Windows_UI_WindowManagement_IAppWindow<D>::Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Closed_revoker>(this, Closed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::Closed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->remove_Closed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WindowManagement_IAppWindow<D>::CloseRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->add_CloseRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WindowManagement_IAppWindow<D>::CloseRequested_revoker consume_Windows_UI_WindowManagement_IAppWindow<D>::CloseRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CloseRequested_revoker>(this, CloseRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindow<D>::CloseRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindow)->remove_CloseRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidAvailableWindowPresentationsChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidAvailableWindowPresentationsChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidDisplayRegionsChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidDisplayRegionsChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidFrameChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidFrameChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidSizeChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidSizeChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidTitleBarChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidTitleBarChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidVisibilityChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidVisibilityChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidWindowingEnvironmentChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidWindowingEnvironmentChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowChangedEventArgs<D>::DidWindowPresentationChange() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs)->get_DidWindowPresentationChange(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowCloseRequestedEventArgs<D>::Cancel() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs)->get_Cancel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowCloseRequestedEventArgs<D>::Cancel(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs)->put_Cancel(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_WindowManagement_IAppWindowCloseRequestedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowClosedReason) consume_Windows_UI_WindowManagement_IAppWindowClosedEventArgs<D>::Reason() const
    {
        llm::OS::UI::WindowManagement::AppWindowClosedReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Composition::IVisualElement>) consume_Windows_UI_WindowManagement_IAppWindowFrame<D>::DragRegionVisuals() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowFrame)->get_DragRegionVisuals(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Composition::IVisualElement>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowFrameStyle) consume_Windows_UI_WindowManagement_IAppWindowFrameStyle<D>::GetFrameStyle() const
    {
        llm::OS::UI::WindowManagement::AppWindowFrameStyle result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowFrameStyle)->GetFrameStyle(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowFrameStyle<D>::SetFrameStyle(llm::OS::UI::WindowManagement::AppWindowFrameStyle const& frameStyle) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowFrameStyle)->SetFrameStyle(static_cast<int32_t>(frameStyle)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::DisplayRegion) consume_Windows_UI_WindowManagement_IAppWindowPlacement<D>::DisplayRegion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPlacement)->get_DisplayRegion(&value));
        return llm::OS::UI::WindowManagement::DisplayRegion{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_WindowManagement_IAppWindowPlacement<D>::Offset() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPlacement)->get_Offset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_WindowManagement_IAppWindowPlacement<D>::Size() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPlacement)->get_Size(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPresentationKind) consume_Windows_UI_WindowManagement_IAppWindowPresentationConfiguration<D>::Kind() const
    {
        llm::OS::UI::WindowManagement::AppWindowPresentationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration) consume_Windows_UI_WindowManagement_IAppWindowPresenter<D>::GetConfiguration() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPresenter)->GetConfiguration(&result));
        return llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowPresenter<D>::IsPresentationSupported(llm::OS::UI::WindowManagement::AppWindowPresentationKind const& presentationKind) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPresenter)->IsPresentationSupported(static_cast<int32_t>(presentationKind), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowPresenter<D>::RequestPresentation(llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration const& configuration) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPresenter)->RequestPresentation(*(void**)(&configuration), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowPresenter<D>::RequestPresentation(llm::OS::UI::WindowManagement::AppWindowPresentationKind const& presentationKind) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowPresenter)->RequestPresentationByKind(static_cast<int32_t>(presentationKind), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WindowManagement::AppWindow>) consume_Windows_UI_WindowManagement_IAppWindowStatics<D>::TryCreateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowStatics)->TryCreateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WindowManagement::AppWindow>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowStatics<D>::ClearAllPersistedState() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowStatics)->ClearAllPersistedState());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowStatics<D>::ClearPersistedState(param::hstring const& key) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowStatics)->ClearPersistedState(*(void**)(&key)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::BackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_BackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::BackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_BackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonHoverBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonHoverBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonHoverBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonHoverBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonHoverForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonHoverForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonHoverForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonHoverForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonInactiveBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonInactiveBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonInactiveBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonInactiveBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonInactiveForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonInactiveForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonInactiveForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonInactiveForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonPressedBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonPressedBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonPressedBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonPressedBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonPressedForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ButtonPressedForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ButtonPressedForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ButtonPressedForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ExtendsContentIntoTitleBar() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ExtendsContentIntoTitleBar(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ExtendsContentIntoTitleBar(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ExtendsContentIntoTitleBar(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_ForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::ForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_ForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::InactiveBackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_InactiveBackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::InactiveBackgroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_InactiveBackgroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::InactiveForegroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_InactiveForegroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Color>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::InactiveForegroundColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->put_InactiveForegroundColor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::IsVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->get_IsVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion>) consume_Windows_UI_WindowManagement_IAppWindowTitleBar<D>::GetTitleBarOcclusions() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBar)->GetTitleBarOcclusions(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_WindowManagement_IAppWindowTitleBarOcclusion<D>::OccludingRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion)->get_OccludingRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility) consume_Windows_UI_WindowManagement_IAppWindowTitleBarVisibility<D>::GetPreferredVisibility() const
    {
        llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility)->GetPreferredVisibility(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IAppWindowTitleBarVisibility<D>::SetPreferredVisibility(llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility const& visibilityMode) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility)->SetPreferredVisibility(static_cast<int32_t>(visibilityMode)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::DisplayMonitorDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->get_DisplayMonitorDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::IsVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->get_IsVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::WorkAreaOffset() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->get_WorkAreaOffset(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::WorkAreaSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->get_WorkAreaSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::WindowingEnvironment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->get_WindowingEnvironment(&value));
        return llm::OS::UI::WindowManagement::WindowingEnvironment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::DisplayRegion, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->add_Changed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WindowManagement_IDisplayRegion<D>::Changed_revoker consume_Windows_UI_WindowManagement_IDisplayRegion<D>::Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::DisplayRegion, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Changed_revoker>(this, Changed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IDisplayRegion<D>::Changed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IDisplayRegion)->remove_Changed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IFullScreenPresentationConfiguration<D>::IsExclusive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration)->get_IsExclusive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IFullScreenPresentationConfiguration<D>::IsExclusive(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration)->put_IsExclusive(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowId>) consume_Windows_UI_WindowManagement_IWindowServicesStatics<D>::FindAllTopLevelWindowIds() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowServicesStatics)->FindAllTopLevelWindowIds(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowId>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironment)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironmentKind) consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::Kind() const
    {
        llm::OS::UI::WindowManagement::WindowingEnvironmentKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironment)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>) consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::GetDisplayRegions() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironment)->GetDisplayRegions(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::DisplayRegion>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::Changed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::WindowingEnvironment, llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironment)->add_Changed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::Changed_revoker consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::Changed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::WindowingEnvironment, llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Changed_revoker>(this, Changed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WindowManagement_IWindowingEnvironment<D>::Changed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironment)->remove_Changed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) consume_Windows_UI_WindowManagement_IWindowingEnvironmentAddedEventArgs<D>::WindowingEnvironment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs)->get_WindowingEnvironment(&value));
        return llm::OS::UI::WindowManagement::WindowingEnvironment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowManagement::WindowingEnvironment) consume_Windows_UI_WindowManagement_IWindowingEnvironmentRemovedEventArgs<D>::WindowingEnvironment() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs)->get_WindowingEnvironment(&value));
        return llm::OS::UI::WindowManagement::WindowingEnvironment{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>) consume_Windows_UI_WindowManagement_IWindowingEnvironmentStatics<D>::FindAll() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics)->FindAll(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>) consume_Windows_UI_WindowManagement_IWindowingEnvironmentStatics<D>::FindAll(llm::OS::UI::WindowManagement::WindowingEnvironmentKind const& kind) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics)->FindAllWithKind(static_cast<int32_t>(kind), &result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindow> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindow>
    {
        int32_t __stdcall get_Content(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIContentRoot>(this->shim().Content());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Frame(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::AppWindowFrame>(this->shim().Frame());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
        int32_t __stdcall get_Presenter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::AppWindowPresenter>(this->shim().Presenter());
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
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TitleBar(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::AppWindowTitleBar>(this->shim().TitleBar());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UIContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::UIContext>(this->shim().UIContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WindowingEnvironment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::WindowingEnvironment>(this->shim().WindowingEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CloseAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().CloseAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPlacement(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::WindowManagement::AppWindowPlacement>(this->shim().GetPlacement());
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
        int32_t __stdcall RequestMoveToDisplayRegion(void* displayRegion) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMoveToDisplayRegion(*reinterpret_cast<llm::OS::UI::WindowManagement::DisplayRegion const*>(&displayRegion));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestMoveAdjacentToCurrentView() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMoveAdjacentToCurrentView();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestMoveAdjacentToWindow(void* anchorWindow) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMoveAdjacentToWindow(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindow const*>(&anchorWindow));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestMoveRelativeToWindowContent(void* anchorWindow, llm::OS::Foundation::Point contentOffset) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMoveRelativeToWindowContent(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindow const*>(&anchorWindow), *reinterpret_cast<llm::OS::Foundation::Point const*>(&contentOffset));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestMoveRelativeToCurrentViewContent(llm::OS::Foundation::Point contentOffset) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMoveRelativeToCurrentViewContent(*reinterpret_cast<llm::OS::Foundation::Point const*>(&contentOffset));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestMoveRelativeToDisplayRegion(void* displayRegion, llm::OS::Foundation::Point displayRegionOffset) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestMoveRelativeToDisplayRegion(*reinterpret_cast<llm::OS::UI::WindowManagement::DisplayRegion const*>(&displayRegion), *reinterpret_cast<llm::OS::Foundation::Point const*>(&displayRegionOffset));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestSize(llm::OS::Foundation::Size frameSize) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&frameSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryShowAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Changed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Changed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Changed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Changed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Closed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Closed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CloseRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CloseRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::AppWindow, llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CloseRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs>
    {
        int32_t __stdcall get_DidAvailableWindowPresentationsChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidAvailableWindowPresentationsChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidDisplayRegionsChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidDisplayRegionsChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidFrameChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidFrameChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidSizeChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidSizeChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidTitleBarChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidTitleBarChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidVisibilityChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidVisibilityChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidWindowingEnvironmentChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidWindowingEnvironmentChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DidWindowPresentationChange(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().DidWindowPresentationChange());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs>
    {
        int32_t __stdcall get_Cancel(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Cancel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Cancel(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Cancel(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::AppWindowClosedReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowFrame> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowFrame>
    {
        int32_t __stdcall get_DragRegionVisuals(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Composition::IVisualElement>>(this->shim().DragRegionVisuals());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowFrameStyle> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowFrameStyle>
    {
        int32_t __stdcall GetFrameStyle(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::WindowManagement::AppWindowFrameStyle>(this->shim().GetFrameStyle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFrameStyle(int32_t frameStyle) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFrameStyle(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindowFrameStyle const*>(&frameStyle));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowPlacement> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowPlacement>
    {
        int32_t __stdcall get_DisplayRegion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::DisplayRegion>(this->shim().DisplayRegion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Offset(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().Offset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::AppWindowPresentationKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowPresenter> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowPresenter>
    {
        int32_t __stdcall GetConfiguration(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration>(this->shim().GetConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPresentationSupported(int32_t presentationKind, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPresentationSupported(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindowPresentationKind const*>(&presentationKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPresentation(void* configuration, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().RequestPresentation(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration const*>(&configuration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPresentationByKind(int32_t presentationKind, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().RequestPresentation(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindowPresentationKind const*>(&presentationKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowStatics> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowStatics>
    {
        int32_t __stdcall TryCreateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WindowManagement::AppWindow>>(this->shim().TryCreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowTitleBar> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowTitleBar>
    {
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
        int32_t __stdcall get_ButtonBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonBackgroundColor());
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
        int32_t __stdcall get_ButtonForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonForegroundColor());
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
        int32_t __stdcall get_ButtonHoverBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonHoverBackgroundColor());
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
        int32_t __stdcall get_ButtonHoverForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonHoverForegroundColor());
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
        int32_t __stdcall get_ButtonInactiveBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonInactiveBackgroundColor());
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
        int32_t __stdcall get_ButtonInactiveForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonInactiveForegroundColor());
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
        int32_t __stdcall get_ButtonPressedBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonPressedBackgroundColor());
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
        int32_t __stdcall get_ButtonPressedForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().ButtonPressedForegroundColor());
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
        int32_t __stdcall get_ExtendsContentIntoTitleBar(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ExtendsContentIntoTitleBar());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExtendsContentIntoTitleBar(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExtendsContentIntoTitleBar(value);
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
        int32_t __stdcall get_InactiveBackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().InactiveBackgroundColor());
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
        int32_t __stdcall get_InactiveForegroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Color>>(this->shim().InactiveForegroundColor());
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
        int32_t __stdcall get_IsVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetTitleBarOcclusions(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion>>(this->shim().GetTitleBarOcclusions());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion>
    {
        int32_t __stdcall get_OccludingRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().OccludingRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility> : produce_base<D, llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility>
    {
        int32_t __stdcall GetPreferredVisibility(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility>(this->shim().GetPreferredVisibility());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPreferredVisibility(int32_t visibilityMode) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPreferredVisibility(*reinterpret_cast<llm::OS::UI::WindowManagement::AppWindowTitleBarVisibility const*>(&visibilityMode));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration> : produce_base<D, llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration> : produce_base<D, llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IDisplayRegion> : produce_base<D, llm::OS::UI::WindowManagement::IDisplayRegion>
    {
        int32_t __stdcall get_DisplayMonitorDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayMonitorDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WorkAreaOffset(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().WorkAreaOffset());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WorkAreaSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().WorkAreaSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WindowingEnvironment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::WindowingEnvironment>(this->shim().WindowingEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Changed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Changed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::DisplayRegion, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Changed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Changed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration> : produce_base<D, llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration>
    {
        int32_t __stdcall get_IsExclusive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsExclusive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsExclusive(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsExclusive(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IWindowServicesStatics> : produce_base<D, llm::OS::UI::WindowManagement::IWindowServicesStatics>
    {
        int32_t __stdcall FindAllTopLevelWindowIds(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowId>>(this->shim().FindAllTopLevelWindowIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IWindowingEnvironment> : produce_base<D, llm::OS::UI::WindowManagement::IWindowingEnvironment>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::WindowingEnvironmentKind>(this->shim().Kind());
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
        int32_t __stdcall add_Changed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Changed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WindowManagement::WindowingEnvironment, llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Changed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Changed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs> : produce_base<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs>
    {
        int32_t __stdcall get_WindowingEnvironment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::WindowingEnvironment>(this->shim().WindowingEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs> : produce_base<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs> : produce_base<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs>
    {
        int32_t __stdcall get_WindowingEnvironment(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowManagement::WindowingEnvironment>(this->shim().WindowingEnvironment());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics> : produce_base<D, llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics>
    {
        int32_t __stdcall FindAll(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>>(this->shim().FindAll());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllWithKind(int32_t kind, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>>(this->shim().FindAll(*reinterpret_cast<llm::OS::UI::WindowManagement::WindowingEnvironmentKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::WindowManagement
{
    inline auto AppWindow::TryCreateAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WindowManagement::AppWindow>(*)(IAppWindowStatics const&), AppWindow, IAppWindowStatics>([](IAppWindowStatics const& f) { return f.TryCreateAsync(); });
    }
    inline auto AppWindow::ClearAllPersistedState()
    {
        impl::call_factory_cast<void(*)(IAppWindowStatics const&), AppWindow, IAppWindowStatics>([](IAppWindowStatics const& f) { return f.ClearAllPersistedState(); });
    }
    inline auto AppWindow::ClearPersistedState(param::hstring const& key)
    {
        impl::call_factory<AppWindow, IAppWindowStatics>([&](IAppWindowStatics const& f) { return f.ClearPersistedState(key); });
    }
    inline CompactOverlayPresentationConfiguration::CompactOverlayPresentationConfiguration() :
        CompactOverlayPresentationConfiguration(impl::call_factory_cast<CompactOverlayPresentationConfiguration(*)(llm::OS::Foundation::IActivationFactory const&), CompactOverlayPresentationConfiguration>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CompactOverlayPresentationConfiguration>(); }))
    {
    }
    inline DefaultPresentationConfiguration::DefaultPresentationConfiguration() :
        DefaultPresentationConfiguration(impl::call_factory_cast<DefaultPresentationConfiguration(*)(llm::OS::Foundation::IActivationFactory const&), DefaultPresentationConfiguration>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DefaultPresentationConfiguration>(); }))
    {
    }
    inline FullScreenPresentationConfiguration::FullScreenPresentationConfiguration() :
        FullScreenPresentationConfiguration(impl::call_factory_cast<FullScreenPresentationConfiguration(*)(llm::OS::Foundation::IActivationFactory const&), FullScreenPresentationConfiguration>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<FullScreenPresentationConfiguration>(); }))
    {
    }
    inline auto WindowServices::FindAllTopLevelWindowIds()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowId>(*)(IWindowServicesStatics const&), WindowServices, IWindowServicesStatics>([](IWindowServicesStatics const& f) { return f.FindAllTopLevelWindowIds(); });
    }
    inline auto WindowingEnvironment::FindAll()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::WindowManagement::WindowingEnvironment>(*)(IWindowingEnvironmentStatics const&), WindowingEnvironment, IWindowingEnvironmentStatics>([](IWindowingEnvironmentStatics const& f) { return f.FindAll(); });
    }
    inline auto WindowingEnvironment::FindAll(llm::OS::UI::WindowManagement::WindowingEnvironmentKind const& kind)
    {
        return impl::call_factory<WindowingEnvironment, IWindowingEnvironmentStatics>([&](IWindowingEnvironmentStatics const& f) { return f.FindAll(kind); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowCloseRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowClosedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowFrameStyle> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowPlacement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowPresentationConfigurationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowPresenter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowTitleBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowTitleBarOcclusion> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IAppWindowTitleBarVisibility> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::ICompactOverlayPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IDefaultPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IDisplayRegion> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IFullScreenPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IWindowServicesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IWindowingEnvironment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IWindowingEnvironmentAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IWindowingEnvironmentChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IWindowingEnvironmentRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::IWindowingEnvironmentStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowCloseRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowClosedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowFrame> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowPlacement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowPresenter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowTitleBar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::AppWindowTitleBarOcclusion> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::CompactOverlayPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::DefaultPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::DisplayRegion> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::FullScreenPresentationConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::WindowServices> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::WindowingEnvironment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::WindowingEnvironmentAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::WindowingEnvironmentChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WindowManagement::WindowingEnvironmentRemovedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
