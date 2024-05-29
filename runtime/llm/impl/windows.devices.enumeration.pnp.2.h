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
#ifndef LLM_OS_Devices_Enumeration_Pnp_2_H
#define LLM_OS_Devices_Enumeration_Pnp_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Devices.Enumeration.Pnp.1.h"
LLM_EXPORT namespace llm::OS::Devices::Enumeration::Pnp
{
    struct __declspec(empty_bases) PnpObject : llm::OS::Devices::Enumeration::Pnp::IPnpObject
    {
        PnpObject(std::nullptr_t) noexcept {}
        PnpObject(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::Pnp::IPnpObject(ptr, take_ownership_from_abi) {}
        static auto CreateFromIdAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::hstring const& id, param::async_iterable<hstring> const& requestedProperties);
        static auto FindAllAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::async_iterable<hstring> const& requestedProperties);
        static auto FindAllAsync(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::async_iterable<hstring> const& requestedProperties, param::hstring const& aqsFilter);
        static auto CreateWatcher(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::iterable<hstring> const& requestedProperties);
        static auto CreateWatcher(llm::OS::Devices::Enumeration::Pnp::PnpObjectType const& type, param::iterable<hstring> const& requestedProperties, param::hstring const& aqsFilter);
    };
    struct __declspec(empty_bases) PnpObjectCollection : llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::Pnp::PnpObject>
    {
        PnpObjectCollection(std::nullptr_t) noexcept {}
        PnpObjectCollection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::Pnp::PnpObject>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PnpObjectUpdate : llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate
    {
        PnpObjectUpdate(std::nullptr_t) noexcept {}
        PnpObjectUpdate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::Pnp::IPnpObjectUpdate(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PnpObjectWatcher : llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher
    {
        PnpObjectWatcher(std::nullptr_t) noexcept {}
        PnpObjectWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Enumeration::Pnp::IPnpObjectWatcher(ptr, take_ownership_from_abi) {}
    };
}
#endif
