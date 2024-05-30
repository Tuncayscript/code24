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
#ifndef LLM_OS_Networking_Sockets_1_H
#define LLM_OS_Networking_Sockets_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Networking.Sockets.0.h"
LLM_EXPORT namespace llm:OS::Networking::Sockets
{
    struct __declspec(empty_bases) IControlChannelTrigger :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IControlChannelTrigger>,
        impl::require<llm:OS::Networking::Sockets::IControlChannelTrigger, llm:OS::Foundation::IClosable>
    {
        IControlChannelTrigger(std::nullptr_t = nullptr) noexcept {}
        IControlChannelTrigger(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IControlChannelTrigger2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IControlChannelTrigger2>
    {
        IControlChannelTrigger2(std::nullptr_t = nullptr) noexcept {}
        IControlChannelTrigger2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IControlChannelTriggerEventDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IControlChannelTriggerEventDetails>
    {
        IControlChannelTriggerEventDetails(std::nullptr_t = nullptr) noexcept {}
        IControlChannelTriggerEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IControlChannelTriggerFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IControlChannelTriggerFactory>
    {
        IControlChannelTriggerFactory(std::nullptr_t = nullptr) noexcept {}
        IControlChannelTriggerFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IControlChannelTriggerResetEventDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IControlChannelTriggerResetEventDetails>
    {
        IControlChannelTriggerResetEventDetails(std::nullptr_t = nullptr) noexcept {}
        IControlChannelTriggerResetEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocket>,
        impl::require<llm:OS::Networking::Sockets::IDatagramSocket, llm:OS::Foundation::IClosable>
    {
        IDatagramSocket(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocket2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocket2>,
        impl::require<llm:OS::Networking::Sockets::IDatagramSocket2, llm:OS::Foundation::IClosable>
    {
        IDatagramSocket2(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocket2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocket3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocket3>
    {
        IDatagramSocket3(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocket3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocketControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocketControl>
    {
        IDatagramSocketControl(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocketControl2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocketControl2>
    {
        IDatagramSocketControl2(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocketControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocketControl3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocketControl3>
    {
        IDatagramSocketControl3(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocketControl3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocketInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocketInformation>
    {
        IDatagramSocketInformation(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocketMessageReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocketMessageReceivedEventArgs>
    {
        IDatagramSocketMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocketMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDatagramSocketStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDatagramSocketStatics>
    {
        IDatagramSocketStatics(std::nullptr_t = nullptr) noexcept {}
        IDatagramSocketStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMessageWebSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocket>,
        impl::require<llm:OS::Networking::Sockets::IMessageWebSocket, llm:OS::Foundation::IClosable, llm:OS::Networking::Sockets::IWebSocket>
    {
        IMessageWebSocket(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IMessageWebSocket, llm:OS::Foundation::IClosable>::Close;
        using impl::consume_t<IMessageWebSocket, llm:OS::Networking::Sockets::IWebSocket>::Close;
    };
    struct __declspec(empty_bases) IMessageWebSocket2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocket2>,
        impl::require<llm:OS::Networking::Sockets::IMessageWebSocket2, llm:OS::Foundation::IClosable, llm:OS::Networking::Sockets::IWebSocket, llm:OS::Networking::Sockets::IMessageWebSocket>
    {
        IMessageWebSocket2(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocket2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IMessageWebSocket2, llm:OS::Foundation::IClosable>::Close;
        using impl::consume_t<IMessageWebSocket2, llm:OS::Networking::Sockets::IWebSocket>::Close;
    };
    struct __declspec(empty_bases) IMessageWebSocket3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocket3>
    {
        IMessageWebSocket3(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocket3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMessageWebSocketControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocketControl>,
        impl::require<llm:OS::Networking::Sockets::IMessageWebSocketControl, llm:OS::Networking::Sockets::IWebSocketControl>
    {
        IMessageWebSocketControl(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMessageWebSocketControl2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocketControl2>
    {
        IMessageWebSocketControl2(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocketControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMessageWebSocketMessageReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocketMessageReceivedEventArgs>
    {
        IMessageWebSocketMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocketMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMessageWebSocketMessageReceivedEventArgs2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMessageWebSocketMessageReceivedEventArgs2>,
        impl::require<llm:OS::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs2, llm:OS::Networking::Sockets::IMessageWebSocketMessageReceivedEventArgs>
    {
        IMessageWebSocketMessageReceivedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        IMessageWebSocketMessageReceivedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IServerMessageWebSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServerMessageWebSocket>,
        impl::require<llm:OS::Networking::Sockets::IServerMessageWebSocket, llm:OS::Foundation::IClosable>
    {
        IServerMessageWebSocket(std::nullptr_t = nullptr) noexcept {}
        IServerMessageWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IServerMessageWebSocket, IServerMessageWebSocket>::Close;
        using impl::consume_t<IServerMessageWebSocket, llm:OS::Foundation::IClosable>::Close;
    };
    struct __declspec(empty_bases) IServerMessageWebSocketControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServerMessageWebSocketControl>
    {
        IServerMessageWebSocketControl(std::nullptr_t = nullptr) noexcept {}
        IServerMessageWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IServerMessageWebSocketInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServerMessageWebSocketInformation>
    {
        IServerMessageWebSocketInformation(std::nullptr_t = nullptr) noexcept {}
        IServerMessageWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IServerStreamWebSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServerStreamWebSocket>,
        impl::require<llm:OS::Networking::Sockets::IServerStreamWebSocket, llm:OS::Foundation::IClosable>
    {
        IServerStreamWebSocket(std::nullptr_t = nullptr) noexcept {}
        IServerStreamWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IServerStreamWebSocket, IServerStreamWebSocket>::Close;
        using impl::consume_t<IServerStreamWebSocket, llm:OS::Foundation::IClosable>::Close;
    };
    struct __declspec(empty_bases) IServerStreamWebSocketInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IServerStreamWebSocketInformation>
    {
        IServerStreamWebSocketInformation(std::nullptr_t = nullptr) noexcept {}
        IServerStreamWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketActivityContext :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISocketActivityContext>
    {
        ISocketActivityContext(std::nullptr_t = nullptr) noexcept {}
        ISocketActivityContext(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketActivityContextFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISocketActivityContextFactory>
    {
        ISocketActivityContextFactory(std::nullptr_t = nullptr) noexcept {}
        ISocketActivityContextFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketActivityInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISocketActivityInformation>
    {
        ISocketActivityInformation(std::nullptr_t = nullptr) noexcept {}
        ISocketActivityInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketActivityInformationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISocketActivityInformationStatics>
    {
        ISocketActivityInformationStatics(std::nullptr_t = nullptr) noexcept {}
        ISocketActivityInformationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketActivityTriggerDetails :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISocketActivityTriggerDetails>
    {
        ISocketActivityTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ISocketActivityTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISocketErrorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISocketErrorStatics>
    {
        ISocketErrorStatics(std::nullptr_t = nullptr) noexcept {}
        ISocketErrorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocket>,
        impl::require<llm:OS::Networking::Sockets::IStreamSocket, llm:OS::Foundation::IClosable>
    {
        IStreamSocket(std::nullptr_t = nullptr) noexcept {}
        IStreamSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocket2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocket2>,
        impl::require<llm:OS::Networking::Sockets::IStreamSocket2, llm:OS::Foundation::IClosable>
    {
        IStreamSocket2(std::nullptr_t = nullptr) noexcept {}
        IStreamSocket2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocket3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocket3>
    {
        IStreamSocket3(std::nullptr_t = nullptr) noexcept {}
        IStreamSocket3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketControl>
    {
        IStreamSocketControl(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketControl2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketControl2>
    {
        IStreamSocketControl2(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketControl3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketControl3>
    {
        IStreamSocketControl3(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketControl3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketControl4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketControl4>
    {
        IStreamSocketControl4(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketControl4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketInformation>
    {
        IStreamSocketInformation(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketInformation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketInformation2>
    {
        IStreamSocketInformation2(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListener :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListener>,
        impl::require<llm:OS::Networking::Sockets::IStreamSocketListener, llm:OS::Foundation::IClosable>
    {
        IStreamSocketListener(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListener(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListener2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListener2>,
        impl::require<llm:OS::Networking::Sockets::IStreamSocketListener2, llm:OS::Foundation::IClosable>
    {
        IStreamSocketListener2(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListener2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListener3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListener3>
    {
        IStreamSocketListener3(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListener3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListenerConnectionReceivedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListenerConnectionReceivedEventArgs>
    {
        IStreamSocketListenerConnectionReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListenerConnectionReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListenerControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListenerControl>
    {
        IStreamSocketListenerControl(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListenerControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListenerControl2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListenerControl2>
    {
        IStreamSocketListenerControl2(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListenerControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketListenerInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketListenerInformation>
    {
        IStreamSocketListenerInformation(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketListenerInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamSocketStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamSocketStatics>
    {
        IStreamSocketStatics(std::nullptr_t = nullptr) noexcept {}
        IStreamSocketStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamWebSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamWebSocket>,
        impl::require<llm:OS::Networking::Sockets::IStreamWebSocket, llm:OS::Foundation::IClosable, llm:OS::Networking::Sockets::IWebSocket>
    {
        IStreamWebSocket(std::nullptr_t = nullptr) noexcept {}
        IStreamWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IStreamWebSocket, llm:OS::Foundation::IClosable>::Close;
        using impl::consume_t<IStreamWebSocket, llm:OS::Networking::Sockets::IWebSocket>::Close;
    };
    struct __declspec(empty_bases) IStreamWebSocket2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamWebSocket2>,
        impl::require<llm:OS::Networking::Sockets::IStreamWebSocket2, llm:OS::Foundation::IClosable, llm:OS::Networking::Sockets::IWebSocket, llm:OS::Networking::Sockets::IStreamWebSocket>
    {
        IStreamWebSocket2(std::nullptr_t = nullptr) noexcept {}
        IStreamWebSocket2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IStreamWebSocket2, llm:OS::Foundation::IClosable>::Close;
        using impl::consume_t<IStreamWebSocket2, llm:OS::Networking::Sockets::IWebSocket>::Close;
    };
    struct __declspec(empty_bases) IStreamWebSocketControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamWebSocketControl>,
        impl::require<llm:OS::Networking::Sockets::IStreamWebSocketControl, llm:OS::Networking::Sockets::IWebSocketControl>
    {
        IStreamWebSocketControl(std::nullptr_t = nullptr) noexcept {}
        IStreamWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IStreamWebSocketControl2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IStreamWebSocketControl2>
    {
        IStreamWebSocketControl2(std::nullptr_t = nullptr) noexcept {}
        IStreamWebSocketControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocket :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocket>,
        impl::require<llm:OS::Networking::Sockets::IWebSocket, llm:OS::Foundation::IClosable>
    {
        IWebSocket(std::nullptr_t = nullptr) noexcept {}
        IWebSocket(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IWebSocket, IWebSocket>::Close;
        using impl::consume_t<IWebSocket, llm:OS::Foundation::IClosable>::Close;
    };
    struct __declspec(empty_bases) IWebSocketClosedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketClosedEventArgs>
    {
        IWebSocketClosedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebSocketClosedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocketControl :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketControl>
    {
        IWebSocketControl(std::nullptr_t = nullptr) noexcept {}
        IWebSocketControl(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocketControl2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketControl2>,
        impl::require<llm:OS::Networking::Sockets::IWebSocketControl2, llm:OS::Networking::Sockets::IWebSocketControl>
    {
        IWebSocketControl2(std::nullptr_t = nullptr) noexcept {}
        IWebSocketControl2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocketErrorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketErrorStatics>
    {
        IWebSocketErrorStatics(std::nullptr_t = nullptr) noexcept {}
        IWebSocketErrorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocketInformation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketInformation>
    {
        IWebSocketInformation(std::nullptr_t = nullptr) noexcept {}
        IWebSocketInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocketInformation2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketInformation2>,
        impl::require<llm:OS::Networking::Sockets::IWebSocketInformation2, llm:OS::Networking::Sockets::IWebSocketInformation>
    {
        IWebSocketInformation2(std::nullptr_t = nullptr) noexcept {}
        IWebSocketInformation2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IWebSocketServerCustomValidationRequestedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IWebSocketServerCustomValidationRequestedEventArgs>
    {
        IWebSocketServerCustomValidationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IWebSocketServerCustomValidationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
