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
#ifndef LLM_OS_Gaming_XboxLive_Storage_2_H
#define LLM_OS_Gaming_XboxLive_Storage_2_H
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.Gaming.XboxLive.Storage.1.h"
LLM_EXPORT namespace llm:OS::Gaming::XboxLive::Storage
{
    struct __declspec(empty_bases) GameSaveBlobGetResult : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult
    {
        GameSaveBlobGetResult(std::nullptr_t) noexcept {}
        GameSaveBlobGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobGetResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveBlobInfo : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo
    {
        GameSaveBlobInfo(std::nullptr_t) noexcept {}
        GameSaveBlobInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveBlobInfoGetResult : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult
    {
        GameSaveBlobInfoGetResult(std::nullptr_t) noexcept {}
        GameSaveBlobInfoGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoGetResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveBlobInfoQuery : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery
    {
        GameSaveBlobInfoQuery(std::nullptr_t) noexcept {}
        GameSaveBlobInfoQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveBlobInfoQuery(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveContainer : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainer
    {
        GameSaveContainer(std::nullptr_t) noexcept {}
        GameSaveContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveContainerInfo : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo
    {
        GameSaveContainerInfo(std::nullptr_t) noexcept {}
        GameSaveContainerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainerInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveContainerInfoGetResult : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult
    {
        GameSaveContainerInfoGetResult(std::nullptr_t) noexcept {}
        GameSaveContainerInfoGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoGetResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveContainerInfoQuery : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery
    {
        GameSaveContainerInfoQuery(std::nullptr_t) noexcept {}
        GameSaveContainerInfoQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveContainerInfoQuery(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveOperationResult : llm:OS::Gaming::XboxLive::Storage::IGameSaveOperationResult
    {
        GameSaveOperationResult(std::nullptr_t) noexcept {}
        GameSaveOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveOperationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameSaveProvider : llm:OS::Gaming::XboxLive::Storage::IGameSaveProvider
    {
        GameSaveProvider(std::nullptr_t) noexcept {}
        GameSaveProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveProvider(ptr, take_ownership_from_abi) {}
        static auto GetForUserAsync(llm:OS::System::User const& user, param::hstring const& serviceConfigId);
        static auto GetSyncOnDemandForUserAsync(llm:OS::System::User const& user, param::hstring const& serviceConfigId);
    };
    struct __declspec(empty_bases) GameSaveProviderGetResult : llm:OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult
    {
        GameSaveProviderGetResult(std::nullptr_t) noexcept {}
        GameSaveProviderGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::XboxLive::Storage::IGameSaveProviderGetResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
