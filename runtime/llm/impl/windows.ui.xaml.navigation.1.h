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
#ifndef LLM_OS_UI_Xaml_Navigation_1_H
#define LLM_OS_UI_Xaml_Navigation_1_H
#include "llm/impl/Windows.UI.Xaml.Navigation.0.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Navigation
{
    struct __declspec(empty_bases) IFrameNavigationOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFrameNavigationOptions>
    {
        IFrameNavigationOptions(std::nullptr_t = nullptr) noexcept {}
        IFrameNavigationOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFrameNavigationOptionsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFrameNavigationOptionsFactory>
    {
        IFrameNavigationOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        IFrameNavigationOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INavigatingCancelEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INavigatingCancelEventArgs>
    {
        INavigatingCancelEventArgs(std::nullptr_t = nullptr) noexcept {}
        INavigatingCancelEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INavigatingCancelEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INavigatingCancelEventArgs2>
    {
        INavigatingCancelEventArgs2(std::nullptr_t = nullptr) noexcept {}
        INavigatingCancelEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INavigationEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INavigationEventArgs>
    {
        INavigationEventArgs(std::nullptr_t = nullptr) noexcept {}
        INavigationEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INavigationEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INavigationEventArgs2>
    {
        INavigationEventArgs2(std::nullptr_t = nullptr) noexcept {}
        INavigationEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) INavigationFailedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<INavigationFailedEventArgs>
    {
        INavigationFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        INavigationFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPageStackEntry :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPageStackEntry>
    {
        IPageStackEntry(std::nullptr_t = nullptr) noexcept {}
        IPageStackEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPageStackEntryFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPageStackEntryFactory>
    {
        IPageStackEntryFactory(std::nullptr_t = nullptr) noexcept {}
        IPageStackEntryFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPageStackEntryStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPageStackEntryStatics>
    {
        IPageStackEntryStatics(std::nullptr_t = nullptr) noexcept {}
        IPageStackEntryStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
