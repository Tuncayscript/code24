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
#ifndef LLM_OS_ApplicationModel_AppService_2_H
#define LLM_OS_ApplicationModel_AppService_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.System.RemoteSystems.1.h"
#include "llm/impl/Windows.ApplicationModel.AppService.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::AppService
{
    struct AppServiceCatalog
    {
        AppServiceCatalog() = delete;
        static auto FindAppServiceProvidersAsync(param::hstring const& appServiceName);
    };
    struct __declspec(empty_bases) AppServiceClosedEventArgs : llm::OS::ApplicationModel::AppService::IAppServiceClosedEventArgs
    {
        AppServiceClosedEventArgs(std::nullptr_t) noexcept {}
        AppServiceClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppServiceConnection : llm::OS::ApplicationModel::AppService::IAppServiceConnection,
        impl::require<AppServiceConnection, llm::OS::ApplicationModel::AppService::IAppServiceConnection2, llm::OS::Foundation::IClosable>
    {
        AppServiceConnection(std::nullptr_t) noexcept {}
        AppServiceConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceConnection(ptr, take_ownership_from_abi) {}
        AppServiceConnection();
        static auto SendStatelessMessageAsync(llm::OS::ApplicationModel::AppService::AppServiceConnection const& connection, llm::OS::System::RemoteSystems::RemoteSystemConnectionRequest const& connectionRequest, llm::OS::Foundation::Collections::ValueSet const& message);
    };
    struct __declspec(empty_bases) AppServiceDeferral : llm::OS::ApplicationModel::AppService::IAppServiceDeferral
    {
        AppServiceDeferral(std::nullptr_t) noexcept {}
        AppServiceDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppServiceRequest : llm::OS::ApplicationModel::AppService::IAppServiceRequest
    {
        AppServiceRequest(std::nullptr_t) noexcept {}
        AppServiceRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppServiceRequestReceivedEventArgs : llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs
    {
        AppServiceRequestReceivedEventArgs(std::nullptr_t) noexcept {}
        AppServiceRequestReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceRequestReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppServiceResponse : llm::OS::ApplicationModel::AppService::IAppServiceResponse
    {
        AppServiceResponse(std::nullptr_t) noexcept {}
        AppServiceResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceResponse(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppServiceTriggerDetails : llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails,
        impl::require<AppServiceTriggerDetails, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails2, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails3, llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails4>
    {
        AppServiceTriggerDetails(std::nullptr_t) noexcept {}
        AppServiceTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IAppServiceTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StatelessAppServiceResponse : llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse
    {
        StatelessAppServiceResponse(std::nullptr_t) noexcept {}
        StatelessAppServiceResponse(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::AppService::IStatelessAppServiceResponse(ptr, take_ownership_from_abi) {}
    };
}
#endif
