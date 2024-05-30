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
#ifndef LLM_OS_Networking_2_H
#define LLM_OS_Networking_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Networking.1.h"
LLM_EXPORT namespace llm:OS::Networking
{
    struct __declspec(empty_bases) EndpointPair : llm:OS::Networking::IEndpointPair
    {
        EndpointPair(std::nullptr_t) noexcept {}
        EndpointPair(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::IEndpointPair(ptr, take_ownership_from_abi) {}
        EndpointPair(llm:OS::Networking::HostName const& localHostName, param::hstring const& localServiceName, llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName);
    };
    struct __declspec(empty_bases) HostName : llm:OS::Networking::IHostName,
        impl::require<HostName, llm:OS::Foundation::IStringable>
    {
        HostName(std::nullptr_t) noexcept {}
        HostName(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::IHostName(ptr, take_ownership_from_abi) {}
        explicit HostName(param::hstring const& hostName);
        static auto Compare(param::hstring const& value1, param::hstring const& value2);
    };
}
#endif
