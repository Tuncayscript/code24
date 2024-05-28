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
#ifndef LLM_OS_UI_StartScreen_H
#define LLM_OS_UI_StartScreen_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.ApplicationModel.Core.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Perception.Spatial.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.UI.StartScreen.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::UI::StartScreen::JumpListItem>) consume_Windows_UI_StartScreen_IJumpList<D>::Items() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpList)->get_Items(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::UI::StartScreen::JumpListItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::JumpListSystemGroupKind) consume_Windows_UI_StartScreen_IJumpList<D>::SystemGroupKind() const
    {
        llm::OS::UI::StartScreen::JumpListSystemGroupKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpList)->get_SystemGroupKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_IJumpList<D>::SystemGroupKind(llm::OS::UI::StartScreen::JumpListSystemGroupKind const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpList)->put_SystemGroupKind(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_UI_StartScreen_IJumpList<D>::SaveAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpList)->SaveAsync(&result));
        return llm::OS::Foundation::IAsyncAction{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::JumpListItemKind) consume_Windows_UI_StartScreen_IJumpListItem<D>::Kind() const
    {
        llm::OS::UI::StartScreen::JumpListItemKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_IJumpListItem<D>::Arguments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_Arguments(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_IJumpListItem<D>::RemovedByUser() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_RemovedByUser(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_IJumpListItem<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_IJumpListItem<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_IJumpListItem<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_IJumpListItem<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_IJumpListItem<D>::GroupName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_GroupName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_IJumpListItem<D>::GroupName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->put_GroupName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_IJumpListItem<D>::Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->get_Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_IJumpListItem<D>::Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItem)->put_Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::JumpListItem) consume_Windows_UI_StartScreen_IJumpListItemStatics<D>::CreateWithArguments(param::hstring const& arguments, param::hstring const& displayName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItemStatics)->CreateWithArguments(*(void**)(&arguments), *(void**)(&displayName), &result));
        return llm::OS::UI::StartScreen::JumpListItem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::JumpListItem) consume_Windows_UI_StartScreen_IJumpListItemStatics<D>::CreateSeparator() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListItemStatics)->CreateSeparator(&result));
        return llm::OS::UI::StartScreen::JumpListItem{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::StartScreen::JumpList>) consume_Windows_UI_StartScreen_IJumpListStatics<D>::LoadCurrentAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListStatics)->LoadCurrentAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::StartScreen::JumpList>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_IJumpListStatics<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IJumpListStatics)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::TileId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_TileId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_ISecondaryTile<D>::TileId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_TileId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::Arguments(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_Arguments(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_ISecondaryTile<D>::Arguments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_Arguments(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::ShortName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_ShortName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_ISecondaryTile<D>::ShortName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_ShortName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_ISecondaryTile<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTile<D>::Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::SmallLogo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_SmallLogo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTile<D>::SmallLogo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_SmallLogo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::WideLogo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_WideLogo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTile<D>::WideLogo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_WideLogo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::LockScreenBadgeLogo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_LockScreenBadgeLogo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTile<D>::LockScreenBadgeLogo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_LockScreenBadgeLogo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::LockScreenDisplayBadgeAndTileText(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_LockScreenDisplayBadgeAndTileText(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_ISecondaryTile<D>::LockScreenDisplayBadgeAndTileText() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_LockScreenDisplayBadgeAndTileText(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::TileOptions(llm::OS::UI::StartScreen::TileOptions const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_TileOptions(static_cast<uint32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::TileOptions) consume_Windows_UI_StartScreen_ISecondaryTile<D>::TileOptions() const
    {
        llm::OS::UI::StartScreen::TileOptions value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_TileOptions(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::ForegroundText(llm::OS::UI::StartScreen::ForegroundText const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_ForegroundText(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::ForegroundText) consume_Windows_UI_StartScreen_ISecondaryTile<D>::ForegroundText() const
    {
        llm::OS::UI::StartScreen::ForegroundText value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_ForegroundText(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile<D>::BackgroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->put_BackgroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_StartScreen_ISecondaryTile<D>::BackgroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->get_BackgroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestCreateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestCreateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestCreateAsync(llm::OS::Foundation::Point const& invocationPoint) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestCreateAsyncWithPoint(impl::bind_in(invocationPoint), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestCreateForSelectionAsync(llm::OS::Foundation::Rect const& selection) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestCreateAsyncWithRect(impl::bind_in(selection), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestCreateForSelectionAsync(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestCreateAsyncWithRectAndPlacement(impl::bind_in(selection), static_cast<int32_t>(preferredPlacement), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestDeleteAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestDeleteAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestDeleteAsync(llm::OS::Foundation::Point const& invocationPoint) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestDeleteAsyncWithPoint(impl::bind_in(invocationPoint), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestDeleteForSelectionAsync(llm::OS::Foundation::Rect const& selection) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestDeleteAsyncWithRect(impl::bind_in(selection), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::RequestDeleteForSelectionAsync(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->RequestDeleteAsyncWithRectAndPlacement(impl::bind_in(selection), static_cast<int32_t>(preferredPlacement), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_ISecondaryTile<D>::UpdateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile)->UpdateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::PhoneticName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->put_PhoneticName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::PhoneticName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->get_PhoneticName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::SecondaryTileVisualElements) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::VisualElements() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->get_VisualElements(&value));
        return llm::OS::UI::StartScreen::SecondaryTileVisualElements{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::RoamingEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->put_RoamingEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::RoamingEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->get_RoamingEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::VisualElementsRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::StartScreen::SecondaryTile, llm::OS::UI::StartScreen::VisualElementsRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->add_VisualElementsRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_StartScreen_ISecondaryTile2<D>::VisualElementsRequested_revoker consume_Windows_UI_StartScreen_ISecondaryTile2<D>::VisualElementsRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::StartScreen::SecondaryTile, llm::OS::UI::StartScreen::VisualElementsRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, VisualElementsRequested_revoker>(this, VisualElementsRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTile2<D>::VisualElementsRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTile2)->remove_VisualElementsRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::SecondaryTile) consume_Windows_UI_StartScreen_ISecondaryTileFactory<D>::CreateTile(param::hstring const& tileId, param::hstring const& shortName, param::hstring const& displayName, param::hstring const& arguments, llm::OS::UI::StartScreen::TileOptions const& tileOptions, llm::OS::Foundation::Uri const& logoReference) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileFactory)->CreateTile(*(void**)(&tileId), *(void**)(&shortName), *(void**)(&displayName), *(void**)(&arguments), static_cast<uint32_t>(tileOptions), *(void**)(&logoReference), &value));
        return llm::OS::UI::StartScreen::SecondaryTile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::SecondaryTile) consume_Windows_UI_StartScreen_ISecondaryTileFactory<D>::CreateWideTile(param::hstring const& tileId, param::hstring const& shortName, param::hstring const& displayName, param::hstring const& arguments, llm::OS::UI::StartScreen::TileOptions const& tileOptions, llm::OS::Foundation::Uri const& logoReference, llm::OS::Foundation::Uri const& wideLogoReference) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileFactory)->CreateWideTile(*(void**)(&tileId), *(void**)(&shortName), *(void**)(&displayName), *(void**)(&arguments), static_cast<uint32_t>(tileOptions), *(void**)(&logoReference), *(void**)(&wideLogoReference), &value));
        return llm::OS::UI::StartScreen::SecondaryTile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::SecondaryTile) consume_Windows_UI_StartScreen_ISecondaryTileFactory<D>::CreateWithId(param::hstring const& tileId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileFactory)->CreateWithId(*(void**)(&tileId), &value));
        return llm::OS::UI::StartScreen::SecondaryTile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::SecondaryTile) consume_Windows_UI_StartScreen_ISecondaryTileFactory2<D>::CreateMinimalTile(param::hstring const& tileId, param::hstring const& displayName, param::hstring const& arguments, llm::OS::Foundation::Uri const& square150x150Logo, llm::OS::UI::StartScreen::TileSize const& desiredSize) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileFactory2)->CreateMinimalTile(*(void**)(&tileId), *(void**)(&displayName), *(void**)(&arguments), *(void**)(&square150x150Logo), static_cast<int32_t>(desiredSize), &value));
        return llm::OS::UI::StartScreen::SecondaryTile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_ISecondaryTileStatics<D>::Exists(param::hstring const& tileId) const
    {
        bool exists{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileStatics)->Exists(*(void**)(&tileId), &exists));
        return exists;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>) consume_Windows_UI_StartScreen_ISecondaryTileStatics<D>::FindAllAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileStatics)->FindAllAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>) consume_Windows_UI_StartScreen_ISecondaryTileStatics<D>::FindAllAsync(param::hstring const& applicationId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileStatics)->FindAllForApplicationAsync(*(void**)(&applicationId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>) consume_Windows_UI_StartScreen_ISecondaryTileStatics<D>::FindAllForPackageAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileStatics)->FindAllForPackageAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square30x30Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_Square30x30Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square30x30Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_Square30x30Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square70x70Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_Square70x70Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square70x70Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_Square70x70Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square150x150Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_Square150x150Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square150x150Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_Square150x150Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Wide310x150Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_Wide310x150Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Wide310x150Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_Wide310x150Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square310x310Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_Square310x310Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::Square310x310Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_Square310x310Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ForegroundText(llm::OS::UI::StartScreen::ForegroundText const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_ForegroundText(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::ForegroundText) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ForegroundText() const
    {
        llm::OS::UI::StartScreen::ForegroundText value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_ForegroundText(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::BackgroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_BackgroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::BackgroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_BackgroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ShowNameOnSquare150x150Logo(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_ShowNameOnSquare150x150Logo(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ShowNameOnSquare150x150Logo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_ShowNameOnSquare150x150Logo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ShowNameOnWide310x150Logo(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_ShowNameOnWide310x150Logo(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ShowNameOnWide310x150Logo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_ShowNameOnWide310x150Logo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ShowNameOnSquare310x310Logo(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->put_ShowNameOnSquare310x310Logo(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements<D>::ShowNameOnSquare310x310Logo() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements)->get_ShowNameOnSquare310x310Logo(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements2<D>::Square71x71Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements2)->put_Square71x71Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements2<D>::Square71x71Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements2)->get_Square71x71Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements3<D>::Square44x44Logo(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements3)->put_Square44x44Logo(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements3<D>::Square44x44Logo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements3)->get_Square44x44Logo(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::TileMixedRealityModel) consume_Windows_UI_StartScreen_ISecondaryTileVisualElements4<D>::MixedRealityModel() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ISecondaryTileVisualElements4)->get_MixedRealityModel(&value));
        return llm::OS::UI::StartScreen::TileMixedRealityModel{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_UI_StartScreen_IStartScreenManager<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManager)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_StartScreen_IStartScreenManager<D>::SupportsAppListEntry(llm::OS::ApplicationModel::Core::AppListEntry const& appListEntry) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManager)->SupportsAppListEntry(*(void**)(&appListEntry), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_IStartScreenManager<D>::ContainsAppListEntryAsync(llm::OS::ApplicationModel::Core::AppListEntry const& appListEntry) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManager)->ContainsAppListEntryAsync(*(void**)(&appListEntry), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_IStartScreenManager<D>::RequestAddAppListEntryAsync(llm::OS::ApplicationModel::Core::AppListEntry const& appListEntry) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManager)->RequestAddAppListEntryAsync(*(void**)(&appListEntry), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_IStartScreenManager2<D>::ContainsSecondaryTileAsync(param::hstring const& tileId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManager2)->ContainsSecondaryTileAsync(*(void**)(&tileId), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_StartScreen_IStartScreenManager2<D>::TryRemoveSecondaryTileAsync(param::hstring const& tileId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManager2)->TryRemoveSecondaryTileAsync(*(void**)(&tileId), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::StartScreenManager) consume_Windows_UI_StartScreen_IStartScreenManagerStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManagerStatics)->GetDefault(&value));
        return llm::OS::UI::StartScreen::StartScreenManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::StartScreenManager) consume_Windows_UI_StartScreen_IStartScreenManagerStatics<D>::GetForUser(llm::OS::System::User const& user) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IStartScreenManagerStatics)->GetForUser(*(void**)(&user), &result));
        return llm::OS::UI::StartScreen::StartScreenManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ITileMixedRealityModel<D>::Uri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ITileMixedRealityModel)->put_Uri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_UI_StartScreen_ITileMixedRealityModel<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ITileMixedRealityModel)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ITileMixedRealityModel<D>::BoundingBox(llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingBox> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ITileMixedRealityModel)->put_BoundingBox(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingBox>) consume_Windows_UI_StartScreen_ITileMixedRealityModel<D>::BoundingBox() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ITileMixedRealityModel)->get_BoundingBox(&value));
        return llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingBox>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_ITileMixedRealityModel2<D>::ActivationBehavior(llm::OS::UI::StartScreen::TileMixedRealityModelActivationBehavior const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ITileMixedRealityModel2)->put_ActivationBehavior(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::TileMixedRealityModelActivationBehavior) consume_Windows_UI_StartScreen_ITileMixedRealityModel2<D>::ActivationBehavior() const
    {
        llm::OS::UI::StartScreen::TileMixedRealityModelActivationBehavior value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::ITileMixedRealityModel2)->get_ActivationBehavior(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::SecondaryTileVisualElements) consume_Windows_UI_StartScreen_IVisualElementsRequest<D>::VisualElements() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IVisualElementsRequest)->get_VisualElements(&value));
        return llm::OS::UI::StartScreen::SecondaryTileVisualElements{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTileVisualElements>) consume_Windows_UI_StartScreen_IVisualElementsRequest<D>::AlternateVisualElements() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IVisualElementsRequest)->get_AlternateVisualElements(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTileVisualElements>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_UI_StartScreen_IVisualElementsRequest<D>::Deadline() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IVisualElementsRequest)->get_Deadline(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::VisualElementsRequestDeferral) consume_Windows_UI_StartScreen_IVisualElementsRequest<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IVisualElementsRequest)->GetDeferral(&deferral));
        return llm::OS::UI::StartScreen::VisualElementsRequestDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_StartScreen_IVisualElementsRequestDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IVisualElementsRequestDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::StartScreen::VisualElementsRequest) consume_Windows_UI_StartScreen_IVisualElementsRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::StartScreen::IVisualElementsRequestedEventArgs)->get_Request(&value));
        return llm::OS::UI::StartScreen::VisualElementsRequest{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IJumpList> : produce_base<D, llm::OS::UI::StartScreen::IJumpList>
    {
        int32_t __stdcall get_Items(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::UI::StartScreen::JumpListItem>>(this->shim().Items());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemGroupKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::JumpListSystemGroupKind>(this->shim().SystemGroupKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SystemGroupKind(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemGroupKind(*reinterpret_cast<llm::OS::UI::StartScreen::JumpListSystemGroupKind const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SaveAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SaveAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IJumpListItem> : produce_base<D, llm::OS::UI::StartScreen::IJumpListItem>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::JumpListItemKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Arguments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Arguments());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemovedByUser(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RemovedByUser());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GroupName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GroupName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_GroupName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GroupName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IJumpListItemStatics> : produce_base<D, llm::OS::UI::StartScreen::IJumpListItemStatics>
    {
        int32_t __stdcall CreateWithArguments(void* arguments, void* displayName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::StartScreen::JumpListItem>(this->shim().CreateWithArguments(*reinterpret_cast<hstring const*>(&arguments), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateSeparator(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::StartScreen::JumpListItem>(this->shim().CreateSeparator());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IJumpListStatics> : produce_base<D, llm::OS::UI::StartScreen::IJumpListStatics>
    {
        int32_t __stdcall LoadCurrentAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::StartScreen::JumpList>>(this->shim().LoadCurrentAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTile> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTile>
    {
        int32_t __stdcall put_TileId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TileId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TileId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Arguments(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Arguments(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Arguments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Arguments());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShortName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShortName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShortName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ShortName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SmallLogo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmallLogo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SmallLogo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().SmallLogo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WideLogo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WideLogo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WideLogo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().WideLogo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LockScreenBadgeLogo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LockScreenBadgeLogo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LockScreenBadgeLogo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().LockScreenBadgeLogo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LockScreenDisplayBadgeAndTileText(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LockScreenDisplayBadgeAndTileText(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LockScreenDisplayBadgeAndTileText(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().LockScreenDisplayBadgeAndTileText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TileOptions(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TileOptions(*reinterpret_cast<llm::OS::UI::StartScreen::TileOptions const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TileOptions(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::TileOptions>(this->shim().TileOptions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ForegroundText(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundText(*reinterpret_cast<llm::OS::UI::StartScreen::ForegroundText const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ForegroundText(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::ForegroundText>(this->shim().ForegroundText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCreateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestCreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCreateAsyncWithPoint(llm::OS::Foundation::Point invocationPoint, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestCreateAsync(*reinterpret_cast<llm::OS::Foundation::Point const*>(&invocationPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCreateAsyncWithRect(llm::OS::Foundation::Rect selection, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestCreateForSelectionAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCreateAsyncWithRectAndPlacement(llm::OS::Foundation::Rect selection, int32_t preferredPlacement, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestCreateForSelectionAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&preferredPlacement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDeleteAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestDeleteAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDeleteAsyncWithPoint(llm::OS::Foundation::Point invocationPoint, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestDeleteAsync(*reinterpret_cast<llm::OS::Foundation::Point const*>(&invocationPoint)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDeleteAsyncWithRect(llm::OS::Foundation::Rect selection, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestDeleteForSelectionAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestDeleteAsyncWithRectAndPlacement(llm::OS::Foundation::Rect selection, int32_t preferredPlacement, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestDeleteForSelectionAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&preferredPlacement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().UpdateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTile2> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTile2>
    {
        int32_t __stdcall put_PhoneticName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PhoneticName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhoneticName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PhoneticName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VisualElements(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::SecondaryTileVisualElements>(this->shim().VisualElements());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RoamingEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoamingEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RoamingEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RoamingEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_VisualElementsRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VisualElementsRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::StartScreen::SecondaryTile, llm::OS::UI::StartScreen::VisualElementsRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VisualElementsRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisualElementsRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileFactory> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileFactory>
    {
        int32_t __stdcall CreateTile(void* tileId, void* shortName, void* displayName, void* arguments, uint32_t tileOptions, void* logoReference, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::SecondaryTile>(this->shim().CreateTile(*reinterpret_cast<hstring const*>(&tileId), *reinterpret_cast<hstring const*>(&shortName), *reinterpret_cast<hstring const*>(&displayName), *reinterpret_cast<hstring const*>(&arguments), *reinterpret_cast<llm::OS::UI::StartScreen::TileOptions const*>(&tileOptions), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&logoReference)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWideTile(void* tileId, void* shortName, void* displayName, void* arguments, uint32_t tileOptions, void* logoReference, void* wideLogoReference, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::SecondaryTile>(this->shim().CreateWideTile(*reinterpret_cast<hstring const*>(&tileId), *reinterpret_cast<hstring const*>(&shortName), *reinterpret_cast<hstring const*>(&displayName), *reinterpret_cast<hstring const*>(&arguments), *reinterpret_cast<llm::OS::UI::StartScreen::TileOptions const*>(&tileOptions), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&logoReference), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&wideLogoReference)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithId(void* tileId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::SecondaryTile>(this->shim().CreateWithId(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileFactory2> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileFactory2>
    {
        int32_t __stdcall CreateMinimalTile(void* tileId, void* displayName, void* arguments, void* square150x150Logo, int32_t desiredSize, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::SecondaryTile>(this->shim().CreateMinimalTile(*reinterpret_cast<hstring const*>(&tileId), *reinterpret_cast<hstring const*>(&displayName), *reinterpret_cast<hstring const*>(&arguments), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&square150x150Logo), *reinterpret_cast<llm::OS::UI::StartScreen::TileSize const*>(&desiredSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileStatics> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileStatics>
    {
        int32_t __stdcall Exists(void* tileId, bool* exists) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *exists = detach_from<bool>(this->shim().Exists(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllForApplicationAsync(void* applicationId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>>(this->shim().FindAllAsync(*reinterpret_cast<hstring const*>(&applicationId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllForPackageAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>>(this->shim().FindAllForPackageAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements>
    {
        int32_t __stdcall put_Square30x30Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square30x30Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Square30x30Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Square30x30Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Square70x70Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square70x70Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Square70x70Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Square70x70Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Square150x150Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square150x150Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Square150x150Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Square150x150Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Wide310x150Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Wide310x150Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Wide310x150Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Wide310x150Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Square310x310Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square310x310Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Square310x310Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Square310x310Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ForegroundText(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundText(*reinterpret_cast<llm::OS::UI::StartScreen::ForegroundText const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ForegroundText(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::ForegroundText>(this->shim().ForegroundText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShowNameOnSquare150x150Logo(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNameOnSquare150x150Logo(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShowNameOnSquare150x150Logo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowNameOnSquare150x150Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShowNameOnWide310x150Logo(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNameOnWide310x150Logo(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShowNameOnWide310x150Logo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowNameOnWide310x150Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShowNameOnSquare310x310Logo(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowNameOnSquare310x310Logo(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShowNameOnSquare310x310Logo(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowNameOnSquare310x310Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements2> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements2>
    {
        int32_t __stdcall put_Square71x71Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square71x71Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Square71x71Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Square71x71Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements3> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements3>
    {
        int32_t __stdcall put_Square44x44Logo(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Square44x44Logo(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Square44x44Logo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Square44x44Logo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements4> : produce_base<D, llm::OS::UI::StartScreen::ISecondaryTileVisualElements4>
    {
        int32_t __stdcall get_MixedRealityModel(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::TileMixedRealityModel>(this->shim().MixedRealityModel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IStartScreenManager> : produce_base<D, llm::OS::UI::StartScreen::IStartScreenManager>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SupportsAppListEntry(void* appListEntry, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().SupportsAppListEntry(*reinterpret_cast<llm::OS::ApplicationModel::Core::AppListEntry const*>(&appListEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ContainsAppListEntryAsync(void* appListEntry, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().ContainsAppListEntryAsync(*reinterpret_cast<llm::OS::ApplicationModel::Core::AppListEntry const*>(&appListEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAddAppListEntryAsync(void* appListEntry, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestAddAppListEntryAsync(*reinterpret_cast<llm::OS::ApplicationModel::Core::AppListEntry const*>(&appListEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IStartScreenManager2> : produce_base<D, llm::OS::UI::StartScreen::IStartScreenManager2>
    {
        int32_t __stdcall ContainsSecondaryTileAsync(void* tileId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().ContainsSecondaryTileAsync(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryRemoveSecondaryTileAsync(void* tileId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryRemoveSecondaryTileAsync(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IStartScreenManagerStatics> : produce_base<D, llm::OS::UI::StartScreen::IStartScreenManagerStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::StartScreenManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetForUser(void* user, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::StartScreen::StartScreenManager>(this->shim().GetForUser(*reinterpret_cast<llm::OS::System::User const*>(&user)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ITileMixedRealityModel> : produce_base<D, llm::OS::UI::StartScreen::ITileMixedRealityModel>
    {
        int32_t __stdcall put_Uri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Uri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BoundingBox(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BoundingBox(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingBox> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BoundingBox(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Perception::Spatial::SpatialBoundingBox>>(this->shim().BoundingBox());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::ITileMixedRealityModel2> : produce_base<D, llm::OS::UI::StartScreen::ITileMixedRealityModel2>
    {
        int32_t __stdcall put_ActivationBehavior(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActivationBehavior(*reinterpret_cast<llm::OS::UI::StartScreen::TileMixedRealityModelActivationBehavior const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivationBehavior(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::TileMixedRealityModelActivationBehavior>(this->shim().ActivationBehavior());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IVisualElementsRequest> : produce_base<D, llm::OS::UI::StartScreen::IVisualElementsRequest>
    {
        int32_t __stdcall get_VisualElements(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::SecondaryTileVisualElements>(this->shim().VisualElements());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlternateVisualElements(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTileVisualElements>>(this->shim().AlternateVisualElements());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Deadline(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Deadline());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::UI::StartScreen::VisualElementsRequestDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IVisualElementsRequestDeferral> : produce_base<D, llm::OS::UI::StartScreen::IVisualElementsRequestDeferral>
    {
        int32_t __stdcall Complete() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::StartScreen::IVisualElementsRequestedEventArgs> : produce_base<D, llm::OS::UI::StartScreen::IVisualElementsRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::StartScreen::VisualElementsRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::StartScreen
{
    constexpr auto operator|(TileOptions const left, TileOptions const right) noexcept
    {
        return static_cast<TileOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(TileOptions& left, TileOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(TileOptions const left, TileOptions const right) noexcept
    {
        return static_cast<TileOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(TileOptions& left, TileOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(TileOptions const value) noexcept
    {
        return static_cast<TileOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(TileOptions const left, TileOptions const right) noexcept
    {
        return static_cast<TileOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(TileOptions& left, TileOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto JumpList::LoadCurrentAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::StartScreen::JumpList>(*)(IJumpListStatics const&), JumpList, IJumpListStatics>([](IJumpListStatics const& f) { return f.LoadCurrentAsync(); });
    }
    inline auto JumpList::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IJumpListStatics const&), JumpList, IJumpListStatics>([](IJumpListStatics const& f) { return f.IsSupported(); });
    }
    inline auto JumpListItem::CreateWithArguments(param::hstring const& arguments, param::hstring const& displayName)
    {
        return impl::call_factory<JumpListItem, IJumpListItemStatics>([&](IJumpListItemStatics const& f) { return f.CreateWithArguments(arguments, displayName); });
    }
    inline auto JumpListItem::CreateSeparator()
    {
        return impl::call_factory_cast<llm::OS::UI::StartScreen::JumpListItem(*)(IJumpListItemStatics const&), JumpListItem, IJumpListItemStatics>([](IJumpListItemStatics const& f) { return f.CreateSeparator(); });
    }
    inline SecondaryTile::SecondaryTile() :
        SecondaryTile(impl::call_factory_cast<SecondaryTile(*)(llm::OS::Foundation::IActivationFactory const&), SecondaryTile>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SecondaryTile>(); }))
    {
    }
    inline SecondaryTile::SecondaryTile(param::hstring const& tileId, param::hstring const& shortName, param::hstring const& displayName, param::hstring const& arguments, llm::OS::UI::StartScreen::TileOptions const& tileOptions, llm::OS::Foundation::Uri const& logoReference) :
        SecondaryTile(impl::call_factory<SecondaryTile, ISecondaryTileFactory>([&](ISecondaryTileFactory const& f) { return f.CreateTile(tileId, shortName, displayName, arguments, tileOptions, logoReference); }))
    {
    }
    inline SecondaryTile::SecondaryTile(param::hstring const& tileId, param::hstring const& shortName, param::hstring const& displayName, param::hstring const& arguments, llm::OS::UI::StartScreen::TileOptions const& tileOptions, llm::OS::Foundation::Uri const& logoReference, llm::OS::Foundation::Uri const& wideLogoReference) :
        SecondaryTile(impl::call_factory<SecondaryTile, ISecondaryTileFactory>([&](ISecondaryTileFactory const& f) { return f.CreateWideTile(tileId, shortName, displayName, arguments, tileOptions, logoReference, wideLogoReference); }))
    {
    }
    inline SecondaryTile::SecondaryTile(param::hstring const& tileId) :
        SecondaryTile(impl::call_factory<SecondaryTile, ISecondaryTileFactory>([&](ISecondaryTileFactory const& f) { return f.CreateWithId(tileId); }))
    {
    }
    inline SecondaryTile::SecondaryTile(param::hstring const& tileId, param::hstring const& displayName, param::hstring const& arguments, llm::OS::Foundation::Uri const& square150x150Logo, llm::OS::UI::StartScreen::TileSize const& desiredSize) :
        SecondaryTile(impl::call_factory<SecondaryTile, ISecondaryTileFactory2>([&](ISecondaryTileFactory2 const& f) { return f.CreateMinimalTile(tileId, displayName, arguments, square150x150Logo, desiredSize); }))
    {
    }
    inline auto SecondaryTile::Exists(param::hstring const& tileId)
    {
        return impl::call_factory<SecondaryTile, ISecondaryTileStatics>([&](ISecondaryTileStatics const& f) { return f.Exists(tileId); });
    }
    inline auto SecondaryTile::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>(*)(ISecondaryTileStatics const&), SecondaryTile, ISecondaryTileStatics>([](ISecondaryTileStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto SecondaryTile::FindAllAsync(param::hstring const& applicationId)
    {
        return impl::call_factory<SecondaryTile, ISecondaryTileStatics>([&](ISecondaryTileStatics const& f) { return f.FindAllAsync(applicationId); });
    }
    inline auto SecondaryTile::FindAllForPackageAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::StartScreen::SecondaryTile>>(*)(ISecondaryTileStatics const&), SecondaryTile, ISecondaryTileStatics>([](ISecondaryTileStatics const& f) { return f.FindAllForPackageAsync(); });
    }
    inline auto StartScreenManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::UI::StartScreen::StartScreenManager(*)(IStartScreenManagerStatics const&), StartScreenManager, IStartScreenManagerStatics>([](IStartScreenManagerStatics const& f) { return f.GetDefault(); });
    }
    inline auto StartScreenManager::GetForUser(llm::OS::System::User const& user)
    {
        return impl::call_factory<StartScreenManager, IStartScreenManagerStatics>([&](IStartScreenManagerStatics const& f) { return f.GetForUser(user); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::StartScreen::IJumpList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IJumpListItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IJumpListItemStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IJumpListStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTile2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileFactory2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileVisualElements> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileVisualElements2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileVisualElements3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ISecondaryTileVisualElements4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IStartScreenManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IStartScreenManager2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IStartScreenManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ITileMixedRealityModel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::ITileMixedRealityModel2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IVisualElementsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IVisualElementsRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::IVisualElementsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::JumpList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::JumpListItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::SecondaryTile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::SecondaryTileVisualElements> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::StartScreenManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::TileMixedRealityModel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::VisualElementsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::VisualElementsRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::StartScreen::VisualElementsRequestedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
