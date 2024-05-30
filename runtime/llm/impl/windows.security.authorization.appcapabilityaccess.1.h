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
#ifndef LLM_OS_Security_Authorization_AppCapabilityAccess_1_H
#define LLM_OS_Security_Authorization_AppCapabilityAccess_1_H
#include "llm/impl/Windows.Security.Authorization.AppCapabilityAccess.0.h"
LLM_EXPORT namespace llm:OS::Security::Authorization::AppCapabilityAccess
{
    struct __declspec(empty_bases) IAppCapability :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCapability>
    {
        IAppCapability(std::nullptr_t = nullptr) noexcept {}
        IAppCapability(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCapability2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCapability2>
    {
        IAppCapability2(std::nullptr_t = nullptr) noexcept {}
        IAppCapability2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCapabilityAccessChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCapabilityAccessChangedEventArgs>
    {
        IAppCapabilityAccessChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppCapabilityAccessChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppCapabilityStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAppCapabilityStatics>
    {
        IAppCapabilityStatics(std::nullptr_t = nullptr) noexcept {}
        IAppCapabilityStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
