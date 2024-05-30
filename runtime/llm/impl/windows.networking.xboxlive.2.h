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
#ifndef LLM_OS_Networking_XboxLive_2_H
#define LLM_OS_Networking_XboxLive_2_H
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Networking.XboxLive.1.h"
LLM_EXPORT namespace llm:OS::Networking::XboxLive
{
    struct __declspec(empty_bases) XboxLiveDeviceAddress : llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress
    {
        XboxLiveDeviceAddress(std::nullptr_t) noexcept {}
        XboxLiveDeviceAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveDeviceAddress(ptr, take_ownership_from_abi) {}
        static auto CreateFromSnapshotBase64(param::hstring const& base64);
        static auto CreateFromSnapshotBuffer(llm:OS::Storage::Streams::IBuffer const& buffer);
        static auto CreateFromSnapshotBytes(array_view<uint8_t const> buffer);
        static auto GetLocal();
        [[nodiscard]] static auto MaxSnapshotBytesSize();
    };
    struct __declspec(empty_bases) XboxLiveEndpointPair : llm:OS::Networking::XboxLive::IXboxLiveEndpointPair
    {
        XboxLiveEndpointPair(std::nullptr_t) noexcept {}
        XboxLiveEndpointPair(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveEndpointPair(ptr, take_ownership_from_abi) {}
        static auto FindEndpointPairBySocketAddressBytes(array_view<uint8_t const> localSocketAddress, array_view<uint8_t const> remoteSocketAddress);
        static auto FindEndpointPairByHostNamesAndPorts(llm:OS::Networking::HostName const& localHostName, param::hstring const& localPort, llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remotePort);
    };
    struct __declspec(empty_bases) XboxLiveEndpointPairCreationResult : llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult
    {
        XboxLiveEndpointPairCreationResult(std::nullptr_t) noexcept {}
        XboxLiveEndpointPairCreationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XboxLiveEndpointPairStateChangedEventArgs : llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs
    {
        XboxLiveEndpointPairStateChangedEventArgs(std::nullptr_t) noexcept {}
        XboxLiveEndpointPairStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XboxLiveEndpointPairTemplate : llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate
    {
        XboxLiveEndpointPairTemplate(std::nullptr_t) noexcept {}
        XboxLiveEndpointPairTemplate(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate(ptr, take_ownership_from_abi) {}
        static auto GetTemplateByName(param::hstring const& name);
        [[nodiscard]] static auto Templates();
    };
    struct __declspec(empty_bases) XboxLiveInboundEndpointPairCreatedEventArgs : llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs
    {
        XboxLiveInboundEndpointPairCreatedEventArgs(std::nullptr_t) noexcept {}
        XboxLiveInboundEndpointPairCreatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XboxLiveQualityOfServiceMeasurement : llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement
    {
        XboxLiveQualityOfServiceMeasurement(std::nullptr_t) noexcept {}
        XboxLiveQualityOfServiceMeasurement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement(ptr, take_ownership_from_abi) {}
        XboxLiveQualityOfServiceMeasurement();
        static auto PublishPrivatePayloadBytes(array_view<uint8_t const> payload);
        static auto ClearPrivatePayload();
        [[nodiscard]] static auto MaxSimultaneousProbeConnections();
        static auto MaxSimultaneousProbeConnections(uint32_t value);
        [[nodiscard]] static auto IsSystemOutboundBandwidthConstrained();
        static auto IsSystemOutboundBandwidthConstrained(bool value);
        [[nodiscard]] static auto IsSystemInboundBandwidthConstrained();
        static auto IsSystemInboundBandwidthConstrained(bool value);
        [[nodiscard]] static auto PublishedPrivatePayload();
        static auto PublishedPrivatePayload(llm:OS::Storage::Streams::IBuffer const& value);
        [[nodiscard]] static auto MaxPrivatePayloadSize();
    };
    struct __declspec(empty_bases) XboxLiveQualityOfServiceMetricResult : llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult
    {
        XboxLiveQualityOfServiceMetricResult(std::nullptr_t) noexcept {}
        XboxLiveQualityOfServiceMetricResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) XboxLiveQualityOfServicePrivatePayloadResult : llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult
    {
        XboxLiveQualityOfServicePrivatePayloadResult(std::nullptr_t) noexcept {}
        XboxLiveQualityOfServicePrivatePayloadResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
