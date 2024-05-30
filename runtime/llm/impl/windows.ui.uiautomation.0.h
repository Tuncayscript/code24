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
#ifndef LLM_OS_UI_UIAutomation_0_H
#define LLM_OS_UI_UIAutomation_0_H
LLM_EXPORT namespace llm:OS::UI::UIAutomation
{
    struct IAutomationConnection;
    struct IAutomationConnectionBoundObject;
    struct IAutomationElement;
    struct IAutomationTextRange;
    struct AutomationConnection;
    struct AutomationConnectionBoundObject;
    struct AutomationElement;
    struct AutomationTextRange;
}
namespace llm::impl
{
    template <> struct category<llm:OS::UI::UIAutomation::IAutomationConnection>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::UIAutomation::IAutomationElement>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::UIAutomation::IAutomationTextRange>{ using type = interface_category; };
    template <> struct category<llm:OS::UI::UIAutomation::AutomationConnection>{ using type = class_category; };
    template <> struct category<llm:OS::UI::UIAutomation::AutomationConnectionBoundObject>{ using type = class_category; };
    template <> struct category<llm:OS::UI::UIAutomation::AutomationElement>{ using type = class_category; };
    template <> struct category<llm:OS::UI::UIAutomation::AutomationTextRange>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::AutomationConnection> = L"Windows.UI.UIAutomation.AutomationConnection";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::AutomationConnectionBoundObject> = L"Windows.UI.UIAutomation.AutomationConnectionBoundObject";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::AutomationElement> = L"Windows.UI.UIAutomation.AutomationElement";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::AutomationTextRange> = L"Windows.UI.UIAutomation.AutomationTextRange";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::IAutomationConnection> = L"Windows.UI.UIAutomation.IAutomationConnection";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject> = L"Windows.UI.UIAutomation.IAutomationConnectionBoundObject";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::IAutomationElement> = L"Windows.UI.UIAutomation.IAutomationElement";
    template <> inline constexpr auto& name_v<llm:OS::UI::UIAutomation::IAutomationTextRange> = L"Windows.UI.UIAutomation.IAutomationTextRange";
    template <> inline constexpr guid guid_v<llm:OS::UI::UIAutomation::IAutomationConnection>{ 0xAAD262ED,0x0EF4,0x5D43,{ 0x97,0xBE,0xA8,0x34,0xE2,0x7B,0x65,0xB9 } }; // AAD262ED-0EF4-5D43-97BE-A834E27B65B9
    template <> inline constexpr guid guid_v<llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject>{ 0x5E8558FB,0xCA52,0x5B65,{ 0x98,0x30,0xDD,0x29,0x05,0x81,0x60,0x93 } }; // 5E8558FB-CA52-5B65-9830-DD2905816093
    template <> inline constexpr guid guid_v<llm:OS::UI::UIAutomation::IAutomationElement>{ 0xA1898370,0x2C07,0x56FD,{ 0x99,0x3F,0x61,0xA7,0x2A,0x08,0x05,0x8C } }; // A1898370-2C07-56FD-993F-61A72A08058C
    template <> inline constexpr guid guid_v<llm:OS::UI::UIAutomation::IAutomationTextRange>{ 0x7E101B65,0x40D3,0x5994,{ 0x85,0xA9,0x0A,0x0C,0xB9,0xA4,0xEC,0x98 } }; // 7E101B65-40D3-5994-85A9-0A0CB9A4EC98
    template <> struct default_interface<llm:OS::UI::UIAutomation::AutomationConnection>{ using type = llm:OS::UI::UIAutomation::IAutomationConnection; };
    template <> struct default_interface<llm:OS::UI::UIAutomation::AutomationConnectionBoundObject>{ using type = llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject; };
    template <> struct default_interface<llm:OS::UI::UIAutomation::AutomationElement>{ using type = llm:OS::UI::UIAutomation::IAutomationElement; };
    template <> struct default_interface<llm:OS::UI::UIAutomation::AutomationTextRange>{ using type = llm:OS::UI::UIAutomation::IAutomationTextRange; };
    template <> struct abi<llm:OS::UI::UIAutomation::IAutomationConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsRemoteSystem(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AppUserModelId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExecutableFileName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Connection(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::UIAutomation::IAutomationElement>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsRemoteSystem(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AppUserModelId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ExecutableFileName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::UI::UIAutomation::IAutomationTextRange>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <typename D>
    struct consume_Windows_UI_UIAutomation_IAutomationConnection
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRemoteSystem() const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppUserModelId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ExecutableFileName() const;
    };
    template <> struct consume<llm:OS::UI::UIAutomation::IAutomationConnection>
    {
        template <typename D> using type = consume_Windows_UI_UIAutomation_IAutomationConnection<D>;
    };
    template <typename D>
    struct consume_Windows_UI_UIAutomation_IAutomationConnectionBoundObject
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::UI::UIAutomation::AutomationConnection) Connection() const;
    };
    template <> struct consume<llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject>
    {
        template <typename D> using type = consume_Windows_UI_UIAutomation_IAutomationConnectionBoundObject<D>;
    };
    template <typename D>
    struct consume_Windows_UI_UIAutomation_IAutomationElement
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRemoteSystem() const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppUserModelId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ExecutableFileName() const;
    };
    template <> struct consume<llm:OS::UI::UIAutomation::IAutomationElement>
    {
        template <typename D> using type = consume_Windows_UI_UIAutomation_IAutomationElement<D>;
    };
    template <typename D>
    struct consume_Windows_UI_UIAutomation_IAutomationTextRange
    {
    };
    template <> struct consume<llm:OS::UI::UIAutomation::IAutomationTextRange>
    {
        template <typename D> using type = consume_Windows_UI_UIAutomation_IAutomationTextRange<D>;
    };
}
#endif
