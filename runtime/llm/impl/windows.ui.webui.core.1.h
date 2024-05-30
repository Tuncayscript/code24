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
#ifndef LLM_OS_UI_WebUI_Core_1_H
#define LLM_OS_UI_WebUI_Core_1_H
#include "llm/impl/Windows.UI.WebUI.Core.0.h"
LLM_EXPORT namespace llm::OS::UI::WebUI::Core
{
    struct __declspec(empty_bases) IWebUICommandBar :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBar>
    {
        IWebUICommandBar(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarBitmapIcon :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarBitmapIcon>,
        impl::require<llm::OS::UI::WebUI::Core::IWebUICommandBarBitmapIcon, llm::OS::UI::WebUI::Core::IWebUICommandBarIcon>
    {
        IWebUICommandBarBitmapIcon(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarBitmapIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarBitmapIconFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarBitmapIconFactory>
    {
        IWebUICommandBarBitmapIconFactory(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarBitmapIconFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarConfirmationButton :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarConfirmationButton>,
        impl::require<llm::OS::UI::WebUI::Core::IWebUICommandBarConfirmationButton, llm::OS::UI::WebUI::Core::IWebUICommandBarElement>
    {
        IWebUICommandBarConfirmationButton(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarConfirmationButton(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarElement :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarElement>
    {
        IWebUICommandBarElement(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarIcon :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarIcon>
    {
        IWebUICommandBarIcon(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarIconButton :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarIconButton>,
        impl::require<llm::OS::UI::WebUI::Core::IWebUICommandBarIconButton, llm::OS::UI::WebUI::Core::IWebUICommandBarElement>
    {
        IWebUICommandBarIconButton(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarIconButton(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarItemInvokedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarItemInvokedEventArgs>
    {
        IWebUICommandBarItemInvokedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarItemInvokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarSizeChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarSizeChangedEventArgs>
    {
        IWebUICommandBarSizeChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarSizeChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarStatics>
    {
        IWebUICommandBarStatics(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarSymbolIcon :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarSymbolIcon>,
        impl::require<llm::OS::UI::WebUI::Core::IWebUICommandBarSymbolIcon, llm::OS::UI::WebUI::Core::IWebUICommandBarIcon>
    {
        IWebUICommandBarSymbolIcon(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarSymbolIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebUICommandBarSymbolIconFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IWebUICommandBarSymbolIconFactory>
    {
        IWebUICommandBarSymbolIconFactory(std::nullptr_t = nullptr) noexcept {}
        IWebUICommandBarSymbolIconFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
