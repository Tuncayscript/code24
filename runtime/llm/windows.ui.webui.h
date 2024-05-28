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
#ifndef LLM_OS_UI_WebUI_H
#define LLM_OS_UI_WebUI_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.UI.h"
#include "llm/impl/Windows.ApplicationModel.2.h"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.ApplicationModel.Background.2.h"
#include "llm/impl/Windows.ApplicationModel.Core.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Graphics.Printing.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.Web.UI.2.h"
#include "llm/impl/Windows.UI.WebUI.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IActivatedDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IActivatedDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::ActivatedOperation) consume_Windows_UI_WebUI_IActivatedEventArgsDeferral<D>::ActivatedOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IActivatedEventArgsDeferral)->get_ActivatedOperation(&value));
        return llm::OS::UI::WebUI::ActivatedOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::ActivatedDeferral) consume_Windows_UI_WebUI_IActivatedOperation<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IActivatedOperation)->GetDeferral(&deferral));
        return llm::OS::UI::WebUI::ActivatedDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::PrintContent) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::Content() const
    {
        llm::OS::UI::WebUI::PrintContent value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_Content(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::Content(llm::OS::UI::WebUI::PrintContent const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_Content(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::LeftMargin() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_LeftMargin(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::LeftMargin(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_LeftMargin(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::TopMargin() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_TopMargin(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::TopMargin(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_TopMargin(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::RightMargin() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_RightMargin(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::RightMargin(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_RightMargin(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::BottomMargin() const
    {
        float value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_BottomMargin(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::BottomMargin(float value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_BottomMargin(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::EnableHeaderFooter() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_EnableHeaderFooter(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::EnableHeaderFooter(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_EnableHeaderFooter(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::ShrinkToFit() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_ShrinkToFit(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::ShrinkToFit(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_ShrinkToFit(value));
    }
    template <typename D> LLM_IMPL_AUTO(float) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::PercentScale() const
    {
        float pScalePercent{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_PercentScale(&pScalePercent));
        return pScalePercent;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::PercentScale(float scalePercent) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->put_PercentScale(scalePercent));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::PageRange() const
    {
        void* pstrPageRange{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->get_PageRange(&pstrPageRange));
        return hstring{ pstrPageRange, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WebUI_IHtmlPrintDocumentSource<D>::TrySetPageRange(param::hstring const& strPageRange) const
    {
        bool pfSuccess{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IHtmlPrintDocumentSource)->TrySetPageRange(*(void**)(&strPageRange), &pfSuccess));
        return pfSuccess;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::WebUIView) consume_Windows_UI_WebUI_INewWebUIViewCreatedEventArgs<D>::WebUIView() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs)->get_WebUIView(&value));
        return llm::OS::UI::WebUI::WebUIView{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::IActivatedEventArgs) consume_Windows_UI_WebUI_INewWebUIViewCreatedEventArgs<D>::ActivatedEventArgs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs)->get_ActivatedEventArgs(&value));
        return llm::OS::ApplicationModel::Activation::IActivatedEventArgs{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WebUI_INewWebUIViewCreatedEventArgs<D>::HasPendingNavigate() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs)->get_HasPendingNavigate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_UI_WebUI_INewWebUIViewCreatedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Activated(llm::OS::UI::WebUI::ActivatedEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->add_Activated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Activated_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Activated(auto_revoke_t, llm::OS::UI::WebUI::ActivatedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Activated_revoker>(this, Activated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Activated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->remove_Activated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Suspending(llm::OS::UI::WebUI::SuspendingEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->add_Suspending(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Suspending_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Suspending(auto_revoke_t, llm::OS::UI::WebUI::SuspendingEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Suspending_revoker>(this, Suspending(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Suspending(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->remove_Suspending(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Resuming(llm::OS::UI::WebUI::ResumingEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->add_Resuming(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Resuming_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Resuming(auto_revoke_t, llm::OS::UI::WebUI::ResumingEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Resuming_revoker>(this, Resuming(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Resuming(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->remove_Resuming(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Navigated(llm::OS::UI::WebUI::NavigatedEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->add_Navigated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Navigated_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Navigated(auto_revoke_t, llm::OS::UI::WebUI::NavigatedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, Navigated_revoker>(this, Navigated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics<D>::Navigated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics)->remove_Navigated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::LeavingBackground(llm::OS::UI::WebUI::LeavingBackgroundEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics2)->add_LeavingBackground(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::LeavingBackground_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::LeavingBackground(auto_revoke_t, llm::OS::UI::WebUI::LeavingBackgroundEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, LeavingBackground_revoker>(this, LeavingBackground(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::LeavingBackground(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics2)->remove_LeavingBackground(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::EnteredBackground(llm::OS::UI::WebUI::EnteredBackgroundEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics2)->add_EnteredBackground(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::EnteredBackground_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::EnteredBackground(auto_revoke_t, llm::OS::UI::WebUI::EnteredBackgroundEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, EnteredBackground_revoker>(this, EnteredBackground(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::EnteredBackground(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics2)->remove_EnteredBackground(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics2<D>::EnablePrelaunch(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics2)->EnablePrelaunch(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Core::AppRestartFailureReason>) consume_Windows_UI_WebUI_IWebUIActivationStatics3<D>::RequestRestartAsync(param::hstring const& launchArguments) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics3)->RequestRestartAsync(*(void**)(&launchArguments), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Core::AppRestartFailureReason>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Core::AppRestartFailureReason>) consume_Windows_UI_WebUI_IWebUIActivationStatics3<D>::RequestRestartForUserAsync(llm::OS::System::User const& user, param::hstring const& launchArguments) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics3)->RequestRestartForUserAsync(*(void**)(&user), *(void**)(&launchArguments), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Core::AppRestartFailureReason>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::NewWebUIViewCreated(llm::OS::Foundation::EventHandler<llm::OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics4)->add_NewWebUIViewCreated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::NewWebUIViewCreated_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::NewWebUIViewCreated(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, NewWebUIViewCreated_revoker>(this, NewWebUIViewCreated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::NewWebUIViewCreated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics4)->remove_NewWebUIViewCreated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::BackgroundActivated(llm::OS::UI::WebUI::BackgroundActivatedEventHandler const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics4)->add_BackgroundActivated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::BackgroundActivated_revoker consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::BackgroundActivated(auto_revoke_t, llm::OS::UI::WebUI::BackgroundActivatedEventHandler const& handler) const
    {
        return impl::make_event_revoker<D, BackgroundActivated_revoker>(this, BackgroundActivated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIActivationStatics4<D>::BackgroundActivated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIActivationStatics4)->remove_BackgroundActivated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstance<D>::Succeeded() const
    {
        bool succeeded{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance)->get_Succeeded(&succeeded));
        return succeeded;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstance<D>::Succeeded(bool succeeded) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance)->put_Succeeded(succeeded));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance) consume_Windows_UI_WebUI_IWebUIBackgroundTaskInstanceStatics<D>::Current() const
    {
        void* backgroundTaskInstance{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics)->get_Current(&backgroundTaskInstance));
        return llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance{ backgroundTaskInstance, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUINavigatedDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUINavigatedDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::WebUINavigatedOperation) consume_Windows_UI_WebUI_IWebUINavigatedEventArgs<D>::NavigatedOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUINavigatedEventArgs)->get_NavigatedOperation(&value));
        return llm::OS::UI::WebUI::WebUINavigatedOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::WebUI::WebUINavigatedDeferral) consume_Windows_UI_WebUI_IWebUINavigatedOperation<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUINavigatedOperation)->GetDeferral(&deferral));
        return llm::OS::UI::WebUI::WebUINavigatedDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_UI_WebUI_IWebUIView<D>::ApplicationViewId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->get_ApplicationViewId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIView<D>::Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WebUI::WebUIView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->add_Closed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIView<D>::Closed_revoker consume_Windows_UI_WebUI_IWebUIView<D>::Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WebUI::WebUIView, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Closed_revoker>(this, Closed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIView<D>::Closed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->remove_Closed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_UI_WebUI_IWebUIView<D>::Activated(llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WebUI::WebUIView, llm::OS::ApplicationModel::Activation::IActivatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->add_Activated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_UI_WebUI_IWebUIView<D>::Activated_revoker consume_Windows_UI_WebUI_IWebUIView<D>::Activated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WebUI::WebUIView, llm::OS::ApplicationModel::Activation::IActivatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Activated_revoker>(this, Activated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIView<D>::Activated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->remove_Activated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_UI_WebUI_IWebUIView<D>::IgnoreApplicationContentUriRulesNavigationRestrictions() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->get_IgnoreApplicationContentUriRulesNavigationRestrictions(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_UI_WebUI_IWebUIView<D>::IgnoreApplicationContentUriRulesNavigationRestrictions(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIView)->put_IgnoreApplicationContentUriRulesNavigationRestrictions(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>) consume_Windows_UI_WebUI_IWebUIViewStatics<D>::CreateAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIViewStatics)->CreateAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>) consume_Windows_UI_WebUI_IWebUIViewStatics<D>::CreateAsync(llm::OS::Foundation::Uri const& uri) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::UI::WebUI::IWebUIViewStatics)->CreateWithUriAsync(*(void**)(&uri), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>{ operation, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::UI::WebUI::ActivatedEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::ActivatedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::ActivatedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* eventArgs) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::Activation::IActivatedEventArgs const*>(&eventArgs));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::WebUI::BackgroundActivatedEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::BackgroundActivatedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::BackgroundActivatedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* eventArgs) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs const*>(&eventArgs));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::WebUI::EnteredBackgroundEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::EnteredBackgroundEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::EnteredBackgroundEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::IEnteredBackgroundEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::WebUI::LeavingBackgroundEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::LeavingBackgroundEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::LeavingBackgroundEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::ILeavingBackgroundEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::WebUI::NavigatedEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::NavigatedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::NavigatedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::UI::WebUI::IWebUINavigatedEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::WebUI::ResumingEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::ResumingEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::ResumingEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::UI::WebUI::SuspendingEventHandler, H> final : implements_delegate<llm::OS::UI::WebUI::SuspendingEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::UI::WebUI::SuspendingEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&sender), *reinterpret_cast<llm::OS::ApplicationModel::ISuspendingEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IActivatedDeferral> : produce_base<D, llm::OS::UI::WebUI::IActivatedDeferral>
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
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IActivatedEventArgsDeferral> : produce_base<D, llm::OS::UI::WebUI::IActivatedEventArgsDeferral>
    {
        int32_t __stdcall get_ActivatedOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WebUI::ActivatedOperation>(this->shim().ActivatedOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IActivatedOperation> : produce_base<D, llm::OS::UI::WebUI::IActivatedOperation>
    {
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::UI::WebUI::ActivatedDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IHtmlPrintDocumentSource> : produce_base<D, llm::OS::UI::WebUI::IHtmlPrintDocumentSource>
    {
        int32_t __stdcall get_Content(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WebUI::PrintContent>(this->shim().Content());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Content(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Content(*reinterpret_cast<llm::OS::UI::WebUI::PrintContent const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LeftMargin(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().LeftMargin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_LeftMargin(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeftMargin(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TopMargin(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().TopMargin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TopMargin(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TopMargin(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RightMargin(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().RightMargin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RightMargin(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RightMargin(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BottomMargin(float* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<float>(this->shim().BottomMargin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BottomMargin(float value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BottomMargin(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnableHeaderFooter(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().EnableHeaderFooter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EnableHeaderFooter(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableHeaderFooter(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShrinkToFit(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShrinkToFit());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShrinkToFit(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShrinkToFit(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PercentScale(float* pScalePercent) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *pScalePercent = detach_from<float>(this->shim().PercentScale());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PercentScale(float scalePercent) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PercentScale(scalePercent);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PageRange(void** pstrPageRange) noexcept final try
        {
            clear_abi(pstrPageRange);
            typename D::abi_guard guard(this->shim());
            *pstrPageRange = detach_from<hstring>(this->shim().PageRange());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetPageRange(void* strPageRange, bool* pfSuccess) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *pfSuccess = detach_from<bool>(this->shim().TrySetPageRange(*reinterpret_cast<hstring const*>(&strPageRange)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs> : produce_base<D, llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs>
    {
        int32_t __stdcall get_WebUIView(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WebUI::WebUIView>(this->shim().WebUIView());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivatedEventArgs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Activation::IActivatedEventArgs>(this->shim().ActivatedEventArgs());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasPendingNavigate(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasPendingNavigate());
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
    struct produce<D, llm::OS::UI::WebUI::IWebUIActivationStatics> : produce_base<D, llm::OS::UI::WebUI::IWebUIActivationStatics>
    {
        int32_t __stdcall add_Activated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Activated(*reinterpret_cast<llm::OS::UI::WebUI::ActivatedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Activated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Suspending(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Suspending(*reinterpret_cast<llm::OS::UI::WebUI::SuspendingEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Suspending(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Suspending(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Resuming(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Resuming(*reinterpret_cast<llm::OS::UI::WebUI::ResumingEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Resuming(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Resuming(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Navigated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Navigated(*reinterpret_cast<llm::OS::UI::WebUI::NavigatedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Navigated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Navigated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIActivationStatics2> : produce_base<D, llm::OS::UI::WebUI::IWebUIActivationStatics2>
    {
        int32_t __stdcall add_LeavingBackground(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().LeavingBackground(*reinterpret_cast<llm::OS::UI::WebUI::LeavingBackgroundEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_LeavingBackground(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LeavingBackground(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnteredBackground(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnteredBackground(*reinterpret_cast<llm::OS::UI::WebUI::EnteredBackgroundEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnteredBackground(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnteredBackground(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall EnablePrelaunch(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnablePrelaunch(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIActivationStatics3> : produce_base<D, llm::OS::UI::WebUI::IWebUIActivationStatics3>
    {
        int32_t __stdcall RequestRestartAsync(void* launchArguments, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Core::AppRestartFailureReason>>(this->shim().RequestRestartAsync(*reinterpret_cast<hstring const*>(&launchArguments)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestRestartForUserAsync(void* user, void* launchArguments, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Core::AppRestartFailureReason>>(this->shim().RequestRestartForUserAsync(*reinterpret_cast<llm::OS::System::User const*>(&user), *reinterpret_cast<hstring const*>(&launchArguments)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIActivationStatics4> : produce_base<D, llm::OS::UI::WebUI::IWebUIActivationStatics4>
    {
        int32_t __stdcall add_NewWebUIViewCreated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().NewWebUIViewCreated(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_NewWebUIViewCreated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NewWebUIViewCreated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_BackgroundActivated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().BackgroundActivated(*reinterpret_cast<llm::OS::UI::WebUI::BackgroundActivatedEventHandler const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_BackgroundActivated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundActivated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance> : produce_base<D, llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance>
    {
        int32_t __stdcall get_Succeeded(bool* succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Succeeded(bool succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Succeeded(succeeded);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics> : produce_base<D, llm::OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics>
    {
        int32_t __stdcall get_Current(void** backgroundTaskInstance) noexcept final try
        {
            clear_abi(backgroundTaskInstance);
            typename D::abi_guard guard(this->shim());
            *backgroundTaskInstance = detach_from<llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance>(this->shim().Current());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUINavigatedDeferral> : produce_base<D, llm::OS::UI::WebUI::IWebUINavigatedDeferral>
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
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUINavigatedEventArgs> : produce_base<D, llm::OS::UI::WebUI::IWebUINavigatedEventArgs>
    {
        int32_t __stdcall get_NavigatedOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::WebUI::WebUINavigatedOperation>(this->shim().NavigatedOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUINavigatedOperation> : produce_base<D, llm::OS::UI::WebUI::IWebUINavigatedOperation>
    {
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::UI::WebUI::WebUINavigatedDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIView> : produce_base<D, llm::OS::UI::WebUI::IWebUIView>
    {
        int32_t __stdcall get_ApplicationViewId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ApplicationViewId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Closed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Closed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WebUI::WebUIView, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Closed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Closed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Activated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Activated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::UI::WebUI::WebUIView, llm::OS::ApplicationModel::Activation::IActivatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Activated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Activated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_IgnoreApplicationContentUriRulesNavigationRestrictions(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IgnoreApplicationContentUriRulesNavigationRestrictions());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IgnoreApplicationContentUriRulesNavigationRestrictions(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IgnoreApplicationContentUriRulesNavigationRestrictions(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::UI::WebUI::IWebUIViewStatics> : produce_base<D, llm::OS::UI::WebUI::IWebUIViewStatics>
    {
        int32_t __stdcall CreateAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>>(this->shim().CreateAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWithUriAsync(void* uri, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>>(this->shim().CreateAsync(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&uri)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::UI::WebUI
{
    inline auto WebUIApplication::Activated(llm::OS::UI::WebUI::ActivatedEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Activated(handler); });
    }
    inline WebUIApplication::Activated_revoker WebUIApplication::Activated(auto_revoke_t, llm::OS::UI::WebUI::ActivatedEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics>();
        return { f, f.Activated(handler) };
    }
    inline auto WebUIApplication::Activated(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Activated(token); });
    }
    inline auto WebUIApplication::Suspending(llm::OS::UI::WebUI::SuspendingEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Suspending(handler); });
    }
    inline WebUIApplication::Suspending_revoker WebUIApplication::Suspending(auto_revoke_t, llm::OS::UI::WebUI::SuspendingEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics>();
        return { f, f.Suspending(handler) };
    }
    inline auto WebUIApplication::Suspending(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Suspending(token); });
    }
    inline auto WebUIApplication::Resuming(llm::OS::UI::WebUI::ResumingEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Resuming(handler); });
    }
    inline WebUIApplication::Resuming_revoker WebUIApplication::Resuming(auto_revoke_t, llm::OS::UI::WebUI::ResumingEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics>();
        return { f, f.Resuming(handler) };
    }
    inline auto WebUIApplication::Resuming(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Resuming(token); });
    }
    inline auto WebUIApplication::Navigated(llm::OS::UI::WebUI::NavigatedEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Navigated(handler); });
    }
    inline WebUIApplication::Navigated_revoker WebUIApplication::Navigated(auto_revoke_t, llm::OS::UI::WebUI::NavigatedEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics>();
        return { f, f.Navigated(handler) };
    }
    inline auto WebUIApplication::Navigated(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics>([&](IWebUIActivationStatics const& f) { return f.Navigated(token); });
    }
    inline auto WebUIApplication::LeavingBackground(llm::OS::UI::WebUI::LeavingBackgroundEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics2>([&](IWebUIActivationStatics2 const& f) { return f.LeavingBackground(handler); });
    }
    inline WebUIApplication::LeavingBackground_revoker WebUIApplication::LeavingBackground(auto_revoke_t, llm::OS::UI::WebUI::LeavingBackgroundEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics2>();
        return { f, f.LeavingBackground(handler) };
    }
    inline auto WebUIApplication::LeavingBackground(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics2>([&](IWebUIActivationStatics2 const& f) { return f.LeavingBackground(token); });
    }
    inline auto WebUIApplication::EnteredBackground(llm::OS::UI::WebUI::EnteredBackgroundEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics2>([&](IWebUIActivationStatics2 const& f) { return f.EnteredBackground(handler); });
    }
    inline WebUIApplication::EnteredBackground_revoker WebUIApplication::EnteredBackground(auto_revoke_t, llm::OS::UI::WebUI::EnteredBackgroundEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics2>();
        return { f, f.EnteredBackground(handler) };
    }
    inline auto WebUIApplication::EnteredBackground(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics2>([&](IWebUIActivationStatics2 const& f) { return f.EnteredBackground(token); });
    }
    inline auto WebUIApplication::EnablePrelaunch(bool value)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics2>([&](IWebUIActivationStatics2 const& f) { return f.EnablePrelaunch(value); });
    }
    inline auto WebUIApplication::RequestRestartAsync(param::hstring const& launchArguments)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics3>([&](IWebUIActivationStatics3 const& f) { return f.RequestRestartAsync(launchArguments); });
    }
    inline auto WebUIApplication::RequestRestartForUserAsync(llm::OS::System::User const& user, param::hstring const& launchArguments)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics3>([&](IWebUIActivationStatics3 const& f) { return f.RequestRestartForUserAsync(user, launchArguments); });
    }
    inline auto WebUIApplication::NewWebUIViewCreated(llm::OS::Foundation::EventHandler<llm::OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics4>([&](IWebUIActivationStatics4 const& f) { return f.NewWebUIViewCreated(handler); });
    }
    inline WebUIApplication::NewWebUIViewCreated_revoker WebUIApplication::NewWebUIViewCreated(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::UI::WebUI::NewWebUIViewCreatedEventArgs> const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics4>();
        return { f, f.NewWebUIViewCreated(handler) };
    }
    inline auto WebUIApplication::NewWebUIViewCreated(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics4>([&](IWebUIActivationStatics4 const& f) { return f.NewWebUIViewCreated(token); });
    }
    inline auto WebUIApplication::BackgroundActivated(llm::OS::UI::WebUI::BackgroundActivatedEventHandler const& handler)
    {
        return impl::call_factory<WebUIApplication, IWebUIActivationStatics4>([&](IWebUIActivationStatics4 const& f) { return f.BackgroundActivated(handler); });
    }
    inline WebUIApplication::BackgroundActivated_revoker WebUIApplication::BackgroundActivated(auto_revoke_t, llm::OS::UI::WebUI::BackgroundActivatedEventHandler const& handler)
    {
        auto f = get_activation_factory<WebUIApplication, llm::OS::UI::WebUI::IWebUIActivationStatics4>();
        return { f, f.BackgroundActivated(handler) };
    }
    inline auto WebUIApplication::BackgroundActivated(llm::event_token const& token)
    {
        impl::call_factory<WebUIApplication, IWebUIActivationStatics4>([&](IWebUIActivationStatics4 const& f) { return f.BackgroundActivated(token); });
    }
    inline auto WebUIBackgroundTaskInstance::Current()
    {
        return impl::call_factory_cast<llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance(*)(IWebUIBackgroundTaskInstanceStatics const&), WebUIBackgroundTaskInstance, IWebUIBackgroundTaskInstanceStatics>([](IWebUIBackgroundTaskInstanceStatics const& f) { return f.Current(); });
    }
    inline auto WebUIView::CreateAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::UI::WebUI::WebUIView>(*)(IWebUIViewStatics const&), WebUIView, IWebUIViewStatics>([](IWebUIViewStatics const& f) { return f.CreateAsync(); });
    }
    inline auto WebUIView::CreateAsync(llm::OS::Foundation::Uri const& uri)
    {
        return impl::call_factory<WebUIView, IWebUIViewStatics>([&](IWebUIViewStatics const& f) { return f.CreateAsync(uri); });
    }
    template <typename L> ActivatedEventHandler::ActivatedEventHandler(L handler) :
        ActivatedEventHandler(impl::make_delegate<ActivatedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> ActivatedEventHandler::ActivatedEventHandler(F* handler) :
        ActivatedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> ActivatedEventHandler::ActivatedEventHandler(O* object, M method) :
        ActivatedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> ActivatedEventHandler::ActivatedEventHandler(com_ptr<O>&& object, M method) :
        ActivatedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> ActivatedEventHandler::ActivatedEventHandler(weak_ref<O>&& object, M method) :
        ActivatedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto ActivatedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::Activation::IActivatedEventArgs const& eventArgs) const
    {
        check_hresult((*(impl::abi_t<ActivatedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&eventArgs)));
    }
    template <typename L> BackgroundActivatedEventHandler::BackgroundActivatedEventHandler(L handler) :
        BackgroundActivatedEventHandler(impl::make_delegate<BackgroundActivatedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> BackgroundActivatedEventHandler::BackgroundActivatedEventHandler(F* handler) :
        BackgroundActivatedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> BackgroundActivatedEventHandler::BackgroundActivatedEventHandler(O* object, M method) :
        BackgroundActivatedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundActivatedEventHandler::BackgroundActivatedEventHandler(com_ptr<O>&& object, M method) :
        BackgroundActivatedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> BackgroundActivatedEventHandler::BackgroundActivatedEventHandler(weak_ref<O>&& object, M method) :
        BackgroundActivatedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto BackgroundActivatedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs const& eventArgs) const
    {
        check_hresult((*(impl::abi_t<BackgroundActivatedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&eventArgs)));
    }
    template <typename L> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(L handler) :
        EnteredBackgroundEventHandler(impl::make_delegate<EnteredBackgroundEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(F* handler) :
        EnteredBackgroundEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(O* object, M method) :
        EnteredBackgroundEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(com_ptr<O>&& object, M method) :
        EnteredBackgroundEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> EnteredBackgroundEventHandler::EnteredBackgroundEventHandler(weak_ref<O>&& object, M method) :
        EnteredBackgroundEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto EnteredBackgroundEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::IEnteredBackgroundEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<EnteredBackgroundEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(L handler) :
        LeavingBackgroundEventHandler(impl::make_delegate<LeavingBackgroundEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(F* handler) :
        LeavingBackgroundEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(O* object, M method) :
        LeavingBackgroundEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(com_ptr<O>&& object, M method) :
        LeavingBackgroundEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> LeavingBackgroundEventHandler::LeavingBackgroundEventHandler(weak_ref<O>&& object, M method) :
        LeavingBackgroundEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto LeavingBackgroundEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::ILeavingBackgroundEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<LeavingBackgroundEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> NavigatedEventHandler::NavigatedEventHandler(L handler) :
        NavigatedEventHandler(impl::make_delegate<NavigatedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> NavigatedEventHandler::NavigatedEventHandler(F* handler) :
        NavigatedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(O* object, M method) :
        NavigatedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(com_ptr<O>&& object, M method) :
        NavigatedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> NavigatedEventHandler::NavigatedEventHandler(weak_ref<O>&& object, M method) :
        NavigatedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto NavigatedEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::UI::WebUI::IWebUINavigatedEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<NavigatedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
    template <typename L> ResumingEventHandler::ResumingEventHandler(L handler) :
        ResumingEventHandler(impl::make_delegate<ResumingEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> ResumingEventHandler::ResumingEventHandler(F* handler) :
        ResumingEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> ResumingEventHandler::ResumingEventHandler(O* object, M method) :
        ResumingEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> ResumingEventHandler::ResumingEventHandler(com_ptr<O>&& object, M method) :
        ResumingEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> ResumingEventHandler::ResumingEventHandler(weak_ref<O>&& object, M method) :
        ResumingEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto ResumingEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender) const
    {
        check_hresult((*(impl::abi_t<ResumingEventHandler>**)this)->Invoke(*(void**)(&sender)));
    }
    template <typename L> SuspendingEventHandler::SuspendingEventHandler(L handler) :
        SuspendingEventHandler(impl::make_delegate<SuspendingEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> SuspendingEventHandler::SuspendingEventHandler(F* handler) :
        SuspendingEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> SuspendingEventHandler::SuspendingEventHandler(O* object, M method) :
        SuspendingEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> SuspendingEventHandler::SuspendingEventHandler(com_ptr<O>&& object, M method) :
        SuspendingEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> SuspendingEventHandler::SuspendingEventHandler(weak_ref<O>&& object, M method) :
        SuspendingEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto SuspendingEventHandler::operator()(llm::OS::Foundation::IInspectable const& sender, llm::OS::ApplicationModel::ISuspendingEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<SuspendingEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::UI::WebUI::IActivatedDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IActivatedEventArgsDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IActivatedOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IHtmlPrintDocumentSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::INewWebUIViewCreatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIActivationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIActivationStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIActivationStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIActivationStatics4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIBackgroundTaskInstance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIBackgroundTaskInstanceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUINavigatedDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUINavigatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUINavigatedOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::IWebUIViewStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::ActivatedDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::ActivatedOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::BackgroundActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::EnteredBackgroundEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::HtmlPrintDocumentSource> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::LeavingBackgroundEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::NewWebUIViewCreatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::SuspendingDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::SuspendingEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::SuspendingOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIApplication> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIAppointmentsProviderAddAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIAppointmentsProviderRemoveAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIAppointmentsProviderReplaceAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIAppointmentsProviderShowTimeFrameActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIBackgroundTaskInstance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIBackgroundTaskInstanceRuntimeClass> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIBarcodeScannerPreviewActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUICachedFileUpdaterActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUICameraSettingsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUICommandLineActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactMapActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactMessageActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactPanelActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactPickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactPostActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIContactVideoCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIDeviceActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIDevicePairingActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIDialReceiverActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIFileActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIFileOpenPickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIFileOpenPickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIFileSavePickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIFileSavePickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIFolderPickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUILaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUILockScreenActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUILockScreenCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUILockScreenComponentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUINavigatedDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUINavigatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUINavigatedOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIPhoneCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIPrint3DWorkflowActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIPrintTaskSettingsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIPrintWorkflowForegroundTaskActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIProtocolActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIProtocolForResultsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIRestrictedLaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUISearchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIShareTargetActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIStartupTaskActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIToastNotificationActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIUserDataAccountProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIView> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIVoiceCommandActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIWalletActionActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIWebAccountProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::UI::WebUI::WebUIWebAuthenticationBrokerContinuationEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
