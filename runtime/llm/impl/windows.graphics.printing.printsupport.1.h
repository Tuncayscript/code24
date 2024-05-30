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
#ifndef LLM_OS_Graphics_Printing_PrintSupport_1_H
#define LLM_OS_Graphics_Printing_PrintSupport_1_H
#include "llm/impl/Windows.Graphics.Printing.PrintSupport.0.h"
LLM_EXPORT namespace llm:OS::Graphics::Printing::PrintSupport
{
    struct __declspec(empty_bases) IPrintSupportExtensionSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportExtensionSession>
    {
        IPrintSupportExtensionSession(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportExtensionSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportExtensionSession2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportExtensionSession2>
    {
        IPrintSupportExtensionSession2(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportExtensionSession2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportExtensionTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportExtensionTriggerDetails>
    {
        IPrintSupportExtensionTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportExtensionTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrintDeviceCapabilitiesChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrintDeviceCapabilitiesChangedEventArgs>
    {
        IPrintSupportPrintDeviceCapabilitiesChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrintDeviceCapabilitiesChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrintDeviceCapabilitiesChangedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrintDeviceCapabilitiesChangedEventArgs2>
    {
        IPrintSupportPrintDeviceCapabilitiesChangedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrintDeviceCapabilitiesChangedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrintDeviceCapabilitiesUpdatePolicy :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrintDeviceCapabilitiesUpdatePolicy>
    {
        IPrintSupportPrintDeviceCapabilitiesUpdatePolicy(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrintDeviceCapabilitiesUpdatePolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrintDeviceCapabilitiesUpdatePolicyStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrintDeviceCapabilitiesUpdatePolicyStatics>
    {
        IPrintSupportPrintDeviceCapabilitiesUpdatePolicyStatics(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrintDeviceCapabilitiesUpdatePolicyStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrintTicketElement :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrintTicketElement>
    {
        IPrintSupportPrintTicketElement(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrintTicketElement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrintTicketValidationRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrintTicketValidationRequestedEventArgs>
    {
        IPrintSupportPrintTicketValidationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrintTicketValidationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportPrinterSelectedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportPrinterSelectedEventArgs>
    {
        IPrintSupportPrinterSelectedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportPrinterSelectedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportSessionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportSessionInfo>
    {
        IPrintSupportSessionInfo(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportSessionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportSettingsActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportSettingsActivatedEventArgs>
    {
        IPrintSupportSettingsActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportSettingsActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPrintSupportSettingsUISession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IPrintSupportSettingsUISession>
    {
        IPrintSupportSettingsUISession(std::nullptr_t = nullptr) noexcept {}
        IPrintSupportSettingsUISession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
