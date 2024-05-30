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
#ifndef LLM_OS_UI_Popups_2_H
#define LLM_OS_UI_Popups_2_H
#include "llm/impl/Windows.UI.Popups.1.h"
LLM_EXPORT namespace llm:OS::UI::Popups
{
    struct UICommandInvokedHandler : llm:OS::Foundation::IUnknown
    {
        UICommandInvokedHandler(std::nullptr_t = nullptr) noexcept {}
        UICommandInvokedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> UICommandInvokedHandler(L lambda);
        template <typename F> UICommandInvokedHandler(F* function);
        template <typename O, typename M> UICommandInvokedHandler(O* object, M method);
        template <typename O, typename M> UICommandInvokedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> UICommandInvokedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::UI::Popups::IUICommand const& command) const;
    };
    struct __declspec(empty_bases) MessageDialog : llm:OS::UI::Popups::IMessageDialog
    {
        MessageDialog(std::nullptr_t) noexcept {}
        MessageDialog(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Popups::IMessageDialog(ptr, take_ownership_from_abi) {}
        explicit MessageDialog(param::hstring const& content);
        MessageDialog(param::hstring const& content, param::hstring const& title);
    };
    struct __declspec(empty_bases) PopupMenu : llm:OS::UI::Popups::IPopupMenu
    {
        PopupMenu(std::nullptr_t) noexcept {}
        PopupMenu(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Popups::IPopupMenu(ptr, take_ownership_from_abi) {}
        PopupMenu();
    };
    struct __declspec(empty_bases) UICommand : llm:OS::UI::Popups::IUICommand
    {
        UICommand(std::nullptr_t) noexcept {}
        UICommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Popups::IUICommand(ptr, take_ownership_from_abi) {}
        UICommand();
        explicit UICommand(param::hstring const& label);
        UICommand(param::hstring const& label, llm:OS::UI::Popups::UICommandInvokedHandler const& action);
        UICommand(param::hstring const& label, llm:OS::UI::Popups::UICommandInvokedHandler const& action, llm:OS::Foundation::IInspectable const& commandId);
    };
    struct __declspec(empty_bases) UICommandSeparator : llm:OS::UI::Popups::IUICommand
    {
        UICommandSeparator(std::nullptr_t) noexcept {}
        UICommandSeparator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Popups::IUICommand(ptr, take_ownership_from_abi) {}
        UICommandSeparator();
    };
}
#endif
