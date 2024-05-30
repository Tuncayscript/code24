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
#ifndef LLM_OS_Networking_Sockets_2_H
#define LLM_OS_Networking_Sockets_2_H
#include "llm/impl/Windows.ApplicationModel.Background.1.h"
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Networking.Sockets.1.h"
LLM_EXPORT namespace llm:OS::Networking::Sockets
{
    struct BandwidthStatistics
    {
        uint64_t OutboundBitsPerSecond;
        uint64_t InboundBitsPerSecond;
        uint64_t OutboundBitsPerSecondInstability;
        uint64_t InboundBitsPerSecondInstability;
        bool OutboundBandwidthPeaked;
        bool InboundBandwidthPeaked;
    };
    inline bool operator==(BandwidthStatistics const& left, BandwidthStatistics const& right) noexcept
    {
        return left.OutboundBitsPerSecond == right.OutboundBitsPerSecond && left.InboundBitsPerSecond == right.InboundBitsPerSecond && left.OutboundBitsPerSecondInstability == right.OutboundBitsPerSecondInstability && left.InboundBitsPerSecondInstability == right.InboundBitsPerSecondInstability && left.OutboundBandwidthPeaked == right.OutboundBandwidthPeaked && left.InboundBandwidthPeaked == right.InboundBandwidthPeaked;
    }
    inline bool operator!=(BandwidthStatistics const& left, BandwidthStatistics const& right) noexcept
    {
        return !(left == right);
    }
    struct RoundTripTimeStatistics
    {
        uint32_t Variance;
        uint32_t Max;
        uint32_t Min;
        uint32_t Sum;
    };
    inline bool operator==(RoundTripTimeStatistics const& left, RoundTripTimeStatistics const& right) noexcept
    {
        return left.Variance == right.Variance && left.Max == right.Max && left.Min == right.Min && left.Sum == right.Sum;
    }
    inline bool operator!=(RoundTripTimeStatistics const& left, RoundTripTimeStatistics const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) ControlChannelTrigger : llm:OS::Networking::Sockets::IControlChannelTrigger,
        impl::require<ControlChannelTrigger, llm:OS::Networking::Sockets::IControlChannelTrigger2>
    {
        ControlChannelTrigger(std::nullptr_t) noexcept {}
        ControlChannelTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IControlChannelTrigger(ptr, take_ownership_from_abi) {}
        ControlChannelTrigger(param::hstring const& channelId, uint32_t serverKeepAliveIntervalInMinutes);
        ControlChannelTrigger(param::hstring const& channelId, uint32_t serverKeepAliveIntervalInMinutes, llm:OS::Networking::Sockets::ControlChannelTriggerResourceType const& resourceRequestType);
    };
    struct __declspec(empty_bases) DatagramSocket : llm:OS::Networking::Sockets::IDatagramSocket,
        impl::require<DatagramSocket, llm:OS::Networking::Sockets::IDatagramSocket2, llm:OS::Networking::Sockets::IDatagramSocket3>
    {
        DatagramSocket(std::nullptr_t) noexcept {}
        DatagramSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IDatagramSocket(ptr, take_ownership_from_abi) {}
        DatagramSocket();
        using llm:OS::Networking::Sockets::IDatagramSocket::BindServiceNameAsync;
        using impl::consume_t<DatagramSocket, llm:OS::Networking::Sockets::IDatagramSocket2>::BindServiceNameAsync;
        static auto GetEndpointPairsAsync(llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName);
        static auto GetEndpointPairsAsync(llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName, llm:OS::Networking::HostNameSortOptions const& sortOptions);
    };
    struct __declspec(empty_bases) DatagramSocketControl : llm:OS::Networking::Sockets::IDatagramSocketControl,
        impl::require<DatagramSocketControl, llm:OS::Networking::Sockets::IDatagramSocketControl2, llm:OS::Networking::Sockets::IDatagramSocketControl3>
    {
        DatagramSocketControl(std::nullptr_t) noexcept {}
        DatagramSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IDatagramSocketControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DatagramSocketInformation : llm:OS::Networking::Sockets::IDatagramSocketInformation
    {
        DatagramSocketInformation(std::nullptr_t) noexcept {}
        DatagramSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IDatagramSocketInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DatagramSocketMessageReceivedEventArgs : llm:OS::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs
    {
        DatagramSocketMessageReceivedEventArgs(std::nullptr_t) noexcept {}
        DatagramSocketMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IDatagramSocketMessageReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MessageWebSocket : llm:OS::Networking::Sockets::IMessageWebSocket,
        impl::require<MessageWebSocket, llm:OS::Networking::Sockets::IMessageWebSocket2, llm:OS::Networking::Sockets::IMessageWebSocket3>
    {
        MessageWebSocket(std::nullptr_t) noexcept {}
        MessageWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IMessageWebSocket(ptr, take_ownership_from_abi) {}
        MessageWebSocket();
    };
    struct __declspec(empty_bases) MessageWebSocketControl : llm:OS::Networking::Sockets::IMessageWebSocketControl,
        impl::require<MessageWebSocketControl, llm:OS::Networking::Sockets::IWebSocketControl2, llm:OS::Networking::Sockets::IMessageWebSocketControl2>
    {
        MessageWebSocketControl(std::nullptr_t) noexcept {}
        MessageWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IMessageWebSocketControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MessageWebSocketInformation : llm:OS::Networking::Sockets::IWebSocketInformation,
        impl::require<MessageWebSocketInformation, llm:OS::Networking::Sockets::IWebSocketInformation2>
    {
        MessageWebSocketInformation(std::nullptr_t) noexcept {}
        MessageWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IWebSocketInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MessageWebSocketMessageReceivedEventArgs : llm:OS::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs,
        impl::require<MessageWebSocketMessageReceivedEventArgs, llm:OS::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs2>
    {
        MessageWebSocketMessageReceivedEventArgs(std::nullptr_t) noexcept {}
        MessageWebSocketMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServerMessageWebSocket : llm:OS::Networking::Sockets::IServerMessageWebSocket
    {
        ServerMessageWebSocket(std::nullptr_t) noexcept {}
        ServerMessageWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IServerMessageWebSocket(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServerMessageWebSocketControl : llm:OS::Networking::Sockets::IServerMessageWebSocketControl
    {
        ServerMessageWebSocketControl(std::nullptr_t) noexcept {}
        ServerMessageWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IServerMessageWebSocketControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServerMessageWebSocketInformation : llm:OS::Networking::Sockets::IServerMessageWebSocketInformation
    {
        ServerMessageWebSocketInformation(std::nullptr_t) noexcept {}
        ServerMessageWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IServerMessageWebSocketInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServerStreamWebSocket : llm:OS::Networking::Sockets::IServerStreamWebSocket
    {
        ServerStreamWebSocket(std::nullptr_t) noexcept {}
        ServerStreamWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IServerStreamWebSocket(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ServerStreamWebSocketInformation : llm:OS::Networking::Sockets::IServerStreamWebSocketInformation
    {
        ServerStreamWebSocketInformation(std::nullptr_t) noexcept {}
        ServerStreamWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IServerStreamWebSocketInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SocketActivityContext : llm:OS::Networking::Sockets::ISocketActivityContext
    {
        SocketActivityContext(std::nullptr_t) noexcept {}
        SocketActivityContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::ISocketActivityContext(ptr, take_ownership_from_abi) {}
        explicit SocketActivityContext(llm:OS::Storage::Streams::IBuffer const& data);
    };
    struct __declspec(empty_bases) SocketActivityInformation : llm:OS::Networking::Sockets::ISocketActivityInformation
    {
        SocketActivityInformation(std::nullptr_t) noexcept {}
        SocketActivityInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::ISocketActivityInformation(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AllSockets();
    };
    struct __declspec(empty_bases) SocketActivityTriggerDetails : llm:OS::Networking::Sockets::ISocketActivityTriggerDetails
    {
        SocketActivityTriggerDetails(std::nullptr_t) noexcept {}
        SocketActivityTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::ISocketActivityTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct SocketError
    {
        SocketError() = delete;
        static auto GetStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) StreamSocket : llm:OS::Networking::Sockets::IStreamSocket,
        impl::require<StreamSocket, llm:OS::Networking::Sockets::IStreamSocket2, llm:OS::Networking::Sockets::IStreamSocket3>
    {
        StreamSocket(std::nullptr_t) noexcept {}
        StreamSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocket(ptr, take_ownership_from_abi) {}
        StreamSocket();
        using llm:OS::Networking::Sockets::IStreamSocket::ConnectAsync;
        using impl::consume_t<StreamSocket, llm:OS::Networking::Sockets::IStreamSocket2>::ConnectAsync;
        static auto GetEndpointPairsAsync(llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName);
        static auto GetEndpointPairsAsync(llm:OS::Networking::HostName const& remoteHostName, param::hstring const& remoteServiceName, llm:OS::Networking::HostNameSortOptions const& sortOptions);
    };
    struct __declspec(empty_bases) StreamSocketControl : llm:OS::Networking::Sockets::IStreamSocketControl,
        impl::require<StreamSocketControl, llm:OS::Networking::Sockets::IStreamSocketControl2, llm:OS::Networking::Sockets::IStreamSocketControl3, llm:OS::Networking::Sockets::IStreamSocketControl4>
    {
        StreamSocketControl(std::nullptr_t) noexcept {}
        StreamSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocketControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamSocketInformation : llm:OS::Networking::Sockets::IStreamSocketInformation,
        impl::require<StreamSocketInformation, llm:OS::Networking::Sockets::IStreamSocketInformation2>
    {
        StreamSocketInformation(std::nullptr_t) noexcept {}
        StreamSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocketInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamSocketListener : llm:OS::Networking::Sockets::IStreamSocketListener,
        impl::require<StreamSocketListener, llm:OS::Networking::Sockets::IStreamSocketListener2, llm:OS::Networking::Sockets::IStreamSocketListener3>
    {
        StreamSocketListener(std::nullptr_t) noexcept {}
        StreamSocketListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocketListener(ptr, take_ownership_from_abi) {}
        StreamSocketListener();
        using llm:OS::Networking::Sockets::IStreamSocketListener::BindServiceNameAsync;
        using impl::consume_t<StreamSocketListener, llm:OS::Networking::Sockets::IStreamSocketListener2>::BindServiceNameAsync;
    };
    struct __declspec(empty_bases) StreamSocketListenerConnectionReceivedEventArgs : llm:OS::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs
    {
        StreamSocketListenerConnectionReceivedEventArgs(std::nullptr_t) noexcept {}
        StreamSocketListenerConnectionReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocketListenerConnectionReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamSocketListenerControl : llm:OS::Networking::Sockets::IStreamSocketListenerControl,
        impl::require<StreamSocketListenerControl, llm:OS::Networking::Sockets::IStreamSocketListenerControl2>
    {
        StreamSocketListenerControl(std::nullptr_t) noexcept {}
        StreamSocketListenerControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocketListenerControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamSocketListenerInformation : llm:OS::Networking::Sockets::IStreamSocketListenerInformation
    {
        StreamSocketListenerInformation(std::nullptr_t) noexcept {}
        StreamSocketListenerInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamSocketListenerInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamWebSocket : llm:OS::Networking::Sockets::IStreamWebSocket,
        impl::require<StreamWebSocket, llm:OS::Networking::Sockets::IStreamWebSocket2>
    {
        StreamWebSocket(std::nullptr_t) noexcept {}
        StreamWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamWebSocket(ptr, take_ownership_from_abi) {}
        StreamWebSocket();
    };
    struct __declspec(empty_bases) StreamWebSocketControl : llm:OS::Networking::Sockets::IStreamWebSocketControl,
        impl::require<StreamWebSocketControl, llm:OS::Networking::Sockets::IWebSocketControl2, llm:OS::Networking::Sockets::IStreamWebSocketControl2>
    {
        StreamWebSocketControl(std::nullptr_t) noexcept {}
        StreamWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IStreamWebSocketControl(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) StreamWebSocketInformation : llm:OS::Networking::Sockets::IWebSocketInformation,
        impl::require<StreamWebSocketInformation, llm:OS::Networking::Sockets::IWebSocketInformation2>
    {
        StreamWebSocketInformation(std::nullptr_t) noexcept {}
        StreamWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IWebSocketInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) WebSocketClosedEventArgs : llm:OS::Networking::Sockets::IWebSocketClosedEventArgs
    {
        WebSocketClosedEventArgs(std::nullptr_t) noexcept {}
        WebSocketClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IWebSocketClosedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct WebSocketError
    {
        WebSocketError() = delete;
        static auto GetStatus(int32_t hresult);
    };
    struct __declspec(empty_bases) WebSocketKeepAlive : llm:OS::ApplicationModel::Background::IBackgroundTask
    {
        WebSocketKeepAlive(std::nullptr_t) noexcept {}
        WebSocketKeepAlive(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::ApplicationModel::Background::IBackgroundTask(ptr, take_ownership_from_abi) {}
        WebSocketKeepAlive();
    };
    struct __declspec(empty_bases) WebSocketServerCustomValidationRequestedEventArgs : llm:OS::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs
    {
        WebSocketServerCustomValidationRequestedEventArgs(std::nullptr_t) noexcept {}
        WebSocketServerCustomValidationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Sockets::IWebSocketServerCustomValidationRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
}
#endif
