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
#ifndef LLM_OS_ApplicationModel_Calls_1_H
#define LLM_OS_ApplicationModel_Calls_1_H
#include "llm/impl/Windows.ApplicationModel.Calls.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls
{
    struct __declspec(empty_bases) ICallAnswerEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICallAnswerEventArgs>
    {
        ICallAnswerEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICallAnswerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICallRejectEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICallRejectEventArgs>
    {
        ICallRejectEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICallRejectEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICallStateChangeEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICallStateChangeEventArgs>
    {
        ICallStateChangeEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICallStateChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenCallEndCallDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenCallEndCallDeferral>
    {
        ILockScreenCallEndCallDeferral(std::nullptr_t = nullptr) noexcept {}
        ILockScreenCallEndCallDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenCallEndRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenCallEndRequestedEventArgs>
    {
        ILockScreenCallEndRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ILockScreenCallEndRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenCallUI :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenCallUI>
    {
        ILockScreenCallUI(std::nullptr_t = nullptr) noexcept {}
        ILockScreenCallUI(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IMuteChangeEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IMuteChangeEventArgs>
    {
        IMuteChangeEventArgs(std::nullptr_t = nullptr) noexcept {}
        IMuteChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCall :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCall>
    {
        IPhoneCall(std::nullptr_t = nullptr) noexcept {}
        IPhoneCall(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallBlockingStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallBlockingStatics>
    {
        IPhoneCallBlockingStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallBlockingStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryEntry :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryEntry>
    {
        IPhoneCallHistoryEntry(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryEntryAddress :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryEntryAddress>
    {
        IPhoneCallHistoryEntryAddress(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryEntryAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryEntryAddressFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryEntryAddressFactory>
    {
        IPhoneCallHistoryEntryAddressFactory(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryEntryAddressFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryEntryQueryOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryEntryQueryOptions>
    {
        IPhoneCallHistoryEntryQueryOptions(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryEntryQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryEntryReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryEntryReader>
    {
        IPhoneCallHistoryEntryReader(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryEntryReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryManagerForUser :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryManagerForUser>
    {
        IPhoneCallHistoryManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryManagerStatics>
    {
        IPhoneCallHistoryManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryManagerStatics2>
    {
        IPhoneCallHistoryManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallHistoryStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallHistoryStore>
    {
        IPhoneCallHistoryStore(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallHistoryStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallInfo>
    {
        IPhoneCallInfo(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallManagerStatics>
    {
        IPhoneCallManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallManagerStatics2>
    {
        IPhoneCallManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallStatics>
    {
        IPhoneCallStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallStore>
    {
        IPhoneCallStore(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallVideoCapabilities :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallVideoCapabilities>
    {
        IPhoneCallVideoCapabilities(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallVideoCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallVideoCapabilitiesManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallVideoCapabilitiesManagerStatics>
    {
        IPhoneCallVideoCapabilitiesManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallVideoCapabilitiesManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallsResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallsResult>
    {
        IPhoneCallsResult(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneDialOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneDialOptions>
    {
        IPhoneDialOptions(std::nullptr_t = nullptr) noexcept {}
        IPhoneDialOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLine :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLine>
    {
        IPhoneLine(std::nullptr_t = nullptr) noexcept {}
        IPhoneLine(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLine2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLine2>
    {
        IPhoneLine2(std::nullptr_t = nullptr) noexcept {}
        IPhoneLine2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLine3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLine3>
    {
        IPhoneLine3(std::nullptr_t = nullptr) noexcept {}
        IPhoneLine3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineCellularDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineCellularDetails>
    {
        IPhoneLineCellularDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineCellularDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineConfiguration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineConfiguration>
    {
        IPhoneLineConfiguration(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineDialResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineDialResult>
    {
        IPhoneLineDialResult(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineDialResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineStatics>
    {
        IPhoneLineStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineTransportDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineTransportDevice>
    {
        IPhoneLineTransportDevice(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineTransportDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineTransportDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineTransportDevice2>
    {
        IPhoneLineTransportDevice2(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineTransportDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineTransportDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineTransportDeviceStatics>
    {
        IPhoneLineTransportDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineTransportDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineWatcher :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineWatcher>
    {
        IPhoneLineWatcher(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineWatcherEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineWatcherEventArgs>
    {
        IPhoneLineWatcherEventArgs(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineWatcherEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneVoicemail :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneVoicemail>
    {
        IPhoneVoicemail(std::nullptr_t = nullptr) noexcept {}
        IPhoneVoicemail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator>
    {
        IVoipCallCoordinator(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator2>,
        impl::require<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>
    {
        IVoipCallCoordinator2(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipCallCoordinator3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator3>,
        impl::require<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>
    {
        IVoipCallCoordinator3(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IVoipCallCoordinator3, IVoipCallCoordinator3>::RequestNewIncomingCall;
        using impl::consume_t<IVoipCallCoordinator3, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>::RequestNewIncomingCall;
    };
    struct __declspec(empty_bases) IVoipCallCoordinator4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinator4>,
        impl::require<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>
    {
        IVoipCallCoordinator4(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinator4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IVoipCallCoordinator4, IVoipCallCoordinator4>::ReserveCallResourcesAsync;
        using impl::consume_t<IVoipCallCoordinator4, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>::ReserveCallResourcesAsync;
    };
    struct __declspec(empty_bases) IVoipCallCoordinatorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipCallCoordinatorStatics>
    {
        IVoipCallCoordinatorStatics(std::nullptr_t = nullptr) noexcept {}
        IVoipCallCoordinatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCall :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCall>
    {
        IVoipPhoneCall(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCall(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCall2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCall2>,
        impl::require<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2, llm::OS::ApplicationModel::Calls::IVoipPhoneCall>
    {
        IVoipPhoneCall2(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCall2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVoipPhoneCall3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IVoipPhoneCall3>,
        impl::require<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3, llm::OS::ApplicationModel::Calls::IVoipPhoneCall, llm::OS::ApplicationModel::Calls::IVoipPhoneCall2>
    {
        IVoipPhoneCall3(std::nullptr_t = nullptr) noexcept {}
        IVoipPhoneCall3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
