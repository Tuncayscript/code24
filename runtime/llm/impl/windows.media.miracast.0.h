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
#ifndef LLM_OS_Media_Miracast_0_H
#define LLM_OS_Media_Miracast_0_H
LLM_EXPORT namespace llm:OS::ApplicationModel::Core
{
    struct CoreApplicationView;
}
LLM_EXPORT namespace llm:OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct HResult;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Graphics
{
    struct PointInt32;
    struct SizeInt32;
}
LLM_EXPORT namespace llm:OS::Media::Core
{
    struct MediaSource;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IRandomAccessStreamWithContentType;
}
LLM_EXPORT namespace llm:OS::Media::Miracast
{
    enum class MiracastReceiverApplySettingsStatus : int32_t
    {
        Success = 0,
        UnknownFailure = 1,
        MiracastNotSupported = 2,
        AccessDenied = 3,
        FriendlyNameTooLong = 4,
        ModelNameTooLong = 5,
        ModelNumberTooLong = 6,
        InvalidSettings = 7,
    };
    enum class MiracastReceiverAuthorizationMethod : int32_t
    {
        None = 0,
        ConfirmConnection = 1,
        PinDisplayIfRequested = 2,
        PinDisplayRequired = 3,
    };
    enum class MiracastReceiverDisconnectReason : int32_t
    {
        Finished = 0,
        AppSpecificError = 1,
        ConnectionNotAccepted = 2,
        DisconnectedByUser = 3,
        FailedToStartStreaming = 4,
        MediaDecodingError = 5,
        MediaStreamingError = 6,
        MediaDecryptionError = 7,
    };
    enum class MiracastReceiverGameControllerDeviceUsageMode : int32_t
    {
        AsGameController = 0,
        AsMouseAndKeyboard = 1,
    };
    enum class MiracastReceiverListeningStatus : int32_t
    {
        NotListening = 0,
        Listening = 1,
        ConnectionPending = 2,
        Connected = 3,
        DisabledByPolicy = 4,
        TemporarilyDisabled = 5,
    };
    enum class MiracastReceiverSessionStartStatus : int32_t
    {
        Success = 0,
        UnknownFailure = 1,
        MiracastNotSupported = 2,
        AccessDenied = 3,
    };
    enum class MiracastReceiverWiFiStatus : int32_t
    {
        MiracastSupportUndetermined = 0,
        MiracastNotSupported = 1,
        MiracastSupportNotOptimized = 2,
        MiracastSupported = 3,
    };
    enum class MiracastTransmitterAuthorizationStatus : int32_t
    {
        Undecided = 0,
        Allowed = 1,
        AlwaysPrompt = 2,
        Blocked = 3,
    };
    struct IMiracastReceiver;
    struct IMiracastReceiverApplySettingsResult;
    struct IMiracastReceiverConnection;
    struct IMiracastReceiverConnectionCreatedEventArgs;
    struct IMiracastReceiverCursorImageChannel;
    struct IMiracastReceiverCursorImageChannelSettings;
    struct IMiracastReceiverDisconnectedEventArgs;
    struct IMiracastReceiverGameControllerDevice;
    struct IMiracastReceiverInputDevices;
    struct IMiracastReceiverKeyboardDevice;
    struct IMiracastReceiverMediaSourceCreatedEventArgs;
    struct IMiracastReceiverSession;
    struct IMiracastReceiverSessionStartResult;
    struct IMiracastReceiverSettings;
    struct IMiracastReceiverStatus;
    struct IMiracastReceiverStreamControl;
    struct IMiracastReceiverVideoStreamSettings;
    struct IMiracastTransmitter;
    struct MiracastReceiver;
    struct MiracastReceiverApplySettingsResult;
    struct MiracastReceiverConnection;
    struct MiracastReceiverConnectionCreatedEventArgs;
    struct MiracastReceiverCursorImageChannel;
    struct MiracastReceiverCursorImageChannelSettings;
    struct MiracastReceiverDisconnectedEventArgs;
    struct MiracastReceiverGameControllerDevice;
    struct MiracastReceiverInputDevices;
    struct MiracastReceiverKeyboardDevice;
    struct MiracastReceiverMediaSourceCreatedEventArgs;
    struct MiracastReceiverSession;
    struct MiracastReceiverSessionStartResult;
    struct MiracastReceiverSettings;
    struct MiracastReceiverStatus;
    struct MiracastReceiverStreamControl;
    struct MiracastReceiverVideoStreamSettings;
    struct MiracastTransmitter;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiver>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverConnection>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverInputDevices>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverSession>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverStatus>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverStreamControl>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::IMiracastTransmitter>{ using type = interface_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiver>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverApplySettingsResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverConnection>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverConnectionCreatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannelSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverDisconnectedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverGameControllerDevice>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverInputDevices>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverKeyboardDevice>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverMediaSourceCreatedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverSession>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverSessionStartResult>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverStatus>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverStreamControl>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastTransmitter>{ using type = class_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverApplySettingsStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverAuthorizationMethod>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverDisconnectReason>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverGameControllerDeviceUsageMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverListeningStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverSessionStartStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastReceiverWiFiStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Media::Miracast::MiracastTransmitterAuthorizationStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiver> = L"Windows.Media.Miracast.MiracastReceiver";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverApplySettingsResult> = L"Windows.Media.Miracast.MiracastReceiverApplySettingsResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverConnection> = L"Windows.Media.Miracast.MiracastReceiverConnection";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverConnectionCreatedEventArgs> = L"Windows.Media.Miracast.MiracastReceiverConnectionCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel> = L"Windows.Media.Miracast.MiracastReceiverCursorImageChannel";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannelSettings> = L"Windows.Media.Miracast.MiracastReceiverCursorImageChannelSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverDisconnectedEventArgs> = L"Windows.Media.Miracast.MiracastReceiverDisconnectedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverGameControllerDevice> = L"Windows.Media.Miracast.MiracastReceiverGameControllerDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverInputDevices> = L"Windows.Media.Miracast.MiracastReceiverInputDevices";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverKeyboardDevice> = L"Windows.Media.Miracast.MiracastReceiverKeyboardDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverMediaSourceCreatedEventArgs> = L"Windows.Media.Miracast.MiracastReceiverMediaSourceCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverSession> = L"Windows.Media.Miracast.MiracastReceiverSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverSessionStartResult> = L"Windows.Media.Miracast.MiracastReceiverSessionStartResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverSettings> = L"Windows.Media.Miracast.MiracastReceiverSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverStatus> = L"Windows.Media.Miracast.MiracastReceiverStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverStreamControl> = L"Windows.Media.Miracast.MiracastReceiverStreamControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings> = L"Windows.Media.Miracast.MiracastReceiverVideoStreamSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastTransmitter> = L"Windows.Media.Miracast.MiracastTransmitter";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverApplySettingsStatus> = L"Windows.Media.Miracast.MiracastReceiverApplySettingsStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverAuthorizationMethod> = L"Windows.Media.Miracast.MiracastReceiverAuthorizationMethod";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverDisconnectReason> = L"Windows.Media.Miracast.MiracastReceiverDisconnectReason";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverGameControllerDeviceUsageMode> = L"Windows.Media.Miracast.MiracastReceiverGameControllerDeviceUsageMode";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverListeningStatus> = L"Windows.Media.Miracast.MiracastReceiverListeningStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverSessionStartStatus> = L"Windows.Media.Miracast.MiracastReceiverSessionStartStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastReceiverWiFiStatus> = L"Windows.Media.Miracast.MiracastReceiverWiFiStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::MiracastTransmitterAuthorizationStatus> = L"Windows.Media.Miracast.MiracastTransmitterAuthorizationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiver> = L"Windows.Media.Miracast.IMiracastReceiver";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult> = L"Windows.Media.Miracast.IMiracastReceiverApplySettingsResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverConnection> = L"Windows.Media.Miracast.IMiracastReceiverConnection";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs> = L"Windows.Media.Miracast.IMiracastReceiverConnectionCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel> = L"Windows.Media.Miracast.IMiracastReceiverCursorImageChannel";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings> = L"Windows.Media.Miracast.IMiracastReceiverCursorImageChannelSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs> = L"Windows.Media.Miracast.IMiracastReceiverDisconnectedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice> = L"Windows.Media.Miracast.IMiracastReceiverGameControllerDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverInputDevices> = L"Windows.Media.Miracast.IMiracastReceiverInputDevices";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice> = L"Windows.Media.Miracast.IMiracastReceiverKeyboardDevice";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs> = L"Windows.Media.Miracast.IMiracastReceiverMediaSourceCreatedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverSession> = L"Windows.Media.Miracast.IMiracastReceiverSession";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult> = L"Windows.Media.Miracast.IMiracastReceiverSessionStartResult";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverSettings> = L"Windows.Media.Miracast.IMiracastReceiverSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverStatus> = L"Windows.Media.Miracast.IMiracastReceiverStatus";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverStreamControl> = L"Windows.Media.Miracast.IMiracastReceiverStreamControl";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings> = L"Windows.Media.Miracast.IMiracastReceiverVideoStreamSettings";
    template <> inline constexpr auto& name_v<llm:OS::Media::Miracast::IMiracastTransmitter> = L"Windows.Media.Miracast.IMiracastTransmitter";
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiver>{ 0x7A315258,0xE444,0x51B4,{ 0xAF,0xF7,0xB8,0x8D,0xAA,0x12,0x29,0xE0 } }; // 7A315258-E444-51B4-AFF7-B88DAA1229E0
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult>{ 0xD0AA6272,0x09CD,0x58E1,{ 0xA4,0xF2,0x5D,0x51,0x43,0xD3,0x12,0xF9 } }; // D0AA6272-09CD-58E1-A4F2-5D5143D312F9
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverConnection>{ 0x704B2F36,0xD2E5,0x551F,{ 0xA8,0x54,0xF8,0x22,0xB7,0x91,0x7D,0x28 } }; // 704B2F36-D2E5-551F-A854-F822B7917D28
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs>{ 0x7D8DFA39,0x307A,0x5C0F,{ 0x94,0xBD,0xD0,0xC6,0x9D,0x16,0x99,0x82 } }; // 7D8DFA39-307A-5C0F-94BD-D0C69D169982
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel>{ 0xD9AC332D,0x723A,0x5A9D,{ 0xB9,0x0A,0x81,0x15,0x3E,0xFA,0x2A,0x0F } }; // D9AC332D-723A-5A9D-B90A-81153EFA2A0F
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings>{ 0xCCDBEDFF,0xBD00,0x5B9C,{ 0x8E,0x4C,0x00,0xCA,0xCF,0x86,0xB6,0x34 } }; // CCDBEDFF-BD00-5B9C-8E4C-00CACF86B634
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs>{ 0xD9A15E5E,0x5FEE,0x57E6,{ 0xB4,0xB0,0x04,0x72,0x7D,0xB9,0x32,0x29 } }; // D9A15E5E-5FEE-57E6-B4B0-04727DB93229
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice>{ 0x2D7171E8,0xBED4,0x5118,{ 0xA0,0x58,0xE2,0x47,0x7E,0xB5,0x88,0x8D } }; // 2D7171E8-BED4-5118-A058-E2477EB5888D
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverInputDevices>{ 0xDA35BB02,0x28AA,0x5EE8,{ 0x96,0xF5,0xA4,0x29,0x01,0xC6,0x6F,0x00 } }; // DA35BB02-28AA-5EE8-96F5-A42901C66F00
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice>{ 0xBEB67272,0x06C0,0x54FF,{ 0xAC,0x96,0x21,0x74,0x64,0xFF,0x25,0x01 } }; // BEB67272-06C0-54FF-AC96-217464FF2501
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs>{ 0x17CF519E,0x1246,0x531D,{ 0x94,0x5A,0x6B,0x15,0x8E,0x39,0xC3,0xAA } }; // 17CF519E-1246-531D-945A-6B158E39C3AA
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverSession>{ 0x1D2BCDB4,0xEF8B,0x5209,{ 0xBF,0xC9,0xC3,0x21,0x16,0x50,0x48,0x03 } }; // 1D2BCDB4-EF8B-5209-BFC9-C32116504803
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult>{ 0xB7C573EE,0x40CA,0x51FF,{ 0x95,0xF2,0xC9,0xDE,0x34,0xF2,0xE9,0x0E } }; // B7C573EE-40CA-51FF-95F2-C9DE34F2E90E
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverSettings>{ 0x57CD2F24,0xC55A,0x5FBE,{ 0x94,0x64,0xEB,0x05,0x30,0x77,0x05,0xDD } }; // 57CD2F24-C55A-5FBE-9464-EB05307705DD
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverStatus>{ 0xC28A5591,0x23AB,0x519E,{ 0xAD,0x09,0x90,0xBF,0xF6,0xDC,0xC8,0x7E } }; // C28A5591-23AB-519E-AD09-90BFF6DCC87E
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverStreamControl>{ 0x38EA2D8B,0x2769,0x5AD7,{ 0x8A,0x8A,0x25,0x4B,0x9D,0xF7,0xBA,0x82 } }; // 38EA2D8B-2769-5AD7-8A8A-254B9DF7BA82
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings>{ 0x169B5E1B,0x149D,0x52D0,{ 0xB1,0x26,0x6F,0x89,0x74,0x4E,0x4F,0x50 } }; // 169B5E1B-149D-52D0-B126-6F89744E4F50
    template <> inline constexpr guid guid_v<llm:OS::Media::Miracast::IMiracastTransmitter>{ 0x342D79FD,0x2E64,0x5508,{ 0x8A,0x30,0x83,0x3D,0x1E,0xAC,0x70,0xD0 } }; // 342D79FD-2E64-5508-8A30-833D1EAC70D0
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiver>{ using type = llm:OS::Media::Miracast::IMiracastReceiver; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverApplySettingsResult>{ using type = llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverConnection>{ using type = llm:OS::Media::Miracast::IMiracastReceiverConnection; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverConnectionCreatedEventArgs>{ using type = llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel>{ using type = llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannelSettings>{ using type = llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverDisconnectedEventArgs>{ using type = llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverGameControllerDevice>{ using type = llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverInputDevices>{ using type = llm:OS::Media::Miracast::IMiracastReceiverInputDevices; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverKeyboardDevice>{ using type = llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverMediaSourceCreatedEventArgs>{ using type = llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverSession>{ using type = llm:OS::Media::Miracast::IMiracastReceiverSession; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverSessionStartResult>{ using type = llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverSettings>{ using type = llm:OS::Media::Miracast::IMiracastReceiverSettings; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverStatus>{ using type = llm:OS::Media::Miracast::IMiracastReceiverStatus; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverStreamControl>{ using type = llm:OS::Media::Miracast::IMiracastReceiverStreamControl; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings>{ using type = llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings; };
    template <> struct default_interface<llm:OS::Media::Miracast::MiracastTransmitter>{ using type = llm:OS::Media::Miracast::IMiracastTransmitter; };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiver>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefaultSettings(void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentSettings(void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentSettingsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DisconnectAllAndApplySettings(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DisconnectAllAndApplySettingsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetStatus(void**) noexcept = 0;
            virtual int32_t __stdcall GetStatusAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_StatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_StatusChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall CreateSession(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateSessionAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ClearKnownTransmitters() noexcept = 0;
            virtual int32_t __stdcall RemoveKnownTransmitter(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Disconnect(int32_t) noexcept = 0;
            virtual int32_t __stdcall DisconnectWithMessage(int32_t, void*) noexcept = 0;
            virtual int32_t __stdcall Pause() noexcept = 0;
            virtual int32_t __stdcall PauseAsync(void**) noexcept = 0;
            virtual int32_t __stdcall Resume() noexcept = 0;
            virtual int32_t __stdcall ResumeAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_Transmitter(void**) noexcept = 0;
            virtual int32_t __stdcall get_InputDevices(void**) noexcept = 0;
            virtual int32_t __stdcall get_CursorImageChannel(void**) noexcept = 0;
            virtual int32_t __stdcall get_StreamControl(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Connection(void**) noexcept = 0;
            virtual int32_t __stdcall get_Pin(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MaxImageSize(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall get_Position(struct struct_Windows_Graphics_PointInt32*) noexcept = 0;
            virtual int32_t __stdcall get_ImageStream(void**) noexcept = 0;
            virtual int32_t __stdcall add_ImageStreamChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ImageStreamChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_PositionChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_PositionChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall get_MaxImageSize(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall put_MaxImageSize(struct struct_Windows_Graphics_SizeInt32) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Connection(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TransmitInput(bool*) noexcept = 0;
            virtual int32_t __stdcall put_TransmitInput(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsRequestedByTransmitter(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsTransmittingInput(bool*) noexcept = 0;
            virtual int32_t __stdcall get_Mode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Mode(int32_t) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverInputDevices>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Keyboard(void**) noexcept = 0;
            virtual int32_t __stdcall get_GameController(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TransmitInput(bool*) noexcept = 0;
            virtual int32_t __stdcall put_TransmitInput(bool) noexcept = 0;
            virtual int32_t __stdcall get_IsRequestedByTransmitter(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsTransmittingInput(bool*) noexcept = 0;
            virtual int32_t __stdcall add_Changed(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Changed(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Connection(void**) noexcept = 0;
            virtual int32_t __stdcall get_MediaSource(void**) noexcept = 0;
            virtual int32_t __stdcall get_CursorImageChannelSettings(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ConnectionCreated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ConnectionCreated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_MediaSourceCreated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_MediaSourceCreated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Disconnected(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Disconnected(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_AllowConnectionTakeover(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowConnectionTakeover(bool) noexcept = 0;
            virtual int32_t __stdcall get_MaxSimultaneousConnections(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MaxSimultaneousConnections(int32_t) noexcept = 0;
            virtual int32_t __stdcall Start(void**) noexcept = 0;
            virtual int32_t __stdcall StartAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ExtendedError(llm::hresult*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FriendlyName(void**) noexcept = 0;
            virtual int32_t __stdcall put_FriendlyName(void*) noexcept = 0;
            virtual int32_t __stdcall get_ModelName(void**) noexcept = 0;
            virtual int32_t __stdcall put_ModelName(void*) noexcept = 0;
            virtual int32_t __stdcall get_ModelNumber(void**) noexcept = 0;
            virtual int32_t __stdcall put_ModelNumber(void*) noexcept = 0;
            virtual int32_t __stdcall get_AuthorizationMethod(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AuthorizationMethod(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_RequireAuthorizationFromKnownTransmitters(bool*) noexcept = 0;
            virtual int32_t __stdcall put_RequireAuthorizationFromKnownTransmitters(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverStatus>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ListeningStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_WiFiStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_IsConnectionTakeoverSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall get_MaxSimultaneousConnections(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_KnownTransmitters(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverStreamControl>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetVideoStreamSettings(void**) noexcept = 0;
            virtual int32_t __stdcall GetVideoStreamSettingsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall SuggestVideoStreamSettings(void*) noexcept = 0;
            virtual int32_t __stdcall SuggestVideoStreamSettingsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_MuteAudio(bool*) noexcept = 0;
            virtual int32_t __stdcall put_MuteAudio(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Size(struct struct_Windows_Graphics_SizeInt32*) noexcept = 0;
            virtual int32_t __stdcall put_Size(struct struct_Windows_Graphics_SizeInt32) noexcept = 0;
            virtual int32_t __stdcall get_Bitrate(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Bitrate(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Media::Miracast::IMiracastTransmitter>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_AuthorizationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_AuthorizationStatus(int32_t) noexcept = 0;
            virtual int32_t __stdcall GetConnections(void**) noexcept = 0;
            virtual int32_t __stdcall get_MacAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_LastConnectionTime(int64_t*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiver
    {
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverSettings) GetDefaultSettings() const;
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverSettings) GetCurrentSettings() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Miracast::MiracastReceiverSettings>) GetCurrentSettingsAsync() const;
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverApplySettingsResult) DisconnectAllAndApplySettings(llm:OS::Media::Miracast::MiracastReceiverSettings const& settings) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Miracast::MiracastReceiverApplySettingsResult>) DisconnectAllAndApplySettingsAsync(llm:OS::Media::Miracast::MiracastReceiverSettings const& settings) const;
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverStatus) GetStatus() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Miracast::MiracastReceiverStatus>) GetStatusAsync() const;
        LLM_IMPL_AUTO(llm::event_token) StatusChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiver, llm:OS::Foundation::IInspectable> const& handler) const;
        using StatusChanged_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiver, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiver>::remove_StatusChanged>;
        [[nodiscard]] StatusChanged_revoker StatusChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiver, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) StatusChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverSession) CreateSession(llm:OS::ApplicationModel::Core::CoreApplicationView const& view) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Miracast::MiracastReceiverSession>) CreateSessionAsync(llm:OS::ApplicationModel::Core::CoreApplicationView const& view) const;
        LLM_IMPL_AUTO(void) ClearKnownTransmitters() const;
        LLM_IMPL_AUTO(void) RemoveKnownTransmitter(llm:OS::Media::Miracast::MiracastTransmitter const& transmitter) const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiver>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiver<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverApplySettingsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverApplySettingsStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverApplySettingsResult>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverApplySettingsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverConnection
    {
        LLM_IMPL_AUTO(void) Disconnect(llm:OS::Media::Miracast::MiracastReceiverDisconnectReason const& reason) const;
        LLM_IMPL_AUTO(void) Disconnect(llm:OS::Media::Miracast::MiracastReceiverDisconnectReason const& reason, param::hstring const& message) const;
        LLM_IMPL_AUTO(void) Pause() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) PauseAsync() const;
        LLM_IMPL_AUTO(void) Resume() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ResumeAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastTransmitter) Transmitter() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverInputDevices) InputDevices() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel) CursorImageChannel() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverStreamControl) StreamControl() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverConnection>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverConnection<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverConnectionCreatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverConnection) Connection() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Pin() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverConnectionCreatedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverConnectionCreatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverCursorImageChannel
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::SizeInt32) MaxImageSize() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::PointInt32) Position() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IRandomAccessStreamWithContentType) ImageStream() const;
        LLM_IMPL_AUTO(llm::event_token) ImageStreamChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel, llm:OS::Foundation::IInspectable> const& handler) const;
        using ImageStreamChanged_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel>::remove_ImageStreamChanged>;
        [[nodiscard]] ImageStreamChanged_revoker ImageStreamChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) ImageStreamChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) PositionChanged(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel, llm:OS::Foundation::IInspectable> const& handler) const;
        using PositionChanged_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel>::remove_PositionChanged>;
        [[nodiscard]] PositionChanged_revoker PositionChanged(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverCursorImageChannel, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) PositionChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannel>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverCursorImageChannel<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverCursorImageChannelSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        LLM_IMPL_AUTO(void) IsEnabled(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::SizeInt32) MaxImageSize() const;
        LLM_IMPL_AUTO(void) MaxImageSize(llm:OS::Graphics::SizeInt32 const& value) const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverCursorImageChannelSettings>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverCursorImageChannelSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverDisconnectedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverConnection) Connection() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverDisconnectedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverDisconnectedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverGameControllerDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) TransmitInput() const;
        LLM_IMPL_AUTO(void) TransmitInput(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRequestedByTransmitter() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTransmittingInput() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverGameControllerDeviceUsageMode) Mode() const;
        LLM_IMPL_AUTO(void) Mode(llm:OS::Media::Miracast::MiracastReceiverGameControllerDeviceUsageMode const& value) const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverGameControllerDevice, llm:OS::Foundation::IInspectable> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverGameControllerDevice, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverGameControllerDevice>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverGameControllerDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverInputDevices
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverKeyboardDevice) Keyboard() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverGameControllerDevice) GameController() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverInputDevices>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverInputDevices<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverKeyboardDevice
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) TransmitInput() const;
        LLM_IMPL_AUTO(void) TransmitInput(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsRequestedByTransmitter() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTransmittingInput() const;
        LLM_IMPL_AUTO(llm::event_token) Changed(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverKeyboardDevice, llm:OS::Foundation::IInspectable> const& handler) const;
        using Changed_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice>::remove_Changed>;
        [[nodiscard]] Changed_revoker Changed(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverKeyboardDevice, llm:OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) Changed(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverKeyboardDevice>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverKeyboardDevice<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverMediaSourceCreatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverConnection) Connection() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Core::MediaSource) MediaSource() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverCursorImageChannelSettings) CursorImageChannelSettings() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverMediaSourceCreatedEventArgs>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverMediaSourceCreatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverSession
    {
        LLM_IMPL_AUTO(llm::event_token) ConnectionCreated(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverSession, llm:OS::Media::Miracast::MiracastReceiverConnectionCreatedEventArgs> const& handler) const;
        using ConnectionCreated_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverSession, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverSession>::remove_ConnectionCreated>;
        [[nodiscard]] ConnectionCreated_revoker ConnectionCreated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverSession, llm:OS::Media::Miracast::MiracastReceiverConnectionCreatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) ConnectionCreated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) MediaSourceCreated(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverSession, llm:OS::Media::Miracast::MiracastReceiverMediaSourceCreatedEventArgs> const& handler) const;
        using MediaSourceCreated_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverSession, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverSession>::remove_MediaSourceCreated>;
        [[nodiscard]] MediaSourceCreated_revoker MediaSourceCreated(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverSession, llm:OS::Media::Miracast::MiracastReceiverMediaSourceCreatedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) MediaSourceCreated(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Disconnected(llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverSession, llm:OS::Media::Miracast::MiracastReceiverDisconnectedEventArgs> const& handler) const;
        using Disconnected_revoker = impl::event_revoker<llm:OS::Media::Miracast::IMiracastReceiverSession, &impl::abi_t<llm:OS::Media::Miracast::IMiracastReceiverSession>::remove_Disconnected>;
        [[nodiscard]] Disconnected_revoker Disconnected(auto_revoke_t, llm:OS::Foundation::TypedEventHandler<llm:OS::Media::Miracast::MiracastReceiverSession, llm:OS::Media::Miracast::MiracastReceiverDisconnectedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Disconnected(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AllowConnectionTakeover() const;
        LLM_IMPL_AUTO(void) AllowConnectionTakeover(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxSimultaneousConnections() const;
        LLM_IMPL_AUTO(void) MaxSimultaneousConnections(int32_t value) const;
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverSessionStartResult) Start() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Miracast::MiracastReceiverSessionStartResult>) StartAsync() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverSession>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverSession<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverSessionStartResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverSessionStartStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::hresult) ExtendedError() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverSessionStartResult>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverSessionStartResult<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FriendlyName() const;
        LLM_IMPL_AUTO(void) FriendlyName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ModelName() const;
        LLM_IMPL_AUTO(void) ModelName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ModelNumber() const;
        LLM_IMPL_AUTO(void) ModelNumber(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverAuthorizationMethod) AuthorizationMethod() const;
        LLM_IMPL_AUTO(void) AuthorizationMethod(llm:OS::Media::Miracast::MiracastReceiverAuthorizationMethod const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) RequireAuthorizationFromKnownTransmitters() const;
        LLM_IMPL_AUTO(void) RequireAuthorizationFromKnownTransmitters(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverSettings>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverStatus
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverListeningStatus) ListeningStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverWiFiStatus) WiFiStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsConnectionTakeoverSupported() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaxSimultaneousConnections() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Miracast::MiracastTransmitter>) KnownTransmitters() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverStatus>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverStatus<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverStreamControl
    {
        LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings) GetVideoStreamSettings() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings>) GetVideoStreamSettingsAsync() const;
        LLM_IMPL_AUTO(void) SuggestVideoStreamSettings(llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings const& settings) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) SuggestVideoStreamSettingsAsync(llm:OS::Media::Miracast::MiracastReceiverVideoStreamSettings const& settings) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) MuteAudio() const;
        LLM_IMPL_AUTO(void) MuteAudio(bool value) const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverStreamControl>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverStreamControl<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastReceiverVideoStreamSettings
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Graphics::SizeInt32) Size() const;
        LLM_IMPL_AUTO(void) Size(llm:OS::Graphics::SizeInt32 const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) Bitrate() const;
        LLM_IMPL_AUTO(void) Bitrate(int32_t value) const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastReceiverVideoStreamSettings>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastReceiverVideoStreamSettings<D>;
    };
    template <typename D>
    struct consume_Windows_Media_Miracast_IMiracastTransmitter
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Media::Miracast::MiracastTransmitterAuthorizationStatus) AuthorizationStatus() const;
        LLM_IMPL_AUTO(void) AuthorizationStatus(llm:OS::Media::Miracast::MiracastTransmitterAuthorizationStatus const& value) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::Collections::IVectorView<llm:OS::Media::Miracast::MiracastReceiverConnection>) GetConnections() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) MacAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Foundation::DateTime) LastConnectionTime() const;
    };
    template <> struct consume<llm:OS::Media::Miracast::IMiracastTransmitter>
    {
        template <typename D> using type = consume_Windows_Media_Miracast_IMiracastTransmitter<D>;
    };
}
#endif
