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
#ifndef LLM_OS_Media_Protection_1_H
#define LLM_OS_Media_Protection_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Media.Protection.0.h"
LLM_EXPORT namespace llm:OS::Media::Protection
{
    struct __declspec(empty_bases) IComponentLoadFailedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IComponentLoadFailedEventArgs>
    {
        IComponentLoadFailedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IComponentLoadFailedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IComponentRenewalStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IComponentRenewalStatics>
    {
        IComponentRenewalStatics(std::nullptr_t = nullptr) noexcept {}
        IComponentRenewalStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IHdcpSession :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IHdcpSession>,
        impl::require<llm:OS::Media::Protection::IHdcpSession, llm:OS::Foundation::IClosable>
    {
        IHdcpSession(std::nullptr_t = nullptr) noexcept {}
        IHdcpSession(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProtectionManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaProtectionManager>
    {
        IMediaProtectionManager(std::nullptr_t = nullptr) noexcept {}
        IMediaProtectionManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProtectionPMPServer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaProtectionPMPServer>
    {
        IMediaProtectionPMPServer(std::nullptr_t = nullptr) noexcept {}
        IMediaProtectionPMPServer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProtectionPMPServerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaProtectionPMPServerFactory>
    {
        IMediaProtectionPMPServerFactory(std::nullptr_t = nullptr) noexcept {}
        IMediaProtectionPMPServerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProtectionServiceCompletion :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaProtectionServiceCompletion>
    {
        IMediaProtectionServiceCompletion(std::nullptr_t = nullptr) noexcept {}
        IMediaProtectionServiceCompletion(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMediaProtectionServiceRequest :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMediaProtectionServiceRequest>
    {
        IMediaProtectionServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IMediaProtectionServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IProtectionCapabilities :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IProtectionCapabilities>
    {
        IProtectionCapabilities(std::nullptr_t = nullptr) noexcept {}
        IProtectionCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRevocationAndRenewalInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRevocationAndRenewalInformation>
    {
        IRevocationAndRenewalInformation(std::nullptr_t = nullptr) noexcept {}
        IRevocationAndRenewalInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IRevocationAndRenewalItem :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IRevocationAndRenewalItem>
    {
        IRevocationAndRenewalItem(std::nullptr_t = nullptr) noexcept {}
        IRevocationAndRenewalItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IServiceRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServiceRequestedEventArgs>
    {
        IServiceRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IServiceRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IServiceRequestedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServiceRequestedEventArgs2>
    {
        IServiceRequestedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IServiceRequestedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
