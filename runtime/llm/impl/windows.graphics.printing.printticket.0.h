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
#ifndef LLM_OS_Graphics_Printing_PrintTicket_0_H
#define LLM_OS_Graphics_Printing_PrintTicket_0_H
LLM_EXPORT namespace llm:OS::Data::Xml::Dom
{
    struct IXmlNode;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct HResult;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Graphics::Printing::PrintTicket
{
    enum class PrintTicketFeatureSelectionType : int32_t
    {
        PickOne = 0,
        PickMany = 1,
    };
    enum class PrintTicketParameterDataType : int32_t
    {
        Integer = 0,
        NumericString = 1,
        String = 2,
    };
    enum class PrintTicketValueType : int32_t
    {
        Integer = 0,
        String = 1,
        Unknown = 2,
    };
    struct IPrintTicketCapabilities;
    struct IPrintTicketFeature;
    struct IPrintTicketOption;
    struct IPrintTicketParameterDefinition;
    struct IPrintTicketParameterInitializer;
    struct IPrintTicketValue;
    struct IWorkflowPrintTicket;
    struct IWorkflowPrintTicketValidationResult;
    struct PrintTicketCapabilities;
    struct PrintTicketFeature;
    struct PrintTicketOption;
    struct PrintTicketParameterDefinition;
    struct PrintTicketParameterInitializer;
    struct PrintTicketValue;
    struct WorkflowPrintTicket;
    struct WorkflowPrintTicketValidationResult;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketCapabilities>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDefinition>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterInitializer>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicket>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicketValidationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeatureSelectionType>{ using type = enum_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDataType>{ using type = enum_category; };
    template <> struct category<llm:OS::Graphics::Printing::PrintTicket::PrintTicketValueType>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketCapabilities> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketFeature";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketOption";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDefinition> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketParameterDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterInitializer> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketParameterInitializer";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketValue";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicket> = L"Windows.Graphics.Printing.PrintTicket.WorkflowPrintTicket";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicketValidationResult> = L"Windows.Graphics.Printing.PrintTicket.WorkflowPrintTicketValidationResult";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeatureSelectionType> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketFeatureSelectionType";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDataType> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketParameterDataType";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::PrintTicketValueType> = L"Windows.Graphics.Printing.PrintTicket.PrintTicketValueType";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities> = L"Windows.Graphics.Printing.PrintTicket.IPrintTicketCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature> = L"Windows.Graphics.Printing.PrintTicket.IPrintTicketFeature";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption> = L"Windows.Graphics.Printing.PrintTicket.IPrintTicketOption";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition> = L"Windows.Graphics.Printing.PrintTicket.IPrintTicketParameterDefinition";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer> = L"Windows.Graphics.Printing.PrintTicket.IPrintTicketParameterInitializer";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue> = L"Windows.Graphics.Printing.PrintTicket.IPrintTicketValue";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket> = L"Windows.Graphics.Printing.PrintTicket.IWorkflowPrintTicket";
    template <> inline constexpr auto& name_v<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult> = L"Windows.Graphics.Printing.PrintTicket.IWorkflowPrintTicketValidationResult";
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities>{ 0x8C45508B,0xBBDC,0x4256,{ 0xA1,0x42,0x2F,0xD6,0x15,0xEC,0xB4,0x16 } }; // 8C45508B-BBDC-4256-A142-2FD615ECB416
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature>{ 0xE7607D6A,0x59F5,0x4103,{ 0x88,0x58,0xB9,0x77,0x10,0x96,0x3D,0x39 } }; // E7607D6A-59F5-4103-8858-B97710963D39
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption>{ 0xB086CF90,0xB367,0x4E4B,{ 0xBD,0x48,0x9C,0x78,0xA0,0xBB,0x31,0xCE } }; // B086CF90-B367-4E4B-BD48-9C78A0BB31CE
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition>{ 0xD6BAB4E4,0x2962,0x4C01,{ 0xB7,0xF3,0x9A,0x92,0x94,0xEB,0x83,0x35 } }; // D6BAB4E4-2962-4C01-B7F3-9A9294EB8335
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer>{ 0x5E3335BB,0xA0A5,0x48B1,{ 0x9D,0x5C,0x07,0x11,0x6D,0xDC,0x59,0x7A } }; // 5E3335BB-A0A5-48B1-9D5C-07116DDC597A
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue>{ 0x66B30A32,0x244D,0x4E22,{ 0xA9,0x8B,0xBB,0x3C,0xF1,0xF2,0xDD,0x91 } }; // 66B30A32-244D-4E22-A98B-BB3CF1F2DD91
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket>{ 0x41D52285,0x35E8,0x448E,{ 0xA8,0xC5,0xE4,0xB6,0xA2,0xCF,0x82,0x6C } }; // 41D52285-35E8-448E-A8C5-E4B6A2CF826C
    template <> inline constexpr guid guid_v<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult>{ 0x0AD1F392,0xDA7B,0x4A36,{ 0xBF,0x36,0x6A,0x99,0xA6,0x2E,0x20,0x59 } }; // 0AD1F392-DA7B-4A36-BF36-6A99A62E2059
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::PrintTicketCapabilities>{ using type = llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature>{ using type = llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption>{ using type = llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDefinition>{ using type = llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterInitializer>{ using type = llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue>{ using type = llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicket>{ using type = llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket; };
    template <> struct default_interface<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicketValidationResult>{ using type = llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult; };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNamespace(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNode(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentBindingFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentCollateFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentDuplexFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentHolePunchFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentInputBinFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentNUpFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentStapleFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_JobPasscodeFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageBorderlessFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageMediaSizeFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageMediaTypeFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageOrientationFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageOutputColorFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageOutputQualityFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageResolutionFeature(void**) noexcept = 0;
            virtual int32_t __stdcall GetFeature(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetParameterDefinition(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNamespace(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNode(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall GetOption(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_Options(void**) noexcept = 0;
            virtual int32_t __stdcall GetSelectedOption(void**) noexcept = 0;
            virtual int32_t __stdcall SetSelectedOption(void*) noexcept = 0;
            virtual int32_t __stdcall get_SelectionType(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNamespace(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNode(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall GetPropertyNode(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetScoredPropertyNode(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetPropertyValue(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetScoredPropertyValue(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNamespace(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNode(void**) noexcept = 0;
            virtual int32_t __stdcall get_DataType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_UnitType(void**) noexcept = 0;
            virtual int32_t __stdcall get_RangeMin(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_RangeMax(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNamespace(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNode(void**) noexcept = 0;
            virtual int32_t __stdcall put_Value(void*) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetValueAsInteger(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetValueAsString(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNamespace(void**) noexcept = 0;
            virtual int32_t __stdcall get_XmlNode(void**) noexcept = 0;
            virtual int32_t __stdcall GetCapabilities(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentBindingFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentCollateFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentDuplexFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentHolePunchFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentInputBinFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentNUpFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_DocumentStapleFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_JobPasscodeFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageBorderlessFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageMediaSizeFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageMediaTypeFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageOrientationFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageOutputColorFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageOutputQualityFeature(void**) noexcept = 0;
            virtual int32_t __stdcall get_PageResolutionFeature(void**) noexcept = 0;
            virtual int32_t __stdcall GetFeature(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall NotifyXmlChangedAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ValidateAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetParameterInitializer(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetParameterInitializerAsInteger(void*, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SetParameterInitializerAsString(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall MergeAndValidateTicket(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Validated(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) XmlNamespace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) XmlNode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentBindingFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentCollateFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentDuplexFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentHolePunchFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentInputBinFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentNUpFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentStapleFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) JobPasscodeFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageBorderlessFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageMediaSizeFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageMediaTypeFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageOrientationFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageOutputColorFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageOutputQualityFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageResolutionFeature() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) GetFeature(param::hstring const& name, param::hstring const& xmlNamespace) const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDefinition) GetParameterDefinition(param::hstring const& name, param::hstring const& xmlNamespace) const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketFeature
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) XmlNamespace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) XmlNode() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption) GetOption(param::hstring const& name, param::hstring const& xmlNamespace) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption>) Options() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption) GetSelectedOption() const;
        LLM_IMPL_AUTO(void) SetSelectedOption(llm:OS::Graphics::Printing::PrintTicket::PrintTicketOption const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeatureSelectionType) SelectionType() const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketFeature<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketOption
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) XmlNamespace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) XmlNode() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) GetPropertyNode(param::hstring const& name, param::hstring const& xmlNamespace) const;
        LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) GetScoredPropertyNode(param::hstring const& name, param::hstring const& xmlNamespace) const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue) GetPropertyValue(param::hstring const& name, param::hstring const& xmlNamespace) const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue) GetScoredPropertyValue(param::hstring const& name, param::hstring const& xmlNamespace) const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketOption<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketParameterDefinition
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) XmlNamespace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) XmlNode() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterDataType) DataType() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UnitType() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) RangeMin() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) RangeMax() const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketParameterDefinition<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketParameterInitializer
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) XmlNamespace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) XmlNode() const;
        LLM_IMPL_AUTO(void) Value(llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketValue) Value() const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketParameterInitializer<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketValue
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketValueType) Type() const;
        LLM_IMPL_AUTO(int32_t) GetValueAsInteger() const;
        LLM_IMPL_AUTO(hstring) GetValueAsString() const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IPrintTicketValue<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IWorkflowPrintTicket
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) XmlNamespace() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Data::Xml::Dom::IXmlNode) XmlNode() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketCapabilities) GetCapabilities() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentBindingFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentCollateFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentDuplexFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentHolePunchFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentInputBinFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentNUpFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) DocumentStapleFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) JobPasscodeFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageBorderlessFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageMediaSizeFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageMediaTypeFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageOrientationFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageOutputColorFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageOutputQualityFeature() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) PageResolutionFeature() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketFeature) GetFeature(param::hstring const& name, param::hstring const& xmlNamespace) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) NotifyXmlChangedAsync() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicketValidationResult>) ValidateAsync() const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterInitializer) GetParameterInitializer(param::hstring const& name, param::hstring const& xmlNamespace) const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterInitializer) SetParameterInitializerAsInteger(param::hstring const& name, param::hstring const& xmlNamespace, int32_t integerValue) const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::PrintTicketParameterInitializer) SetParameterInitializerAsString(param::hstring const& name, param::hstring const& xmlNamespace, param::hstring const& stringValue) const;
        LLM_IMPL_AUTO(llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicket) MergeAndValidateTicket(llm:OS::Graphics::Printing::PrintTicket::WorkflowPrintTicket const& deltaShemaTicket) const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IWorkflowPrintTicket<D>;
    };
    template <typename D>
    struct consume_Windows_Graphics_Printing_PrintTicket_IWorkflowPrintTicketValidationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Validated() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult>
    {
        template <typename D> using type = consume_Windows_Graphics_Printing_PrintTicket_IWorkflowPrintTicketValidationResult<D>;
    };
}
#endif
