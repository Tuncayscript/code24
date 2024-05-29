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
#ifndef LLM_OS_ApplicationModel_AppService_1_H
#define LLM_OS_ApplicationModel_AppService_1_H
#include "llm/impl/Windows.ApplicationModel.AppService.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::AppService
{
    struct __declspec(empty_bases) IAppServiceCatalogStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceCatalogStatics>
    {
        IAppServiceCatalogStatics(std::nullptr_t = nullptr) noexcept {}
        IAppServiceCatalogStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceClosedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceClosedEventArgs>
    {
        IAppServiceClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppServiceClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceConnection>
    {
        IAppServiceConnection(std::nullptr_t = nullptr) noexcept {}
        IAppServiceConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceConnection2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceConnection2>
    {
        IAppServiceConnection2(std::nullptr_t = nullptr) noexcept {}
        IAppServiceConnection2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceConnectionStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceConnectionStatics>
    {
        IAppServiceConnectionStatics(std::nullptr_t = nullptr) noexcept {}
        IAppServiceConnectionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceDeferral>
    {
        IAppServiceDeferral(std::nullptr_t = nullptr) noexcept {}
        IAppServiceDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceRequest>
    {
        IAppServiceRequest(std::nullptr_t = nullptr) noexcept {}
        IAppServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceRequestReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceRequestReceivedEventArgs>
    {
        IAppServiceRequestReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppServiceRequestReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceResponse :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceResponse>
    {
        IAppServiceResponse(std::nullptr_t = nullptr) noexcept {}
        IAppServiceResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceTriggerDetails>
    {
        IAppServiceTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IAppServiceTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceTriggerDetails2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceTriggerDetails2>
    {
        IAppServiceTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        IAppServiceTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceTriggerDetails3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceTriggerDetails3>
    {
        IAppServiceTriggerDetails3(std::nullptr_t = nullptr) noexcept {}
        IAppServiceTriggerDetails3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppServiceTriggerDetails4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppServiceTriggerDetails4>
    {
        IAppServiceTriggerDetails4(std::nullptr_t = nullptr) noexcept {}
        IAppServiceTriggerDetails4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStatelessAppServiceResponse :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IStatelessAppServiceResponse>
    {
        IStatelessAppServiceResponse(std::nullptr_t = nullptr) noexcept {}
        IStatelessAppServiceResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
