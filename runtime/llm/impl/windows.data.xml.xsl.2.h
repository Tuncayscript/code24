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
#ifndef LLM_OS_Data_Xml_Xsl_2_H
#define LLM_OS_Data_Xml_Xsl_2_H
#include "llm/impl/Windows.Data.Xml.Dom.1.h"
#include "llm/impl/Windows.Data.Xml.Xsl.1.h"
LLM_EXPORT namespace llm::OS::Data::Xml::Xsl
{
    struct __declspec(empty_bases) XsltProcessor : llm::OS::Data::Xml::Xsl::IXsltProcessor,
        impl::require<XsltProcessor, llm::OS::Data::Xml::Xsl::IXsltProcessor2>
    {
        XsltProcessor(std::nullptr_t) noexcept {}
        XsltProcessor(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Xsl::IXsltProcessor(ptr, take_ownership_from_abi) {}
        explicit XsltProcessor(llm::OS::Data::Xml::Dom::XmlDocument const& document);
    };
}
#endif
