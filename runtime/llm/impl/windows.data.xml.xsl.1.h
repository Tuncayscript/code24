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
#ifndef LLM_OS_Data_Xml_Xsl_1_H
#define LLM_OS_Data_Xml_Xsl_1_H
#include "llm/impl/Windows.Data.Xml.Xsl.0.h"
LLM_EXPORT namespace llm::OS::Data::Xml::Xsl
{
    struct __declspec(empty_bases) IXsltProcessor :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXsltProcessor>
    {
        IXsltProcessor(std::nullptr_t = nullptr) noexcept {}
        IXsltProcessor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXsltProcessor2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXsltProcessor2>
    {
        IXsltProcessor2(std::nullptr_t = nullptr) noexcept {}
        IXsltProcessor2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXsltProcessorFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXsltProcessorFactory>
    {
        IXsltProcessorFactory(std::nullptr_t = nullptr) noexcept {}
        IXsltProcessorFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
