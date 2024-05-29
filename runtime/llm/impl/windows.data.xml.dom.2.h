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
#ifndef LLM_OS_Data_Xml_Dom_2_H
#define LLM_OS_Data_Xml_Dom_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.1.h"
#include "llm/impl/Windows.Data.Xml.Dom.1.h"
LLM_EXPORT namespace llm::OS::Data::Xml::Dom
{
    struct __declspec(empty_bases) DtdEntity : llm::OS::Data::Xml::Dom::IDtdEntity
    {
        DtdEntity(std::nullptr_t) noexcept {}
        DtdEntity(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IDtdEntity(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DtdNotation : llm::OS::Data::Xml::Dom::IDtdNotation
    {
        DtdNotation(std::nullptr_t) noexcept {}
        DtdNotation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IDtdNotation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlAttribute : llm::OS::Data::Xml::Dom::IXmlAttribute
    {
        XmlAttribute(std::nullptr_t) noexcept {}
        XmlAttribute(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlAttribute(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlCDataSection : llm::OS::Data::Xml::Dom::IXmlCDataSection
    {
        XmlCDataSection(std::nullptr_t) noexcept {}
        XmlCDataSection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlCDataSection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlComment : llm::OS::Data::Xml::Dom::IXmlComment
    {
        XmlComment(std::nullptr_t) noexcept {}
        XmlComment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlComment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlDocument : llm::OS::Data::Xml::Dom::IXmlDocument,
        impl::require<XmlDocument, llm::OS::Data::Xml::Dom::IXmlDocumentIO, llm::OS::Data::Xml::Dom::IXmlDocumentIO2>
    {
        XmlDocument(std::nullptr_t) noexcept {}
        XmlDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlDocument(ptr, take_ownership_from_abi) {}
        XmlDocument();
        static auto LoadFromUriAsync(llm::OS::Foundation::Uri const& uri);
        static auto LoadFromUriAsync(llm::OS::Foundation::Uri const& uri, llm::OS::Data::Xml::Dom::XmlLoadSettings const& loadSettings);
        static auto LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file);
        static auto LoadFromFileAsync(llm::OS::Storage::IStorageFile const& file, llm::OS::Data::Xml::Dom::XmlLoadSettings const& loadSettings);
    };
    struct __declspec(empty_bases) XmlDocumentFragment : llm::OS::Data::Xml::Dom::IXmlDocumentFragment
    {
        XmlDocumentFragment(std::nullptr_t) noexcept {}
        XmlDocumentFragment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlDocumentFragment(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlDocumentType : llm::OS::Data::Xml::Dom::IXmlDocumentType
    {
        XmlDocumentType(std::nullptr_t) noexcept {}
        XmlDocumentType(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlDocumentType(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlDomImplementation : llm::OS::Data::Xml::Dom::IXmlDomImplementation
    {
        XmlDomImplementation(std::nullptr_t) noexcept {}
        XmlDomImplementation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlDomImplementation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlElement : llm::OS::Data::Xml::Dom::IXmlElement
    {
        XmlElement(std::nullptr_t) noexcept {}
        XmlElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlElement(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlEntityReference : llm::OS::Data::Xml::Dom::IXmlEntityReference
    {
        XmlEntityReference(std::nullptr_t) noexcept {}
        XmlEntityReference(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlEntityReference(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlLoadSettings : llm::OS::Data::Xml::Dom::IXmlLoadSettings
    {
        XmlLoadSettings(std::nullptr_t) noexcept {}
        XmlLoadSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlLoadSettings(ptr, take_ownership_from_abi) {}
        XmlLoadSettings();
    };
    struct __declspec(empty_bases) XmlNamedNodeMap : llm::OS::Data::Xml::Dom::IXmlNamedNodeMap
    {
        XmlNamedNodeMap(std::nullptr_t) noexcept {}
        XmlNamedNodeMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlNamedNodeMap(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlNodeList : llm::OS::Data::Xml::Dom::IXmlNodeList
    {
        XmlNodeList(std::nullptr_t) noexcept {}
        XmlNodeList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlNodeList(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlProcessingInstruction : llm::OS::Data::Xml::Dom::IXmlProcessingInstruction
    {
        XmlProcessingInstruction(std::nullptr_t) noexcept {}
        XmlProcessingInstruction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlProcessingInstruction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XmlText : llm::OS::Data::Xml::Dom::IXmlText
    {
        XmlText(std::nullptr_t) noexcept {}
        XmlText(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Data::Xml::Dom::IXmlText(ptr, take_ownership_from_abi) {}
    };
}
#endif
