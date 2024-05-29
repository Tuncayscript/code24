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
#ifndef LLM_OS_Devices_AllJoyn_1_H
#define LLM_OS_Devices_AllJoyn_1_H
#include "llm/impl/Windows.Devices.AllJoyn.0.h"
LLM_EXPORT namespace llm::OS::Devices::AllJoyn
{
    struct __declspec(empty_bases) IAllJoynAboutData :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAboutData>
    {
        IAllJoynAboutData(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAboutData(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynAboutDataView :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAboutDataView>
    {
        IAllJoynAboutDataView(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAboutDataView(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynAboutDataViewStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAboutDataViewStatics>
    {
        IAllJoynAboutDataViewStatics(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAboutDataViewStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynAcceptSessionJoiner :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAcceptSessionJoiner>
    {
        IAllJoynAcceptSessionJoiner(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAcceptSessionJoiner(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynAcceptSessionJoinerEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAcceptSessionJoinerEventArgs>
    {
        IAllJoynAcceptSessionJoinerEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAcceptSessionJoinerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynAcceptSessionJoinerEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAcceptSessionJoinerEventArgsFactory>
    {
        IAllJoynAcceptSessionJoinerEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAcceptSessionJoinerEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynAuthenticationCompleteEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynAuthenticationCompleteEventArgs>
    {
        IAllJoynAuthenticationCompleteEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynAuthenticationCompleteEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusAttachment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusAttachment>
    {
        IAllJoynBusAttachment(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusAttachment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusAttachment2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusAttachment2>
    {
        IAllJoynBusAttachment2(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusAttachment2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusAttachmentFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusAttachmentFactory>
    {
        IAllJoynBusAttachmentFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusAttachmentFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusAttachmentStateChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusAttachmentStateChangedEventArgs>
    {
        IAllJoynBusAttachmentStateChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusAttachmentStateChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusAttachmentStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusAttachmentStatics>
    {
        IAllJoynBusAttachmentStatics(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusAttachmentStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusObject :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusObject>
    {
        IAllJoynBusObject(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusObject(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusObjectFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusObjectFactory>
    {
        IAllJoynBusObjectFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusObjectFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusObjectStoppedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusObjectStoppedEventArgs>
    {
        IAllJoynBusObjectStoppedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusObjectStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynBusObjectStoppedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynBusObjectStoppedEventArgsFactory>
    {
        IAllJoynBusObjectStoppedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynBusObjectStoppedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynCredentials :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynCredentials>
    {
        IAllJoynCredentials(std::nullptr_t = nullptr) noexcept {}
        IAllJoynCredentials(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynCredentialsRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynCredentialsRequestedEventArgs>
    {
        IAllJoynCredentialsRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynCredentialsRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynCredentialsVerificationRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynCredentialsVerificationRequestedEventArgs>
    {
        IAllJoynCredentialsVerificationRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynCredentialsVerificationRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynMessageInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynMessageInfo>
    {
        IAllJoynMessageInfo(std::nullptr_t = nullptr) noexcept {}
        IAllJoynMessageInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynMessageInfoFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynMessageInfoFactory>
    {
        IAllJoynMessageInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynMessageInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynProducer :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynProducer>
    {
        IAllJoynProducer(std::nullptr_t = nullptr) noexcept {}
        IAllJoynProducer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynProducerStoppedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynProducerStoppedEventArgs>
    {
        IAllJoynProducerStoppedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynProducerStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynProducerStoppedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynProducerStoppedEventArgsFactory>
    {
        IAllJoynProducerStoppedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynProducerStoppedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynServiceInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynServiceInfo>
    {
        IAllJoynServiceInfo(std::nullptr_t = nullptr) noexcept {}
        IAllJoynServiceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynServiceInfoFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynServiceInfoFactory>
    {
        IAllJoynServiceInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynServiceInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynServiceInfoRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynServiceInfoRemovedEventArgs>
    {
        IAllJoynServiceInfoRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynServiceInfoRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynServiceInfoRemovedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynServiceInfoRemovedEventArgsFactory>
    {
        IAllJoynServiceInfoRemovedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynServiceInfoRemovedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynServiceInfoStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynServiceInfoStatics>
    {
        IAllJoynServiceInfoStatics(std::nullptr_t = nullptr) noexcept {}
        IAllJoynServiceInfoStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSession :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSession>
    {
        IAllJoynSession(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionJoinedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionJoinedEventArgs>
    {
        IAllJoynSessionJoinedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionJoinedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionJoinedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionJoinedEventArgsFactory>
    {
        IAllJoynSessionJoinedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionJoinedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionLostEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionLostEventArgs>
    {
        IAllJoynSessionLostEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionLostEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionLostEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionLostEventArgsFactory>
    {
        IAllJoynSessionLostEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionLostEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionMemberAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionMemberAddedEventArgs>
    {
        IAllJoynSessionMemberAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionMemberAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionMemberAddedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionMemberAddedEventArgsFactory>
    {
        IAllJoynSessionMemberAddedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionMemberAddedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionMemberRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionMemberRemovedEventArgs>
    {
        IAllJoynSessionMemberRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionMemberRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionMemberRemovedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionMemberRemovedEventArgsFactory>
    {
        IAllJoynSessionMemberRemovedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionMemberRemovedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynSessionStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynSessionStatics>
    {
        IAllJoynSessionStatics(std::nullptr_t = nullptr) noexcept {}
        IAllJoynSessionStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynStatusStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynStatusStatics>
    {
        IAllJoynStatusStatics(std::nullptr_t = nullptr) noexcept {}
        IAllJoynStatusStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynWatcherStoppedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynWatcherStoppedEventArgs>
    {
        IAllJoynWatcherStoppedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAllJoynWatcherStoppedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAllJoynWatcherStoppedEventArgsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAllJoynWatcherStoppedEventArgsFactory>
    {
        IAllJoynWatcherStoppedEventArgsFactory(std::nullptr_t = nullptr) noexcept {}
        IAllJoynWatcherStoppedEventArgsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
