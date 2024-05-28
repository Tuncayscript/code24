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
#ifndef LLM_OS_ApplicationModel_Search_H
#define LLM_OS_ApplicationModel_Search_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.Search.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ILocalContentSuggestionSettings<D>::Enabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings)->put_Enabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ILocalContentSuggestionSettings<D>::Enabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings)->get_Enabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Storage::StorageFolder>) consume_Windows_ApplicationModel_Search_ILocalContentSuggestionSettings<D>::Locations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings)->get_Locations(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Storage::StorageFolder>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ILocalContentSuggestionSettings<D>::AqsFilter(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings)->put_AqsFilter(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ILocalContentSuggestionSettings<D>::AqsFilter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings)->get_AqsFilter(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_ApplicationModel_Search_ILocalContentSuggestionSettings<D>::PropertiesToMatch() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings)->get_PropertiesToMatch(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SearchHistoryEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->put_SearchHistoryEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SearchHistoryEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_SearchHistoryEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SearchHistoryContext(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->put_SearchHistoryContext(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SearchHistoryContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_SearchHistoryContext(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::PlaceholderText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->put_PlaceholderText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPane<D>::PlaceholderText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_PlaceholderText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPane<D>::QueryText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_QueryText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPane<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchPane<D>::Visible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_Visible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Search_ISearchPane<D>::VisibilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->add_VisibilityChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Search_ISearchPane<D>::VisibilityChanged_revoker consume_Windows_ApplicationModel_Search_ISearchPane<D>::VisibilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, VisibilityChanged_revoker>(this, VisibilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::VisibilityChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->remove_VisibilityChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Search_ISearchPane<D>::QueryChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->add_QueryChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Search_ISearchPane<D>::QueryChanged_revoker consume_Windows_ApplicationModel_Search_ISearchPane<D>::QueryChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, QueryChanged_revoker>(this, QueryChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::QueryChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->remove_QueryChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SuggestionsRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->add_SuggestionsRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Search_ISearchPane<D>::SuggestionsRequested_revoker consume_Windows_ApplicationModel_Search_ISearchPane<D>::SuggestionsRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SuggestionsRequested_revoker>(this, SuggestionsRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SuggestionsRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->remove_SuggestionsRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Search_ISearchPane<D>::QuerySubmitted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->add_QuerySubmitted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Search_ISearchPane<D>::QuerySubmitted_revoker consume_Windows_ApplicationModel_Search_ISearchPane<D>::QuerySubmitted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, QuerySubmitted_revoker>(this, QuerySubmitted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::QuerySubmitted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->remove_QuerySubmitted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Search_ISearchPane<D>::ResultSuggestionChosen(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->add_ResultSuggestionChosen(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Search_ISearchPane<D>::ResultSuggestionChosen_revoker consume_Windows_ApplicationModel_Search_ISearchPane<D>::ResultSuggestionChosen(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ResultSuggestionChosen_revoker>(this, ResultSuggestionChosen(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::ResultSuggestionChosen(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->remove_ResultSuggestionChosen(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::SetLocalContentSuggestionSettings(llm::OS::ApplicationModel::Search::LocalContentSuggestionSettings const& settings) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->SetLocalContentSuggestionSettings(*(void**)(&settings)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::Show() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->ShowOverloadDefault());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::Show(param::hstring const& query) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->ShowOverloadWithQuery(*(void**)(&query)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPane<D>::ShowOnKeyboardInput(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->put_ShowOnKeyboardInput(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchPane<D>::ShowOnKeyboardInput() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->get_ShowOnKeyboardInput(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchPane<D>::TrySetQueryText(param::hstring const& query) const
    {
        bool succeeded{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPane)->TrySetQueryText(*(void**)(&query), &succeeded));
        return succeeded;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPaneQueryChangedEventArgs<D>::QueryText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs)->get_QueryText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPaneQueryChangedEventArgs<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails) consume_Windows_ApplicationModel_Search_ISearchPaneQueryChangedEventArgs<D>::LinguisticDetails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs)->get_LinguisticDetails(&value));
        return llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_ApplicationModel_Search_ISearchPaneQueryLinguisticDetails<D>::QueryTextAlternatives() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails)->get_QueryTextAlternatives(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Search_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionStart() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails)->get_QueryTextCompositionStart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Search_ISearchPaneQueryLinguisticDetails<D>::QueryTextCompositionLength() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails)->get_QueryTextCompositionLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPaneQuerySubmittedEventArgs<D>::QueryText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs)->get_QueryText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPaneQuerySubmittedEventArgs<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails) consume_Windows_ApplicationModel_Search_ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails<D>::LinguisticDetails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails)->get_LinguisticDetails(&value));
        return llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Search_ISearchPaneResultSuggestionChosenEventArgs<D>::Tag() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs)->get_Tag(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchPane) consume_Windows_ApplicationModel_Search_ISearchPaneStatics<D>::GetForCurrentView() const
    {
        void* searchPane{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneStatics)->GetForCurrentView(&searchPane));
        return llm::OS::ApplicationModel::Search::SearchPane{ searchPane, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPaneStaticsWithHideThisApplication<D>::HideThisApplication() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication)->HideThisApplication());
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchPaneSuggestionsRequest<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchSuggestionCollection) consume_Windows_ApplicationModel_Search_ISearchPaneSuggestionsRequest<D>::SearchSuggestionCollection() const
    {
        void* collection{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest)->get_SearchSuggestionCollection(&collection));
        return llm::OS::ApplicationModel::Search::SearchSuggestionCollection{ collection, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral) consume_Windows_ApplicationModel_Search_ISearchPaneSuggestionsRequest<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest)->GetDeferral(&deferral));
        return llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchPaneSuggestionsRequestDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral)->Complete());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequest) consume_Windows_ApplicationModel_Search_ISearchPaneSuggestionsRequestedEventArgs<D>::Request() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs)->get_Request(&value));
        return llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequest{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchPaneVisibilityChangedEventArgs<D>::Visible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs)->get_Visible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_ApplicationModel_Search_ISearchQueryLinguisticDetails<D>::QueryTextAlternatives() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails)->get_QueryTextAlternatives(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Search_ISearchQueryLinguisticDetails<D>::QueryTextCompositionStart() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails)->get_QueryTextCompositionStart(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Search_ISearchQueryLinguisticDetails<D>::QueryTextCompositionLength() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails)->get_QueryTextCompositionLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchQueryLinguisticDetails) consume_Windows_ApplicationModel_Search_ISearchQueryLinguisticDetailsFactory<D>::CreateInstance(param::iterable<hstring> const& queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory)->CreateInstance(*(void**)(&queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength, &value));
        return llm::OS::ApplicationModel::Search::SearchQueryLinguisticDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_Search_ISearchSuggestionCollection<D>::Size() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionCollection)->get_Size(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchSuggestionCollection<D>::AppendQuerySuggestion(param::hstring const& text) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionCollection)->AppendQuerySuggestion(*(void**)(&text)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchSuggestionCollection<D>::AppendQuerySuggestions(param::iterable<hstring> const& suggestions) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionCollection)->AppendQuerySuggestions(*(void**)(&suggestions)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchSuggestionCollection<D>::AppendResultSuggestion(param::hstring const& text, param::hstring const& detailText, param::hstring const& tag, llm::OS::Storage::Streams::IRandomAccessStreamReference const& image, param::hstring const& imageAlternateText) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionCollection)->AppendResultSuggestion(*(void**)(&text), *(void**)(&detailText), *(void**)(&tag), *(void**)(&image), *(void**)(&imageAlternateText)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchSuggestionCollection<D>::AppendSearchSeparator(param::hstring const& label) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionCollection)->AppendSearchSeparator(*(void**)(&label)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Search_ISearchSuggestionsRequest<D>::IsCanceled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest)->get_IsCanceled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchSuggestionCollection) consume_Windows_ApplicationModel_Search_ISearchSuggestionsRequest<D>::SearchSuggestionCollection() const
    {
        void* collection{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest)->get_SearchSuggestionCollection(&collection));
        return llm::OS::ApplicationModel::Search::SearchSuggestionCollection{ collection, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchSuggestionsRequestDeferral) consume_Windows_ApplicationModel_Search_ISearchSuggestionsRequest<D>::GetDeferral() const
    {
        void* deferral{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest)->GetDeferral(&deferral));
        return llm::OS::ApplicationModel::Search::SearchSuggestionsRequestDeferral{ deferral, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Search_ISearchSuggestionsRequestDeferral<D>::Complete() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Search::ISearchSuggestionsRequestDeferral)->Complete());
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings> : produce_base<D, llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings>
    {
        int32_t __stdcall put_Enabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Enabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Enabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Enabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Locations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Storage::StorageFolder>>(this->shim().Locations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AqsFilter(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AqsFilter(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AqsFilter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AqsFilter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PropertiesToMatch(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().PropertiesToMatch());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPane> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPane>
    {
        int32_t __stdcall put_SearchHistoryEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchHistoryEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SearchHistoryEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().SearchHistoryEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SearchHistoryContext(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SearchHistoryContext(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SearchHistoryContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SearchHistoryContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PlaceholderText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaceholderText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaceholderText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PlaceholderText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QueryText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
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
        int32_t __stdcall add_VisibilityChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().VisibilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_VisibilityChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VisibilityChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_QueryChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().QueryChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_QueryChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QueryChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SuggestionsRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SuggestionsRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SuggestionsRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SuggestionsRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_QuerySubmitted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().QuerySubmitted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_QuerySubmitted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().QuerySubmitted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ResultSuggestionChosen(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ResultSuggestionChosen(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Search::SearchPane, llm::OS::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ResultSuggestionChosen(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ResultSuggestionChosen(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall SetLocalContentSuggestionSettings(void* settings) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetLocalContentSuggestionSettings(*reinterpret_cast<llm::OS::ApplicationModel::Search::LocalContentSuggestionSettings const*>(&settings));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowOverloadDefault() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowOverloadWithQuery(void* query) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<hstring const*>(&query));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShowOnKeyboardInput(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowOnKeyboardInput(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShowOnKeyboardInput(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShowOnKeyboardInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TrySetQueryText(void* query, bool* succeeded) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *succeeded = detach_from<bool>(this->shim().TrySetQueryText(*reinterpret_cast<hstring const*>(&query)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>
    {
        int32_t __stdcall get_QueryText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QueryText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LinguisticDetails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails>(this->shim().LinguisticDetails());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails>
    {
        int32_t __stdcall get_QueryTextAlternatives(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().QueryTextAlternatives());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryTextCompositionStart(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().QueryTextCompositionStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryTextCompositionLength(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().QueryTextCompositionLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs>
    {
        int32_t __stdcall get_QueryText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QueryText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails>
    {
        int32_t __stdcall get_LinguisticDetails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails>(this->shim().LinguisticDetails());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs>
    {
        int32_t __stdcall get_Tag(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Tag());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneStatics> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneStatics>
    {
        int32_t __stdcall GetForCurrentView(void** searchPane) noexcept final try
        {
            clear_abi(searchPane);
            typename D::abi_guard guard(this->shim());
            *searchPane = detach_from<llm::OS::ApplicationModel::Search::SearchPane>(this->shim().GetForCurrentView());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication>
    {
        int32_t __stdcall HideThisApplication() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().HideThisApplication();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest>
    {
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SearchSuggestionCollection(void** collection) noexcept final try
        {
            clear_abi(collection);
            typename D::abi_guard guard(this->shim());
            *collection = detach_from<llm::OS::ApplicationModel::Search::SearchSuggestionCollection>(this->shim().SearchSuggestionCollection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral>
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
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs>
    {
        int32_t __stdcall get_Request(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequest>(this->shim().Request());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs>
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
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails>
    {
        int32_t __stdcall get_QueryTextAlternatives(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().QueryTextAlternatives());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryTextCompositionStart(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().QueryTextCompositionStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_QueryTextCompositionLength(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().QueryTextCompositionLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory>
    {
        int32_t __stdcall CreateInstance(void* queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Search::SearchQueryLinguisticDetails>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&queryTextAlternatives), queryTextCompositionStart, queryTextCompositionLength));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchSuggestionCollection> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchSuggestionCollection>
    {
        int32_t __stdcall get_Size(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AppendQuerySuggestion(void* text) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendQuerySuggestion(*reinterpret_cast<hstring const*>(&text));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AppendQuerySuggestions(void* suggestions) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendQuerySuggestions(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&suggestions));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AppendResultSuggestion(void* text, void* detailText, void* tag, void* image, void* imageAlternateText) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendResultSuggestion(*reinterpret_cast<hstring const*>(&text), *reinterpret_cast<hstring const*>(&detailText), *reinterpret_cast<hstring const*>(&tag), *reinterpret_cast<llm::OS::Storage::Streams::IRandomAccessStreamReference const*>(&image), *reinterpret_cast<hstring const*>(&imageAlternateText));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AppendSearchSeparator(void* label) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendSearchSeparator(*reinterpret_cast<hstring const*>(&label));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest>
    {
        int32_t __stdcall get_IsCanceled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCanceled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SearchSuggestionCollection(void** collection) noexcept final try
        {
            clear_abi(collection);
            typename D::abi_guard guard(this->shim());
            *collection = detach_from<llm::OS::ApplicationModel::Search::SearchSuggestionCollection>(this->shim().SearchSuggestionCollection());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** deferral) noexcept final try
        {
            clear_abi(deferral);
            typename D::abi_guard guard(this->shim());
            *deferral = detach_from<llm::OS::ApplicationModel::Search::SearchSuggestionsRequestDeferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> : produce_base<D, llm::OS::ApplicationModel::Search::ISearchSuggestionsRequestDeferral>
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
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Search
{
    inline LocalContentSuggestionSettings::LocalContentSuggestionSettings() :
        LocalContentSuggestionSettings(impl::call_factory_cast<LocalContentSuggestionSettings(*)(llm::OS::Foundation::IActivationFactory const&), LocalContentSuggestionSettings>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<LocalContentSuggestionSettings>(); }))
    {
    }
    inline auto SearchPane::GetForCurrentView()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::Search::SearchPane(*)(ISearchPaneStatics const&), SearchPane, ISearchPaneStatics>([](ISearchPaneStatics const& f) { return f.GetForCurrentView(); });
    }
    inline auto SearchPane::HideThisApplication()
    {
        impl::call_factory_cast<void(*)(ISearchPaneStaticsWithHideThisApplication const&), SearchPane, ISearchPaneStaticsWithHideThisApplication>([](ISearchPaneStaticsWithHideThisApplication const& f) { return f.HideThisApplication(); });
    }
    inline SearchQueryLinguisticDetails::SearchQueryLinguisticDetails(param::iterable<hstring> const& queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength) :
        SearchQueryLinguisticDetails(impl::call_factory<SearchQueryLinguisticDetails, ISearchQueryLinguisticDetailsFactory>([&](ISearchQueryLinguisticDetailsFactory const& f) { return f.CreateInstance(queryTextAlternatives, queryTextCompositionStart, queryTextCompositionLength); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneStaticsWithHideThisApplication> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetailsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchSuggestionCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::ISearchSuggestionsRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::LocalContentSuggestionSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPane> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneQueryChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneQuerySubmittedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneResultSuggestionChosenEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestDeferral> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneSuggestionsRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchPaneVisibilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchQueryLinguisticDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchSuggestionCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchSuggestionsRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Search::SearchSuggestionsRequestDeferral> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
