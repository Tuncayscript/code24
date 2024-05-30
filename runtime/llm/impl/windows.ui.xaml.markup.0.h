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
#ifndef LLM_OS_UI_Xaml_Markup_0_H
#define LLM_OS_UI_Xaml_Markup_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Point;
    struct Rect;
    struct Size;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStream;
}
LLM_EXPORT namespace llm::OS::UI::Xaml
{
    struct DependencyObject;
    struct DependencyProperty;
    struct UIElement;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Interop
{
    struct TypeName;
}
LLM_EXPORT namespace llm::OS::UI::Xaml::Markup
{
    struct IComponentConnector;
    struct IComponentConnector2;
    struct IDataTemplateComponent;
    struct IMarkupExtension;
    struct IMarkupExtensionFactory;
    struct IMarkupExtensionOverrides;
    struct IXamlBinaryWriter;
    struct IXamlBinaryWriterStatics;
    struct IXamlBindScopeDiagnostics;
    struct IXamlBindingHelper;
    struct IXamlBindingHelperStatics;
    struct IXamlMarkupHelper;
    struct IXamlMarkupHelperStatics;
    struct IXamlMember;
    struct IXamlMetadataProvider;
    struct IXamlReader;
    struct IXamlReaderStatics;
    struct IXamlType;
    struct IXamlType2;
    struct MarkupExtension;
    struct XamlBinaryWriter;
    struct XamlBindingHelper;
    struct XamlMarkupHelper;
    struct XamlReader;
    struct XamlBinaryWriterErrorInformation;
    struct XmlnsDefinition;
}
namespace llm::impl
{
    template <> struct category<llm::OS::UI::Xaml::Markup::IComponentConnector>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IComponentConnector2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IDataTemplateComponent>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IMarkupExtension>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlBinaryWriter>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlBindingHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlMarkupHelper>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlMember>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlReader>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlReaderStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlType>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::IXamlType2>{ using type = interface_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::MarkupExtension>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::XamlBinaryWriter>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::XamlBindingHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::XamlMarkupHelper>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::XamlReader>{ using type = class_category; };
    template <> struct category<llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation>{ using type = struct_category<uint32_t, uint32_t, uint32_t>; };
    template <> struct category<llm::OS::UI::Xaml::Markup::XmlnsDefinition>{ using type = struct_category<hstring, hstring>; };
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::MarkupExtension> = L"Windows.UI.Xaml.Markup.MarkupExtension";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::XamlBinaryWriter> = L"Windows.UI.Xaml.Markup.XamlBinaryWriter";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::XamlBindingHelper> = L"Windows.UI.Xaml.Markup.XamlBindingHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::XamlMarkupHelper> = L"Windows.UI.Xaml.Markup.XamlMarkupHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::XamlReader> = L"Windows.UI.Xaml.Markup.XamlReader";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation> = L"Windows.UI.Xaml.Markup.XamlBinaryWriterErrorInformation";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::XmlnsDefinition> = L"Windows.UI.Xaml.Markup.XmlnsDefinition";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IComponentConnector> = L"Windows.UI.Xaml.Markup.IComponentConnector";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IComponentConnector2> = L"Windows.UI.Xaml.Markup.IComponentConnector2";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IDataTemplateComponent> = L"Windows.UI.Xaml.Markup.IDataTemplateComponent";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IMarkupExtension> = L"Windows.UI.Xaml.Markup.IMarkupExtension";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory> = L"Windows.UI.Xaml.Markup.IMarkupExtensionFactory";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides> = L"Windows.UI.Xaml.Markup.IMarkupExtensionOverrides";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlBinaryWriter> = L"Windows.UI.Xaml.Markup.IXamlBinaryWriter";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics> = L"Windows.UI.Xaml.Markup.IXamlBinaryWriterStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics> = L"Windows.UI.Xaml.Markup.IXamlBindScopeDiagnostics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlBindingHelper> = L"Windows.UI.Xaml.Markup.IXamlBindingHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics> = L"Windows.UI.Xaml.Markup.IXamlBindingHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlMarkupHelper> = L"Windows.UI.Xaml.Markup.IXamlMarkupHelper";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics> = L"Windows.UI.Xaml.Markup.IXamlMarkupHelperStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlMember> = L"Windows.UI.Xaml.Markup.IXamlMember";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider> = L"Windows.UI.Xaml.Markup.IXamlMetadataProvider";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlReader> = L"Windows.UI.Xaml.Markup.IXamlReader";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlReaderStatics> = L"Windows.UI.Xaml.Markup.IXamlReaderStatics";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlType> = L"Windows.UI.Xaml.Markup.IXamlType";
    template <> inline constexpr auto& name_v<llm::OS::UI::Xaml::Markup::IXamlType2> = L"Windows.UI.Xaml.Markup.IXamlType2";
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IComponentConnector>{ 0xF6790987,0xE6E5,0x47F2,{ 0x92,0xC6,0xEC,0xCC,0xE4,0xBA,0x15,0x9A } }; // F6790987-E6E5-47F2-92C6-ECCCE4BA159A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IComponentConnector2>{ 0xDC8F368B,0xECCC,0x498E,{ 0xB1,0x39,0x91,0x14,0x22,0x54,0xD7,0xAE } }; // DC8F368B-ECCC-498E-B139-91142254D7AE
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IDataTemplateComponent>{ 0x08429DC8,0x8AB0,0x4747,{ 0xAA,0x9A,0xFE,0xAD,0xFC,0x8D,0xA8,0xE1 } }; // 08429DC8-8AB0-4747-AA9A-FEADFC8DA8E1
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IMarkupExtension>{ 0x1EE3416D,0x562B,0x486E,{ 0x9E,0xE5,0x0F,0x0C,0xBC,0xC8,0x04,0x8C } }; // 1EE3416D-562B-486E-9EE5-0F0CBCC8048C
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory>{ 0x65329C05,0xFB5A,0x4567,{ 0x9D,0x55,0x5C,0xDF,0xBA,0xDA,0x27,0x39 } }; // 65329C05-FB5A-4567-9D55-5CDFBADA2739
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>{ 0x393779BF,0xB9C0,0x4FFB,{ 0xA5,0x7F,0x58,0xE7,0x35,0x6E,0x42,0x5F } }; // 393779BF-B9C0-4FFB-A57F-58E7356E425F
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlBinaryWriter>{ 0x829D2AD3,0x620A,0x46F6,{ 0x84,0x5D,0x43,0x6A,0x05,0x92,0x71,0x00 } }; // 829D2AD3-620A-46F6-845D-436A05927100
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics>{ 0x0D8ED07A,0x9B82,0x4AA8,{ 0xB6,0x8B,0x02,0x6F,0x2D,0xE1,0xCC,0x86 } }; // 0D8ED07A-9B82-4AA8-B68B-026F2DE1CC86
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics>{ 0xF264A29D,0xBDED,0x43AA,{ 0xA5,0xB0,0x26,0xAC,0x21,0xA8,0x1E,0xB8 } }; // F264A29D-BDED-43AA-A5B0-26AC21A81EB8
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlBindingHelper>{ 0xFAA6FB06,0x8AB9,0x4EF7,{ 0x8A,0xE7,0xFB,0xD3,0x0B,0xBF,0xD0,0x6D } }; // FAA6FB06-8AB9-4EF7-8AE7-FBD30BBFD06D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics>{ 0xF65CFB71,0xC80C,0x4FFA,{ 0x86,0xEE,0x55,0x87,0x54,0xEE,0x33,0x6D } }; // F65CFB71-C80C-4FFA-86EE-558754EE336D
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlMarkupHelper>{ 0xD0E6673C,0x5342,0x44EF,{ 0x85,0xA7,0xED,0x32,0x7A,0x73,0x9D,0x9A } }; // D0E6673C-5342-44EF-85A7-ED327A739D9A
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics>{ 0xC9BC3725,0xF34F,0x445C,{ 0x81,0xA2,0x6B,0x72,0xA5,0xE8,0xF0,0x72 } }; // C9BC3725-F34F-445C-81A2-6B72A5E8F072
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlMember>{ 0xC541F58C,0x43A9,0x4216,{ 0xB7,0x18,0xE0,0xB1,0x1B,0x14,0xE9,0x3E } }; // C541F58C-43A9-4216-B718-E0B11B14E93E
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider>{ 0xB3765D69,0x68A5,0x4B32,{ 0x88,0x61,0xFD,0xB9,0x0C,0x1F,0x58,0x36 } }; // B3765D69-68A5-4B32-8861-FDB90C1F5836
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlReader>{ 0x24374CF1,0xCCEB,0x48BF,{ 0xA5,0x14,0x41,0xB0,0x18,0x6F,0x84,0xC2 } }; // 24374CF1-CCEB-48BF-A514-41B0186F84C2
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlReaderStatics>{ 0x9891C6BD,0x534F,0x4955,{ 0xB8,0x5A,0x8A,0x8D,0xC0,0xDC,0xA6,0x02 } }; // 9891C6BD-534F-4955-B85A-8A8DC0DCA602
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlType>{ 0x7920EAB1,0xA2E5,0x479A,{ 0xBD,0x50,0x6C,0xEF,0x3C,0x0B,0x49,0x70 } }; // 7920EAB1-A2E5-479A-BD50-6CEF3C0B4970
    template <> inline constexpr guid guid_v<llm::OS::UI::Xaml::Markup::IXamlType2>{ 0x9F0C6E3B,0x433B,0x56AD,{ 0x8F,0x69,0x78,0xA4,0xDD,0x3E,0x64,0xF9 } }; // 9F0C6E3B-433B-56AD-8F69-78A4DD3E64F9
    template <> struct default_interface<llm::OS::UI::Xaml::Markup::MarkupExtension>{ using type = llm::OS::UI::Xaml::Markup::IMarkupExtension; };
    template <> struct default_interface<llm::OS::UI::Xaml::Markup::XamlBinaryWriter>{ using type = llm::OS::UI::Xaml::Markup::IXamlBinaryWriter; };
    template <> struct default_interface<llm::OS::UI::Xaml::Markup::XamlBindingHelper>{ using type = llm::OS::UI::Xaml::Markup::IXamlBindingHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::Markup::XamlMarkupHelper>{ using type = llm::OS::UI::Xaml::Markup::IXamlMarkupHelper; };
    template <> struct default_interface<llm::OS::UI::Xaml::Markup::XamlReader>{ using type = llm::OS::UI::Xaml::Markup::IXamlReader; };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IComponentConnector>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Connect(int32_t, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IComponentConnector2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetBindingConnector(int32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IDataTemplateComponent>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Recycle() noexcept = 0;
            virtual int32_t __stdcall ProcessBindings(void*, int32_t, int32_t, int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IMarkupExtension>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstance(void*, void**, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ProvideValue(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlBinaryWriter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Write(void*, void*, void*, struct struct_Windows_UI_Xaml_Markup_XamlBinaryWriterErrorInformation*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Disable(int32_t, int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlBindingHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DataTemplateComponentProperty(void**) noexcept = 0;
            virtual int32_t __stdcall GetDataTemplateComponent(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetDataTemplateComponent(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SuspendRendering(void*) noexcept = 0;
            virtual int32_t __stdcall ResumeRendering(void*) noexcept = 0;
            virtual int32_t __stdcall ConvertValue(struct struct_Windows_UI_Xaml_Interop_TypeName, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromString(void*, void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromBoolean(void*, void*, bool) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromChar16(void*, void*, char16_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromDateTime(void*, void*, int64_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromDouble(void*, void*, double) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromInt32(void*, void*, int32_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromUInt32(void*, void*, uint32_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromInt64(void*, void*, int64_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromUInt64(void*, void*, uint64_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromSingle(void*, void*, float) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromPoint(void*, void*, llm::OS::Foundation::Point) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromRect(void*, void*, llm::OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromSize(void*, void*, llm::OS::Foundation::Size) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromTimeSpan(void*, void*, int64_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromByte(void*, void*, uint8_t) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromUri(void*, void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetPropertyFromObject(void*, void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlMarkupHelper>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall UnloadObject(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlMember>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsAttachable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDependencyProperty(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsReadOnly(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_TargetType(void**) noexcept = 0;
            virtual int32_t __stdcall get_Type(void**) noexcept = 0;
            virtual int32_t __stdcall GetValue(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetValue(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetXamlType(struct struct_Windows_UI_Xaml_Interop_TypeName, void**) noexcept = 0;
            virtual int32_t __stdcall GetXamlTypeByFullName(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetXmlnsDefinitions(uint32_t* __resultSize, struct struct_Windows_UI_Xaml_Markup_XmlnsDefinition**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlReader>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlReaderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Load(void*, void**) noexcept = 0;
            virtual int32_t __stdcall LoadWithInitialTemplateValidation(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlType>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BaseType(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContentProperty(void**) noexcept = 0;
            virtual int32_t __stdcall get_FullName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsArray(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsCollection(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsConstructible(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsDictionary(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsMarkupExtension(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsBindable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ItemType(void**) noexcept = 0;
            virtual int32_t __stdcall get_KeyType(void**) noexcept = 0;
            virtual int32_t __stdcall get_UnderlyingType(struct struct_Windows_UI_Xaml_Interop_TypeName*) noexcept = 0;
            virtual int32_t __stdcall ActivateInstance(void**) noexcept = 0;
            virtual int32_t __stdcall CreateFromString(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetMember(void*, void**) noexcept = 0;
            virtual int32_t __stdcall AddToVector(void*, void*) noexcept = 0;
            virtual int32_t __stdcall AddToMap(void*, void*, void*) noexcept = 0;
            virtual int32_t __stdcall RunInitializer() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::UI::Xaml::Markup::IXamlType2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BoxedType(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IComponentConnector
    {
        WINRT_IMPL_AUTO(void) Connect(int32_t connectionId, llm::OS::Foundation::IInspectable const& target) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IComponentConnector>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IComponentConnector<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IComponentConnector2
    {
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IComponentConnector) GetBindingConnector(int32_t connectionId, llm::OS::Foundation::IInspectable const& target) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IComponentConnector2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IComponentConnector2<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IDataTemplateComponent
    {
        WINRT_IMPL_AUTO(void) Recycle() const;
        WINRT_IMPL_AUTO(void) ProcessBindings(llm::OS::Foundation::IInspectable const& item, int32_t itemIndex, int32_t phase, int32_t& nextPhase) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IDataTemplateComponent>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IDataTemplateComponent<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IMarkupExtension
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IMarkupExtension>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IMarkupExtension<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IMarkupExtensionFactory
    {
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::MarkupExtension) CreateInstance(llm::OS::Foundation::IInspectable const& baseInterface, llm::OS::Foundation::IInspectable& innerInterface) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IMarkupExtensionFactory>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IMarkupExtensionFactory<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IMarkupExtensionOverrides
    {
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) ProvideValue() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IMarkupExtensionOverrides>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IMarkupExtensionOverrides<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlBinaryWriter
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlBinaryWriter>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlBinaryWriter<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlBinaryWriterStatics
    {
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::XamlBinaryWriterErrorInformation) Write(param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& inputStreams, param::vector<llm::OS::Storage::Streams::IRandomAccessStream> const& outputStreams, llm::OS::UI::Xaml::Markup::IXamlMetadataProvider const& xamlMetadataProvider) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlBinaryWriterStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlBinaryWriterStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlBindScopeDiagnostics
    {
        WINRT_IMPL_AUTO(void) Disable(int32_t lineNumber, int32_t columnNumber) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlBindScopeDiagnostics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlBindScopeDiagnostics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlBindingHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlBindingHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlBindingHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::DependencyProperty) DataTemplateComponentProperty() const;
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IDataTemplateComponent) GetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element) const;
        WINRT_IMPL_AUTO(void) SetDataTemplateComponent(llm::OS::UI::Xaml::DependencyObject const& element, llm::OS::UI::Xaml::Markup::IDataTemplateComponent const& value) const;
        WINRT_IMPL_AUTO(void) SuspendRendering(llm::OS::UI::Xaml::UIElement const& target) const;
        WINRT_IMPL_AUTO(void) ResumeRendering(llm::OS::UI::Xaml::UIElement const& target) const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) ConvertValue(llm::OS::UI::Xaml::Interop::TypeName const& type, llm::OS::Foundation::IInspectable const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromString(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, param::hstring const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromBoolean(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, bool value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromChar16(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, char16_t value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromDateTime(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::DateTime const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromDouble(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, double value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int32_t value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromUInt32(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint32_t value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, int64_t value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromUInt64(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint64_t value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromSingle(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, float value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromPoint(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Point const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromRect(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Rect const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromSize(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Size const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromTimeSpan(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::TimeSpan const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromByte(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, uint8_t value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromUri(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::Uri const& value) const;
        WINRT_IMPL_AUTO(void) SetPropertyFromObject(llm::OS::Foundation::IInspectable const& dependencyObject, llm::OS::UI::Xaml::DependencyProperty const& propertyToSet, llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlBindingHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlBindingHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlMarkupHelper
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlMarkupHelper>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlMarkupHelper<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlMarkupHelperStatics
    {
        WINRT_IMPL_AUTO(void) UnloadObject(llm::OS::UI::Xaml::DependencyObject const& element) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlMarkupHelperStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlMarkupHelperStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlMember
    {
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsAttachable() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsDependencyProperty() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsReadOnly() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) TargetType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) Type() const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) GetValue(llm::OS::Foundation::IInspectable const& instance) const;
        WINRT_IMPL_AUTO(void) SetValue(llm::OS::Foundation::IInspectable const& instance, llm::OS::Foundation::IInspectable const& value) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlMember>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlMember<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlMetadataProvider
    {
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) GetXamlType(llm::OS::UI::Xaml::Interop::TypeName const& type) const;
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) GetXamlType(param::hstring const& fullName) const;
        WINRT_IMPL_AUTO(com_array<llm::OS::UI::Xaml::Markup::XmlnsDefinition>) GetXmlnsDefinitions() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlMetadataProvider>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlMetadataProvider<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlReader
    {
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlReader>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlReader<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlReaderStatics
    {
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) Load(param::hstring const& xaml) const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) LoadWithInitialTemplateValidation(param::hstring const& xaml) const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlReaderStatics>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlReaderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlType
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) BaseType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlMember) ContentProperty() const;
        [[nodiscard]] WINRT_IMPL_AUTO(hstring) FullName() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsArray() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsCollection() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsConstructible() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsDictionary() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsMarkupExtension() const;
        [[nodiscard]] WINRT_IMPL_AUTO(bool) IsBindable() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) ItemType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) KeyType() const;
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Interop::TypeName) UnderlyingType() const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) ActivateInstance() const;
        WINRT_IMPL_AUTO(llm::OS::Foundation::IInspectable) CreateFromString(param::hstring const& value) const;
        WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlMember) GetMember(param::hstring const& name) const;
        WINRT_IMPL_AUTO(void) AddToVector(llm::OS::Foundation::IInspectable const& instance, llm::OS::Foundation::IInspectable const& value) const;
        WINRT_IMPL_AUTO(void) AddToMap(llm::OS::Foundation::IInspectable const& instance, llm::OS::Foundation::IInspectable const& key, llm::OS::Foundation::IInspectable const& value) const;
        WINRT_IMPL_AUTO(void) RunInitializer() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlType>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlType<D>;
    };
    template <typename D>
    struct consume_Windows_UI_Xaml_Markup_IXamlType2
    {
        [[nodiscard]] WINRT_IMPL_AUTO(llm::OS::UI::Xaml::Markup::IXamlType) BoxedType() const;
    };
    template <> struct consume<llm::OS::UI::Xaml::Markup::IXamlType2>
    {
        template <typename D> using type = consume_Windows_UI_Xaml_Markup_IXamlType2<D>;
    };
    struct struct_Windows_UI_Xaml_Markup_XamlBinaryWriterErrorInformation
    {
        uint32_t InputStreamIndex;
        uint32_t LineNumber;
        uint32_t LinePosition;
    };
    template <> struct abi<Windows::UI::Xaml::Markup::XamlBinaryWriterErrorInformation>
    {
        using type = struct_Windows_UI_Xaml_Markup_XamlBinaryWriterErrorInformation;
    };
    struct struct_Windows_UI_Xaml_Markup_XmlnsDefinition
    {
        void* XmlNamespace;
        void* Namespace;
    };
    template <> struct abi<Windows::UI::Xaml::Markup::XmlnsDefinition>
    {
        using type = struct_Windows_UI_Xaml_Markup_XmlnsDefinition;
    };
}
#endif