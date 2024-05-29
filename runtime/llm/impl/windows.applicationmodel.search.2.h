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
#ifndef LLM_OS_ApplicationModel_Search_2_H
#define LLM_OS_ApplicationModel_Search_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.ApplicationModel.Search.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Search
{
    struct __declspec(empty_bases) LocalContentSuggestionSettings : llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings
    {
        LocalContentSuggestionSettings(std::nullptr_t) noexcept {}
        LocalContentSuggestionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ILocalContentSuggestionSettings(ptr, take_ownership_from_abi) {}
        LocalContentSuggestionSettings();
    };
    struct __declspec(empty_bases) SearchPane : llm::OS::ApplicationModel::Search::ISearchPane
    {
        SearchPane(std::nullptr_t) noexcept {}
        SearchPane(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPane(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
        static auto HideThisApplication();
    };
    struct __declspec(empty_bases) SearchPaneQueryChangedEventArgs : llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs
    {
        SearchPaneQueryChangedEventArgs(std::nullptr_t) noexcept {}
        SearchPaneQueryChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneQueryLinguisticDetails : llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails
    {
        SearchPaneQueryLinguisticDetails(std::nullptr_t) noexcept {}
        SearchPaneQueryLinguisticDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneQueryLinguisticDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneQuerySubmittedEventArgs : llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs,
        impl::require<SearchPaneQuerySubmittedEventArgs, llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails>
    {
        SearchPaneQuerySubmittedEventArgs(std::nullptr_t) noexcept {}
        SearchPaneQuerySubmittedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneQuerySubmittedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneResultSuggestionChosenEventArgs : llm::OS::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs
    {
        SearchPaneResultSuggestionChosenEventArgs(std::nullptr_t) noexcept {}
        SearchPaneResultSuggestionChosenEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneResultSuggestionChosenEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneSuggestionsRequest : llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest
    {
        SearchPaneSuggestionsRequest(std::nullptr_t) noexcept {}
        SearchPaneSuggestionsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneSuggestionsRequestDeferral : llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral
    {
        SearchPaneSuggestionsRequestDeferral(std::nullptr_t) noexcept {}
        SearchPaneSuggestionsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneSuggestionsRequestedEventArgs : llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs
    {
        SearchPaneSuggestionsRequestedEventArgs(std::nullptr_t) noexcept {}
        SearchPaneSuggestionsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchPaneVisibilityChangedEventArgs : llm::OS::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs
    {
        SearchPaneVisibilityChangedEventArgs(std::nullptr_t) noexcept {}
        SearchPaneVisibilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchPaneVisibilityChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchQueryLinguisticDetails : llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails
    {
        SearchQueryLinguisticDetails(std::nullptr_t) noexcept {}
        SearchQueryLinguisticDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchQueryLinguisticDetails(ptr, take_ownership_from_abi) {}
        SearchQueryLinguisticDetails(param::iterable<hstring> const& queryTextAlternatives, uint32_t queryTextCompositionStart, uint32_t queryTextCompositionLength);
    };
    struct __declspec(empty_bases) SearchSuggestionCollection : llm::OS::ApplicationModel::Search::ISearchSuggestionCollection
    {
        SearchSuggestionCollection(std::nullptr_t) noexcept {}
        SearchSuggestionCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchSuggestionCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchSuggestionsRequest : llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest
    {
        SearchSuggestionsRequest(std::nullptr_t) noexcept {}
        SearchSuggestionsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchSuggestionsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchSuggestionsRequestDeferral : llm::OS::ApplicationModel::Search::ISearchSuggestionsRequestDeferral
    {
        SearchSuggestionsRequestDeferral(std::nullptr_t) noexcept {}
        SearchSuggestionsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::ISearchSuggestionsRequestDeferral(ptr, take_ownership_from_abi) {}
    };
}
#endif
