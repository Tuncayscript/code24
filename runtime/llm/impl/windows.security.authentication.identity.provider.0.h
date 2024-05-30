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
#ifndef LLM_OS_Security_Authentication_Identity_Provider_0_H
#define LLM_OS_Security_Authentication_Identity_Provider_0_H
LLM_EXPORT namespace llm:OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) EventHandler;
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
}
LLM_EXPORT namespace llm:OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
}
LLM_EXPORT namespace llm:OS::Storage::Streams
{
    struct IBuffer;
}
LLM_EXPORT namespace llm:OS::Security::Authentication::Identity::Provider
{
    enum class SecondaryAuthenticationFactorAuthenticationMessage : int32_t
    {
        Invalid = 0,
        SwipeUpWelcome = 1,
        TapWelcome = 2,
        DeviceNeedsAttention = 3,
        LookingForDevice = 4,
        LookingForDevicePluggedin = 5,
        BluetoothIsDisabled = 6,
        NfcIsDisabled = 7,
        WiFiIsDisabled = 8,
        ExtraTapIsRequired = 9,
        DisabledByPolicy = 10,
        TapOnDeviceRequired = 11,
        HoldFinger = 12,
        ScanFinger = 13,
        UnauthorizedUser = 14,
        ReregisterRequired = 15,
        TryAgain = 16,
        SayPassphrase = 17,
        ReadyToSignIn = 18,
        UseAnotherSignInOption = 19,
        ConnectionRequired = 20,
        TimeLimitExceeded = 21,
        CanceledByUser = 22,
        CenterHand = 23,
        MoveHandCloser = 24,
        MoveHandFarther = 25,
        PlaceHandAbove = 26,
        RecognitionFailed = 27,
        DeviceUnavailable = 28,
    };
    enum class SecondaryAuthenticationFactorAuthenticationScenario : int32_t
    {
        SignIn = 0,
        CredentialPrompt = 1,
    };
    enum class SecondaryAuthenticationFactorAuthenticationStage : int32_t
    {
        NotStarted = 0,
        WaitingForUserConfirmation = 1,
        CollectingCredential = 2,
        SuspendingAuthentication = 3,
        CredentialCollected = 4,
        CredentialAuthenticated = 5,
        StoppingAuthentication = 6,
        ReadyForLock = 7,
        CheckingDevicePresence = 8,
    };
    enum class SecondaryAuthenticationFactorAuthenticationStatus : int32_t
    {
        Failed = 0,
        Started = 1,
        UnknownDevice = 2,
        DisabledByPolicy = 3,
        InvalidAuthenticationStage = 4,
    };
    enum class SecondaryAuthenticationFactorDeviceCapabilities : uint32_t
    {
        None = 0,
        SecureStorage = 0x1,
        StoreKeys = 0x2,
        ConfirmUserIntentToAuthenticate = 0x4,
        SupportSecureUserPresenceCheck = 0x8,
        TransmittedDataIsEncrypted = 0x10,
        HMacSha256 = 0x20,
        CloseRangeDataTransmission = 0x40,
    };
    enum class SecondaryAuthenticationFactorDeviceFindScope : int32_t
    {
        User = 0,
        AllUsers = 1,
    };
    enum class SecondaryAuthenticationFactorDevicePresence : int32_t
    {
        Absent = 0,
        Present = 1,
    };
    enum class SecondaryAuthenticationFactorDevicePresenceMonitoringMode : int32_t
    {
        Unsupported = 0,
        AppManaged = 1,
        SystemManaged = 2,
    };
    enum class SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus : int32_t
    {
        Unsupported = 0,
        Succeeded = 1,
        DisabledByPolicy = 2,
    };
    enum class SecondaryAuthenticationFactorFinishAuthenticationStatus : int32_t
    {
        Failed = 0,
        Completed = 1,
        NonceExpired = 2,
    };
    enum class SecondaryAuthenticationFactorRegistrationStatus : int32_t
    {
        Failed = 0,
        Started = 1,
        CanceledByUser = 2,
        PinSetupRequired = 3,
        DisabledByPolicy = 4,
    };
    struct ISecondaryAuthenticationFactorAuthentication;
    struct ISecondaryAuthenticationFactorAuthenticationResult;
    struct ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs;
    struct ISecondaryAuthenticationFactorAuthenticationStageInfo;
    struct ISecondaryAuthenticationFactorAuthenticationStatics;
    struct ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics;
    struct ISecondaryAuthenticationFactorInfo;
    struct ISecondaryAuthenticationFactorInfo2;
    struct ISecondaryAuthenticationFactorRegistration;
    struct ISecondaryAuthenticationFactorRegistrationResult;
    struct ISecondaryAuthenticationFactorRegistrationStatics;
    struct SecondaryAuthenticationFactorAuthentication;
    struct SecondaryAuthenticationFactorAuthenticationResult;
    struct SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs;
    struct SecondaryAuthenticationFactorAuthenticationStageInfo;
    struct SecondaryAuthenticationFactorInfo;
    struct SecondaryAuthenticationFactorRegistration;
    struct SecondaryAuthenticationFactorRegistrationResult;
}
namespace llm::impl
{
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>{ using type = interface_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>{ using type = class_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresence>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>{ using type = enum_category; };
    template <> struct category<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthentication";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStageInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistration";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistrationResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationMessage";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationScenario";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStage";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorAuthenticationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDeviceCapabilities";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDeviceFindScope";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresence> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDevicePresence";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDevicePresenceMonitoringMode";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorFinishAuthenticationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus> = L"Windows.Security.Authentication.Identity.Provider.SecondaryAuthenticationFactorRegistrationStatus";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorAuthentication";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorAuthenticationResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorAuthenticationStageInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorAuthenticationStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorInfo";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorInfo2";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorRegistration";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorRegistrationResult";
    template <> inline constexpr auto& name_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics> = L"Windows.Security.Authentication.Identity.Provider.ISecondaryAuthenticationFactorRegistrationStatics";
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>{ 0x020A16E5,0x6A25,0x40A3,{ 0x8C,0x00,0x50,0xA0,0x23,0xF6,0x19,0xD1 } }; // 020A16E5-6A25-40A3-8C00-50A023F619D1
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>{ 0x9CBB5987,0xEF6D,0x4BC2,{ 0xBF,0x49,0x46,0x17,0x51,0x5A,0x0F,0x9A } }; // 9CBB5987-EF6D-4BC2-BF49-4617515A0F9A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>{ 0xD4A5EE56,0x7291,0x4073,{ 0xBC,0x1F,0xCC,0xB8,0xF5,0xAF,0xDF,0x96 } }; // D4A5EE56-7291-4073-BC1F-CCB8F5AFDF96
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>{ 0x56FEC28B,0xE8AA,0x4C0F,{ 0x8E,0x4C,0xA5,0x59,0xE7,0x3A,0xDD,0x88 } }; // 56FEC28B-E8AA-4C0F-8E4C-A559E73ADD88
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>{ 0x3F582656,0x28F8,0x4E0F,{ 0xAE,0x8C,0x58,0x98,0xB9,0xAE,0x24,0x69 } }; // 3F582656-28F8-4E0F-AE8C-5898B9AE2469
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>{ 0x90499A19,0x7EF2,0x4523,{ 0x95,0x1C,0xA4,0x17,0xA2,0x4A,0xCF,0x93 } }; // 90499A19-7EF2-4523-951C-A417A24ACF93
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>{ 0x1E2BA861,0x8533,0x4FCE,{ 0x83,0x9B,0xEC,0xB7,0x24,0x10,0xAC,0x14 } }; // 1E2BA861-8533-4FCE-839B-ECB72410AC14
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2>{ 0x14D981A3,0xFC26,0x4FF7,{ 0xAB,0xC3,0x48,0xE8,0x2A,0x51,0x2A,0x0A } }; // 14D981A3-FC26-4FF7-ABC3-48E82A512A0A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>{ 0x9F4CBBB4,0x8CBA,0x48B0,{ 0x84,0x0D,0xDB,0xB2,0x2A,0x54,0xC6,0x78 } }; // 9F4CBBB4-8CBA-48B0-840D-DBB22A54C678
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>{ 0xA4FE35F0,0xADE3,0x4981,{ 0xAF,0x6B,0xEC,0x19,0x59,0x21,0x68,0x2A } }; // A4FE35F0-ADE3-4981-AF6B-EC195921682A
    template <> inline constexpr guid guid_v<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>{ 0x1ADF0F65,0xE3B7,0x4155,{ 0x99,0x7F,0xB7,0x56,0xEF,0x65,0xBE,0xBA } }; // 1ADF0F65-E3B7-4155-997F-B756EF65BEBA
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration; };
    template <> struct default_interface<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>{ using type = llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult; };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ServiceAuthenticationHmac(void**) noexcept = 0;
            virtual int32_t __stdcall get_SessionNonce(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceNonce(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceConfigurationData(void**) noexcept = 0;
            virtual int32_t __stdcall FinishAuthenticationAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall AbortAuthenticationAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Authentication(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_StageInfo(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Stage(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Scenario(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ShowNotificationMessageAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall StartAuthenticationAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall add_AuthenticationStageChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AuthenticationStageChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall GetAuthenticationStageInfoAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RegisterDevicePresenceMonitoringAsync(void*, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RegisterDevicePresenceMonitoringWithNewDeviceAsync(void*, void*, int32_t, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnregisterDevicePresenceMonitoringAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall IsDevicePresenceMonitoringSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceFriendlyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceModelNumber(void**) noexcept = 0;
            virtual int32_t __stdcall get_DeviceConfigurationData(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PresenceMonitoringMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall UpdateDevicePresenceAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_IsAuthenticationSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FinishRegisteringDeviceAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall AbortRegisteringDeviceAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Registration(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestStartRegisteringDeviceAsync(void*, uint32_t, void*, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAllRegisteredDeviceInfoAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall UnregisterDeviceAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UpdateDeviceConfigurationDataAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) ServiceAuthenticationHmac() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) SessionNonce() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DeviceNonce() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DeviceConfigurationData() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorFinishAuthenticationStatus>) FinishAuthenticationAsync(llm:OS::Storage::Streams::IBuffer const& deviceHmac, llm:OS::Storage::Streams::IBuffer const& sessionHmac) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) AbortAuthenticationAsync(param::hstring const& errorLogMessage) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthentication<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthentication) Authentication() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo) StageInfo() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStage) Stage() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationScenario) Scenario() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStageInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) ShowNotificationMessageAsync(param::hstring const& deviceName, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage const& message) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationResult>) StartAuthenticationAsync(param::hstring const& deviceId, llm:OS::Storage::Streams::IBuffer const& serviceAuthenticationNonce) const;
        LLM_IMPL_AUTO(llm::event_token) AuthenticationStageChanged(llm:OS::Foundation::EventHandler<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler) const;
        using AuthenticationStageChanged_revoker = impl::event_revoker<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics, &impl::abi_t<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>::remove_AuthenticationStageChanged>;
        [[nodiscard]] AuthenticationStageChanged_revoker AuthenticationStageChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AuthenticationStageChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageInfo>) GetAuthenticationStageInfoAsync() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorAuthenticationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>) RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatus>) RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm:OS::Storage::Streams::IBuffer const& deviceConfigurationData) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UnregisterDevicePresenceMonitoringAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(bool) IsDevicePresenceMonitoringSupported() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceFriendlyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceModelNumber() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Storage::Streams::IBuffer) DeviceConfigurationData() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode) PresenceMonitoringMode() const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UpdateDevicePresenceAsync(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresence const& presenceState) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAuthenticationSupported() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistration
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) FinishRegisteringDeviceAsync(llm:OS::Storage::Streams::IBuffer const& deviceConfigurationData) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) AbortRegisteringDeviceAsync(param::hstring const& errorLogMessage) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistration<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistration) Registration() const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationResult<D>;
    };
    template <typename D>
    struct consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationStatics
    {
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorRegistrationResult>) RequestStartRegisteringDeviceAsync(param::hstring const& deviceId, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities const& capabilities, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm:OS::Storage::Streams::IBuffer const& deviceKey, llm:OS::Storage::Streams::IBuffer const& mutualAuthenticationKey) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncOperation<llm:OS::Foundation::Collections::IVectorView<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorInfo>>) FindAllRegisteredDeviceInfoAsync(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope const& queryType) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UnregisterDeviceAsync(param::hstring const& deviceId) const;
        LLM_IMPL_AUTO(llm:OS::Foundation::IAsyncAction) UpdateDeviceConfigurationDataAsync(param::hstring const& deviceId, llm:OS::Storage::Streams::IBuffer const& deviceConfigurationData) const;
    };
    template <> struct consume<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationStatics>
    {
        template <typename D> using type = consume_Windows_Security_Authentication_Identity_Provider_ISecondaryAuthenticationFactorRegistrationStatics<D>;
    };
}
#endif
