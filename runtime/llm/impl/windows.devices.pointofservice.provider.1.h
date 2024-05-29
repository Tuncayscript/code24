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
#ifndef LLM_OS_Devices_PointOfService_Provider_1_H
#define LLM_OS_Devices_PointOfService_Provider_1_H
#include "llm/impl/Windows.Devices.PointOfService.Provider.0.h"
LLM_EXPORT namespace llm::OS::Devices::PointOfService::Provider
{
    struct __declspec(empty_bases) IBarcodeScannerDisableScannerRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerDisableScannerRequest>
    {
        IBarcodeScannerDisableScannerRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerDisableScannerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerDisableScannerRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerDisableScannerRequest2>
    {
        IBarcodeScannerDisableScannerRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerDisableScannerRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerDisableScannerRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerDisableScannerRequestEventArgs>
    {
        IBarcodeScannerDisableScannerRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerDisableScannerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerEnableScannerRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerEnableScannerRequest>
    {
        IBarcodeScannerEnableScannerRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerEnableScannerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerEnableScannerRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerEnableScannerRequest2>
    {
        IBarcodeScannerEnableScannerRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerEnableScannerRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerEnableScannerRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerEnableScannerRequestEventArgs>
    {
        IBarcodeScannerEnableScannerRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerEnableScannerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerFrameReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerFrameReader>
    {
        IBarcodeScannerFrameReader(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerFrameReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerFrameReaderFrameArrivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerFrameReaderFrameArrivedEventArgs>
    {
        IBarcodeScannerFrameReaderFrameArrivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerFrameReaderFrameArrivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerGetSymbologyAttributesRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerGetSymbologyAttributesRequest>
    {
        IBarcodeScannerGetSymbologyAttributesRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerGetSymbologyAttributesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerGetSymbologyAttributesRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerGetSymbologyAttributesRequest2>
    {
        IBarcodeScannerGetSymbologyAttributesRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerGetSymbologyAttributesRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerGetSymbologyAttributesRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerGetSymbologyAttributesRequestEventArgs>
    {
        IBarcodeScannerGetSymbologyAttributesRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerGetSymbologyAttributesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerHideVideoPreviewRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerHideVideoPreviewRequest>
    {
        IBarcodeScannerHideVideoPreviewRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerHideVideoPreviewRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerHideVideoPreviewRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerHideVideoPreviewRequest2>
    {
        IBarcodeScannerHideVideoPreviewRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerHideVideoPreviewRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerHideVideoPreviewRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerHideVideoPreviewRequestEventArgs>
    {
        IBarcodeScannerHideVideoPreviewRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerHideVideoPreviewRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerProviderConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerProviderConnection>
    {
        IBarcodeScannerProviderConnection(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerProviderConnection2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerProviderConnection2>
    {
        IBarcodeScannerProviderConnection2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerProviderConnection2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerProviderTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerProviderTriggerDetails>
    {
        IBarcodeScannerProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerSetActiveSymbologiesRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerSetActiveSymbologiesRequest>
    {
        IBarcodeScannerSetActiveSymbologiesRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerSetActiveSymbologiesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerSetActiveSymbologiesRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerSetActiveSymbologiesRequest2>
    {
        IBarcodeScannerSetActiveSymbologiesRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerSetActiveSymbologiesRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerSetActiveSymbologiesRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerSetActiveSymbologiesRequestEventArgs>
    {
        IBarcodeScannerSetActiveSymbologiesRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerSetActiveSymbologiesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerSetSymbologyAttributesRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerSetSymbologyAttributesRequest>
    {
        IBarcodeScannerSetSymbologyAttributesRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerSetSymbologyAttributesRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerSetSymbologyAttributesRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerSetSymbologyAttributesRequest2>
    {
        IBarcodeScannerSetSymbologyAttributesRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerSetSymbologyAttributesRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerSetSymbologyAttributesRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerSetSymbologyAttributesRequestEventArgs>
    {
        IBarcodeScannerSetSymbologyAttributesRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerSetSymbologyAttributesRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStartSoftwareTriggerRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStartSoftwareTriggerRequest>
    {
        IBarcodeScannerStartSoftwareTriggerRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStartSoftwareTriggerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStartSoftwareTriggerRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStartSoftwareTriggerRequest2>
    {
        IBarcodeScannerStartSoftwareTriggerRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStartSoftwareTriggerRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStartSoftwareTriggerRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStartSoftwareTriggerRequestEventArgs>
    {
        IBarcodeScannerStartSoftwareTriggerRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStartSoftwareTriggerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStopSoftwareTriggerRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStopSoftwareTriggerRequest>
    {
        IBarcodeScannerStopSoftwareTriggerRequest(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStopSoftwareTriggerRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStopSoftwareTriggerRequest2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStopSoftwareTriggerRequest2>
    {
        IBarcodeScannerStopSoftwareTriggerRequest2(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStopSoftwareTriggerRequest2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerStopSoftwareTriggerRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerStopSoftwareTriggerRequestEventArgs>
    {
        IBarcodeScannerStopSoftwareTriggerRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerStopSoftwareTriggerRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeScannerVideoFrame :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeScannerVideoFrame>
    {
        IBarcodeScannerVideoFrame(std::nullptr_t = nullptr) noexcept {}
        IBarcodeScannerVideoFrame(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IBarcodeSymbologyAttributesBuilder :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IBarcodeSymbologyAttributesBuilder>
    {
        IBarcodeSymbologyAttributesBuilder(std::nullptr_t = nullptr) noexcept {}
        IBarcodeSymbologyAttributesBuilder(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
