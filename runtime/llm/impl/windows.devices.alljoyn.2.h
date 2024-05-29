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
#ifndef LLM_OS_Devices_AllJoyn_2_H
#define LLM_OS_Devices_AllJoyn_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Globalization.1.h"
#include "llm/impl/Windows.Devices.AllJoyn.1.h"
LLM_EXPORT namespace llm::OS::Devices::AllJoyn
{
    struct __declspec(empty_bases) AllJoynAboutData : llm::OS::Devices::AllJoyn::IAllJoynAboutData
    {
        AllJoynAboutData(std::nullptr_t) noexcept {}
        AllJoynAboutData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynAboutData(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AllJoynAboutDataView : llm::OS::Devices::AllJoyn::IAllJoynAboutDataView
    {
        AllJoynAboutDataView(std::nullptr_t) noexcept {}
        AllJoynAboutDataView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynAboutDataView(ptr, take_ownership_from_abi) {}
        static auto GetDataBySessionPortAsync(param::hstring const& uniqueName, llm::OS::Devices::AllJoyn::AllJoynBusAttachment const& busAttachment, uint16_t sessionPort);
        static auto GetDataBySessionPortAsync(param::hstring const& uniqueName, llm::OS::Devices::AllJoyn::AllJoynBusAttachment const& busAttachment, uint16_t sessionPort, llm::OS::Globalization::Language const& language);
    };
    struct __declspec(empty_bases) AllJoynAcceptSessionJoinerEventArgs : llm::OS::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs
    {
        AllJoynAcceptSessionJoinerEventArgs(std::nullptr_t) noexcept {}
        AllJoynAcceptSessionJoinerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynAcceptSessionJoinerEventArgs(ptr, take_ownership_from_abi) {}
        AllJoynAcceptSessionJoinerEventArgs(param::hstring const& uniqueName, uint16_t sessionPort, llm::OS::Devices::AllJoyn::AllJoynTrafficType const& trafficType, uint8_t proximity, llm::OS::Devices::AllJoyn::IAllJoynAcceptSessionJoiner const& acceptSessionJoiner);
    };
    struct __declspec(empty_bases) AllJoynAuthenticationCompleteEventArgs : llm::OS::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs
    {
        AllJoynAuthenticationCompleteEventArgs(std::nullptr_t) noexcept {}
        AllJoynAuthenticationCompleteEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynAuthenticationCompleteEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AllJoynBusAttachment : llm::OS::Devices::AllJoyn::IAllJoynBusAttachment,
        impl::require<AllJoynBusAttachment, llm::OS::Devices::AllJoyn::IAllJoynBusAttachment2>
    {
        AllJoynBusAttachment(std::nullptr_t) noexcept {}
        AllJoynBusAttachment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynBusAttachment(ptr, take_ownership_from_abi) {}
        AllJoynBusAttachment();
        explicit AllJoynBusAttachment(param::hstring const& connectionSpecification);
        static auto GetDefault();
        static auto GetWatcher(param::iterable<hstring> const& requiredInterfaces);
    };
    struct __declspec(empty_bases) AllJoynBusAttachmentStateChangedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs
    {
        AllJoynBusAttachmentStateChangedEventArgs(std::nullptr_t) noexcept {}
        AllJoynBusAttachmentStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynBusAttachmentStateChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AllJoynBusObject : llm::OS::Devices::AllJoyn::IAllJoynBusObject
    {
        AllJoynBusObject(std::nullptr_t) noexcept {}
        AllJoynBusObject(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynBusObject(ptr, take_ownership_from_abi) {}
        AllJoynBusObject();
        explicit AllJoynBusObject(param::hstring const& objectPath);
        AllJoynBusObject(param::hstring const& objectPath, llm::OS::Devices::AllJoyn::AllJoynBusAttachment const& busAttachment);
    };
    struct __declspec(empty_bases) AllJoynBusObjectStoppedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs
    {
        AllJoynBusObjectStoppedEventArgs(std::nullptr_t) noexcept {}
        AllJoynBusObjectStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynBusObjectStoppedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynBusObjectStoppedEventArgs(int32_t status);
    };
    struct __declspec(empty_bases) AllJoynCredentials : llm::OS::Devices::AllJoyn::IAllJoynCredentials
    {
        AllJoynCredentials(std::nullptr_t) noexcept {}
        AllJoynCredentials(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynCredentials(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AllJoynCredentialsRequestedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs
    {
        AllJoynCredentialsRequestedEventArgs(std::nullptr_t) noexcept {}
        AllJoynCredentialsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynCredentialsRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AllJoynCredentialsVerificationRequestedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs
    {
        AllJoynCredentialsVerificationRequestedEventArgs(std::nullptr_t) noexcept {}
        AllJoynCredentialsVerificationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynCredentialsVerificationRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AllJoynMessageInfo : llm::OS::Devices::AllJoyn::IAllJoynMessageInfo
    {
        AllJoynMessageInfo(std::nullptr_t) noexcept {}
        AllJoynMessageInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynMessageInfo(ptr, take_ownership_from_abi) {}
        explicit AllJoynMessageInfo(param::hstring const& senderUniqueName);
    };
    struct __declspec(empty_bases) AllJoynProducerStoppedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs
    {
        AllJoynProducerStoppedEventArgs(std::nullptr_t) noexcept {}
        AllJoynProducerStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynProducerStoppedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynProducerStoppedEventArgs(int32_t status);
    };
    struct __declspec(empty_bases) AllJoynServiceInfo : llm::OS::Devices::AllJoyn::IAllJoynServiceInfo
    {
        AllJoynServiceInfo(std::nullptr_t) noexcept {}
        AllJoynServiceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynServiceInfo(ptr, take_ownership_from_abi) {}
        AllJoynServiceInfo(param::hstring const& uniqueName, param::hstring const& objectPath, uint16_t sessionPort);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) AllJoynServiceInfoRemovedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs
    {
        AllJoynServiceInfoRemovedEventArgs(std::nullptr_t) noexcept {}
        AllJoynServiceInfoRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynServiceInfoRemovedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynServiceInfoRemovedEventArgs(param::hstring const& uniqueName);
    };
    struct __declspec(empty_bases) AllJoynSession : llm::OS::Devices::AllJoyn::IAllJoynSession
    {
        AllJoynSession(std::nullptr_t) noexcept {}
        AllJoynSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynSession(ptr, take_ownership_from_abi) {}
        static auto GetFromServiceInfoAsync(llm::OS::Devices::AllJoyn::AllJoynServiceInfo const& serviceInfo);
        static auto GetFromServiceInfoAsync(llm::OS::Devices::AllJoyn::AllJoynServiceInfo const& serviceInfo, llm::OS::Devices::AllJoyn::AllJoynBusAttachment const& busAttachment);
    };
    struct __declspec(empty_bases) AllJoynSessionJoinedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs
    {
        AllJoynSessionJoinedEventArgs(std::nullptr_t) noexcept {}
        AllJoynSessionJoinedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynSessionJoinedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynSessionJoinedEventArgs(llm::OS::Devices::AllJoyn::AllJoynSession const& session);
    };
    struct __declspec(empty_bases) AllJoynSessionLostEventArgs : llm::OS::Devices::AllJoyn::IAllJoynSessionLostEventArgs
    {
        AllJoynSessionLostEventArgs(std::nullptr_t) noexcept {}
        AllJoynSessionLostEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynSessionLostEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynSessionLostEventArgs(llm::OS::Devices::AllJoyn::AllJoynSessionLostReason const& reason);
    };
    struct __declspec(empty_bases) AllJoynSessionMemberAddedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs
    {
        AllJoynSessionMemberAddedEventArgs(std::nullptr_t) noexcept {}
        AllJoynSessionMemberAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynSessionMemberAddedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynSessionMemberAddedEventArgs(param::hstring const& uniqueName);
    };
    struct __declspec(empty_bases) AllJoynSessionMemberRemovedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs
    {
        AllJoynSessionMemberRemovedEventArgs(std::nullptr_t) noexcept {}
        AllJoynSessionMemberRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynSessionMemberRemovedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynSessionMemberRemovedEventArgs(param::hstring const& uniqueName);
    };
    struct AllJoynStatus
    {
        AllJoynStatus() = delete;
        [[nodiscard]] static auto Ok();
        [[nodiscard]] static auto Fail();
        [[nodiscard]] static auto OperationTimedOut();
        [[nodiscard]] static auto OtherEndClosed();
        [[nodiscard]] static auto ConnectionRefused();
        [[nodiscard]] static auto AuthenticationFailed();
        [[nodiscard]] static auto AuthenticationRejectedByUser();
        [[nodiscard]] static auto SslConnectFailed();
        [[nodiscard]] static auto SslIdentityVerificationFailed();
        [[nodiscard]] static auto InsufficientSecurity();
        [[nodiscard]] static auto InvalidArgument1();
        [[nodiscard]] static auto InvalidArgument2();
        [[nodiscard]] static auto InvalidArgument3();
        [[nodiscard]] static auto InvalidArgument4();
        [[nodiscard]] static auto InvalidArgument5();
        [[nodiscard]] static auto InvalidArgument6();
        [[nodiscard]] static auto InvalidArgument7();
        [[nodiscard]] static auto InvalidArgument8();
    };
    struct __declspec(empty_bases) AllJoynWatcherStoppedEventArgs : llm::OS::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs
    {
        AllJoynWatcherStoppedEventArgs(std::nullptr_t) noexcept {}
        AllJoynWatcherStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::AllJoyn::IAllJoynWatcherStoppedEventArgs(ptr, take_ownership_from_abi) {}
        explicit AllJoynWatcherStoppedEventArgs(int32_t status);
    };
}
#endif
