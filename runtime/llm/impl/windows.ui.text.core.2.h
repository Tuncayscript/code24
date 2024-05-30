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
#ifndef LLM_OS_UI_Text_Core_2_H
#define LLM_OS_UI_Text_Core_2_H
#include "llm/impl/Windows.UI.Text.Core.1.h"
LLM_EXPORT namespace llm:OS::UI::Text::Core
{
    struct CoreTextRange
    {
        int32_t StartCaretPosition;
        int32_t EndCaretPosition;
    };
    inline bool operator==(CoreTextRange const& left, CoreTextRange const& right) noexcept
    {
        return left.StartCaretPosition == right.StartCaretPosition && left.EndCaretPosition == right.EndCaretPosition;
    }
    inline bool operator!=(CoreTextRange const& left, CoreTextRange const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) CoreTextCompositionCompletedEventArgs : llm:OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs
    {
        CoreTextCompositionCompletedEventArgs(std::nullptr_t) noexcept {}
        CoreTextCompositionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextCompositionCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextCompositionSegment : llm:OS::UI::Text::Core::ICoreTextCompositionSegment
    {
        CoreTextCompositionSegment(std::nullptr_t) noexcept {}
        CoreTextCompositionSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextCompositionSegment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextCompositionStartedEventArgs : llm:OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs
    {
        CoreTextCompositionStartedEventArgs(std::nullptr_t) noexcept {}
        CoreTextCompositionStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextCompositionStartedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextEditContext : llm:OS::UI::Text::Core::ICoreTextEditContext,
        impl::require<CoreTextEditContext, llm:OS::UI::Text::Core::ICoreTextEditContext2>
    {
        CoreTextEditContext(std::nullptr_t) noexcept {}
        CoreTextEditContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextEditContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextFormatUpdatingEventArgs : llm:OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs
    {
        CoreTextFormatUpdatingEventArgs(std::nullptr_t) noexcept {}
        CoreTextFormatUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextFormatUpdatingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextLayoutBounds : llm:OS::UI::Text::Core::ICoreTextLayoutBounds
    {
        CoreTextLayoutBounds(std::nullptr_t) noexcept {}
        CoreTextLayoutBounds(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextLayoutBounds(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextLayoutRequest : llm:OS::UI::Text::Core::ICoreTextLayoutRequest,
        impl::require<CoreTextLayoutRequest, llm:OS::UI::Text::Core::ICoreTextLayoutRequest2>
    {
        CoreTextLayoutRequest(std::nullptr_t) noexcept {}
        CoreTextLayoutRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextLayoutRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextLayoutRequestedEventArgs : llm:OS::UI::Text::Core::ICoreTextLayoutRequestedEventArgs
    {
        CoreTextLayoutRequestedEventArgs(std::nullptr_t) noexcept {}
        CoreTextLayoutRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextLayoutRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextSelectionRequest : llm:OS::UI::Text::Core::ICoreTextSelectionRequest
    {
        CoreTextSelectionRequest(std::nullptr_t) noexcept {}
        CoreTextSelectionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextSelectionRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextSelectionRequestedEventArgs : llm:OS::UI::Text::Core::ICoreTextSelectionRequestedEventArgs
    {
        CoreTextSelectionRequestedEventArgs(std::nullptr_t) noexcept {}
        CoreTextSelectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextSelectionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextSelectionUpdatingEventArgs : llm:OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs
    {
        CoreTextSelectionUpdatingEventArgs(std::nullptr_t) noexcept {}
        CoreTextSelectionUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextSelectionUpdatingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct CoreTextServicesConstants
    {
        CoreTextServicesConstants() = delete;
        [[nodiscard]] static auto HiddenCharacter();
    };
    struct __declspec(empty_bases) CoreTextServicesManager : llm:OS::UI::Text::Core::ICoreTextServicesManager
    {
        CoreTextServicesManager(std::nullptr_t) noexcept {}
        CoreTextServicesManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextServicesManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) CoreTextTextRequest : llm:OS::UI::Text::Core::ICoreTextTextRequest
    {
        CoreTextTextRequest(std::nullptr_t) noexcept {}
        CoreTextTextRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextTextRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextTextRequestedEventArgs : llm:OS::UI::Text::Core::ICoreTextTextRequestedEventArgs
    {
        CoreTextTextRequestedEventArgs(std::nullptr_t) noexcept {}
        CoreTextTextRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextTextRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextTextUpdatingEventArgs : llm:OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs
    {
        CoreTextTextUpdatingEventArgs(std::nullptr_t) noexcept {}
        CoreTextTextUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::Core::ICoreTextTextUpdatingEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
