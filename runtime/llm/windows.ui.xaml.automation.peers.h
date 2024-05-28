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
#ifndef LLM_OS_UI_Xaml_Automation_Peers_H
#define LLM_OS_UI_Xaml_Automation_Peers_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.Xaml.Automation.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.UI.Xaml.2.h"
#include "llm/impl/Windows.UI.Xaml.Automation.2.h"
#include "llm/impl/Windows.UI.Xaml.Automation.Provider.2.h"
#include "llm/impl/Windows.UI.Xaml.Controls.2.h"
#include "llm/impl/Windows.UI.Xaml.Controls.Primitives.2.h"
#include "llm/impl/Windows.UI.Xaml.Automation.Peers.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AppBarAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAppBarAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::AppBar const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AppBarAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAppBarButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::AppBarButton const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAppBarToggleButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::AppBarToggleButton const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutoSuggestBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::AutoSuggestBox const& owner) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::EventsSource() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->get_EventsSource(&value));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::EventsSource(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->put_EventsSource(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetPattern(llm::OS::UI::Xaml::Automation::Peers::PatternInterface const& patternInterface) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetPattern(static_cast<int32_t>(patternInterface), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::RaiseAutomationEvent(llm::OS::UI::Xaml::Automation::Peers::AutomationEvents const& eventId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->RaiseAutomationEvent(static_cast<int32_t>(eventId)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::RaisePropertyChangedEvent(llm::OS::UI::Xaml::Automation::AutomationProperty const& automationProperty, llm::OS::Foundation::IInspectable const& oldValue, llm::OS::Foundation::IInspectable const& newValue) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->RaisePropertyChangedEvent(*(void**)(&automationProperty), *(void**)(&oldValue), *(void**)(&newValue)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetAcceleratorKey() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetAcceleratorKey(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetAccessKey() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetAccessKey(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationControlType) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetAutomationControlType() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationControlType result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetAutomationControlType(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetAutomationId() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetAutomationId(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetBoundingRectangle() const
    {
        llm::OS::Foundation::Rect result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetBoundingRectangle(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetChildren() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetChildren(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetClassName() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetClassName(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetClickablePoint() const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetClickablePoint(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetHelpText() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetHelpText(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetItemStatus() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetItemStatus(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetItemType() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetItemType(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetLabeledBy() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetLabeledBy(&result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetLocalizedControlType() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetLocalizedControlType(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetName() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetName(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetOrientation() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetOrientation(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::HasKeyboardFocus() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->HasKeyboardFocus(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsContentElement() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsContentElement(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsControlElement() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsControlElement(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsEnabled() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsEnabled(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsKeyboardFocusable() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsKeyboardFocusable(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsOffscreen() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsOffscreen(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsPassword() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsPassword(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::IsRequiredForForm() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->IsRequiredForForm(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::SetFocus() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->SetFocus());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetParent() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetParent(&result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::InvalidatePeer() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->InvalidatePeer());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetPeerFromPoint(llm::OS::Foundation::Point const& point) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetPeerFromPoint(impl::bind_in(point), &result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer<D>::GetLiveSetting() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer)->GetLiveSetting(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::Navigate(llm::OS::UI::Xaml::Automation::Peers::AutomationNavigationDirection const& direction) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->Navigate(static_cast<int32_t>(direction), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetElementFromPoint(llm::OS::Foundation::Point const& pointInWindowCoordinates) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetElementFromPoint(impl::bind_in(pointInWindowCoordinates), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetFocusedElement() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetFocusedElement(&result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::ShowContextMenu() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->ShowContextMenu());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetControlledPeers() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetControlledPeers(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetAnnotations() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetAnnotations(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::SetParent(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& peer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->SetParent(*(void**)(&peer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::RaiseTextEditTextChangedEvent(llm::OS::UI::Xaml::Automation::AutomationTextEditChangeType const& automationTextEditChangeType, param::vector_view<hstring> const& changedData) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->RaiseTextEditTextChangedEvent(static_cast<int32_t>(automationTextEditChangeType), *(void**)(&changedData)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetPositionInSet() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetPositionInSet(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetSizeOfSet() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetSizeOfSet(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::GetLevel() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->GetLevel(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer3<D>::RaiseStructureChangedEvent(llm::OS::UI::Xaml::Automation::Peers::AutomationStructureChangeType const& structureChangeType, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& child) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3)->RaiseStructureChangedEvent(static_cast<int32_t>(structureChangeType), *(void**)(&child)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer4<D>::GetLandmarkType() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4)->GetLandmarkType(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer4<D>::GetLocalizedLandmarkType() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4)->GetLocalizedLandmarkType(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer5<D>::IsPeripheral() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5)->IsPeripheral(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer5<D>::IsDataValidForForm() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5)->IsDataValidForForm(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer5<D>::GetFullDescription() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5)->GetFullDescription(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer6<D>::GetCulture() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6)->GetCulture(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer7<D>::RaiseNotificationEvent(llm::OS::UI::Xaml::Automation::Peers::AutomationNotificationKind const& notificationKind, llm::OS::UI::Xaml::Automation::Peers::AutomationNotificationProcessing const& notificationProcessing, param::hstring const& displayString, param::hstring const& activityId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7)->RaiseNotificationEvent(static_cast<int32_t>(notificationKind), static_cast<int32_t>(notificationProcessing), *(void**)(&displayString), *(void**)(&activityId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer8<D>::GetHeadingLevel() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8)->GetHeadingLevel(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeer9<D>::IsDialog() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9)->IsDialog(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::AnnotationType) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotation<D>::Type() const
    {
        llm::OS::UI::Xaml::Automation::AnnotationType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotation<D>::Type(llm::OS::UI::Xaml::Automation::AnnotationType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation)->put_Type(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotation<D>::Peer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation)->get_Peer(&value));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotation<D>::Peer(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation)->put_Peer(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotationFactory<D>::CreateInstance(llm::OS::UI::Xaml::Automation::AnnotationType const& type) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory)->CreateInstance(static_cast<int32_t>(type), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotationFactory<D>::CreateWithPeerParameter(llm::OS::UI::Xaml::Automation::AnnotationType const& type, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& peer) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory)->CreateWithPeerParameter(static_cast<int32_t>(type), *(void**)(&peer), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotationStatics<D>::TypeProperty() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics)->get_TypeProperty(&value));
        return llm::OS::UI::Xaml::DependencyProperty{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerAnnotationStatics<D>::PeerProperty() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics)->get_PeerProperty(&value));
        return llm::OS::UI::Xaml::DependencyProperty{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerFactory<D>::CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerFactory)->CreateInstance(*(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetPatternCore(llm::OS::UI::Xaml::Automation::Peers::PatternInterface const& patternInterface) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetPatternCore(static_cast<int32_t>(patternInterface), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetAcceleratorKeyCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetAcceleratorKeyCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetAccessKeyCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetAccessKeyCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationControlType) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetAutomationControlTypeCore() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationControlType result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetAutomationControlTypeCore(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetAutomationIdCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetAutomationIdCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetBoundingRectangleCore() const
    {
        llm::OS::Foundation::Rect result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetBoundingRectangleCore(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetChildrenCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetChildrenCore(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetClassNameCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetClassNameCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetClickablePointCore() const
    {
        llm::OS::Foundation::Point result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetClickablePointCore(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetHelpTextCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetHelpTextCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetItemStatusCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetItemStatusCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetItemTypeCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetItemTypeCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetLabeledByCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetLabeledByCore(&result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetLocalizedControlTypeCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetLocalizedControlTypeCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetNameCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetNameCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetOrientationCore() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetOrientationCore(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::HasKeyboardFocusCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->HasKeyboardFocusCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsContentElementCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsContentElementCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsControlElementCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsControlElementCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsEnabledCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsEnabledCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsKeyboardFocusableCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsKeyboardFocusableCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsOffscreenCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsOffscreenCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsPasswordCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsPasswordCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::IsRequiredForFormCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->IsRequiredForFormCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::SetFocusCore() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->SetFocusCore());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetPeerFromPointCore(llm::OS::Foundation::Point const& point) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetPeerFromPointCore(impl::bind_in(point), &result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides<D>::GetLiveSettingCore() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides)->GetLiveSettingCore(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides2<D>::ShowContextMenuCore() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2)->ShowContextMenuCore());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides2<D>::GetControlledPeersCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2)->GetControlledPeersCore(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::NavigateCore(llm::OS::UI::Xaml::Automation::Peers::AutomationNavigationDirection const& direction) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->NavigateCore(static_cast<int32_t>(direction), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::GetElementFromPointCore(llm::OS::Foundation::Point const& pointInWindowCoordinates) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->GetElementFromPointCore(impl::bind_in(pointInWindowCoordinates), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::GetFocusedElementCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->GetFocusedElementCore(&result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::GetAnnotationsCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->GetAnnotationsCore(&result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::GetPositionInSetCore() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->GetPositionInSetCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::GetSizeOfSetCore() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->GetSizeOfSetCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides3<D>::GetLevelCore() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3)->GetLevelCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides4<D>::GetLandmarkTypeCore() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4)->GetLandmarkTypeCore(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides4<D>::GetLocalizedLandmarkTypeCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4)->GetLocalizedLandmarkTypeCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides5<D>::IsPeripheralCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5)->IsPeripheralCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides5<D>::IsDataValidForFormCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5)->IsDataValidForFormCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides5<D>::GetFullDescriptionCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5)->GetFullDescriptionCore(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides5<D>::GetDescribedByCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5)->GetDescribedByCore(&result));
        return llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides5<D>::GetFlowsToCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5)->GetFlowsToCore(&result));
        return llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides5<D>::GetFlowsFromCore() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5)->GetFlowsFromCore(&result));
        return llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides6<D>::GetCultureCore() const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6)->GetCultureCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides8<D>::GetHeadingLevelCore() const
    {
        llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8)->GetHeadingLevelCore(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerOverrides9<D>::IsDialogCore() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9)->IsDialogCore(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerProtected<D>::PeerFromProvider(llm::OS::UI::Xaml::Automation::Provider::IRawElementProviderSimple const& provider) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected)->PeerFromProvider(*(void**)(&provider), &result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Provider::IRawElementProviderSimple) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerProtected<D>::ProviderFromPeer(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& peer) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected)->ProviderFromPeer(*(void**)(&peer), &result));
        return llm::OS::UI::Xaml::Automation::Provider::IRawElementProviderSimple{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerStatics<D>::ListenerExists(llm::OS::UI::Xaml::Automation::Peers::AutomationEvents const& eventId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics)->ListenerExists(static_cast<int32_t>(eventId), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId) consume_Windows_UI_Xaml_Automation_Peers_IAutomationPeerStatics3<D>::GenerateRawElementProviderRuntimeId() const
    {
        llm::OS::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics3)->GenerateRawElementProviderRuntimeId(put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Button const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IButtonBaseAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::ButtonBase const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::CalendarDatePickerAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ICalendarDatePickerAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::CalendarDatePicker const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::CalendarDatePickerAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ICaptureElementAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::CaptureElement const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ICheckBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::CheckBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ColorPickerSliderAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IColorPickerSliderAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::ColorPickerSlider const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ColorPickerSliderAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ColorSpectrumAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IColorSpectrumAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::ColorSpectrum const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ColorSpectrumAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IComboBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ComboBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IComboBoxItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ComboBoxItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IComboBoxItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::DatePickerAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IDatePickerAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::DatePicker const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::DatePickerAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFlipViewAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::FlipView const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFlipViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::FlipViewItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFlipViewItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFlyoutPresenterAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::FlyoutPresenter const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::UIElement) consume_Windows_UI_Xaml_Automation_Peers_IFrameworkElementAutomationPeer<D>::Owner() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer)->get_Owner(&value));
        return llm::OS::UI::Xaml::UIElement{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFrameworkElementAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::FrameworkElement const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFrameworkElementAutomationPeerStatics<D>::FromElement(llm::OS::UI::Xaml::UIElement const& element) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics)->FromElement(*(void**)(&element), &result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IFrameworkElementAutomationPeerStatics<D>::CreatePeerForElement(llm::OS::UI::Xaml::UIElement const& element) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics)->CreatePeerForElement(*(void**)(&element), &result));
        return llm::OS::UI::Xaml::Automation::Peers::AutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IGridViewAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::GridView const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IGridViewHeaderItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::GridViewHeaderItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IGridViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::GridViewItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IGridViewItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::GroupItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IGroupItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::GroupItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::GroupItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::HubAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IHubAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Hub const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::HubAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::HubSectionAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IHubSectionAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::HubSection const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::HubSectionAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IHyperlinkButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::HyperlinkButton const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ImageAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IImageAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Image const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ImageAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Xaml_Automation_Peers_IItemAutomationPeer<D>::Item() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer)->get_Item(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IItemAutomationPeer<D>::ItemsControlAutomationPeer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer)->get_ItemsControlAutomationPeer(&value));
        return llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IItemAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IItemsControlAutomationPeer2<D>::CreateItemAutomationPeer(llm::OS::Foundation::IInspectable const& item) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2)->CreateItemAutomationPeer(*(void**)(&item), &result));
        return llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IItemsControlAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ItemsControl const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IItemsControlAutomationPeerOverrides2<D>::OnCreateItemAutomationPeer(llm::OS::Foundation::IInspectable const& item) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2)->OnCreateItemAutomationPeer(*(void**)(&item), &result));
        return llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListBoxItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListBoxItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListBoxItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListViewAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListViewAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListView const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListViewAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListViewBaseAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListViewBase const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListViewBaseHeaderItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListViewBaseHeaderItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListViewHeaderItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListViewHeaderItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ListViewItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IListViewItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MediaElementAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMediaElementAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::MediaElement const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MediaElementAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMediaPlayerElementAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::MediaPlayerElement const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMediaTransportControlsAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::MediaTransportControls const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MenuBarAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMenuBarAutomationPeerFactory<D>::CreateInstance(llm::OS::UI::Xaml::Controls::MenuBar const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeerFactory)->CreateInstance(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MenuBarAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MenuBarItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMenuBarItemAutomationPeerFactory<D>::CreateInstance(llm::OS::UI::Xaml::Controls::MenuBarItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeerFactory)->CreateInstance(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MenuBarItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMenuFlyoutItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::MenuFlyoutItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IMenuFlyoutPresenterAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::MenuFlyoutPresenter const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::NavigationViewItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_INavigationViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::NavigationViewItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::NavigationViewItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IPasswordBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::PasswordBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::PersonPictureAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IPersonPictureAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::PersonPicture const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::PersonPictureAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IPivotAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Pivot const& owner) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), &value));
        return llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::PivotItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IPivotItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::PivotItem const& owner) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), &value));
        return llm::OS::UI::Xaml::Automation::Peers::PivotItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IPivotItemDataAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer const& parent) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), &value));
        return llm::OS::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IProgressBarAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ProgressBar const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IProgressRingAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ProgressRing const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRadioButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::RadioButton const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRangeBaseAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::RangeBase const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RatingControlAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRatingControlAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::RatingControl const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RatingControlAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRepeatButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::RepeatButton const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRichEditBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::RichEditBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRichTextBlockAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::RichTextBlock const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IRichTextBlockOverflowAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::RichTextBlockOverflow const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IScrollBarAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::ScrollBar const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IScrollViewerAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ScrollViewer const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ISearchBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::SearchBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ISelectorAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::Selector const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ISelectorItemAutomationPeerFactory<D>::CreateInstanceWithParentAndItem(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer const& parent, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory)->CreateInstanceWithParentAndItem(*(void**)(&item), *(void**)(&parent), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ISemanticZoomAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::SemanticZoom const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ISettingsFlyoutAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::SettingsFlyout const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::SliderAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ISliderAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Slider const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::SliderAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::TextBlockAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ITextBlockAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::TextBlock const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::TextBlockAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::TextBoxAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ITextBoxAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::TextBox const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::TextBoxAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ThumbAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IThumbAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::Thumb const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ThumbAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::TimePickerAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ITimePickerAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::TimePicker const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::TimePickerAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IToggleButtonAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::Primitives::ToggleButton const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IToggleMenuFlyoutItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ToggleMenuFlyoutItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_IToggleSwitchAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::ToggleSwitch const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::TreeViewItemAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ITreeViewItemAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::TreeViewItem const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::TreeViewItemAutomationPeer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::TreeViewListAutomationPeer) consume_Windows_UI_Xaml_Automation_Peers_ITreeViewListAutomationPeerFactory<D>::CreateInstanceWithOwner(llm::OS::UI::Xaml::Controls::TreeViewList const& owner, llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeerFactory)->CreateInstanceWithOwner(*(void**)(&owner), *(void**)(&baseInterface), impl::bind_out(innerInterface), &value));
        return llm::OS::UI::Xaml::Automation::Peers::TreeViewListAutomationPeer{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AppBarAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::AppBar const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::AppBarButton const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::AppBarToggleButton const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::AutoSuggestBox const*>(&owner)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer>
    {
        int32_t __stdcall get_EventsSource(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().EventsSource());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EventsSource(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EventsSource(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPattern(int32_t patternInterface, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetPattern(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::PatternInterface const*>(&patternInterface)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RaiseAutomationEvent(int32_t eventId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseAutomationEvent(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationEvents const*>(&eventId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RaisePropertyChangedEvent(void* automationProperty, void* oldValue, void* newValue) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaisePropertyChangedEvent(*reinterpret_cast<llm::OS::UI::Xaml::Automation::AutomationProperty const*>(&automationProperty), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&oldValue), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&newValue));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAcceleratorKey(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAcceleratorKey());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessKey(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAccessKey());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAutomationControlType(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationControlType>(this->shim().GetAutomationControlType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAutomationId(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAutomationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBoundingRectangle(llm::OS::Foundation::Rect* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Rect>(this->shim().GetBoundingRectangle());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetChildren(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetChildren());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetClassName(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetClassName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetClickablePoint(llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().GetClickablePoint());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetHelpText(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetHelpText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemStatus(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetItemStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemType(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetItemType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLabeledBy(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().GetLabeledBy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLocalizedControlType(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetLocalizedControlType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetName(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOrientation(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation>(this->shim().GetOrientation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HasKeyboardFocus(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().HasKeyboardFocus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsContentElement(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsContentElement());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsControlElement(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsControlElement());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsEnabled(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsKeyboardFocusable(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsKeyboardFocusable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsOffscreen(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsOffscreen());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPassword(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPassword());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsRequiredForForm(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsRequiredForForm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFocus() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocus();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetParent(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().GetParent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall InvalidatePeer() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InvalidatePeer();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPeerFromPoint(llm::OS::Foundation::Point point, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().GetPeerFromPoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&point)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLiveSetting(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting>(this->shim().GetLiveSetting());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3>
    {
        int32_t __stdcall Navigate(int32_t direction, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Navigate(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationNavigationDirection const*>(&direction)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetElementFromPoint(llm::OS::Foundation::Point pointInWindowCoordinates, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetElementFromPoint(*reinterpret_cast<llm::OS::Foundation::Point const*>(&pointInWindowCoordinates)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFocusedElement(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetFocusedElement());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowContextMenu() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContextMenu();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetControlledPeers(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetControlledPeers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAnnotations(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>>(this->shim().GetAnnotations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetParent(void* peer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetParent(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const*>(&peer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RaiseTextEditTextChangedEvent(int32_t automationTextEditChangeType, void* changedData) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseTextEditTextChangedEvent(*reinterpret_cast<llm::OS::UI::Xaml::Automation::AutomationTextEditChangeType const*>(&automationTextEditChangeType), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<hstring> const*>(&changedData));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPositionInSet(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetPositionInSet());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSizeOfSet(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetSizeOfSet());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLevel(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RaiseStructureChangedEvent(int32_t structureChangeType, void* child) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseStructureChangedEvent(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationStructureChangeType const*>(&structureChangeType), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const*>(&child));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4>
    {
        int32_t __stdcall GetLandmarkType(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType>(this->shim().GetLandmarkType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLocalizedLandmarkType(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetLocalizedLandmarkType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5>
    {
        int32_t __stdcall IsPeripheral(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPeripheral());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsDataValidForForm(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsDataValidForForm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFullDescription(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetFullDescription());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6>
    {
        int32_t __stdcall GetCulture(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetCulture());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7>
    {
        int32_t __stdcall RaiseNotificationEvent(int32_t notificationKind, int32_t notificationProcessing, void* displayString, void* activityId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RaiseNotificationEvent(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationNotificationKind const*>(&notificationKind), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationNotificationProcessing const*>(&notificationProcessing), *reinterpret_cast<hstring const*>(&displayString), *reinterpret_cast<hstring const*>(&activityId));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8>
    {
        int32_t __stdcall GetHeadingLevel(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel>(this->shim().GetHeadingLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9>
    {
        int32_t __stdcall IsDialog(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsDialog());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::AnnotationType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Type(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<llm::OS::UI::Xaml::Automation::AnnotationType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Peer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().Peer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Peer(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Peer(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory>
    {
        int32_t __stdcall CreateInstance(int32_t type, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::UI::Xaml::Automation::AnnotationType const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithPeerParameter(int32_t type, void* peer, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>(this->shim().CreateWithPeerParameter(*reinterpret_cast<llm::OS::UI::Xaml::Automation::AnnotationType const*>(&type), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const*>(&peer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics>
    {
        int32_t __stdcall get_TypeProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::DependencyProperty>(this->shim().TypeProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PeerProperty(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::DependencyProperty>(this->shim().PeerProperty());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstance(void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
    {
        int32_t __stdcall GetPatternCore(int32_t patternInterface, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetPatternCore(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::PatternInterface const*>(&patternInterface)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAcceleratorKeyCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAcceleratorKeyCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAccessKeyCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAccessKeyCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAutomationControlTypeCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationControlType>(this->shim().GetAutomationControlTypeCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAutomationIdCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAutomationIdCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetBoundingRectangleCore(llm::OS::Foundation::Rect* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Rect>(this->shim().GetBoundingRectangleCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetChildrenCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetChildrenCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetClassNameCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetClassNameCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetClickablePointCore(llm::OS::Foundation::Point* result) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Point>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Point>(this->shim().GetClickablePointCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetHelpTextCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetHelpTextCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemStatusCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetItemStatusCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetItemTypeCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetItemTypeCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLabeledByCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().GetLabeledByCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLocalizedControlTypeCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetLocalizedControlTypeCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetNameCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetNameCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetOrientationCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation>(this->shim().GetOrientationCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall HasKeyboardFocusCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().HasKeyboardFocusCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsContentElementCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsContentElementCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsControlElementCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsControlElementCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsEnabledCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsEnabledCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsKeyboardFocusableCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsKeyboardFocusableCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsOffscreenCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsOffscreenCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsPasswordCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPasswordCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsRequiredForFormCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsRequiredForFormCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetFocusCore() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetFocusCore();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPeerFromPointCore(llm::OS::Foundation::Point point, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().GetPeerFromPointCore(*reinterpret_cast<llm::OS::Foundation::Point const*>(&point)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLiveSettingCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting>(this->shim().GetLiveSettingCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
    {
        int32_t __stdcall ShowContextMenuCore() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowContextMenuCore();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetControlledPeersCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetControlledPeersCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
    {
        int32_t __stdcall NavigateCore(int32_t direction, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().NavigateCore(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationNavigationDirection const*>(&direction)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetElementFromPointCore(llm::OS::Foundation::Point pointInWindowCoordinates, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetElementFromPointCore(*reinterpret_cast<llm::OS::Foundation::Point const*>(&pointInWindowCoordinates)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFocusedElementCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetFocusedElementCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAnnotationsCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>>(this->shim().GetAnnotationsCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPositionInSetCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetPositionInSetCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSizeOfSetCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetSizeOfSetCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLevelCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetLevelCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
    {
        int32_t __stdcall GetLandmarkTypeCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType>(this->shim().GetLandmarkTypeCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLocalizedLandmarkTypeCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetLocalizedLandmarkTypeCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
    {
        int32_t __stdcall IsPeripheralCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsPeripheralCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsDataValidForFormCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsDataValidForFormCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFullDescriptionCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetFullDescriptionCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDescribedByCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetDescribedByCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFlowsToCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetFlowsToCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetFlowsFromCore(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>>(this->shim().GetFlowsFromCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6>
    {
        int32_t __stdcall GetCultureCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().GetCultureCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8>
    {
        int32_t __stdcall GetHeadingLevelCore(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel>(this->shim().GetHeadingLevelCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9>
    {
        int32_t __stdcall IsDialogCore(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsDialogCore());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected>
    {
        int32_t __stdcall PeerFromProvider(void* provider, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().PeerFromProvider(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Provider::IRawElementProviderSimple const*>(&provider)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ProviderFromPeer(void* peer, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Provider::IRawElementProviderSimple>(this->shim().ProviderFromPeer(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const*>(&peer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics>
    {
        int32_t __stdcall ListenerExists(int32_t eventId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().ListenerExists(*reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::AutomationEvents const*>(&eventId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics3> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics3>
    {
        int32_t __stdcall GenerateRawElementProviderRuntimeId(struct struct_Windows_UI_Xaml_Automation_Peers_RawElementProviderRuntimeId* result) noexcept final try
        {
            zero_abi<llm::OS::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId>(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId>(this->shim().GenerateRawElementProviderRuntimeId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Button const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::ButtonBase const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::CalendarDatePickerAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::CalendarDatePicker const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::CaptureElement const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::CheckBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ColorPickerSliderAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::ColorPickerSlider const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ColorSpectrumAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::ColorSpectrum const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ComboBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ComboBoxItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::DatePickerAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::DatePicker const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::FlipView const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::FlipViewItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::FlyoutPresenter const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer>
    {
        int32_t __stdcall get_Owner(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::UIElement>(this->shim().Owner());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::FrameworkElement const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics>
    {
        int32_t __stdcall FromElement(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().FromElement(*reinterpret_cast<llm::OS::UI::Xaml::UIElement const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreatePeerForElement(void* element, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>(this->shim().CreatePeerForElement(*reinterpret_cast<llm::OS::UI::Xaml::UIElement const*>(&element)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::GridView const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::GridViewHeaderItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::GridViewItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::GroupItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::GroupItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::HubAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Hub const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::HubSectionAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::HubSection const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::HyperlinkButton const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ImageAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Image const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer>
    {
        int32_t __stdcall get_Item(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Item());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ItemsControlAutomationPeer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer>(this->shim().ItemsControlAutomationPeer());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2>
    {
        int32_t __stdcall CreateItemAutomationPeer(void* item, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer>(this->shim().CreateItemAutomationPeer(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ItemsControl const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
    {
        int32_t __stdcall OnCreateItemAutomationPeer(void* item, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer>(this->shim().OnCreateItemAutomationPeer(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListBoxItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListViewAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListView const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListViewBase const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListViewBaseHeaderItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListViewHeaderItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ListViewItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMapControlAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMapControlAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MediaElementAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MediaElement const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MediaPlayerElement const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MediaTransportControls const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstance(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MenuBarAutomationPeer>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MenuBar const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstance(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MenuBarItemAutomationPeer>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MenuBarItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MenuFlyoutItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::MenuFlyoutPresenter const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::NavigationViewItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::NavigationViewItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::PasswordBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::PersonPictureAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::PersonPicture const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Pivot const*>(&owner)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::PivotItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::PivotItem const*>(&owner)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer const*>(&parent)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ProgressBar const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ProgressRing const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::RadioButton const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::RangeBase const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RatingControlAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::RatingControl const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::RepeatButton const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::RichEditBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::RichTextBlock const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::RichTextBlockOverflow const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::ScrollBar const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ScrollViewer const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::SearchBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::Selector const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithParentAndItem(void* item, void* parent, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer>(this->shim().CreateInstanceWithParentAndItem(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&item), *reinterpret_cast<llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer const*>(&parent), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::SemanticZoom const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::SettingsFlyout const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::SliderAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Slider const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::TextBlockAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::TextBlock const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::TextBoxAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::TextBox const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ThumbAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::Thumb const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::TimePickerAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::TimePicker const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::Primitives::ToggleButton const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ToggleMenuFlyoutItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::ToggleSwitch const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::TreeViewItemAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::TreeViewItem const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeer> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeer>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeerFactory> : produce_base<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeerFactory>
    {
        int32_t __stdcall CreateInstanceWithOwner(void* owner, void* baseInterface, void** innerInterface, void** value) noexcept final try
        {
            if (innerInterface) *innerInterface = nullptr;
            llm::OS::Foundation::IInspectable llm_impl_innerInterface;
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Xaml::Automation::Peers::TreeViewListAutomationPeer>(this->shim().CreateInstanceWithOwner(*reinterpret_cast<llm::OS::UI::Xaml::Controls::TreeViewList const*>(&owner), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&baseInterface), llm_impl_innerInterface));
                if (innerInterface) *innerInterface = detach_abi(llm_impl_innerInterface);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides>
{
    auto GetPatternCore(llm::OS::UI::Xaml::Automation::Peers::PatternInterface const& patternInterface)
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetPatternCore(patternInterface);
        }

        return this->shim().GetPatternCore(patternInterface);
    }
    auto GetAcceleratorKeyCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetAcceleratorKeyCore();
        }

        return this->shim().GetAcceleratorKeyCore();
    }
    auto GetAccessKeyCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetAccessKeyCore();
        }

        return this->shim().GetAccessKeyCore();
    }
    auto GetAutomationControlTypeCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetAutomationControlTypeCore();
        }

        return this->shim().GetAutomationControlTypeCore();
    }
    auto GetAutomationIdCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetAutomationIdCore();
        }

        return this->shim().GetAutomationIdCore();
    }
    auto GetBoundingRectangleCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetBoundingRectangleCore();
        }

        return this->shim().GetBoundingRectangleCore();
    }
    auto GetChildrenCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetChildrenCore();
        }

        return this->shim().GetChildrenCore();
    }
    auto GetClassNameCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetClassNameCore();
        }

        return this->shim().GetClassNameCore();
    }
    auto GetClickablePointCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetClickablePointCore();
        }

        return this->shim().GetClickablePointCore();
    }
    auto GetHelpTextCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetHelpTextCore();
        }

        return this->shim().GetHelpTextCore();
    }
    auto GetItemStatusCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetItemStatusCore();
        }

        return this->shim().GetItemStatusCore();
    }
    auto GetItemTypeCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetItemTypeCore();
        }

        return this->shim().GetItemTypeCore();
    }
    auto GetLabeledByCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetLabeledByCore();
        }

        return this->shim().GetLabeledByCore();
    }
    auto GetLocalizedControlTypeCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetLocalizedControlTypeCore();
        }

        return this->shim().GetLocalizedControlTypeCore();
    }
    auto GetNameCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetNameCore();
        }

        return this->shim().GetNameCore();
    }
    auto GetOrientationCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetOrientationCore();
        }

        return this->shim().GetOrientationCore();
    }
    auto HasKeyboardFocusCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.HasKeyboardFocusCore();
        }

        return this->shim().HasKeyboardFocusCore();
    }
    auto IsContentElementCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsContentElementCore();
        }

        return this->shim().IsContentElementCore();
    }
    auto IsControlElementCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsControlElementCore();
        }

        return this->shim().IsControlElementCore();
    }
    auto IsEnabledCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsEnabledCore();
        }

        return this->shim().IsEnabledCore();
    }
    auto IsKeyboardFocusableCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsKeyboardFocusableCore();
        }

        return this->shim().IsKeyboardFocusableCore();
    }
    auto IsOffscreenCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsOffscreenCore();
        }

        return this->shim().IsOffscreenCore();
    }
    auto IsPasswordCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsPasswordCore();
        }

        return this->shim().IsPasswordCore();
    }
    auto IsRequiredForFormCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsRequiredForFormCore();
        }

        return this->shim().IsRequiredForFormCore();
    }
    auto SetFocusCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.SetFocusCore();
        }

        return this->shim().SetFocusCore();
    }
    auto GetPeerFromPointCore(llm::OS::Foundation::Point const& point)
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetPeerFromPointCore(point);
        }

        return this->shim().GetPeerFromPointCore(point);
    }
    auto GetLiveSettingCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetLiveSettingCore();
        }

        return this->shim().GetLiveSettingCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2>
{
    auto ShowContextMenuCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.ShowContextMenuCore();
        }

        return this->shim().ShowContextMenuCore();
    }
    auto GetControlledPeersCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetControlledPeersCore();
        }

        return this->shim().GetControlledPeersCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3>
{
    auto NavigateCore(llm::OS::UI::Xaml::Automation::Peers::AutomationNavigationDirection const& direction)
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.NavigateCore(direction);
        }

        return this->shim().NavigateCore(direction);
    }
    auto GetElementFromPointCore(llm::OS::Foundation::Point const& pointInWindowCoordinates)
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetElementFromPointCore(pointInWindowCoordinates);
        }

        return this->shim().GetElementFromPointCore(pointInWindowCoordinates);
    }
    auto GetFocusedElementCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetFocusedElementCore();
        }

        return this->shim().GetFocusedElementCore();
    }
    auto GetAnnotationsCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetAnnotationsCore();
        }

        return this->shim().GetAnnotationsCore();
    }
    auto GetPositionInSetCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetPositionInSetCore();
        }

        return this->shim().GetPositionInSetCore();
    }
    auto GetSizeOfSetCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetSizeOfSetCore();
        }

        return this->shim().GetSizeOfSetCore();
    }
    auto GetLevelCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetLevelCore();
        }

        return this->shim().GetLevelCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4>
{
    auto GetLandmarkTypeCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetLandmarkTypeCore();
        }

        return this->shim().GetLandmarkTypeCore();
    }
    auto GetLocalizedLandmarkTypeCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetLocalizedLandmarkTypeCore();
        }

        return this->shim().GetLocalizedLandmarkTypeCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5>
{
    auto IsPeripheralCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsPeripheralCore();
        }

        return this->shim().IsPeripheralCore();
    }
    auto IsDataValidForFormCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsDataValidForFormCore();
        }

        return this->shim().IsDataValidForFormCore();
    }
    auto GetFullDescriptionCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetFullDescriptionCore();
        }

        return this->shim().GetFullDescriptionCore();
    }
    auto GetDescribedByCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetDescribedByCore();
        }

        return this->shim().GetDescribedByCore();
    }
    auto GetFlowsToCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetFlowsToCore();
        }

        return this->shim().GetFlowsToCore();
    }
    auto GetFlowsFromCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetFlowsFromCore();
        }

        return this->shim().GetFlowsFromCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6>
{
    auto GetCultureCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetCultureCore();
        }

        return this->shim().GetCultureCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8>
{
    auto GetHeadingLevelCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.GetHeadingLevelCore();
        }

        return this->shim().GetHeadingLevelCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9>
{
    auto IsDialogCore()
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.IsDialogCore();
        }

        return this->shim().IsDialogCore();
    }
};
template <typename T, typename D>
struct __declspec(empty_bases) produce_dispatch_to_overridable<T, D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
    : produce_dispatch_to_overridable_base<T, D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2>
{
    auto OnCreateItemAutomationPeer(llm::OS::Foundation::IInspectable const& item)
    {
        if (auto overridable = this->shim_overridable())
        {
            return overridable.OnCreateItemAutomationPeer(item);
        }

        return this->shim().OnCreateItemAutomationPeer(item);
    }
};
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Automation::Peers
{
    inline AppBarAutomationPeer::AppBarAutomationPeer(llm::OS::UI::Xaml::Controls::AppBar const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>([&](IAppBarAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline AppBarButtonAutomationPeer::AppBarButtonAutomationPeer(llm::OS::UI::Xaml::Controls::AppBarButton const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>([&](IAppBarButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline AppBarToggleButtonAutomationPeer::AppBarToggleButtonAutomationPeer(llm::OS::UI::Xaml::Controls::AppBarToggleButton const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>([&](IAppBarToggleButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline AutoSuggestBoxAutomationPeer::AutoSuggestBoxAutomationPeer(llm::OS::UI::Xaml::Controls::AutoSuggestBox const& owner) :
        AutoSuggestBoxAutomationPeer(impl::call_factory<AutoSuggestBoxAutomationPeer, IAutoSuggestBoxAutomationPeerFactory>([&](IAutoSuggestBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner); }))
    {
    }
    inline auto AutomationPeer::ListenerExists(llm::OS::UI::Xaml::Automation::Peers::AutomationEvents const& eventId)
    {
        return impl::call_factory<AutomationPeer, IAutomationPeerStatics>([&](IAutomationPeerStatics const& f) { return f.ListenerExists(eventId); });
    }
    inline auto AutomationPeer::GenerateRawElementProviderRuntimeId()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::Automation::Peers::RawElementProviderRuntimeId(*)(IAutomationPeerStatics3 const&), AutomationPeer, IAutomationPeerStatics3>([](IAutomationPeerStatics3 const& f) { return f.GenerateRawElementProviderRuntimeId(); });
    }
    inline AutomationPeerAnnotation::AutomationPeerAnnotation() :
        AutomationPeerAnnotation(impl::call_factory_cast<AutomationPeerAnnotation(*)(llm::OS::Foundation::IActivationFactory const&), AutomationPeerAnnotation>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<AutomationPeerAnnotation>(); }))
    {
    }
    inline AutomationPeerAnnotation::AutomationPeerAnnotation(llm::OS::UI::Xaml::Automation::AnnotationType const& type) :
        AutomationPeerAnnotation(impl::call_factory<AutomationPeerAnnotation, IAutomationPeerAnnotationFactory>([&](IAutomationPeerAnnotationFactory const& f) { return f.CreateInstance(type); }))
    {
    }
    inline AutomationPeerAnnotation::AutomationPeerAnnotation(llm::OS::UI::Xaml::Automation::AnnotationType const& type, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer const& peer) :
        AutomationPeerAnnotation(impl::call_factory<AutomationPeerAnnotation, IAutomationPeerAnnotationFactory>([&](IAutomationPeerAnnotationFactory const& f) { return f.CreateWithPeerParameter(type, peer); }))
    {
    }
    inline auto AutomationPeerAnnotation::TypeProperty()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::DependencyProperty(*)(IAutomationPeerAnnotationStatics const&), AutomationPeerAnnotation, IAutomationPeerAnnotationStatics>([](IAutomationPeerAnnotationStatics const& f) { return f.TypeProperty(); });
    }
    inline auto AutomationPeerAnnotation::PeerProperty()
    {
        return impl::call_factory_cast<llm::OS::UI::Xaml::DependencyProperty(*)(IAutomationPeerAnnotationStatics const&), AutomationPeerAnnotation, IAutomationPeerAnnotationStatics>([](IAutomationPeerAnnotationStatics const& f) { return f.PeerProperty(); });
    }
    inline ButtonAutomationPeer::ButtonAutomationPeer(llm::OS::UI::Xaml::Controls::Button const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ButtonAutomationPeer, IButtonAutomationPeerFactory>([&](IButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline CalendarDatePickerAutomationPeer::CalendarDatePickerAutomationPeer(llm::OS::UI::Xaml::Controls::CalendarDatePicker const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<CalendarDatePickerAutomationPeer, ICalendarDatePickerAutomationPeerFactory>([&](ICalendarDatePickerAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline CaptureElementAutomationPeer::CaptureElementAutomationPeer(llm::OS::UI::Xaml::Controls::CaptureElement const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>([&](ICaptureElementAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline CheckBoxAutomationPeer::CheckBoxAutomationPeer(llm::OS::UI::Xaml::Controls::CheckBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>([&](ICheckBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ColorPickerSliderAutomationPeer::ColorPickerSliderAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::ColorPickerSlider const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ColorPickerSliderAutomationPeer, IColorPickerSliderAutomationPeerFactory>([&](IColorPickerSliderAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ColorSpectrumAutomationPeer::ColorSpectrumAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::ColorSpectrum const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ColorSpectrumAutomationPeer, IColorSpectrumAutomationPeerFactory>([&](IColorSpectrumAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ComboBoxAutomationPeer::ComboBoxAutomationPeer(llm::OS::UI::Xaml::Controls::ComboBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>([&](IComboBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ComboBoxItemAutomationPeer::ComboBoxItemAutomationPeer(llm::OS::UI::Xaml::Controls::ComboBoxItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>([&](IComboBoxItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ComboBoxItemDataAutomationPeer::ComboBoxItemDataAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>([&](IComboBoxItemDataAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline DatePickerAutomationPeer::DatePickerAutomationPeer(llm::OS::UI::Xaml::Controls::DatePicker const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>([&](IDatePickerAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline FlipViewAutomationPeer::FlipViewAutomationPeer(llm::OS::UI::Xaml::Controls::FlipView const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>([&](IFlipViewAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline FlipViewItemAutomationPeer::FlipViewItemAutomationPeer(llm::OS::UI::Xaml::Controls::FlipViewItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>([&](IFlipViewItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline FlipViewItemDataAutomationPeer::FlipViewItemDataAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>([&](IFlipViewItemDataAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline FlyoutPresenterAutomationPeer::FlyoutPresenterAutomationPeer(llm::OS::UI::Xaml::Controls::FlyoutPresenter const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>([&](IFlyoutPresenterAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline FrameworkElementAutomationPeer::FrameworkElementAutomationPeer(llm::OS::UI::Xaml::FrameworkElement const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>([&](IFrameworkElementAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline auto FrameworkElementAutomationPeer::FromElement(llm::OS::UI::Xaml::UIElement const& element)
    {
        return impl::call_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerStatics>([&](IFrameworkElementAutomationPeerStatics const& f) { return f.FromElement(element); });
    }
    inline auto FrameworkElementAutomationPeer::CreatePeerForElement(llm::OS::UI::Xaml::UIElement const& element)
    {
        return impl::call_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerStatics>([&](IFrameworkElementAutomationPeerStatics const& f) { return f.CreatePeerForElement(element); });
    }
    inline GridViewAutomationPeer::GridViewAutomationPeer(llm::OS::UI::Xaml::Controls::GridView const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>([&](IGridViewAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline GridViewHeaderItemAutomationPeer::GridViewHeaderItemAutomationPeer(llm::OS::UI::Xaml::Controls::GridViewHeaderItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>([&](IGridViewHeaderItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline GridViewItemAutomationPeer::GridViewItemAutomationPeer(llm::OS::UI::Xaml::Controls::GridViewItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>([&](IGridViewItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline GridViewItemDataAutomationPeer::GridViewItemDataAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>([&](IGridViewItemDataAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline GroupItemAutomationPeer::GroupItemAutomationPeer(llm::OS::UI::Xaml::Controls::GroupItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>([&](IGroupItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline HubAutomationPeer::HubAutomationPeer(llm::OS::UI::Xaml::Controls::Hub const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<HubAutomationPeer, IHubAutomationPeerFactory>([&](IHubAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline HubSectionAutomationPeer::HubSectionAutomationPeer(llm::OS::UI::Xaml::Controls::HubSection const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>([&](IHubSectionAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline HyperlinkButtonAutomationPeer::HyperlinkButtonAutomationPeer(llm::OS::UI::Xaml::Controls::HyperlinkButton const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>([&](IHyperlinkButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ImageAutomationPeer::ImageAutomationPeer(llm::OS::UI::Xaml::Controls::Image const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ImageAutomationPeer, IImageAutomationPeerFactory>([&](IImageAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ItemAutomationPeer::ItemAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ItemAutomationPeer, IItemAutomationPeerFactory>([&](IItemAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline ItemsControlAutomationPeer::ItemsControlAutomationPeer(llm::OS::UI::Xaml::Controls::ItemsControl const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>([&](IItemsControlAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListBoxAutomationPeer::ListBoxAutomationPeer(llm::OS::UI::Xaml::Controls::ListBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>([&](IListBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListBoxItemAutomationPeer::ListBoxItemAutomationPeer(llm::OS::UI::Xaml::Controls::ListBoxItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>([&](IListBoxItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListBoxItemDataAutomationPeer::ListBoxItemDataAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>([&](IListBoxItemDataAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline ListViewAutomationPeer::ListViewAutomationPeer(llm::OS::UI::Xaml::Controls::ListView const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListViewAutomationPeer, IListViewAutomationPeerFactory>([&](IListViewAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListViewBaseAutomationPeer::ListViewBaseAutomationPeer(llm::OS::UI::Xaml::Controls::ListViewBase const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>([&](IListViewBaseAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListViewHeaderItemAutomationPeer::ListViewHeaderItemAutomationPeer(llm::OS::UI::Xaml::Controls::ListViewHeaderItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>([&](IListViewHeaderItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListViewItemAutomationPeer::ListViewItemAutomationPeer(llm::OS::UI::Xaml::Controls::ListViewItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>([&](IListViewItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ListViewItemDataAutomationPeer::ListViewItemDataAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>([&](IListViewItemDataAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline MediaElementAutomationPeer::MediaElementAutomationPeer(llm::OS::UI::Xaml::Controls::MediaElement const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>([&](IMediaElementAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline MediaPlayerElementAutomationPeer::MediaPlayerElementAutomationPeer(llm::OS::UI::Xaml::Controls::MediaPlayerElement const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MediaPlayerElementAutomationPeer, IMediaPlayerElementAutomationPeerFactory>([&](IMediaPlayerElementAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline MediaTransportControlsAutomationPeer::MediaTransportControlsAutomationPeer(llm::OS::UI::Xaml::Controls::MediaTransportControls const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>([&](IMediaTransportControlsAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline MenuBarAutomationPeer::MenuBarAutomationPeer(llm::OS::UI::Xaml::Controls::MenuBar const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MenuBarAutomationPeer, IMenuBarAutomationPeerFactory>([&](IMenuBarAutomationPeerFactory const& f) { return f.CreateInstance(owner, baseInterface, innerInterface); });
    }
    inline MenuBarItemAutomationPeer::MenuBarItemAutomationPeer(llm::OS::UI::Xaml::Controls::MenuBarItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MenuBarItemAutomationPeer, IMenuBarItemAutomationPeerFactory>([&](IMenuBarItemAutomationPeerFactory const& f) { return f.CreateInstance(owner, baseInterface, innerInterface); });
    }
    inline MenuFlyoutItemAutomationPeer::MenuFlyoutItemAutomationPeer(llm::OS::UI::Xaml::Controls::MenuFlyoutItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>([&](IMenuFlyoutItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline MenuFlyoutPresenterAutomationPeer::MenuFlyoutPresenterAutomationPeer(llm::OS::UI::Xaml::Controls::MenuFlyoutPresenter const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>([&](IMenuFlyoutPresenterAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline NavigationViewItemAutomationPeer::NavigationViewItemAutomationPeer(llm::OS::UI::Xaml::Controls::NavigationViewItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<NavigationViewItemAutomationPeer, INavigationViewItemAutomationPeerFactory>([&](INavigationViewItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline PasswordBoxAutomationPeer::PasswordBoxAutomationPeer(llm::OS::UI::Xaml::Controls::PasswordBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>([&](IPasswordBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline PersonPictureAutomationPeer::PersonPictureAutomationPeer(llm::OS::UI::Xaml::Controls::PersonPicture const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<PersonPictureAutomationPeer, IPersonPictureAutomationPeerFactory>([&](IPersonPictureAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline PivotAutomationPeer::PivotAutomationPeer(llm::OS::UI::Xaml::Controls::Pivot const& owner) :
        PivotAutomationPeer(impl::call_factory<PivotAutomationPeer, IPivotAutomationPeerFactory>([&](IPivotAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner); }))
    {
    }
    inline PivotItemAutomationPeer::PivotItemAutomationPeer(llm::OS::UI::Xaml::Controls::PivotItem const& owner) :
        PivotItemAutomationPeer(impl::call_factory<PivotItemAutomationPeer, IPivotItemAutomationPeerFactory>([&](IPivotItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner); }))
    {
    }
    inline PivotItemDataAutomationPeer::PivotItemDataAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer const& parent) :
        PivotItemDataAutomationPeer(impl::call_factory<PivotItemDataAutomationPeer, IPivotItemDataAutomationPeerFactory>([&](IPivotItemDataAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent); }))
    {
    }
    inline ProgressBarAutomationPeer::ProgressBarAutomationPeer(llm::OS::UI::Xaml::Controls::ProgressBar const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>([&](IProgressBarAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ProgressRingAutomationPeer::ProgressRingAutomationPeer(llm::OS::UI::Xaml::Controls::ProgressRing const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>([&](IProgressRingAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RadioButtonAutomationPeer::RadioButtonAutomationPeer(llm::OS::UI::Xaml::Controls::RadioButton const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>([&](IRadioButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RangeBaseAutomationPeer::RangeBaseAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::RangeBase const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>([&](IRangeBaseAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RatingControlAutomationPeer::RatingControlAutomationPeer(llm::OS::UI::Xaml::Controls::RatingControl const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RatingControlAutomationPeer, IRatingControlAutomationPeerFactory>([&](IRatingControlAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RepeatButtonAutomationPeer::RepeatButtonAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::RepeatButton const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>([&](IRepeatButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RichEditBoxAutomationPeer::RichEditBoxAutomationPeer(llm::OS::UI::Xaml::Controls::RichEditBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>([&](IRichEditBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RichTextBlockAutomationPeer::RichTextBlockAutomationPeer(llm::OS::UI::Xaml::Controls::RichTextBlock const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>([&](IRichTextBlockAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline RichTextBlockOverflowAutomationPeer::RichTextBlockOverflowAutomationPeer(llm::OS::UI::Xaml::Controls::RichTextBlockOverflow const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>([&](IRichTextBlockOverflowAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ScrollBarAutomationPeer::ScrollBarAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::ScrollBar const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>([&](IScrollBarAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ScrollViewerAutomationPeer::ScrollViewerAutomationPeer(llm::OS::UI::Xaml::Controls::ScrollViewer const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>([&](IScrollViewerAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline SearchBoxAutomationPeer::SearchBoxAutomationPeer(llm::OS::UI::Xaml::Controls::SearchBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>([&](ISearchBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline SelectorAutomationPeer::SelectorAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::Selector const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>([&](ISelectorAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline SelectorItemAutomationPeer::SelectorItemAutomationPeer(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer const& parent)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>([&](ISelectorItemAutomationPeerFactory const& f) { return f.CreateInstanceWithParentAndItem(item, parent, baseInterface, innerInterface); });
    }
    inline SemanticZoomAutomationPeer::SemanticZoomAutomationPeer(llm::OS::UI::Xaml::Controls::SemanticZoom const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>([&](ISemanticZoomAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline SettingsFlyoutAutomationPeer::SettingsFlyoutAutomationPeer(llm::OS::UI::Xaml::Controls::SettingsFlyout const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>([&](ISettingsFlyoutAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline SliderAutomationPeer::SliderAutomationPeer(llm::OS::UI::Xaml::Controls::Slider const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<SliderAutomationPeer, ISliderAutomationPeerFactory>([&](ISliderAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline TextBlockAutomationPeer::TextBlockAutomationPeer(llm::OS::UI::Xaml::Controls::TextBlock const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>([&](ITextBlockAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline TextBoxAutomationPeer::TextBoxAutomationPeer(llm::OS::UI::Xaml::Controls::TextBox const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>([&](ITextBoxAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ThumbAutomationPeer::ThumbAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::Thumb const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ThumbAutomationPeer, IThumbAutomationPeerFactory>([&](IThumbAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline TimePickerAutomationPeer::TimePickerAutomationPeer(llm::OS::UI::Xaml::Controls::TimePicker const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>([&](ITimePickerAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ToggleButtonAutomationPeer::ToggleButtonAutomationPeer(llm::OS::UI::Xaml::Controls::Primitives::ToggleButton const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>([&](IToggleButtonAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ToggleMenuFlyoutItemAutomationPeer::ToggleMenuFlyoutItemAutomationPeer(llm::OS::UI::Xaml::Controls::ToggleMenuFlyoutItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>([&](IToggleMenuFlyoutItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline ToggleSwitchAutomationPeer::ToggleSwitchAutomationPeer(llm::OS::UI::Xaml::Controls::ToggleSwitch const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<ToggleSwitchAutomationPeer, IToggleSwitchAutomationPeerFactory>([&](IToggleSwitchAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline TreeViewItemAutomationPeer::TreeViewItemAutomationPeer(llm::OS::UI::Xaml::Controls::TreeViewItem const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<TreeViewItemAutomationPeer, ITreeViewItemAutomationPeerFactory>([&](ITreeViewItemAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    inline TreeViewListAutomationPeer::TreeViewListAutomationPeer(llm::OS::UI::Xaml::Controls::TreeViewList const& owner)
    {
        llm::OS::Foundation::IInspectable baseInterface, innerInterface;
        *this = impl::call_factory<TreeViewListAutomationPeer, ITreeViewListAutomationPeerFactory>([&](ITreeViewListAutomationPeerFactory const& f) { return f.CreateInstanceWithOwner(owner, baseInterface, innerInterface); });
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) IAutomationPeerOverridesT<D>::GetPatternCore(llm::OS::UI::Xaml::Automation::Peers::PatternInterface const& patternInterface) const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetPatternCore(patternInterface);
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetAcceleratorKeyCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetAcceleratorKeyCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetAccessKeyCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetAccessKeyCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationControlType) IAutomationPeerOverridesT<D>::GetAutomationControlTypeCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetAutomationControlTypeCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetAutomationIdCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetAutomationIdCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) IAutomationPeerOverridesT<D>::GetBoundingRectangleCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetBoundingRectangleCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) IAutomationPeerOverridesT<D>::GetChildrenCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetChildrenCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetClassNameCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetClassNameCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Point) IAutomationPeerOverridesT<D>::GetClickablePointCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetClickablePointCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetHelpTextCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetHelpTextCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetItemStatusCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetItemStatusCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetItemTypeCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetItemTypeCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) IAutomationPeerOverridesT<D>::GetLabeledByCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetLabeledByCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetLocalizedControlTypeCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetLocalizedControlTypeCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverridesT<D>::GetNameCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetNameCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationOrientation) IAutomationPeerOverridesT<D>::GetOrientationCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetOrientationCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::HasKeyboardFocusCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().HasKeyboardFocusCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsContentElementCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsContentElementCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsControlElementCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsControlElementCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsEnabledCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsEnabledCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsKeyboardFocusableCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsKeyboardFocusableCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsOffscreenCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsOffscreenCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsPasswordCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsPasswordCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverridesT<D>::IsRequiredForFormCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().IsRequiredForFormCore();
    }
    template <typename D> LLM_IMPL_AUTO(void) IAutomationPeerOverridesT<D>::SetFocusCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().SetFocusCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationPeer) IAutomationPeerOverridesT<D>::GetPeerFromPointCore(llm::OS::Foundation::Point const& point) const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetPeerFromPointCore(point);
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationLiveSetting) IAutomationPeerOverridesT<D>::GetLiveSettingCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides>().GetLiveSettingCore();
    }
    template <typename D> LLM_IMPL_AUTO(void) IAutomationPeerOverrides2T<D>::ShowContextMenuCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides2>().ShowContextMenuCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) IAutomationPeerOverrides2T<D>::GetControlledPeersCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides2>().GetControlledPeersCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) IAutomationPeerOverrides3T<D>::NavigateCore(llm::OS::UI::Xaml::Automation::Peers::AutomationNavigationDirection const& direction) const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().NavigateCore(direction);
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) IAutomationPeerOverrides3T<D>::GetElementFromPointCore(llm::OS::Foundation::Point const& pointInWindowCoordinates) const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().GetElementFromPointCore(pointInWindowCoordinates);
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) IAutomationPeerOverrides3T<D>::GetFocusedElementCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().GetFocusedElementCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation>) IAutomationPeerOverrides3T<D>::GetAnnotationsCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().GetAnnotationsCore();
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) IAutomationPeerOverrides3T<D>::GetPositionInSetCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().GetPositionInSetCore();
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) IAutomationPeerOverrides3T<D>::GetSizeOfSetCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().GetSizeOfSetCore();
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) IAutomationPeerOverrides3T<D>::GetLevelCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides3>().GetLevelCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationLandmarkType) IAutomationPeerOverrides4T<D>::GetLandmarkTypeCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides4>().GetLandmarkTypeCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverrides4T<D>::GetLocalizedLandmarkTypeCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides4>().GetLocalizedLandmarkTypeCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverrides5T<D>::IsPeripheralCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides5>().IsPeripheralCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverrides5T<D>::IsDataValidForFormCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides5>().IsDataValidForFormCore();
    }
    template <typename D> LLM_IMPL_AUTO(hstring) IAutomationPeerOverrides5T<D>::GetFullDescriptionCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides5>().GetFullDescriptionCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) IAutomationPeerOverrides5T<D>::GetDescribedByCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides5>().GetDescribedByCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) IAutomationPeerOverrides5T<D>::GetFlowsToCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides5>().GetFlowsToCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IIterable<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer>) IAutomationPeerOverrides5T<D>::GetFlowsFromCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides5>().GetFlowsFromCore();
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) IAutomationPeerOverrides6T<D>::GetCultureCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides6>().GetCultureCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::AutomationHeadingLevel) IAutomationPeerOverrides8T<D>::GetHeadingLevelCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides8>().GetHeadingLevelCore();
    }
    template <typename D> LLM_IMPL_AUTO(bool) IAutomationPeerOverrides9T<D>::IsDialogCore() const
    {
        return shim().template try_as<IAutomationPeerOverrides9>().IsDialogCore();
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer) IItemsControlAutomationPeerOverrides2T<D>::OnCreateItemAutomationPeer(llm::OS::Foundation::IInspectable const& item) const
    {
        return shim().template try_as<IItemsControlAutomationPeerOverrides2>().OnCreateItemAutomationPeer(item);
    }
    template <typename D, typename... Interfaces>
    struct AppBarAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Provider::IExpandCollapseProvider, llm::OS::UI::Xaml::Automation::Provider::IWindowProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, AppBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = AppBarAutomationPeer;
    protected:
        AppBarAutomationPeerT(llm::OS::UI::Xaml::Controls::AppBar const& owner)
        {
            impl::call_factory<AppBarAutomationPeer, IAppBarAutomationPeerFactory>([&](IAppBarAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct AppBarButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IExpandCollapseProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, AppBarButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = AppBarButtonAutomationPeer;
    protected:
        AppBarButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::AppBarButton const& owner)
        {
            impl::call_factory<AppBarButtonAutomationPeer, IAppBarButtonAutomationPeerFactory>([&](IAppBarButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct AppBarToggleButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, AppBarToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = AppBarToggleButtonAutomationPeer;
    protected:
        AppBarToggleButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::AppBarToggleButton const& owner)
        {
            impl::call_factory<AppBarToggleButtonAutomationPeer, IAppBarToggleButtonAutomationPeerFactory>([&](IAppBarToggleButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct AutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = AutomationPeer;
    protected:
        AutomationPeerT()
        {
            impl::call_factory<AutomationPeer, IAutomationPeerFactory>([&](IAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(*this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ButtonAutomationPeer;
    protected:
        ButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::Button const& owner)
        {
            impl::call_factory<ButtonAutomationPeer, IButtonAutomationPeerFactory>([&](IButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ButtonBaseAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ButtonBaseAutomationPeer;
    protected:
        ButtonBaseAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::ButtonBase const& owner)
        {
            impl::call_factory<ButtonBaseAutomationPeer, IButtonBaseAutomationPeerFactory>([&](IButtonBaseAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct CalendarDatePickerAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Provider::IValueProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, CalendarDatePickerAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = CalendarDatePickerAutomationPeer;
    protected:
        CalendarDatePickerAutomationPeerT(llm::OS::UI::Xaml::Controls::CalendarDatePicker const& owner)
        {
            impl::call_factory<CalendarDatePickerAutomationPeer, ICalendarDatePickerAutomationPeerFactory>([&](ICalendarDatePickerAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct CaptureElementAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, CaptureElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = CaptureElementAutomationPeer;
    protected:
        CaptureElementAutomationPeerT(llm::OS::UI::Xaml::Controls::CaptureElement const& owner)
        {
            impl::call_factory<CaptureElementAutomationPeer, ICaptureElementAutomationPeerFactory>([&](ICaptureElementAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct CheckBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, CheckBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = CheckBoxAutomationPeer;
    protected:
        CheckBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::CheckBox const& owner)
        {
            impl::call_factory<CheckBoxAutomationPeer, ICheckBoxAutomationPeerFactory>([&](ICheckBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ColorPickerSliderAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ColorPickerSliderAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SliderAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ColorPickerSliderAutomationPeer;
    protected:
        ColorPickerSliderAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::ColorPickerSlider const& owner)
        {
            impl::call_factory<ColorPickerSliderAutomationPeer, IColorPickerSliderAutomationPeerFactory>([&](IColorPickerSliderAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct ColorSpectrumAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ColorSpectrumAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ColorSpectrumAutomationPeer;
    protected:
        ColorSpectrumAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::ColorSpectrum const& owner)
        {
            impl::call_factory<ColorSpectrumAutomationPeer, IColorSpectrumAutomationPeerFactory>([&](IColorSpectrumAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ComboBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IValueProvider, llm::OS::UI::Xaml::Automation::Provider::IExpandCollapseProvider, llm::OS::UI::Xaml::Automation::Provider::IWindowProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ComboBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ComboBoxAutomationPeer;
    protected:
        ComboBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::ComboBox const& owner)
        {
            impl::call_factory<ComboBoxAutomationPeer, IComboBoxAutomationPeerFactory>([&](IComboBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct ComboBoxItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ComboBoxItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ComboBoxItemAutomationPeer;
    protected:
        ComboBoxItemAutomationPeerT(llm::OS::UI::Xaml::Controls::ComboBoxItem const& owner)
        {
            impl::call_factory<ComboBoxItemAutomationPeer, IComboBoxItemAutomationPeerFactory>([&](IComboBoxItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ComboBoxItemDataAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollItemProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ComboBoxItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ComboBoxItemDataAutomationPeer;
    protected:
        ComboBoxItemDataAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer const& parent)
        {
            impl::call_factory<ComboBoxItemDataAutomationPeer, IComboBoxItemDataAutomationPeerFactory>([&](IComboBoxItemDataAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct DatePickerAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, DatePickerAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = DatePickerAutomationPeer;
    protected:
        DatePickerAutomationPeerT(llm::OS::UI::Xaml::Controls::DatePicker const& owner)
        {
            impl::call_factory<DatePickerAutomationPeer, IDatePickerAutomationPeerFactory>([&](IDatePickerAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct FlipViewAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, FlipViewAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = FlipViewAutomationPeer;
    protected:
        FlipViewAutomationPeerT(llm::OS::UI::Xaml::Controls::FlipView const& owner)
        {
            impl::call_factory<FlipViewAutomationPeer, IFlipViewAutomationPeerFactory>([&](IFlipViewAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct FlipViewItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, FlipViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = FlipViewItemAutomationPeer;
    protected:
        FlipViewItemAutomationPeerT(llm::OS::UI::Xaml::Controls::FlipViewItem const& owner)
        {
            impl::call_factory<FlipViewItemAutomationPeer, IFlipViewItemAutomationPeerFactory>([&](IFlipViewItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct FlipViewItemDataAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollItemProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, FlipViewItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = FlipViewItemDataAutomationPeer;
    protected:
        FlipViewItemDataAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer const& parent)
        {
            impl::call_factory<FlipViewItemDataAutomationPeer, IFlipViewItemDataAutomationPeerFactory>([&](IFlipViewItemDataAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct FlyoutPresenterAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, FlyoutPresenterAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = FlyoutPresenterAutomationPeer;
    protected:
        FlyoutPresenterAutomationPeerT(llm::OS::UI::Xaml::Controls::FlyoutPresenter const& owner)
        {
            impl::call_factory<FlyoutPresenterAutomationPeer, IFlyoutPresenterAutomationPeerFactory>([&](IFlyoutPresenterAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct FrameworkElementAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = FrameworkElementAutomationPeer;
    protected:
        FrameworkElementAutomationPeerT(llm::OS::UI::Xaml::FrameworkElement const& owner)
        {
            impl::call_factory<FrameworkElementAutomationPeer, IFrameworkElementAutomationPeerFactory>([&](IFrameworkElementAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct GridViewAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IDropTargetProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, GridViewAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = GridViewAutomationPeer;
    protected:
        GridViewAutomationPeerT(llm::OS::UI::Xaml::Controls::GridView const& owner)
        {
            impl::call_factory<GridViewAutomationPeer, IGridViewAutomationPeerFactory>([&](IGridViewAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct GridViewHeaderItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, GridViewHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = GridViewHeaderItemAutomationPeer;
    protected:
        GridViewHeaderItemAutomationPeerT(llm::OS::UI::Xaml::Controls::GridViewHeaderItem const& owner)
        {
            impl::call_factory<GridViewHeaderItemAutomationPeer, IGridViewHeaderItemAutomationPeerFactory>([&](IGridViewHeaderItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct GridViewItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, GridViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = GridViewItemAutomationPeer;
    protected:
        GridViewItemAutomationPeerT(llm::OS::UI::Xaml::Controls::GridViewItem const& owner)
        {
            impl::call_factory<GridViewItemAutomationPeer, IGridViewItemAutomationPeerFactory>([&](IGridViewItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct GridViewItemDataAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollItemProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, GridViewItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = GridViewItemDataAutomationPeer;
    protected:
        GridViewItemDataAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer const& parent)
        {
            impl::call_factory<GridViewItemDataAutomationPeer, IGridViewItemDataAutomationPeerFactory>([&](IGridViewItemDataAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct GroupItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, GroupItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = GroupItemAutomationPeer;
    protected:
        GroupItemAutomationPeerT(llm::OS::UI::Xaml::Controls::GroupItem const& owner)
        {
            impl::call_factory<GroupItemAutomationPeer, IGroupItemAutomationPeerFactory>([&](IGroupItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct HubAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, HubAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = HubAutomationPeer;
    protected:
        HubAutomationPeerT(llm::OS::UI::Xaml::Controls::Hub const& owner)
        {
            impl::call_factory<HubAutomationPeer, IHubAutomationPeerFactory>([&](IHubAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct HubSectionAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollItemProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, HubSectionAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = HubSectionAutomationPeer;
    protected:
        HubSectionAutomationPeerT(llm::OS::UI::Xaml::Controls::HubSection const& owner)
        {
            impl::call_factory<HubSectionAutomationPeer, IHubSectionAutomationPeerFactory>([&](IHubSectionAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct HyperlinkButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, HyperlinkButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = HyperlinkButtonAutomationPeer;
    protected:
        HyperlinkButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::HyperlinkButton const& owner)
        {
            impl::call_factory<HyperlinkButtonAutomationPeer, IHyperlinkButtonAutomationPeerFactory>([&](IHyperlinkButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ImageAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ImageAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ImageAutomationPeer;
    protected:
        ImageAutomationPeerT(llm::OS::UI::Xaml::Controls::Image const& owner)
        {
            impl::call_factory<ImageAutomationPeer, IImageAutomationPeerFactory>([&](IImageAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ItemAutomationPeer;
    protected:
        ItemAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer const& parent)
        {
            impl::call_factory<ItemAutomationPeer, IItemAutomationPeerFactory>([&](IItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ItemsControlAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ItemsControlAutomationPeer;
    protected:
        ItemsControlAutomationPeerT(llm::OS::UI::Xaml::Controls::ItemsControl const& owner)
        {
            impl::call_factory<ItemsControlAutomationPeer, IItemsControlAutomationPeerFactory>([&](IItemsControlAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListBoxAutomationPeer;
    protected:
        ListBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::ListBox const& owner)
        {
            impl::call_factory<ListBoxAutomationPeer, IListBoxAutomationPeerFactory>([&](IListBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListBoxItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListBoxItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListBoxItemAutomationPeer;
    protected:
        ListBoxItemAutomationPeerT(llm::OS::UI::Xaml::Controls::ListBoxItem const& owner)
        {
            impl::call_factory<ListBoxItemAutomationPeer, IListBoxItemAutomationPeerFactory>([&](IListBoxItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListBoxItemDataAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollItemProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListBoxItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListBoxItemDataAutomationPeer;
    protected:
        ListBoxItemDataAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer const& parent)
        {
            impl::call_factory<ListBoxItemDataAutomationPeer, IListBoxItemDataAutomationPeerFactory>([&](IListBoxItemDataAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListViewAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IDropTargetProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListViewAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListViewAutomationPeer;
    protected:
        ListViewAutomationPeerT(llm::OS::UI::Xaml::Controls::ListView const& owner)
        {
            impl::call_factory<ListViewAutomationPeer, IListViewAutomationPeerFactory>([&](IListViewAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListViewBaseAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IDropTargetProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListViewBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListViewBaseAutomationPeer;
    protected:
        ListViewBaseAutomationPeerT(llm::OS::UI::Xaml::Controls::ListViewBase const& owner)
        {
            impl::call_factory<ListViewBaseAutomationPeer, IListViewBaseAutomationPeerFactory>([&](IListViewBaseAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListViewBaseHeaderItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListViewBaseHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListViewBaseHeaderItemAutomationPeer;
    protected:
        ListViewBaseHeaderItemAutomationPeerT(llm::OS::UI::Xaml::Controls::ListViewBaseHeaderItem const& owner)
        {
            impl::call_factory<ListViewBaseHeaderItemAutomationPeer, IListViewBaseHeaderItemAutomationPeerFactory>([&](IListViewBaseHeaderItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListViewHeaderItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListViewHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListViewHeaderItemAutomationPeer;
    protected:
        ListViewHeaderItemAutomationPeerT(llm::OS::UI::Xaml::Controls::ListViewHeaderItem const& owner)
        {
            impl::call_factory<ListViewHeaderItemAutomationPeer, IListViewHeaderItemAutomationPeerFactory>([&](IListViewHeaderItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListViewItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListViewItemAutomationPeer;
    protected:
        ListViewItemAutomationPeerT(llm::OS::UI::Xaml::Controls::ListViewItem const& owner)
        {
            impl::call_factory<ListViewItemAutomationPeer, IListViewItemAutomationPeerFactory>([&](IListViewItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ListViewItemDataAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollItemProvider, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ListViewItemDataAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ListViewItemDataAutomationPeer;
    protected:
        ListViewItemDataAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer const& parent)
        {
            impl::call_factory<ListViewItemDataAutomationPeer, IListViewItemDataAutomationPeerFactory>([&](IListViewItemDataAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MediaElementAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MediaElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MediaElementAutomationPeer;
    protected:
        MediaElementAutomationPeerT(llm::OS::UI::Xaml::Controls::MediaElement const& owner)
        {
            impl::call_factory<MediaElementAutomationPeer, IMediaElementAutomationPeerFactory>([&](IMediaElementAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MediaPlayerElementAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MediaPlayerElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MediaPlayerElementAutomationPeer;
    protected:
        MediaPlayerElementAutomationPeerT(llm::OS::UI::Xaml::Controls::MediaPlayerElement const& owner)
        {
            impl::call_factory<MediaPlayerElementAutomationPeer, IMediaPlayerElementAutomationPeerFactory>([&](IMediaPlayerElementAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MediaTransportControlsAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MediaTransportControlsAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MediaTransportControlsAutomationPeer;
    protected:
        MediaTransportControlsAutomationPeerT(llm::OS::UI::Xaml::Controls::MediaTransportControls const& owner)
        {
            impl::call_factory<MediaTransportControlsAutomationPeer, IMediaTransportControlsAutomationPeerFactory>([&](IMediaTransportControlsAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MenuBarAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MenuBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MenuBarAutomationPeer;
    protected:
        MenuBarAutomationPeerT(llm::OS::UI::Xaml::Controls::MenuBar const& owner)
        {
            impl::call_factory<MenuBarAutomationPeer, IMenuBarAutomationPeerFactory>([&](IMenuBarAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MenuBarItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IExpandCollapseProvider, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MenuBarItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MenuBarItemAutomationPeer;
    protected:
        MenuBarItemAutomationPeerT(llm::OS::UI::Xaml::Controls::MenuBarItem const& owner)
        {
            impl::call_factory<MenuBarItemAutomationPeer, IMenuBarItemAutomationPeerFactory>([&](IMenuBarItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstance(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MenuFlyoutItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MenuFlyoutItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MenuFlyoutItemAutomationPeer;
    protected:
        MenuFlyoutItemAutomationPeerT(llm::OS::UI::Xaml::Controls::MenuFlyoutItem const& owner)
        {
            impl::call_factory<MenuFlyoutItemAutomationPeer, IMenuFlyoutItemAutomationPeerFactory>([&](IMenuFlyoutItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct MenuFlyoutPresenterAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, MenuFlyoutPresenterAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = MenuFlyoutPresenterAutomationPeer;
    protected:
        MenuFlyoutPresenterAutomationPeerT(llm::OS::UI::Xaml::Controls::MenuFlyoutPresenter const& owner)
        {
            impl::call_factory<MenuFlyoutPresenterAutomationPeer, IMenuFlyoutPresenterAutomationPeerFactory>([&](IMenuFlyoutPresenterAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct NavigationViewItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, NavigationViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = NavigationViewItemAutomationPeer;
    protected:
        NavigationViewItemAutomationPeerT(llm::OS::UI::Xaml::Controls::NavigationViewItem const& owner)
        {
            impl::call_factory<NavigationViewItemAutomationPeer, INavigationViewItemAutomationPeerFactory>([&](INavigationViewItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct PasswordBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, PasswordBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = PasswordBoxAutomationPeer;
    protected:
        PasswordBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::PasswordBox const& owner)
        {
            impl::call_factory<PasswordBoxAutomationPeer, IPasswordBoxAutomationPeerFactory>([&](IPasswordBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct PersonPictureAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, PersonPictureAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = PersonPictureAutomationPeer;
    protected:
        PersonPictureAutomationPeerT(llm::OS::UI::Xaml::Controls::PersonPicture const& owner)
        {
            impl::call_factory<PersonPictureAutomationPeer, IPersonPictureAutomationPeerFactory>([&](IPersonPictureAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ProgressBarAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ProgressBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ProgressBarAutomationPeer;
    protected:
        ProgressBarAutomationPeerT(llm::OS::UI::Xaml::Controls::ProgressBar const& owner)
        {
            impl::call_factory<ProgressBarAutomationPeer, IProgressBarAutomationPeerFactory>([&](IProgressBarAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct ProgressRingAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ProgressRingAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ProgressRingAutomationPeer;
    protected:
        ProgressRingAutomationPeerT(llm::OS::UI::Xaml::Controls::ProgressRing const& owner)
        {
            impl::call_factory<ProgressRingAutomationPeer, IProgressRingAutomationPeerFactory>([&](IProgressRingAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct RadioButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RadioButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RadioButtonAutomationPeer;
    protected:
        RadioButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::RadioButton const& owner)
        {
            impl::call_factory<RadioButtonAutomationPeer, IRadioButtonAutomationPeerFactory>([&](IRadioButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct RangeBaseAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RangeBaseAutomationPeer;
    protected:
        RangeBaseAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::RangeBase const& owner)
        {
            impl::call_factory<RangeBaseAutomationPeer, IRangeBaseAutomationPeerFactory>([&](IRangeBaseAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct RatingControlAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RatingControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RatingControlAutomationPeer;
    protected:
        RatingControlAutomationPeerT(llm::OS::UI::Xaml::Controls::RatingControl const& owner)
        {
            impl::call_factory<RatingControlAutomationPeer, IRatingControlAutomationPeerFactory>([&](IRatingControlAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct RepeatButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IInvokeProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RepeatButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RepeatButtonAutomationPeer;
    protected:
        RepeatButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::RepeatButton const& owner)
        {
            impl::call_factory<RepeatButtonAutomationPeer, IRepeatButtonAutomationPeerFactory>([&](IRepeatButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct RichEditBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RichEditBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RichEditBoxAutomationPeer;
    protected:
        RichEditBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::RichEditBox const& owner)
        {
            impl::call_factory<RichEditBoxAutomationPeer, IRichEditBoxAutomationPeerFactory>([&](IRichEditBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct RichTextBlockAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RichTextBlockAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RichTextBlockAutomationPeer;
    protected:
        RichTextBlockAutomationPeerT(llm::OS::UI::Xaml::Controls::RichTextBlock const& owner)
        {
            impl::call_factory<RichTextBlockAutomationPeer, IRichTextBlockAutomationPeerFactory>([&](IRichTextBlockAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct RichTextBlockOverflowAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, RichTextBlockOverflowAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = RichTextBlockOverflowAutomationPeer;
    protected:
        RichTextBlockOverflowAutomationPeerT(llm::OS::UI::Xaml::Controls::RichTextBlockOverflow const& owner)
        {
            impl::call_factory<RichTextBlockOverflowAutomationPeer, IRichTextBlockOverflowAutomationPeerFactory>([&](IRichTextBlockOverflowAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ScrollBarAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ScrollBarAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ScrollBarAutomationPeer;
    protected:
        ScrollBarAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::ScrollBar const& owner)
        {
            impl::call_factory<ScrollBarAutomationPeer, IScrollBarAutomationPeerFactory>([&](IScrollBarAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct ScrollViewerAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IScrollProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ScrollViewerAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ScrollViewerAutomationPeer;
    protected:
        ScrollViewerAutomationPeerT(llm::OS::UI::Xaml::Controls::ScrollViewer const& owner)
        {
            impl::call_factory<ScrollViewerAutomationPeer, IScrollViewerAutomationPeerFactory>([&](IScrollViewerAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct SearchBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, SearchBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = SearchBoxAutomationPeer;
    protected:
        SearchBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::SearchBox const& owner)
        {
            impl::call_factory<SearchBoxAutomationPeer, ISearchBoxAutomationPeerFactory>([&](ISearchBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct SelectorAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = SelectorAutomationPeer;
    protected:
        SelectorAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::Selector const& owner)
        {
            impl::call_factory<SelectorAutomationPeer, ISelectorAutomationPeerFactory>([&](ISelectorAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct SelectorItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionItemProvider, llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IVirtualizedItemProvider, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, SelectorItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = SelectorItemAutomationPeer;
    protected:
        SelectorItemAutomationPeerT(llm::OS::Foundation::IInspectable const& item, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer const& parent)
        {
            impl::call_factory<SelectorItemAutomationPeer, ISelectorItemAutomationPeerFactory>([&](ISelectorItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithParentAndItem(item, parent, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct SemanticZoomAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, SemanticZoomAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = SemanticZoomAutomationPeer;
    protected:
        SemanticZoomAutomationPeerT(llm::OS::UI::Xaml::Controls::SemanticZoom const& owner)
        {
            impl::call_factory<SemanticZoomAutomationPeer, ISemanticZoomAutomationPeerFactory>([&](ISemanticZoomAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct SettingsFlyoutAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, SettingsFlyoutAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = SettingsFlyoutAutomationPeer;
    protected:
        SettingsFlyoutAutomationPeerT(llm::OS::UI::Xaml::Controls::SettingsFlyout const& owner)
        {
            impl::call_factory<SettingsFlyoutAutomationPeer, ISettingsFlyoutAutomationPeerFactory>([&](ISettingsFlyoutAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct SliderAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, SliderAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = SliderAutomationPeer;
    protected:
        SliderAutomationPeerT(llm::OS::UI::Xaml::Controls::Slider const& owner)
        {
            impl::call_factory<SliderAutomationPeer, ISliderAutomationPeerFactory>([&](ISliderAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
        using impl::consume_t<D, llm::OS::UI::Xaml::Automation::Provider::IRangeValueProvider>::SetValue;
        using impl::consume_t<D, llm::OS::UI::Xaml::IDependencyObject>::SetValue;
    };
    template <typename D, typename... Interfaces>
    struct TextBlockAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, TextBlockAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = TextBlockAutomationPeer;
    protected:
        TextBlockAutomationPeerT(llm::OS::UI::Xaml::Controls::TextBlock const& owner)
        {
            impl::call_factory<TextBlockAutomationPeer, ITextBlockAutomationPeerFactory>([&](ITextBlockAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct TextBoxAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, TextBoxAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = TextBoxAutomationPeer;
    protected:
        TextBoxAutomationPeerT(llm::OS::UI::Xaml::Controls::TextBox const& owner)
        {
            impl::call_factory<TextBoxAutomationPeer, ITextBoxAutomationPeerFactory>([&](ITextBoxAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ThumbAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ThumbAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ThumbAutomationPeer;
    protected:
        ThumbAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::Thumb const& owner)
        {
            impl::call_factory<ThumbAutomationPeer, IThumbAutomationPeerFactory>([&](IThumbAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct TimePickerAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, TimePickerAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = TimePickerAutomationPeer;
    protected:
        TimePickerAutomationPeerT(llm::OS::UI::Xaml::Controls::TimePicker const& owner)
        {
            impl::call_factory<TimePickerAutomationPeer, ITimePickerAutomationPeerFactory>([&](ITimePickerAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ToggleButtonAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ToggleButtonAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ToggleButtonAutomationPeer;
    protected:
        ToggleButtonAutomationPeerT(llm::OS::UI::Xaml::Controls::Primitives::ToggleButton const& owner)
        {
            impl::call_factory<ToggleButtonAutomationPeer, IToggleButtonAutomationPeerFactory>([&](IToggleButtonAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ToggleMenuFlyoutItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ToggleMenuFlyoutItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ToggleMenuFlyoutItemAutomationPeer;
    protected:
        ToggleMenuFlyoutItemAutomationPeerT(llm::OS::UI::Xaml::Controls::ToggleMenuFlyoutItem const& owner)
        {
            impl::call_factory<ToggleMenuFlyoutItemAutomationPeer, IToggleMenuFlyoutItemAutomationPeerFactory>([&](IToggleMenuFlyoutItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct ToggleSwitchAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IToggleProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, ToggleSwitchAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = ToggleSwitchAutomationPeer;
    protected:
        ToggleSwitchAutomationPeerT(llm::OS::UI::Xaml::Controls::ToggleSwitch const& owner)
        {
            impl::call_factory<ToggleSwitchAutomationPeer, IToggleSwitchAutomationPeerFactory>([&](IToggleSwitchAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct TreeViewItemAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::IExpandCollapseProvider, llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, TreeViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = TreeViewItemAutomationPeer;
    protected:
        TreeViewItemAutomationPeerT(llm::OS::UI::Xaml::Controls::TreeViewItem const& owner)
        {
            impl::call_factory<TreeViewItemAutomationPeer, ITreeViewItemAutomationPeerFactory>([&](ITreeViewItemAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
    template <typename D, typename... Interfaces>
    struct TreeViewListAutomationPeerT :
        implements<D, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9, composing, Interfaces...>,
        impl::require<D, llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Provider::ISelectionProvider, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2, llm::OS::UI::Xaml::Automation::Provider::IItemContainerProvider, llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected, llm::OS::UI::Xaml::IDependencyObject, llm::OS::UI::Xaml::IDependencyObject2>,
        impl::base<D, TreeViewListAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer, llm::OS::UI::Xaml::Automation::Peers::AutomationPeer, llm::OS::UI::Xaml::DependencyObject>,
        llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverridesT<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8T<D>, llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9T<D>
    {
        using composable = TreeViewListAutomationPeer;
    protected:
        TreeViewListAutomationPeerT(llm::OS::UI::Xaml::Controls::TreeViewList const& owner)
        {
            impl::call_factory<TreeViewListAutomationPeer, ITreeViewListAutomationPeerFactory>([&](ITreeViewListAutomationPeerFactory const& f) { [[maybe_unused]] auto llm_impl_discarded = f.CreateInstanceWithOwner(owner, *this, this->m_inner); });
        }
    };
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAppBarAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAppBarButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAppBarToggleButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutoSuggestBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer7> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer8> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeer9> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerAnnotationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides8> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerOverrides9> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerProtected> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IAutomationPeerStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IButtonBaseAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ICalendarDatePickerAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ICaptureElementAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ICheckBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IColorPickerSliderAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IColorSpectrumAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IComboBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IComboBoxItemDataAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IDatePickerAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IDatePickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlipViewAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlipViewItemDataAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFlyoutPresenterAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IFrameworkElementAutomationPeerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewHeaderItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGridViewItemDataAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IGroupItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IHubAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IHubSectionAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IHyperlinkButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IImageAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IInkToolbarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeer2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IItemsControlAutomationPeerOverrides2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListBoxItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListBoxItemDataAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListPickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewBaseAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewBaseHeaderItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewHeaderItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IListViewItemDataAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ILoopingSelectorItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMapControlAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMediaElementAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMediaPlayerElementAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMediaTransportControlsAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuBarAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuBarItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IMenuFlyoutPresenterAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::INavigationViewItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPasswordBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPersonPictureAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPivotAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPivotItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IPivotItemDataAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IProgressBarAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IProgressRingAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRadioButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRangeBaseAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRatingControlAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRepeatButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRichEditBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IRichTextBlockOverflowAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IScrollBarAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IScrollViewerAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISearchBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISelectorAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISelectorItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISemanticZoomAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISettingsFlyoutAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ISliderAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITextBlockAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITextBoxAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IThumbAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITimePickerAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITimePickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IToggleButtonAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IToggleMenuFlyoutItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::IToggleSwitchAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITreeViewItemAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ITreeViewListAutomationPeerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::AppBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::AppBarButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::AppBarToggleButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::AutoSuggestBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::AutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::AutomationPeerAnnotation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ButtonBaseAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::CalendarDatePickerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::CaptureElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::CheckBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ColorPickerSliderAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ColorSpectrumAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ComboBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ComboBoxItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::DatePickerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::DatePickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::FlipViewAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::FlipViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::FlipViewItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::FlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::FrameworkElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::GridViewAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::GridViewHeaderItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::GridViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::GridViewItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::GroupItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::HubAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::HubSectionAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::HyperlinkButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ImageAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::InkToolbarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ItemsControlAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListBoxItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListBoxItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListPickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListViewAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListViewBaseAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListViewBaseHeaderItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListViewHeaderItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ListViewItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::LoopingSelectorAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::LoopingSelectorItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::LoopingSelectorItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MapControlAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MediaElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MediaPlayerElementAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MediaTransportControlsAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MenuBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MenuBarItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::MenuFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::NavigationViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::PasswordBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::PersonPictureAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::PickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::PivotAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::PivotItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::PivotItemDataAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ProgressBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ProgressRingAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RadioButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RangeBaseAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RatingControlAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RepeatButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RichEditBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RichTextBlockAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::RichTextBlockOverflowAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ScrollBarAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ScrollViewerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::SearchBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::SelectorAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::SelectorItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::SemanticZoomAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::SettingsFlyoutAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::SliderAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::TextBlockAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::TextBoxAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ThumbAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::TimePickerAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::TimePickerFlyoutPresenterAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ToggleButtonAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ToggleMenuFlyoutItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::ToggleSwitchAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::TreeViewItemAutomationPeer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Xaml::Automation::Peers::TreeViewListAutomationPeer> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
