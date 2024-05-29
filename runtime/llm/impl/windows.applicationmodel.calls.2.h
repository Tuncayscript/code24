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
#ifndef LLM_OS_ApplicationModel_Calls_2_H
#define LLM_OS_ApplicationModel_Calls_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.Calls.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls
{
    struct __declspec(empty_bases) CallAnswerEventArgs : llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs
    {
        CallAnswerEventArgs(std::nullptr_t) noexcept {}
        CallAnswerEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CallRejectEventArgs : llm::OS::ApplicationModel::Calls::ICallRejectEventArgs
    {
        CallRejectEventArgs(std::nullptr_t) noexcept {}
        CallRejectEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::ICallRejectEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CallStateChangeEventArgs : llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs
    {
        CallStateChangeEventArgs(std::nullptr_t) noexcept {}
        CallStateChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenCallEndCallDeferral : llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral
    {
        LockScreenCallEndCallDeferral(std::nullptr_t) noexcept {}
        LockScreenCallEndCallDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenCallEndRequestedEventArgs : llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs
    {
        LockScreenCallEndRequestedEventArgs(std::nullptr_t) noexcept {}
        LockScreenCallEndRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LockScreenCallUI : llm::OS::ApplicationModel::Calls::ILockScreenCallUI
    {
        LockScreenCallUI(std::nullptr_t) noexcept {}
        LockScreenCallUI(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::ILockScreenCallUI(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) MuteChangeEventArgs : llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs
    {
        MuteChangeEventArgs(std::nullptr_t) noexcept {}
        MuteChangeEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneCall : llm::OS::ApplicationModel::Calls::IPhoneCall
    {
        PhoneCall(std::nullptr_t) noexcept {}
        PhoneCall(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCall(ptr, take_ownership_from_abi) {}
        static auto GetFromId(param::hstring const& callId);
    };
    struct PhoneCallBlocking
    {
        PhoneCallBlocking() = delete;
        [[nodiscard]] static auto BlockUnknownNumbers();
        static auto BlockUnknownNumbers(bool value);
        [[nodiscard]] static auto BlockPrivateNumbers();
        static auto BlockPrivateNumbers(bool value);
        static auto SetCallBlockingListAsync(param::async_iterable<hstring> const& phoneNumberList);
    };
    struct __declspec(empty_bases) PhoneCallHistoryEntry : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry
    {
        PhoneCallHistoryEntry(std::nullptr_t) noexcept {}
        PhoneCallHistoryEntry(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry(ptr, take_ownership_from_abi) {}
        PhoneCallHistoryEntry();
    };
    struct __declspec(empty_bases) PhoneCallHistoryEntryAddress : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress
    {
        PhoneCallHistoryEntryAddress(std::nullptr_t) noexcept {}
        PhoneCallHistoryEntryAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress(ptr, take_ownership_from_abi) {}
        PhoneCallHistoryEntryAddress();
        PhoneCallHistoryEntryAddress(param::hstring const& rawAddress, llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const& rawAddressKind);
    };
    struct __declspec(empty_bases) PhoneCallHistoryEntryQueryOptions : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions
    {
        PhoneCallHistoryEntryQueryOptions(std::nullptr_t) noexcept {}
        PhoneCallHistoryEntryQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions(ptr, take_ownership_from_abi) {}
        PhoneCallHistoryEntryQueryOptions();
    };
    struct __declspec(empty_bases) PhoneCallHistoryEntryReader : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader
    {
        PhoneCallHistoryEntryReader(std::nullptr_t) noexcept {}
        PhoneCallHistoryEntryReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader(ptr, take_ownership_from_abi) {}
    };
    struct PhoneCallHistoryManager
    {
        PhoneCallHistoryManager() = delete;
        static auto RequestStoreAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const& accessType);
        static auto GetForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) PhoneCallHistoryManagerForUser : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser
    {
        PhoneCallHistoryManagerForUser(std::nullptr_t) noexcept {}
        PhoneCallHistoryManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneCallHistoryStore : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore
    {
        PhoneCallHistoryStore(std::nullptr_t) noexcept {}
        PhoneCallHistoryStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneCallInfo : llm::OS::ApplicationModel::Calls::IPhoneCallInfo
    {
        PhoneCallInfo(std::nullptr_t) noexcept {}
        PhoneCallInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallInfo(ptr, take_ownership_from_abi) {}
    };
    struct PhoneCallManager
    {
        PhoneCallManager() = delete;
        static auto ShowPhoneCallUI(param::hstring const& phoneNumber, param::hstring const& displayName);
        static auto CallStateChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        using CallStateChanged_revoker = impl::factory_event_revoker<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>::remove_CallStateChanged>;
        [[nodiscard]] static CallStateChanged_revoker CallStateChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler);
        static auto CallStateChanged(llm::event_token const& token);
        [[nodiscard]] static auto IsCallActive();
        [[nodiscard]] static auto IsCallIncoming();
        static auto ShowPhoneCallSettingsUI();
        static auto RequestStoreAsync();
    };
    struct __declspec(empty_bases) PhoneCallStore : llm::OS::ApplicationModel::Calls::IPhoneCallStore
    {
        PhoneCallStore(std::nullptr_t) noexcept {}
        PhoneCallStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneCallVideoCapabilities : llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities
    {
        PhoneCallVideoCapabilities(std::nullptr_t) noexcept {}
        PhoneCallVideoCapabilities(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities(ptr, take_ownership_from_abi) {}
    };
    struct PhoneCallVideoCapabilitiesManager
    {
        PhoneCallVideoCapabilitiesManager() = delete;
        static auto GetCapabilitiesAsync(param::hstring const& phoneNumber);
    };
    struct __declspec(empty_bases) PhoneCallsResult : llm::OS::ApplicationModel::Calls::IPhoneCallsResult
    {
        PhoneCallsResult(std::nullptr_t) noexcept {}
        PhoneCallsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneCallsResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneDialOptions : llm::OS::ApplicationModel::Calls::IPhoneDialOptions
    {
        PhoneDialOptions(std::nullptr_t) noexcept {}
        PhoneDialOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneDialOptions(ptr, take_ownership_from_abi) {}
        PhoneDialOptions();
    };
    struct __declspec(empty_bases) PhoneLine : llm::OS::ApplicationModel::Calls::IPhoneLine,
        impl::require<PhoneLine, llm::OS::ApplicationModel::Calls::IPhoneLine2, llm::OS::ApplicationModel::Calls::IPhoneLine3>
    {
        PhoneLine(std::nullptr_t) noexcept {}
        PhoneLine(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLine(ptr, take_ownership_from_abi) {}
        static auto FromIdAsync(llm::guid const& lineId);
    };
    struct __declspec(empty_bases) PhoneLineCellularDetails : llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails
    {
        PhoneLineCellularDetails(std::nullptr_t) noexcept {}
        PhoneLineCellularDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneLineConfiguration : llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration
    {
        PhoneLineConfiguration(std::nullptr_t) noexcept {}
        PhoneLineConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneLineDialResult : llm::OS::ApplicationModel::Calls::IPhoneLineDialResult
    {
        PhoneLineDialResult(std::nullptr_t) noexcept {}
        PhoneLineDialResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLineDialResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneLineTransportDevice : llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice,
        impl::require<PhoneLineTransportDevice, llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>
    {
        PhoneLineTransportDevice(std::nullptr_t) noexcept {}
        PhoneLineTransportDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice(ptr, take_ownership_from_abi) {}
        static auto FromId(param::hstring const& id);
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::ApplicationModel::Calls::PhoneLineTransport const& transport);
    };
    struct __declspec(empty_bases) PhoneLineWatcher : llm::OS::ApplicationModel::Calls::IPhoneLineWatcher
    {
        PhoneLineWatcher(std::nullptr_t) noexcept {}
        PhoneLineWatcher(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLineWatcher(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneLineWatcherEventArgs : llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs
    {
        PhoneLineWatcherEventArgs(std::nullptr_t) noexcept {}
        PhoneLineWatcherEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneVoicemail : llm::OS::ApplicationModel::Calls::IPhoneVoicemail
    {
        PhoneVoicemail(std::nullptr_t) noexcept {}
        PhoneVoicemail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IPhoneVoicemail(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VoipCallCoordinator : llm::OS::ApplicationModel::Calls::IVoipCallCoordinator,
        impl::require<VoipCallCoordinator, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>
    {
        VoipCallCoordinator(std::nullptr_t) noexcept {}
        VoipCallCoordinator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IVoipCallCoordinator(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Calls::IVoipCallCoordinator::RequestNewIncomingCall;
        using impl::consume_t<VoipCallCoordinator, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3>::RequestNewIncomingCall;
        using llm::OS::ApplicationModel::Calls::IVoipCallCoordinator::ReserveCallResourcesAsync;
        using impl::consume_t<VoipCallCoordinator, llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>::ReserveCallResourcesAsync;
        static auto GetDefault();
    };
    struct __declspec(empty_bases) VoipPhoneCall : llm::OS::ApplicationModel::Calls::IVoipPhoneCall,
        impl::require<VoipPhoneCall, llm::OS::ApplicationModel::Calls::IVoipPhoneCall2, llm::OS::ApplicationModel::Calls::IVoipPhoneCall3>
    {
        VoipPhoneCall(std::nullptr_t) noexcept {}
        VoipPhoneCall(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::IVoipPhoneCall(ptr, take_ownership_from_abi) {}
    };
}
#endif
