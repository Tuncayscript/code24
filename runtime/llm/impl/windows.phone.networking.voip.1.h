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
#ifndef LLM_OS_Phone_Networking_Voip_1_H
#define LLM_OS_Phone_Networking_Voip_1_H
#include "llm/impl/Windows.Phone.Networking.Voip.0.h"
LLM_EXPORT namespace llm:OS::Phone::Networking::Voip
{
    struct __declspec(empty_bases) ICallAnswerEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICallAnswerEventArgs>
    {
        ICallAnswerEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICallAnswerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICallRejectEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICallRejectEventArgs>
    {
        ICallRejectEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICallRejectEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICallStateChangeEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICallStateChangeEventArgs>
    {
        ICallStateChangeEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICallStateChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMuteChangeEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IMuteChangeEventArgs>
    {
        IMuteChangeEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMuteChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IQuerySeamlessUpgradeSupportOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IQuerySeamlessUpgradeSupportOperation>,
        impl::require<llm:OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation, llm:OS::Phone::Networking::Voip::IVoipOperation>
    {
        IQuerySeamlessUpgradeSupportOperation(std::nullptr_t = nullptr) noexcept {}
        IQuerySeamlessUpgradeSupportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinator :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator>
    {
        IVoipCallCoordinator(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinator2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator2>,
        impl::require<llm:OS::Phone::Networking::Voip::IVoipCallCoordinator2, llm:OS::Phone::Networking::Voip::IVoipCallCoordinator>
    {
        IVoipCallCoordinator2(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinator3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator3>,
        impl::require<llm:OS::Phone::Networking::Voip::IVoipCallCoordinator3, llm:OS::Phone::Networking::Voip::IVoipCallCoordinator>
    {
        IVoipCallCoordinator3(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IVoipCallCoordinator3, IVoipCallCoordinator3>::RequestNewIncomingCall;
        using impl::consume_t<IVoipCallCoordinator3, llm:OS::Phone::Networking::Voip::IVoipCallCoordinator>::RequestNewIncomingCall;
    };
    struct __declspec(empty_bases) IVoipCallCoordinatorStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinatorStatics>
    {
        IVoipCallCoordinatorStatics(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinatorWithAppDeterminedUpgrade :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinatorWithAppDeterminedUpgrade>
    {
        IVoipCallCoordinatorWithAppDeterminedUpgrade(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinatorWithAppDeterminedUpgrade(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinatorWithUpgrade :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinatorWithUpgrade>
    {
        IVoipCallCoordinatorWithUpgrade(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinatorWithUpgrade(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipOperation>
    {
        IVoipOperation(std::nullptr_t = nullptr) noexcept {}
        IVoipOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipOperationsManager :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipOperationsManager>
    {
        IVoipOperationsManager(std::nullptr_t = nullptr) noexcept {}
        IVoipOperationsManager(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCall :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCall>
    {
        IVoipPhoneCall(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCall(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCall2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCall2>,
        impl::require<llm:OS::Phone::Networking::Voip::IVoipPhoneCall2, llm:OS::Phone::Networking::Voip::IVoipPhoneCall>
    {
        IVoipPhoneCall2(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCall2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCall3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCall3>,
        impl::require<llm:OS::Phone::Networking::Voip::IVoipPhoneCall3, llm:OS::Phone::Networking::Voip::IVoipPhoneCall, llm:OS::Phone::Networking::Voip::IVoipPhoneCall2>
    {
        IVoipPhoneCall3(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCall3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCallReady :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCallReady>
    {
        IVoipPhoneCallReady(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCallReady(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
