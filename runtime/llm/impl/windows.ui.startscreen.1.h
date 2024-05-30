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
#ifndef LLM_OS_UI_StartScreen_1_H
#define LLM_OS_UI_StartScreen_1_H
#include "llm/impl/Windows.UI.StartScreen.0.h"
LLM_EXPORT namespace llm:OS::UI::StartScreen
{
    struct __declspec(empty_bases) IJumpList :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IJumpList>
    {
        IJumpList(std::nullptr_t = nullptr) noexcept {}
        IJumpList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJumpListItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IJumpListItem>
    {
        IJumpListItem(std::nullptr_t = nullptr) noexcept {}
        IJumpListItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJumpListItemStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IJumpListItemStatics>
    {
        IJumpListItemStatics(std::nullptr_t = nullptr) noexcept {}
        IJumpListItemStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IJumpListStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IJumpListStatics>
    {
        IJumpListStatics(std::nullptr_t = nullptr) noexcept {}
        IJumpListStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTile>
    {
        ISecondaryTile(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTile2>,
        impl::require<llm:OS::UI::StartScreen::ISecondaryTile2, llm:OS::UI::StartScreen::ISecondaryTile>
    {
        ISecondaryTile2(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileFactory>
    {
        ISecondaryTileFactory(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileFactory2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileFactory2>,
        impl::require<llm:OS::UI::StartScreen::ISecondaryTileFactory2, llm:OS::UI::StartScreen::ISecondaryTileFactory>
    {
        ISecondaryTileFactory2(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileFactory2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileStatics>
    {
        ISecondaryTileStatics(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileVisualElements :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileVisualElements>
    {
        ISecondaryTileVisualElements(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileVisualElements(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileVisualElements2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileVisualElements2>
    {
        ISecondaryTileVisualElements2(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileVisualElements2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileVisualElements3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileVisualElements3>
    {
        ISecondaryTileVisualElements3(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileVisualElements3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryTileVisualElements4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryTileVisualElements4>
    {
        ISecondaryTileVisualElements4(std::nullptr_t = nullptr) noexcept {}
        ISecondaryTileVisualElements4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStartScreenManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStartScreenManager>
    {
        IStartScreenManager(std::nullptr_t = nullptr) noexcept {}
        IStartScreenManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStartScreenManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStartScreenManager2>,
        impl::require<llm:OS::UI::StartScreen::IStartScreenManager2, llm:OS::UI::StartScreen::IStartScreenManager>
    {
        IStartScreenManager2(std::nullptr_t = nullptr) noexcept {}
        IStartScreenManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStartScreenManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStartScreenManagerStatics>
    {
        IStartScreenManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IStartScreenManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileMixedRealityModel :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileMixedRealityModel>
    {
        ITileMixedRealityModel(std::nullptr_t = nullptr) noexcept {}
        ITileMixedRealityModel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITileMixedRealityModel2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITileMixedRealityModel2>
    {
        ITileMixedRealityModel2(std::nullptr_t = nullptr) noexcept {}
        ITileMixedRealityModel2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualElementsRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualElementsRequest>
    {
        IVisualElementsRequest(std::nullptr_t = nullptr) noexcept {}
        IVisualElementsRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualElementsRequestDeferral :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualElementsRequestDeferral>
    {
        IVisualElementsRequestDeferral(std::nullptr_t = nullptr) noexcept {}
        IVisualElementsRequestDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVisualElementsRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVisualElementsRequestedEventArgs>
    {
        IVisualElementsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVisualElementsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
