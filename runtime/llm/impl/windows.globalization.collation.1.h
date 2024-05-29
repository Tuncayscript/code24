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
#ifndef LLM_OS_Globalization_Collation_1_H
#define LLM_OS_Globalization_Collation_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.Globalization.Collation.0.h"
LLM_EXPORT namespace llm:OS::Globalization::Collation
{
    struct __declspec(empty_bases) ICharacterGrouping :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICharacterGrouping>
    {
        ICharacterGrouping(std::nullptr_t = nullptr) noexcept {}
        ICharacterGrouping(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICharacterGroupings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICharacterGroupings>,
        impl::require<llm:OS::Globalization::Collation::ICharacterGroupings, llm:OS::Foundation::Collections::IIterable<llm:OS::Globalization::Collation::CharacterGrouping>, llm:OS::Foundation::Collections::IVectorView<llm:OS::Globalization::Collation::CharacterGrouping>>
    {
        ICharacterGroupings(std::nullptr_t = nullptr) noexcept {}
        ICharacterGroupings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICharacterGroupingsFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICharacterGroupingsFactory>
    {
        ICharacterGroupingsFactory(std::nullptr_t = nullptr) noexcept {}
        ICharacterGroupingsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
