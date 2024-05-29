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
#ifndef LLM_OS_ApplicationModel_Search_Core_2_H
#define LLM_OS_ApplicationModel_Search_Core_2_H
#include "llm/impl/Windows.ApplicationModel.Search.Core.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Search::Core
{
    struct __declspec(empty_bases) RequestingFocusOnKeyboardInputEventArgs : llm::OS::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs
    {
        RequestingFocusOnKeyboardInputEventArgs(std::nullptr_t) noexcept {}
        RequestingFocusOnKeyboardInputEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::Core::IRequestingFocusOnKeyboardInputEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchSuggestion : llm::OS::ApplicationModel::Search::Core::ISearchSuggestion
    {
        SearchSuggestion(std::nullptr_t) noexcept {}
        SearchSuggestion(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::Core::ISearchSuggestion(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SearchSuggestionManager : llm::OS::ApplicationModel::Search::Core::ISearchSuggestionManager
    {
        SearchSuggestionManager(std::nullptr_t) noexcept {}
        SearchSuggestionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::Core::ISearchSuggestionManager(ptr, take_ownership_from_abi) {}
        SearchSuggestionManager();
    };
    struct __declspec(empty_bases) SearchSuggestionsRequestedEventArgs : llm::OS::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs
    {
        SearchSuggestionsRequestedEventArgs(std::nullptr_t) noexcept {}
        SearchSuggestionsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Search::Core::ISearchSuggestionsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
