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
#ifndef LLM_OS_UI_Text_Core_H
#define LLM_OS_UI_Text_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Text.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Globalization.2.h"
#include "llm/impl/Windows.UI.Text.2.h"
#include "llm/impl/Windows.UI.ViewManagement.2.h"
#include "llm/impl/Windows.UI.Text.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextCompositionCompletedEventArgs<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Text::Core::CoreTextCompositionSegment>) consume_Windows_UI_Text_Core_ICoreTextCompositionCompletedEventArgs<D>::CompositionSegments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs)->get_CompositionSegments(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Text::Core::CoreTextCompositionSegment>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextCompositionCompletedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Text_Core_ICoreTextCompositionSegment<D>::PreconversionString() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionSegment)->get_PreconversionString(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextCompositionSegment<D>::Range() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionSegment)->get_Range(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextCompositionStartedEventArgs<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextCompositionStartedEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::Name(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->put_Name(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextInputScope) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::InputScope() const
    {
        llm::OS::UI::Text::Core::CoreTextInputScope value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->get_InputScope(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::InputScope(llm::OS::UI::Text::Core::CoreTextInputScope const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->put_InputScope(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::IsReadOnly() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->get_IsReadOnly(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::IsReadOnly(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->put_IsReadOnly(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextInputPaneDisplayPolicy) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::InputPaneDisplayPolicy() const
    {
        llm::OS::UI::Text::Core::CoreTextInputPaneDisplayPolicy value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->get_InputPaneDisplayPolicy(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::InputPaneDisplayPolicy(llm::OS::UI::Text::Core::CoreTextInputPaneDisplayPolicy const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->put_InputPaneDisplayPolicy(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextTextRequestedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_TextRequested(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextRequested_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextTextRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TextRequested_revoker>(this, TextRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_TextRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextSelectionRequestedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_SelectionRequested(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionRequested_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextSelectionRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SelectionRequested_revoker>(this, SelectionRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_SelectionRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::LayoutRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextLayoutRequestedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_LayoutRequested(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::LayoutRequested_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::LayoutRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextLayoutRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, LayoutRequested_revoker>(this, LayoutRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::LayoutRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_LayoutRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextTextUpdatingEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_TextUpdating(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextUpdating_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextTextUpdatingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TextUpdating_revoker>(this, TextUpdating(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::TextUpdating(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_TextUpdating(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_SelectionUpdating(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionUpdating_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SelectionUpdating_revoker>(this, SelectionUpdating(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::SelectionUpdating(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_SelectionUpdating(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FormatUpdating(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextFormatUpdatingEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_FormatUpdating(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FormatUpdating_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FormatUpdating(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextFormatUpdatingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, FormatUpdating_revoker>(this, FormatUpdating(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FormatUpdating(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_FormatUpdating(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionStarted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextCompositionStartedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_CompositionStarted(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionStarted_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionStarted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextCompositionStartedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CompositionStarted_revoker>(this, CompositionStarted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionStarted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_CompositionStarted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextCompositionCompletedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_CompositionCompleted(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionCompleted_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextCompositionCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CompositionCompleted_revoker>(this, CompositionCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::CompositionCompleted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_CompositionCompleted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FocusRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->add_FocusRemoved(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FocusRemoved_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FocusRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, FocusRemoved_revoker>(this, FocusRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::FocusRemoved(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->remove_FocusRemoved(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::NotifyFocusEnter() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->NotifyFocusEnter());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::NotifyFocusLeave() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->NotifyFocusLeave());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::NotifyTextChanged(llm::OS::UI::Text::Core::CoreTextRange const& modifiedRange, int32_t newLength, llm::OS::UI::Text::Core::CoreTextRange const& newSelection) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->NotifyTextChanged(impl::bind_in(modifiedRange), newLength, impl::bind_in(newSelection)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::NotifySelectionChanged(llm::OS::UI::Text::Core::CoreTextRange const& selection) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->NotifySelectionChanged(impl::bind_in(selection)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext<D>::NotifyLayoutChanged() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext)->NotifyLayoutChanged());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext2)->add_NotifyFocusLeaveCompleted(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted_revoker consume_Windows_UI_Text_Core_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, NotifyFocusLeaveCompleted_revoker>(this, NotifyFocusLeaveCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextEditContext2<D>::NotifyFocusLeaveCompleted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextEditContext2)->remove_NotifyFocusLeaveCompleted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::Range() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_Range(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::TextColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_TextColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::BackgroundColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_BackgroundColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::UnderlineColor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_UnderlineColor(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Text::UnderlineType>) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::UnderlineType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_UnderlineType(&value));
        return llm::OS::Foundation::IReference<llm::OS::UI::Text::UnderlineType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextFormatUpdatingReason) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::Reason() const
    {
        llm::OS::UI::Text::Core::CoreTextFormatUpdatingReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextFormatUpdatingResult) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::Result() const
    {
        llm::OS::UI::Text::Core::CoreTextFormatUpdatingResult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_Result(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::Result(llm::OS::UI::Text::Core::CoreTextFormatUpdatingResult const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->put_Result(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextFormatUpdatingEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Text_Core_ICoreTextLayoutBounds<D>::TextBounds() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutBounds)->get_TextBounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextLayoutBounds<D>::TextBounds(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutBounds)->put_TextBounds(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Text_Core_ICoreTextLayoutBounds<D>::ControlBounds() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutBounds)->get_ControlBounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextLayoutBounds<D>::ControlBounds(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutBounds)->put_ControlBounds(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextLayoutRequest<D>::Range() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutRequest)->get_Range(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextLayoutBounds) consume_Windows_UI_Text_Core_ICoreTextLayoutRequest<D>::LayoutBounds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutRequest)->get_LayoutBounds(&value));
        return llm::OS::UI::Text::Core::CoreTextLayoutBounds{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextLayoutRequest<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutRequest)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextLayoutRequest<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutRequest)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextLayoutBounds) consume_Windows_UI_Text_Core_ICoreTextLayoutRequest2<D>::LayoutBoundsVisualPixels() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutRequest2)->get_LayoutBoundsVisualPixels(&value));
        return llm::OS::UI::Text::Core::CoreTextLayoutBounds{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextLayoutRequest) consume_Windows_UI_Text_Core_ICoreTextLayoutRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextLayoutRequestedEventArgs)->get_Request(&value));
        return llm::OS::UI::Text::Core::CoreTextLayoutRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextSelectionRequest<D>::Selection() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionRequest)->get_Selection(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextSelectionRequest<D>::Selection(llm::OS::UI::Text::Core::CoreTextRange const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionRequest)->put_Selection(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextSelectionRequest<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionRequest)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextSelectionRequest<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionRequest)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextSelectionRequest) consume_Windows_UI_Text_Core_ICoreTextSelectionRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionRequestedEventArgs)->get_Request(&value));
        return llm::OS::UI::Text::Core::CoreTextSelectionRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextSelectionUpdatingEventArgs<D>::Selection() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs)->get_Selection(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextSelectionUpdatingResult) consume_Windows_UI_Text_Core_ICoreTextSelectionUpdatingEventArgs<D>::Result() const
    {
        llm::OS::UI::Text::Core::CoreTextSelectionUpdatingResult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs)->get_Result(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextSelectionUpdatingEventArgs<D>::Result(llm::OS::UI::Text::Core::CoreTextSelectionUpdatingResult const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs)->put_Result(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextSelectionUpdatingEventArgs<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextSelectionUpdatingEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::Language) consume_Windows_UI_Text_Core_ICoreTextServicesManager<D>::InputLanguage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextServicesManager)->get_InputLanguage(&value));
        return llm::OS::Globalization::Language{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Text_Core_ICoreTextServicesManager<D>::InputLanguageChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextServicesManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextServicesManager)->add_InputLanguageChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Text_Core_ICoreTextServicesManager<D>::InputLanguageChanged_revoker consume_Windows_UI_Text_Core_ICoreTextServicesManager<D>::InputLanguageChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextServicesManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, InputLanguageChanged_revoker>(this, InputLanguageChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextServicesManager<D>::InputLanguageChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextServicesManager)->remove_InputLanguageChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextEditContext) consume_Windows_UI_Text_Core_ICoreTextServicesManager<D>::CreateEditContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextServicesManager)->CreateEditContext(&value));
        return llm::OS::UI::Text::Core::CoreTextEditContext{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextServicesManager) consume_Windows_UI_Text_Core_ICoreTextServicesManagerStatics<D>::GetForCurrentView() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextServicesManagerStatics)->GetForCurrentView(&value));
        return llm::OS::UI::Text::Core::CoreTextServicesManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(char16_t) consume_Windows_UI_Text_Core_ICoreTextServicesStatics<D>::HiddenCharacter() const
    {
        char16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextServicesStatics)->get_HiddenCharacter(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextTextRequest<D>::Range() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextRequest)->get_Range(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Text_Core_ICoreTextTextRequest<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextRequest)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextTextRequest<D>::Text(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextRequest)->put_Text(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextTextRequest<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextRequest)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextTextRequest<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextRequest)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextTextRequest) consume_Windows_UI_Text_Core_ICoreTextTextRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextRequestedEventArgs)->get_Request(&value));
        return llm::OS::UI::Text::Core::CoreTextTextRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::Range() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->get_Range(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextRange) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::NewSelection() const
    {
        llm::OS::UI::Text::Core::CoreTextRange value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->get_NewSelection(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Globalization::Language) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::InputLanguage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->get_InputLanguage(&value));
        return llm::OS::Globalization::Language{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Text::Core::CoreTextTextUpdatingResult) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::Result() const
    {
        llm::OS::UI::Text::Core::CoreTextTextUpdatingResult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->get_Result(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::Result(llm::OS::UI::Text::Core::CoreTextTextUpdatingResult const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->put_Result(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Text_Core_ICoreTextTextUpdatingEventArgs<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs>
    {
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CompositionSegments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Text::Core::CoreTextCompositionSegment>>(this->shim().CompositionSegments());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextCompositionSegment> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextCompositionSegment>
    {
        int32_t __stdcall get_PreconversionString(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PreconversionString());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Range(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Range());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs>
    {
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextEditContext> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextEditContext>
    {
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Name(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Name(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InputScope(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextInputScope>(this->shim().InputScope());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InputScope(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputScope(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextInputScope const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsReadOnly(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsReadOnly());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsReadOnly(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsReadOnly(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InputPaneDisplayPolicy(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextInputPaneDisplayPolicy>(this->shim().InputPaneDisplayPolicy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InputPaneDisplayPolicy(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputPaneDisplayPolicy(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextInputPaneDisplayPolicy const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_TextRequested(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().TextRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextTextRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TextRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_SelectionRequested(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().SelectionRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextSelectionRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SelectionRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_LayoutRequested(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().LayoutRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextLayoutRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LayoutRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LayoutRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_TextUpdating(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().TextUpdating(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextTextUpdatingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TextUpdating(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextUpdating(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_SelectionUpdating(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().SelectionUpdating(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SelectionUpdating(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectionUpdating(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_FormatUpdating(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().FormatUpdating(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextFormatUpdatingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FormatUpdating(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FormatUpdating(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_CompositionStarted(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().CompositionStarted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextCompositionStartedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CompositionStarted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositionStarted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_CompositionCompleted(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().CompositionCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::UI::Text::Core::CoreTextCompositionCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CompositionCompleted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CompositionCompleted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_FocusRemoved(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().FocusRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_FocusRemoved(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FocusRemoved(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall NotifyFocusEnter() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyFocusEnter();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyFocusLeave() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyFocusLeave();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyTextChanged(struct struct_Windows_UI_Text_Core_CoreTextRange modifiedRange, int32_t newLength, struct struct_Windows_UI_Text_Core_CoreTextRange newSelection) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyTextChanged(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextRange const*>(&modifiedRange), newLength, *reinterpret_cast<llm::OS::UI::Text::Core::CoreTextRange const*>(&newSelection));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifySelectionChanged(struct struct_Windows_UI_Text_Core_CoreTextRange selection) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifySelectionChanged(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextRange const*>(&selection));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall NotifyLayoutChanged() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyLayoutChanged();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextEditContext2> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextEditContext2>
    {
        int32_t __stdcall add_NotifyFocusLeaveCompleted(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().NotifyFocusLeaveCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextEditContext, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NotifyFocusLeaveCompleted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyFocusLeaveCompleted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs>
    {
        int32_t __stdcall get_Range(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Range());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TextColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>>(this->shim().TextColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnderlineColor(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::ViewManagement::UIElementType>>(this->shim().UnderlineColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UnderlineType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::UI::Text::UnderlineType>>(this->shim().UnderlineType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextFormatUpdatingReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextFormatUpdatingResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Result(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextFormatUpdatingResult const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextLayoutBounds> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextLayoutBounds>
    {
        int32_t __stdcall get_TextBounds(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().TextBounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TextBounds(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TextBounds(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ControlBounds(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().ControlBounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ControlBounds(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ControlBounds(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextLayoutRequest> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextLayoutRequest>
    {
        int32_t __stdcall get_Range(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Range());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LayoutBounds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextLayoutBounds>(this->shim().LayoutBounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextLayoutRequest2> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextLayoutRequest2>
    {
        int32_t __stdcall get_LayoutBoundsVisualPixels(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextLayoutBounds>(this->shim().LayoutBoundsVisualPixels());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextLayoutRequestedEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextLayoutRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextLayoutRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextSelectionRequest> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextSelectionRequest>
    {
        int32_t __stdcall get_Selection(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Selection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Selection(struct struct_Windows_UI_Text_Core_CoreTextRange value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Selection(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextRange const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextSelectionRequestedEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextSelectionRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextSelectionRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs>
    {
        int32_t __stdcall get_Selection(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Selection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextSelectionUpdatingResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Result(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextSelectionUpdatingResult const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextServicesManager> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextServicesManager>
    {
        int32_t __stdcall get_InputLanguage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::Language>(this->shim().InputLanguage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_InputLanguageChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().InputLanguageChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Text::Core::CoreTextServicesManager, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_InputLanguageChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputLanguageChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall CreateEditContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextEditContext>(this->shim().CreateEditContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextServicesManagerStatics> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextServicesManagerStatics>
    {
        int32_t __stdcall GetForCurrentView(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextServicesManager>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextServicesStatics> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextServicesStatics>
    {
        int32_t __stdcall get_HiddenCharacter(char16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<char16_t>(this->shim().HiddenCharacter());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextTextRequest> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextTextRequest>
    {
        int32_t __stdcall get_Range(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Range());
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
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextTextRequestedEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextTextRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextTextRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs> : produce_base<D, llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs>
    {
        int32_t __stdcall get_Range(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().Range());
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
        int32_t __stdcall get_NewSelection(struct struct_Windows_UI_Text_Core_CoreTextRange* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Text::Core::CoreTextRange>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextRange>(this->shim().NewSelection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InputLanguage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Globalization::Language>(this->shim().InputLanguage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Text::Core::CoreTextTextUpdatingResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Result(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Result(*reinterpret_cast<llm::OS::UI::Text::Core::CoreTextTextUpdatingResult const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Text::Core
{
    inline auto CoreTextServicesConstants::HiddenCharacter()
    {
        return impl::call_factory_cast<char16_t(*)(ICoreTextServicesStatics const&), CoreTextServicesConstants, ICoreTextServicesStatics>([](ICoreTextServicesStatics const& f) { return f.HiddenCharacter(); });
    }
    inline auto CoreTextServicesManager::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::Text::Core::CoreTextServicesManager(*)(ICoreTextServicesManagerStatics const&), CoreTextServicesManager, ICoreTextServicesManagerStatics>([](ICoreTextServicesManagerStatics const& f) { return f.GetForCurrentView(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextCompositionSegment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextEditContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextEditContext2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextLayoutBounds> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextLayoutRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextLayoutRequest2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextLayoutRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextSelectionRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextSelectionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextServicesManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextServicesManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextServicesStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextTextRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextTextRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextCompositionCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextCompositionSegment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextCompositionStartedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextEditContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextFormatUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextLayoutBounds> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextLayoutRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextLayoutRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextSelectionRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextSelectionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextSelectionUpdatingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextServicesConstants> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextServicesManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextTextRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextTextRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Text::Core::CoreTextTextUpdatingEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
