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
#ifndef LLM_OS_Graphics_Printing_PrintTicket_1_H
#define LLM_OS_Graphics_Printing_PrintTicket_1_H
#include "llm/impl/Windows.Graphics.Printing.PrintTicket.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::PrintTicket
{
    struct __declspec(empty_bases) IPrintTicketCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTicketCapabilities>
    {
        IPrintTicketCapabilities(std::nullptr_t = nullptr) noexcept {}
        IPrintTicketCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTicketFeature :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTicketFeature>
    {
        IPrintTicketFeature(std::nullptr_t = nullptr) noexcept {}
        IPrintTicketFeature(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTicketOption :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTicketOption>
    {
        IPrintTicketOption(std::nullptr_t = nullptr) noexcept {}
        IPrintTicketOption(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTicketParameterDefinition :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTicketParameterDefinition>
    {
        IPrintTicketParameterDefinition(std::nullptr_t = nullptr) noexcept {}
        IPrintTicketParameterDefinition(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTicketParameterInitializer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTicketParameterInitializer>
    {
        IPrintTicketParameterInitializer(std::nullptr_t = nullptr) noexcept {}
        IPrintTicketParameterInitializer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTicketValue :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintTicketValue>
    {
        IPrintTicketValue(std::nullptr_t = nullptr) noexcept {}
        IPrintTicketValue(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWorkflowPrintTicket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWorkflowPrintTicket>
    {
        IWorkflowPrintTicket(std::nullptr_t = nullptr) noexcept {}
        IWorkflowPrintTicket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWorkflowPrintTicketValidationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWorkflowPrintTicketValidationResult>
    {
        IWorkflowPrintTicketValidationResult(std::nullptr_t = nullptr) noexcept {}
        IWorkflowPrintTicketValidationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
