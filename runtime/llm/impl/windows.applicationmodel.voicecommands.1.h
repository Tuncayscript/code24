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
#ifndef LLM_OS_ApplicationModel_VoiceCommands_1_H
#define LLM_OS_ApplicationModel_VoiceCommands_1_H
#include "llm/impl/Windows.ApplicationModel.VoiceCommands.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::VoiceCommands
{
    struct __declspec(empty_bases) IVoiceCommand :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommand>
    {
        IVoiceCommand(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandCompletedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandCompletedEventArgs>
    {
        IVoiceCommandCompletedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandConfirmationResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandConfirmationResult>
    {
        IVoiceCommandConfirmationResult(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandConfirmationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandContentTile :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandContentTile>
    {
        IVoiceCommandContentTile(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandContentTile(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandDefinition :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandDefinition>
    {
        IVoiceCommandDefinition(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandDefinitionManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandDefinitionManagerStatics>
    {
        IVoiceCommandDefinitionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandDefinitionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandDisambiguationResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandDisambiguationResult>
    {
        IVoiceCommandDisambiguationResult(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandDisambiguationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandResponse :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandResponse>
    {
        IVoiceCommandResponse(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandResponseStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandResponseStatics>
    {
        IVoiceCommandResponseStatics(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandResponseStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandServiceConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandServiceConnection>
    {
        IVoiceCommandServiceConnection(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandServiceConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandServiceConnectionStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandServiceConnectionStatics>
    {
        IVoiceCommandServiceConnectionStatics(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandServiceConnectionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoiceCommandUserMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoiceCommandUserMessage>
    {
        IVoiceCommandUserMessage(std::nullptr_t = nullptr) noexcept {}
        IVoiceCommandUserMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
