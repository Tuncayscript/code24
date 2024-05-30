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
#ifndef LLM_OS_Graphics_Printing_PrintSupport_2_H
#define LLM_OS_Graphics_Printing_PrintSupport_2_H
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Graphics.Printing.PrintSupport.1.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::PrintSupport
{
    struct __declspec(empty_bases) PrintSupportExtensionSession : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportExtensionSession,
        impl::require<PrintSupportExtensionSession, llm:OS::Graphics::Printing::PrintSupport::IPrintSupportExtensionSession2>
    {
        PrintSupportExtensionSession(std::nullptr_t) noexcept {}
        PrintSupportExtensionSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportExtensionSession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportExtensionTriggerDetails : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportExtensionTriggerDetails
    {
        PrintSupportExtensionTriggerDetails(std::nullptr_t) noexcept {}
        PrintSupportExtensionTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportExtensionTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportPrintDeviceCapabilitiesChangedEventArgs : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintDeviceCapabilitiesChangedEventArgs,
        impl::require<PrintSupportPrintDeviceCapabilitiesChangedEventArgs, llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintDeviceCapabilitiesChangedEventArgs2>
    {
        PrintSupportPrintDeviceCapabilitiesChangedEventArgs(std::nullptr_t) noexcept {}
        PrintSupportPrintDeviceCapabilitiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintDeviceCapabilitiesChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportPrintDeviceCapabilitiesUpdatePolicy : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintDeviceCapabilitiesUpdatePolicy
    {
        PrintSupportPrintDeviceCapabilitiesUpdatePolicy(std::nullptr_t) noexcept {}
        PrintSupportPrintDeviceCapabilitiesUpdatePolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintDeviceCapabilitiesUpdatePolicy(ptr, take_ownership_from_abi) {}
        static auto CreatePeriodicRefresh(llm:OS::Foundation::TimeSpan const& updatePeriod);
        static auto CreatePrintJobRefresh(uint32_t numberOfJobs);
    };
    struct __declspec(empty_bases) PrintSupportPrintTicketElement : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintTicketElement
    {
        PrintSupportPrintTicketElement(std::nullptr_t) noexcept {}
        PrintSupportPrintTicketElement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintTicketElement(ptr, take_ownership_from_abi) {}
        PrintSupportPrintTicketElement();
    };
    struct __declspec(empty_bases) PrintSupportPrintTicketValidationRequestedEventArgs : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintTicketValidationRequestedEventArgs
    {
        PrintSupportPrintTicketValidationRequestedEventArgs(std::nullptr_t) noexcept {}
        PrintSupportPrintTicketValidationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrintTicketValidationRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportPrinterSelectedEventArgs : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrinterSelectedEventArgs
    {
        PrintSupportPrinterSelectedEventArgs(std::nullptr_t) noexcept {}
        PrintSupportPrinterSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportPrinterSelectedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportSessionInfo : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportSessionInfo
    {
        PrintSupportSessionInfo(std::nullptr_t) noexcept {}
        PrintSupportSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportSessionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportSettingsActivatedEventArgs : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportSettingsActivatedEventArgs,
        impl::require<PrintSupportSettingsActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        PrintSupportSettingsActivatedEventArgs(std::nullptr_t) noexcept {}
        PrintSupportSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportSettingsActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PrintSupportSettingsUISession : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportSettingsUISession
    {
        PrintSupportSettingsUISession(std::nullptr_t) noexcept {}
        PrintSupportSettingsUISession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Graphics::Printing::PrintSupport::IPrintSupportSettingsUISession(ptr, take_ownership_from_abi) {}
    };
}
#endif
