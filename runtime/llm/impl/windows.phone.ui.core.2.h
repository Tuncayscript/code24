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
#ifndef LLM_OS_Phone_UI_Core_2_H
#define LLM_OS_Phone_UI_Core_2_H
#include "llm/impl/Windows.Phone.UI.Core.1.h"
LLM_EXPORT namespace llm:OS::Phone::UI::Core
{
    struct __declspec(empty_bases) CoreSelectionChangedEventArgs : llm:OS::Phone::UI::Core::ICoreSelectionChangedEventArgs
    {
        CoreSelectionChangedEventArgs(std::nullptr_t) noexcept {}
        CoreSelectionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::UI::Core::ICoreSelectionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CoreTextChangedEventArgs : llm:OS::Phone::UI::Core::ICoreTextChangedEventArgs
    {
        CoreTextChangedEventArgs(std::nullptr_t) noexcept {}
        CoreTextChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::UI::Core::ICoreTextChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) KeyboardInputBuffer : llm:OS::Phone::UI::Core::IKeyboardInputBuffer
    {
        KeyboardInputBuffer(std::nullptr_t) noexcept {}
        KeyboardInputBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::UI::Core::IKeyboardInputBuffer(ptr, take_ownership_from_abi) {}
        KeyboardInputBuffer();
    };
}
#endif
