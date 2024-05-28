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
#ifndef LLM_OS_UI_ViewManagement_Core_H
#define LLM_OS_UI_ViewManagement_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.ViewManagement.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.ViewManagement.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::PrimaryViewAnimationStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView)->add_PrimaryViewAnimationStarting(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::PrimaryViewAnimationStarting_revoker consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::PrimaryViewAnimationStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PrimaryViewAnimationStarting_revoker>(this, PrimaryViewAnimationStarting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::PrimaryViewAnimationStarting(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView)->remove_PrimaryViewAnimationStarting(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::OcclusionsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView)->add_OcclusionsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::OcclusionsChanged_revoker consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::OcclusionsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, OcclusionsChanged_revoker>(this, OcclusionsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputView<D>::OcclusionsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView)->remove_OcclusionsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewAnimationStartingEventArgs<D>::Occlusions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs)->get_Occlusions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewAnimationStartingEventArgs<D>::FrameworkAnimationRecommended() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs)->get_FrameworkAnimationRecommended(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewAnimationStartingEventArgs<D>::AnimationDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs)->get_AnimationDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewOcclusionsChangedEventArgs<D>::Occlusions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs)->get_Occlusions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewOcclusionsChangedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewStatics<D>::GetForUIContext(llm::OS::UI::UIContext const& context) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics)->GetForUIContext(*(void**)(&context), &result));
        return llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView) consume_Windows_UI_ViewManagement_Core_ICoreFrameworkInputViewStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics)->GetForCurrentView(&result));
        return llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::OcclusionsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView)->add_OcclusionsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::OcclusionsChanged_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::OcclusionsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, OcclusionsChanged_revoker>(this, OcclusionsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::OcclusionsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView)->remove_OcclusionsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::GetCoreInputViewOcclusions() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView)->GetCoreInputViewOcclusions(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::TryShowPrimaryView() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView)->TryShowPrimaryView(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView<D>::TryHidePrimaryView() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView)->TryHidePrimaryView(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferringFromPrimaryView(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView2)->add_XYFocusTransferringFromPrimaryView(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferringFromPrimaryView_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferringFromPrimaryView(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, XYFocusTransferringFromPrimaryView_revoker>(this, XYFocusTransferringFromPrimaryView(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferringFromPrimaryView(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView2)->remove_XYFocusTransferringFromPrimaryView(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferredToPrimaryView(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView2)->add_XYFocusTransferredToPrimaryView(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferredToPrimaryView_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferredToPrimaryView(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, XYFocusTransferredToPrimaryView_revoker>(this, XYFocusTransferredToPrimaryView(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::XYFocusTransferredToPrimaryView(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView2)->remove_XYFocusTransferredToPrimaryView(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView2<D>::TryTransferXYFocusToPrimaryView(llm::OS::Foundation::Rect const& origin, llm::OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection const& direction) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView2)->TryTransferXYFocusToPrimaryView(impl::bind_in(origin), static_cast<int32_t>(direction), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView3<D>::TryShow() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView3)->TryShow(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView3<D>::TryShow(llm::OS::UI::ViewManagement::Core::CoreInputViewKind const& type) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView3)->TryShowWithKind(static_cast<int32_t>(type), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView3<D>::TryHide() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView3)->TryHide(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewShowing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView4)->add_PrimaryViewShowing(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewShowing_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewShowing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PrimaryViewShowing_revoker>(this, PrimaryViewShowing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewShowing(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView4)->remove_PrimaryViewShowing(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewHiding(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView4)->add_PrimaryViewHiding(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewHiding_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewHiding(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PrimaryViewHiding_revoker>(this, PrimaryViewHiding(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView4<D>::PrimaryViewHiding(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView4)->remove_PrimaryViewHiding(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::IsKindSupported(llm::OS::UI::ViewManagement::Core::CoreInputViewKind const& type) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView5)->IsKindSupported(static_cast<int32_t>(type), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::SupportedKindsChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView5)->add_SupportedKindsChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::SupportedKindsChanged_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::SupportedKindsChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, SupportedKindsChanged_revoker>(this, SupportedKindsChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::SupportedKindsChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView5)->remove_SupportedKindsChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::PrimaryViewAnimationStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView5)->add_PrimaryViewAnimationStarting(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::PrimaryViewAnimationStarting_revoker consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::PrimaryViewAnimationStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PrimaryViewAnimationStarting_revoker>(this, PrimaryViewAnimationStarting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputView5<D>::PrimaryViewAnimationStarting(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputView5)->remove_PrimaryViewAnimationStarting(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) consume_Windows_UI_ViewManagement_Core_ICoreInputViewAnimationStartingEventArgs<D>::Occlusions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs)->get_Occlusions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputViewAnimationStartingEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputViewAnimationStartingEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_UI_ViewManagement_Core_ICoreInputViewAnimationStartingEventArgs<D>::AnimationDuration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs)->get_AnimationDuration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputViewHidingEventArgs<D>::TryCancel() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs)->TryCancel(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusion<D>::OccludingRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusion)->get_OccludingRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionKind) consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusion<D>::OcclusionKind() const
    {
        llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusion)->get_OcclusionKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>) consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusionsChangedEventArgs<D>::Occlusions() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs)->get_Occlusions(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusionsChangedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputViewOcclusionsChangedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputViewShowingEventArgs<D>::TryCancel() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs)->TryCancel(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::Core::CoreInputView) consume_Windows_UI_ViewManagement_Core_ICoreInputViewStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics)->GetForCurrentView(&result));
        return llm::OS::UI::ViewManagement::Core::CoreInputView{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::Core::CoreInputView) consume_Windows_UI_ViewManagement_Core_ICoreInputViewStatics2<D>::GetForUIContext(llm::OS::UI::UIContext const& context) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics2)->GetForUIContext(*(void**)(&context), &result));
        return llm::OS::UI::ViewManagement::Core::CoreInputView{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>::Origin() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs)->get_Origin(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection) consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>::Direction() const
    {
        llm::OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs)->get_Direction(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>::TransferHandled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs)->put_TransferHandled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>::TransferHandled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs)->get_TransferHandled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>::KeepPrimaryViewVisible(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs)->put_KeepPrimaryViewVisible(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_ViewManagement_Core_ICoreInputViewTransferringXYFocusEventArgs<D>::KeepPrimaryViewVisible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs)->get_KeepPrimaryViewVisible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_IUISettingsController<D>::SetAdvancedEffectsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::IUISettingsController)->SetAdvancedEffectsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_IUISettingsController<D>::SetAnimationsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::IUISettingsController)->SetAnimationsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_IUISettingsController<D>::SetAutoHideScrollBars(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::IUISettingsController)->SetAutoHideScrollBars(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_IUISettingsController<D>::SetMessageDuration(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::IUISettingsController)->SetMessageDuration(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_ViewManagement_Core_IUISettingsController<D>::SetTextScaleFactor(double value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::IUISettingsController)->SetTextScaleFactor(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::ViewManagement::Core::UISettingsController>) consume_Windows_UI_ViewManagement_Core_IUISettingsControllerStatics<D>::RequestDefaultAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::ViewManagement::Core::IUISettingsControllerStatics)->RequestDefaultAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::ViewManagement::Core::UISettingsController>{ operation, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView>
    {
        int32_t __stdcall add_PrimaryViewAnimationStarting(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PrimaryViewAnimationStarting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PrimaryViewAnimationStarting(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimaryViewAnimationStarting(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_OcclusionsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().OcclusionsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView, llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OcclusionsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OcclusionsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs>
    {
        int32_t __stdcall get_Occlusions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>>(this->shim().Occlusions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FrameworkAnimationRecommended(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().FrameworkAnimationRecommended());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AnimationDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().AnimationDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs>
    {
        int32_t __stdcall get_Occlusions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>>(this->shim().Occlusions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics>
    {
        int32_t __stdcall GetForUIContext(void* context, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView>(this->shim().GetForUIContext(*reinterpret_cast<llm::OS::UI::UIContext const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputView> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputView>
    {
        int32_t __stdcall add_OcclusionsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().OcclusionsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_OcclusionsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OcclusionsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetCoreInputViewOcclusions(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>>(this->shim().GetCoreInputViewOcclusions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowPrimaryView(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryShowPrimaryView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryHidePrimaryView(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryHidePrimaryView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputView2> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputView2>
    {
        int32_t __stdcall add_XYFocusTransferringFromPrimaryView(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().XYFocusTransferringFromPrimaryView(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_XYFocusTransferringFromPrimaryView(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().XYFocusTransferringFromPrimaryView(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_XYFocusTransferredToPrimaryView(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().XYFocusTransferredToPrimaryView(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_XYFocusTransferredToPrimaryView(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().XYFocusTransferredToPrimaryView(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall TryTransferXYFocusToPrimaryView(llm::OS::Foundation::Rect origin, int32_t direction, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryTransferXYFocusToPrimaryView(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&origin), *reinterpret_cast<llm::OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection const*>(&direction)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputView3> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputView3>
    {
        int32_t __stdcall TryShow(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryShow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryShowWithKind(int32_t type, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryShow(*reinterpret_cast<llm::OS::UI::ViewManagement::Core::CoreInputViewKind const*>(&type)));
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
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputView4> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputView4>
    {
        int32_t __stdcall add_PrimaryViewShowing(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PrimaryViewShowing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PrimaryViewShowing(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimaryViewShowing(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PrimaryViewHiding(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PrimaryViewHiding(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PrimaryViewHiding(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimaryViewHiding(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputView5> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputView5>
    {
        int32_t __stdcall IsKindSupported(int32_t type, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsKindSupported(*reinterpret_cast<llm::OS::UI::ViewManagement::Core::CoreInputViewKind const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SupportedKindsChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SupportedKindsChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SupportedKindsChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SupportedKindsChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_PrimaryViewAnimationStarting(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PrimaryViewAnimationStarting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::ViewManagement::Core::CoreInputView, llm::OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PrimaryViewAnimationStarting(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrimaryViewAnimationStarting(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs>
    {
        int32_t __stdcall get_Occlusions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>>(this->shim().Occlusions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AnimationDuration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().AnimationDuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs>
    {
        int32_t __stdcall TryCancel(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryCancel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusion> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusion>
    {
        int32_t __stdcall get_OccludingRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().OccludingRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OcclusionKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionKind>(this->shim().OcclusionKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs>
    {
        int32_t __stdcall get_Occlusions(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion>>(this->shim().Occlusions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Handled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Handled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Handled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Handled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs>
    {
        int32_t __stdcall TryCancel(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryCancel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::ViewManagement::Core::CoreInputView>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics2> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics2>
    {
        int32_t __stdcall GetForUIContext(void* context, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::ViewManagement::Core::CoreInputView>(this->shim().GetForUIContext(*reinterpret_cast<llm::OS::UI::UIContext const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs> : produce_base<D, llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs>
    {
        int32_t __stdcall get_Origin(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().Origin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Direction(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::Core::CoreInputViewXYFocusTransferDirection>(this->shim().Direction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransferHandled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransferHandled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransferHandled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().TransferHandled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_KeepPrimaryViewVisible(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeepPrimaryViewVisible(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeepPrimaryViewVisible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().KeepPrimaryViewVisible());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::IUISettingsController> : produce_base<D, llm::OS::UI::ViewManagement::Core::IUISettingsController>
    {
        int32_t __stdcall SetAdvancedEffectsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAdvancedEffectsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAnimationsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAnimationsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAutoHideScrollBars(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAutoHideScrollBars(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetMessageDuration(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetMessageDuration(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetTextScaleFactor(double value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetTextScaleFactor(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::ViewManagement::Core::IUISettingsControllerStatics> : produce_base<D, llm::OS::UI::ViewManagement::Core::IUISettingsControllerStatics>
    {
        int32_t __stdcall RequestDefaultAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::ViewManagement::Core::UISettingsController>>(this->shim().RequestDefaultAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::ViewManagement::Core
{
    inline auto CoreFrameworkInputView::GetForUIContext(llm::OS::UI::UIContext const& context)
    {
        return impl::call_factory<CoreFrameworkInputView, ICoreFrameworkInputViewStatics>([&](ICoreFrameworkInputViewStatics const& f) { return f.GetForUIContext(context); });
    }
    inline auto CoreFrameworkInputView::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView(*)(ICoreFrameworkInputViewStatics const&), CoreFrameworkInputView, ICoreFrameworkInputViewStatics>([](ICoreFrameworkInputViewStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto CoreInputView::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::ViewManagement::Core::CoreInputView(*)(ICoreInputViewStatics const&), CoreInputView, ICoreInputViewStatics>([](ICoreInputViewStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto CoreInputView::GetForUIContext(llm::OS::UI::UIContext const& context)
    {
        return impl::call_factory<CoreInputView, ICoreInputViewStatics2>([&](ICoreInputViewStatics2 const& f) { return f.GetForUIContext(context); });
    }
    inline auto UISettingsController::RequestDefaultAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::ViewManagement::Core::UISettingsController>(*)(IUISettingsControllerStatics const&), UISettingsController, IUISettingsControllerStatics>([](IUISettingsControllerStatics const& f) { return f.RequestDefaultAsync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewAnimationStartingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewOcclusionsChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreFrameworkInputViewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputView2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputView3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputView4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputView5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewAnimationStartingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewHidingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusion> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewOcclusionsChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewShowingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::ICoreInputViewTransferringXYFocusEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::IUISettingsController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::IUISettingsControllerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewAnimationStartingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreFrameworkInputViewOcclusionsChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputViewAnimationStartingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputViewHidingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusion> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputViewOcclusionsChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputViewShowingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::CoreInputViewTransferringXYFocusEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::ViewManagement::Core::UISettingsController> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
