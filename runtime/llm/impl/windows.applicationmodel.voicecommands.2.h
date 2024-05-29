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
#ifndef LLM_OS_ApplicationModel_VoiceCommands_2_H
#define LLM_OS_ApplicationModel_VoiceCommands_2_H
#include "llm/impl/Windows.ApplicationModel.AppService.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.ApplicationModel.VoiceCommands.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::VoiceCommands
{
    struct __declspec(empty_bases) VoiceCommand : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommand
    {
        VoiceCommand(std::nullptr_t) noexcept {}
        VoiceCommand(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommand(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoiceCommandCompletedEventArgs : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs
    {
        VoiceCommandCompletedEventArgs(std::nullptr_t) noexcept {}
        VoiceCommandCompletedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandCompletedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoiceCommandConfirmationResult : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult
    {
        VoiceCommandConfirmationResult(std::nullptr_t) noexcept {}
        VoiceCommandConfirmationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandConfirmationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoiceCommandContentTile : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandContentTile
    {
        VoiceCommandContentTile(std::nullptr_t) noexcept {}
        VoiceCommandContentTile(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandContentTile(ptr, take_ownership_from_abi) {}
        VoiceCommandContentTile();
    };
    struct __declspec(empty_bases) VoiceCommandDefinition : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandDefinition
    {
        VoiceCommandDefinition(std::nullptr_t) noexcept {}
        VoiceCommandDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandDefinition(ptr, take_ownership_from_abi) {}
    };
    struct VoiceCommandDefinitionManager
    {
        VoiceCommandDefinitionManager() = delete;
        static auto InstallCommandDefinitionsFromStorageFileAsync(llm::OS::Storage::StorageFile const& file);
        [[nodiscard]] static auto InstalledCommandDefinitions();
    };
    struct __declspec(empty_bases) VoiceCommandDisambiguationResult : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult
    {
        VoiceCommandDisambiguationResult(std::nullptr_t) noexcept {}
        VoiceCommandDisambiguationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandDisambiguationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoiceCommandResponse : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandResponse
    {
        VoiceCommandResponse(std::nullptr_t) noexcept {}
        VoiceCommandResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandResponse(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto MaxSupportedVoiceCommandContentTiles();
        static auto CreateResponse(llm::OS::ApplicationModel::VoiceCommands::VoiceCommandUserMessage const& userMessage);
        static auto CreateResponse(llm::OS::ApplicationModel::VoiceCommands::VoiceCommandUserMessage const& message, param::iterable<llm::OS::ApplicationModel::VoiceCommands::VoiceCommandContentTile> const& contentTiles);
        static auto CreateResponseForPrompt(llm::OS::ApplicationModel::VoiceCommands::VoiceCommandUserMessage const& message, llm::OS::ApplicationModel::VoiceCommands::VoiceCommandUserMessage const& repeatMessage);
        static auto CreateResponseForPrompt(llm::OS::ApplicationModel::VoiceCommands::VoiceCommandUserMessage const& message, llm::OS::ApplicationModel::VoiceCommands::VoiceCommandUserMessage const& repeatMessage, param::iterable<llm::OS::ApplicationModel::VoiceCommands::VoiceCommandContentTile> const& contentTiles);
    };
    struct __declspec(empty_bases) VoiceCommandServiceConnection : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection
    {
        VoiceCommandServiceConnection(std::nullptr_t) noexcept {}
        VoiceCommandServiceConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandServiceConnection(ptr, take_ownership_from_abi) {}
        static auto FromAppServiceTriggerDetails(llm::OS::ApplicationModel::AppService::AppServiceTriggerDetails const& triggerDetails);
    };
    struct __declspec(empty_bases) VoiceCommandUserMessage : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage
    {
        VoiceCommandUserMessage(std::nullptr_t) noexcept {}
        VoiceCommandUserMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::VoiceCommands::IVoiceCommandUserMessage(ptr, take_ownership_from_abi) {}
        VoiceCommandUserMessage();
    };
}
#endif
