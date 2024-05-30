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
#ifndef LLM_OS_Graphics_Printing_PrintTicket_2_H
#define LLM_OS_Graphics_Printing_PrintTicket_2_H
#include "llm/impl/Windows.Graphics.Printing.PrintTicket.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::PrintTicket
{
    struct __declspec(empty_bases) PrintTicketCapabilities : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities
    {
        PrintTicketCapabilities(std::nullptr_t) noexcept {}
        PrintTicketCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTicketFeature : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature
    {
        PrintTicketFeature(std::nullptr_t) noexcept {}
        PrintTicketFeature(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketFeature(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTicketOption : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption
    {
        PrintTicketOption(std::nullptr_t) noexcept {}
        PrintTicketOption(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketOption(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTicketParameterDefinition : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition
    {
        PrintTicketParameterDefinition(std::nullptr_t) noexcept {}
        PrintTicketParameterDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterDefinition(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTicketParameterInitializer : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer
    {
        PrintTicketParameterInitializer(std::nullptr_t) noexcept {}
        PrintTicketParameterInitializer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketParameterInitializer(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTicketValue : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue
    {
        PrintTicketValue(std::nullptr_t) noexcept {}
        PrintTicketValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IPrintTicketValue(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WorkflowPrintTicket : llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket
    {
        WorkflowPrintTicket(std::nullptr_t) noexcept {}
        WorkflowPrintTicket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicket(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WorkflowPrintTicketValidationResult : llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult
    {
        WorkflowPrintTicketValidationResult(std::nullptr_t) noexcept {}
        WorkflowPrintTicketValidationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintTicket::IWorkflowPrintTicketValidationResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
