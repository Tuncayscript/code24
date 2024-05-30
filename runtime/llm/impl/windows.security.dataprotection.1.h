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
#ifndef LLM_OS_Security_DataProtection_1_H
#define LLM_OS_Security_DataProtection_1_H
#include "llm/impl/Windows.Security.DataProtection.0.h"
LLM_EXPORT namespace llm:OS::Security::DataProtection
{
    struct __declspec(empty_bases) IUserDataAvailabilityStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataAvailabilityStateChangedEventArgs>
    {
        IUserDataAvailabilityStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IUserDataAvailabilityStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataBufferUnprotectResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataBufferUnprotectResult>
    {
        IUserDataBufferUnprotectResult(std::nullptr_t = nullptr) noexcept {}
        IUserDataBufferUnprotectResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataProtectionManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataProtectionManager>
    {
        IUserDataProtectionManager(std::nullptr_t = nullptr) noexcept {}
        IUserDataProtectionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataProtectionManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataProtectionManagerStatics>
    {
        IUserDataProtectionManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IUserDataProtectionManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserDataStorageItemProtectionInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserDataStorageItemProtectionInfo>
    {
        IUserDataStorageItemProtectionInfo(std::nullptr_t = nullptr) noexcept {}
        IUserDataStorageItemProtectionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
