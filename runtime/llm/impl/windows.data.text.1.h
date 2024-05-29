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
#ifndef LLM_OS_Data_Text_1_H
#define LLM_OS_Data_Text_1_H
#include "llm/impl/Windows.Data.Text.0.h"
LLM_EXPORT namespace llm::OS::Data::Text
{
    struct __declspec(empty_bases) IAlternateWordForm :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAlternateWordForm>
    {
        IAlternateWordForm(std::nullptr_t = nullptr) noexcept {}
        IAlternateWordForm(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISelectableWordSegment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISelectableWordSegment>
    {
        ISelectableWordSegment(std::nullptr_t = nullptr) noexcept {}
        ISelectableWordSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISelectableWordsSegmenter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISelectableWordsSegmenter>
    {
        ISelectableWordsSegmenter(std::nullptr_t = nullptr) noexcept {}
        ISelectableWordsSegmenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISelectableWordsSegmenterFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISelectableWordsSegmenterFactory>
    {
        ISelectableWordsSegmenterFactory(std::nullptr_t = nullptr) noexcept {}
        ISelectableWordsSegmenterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISemanticTextQuery :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISemanticTextQuery>
    {
        ISemanticTextQuery(std::nullptr_t = nullptr) noexcept {}
        ISemanticTextQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISemanticTextQueryFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISemanticTextQueryFactory>
    {
        ISemanticTextQueryFactory(std::nullptr_t = nullptr) noexcept {}
        ISemanticTextQueryFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextConversionGenerator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextConversionGenerator>
    {
        ITextConversionGenerator(std::nullptr_t = nullptr) noexcept {}
        ITextConversionGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextConversionGeneratorFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextConversionGeneratorFactory>
    {
        ITextConversionGeneratorFactory(std::nullptr_t = nullptr) noexcept {}
        ITextConversionGeneratorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextPhoneme :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextPhoneme>
    {
        ITextPhoneme(std::nullptr_t = nullptr) noexcept {}
        ITextPhoneme(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextPredictionGenerator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextPredictionGenerator>
    {
        ITextPredictionGenerator(std::nullptr_t = nullptr) noexcept {}
        ITextPredictionGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextPredictionGenerator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextPredictionGenerator2>
    {
        ITextPredictionGenerator2(std::nullptr_t = nullptr) noexcept {}
        ITextPredictionGenerator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextPredictionGeneratorFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextPredictionGeneratorFactory>
    {
        ITextPredictionGeneratorFactory(std::nullptr_t = nullptr) noexcept {}
        ITextPredictionGeneratorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextReverseConversionGenerator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextReverseConversionGenerator>
    {
        ITextReverseConversionGenerator(std::nullptr_t = nullptr) noexcept {}
        ITextReverseConversionGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextReverseConversionGenerator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextReverseConversionGenerator2>
    {
        ITextReverseConversionGenerator2(std::nullptr_t = nullptr) noexcept {}
        ITextReverseConversionGenerator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITextReverseConversionGeneratorFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ITextReverseConversionGeneratorFactory>
    {
        ITextReverseConversionGeneratorFactory(std::nullptr_t = nullptr) noexcept {}
        ITextReverseConversionGeneratorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUnicodeCharactersStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IUnicodeCharactersStatics>
    {
        IUnicodeCharactersStatics(std::nullptr_t = nullptr) noexcept {}
        IUnicodeCharactersStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWordSegment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWordSegment>
    {
        IWordSegment(std::nullptr_t = nullptr) noexcept {}
        IWordSegment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWordsSegmenter :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWordsSegmenter>
    {
        IWordsSegmenter(std::nullptr_t = nullptr) noexcept {}
        IWordsSegmenter(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWordsSegmenterFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWordsSegmenterFactory>
    {
        IWordsSegmenterFactory(std::nullptr_t = nullptr) noexcept {}
        IWordsSegmenterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
