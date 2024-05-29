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
#ifndef LLM_OS_Devices_Printers_Extensions_1_H
#define LLM_OS_Devices_Printers_Extensions_1_H
#include "llm/impl/Windows.Devices.Printers.Extensions.0.h"
LLM_EXPORT namespace llm::OS::Devices::Printers::Extensions
{
    struct __declspec(empty_bases) IPrint3DWorkflow :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DWorkflow>
    {
        IPrint3DWorkflow(std::nullptr_t = nullptr) noexcept {}
        IPrint3DWorkflow(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DWorkflow2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DWorkflow2>
    {
        IPrint3DWorkflow2(std::nullptr_t = nullptr) noexcept {}
        IPrint3DWorkflow2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DWorkflowPrintRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DWorkflowPrintRequestedEventArgs>
    {
        IPrint3DWorkflowPrintRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DWorkflowPrintRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrint3DWorkflowPrinterChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrint3DWorkflowPrinterChangedEventArgs>
    {
        IPrint3DWorkflowPrinterChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrint3DWorkflowPrinterChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintExtensionContextStatic :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintExtensionContextStatic>
    {
        IPrintExtensionContextStatic(std::nullptr_t = nullptr) noexcept {}
        IPrintExtensionContextStatic(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintNotificationEventDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintNotificationEventDetails>
    {
        IPrintNotificationEventDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintNotificationEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskConfiguration>
    {
        IPrintTaskConfiguration(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskConfigurationSaveRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskConfigurationSaveRequest>
    {
        IPrintTaskConfigurationSaveRequest(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskConfigurationSaveRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskConfigurationSaveRequestedDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskConfigurationSaveRequestedDeferral>
    {
        IPrintTaskConfigurationSaveRequestedDeferral(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskConfigurationSaveRequestedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintTaskConfigurationSaveRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPrintTaskConfigurationSaveRequestedEventArgs>
    {
        IPrintTaskConfigurationSaveRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintTaskConfigurationSaveRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
