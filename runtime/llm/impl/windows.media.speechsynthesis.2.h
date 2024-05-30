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
#ifndef LLM_OS_Media_SpeechSynthesis_2_H
#define LLM_OS_Media_SpeechSynthesis_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Media.Core.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Media.SpeechSynthesis.1.h"
LLM_EXPORT namespace llm:OS::Media::SpeechSynthesis
{
    struct __declspec(empty_bases) SpeechSynthesisStream : llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream,
        impl::require<SpeechSynthesisStream, llm:OS::Media::Core::ITimedMetadataTrackProvider>
    {
        SpeechSynthesisStream(std::nullptr_t) noexcept {}
        SpeechSynthesisStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SpeechSynthesizer : llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer,
        impl::require<SpeechSynthesizer, llm:OS::Foundation::IClosable, llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer2>
    {
        SpeechSynthesizer(std::nullptr_t) noexcept {}
        SpeechSynthesizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechSynthesis::ISpeechSynthesizer(ptr, take_ownership_from_abi) {}
        SpeechSynthesizer();
        [[nodiscard]] static auto AllVoices();
        [[nodiscard]] static auto DefaultVoice();
        static auto TrySetDefaultVoiceAsync(llm:OS::Media::SpeechSynthesis::VoiceInformation const& voice);
    };
    struct __declspec(empty_bases) SpeechSynthesizerOptions : llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions,
        impl::require<SpeechSynthesizerOptions, llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions2, llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions3>
    {
        SpeechSynthesizerOptions(std::nullptr_t) noexcept {}
        SpeechSynthesizerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechSynthesis::ISpeechSynthesizerOptions(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoiceInformation : llm:OS::Media::SpeechSynthesis::IVoiceInformation
    {
        VoiceInformation(std::nullptr_t) noexcept {}
        VoiceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Media::SpeechSynthesis::IVoiceInformation(ptr, take_ownership_from_abi) {}
    };
}
#endif
