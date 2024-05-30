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
#ifndef LLM_OS_Devices_SmartCards_0_H
#define LLM_OS_Devices_SmartCards_0_H
LLM_EXPORT namespace llm::OS::Foundation
{
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
    struct ValueSet;
}
LLM_EXPORT namespace llm::OS::Security::Cryptography::Core
{
    enum class CryptographicPublicKeyBlobType : int32_t;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IBuffer;
    struct IRandomAccessStreamReference;
}
LLM_EXPORT namespace llm::OS::Devices::SmartCards
{
    enum class SmartCardActivationPolicyChangeResult : int32_t
    {
        Denied = 0,
        Allowed = 1,
    };
    enum class SmartCardAppletIdGroupActivationPolicy : int32_t
    {
        Disabled = 0,
        ForegroundOverride = 1,
        Enabled = 2,
    };
    enum class SmartCardAutomaticResponseStatus : int32_t
    {
        None = 0,
        Success = 1,
        UnknownError = 2,
    };
    enum class SmartCardCryptogramAlgorithm : int32_t
    {
        None = 0,
        CbcMac = 1,
        Cvc3Umd = 2,
        DecimalizedMsd = 3,
        Cvc3MD = 4,
        Sha1 = 5,
        SignedDynamicApplicationData = 6,
        RsaPkcs1 = 7,
        Sha256Hmac = 8,
    };
    enum class SmartCardCryptogramGeneratorOperationStatus : int32_t
    {
        Success = 0,
        AuthorizationFailed = 1,
        AuthorizationCanceled = 2,
        AuthorizationRequired = 3,
        CryptogramMaterialPackageStorageKeyExists = 4,
        NoCryptogramMaterialPackageStorageKey = 5,
        NoCryptogramMaterialPackage = 6,
        UnsupportedCryptogramMaterialPackage = 7,
        UnknownCryptogramMaterialName = 8,
        InvalidCryptogramMaterialUsage = 9,
        ApduResponseNotSent = 10,
        OtherError = 11,
        ValidationFailed = 12,
        NotSupported = 13,
    };
    enum class SmartCardCryptogramMaterialPackageConfirmationResponseFormat : int32_t
    {
        None = 0,
        VisaHmac = 1,
    };
    enum class SmartCardCryptogramMaterialPackageFormat : int32_t
    {
        None = 0,
        JweRsaPki = 1,
    };
    enum class SmartCardCryptogramMaterialProtectionMethod : int32_t
    {
        None = 0,
        WhiteBoxing = 1,
    };
    enum class SmartCardCryptogramMaterialType : int32_t
    {
        None = 0,
        StaticDataAuthentication = 1,
        TripleDes112 = 2,
        Aes = 3,
        RsaPkcs1 = 4,
    };
    enum class SmartCardCryptogramPlacementOptions : uint32_t
    {
        None = 0,
        UnitsAreInNibbles = 0x1,
        ChainOutput = 0x2,
    };
    enum class SmartCardCryptogramStorageKeyAlgorithm : int32_t
    {
        None = 0,
        Rsa2048 = 1,
    };
    enum class SmartCardCryptogramStorageKeyCapabilities : uint32_t
    {
        None = 0,
        HardwareProtection = 0x1,
        UnlockPrompt = 0x2,
    };
    enum class SmartCardCryptographicKeyAttestationStatus : int32_t
    {
        NoAttestation = 0,
        SoftwareKeyWithoutTpm = 1,
        SoftwareKeyWithTpm = 2,
        TpmKeyUnknownAttestationStatus = 3,
        TpmKeyWithoutAttestationCapability = 4,
        TpmKeyWithTemporaryAttestationFailure = 5,
        TpmKeyWithLongTermAttestationFailure = 6,
        TpmKeyWithAttestation = 7,
    };
    enum class SmartCardEmulationCategory : int32_t
    {
        Other = 0,
        Payment = 1,
    };
    enum class SmartCardEmulationType : int32_t
    {
        Host = 0,
        Uicc = 1,
        EmbeddedSE = 2,
    };
    enum class SmartCardEmulatorConnectionDeactivatedReason : int32_t
    {
        ConnectionLost = 0,
        ConnectionRedirected = 1,
    };
    enum class SmartCardEmulatorConnectionSource : int32_t
    {
        Unknown = 0,
        NfcReader = 1,
    };
    enum class SmartCardEmulatorEnablementPolicy : int32_t
    {
        Never = 0,
        Always = 1,
        ScreenOn = 2,
        ScreenUnlocked = 3,
    };
    enum class SmartCardLaunchBehavior : int32_t
    {
        Default = 0,
        AboveLock = 1,
    };
    enum class SmartCardPinCharacterPolicyOption : int32_t
    {
        Allow = 0,
        RequireAtLeastOne = 1,
        Disallow = 2,
    };
    enum class SmartCardReaderKind : int32_t
    {
        Any = 0,
        Generic = 1,
        Tpm = 2,
        Nfc = 3,
        Uicc = 4,
        EmbeddedSE = 5,
    };
    enum class SmartCardReaderStatus : int32_t
    {
        Disconnected = 0,
        Ready = 1,
        Exclusive = 2,
    };
    enum class SmartCardStatus : int32_t
    {
        Disconnected = 0,
        Ready = 1,
        Shared = 2,
        Exclusive = 3,
        Unresponsive = 4,
    };
    enum class SmartCardTriggerType : int32_t
    {
        EmulatorTransaction = 0,
        EmulatorNearFieldEntry = 1,
        EmulatorNearFieldExit = 2,
        EmulatorHostApplicationActivated = 3,
        EmulatorAppletIdGroupRegistrationChanged = 4,
        ReaderCardAdded = 5,
    };
    enum class SmartCardUnlockPromptingBehavior : int32_t
    {
        AllowUnlockPrompt = 0,
        RequireUnlockPrompt = 1,
        PreventUnlockPrompt = 2,
    };
    struct ICardAddedEventArgs;
    struct ICardRemovedEventArgs;
    struct IKnownSmartCardAppletIds;
    struct ISmartCard;
    struct ISmartCardAppletIdGroup;
    struct ISmartCardAppletIdGroup2;
    struct ISmartCardAppletIdGroupFactory;
    struct ISmartCardAppletIdGroupRegistration;
    struct ISmartCardAppletIdGroupRegistration2;
    struct ISmartCardAppletIdGroupStatics;
    struct ISmartCardAutomaticResponseApdu;
    struct ISmartCardAutomaticResponseApdu2;
    struct ISmartCardAutomaticResponseApdu3;
    struct ISmartCardAutomaticResponseApduFactory;
    struct ISmartCardChallengeContext;
    struct ISmartCardConnect;
    struct ISmartCardConnection;
    struct ISmartCardCryptogramGenerator;
    struct ISmartCardCryptogramGenerator2;
    struct ISmartCardCryptogramGeneratorStatics;
    struct ISmartCardCryptogramGeneratorStatics2;
    struct ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult;
    struct ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult;
    struct ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult;
    struct ISmartCardCryptogramMaterialCharacteristics;
    struct ISmartCardCryptogramMaterialPackageCharacteristics;
    struct ISmartCardCryptogramMaterialPossessionProof;
    struct ISmartCardCryptogramPlacementStep;
    struct ISmartCardCryptogramStorageKeyCharacteristics;
    struct ISmartCardCryptogramStorageKeyInfo;
    struct ISmartCardCryptogramStorageKeyInfo2;
    struct ISmartCardEmulator;
    struct ISmartCardEmulator2;
    struct ISmartCardEmulatorApduReceivedEventArgs;
    struct ISmartCardEmulatorApduReceivedEventArgs2;
    struct ISmartCardEmulatorApduReceivedEventArgsWithCryptograms;
    struct ISmartCardEmulatorConnectionDeactivatedEventArgs;
    struct ISmartCardEmulatorConnectionProperties;
    struct ISmartCardEmulatorStatics;
    struct ISmartCardEmulatorStatics2;
    struct ISmartCardEmulatorStatics3;
    struct ISmartCardPinPolicy;
    struct ISmartCardPinResetDeferral;
    struct ISmartCardPinResetRequest;
    struct ISmartCardProvisioning;
    struct ISmartCardProvisioning2;
    struct ISmartCardProvisioningStatics;
    struct ISmartCardProvisioningStatics2;
    struct ISmartCardReader;
    struct ISmartCardReaderStatics;
    struct ISmartCardTriggerDetails;
    struct ISmartCardTriggerDetails2;
    struct ISmartCardTriggerDetails3;
    struct CardAddedEventArgs;
    struct CardRemovedEventArgs;
    struct KnownSmartCardAppletIds;
    struct SmartCard;
    struct SmartCardAppletIdGroup;
    struct SmartCardAppletIdGroupRegistration;
    struct SmartCardAutomaticResponseApdu;
    struct SmartCardChallengeContext;
    struct SmartCardConnection;
    struct SmartCardCryptogramGenerator;
    struct SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult;
    struct SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult;
    struct SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult;
    struct SmartCardCryptogramMaterialCharacteristics;
    struct SmartCardCryptogramMaterialPackageCharacteristics;
    struct SmartCardCryptogramMaterialPossessionProof;
    struct SmartCardCryptogramPlacementStep;
    struct SmartCardCryptogramStorageKeyCharacteristics;
    struct SmartCardCryptogramStorageKeyInfo;
    struct SmartCardEmulator;
    struct SmartCardEmulatorApduReceivedEventArgs;
    struct SmartCardEmulatorConnectionDeactivatedEventArgs;
    struct SmartCardEmulatorConnectionProperties;
    struct SmartCardPinPolicy;
    struct SmartCardPinResetDeferral;
    struct SmartCardPinResetRequest;
    struct SmartCardProvisioning;
    struct SmartCardReader;
    struct SmartCardTriggerDetails;
    struct SmartCardPinResetHandler;
}
namespace llm::impl
{
    template <> struct category<llm::OS::Devices::SmartCards::ICardAddedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ICardRemovedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::IKnownSmartCardAppletIds>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCard>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardChallengeContext>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardConnect>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardConnection>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulator>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulator2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics3>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardPinPolicy>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardPinResetRequest>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardProvisioning>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardProvisioning2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardReader>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardReaderStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails2>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails3>{ using type = interface_category; };
    template <> struct category<llm::OS::Devices::SmartCards::CardAddedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::CardRemovedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::KnownSmartCardAppletIds>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCard>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardAppletIdGroup>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardAutomaticResponseApdu>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardChallengeContext>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardConnection>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramGenerator>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialCharacteristics>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageCharacteristics>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCharacteristics>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulator>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionProperties>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardPinPolicy>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardPinResetDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardPinResetRequest>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardProvisioning>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardReader>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardTriggerDetails>{ using type = class_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardActivationPolicyChangeResult>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardAutomaticResponseStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialProtectionMethod>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialType>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementOptions>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulationCategory>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulationType>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionSource>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardEmulatorEnablementPolicy>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardLaunchBehavior>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardReaderKind>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardReaderStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardTriggerType>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior>{ using type = enum_category; };
    template <> struct category<llm::OS::Devices::SmartCards::SmartCardPinResetHandler>{ using type = delegate_category; };
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::CardAddedEventArgs> = L"Windows.Devices.SmartCards.CardAddedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::CardRemovedEventArgs> = L"Windows.Devices.SmartCards.CardRemovedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::KnownSmartCardAppletIds> = L"Windows.Devices.SmartCards.KnownSmartCardAppletIds";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCard> = L"Windows.Devices.SmartCards.SmartCard";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardAppletIdGroup> = L"Windows.Devices.SmartCards.SmartCardAppletIdGroup";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration> = L"Windows.Devices.SmartCards.SmartCardAppletIdGroupRegistration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardAutomaticResponseApdu> = L"Windows.Devices.SmartCards.SmartCardAutomaticResponseApdu";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardChallengeContext> = L"Windows.Devices.SmartCards.SmartCardChallengeContext";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardConnection> = L"Windows.Devices.SmartCards.SmartCardConnection";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramGenerator> = L"Windows.Devices.SmartCards.SmartCardCryptogramGenerator";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult> = L"Windows.Devices.SmartCards.SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult> = L"Windows.Devices.SmartCards.SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult> = L"Windows.Devices.SmartCards.SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialCharacteristics> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialCharacteristics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageCharacteristics> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialPackageCharacteristics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialPossessionProof";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep> = L"Windows.Devices.SmartCards.SmartCardCryptogramPlacementStep";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCharacteristics> = L"Windows.Devices.SmartCards.SmartCardCryptogramStorageKeyCharacteristics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo> = L"Windows.Devices.SmartCards.SmartCardCryptogramStorageKeyInfo";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulator> = L"Windows.Devices.SmartCards.SmartCardEmulator";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> = L"Windows.Devices.SmartCards.SmartCardEmulatorApduReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> = L"Windows.Devices.SmartCards.SmartCardEmulatorConnectionDeactivatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionProperties> = L"Windows.Devices.SmartCards.SmartCardEmulatorConnectionProperties";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardPinPolicy> = L"Windows.Devices.SmartCards.SmartCardPinPolicy";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardPinResetDeferral> = L"Windows.Devices.SmartCards.SmartCardPinResetDeferral";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardPinResetRequest> = L"Windows.Devices.SmartCards.SmartCardPinResetRequest";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardProvisioning> = L"Windows.Devices.SmartCards.SmartCardProvisioning";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardReader> = L"Windows.Devices.SmartCards.SmartCardReader";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardTriggerDetails> = L"Windows.Devices.SmartCards.SmartCardTriggerDetails";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardActivationPolicyChangeResult> = L"Windows.Devices.SmartCards.SmartCardActivationPolicyChangeResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy> = L"Windows.Devices.SmartCards.SmartCardAppletIdGroupActivationPolicy";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardAutomaticResponseStatus> = L"Windows.Devices.SmartCards.SmartCardAutomaticResponseStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm> = L"Windows.Devices.SmartCards.SmartCardCryptogramAlgorithm";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus> = L"Windows.Devices.SmartCards.SmartCardCryptogramGeneratorOperationStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialPackageConfirmationResponseFormat";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialPackageFormat";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialProtectionMethod> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialProtectionMethod";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialType> = L"Windows.Devices.SmartCards.SmartCardCryptogramMaterialType";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementOptions> = L"Windows.Devices.SmartCards.SmartCardCryptogramPlacementOptions";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm> = L"Windows.Devices.SmartCards.SmartCardCryptogramStorageKeyAlgorithm";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities> = L"Windows.Devices.SmartCards.SmartCardCryptogramStorageKeyCapabilities";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus> = L"Windows.Devices.SmartCards.SmartCardCryptographicKeyAttestationStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulationCategory> = L"Windows.Devices.SmartCards.SmartCardEmulationCategory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulationType> = L"Windows.Devices.SmartCards.SmartCardEmulationType";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason> = L"Windows.Devices.SmartCards.SmartCardEmulatorConnectionDeactivatedReason";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionSource> = L"Windows.Devices.SmartCards.SmartCardEmulatorConnectionSource";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardEmulatorEnablementPolicy> = L"Windows.Devices.SmartCards.SmartCardEmulatorEnablementPolicy";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardLaunchBehavior> = L"Windows.Devices.SmartCards.SmartCardLaunchBehavior";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption> = L"Windows.Devices.SmartCards.SmartCardPinCharacterPolicyOption";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardReaderKind> = L"Windows.Devices.SmartCards.SmartCardReaderKind";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardReaderStatus> = L"Windows.Devices.SmartCards.SmartCardReaderStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardStatus> = L"Windows.Devices.SmartCards.SmartCardStatus";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardTriggerType> = L"Windows.Devices.SmartCards.SmartCardTriggerType";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior> = L"Windows.Devices.SmartCards.SmartCardUnlockPromptingBehavior";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ICardAddedEventArgs> = L"Windows.Devices.SmartCards.ICardAddedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ICardRemovedEventArgs> = L"Windows.Devices.SmartCards.ICardRemovedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::IKnownSmartCardAppletIds> = L"Windows.Devices.SmartCards.IKnownSmartCardAppletIds";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCard> = L"Windows.Devices.SmartCards.ISmartCard";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup> = L"Windows.Devices.SmartCards.ISmartCardAppletIdGroup";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup2> = L"Windows.Devices.SmartCards.ISmartCardAppletIdGroup2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupFactory> = L"Windows.Devices.SmartCards.ISmartCardAppletIdGroupFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration> = L"Windows.Devices.SmartCards.ISmartCardAppletIdGroupRegistration";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration2> = L"Windows.Devices.SmartCards.ISmartCardAppletIdGroupRegistration2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupStatics> = L"Windows.Devices.SmartCards.ISmartCardAppletIdGroupStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu> = L"Windows.Devices.SmartCards.ISmartCardAutomaticResponseApdu";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu2> = L"Windows.Devices.SmartCards.ISmartCardAutomaticResponseApdu2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu3> = L"Windows.Devices.SmartCards.ISmartCardAutomaticResponseApdu3";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory> = L"Windows.Devices.SmartCards.ISmartCardAutomaticResponseApduFactory";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardChallengeContext> = L"Windows.Devices.SmartCards.ISmartCardChallengeContext";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardConnect> = L"Windows.Devices.SmartCards.ISmartCardConnect";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardConnection> = L"Windows.Devices.SmartCards.ISmartCardConnection";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGenerator";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator2> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGenerator2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGeneratorStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics2> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGeneratorStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult> = L"Windows.Devices.SmartCards.ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics> = L"Windows.Devices.SmartCards.ISmartCardCryptogramMaterialCharacteristics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics> = L"Windows.Devices.SmartCards.ISmartCardCryptogramMaterialPackageCharacteristics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof> = L"Windows.Devices.SmartCards.ISmartCardCryptogramMaterialPossessionProof";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep> = L"Windows.Devices.SmartCards.ISmartCardCryptogramPlacementStep";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics> = L"Windows.Devices.SmartCards.ISmartCardCryptogramStorageKeyCharacteristics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo> = L"Windows.Devices.SmartCards.ISmartCardCryptogramStorageKeyInfo";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2> = L"Windows.Devices.SmartCards.ISmartCardCryptogramStorageKeyInfo2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulator> = L"Windows.Devices.SmartCards.ISmartCardEmulator";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulator2> = L"Windows.Devices.SmartCards.ISmartCardEmulator2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs> = L"Windows.Devices.SmartCards.ISmartCardEmulatorApduReceivedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2> = L"Windows.Devices.SmartCards.ISmartCardEmulatorApduReceivedEventArgs2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms> = L"Windows.Devices.SmartCards.ISmartCardEmulatorApduReceivedEventArgsWithCryptograms";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs> = L"Windows.Devices.SmartCards.ISmartCardEmulatorConnectionDeactivatedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties> = L"Windows.Devices.SmartCards.ISmartCardEmulatorConnectionProperties";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics> = L"Windows.Devices.SmartCards.ISmartCardEmulatorStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics2> = L"Windows.Devices.SmartCards.ISmartCardEmulatorStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics3> = L"Windows.Devices.SmartCards.ISmartCardEmulatorStatics3";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardPinPolicy> = L"Windows.Devices.SmartCards.ISmartCardPinPolicy";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral> = L"Windows.Devices.SmartCards.ISmartCardPinResetDeferral";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardPinResetRequest> = L"Windows.Devices.SmartCards.ISmartCardPinResetRequest";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardProvisioning> = L"Windows.Devices.SmartCards.ISmartCardProvisioning";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardProvisioning2> = L"Windows.Devices.SmartCards.ISmartCardProvisioning2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics> = L"Windows.Devices.SmartCards.ISmartCardProvisioningStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics2> = L"Windows.Devices.SmartCards.ISmartCardProvisioningStatics2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardReader> = L"Windows.Devices.SmartCards.ISmartCardReader";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardReaderStatics> = L"Windows.Devices.SmartCards.ISmartCardReaderStatics";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails> = L"Windows.Devices.SmartCards.ISmartCardTriggerDetails";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails2> = L"Windows.Devices.SmartCards.ISmartCardTriggerDetails2";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails3> = L"Windows.Devices.SmartCards.ISmartCardTriggerDetails3";
    template <> inline constexpr auto& name_v<llm::OS::Devices::SmartCards::SmartCardPinResetHandler> = L"Windows.Devices.SmartCards.SmartCardPinResetHandler";
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ICardAddedEventArgs>{ 0x18BBEF98,0xF18B,0x4DD3,{ 0xB1,0x18,0xDF,0xB2,0xC8,0xE2,0x3C,0xC6 } }; // 18BBEF98-F18B-4DD3-B118-DFB2C8E23CC6
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ICardRemovedEventArgs>{ 0x15331AAF,0x22D7,0x4945,{ 0xAF,0xC9,0x03,0xB4,0x6F,0x42,0xA6,0xCD } }; // 15331AAF-22D7-4945-AFC9-03B46F42A6CD
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::IKnownSmartCardAppletIds>{ 0x7B04D8D8,0x95B4,0x4C88,{ 0x8C,0xEA,0x41,0x1E,0x55,0x51,0x1E,0xFC } }; // 7B04D8D8-95B4-4C88-8CEA-411E55511EFC
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCard>{ 0x1B718871,0x6434,0x43F4,{ 0xB5,0x5A,0x6A,0x29,0x62,0x38,0x70,0xAA } }; // 1B718871-6434-43F4-B55A-6A29623870AA
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup>{ 0x7DB165E6,0x6264,0x56F4,{ 0x5E,0x03,0xC8,0x63,0x85,0x39,0x5E,0xB1 } }; // 7DB165E6-6264-56F4-5E03-C86385395EB1
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup2>{ 0x6B0EF9DC,0x9956,0x4A62,{ 0x8D,0x4E,0xD3,0x7A,0x68,0xEB,0xC3,0xA6 } }; // 6B0EF9DC-9956-4A62-8D4E-D37A68EBC3A6
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupFactory>{ 0x9105EB4D,0x4A65,0x4E41,{ 0x80,0x61,0xCB,0xE8,0x3F,0x36,0x95,0xE5 } }; // 9105EB4D-4A65-4E41-8061-CBE83F3695E5
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>{ 0xDF1208D1,0x31BB,0x5596,{ 0x43,0xB1,0x6D,0x69,0xA0,0x25,0x7B,0x3A } }; // DF1208D1-31BB-5596-43B1-6D69A0257B3A
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration2>{ 0x5F5508D8,0x98A7,0x4F2E,{ 0x91,0xD9,0x6C,0xFC,0xCE,0xDA,0x40,0x7F } }; // 5F5508D8-98A7-4F2E-91D9-6CFCCEDA407F
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupStatics>{ 0xAB2899A9,0xE76C,0x45CF,{ 0xBF,0x1D,0x90,0xEA,0xA6,0x20,0x59,0x27 } }; // AB2899A9-E76C-45CF-BF1D-90EAA6205927
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu>{ 0x52152BAB,0xC63E,0x4531,{ 0xA8,0x57,0xD7,0x56,0xD9,0x9B,0x98,0x6A } }; // 52152BAB-C63E-4531-A857-D756D99B986A
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>{ 0x44AEBB14,0x559D,0x4531,{ 0x4E,0x51,0x89,0xDB,0x6F,0xA8,0xA5,0x7A } }; // 44AEBB14-559D-4531-4E51-89DB6FA8A57A
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>{ 0xBF43DA74,0x6576,0x4392,{ 0x93,0x67,0xFE,0x3B,0xC9,0xE2,0xD4,0x96 } }; // BF43DA74-6576-4392-9367-FE3BC9E2D496
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory>{ 0xE97EA2FA,0xD02C,0x4C55,{ 0xB0,0x2A,0x8C,0xFF,0x7F,0xA9,0xF0,0x5B } }; // E97EA2FA-D02C-4C55-B02A-8CFF7FA9F05B
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardChallengeContext>{ 0x192A5319,0xC9C4,0x4947,{ 0x81,0xCC,0x44,0x79,0x4A,0x61,0xEF,0x91 } }; // 192A5319-C9C4-4947-81CC-44794A61EF91
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardConnect>{ 0x2FDF87E5,0x028D,0x491E,{ 0xA0,0x58,0x33,0x82,0xC3,0x98,0x6F,0x40 } }; // 2FDF87E5-028D-491E-A058-3382C3986F40
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardConnection>{ 0x7EDB991A,0xA81A,0x47BC,{ 0xA6,0x49,0x15,0x6B,0xE6,0xB7,0xF2,0x31 } }; // 7EDB991A-A81A-47BC-A649-156BE6B7F231
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator>{ 0xE39F587B,0xEDD3,0x4E49,{ 0xB5,0x94,0x0F,0xF5,0xE4,0xD0,0xC7,0x6F } }; // E39F587B-EDD3-4E49-B594-0FF5E4D0C76F
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator2>{ 0x7116AA34,0x5D6D,0x4B4A,{ 0x96,0xA3,0xEF,0xA4,0x7D,0x2A,0x7E,0x25 } }; // 7116AA34-5D6D-4B4A-96A3-EFA47D2A7E25
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics>{ 0x09933910,0xCB9C,0x4015,{ 0x96,0x7D,0x52,0x34,0xF3,0xB0,0x29,0x00 } }; // 09933910-CB9C-4015-967D-5234F3B02900
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics2>{ 0x09BDF5E5,0xB4BD,0x4E23,{ 0xA5,0x88,0x74,0x46,0x92,0x04,0xC1,0x28 } }; // 09BDF5E5-B4BD-4E23-A588-74469204C128
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>{ 0x2798E029,0xD687,0x4C92,{ 0x86,0xC6,0x39,0x9E,0x9A,0x0E,0xCB,0x09 } }; // 2798E029-D687-4C92-86C6-399E9A0ECB09
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>{ 0x4E6A8A5C,0x9773,0x46C4,{ 0xA3,0x2F,0xB1,0xE5,0x43,0x15,0x9E,0x04 } }; // 4E6A8A5C-9773-46C4-A32F-B1E543159E04
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>{ 0x8C7CE857,0xA7E7,0x489D,{ 0xB9,0xD6,0x36,0x80,0x61,0x51,0x50,0x12 } }; // 8C7CE857-A7E7-489D-B9D6-368061515012
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics>{ 0xFC9AC5CC,0xC1D7,0x4153,{ 0x92,0x3B,0xA2,0xD4,0x3C,0x6C,0x8D,0x49 } }; // FC9AC5CC-C1D7-4153-923B-A2D43C6C8D49
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics>{ 0xFFB58E1F,0x0692,0x4C47,{ 0x93,0xCF,0x34,0xD9,0x1F,0x9D,0xCD,0x00 } }; // FFB58E1F-0692-4C47-93CF-34D91F9DCD00
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>{ 0xE5B9AB8C,0xA141,0x4135,{ 0x9A,0xDD,0xB0,0xD2,0xE3,0xAA,0x1F,0xC9 } }; // E5B9AB8C-A141-4135-9ADD-B0D2E3AA1FC9
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep>{ 0x947B03EB,0x8342,0x4792,{ 0xA2,0xE5,0x92,0x56,0x36,0x37,0x8A,0x53 } }; // 947B03EB-8342-4792-A2E5-925636378A53
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics>{ 0x8552546E,0x4457,0x4825,{ 0xB4,0x64,0x63,0x54,0x71,0xA3,0x9F,0x5C } }; // 8552546E-4457-4825-B464-635471A39F5C
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>{ 0x77B0F00D,0xB097,0x4F61,{ 0xA2,0x6A,0x95,0x61,0x63,0x9C,0x9C,0x3A } }; // 77B0F00D-B097-4F61-A26A-9561639C9C3A
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>{ 0x000440F9,0xF7FD,0x417D,{ 0x89,0xE1,0xFB,0xB0,0x38,0x2A,0xDC,0x4D } }; // 000440F9-F7FD-417D-89E1-FBB0382ADC4D
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulator>{ 0xDFB906B2,0x875E,0x47E5,{ 0x80,0x77,0xE8,0xBF,0xF1,0xB1,0xC6,0xFB } }; // DFB906B2-875E-47E5-8077-E8BFF1B1C6FB
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulator2>{ 0xFE3FC0B8,0x8529,0x411A,{ 0x80,0x7B,0x48,0xED,0xC2,0xA0,0xAB,0x44 } }; // FE3FC0B8-8529-411A-807B-48EDC2A0AB44
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>{ 0xD55D1576,0x69D2,0x5333,{ 0x5B,0x5F,0xF8,0xC0,0xD6,0xE9,0xF0,0x9F } }; // D55D1576-69D2-5333-5B5F-F8C0D6E9F09F
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>{ 0x8BF93DF0,0x22E1,0x4238,{ 0x86,0x10,0x94,0xCE,0x4A,0x96,0x54,0x25 } }; // 8BF93DF0-22E1-4238-8610-94CE4A965425
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>{ 0xD550BAC7,0xB7BF,0x4E29,{ 0x92,0x94,0x0C,0x4A,0xC3,0xC9,0x41,0xBD } }; // D550BAC7-B7BF-4E29-9294-0C4AC3C941BD
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>{ 0x2186D8D3,0xC5EB,0x5262,{ 0x43,0xDF,0x62,0xA0,0xA1,0xB5,0x55,0x57 } }; // 2186D8D3-C5EB-5262-43DF-62A0A1B55557
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>{ 0x4E2CA5EE,0xF969,0x507D,{ 0x6C,0xF9,0x34,0xE2,0xD1,0x8D,0xF3,0x11 } }; // 4E2CA5EE-F969-507D-6CF9-34E2D18DF311
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics>{ 0x7A9BFC4B,0xC4D3,0x494F,{ 0xB8,0xA2,0x62,0x15,0xD8,0x1E,0x85,0xB2 } }; // 7A9BFC4B-C4D3-494F-B8A2-6215D81E85B2
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics2>{ 0x69AE9F8A,0xB775,0x488B,{ 0x84,0x36,0x6C,0x1E,0x28,0xED,0x73,0x1F } }; // 69AE9F8A-B775-488B-8436-6C1E28ED731F
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics3>{ 0x59EA142A,0x9F09,0x43F5,{ 0x85,0x65,0xCF,0xA8,0x14,0x8E,0x4C,0xB2 } }; // 59EA142A-9F09-43F5-8565-CFA8148E4CB2
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardPinPolicy>{ 0x183CE184,0x4DB6,0x4841,{ 0xAC,0x9E,0x2A,0xC1,0xF3,0x9B,0x73,0x04 } }; // 183CE184-4DB6-4841-AC9E-2AC1F39B7304
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral>{ 0x18C94AAC,0x7805,0x4004,{ 0x85,0xE4,0xBB,0xEF,0xAC,0x8F,0x68,0x84 } }; // 18C94AAC-7805-4004-85E4-BBEFAC8F6884
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardPinResetRequest>{ 0x12FE3C4D,0x5FB9,0x4E8E,{ 0x9F,0xF6,0x61,0xF4,0x75,0x12,0x4F,0xEF } }; // 12FE3C4D-5FB9-4E8E-9FF6-61F475124FEF
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardProvisioning>{ 0x19EEEDBD,0x1FAB,0x477C,{ 0xB7,0x12,0x1A,0x2C,0x5A,0xF1,0xFD,0x6E } }; // 19EEEDBD-1FAB-477C-B712-1A2C5AF1FD6E
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardProvisioning2>{ 0x10FD28EB,0x3F79,0x4B66,{ 0x9B,0x7C,0x11,0xC1,0x49,0xB7,0xD0,0xBC } }; // 10FD28EB-3F79-4B66-9B7C-11C149B7D0BC
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics>{ 0x13882848,0x0D13,0x4E70,{ 0x97,0x35,0x51,0xDA,0xEC,0xA5,0x25,0x4F } }; // 13882848-0D13-4E70-9735-51DAECA5254F
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics2>{ 0x3447C6A8,0xC9A0,0x4BD6,{ 0xB5,0x0D,0x25,0x1F,0x4E,0x8D,0x3A,0x62 } }; // 3447C6A8-C9A0-4BD6-B50D-251F4E8D3A62
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardReader>{ 0x1074B4E0,0x54C2,0x4DF0,{ 0x81,0x7A,0x14,0xC1,0x43,0x78,0xF0,0x6C } }; // 1074B4E0-54C2-4DF0-817A-14C14378F06C
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardReaderStatics>{ 0x103C04E1,0xA1CA,0x48F2,{ 0xA2,0x81,0x5B,0x6F,0x66,0x9A,0xF1,0x07 } }; // 103C04E1-A1CA-48F2-A281-5B6F669AF107
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails>{ 0x5F9BF11E,0x39EF,0x4F2B,{ 0xB4,0x4F,0x0A,0x91,0x55,0xB1,0x77,0xBC } }; // 5F9BF11E-39EF-4F2B-B44F-0A9155B177BC
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails2>{ 0x2945C569,0x8975,0x4A51,{ 0x9E,0x1A,0x5F,0x8A,0x76,0xEE,0x51,0xAF } }; // 2945C569-8975-4A51-9E1A-5F8A76EE51AF
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails3>{ 0xB3E2C27D,0x18C6,0x4BA8,{ 0x83,0x76,0xEF,0x03,0xD4,0x91,0x26,0x66 } }; // B3E2C27D-18C6-4BA8-8376-EF03D4912666
    template <> inline constexpr guid guid_v<llm::OS::Devices::SmartCards::SmartCardPinResetHandler>{ 0x138D5E40,0xF3BC,0x4A5C,{ 0xB4,0x1D,0x4B,0x4E,0xF6,0x84,0xE2,0x37 } }; // 138D5E40-F3BC-4A5C-B41D-4B4EF684E237
    template <> struct default_interface<llm::OS::Devices::SmartCards::CardAddedEventArgs>{ using type = llm::OS::Devices::SmartCards::ICardAddedEventArgs; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::CardRemovedEventArgs>{ using type = llm::OS::Devices::SmartCards::ICardRemovedEventArgs; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCard>{ using type = llm::OS::Devices::SmartCards::ISmartCard; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardAppletIdGroup>{ using type = llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration>{ using type = llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardAutomaticResponseApdu>{ using type = llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardChallengeContext>{ using type = llm::OS::Devices::SmartCards::ISmartCardChallengeContext; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardConnection>{ using type = llm::OS::Devices::SmartCards::ISmartCardConnection; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramGenerator>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialCharacteristics>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageCharacteristics>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCharacteristics>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo>{ using type = llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardEmulator>{ using type = llm::OS::Devices::SmartCards::ISmartCardEmulator; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs>{ using type = llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs>{ using type = llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionProperties>{ using type = llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardPinPolicy>{ using type = llm::OS::Devices::SmartCards::ISmartCardPinPolicy; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardPinResetDeferral>{ using type = llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardPinResetRequest>{ using type = llm::OS::Devices::SmartCards::ISmartCardPinResetRequest; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardProvisioning>{ using type = llm::OS::Devices::SmartCards::ISmartCardProvisioning; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardReader>{ using type = llm::OS::Devices::SmartCards::ISmartCardReader; };
    template <> struct default_interface<llm::OS::Devices::SmartCards::SmartCardTriggerDetails>{ using type = llm::OS::Devices::SmartCards::ISmartCardTriggerDetails; };
    template <> struct abi<llm::OS::Devices::SmartCards::ICardAddedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SmartCard(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ICardRemovedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SmartCard(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::IKnownSmartCardAppletIds>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PaymentSystemEnvironment(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProximityPaymentSystemEnvironment(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCard>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Reader(void**) noexcept = 0;
            virtual int32_t __stdcall GetStatusAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAnswerToResetAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_AppletIds(void**) noexcept = 0;
            virtual int32_t __stdcall get_SmartCardEmulationCategory(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SmartCardEmulationCategory(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SmartCardEmulationType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SmartCardEmulationType(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_AutomaticEnablement(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AutomaticEnablement(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Logo(void**) noexcept = 0;
            virtual int32_t __stdcall put_Logo(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
            virtual int32_t __stdcall get_Properties(void**) noexcept = 0;
            virtual int32_t __stdcall get_SecureUserAuthenticationRequired(bool*) noexcept = 0;
            virtual int32_t __stdcall put_SecureUserAuthenticationRequired(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ActivationPolicy(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_AppletIdGroup(void**) noexcept = 0;
            virtual int32_t __stdcall RequestActivationPolicyChangeAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_Id(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall SetAutomaticResponseApdusAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SmartCardReaderId(void**) noexcept = 0;
            virtual int32_t __stdcall SetPropertiesAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaxAppletIds(uint16_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CommandApdu(void**) noexcept = 0;
            virtual int32_t __stdcall put_CommandApdu(void*) noexcept = 0;
            virtual int32_t __stdcall get_CommandApduBitMask(void**) noexcept = 0;
            virtual int32_t __stdcall put_CommandApduBitMask(void*) noexcept = 0;
            virtual int32_t __stdcall get_ShouldMatchLength(bool*) noexcept = 0;
            virtual int32_t __stdcall put_ShouldMatchLength(bool) noexcept = 0;
            virtual int32_t __stdcall get_AppletId(void**) noexcept = 0;
            virtual int32_t __stdcall put_AppletId(void*) noexcept = 0;
            virtual int32_t __stdcall get_ResponseApdu(void**) noexcept = 0;
            virtual int32_t __stdcall put_ResponseApdu(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_InputState(void**) noexcept = 0;
            virtual int32_t __stdcall put_InputState(void*) noexcept = 0;
            virtual int32_t __stdcall get_OutputState(void**) noexcept = 0;
            virtual int32_t __stdcall put_OutputState(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AllowWhenCryptogramGeneratorNotPrepared(bool*) noexcept = 0;
            virtual int32_t __stdcall put_AllowWhenCryptogramGeneratorNotPrepared(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Create(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardChallengeContext>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Challenge(void**) noexcept = 0;
            virtual int32_t __stdcall VerifyResponseAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ProvisionAsync(void*, bool, void**) noexcept = 0;
            virtual int32_t __stdcall ProvisionAsyncWithNewCardId(void*, bool, llm::guid, void**) noexcept = 0;
            virtual int32_t __stdcall ChangeAdministrativeKeyAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardConnect>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ConnectAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardConnection>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TransmitAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SupportedCryptogramMaterialTypes(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedCryptogramAlgorithms(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedCryptogramMaterialPackageFormats(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedCryptogramMaterialPackageConfirmationResponseFormats(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportedSmartCardCryptogramStorageKeyCapabilities(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteCryptogramMaterialStorageKeyAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateCryptogramMaterialStorageKeyAsync(int32_t, void*, int32_t, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestCryptogramMaterialStorageKeyInfoAsync(int32_t, void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ImportCryptogramMaterialPackageAsync(int32_t, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryProvePossessionOfCryptogramMaterialPackageAsync(int32_t, int32_t, void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestUnlockCryptogramMaterialForUseAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteCryptogramMaterialPackageAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ValidateRequestApduAsync(int32_t, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAllCryptogramStorageKeyCharacteristicsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAllCryptogramMaterialPackageCharacteristicsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetAllCryptogramMaterialPackageCharacteristicsWithStorageKeyAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAllCryptogramMaterialCharacteristicsAsync(int32_t, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetSmartCardCryptogramGeneratorAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Characteristics(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Characteristics(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Characteristics(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MaterialName(void**) noexcept = 0;
            virtual int32_t __stdcall get_AllowedAlgorithms(void**) noexcept = 0;
            virtual int32_t __stdcall get_AllowedProofOfPossessionAlgorithms(void**) noexcept = 0;
            virtual int32_t __stdcall get_AllowedValidations(void**) noexcept = 0;
            virtual int32_t __stdcall get_MaterialType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ProtectionMethod(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_ProtectionVersion(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_MaterialLength(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_PackageName(void**) noexcept = 0;
            virtual int32_t __stdcall get_StorageKeyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_DateImported(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_PackageFormat(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Proof(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Algorithm(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Algorithm(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SourceData(void**) noexcept = 0;
            virtual int32_t __stdcall put_SourceData(void*) noexcept = 0;
            virtual int32_t __stdcall get_CryptogramMaterialPackageName(void**) noexcept = 0;
            virtual int32_t __stdcall put_CryptogramMaterialPackageName(void*) noexcept = 0;
            virtual int32_t __stdcall get_CryptogramMaterialName(void**) noexcept = 0;
            virtual int32_t __stdcall put_CryptogramMaterialName(void*) noexcept = 0;
            virtual int32_t __stdcall get_TemplateOffset(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_TemplateOffset(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_CryptogramOffset(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CryptogramOffset(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_CryptogramLength(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CryptogramLength(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_CryptogramPlacementOptions(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_CryptogramPlacementOptions(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_ChainedOutputStep(void**) noexcept = 0;
            virtual int32_t __stdcall put_ChainedOutputStep(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_StorageKeyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_DateCreated(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_Algorithm(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Capabilities(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PublicKeyBlobType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_PublicKey(void**) noexcept = 0;
            virtual int32_t __stdcall get_AttestationStatus(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Attestation(void**) noexcept = 0;
            virtual int32_t __stdcall get_AttestationCertificateChain(void**) noexcept = 0;
            virtual int32_t __stdcall get_Capabilities(uint32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_OperationalRequirements(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulator>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_EnablementPolicy(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulator2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall add_ApduReceived(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ApduReceived(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_ConnectionDeactivated(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ConnectionDeactivated(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall Start() noexcept = 0;
            virtual int32_t __stdcall IsHostCardEmulationSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CommandApdu(void**) noexcept = 0;
            virtual int32_t __stdcall get_ConnectionProperties(void**) noexcept = 0;
            virtual int32_t __stdcall TryRespondAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_AutomaticResponseStatus(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_State(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall TryRespondWithStateAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryRespondWithCryptogramsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryRespondWithCryptogramsAndStateAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ConnectionProperties(void**) noexcept = 0;
            virtual int32_t __stdcall get_Reason(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(llm::guid*) noexcept = 0;
            virtual int32_t __stdcall get_Source(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefaultAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAppletIdGroupRegistrationsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RegisterAppletIdGroupAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnregisterAppletIdGroupAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall get_MaxAppletIdGroupRegistrations(uint16_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardPinPolicy>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_MinLength(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MinLength(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_MaxLength(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_MaxLength(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_UppercaseLetters(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_UppercaseLetters(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_LowercaseLetters(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_LowercaseLetters(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Digits(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Digits(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SpecialCharacters(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SpecialCharacters(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardPinResetRequest>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Challenge(void**) noexcept = 0;
            virtual int32_t __stdcall get_Deadline(int64_t*) noexcept = 0;
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
            virtual int32_t __stdcall SetResponse(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardProvisioning>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SmartCard(void**) noexcept = 0;
            virtual int32_t __stdcall GetIdAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetNameAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetChallengeContextAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestPinChangeAsync(void**) noexcept = 0;
            virtual int32_t __stdcall RequestPinResetAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardProvisioning2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetAuthorityKeyContainerNameAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FromSmartCardAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestVirtualSmartCardCreationAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestVirtualSmartCardCreationAsyncWithCardId(void*, void*, void*, llm::guid, void**) noexcept = 0;
            virtual int32_t __stdcall RequestVirtualSmartCardDeletionAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestAttestedVirtualSmartCardCreationAsync(void*, void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestAttestedVirtualSmartCardCreationAsyncWithCardId(void*, void*, void*, llm::guid, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardReader>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DeviceId(void**) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall GetStatusAsync(void**) noexcept = 0;
            virtual int32_t __stdcall FindAllCardsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_CardAdded(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CardAdded(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_CardRemoved(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_CardRemoved(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardReaderStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeviceSelector(void**) noexcept = 0;
            virtual int32_t __stdcall GetDeviceSelectorWithKind(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall FromIdAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TriggerType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_SourceAppletId(void**) noexcept = 0;
            virtual int32_t __stdcall get_TriggerData(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Emulator(void**) noexcept = 0;
            virtual int32_t __stdcall TryLaunchCurrentAppAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryLaunchCurrentAppWithBehaviorAsync(void*, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_SmartCard(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::Devices::SmartCards::SmartCardPinResetHandler>
    {
        struct __declspec(novtable) type : unknown_abi
        {
            virtual int32_t __stdcall Invoke(void*, void*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ICardAddedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCard) SmartCard() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ICardAddedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ICardAddedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ICardRemovedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCard) SmartCard() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ICardRemovedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ICardRemovedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_IKnownSmartCardAppletIds
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) PaymentSystemEnvironment() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) ProximityPaymentSystemEnvironment() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::IKnownSmartCardAppletIds>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_IKnownSmartCardAppletIds<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCard
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardReader) Reader() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardStatus>) GetStatusAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>) GetAnswerToResetAsync() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCard>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCard<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroup
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Storage::Streams::IBuffer>) AppletIds() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulationCategory) SmartCardEmulationCategory() const;
        LLM_IMPL_AUTO(void) SmartCardEmulationCategory(llm::OS::Devices::SmartCards::SmartCardEmulationCategory const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulationType) SmartCardEmulationType() const;
        LLM_IMPL_AUTO(void) SmartCardEmulationType(llm::OS::Devices::SmartCards::SmartCardEmulationType const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) AutomaticEnablement() const;
        LLM_IMPL_AUTO(void) AutomaticEnablement(bool value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroup<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroup2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Logo() const;
        LLM_IMPL_AUTO(void) Logo(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) Properties() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SecureUserAuthenticationRequired() const;
        LLM_IMPL_AUTO(void) SecureUserAuthenticationRequired(bool value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroup2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardAppletIdGroup) Create(param::hstring const& displayName, param::vector<llm::OS::Storage::Streams::IBuffer> const& appletIds, llm::OS::Devices::SmartCards::SmartCardEmulationCategory const& emulationCategory, llm::OS::Devices::SmartCards::SmartCardEmulationType const& emulationType) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupFactory>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupRegistration
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy) ActivationPolicy() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardAppletIdGroup) AppletIdGroup() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardActivationPolicyChangeResult>) RequestActivationPolicyChangeAsync(llm::OS::Devices::SmartCards::SmartCardAppletIdGroupActivationPolicy const& policy) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) Id() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetAutomaticResponseApdusAsync(param::async_iterable<llm::OS::Devices::SmartCards::SmartCardAutomaticResponseApdu> const& apdus) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupRegistration<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupRegistration2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SmartCardReaderId() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetPropertiesAsync(llm::OS::Foundation::Collections::ValueSet const& props) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupRegistration2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) MaxAppletIds() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupStatics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAppletIdGroupStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApdu
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) CommandApdu() const;
        LLM_IMPL_AUTO(void) CommandApdu(llm::OS::Storage::Streams::IBuffer const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) CommandApduBitMask() const;
        LLM_IMPL_AUTO(void) CommandApduBitMask(llm::OS::Storage::Streams::IBuffer const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) ShouldMatchLength() const;
        LLM_IMPL_AUTO(void) ShouldMatchLength(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) AppletId() const;
        LLM_IMPL_AUTO(void) AppletId(llm::OS::Storage::Streams::IBuffer const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) ResponseApdu() const;
        LLM_IMPL_AUTO(void) ResponseApdu(llm::OS::Storage::Streams::IBuffer const& value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApdu<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApdu2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) InputState() const;
        LLM_IMPL_AUTO(void) InputState(llm::OS::Foundation::IReference<uint32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) OutputState() const;
        LLM_IMPL_AUTO(void) OutputState(llm::OS::Foundation::IReference<uint32_t> const& value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApdu2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApdu3
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) AllowWhenCryptogramGeneratorNotPrepared() const;
        LLM_IMPL_AUTO(void) AllowWhenCryptogramGeneratorNotPrepared(bool value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApdu3<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApduFactory
    {
        LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardAutomaticResponseApdu) Create(llm::OS::Storage::Streams::IBuffer const& commandApdu, llm::OS::Storage::Streams::IBuffer const& responseApdu) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApduFactory>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardAutomaticResponseApduFactory<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardChallengeContext
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) Challenge() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) VerifyResponseAsync(llm::OS::Storage::Streams::IBuffer const& response) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ProvisionAsync(llm::OS::Storage::Streams::IBuffer const& response, bool formatCard) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ProvisionAsync(llm::OS::Storage::Streams::IBuffer const& response, bool formatCard, llm::guid const& newCardId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) ChangeAdministrativeKeyAsync(llm::OS::Storage::Streams::IBuffer const& response, llm::OS::Storage::Streams::IBuffer const& newAdministrativeKey) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardChallengeContext>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardChallengeContext<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardConnect
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardConnection>) ConnectAsync() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardConnect>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardConnect<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardConnection
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IBuffer>) TransmitAsync(llm::OS::Storage::Streams::IBuffer const& command) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardConnection>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardConnection<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGenerator
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialType>) SupportedCryptogramMaterialTypes() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm>) SupportedCryptogramAlgorithms() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat>) SupportedCryptogramMaterialPackageFormats() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>) SupportedCryptogramMaterialPackageConfirmationResponseFormats() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities>) SupportedSmartCardCryptogramStorageKeyCapabilities() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) DeleteCryptogramMaterialStorageKeyAsync(param::hstring const& storageKeyName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) CreateCryptogramMaterialStorageKeyAsync(llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior const& promptingBehavior, param::hstring const& storageKeyName, llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm const& algorithm, llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities const& capabilities) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyInfo>) RequestCryptogramMaterialStorageKeyInfoAsync(llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior const& promptingBehavior, param::hstring const& storageKeyName, llm::OS::Security::Cryptography::Core::CryptographicPublicKeyBlobType const& format) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) ImportCryptogramMaterialPackageAsync(llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat const& format, param::hstring const& storageKeyName, param::hstring const& materialPackageName, llm::OS::Storage::Streams::IBuffer const& cryptogramMaterialPackage) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPossessionProof>) TryProvePossessionOfCryptogramMaterialPackageAsync(llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior const& promptingBehavior, llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat const& responseFormat, param::hstring const& materialPackageName, param::hstring const& materialName, llm::OS::Storage::Streams::IBuffer const& challenge) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) RequestUnlockCryptogramMaterialForUseAsync(llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior const& promptingBehavior) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) DeleteCryptogramMaterialPackageAsync(param::hstring const& materialPackageName) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGenerator<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGenerator2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) ValidateRequestApduAsync(llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior const& promptingBehavior, llm::OS::Storage::Streams::IBuffer const& apduToValidate, param::async_iterable<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep> const& cryptogramPlacementSteps) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>) GetAllCryptogramStorageKeyCharacteristicsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>) GetAllCryptogramMaterialPackageCharacteristicsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>) GetAllCryptogramMaterialPackageCharacteristicsAsync(param::hstring const& storageKeyName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>) GetAllCryptogramMaterialCharacteristicsAsync(llm::OS::Devices::SmartCards::SmartCardUnlockPromptingBehavior const& promptingBehavior, param::hstring const& materialPackageName) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGenerator2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGeneratorStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGenerator>) GetSmartCardCryptogramGeneratorAsync() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGeneratorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGeneratorStatics2
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGeneratorStatics2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGeneratorStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus) OperationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialCharacteristics>) Characteristics() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus) OperationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageCharacteristics>) Characteristics() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus) OperationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCharacteristics>) Characteristics() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramMaterialCharacteristics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) MaterialName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm>) AllowedAlgorithms() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageConfirmationResponseFormat>) AllowedProofOfPossessionAlgorithms() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm>) AllowedValidations() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialType) MaterialType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialProtectionMethod) ProtectionMethod() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) ProtectionVersion() const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) MaterialLength() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramMaterialCharacteristics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramMaterialPackageCharacteristics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PackageName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) StorageKeyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) DateImported() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramMaterialPackageFormat) PackageFormat() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramMaterialPackageCharacteristics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramMaterialPossessionProof
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus) OperationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) Proof() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramMaterialPossessionProof<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramPlacementStep
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm) Algorithm() const;
        LLM_IMPL_AUTO(void) Algorithm(llm::OS::Devices::SmartCards::SmartCardCryptogramAlgorithm const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) SourceData() const;
        LLM_IMPL_AUTO(void) SourceData(llm::OS::Storage::Streams::IBuffer const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CryptogramMaterialPackageName() const;
        LLM_IMPL_AUTO(void) CryptogramMaterialPackageName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CryptogramMaterialName() const;
        LLM_IMPL_AUTO(void) CryptogramMaterialName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) TemplateOffset() const;
        LLM_IMPL_AUTO(void) TemplateOffset(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) CryptogramOffset() const;
        LLM_IMPL_AUTO(void) CryptogramOffset(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(int32_t) CryptogramLength() const;
        LLM_IMPL_AUTO(void) CryptogramLength(int32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementOptions) CryptogramPlacementOptions() const;
        LLM_IMPL_AUTO(void) CryptogramPlacementOptions(llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementOptions const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep) ChainedOutputStep() const;
        LLM_IMPL_AUTO(void) ChainedOutputStep(llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep const& value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramPlacementStep<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramStorageKeyCharacteristics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) StorageKeyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) DateCreated() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyAlgorithm) Algorithm() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities) Capabilities() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramStorageKeyCharacteristics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramStorageKeyInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus) OperationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Security::Cryptography::Core::CryptographicPublicKeyBlobType) PublicKeyBlobType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) PublicKey() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptographicKeyAttestationStatus) AttestationStatus() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) Attestation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) AttestationCertificateChain() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardCryptogramStorageKeyCapabilities) Capabilities() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramStorageKeyInfo<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardCryptogramStorageKeyInfo2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) OperationalRequirements() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardCryptogramStorageKeyInfo2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulator
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulatorEnablementPolicy) EnablementPolicy() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulator>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulator<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulator2
    {
        LLM_IMPL_AUTO(llm::event_token) ApduReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardEmulator, llm::OS::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> const& value) const;
        using ApduReceived_revoker = impl::event_revoker<llm::OS::Devices::SmartCards::ISmartCardEmulator2, &impl::abi_t<llm::OS::Devices::SmartCards::ISmartCardEmulator2>::remove_ApduReceived>;
        [[nodiscard]] ApduReceived_revoker ApduReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardEmulator, llm::OS::Devices::SmartCards::SmartCardEmulatorApduReceivedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) ApduReceived(llm::event_token const& value) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) ConnectionDeactivated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardEmulator, llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> const& value) const;
        using ConnectionDeactivated_revoker = impl::event_revoker<llm::OS::Devices::SmartCards::ISmartCardEmulator2, &impl::abi_t<llm::OS::Devices::SmartCards::ISmartCardEmulator2>::remove_ConnectionDeactivated>;
        [[nodiscard]] ConnectionDeactivated_revoker ConnectionDeactivated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardEmulator, llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) ConnectionDeactivated(llm::event_token const& value) const noexcept;
        LLM_IMPL_AUTO(void) Start() const;
        LLM_IMPL_AUTO(bool) IsHostCardEmulationSupported() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulator2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulator2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorApduReceivedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) CommandApdu() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionProperties) ConnectionProperties() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryRespondAsync(llm::OS::Storage::Streams::IBuffer const& responseApdu) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardAutomaticResponseStatus) AutomaticResponseStatus() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorApduReceivedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorApduReceivedEventArgs2
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) State() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryRespondAsync(llm::OS::Storage::Streams::IBuffer const& responseApdu, llm::OS::Foundation::IReference<uint32_t> const& nextState) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorApduReceivedEventArgs2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorApduReceivedEventArgsWithCryptograms
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) TryRespondWithCryptogramsAsync(llm::OS::Storage::Streams::IBuffer const& responseTemplate, param::async_iterable<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep> const& cryptogramPlacementSteps) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardCryptogramGeneratorOperationStatus>) TryRespondWithCryptogramsAsync(llm::OS::Storage::Streams::IBuffer const& responseTemplate, param::async_iterable<llm::OS::Devices::SmartCards::SmartCardCryptogramPlacementStep> const& cryptogramPlacementSteps, llm::OS::Foundation::IReference<uint32_t> const& nextState) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorApduReceivedEventArgsWithCryptograms<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorConnectionDeactivatedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionProperties) ConnectionProperties() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionDeactivatedReason) Reason() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorConnectionDeactivatedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorConnectionProperties
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::guid) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulatorConnectionSource) Source() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorConnectionProperties<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardEmulator>) GetDefaultAsync() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration>>) GetAppletIdGroupRegistrationsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration>) RegisterAppletIdGroupAsync(llm::OS::Devices::SmartCards::SmartCardAppletIdGroup const& appletIdGroup) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) UnregisterAppletIdGroupAsync(llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration const& registration) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint16_t) MaxAppletIdGroupRegistrations() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardEmulatorStatics3
    {
        LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardEmulatorStatics3>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardEmulatorStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardPinPolicy
    {
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MinLength() const;
        LLM_IMPL_AUTO(void) MinLength(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(uint32_t) MaxLength() const;
        LLM_IMPL_AUTO(void) MaxLength(uint32_t value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption) UppercaseLetters() const;
        LLM_IMPL_AUTO(void) UppercaseLetters(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption) LowercaseLetters() const;
        LLM_IMPL_AUTO(void) LowercaseLetters(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption) Digits() const;
        LLM_IMPL_AUTO(void) Digits(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption) SpecialCharacters() const;
        LLM_IMPL_AUTO(void) SpecialCharacters(llm::OS::Devices::SmartCards::SmartCardPinCharacterPolicyOption const& value) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardPinPolicy>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardPinPolicy<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardPinResetDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardPinResetDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardPinResetRequest
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) Challenge() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) Deadline() const;
        LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardPinResetDeferral) GetDeferral() const;
        LLM_IMPL_AUTO(void) SetResponse(llm::OS::Storage::Streams::IBuffer const& response) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardPinResetRequest>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardPinResetRequest<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardProvisioning
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCard) SmartCard() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::guid>) GetIdAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetNameAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardChallengeContext>) GetChallengeContextAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestPinChangeAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestPinResetAsync(llm::OS::Devices::SmartCards::SmartCardPinResetHandler const& handler) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardProvisioning>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardProvisioning<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardProvisioning2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) GetAuthorityKeyContainerNameAsync() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardProvisioning2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardProvisioning2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardProvisioningStatics
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardProvisioning>) FromSmartCardAsync(llm::OS::Devices::SmartCards::SmartCard const& card) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardProvisioning>) RequestVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardProvisioning>) RequestVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy, llm::guid const& cardId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestVirtualSmartCardDeletionAsync(llm::OS::Devices::SmartCards::SmartCard const& card) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardProvisioningStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardProvisioningStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardProvisioning>) RequestAttestedVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardProvisioning>) RequestAttestedVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy, llm::guid const& cardId) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardProvisioningStatics2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardProvisioningStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardReader
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DeviceId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardReaderKind) Kind() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardReaderStatus>) GetStatusAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::SmartCards::SmartCard>>) FindAllCardsAsync() const;
        LLM_IMPL_AUTO(llm::event_token) CardAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardReader, llm::OS::Devices::SmartCards::CardAddedEventArgs> const& handler) const;
        using CardAdded_revoker = impl::event_revoker<llm::OS::Devices::SmartCards::ISmartCardReader, &impl::abi_t<llm::OS::Devices::SmartCards::ISmartCardReader>::remove_CardAdded>;
        [[nodiscard]] CardAdded_revoker CardAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardReader, llm::OS::Devices::SmartCards::CardAddedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CardAdded(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) CardRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardReader, llm::OS::Devices::SmartCards::CardRemovedEventArgs> const& handler) const;
        using CardRemoved_revoker = impl::event_revoker<llm::OS::Devices::SmartCards::ISmartCardReader, &impl::abi_t<llm::OS::Devices::SmartCards::ISmartCardReader>::remove_CardRemoved>;
        [[nodiscard]] CardRemoved_revoker CardRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::SmartCards::SmartCardReader, llm::OS::Devices::SmartCards::CardRemovedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) CardRemoved(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardReader>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardReader<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardReaderStatics
    {
        LLM_IMPL_AUTO(hstring) GetDeviceSelector() const;
        LLM_IMPL_AUTO(hstring) GetDeviceSelector(llm::OS::Devices::SmartCards::SmartCardReaderKind const& kind) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::SmartCards::SmartCardReader>) FromIdAsync(param::hstring const& deviceId) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardReaderStatics>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardReaderStatics<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardTriggerDetails
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardTriggerType) TriggerType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) SourceAppletId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) TriggerData() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardTriggerDetails<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardTriggerDetails2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCardEmulator) Emulator() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryLaunchCurrentAppAsync(param::hstring const& arguments) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryLaunchCurrentAppAsync(param::hstring const& arguments, llm::OS::Devices::SmartCards::SmartCardLaunchBehavior const& behavior) const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails2>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardTriggerDetails2<D>;
    };
    template <typename D>
    struct consume_Windows_Devices_SmartCards_ISmartCardTriggerDetails3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Devices::SmartCards::SmartCard) SmartCard() const;
    };
    template <> struct consume<llm::OS::Devices::SmartCards::ISmartCardTriggerDetails3>
    {
        template <typename D> using type = consume_Windows_Devices_SmartCards_ISmartCardTriggerDetails3<D>;
    };
}
#endif