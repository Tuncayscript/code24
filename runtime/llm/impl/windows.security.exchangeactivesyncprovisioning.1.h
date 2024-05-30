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
#ifndef LLM_OS_Security_ExchangeActiveSyncProvisioning_1_H
#define LLM_OS_Security_ExchangeActiveSyncProvisioning_1_H
#include "llm/impl/Windows.Security.ExchangeActiveSyncProvisioning.0.h"
LLM_EXPORT namespace llm:OS::Security::ExchangeActiveSyncProvisioning
{
    struct __declspec(empty_bases) IEasClientDeviceInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEasClientDeviceInformation>
    {
        IEasClientDeviceInformation(std::nullptr_t = nullptr) noexcept {}
        IEasClientDeviceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEasClientDeviceInformation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEasClientDeviceInformation2>,
        impl::require<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2, llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation>
    {
        IEasClientDeviceInformation2(std::nullptr_t = nullptr) noexcept {}
        IEasClientDeviceInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEasClientSecurityPolicy :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEasClientSecurityPolicy>
    {
        IEasClientSecurityPolicy(std::nullptr_t = nullptr) noexcept {}
        IEasClientSecurityPolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEasComplianceResults :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEasComplianceResults>
    {
        IEasComplianceResults(std::nullptr_t = nullptr) noexcept {}
        IEasComplianceResults(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IEasComplianceResults2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IEasComplianceResults2>,
        impl::require<llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2, llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults>
    {
        IEasComplianceResults2(std::nullptr_t = nullptr) noexcept {}
        IEasComplianceResults2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
