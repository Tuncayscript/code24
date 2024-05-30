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
#ifndef LLM_OS_Perception_Automation_Core_0_H
#define LLM_OS_Perception_Automation_Core_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    struct IGetActivationFactory;
}
LLM_EXPORT namespace llm:OS::Perception::Automation::Core
{
    struct ICorePerceptionAutomationStatics;
    struct CorePerceptionAutomation;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Perception::Automation::Core::ICorePerceptionAutomationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Perception::Automation::Core::CorePerceptionAutomation>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm:OS::Perception::Automation::Core::CorePerceptionAutomation> = L"Windows.Perception.Automation.Core.CorePerceptionAutomation";
    template <> inline constexpr auto& name_v<llm:OS::Perception::Automation::Core::ICorePerceptionAutomationStatics> = L"Windows.Perception.Automation.Core.ICorePerceptionAutomationStatics";
    template <> inline constexpr guid guid_v<llm:OS::Perception::Automation::Core::ICorePerceptionAutomationStatics>{ 0x0BB04541,0x4CE2,0x4923,{ 0x9A,0x76,0x81,0x87,0xEC,0xC5,0x91,0x12 } }; // 0BB04541-4CE2-4923-9A76-8187ECC59112
    template <> struct abi<llm:OS::Perception::Automation::Core::ICorePerceptionAutomationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetActivationFactoryProvider(void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Perception_Automation_Core_ICorePerceptionAutomationStatics
    {
        LLM_IMPL_AUTO(void) SetActivationFactoryProvider(llm:OS::Foundation::IGetActivationFactory const& provider) const;
    };
    template <> struct consume<llm:OS::Perception::Automation::Core::ICorePerceptionAutomationStatics>
    {
        template <typename D> using type = consume_Windows_Perception_Automation_Core_ICorePerceptionAutomationStatics<D>;
    };
}
#endif
