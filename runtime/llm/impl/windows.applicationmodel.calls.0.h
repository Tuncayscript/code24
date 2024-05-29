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
#ifndef LLM_OS_ApplicationModel_Calls_0_H
#define LLM_OS_ApplicationModel_Calls_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts
{
    struct Contact;
    struct ContactPhone;
}
LLM_EXPORT namespace llm::OS::Devices::Enumeration
{
    enum class DeviceAccessStatus : int32_t;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename K, typename V> struct __declspec(empty_bases) IMapView;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::System
{
    struct User;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls
{
    enum class CellularDtmfMode : int32_t
    {
        Continuous = 0,
        Burst = 1,
    };
    enum class DtmfKey : int32_t
    {
        D0 = 0,
        D1 = 1,
        D2 = 2,
        D3 = 3,
        D4 = 4,
        D5 = 5,
        D6 = 6,
        D7 = 7,
        D8 = 8,
        D9 = 9,
        Star = 10,
        Pound = 11,
    };
    enum class DtmfToneAudioPlayback : int32_t
    {
        Play = 0,
        DoNotPlay = 1,
    };
    enum class PhoneAudioRoutingEndpoint : int32_t
    {
        Default = 0,
        Bluetooth = 1,
        Speakerphone = 2,
    };
    enum class PhoneCallAudioDevice : int32_t
    {
        Unknown = 0,
        LocalDevice = 1,
        RemoteDevice = 2,
    };
    enum class PhoneCallDirection : int32_t
    {
        Unknown = 0,
        Incoming = 1,
        Outgoing = 2,
    };
    enum class PhoneCallHistoryEntryMedia : int32_t
    {
        Audio = 0,
        Video = 1,
    };
    enum class PhoneCallHistoryEntryOtherAppReadAccess : int32_t
    {
        Full = 0,
        SystemOnly = 1,
    };
    enum class PhoneCallHistoryEntryQueryDesiredMedia : uint32_t
    {
        None = 0,
        Audio = 0x1,
        Video = 0x2,
        All = 0xffffffff,
    };
    enum class PhoneCallHistoryEntryRawAddressKind : int32_t
    {
        PhoneNumber = 0,
        Custom = 1,
    };
    enum class PhoneCallHistorySourceIdKind : int32_t
    {
        CellularPhoneLineId = 0,
        PackageFamilyName = 1,
    };
    enum class PhoneCallHistoryStoreAccessType : int32_t
    {
        AppEntriesReadWrite = 0,
        AllEntriesLimitedReadWrite = 1,
        AllEntriesReadWrite = 2,
    };
    enum class PhoneCallMedia : int32_t
    {
        Audio = 0,
        AudioAndVideo = 1,
        AudioAndRealTimeText = 2,
    };
    enum class PhoneCallOperationStatus : int32_t
    {
        Succeeded = 0,
        OtherFailure = 1,
        TimedOut = 2,
        ConnectionLost = 3,
        InvalidCallState = 4,
    };
    enum class PhoneCallStatus : int32_t
    {
        Lost = 0,
        Incoming = 1,
        Dialing = 2,
        Talking = 3,
        Held = 4,
        Ended = 5,
    };
    enum class PhoneLineNetworkOperatorDisplayTextLocation : int32_t
    {
        Default = 0,
        Tile = 1,
        Dialer = 2,
        InCallUI = 3,
    };
    enum class PhoneLineOperationStatus : int32_t
    {
        Succeeded = 0,
        OtherFailure = 1,
        TimedOut = 2,
        ConnectionLost = 3,
        InvalidCallState = 4,
    };
    enum class PhoneLineTransport : int32_t
    {
        Cellular = 0,
        VoipApp = 1,
        Bluetooth = 2,
    };
    enum class PhoneLineWatcherStatus : int32_t
    {
        Created = 0,
        Started = 1,
        EnumerationCompleted = 2,
        Stopped = 3,
    };
    enum class PhoneNetworkState : int32_t
    {
        Unknown = 0,
        NoSignal = 1,
        Deregistered = 2,
        Denied = 3,
        Searching = 4,
        Home = 5,
        RoamingInternational = 6,
        RoamingDomestic = 7,
    };
    enum class PhoneSimState : int32_t
    {
        Unknown = 0,
        PinNotRequired = 1,
        PinUnlocked = 2,
        PinLocked = 3,
        PukLocked = 4,
        NotInserted = 5,
        Invalid = 6,
        Disabled = 7,
    };
    enum class PhoneVoicemailType : int32_t
    {
        None = 0,
        Traditional = 1,
        Visual = 2,
    };
    enum class TransportDeviceAudioRoutingStatus : int32_t
    {
        Unknown = 0,
        CanRouteToLocalDevice = 1,
        CannotRouteToLocalDevice = 2,
    };
    enum class VoipPhoneCallMedia : uint32_t
    {
        None = 0,
        Audio = 0x1,
        Video = 0x2,
    };
    enum class VoipPhoneCallRejectReason : int32_t
    {
        UserIgnored = 0,
        TimedOut = 1,
        OtherIncomingCall = 2,
        EmergencyCallExists = 3,
        InvalidCallState = 4,
    };
    enum class VoipPhoneCallResourceReservationStatus : int32_t
    {
        Success = 0,
        ResourcesNotAvailable = 1,
    };
    enum class VoipPhoneCallState : int32_t
    {
        Ended = 0,
        Held = 1,
        Active = 2,
        Incoming = 3,
        Outgoing = 4,
    };
    struct ICallAnswerEventArgs;
    struct ICallRejectEventArgs;
    struct ICallStateChangeEventArgs;
    struct ILockScreenCallEndCallDeferral;
    struct ILockScreenCallEndRequestedEventArgs;
    struct ILockScreenCallUI;
    struct IMuteChangeEventArgs;
    struct IPhoneCall;
    struct IPhoneCallBlockingStatics;
    struct IPhoneCallHistoryEntry;
    struct IPhoneCallHistoryEntryAddress;
    struct IPhoneCallHistoryEntryAddressFactory;
    struct IPhoneCallHistoryEntryQueryOptions;
    struct IPhoneCallHistoryEntryReader;
    struct IPhoneCallHistoryManagerForUser;
    struct IPhoneCallHistoryManagerStatics;
    struct IPhoneCallHistoryManagerStatics2;
    struct IPhoneCallHistoryStore;
    struct IPhoneCallInfo;
    struct IPhoneCallManagerStatics;
    struct IPhoneCallManagerStatics2;
    struct IPhoneCallStatics;
    struct IPhoneCallStore;
    struct IPhoneCallVideoCapabilities;
    struct IPhoneCallVideoCapabilitiesManagerStatics;
    struct IPhoneCallsResult;
    struct IPhoneDialOptions;
    struct IPhoneLine;
    struct IPhoneLine2;
    struct IPhoneLine3;
    struct IPhoneLineCellularDetails;
    struct IPhoneLineConfiguration;
    struct IPhoneLineDialResult;
    struct IPhoneLineStatics;
    struct IPhoneLineTransportDevice;
    struct IPhoneLineTransportDevice2;
    struct IPhoneLineTransportDeviceStatics;
    struct IPhoneLineWatcher;
    struct IPhoneLineWatcherEventArgs;
    struct IPhoneVoicemail;
    struct IVoipCallCoordinator;
    struct IVoipCallCoordinator2;
    struct IVoipCallCoordinator3;
    struct IVoipCallCoordinator4;
    struct IVoipCallCoordinatorStatics;
    struct IVoipPhoneCall;
    struct IVoipPhoneCall2;
    struct IVoipPhoneCall3;
    struct CallAnswerEventArgs;
    struct CallRejectEventArgs;
    struct CallStateChangeEventArgs;
    struct LockScreenCallEndCallDeferral;
    struct LockScreenCallEndRequestedEventArgs;
    struct LockScreenCallUI;
    struct MuteChangeEventArgs;
    struct PhoneCall;
    struct PhoneCallBlocking;
    struct PhoneCallHistoryEntry;
    struct PhoneCallHistoryEntryAddress;
    struct PhoneCallHistoryEntryQueryOptions;
    struct PhoneCallHistoryEntryReader;
    struct PhoneCallHistoryManager;
    struct PhoneCallHistoryManagerForUser;
    struct PhoneCallHistoryStore;
    struct PhoneCallInfo;
    struct PhoneCallManager;
    struct PhoneCallStore;
    struct PhoneCallVideoCapabilities;
    struct PhoneCallVideoCapabilitiesManager;
    struct PhoneCallsResult;
    struct PhoneDialOptions;
    struct PhoneLine;
    struct PhoneLineCellularDetails;
    struct PhoneLineConfiguration;
    struct PhoneLineDialResult;
    struct PhoneLineTransportDevice;
    struct PhoneLineWatcher;
    struct PhoneLineWatcherEventArgs;
    struct PhoneVoicemail;
    struct VoipCallCoordinator;
    struct VoipPhoneCall;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::ICallRejectEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::ILockScreenCallUI>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCall>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallStore>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneCallsResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneDialOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLine>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLine2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLine3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineDialResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IPhoneVoicemail>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::CallAnswerEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::CallRejectEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::LockScreenCallUI>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::MuteChangeEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCall>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallBlocking>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallStore>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilitiesManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallsResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneDialOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLine>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineWatcher>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneVoicemail>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::VoipCallCoordinator>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::VoipPhoneCall>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::CellularDtmfMode>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::DtmfKey>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallDirection>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallMedia>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneCallStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineOperationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineTransport>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneLineWatcherStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneNetworkState>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneSimState>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::PhoneVoicemailType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::TransportDeviceAudioRoutingStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::VoipPhoneCallRejectReason>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Calls::VoipPhoneCallState>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> = L"Windows.ApplicationModel.Calls.CallAnswerEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::CallRejectEventArgs> = L"Windows.ApplicationModel.Calls.CallRejectEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> = L"Windows.ApplicationModel.Calls.CallStateChangeEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral> = L"Windows.ApplicationModel.Calls.LockScreenCallEndCallDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> = L"Windows.ApplicationModel.Calls.LockScreenCallEndRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::LockScreenCallUI> = L"Windows.ApplicationModel.Calls.LockScreenCallUI";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> = L"Windows.ApplicationModel.Calls.MuteChangeEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCall> = L"Windows.ApplicationModel.Calls.PhoneCall";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallBlocking> = L"Windows.ApplicationModel.Calls.PhoneCallBlocking";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntry";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryAddress";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryReader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManager> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryManagerForUser";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallInfo> = L"Windows.ApplicationModel.Calls.PhoneCallInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallManager> = L"Windows.ApplicationModel.Calls.PhoneCallManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallStore> = L"Windows.ApplicationModel.Calls.PhoneCallStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities> = L"Windows.ApplicationModel.Calls.PhoneCallVideoCapabilities";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilitiesManager> = L"Windows.ApplicationModel.Calls.PhoneCallVideoCapabilitiesManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallsResult> = L"Windows.ApplicationModel.Calls.PhoneCallsResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneDialOptions> = L"Windows.ApplicationModel.Calls.PhoneDialOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLine> = L"Windows.ApplicationModel.Calls.PhoneLine";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails> = L"Windows.ApplicationModel.Calls.PhoneLineCellularDetails";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineConfiguration> = L"Windows.ApplicationModel.Calls.PhoneLineConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineDialResult> = L"Windows.ApplicationModel.Calls.PhoneLineDialResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice> = L"Windows.ApplicationModel.Calls.PhoneLineTransportDevice";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineWatcher> = L"Windows.ApplicationModel.Calls.PhoneLineWatcher";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> = L"Windows.ApplicationModel.Calls.PhoneLineWatcherEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneVoicemail> = L"Windows.ApplicationModel.Calls.PhoneVoicemail";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::VoipCallCoordinator> = L"Windows.ApplicationModel.Calls.VoipCallCoordinator";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::VoipPhoneCall> = L"Windows.ApplicationModel.Calls.VoipPhoneCall";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::CellularDtmfMode> = L"Windows.ApplicationModel.Calls.CellularDtmfMode";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::DtmfKey> = L"Windows.ApplicationModel.Calls.DtmfKey";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback> = L"Windows.ApplicationModel.Calls.DtmfToneAudioPlayback";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint> = L"Windows.ApplicationModel.Calls.PhoneAudioRoutingEndpoint";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice> = L"Windows.ApplicationModel.Calls.PhoneCallAudioDevice";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallDirection> = L"Windows.ApplicationModel.Calls.PhoneCallDirection";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryMedia";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryOtherAppReadAccess";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryQueryDesiredMedia";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryEntryRawAddressKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind> = L"Windows.ApplicationModel.Calls.PhoneCallHistorySourceIdKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType> = L"Windows.ApplicationModel.Calls.PhoneCallHistoryStoreAccessType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallMedia> = L"Windows.ApplicationModel.Calls.PhoneCallMedia";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus> = L"Windows.ApplicationModel.Calls.PhoneCallOperationStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneCallStatus> = L"Windows.ApplicationModel.Calls.PhoneCallStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation> = L"Windows.ApplicationModel.Calls.PhoneLineNetworkOperatorDisplayTextLocation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineOperationStatus> = L"Windows.ApplicationModel.Calls.PhoneLineOperationStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineTransport> = L"Windows.ApplicationModel.Calls.PhoneLineTransport";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneLineWatcherStatus> = L"Windows.ApplicationModel.Calls.PhoneLineWatcherStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneNetworkState> = L"Windows.ApplicationModel.Calls.PhoneNetworkState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneSimState> = L"Windows.ApplicationModel.Calls.PhoneSimState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::PhoneVoicemailType> = L"Windows.ApplicationModel.Calls.PhoneVoicemailType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::TransportDeviceAudioRoutingStatus> = L"Windows.ApplicationModel.Calls.TransportDeviceAudioRoutingStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia> = L"Windows.ApplicationModel.Calls.VoipPhoneCallMedia";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::VoipPhoneCallRejectReason> = L"Windows.ApplicationModel.Calls.VoipPhoneCallRejectReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus> = L"Windows.ApplicationModel.Calls.VoipPhoneCallResourceReservationStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::VoipPhoneCallState> = L"Windows.ApplicationModel.Calls.VoipPhoneCallState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs> = L"Windows.ApplicationModel.Calls.ICallAnswerEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::ICallRejectEventArgs> = L"Windows.ApplicationModel.Calls.ICallRejectEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs> = L"Windows.ApplicationModel.Calls.ICallStateChangeEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral> = L"Windows.ApplicationModel.Calls.ILockScreenCallEndCallDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs> = L"Windows.ApplicationModel.Calls.ILockScreenCallEndRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::ILockScreenCallUI> = L"Windows.ApplicationModel.Calls.ILockScreenCallUI";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs> = L"Windows.ApplicationModel.Calls.IMuteChangeEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCall> = L"Windows.ApplicationModel.Calls.IPhoneCall";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics> = L"Windows.ApplicationModel.Calls.IPhoneCallBlockingStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryEntry";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryEntryAddress";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryEntryAddressFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryEntryQueryOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryEntryReader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryManagerForUser";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryManagerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore> = L"Windows.ApplicationModel.Calls.IPhoneCallHistoryStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallInfo> = L"Windows.ApplicationModel.Calls.IPhoneCallInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics> = L"Windows.ApplicationModel.Calls.IPhoneCallManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2> = L"Windows.ApplicationModel.Calls.IPhoneCallManagerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallStatics> = L"Windows.ApplicationModel.Calls.IPhoneCallStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallStore> = L"Windows.ApplicationModel.Calls.IPhoneCallStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities> = L"Windows.ApplicationModel.Calls.IPhoneCallVideoCapabilities";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics> = L"Windows.ApplicationModel.Calls.IPhoneCallVideoCapabilitiesManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneCallsResult> = L"Windows.ApplicationModel.Calls.IPhoneCallsResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneDialOptions> = L"Windows.ApplicationModel.Calls.IPhoneDialOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLine> = L"Windows.ApplicationModel.Calls.IPhoneLine";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLine2> = L"Windows.ApplicationModel.Calls.IPhoneLine2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLine3> = L"Windows.ApplicationModel.Calls.IPhoneLine3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails> = L"Windows.ApplicationModel.Calls.IPhoneLineCellularDetails";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration> = L"Windows.ApplicationModel.Calls.IPhoneLineConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineDialResult> = L"Windows.ApplicationModel.Calls.IPhoneLineDialResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineStatics> = L"Windows.ApplicationModel.Calls.IPhoneLineStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice> = L"Windows.ApplicationModel.Calls.IPhoneLineTransportDevice";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2> = L"Windows.ApplicationModel.Calls.IPhoneLineTransportDevice2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics> = L"Windows.ApplicationModel.Calls.IPhoneLineTransportDeviceStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher> = L"Windows.ApplicationModel.Calls.IPhoneLineWatcher";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs> = L"Windows.ApplicationModel.Calls.IPhoneLineWatcherEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IPhoneVoicemail> = L"Windows.ApplicationModel.Calls.IPhoneVoicemail";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator> = L"Windows.ApplicationModel.Calls.IVoipCallCoordinator";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2> = L"Windows.ApplicationModel.Calls.IVoipCallCoordinator2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3> = L"Windows.ApplicationModel.Calls.IVoipCallCoordinator3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4> = L"Windows.ApplicationModel.Calls.IVoipCallCoordinator4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics> = L"Windows.ApplicationModel.Calls.IVoipCallCoordinatorStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipPhoneCall> = L"Windows.ApplicationModel.Calls.IVoipPhoneCall";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2> = L"Windows.ApplicationModel.Calls.IVoipPhoneCall2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3> = L"Windows.ApplicationModel.Calls.IVoipPhoneCall3";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs>{ 0xFD789617,0x2DD7,0x4C8C,{ 0xB2,0xBD,0x95,0xD1,0x7A,0x5B,0xB7,0x33 } }; // FD789617-2DD7-4C8C-B2BD-95D17A5BB733
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::ICallRejectEventArgs>{ 0xDA47FAD7,0x13D4,0x4D92,{ 0xA1,0xC2,0xB7,0x78,0x11,0xEE,0x37,0xEC } }; // DA47FAD7-13D4-4D92-A1C2-B77811EE37EC
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs>{ 0xEAB2349E,0x66F5,0x47F9,{ 0x9F,0xB5,0x45,0x9C,0x51,0x98,0xC7,0x20 } }; // EAB2349E-66F5-47F9-9FB5-459C5198C720
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>{ 0x2DD7ED0D,0x98ED,0x4041,{ 0x96,0x32,0x50,0xFF,0x81,0x2B,0x77,0x3F } }; // 2DD7ED0D-98ED-4041-9632-50FF812B773F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>{ 0x8190A363,0x6F27,0x46E9,{ 0xAE,0xB6,0xC0,0xAE,0x83,0xE4,0x7D,0xC7 } }; // 8190A363-6F27-46E9-AEB6-C0AE83E47DC7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::ILockScreenCallUI>{ 0xC596FD8D,0x73C9,0x4A14,{ 0xB0,0x21,0xEC,0x1C,0x50,0xA3,0xB7,0x27 } }; // C596FD8D-73C9-4A14-B021-EC1C50A3B727
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs>{ 0x8585E159,0x0C41,0x432C,{ 0x81,0x4D,0xC5,0xF1,0xFD,0xF5,0x30,0xBE } }; // 8585E159-0C41-432C-814D-C5F1FDF530BE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCall>{ 0xC14ED0F8,0xC17D,0x59D2,{ 0x96,0x28,0x66,0xE5,0x45,0xB6,0xCD,0x21 } }; // C14ED0F8-C17D-59D2-9628-66E545B6CD21
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics>{ 0x19646F84,0x2B79,0x26F1,{ 0xA4,0x6F,0x69,0x4B,0xE0,0x43,0xF3,0x13 } }; // 19646F84-2B79-26F1-A46F-694BE043F313
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry>{ 0xFAB0E129,0x32A4,0x4B85,{ 0x83,0xD1,0xF9,0x0D,0x8C,0x23,0xA8,0x57 } }; // FAB0E129-32A4-4B85-83D1-F90D8C23A857
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>{ 0x30F159DA,0x3955,0x4042,{ 0x84,0xE6,0x66,0xEE,0xBF,0x82,0xE6,0x7F } }; // 30F159DA-3955-4042-84E6-66EEBF82E67F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>{ 0xFB0FADBA,0xC7F0,0x4BB6,{ 0x9F,0x6B,0xBA,0x5D,0x73,0x20,0x9A,0xCA } }; // FB0FADBA-C7F0-4BB6-9F6B-BA5D73209ACA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>{ 0x9C5FE15C,0x8BED,0x40CA,{ 0xB0,0x6E,0xC4,0xCA,0x8E,0xAE,0x5C,0x87 } }; // 9C5FE15C-8BED-40CA-B06E-C4CA8EAE5C87
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>{ 0x61ECE4BE,0x8D86,0x479F,{ 0x84,0x04,0xA9,0x84,0x69,0x20,0xFE,0xE6 } }; // 61ECE4BE-8D86-479F-8404-A9846920FEE6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>{ 0xD925C523,0xF55F,0x4353,{ 0x9D,0xB4,0x02,0x05,0xA5,0x26,0x5A,0x55 } }; // D925C523-F55F-4353-9DB4-0205A5265A55
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>{ 0xF5A6DA39,0xB31F,0x4F45,{ 0xAC,0x8E,0x1B,0x08,0x89,0x3C,0x1B,0x50 } }; // F5A6DA39-B31F-4F45-AC8E-1B08893C1B50
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>{ 0xEFD474F0,0xA2DB,0x4188,{ 0x9E,0x92,0xBC,0x3C,0xFA,0x68,0x13,0xCF } }; // EFD474F0-A2DB-4188-9E92-BC3CFA6813CF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore>{ 0x2F907DB8,0xB40E,0x422B,{ 0x85,0x45,0xCB,0x19,0x10,0xA6,0x1C,0x52 } }; // 2F907DB8-B40E-422B-8545-CB1910A61C52
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallInfo>{ 0x22B42577,0x3E4D,0x5DC6,{ 0x89,0xC2,0x46,0x9F,0xE5,0xFF,0xC1,0x89 } }; // 22B42577-3E4D-5DC6-89C2-469FE5FFC189
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics>{ 0x60EDAC78,0x78A6,0x4872,{ 0xA3,0xEF,0x98,0x32,0x5E,0xC8,0xB8,0x43 } }; // 60EDAC78-78A6-4872-A3EF-98325EC8B843
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>{ 0xC7E3C8BC,0x2370,0x431C,{ 0x98,0xFD,0x43,0xBE,0x5F,0x03,0x08,0x6D } }; // C7E3C8BC-2370-431C-98FD-43BE5F03086D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallStatics>{ 0x2218EEAB,0xF60B,0x53E7,{ 0xBA,0x13,0x5A,0xEA,0xFB,0xC2,0x29,0x57 } }; // 2218EEAB-F60B-53E7-BA13-5AEAFBC22957
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallStore>{ 0x5F610748,0x18A6,0x4173,{ 0x86,0xD1,0x28,0xBE,0x9D,0xC6,0x2D,0xBA } }; // 5F610748-18A6-4173-86D1-28BE9DC62DBA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities>{ 0x02382786,0xB16A,0x4FDB,{ 0xBE,0x3B,0xC4,0x24,0x0E,0x13,0xAD,0x0D } }; // 02382786-B16A-4FDB-BE3B-C4240E13AD0D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>{ 0xF3C64B56,0xF00B,0x4A1C,{ 0xA0,0xC6,0xEE,0x19,0x10,0x74,0x9C,0xE7 } }; // F3C64B56-F00B-4A1C-A0C6-EE1910749CE7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneCallsResult>{ 0x1BFAD365,0x57CF,0x57DD,{ 0x98,0x6D,0xB0,0x57,0xC9,0x1E,0xAC,0x33 } }; // 1BFAD365-57CF-57DD-986D-B057C91EAC33
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneDialOptions>{ 0xB639C4B8,0xF06F,0x36CB,{ 0xA8,0x63,0x82,0x37,0x42,0xB5,0xF2,0xD4 } }; // B639C4B8-F06F-36CB-A863-823742B5F2D4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLine>{ 0x27C66F30,0x6A69,0x34CA,{ 0xA2,0xBA,0x65,0x30,0x25,0x30,0xC3,0x11 } }; // 27C66F30-6A69-34CA-A2BA-65302530C311
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLine2>{ 0x0167F56A,0x5344,0x5D64,{ 0x8A,0xF3,0xA3,0x1A,0x95,0x0E,0x91,0x6A } }; // 0167F56A-5344-5D64-8AF3-A31A950E916A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLine3>{ 0xE2E33CF7,0x2406,0x57F3,{ 0x82,0x6A,0xE5,0xA5,0xF4,0x0D,0x6F,0xB5 } }; // E2E33CF7-2406-57F3-826A-E5A5F40D6FB5
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails>{ 0x192601D5,0x147C,0x4769,{ 0xB6,0x73,0x98,0xA5,0xEC,0x84,0x26,0xCB } }; // 192601D5-147C-4769-B673-98A5EC8426CB
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration>{ 0xFE265862,0xF64F,0x4312,{ 0xB2,0xA8,0x4E,0x25,0x77,0x21,0xAA,0x95 } }; // FE265862-F64F-4312-B2A8-4E257721AA95
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineDialResult>{ 0xE825A30A,0x5C7F,0x546F,{ 0xB9,0x18,0x3A,0xD2,0xFE,0x70,0xFB,0x34 } }; // E825A30A-5C7F-546F-B918-3AD2FE70FB34
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineStatics>{ 0xF38B5F23,0xCEB0,0x404F,{ 0xBC,0xF2,0xBA,0x9F,0x69,0x7D,0x8A,0xDF } }; // F38B5F23-CEB0-404F-BCF2-BA9F697D8ADF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice>{ 0xEFA8F889,0xCFFA,0x59F4,{ 0x97,0xE4,0x74,0x70,0x5B,0x7D,0xC4,0x90 } }; // EFA8F889-CFFA-59F4-97E4-74705B7DC490
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>{ 0x64C885F2,0xECF4,0x5761,{ 0x8C,0x04,0x3C,0x24,0x8C,0xE6,0x16,0x90 } }; // 64C885F2-ECF4-5761-8C04-3C248CE61690
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics>{ 0x0F3121AC,0xD609,0x51A1,{ 0x96,0xF3,0xFB,0x00,0xD1,0x81,0x92,0x52 } }; // 0F3121AC-D609-51A1-96F3-FB00D1819252
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>{ 0x8A45CD0A,0x6323,0x44E0,{ 0xA6,0xF6,0x9F,0x21,0xF6,0x4D,0xC9,0x0A } }; // 8A45CD0A-6323-44E0-A6F6-9F21F64DC90A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>{ 0xD07C753E,0x9E12,0x4A37,{ 0x82,0xB7,0xAD,0x53,0x5D,0xAD,0x6A,0x67 } }; // D07C753E-9E12-4A37-82B7-AD535DAD6A67
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IPhoneVoicemail>{ 0xC9CE77F6,0x6E9F,0x3A8B,{ 0xB7,0x27,0x6E,0x0C,0xF6,0x99,0x82,0x24 } }; // C9CE77F6-6E9F-3A8B-B727-6E0CF6998224
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>{ 0x4F118BCF,0xE8EF,0x4434,{ 0x9C,0x5F,0xA8,0xD8,0x93,0xFA,0xFE,0x79 } }; // 4F118BCF-E8EF-4434-9C5F-A8D893FAFE79
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2>{ 0xBEB4A9F3,0xC704,0x4234,{ 0x89,0xCE,0xE8,0x8C,0xC0,0xD2,0x8F,0xBE } }; // BEB4A9F3-C704-4234-89CE-E88CC0D28FBE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3>{ 0x338D0CBF,0x9B55,0x4021,{ 0x87,0xCA,0xE6,0x4B,0x9B,0xD6,0x66,0xC7 } }; // 338D0CBF-9B55-4021-87CA-E64B9BD666C7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>{ 0x83737239,0x9311,0x468F,{ 0xBB,0x49,0x47,0xE0,0xDF,0xB5,0xD9,0x3E } }; // 83737239-9311-468F-BB49-47E0DFB5D93E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics>{ 0x7F5D1F2B,0xE04A,0x4D10,{ 0xB3,0x1A,0xA5,0x5C,0x92,0x2C,0xC2,0xFB } }; // 7F5D1F2B-E04A-4D10-B31A-A55C922CC2FB
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>{ 0x6CF1F19A,0x7794,0x4A5A,{ 0x8C,0x68,0xAE,0x87,0x94,0x7A,0x69,0x90 } }; // 6CF1F19A-7794-4A5A-8C68-AE87947A6990
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2>{ 0x741B46E1,0x245F,0x41F3,{ 0x93,0x99,0x31,0x41,0xD2,0x5B,0x52,0xE3 } }; // 741B46E1-245F-41F3-9399-3141D25B52E3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3>{ 0x0D891522,0xE258,0x4AA9,{ 0x90,0x7A,0x1A,0xA4,0x13,0xC2,0x55,0x23 } }; // 0D891522-E258-4AA9-907A-1AA413C25523
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::CallAnswerEventArgs>{ using type = llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::CallRejectEventArgs>{ using type = llm::OS::ApplicationModel::Calls::ICallRejectEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs>{ using type = llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral>{ using type = llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs>{ using type = llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::LockScreenCallUI>{ using type = llm::OS::ApplicationModel::Calls::ILockScreenCallUI; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::MuteChangeEventArgs>{ using type = llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCall>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCall; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallInfo>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallStore>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallStore; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneCallsResult>{ using type = llm::OS::ApplicationModel::Calls::IPhoneCallsResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneDialOptions>{ using type = llm::OS::ApplicationModel::Calls::IPhoneDialOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLine>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLine; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLineConfiguration>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLineDialResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLineWatcher>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLineWatcher; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs>{ using type = llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::PhoneVoicemail>{ using type = llm::OS::ApplicationModel::Calls::IPhoneVoicemail; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::VoipCallCoordinator>{ using type = llm::OS::ApplicationModel::Calls::IVoipCallCoordinator; };
    template <> struct default_interface<llm::OS::ApplicationModel::Calls::VoipPhoneCall>{ using type = llm::OS::ApplicationModel::Calls::IVoipPhoneCall; };
    template <> struct abi<llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AcceptedMedia(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::ICallRejectEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RejectReason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::ILockScreenCallUI>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Dismiss() noexcept = 0;
            virtual int32_t __stdcall add_EndRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EndRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Closed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closed(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_CallTitle(void**) noexcept = 0;
            virtual int32_t __stdcall put_CallTitle(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Muted(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCall>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_StatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AudioDeviceChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AudioDeviceChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_IsMutedChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_IsMutedChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_CallId(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsMuted(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AudioDevice(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetPhoneCallInfo(void**) noexcept = 0;
            virtual int32_t __stdcall GetPhoneCallInfoAsync(void**) noexcept = 0;
            virtual int32_t __stdcall End(int32_t*) noexcept = 0;
            virtual int32_t __stdcall EndAsync(void**) noexcept = 0;
            virtual int32_t __stdcall SendDtmfKey(int32_t, int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall SendDtmfKeyAsync(int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall AcceptIncoming(int32_t*) noexcept = 0;
            virtual int32_t __stdcall AcceptIncomingAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Hold(int32_t*) noexcept = 0;
            virtual int32_t __stdcall HoldAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ResumeFromHold(int32_t*) noexcept = 0;
            virtual int32_t __stdcall ResumeFromHoldAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Mute(int32_t*) noexcept = 0;
            virtual int32_t __stdcall MuteAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Unmute(int32_t*) noexcept = 0;
            virtual int32_t __stdcall UnmuteAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RejectIncoming(int32_t*) noexcept = 0;
            virtual int32_t __stdcall RejectIncomingAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ChangeAudioDevice(int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall ChangeAudioDeviceAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_BlockUnknownNumbers(bool*) noexcept = 0;
            virtual int32_t __stdcall put_BlockUnknownNumbers(bool) noexcept = 0;
            virtual int32_t __stdcall get_BlockPrivateNumbers(bool*) noexcept = 0;
            virtual int32_t __stdcall put_BlockPrivateNumbers(bool) noexcept = 0;
            virtual int32_t __stdcall SetCallBlockingListAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_Address(void**) noexcept = 0;
            virtual int32_t __stdcall put_Address(void*) noexcept = 0;
            virtual int32_t __stdcall get_Duration(void**) noexcept = 0;
            virtual int32_t __stdcall put_Duration(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsCallerIdBlocked(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsCallerIdBlocked(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsEmergency(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEmergency(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsIncoming(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsIncoming(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsMissed(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsMissed(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsRinging(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsRinging(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsSeen(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSeen(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsSuppressed(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSuppressed(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsVoicemail(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsVoicemail(bool) noexcept = 0;
            virtual int32_t __stdcall get_Media(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Media(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_OtherAppReadAccess(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_OtherAppReadAccess(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_RemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall put_RemoteId(void*) noexcept = 0;
            virtual int32_t __stdcall get_SourceDisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_SourceId(void**) noexcept = 0;
            virtual int32_t __stdcall put_SourceId(void*) noexcept = 0;
            virtual int32_t __stdcall get_SourceIdKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SourceIdKind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_StartTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_StartTime(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContactId(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContactId(void*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_RawAddress(void**) noexcept = 0;
            virtual int32_t __stdcall put_RawAddress(void*) noexcept = 0;
            virtual int32_t __stdcall get_RawAddressKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_RawAddressKind(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesiredMedia(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredMedia(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_SourceIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ReadBatchAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestStoreAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestStoreAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetEntryAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetEntryReader(void**) noexcept = 0;
            virtual int32_t __stdcall GetEntryReaderWithOptions(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SaveEntryAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteEntryAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteEntriesAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall MarkEntryAsSeenAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall MarkEntriesAsSeenAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetUnseenCountAsync(void**) noexcept = 0;
            virtual int32_t __stdcall MarkAllAsSeenAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetSourcesUnseenCountAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall MarkSourcesAsSeenAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LineId(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_IsHoldSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_StartTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PhoneNumber(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_CallDirection(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ShowPhoneCallUI(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_CallStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CallStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_IsCallActive(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsCallIncoming(bool*) noexcept = 0;
            virtual int32_t __stdcall ShowPhoneCallSettingsUI() noexcept = 0;
            virtual int32_t __stdcall RequestStoreAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetFromId(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallStore>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsEmergencyPhoneNumberAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDefaultLineAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestLineWatcher(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsVideoCallingCapable(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetCapabilitiesAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneCallsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AllActivePhoneCalls(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneDialOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Number(void**) noexcept = 0;
            virtual int32_t __stdcall put_Number(void*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_Contact(void**) noexcept = 0;
            virtual int32_t __stdcall put_Contact(void*) noexcept = 0;
            virtual int32_t __stdcall get_ContactPhone(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContactPhone(void*) noexcept = 0;
            virtual int32_t __stdcall get_Media(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Media(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_AudioEndpoint(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AudioEndpoint(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLine>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_LineChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LineChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Id(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayColor(struct struct_Windows_UI_Color*) noexcept = 0;
            virtual int32_t __stdcall get_NetworkState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Voicemail(void**) noexcept = 0;
            virtual int32_t __stdcall get_NetworkName(void**) noexcept = 0;
            virtual int32_t __stdcall get_CellularDetails(void**) noexcept = 0;
            virtual int32_t __stdcall get_Transport(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_CanDial(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportsTile(bool*) noexcept = 0;
            virtual int32_t __stdcall get_VideoCallingCapabilities(void**) noexcept = 0;
            virtual int32_t __stdcall get_LineConfiguration(void**) noexcept = 0;
            virtual int32_t __stdcall IsImmediateDialNumberAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall Dial(void*, void*) noexcept = 0;
            virtual int32_t __stdcall DialWithOptions(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLine2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall EnableTextReply(bool) noexcept = 0;
            virtual int32_t __stdcall get_TransportDeviceId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLine3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall DialWithResult(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall DialWithResultAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAllActivePhoneCalls(void**) noexcept = 0;
            virtual int32_t __stdcall GetAllActivePhoneCallsAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SimState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SimSlotIndex(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsModemOn(bool*) noexcept = 0;
            virtual int32_t __stdcall get_RegistrationRejectCode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetNetworkOperatorDisplayText(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsVideoCallingEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedProperties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineDialResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DialCallStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DialedCall(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromIdAsync(llm::guid, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Transport(int32_t*) noexcept = 0;
            virtual int32_t __stdcall RequestAccessAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RegisterApp() noexcept = 0;
            virtual int32_t __stdcall RegisterAppForUser(void*) noexcept = 0;
            virtual int32_t __stdcall UnregisterApp() noexcept = 0;
            virtual int32_t __stdcall UnregisterAppForUser(void*) noexcept = 0;
            virtual int32_t __stdcall IsRegistered(bool*) noexcept = 0;
            virtual int32_t __stdcall Connect(bool*) noexcept = 0;
            virtual int32_t __stdcall ConnectAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AudioRoutingStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall add_AudioRoutingStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AudioRoutingStatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_InBandRingingEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall add_InBandRingingEnabledChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_InBandRingingEnabledChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelectorForPhoneLineTransport(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall Stop() noexcept = 0;
            virtual int32_t __stdcall add_LineAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LineAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_LineRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LineRemoved(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_LineUpdated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LineUpdated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_EnumerationCompleted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EnumerationCompleted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Stopped(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Stopped(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LineId(llm::guid*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IPhoneVoicemail>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Number(void**) noexcept = 0;
            virtual int32_t __stdcall get_MessageCount(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall DialVoicemailAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ReserveCallResourcesAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall add_MuteStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_MuteStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall RequestNewIncomingCall(void*, void*, void*, void*, void*, void*, void*, void*, uint32_t, int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestNewOutgoingCall(void*, void*, void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall NotifyMuted() noexcept = 0;
            virtual int32_t __stdcall NotifyUnmuted() noexcept = 0;
            virtual int32_t __stdcall RequestOutgoingUpgradeToVideoCall(llm::guid, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestIncomingUpgradeToVideoCall(void*, void*, void*, void*, void*, void*, void*, void*, int64_t, void**) noexcept = 0;
            virtual int32_t __stdcall TerminateCellularCall(llm::guid) noexcept = 0;
            virtual int32_t __stdcall CancelUpgrade(llm::guid) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetupNewAcceptedCall(void*, void*, void*, void*, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestNewAppInitiatedCall(void*, void*, void*, void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestNewIncomingCallWithContactRemoteId(void*, void*, void*, void*, void*, void*, void*, void*, uint32_t, int64_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ReserveOneProcessCallResourcesAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_EndRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_EndRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_HoldRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_HoldRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ResumeRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ResumeRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_AnswerRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AnswerRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_RejectRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_RejectRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall NotifyCallHeld() noexcept = 0;
            virtual int32_t __stdcall NotifyCallActive() noexcept = 0;
            virtual int32_t __stdcall NotifyCallEnded() noexcept = 0;
            virtual int32_t __stdcall get_ContactName(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContactName(void*) noexcept = 0;
            virtual int32_t __stdcall get_StartTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_StartTime(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_CallMedia(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CallMedia(uint32_t) noexcept = 0;
            virtual int32_t __stdcall NotifyCallReady() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryShowAppUI() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall NotifyCallAccepted(uint32_t) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_ICallAnswerEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia) AcceptedMedia() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::ICallAnswerEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_ICallAnswerEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_ICallRejectEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallRejectReason) RejectReason() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::ICallRejectEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_ICallRejectEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_ICallStateChangeEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallState) State() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::ICallStateChangeEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_ICallStateChangeEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_ILockScreenCallEndCallDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::ILockScreenCallEndCallDeferral>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_ILockScreenCallEndCallDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_ILockScreenCallEndRequestedEventArgs
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::LockScreenCallEndCallDeferral) GetDeferral() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Deadline() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::ILockScreenCallEndRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_ILockScreenCallEndRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_ILockScreenCallUI
    {
        LLM_IMPL_AUTO(void) Dismiss() const;
        LLM_IMPL_AUTO(llm::event_token) EndRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> const& handler) const;
        using EndRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::ILockScreenCallUI, &impl::abi_t<llm::OS::ApplicationModel::Calls::ILockScreenCallUI>::remove_EndRequested>;
        [[nodiscard]] EndRequested_revoker EndRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::ApplicationModel::Calls::LockScreenCallEndRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) EndRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Closed(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::Foundation::IInspectable> const& handler) const;
        using Closed_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::ILockScreenCallUI, &impl::abi_t<llm::OS::ApplicationModel::Calls::ILockScreenCallUI>::remove_Closed>;
        [[nodiscard]] Closed_revoker Closed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::LockScreenCallUI, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Closed(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CallTitle() const;
        LLM_IMPL_AUTO(void) CallTitle(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::ILockScreenCallUI>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_ILockScreenCallUI<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IMuteChangeEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Muted() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IMuteChangeEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IMuteChangeEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCall
    {
        LLM_IMPL_AUTO(llm::event_token) StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const;
        using StatusChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneCall>::remove_StatusChanged>;
        [[nodiscard]] StatusChanged_revoker StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) StatusChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AudioDeviceChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const;
        using AudioDeviceChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneCall>::remove_AudioDeviceChanged>;
        [[nodiscard]] AudioDeviceChanged_revoker AudioDeviceChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AudioDeviceChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) IsMutedChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const;
        using IsMutedChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneCall>::remove_IsMutedChanged>;
        [[nodiscard]] IsMutedChanged_revoker IsMutedChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneCall, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) IsMutedChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CallId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMuted() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice) AudioDevice() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallInfo) GetPhoneCallInfo() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallInfo>) GetPhoneCallInfoAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) End() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) EndAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) SendDtmfKey(llm::OS::ApplicationModel::Calls::DtmfKey const& key, llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback const& dtmfToneAudioPlayback) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) SendDtmfKeyAsync(llm::OS::ApplicationModel::Calls::DtmfKey const& key, llm::OS::ApplicationModel::Calls::DtmfToneAudioPlayback const& dtmfToneAudioPlayback) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) AcceptIncoming() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) AcceptIncomingAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) Hold() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) HoldAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) ResumeFromHold() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) ResumeFromHoldAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) Mute() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) MuteAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) Unmute() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) UnmuteAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) RejectIncoming() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) RejectIncomingAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) ChangeAudioDevice(llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice const& endpoint) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus>) ChangeAudioDeviceAsync(llm::OS::ApplicationModel::Calls::PhoneCallAudioDevice const& endpoint) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCall>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCall<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) BlockUnknownNumbers() const;
        LLM_IMPL_AUTO(void) BlockUnknownNumbers(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) BlockPrivateNumbers() const;
        LLM_IMPL_AUTO(void) BlockPrivateNumbers(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) SetCallBlockingListAsync(param::async_iterable<hstring> const& phoneNumberList) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallBlockingStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallBlockingStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress) Address() const;
        LLM_IMPL_AUTO(void) Address(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) Duration() const;
        LLM_IMPL_AUTO(void) Duration(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCallerIdBlocked() const;
        LLM_IMPL_AUTO(void) IsCallerIdBlocked(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEmergency() const;
        LLM_IMPL_AUTO(void) IsEmergency(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsIncoming() const;
        LLM_IMPL_AUTO(void) IsIncoming(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMissed() const;
        LLM_IMPL_AUTO(void) IsMissed(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRinging() const;
        LLM_IMPL_AUTO(void) IsRinging(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSeen() const;
        LLM_IMPL_AUTO(void) IsSeen(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSuppressed() const;
        LLM_IMPL_AUTO(void) IsSuppressed(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVoicemail() const;
        LLM_IMPL_AUTO(void) IsVoicemail(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia) Media() const;
        LLM_IMPL_AUTO(void) Media(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryMedia const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess) OtherAppReadAccess() const;
        LLM_IMPL_AUTO(void) OtherAppReadAccess(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryOtherAppReadAccess const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemoteId() const;
        LLM_IMPL_AUTO(void) RemoteId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourceDisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourceId() const;
        LLM_IMPL_AUTO(void) SourceId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind) SourceIdKind() const;
        LLM_IMPL_AUTO(void) SourceIdKind(llm::OS::ApplicationModel::Calls::PhoneCallHistorySourceIdKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) StartTime() const;
        LLM_IMPL_AUTO(void) StartTime(llm::OS::Foundation::DateTime const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntry>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntry<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContactId() const;
        LLM_IMPL_AUTO(void) ContactId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RawAddress() const;
        LLM_IMPL_AUTO(void) RawAddress(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind) RawAddressKind() const;
        LLM_IMPL_AUTO(void) RawAddressKind(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddress>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddress<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddressFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryAddress) Create(param::hstring const& rawAddress, llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryRawAddressKind const& rawAddressKind) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryAddressFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryAddressFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryQueryOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia) DesiredMedia() const;
        LLM_IMPL_AUTO(void) DesiredMedia(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryDesiredMedia const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) SourceIds() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryQueryOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryQueryOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryReader
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>>) ReadBatchAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryEntryReader>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryEntryReader<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerForUser
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>) RequestStoreAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const& accessType) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::User) User() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerForUser>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerForUser<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryStore>) RequestStoreAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryStoreAccessType const& accessType) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryManagerForUser) GetForUser(llm::OS::System::User const& user) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry>) GetEntryAsync(param::hstring const& callHistoryEntryId) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader) GetEntryReader() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryReader) GetEntryReader(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntryQueryOptions const& queryOptions) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SaveEntryAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const& callHistoryEntry) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteEntryAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const& callHistoryEntry) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteEntriesAsync(param::async_iterable<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> const& callHistoryEntries) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) MarkEntryAsSeenAsync(llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry const& callHistoryEntry) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) MarkEntriesAsSeenAsync(param::async_iterable<llm::OS::ApplicationModel::Calls::PhoneCallHistoryEntry> const& callHistoryEntries) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) GetUnseenCountAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) MarkAllAsSeenAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) GetSourcesUnseenCountAsync(param::async_iterable<hstring> const& sourceIds) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) MarkSourcesAsSeenAsync(param::async_iterable<hstring> const& sourceIds) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallHistoryStore>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallHistoryStore<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) LineId() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsHoldSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) StartTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PhoneNumber() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallDirection) CallDirection() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics
    {
        LLM_IMPL_AUTO(void) ShowPhoneCallUI(param::hstring const& phoneNumber, param::hstring const& displayName) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2
    {
        LLM_IMPL_AUTO(llm::event_token) CallStateChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        using CallStateChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>::remove_CallStateChanged>;
        [[nodiscard]] CallStateChanged_revoker CallStateChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) CallStateChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCallActive() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsCallIncoming() const;
        LLM_IMPL_AUTO(void) ShowPhoneCallSettingsUI() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallStore>) RequestStoreAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCall) GetFromId(param::hstring const& callId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallStore
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) IsEmergencyPhoneNumberAsync(param::hstring const& number) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::guid>) GetDefaultLineAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineWatcher) RequestLineWatcher() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallStore>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallStore<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallVideoCapabilities
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVideoCallingCapable() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilities>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallVideoCapabilities<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallVideoCapabilitiesManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities>) GetCapabilitiesAsync(param::hstring const& phoneNumber) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallVideoCapabilitiesManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallVideoCapabilitiesManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneCallsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineOperationStatus) OperationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Calls::PhoneCall>) AllActivePhoneCalls() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneCallsResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneCallsResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneDialOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Number() const;
        LLM_IMPL_AUTO(void) Number(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) Contact() const;
        LLM_IMPL_AUTO(void) Contact(llm::OS::ApplicationModel::Contacts::Contact const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactPhone) ContactPhone() const;
        LLM_IMPL_AUTO(void) ContactPhone(llm::OS::ApplicationModel::Contacts::ContactPhone const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallMedia) Media() const;
        LLM_IMPL_AUTO(void) Media(llm::OS::ApplicationModel::Calls::PhoneCallMedia const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint) AudioEndpoint() const;
        LLM_IMPL_AUTO(void) AudioEndpoint(llm::OS::ApplicationModel::Calls::PhoneAudioRoutingEndpoint const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneDialOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneDialOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLine
    {
        LLM_IMPL_AUTO(llm::event_token) LineChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLine, llm::OS::Foundation::IInspectable> const& handler) const;
        using LineChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLine, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLine>::remove_LineChanged>;
        [[nodiscard]] LineChanged_revoker LineChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLine, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) LineChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::Color) DisplayColor() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneNetworkState) NetworkState() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneVoicemail) Voicemail() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) NetworkName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineCellularDetails) CellularDetails() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineTransport) Transport() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanDial() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SupportsTile() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallVideoCapabilities) VideoCallingCapabilities() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineConfiguration) LineConfiguration() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) IsImmediateDialNumberAsync(param::hstring const& number) const;
        LLM_IMPL_AUTO(void) Dial(param::hstring const& number, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(void) DialWithOptions(llm::OS::ApplicationModel::Calls::PhoneDialOptions const& options) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLine>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLine<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLine2
    {
        LLM_IMPL_AUTO(void) EnableTextReply(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TransportDeviceId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLine2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLine2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLine3
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineDialResult) DialWithResult(param::hstring const& number, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLineDialResult>) DialWithResultAsync(param::hstring const& number, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallsResult) GetAllActivePhoneCalls() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneCallsResult>) GetAllActivePhoneCallsAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLine3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLine3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneSimState) SimState() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) SimSlotIndex() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsModemOn() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) RegistrationRejectCode() const;
        LLM_IMPL_AUTO(hstring) GetNetworkOperatorDisplayText(llm::OS::ApplicationModel::Calls::PhoneLineNetworkOperatorDisplayTextLocation const& location) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineCellularDetails>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineCellularDetails<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVideoCallingEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) ExtendedProperties() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineConfiguration>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineDialResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCallOperationStatus) DialCallStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneCall) DialedCall() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineDialResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineDialResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::PhoneLine>) FromIdAsync(llm::guid const& lineId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineTransport) Transport() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceAccessStatus>) RequestAccessAsync() const;
        LLM_IMPL_AUTO(void) RegisterApp() const;
        LLM_IMPL_AUTO(void) RegisterAppForUser(llm::OS::System::User const& user) const;
        LLM_IMPL_AUTO(void) UnregisterApp() const;
        LLM_IMPL_AUTO(void) UnregisterAppForUser(llm::OS::System::User const& user) const;
        LLM_IMPL_AUTO(bool) IsRegistered() const;
        LLM_IMPL_AUTO(bool) Connect() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) ConnectAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::TransportDeviceAudioRoutingStatus) AudioRoutingStatus() const;
        LLM_IMPL_AUTO(llm::event_token) AudioRoutingStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const;
        using AudioRoutingStatusChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>::remove_AudioRoutingStatusChanged>;
        [[nodiscard]] AudioRoutingStatusChanged_revoker AudioRoutingStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) AudioRoutingStatusChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(bool) InBandRingingEnabled() const;
        LLM_IMPL_AUTO(llm::event_token) InBandRingingEnabledChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const;
        using InBandRingingEnabledChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>::remove_InBandRingingEnabledChanged>;
        [[nodiscard]] InBandRingingEnabledChanged_revoker InBandRingingEnabledChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) InBandRingingEnabledChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDevice2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDevice2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDeviceStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineTransportDevice) FromId(param::hstring const& id) const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector(llm::OS::ApplicationModel::Calls::PhoneLineTransport const& transport) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineTransportDeviceStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineTransportDeviceStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher
    {
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(void) Stop() const;
        LLM_IMPL_AUTO(llm::event_token) LineAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const;
        using LineAdded_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>::remove_LineAdded>;
        [[nodiscard]] LineAdded_revoker LineAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) LineAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) LineRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const;
        using LineRemoved_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>::remove_LineRemoved>;
        [[nodiscard]] LineRemoved_revoker LineRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) LineRemoved(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) LineUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const;
        using LineUpdated_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>::remove_LineUpdated>;
        [[nodiscard]] LineUpdated_revoker LineUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::ApplicationModel::Calls::PhoneLineWatcherEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) LineUpdated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const;
        using EnumerationCompleted_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>::remove_EnumerationCompleted>;
        [[nodiscard]] EnumerationCompleted_revoker EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) EnumerationCompleted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const;
        using Stopped_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher, &impl::abi_t<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>::remove_Stopped>;
        [[nodiscard]] Stopped_revoker Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::PhoneLineWatcher, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Stopped(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneLineWatcherStatus) Status() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineWatcher>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineWatcher<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneLineWatcherEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) LineId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneLineWatcherEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneLineWatcherEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IPhoneVoicemail
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Number() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MessageCount() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::PhoneVoicemailType) Type() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DialVoicemailAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IPhoneVoicemail>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IPhoneVoicemail<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>) ReserveCallResourcesAsync(param::hstring const& taskEntryPoint) const;
        LLM_IMPL_AUTO(llm::event_token) MuteStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipCallCoordinator, llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> const& muteChangeHandler) const;
        using MuteStateChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator, &impl::abi_t<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>::remove_MuteStateChanged>;
        [[nodiscard]] MuteStateChanged_revoker MuteStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipCallCoordinator, llm::OS::ApplicationModel::Calls::MuteChangeEventArgs> const& muteChangeHandler) const;
        LLM_IMPL_AUTO(void) MuteStateChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) RequestNewIncomingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media, llm::OS::Foundation::TimeSpan const& ringTimeout) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) RequestNewOutgoingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& serviceName, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const;
        LLM_IMPL_AUTO(void) NotifyMuted() const;
        LLM_IMPL_AUTO(void) NotifyUnmuted() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) RequestOutgoingUpgradeToVideoCall(llm::guid const& callUpgradeGuid, param::hstring const& context, param::hstring const& contactName, param::hstring const& serviceName) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) RequestIncomingUpgradeToVideoCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::Foundation::TimeSpan const& ringTimeout) const;
        LLM_IMPL_AUTO(void) TerminateCellularCall(llm::guid const& callUpgradeGuid) const;
        LLM_IMPL_AUTO(void) CancelUpgrade(llm::guid const& callUpgradeGuid) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator2
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) SetupNewAcceptedCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, param::hstring const& serviceName, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator3
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) RequestNewAppInitiatedCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, param::hstring const& serviceName, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCall) RequestNewIncomingCall(param::hstring const& context, param::hstring const& contactName, param::hstring const& contactNumber, llm::OS::Foundation::Uri const& contactImage, param::hstring const& serviceName, llm::OS::Foundation::Uri const& brandingImage, param::hstring const& callDetails, llm::OS::Foundation::Uri const& ringtone, llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media, llm::OS::Foundation::TimeSpan const& ringTimeout, param::hstring const& contactRemoteId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator4
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Calls::VoipPhoneCallResourceReservationStatus>) ReserveCallResourcesAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipCallCoordinator4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipCallCoordinator4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipCallCoordinatorStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipCallCoordinator) GetDefault() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipCallCoordinatorStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipCallCoordinatorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipPhoneCall
    {
        LLM_IMPL_AUTO(llm::event_token) EndRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const;
        using EndRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IVoipPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>::remove_EndRequested>;
        [[nodiscard]] EndRequested_revoker EndRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) EndRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) HoldRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const;
        using HoldRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IVoipPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>::remove_HoldRequested>;
        [[nodiscard]] HoldRequested_revoker HoldRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) HoldRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ResumeRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const;
        using ResumeRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IVoipPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>::remove_ResumeRequested>;
        [[nodiscard]] ResumeRequested_revoker ResumeRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallStateChangeEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ResumeRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) AnswerRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> const& acceptHandler) const;
        using AnswerRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IVoipPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>::remove_AnswerRequested>;
        [[nodiscard]] AnswerRequested_revoker AnswerRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallAnswerEventArgs> const& acceptHandler) const;
        LLM_IMPL_AUTO(void) AnswerRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) RejectRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallRejectEventArgs> const& rejectHandler) const;
        using RejectRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Calls::IVoipPhoneCall, &impl::abi_t<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>::remove_RejectRequested>;
        [[nodiscard]] RejectRequested_revoker RejectRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Calls::VoipPhoneCall, llm::OS::ApplicationModel::Calls::CallRejectEventArgs> const& rejectHandler) const;
        LLM_IMPL_AUTO(void) RejectRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) NotifyCallHeld() const;
        LLM_IMPL_AUTO(void) NotifyCallActive() const;
        LLM_IMPL_AUTO(void) NotifyCallEnded() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContactName() const;
        LLM_IMPL_AUTO(void) ContactName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) StartTime() const;
        LLM_IMPL_AUTO(void) StartTime(llm::OS::Foundation::DateTime const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia) CallMedia() const;
        LLM_IMPL_AUTO(void) CallMedia(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& value) const;
        LLM_IMPL_AUTO(void) NotifyCallReady() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipPhoneCall>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipPhoneCall<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipPhoneCall2
    {
        LLM_IMPL_AUTO(void) TryShowAppUI() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipPhoneCall2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipPhoneCall2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Calls_IVoipPhoneCall3
    {
        LLM_IMPL_AUTO(void) NotifyCallAccepted(llm::OS::ApplicationModel::Calls::VoipPhoneCallMedia const& media) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Calls::IVoipPhoneCall3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Calls_IVoipPhoneCall3<D>;
    };
}
#endif
