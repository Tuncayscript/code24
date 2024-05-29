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
#ifndef LLM_OS_Data_Text_2_H
#define LLM_OS_Data_Text_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Data.Text.1.h"
LLM_EXPORT namespace llm::OS::Data::Text
{
    struct SelectableWordSegmentsTokenizingHandler : llm::OS::Foundation::IUnknown
    {
        SelectableWordSegmentsTokenizingHandler(std::nullptr_t = nullptr) noexcept {}
        SelectableWordSegmentsTokenizingHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SelectableWordSegmentsTokenizingHandler(L lambda);
        template <typename F> SelectableWordSegmentsTokenizingHandler(F* function);
        template <typename O, typename M> SelectableWordSegmentsTokenizingHandler(O* object, M method);
        template <typename O, typename M> SelectableWordSegmentsTokenizingHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SelectableWordSegmentsTokenizingHandler(weak_ref<O>&& object, M method);
        auto operator()(param::iterable<llm::OS::Data::Text::SelectableWordSegment> const& precedingWords, param::iterable<llm::OS::Data::Text::SelectableWordSegment> const& words) const;
    };
    struct WordSegmentsTokenizingHandler : llm::OS::Foundation::IUnknown
    {
        WordSegmentsTokenizingHandler(std::nullptr_t = nullptr) noexcept {}
        WordSegmentsTokenizingHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> WordSegmentsTokenizingHandler(L lambda);
        template <typename F> WordSegmentsTokenizingHandler(F* function);
        template <typename O, typename M> WordSegmentsTokenizingHandler(O* object, M method);
        template <typename O, typename M> WordSegmentsTokenizingHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> WordSegmentsTokenizingHandler(weak_ref<O>&& object, M method);
        auto operator()(param::iterable<llm::OS::Data::Text::WordSegment> const& precedingWords, param::iterable<llm::OS::Data::Text::WordSegment> const& words) const;
    };
    struct TextSegment
    {
        uint32_t StartPosition;
        uint32_t Length;
    };
    inline bool operator==(TextSegment const& left, TextSegment const& right) noexcept
    {
        return left.StartPosition == right.StartPosition && left.Length == right.Length;
    }
    inline bool operator!=(TextSegment const& left, TextSegment const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) AlternateWordForm : llm::OS::Data::Text::IAlternateWordForm
    {
        AlternateWordForm(std::nullptr_t) noexcept {}
        AlternateWordForm(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::IAlternateWordForm(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SelectableWordSegment : llm::OS::Data::Text::ISelectableWordSegment
    {
        SelectableWordSegment(std::nullptr_t) noexcept {}
        SelectableWordSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ISelectableWordSegment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SelectableWordsSegmenter : llm::OS::Data::Text::ISelectableWordsSegmenter
    {
        SelectableWordsSegmenter(std::nullptr_t) noexcept {}
        SelectableWordsSegmenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ISelectableWordsSegmenter(ptr, take_ownership_from_abi) {}
        explicit SelectableWordsSegmenter(param::hstring const& language);
    };
    struct __declspec(empty_bases) SemanticTextQuery : llm::OS::Data::Text::ISemanticTextQuery
    {
        SemanticTextQuery(std::nullptr_t) noexcept {}
        SemanticTextQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ISemanticTextQuery(ptr, take_ownership_from_abi) {}
        explicit SemanticTextQuery(param::hstring const& aqsFilter);
        SemanticTextQuery(param::hstring const& aqsFilter, param::hstring const& filterLanguage);
    };
    struct __declspec(empty_bases) TextConversionGenerator : llm::OS::Data::Text::ITextConversionGenerator
    {
        TextConversionGenerator(std::nullptr_t) noexcept {}
        TextConversionGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ITextConversionGenerator(ptr, take_ownership_from_abi) {}
        explicit TextConversionGenerator(param::hstring const& languageTag);
    };
    struct __declspec(empty_bases) TextPhoneme : llm::OS::Data::Text::ITextPhoneme
    {
        TextPhoneme(std::nullptr_t) noexcept {}
        TextPhoneme(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ITextPhoneme(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TextPredictionGenerator : llm::OS::Data::Text::ITextPredictionGenerator,
        impl::require<TextPredictionGenerator, llm::OS::Data::Text::ITextPredictionGenerator2>
    {
        TextPredictionGenerator(std::nullptr_t) noexcept {}
        TextPredictionGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ITextPredictionGenerator(ptr, take_ownership_from_abi) {}
        explicit TextPredictionGenerator(param::hstring const& languageTag);
        using llm::OS::Data::Text::ITextPredictionGenerator::GetCandidatesAsync;
        using impl::consume_t<TextPredictionGenerator, llm::OS::Data::Text::ITextPredictionGenerator2>::GetCandidatesAsync;
    };
    struct __declspec(empty_bases) TextReverseConversionGenerator : llm::OS::Data::Text::ITextReverseConversionGenerator,
        impl::require<TextReverseConversionGenerator, llm::OS::Data::Text::ITextReverseConversionGenerator2>
    {
        TextReverseConversionGenerator(std::nullptr_t) noexcept {}
        TextReverseConversionGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::ITextReverseConversionGenerator(ptr, take_ownership_from_abi) {}
        explicit TextReverseConversionGenerator(param::hstring const& languageTag);
    };
    struct UnicodeCharacters
    {
        UnicodeCharacters() = delete;
        static auto GetCodepointFromSurrogatePair(uint32_t highSurrogate, uint32_t lowSurrogate);
        static auto GetSurrogatePairFromCodepoint(uint32_t codepoint, char16_t& highSurrogate, char16_t& lowSurrogate);
        static auto IsHighSurrogate(uint32_t codepoint);
        static auto IsLowSurrogate(uint32_t codepoint);
        static auto IsSupplementary(uint32_t codepoint);
        static auto IsNoncharacter(uint32_t codepoint);
        static auto IsWhitespace(uint32_t codepoint);
        static auto IsAlphabetic(uint32_t codepoint);
        static auto IsCased(uint32_t codepoint);
        static auto IsUppercase(uint32_t codepoint);
        static auto IsLowercase(uint32_t codepoint);
        static auto IsIdStart(uint32_t codepoint);
        static auto IsIdContinue(uint32_t codepoint);
        static auto IsGraphemeBase(uint32_t codepoint);
        static auto IsGraphemeExtend(uint32_t codepoint);
        static auto GetNumericType(uint32_t codepoint);
        static auto GetGeneralCategory(uint32_t codepoint);
    };
    struct __declspec(empty_bases) WordSegment : llm::OS::Data::Text::IWordSegment
    {
        WordSegment(std::nullptr_t) noexcept {}
        WordSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::IWordSegment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WordsSegmenter : llm::OS::Data::Text::IWordsSegmenter
    {
        WordsSegmenter(std::nullptr_t) noexcept {}
        WordsSegmenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Text::IWordsSegmenter(ptr, take_ownership_from_abi) {}
        explicit WordsSegmenter(param::hstring const& language);
    };
}
#endif
