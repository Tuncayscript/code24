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
#ifndef LLM_OS_Foundation_Metadata_0_H
#define LLM_OS_Foundation_Metadata_0_H
LLM_EXPORT namespace llm::OS::Foundation::Metadata
{
    enum class AttributeTargets : uint32_t
    {
        All = 0xffffffff,
        Delegate = 0x1,
        Enum = 0x2,
        Event = 0x4,
        Field = 0x8,
        Interface = 0x10,
        Method = 0x40,
        Parameter = 0x80,
        Property = 0x100,
        RuntimeClass = 0x200,
        Struct = 0x400,
        InterfaceImpl = 0x800,
        ApiContract = 0x2000,
    };
    enum class CompositionType : int32_t
    {
        Protected = 1,
        Public = 2,
    };
    enum class DeprecationType : int32_t
    {
        Deprecate = 0,
        Remove = 1,
    };
    enum class FeatureStage : int32_t
    {
        AlwaysDisabled = 0,
        DisabledByDefault = 1,
        EnabledByDefault = 2,
        AlwaysEnabled = 3,
    };
    enum class GCPressureAmount : int32_t
    {
        Low = 0,
        Medium = 1,
        High = 2,
    };
    enum class MarshalingType : int32_t
    {
        None = 1,
        Agile = 2,
        Standard = 3,
        InvalidMarshaling = 0,
    };
    enum class Platform : int32_t
    {
        Windows = 0,
        WindowsPhone = 1,
    };
    enum class ThreadingModel : int32_t
    {
        STA = 1,
        MTA = 2,
        Both = 3,
        InvalidThreading = 0,
    };
    struct IApiInformationStatics;
    struct ApiInformation;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Foundation::Metadata::IApiInformationStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Foundation::Metadata::ApiInformation>{ using type = class_category; };
    template <> struct category<llm::OS::Foundation::Metadata::AttributeTargets>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::CompositionType>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::DeprecationType>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::FeatureStage>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::GCPressureAmount>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::MarshalingType>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::Platform>{ using type = enum_category; };
    template <> struct category<llm::OS::Foundation::Metadata::ThreadingModel>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::ApiInformation> = L"Windows.Foundation.Metadata.ApiInformation";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::AttributeTargets> = L"Windows.Foundation.Metadata.AttributeTargets";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::CompositionType> = L"Windows.Foundation.Metadata.CompositionType";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::DeprecationType> = L"Windows.Foundation.Metadata.DeprecationType";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::FeatureStage> = L"Windows.Foundation.Metadata.FeatureStage";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::GCPressureAmount> = L"Windows.Foundation.Metadata.GCPressureAmount";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::MarshalingType> = L"Windows.Foundation.Metadata.MarshalingType";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::Platform> = L"Windows.Foundation.Metadata.Platform";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::ThreadingModel> = L"Windows.Foundation.Metadata.ThreadingModel";
    template <> inline constexpr auto& name_v<llm::OS::Foundation::Metadata::IApiInformationStatics> = L"Windows.Foundation.Metadata.IApiInformationStatics";
    template <> inline constexpr guid guid_v<llm::OS::Foundation::Metadata::IApiInformationStatics>{ 0x997439FE,0xF681,0x4A11,{ 0xB4,0x16,0xC1,0x3A,0x47,0xE8,0xBA,0x36 } }; // 997439FE-F681-4A11-B416-C13A47E8BA36
    template <> struct abi<llm::OS::Foundation::Metadata::IApiInformationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsTypePresent(void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsMethodPresent(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsMethodPresentWithArity(void*, void*, uint32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall IsEventPresent(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsPropertyPresent(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsReadOnlyPropertyPresent(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsWriteablePropertyPresent(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsEnumNamedValuePresent(void*, void*, bool*) noexcept = 0;
            virtual int32_t __stdcall IsApiContractPresentByMajor(void*, uint16_t, bool*) noexcept = 0;
            virtual int32_t __stdcall IsApiContractPresentByMajorAndMinor(void*, uint16_t, uint16_t, bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Foundation_Metadata_IApiInformationStatics
    {
        LLM_IMPL_AUTO(bool) IsTypePresent(param::hstring const& typeName) const;
        LLM_IMPL_AUTO(bool) IsMethodPresent(param::hstring const& typeName, param::hstring const& methodName) const;
        LLM_IMPL_AUTO(bool) IsMethodPresent(param::hstring const& typeName, param::hstring const& methodName, uint32_t inputParameterCount) const;
        LLM_IMPL_AUTO(bool) IsEventPresent(param::hstring const& typeName, param::hstring const& eventName) const;
        LLM_IMPL_AUTO(bool) IsPropertyPresent(param::hstring const& typeName, param::hstring const& propertyName) const;
        LLM_IMPL_AUTO(bool) IsReadOnlyPropertyPresent(param::hstring const& typeName, param::hstring const& propertyName) const;
        LLM_IMPL_AUTO(bool) IsWriteablePropertyPresent(param::hstring const& typeName, param::hstring const& propertyName) const;
        LLM_IMPL_AUTO(bool) IsEnumNamedValuePresent(param::hstring const& enumTypeName, param::hstring const& valueName) const;
        LLM_IMPL_AUTO(bool) IsApiContractPresent(param::hstring const& contractName, uint16_t majorVersion) const;
        LLM_IMPL_AUTO(bool) IsApiContractPresent(param::hstring const& contractName, uint16_t majorVersion, uint16_t minorVersion) const;
    };
    template <> struct consume<llm::OS::Foundation::Metadata::IApiInformationStatics>
    {
        template <typename D> using type = consume_Windows_Foundation_Metadata_IApiInformationStatics<D>;
    };
}
#endif
