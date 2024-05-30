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
#ifndef LLM_OS_UI_StartScreen_2_H
#define LLM_OS_UI_StartScreen_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.UI.StartScreen.1.h"
LLM_EXPORT namespace llm:OS::UI::StartScreen
{
    struct __declspec(empty_bases) JumpList : llm:OS::UI::StartScreen::IJumpList
    {
        JumpList(std::nullptr_t) noexcept {}
        JumpList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::IJumpList(ptr, take_ownership_from_abi) {}
        static auto LoadCurrentAsync();
        static auto IsSupported();
    };
    struct __declspec(empty_bases) JumpListItem : llm:OS::UI::StartScreen::IJumpListItem
    {
        JumpListItem(std::nullptr_t) noexcept {}
        JumpListItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::IJumpListItem(ptr, take_ownership_from_abi) {}
        static auto CreateWithArguments(param::hstring const& arguments, param::hstring const& displayName);
        static auto CreateSeparator();
    };
    struct __declspec(empty_bases) SecondaryTile : llm:OS::UI::StartScreen::ISecondaryTile,
        impl::require<SecondaryTile, llm:OS::UI::StartScreen::ISecondaryTile2>
    {
        SecondaryTile(std::nullptr_t) noexcept {}
        SecondaryTile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::ISecondaryTile(ptr, take_ownership_from_abi) {}
        SecondaryTile();
        SecondaryTile(param::hstring const& tileId, param::hstring const& shortName, param::hstring const& displayName, param::hstring const& arguments, llm:OS::UI::StartScreen::TileOptions const& tileOptions, llm:OS::Foundation::Uri const& logoReference);
        SecondaryTile(param::hstring const& tileId, param::hstring const& shortName, param::hstring const& displayName, param::hstring const& arguments, llm:OS::UI::StartScreen::TileOptions const& tileOptions, llm:OS::Foundation::Uri const& logoReference, llm:OS::Foundation::Uri const& wideLogoReference);
        explicit SecondaryTile(param::hstring const& tileId);
        SecondaryTile(param::hstring const& tileId, param::hstring const& displayName, param::hstring const& arguments, llm:OS::Foundation::Uri const& square150x150Logo, llm:OS::UI::StartScreen::TileSize const& desiredSize);
        static auto Exists(param::hstring const& tileId);
        static auto FindAllAsync();
        static auto FindAllAsync(param::hstring const& applicationId);
        static auto FindAllForPackageAsync();
    };
    struct __declspec(empty_bases) SecondaryTileVisualElements : llm:OS::UI::StartScreen::ISecondaryTileVisualElements,
        impl::require<SecondaryTileVisualElements, llm:OS::UI::StartScreen::ISecondaryTileVisualElements2, llm:OS::UI::StartScreen::ISecondaryTileVisualElements3, llm:OS::UI::StartScreen::ISecondaryTileVisualElements4>
    {
        SecondaryTileVisualElements(std::nullptr_t) noexcept {}
        SecondaryTileVisualElements(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::ISecondaryTileVisualElements(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StartScreenManager : llm:OS::UI::StartScreen::IStartScreenManager,
        impl::require<StartScreenManager, llm:OS::UI::StartScreen::IStartScreenManager2>
    {
        StartScreenManager(std::nullptr_t) noexcept {}
        StartScreenManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::IStartScreenManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm:OS::System::User const& user);
    };
    struct __declspec(empty_bases) TileMixedRealityModel : llm:OS::UI::StartScreen::ITileMixedRealityModel,
        impl::require<TileMixedRealityModel, llm:OS::UI::StartScreen::ITileMixedRealityModel2>
    {
        TileMixedRealityModel(std::nullptr_t) noexcept {}
        TileMixedRealityModel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::ITileMixedRealityModel(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VisualElementsRequest : llm:OS::UI::StartScreen::IVisualElementsRequest
    {
        VisualElementsRequest(std::nullptr_t) noexcept {}
        VisualElementsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::IVisualElementsRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VisualElementsRequestDeferral : llm:OS::UI::StartScreen::IVisualElementsRequestDeferral
    {
        VisualElementsRequestDeferral(std::nullptr_t) noexcept {}
        VisualElementsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::IVisualElementsRequestDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VisualElementsRequestedEventArgs : llm:OS::UI::StartScreen::IVisualElementsRequestedEventArgs
    {
        VisualElementsRequestedEventArgs(std::nullptr_t) noexcept {}
        VisualElementsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::StartScreen::IVisualElementsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
