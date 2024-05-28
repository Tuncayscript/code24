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
#ifndef LLM_OS_UI_Core_H
#define LLM_OS_UI_Core_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Composition.2.h"
#include "llm/impl/Windows.UI.Input.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.UI.Core.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreAcceleratorKeyEventType) consume_Windows_UI_Core_IAcceleratorKeyEventArgs<D>::EventType() const
    {
        llm::OS::UI::Core::CoreAcceleratorKeyEventType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IAcceleratorKeyEventArgs)->get_EventType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::VirtualKey) consume_Windows_UI_Core_IAcceleratorKeyEventArgs<D>::VirtualKey() const
    {
        llm::OS::System::VirtualKey value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IAcceleratorKeyEventArgs)->get_VirtualKey(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CorePhysicalKeyStatus) consume_Windows_UI_Core_IAcceleratorKeyEventArgs<D>::KeyStatus() const
    {
        llm::OS::UI::Core::CorePhysicalKeyStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IAcceleratorKeyEventArgs)->get_KeyStatus(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Core_IAcceleratorKeyEventArgs2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IAcceleratorKeyEventArgs2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Core_IAutomationProviderRequestedEventArgs<D>::AutomationProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IAutomationProviderRequestedEventArgs)->get_AutomationProvider(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_IAutomationProviderRequestedEventArgs<D>::AutomationProvider(llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IAutomationProviderRequestedEventArgs)->put_AutomationProvider(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_IBackRequestedEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IBackRequestedEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_IBackRequestedEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IBackRequestedEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Core_ICharacterReceivedEventArgs<D>::KeyCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICharacterReceivedEventArgs)->get_KeyCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CorePhysicalKeyStatus) consume_Windows_UI_Core_ICharacterReceivedEventArgs<D>::KeyStatus() const
    {
        llm::OS::UI::Core::CorePhysicalKeyStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICharacterReceivedEventArgs)->get_KeyStatus(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_IClosestInteractiveBoundsRequestedEventArgs<D>::PointerPosition() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs)->get_PointerPosition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Core_IClosestInteractiveBoundsRequestedEventArgs<D>::SearchBounds() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs)->get_SearchBounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Core_IClosestInteractiveBoundsRequestedEventArgs<D>::ClosestInteractiveBounds() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs)->get_ClosestInteractiveBounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_IClosestInteractiveBoundsRequestedEventArgs<D>::ClosestInteractiveBounds(llm::OS::Foundation::Rect const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs)->put_ClosestInteractiveBounds(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreDispatcher, llm::OS::UI::Core::AcceleratorKeyEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreAcceleratorKeys)->add_AcceleratorKeyActivated(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated_revoker consume_Windows_UI_Core_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreDispatcher, llm::OS::UI::Core::AcceleratorKeyEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AcceleratorKeyActivated_revoker>(this, AcceleratorKeyActivated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreAcceleratorKeys<D>::AcceleratorKeyActivated(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreAcceleratorKeys)->remove_AcceleratorKeyActivated(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreComponentInputSource, llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreClosestInteractiveBoundsRequested)->add_ClosestInteractiveBoundsRequested(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested_revoker consume_Windows_UI_Core_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreComponentInputSource, llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ClosestInteractiveBoundsRequested_revoker>(this, ClosestInteractiveBoundsRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreClosestInteractiveBoundsRequested<D>::ClosestInteractiveBoundsRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreClosestInteractiveBoundsRequested)->remove_ClosestInteractiveBoundsRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreComponentFocusable<D>::HasFocus() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreComponentFocusable)->get_HasFocus(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreComponentFocusable<D>::GotFocus(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CoreWindowEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreComponentFocusable)->add_GotFocus(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreComponentFocusable<D>::GotFocus_revoker consume_Windows_UI_Core_ICoreComponentFocusable<D>::GotFocus(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CoreWindowEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, GotFocus_revoker>(this, GotFocus(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreComponentFocusable<D>::GotFocus(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreComponentFocusable)->remove_GotFocus(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreComponentFocusable<D>::LostFocus(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CoreWindowEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreComponentFocusable)->add_LostFocus(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreComponentFocusable<D>::LostFocus_revoker consume_Windows_UI_Core_ICoreComponentFocusable<D>::LostFocus(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CoreWindowEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, LostFocus_revoker>(this, LostFocus(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreComponentFocusable<D>::LostFocus(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreComponentFocusable)->remove_LostFocus(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Core_ICoreCursor<D>::Id() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreCursor)->get_Id(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreCursorType) consume_Windows_UI_Core_ICoreCursor<D>::Type() const
    {
        llm::OS::UI::Core::CoreCursorType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreCursor)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreCursor) consume_Windows_UI_Core_ICoreCursorFactory<D>::CreateCursor(llm::OS::UI::Core::CoreCursorType const& type, uint32_t id) const
    {
        void* cursor{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreCursorFactory)->CreateCursor(static_cast<int32_t>(type), id, &cursor));
        return llm::OS::UI::Core::CoreCursor{ cursor, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreDispatcher<D>::HasThreadAccess() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcher)->get_HasThreadAccess(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreDispatcher<D>::ProcessEvents(llm::OS::UI::Core::CoreProcessEventsOption const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcher)->ProcessEvents(static_cast<int32_t>(options)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_Core_ICoreDispatcher<D>::RunAsync(llm::OS::UI::Core::CoreDispatcherPriority const& priority, llm::OS::UI::Core::DispatchedHandler const& agileCallback) const
    {
        void* asyncAction{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcher)->RunAsync(static_cast<int32_t>(priority), *(void**)(&agileCallback), &asyncAction));
        return llm::OS::Foundation::IAsyncAction{ asyncAction, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_Core_ICoreDispatcher<D>::RunIdleAsync(llm::OS::UI::Core::IdleDispatchedHandler const& agileCallback) const
    {
        void* asyncAction{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcher)->RunIdleAsync(*(void**)(&agileCallback), &asyncAction));
        return llm::OS::Foundation::IAsyncAction{ asyncAction, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Core_ICoreDispatcher2<D>::TryRunAsync(llm::OS::UI::Core::CoreDispatcherPriority const& priority, llm::OS::UI::Core::DispatchedHandler const& agileCallback) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcher2)->TryRunAsync(static_cast<int32_t>(priority), *(void**)(&agileCallback), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Core_ICoreDispatcher2<D>::TryRunIdleAsync(llm::OS::UI::Core::IdleDispatchedHandler const& agileCallback) const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcher2)->TryRunIdleAsync(*(void**)(&agileCallback), &asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcherPriority) consume_Windows_UI_Core_ICoreDispatcherWithTaskPriority<D>::CurrentPriority() const
    {
        llm::OS::UI::Core::CoreDispatcherPriority value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcherWithTaskPriority)->get_CurrentPriority(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreDispatcherWithTaskPriority<D>::CurrentPriority(llm::OS::UI::Core::CoreDispatcherPriority const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcherWithTaskPriority)->put_CurrentPriority(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreDispatcherWithTaskPriority<D>::ShouldYield() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcherWithTaskPriority)->ShouldYield(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreDispatcherWithTaskPriority<D>::ShouldYield(llm::OS::UI::Core::CoreDispatcherPriority const& priority) const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcherWithTaskPriority)->ShouldYieldToPriority(static_cast<int32_t>(priority), &value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreDispatcherWithTaskPriority<D>::StopProcessEvents() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreDispatcherWithTaskPriority)->StopProcessEvents());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::IsTransparentForUncontrolledInput() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->get_IsTransparentForUncontrolledInput(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::IsTransparentForUncontrolledInput(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->put_IsTransparentForUncontrolledInput(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::IsPalmRejectionEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->get_IsPalmRejectionEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::IsPalmRejectionEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->put_IsPalmRejectionEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreIndependentInputSource) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::Source() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->get_Source(&value));
        return llm::OS::UI::Core::CoreIndependentInputSource{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::SetControlledInput(llm::OS::UI::Core::CoreInputDeviceTypes const& inputTypes) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->SetControlledInput(static_cast<uint32_t>(inputTypes)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreIndependentInputSourceController<D>::SetControlledInput(llm::OS::UI::Core::CoreInputDeviceTypes const& inputTypes, llm::OS::UI::Core::CoreIndependentInputFilters const& required, llm::OS::UI::Core::CoreIndependentInputFilters const& excluded) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceController)->SetControlledInputWithFilters(static_cast<uint32_t>(inputTypes), static_cast<uint32_t>(required), static_cast<uint32_t>(excluded)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreIndependentInputSourceController) consume_Windows_UI_Core_ICoreIndependentInputSourceControllerStatics<D>::CreateForVisual(llm::OS::UI::Composition::Visual const& visual) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceControllerStatics)->CreateForVisual(*(void**)(&visual), &result));
        return llm::OS::UI::Core::CoreIndependentInputSourceController{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreIndependentInputSourceController) consume_Windows_UI_Core_ICoreIndependentInputSourceControllerStatics<D>::CreateForIVisualElement(llm::OS::UI::Composition::IVisualElement const& visualElement) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreIndependentInputSourceControllerStatics)->CreateForIVisualElement(*(void**)(&visualElement), &result));
        return llm::OS::UI::Core::CoreIndependentInputSourceController{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcher) consume_Windows_UI_Core_ICoreInputSourceBase<D>::Dispatcher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreInputSourceBase)->get_Dispatcher(&value));
        return llm::OS::UI::Core::CoreDispatcher{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreInputSourceBase<D>::IsInputEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreInputSourceBase)->get_IsInputEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreInputSourceBase<D>::IsInputEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreInputSourceBase)->put_IsInputEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreInputSourceBase<D>::InputEnabled(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::InputEnabledEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreInputSourceBase)->add_InputEnabled(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreInputSourceBase<D>::InputEnabled_revoker consume_Windows_UI_Core_ICoreInputSourceBase<D>::InputEnabled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::InputEnabledEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, InputEnabled_revoker>(this, InputEnabled(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreInputSourceBase<D>::InputEnabled(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreInputSourceBase)->remove_InputEnabled(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreVirtualKeyStates) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::GetCurrentKeyState(llm::OS::System::VirtualKey const& virtualKey) const
    {
        llm::OS::UI::Core::CoreVirtualKeyStates KeyState{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->GetCurrentKeyState(static_cast<int32_t>(virtualKey), reinterpret_cast<uint32_t*>(&KeyState)));
        return KeyState;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::CharacterReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CharacterReceivedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->add_CharacterReceived(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::CharacterReceived_revoker consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::CharacterReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CharacterReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CharacterReceived_revoker>(this, CharacterReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::CharacterReceived(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->remove_CharacterReceived(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyDown(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->add_KeyDown(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyDown_revoker consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyDown(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, KeyDown_revoker>(this, KeyDown(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyDown(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->remove_KeyDown(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyUp(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->add_KeyUp(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyUp_revoker consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyUp(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, KeyUp_revoker>(this, KeyUp(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreKeyboardInputSource<D>::KeyUp(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource)->remove_KeyUp(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Core_ICoreKeyboardInputSource2<D>::GetCurrentKeyEventDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreKeyboardInputSource2)->GetCurrentKeyEventDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::ReleasePointerCapture() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->ReleasePointerCapture());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::SetPointerCapture() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->SetPointerCapture());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICorePointerInputSource<D>::HasCapture() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->get_HasCapture(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerPosition() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->get_PointerPosition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreCursor) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerCursor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->get_PointerCursor(&value));
        return llm::OS::UI::Core::CoreCursor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerCursor(llm::OS::UI::Core::CoreCursor const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->put_PointerCursor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerCaptureLost(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerCaptureLost(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerCaptureLost_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerCaptureLost(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerCaptureLost_revoker>(this, PointerCaptureLost(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerCaptureLost(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerCaptureLost(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerEntered(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerEntered(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerEntered_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerEntered(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerEntered_revoker>(this, PointerEntered(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerEntered(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerEntered(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerExited(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerExited(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerExited_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerExited(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerExited_revoker>(this, PointerExited(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerExited(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerExited(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerMoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerMoved(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerMoved_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerMoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerMoved_revoker>(this, PointerMoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerMoved(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerMoved(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerPressed(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerPressed(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerPressed_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerPressed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerPressed_revoker>(this, PointerPressed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerPressed(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerPressed(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerReleased(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerReleased(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerReleased_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerReleased(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerReleased_revoker>(this, PointerReleased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerReleased(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerReleased(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerWheelChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->add_PointerWheelChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerWheelChanged_revoker consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerWheelChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerWheelChanged_revoker>(this, PointerWheelChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerInputSource<D>::PointerWheelChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource)->remove_PointerWheelChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_UI_Core_ICorePointerInputSource2<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerInputSource2)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedAway(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerRedirector)->add_PointerRoutedAway(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedAway_revoker consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedAway(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerRoutedAway_revoker>(this, PointerRoutedAway(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedAway(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerRedirector)->remove_PointerRoutedAway(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedTo(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerRedirector)->add_PointerRoutedTo(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedTo_revoker consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedTo(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerRoutedTo_revoker>(this, PointerRoutedTo(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedTo(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerRedirector)->remove_PointerRoutedTo(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedReleased(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerRedirector)->add_PointerRoutedReleased(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedReleased_revoker consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedReleased(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerRoutedReleased_revoker>(this, PointerRoutedReleased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICorePointerRedirector<D>::PointerRoutedReleased(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICorePointerRedirector)->remove_PointerRoutedReleased(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreTouchHitTesting<D>::TouchHitTesting(llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::TouchHitTestingEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreTouchHitTesting)->add_TouchHitTesting(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreTouchHitTesting<D>::TouchHitTesting_revoker consume_Windows_UI_Core_ICoreTouchHitTesting<D>::TouchHitTesting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::TouchHitTestingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TouchHitTesting_revoker>(this, TouchHitTesting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreTouchHitTesting<D>::TouchHitTesting(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreTouchHitTesting)->remove_TouchHitTesting(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Core_ICoreWindow<D>::AutomationHostProvider() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_AutomationHostProvider(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Core_ICoreWindow<D>::Bounds() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_Bounds(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) consume_Windows_UI_Core_ICoreWindow<D>::CustomProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_CustomProperties(&value));
        return llm::OS::Foundation::Collections::IPropertySet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreDispatcher) consume_Windows_UI_Core_ICoreWindow<D>::Dispatcher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_Dispatcher(&value));
        return llm::OS::UI::Core::CoreDispatcher{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowFlowDirection) consume_Windows_UI_Core_ICoreWindow<D>::FlowDirection() const
    {
        llm::OS::UI::Core::CoreWindowFlowDirection value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_FlowDirection(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::FlowDirection(llm::OS::UI::Core::CoreWindowFlowDirection const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->put_FlowDirection(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreWindow<D>::IsInputEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_IsInputEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::IsInputEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->put_IsInputEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreCursor) consume_Windows_UI_Core_ICoreWindow<D>::PointerCursor() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_PointerCursor(&value));
        return llm::OS::UI::Core::CoreCursor{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerCursor(llm::OS::UI::Core::CoreCursor const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->put_PointerCursor(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_ICoreWindow<D>::PointerPosition() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_PointerPosition(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreWindow<D>::Visible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->get_Visible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::Activate() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->Activate());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::Close() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->Close());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreVirtualKeyStates) consume_Windows_UI_Core_ICoreWindow<D>::GetAsyncKeyState(llm::OS::System::VirtualKey const& virtualKey) const
    {
        llm::OS::UI::Core::CoreVirtualKeyStates KeyState{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->GetAsyncKeyState(static_cast<int32_t>(virtualKey), reinterpret_cast<uint32_t*>(&KeyState)));
        return KeyState;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreVirtualKeyStates) consume_Windows_UI_Core_ICoreWindow<D>::GetKeyState(llm::OS::System::VirtualKey const& virtualKey) const
    {
        llm::OS::UI::Core::CoreVirtualKeyStates KeyState{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->GetKeyState(static_cast<int32_t>(virtualKey), reinterpret_cast<uint32_t*>(&KeyState)));
        return KeyState;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::ReleasePointerCapture() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->ReleasePointerCapture());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::SetPointerCapture() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->SetPointerCapture());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::Activated(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::WindowActivatedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_Activated(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::Activated_revoker consume_Windows_UI_Core_ICoreWindow<D>::Activated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::WindowActivatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Activated_revoker>(this, Activated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::Activated(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_Activated(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::AutomationProviderRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::AutomationProviderRequestedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_AutomationProviderRequested(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::AutomationProviderRequested_revoker consume_Windows_UI_Core_ICoreWindow<D>::AutomationProviderRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::AutomationProviderRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AutomationProviderRequested_revoker>(this, AutomationProviderRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::AutomationProviderRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_AutomationProviderRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::CharacterReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CharacterReceivedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_CharacterReceived(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::CharacterReceived_revoker consume_Windows_UI_Core_ICoreWindow<D>::CharacterReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CharacterReceivedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CharacterReceived_revoker>(this, CharacterReceived(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::CharacterReceived(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_CharacterReceived(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_Closed(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::Closed_revoker consume_Windows_UI_Core_ICoreWindow<D>::Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Closed_revoker>(this, Closed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::Closed(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_Closed(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::InputEnabled(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::InputEnabledEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_InputEnabled(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::InputEnabled_revoker consume_Windows_UI_Core_ICoreWindow<D>::InputEnabled(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::InputEnabledEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, InputEnabled_revoker>(this, InputEnabled(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::InputEnabled(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_InputEnabled(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::KeyDown(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_KeyDown(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::KeyDown_revoker consume_Windows_UI_Core_ICoreWindow<D>::KeyDown(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, KeyDown_revoker>(this, KeyDown(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::KeyDown(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_KeyDown(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::KeyUp(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_KeyUp(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::KeyUp_revoker consume_Windows_UI_Core_ICoreWindow<D>::KeyUp(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::KeyEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, KeyUp_revoker>(this, KeyUp(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::KeyUp(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_KeyUp(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerCaptureLost(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerCaptureLost(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerCaptureLost_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerCaptureLost(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerCaptureLost_revoker>(this, PointerCaptureLost(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerCaptureLost(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerCaptureLost(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerEntered(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerEntered(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerEntered_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerEntered(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerEntered_revoker>(this, PointerEntered(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerEntered(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerEntered(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerExited(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerExited(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerExited_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerExited(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerExited_revoker>(this, PointerExited(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerExited(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerExited(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerMoved(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerMoved(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerMoved_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerMoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerMoved_revoker>(this, PointerMoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerMoved(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerMoved(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerPressed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerPressed(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerPressed_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerPressed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerPressed_revoker>(this, PointerPressed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerPressed(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerPressed(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerReleased(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerReleased(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerReleased_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerReleased(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerReleased_revoker>(this, PointerReleased(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerReleased(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerReleased(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::TouchHitTesting(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::TouchHitTestingEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_TouchHitTesting(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::TouchHitTesting_revoker consume_Windows_UI_Core_ICoreWindow<D>::TouchHitTesting(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::TouchHitTestingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TouchHitTesting_revoker>(this, TouchHitTesting(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::TouchHitTesting(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_TouchHitTesting(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::PointerWheelChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_PointerWheelChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::PointerWheelChanged_revoker consume_Windows_UI_Core_ICoreWindow<D>::PointerWheelChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PointerWheelChanged_revoker>(this, PointerWheelChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::PointerWheelChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_PointerWheelChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::SizeChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::WindowSizeChangedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_SizeChanged(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::SizeChanged_revoker consume_Windows_UI_Core_ICoreWindow<D>::SizeChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::WindowSizeChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SizeChanged_revoker>(this, SizeChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::SizeChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_SizeChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow<D>::VisibilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::VisibilityChangedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->add_VisibilityChanged(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow<D>::VisibilityChanged_revoker consume_Windows_UI_Core_ICoreWindow<D>::VisibilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::VisibilityChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, VisibilityChanged_revoker>(this, VisibilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow<D>::VisibilityChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow)->remove_VisibilityChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow2<D>::PointerPosition(llm::OS::Foundation::Point const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow2)->put_PointerPosition(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow3<D>::ClosestInteractiveBoundsRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow3)->add_ClosestInteractiveBoundsRequested(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow3<D>::ClosestInteractiveBoundsRequested_revoker consume_Windows_UI_Core_ICoreWindow3<D>::ClosestInteractiveBoundsRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ClosestInteractiveBoundsRequested_revoker>(this, ClosestInteractiveBoundsRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow3<D>::ClosestInteractiveBoundsRequested(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow3)->remove_ClosestInteractiveBoundsRequested(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Core_ICoreWindow3<D>::GetCurrentKeyEventDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow3)->GetCurrentKeyEventDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow4<D>::ResizeStarted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow4)->add_ResizeStarted(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow4<D>::ResizeStarted_revoker consume_Windows_UI_Core_ICoreWindow4<D>::ResizeStarted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ResizeStarted_revoker>(this, ResizeStarted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow4<D>::ResizeStarted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow4)->remove_ResizeStarted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindow4<D>::ResizeCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token pCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow4)->add_ResizeCompleted(*(void**)(&handler), put_abi(pCookie)));
        return pCookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindow4<D>::ResizeCompleted_revoker consume_Windows_UI_Core_ICoreWindow4<D>::ResizeCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ResizeCompleted_revoker>(this, ResizeCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindow4<D>::ResizeCompleted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow4)->remove_ResizeCompleted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::DispatcherQueue) consume_Windows_UI_Core_ICoreWindow5<D>::DispatcherQueue() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow5)->get_DispatcherQueue(&value));
        return llm::OS::System::DispatcherQueue{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowActivationMode) consume_Windows_UI_Core_ICoreWindow5<D>::ActivationMode() const
    {
        llm::OS::UI::Core::CoreWindowActivationMode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindow5)->get_ActivationMode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindowDialog<D>::Showing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->add_Showing(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindowDialog<D>::Showing_revoker consume_Windows_UI_Core_ICoreWindowDialog<D>::Showing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Showing_revoker>(this, Showing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowDialog<D>::Showing(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->remove_Showing(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Core_ICoreWindowDialog<D>::MaxSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_MaxSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Core_ICoreWindowDialog<D>::MinSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_MinSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Core_ICoreWindowDialog<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowDialog<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Core_ICoreWindowDialog<D>::IsInteractionDelayed() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_IsInteractionDelayed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowDialog<D>::IsInteractionDelayed(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->put_IsInteractionDelayed(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Popups::IUICommand>) consume_Windows_UI_Core_ICoreWindowDialog<D>::Commands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_Commands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Popups::IUICommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Core_ICoreWindowDialog<D>::DefaultCommandIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_DefaultCommandIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowDialog<D>::DefaultCommandIndex(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->put_DefaultCommandIndex(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Core_ICoreWindowDialog<D>::CancelCommandIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_CancelCommandIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowDialog<D>::CancelCommandIndex(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->put_CancelCommandIndex(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Popups::UICommandInvokedHandler) consume_Windows_UI_Core_ICoreWindowDialog<D>::BackButtonCommand() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->get_BackButtonCommand(&value));
        return llm::OS::UI::Popups::UICommandInvokedHandler{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowDialog<D>::BackButtonCommand(llm::OS::UI::Popups::UICommandInvokedHandler const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->put_BackButtonCommand(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Popups::IUICommand>) consume_Windows_UI_Core_ICoreWindowDialog<D>::ShowAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialog)->ShowAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Popups::IUICommand>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowDialog) consume_Windows_UI_Core_ICoreWindowDialogFactory<D>::CreateWithTitle(param::hstring const& title) const
    {
        void* coreWindowDialog{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowDialogFactory)->CreateWithTitle(*(void**)(&title), &coreWindowDialog));
        return llm::OS::UI::Core::CoreWindowDialog{ coreWindowDialog, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreWindowEventArgs<D>::Handled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowEventArgs)->get_Handled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowEventArgs<D>::Handled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowEventArgs)->put_Handled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ICoreWindowFlyout<D>::Showing(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->add_Showing(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_UI_Core_ICoreWindowFlyout<D>::Showing_revoker consume_Windows_UI_Core_ICoreWindowFlyout<D>::Showing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Showing_revoker>(this, Showing(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowFlyout<D>::Showing(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->remove_Showing(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Core_ICoreWindowFlyout<D>::MaxSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_MaxSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Core_ICoreWindowFlyout<D>::MinSize() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_MinSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Core_ICoreWindowFlyout<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowFlyout<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Core_ICoreWindowFlyout<D>::IsInteractionDelayed() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_IsInteractionDelayed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowFlyout<D>::IsInteractionDelayed(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->put_IsInteractionDelayed(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Popups::IUICommand>) consume_Windows_UI_Core_ICoreWindowFlyout<D>::Commands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_Commands(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Popups::IUICommand>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_UI_Core_ICoreWindowFlyout<D>::DefaultCommandIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_DefaultCommandIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowFlyout<D>::DefaultCommandIndex(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->put_DefaultCommandIndex(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Popups::UICommandInvokedHandler) consume_Windows_UI_Core_ICoreWindowFlyout<D>::BackButtonCommand() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->get_BackButtonCommand(&value));
        return llm::OS::UI::Popups::UICommandInvokedHandler{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowFlyout<D>::BackButtonCommand(llm::OS::UI::Popups::UICommandInvokedHandler const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->put_BackButtonCommand(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Popups::IUICommand>) consume_Windows_UI_Core_ICoreWindowFlyout<D>::ShowAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyout)->ShowAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Popups::IUICommand>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowFlyout) consume_Windows_UI_Core_ICoreWindowFlyoutFactory<D>::Create(llm::OS::Foundation::Point const& position) const
    {
        void* coreWindowFlyout{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyoutFactory)->Create(impl::bind_in(position), &coreWindowFlyout));
        return llm::OS::UI::Core::CoreWindowFlyout{ coreWindowFlyout, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowFlyout) consume_Windows_UI_Core_ICoreWindowFlyoutFactory<D>::CreateWithTitle(llm::OS::Foundation::Point const& position, param::hstring const& title) const
    {
        void* coreWindowFlyout{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowFlyoutFactory)->CreateWithTitle(impl::bind_in(position), *(void**)(&title), &coreWindowFlyout));
        return llm::OS::UI::Core::CoreWindowFlyout{ coreWindowFlyout, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowPopupShowingEventArgs<D>::SetDesiredSize(llm::OS::Foundation::Size const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowPopupShowingEventArgs)->SetDesiredSize(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowResizeManager<D>::NotifyLayoutCompleted() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowResizeManager)->NotifyLayoutCompleted());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ICoreWindowResizeManagerLayoutCapability<D>::ShouldWaitForLayoutCompletion(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowResizeManagerLayoutCapability)->put_ShouldWaitForLayoutCompletion(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_ICoreWindowResizeManagerLayoutCapability<D>::ShouldWaitForLayoutCompletion() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowResizeManagerLayoutCapability)->get_ShouldWaitForLayoutCompletion(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowResizeManager) consume_Windows_UI_Core_ICoreWindowResizeManagerStatics<D>::GetForCurrentView() const
    {
        void* CoreWindowResizeManager{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowResizeManagerStatics)->GetForCurrentView(&CoreWindowResizeManager));
        return llm::OS::UI::Core::CoreWindowResizeManager{ CoreWindowResizeManager, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindow) consume_Windows_UI_Core_ICoreWindowStatic<D>::GetForCurrentThread() const
    {
        void* ppWindow{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowStatic)->GetForCurrentThread(&ppWindow));
        return llm::OS::UI::Core::CoreWindow{ ppWindow, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::UIContext) consume_Windows_UI_Core_ICoreWindowWithContext<D>::UIContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ICoreWindowWithContext)->get_UIContext(&value));
        return llm::OS::UI::UIContext{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_IIdleDispatchedHandlerArgs<D>::IsDispatcherIdle() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IIdleDispatchedHandlerArgs)->get_IsDispatcherIdle(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_IInitializeWithCoreWindow<D>::Initialize(llm::OS::UI::Core::CoreWindow const& window) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IInitializeWithCoreWindow)->Initialize(*(void**)(&window)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_IInputEnabledEventArgs<D>::InputEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IInputEnabledEventArgs)->get_InputEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::VirtualKey) consume_Windows_UI_Core_IKeyEventArgs<D>::VirtualKey() const
    {
        llm::OS::System::VirtualKey value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IKeyEventArgs)->get_VirtualKey(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CorePhysicalKeyStatus) consume_Windows_UI_Core_IKeyEventArgs<D>::KeyStatus() const
    {
        llm::OS::UI::Core::CorePhysicalKeyStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IKeyEventArgs)->get_KeyStatus(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Core_IKeyEventArgs2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IKeyEventArgs2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Input::PointerPoint) consume_Windows_UI_Core_IPointerEventArgs<D>::CurrentPoint() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IPointerEventArgs)->get_CurrentPoint(&value));
        return llm::OS::UI::Input::PointerPoint{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::VirtualKeyModifiers) consume_Windows_UI_Core_IPointerEventArgs<D>::KeyModifiers() const
    {
        llm::OS::System::VirtualKeyModifiers value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IPointerEventArgs)->get_KeyModifiers(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Input::PointerPoint>) consume_Windows_UI_Core_IPointerEventArgs<D>::GetIntermediatePoints() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IPointerEventArgs)->GetIntermediatePoints(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Input::PointerPoint>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Core_ISystemNavigationManager<D>::BackRequested(llm::OS::Foundation::EventHandler<llm::OS::UI::Core::BackRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ISystemNavigationManager)->add_BackRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Core_ISystemNavigationManager<D>::BackRequested_revoker consume_Windows_UI_Core_ISystemNavigationManager<D>::BackRequested(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::Core::BackRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, BackRequested_revoker>(this, BackRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ISystemNavigationManager<D>::BackRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Core::ISystemNavigationManager)->remove_BackRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::AppViewBackButtonVisibility) consume_Windows_UI_Core_ISystemNavigationManager2<D>::AppViewBackButtonVisibility() const
    {
        llm::OS::UI::Core::AppViewBackButtonVisibility value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ISystemNavigationManager2)->get_AppViewBackButtonVisibility(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ISystemNavigationManager2<D>::AppViewBackButtonVisibility(llm::OS::UI::Core::AppViewBackButtonVisibility const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ISystemNavigationManager2)->put_AppViewBackButtonVisibility(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::SystemNavigationManager) consume_Windows_UI_Core_ISystemNavigationManagerStatics<D>::GetForCurrentView() const
    {
        void* loader{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ISystemNavigationManagerStatics)->GetForCurrentView(&loader));
        return llm::OS::UI::Core::SystemNavigationManager{ loader, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreProximityEvaluation) consume_Windows_UI_Core_ITouchHitTestingEventArgs<D>::ProximityEvaluation() const
    {
        llm::OS::UI::Core::CoreProximityEvaluation value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ITouchHitTestingEventArgs)->get_ProximityEvaluation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Core_ITouchHitTestingEventArgs<D>::ProximityEvaluation(llm::OS::UI::Core::CoreProximityEvaluation const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ITouchHitTestingEventArgs)->put_ProximityEvaluation(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Core_ITouchHitTestingEventArgs<D>::Point() const
    {
        llm::OS::Foundation::Point value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ITouchHitTestingEventArgs)->get_Point(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Core_ITouchHitTestingEventArgs<D>::BoundingBox() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ITouchHitTestingEventArgs)->get_BoundingBox(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreProximityEvaluation) consume_Windows_UI_Core_ITouchHitTestingEventArgs<D>::EvaluateProximity(llm::OS::Foundation::Rect const& controlBoundingBox) const
    {
        llm::OS::UI::Core::CoreProximityEvaluation proximityEvaluation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ITouchHitTestingEventArgs)->EvaluateProximityToRect(impl::bind_in(controlBoundingBox), put_abi(proximityEvaluation)));
        return proximityEvaluation;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreProximityEvaluation) consume_Windows_UI_Core_ITouchHitTestingEventArgs<D>::EvaluateProximity(array_view<llm::OS::Foundation::Point const> controlVertices) const
    {
        llm::OS::UI::Core::CoreProximityEvaluation proximityEvaluation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::ITouchHitTestingEventArgs)->EvaluateProximityToPolygon(controlVertices.size(), get_abi(controlVertices), put_abi(proximityEvaluation)));
        return proximityEvaluation;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Core_IVisibilityChangedEventArgs<D>::Visible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IVisibilityChangedEventArgs)->get_Visible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Core::CoreWindowActivationState) consume_Windows_UI_Core_IWindowActivatedEventArgs<D>::WindowActivationState() const
    {
        llm::OS::UI::Core::CoreWindowActivationState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IWindowActivatedEventArgs)->get_WindowActivationState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Size) consume_Windows_UI_Core_IWindowSizeChangedEventArgs<D>::Size() const
    {
        llm::OS::Foundation::Size value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Core::IWindowSizeChangedEventArgs)->get_Size(put_abi(value)));
        return value;
    }
    template <typename H> struct delegate<llm::OS::UI::Core::DispatchedHandler, H> final : implements_delegate<llm::OS::UI::Core::DispatchedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Core::DispatchedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke() noexcept final try
        {
            (*this)();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::Core::IdleDispatchedHandler, H> final : implements_delegate<llm::OS::UI::Core::IdleDispatchedHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::Core::IdleDispatchedHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::UI::Core::IdleDispatchedHandlerArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IAcceleratorKeyEventArgs> : produce_base<D, llm::OS::UI::Core::IAcceleratorKeyEventArgs>
    {
        int32_t __stdcall get_EventType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreAcceleratorKeyEventType>(this->shim().EventType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VirtualKey(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::VirtualKey>(this->shim().VirtualKey());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyStatus(struct struct_Windows_UI_Core_CorePhysicalKeyStatus* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Core::CorePhysicalKeyStatus>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CorePhysicalKeyStatus>(this->shim().KeyStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IAcceleratorKeyEventArgs2> : produce_base<D, llm::OS::UI::Core::IAcceleratorKeyEventArgs2>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IAutomationProviderRequestedEventArgs> : produce_base<D, llm::OS::UI::Core::IAutomationProviderRequestedEventArgs>
    {
        int32_t __stdcall get_AutomationProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().AutomationProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AutomationProvider(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutomationProvider(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IBackRequestedEventArgs> : produce_base<D, llm::OS::UI::Core::IBackRequestedEventArgs>
    {
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
    struct produce<D, llm::OS::UI::Core::ICharacterReceivedEventArgs> : produce_base<D, llm::OS::UI::Core::ICharacterReceivedEventArgs>
    {
        int32_t __stdcall get_KeyCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().KeyCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyStatus(struct struct_Windows_UI_Core_CorePhysicalKeyStatus* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Core::CorePhysicalKeyStatus>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CorePhysicalKeyStatus>(this->shim().KeyStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs> : produce_base<D, llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs>
    {
        int32_t __stdcall get_PointerPosition(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().PointerPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SearchBounds(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().SearchBounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ClosestInteractiveBounds(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().ClosestInteractiveBounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ClosestInteractiveBounds(llm::OS::Foundation::Rect value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosestInteractiveBounds(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreAcceleratorKeys> : produce_base<D, llm::OS::UI::Core::ICoreAcceleratorKeys>
    {
        int32_t __stdcall add_AcceleratorKeyActivated(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().AcceleratorKeyActivated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreDispatcher, llm::OS::UI::Core::AcceleratorKeyEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AcceleratorKeyActivated(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceleratorKeyActivated(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreClosestInteractiveBoundsRequested> : produce_base<D, llm::OS::UI::Core::ICoreClosestInteractiveBoundsRequested>
    {
        int32_t __stdcall add_ClosestInteractiveBoundsRequested(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().ClosestInteractiveBoundsRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreComponentInputSource, llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ClosestInteractiveBoundsRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosestInteractiveBoundsRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreComponentFocusable> : produce_base<D, llm::OS::UI::Core::ICoreComponentFocusable>
    {
        int32_t __stdcall get_HasFocus(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasFocus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_GotFocus(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().GotFocus(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CoreWindowEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_GotFocus(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GotFocus(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_LostFocus(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().LostFocus(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CoreWindowEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LostFocus(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LostFocus(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreCursor> : produce_base<D, llm::OS::UI::Core::ICoreCursor>
    {
        int32_t __stdcall get_Id(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreCursorType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreCursorFactory> : produce_base<D, llm::OS::UI::Core::ICoreCursorFactory>
    {
        int32_t __stdcall CreateCursor(int32_t type, uint32_t id, void** cursor) noexcept final try
        {
            clear_abi(cursor);
            typename D::abi_guard guard(this->shim());
            *cursor = detach_from<llm::OS::UI::Core::CoreCursor>(this->shim().CreateCursor(*reinterpret_cast<llm::OS::UI::Core::CoreCursorType const*>(&type), id));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreDispatcher> : produce_base<D, llm::OS::UI::Core::ICoreDispatcher>
    {
        int32_t __stdcall get_HasThreadAccess(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasThreadAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProcessEvents(int32_t options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessEvents(*reinterpret_cast<llm::OS::UI::Core::CoreProcessEventsOption const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RunAsync(int32_t priority, void* agileCallback, void** asyncAction) noexcept final try
        {
            clear_abi(asyncAction);
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RunAsync(*reinterpret_cast<llm::OS::UI::Core::CoreDispatcherPriority const*>(&priority), *reinterpret_cast<llm::OS::UI::Core::DispatchedHandler const*>(&agileCallback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RunIdleAsync(void* agileCallback, void** asyncAction) noexcept final try
        {
            clear_abi(asyncAction);
            typename D::abi_guard guard(this->shim());
            *asyncAction = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RunIdleAsync(*reinterpret_cast<llm::OS::UI::Core::IdleDispatchedHandler const*>(&agileCallback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreDispatcher2> : produce_base<D, llm::OS::UI::Core::ICoreDispatcher2>
    {
        int32_t __stdcall TryRunAsync(int32_t priority, void* agileCallback, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryRunAsync(*reinterpret_cast<llm::OS::UI::Core::CoreDispatcherPriority const*>(&priority), *reinterpret_cast<llm::OS::UI::Core::DispatchedHandler const*>(&agileCallback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryRunIdleAsync(void* agileCallback, void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryRunIdleAsync(*reinterpret_cast<llm::OS::UI::Core::IdleDispatchedHandler const*>(&agileCallback)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreDispatcherWithTaskPriority> : produce_base<D, llm::OS::UI::Core::ICoreDispatcherWithTaskPriority>
    {
        int32_t __stdcall get_CurrentPriority(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreDispatcherPriority>(this->shim().CurrentPriority());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CurrentPriority(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentPriority(*reinterpret_cast<llm::OS::UI::Core::CoreDispatcherPriority const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShouldYield(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShouldYield());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShouldYieldToPriority(int32_t priority, bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShouldYield(*reinterpret_cast<llm::OS::UI::Core::CoreDispatcherPriority const*>(&priority)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopProcessEvents() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopProcessEvents();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreIndependentInputSourceController> : produce_base<D, llm::OS::UI::Core::ICoreIndependentInputSourceController>
    {
        int32_t __stdcall get_IsTransparentForUncontrolledInput(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTransparentForUncontrolledInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsTransparentForUncontrolledInput(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTransparentForUncontrolledInput(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPalmRejectionEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPalmRejectionEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsPalmRejectionEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsPalmRejectionEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Source(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreIndependentInputSource>(this->shim().Source());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetControlledInput(uint32_t inputTypes) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetControlledInput(*reinterpret_cast<llm::OS::UI::Core::CoreInputDeviceTypes const*>(&inputTypes));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetControlledInputWithFilters(uint32_t inputTypes, uint32_t required, uint32_t excluded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetControlledInput(*reinterpret_cast<llm::OS::UI::Core::CoreInputDeviceTypes const*>(&inputTypes), *reinterpret_cast<llm::OS::UI::Core::CoreIndependentInputFilters const*>(&required), *reinterpret_cast<llm::OS::UI::Core::CoreIndependentInputFilters const*>(&excluded));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreIndependentInputSourceControllerStatics> : produce_base<D, llm::OS::UI::Core::ICoreIndependentInputSourceControllerStatics>
    {
        int32_t __stdcall CreateForVisual(void* visual, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Core::CoreIndependentInputSourceController>(this->shim().CreateForVisual(*reinterpret_cast<llm::OS::UI::Composition::Visual const*>(&visual)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateForIVisualElement(void* visualElement, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Core::CoreIndependentInputSourceController>(this->shim().CreateForIVisualElement(*reinterpret_cast<llm::OS::UI::Composition::IVisualElement const*>(&visualElement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreInputSourceBase> : produce_base<D, llm::OS::UI::Core::ICoreInputSourceBase>
    {
        int32_t __stdcall get_Dispatcher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreDispatcher>(this->shim().Dispatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInputEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInputEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInputEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInputEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_InputEnabled(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().InputEnabled(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::InputEnabledEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_InputEnabled(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputEnabled(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreKeyboardInputSource> : produce_base<D, llm::OS::UI::Core::ICoreKeyboardInputSource>
    {
        int32_t __stdcall GetCurrentKeyState(int32_t virtualKey, uint32_t* KeyState) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *KeyState = detach_from<llm::OS::UI::Core::CoreVirtualKeyStates>(this->shim().GetCurrentKeyState(*reinterpret_cast<llm::OS::System::VirtualKey const*>(&virtualKey)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CharacterReceived(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().CharacterReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::CharacterReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CharacterReceived(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharacterReceived(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_KeyDown(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().KeyDown(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::KeyEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_KeyDown(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyDown(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_KeyUp(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().KeyUp(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::KeyEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_KeyUp(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyUp(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreKeyboardInputSource2> : produce_base<D, llm::OS::UI::Core::ICoreKeyboardInputSource2>
    {
        int32_t __stdcall GetCurrentKeyEventDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetCurrentKeyEventDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICorePointerInputSource> : produce_base<D, llm::OS::UI::Core::ICorePointerInputSource>
    {
        int32_t __stdcall ReleasePointerCapture() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePointerCapture();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPointerCapture() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPointerCapture();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasCapture(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasCapture());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PointerPosition(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().PointerPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
        int32_t __stdcall add_PointerCaptureLost(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerCaptureLost(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerCaptureLost(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCaptureLost(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerEntered(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerEntered(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerEntered(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntered(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerExited(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerExited(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerExited(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExited(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerMoved(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerMoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerMoved(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoved(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerPressed(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerPressed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerPressed(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressed(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerReleased(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerReleased(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerReleased(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleased(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerWheelChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerWheelChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerWheelChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerWheelChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICorePointerInputSource2> : produce_base<D, llm::OS::UI::Core::ICorePointerInputSource2>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICorePointerRedirector> : produce_base<D, llm::OS::UI::Core::ICorePointerRedirector>
    {
        int32_t __stdcall add_PointerRoutedAway(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerRoutedAway(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerRoutedAway(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerRoutedAway(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerRoutedTo(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerRoutedTo(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerRoutedTo(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerRoutedTo(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerRoutedReleased(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerRoutedReleased(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::ICorePointerRedirector, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerRoutedReleased(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerRoutedReleased(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreTouchHitTesting> : produce_base<D, llm::OS::UI::Core::ICoreTouchHitTesting>
    {
        int32_t __stdcall add_TouchHitTesting(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().TouchHitTesting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Foundation::IInspectable, llm::OS::UI::Core::TouchHitTestingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TouchHitTesting(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TouchHitTesting(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindow> : produce_base<D, llm::OS::UI::Core::ICoreWindow>
    {
        int32_t __stdcall get_AutomationHostProvider(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().AutomationHostProvider());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bounds(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().Bounds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IPropertySet>(this->shim().CustomProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Dispatcher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreDispatcher>(this->shim().Dispatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FlowDirection(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreWindowFlowDirection>(this->shim().FlowDirection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_FlowDirection(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlowDirection(*reinterpret_cast<llm::OS::UI::Core::CoreWindowFlowDirection const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInputEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInputEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInputEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInputEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
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
        int32_t __stdcall get_PointerPosition(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().PointerPosition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Visible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Visible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Activate() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activate();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAsyncKeyState(int32_t virtualKey, uint32_t* KeyState) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *KeyState = detach_from<llm::OS::UI::Core::CoreVirtualKeyStates>(this->shim().GetAsyncKeyState(*reinterpret_cast<llm::OS::System::VirtualKey const*>(&virtualKey)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetKeyState(int32_t virtualKey, uint32_t* KeyState) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *KeyState = detach_from<llm::OS::UI::Core::CoreVirtualKeyStates>(this->shim().GetKeyState(*reinterpret_cast<llm::OS::System::VirtualKey const*>(&virtualKey)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReleasePointerCapture() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReleasePointerCapture();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPointerCapture() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPointerCapture();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Activated(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().Activated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::WindowActivatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Activated(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activated(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_AutomationProviderRequested(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AutomationProviderRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::AutomationProviderRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AutomationProviderRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AutomationProviderRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_CharacterReceived(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().CharacterReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CharacterReceivedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CharacterReceived(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CharacterReceived(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_Closed(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().Closed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closed(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_InputEnabled(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().InputEnabled(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::InputEnabledEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_InputEnabled(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InputEnabled(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_KeyDown(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().KeyDown(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::KeyEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_KeyDown(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyDown(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_KeyUp(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().KeyUp(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::KeyEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_KeyUp(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().KeyUp(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerCaptureLost(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerCaptureLost(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerCaptureLost(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerCaptureLost(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerEntered(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerEntered(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerEntered(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerEntered(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerExited(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerExited(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerExited(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerExited(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerMoved(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerMoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerMoved(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerMoved(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerPressed(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerPressed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerPressed(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPressed(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerReleased(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerReleased(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerReleased(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerReleased(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_TouchHitTesting(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().TouchHitTesting(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::TouchHitTestingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TouchHitTesting(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TouchHitTesting(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_PointerWheelChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().PointerWheelChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::PointerEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PointerWheelChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerWheelChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_SizeChanged(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().SizeChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::WindowSizeChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SizeChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SizeChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_VisibilityChanged(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().VisibilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::VisibilityChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VisibilityChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibilityChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindow2> : produce_base<D, llm::OS::UI::Core::ICoreWindow2>
    {
        int32_t __stdcall put_PointerPosition(llm::OS::Foundation::Point value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PointerPosition(*reinterpret_cast<llm::OS::Foundation::Point const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindow3> : produce_base<D, llm::OS::UI::Core::ICoreWindow3>
    {
        int32_t __stdcall add_ClosestInteractiveBoundsRequested(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().ClosestInteractiveBoundsRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ClosestInteractiveBoundsRequested(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClosestInteractiveBoundsRequested(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall GetCurrentKeyEventDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetCurrentKeyEventDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindow4> : produce_base<D, llm::OS::UI::Core::ICoreWindow4>
    {
        int32_t __stdcall add_ResizeStarted(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().ResizeStarted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ResizeStarted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResizeStarted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_ResizeCompleted(void* handler, llm::event_token* pCookie) noexcept final try
        {
            zero_abi<llm::event_token>(pCookie);
            typename D::abi_guard guard(this->shim());
            *pCookie = detach_from<llm::event_token>(this->shim().ResizeCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ResizeCompleted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResizeCompleted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindow5> : produce_base<D, llm::OS::UI::Core::ICoreWindow5>
    {
        int32_t __stdcall get_DispatcherQueue(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::DispatcherQueue>(this->shim().DispatcherQueue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivationMode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreWindowActivationMode>(this->shim().ActivationMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowDialog> : produce_base<D, llm::OS::UI::Core::ICoreWindowDialog>
    {
        int32_t __stdcall add_Showing(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Showing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Showing(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_MaxSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MaxSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MinSize());
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
        int32_t __stdcall get_IsInteractionDelayed(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().IsInteractionDelayed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInteractionDelayed(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInteractionDelayed(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Commands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Popups::IUICommand>>(this->shim().Commands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultCommandIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().DefaultCommandIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DefaultCommandIndex(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultCommandIndex(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CancelCommandIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().CancelCommandIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CancelCommandIndex(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelCommandIndex(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackButtonCommand(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Popups::UICommandInvokedHandler>(this->shim().BackButtonCommand());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackButtonCommand(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackButtonCommand(*reinterpret_cast<llm::OS::UI::Popups::UICommandInvokedHandler const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Popups::IUICommand>>(this->shim().ShowAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowDialogFactory> : produce_base<D, llm::OS::UI::Core::ICoreWindowDialogFactory>
    {
        int32_t __stdcall CreateWithTitle(void* title, void** coreWindowDialog) noexcept final try
        {
            clear_abi(coreWindowDialog);
            typename D::abi_guard guard(this->shim());
            *coreWindowDialog = detach_from<llm::OS::UI::Core::CoreWindowDialog>(this->shim().CreateWithTitle(*reinterpret_cast<hstring const*>(&title)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowEventArgs> : produce_base<D, llm::OS::UI::Core::ICoreWindowEventArgs>
    {
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
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowFlyout> : produce_base<D, llm::OS::UI::Core::ICoreWindowFlyout>
    {
        int32_t __stdcall add_Showing(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Showing(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Core::CoreWindow, llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Showing(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Showing(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_MaxSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MaxSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinSize(llm::OS::Foundation::Size* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Size>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Size>(this->shim().MinSize());
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
        int32_t __stdcall get_IsInteractionDelayed(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().IsInteractionDelayed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsInteractionDelayed(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInteractionDelayed(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Commands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Popups::IUICommand>>(this->shim().Commands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultCommandIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().DefaultCommandIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DefaultCommandIndex(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultCommandIndex(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackButtonCommand(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Popups::UICommandInvokedHandler>(this->shim().BackButtonCommand());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackButtonCommand(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackButtonCommand(*reinterpret_cast<llm::OS::UI::Popups::UICommandInvokedHandler const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::Popups::IUICommand>>(this->shim().ShowAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowFlyoutFactory> : produce_base<D, llm::OS::UI::Core::ICoreWindowFlyoutFactory>
    {
        int32_t __stdcall Create(llm::OS::Foundation::Point position, void** coreWindowFlyout) noexcept final try
        {
            clear_abi(coreWindowFlyout);
            typename D::abi_guard guard(this->shim());
            *coreWindowFlyout = detach_from<llm::OS::UI::Core::CoreWindowFlyout>(this->shim().Create(*reinterpret_cast<llm::OS::Foundation::Point const*>(&position)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithTitle(llm::OS::Foundation::Point position, void* title, void** coreWindowFlyout) noexcept final try
        {
            clear_abi(coreWindowFlyout);
            typename D::abi_guard guard(this->shim());
            *coreWindowFlyout = detach_from<llm::OS::UI::Core::CoreWindowFlyout>(this->shim().CreateWithTitle(*reinterpret_cast<llm::OS::Foundation::Point const*>(&position), *reinterpret_cast<hstring const*>(&title)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowPopupShowingEventArgs> : produce_base<D, llm::OS::UI::Core::ICoreWindowPopupShowingEventArgs>
    {
        int32_t __stdcall SetDesiredSize(llm::OS::Foundation::Size value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDesiredSize(*reinterpret_cast<llm::OS::Foundation::Size const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowResizeManager> : produce_base<D, llm::OS::UI::Core::ICoreWindowResizeManager>
    {
        int32_t __stdcall NotifyLayoutCompleted() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NotifyLayoutCompleted();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowResizeManagerLayoutCapability> : produce_base<D, llm::OS::UI::Core::ICoreWindowResizeManagerLayoutCapability>
    {
        int32_t __stdcall put_ShouldWaitForLayoutCompletion(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShouldWaitForLayoutCompletion(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShouldWaitForLayoutCompletion(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShouldWaitForLayoutCompletion());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowResizeManagerStatics> : produce_base<D, llm::OS::UI::Core::ICoreWindowResizeManagerStatics>
    {
        int32_t __stdcall GetForCurrentView(void** CoreWindowResizeManager) noexcept final try
        {
            clear_abi(CoreWindowResizeManager);
            typename D::abi_guard guard(this->shim());
            *CoreWindowResizeManager = detach_from<llm::OS::UI::Core::CoreWindowResizeManager>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowStatic> : produce_base<D, llm::OS::UI::Core::ICoreWindowStatic>
    {
        int32_t __stdcall GetForCurrentThread(void** ppWindow) noexcept final try
        {
            clear_abi(ppWindow);
            typename D::abi_guard guard(this->shim());
            *ppWindow = detach_from<llm::OS::UI::Core::CoreWindow>(this->shim().GetForCurrentThread());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ICoreWindowWithContext> : produce_base<D, llm::OS::UI::Core::ICoreWindowWithContext>
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
    struct produce<D, llm::OS::UI::Core::IIdleDispatchedHandlerArgs> : produce_base<D, llm::OS::UI::Core::IIdleDispatchedHandlerArgs>
    {
        int32_t __stdcall get_IsDispatcherIdle(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDispatcherIdle());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IInitializeWithCoreWindow> : produce_base<D, llm::OS::UI::Core::IInitializeWithCoreWindow>
    {
        int32_t __stdcall Initialize(void* window) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Initialize(*reinterpret_cast<llm::OS::UI::Core::CoreWindow const*>(&window));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IInputEnabledEventArgs> : produce_base<D, llm::OS::UI::Core::IInputEnabledEventArgs>
    {
        int32_t __stdcall get_InputEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().InputEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IKeyEventArgs> : produce_base<D, llm::OS::UI::Core::IKeyEventArgs>
    {
        int32_t __stdcall get_VirtualKey(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::VirtualKey>(this->shim().VirtualKey());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyStatus(struct struct_Windows_UI_Core_CorePhysicalKeyStatus* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Core::CorePhysicalKeyStatus>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CorePhysicalKeyStatus>(this->shim().KeyStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IKeyEventArgs2> : produce_base<D, llm::OS::UI::Core::IKeyEventArgs2>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IPointerEventArgs> : produce_base<D, llm::OS::UI::Core::IPointerEventArgs>
    {
        int32_t __stdcall get_CurrentPoint(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Input::PointerPoint>(this->shim().CurrentPoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_KeyModifiers(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::VirtualKeyModifiers>(this->shim().KeyModifiers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIntermediatePoints(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Input::PointerPoint>>(this->shim().GetIntermediatePoints());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ISystemNavigationManager> : produce_base<D, llm::OS::UI::Core::ISystemNavigationManager>
    {
        int32_t __stdcall add_BackRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BackRequested(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::UI::Core::BackRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BackRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ISystemNavigationManager2> : produce_base<D, llm::OS::UI::Core::ISystemNavigationManager2>
    {
        int32_t __stdcall get_AppViewBackButtonVisibility(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::AppViewBackButtonVisibility>(this->shim().AppViewBackButtonVisibility());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AppViewBackButtonVisibility(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppViewBackButtonVisibility(*reinterpret_cast<llm::OS::UI::Core::AppViewBackButtonVisibility const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ISystemNavigationManagerStatics> : produce_base<D, llm::OS::UI::Core::ISystemNavigationManagerStatics>
    {
        int32_t __stdcall GetForCurrentView(void** loader) noexcept final try
        {
            clear_abi(loader);
            typename D::abi_guard guard(this->shim());
            *loader = detach_from<llm::OS::UI::Core::SystemNavigationManager>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::ITouchHitTestingEventArgs> : produce_base<D, llm::OS::UI::Core::ITouchHitTestingEventArgs>
    {
        int32_t __stdcall get_ProximityEvaluation(struct struct_Windows_UI_Core_CoreProximityEvaluation* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Core::CoreProximityEvaluation>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreProximityEvaluation>(this->shim().ProximityEvaluation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProximityEvaluation(struct struct_Windows_UI_Core_CoreProximityEvaluation value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProximityEvaluation(*reinterpret_cast<llm::OS::UI::Core::CoreProximityEvaluation const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Point(llm::OS::Foundation::Point* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Point>(this->shim().Point());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BoundingBox(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().BoundingBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EvaluateProximityToRect(llm::OS::Foundation::Rect controlBoundingBox, struct struct_Windows_UI_Core_CoreProximityEvaluation* proximityEvaluation) noexcept final try
        {
            zero_abi<llm::OS::UI::Core::CoreProximityEvaluation>(proximityEvaluation);
            typename D::abi_guard guard(this->shim());
            *proximityEvaluation = detach_from<llm::OS::UI::Core::CoreProximityEvaluation>(this->shim().EvaluateProximity(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&controlBoundingBox)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EvaluateProximityToPolygon(uint32_t __controlVerticesSize, llm::OS::Foundation::Point* controlVertices, struct struct_Windows_UI_Core_CoreProximityEvaluation* proximityEvaluation) noexcept final try
        {
            zero_abi<llm::OS::UI::Core::CoreProximityEvaluation>(proximityEvaluation);
            typename D::abi_guard guard(this->shim());
            *proximityEvaluation = detach_from<llm::OS::UI::Core::CoreProximityEvaluation>(this->shim().EvaluateProximity(array_view<llm::OS::Foundation::Point const>(reinterpret_cast<llm::OS::Foundation::Point const *>(controlVertices), reinterpret_cast<llm::OS::Foundation::Point const *>(controlVertices) + __controlVerticesSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IVisibilityChangedEventArgs> : produce_base<D, llm::OS::UI::Core::IVisibilityChangedEventArgs>
    {
        int32_t __stdcall get_Visible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Visible());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IWindowActivatedEventArgs> : produce_base<D, llm::OS::UI::Core::IWindowActivatedEventArgs>
    {
        int32_t __stdcall get_WindowActivationState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Core::CoreWindowActivationState>(this->shim().WindowActivationState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Core::IWindowSizeChangedEventArgs> : produce_base<D, llm::OS::UI::Core::IWindowSizeChangedEventArgs>
    {
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
}
LLM_EXPORT namespace llm::OS::UI::Core
{
    constexpr auto operator|(CoreIndependentInputFilters const left, CoreIndependentInputFilters const right) noexcept
    {
        return static_cast<CoreIndependentInputFilters>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(CoreIndependentInputFilters& left, CoreIndependentInputFilters const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(CoreIndependentInputFilters const left, CoreIndependentInputFilters const right) noexcept
    {
        return static_cast<CoreIndependentInputFilters>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(CoreIndependentInputFilters& left, CoreIndependentInputFilters const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(CoreIndependentInputFilters const value) noexcept
    {
        return static_cast<CoreIndependentInputFilters>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(CoreIndependentInputFilters const left, CoreIndependentInputFilters const right) noexcept
    {
        return static_cast<CoreIndependentInputFilters>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(CoreIndependentInputFilters& left, CoreIndependentInputFilters const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(CoreInputDeviceTypes const left, CoreInputDeviceTypes const right) noexcept
    {
        return static_cast<CoreInputDeviceTypes>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(CoreInputDeviceTypes& left, CoreInputDeviceTypes const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(CoreInputDeviceTypes const left, CoreInputDeviceTypes const right) noexcept
    {
        return static_cast<CoreInputDeviceTypes>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(CoreInputDeviceTypes& left, CoreInputDeviceTypes const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(CoreInputDeviceTypes const value) noexcept
    {
        return static_cast<CoreInputDeviceTypes>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(CoreInputDeviceTypes const left, CoreInputDeviceTypes const right) noexcept
    {
        return static_cast<CoreInputDeviceTypes>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(CoreInputDeviceTypes& left, CoreInputDeviceTypes const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(CoreVirtualKeyStates const left, CoreVirtualKeyStates const right) noexcept
    {
        return static_cast<CoreVirtualKeyStates>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(CoreVirtualKeyStates& left, CoreVirtualKeyStates const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(CoreVirtualKeyStates const left, CoreVirtualKeyStates const right) noexcept
    {
        return static_cast<CoreVirtualKeyStates>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(CoreVirtualKeyStates& left, CoreVirtualKeyStates const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(CoreVirtualKeyStates const value) noexcept
    {
        return static_cast<CoreVirtualKeyStates>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(CoreVirtualKeyStates const left, CoreVirtualKeyStates const right) noexcept
    {
        return static_cast<CoreVirtualKeyStates>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(CoreVirtualKeyStates& left, CoreVirtualKeyStates const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline CoreCursor::CoreCursor(llm::OS::UI::Core::CoreCursorType const& type, uint32_t id) :
        CoreCursor(impl::call_factory<CoreCursor, ICoreCursorFactory>([&](ICoreCursorFactory const& f) { return f.CreateCursor(type, id); }))
    {
    }
    inline auto CoreIndependentInputSourceController::CreateForVisual(llm::OS::UI::Composition::Visual const& visual)
    {
        return impl::call_factory<CoreIndependentInputSourceController, ICoreIndependentInputSourceControllerStatics>([&](ICoreIndependentInputSourceControllerStatics const& f) { return f.CreateForVisual(visual); });
    }
    inline auto CoreIndependentInputSourceController::CreateForIVisualElement(llm::OS::UI::Composition::IVisualElement const& visualElement)
    {
        return impl::call_factory<CoreIndependentInputSourceController, ICoreIndependentInputSourceControllerStatics>([&](ICoreIndependentInputSourceControllerStatics const& f) { return f.CreateForIVisualElement(visualElement); });
    }
    inline auto CoreWindow::GetForCurrentThread()
    {
        return impl::call_factory_cast<llm::OS::UI::Core::CoreWindow(*)(ICoreWindowStatic const&), CoreWindow, ICoreWindowStatic>([](ICoreWindowStatic const& f) { return f.GetForCurrentThread(); });
    }
    inline CoreWindowDialog::CoreWindowDialog() :
        CoreWindowDialog(impl::call_factory_cast<CoreWindowDialog(*)(llm::OS::Foundation::IActivationFactory const&), CoreWindowDialog>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<CoreWindowDialog>(); }))
    {
    }
    inline CoreWindowDialog::CoreWindowDialog(param::hstring const& title) :
        CoreWindowDialog(impl::call_factory<CoreWindowDialog, ICoreWindowDialogFactory>([&](ICoreWindowDialogFactory const& f) { return f.CreateWithTitle(title); }))
    {
    }
    inline CoreWindowFlyout::CoreWindowFlyout(llm::OS::Foundation::Point const& position) :
        CoreWindowFlyout(impl::call_factory<CoreWindowFlyout, ICoreWindowFlyoutFactory>([&](ICoreWindowFlyoutFactory const& f) { return f.Create(position); }))
    {
    }
    inline CoreWindowFlyout::CoreWindowFlyout(llm::OS::Foundation::Point const& position, param::hstring const& title) :
        CoreWindowFlyout(impl::call_factory<CoreWindowFlyout, ICoreWindowFlyoutFactory>([&](ICoreWindowFlyoutFactory const& f) { return f.CreateWithTitle(position, title); }))
    {
    }
    inline auto CoreWindowResizeManager::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::Core::CoreWindowResizeManager(*)(ICoreWindowResizeManagerStatics const&), CoreWindowResizeManager, ICoreWindowResizeManagerStatics>([](ICoreWindowResizeManagerStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto SystemNavigationManager::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::Core::SystemNavigationManager(*)(ISystemNavigationManagerStatics const&), SystemNavigationManager, ISystemNavigationManagerStatics>([](ISystemNavigationManagerStatics const& f) { return f.GetForCurrentView(); });
    }
    template <typename L> DispatchedHandler::DispatchedHandler(L handler) :
        DispatchedHandler(impl::make_delegate<DispatchedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> DispatchedHandler::DispatchedHandler(F* handler) :
        DispatchedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> DispatchedHandler::DispatchedHandler(O* object, M method) :
        DispatchedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> DispatchedHandler::DispatchedHandler(com_ptr<O>&& object, M method) :
        DispatchedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> DispatchedHandler::DispatchedHandler(weak_ref<O>&& object, M method) :
        DispatchedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto DispatchedHandler::operator()() const
    {
        check_hresult((*(impl::abi_t<DispatchedHandler>**)this)->Invoke());
    }
    template <typename L> IdleDispatchedHandler::IdleDispatchedHandler(L handler) :
        IdleDispatchedHandler(impl::make_delegate<IdleDispatchedHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> IdleDispatchedHandler::IdleDispatchedHandler(F* handler) :
        IdleDispatchedHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> IdleDispatchedHandler::IdleDispatchedHandler(O* object, M method) :
        IdleDispatchedHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> IdleDispatchedHandler::IdleDispatchedHandler(com_ptr<O>&& object, M method) :
        IdleDispatchedHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> IdleDispatchedHandler::IdleDispatchedHandler(weak_ref<O>&& object, M method) :
        IdleDispatchedHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto IdleDispatchedHandler::operator()(llm::OS::UI::Core::IdleDispatchedHandlerArgs const& e) const
    {
        check_hresult((*(impl::abi_t<IdleDispatchedHandler>**)this)->Invoke(*(void**)(&e)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Core::IAcceleratorKeyEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IAcceleratorKeyEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IAutomationProviderRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IBackRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICharacterReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IClosestInteractiveBoundsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreAcceleratorKeys> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreClosestInteractiveBoundsRequested> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreComponentFocusable> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreCursor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreCursorFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreDispatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreDispatcher2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreDispatcherWithTaskPriority> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreIndependentInputSourceController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreIndependentInputSourceControllerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreInputSourceBase> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreKeyboardInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreKeyboardInputSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICorePointerInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICorePointerInputSource2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICorePointerRedirector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreTouchHitTesting> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindow2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindow3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindow4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindow5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowDialog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowDialogFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowFlyout> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowFlyoutFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowPopupShowingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowResizeManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowResizeManagerLayoutCapability> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowResizeManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowStatic> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ICoreWindowWithContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IIdleDispatchedHandlerArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IInitializeWithCoreWindow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IInputEnabledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IKeyEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IKeyEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IPointerEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ISystemNavigationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ISystemNavigationManager2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ISystemNavigationManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ITouchHitTestingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IVisibilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IWindowActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IWindowSizeChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AcceleratorKeyEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::AutomationProviderRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::BackRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CharacterReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::ClosestInteractiveBoundsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreAcceleratorKeys> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreComponentInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreCursor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreDispatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreIndependentInputSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreIndependentInputSourceController> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreWindow> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreWindowDialog> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreWindowEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreWindowFlyout> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreWindowPopupShowingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::CoreWindowResizeManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::IdleDispatchedHandlerArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::InputEnabledEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::KeyEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::PointerEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::SystemNavigationManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::TouchHitTestingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::VisibilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::WindowActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Core::WindowSizeChangedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}

LLM_EXPORT namespace winrt
{
    [[nodiscard]] inline auto resume_foreground(
        Windows::UI::Core::CoreDispatcher const& dispatcher,
        Windows::UI::Core::CoreDispatcherPriority const priority = Windows::UI::Core::CoreDispatcherPriority::Normal) noexcept
    {
        struct awaitable
        {
            awaitable(Windows::UI::Core::CoreDispatcher const& dispatcher, Windows::UI::Core::CoreDispatcherPriority const priority) noexcept :
                m_dispatcher(dispatcher),
                m_priority(priority)
            {
            }

            bool await_ready() const noexcept
            {
                return false;
            }

            void await_resume() const noexcept
            {
            }

            void await_suspend(impl::coroutine_handle<> handle) const
            {
                m_dispatcher.RunAsync(m_priority, [handle]
                    {
                        handle();
                    });
            }

        private:

            Windows::UI::Core::CoreDispatcher const& m_dispatcher;
            Windows::UI::Core::CoreDispatcherPriority const m_priority;
        };

        return awaitable{ dispatcher, priority };
    };

#ifdef LLM_IMPL_COROUTINES
    inline auto operator co_await(Windows::UI::Core::CoreDispatcher const& dispatcher)
    {
        return resume_foreground(dispatcher);
    }
#endif
}
#endif
