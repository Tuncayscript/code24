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
#ifndef LLM_OS_ApplicationModel_ConversationalAgent_0_H
#define LLM_OS_ApplicationModel_ConversationalAgent_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
}
LLM_EXPORT namespace llm::OS::Media::Audio
{
    struct AudioDeviceInputNode;
    struct AudioGraph;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IInputStream;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::ConversationalAgent
{
    enum class ActivationSignalDetectionConfigurationCreationStatus : int32_t
    {
        Success = 0,
        SignalIdNotAvailable = 1,
        ModelIdNotSupported = 2,
        InvalidSignalId = 3,
        InvalidModelId = 4,
        InvalidDisplayName = 5,
        ConfigurationAlreadyExists = 6,
        CreationNotSupported = 7,
    };
    enum class ActivationSignalDetectionConfigurationRemovalResult : int32_t
    {
        Success = 0,
        NotFound = 1,
        CurrentlyEnabled = 2,
        RemovalNotSupported = 3,
    };
    enum class ActivationSignalDetectionConfigurationSetModelDataResult : int32_t
    {
        Success = 0,
        EmptyModelData = 1,
        UnsupportedFormat = 2,
        ConfigurationCurrentlyEnabled = 3,
        InvalidData = 4,
        SetModelDataNotSupported = 5,
        ConfigurationNotFound = 6,
        UnknownError = 7,
    };
    enum class ActivationSignalDetectionConfigurationStateChangeResult : int32_t
    {
        Success = 0,
        NoModelData = 1,
        ConfigurationNotFound = 2,
    };
    enum class ActivationSignalDetectionTrainingDataFormat : int32_t
    {
        Voice8kHz8BitMono = 0,
        Voice8kHz16BitMono = 1,
        Voice16kHz8BitMono = 2,
        Voice16kHz16BitMono = 3,
        VoiceOEMDefined = 4,
        Audio44kHz8BitMono = 5,
        Audio44kHz16BitMono = 6,
        Audio48kHz8BitMono = 7,
        Audio48kHz16BitMono = 8,
        AudioOEMDefined = 9,
        OtherOEMDefined = 10,
    };
    enum class ActivationSignalDetectorKind : int32_t
    {
        AudioPattern = 0,
        AudioImpulse = 1,
        HardwareEvent = 2,
    };
    enum class ActivationSignalDetectorPowerState : int32_t
    {
        HighPower = 0,
        ConnectedLowPower = 1,
        DisconnectedLowPower = 2,
    };
    enum class ConversationalAgentActivationKind : int32_t
    {
        VoiceActivationPreview = 0,
        Foreground = 1,
    };
    enum class ConversationalAgentActivationResult : int32_t
    {
        Success = 0,
        AgentInactive = 1,
        ScreenNotAvailable = 2,
        AgentInterrupted = 3,
    };
    enum class ConversationalAgentSessionUpdateResponse : int32_t
    {
        Success = 0,
        Failed = 1,
    };
    enum class ConversationalAgentState : int32_t
    {
        Inactive = 0,
        Detecting = 1,
        Listening = 2,
        Working = 3,
        Speaking = 4,
        ListeningAndSpeaking = 5,
    };
    enum class ConversationalAgentSystemStateChangeType : int32_t
    {
        UserAuthentication = 0,
        ScreenAvailability = 1,
        IndicatorLightAvailability = 2,
        VoiceActivationAvailability = 3,
    };
    enum class ConversationalAgentVoiceActivationPrerequisiteKind : int32_t
    {
        MicrophonePermission = 0,
        KnownAgents = 1,
        AgentAllowed = 2,
        AppCapability = 3,
        BackgroundTaskRegistration = 4,
        PolicyPermission = 5,
    };
    enum class DetectionConfigurationAvailabilityChangeKind : int32_t
    {
        SystemResourceAccess = 0,
        Permission = 1,
        LockScreenPermission = 2,
    };
    enum class DetectionConfigurationTrainingStatus : int32_t
    {
        Success = 0,
        FormatNotSupported = 1,
        VoiceTooQuiet = 2,
        VoiceTooLoud = 3,
        VoiceTooFast = 4,
        VoiceTooSlow = 5,
        VoiceQualityProblem = 6,
        TrainingSystemInternalError = 7,
        TrainingTimedOut = 8,
        ConfigurationNotFound = 9,
    };
    enum class SignalDetectorResourceKind : int32_t
    {
        ParallelModelSupport = 0,
        ParallelModelSupportForAgent = 1,
        ParallelSignalSupport = 2,
        ParallelSignalSupportForAgent = 3,
        DisplayOffSupport = 4,
        PluggedInPower = 5,
        Detector = 6,
        SupportedSleepState = 7,
        SupportedBatterySaverState = 8,
        ScreenAvailability = 9,
        InputHardware = 10,
        AcousticEchoCancellation = 11,
        ModelIdSupport = 12,
        DataChannel = 13,
    };
    struct IActivationSignalDetectionConfiguration;
    struct IActivationSignalDetectionConfiguration2;
    struct IActivationSignalDetectionConfigurationCreationResult;
    struct IActivationSignalDetector;
    struct IActivationSignalDetector2;
    struct IConversationalAgentDetectorManager;
    struct IConversationalAgentDetectorManager2;
    struct IConversationalAgentDetectorManagerStatics;
    struct IConversationalAgentSession;
    struct IConversationalAgentSession2;
    struct IConversationalAgentSessionInterruptedEventArgs;
    struct IConversationalAgentSessionStatics;
    struct IConversationalAgentSignal;
    struct IConversationalAgentSignal2;
    struct IConversationalAgentSignalDetectedEventArgs;
    struct IConversationalAgentSystemStateChangedEventArgs;
    struct IDetectionConfigurationAvailabilityChangedEventArgs;
    struct IDetectionConfigurationAvailabilityInfo;
    struct IDetectionConfigurationAvailabilityInfo2;
    struct ActivationSignalDetectionConfiguration;
    struct ActivationSignalDetectionConfigurationCreationResult;
    struct ActivationSignalDetector;
    struct ConversationalAgentDetectorManager;
    struct ConversationalAgentSession;
    struct ConversationalAgentSessionInterruptedEventArgs;
    struct ConversationalAgentSignal;
    struct ConversationalAgentSignalDetectedEventArgs;
    struct ConversationalAgentSystemStateChangedEventArgs;
    struct DetectionConfigurationAvailabilityChangedEventArgs;
    struct DetectionConfigurationAvailabilityInfo;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorPowerState>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangeType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangeKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::ConversationalAgent::SignalDetectorResourceKind>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionConfigurationCreationResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetector";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentDetectorManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSession";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSessionInterruptedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSignal";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSignalDetectedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSystemStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.DetectionConfigurationAvailabilityChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo> = L"Windows.ApplicationModel.ConversationalAgent.DetectionConfigurationAvailabilityInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationStatus> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionConfigurationCreationStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionConfigurationRemovalResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionConfigurationSetModelDataResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionConfigurationStateChangeResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectionTrainingDataFormat";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectorKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorPowerState> = L"Windows.ApplicationModel.ConversationalAgent.ActivationSignalDetectorPowerState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentActivationKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentActivationResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSessionUpdateResponse";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentState";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangeType> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentSystemStateChangeType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind> = L"Windows.ApplicationModel.ConversationalAgent.ConversationalAgentVoiceActivationPrerequisiteKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangeKind> = L"Windows.ApplicationModel.ConversationalAgent.DetectionConfigurationAvailabilityChangeKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus> = L"Windows.ApplicationModel.ConversationalAgent.DetectionConfigurationTrainingStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::SignalDetectorResourceKind> = L"Windows.ApplicationModel.ConversationalAgent.SignalDetectorResourceKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration> = L"Windows.ApplicationModel.ConversationalAgent.IActivationSignalDetectionConfiguration";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2> = L"Windows.ApplicationModel.ConversationalAgent.IActivationSignalDetectionConfiguration2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult> = L"Windows.ApplicationModel.ConversationalAgent.IActivationSignalDetectionConfigurationCreationResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector> = L"Windows.ApplicationModel.ConversationalAgent.IActivationSignalDetector";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2> = L"Windows.ApplicationModel.ConversationalAgent.IActivationSignalDetector2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentDetectorManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentDetectorManager2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentDetectorManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSession";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSession2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSessionInterruptedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSessionStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSignal";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSignal2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSignalDetectedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.IConversationalAgentSystemStateChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs> = L"Windows.ApplicationModel.ConversationalAgent.IDetectionConfigurationAvailabilityChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo> = L"Windows.ApplicationModel.ConversationalAgent.IDetectionConfigurationAvailabilityInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2> = L"Windows.ApplicationModel.ConversationalAgent.IDetectionConfigurationAvailabilityInfo2";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration>{ 0x40D8BE16,0x5217,0x581C,{ 0x9A,0xB2,0xCE,0x9B,0x2F,0x2E,0x8E,0x00 } }; // 40D8BE16-5217-581C-9AB2-CE9B2F2E8E00
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2>{ 0x71D9B022,0x562C,0x57CE,{ 0xA7,0x8B,0x8B,0x4F,0xF0,0x14,0x5B,0xAB } }; // 71D9B022-562C-57CE-A78B-8B4FF0145BAB
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult>{ 0x4C89BC1B,0x8D12,0x5E48,{ 0xA7,0x1C,0x7F,0x6B,0xC1,0xCD,0x66,0xE0 } }; // 4C89BC1B-8D12-5E48-A71C-7F6BC1CD66E0
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector>{ 0xB5BF345F,0xA4D0,0x5B2B,{ 0x8E,0x65,0xB3,0xC5,0x5E,0xE7,0x56,0xFF } }; // B5BF345F-A4D0-5B2B-8E65-B3C55EE756FF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2>{ 0xC7E2490A,0xBAA5,0x59D2,{ 0x85,0xD1,0xBA,0x42,0xF7,0xCF,0x78,0xC9 } }; // C7E2490A-BAA5-59D2-85D1-BA42F7CF78C9
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager>{ 0xDE94FBB0,0x597A,0x5DF8,{ 0x8C,0xFB,0x9D,0xBB,0x58,0x3B,0xA3,0xFF } }; // DE94FBB0-597A-5DF8-8CFB-9DBB583BA3FF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2>{ 0x84610F31,0xD7F3,0x52FE,{ 0x93,0x11,0xC9,0xEB,0x4E,0x3E,0xB3,0x0A } }; // 84610F31-D7F3-52FE-9311-C9EB4E3EB30A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics>{ 0x36A8D283,0xFA0E,0x5693,{ 0x84,0x89,0x0F,0xB2,0xF0,0xAB,0x40,0xD3 } }; // 36A8D283-FA0E-5693-8489-0FB2F0AB40D3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>{ 0xDAAAE09A,0xB7BA,0x57E5,{ 0xAD,0x13,0xDF,0x52,0x0F,0x9B,0x6F,0xA7 } }; // DAAAE09A-B7BA-57E5-AD13-DF520F9B6FA7
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2>{ 0xA7A9FBF9,0xAC78,0x57FF,{ 0x95,0x96,0xAC,0xC7,0xA1,0xC9,0xA6,0x07 } }; // A7A9FBF9-AC78-57FF-9596-ACC7A1C9A607
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs>{ 0x9766591F,0xF63D,0x5D3E,{ 0x9B,0xF2,0xBD,0x07,0x60,0x55,0x26,0x86 } }; // 9766591F-F63D-5D3E-9BF2-BD0760552686
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics>{ 0xA005166E,0xE954,0x576E,{ 0xBE,0x04,0x11,0xB8,0xED,0x10,0xF3,0x7B } }; // A005166E-E954-576E-BE04-11B8ED10F37B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal>{ 0x20ED25F7,0xB120,0x51F2,{ 0x86,0x03,0x26,0x5D,0x6A,0x47,0xF2,0x32 } }; // 20ED25F7-B120-51F2-8603-265D6A47F232
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2>{ 0xD0CC7BA9,0x9A7B,0x5C34,{ 0x88,0x0E,0xB6,0x14,0x6C,0x90,0x4E,0xCB } }; // D0CC7BA9-9A7B-5C34-880E-B6146C904ECB
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs>{ 0x4D57EB8F,0xF88A,0x599B,{ 0x91,0xD3,0xD6,0x04,0x87,0x67,0x08,0xBC } }; // 4D57EB8F-F88A-599B-91D3-D604876708BC
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs>{ 0x1C2C6E3E,0x2785,0x59A7,{ 0x8E,0x71,0x38,0xAD,0xEE,0xF7,0x99,0x28 } }; // 1C2C6E3E-2785-59A7-8E71-38ADEEF79928
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs>{ 0x5129C9FB,0x4BE8,0x5F14,{ 0xAF,0x2B,0x88,0xD6,0x2B,0x1B,0x44,0x62 } }; // 5129C9FB-4BE8-5F14-AF2B-88D62B1B4462
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo>{ 0xB5AFFEB0,0x40F0,0x5398,{ 0xB8,0x38,0x91,0x97,0x9C,0x2C,0x62,0x08 } }; // B5AFFEB0-40F0-5398-B838-91979C2C6208
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2>{ 0x30E06433,0x38B3,0x5C4B,{ 0x84,0xC3,0x62,0xB6,0xE6,0x85,0xB2,0xFF } }; // 30E06433-38B3-5C4B-84C3-62B6E685B2FF
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo>{ using type = llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo; };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SignalId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ModelId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsActive(bool*) noexcept = 0;
            virtual int32_t __stdcall SetEnabled(bool) noexcept = 0;
            virtual int32_t __stdcall SetEnabledAsync(bool, void**) noexcept = 0;
            virtual int32_t __stdcall get_AvailabilityInfo(void**) noexcept = 0;
            virtual int32_t __stdcall add_AvailabilityChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_AvailabilityChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall SetModelData(void*, void*) noexcept = 0;
            virtual int32_t __stdcall SetModelDataAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetModelDataType(void**) noexcept = 0;
            virtual int32_t __stdcall GetModelDataTypeAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetModelData(void**) noexcept = 0;
            virtual int32_t __stdcall GetModelDataAsync(void**) noexcept = 0;
            virtual int32_t __stdcall ClearModelData() noexcept = 0;
            virtual int32_t __stdcall ClearModelDataAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_TrainingStepsCompleted(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TrainingStepsRemaining(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TrainingDataFormat(int32_t*) noexcept = 0;
            virtual int32_t __stdcall ApplyTrainingData(int32_t, void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall ApplyTrainingDataAsync(int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ClearTrainingData() noexcept = 0;
            virtual int32_t __stdcall ClearTrainingDataAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetModelDataWithResult(void*, void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetModelDataWithResultAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall SetEnabledWithResultAsync(bool, void**) noexcept = 0;
            virtual int32_t __stdcall SetEnabledWithResult(bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_TrainingStepCompletionMaxAllowedTime(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Configuration(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ProviderId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_CanCreateConfigurations(bool*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedModelDataTypes(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedTrainingDataFormats(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedPowerStates(void**) noexcept = 0;
            virtual int32_t __stdcall GetSupportedModelIdsForSignalId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetSupportedModelIdsForSignalIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateConfiguration(void*, void*, void*) noexcept = 0;
            virtual int32_t __stdcall CreateConfigurationAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetConfigurations(void**) noexcept = 0;
            virtual int32_t __stdcall GetConfigurationsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetConfiguration(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetConfigurationAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RemoveConfiguration(void*, void*) noexcept = 0;
            virtual int32_t __stdcall RemoveConfigurationAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAvailableModelIdsForSignalIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAvailableModelIdsForSignalId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateConfigurationWithResultAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateConfigurationWithResult(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RemoveConfigurationWithResultAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RemoveConfigurationWithResult(void*, void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_DetectorId(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAllActivationSignalDetectors(void**) noexcept = 0;
            virtual int32_t __stdcall GetAllActivationSignalDetectorsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetActivationSignalDetectors(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall GetActivationSignalDetectorsAsync(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetActivationSignalDetectorFromId(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetActivationSignalDetectorFromIdAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Default(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_SessionInterrupted(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SessionInterrupted(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_SignalDetected(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SignalDetected(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_SystemStateChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SystemStateChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_AgentState(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Signal(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsIndicatorLightAvailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsScreenAvailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsUserAuthenticated(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsVoiceActivationAvailable(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsInterruptible(bool*) noexcept = 0;
            virtual int32_t __stdcall get_IsInterrupted(bool*) noexcept = 0;
            virtual int32_t __stdcall RequestInterruptibleAsync(bool, void**) noexcept = 0;
            virtual int32_t __stdcall RequestInterruptible(bool, int32_t*) noexcept = 0;
            virtual int32_t __stdcall RequestAgentStateChangeAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestAgentStateChange(int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall RequestForegroundActivationAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestForegroundActivation(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetAudioClientAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioClient(void**) noexcept = 0;
            virtual int32_t __stdcall CreateAudioDeviceInputNodeAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateAudioDeviceInputNode(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioCaptureDeviceIdAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioCaptureDeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioRenderDeviceIdAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAudioRenderDeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall GetSignalModelIdAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetSignalModelId(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall SetSignalModelIdAsync(uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SetSignalModelId(uint32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall GetSupportedSignalModelIdsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetSupportedSignalModelIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestActivationAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestActivation(int32_t, int32_t*) noexcept = 0;
            virtual int32_t __stdcall SetSupportLockScreenActivationAsync(bool, void**) noexcept = 0;
            virtual int32_t __stdcall SetSupportLockScreenActivation(bool) noexcept = 0;
            virtual int32_t __stdcall GetMissingPrerequisites(void**) noexcept = 0;
            virtual int32_t __stdcall GetMissingPrerequisitesAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetCurrentSessionAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetCurrentSessionSync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsSignalVerificationRequired(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsSignalVerificationRequired(bool) noexcept = 0;
            virtual int32_t __stdcall get_SignalId(void**) noexcept = 0;
            virtual int32_t __stdcall put_SignalId(void*) noexcept = 0;
            virtual int32_t __stdcall get_SignalName(void**) noexcept = 0;
            virtual int32_t __stdcall put_SignalName(void*) noexcept = 0;
            virtual int32_t __stdcall get_SignalContext(void**) noexcept = 0;
            virtual int32_t __stdcall put_SignalContext(void*) noexcept = 0;
            virtual int32_t __stdcall get_SignalStart(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_SignalStart(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_SignalEnd(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_SignalEnd(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DetectorId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DetectorKind(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SystemStateChangeType(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsEnabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HasSystemResourceAccess(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HasPermission(bool*) noexcept = 0;
            virtual int32_t __stdcall get_HasLockScreenPermission(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UnavailableSystemResources(void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SignalId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ModelId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsActive() const;
        LLM_IMPL_AUTO(void) SetEnabled(bool value) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetEnabledAsync(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo) AvailabilityInfo() const;
        LLM_IMPL_AUTO(llm::event_token) AvailabilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration, llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> const& handler) const;
        using AvailabilityChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration, &impl::abi_t<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration>::remove_AvailabilityChanged>;
        [[nodiscard]] AvailabilityChanged_revoker AvailabilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration, llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) AvailabilityChanged(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(void) SetModelData(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetModelDataAsync(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const;
        LLM_IMPL_AUTO(hstring) GetModelDataType() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetModelDataTypeAsync() const;
        LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) GetModelData() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>) GetModelDataAsync() const;
        LLM_IMPL_AUTO(void) ClearModelData() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ClearModelDataAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TrainingStepsCompleted() const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TrainingStepsRemaining() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat) TrainingDataFormat() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus) ApplyTrainingData(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat const& trainingDataFormat, llm::OS::Storage::Streams::IInputStream const& trainingData) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus>) ApplyTrainingDataAsync(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat const& trainingDataFormat, llm::OS::Storage::Streams::IInputStream const& trainingData) const;
        LLM_IMPL_AUTO(void) ClearTrainingData() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ClearTrainingDataAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult) SetModelDataWithResult(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult>) SetModelDataWithResultAsync(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult>) SetEnabledWithResultAsync(bool value) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult) SetEnabledWithResult(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) TrainingStepCompletionMaxAllowedTime() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfigurationCreationResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration) Configuration() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfigurationCreationResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProviderId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind) Kind() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanCreateConfigurations() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) SupportedModelDataTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat>) SupportedTrainingDataFormats() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorPowerState>) SupportedPowerStates() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) GetSupportedModelIdsForSignalId(param::hstring const& signalId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>) GetSupportedModelIdsForSignalIdAsync(param::hstring const& signalId) const;
        LLM_IMPL_AUTO(void) CreateConfiguration(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) CreateConfigurationAsync(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>) GetConfigurations() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>>) GetConfigurationsAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration) GetConfiguration(param::hstring const& signalId, param::hstring const& modelId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>) GetConfigurationAsync(param::hstring const& signalId, param::hstring const& modelId) const;
        LLM_IMPL_AUTO(void) RemoveConfiguration(param::hstring const& signalId, param::hstring const& modelId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) RemoveConfigurationAsync(param::hstring const& signalId, param::hstring const& modelId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<hstring>>) GetAvailableModelIdsForSignalIdAsync(param::hstring const& signalId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) GetAvailableModelIdsForSignalId(param::hstring const& signalId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>) CreateConfigurationWithResultAsync(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult) CreateConfigurationWithResult(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult>) RemoveConfigurationWithResultAsync(param::hstring const& signalId, param::hstring const& modelId) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult) RemoveConfigurationWithResult(param::hstring const& signalId, param::hstring const& modelId) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DetectorId() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>) GetAllActivationSignalDetectors() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>) GetAllActivationSignalDetectorsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>) GetActivationSignalDetectors(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind const& kind) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>) GetActivationSignalDetectorsAsync(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind const& kind) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager2
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector) GetActivationSignalDetectorFromId(param::hstring const& detectorId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>) GetActivationSignalDetectorFromIdAsync(param::hstring const& detectorId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManagerStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager) Default() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession
    {
        LLM_IMPL_AUTO(llm::event_token) SessionInterrupted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> const& handler) const;
        using SessionInterrupted_revoker = impl::event_revoker<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession, &impl::abi_t<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>::remove_SessionInterrupted>;
        [[nodiscard]] SessionInterrupted_revoker SessionInterrupted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) SessionInterrupted(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) SignalDetected(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> const& handler) const;
        using SignalDetected_revoker = impl::event_revoker<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession, &impl::abi_t<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>::remove_SignalDetected>;
        [[nodiscard]] SignalDetected_revoker SignalDetected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) SignalDetected(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) SystemStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> const& handler) const;
        using SystemStateChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession, &impl::abi_t<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>::remove_SystemStateChanged>;
        [[nodiscard]] SystemStateChanged_revoker SystemStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) SystemStateChanged(llm::event_token const& token) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState) AgentState() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal) Signal() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsIndicatorLightAvailable() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsScreenAvailable() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsUserAuthenticated() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsVoiceActivationAvailable() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsInterruptible() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsInterrupted() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>) RequestInterruptibleAsync(bool interruptible) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse) RequestInterruptible(bool interruptible) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>) RequestAgentStateChangeAsync(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState const& state) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse) RequestAgentStateChange(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState const& state) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>) RequestForegroundActivationAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse) RequestForegroundActivation() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>) GetAudioClientAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) GetAudioClient() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Audio::AudioDeviceInputNode>) CreateAudioDeviceInputNodeAsync(llm::OS::Media::Audio::AudioGraph const& graph) const;
        LLM_IMPL_AUTO(llm::OS::Media::Audio::AudioDeviceInputNode) CreateAudioDeviceInputNode(llm::OS::Media::Audio::AudioGraph const& graph) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetAudioCaptureDeviceIdAsync() const;
        LLM_IMPL_AUTO(hstring) GetAudioCaptureDeviceId() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetAudioRenderDeviceIdAsync() const;
        LLM_IMPL_AUTO(hstring) GetAudioRenderDeviceId() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) GetSignalModelIdAsync() const;
        LLM_IMPL_AUTO(uint32_t) GetSignalModelId() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) SetSignalModelIdAsync(uint32_t signalModelId) const;
        LLM_IMPL_AUTO(bool) SetSignalModelId(uint32_t signalModelId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<uint32_t>>) GetSupportedSignalModelIdsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) GetSupportedSignalModelIds() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult>) RequestActivationAsync(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind const& activationKind) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult) RequestActivation(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind const& activationKind) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetSupportLockScreenActivationAsync(bool lockScreenActivationSupported) const;
        LLM_IMPL_AUTO(void) SetSupportLockScreenActivation(bool lockScreenActivationSupported) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>) GetMissingPrerequisites() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>>) GetMissingPrerequisitesAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSessionInterruptedEventArgs
    {
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSessionInterruptedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSessionStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>) GetCurrentSessionAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession) GetCurrentSessionSync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSessionStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsSignalVerificationRequired() const;
        LLM_IMPL_AUTO(void) IsSignalVerificationRequired(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SignalId() const;
        LLM_IMPL_AUTO(void) SignalId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SignalName() const;
        LLM_IMPL_AUTO(void) SignalName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) SignalContext() const;
        LLM_IMPL_AUTO(void) SignalContext(llm::OS::Foundation::IInspectable const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) SignalStart() const;
        LLM_IMPL_AUTO(void) SignalStart(llm::OS::Foundation::TimeSpan const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) SignalEnd() const;
        LLM_IMPL_AUTO(void) SignalEnd(llm::OS::Foundation::TimeSpan const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DetectorId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind) DetectorKind() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignalDetectedEventArgs
    {
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignalDetectedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSystemStateChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangeType) SystemStateChangeType() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSystemStateChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityChangedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangeKind) Kind() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsEnabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasSystemResourceAccess() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasPermission() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) HasLockScreenPermission() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::SignalDetectorResourceKind>) UnavailableSystemResources() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo2<D>;
    };
}
#endif
