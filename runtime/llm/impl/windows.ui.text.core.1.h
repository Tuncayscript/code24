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
#ifndef LLM_OS_UI_Text_Core_1_H
#define LLM_OS_UI_Text_Core_1_H
#include "llm/impl/Windows.UI.Text.Core.0.h"
LLM_EXPORT namespace llm:OS::UI::Text::Core
{
    struct __declspec(empty_bases) ICoreTextCompositionCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextCompositionCompletedEventArgs>
    {
        ICoreTextCompositionCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextCompositionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextCompositionSegment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextCompositionSegment>
    {
        ICoreTextCompositionSegment(std::nullptr_t = nullptr) noexcept {}
        ICoreTextCompositionSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextCompositionStartedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextCompositionStartedEventArgs>
    {
        ICoreTextCompositionStartedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextCompositionStartedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextEditContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextEditContext>
    {
        ICoreTextEditContext(std::nullptr_t = nullptr) noexcept {}
        ICoreTextEditContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextEditContext2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextEditContext2>
    {
        ICoreTextEditContext2(std::nullptr_t = nullptr) noexcept {}
        ICoreTextEditContext2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextFormatUpdatingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextFormatUpdatingEventArgs>
    {
        ICoreTextFormatUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextFormatUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextLayoutBounds :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextLayoutBounds>
    {
        ICoreTextLayoutBounds(std::nullptr_t = nullptr) noexcept {}
        ICoreTextLayoutBounds(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextLayoutRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextLayoutRequest>
    {
        ICoreTextLayoutRequest(std::nullptr_t = nullptr) noexcept {}
        ICoreTextLayoutRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextLayoutRequest2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextLayoutRequest2>
    {
        ICoreTextLayoutRequest2(std::nullptr_t = nullptr) noexcept {}
        ICoreTextLayoutRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextLayoutRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextLayoutRequestedEventArgs>
    {
        ICoreTextLayoutRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextLayoutRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextSelectionRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextSelectionRequest>
    {
        ICoreTextSelectionRequest(std::nullptr_t = nullptr) noexcept {}
        ICoreTextSelectionRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextSelectionRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextSelectionRequestedEventArgs>
    {
        ICoreTextSelectionRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextSelectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextSelectionUpdatingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextSelectionUpdatingEventArgs>
    {
        ICoreTextSelectionUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextSelectionUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextServicesManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextServicesManager>
    {
        ICoreTextServicesManager(std::nullptr_t = nullptr) noexcept {}
        ICoreTextServicesManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextServicesManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextServicesManagerStatics>
    {
        ICoreTextServicesManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreTextServicesManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextServicesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextServicesStatics>
    {
        ICoreTextServicesStatics(std::nullptr_t = nullptr) noexcept {}
        ICoreTextServicesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextTextRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextTextRequest>
    {
        ICoreTextTextRequest(std::nullptr_t = nullptr) noexcept {}
        ICoreTextTextRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextTextRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextTextRequestedEventArgs>
    {
        ICoreTextTextRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextTextRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextTextUpdatingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextTextUpdatingEventArgs>
    {
        ICoreTextTextUpdatingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextTextUpdatingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
