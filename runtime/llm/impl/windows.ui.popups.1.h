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
#ifndef LLM_OS_UI_Popups_1_H
#define LLM_OS_UI_Popups_1_H
#include "llm/impl/Windows.UI.Popups.0.h"
LLM_EXPORT namespace llm:OS::UI::Popups
{
    struct __declspec(empty_bases) IMessageDialog :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageDialog>
    {
        IMessageDialog(std::nullptr_t = nullptr) noexcept {}
        IMessageDialog(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMessageDialogFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageDialogFactory>
    {
        IMessageDialogFactory(std::nullptr_t = nullptr) noexcept {}
        IMessageDialogFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPopupMenu :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPopupMenu>
    {
        IPopupMenu(std::nullptr_t = nullptr) noexcept {}
        IPopupMenu(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUICommand :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUICommand>
    {
        IUICommand(std::nullptr_t = nullptr) noexcept {}
        IUICommand(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUICommandFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUICommandFactory>
    {
        IUICommandFactory(std::nullptr_t = nullptr) noexcept {}
        IUICommandFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
