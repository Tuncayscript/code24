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
#ifndef LLM_OS_UI_Input_Inking_Core_H
#define LLM_OS_UI_Input_Inking_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Input.Inking.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Foundation.Numerics.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
#include "llm/impl/Windows.UI.Input.Inking.2.h"
#include "llm/impl/Windows.UI.Input.Inking.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Input_Inking_Core_ICoreIncrementalInkStroke<D>::AppendInkPoints(param::iterable<llm::OS::UI::Input::Inking::InkPoint> const& inkPoints) const
    {
        llm::OS::Foundation::Rect result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke)->AppendInkPoints(*(void**)(&inkPoints), put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::InkStroke) consume_Windows_UI_Input_Inking_Core_ICoreIncrementalInkStroke<D>::CreateInkStroke() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke)->CreateInkStroke(&result));
        return llm::OS::UI::Input::Inking::InkStroke{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::InkDrawingAttributes) consume_Windows_UI_Input_Inking_Core_ICoreIncrementalInkStroke<D>::DrawingAttributes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke)->get_DrawingAttributes(&value));
        return llm::OS::UI::Input::Inking::InkDrawingAttributes{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Numerics::float3x2) consume_Windows_UI_Input_Inking_Core_ICoreIncrementalInkStroke<D>::PointTransform() const
    {
        llm::OS::Foundation::Numerics::float3x2 value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke)->get_PointTransform(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Input_Inking_Core_ICoreIncrementalInkStroke<D>::BoundingRect() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke)->get_BoundingRect(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::Core::CoreIncrementalInkStroke) consume_Windows_UI_Input_Inking_Core_ICoreIncrementalInkStrokeFactory<D>::Create(llm::OS::UI::Input::Inking::InkDrawingAttributes const& drawingAttributes, llm::OS::Foundation::Numerics::float3x2 const& pointTransform) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStrokeFactory)->Create(*(void**)(&drawingAttributes), impl::bind_in(pointTransform), &result));
        return llm::OS::UI::Input::Inking::Core::CoreIncrementalInkStroke{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerEntering(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerEntering(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerEntering_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerEntering(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerEntering_revoker>(this, PointerEntering(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerEntering(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerEntering(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerHovering(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerHovering(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerHovering_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerHovering(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerHovering_revoker>(this, PointerHovering(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerHovering(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerHovering(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerExiting(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerExiting(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerExiting_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerExiting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerExiting_revoker>(this, PointerExiting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerExiting(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerExiting(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerPressing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerPressing(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerPressing_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerPressing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerPressing_revoker>(this, PointerPressing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerPressing(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerPressing(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerMoving(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerMoving(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerMoving_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerMoving(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerMoving_revoker>(this, PointerMoving(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerMoving(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerMoving(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerReleasing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerReleasing(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerReleasing_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerReleasing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerReleasing_revoker>(this, PointerReleasing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerReleasing(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerReleasing(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerLost(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->add_PointerLost(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerLost_revoker consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerLost(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerLost_revoker>(this, PointerLost(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::PointerLost(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->remove_PointerLost(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::InkPresenter) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource<D>::InkPresenter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource)->get_InkPresenter(&value));
        return llm::OS::UI::Input::Inking::InkPresenter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreCursor) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource2<D>::PointerCursor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource2)->get_PointerCursor(&value));
        return llm::OS::UI::Core::CoreCursor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSource2<D>::PointerCursor(llm::OS::UI::Core::CoreCursor const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource2)->put_PointerCursor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource) consume_Windows_UI_Input_Inking_Core_ICoreInkIndependentInputSourceStatics<D>::Create(llm::OS::UI::Input::Inking::InkPresenter const& inkPresenter) const
    {
        void* inkIndependentInputSource{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics)->Create(*(void**)(&inkPresenter), &inkIndependentInputSource));
        return llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource{ inkIndependentInputSource, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::InkPresenter) consume_Windows_UI_Input_Inking_Core_ICoreInkPresenterHost<D>::InkPresenter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkPresenterHost)->get_InkPresenter(&value));
        return llm::OS::UI::Input::Inking::InkPresenter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Composition::ContainerVisual) consume_Windows_UI_Input_Inking_Core_ICoreInkPresenterHost<D>::RootVisual() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkPresenterHost)->get_RootVisual(&value));
        return llm::OS::UI::Composition::ContainerVisual{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreInkPresenterHost<D>::RootVisual(llm::OS::UI::Composition::ContainerVisual const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreInkPresenterHost)->put_RootVisual(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Input::Inking::InkPoint>) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateEventArgs<D>::NewInkPoints() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs)->get_NewInkPoints(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Input::Inking::InkPoint>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateEventArgs<D>::PointerId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs)->get_PointerId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::Core::CoreWetStrokeDisposition) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateEventArgs<D>::Disposition() const
    {
        llm::OS::UI::Input::Inking::Core::CoreWetStrokeDisposition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs)->get_Disposition(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateEventArgs<D>::Disposition(llm::OS::UI::Input::Inking::Core::CoreWetStrokeDisposition const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs)->put_Disposition(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->add_WetStrokeStarting(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting_revoker consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, WetStrokeStarting_revoker>(this, WetStrokeStarting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStarting(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->remove_WetStrokeStarting(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->add_WetStrokeContinuing(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing_revoker consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, WetStrokeContinuing_revoker>(this, WetStrokeContinuing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeContinuing(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->remove_WetStrokeContinuing(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->add_WetStrokeStopping(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping_revoker consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, WetStrokeStopping_revoker>(this, WetStrokeStopping(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeStopping(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->remove_WetStrokeStopping(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->add_WetStrokeCompleted(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted_revoker consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, WetStrokeCompleted_revoker>(this, WetStrokeCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCompleted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->remove_WetStrokeCompleted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->add_WetStrokeCanceled(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled_revoker consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, WetStrokeCanceled_revoker>(this, WetStrokeCanceled(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::WetStrokeCanceled(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->remove_WetStrokeCanceled(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::InkPresenter) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSource<D>::InkPresenter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource)->get_InkPresenter(&value));
        return llm::OS::UI::Input::Inking::InkPresenter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource) consume_Windows_UI_Input_Inking_Core_ICoreWetStrokeUpdateSourceStatics<D>::Create(llm::OS::UI::Input::Inking::InkPresenter const& inkPresenter) const
    {
        void* WetStrokeUpdateSource{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics)->Create(*(void**)(&inkPresenter), &WetStrokeUpdateSource));
        return llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource{ WetStrokeUpdateSource, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke>
    {
        int32_t __stdcall AppendInkPoints(void* inkPoints, llm::OS::Foundation::Rect* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Rect>(this->shim().AppendInkPoints(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Input::Inking::InkPoint> const*>(&inkPoints)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateInkStroke(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Input::Inking::InkStroke>(this->shim().CreateInkStroke());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DrawingAttributes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::Inking::InkDrawingAttributes>(this->shim().DrawingAttributes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PointTransform(llm::OS::Foundation::Numerics::float3x2* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Numerics::float3x2>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Numerics::float3x2>(this->shim().PointTransform());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BoundingRect(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().BoundingRect());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStrokeFactory> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStrokeFactory>
    {
        int32_t __stdcall Create(void* drawingAttributes, llm::OS::Foundation::Numerics::float3x2 pointTransform, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Input::Inking::Core::CoreIncrementalInkStroke>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Input::Inking::InkDrawingAttributes const*>(&drawingAttributes), *reinterpret_cast<llm::OS::Foundation::Numerics::float3x2 const*>(&pointTransform)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource>
    {
        int32_t __stdcall add_PointerEntering(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerEntering(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerEntering(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntering(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerHovering(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerHovering(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerHovering(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerHovering(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerExiting(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerExiting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerExiting(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExiting(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerPressing(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerPressing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerPressing(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressing(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerMoving(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerMoving(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerMoving(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoving(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerReleasing(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerReleasing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerReleasing(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleasing(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerLost(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerLost(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerLost(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerLost(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_InkPresenter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::Inking::InkPresenter>(this->shim().InkPresenter());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource2> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource2>
    {
        int32_t __stdcall get_PointerCursor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreCursor>(this->shim().PointerCursor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PointerCursor(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCursor(*reinterpret_cast<llm::OS::UI::Core::CoreCursor const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics>
    {
        int32_t __stdcall Create(void* inkPresenter, void** inkIndependentInputSource) noexcept final try
        {
            clear_abi(inkIndependentInputSource);
            typename D::abi_guard guard(this->shim());
            *inkIndependentInputSource = detach_from<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Input::Inking::InkPresenter const*>(&inkPresenter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreInkPresenterHost> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreInkPresenterHost>
    {
        int32_t __stdcall get_InkPresenter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::Inking::InkPresenter>(this->shim().InkPresenter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RootVisual(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Composition::ContainerVisual>(this->shim().RootVisual());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RootVisual(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RootVisual(*reinterpret_cast<llm::OS::UI::Composition::ContainerVisual const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs>
    {
        int32_t __stdcall get_NewInkPoints(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Input::Inking::InkPoint>>(this->shim().NewInkPoints());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PointerId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PointerId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Disposition(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::Inking::Core::CoreWetStrokeDisposition>(this->shim().Disposition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Disposition(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disposition(*reinterpret_cast<llm::OS::UI::Input::Inking::Core::CoreWetStrokeDisposition const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource>
    {
        int32_t __stdcall add_WetStrokeStarting(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().WetStrokeStarting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_WetStrokeStarting(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeStarting(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_WetStrokeContinuing(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().WetStrokeContinuing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_WetStrokeContinuing(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeContinuing(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_WetStrokeStopping(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().WetStrokeStopping(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_WetStrokeStopping(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeStopping(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_WetStrokeCompleted(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().WetStrokeCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_WetStrokeCompleted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeCompleted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_WetStrokeCanceled(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().WetStrokeCanceled(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource, llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_WetStrokeCanceled(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WetStrokeCanceled(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_InkPresenter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::Inking::InkPresenter>(this->shim().InkPresenter());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics> : produce_base<D, llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics>
    {
        int32_t __stdcall Create(void* inkPresenter, void** WetStrokeUpdateSource) noexcept final try
        {
            clear_abi(WetStrokeUpdateSource);
            typename D::abi_guard guard(this->shim());
            *WetStrokeUpdateSource = detach_from<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource>(this->shim().Create(*reinterpret_cast<llm::OS::UI::Input::Inking::InkPresenter const*>(&inkPresenter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Input::Inking::Core
{
    inline CoreIncrementalInkStroke::CoreIncrementalInkStroke(llm::OS::UI::Input::Inking::InkDrawingAttributes const& drawingAttributes, llm::OS::Foundation::Numerics::float3x2 const& pointTransform) :
        CoreIncrementalInkStroke(impl::call_factory<CoreIncrementalInkStroke, ICoreIncrementalInkStrokeFactory>([&](ICoreIncrementalInkStrokeFactory const& f) { return f.Create(drawingAttributes, pointTransform); }))
    {
    }
    inline auto CoreInkIndependentInputSource::Create(llm::OS::UI::Input::Inking::InkPresenter const& inkPresenter)
    {
        return impl::call_factory<CoreInkIndependentInputSource, ICoreInkIndependentInputSourceStatics>([&](ICoreInkIndependentInputSourceStatics const& f) { return f.Create(inkPresenter); });
    }
    inline CoreInkPresenterHost::CoreInkPresenterHost() :
        CoreInkPresenterHost(impl::call_factory_cast<CoreInkPresenterHost(*)(llm::OS::Foundation::IActivationFactory const&), CoreInkPresenterHost>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CoreInkPresenterHost>(); }))
    {
    }
    inline auto CoreWetStrokeUpdateSource::Create(llm::OS::UI::Input::Inking::InkPresenter const& inkPresenter)
    {
        return impl::call_factory<CoreWetStrokeUpdateSource, ICoreWetStrokeUpdateSourceStatics>([&](ICoreWetStrokeUpdateSourceStatics const& f) { return f.Create(inkPresenter); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStroke> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreIncrementalInkStrokeFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreInkIndependentInputSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreInkPresenterHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::ICoreWetStrokeUpdateSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::CoreIncrementalInkStroke> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::CoreInkIndependentInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::CoreInkPresenterHost> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Input::Inking::Core::CoreWetStrokeUpdateSource> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
