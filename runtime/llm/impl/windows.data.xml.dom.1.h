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
#ifndef LLM_OS_Data_Xml_Dom_1_H
#define LLM_OS_Data_Xml_Dom_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.Data.Xml.Dom.0.h"
LLM_EXPORT namespace llm::OS::Data::Xml::Dom
{
    struct __declspec(empty_bases) IDtdEntity :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDtdEntity>,
        impl::require<llm::OS::Data::Xml::Dom::IDtdEntity, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IDtdEntity(std::nullptr_t = nullptr) noexcept {}
        IDtdEntity(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDtdNotation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IDtdNotation>,
        impl::require<llm::OS::Data::Xml::Dom::IDtdNotation, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IDtdNotation(std::nullptr_t = nullptr) noexcept {}
        IDtdNotation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlAttribute :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlAttribute>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlAttribute, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlAttribute(std::nullptr_t = nullptr) noexcept {}
        IXmlAttribute(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlCDataSection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlCDataSection>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlCDataSection, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode, llm::OS::Data::Xml::Dom::IXmlCharacterData, llm::OS::Data::Xml::Dom::IXmlText>
    {
        IXmlCDataSection(std::nullptr_t = nullptr) noexcept {}
        IXmlCDataSection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlCharacterData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlCharacterData>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlCharacterData, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlCharacterData(std::nullptr_t = nullptr) noexcept {}
        IXmlCharacterData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlComment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlComment>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlComment, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode, llm::OS::Data::Xml::Dom::IXmlCharacterData>
    {
        IXmlComment(std::nullptr_t = nullptr) noexcept {}
        IXmlComment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDocument :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDocument>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlDocument, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlDocument(std::nullptr_t = nullptr) noexcept {}
        IXmlDocument(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDocumentFragment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDocumentFragment>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlDocumentFragment, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlDocumentFragment(std::nullptr_t = nullptr) noexcept {}
        IXmlDocumentFragment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDocumentIO :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDocumentIO>
    {
        IXmlDocumentIO(std::nullptr_t = nullptr) noexcept {}
        IXmlDocumentIO(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDocumentIO2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDocumentIO2>
    {
        IXmlDocumentIO2(std::nullptr_t = nullptr) noexcept {}
        IXmlDocumentIO2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDocumentStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDocumentStatics>
    {
        IXmlDocumentStatics(std::nullptr_t = nullptr) noexcept {}
        IXmlDocumentStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDocumentType :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDocumentType>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlDocumentType, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlDocumentType(std::nullptr_t = nullptr) noexcept {}
        IXmlDocumentType(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlDomImplementation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlDomImplementation>
    {
        IXmlDomImplementation(std::nullptr_t = nullptr) noexcept {}
        IXmlDomImplementation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlElement :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlElement>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlElement, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlElement(std::nullptr_t = nullptr) noexcept {}
        IXmlElement(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlEntityReference :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlEntityReference>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlEntityReference, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlEntityReference(std::nullptr_t = nullptr) noexcept {}
        IXmlEntityReference(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlLoadSettings :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlLoadSettings>
    {
        IXmlLoadSettings(std::nullptr_t = nullptr) noexcept {}
        IXmlLoadSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlNamedNodeMap :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlNamedNodeMap>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlNamedNodeMap, llm::OS::Foundation::Collections::IIterable<llm::OS::Data::Xml::Dom::IXmlNode>, llm::OS::Foundation::Collections::IVectorView<llm::OS::Data::Xml::Dom::IXmlNode>>
    {
        IXmlNamedNodeMap(std::nullptr_t = nullptr) noexcept {}
        IXmlNamedNodeMap(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlNode :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlNode>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlNode, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer>
    {
        IXmlNode(std::nullptr_t = nullptr) noexcept {}
        IXmlNode(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlNodeList :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlNodeList>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlNodeList, llm::OS::Foundation::Collections::IIterable<llm::OS::Data::Xml::Dom::IXmlNode>, llm::OS::Foundation::Collections::IVectorView<llm::OS::Data::Xml::Dom::IXmlNode>>
    {
        IXmlNodeList(std::nullptr_t = nullptr) noexcept {}
        IXmlNodeList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlNodeSelector :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlNodeSelector>
    {
        IXmlNodeSelector(std::nullptr_t = nullptr) noexcept {}
        IXmlNodeSelector(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlNodeSerializer :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlNodeSerializer>
    {
        IXmlNodeSerializer(std::nullptr_t = nullptr) noexcept {}
        IXmlNodeSerializer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlProcessingInstruction :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlProcessingInstruction>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlProcessingInstruction, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode>
    {
        IXmlProcessingInstruction(std::nullptr_t = nullptr) noexcept {}
        IXmlProcessingInstruction(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXmlText :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IXmlText>,
        impl::require<llm::OS::Data::Xml::Dom::IXmlText, llm::OS::Data::Xml::Dom::IXmlNodeSelector, llm::OS::Data::Xml::Dom::IXmlNodeSerializer, llm::OS::Data::Xml::Dom::IXmlNode, llm::OS::Data::Xml::Dom::IXmlCharacterData>
    {
        IXmlText(std::nullptr_t = nullptr) noexcept {}
        IXmlText(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
