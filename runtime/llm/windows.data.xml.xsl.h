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
#ifndef LLM_OS_Data_Xml_Xsl_H
#define LLM_OS_Data_Xml_Xsl_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/impl/Windows.Data.Xml.Dom.2.h"
#include "llm/impl/Windows.Data.Xml.Xsl.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Data_Xml_Xsl_IXsltProcessor<D>::TransformToString(llm::OS::Data::Xml::Dom::IXmlNode const& inputNode) const
    {
        void* output{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Xml::Xsl::IXsltProcessor)->TransformToString(*(void**)(&inputNode), &output));
        return hstring{ output, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Xml::Dom::XmlDocument) consume_Windows_Data_Xml_Xsl_IXsltProcessor2<D>::TransformToDocument(llm::OS::Data::Xml::Dom::IXmlNode const& inputNode) const
    {
        void* output{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Xml::Xsl::IXsltProcessor2)->TransformToDocument(*(void**)(&inputNode), &output));
        return llm::OS::Data::Xml::Dom::XmlDocument{ output, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Xml::Xsl::XsltProcessor) consume_Windows_Data_Xml_Xsl_IXsltProcessorFactory<D>::CreateInstance(llm::OS::Data::Xml::Dom::XmlDocument const& document) const
    {
        void* xsltProcessor{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Data::Xml::Xsl::IXsltProcessorFactory)->CreateInstance(*(void**)(&document), &xsltProcessor));
        return llm::OS::Data::Xml::Xsl::XsltProcessor{ xsltProcessor, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Xml::Xsl::IXsltProcessor> : produce_base<D, llm::OS::Data::Xml::Xsl::IXsltProcessor>
    {
        int32_t __stdcall TransformToString(void* inputNode, void** output) noexcept final try
        {
            clear_abi(output);
            typename D::abi_guard guard(this->shim());
            *output = detach_from<hstring>(this->shim().TransformToString(*reinterpret_cast<llm::OS::Data::Xml::Dom::IXmlNode const*>(&inputNode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Xml::Xsl::IXsltProcessor2> : produce_base<D, llm::OS::Data::Xml::Xsl::IXsltProcessor2>
    {
        int32_t __stdcall TransformToDocument(void* inputNode, void** output) noexcept final try
        {
            clear_abi(output);
            typename D::abi_guard guard(this->shim());
            *output = detach_from<llm::OS::Data::Xml::Dom::XmlDocument>(this->shim().TransformToDocument(*reinterpret_cast<llm::OS::Data::Xml::Dom::IXmlNode const*>(&inputNode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Data::Xml::Xsl::IXsltProcessorFactory> : produce_base<D, llm::OS::Data::Xml::Xsl::IXsltProcessorFactory>
    {
        int32_t __stdcall CreateInstance(void* document, void** xsltProcessor) noexcept final try
        {
            clear_abi(xsltProcessor);
            typename D::abi_guard guard(this->shim());
            *xsltProcessor = detach_from<llm::OS::Data::Xml::Xsl::XsltProcessor>(this->shim().CreateInstance(*reinterpret_cast<llm::OS::Data::Xml::Dom::XmlDocument const*>(&document)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Data::Xml::Xsl
{
    inline XsltProcessor::XsltProcessor(llm::OS::Data::Xml::Dom::XmlDocument const& document) :
        XsltProcessor(impl::call_factory<XsltProcessor, IXsltProcessorFactory>([&](IXsltProcessorFactory const& f) { return f.CreateInstance(document); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Data::Xml::Xsl::IXsltProcessor> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Xml::Xsl::IXsltProcessor2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Xml::Xsl::IXsltProcessorFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Data::Xml::Xsl::XsltProcessor> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
