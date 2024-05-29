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
#ifndef LLM_OS_Globalization_Collation_2_H
#define LLM_OS_Globalization_Collation_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Globalization.Collation.1.h"
LLM_EXPORT namespace llm:OS::Globalization::Collation
{
    struct __declspec(empty_bases) CharacterGrouping : llm:OS::Globalization::Collation::ICharacterGrouping
    {
        CharacterGrouping(std::nullptr_t) noexcept {}
        CharacterGrouping(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::Collation::ICharacterGrouping(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CharacterGroupings : llm:OS::Globalization::Collation::ICharacterGroupings
    {
        CharacterGroupings(std::nullptr_t) noexcept {}
        CharacterGroupings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Globalization::Collation::ICharacterGroupings(ptr, take_ownership_from_abi) {}
        CharacterGroupings();
        explicit CharacterGroupings(param::hstring const& language);
    };
}
#endif
