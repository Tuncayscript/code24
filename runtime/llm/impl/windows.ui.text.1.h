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
#ifndef LLM_OS_UI_Text_1_H
#define LLM_OS_UI_Text_1_H
#include "llm/impl/Windows.UI.Text.0.h"
LLM_EXPORT namespace llm:OS::UI::Text
{
    struct __declspec(empty_bases) IContentLinkInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IContentLinkInfo>
    {
        IContentLinkInfo(std::nullptr_t = nullptr) noexcept {}
        IContentLinkInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFontWeights :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFontWeights>
    {
        IFontWeights(std::nullptr_t = nullptr) noexcept {}
        IFontWeights(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFontWeightsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFontWeightsStatics>
    {
        IFontWeightsStatics(std::nullptr_t = nullptr) noexcept {}
        IFontWeightsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRichEditTextRange :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRichEditTextRange>
    {
        IRichEditTextRange(std::nullptr_t = nullptr) noexcept {}
        IRichEditTextRange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextCharacterFormat :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextCharacterFormat>
    {
        ITextCharacterFormat(std::nullptr_t = nullptr) noexcept {}
        ITextCharacterFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextConstantsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextConstantsStatics>
    {
        ITextConstantsStatics(std::nullptr_t = nullptr) noexcept {}
        ITextConstantsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextDocument :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextDocument>
    {
        ITextDocument(std::nullptr_t = nullptr) noexcept {}
        ITextDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextDocument2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextDocument2>
    {
        ITextDocument2(std::nullptr_t = nullptr) noexcept {}
        ITextDocument2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextDocument3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextDocument3>
    {
        ITextDocument3(std::nullptr_t = nullptr) noexcept {}
        ITextDocument3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextDocument4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextDocument4>
    {
        ITextDocument4(std::nullptr_t = nullptr) noexcept {}
        ITextDocument4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextParagraphFormat :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextParagraphFormat>
    {
        ITextParagraphFormat(std::nullptr_t = nullptr) noexcept {}
        ITextParagraphFormat(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextRange :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextRange>
    {
        ITextRange(std::nullptr_t = nullptr) noexcept {}
        ITextRange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextSelection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITextSelection>,
        impl::require<llm:OS::UI::Text::ITextSelection, llm:OS::UI::Text::ITextRange>
    {
        ITextSelection(std::nullptr_t = nullptr) noexcept {}
        ITextSelection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
