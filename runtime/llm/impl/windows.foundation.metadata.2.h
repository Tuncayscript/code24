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
#ifndef LLM_OS_Foundation_Metadata_2_H
#define LLM_OS_Foundation_Metadata_2_H
#include "llm/impl/Windows.Foundation.Metadata.1.h"
LLM_EXPORT namespace llm::OS::Foundation::Metadata
{
    struct ApiInformation
    {
        ApiInformation() = delete;
        static auto IsTypePresent(param::hstring const& typeName);
        static auto IsMethodPresent(param::hstring const& typeName, param::hstring const& methodName);
        static auto IsMethodPresent(param::hstring const& typeName, param::hstring const& methodName, uint32_t inputParameterCount);
        static auto IsEventPresent(param::hstring const& typeName, param::hstring const& eventName);
        static auto IsPropertyPresent(param::hstring const& typeName, param::hstring const& propertyName);
        static auto IsReadOnlyPropertyPresent(param::hstring const& typeName, param::hstring const& propertyName);
        static auto IsWriteablePropertyPresent(param::hstring const& typeName, param::hstring const& propertyName);
        static auto IsEnumNamedValuePresent(param::hstring const& enumTypeName, param::hstring const& valueName);
        static auto IsApiContractPresent(param::hstring const& contractName, uint16_t majorVersion);
        static auto IsApiContractPresent(param::hstring const& contractName, uint16_t majorVersion, uint16_t minorVersion);
    };
}
#endif
