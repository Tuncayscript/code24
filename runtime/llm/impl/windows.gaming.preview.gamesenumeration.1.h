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
#ifndef LLM_OS_Gaming_Preview_GamesEnumeration_1_H
#define LLM_OS_Gaming_Preview_GamesEnumeration_1_H
#include "llm/impl/Windows.Gaming.Preview.GamesEnumeration.0.h"
LLM_EXPORT namespace llm:OS::Gaming::Preview::GamesEnumeration
{
    struct __declspec(empty_bases) IGameListEntry :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameListEntry>
    {
        IGameListEntry(std::nullptr_t = nullptr) noexcept {}
        IGameListEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameListEntry2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameListEntry2>,
        impl::require<llm:OS::Gaming::Preview::GamesEnumeration::IGameListEntry2, llm:OS::Gaming::Preview::GamesEnumeration::IGameListEntry>
    {
        IGameListEntry2(std::nullptr_t = nullptr) noexcept {}
        IGameListEntry2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameListStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameListStatics>
    {
        IGameListStatics(std::nullptr_t = nullptr) noexcept {}
        IGameListStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameListStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameListStatics2>
    {
        IGameListStatics2(std::nullptr_t = nullptr) noexcept {}
        IGameListStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameModeConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameModeConfiguration>
    {
        IGameModeConfiguration(std::nullptr_t = nullptr) noexcept {}
        IGameModeConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameModeUserConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameModeUserConfiguration>
    {
        IGameModeUserConfiguration(std::nullptr_t = nullptr) noexcept {}
        IGameModeUserConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameModeUserConfigurationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameModeUserConfigurationStatics>
    {
        IGameModeUserConfigurationStatics(std::nullptr_t = nullptr) noexcept {}
        IGameModeUserConfigurationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
