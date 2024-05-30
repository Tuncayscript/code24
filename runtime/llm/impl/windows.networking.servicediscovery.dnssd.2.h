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
#ifndef LLM_OS_Networking_ServiceDiscovery_Dnssd_2_H
#define LLM_OS_Networking_ServiceDiscovery_Dnssd_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Networking.ServiceDiscovery.Dnssd.1.h"
LLM_EXPORT namespace llm:OS::Networking::ServiceDiscovery::Dnssd
{
    struct __declspec(empty_bases) DnssdRegistrationResult : llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult,
        impl::require<DnssdRegistrationResult, llm:OS::Foundation::IStringable>
    {
        DnssdRegistrationResult(std::nullptr_t) noexcept {}
        DnssdRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdRegistrationResult(ptr, take_ownership_from_abi) {}
        DnssdRegistrationResult();
    };
    struct __declspec(empty_bases) DnssdServiceInstance : llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance,
        impl::require<DnssdServiceInstance, llm:OS::Foundation::IStringable>
    {
        DnssdServiceInstance(std::nullptr_t) noexcept {}
        DnssdServiceInstance(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceInstance(ptr, take_ownership_from_abi) {}
        DnssdServiceInstance(param::hstring const& dnssdServiceInstanceName, llm:OS::Networking::HostName const& hostName, uint16_t port);
    };
    struct __declspec(empty_bases) DnssdServiceInstanceCollection : llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>
    {
        DnssdServiceInstanceCollection(std::nullptr_t) noexcept {}
        DnssdServiceInstanceCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::Collections::IVectorView<llm:OS::Networking::ServiceDiscovery::Dnssd::DnssdServiceInstance>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DnssdServiceWatcher : llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher
    {
        DnssdServiceWatcher(std::nullptr_t) noexcept {}
        DnssdServiceWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::ServiceDiscovery::Dnssd::IDnssdServiceWatcher(ptr, take_ownership_from_abi) {}
    };
}
#endif
