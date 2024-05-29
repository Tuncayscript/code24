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
#ifndef LLM_OS_ApplicationModel_Search_1_H
#define LLM_OS_ApplicationModel_Search_1_H
#include "llm/impl/Windows.ApplicationModel.Search.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Search
{
    struct __declspec(empty_bases) ILocalContentSuggestionSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILocalContentSuggestionSettings>
    {
        ILocalContentSuggestionSettings(std::nullptr_t = nullptr) noexcept {}
        ILocalContentSuggestionSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPane :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPane>
    {
        ISearchPane(std::nullptr_t = nullptr) noexcept {}
        ISearchPane(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneQueryChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneQueryChangedEventArgs>
    {
        ISearchPaneQueryChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneQueryChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneQueryLinguisticDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneQueryLinguisticDetails>
    {
        ISearchPaneQueryLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneQueryLinguisticDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneQuerySubmittedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneQuerySubmittedEventArgs>
    {
        ISearchPaneQuerySubmittedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneQuerySubmittedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails>
    {
        ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneQuerySubmittedEventArgsWithLinguisticDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneResultSuggestionChosenEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneResultSuggestionChosenEventArgs>
    {
        ISearchPaneResultSuggestionChosenEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneResultSuggestionChosenEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneStatics>
    {
        ISearchPaneStatics(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneStaticsWithHideThisApplication :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneStaticsWithHideThisApplication>
    {
        ISearchPaneStaticsWithHideThisApplication(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneStaticsWithHideThisApplication(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneSuggestionsRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneSuggestionsRequest>
    {
        ISearchPaneSuggestionsRequest(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneSuggestionsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneSuggestionsRequestDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneSuggestionsRequestDeferral>
    {
        ISearchPaneSuggestionsRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneSuggestionsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneSuggestionsRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneSuggestionsRequestedEventArgs>,
        impl::require<llm::OS::ApplicationModel::Search::ISearchPaneSuggestionsRequestedEventArgs, llm::OS::ApplicationModel::Search::ISearchPaneQueryChangedEventArgs>
    {
        ISearchPaneSuggestionsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneSuggestionsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchPaneVisibilityChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchPaneVisibilityChangedEventArgs>
    {
        ISearchPaneVisibilityChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISearchPaneVisibilityChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchQueryLinguisticDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchQueryLinguisticDetails>
    {
        ISearchQueryLinguisticDetails(std::nullptr_t = nullptr) noexcept {}
        ISearchQueryLinguisticDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchQueryLinguisticDetailsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchQueryLinguisticDetailsFactory>
    {
        ISearchQueryLinguisticDetailsFactory(std::nullptr_t = nullptr) noexcept {}
        ISearchQueryLinguisticDetailsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchSuggestionCollection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchSuggestionCollection>
    {
        ISearchSuggestionCollection(std::nullptr_t = nullptr) noexcept {}
        ISearchSuggestionCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchSuggestionsRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchSuggestionsRequest>
    {
        ISearchSuggestionsRequest(std::nullptr_t = nullptr) noexcept {}
        ISearchSuggestionsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISearchSuggestionsRequestDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISearchSuggestionsRequestDeferral>
    {
        ISearchSuggestionsRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        ISearchSuggestionsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
