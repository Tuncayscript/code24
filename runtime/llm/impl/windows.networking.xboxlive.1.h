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
#ifndef LLM_OS_Networking_XboxLive_1_H
#define LLM_OS_Networking_XboxLive_1_H
#include "llm/impl/Windows.Networking.XboxLive.0.h"
LLM_EXPORT namespace llm:OS::Networking::XboxLive
{
    struct __declspec(empty_bases) IXboxLiveDeviceAddress :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveDeviceAddress>
    {
        IXboxLiveDeviceAddress(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveDeviceAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveDeviceAddressStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveDeviceAddressStatics>
    {
        IXboxLiveDeviceAddressStatics(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveDeviceAddressStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveEndpointPair :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveEndpointPair>
    {
        IXboxLiveEndpointPair(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveEndpointPair(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveEndpointPairCreationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveEndpointPairCreationResult>
    {
        IXboxLiveEndpointPairCreationResult(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveEndpointPairCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveEndpointPairStateChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveEndpointPairStateChangedEventArgs>
    {
        IXboxLiveEndpointPairStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveEndpointPairStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveEndpointPairStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveEndpointPairStatics>
    {
        IXboxLiveEndpointPairStatics(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveEndpointPairStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveEndpointPairTemplate :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveEndpointPairTemplate>
    {
        IXboxLiveEndpointPairTemplate(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveEndpointPairTemplate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveEndpointPairTemplateStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveEndpointPairTemplateStatics>
    {
        IXboxLiveEndpointPairTemplateStatics(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveEndpointPairTemplateStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveInboundEndpointPairCreatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveInboundEndpointPairCreatedEventArgs>
    {
        IXboxLiveInboundEndpointPairCreatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveInboundEndpointPairCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveQualityOfServiceMeasurement :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveQualityOfServiceMeasurement>
    {
        IXboxLiveQualityOfServiceMeasurement(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveQualityOfServiceMeasurement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveQualityOfServiceMeasurementStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveQualityOfServiceMeasurementStatics>
    {
        IXboxLiveQualityOfServiceMeasurementStatics(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveQualityOfServiceMeasurementStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveQualityOfServiceMetricResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveQualityOfServiceMetricResult>
    {
        IXboxLiveQualityOfServiceMetricResult(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveQualityOfServiceMetricResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IXboxLiveQualityOfServicePrivatePayloadResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IXboxLiveQualityOfServicePrivatePayloadResult>
    {
        IXboxLiveQualityOfServicePrivatePayloadResult(std::nullptr_t = nullptr) noexcept {}
        IXboxLiveQualityOfServicePrivatePayloadResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
