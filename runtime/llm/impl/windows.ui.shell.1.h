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
#ifndef LLM_OS_UI_Shell_1_H
#define LLM_OS_UI_Shell_1_H
#include "llm/impl/Windows.UI.Shell.0.h"
LLM_EXPORT namespace llm:OS::UI::Shell
{
    struct __declspec(empty_bases) IAdaptiveCard :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveCard>
    {
        IAdaptiveCard(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveCard(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdaptiveCardBuilderStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdaptiveCardBuilderStatics>
    {
        IAdaptiveCardBuilderStatics(std::nullptr_t = nullptr) noexcept {}
        IAdaptiveCardBuilderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFocusSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFocusSession>
    {
        IFocusSession(std::nullptr_t = nullptr) noexcept {}
        IFocusSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFocusSessionManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFocusSessionManager>
    {
        IFocusSessionManager(std::nullptr_t = nullptr) noexcept {}
        IFocusSessionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFocusSessionManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFocusSessionManagerStatics>
    {
        IFocusSessionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IFocusSessionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecurityAppManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecurityAppManager>
    {
        ISecurityAppManager(std::nullptr_t = nullptr) noexcept {}
        ISecurityAppManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareWindowCommandEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShareWindowCommandEventArgs>
    {
        IShareWindowCommandEventArgs(std::nullptr_t = nullptr) noexcept {}
        IShareWindowCommandEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareWindowCommandSource :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShareWindowCommandSource>
    {
        IShareWindowCommandSource(std::nullptr_t = nullptr) noexcept {}
        IShareWindowCommandSource(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareWindowCommandSourceStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IShareWindowCommandSourceStatics>
    {
        IShareWindowCommandSourceStatics(std::nullptr_t = nullptr) noexcept {}
        IShareWindowCommandSourceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITaskbarManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITaskbarManager>
    {
        ITaskbarManager(std::nullptr_t = nullptr) noexcept {}
        ITaskbarManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITaskbarManager2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITaskbarManager2>,
        impl::require<llm:OS::UI::Shell::ITaskbarManager2, llm:OS::UI::Shell::ITaskbarManager>
    {
        ITaskbarManager2(std::nullptr_t = nullptr) noexcept {}
        ITaskbarManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITaskbarManagerDesktopAppSupportStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITaskbarManagerDesktopAppSupportStatics>
    {
        ITaskbarManagerDesktopAppSupportStatics(std::nullptr_t = nullptr) noexcept {}
        ITaskbarManagerDesktopAppSupportStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ITaskbarManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ITaskbarManagerStatics>
    {
        ITaskbarManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ITaskbarManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTab :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTab>
    {
        IWindowTab(std::nullptr_t = nullptr) noexcept {}
        IWindowTab(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabCloseRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabCloseRequestedEventArgs>
    {
        IWindowTabCloseRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowTabCloseRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabCollection :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabCollection>
    {
        IWindowTabCollection(std::nullptr_t = nullptr) noexcept {}
        IWindowTabCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabGroup :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabGroup>
    {
        IWindowTabGroup(std::nullptr_t = nullptr) noexcept {}
        IWindowTabGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabIcon :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabIcon>
    {
        IWindowTabIcon(std::nullptr_t = nullptr) noexcept {}
        IWindowTabIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabIconStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabIconStatics>
    {
        IWindowTabIconStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowTabIconStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabManager>
    {
        IWindowTabManager(std::nullptr_t = nullptr) noexcept {}
        IWindowTabManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabManagerStatics>
    {
        IWindowTabManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IWindowTabManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabSwitchRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabSwitchRequestedEventArgs>
    {
        IWindowTabSwitchRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowTabSwitchRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabTearOutRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabTearOutRequestedEventArgs>
    {
        IWindowTabTearOutRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowTabTearOutRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWindowTabThumbnailRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWindowTabThumbnailRequestedEventArgs>
    {
        IWindowTabThumbnailRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWindowTabThumbnailRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
