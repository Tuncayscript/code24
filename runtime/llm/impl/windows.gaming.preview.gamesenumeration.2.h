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
#ifndef LLM_OS_Gaming_Preview_GamesEnumeration_2_H
#define LLM_OS_Gaming_Preview_GamesEnumeration_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Gaming.Preview.GamesEnumeration.1.h"
LLM_EXPORT namespace llm:OS::Gaming::Preview::GamesEnumeration
{
    struct GameListChangedEventHandler : llm:OS::Foundation::IUnknown
    {
        GameListChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        GameListChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> GameListChangedEventHandler(L lambda);
        template <typename F> GameListChangedEventHandler(F* function);
        template <typename O, typename M> GameListChangedEventHandler(O* object, M method);
        template <typename O, typename M> GameListChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> GameListChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Gaming::Preview::GamesEnumeration::GameListEntry const& game) const;
    };
    struct GameListRemovedEventHandler : llm:OS::Foundation::IUnknown
    {
        GameListRemovedEventHandler(std::nullptr_t = nullptr) noexcept {}
        GameListRemovedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> GameListRemovedEventHandler(L lambda);
        template <typename F> GameListRemovedEventHandler(F* function);
        template <typename O, typename M> GameListRemovedEventHandler(O* object, M method);
        template <typename O, typename M> GameListRemovedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> GameListRemovedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(param::hstring const& identifier) const;
    };
    struct GameList
    {
        GameList() = delete;
        static auto FindAllAsync();
        static auto FindAllAsync(param::hstring const& packageFamilyName);
        static auto GameAdded(llm:OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        using GameAdded_revoker = impl::factory_event_revoker<llm:OS::Gaming::Preview::GamesEnumeration::IGameListStatics, &impl::abi_t<llm:OS::Gaming::Preview::GamesEnumeration::IGameListStatics>::remove_GameAdded>;
        [[nodiscard]] static GameAdded_revoker GameAdded(auto_revoke_t, llm:OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        static auto GameAdded(llm::event_token const& token);
        static auto GameRemoved(llm:OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler);
        using GameRemoved_revoker = impl::factory_event_revoker<llm:OS::Gaming::Preview::GamesEnumeration::IGameListStatics, &impl::abi_t<llm:OS::Gaming::Preview::GamesEnumeration::IGameListStatics>::remove_GameRemoved>;
        [[nodiscard]] static GameRemoved_revoker GameRemoved(auto_revoke_t, llm:OS::Gaming::Preview::GamesEnumeration::GameListRemovedEventHandler const& handler);
        static auto GameRemoved(llm::event_token const& token);
        static auto GameUpdated(llm:OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        using GameUpdated_revoker = impl::factory_event_revoker<llm:OS::Gaming::Preview::GamesEnumeration::IGameListStatics, &impl::abi_t<llm:OS::Gaming::Preview::GamesEnumeration::IGameListStatics>::remove_GameUpdated>;
        [[nodiscard]] static GameUpdated_revoker GameUpdated(auto_revoke_t, llm:OS::Gaming::Preview::GamesEnumeration::GameListChangedEventHandler const& handler);
        static auto GameUpdated(llm::event_token const& token);
        static auto MergeEntriesAsync(llm:OS::Gaming::Preview::GamesEnumeration::GameListEntry const& left, llm:OS::Gaming::Preview::GamesEnumeration::GameListEntry const& right);
        static auto UnmergeEntryAsync(llm:OS::Gaming::Preview::GamesEnumeration::GameListEntry const& mergedEntry);
    };
    struct __declspec(empty_bases) GameListEntry : llm:OS::Gaming::Preview::GamesEnumeration::IGameListEntry,
        impl::require<GameListEntry, llm:OS::Gaming::Preview::GamesEnumeration::IGameListEntry2>
    {
        GameListEntry(std::nullptr_t) noexcept {}
        GameListEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::Preview::GamesEnumeration::IGameListEntry(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameModeConfiguration : llm:OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration
    {
        GameModeConfiguration(std::nullptr_t) noexcept {}
        GameModeConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::Preview::GamesEnumeration::IGameModeConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GameModeUserConfiguration : llm:OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration
    {
        GameModeUserConfiguration(std::nullptr_t) noexcept {}
        GameModeUserConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Gaming::Preview::GamesEnumeration::IGameModeUserConfiguration(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
}
#endif
