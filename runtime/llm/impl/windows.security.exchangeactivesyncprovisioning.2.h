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
#ifndef LLM_OS_Security_ExchangeActiveSyncProvisioning_2_H
#define LLM_OS_Security_ExchangeActiveSyncProvisioning_2_H
#include "llm/impl/Windows.Security.ExchangeActiveSyncProvisioning.1.h"
LLM_EXPORT namespace llm:OS::Security::ExchangeActiveSyncProvisioning
{
    struct __declspec(empty_bases) EasClientDeviceInformation : llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation,
        impl::require<EasClientDeviceInformation, llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation2>
    {
        EasClientDeviceInformation(std::nullptr_t) noexcept {}
        EasClientDeviceInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientDeviceInformation(ptr, take_ownership_from_abi) {}
        EasClientDeviceInformation();
    };
    struct __declspec(empty_bases) EasClientSecurityPolicy : llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy
    {
        EasClientSecurityPolicy(std::nullptr_t) noexcept {}
        EasClientSecurityPolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::ExchangeActiveSyncProvisioning::IEasClientSecurityPolicy(ptr, take_ownership_from_abi) {}
        EasClientSecurityPolicy();
    };
    struct __declspec(empty_bases) EasComplianceResults : llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults,
        impl::require<EasComplianceResults, llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults2>
    {
        EasComplianceResults(std::nullptr_t) noexcept {}
        EasComplianceResults(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::ExchangeActiveSyncProvisioning::IEasComplianceResults(ptr, take_ownership_from_abi) {}
    };
}
#endif
