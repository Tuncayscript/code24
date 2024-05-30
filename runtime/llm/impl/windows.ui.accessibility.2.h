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
#ifndef LLM_OS_UI_Accessibility_2_H
#define LLM_OS_UI_Accessibility_2_H
#include "llm/impl/Windows.UI.Accessibility.1.h"
LLM_EXPORT namespace llm:OS::UI::Accessibility
{
    struct __declspec(empty_bases) ScreenReaderPositionChangedEventArgs : llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs
    {
        ScreenReaderPositionChangedEventArgs(std::nullptr_t) noexcept {}
        ScreenReaderPositionChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Accessibility::IScreenReaderPositionChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ScreenReaderService : llm:OS::UI::Accessibility::IScreenReaderService
    {
        ScreenReaderService(std::nullptr_t) noexcept {}
        ScreenReaderService(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::Accessibility::IScreenReaderService(ptr, take_ownership_from_abi) {}
        ScreenReaderService();
    };
}
#endif
