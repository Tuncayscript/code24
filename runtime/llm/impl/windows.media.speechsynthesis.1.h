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
#ifndef LLM_OS_Media_SpeechSynthesis_1_H
#define LLM_OS_Media_SpeechSynthesis_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Storage.Streams.0.h"
#include "llm/impl/Windows.Media.SpeechSynthesis.0.h"
LLM_EXPORT namespace llm:OS::Media::SpeechSynthesis
{
    struct __declspec(empty_bases) IInstalledVoicesStatic :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInstalledVoicesStatic>
    {
        IInstalledVoicesStatic(std::nullptr_t = nullptr) noexcept {}
        IInstalledVoicesStatic(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IInstalledVoicesStatic2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IInstalledVoicesStatic2>
    {
        IInstalledVoicesStatic2(std::nullptr_t = nullptr) noexcept {}
        IInstalledVoicesStatic2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechSynthesisStream :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechSynthesisStream>,
        impl::require<llm:OS::Media::SpeechSynthesis::ISpeechSynthesisStream, llm:OS::Foundation::IClosable, llm:OS::Storage::Streams::IInputStream, llm:OS::Storage::Streams::IOutputStream, llm:OS::Storage::Streams::IRandomAccessStream, llm:OS::Storage::Streams::IContentTypeProvider, llm:OS::Storage::Streams::IRandomAccessStreamWithContentType>
    {
        ISpeechSynthesisStream(std::nullptr_t = nullptr) noexcept {}
        ISpeechSynthesisStream(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechSynthesizer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechSynthesizer>
    {
        ISpeechSynthesizer(std::nullptr_t = nullptr) noexcept {}
        ISpeechSynthesizer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechSynthesizer2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechSynthesizer2>
    {
        ISpeechSynthesizer2(std::nullptr_t = nullptr) noexcept {}
        ISpeechSynthesizer2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechSynthesizerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechSynthesizerOptions>
    {
        ISpeechSynthesizerOptions(std::nullptr_t = nullptr) noexcept {}
        ISpeechSynthesizerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechSynthesizerOptions2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechSynthesizerOptions2>
    {
        ISpeechSynthesizerOptions2(std::nullptr_t = nullptr) noexcept {}
        ISpeechSynthesizerOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISpeechSynthesizerOptions3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISpeechSynthesizerOptions3>
    {
        ISpeechSynthesizerOptions3(std::nullptr_t = nullptr) noexcept {}
        ISpeechSynthesizerOptions3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoiceInformation>
    {
        IVoiceInformation(std::nullptr_t = nullptr) noexcept {}
        IVoiceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
