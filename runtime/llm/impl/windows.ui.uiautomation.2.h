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
#ifndef LLM_OS_UI_UIAutomation_2_H
#define LLM_OS_UI_UIAutomation_2_H
#include "llm/impl/Windows.UI.UIAutomation.1.h"
LLM_EXPORT namespace llm:OS::UI::UIAutomation
{
    struct __declspec(empty_bases) AutomationConnection : llm:OS::UI::UIAutomation::IAutomationConnection
    {
        AutomationConnection(std::nullptr_t) noexcept {}
        AutomationConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::IAutomationConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AutomationConnectionBoundObject : llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject
    {
        AutomationConnectionBoundObject(std::nullptr_t) noexcept {}
        AutomationConnectionBoundObject(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::IAutomationConnectionBoundObject(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AutomationElement : llm:OS::UI::UIAutomation::IAutomationElement
    {
        AutomationElement(std::nullptr_t) noexcept {}
        AutomationElement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::IAutomationElement(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AutomationTextRange : llm:OS::UI::UIAutomation::IAutomationTextRange
    {
        AutomationTextRange(std::nullptr_t) noexcept {}
        AutomationTextRange(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::UI::UIAutomation::IAutomationTextRange(ptr, take_ownership_from_abi) {}
    };
}
#endif
