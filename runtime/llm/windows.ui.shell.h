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
#ifndef LLM_OS_UI_Shell_H
#define LLM_OS_UI_Shell_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.ApplicationModel.Core.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Graphics.Imaging.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.StartScreen.2.h"
#include "llm/impl/Windows.UI.Shell.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Shell_IAdaptiveCard<D>::ToJson() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IAdaptiveCard)->ToJson(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::IAdaptiveCard) consume_Windows_UI_Shell_IAdaptiveCardBuilderStatics<D>::CreateAdaptiveCardFromJson(param::hstring const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IAdaptiveCardBuilderStatics)->CreateAdaptiveCardFromJson(*(void**)(&value), &result));
        return llm::OS::UI::Shell::IAdaptiveCard{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Shell_IFocusSession<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSession)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IFocusSession<D>::End() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSession)->End());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_IFocusSessionManager<D>::IsFocusActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->get_IsFocusActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::FocusSession) consume_Windows_UI_Shell_IFocusSessionManager<D>::GetSession(param::hstring const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->GetSession(*(void**)(&id), &result));
        return llm::OS::UI::Shell::FocusSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::FocusSession) consume_Windows_UI_Shell_IFocusSessionManager<D>::TryStartFocusSession() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->TryStartFocusSession(&result));
        return llm::OS::UI::Shell::FocusSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::FocusSession) consume_Windows_UI_Shell_IFocusSessionManager<D>::TryStartFocusSession(llm::OS::Foundation::DateTime const& endTime) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->TryStartFocusSession2(impl::bind_in(endTime), &result));
        return llm::OS::UI::Shell::FocusSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IFocusSessionManager<D>::DeactivateFocus() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->DeactivateFocus());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IFocusSessionManager<D>::IsFocusActiveChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::FocusSessionManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->add_IsFocusActiveChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IFocusSessionManager<D>::IsFocusActiveChanged_revoker consume_Windows_UI_Shell_IFocusSessionManager<D>::IsFocusActiveChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::FocusSessionManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsFocusActiveChanged_revoker>(this, IsFocusActiveChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IFocusSessionManager<D>::IsFocusActiveChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManager)->remove_IsFocusActiveChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::FocusSessionManager) consume_Windows_UI_Shell_IFocusSessionManagerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManagerStatics)->GetDefault(&result));
        return llm::OS::UI::Shell::FocusSessionManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_IFocusSessionManagerStatics<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IFocusSessionManagerStatics)->get_IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_UI_Shell_ISecurityAppManager<D>::Register(llm::OS::UI::Shell::SecurityAppKind const& kind, param::hstring const& displayName, llm::OS::Foundation::Uri const& detailsUri, bool registerPerUser) const
    {
        llm::guid result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ISecurityAppManager)->Register(static_cast<int32_t>(kind), *(void**)(&displayName), *(void**)(&detailsUri), registerPerUser, put_abi(result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_ISecurityAppManager<D>::Unregister(llm::OS::UI::Shell::SecurityAppKind const& kind, llm::guid const& guidRegistration) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ISecurityAppManager)->Unregister(static_cast<int32_t>(kind), impl::bind_in(guidRegistration)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_ISecurityAppManager<D>::UpdateState(llm::OS::UI::Shell::SecurityAppKind const& kind, llm::guid const& guidRegistration, llm::OS::UI::Shell::SecurityAppState const& state, llm::OS::UI::Shell::SecurityAppSubstatus const& substatus, llm::OS::Foundation::Uri const& detailsUri) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ISecurityAppManager)->UpdateState(static_cast<int32_t>(kind), impl::bind_in(guidRegistration), static_cast<int32_t>(state), static_cast<int32_t>(substatus), *(void**)(&detailsUri)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WindowId) consume_Windows_UI_Shell_IShareWindowCommandEventArgs<D>::WindowId() const
    {
        llm::OS::UI::WindowId value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandEventArgs)->get_WindowId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::ShareWindowCommand) consume_Windows_UI_Shell_IShareWindowCommandEventArgs<D>::Command() const
    {
        llm::OS::UI::Shell::ShareWindowCommand value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandEventArgs)->get_Command(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IShareWindowCommandEventArgs<D>::Command(llm::OS::UI::Shell::ShareWindowCommand const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandEventArgs)->put_Command(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::ReportCommandChanged() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->ReportCommandChanged());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::ShareWindowCommandSource, llm::OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->add_CommandRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandRequested_revoker consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::ShareWindowCommandSource, llm::OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CommandRequested_revoker>(this, CommandRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->remove_CommandRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandInvoked(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::ShareWindowCommandSource, llm::OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->add_CommandInvoked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandInvoked_revoker consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandInvoked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::ShareWindowCommandSource, llm::OS::UI::Shell::ShareWindowCommandEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CommandInvoked_revoker>(this, CommandInvoked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IShareWindowCommandSource<D>::CommandInvoked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSource)->remove_CommandInvoked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::ShareWindowCommandSource) consume_Windows_UI_Shell_IShareWindowCommandSourceStatics<D>::GetForCurrentView() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IShareWindowCommandSourceStatics)->GetForCurrentView(&result));
        return llm::OS::UI::Shell::ShareWindowCommandSource{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_ITaskbarManager<D>::IsSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager)->get_IsSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_ITaskbarManager<D>::IsPinningAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager)->get_IsPinningAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager<D>::IsCurrentAppPinnedAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager)->IsCurrentAppPinnedAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager<D>::IsAppListEntryPinnedAsync(llm::OS::ApplicationModel::Core::AppListEntry const& appListEntry) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager)->IsAppListEntryPinnedAsync(*(void**)(&appListEntry), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager<D>::RequestPinCurrentAppAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager)->RequestPinCurrentAppAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager<D>::RequestPinAppListEntryAsync(llm::OS::ApplicationModel::Core::AppListEntry const& appListEntry) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager)->RequestPinAppListEntryAsync(*(void**)(&appListEntry), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager2<D>::IsSecondaryTilePinnedAsync(param::hstring const& tileId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager2)->IsSecondaryTilePinnedAsync(*(void**)(&tileId), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager2<D>::RequestPinSecondaryTileAsync(llm::OS::UI::StartScreen::SecondaryTile const& secondaryTile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager2)->RequestPinSecondaryTileAsync(*(void**)(&secondaryTile), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_UI_Shell_ITaskbarManager2<D>::TryUnpinSecondaryTileAsync(param::hstring const& tileId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManager2)->TryUnpinSecondaryTileAsync(*(void**)(&tileId), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::TaskbarManager) consume_Windows_UI_Shell_ITaskbarManagerStatics<D>::GetDefault() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::ITaskbarManagerStatics)->GetDefault(&result));
        return llm::OS::UI::Shell::TaskbarManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_UI_Shell_IWindowTab<D>::Tag() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->get_Tag(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTab<D>::Tag(llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->put_Tag(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Shell_IWindowTab<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTab<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabIcon) consume_Windows_UI_Shell_IWindowTab<D>::Icon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->get_Icon(&value));
        return llm::OS::UI::Shell::WindowTabIcon{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTab<D>::Icon(llm::OS::UI::Shell::WindowTabIcon const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->put_Icon(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Shell_IWindowTab<D>::TreatAsSecondaryTileId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->get_TreatAsSecondaryTileId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTab<D>::TreatAsSecondaryTileId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->put_TreatAsSecondaryTileId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabGroup) consume_Windows_UI_Shell_IWindowTab<D>::Group() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->get_Group(&value));
        return llm::OS::UI::Shell::WindowTabGroup{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTab<D>::Group(llm::OS::UI::Shell::WindowTabGroup const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->put_Group(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTab<D>::ReportThumbnailAvailable() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTab)->ReportThumbnailAvailable());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTab) consume_Windows_UI_Shell_IWindowTabCloseRequestedEventArgs<D>::Tab() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabCloseRequestedEventArgs)->get_Tab(&value));
        return llm::OS::UI::Shell::WindowTab{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabCollection<D>::MoveTab(llm::OS::UI::Shell::WindowTab const& tab, uint32_t index) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabCollection)->MoveTab(*(void**)(&tab), index));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_Shell_IWindowTabGroup<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabGroup)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabGroup<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabGroup)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabIcon) consume_Windows_UI_Shell_IWindowTabGroup<D>::Icon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabGroup)->get_Icon(&value));
        return llm::OS::UI::Shell::WindowTabIcon{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabGroup<D>::Icon(llm::OS::UI::Shell::WindowTabIcon const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabGroup)->put_Icon(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabIcon) consume_Windows_UI_Shell_IWindowTabIconStatics<D>::CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabIconStatics)->CreateFromFontGlyph(*(void**)(&glyph), *(void**)(&fontFamily), &result));
        return llm::OS::UI::Shell::WindowTabIcon{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabIcon) consume_Windows_UI_Shell_IWindowTabIconStatics<D>::CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily, llm::OS::Foundation::Uri const& fontUri) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabIconStatics)->CreateFromFontGlyphWithUri(*(void**)(&glyph), *(void**)(&fontFamily), *(void**)(&fontUri), &result));
        return llm::OS::UI::Shell::WindowTabIcon{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabIcon) consume_Windows_UI_Shell_IWindowTabIconStatics<D>::CreateFromImage(llm::OS::Storage::Streams::IRandomAccessStreamReference const& image) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabIconStatics)->CreateFromImage(*(void**)(&image), &result));
        return llm::OS::UI::Shell::WindowTabIcon{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabCollection) consume_Windows_UI_Shell_IWindowTabManager<D>::Tabs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->get_Tabs(&value));
        return llm::OS::UI::Shell::WindowTabCollection{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabManager<D>::SetActiveTab(llm::OS::UI::Shell::WindowTab const& tab) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->SetActiveTab(*(void**)(&tab)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IWindowTabManager<D>::TabSwitchRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabSwitchRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->add_TabSwitchRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IWindowTabManager<D>::TabSwitchRequested_revoker consume_Windows_UI_Shell_IWindowTabManager<D>::TabSwitchRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabSwitchRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TabSwitchRequested_revoker>(this, TabSwitchRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabManager<D>::TabSwitchRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->remove_TabSwitchRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IWindowTabManager<D>::TabCloseRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabCloseRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->add_TabCloseRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IWindowTabManager<D>::TabCloseRequested_revoker consume_Windows_UI_Shell_IWindowTabManager<D>::TabCloseRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabCloseRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TabCloseRequested_revoker>(this, TabCloseRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabManager<D>::TabCloseRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->remove_TabCloseRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IWindowTabManager<D>::TabTearOutRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabTearOutRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->add_TabTearOutRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IWindowTabManager<D>::TabTearOutRequested_revoker consume_Windows_UI_Shell_IWindowTabManager<D>::TabTearOutRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabTearOutRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TabTearOutRequested_revoker>(this, TabTearOutRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabManager<D>::TabTearOutRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->remove_TabTearOutRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_Shell_IWindowTabManager<D>::TabThumbnailRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->add_TabThumbnailRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_Shell_IWindowTabManager<D>::TabThumbnailRequested_revoker consume_Windows_UI_Shell_IWindowTabManager<D>::TabThumbnailRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TabThumbnailRequested_revoker>(this, TabThumbnailRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabManager<D>::TabThumbnailRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManager)->remove_TabThumbnailRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTabManager) consume_Windows_UI_Shell_IWindowTabManagerStatics<D>::GetForWindow(llm::OS::UI::WindowId const& id) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManagerStatics)->GetForWindow(impl::bind_in(id), &result));
        return llm::OS::UI::Shell::WindowTabManager{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_IWindowTabManagerStatics<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManagerStatics)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_IWindowTabManagerStatics<D>::IsTabTearOutSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabManagerStatics)->IsTabTearOutSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTab) consume_Windows_UI_Shell_IWindowTabSwitchRequestedEventArgs<D>::Tab() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabSwitchRequestedEventArgs)->get_Tab(&value));
        return llm::OS::UI::Shell::WindowTab{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTab) consume_Windows_UI_Shell_IWindowTabTearOutRequestedEventArgs<D>::Tab() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs)->get_Tab(&value));
        return llm::OS::UI::Shell::WindowTab{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_UI_Shell_IWindowTabTearOutRequestedEventArgs<D>::WindowId() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs)->get_WindowId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabTearOutRequestedEventArgs<D>::WindowId(uint64_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs)->put_WindowId(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Shell_IWindowTabTearOutRequestedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Shell::WindowTab) consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>::Tab() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs)->get_Tab(&value));
        return llm::OS::UI::Shell::WindowTab{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Graphics::Imaging::BitmapSize) consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>::RequestedSize() const
    {
        llm::OS::Graphics::Imaging::BitmapSize value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs)->get_RequestedSize(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>::Image() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs)->get_Image(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>::Image(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs)->put_Image(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_Shell_IWindowTabThumbnailRequestedEventArgs<D>::IsCompositedOnWindow() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs)->get_IsCompositedOnWindow(&value));
        return value;
    }
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IAdaptiveCard> : produce_base<D, llm::OS::UI::Shell::IAdaptiveCard>
    {
        int32_t __stdcall ToJson(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().ToJson());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IAdaptiveCardBuilderStatics> : produce_base<D, llm::OS::UI::Shell::IAdaptiveCardBuilderStatics>
    {
        int32_t __stdcall CreateAdaptiveCardFromJson(void* value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::IAdaptiveCard>(this->shim().CreateAdaptiveCardFromJson(*reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IFocusSession> : produce_base<D, llm::OS::UI::Shell::IFocusSession>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall End() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().End();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IFocusSessionManager> : produce_base<D, llm::OS::UI::Shell::IFocusSessionManager>
    {
        int32_t __stdcall get_IsFocusActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFocusActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSession(void* id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::FocusSession>(this->shim().GetSession(*reinterpret_cast<hstring const*>(&id)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryStartFocusSession(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::FocusSession>(this->shim().TryStartFocusSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryStartFocusSession2(int64_t endTime, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::FocusSession>(this->shim().TryStartFocusSession(*reinterpret_cast<llm::OS::Foundation::DateTime const*>(&endTime)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeactivateFocus() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeactivateFocus();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsFocusActiveChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsFocusActiveChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::FocusSessionManager, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsFocusActiveChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsFocusActiveChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IFocusSessionManagerStatics> : produce_base<D, llm::OS::UI::Shell::IFocusSessionManagerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::FocusSessionManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::ISecurityAppManager> : produce_base<D, llm::OS::UI::Shell::ISecurityAppManager>
    {
        int32_t __stdcall Register(int32_t kind, void* displayName, void* detailsUri, bool registerPerUser, llm::guid* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::guid>(this->shim().Register(*reinterpret_cast<llm::OS::UI::Shell::SecurityAppKind const*>(&kind), *reinterpret_cast<hstring const*>(&displayName), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&detailsUri), registerPerUser));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Unregister(int32_t kind, llm::guid guidRegistration) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister(*reinterpret_cast<llm::OS::UI::Shell::SecurityAppKind const*>(&kind), *reinterpret_cast<llm::guid const*>(&guidRegistration));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateState(int32_t kind, llm::guid guidRegistration, int32_t state, int32_t substatus, void* detailsUri) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateState(*reinterpret_cast<llm::OS::UI::Shell::SecurityAppKind const*>(&kind), *reinterpret_cast<llm::guid const*>(&guidRegistration), *reinterpret_cast<llm::OS::UI::Shell::SecurityAppState const*>(&state), *reinterpret_cast<llm::OS::UI::Shell::SecurityAppSubstatus const*>(&substatus), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&detailsUri));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IShareWindowCommandEventArgs> : produce_base<D, llm::OS::UI::Shell::IShareWindowCommandEventArgs>
    {
        int32_t __stdcall get_WindowId(struct struct_Windows_UI_WindowId* value) noexcept final try
        {
            zero_abi<llm::OS::UI::WindowId>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WindowId>(this->shim().WindowId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Command(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::ShareWindowCommand>(this->shim().Command());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Command(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Command(*reinterpret_cast<llm::OS::UI::Shell::ShareWindowCommand const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IShareWindowCommandSource> : produce_base<D, llm::OS::UI::Shell::IShareWindowCommandSource>
    {
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportCommandChanged() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportCommandChanged();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_CommandRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CommandRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::ShareWindowCommandSource, llm::OS::UI::Shell::ShareWindowCommandEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CommandRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommandRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CommandInvoked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CommandInvoked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::ShareWindowCommandSource, llm::OS::UI::Shell::ShareWindowCommandEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CommandInvoked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CommandInvoked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IShareWindowCommandSourceStatics> : produce_base<D, llm::OS::UI::Shell::IShareWindowCommandSourceStatics>
    {
        int32_t __stdcall GetForCurrentView(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::ShareWindowCommandSource>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::ITaskbarManager> : produce_base<D, llm::OS::UI::Shell::ITaskbarManager>
    {
        int32_t __stdcall get_IsSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsPinningAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPinningAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsCurrentAppPinnedAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsCurrentAppPinnedAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsAppListEntryPinnedAsync(void* appListEntry, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsAppListEntryPinnedAsync(*reinterpret_cast<llm::OS::ApplicationModel::Core::AppListEntry const*>(&appListEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPinCurrentAppAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestPinCurrentAppAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPinAppListEntryAsync(void* appListEntry, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestPinAppListEntryAsync(*reinterpret_cast<llm::OS::ApplicationModel::Core::AppListEntry const*>(&appListEntry)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::ITaskbarManager2> : produce_base<D, llm::OS::UI::Shell::ITaskbarManager2>
    {
        int32_t __stdcall IsSecondaryTilePinnedAsync(void* tileId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsSecondaryTilePinnedAsync(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestPinSecondaryTileAsync(void* secondaryTile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestPinSecondaryTileAsync(*reinterpret_cast<llm::OS::UI::StartScreen::SecondaryTile const*>(&secondaryTile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryUnpinSecondaryTileAsync(void* tileId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().TryUnpinSecondaryTileAsync(*reinterpret_cast<hstring const*>(&tileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics> : produce_base<D, llm::OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::ITaskbarManagerStatics> : produce_base<D, llm::OS::UI::Shell::ITaskbarManagerStatics>
    {
        int32_t __stdcall GetDefault(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::TaskbarManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTab> : produce_base<D, llm::OS::UI::Shell::IWindowTab>
    {
        int32_t __stdcall get_Tag(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Tag());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Tag(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Tag(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
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
        int32_t __stdcall get_Icon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTabIcon>(this->shim().Icon());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Icon(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Icon(*reinterpret_cast<llm::OS::UI::Shell::WindowTabIcon const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TreatAsSecondaryTileId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TreatAsSecondaryTileId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TreatAsSecondaryTileId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TreatAsSecondaryTileId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Group(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTabGroup>(this->shim().Group());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Group(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Group(*reinterpret_cast<llm::OS::UI::Shell::WindowTabGroup const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportThumbnailAvailable() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportThumbnailAvailable();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabCloseRequestedEventArgs> : produce_base<D, llm::OS::UI::Shell::IWindowTabCloseRequestedEventArgs>
    {
        int32_t __stdcall get_Tab(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTab>(this->shim().Tab());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabCollection> : produce_base<D, llm::OS::UI::Shell::IWindowTabCollection>
    {
        int32_t __stdcall MoveTab(void* tab, uint32_t index) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MoveTab(*reinterpret_cast<llm::OS::UI::Shell::WindowTab const*>(&tab), index);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabGroup> : produce_base<D, llm::OS::UI::Shell::IWindowTabGroup>
    {
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
        int32_t __stdcall get_Icon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTabIcon>(this->shim().Icon());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Icon(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Icon(*reinterpret_cast<llm::OS::UI::Shell::WindowTabIcon const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabIcon> : produce_base<D, llm::OS::UI::Shell::IWindowTabIcon>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabIconStatics> : produce_base<D, llm::OS::UI::Shell::IWindowTabIconStatics>
    {
        int32_t __stdcall CreateFromFontGlyph(void* glyph, void* fontFamily, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::WindowTabIcon>(this->shim().CreateFromFontGlyph(*reinterpret_cast<hstring const*>(&glyph), *reinterpret_cast<hstring const*>(&fontFamily)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromFontGlyphWithUri(void* glyph, void* fontFamily, void* fontUri, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::WindowTabIcon>(this->shim().CreateFromFontGlyph(*reinterpret_cast<hstring const*>(&glyph), *reinterpret_cast<hstring const*>(&fontFamily), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&fontUri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromImage(void* image, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::WindowTabIcon>(this->shim().CreateFromImage(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&image)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabManager> : produce_base<D, llm::OS::UI::Shell::IWindowTabManager>
    {
        int32_t __stdcall get_Tabs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTabCollection>(this->shim().Tabs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetActiveTab(void* tab) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetActiveTab(*reinterpret_cast<llm::OS::UI::Shell::WindowTab const*>(&tab));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_TabSwitchRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TabSwitchRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabSwitchRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TabSwitchRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TabSwitchRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TabCloseRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TabCloseRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabCloseRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TabCloseRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TabCloseRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TabTearOutRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TabTearOutRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabTearOutRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TabTearOutRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TabTearOutRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_TabThumbnailRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TabThumbnailRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::Shell::WindowTabManager, llm::OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TabThumbnailRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TabThumbnailRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabManagerStatics> : produce_base<D, llm::OS::UI::Shell::IWindowTabManagerStatics>
    {
        int32_t __stdcall GetForWindow(struct struct_Windows_UI_WindowId id, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::UI::Shell::WindowTabManager>(this->shim().GetForWindow(*reinterpret_cast<llm::OS::UI::WindowId const*>(&id)));
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
        int32_t __stdcall IsTabTearOutSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsTabTearOutSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabSwitchRequestedEventArgs> : produce_base<D, llm::OS::UI::Shell::IWindowTabSwitchRequestedEventArgs>
    {
        int32_t __stdcall get_Tab(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTab>(this->shim().Tab());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs> : produce_base<D, llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs>
    {
        int32_t __stdcall get_Tab(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTab>(this->shim().Tab());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WindowId(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().WindowId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WindowId(uint64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WindowId(value);
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
    struct produce<D, llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs> : produce_base<D, llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs>
    {
        int32_t __stdcall get_Tab(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Shell::WindowTab>(this->shim().Tab());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestedSize(struct struct_Windows_Graphics_Imaging_BitmapSize* value) noexcept final try
        {
            zero_abi<llm::OS::Graphics::Imaging::BitmapSize>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Graphics::Imaging::BitmapSize>(this->shim().RequestedSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Image(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().Image());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Image(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Image(*reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&value));
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
        int32_t __stdcall get_IsCompositedOnWindow(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCompositedOnWindow());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::Shell
{
    inline auto AdaptiveCardBuilder::CreateAdaptiveCardFromJson(param::hstring const& value)
    {
        return impl::call_factory<AdaptiveCardBuilder, IAdaptiveCardBuilderStatics>([&](IAdaptiveCardBuilderStatics const& f) { return f.CreateAdaptiveCardFromJson(value); });
    }
    inline auto FocusSessionManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::UI::Shell::FocusSessionManager(*)(IFocusSessionManagerStatics const&), FocusSessionManager, IFocusSessionManagerStatics>([](IFocusSessionManagerStatics const& f) { return f.GetDefault(); });
    }
    inline auto FocusSessionManager::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IFocusSessionManagerStatics const&), FocusSessionManager, IFocusSessionManagerStatics>([](IFocusSessionManagerStatics const& f) { return f.IsSupported(); });
    }
    inline SecurityAppManager::SecurityAppManager() :
        SecurityAppManager(impl::call_factory_cast<SecurityAppManager(*)(llm::OS::Foundation::IActivationFactory const&), SecurityAppManager>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SecurityAppManager>(); }))
    {
    }
    inline auto ShareWindowCommandSource::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::UI::Shell::ShareWindowCommandSource(*)(IShareWindowCommandSourceStatics const&), ShareWindowCommandSource, IShareWindowCommandSourceStatics>([](IShareWindowCommandSourceStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto TaskbarManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::UI::Shell::TaskbarManager(*)(ITaskbarManagerStatics const&), TaskbarManager, ITaskbarManagerStatics>([](ITaskbarManagerStatics const& f) { return f.GetDefault(); });
    }
    inline WindowTab::WindowTab() :
        WindowTab(impl::call_factory_cast<WindowTab(*)(llm::OS::Foundation::IActivationFactory const&), WindowTab>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WindowTab>(); }))
    {
    }
    inline WindowTabGroup::WindowTabGroup() :
        WindowTabGroup(impl::call_factory_cast<WindowTabGroup(*)(llm::OS::Foundation::IActivationFactory const&), WindowTabGroup>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WindowTabGroup>(); }))
    {
    }
    inline auto WindowTabIcon::CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily)
    {
        return impl::call_factory<WindowTabIcon, IWindowTabIconStatics>([&](IWindowTabIconStatics const& f) { return f.CreateFromFontGlyph(glyph, fontFamily); });
    }
    inline auto WindowTabIcon::CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily, llm::OS::Foundation::Uri const& fontUri)
    {
        return impl::call_factory<WindowTabIcon, IWindowTabIconStatics>([&](IWindowTabIconStatics const& f) { return f.CreateFromFontGlyph(glyph, fontFamily, fontUri); });
    }
    inline auto WindowTabIcon::CreateFromImage(llm::OS::Storage::Streams::IRandomAccessStreamReference const& image)
    {
        return impl::call_factory<WindowTabIcon, IWindowTabIconStatics>([&](IWindowTabIconStatics const& f) { return f.CreateFromImage(image); });
    }
    inline auto WindowTabManager::GetForWindow(llm::OS::UI::WindowId const& id)
    {
        return impl::call_factory<WindowTabManager, IWindowTabManagerStatics>([&](IWindowTabManagerStatics const& f) { return f.GetForWindow(id); });
    }
    inline auto WindowTabManager::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IWindowTabManagerStatics const&), WindowTabManager, IWindowTabManagerStatics>([](IWindowTabManagerStatics const& f) { return f.IsSupported(); });
    }
    inline auto WindowTabManager::IsTabTearOutSupported()
    {
        return impl::call_factory_cast<bool(*)(IWindowTabManagerStatics const&), WindowTabManager, IWindowTabManagerStatics>([](IWindowTabManagerStatics const& f) { return f.IsTabTearOutSupported(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::Shell::IAdaptiveCard> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IAdaptiveCardBuilderStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IFocusSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IFocusSessionManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IFocusSessionManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ISecurityAppManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IShareWindowCommandEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IShareWindowCommandSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IShareWindowCommandSourceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ITaskbarManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ITaskbarManager2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ITaskbarManagerDesktopAppSupportStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ITaskbarManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTab> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabCloseRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabIcon> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabIconStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabSwitchRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabTearOutRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::AdaptiveCardBuilder> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::FocusSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::FocusSessionManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::SecurityAppManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ShareWindowCommandEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::ShareWindowCommandSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::TaskbarManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTab> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabCloseRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabGroup> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabIcon> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabSwitchRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabTearOutRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::Shell::WindowTabThumbnailRequestedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
