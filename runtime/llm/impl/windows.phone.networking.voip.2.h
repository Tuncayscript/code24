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
#ifndef LLM_OS_Phone_Networking_Voip_2_H
#define LLM_OS_Phone_Networking_Voip_2_H
#include "llm/impl/Windows.Phone.Networking.Voip.1.h"
LLM_EXPORT namespace llm:OS::Phone::Networking::Voip
{
    struct __declspec(empty_bases) CallAnswerEventArgs : llm:OS::Phone::Networking::Voip::ICallAnswerEventArgs
    {
        CallAnswerEventArgs(std::nullptr_t) noexcept {}
        CallAnswerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::ICallAnswerEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CallRejectEventArgs : llm:OS::Phone::Networking::Voip::ICallRejectEventArgs
    {
        CallRejectEventArgs(std::nullptr_t) noexcept {}
        CallRejectEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::ICallRejectEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CallStateChangeEventArgs : llm:OS::Phone::Networking::Voip::ICallStateChangeEventArgs
    {
        CallStateChangeEventArgs(std::nullptr_t) noexcept {}
        CallStateChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::ICallStateChangeEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MuteChangeEventArgs : llm:OS::Phone::Networking::Voip::IMuteChangeEventArgs
    {
        MuteChangeEventArgs(std::nullptr_t) noexcept {}
        MuteChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::IMuteChangeEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) QuerySeamlessUpgradeSupportOperation : llm:OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation
    {
        QuerySeamlessUpgradeSupportOperation(std::nullptr_t) noexcept {}
        QuerySeamlessUpgradeSupportOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::IQuerySeamlessUpgradeSupportOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoipCallCoordinator : llm:OS::Phone::Networking::Voip::IVoipCallCoordinator,
        impl::require<VoipCallCoordinator, llm:OS::Phone::Networking::Voip::IVoipCallCoordinatorWithUpgrade, llm:OS::Phone::Networking::Voip::IVoipOperationsManager, llm:OS::Phone::Networking::Voip::IVoipCallCoordinatorWithAppDeterminedUpgrade, llm:OS::Phone::Networking::Voip::IVoipCallCoordinator2, llm:OS::Phone::Networking::Voip::IVoipCallCoordinator3>
    {
        VoipCallCoordinator(std::nullptr_t) noexcept {}
        VoipCallCoordinator(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::IVoipCallCoordinator(ptr, take_ownership_from_abi) {}
        using llm:OS::Phone::Networking::Voip::IVoipCallCoordinator::RequestNewIncomingCall;
        using impl::consume_t<VoipCallCoordinator, llm:OS::Phone::Networking::Voip::IVoipCallCoordinator3>::RequestNewIncomingCall;
        static auto GetDefault();
    };
    struct __declspec(empty_bases) VoipPhoneCall : llm:OS::Phone::Networking::Voip::IVoipPhoneCall,
        impl::require<VoipPhoneCall, llm:OS::Phone::Networking::Voip::IVoipPhoneCallReady, llm:OS::Phone::Networking::Voip::IVoipPhoneCall2, llm:OS::Phone::Networking::Voip::IVoipPhoneCall3>
    {
        VoipPhoneCall(std::nullptr_t) noexcept {}
        VoipPhoneCall(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Phone::Networking::Voip::IVoipPhoneCall(ptr, take_ownership_from_abi) {}
    };
}
#endif
