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
#ifndef LLM_OS_Media_SpeechRecognition_1_H
#define LLM_OS_Media_SpeechRecognition_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.SpeechRecognition.0.h"
LLM_EXPORT namespace llm:OS::Media::SpeechRecognition
{
    struct __declspec(empty_bases) ISpeechContinuousRecognitionCompletedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechContinuousRecognitionCompletedEventArgs>
    {
        ISpeechContinuousRecognitionCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpeechContinuousRecognitionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechContinuousRecognitionResultGeneratedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechContinuousRecognitionResultGeneratedEventArgs>
    {
        ISpeechContinuousRecognitionResultGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpeechContinuousRecognitionResultGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechContinuousRecognitionSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechContinuousRecognitionSession>
    {
        ISpeechContinuousRecognitionSession(std::nullptr_t = nullptr) noexcept {}
        ISpeechContinuousRecognitionSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionCompilationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionCompilationResult>
    {
        ISpeechRecognitionCompilationResult(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionCompilationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionConstraint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionConstraint>
    {
        ISpeechRecognitionConstraint(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionGrammarFileConstraint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionGrammarFileConstraint>,
        impl::require<llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint, llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>
    {
        ISpeechRecognitionGrammarFileConstraint(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionGrammarFileConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionGrammarFileConstraintFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionGrammarFileConstraintFactory>
    {
        ISpeechRecognitionGrammarFileConstraintFactory(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionGrammarFileConstraintFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionHypothesis :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionHypothesis>
    {
        ISpeechRecognitionHypothesis(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionHypothesis(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionHypothesisGeneratedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionHypothesisGeneratedEventArgs>
    {
        ISpeechRecognitionHypothesisGeneratedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionHypothesisGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionListConstraint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionListConstraint>,
        impl::require<llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint, llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>
    {
        ISpeechRecognitionListConstraint(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionListConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionListConstraintFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionListConstraintFactory>
    {
        ISpeechRecognitionListConstraintFactory(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionListConstraintFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionQualityDegradingEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionQualityDegradingEventArgs>
    {
        ISpeechRecognitionQualityDegradingEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionQualityDegradingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionResult>
    {
        ISpeechRecognitionResult(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionResult2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionResult2>
    {
        ISpeechRecognitionResult2(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionResult2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionSemanticInterpretation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionSemanticInterpretation>
    {
        ISpeechRecognitionSemanticInterpretation(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionSemanticInterpretation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionTopicConstraint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionTopicConstraint>,
        impl::require<llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint, llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>
    {
        ISpeechRecognitionTopicConstraint(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionTopicConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionTopicConstraintFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionTopicConstraintFactory>
    {
        ISpeechRecognitionTopicConstraintFactory(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionTopicConstraintFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognitionVoiceCommandDefinitionConstraint :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognitionVoiceCommandDefinitionConstraint>,
        impl::require<llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint, llm:OS::Media::SpeechRecognition::ISpeechRecognitionConstraint>
    {
        ISpeechRecognitionVoiceCommandDefinitionConstraint(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognitionVoiceCommandDefinitionConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizer>,
        impl::require<llm:OS::Media::SpeechRecognition::ISpeechRecognizer, llm:OS::Foundation::IClosable>
    {
        ISpeechRecognizer(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizer2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizer2>
    {
        ISpeechRecognizer2(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizer2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizerFactory>
    {
        ISpeechRecognizerFactory(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizerStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizerStateChangedEventArgs>
    {
        ISpeechRecognizerStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizerStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizerStatics>
    {
        ISpeechRecognizerStatics(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizerStatics2>
    {
        ISpeechRecognizerStatics2(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizerTimeouts :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizerTimeouts>
    {
        ISpeechRecognizerTimeouts(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizerTimeouts(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechRecognizerUIOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechRecognizerUIOptions>
    {
        ISpeechRecognizerUIOptions(std::nullptr_t = nullptr) noexcept {}
        ISpeechRecognizerUIOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandManager>
    {
        IVoiceCommandManager(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandSet :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandSet>
    {
        IVoiceCommandSet(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandSet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
