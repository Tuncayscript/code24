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
#ifndef LLM_OS_Media_SpeechRecognition_2_H
#define LLM_OS_Media_SpeechRecognition_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Globalization.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Media.SpeechRecognition.1.h"
LLM_EXPORT namespace llm:OS::Media::SpeechRecognition
{
    struct __declspec(empty_bases) SpeechContinuousRecognitionCompletedEventArgs : llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs
    {
        SpeechContinuousRecognitionCompletedEventArgs(std::nullptr_t) noexcept {}
        SpeechContinuousRecognitionCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechContinuousRecognitionResultGeneratedEventArgs : llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs
    {
        SpeechContinuousRecognitionResultGeneratedEventArgs(std::nullptr_t) noexcept {}
        SpeechContinuousRecognitionResultGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionResultGeneratedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechContinuousRecognitionSession : llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession
    {
        SpeechContinuousRecognitionSession(std::nullptr_t) noexcept {}
        SpeechContinuousRecognitionSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechContinuousRecognitionSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionCompilationResult : llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult
    {
        SpeechRecognitionCompilationResult(std::nullptr_t) noexcept {}
        SpeechRecognitionCompilationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionCompilationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionGrammarFileConstraint : llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint
    {
        SpeechRecognitionGrammarFileConstraint(std::nullptr_t) noexcept {}
        SpeechRecognitionGrammarFileConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionGrammarFileConstraint(ptr, take_ownership_from_abi) {}
        explicit SpeechRecognitionGrammarFileConstraint(llm:OS::Storage::StorageFile const& file);
        SpeechRecognitionGrammarFileConstraint(llm:OS::Storage::StorageFile const& file, param::hstring const& tag);
    };
    struct __declspec(empty_bases) SpeechRecognitionHypothesis : llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis
    {
        SpeechRecognitionHypothesis(std::nullptr_t) noexcept {}
        SpeechRecognitionHypothesis(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesis(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionHypothesisGeneratedEventArgs : llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs
    {
        SpeechRecognitionHypothesisGeneratedEventArgs(std::nullptr_t) noexcept {}
        SpeechRecognitionHypothesisGeneratedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionHypothesisGeneratedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionListConstraint : llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint
    {
        SpeechRecognitionListConstraint(std::nullptr_t) noexcept {}
        SpeechRecognitionListConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionListConstraint(ptr, take_ownership_from_abi) {}
        explicit SpeechRecognitionListConstraint(param::iterable<hstring> const& commands);
        SpeechRecognitionListConstraint(param::iterable<hstring> const& commands, param::hstring const& tag);
    };
    struct __declspec(empty_bases) SpeechRecognitionQualityDegradingEventArgs : llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs
    {
        SpeechRecognitionQualityDegradingEventArgs(std::nullptr_t) noexcept {}
        SpeechRecognitionQualityDegradingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionQualityDegradingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionResult : llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult,
        impl::require<SpeechRecognitionResult, llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult2>
    {
        SpeechRecognitionResult(std::nullptr_t) noexcept {}
        SpeechRecognitionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionSemanticInterpretation : llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation
    {
        SpeechRecognitionSemanticInterpretation(std::nullptr_t) noexcept {}
        SpeechRecognitionSemanticInterpretation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionSemanticInterpretation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognitionTopicConstraint : llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint
    {
        SpeechRecognitionTopicConstraint(std::nullptr_t) noexcept {}
        SpeechRecognitionTopicConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionTopicConstraint(ptr, take_ownership_from_abi) {}
        SpeechRecognitionTopicConstraint(llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario const& scenario, param::hstring const& topicHint);
        SpeechRecognitionTopicConstraint(llm:OS::Media::SpeechRecognition::SpeechRecognitionScenario const& scenario, param::hstring const& topicHint, param::hstring const& tag);
    };
    struct __declspec(empty_bases) SpeechRecognitionVoiceCommandDefinitionConstraint : llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint
    {
        SpeechRecognitionVoiceCommandDefinitionConstraint(std::nullptr_t) noexcept {}
        SpeechRecognitionVoiceCommandDefinitionConstraint(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognitionVoiceCommandDefinitionConstraint(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognizer : llm:OS::Media::SpeechRecognition::ISpeechRecognizer,
        impl::require<SpeechRecognizer, llm:OS::Media::SpeechRecognition::ISpeechRecognizer2>
    {
        SpeechRecognizer(std::nullptr_t) noexcept {}
        SpeechRecognizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognizer(ptr, take_ownership_from_abi) {}
        SpeechRecognizer();
        explicit SpeechRecognizer(llm:OS::Globalization::Language const& language);
        [[nodiscard]] static auto SystemSpeechLanguage();
        [[nodiscard]] static auto SupportedTopicLanguages();
        [[nodiscard]] static auto SupportedGrammarLanguages();
        static auto TrySetSystemSpeechLanguageAsync(llm:OS::Globalization::Language const& speechLanguage);
    };
    struct __declspec(empty_bases) SpeechRecognizerStateChangedEventArgs : llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs
    {
        SpeechRecognizerStateChangedEventArgs(std::nullptr_t) noexcept {}
        SpeechRecognizerStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognizerStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognizerTimeouts : llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts
    {
        SpeechRecognizerTimeouts(std::nullptr_t) noexcept {}
        SpeechRecognizerTimeouts(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognizerTimeouts(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechRecognizerUIOptions : llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions
    {
        SpeechRecognizerUIOptions(std::nullptr_t) noexcept {}
        SpeechRecognizerUIOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::ISpeechRecognizerUIOptions(ptr, take_ownership_from_abi) {}
    };
    struct VoiceCommandManager
    {
        VoiceCommandManager() = delete;
        static auto InstallCommandSetsFromStorageFileAsync(llm:OS::Storage::StorageFile const& file);
        [[nodiscard]] static auto InstalledCommandSets();
    };
    struct __declspec(empty_bases) VoiceCommandSet : llm:OS::Media::SpeechRecognition::IVoiceCommandSet
    {
        VoiceCommandSet(std::nullptr_t) noexcept {}
        VoiceCommandSet(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechRecognition::IVoiceCommandSet(ptr, take_ownership_from_abi) {}
    };
}
#endif
