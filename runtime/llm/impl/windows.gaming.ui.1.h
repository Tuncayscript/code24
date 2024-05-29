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
#ifndef LLM_OS_Gaming_UI_1_H
#define LLM_OS_Gaming_UI_1_H
#include "llm/impl/Windows.ApplicationModel.Activation.0.h"
#include "llm/impl/Windows.Gaming.UI.0.h"
LLM_EXPORT namespace llm:OS::Gaming::UI
{
    struct __declspec(empty_bases) IGameBarStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameBarStatics>
    {
        IGameBarStatics(std::nullptr_t = nullptr) noexcept {}
        IGameBarStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameChatMessageReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameChatMessageReceivedEventArgs>
    {
        IGameChatMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGameChatMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameChatOverlay :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameChatOverlay>
    {
        IGameChatOverlay(std::nullptr_t = nullptr) noexcept {}
        IGameChatOverlay(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameChatOverlayMessageSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameChatOverlayMessageSource>
    {
        IGameChatOverlayMessageSource(std::nullptr_t = nullptr) noexcept {}
        IGameChatOverlayMessageSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameChatOverlayStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameChatOverlayStatics>
    {
        IGameChatOverlayStatics(std::nullptr_t = nullptr) noexcept {}
        IGameChatOverlayStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGameUIProviderActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGameUIProviderActivatedEventArgs>,
        impl::require<llm:OS::Gaming::UI::IGameUIProviderActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        IGameUIProviderActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IGameUIProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
