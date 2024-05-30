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
#ifndef LLM_OS_UI_Xaml_Core_Direct_2_H
#define LLM_OS_UI_Xaml_Core_Direct_2_H
#include "llm/impl/Windows.UI.Xaml.Core.Direct.1.h"
LLM_EXPORT namespace llm::OS::UI::Xaml::Core::Direct
{
    struct __declspec(empty_bases) XamlDirect : llm::OS::UI::Xaml::Core::Direct::IXamlDirect
    {
        XamlDirect(std::nullptr_t) noexcept {}
        XamlDirect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::UI::Xaml::Core::Direct::IXamlDirect(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
    };
}
#endif
