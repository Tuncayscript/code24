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
#ifndef LLM_OS_Devices_PointOfService_Provider_2_H
#define LLM_OS_Devices_PointOfService_Provider_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Devices.PointOfService.Provider.1.h"
LLM_EXPORT namespace llm::OS::Devices::PointOfService::Provider
{
    struct __declspec(empty_bases) BarcodeScannerDisableScannerRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequest,
        impl::require<BarcodeScannerDisableScannerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequest2>
    {
        BarcodeScannerDisableScannerRequest(std::nullptr_t) noexcept {}
        BarcodeScannerDisableScannerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerDisableScannerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerDisableScannerRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequestEventArgs
    {
        BarcodeScannerDisableScannerRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerDisableScannerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerDisableScannerRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerEnableScannerRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequest,
        impl::require<BarcodeScannerEnableScannerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequest2>
    {
        BarcodeScannerEnableScannerRequest(std::nullptr_t) noexcept {}
        BarcodeScannerEnableScannerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerEnableScannerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerEnableScannerRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequestEventArgs
    {
        BarcodeScannerEnableScannerRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerEnableScannerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerEnableScannerRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerFrameReader : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerFrameReader,
        impl::require<BarcodeScannerFrameReader, llm::OS::Foundation::IClosable>
    {
        BarcodeScannerFrameReader(std::nullptr_t) noexcept {}
        BarcodeScannerFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerFrameReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerFrameReaderFrameArrivedEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerFrameReaderFrameArrivedEventArgs
    {
        BarcodeScannerFrameReaderFrameArrivedEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerFrameReaderFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerFrameReaderFrameArrivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerGetSymbologyAttributesRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequest,
        impl::require<BarcodeScannerGetSymbologyAttributesRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequest2>
    {
        BarcodeScannerGetSymbologyAttributesRequest(std::nullptr_t) noexcept {}
        BarcodeScannerGetSymbologyAttributesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerGetSymbologyAttributesRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerGetSymbologyAttributesRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequestEventArgs
    {
        BarcodeScannerGetSymbologyAttributesRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerGetSymbologyAttributesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerGetSymbologyAttributesRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerHideVideoPreviewRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequest,
        impl::require<BarcodeScannerHideVideoPreviewRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequest2>
    {
        BarcodeScannerHideVideoPreviewRequest(std::nullptr_t) noexcept {}
        BarcodeScannerHideVideoPreviewRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerHideVideoPreviewRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerHideVideoPreviewRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequestEventArgs
    {
        BarcodeScannerHideVideoPreviewRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerHideVideoPreviewRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerHideVideoPreviewRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerProviderConnection : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerProviderConnection,
        impl::require<BarcodeScannerProviderConnection, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerProviderConnection2, llm::OS::Foundation::IClosable>
    {
        BarcodeScannerProviderConnection(std::nullptr_t) noexcept {}
        BarcodeScannerProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerProviderConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerProviderTriggerDetails : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerProviderTriggerDetails
    {
        BarcodeScannerProviderTriggerDetails(std::nullptr_t) noexcept {}
        BarcodeScannerProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerProviderTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerSetActiveSymbologiesRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequest,
        impl::require<BarcodeScannerSetActiveSymbologiesRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequest2>
    {
        BarcodeScannerSetActiveSymbologiesRequest(std::nullptr_t) noexcept {}
        BarcodeScannerSetActiveSymbologiesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerSetActiveSymbologiesRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerSetActiveSymbologiesRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequestEventArgs
    {
        BarcodeScannerSetActiveSymbologiesRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerSetActiveSymbologiesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetActiveSymbologiesRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerSetSymbologyAttributesRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequest,
        impl::require<BarcodeScannerSetSymbologyAttributesRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequest2>
    {
        BarcodeScannerSetSymbologyAttributesRequest(std::nullptr_t) noexcept {}
        BarcodeScannerSetSymbologyAttributesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerSetSymbologyAttributesRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerSetSymbologyAttributesRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequestEventArgs
    {
        BarcodeScannerSetSymbologyAttributesRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerSetSymbologyAttributesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerSetSymbologyAttributesRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerStartSoftwareTriggerRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequest,
        impl::require<BarcodeScannerStartSoftwareTriggerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequest2>
    {
        BarcodeScannerStartSoftwareTriggerRequest(std::nullptr_t) noexcept {}
        BarcodeScannerStartSoftwareTriggerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerStartSoftwareTriggerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerStartSoftwareTriggerRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequestEventArgs
    {
        BarcodeScannerStartSoftwareTriggerRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerStartSoftwareTriggerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStartSoftwareTriggerRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerStopSoftwareTriggerRequest : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequest,
        impl::require<BarcodeScannerStopSoftwareTriggerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequest2>
    {
        BarcodeScannerStopSoftwareTriggerRequest(std::nullptr_t) noexcept {}
        BarcodeScannerStopSoftwareTriggerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequest(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequest::ReportFailedAsync;
        using impl::consume_t<BarcodeScannerStopSoftwareTriggerRequest, llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequest2>::ReportFailedAsync;
    };
    struct __declspec(empty_bases) BarcodeScannerStopSoftwareTriggerRequestEventArgs : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequestEventArgs
    {
        BarcodeScannerStopSoftwareTriggerRequestEventArgs(std::nullptr_t) noexcept {}
        BarcodeScannerStopSoftwareTriggerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerStopSoftwareTriggerRequestEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeScannerVideoFrame : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerVideoFrame,
        impl::require<BarcodeScannerVideoFrame, llm::OS::Foundation::IClosable>
    {
        BarcodeScannerVideoFrame(std::nullptr_t) noexcept {}
        BarcodeScannerVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeScannerVideoFrame(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) BarcodeSymbologyAttributesBuilder : llm::OS::Devices::PointOfService::Provider::IBarcodeSymbologyAttributesBuilder
    {
        BarcodeSymbologyAttributesBuilder(std::nullptr_t) noexcept {}
        BarcodeSymbologyAttributesBuilder(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::PointOfService::Provider::IBarcodeSymbologyAttributesBuilder(ptr, take_ownership_from_abi) {}
        BarcodeSymbologyAttributesBuilder();
    };
}
#endif
