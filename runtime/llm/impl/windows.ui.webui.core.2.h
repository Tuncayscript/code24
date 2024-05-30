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
#ifndef LLM_OS_UI_WebUI_Core_2_H
#define LLM_OS_UI_WebUI_Core_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.UI.WebUI.Core.1.h"
LLM_EXPORT namespace llm::OS::UI::WebUI::Core
{
    struct MenuClosedEventHandler : llm::OS::Foundation::IUnknown
    {
        MenuClosedEventHandler(std::nullptr_t = nullptr) noexcept {}
        MenuClosedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MenuClosedEventHandler(L lambda);
        template <typename F> MenuClosedEventHandler(F* function);
        template <typename O, typename M> MenuClosedEventHandler(O* object, M method);
        template <typename O, typename M> MenuClosedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> MenuClosedEventHandler(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    struct MenuOpenedEventHandler : llm::OS::Foundation::IUnknown
    {
        MenuOpenedEventHandler(std::nullptr_t = nullptr) noexcept {}
        MenuOpenedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MenuOpenedEventHandler(L lambda);
        template <typename F> MenuOpenedEventHandler(F* function);
        template <typename O, typename M> MenuOpenedEventHandler(O* object, M method);
        template <typename O, typename M> MenuOpenedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> MenuOpenedEventHandler(weak_ref<O>&& object, M method);
        auto operator()() const;
    };
    struct SizeChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        SizeChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        SizeChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SizeChangedEventHandler(L lambda);
        template <typename F> SizeChangedEventHandler(F* function);
        template <typename O, typename M> SizeChangedEventHandler(O* object, M method);
        template <typename O, typename M> SizeChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SizeChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::UI::WebUI::Core::WebUICommandBarSizeChangedEventArgs const& eventArgs) const;
    };
    struct __declspec(empty_bases) WebUICommandBar : llm::OS::UI::WebUI::Core::IWebUICommandBar
    {
        WebUICommandBar(std::nullptr_t) noexcept {}
        WebUICommandBar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBar(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) WebUICommandBarBitmapIcon : llm::OS::UI::WebUI::Core::IWebUICommandBarBitmapIcon
    {
        WebUICommandBarBitmapIcon(std::nullptr_t) noexcept {}
        WebUICommandBarBitmapIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBarBitmapIcon(ptr, take_ownership_from_abi) {}
        WebUICommandBarBitmapIcon();
        explicit WebUICommandBarBitmapIcon(llm::OS::Foundation::Uri const& uri);
    };
    struct __declspec(empty_bases) WebUICommandBarConfirmationButton : llm::OS::UI::WebUI::Core::IWebUICommandBarConfirmationButton
    {
        WebUICommandBarConfirmationButton(std::nullptr_t) noexcept {}
        WebUICommandBarConfirmationButton(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBarConfirmationButton(ptr, take_ownership_from_abi) {}
        WebUICommandBarConfirmationButton();
    };
    struct __declspec(empty_bases) WebUICommandBarIconButton : llm::OS::UI::WebUI::Core::IWebUICommandBarIconButton
    {
        WebUICommandBarIconButton(std::nullptr_t) noexcept {}
        WebUICommandBarIconButton(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBarIconButton(ptr, take_ownership_from_abi) {}
        WebUICommandBarIconButton();
    };
    struct __declspec(empty_bases) WebUICommandBarItemInvokedEventArgs : llm::OS::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs
    {
        WebUICommandBarItemInvokedEventArgs(std::nullptr_t) noexcept {}
        WebUICommandBarItemInvokedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBarItemInvokedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUICommandBarSizeChangedEventArgs : llm::OS::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs
    {
        WebUICommandBarSizeChangedEventArgs(std::nullptr_t) noexcept {}
        WebUICommandBarSizeChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBarSizeChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebUICommandBarSymbolIcon : llm::OS::UI::WebUI::Core::IWebUICommandBarSymbolIcon
    {
        WebUICommandBarSymbolIcon(std::nullptr_t) noexcept {}
        WebUICommandBarSymbolIcon(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::WebUI::Core::IWebUICommandBarSymbolIcon(ptr, take_ownership_from_abi) {}
        WebUICommandBarSymbolIcon();
        explicit WebUICommandBarSymbolIcon(param::hstring const& symbol);
    };
}
#endif
