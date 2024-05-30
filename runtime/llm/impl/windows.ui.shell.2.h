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
#ifndef LLM_OS_UI_Shell_2_H
#define LLM_OS_UI_Shell_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.UI.1.h"
#include "llm/impl/Windows.UI.Shell.1.h"
LLM_EXPORT namespace llm:OS::UI::Shell
{
    struct AdaptiveCardBuilder
    {
        AdaptiveCardBuilder() = delete;
        static auto CreateAdaptiveCardFromJson(param::hstring const& value);
    };
    struct __declspec(empty_bases) FocusSession : llm:OS::UI::Shell::IFocusSession
    {
        FocusSession(std::nullptr_t) noexcept {}
        FocusSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IFocusSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FocusSessionManager : llm:OS::UI::Shell::IFocusSessionManager
    {
        FocusSessionManager(std::nullptr_t) noexcept {}
        FocusSessionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IFocusSessionManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        [[nodiscard]] static auto IsSupported();
    };
    struct __declspec(empty_bases) SecurityAppManager : llm:OS::UI::Shell::ISecurityAppManager
    {
        SecurityAppManager(std::nullptr_t) noexcept {}
        SecurityAppManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::ISecurityAppManager(ptr, take_ownership_from_abi) {}
        SecurityAppManager();
    };
    struct __declspec(empty_bases) ShareWindowCommandEventArgs : llm:OS::UI::Shell::IShareWindowCommandEventArgs
    {
        ShareWindowCommandEventArgs(std::nullptr_t) noexcept {}
        ShareWindowCommandEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IShareWindowCommandEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ShareWindowCommandSource : llm:OS::UI::Shell::IShareWindowCommandSource
    {
        ShareWindowCommandSource(std::nullptr_t) noexcept {}
        ShareWindowCommandSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IShareWindowCommandSource(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) TaskbarManager : llm:OS::UI::Shell::ITaskbarManager,
        impl::require<TaskbarManager, llm:OS::UI::Shell::ITaskbarManager2>
    {
        TaskbarManager(std::nullptr_t) noexcept {}
        TaskbarManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::ITaskbarManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
    struct __declspec(empty_bases) WindowTab : llm:OS::UI::Shell::IWindowTab
    {
        WindowTab(std::nullptr_t) noexcept {}
        WindowTab(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTab(ptr, take_ownership_from_abi) {}
        WindowTab();
    };
    struct __declspec(empty_bases) WindowTabCloseRequestedEventArgs : llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs
    {
        WindowTabCloseRequestedEventArgs(std::nullptr_t) noexcept {}
        WindowTabCloseRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabCloseRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowTabCollection : llm:OS::UI::Shell::IWindowTabCollection,
        impl::require<WindowTabCollection, llm:OS::Foundation::Collections::IIterable<llm:OS::UI::Shell::WindowTab>, llm:OS::Foundation::Collections::IVector<llm:OS::UI::Shell::WindowTab>>
    {
        WindowTabCollection(std::nullptr_t) noexcept {}
        WindowTabCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabCollection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowTabGroup : llm:OS::UI::Shell::IWindowTabGroup
    {
        WindowTabGroup(std::nullptr_t) noexcept {}
        WindowTabGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabGroup(ptr, take_ownership_from_abi) {}
        WindowTabGroup();
    };
    struct __declspec(empty_bases) WindowTabIcon : llm:OS::UI::Shell::IWindowTabIcon
    {
        WindowTabIcon(std::nullptr_t) noexcept {}
        WindowTabIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabIcon(ptr, take_ownership_from_abi) {}
        static auto CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily);
        static auto CreateFromFontGlyph(param::hstring const& glyph, param::hstring const& fontFamily, llm:OS::Foundation::Uri const& fontUri);
        static auto CreateFromImage(llm:OS::Storage::Streams::IRandomAccessStreamReference const& image);
    };
    struct __declspec(empty_bases) WindowTabManager : llm:OS::UI::Shell::IWindowTabManager
    {
        WindowTabManager(std::nullptr_t) noexcept {}
        WindowTabManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabManager(ptr, take_ownership_from_abi) {}
        static auto GetForWindow(llm:OS::UI::WindowId const& id);
        static auto IsSupported();
        static auto IsTabTearOutSupported();
    };
    struct __declspec(empty_bases) WindowTabSwitchRequestedEventArgs : llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs
    {
        WindowTabSwitchRequestedEventArgs(std::nullptr_t) noexcept {}
        WindowTabSwitchRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabSwitchRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowTabTearOutRequestedEventArgs : llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs
    {
        WindowTabTearOutRequestedEventArgs(std::nullptr_t) noexcept {}
        WindowTabTearOutRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabTearOutRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WindowTabThumbnailRequestedEventArgs : llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs
    {
        WindowTabThumbnailRequestedEventArgs(std::nullptr_t) noexcept {}
        WindowTabThumbnailRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Shell::IWindowTabThumbnailRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
