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
#ifndef LLM_OS_Networking_Proximity_2_H
#define LLM_OS_Networking_Proximity_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Networking.Proximity.1.h"
LLM_EXPORT namespace llm:OS::Networking::Proximity
{
    struct DeviceArrivedEventHandler : llm:OS::Foundation::IUnknown
    {
        DeviceArrivedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DeviceArrivedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DeviceArrivedEventHandler(L lambda);
        template <typename F> DeviceArrivedEventHandler(F* function);
        template <typename O, typename M> DeviceArrivedEventHandler(O* object, M method);
        template <typename O, typename M> DeviceArrivedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DeviceArrivedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Networking::Proximity::ProximityDevice const& sender) const;
    };
    struct DeviceDepartedEventHandler : llm:OS::Foundation::IUnknown
    {
        DeviceDepartedEventHandler(std::nullptr_t = nullptr) noexcept {}
        DeviceDepartedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> DeviceDepartedEventHandler(L lambda);
        template <typename F> DeviceDepartedEventHandler(F* function);
        template <typename O, typename M> DeviceDepartedEventHandler(O* object, M method);
        template <typename O, typename M> DeviceDepartedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> DeviceDepartedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Networking::Proximity::ProximityDevice const& sender) const;
    };
    struct MessageReceivedHandler : llm:OS::Foundation::IUnknown
    {
        MessageReceivedHandler(std::nullptr_t = nullptr) noexcept {}
        MessageReceivedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MessageReceivedHandler(L lambda);
        template <typename F> MessageReceivedHandler(F* function);
        template <typename O, typename M> MessageReceivedHandler(O* object, M method);
        template <typename O, typename M> MessageReceivedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> MessageReceivedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Networking::Proximity::ProximityDevice const& sender, llm:OS::Networking::Proximity::ProximityMessage const& message) const;
    };
    struct MessageTransmittedHandler : llm:OS::Foundation::IUnknown
    {
        MessageTransmittedHandler(std::nullptr_t = nullptr) noexcept {}
        MessageTransmittedHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> MessageTransmittedHandler(L lambda);
        template <typename F> MessageTransmittedHandler(F* function);
        template <typename O, typename M> MessageTransmittedHandler(O* object, M method);
        template <typename O, typename M> MessageTransmittedHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> MessageTransmittedHandler(weak_ref<O>&& object, M method);
        auto operator()(llm:OS::Networking::Proximity::ProximityDevice const& sender, int64_t messageId) const;
    };
    struct __declspec(empty_bases) ConnectionRequestedEventArgs : llm:OS::Networking::Proximity::IConnectionRequestedEventArgs
    {
        ConnectionRequestedEventArgs(std::nullptr_t) noexcept {}
        ConnectionRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Proximity::IConnectionRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct PeerFinder
    {
        PeerFinder() = delete;
        [[nodiscard]] static auto AllowBluetooth();
        static auto AllowBluetooth(bool value);
        [[nodiscard]] static auto AllowInfrastructure();
        static auto AllowInfrastructure(bool value);
        [[nodiscard]] static auto AllowWiFiDirect();
        static auto AllowWiFiDirect(bool value);
        [[nodiscard]] static auto DisplayName();
        static auto DisplayName(param::hstring const& value);
        [[nodiscard]] static auto SupportedDiscoveryTypes();
        [[nodiscard]] static auto AlternateIdentities();
        static auto Start();
        static auto Start(param::hstring const& peerMessage);
        static auto Stop();
        static auto TriggeredConnectionStateChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> const& handler);
        using TriggeredConnectionStateChanged_revoker = impl::factory_event_revoker<llm:OS::Networking::Proximity::IPeerFinderStatics, &impl::abi_t<llm:OS::Networking::Proximity::IPeerFinderStatics>::remove_TriggeredConnectionStateChanged>;
        [[nodiscard]] static TriggeredConnectionStateChanged_revoker TriggeredConnectionStateChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Networking::Proximity::TriggeredConnectionStateChangedEventArgs> const& handler);
        static auto TriggeredConnectionStateChanged(llm::event_token const& cookie);
        static auto ConnectionRequested(llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Networking::Proximity::ConnectionRequestedEventArgs> const& handler);
        using ConnectionRequested_revoker = impl::factory_event_revoker<llm:OS::Networking::Proximity::IPeerFinderStatics, &impl::abi_t<llm:OS::Networking::Proximity::IPeerFinderStatics>::remove_ConnectionRequested>;
        [[nodiscard]] static ConnectionRequested_revoker ConnectionRequested(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Foundation::IInspectable, llm:OS::Networking::Proximity::ConnectionRequestedEventArgs> const& handler);
        static auto ConnectionRequested(llm::event_token const& cookie);
        static auto FindAllPeersAsync();
        static auto ConnectAsync(llm:OS::Networking::Proximity::PeerInformation const& peerInformation);
        [[nodiscard]] static auto Role();
        static auto Role(llm:OS::Networking::Proximity::PeerRole const& value);
        [[nodiscard]] static auto DiscoveryData();
        static auto DiscoveryData(llm:OS::Storage::Streams::IBuffer const& value);
        static auto CreateWatcher();
    };
    struct __declspec(empty_bases) PeerInformation : llm:OS::Networking::Proximity::IPeerInformation,
        impl::require<PeerInformation, llm:OS::Networking::Proximity::IPeerInformation3, llm:OS::Networking::Proximity::IPeerInformationWithHostAndService>
    {
        PeerInformation(std::nullptr_t) noexcept {}
        PeerInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Proximity::IPeerInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PeerWatcher : llm:OS::Networking::Proximity::IPeerWatcher
    {
        PeerWatcher(std::nullptr_t) noexcept {}
        PeerWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Proximity::IPeerWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ProximityDevice : llm:OS::Networking::Proximity::IProximityDevice
    {
        ProximityDevice(std::nullptr_t) noexcept {}
        ProximityDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Proximity::IProximityDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto GetDefault();
        static auto FromId(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) ProximityMessage : llm:OS::Networking::Proximity::IProximityMessage
    {
        ProximityMessage(std::nullptr_t) noexcept {}
        ProximityMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Proximity::IProximityMessage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) TriggeredConnectionStateChangedEventArgs : llm:OS::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs
    {
        TriggeredConnectionStateChangedEventArgs(std::nullptr_t) noexcept {}
        TriggeredConnectionStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Proximity::ITriggeredConnectionStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
