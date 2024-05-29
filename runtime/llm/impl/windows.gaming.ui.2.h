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
#ifndef LLM_OS_Gaming_UI_2_H
#define LLM_OS_Gaming_UI_2_H
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Gaming.UI.1.h"
LLM_EXPORT namespace llm:OS::Gaming::UI
{
    struct GameBar
    {
        GameBar() = delete;
        static auto VisibilityChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using VisibilityChanged_revoker = impl::factory_event_revoker<llm:OS::Gaming::UI::IGameBarStatics, &impl::abi_t<llm:OS::Gaming::UI::IGameBarStatics>::remove_VisibilityChanged>;
        [[nodiscard]] static VisibilityChanged_revoker VisibilityChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto VisibilityChanged(llm::event_token const& token);
        static auto IsInputRedirectedChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using IsInputRedirectedChanged_revoker = impl::factory_event_revoker<llm:OS::Gaming::UI::IGameBarStatics, &impl::abi_t<llm:OS::Gaming::UI::IGameBarStatics>::remove_IsInputRedirectedChanged>;
        [[nodiscard]] static IsInputRedirectedChanged_revoker IsInputRedirectedChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto IsInputRedirectedChanged(llm::event_token const& token);
        [[nodiscard]] static auto Visible();
        [[nodiscard]] static auto IsInputRedirected();
    };
    struct __declspec(empty_bases) GameChatMessageReceivedEventArgs : llm:OS::Gaming::UI::IGameChatMessageReceivedEventArgs
    {
        GameChatMessageReceivedEventArgs(std::nullptr_t) noexcept {}
        GameChatMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::UI::IGameChatMessageReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameChatOverlay : llm:OS::Gaming::UI::IGameChatOverlay
    {
        GameChatOverlay(std::nullptr_t) noexcept {}
        GameChatOverlay(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::UI::IGameChatOverlay(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) GameChatOverlayMessageSource : llm:OS::Gaming::UI::IGameChatOverlayMessageSource
    {
        GameChatOverlayMessageSource(std::nullptr_t) noexcept {}
        GameChatOverlayMessageSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::UI::IGameChatOverlayMessageSource(ptr, take_ownership_from_abi) {}
        GameChatOverlayMessageSource();
    };
    struct __declspec(empty_bases) GameUIProviderActivatedEventArgs : llm:OS::Gaming::UI::IGameUIProviderActivatedEventArgs
    {
        GameUIProviderActivatedEventArgs(std::nullptr_t) noexcept {}
        GameUIProviderActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::UI::IGameUIProviderActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
