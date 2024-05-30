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
#ifndef LLM_OS_Phone_UI_Core_1_H
#define LLM_OS_Phone_UI_Core_1_H
#include "llm/impl/Windows.Phone.UI.Core.0.h"
LLM_EXPORT namespace llm:OS::Phone::UI::Core
{
    struct __declspec(empty_bases) ICoreSelectionChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreSelectionChangedEventArgs>
    {
        ICoreSelectionChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreSelectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreTextChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreTextChangedEventArgs>
    {
        ICoreTextChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICoreTextChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICoreWindowKeyboardInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICoreWindowKeyboardInput>
    {
        ICoreWindowKeyboardInput(std::nullptr_t = nullptr) noexcept {}
        ICoreWindowKeyboardInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKeyboardInputBuffer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IKeyboardInputBuffer>
    {
        IKeyboardInputBuffer(std::nullptr_t = nullptr) noexcept {}
        IKeyboardInputBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
