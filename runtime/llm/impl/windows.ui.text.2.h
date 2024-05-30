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
#ifndef LLM_OS_UI_Text_2_H
#define LLM_OS_UI_Text_2_H
#include "llm/impl/Windows.UI.Text.1.h"
LLM_EXPORT namespace llm:OS::UI::Text
{
    struct FontWeight
    {
        uint16_t Weight;
    };
    inline bool operator==(FontWeight const& left, FontWeight const& right) noexcept
    {
        return left.Weight == right.Weight;
    }
    inline bool operator!=(FontWeight const& left, FontWeight const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ContentLinkInfo : llm:OS::UI::Text::IContentLinkInfo
    {
        ContentLinkInfo(std::nullptr_t) noexcept {}
        ContentLinkInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::IContentLinkInfo(ptr, take_ownership_from_abi) {}
        ContentLinkInfo();
    };
    struct __declspec(empty_bases) FontWeights : llm:OS::UI::Text::IFontWeights
    {
        FontWeights(std::nullptr_t) noexcept {}
        FontWeights(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::IFontWeights(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto Black();
        [[nodiscard]] static auto Bold();
        [[nodiscard]] static auto ExtraBlack();
        [[nodiscard]] static auto ExtraBold();
        [[nodiscard]] static auto ExtraLight();
        [[nodiscard]] static auto Light();
        [[nodiscard]] static auto Medium();
        [[nodiscard]] static auto Normal();
        [[nodiscard]] static auto SemiBold();
        [[nodiscard]] static auto SemiLight();
        [[nodiscard]] static auto Thin();
    };
    struct __declspec(empty_bases) RichEditTextDocument : llm:OS::UI::Text::ITextDocument,
        impl::require<RichEditTextDocument, llm:OS::UI::Text::ITextDocument2, llm:OS::UI::Text::ITextDocument3, llm:OS::UI::Text::ITextDocument4>
    {
        RichEditTextDocument(std::nullptr_t) noexcept {}
        RichEditTextDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::ITextDocument(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) RichEditTextRange : llm:OS::UI::Text::ITextRange,
        impl::require<RichEditTextRange, llm:OS::UI::Text::IRichEditTextRange>
    {
        RichEditTextRange(std::nullptr_t) noexcept {}
        RichEditTextRange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Text::ITextRange(ptr, take_ownership_from_abi) {}
    };
    struct TextConstants
    {
        TextConstants() = delete;
        [[nodiscard]] static auto AutoColor();
        [[nodiscard]] static auto MinUnitCount();
        [[nodiscard]] static auto MaxUnitCount();
        [[nodiscard]] static auto UndefinedColor();
        [[nodiscard]] static auto UndefinedFloatValue();
        [[nodiscard]] static auto UndefinedInt32Value();
        [[nodiscard]] static auto UndefinedFontStretch();
        [[nodiscard]] static auto UndefinedFontStyle();
    };
}
#endif
