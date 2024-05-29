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
#ifndef LLM_OS_Gaming_XboxLive_Storage_1_H
#define LLM_OS_Gaming_XboxLive_Storage_1_H
#include "llm/impl/Windows.Gaming.XboxLive.Storage.0.h"
LLM_EXPORT namespace llm:OS::Gaming::XboxLive::Storage
{
    struct __declspec(empty_bases) IGameSaveBlobGetResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveBlobGetResult>
    {
        IGameSaveBlobGetResult(std::nullptr_t = nullptr) noexcept {}
        IGameSaveBlobGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveBlobInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveBlobInfo>
    {
        IGameSaveBlobInfo(std::nullptr_t = nullptr) noexcept {}
        IGameSaveBlobInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveBlobInfoGetResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveBlobInfoGetResult>
    {
        IGameSaveBlobInfoGetResult(std::nullptr_t = nullptr) noexcept {}
        IGameSaveBlobInfoGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveBlobInfoQuery :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveBlobInfoQuery>
    {
        IGameSaveBlobInfoQuery(std::nullptr_t = nullptr) noexcept {}
        IGameSaveBlobInfoQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveContainer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveContainer>
    {
        IGameSaveContainer(std::nullptr_t = nullptr) noexcept {}
        IGameSaveContainer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveContainerInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveContainerInfo>
    {
        IGameSaveContainerInfo(std::nullptr_t = nullptr) noexcept {}
        IGameSaveContainerInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveContainerInfoGetResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveContainerInfoGetResult>
    {
        IGameSaveContainerInfoGetResult(std::nullptr_t = nullptr) noexcept {}
        IGameSaveContainerInfoGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveContainerInfoQuery :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveContainerInfoQuery>
    {
        IGameSaveContainerInfoQuery(std::nullptr_t = nullptr) noexcept {}
        IGameSaveContainerInfoQuery(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveOperationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveOperationResult>
    {
        IGameSaveOperationResult(std::nullptr_t = nullptr) noexcept {}
        IGameSaveOperationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveProvider :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveProvider>
    {
        IGameSaveProvider(std::nullptr_t = nullptr) noexcept {}
        IGameSaveProvider(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveProviderGetResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveProviderGetResult>
    {
        IGameSaveProviderGetResult(std::nullptr_t = nullptr) noexcept {}
        IGameSaveProviderGetResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameSaveProviderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameSaveProviderStatics>
    {
        IGameSaveProviderStatics(std::nullptr_t = nullptr) noexcept {}
        IGameSaveProviderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
