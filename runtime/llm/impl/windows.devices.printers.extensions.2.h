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
#ifndef LLM_OS_Devices_Printers_Extensions_2_H
#define LLM_OS_Devices_Printers_Extensions_2_H
#include "llm/impl/Windows.Devices.Printers.Extensions.1.h"
LLM_EXPORT namespace llm::OS::Devices::Printers::Extensions
{
    struct __declspec(empty_bases) Print3DWorkflow : llm::OS::Devices::Printers::Extensions::IPrint3DWorkflow,
        impl::require<Print3DWorkflow, llm::OS::Devices::Printers::Extensions::IPrint3DWorkflow2>
    {
        Print3DWorkflow(std::nullptr_t) noexcept {}
        Print3DWorkflow(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrint3DWorkflow(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Print3DWorkflowPrintRequestedEventArgs : llm::OS::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs
    {
        Print3DWorkflowPrintRequestedEventArgs(std::nullptr_t) noexcept {}
        Print3DWorkflowPrintRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrint3DWorkflowPrintRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Print3DWorkflowPrinterChangedEventArgs : llm::OS::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs
    {
        Print3DWorkflowPrinterChangedEventArgs(std::nullptr_t) noexcept {}
        Print3DWorkflowPrinterChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrint3DWorkflowPrinterChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct PrintExtensionContext
    {
        PrintExtensionContext() = delete;
        static auto FromDeviceId(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) PrintNotificationEventDetails : llm::OS::Devices::Printers::Extensions::IPrintNotificationEventDetails
    {
        PrintNotificationEventDetails(std::nullptr_t) noexcept {}
        PrintNotificationEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrintNotificationEventDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskConfiguration : llm::OS::Devices::Printers::Extensions::IPrintTaskConfiguration
    {
        PrintTaskConfiguration(std::nullptr_t) noexcept {}
        PrintTaskConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrintTaskConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskConfigurationSaveRequest : llm::OS::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest
    {
        PrintTaskConfigurationSaveRequest(std::nullptr_t) noexcept {}
        PrintTaskConfigurationSaveRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskConfigurationSaveRequestedDeferral : llm::OS::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral
    {
        PrintTaskConfigurationSaveRequestedDeferral(std::nullptr_t) noexcept {}
        PrintTaskConfigurationSaveRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintTaskConfigurationSaveRequestedEventArgs : llm::OS::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs
    {
        PrintTaskConfigurationSaveRequestedEventArgs(std::nullptr_t) noexcept {}
        PrintTaskConfigurationSaveRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Printers::Extensions::IPrintTaskConfigurationSaveRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
