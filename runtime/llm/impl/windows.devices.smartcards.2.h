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
#ifndef LLM_OS_Devices_SmartCards_2_H
#define LLM_OS_Devices_SmartCards_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Devices.SmartCards.1.h"
LLM_EXPORT namespace llm::OS::Devices::SmartCards
{
    struct SmartCardPinResetHandler : llm::OS::Foundation::IUnknown
    {
        SmartCardPinResetHandler(std::nullptr_t = nullptr) noexcept {}
        SmartCardPinResetHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SmartCardPinResetHandler(L lambda);
        template <typename F> SmartCardPinResetHandler(F* function);
        template <typename O, typename M> SmartCardPinResetHandler(O* object, M method);
        template <typename O, typename M> SmartCardPinResetHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SmartCardPinResetHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Devices::SmartCards::SmartCardProvisioning const& sender, llm::OS::Devices::SmartCards::SmartCardPinResetRequest const& request) const;
    };
    struct __declspec(empty_bases) CardAddedEventArgs : llm::OS::Devices::SmartCards::ICardAddedEventArgs
    {
        CardAddedEventArgs(std::nullptr_t) noexcept {}
        CardAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ICardAddedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) CardRemovedEventArgs : llm::OS::Devices::SmartCards::ICardRemovedEventArgs
    {
        CardRemovedEventArgs(std::nullptr_t) noexcept {}
        CardRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ICardRemovedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct KnownSmartCardAppletIds
    {
        KnownSmartCardAppletIds() = delete;
        [[nodiscard]] static auto PaymentSystemEnvironment();
        [[nodiscard]] static auto ProximityPaymentSystemEnvironment();
    };
    struct __declspec(empty_bases) SmartCard : llm::OS::Devices::SmartCards::ISmartCard,
        impl::require<SmartCard, llm::OS::Devices::SmartCards::ISmartCardConnect>
    {
        SmartCard(std::nullptr_t) noexcept {}
        SmartCard(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCard(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardAppletIdGroup : llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup,
        impl::require<SmartCardAppletIdGroup, llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup2>
    {
        SmartCardAppletIdGroup(std::nullptr_t) noexcept {}
        SmartCardAppletIdGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardAppletIdGroup(ptr, take_ownership_from_abi) {}
        SmartCardAppletIdGroup();
        SmartCardAppletIdGroup(param::hstring const& displayName, param::vector<llm::OS::Storage::Streams::IBuffer> const& appletIds, llm::OS::Devices::SmartCards::SmartCardEmulationCategory const& emulationCategory, llm::OS::Devices::SmartCards::SmartCardEmulationType const& emulationType);
        [[nodiscard]] static auto MaxAppletIds();
    };
    struct __declspec(empty_bases) SmartCardAppletIdGroupRegistration : llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration,
        impl::require<SmartCardAppletIdGroupRegistration, llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration2>
    {
        SmartCardAppletIdGroupRegistration(std::nullptr_t) noexcept {}
        SmartCardAppletIdGroupRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardAppletIdGroupRegistration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardAutomaticResponseApdu : llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu,
        impl::require<SmartCardAutomaticResponseApdu, llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu2, llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu3>
    {
        SmartCardAutomaticResponseApdu(std::nullptr_t) noexcept {}
        SmartCardAutomaticResponseApdu(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardAutomaticResponseApdu(ptr, take_ownership_from_abi) {}
        SmartCardAutomaticResponseApdu(llm::OS::Storage::Streams::IBuffer const& commandApdu, llm::OS::Storage::Streams::IBuffer const& responseApdu);
    };
    struct __declspec(empty_bases) SmartCardChallengeContext : llm::OS::Devices::SmartCards::ISmartCardChallengeContext
    {
        SmartCardChallengeContext(std::nullptr_t) noexcept {}
        SmartCardChallengeContext(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardChallengeContext(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardConnection : llm::OS::Devices::SmartCards::ISmartCardConnection
    {
        SmartCardConnection(std::nullptr_t) noexcept {}
        SmartCardConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardConnection(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardCryptogramGenerator : llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator,
        impl::require<SmartCardCryptogramGenerator, llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator2>
    {
        SmartCardCryptogramGenerator(std::nullptr_t) noexcept {}
        SmartCardCryptogramGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramGenerator(ptr, take_ownership_from_abi) {}
        static auto GetSmartCardCryptogramGeneratorAsync();
        static auto IsSupported();
    };
    struct __declspec(empty_bases) SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult : llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult
    {
        SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult(std::nullptr_t) noexcept {}
        SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult();
    };
    struct __declspec(empty_bases) SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult : llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult
    {
        SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult(std::nullptr_t) noexcept {}
        SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult();
    };
    struct __declspec(empty_bases) SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult : llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult
    {
        SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult(std::nullptr_t) noexcept {}
        SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult();
    };
    struct __declspec(empty_bases) SmartCardCryptogramMaterialCharacteristics : llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics
    {
        SmartCardCryptogramMaterialCharacteristics(std::nullptr_t) noexcept {}
        SmartCardCryptogramMaterialCharacteristics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialCharacteristics(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramMaterialCharacteristics();
    };
    struct __declspec(empty_bases) SmartCardCryptogramMaterialPackageCharacteristics : llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics
    {
        SmartCardCryptogramMaterialPackageCharacteristics(std::nullptr_t) noexcept {}
        SmartCardCryptogramMaterialPackageCharacteristics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPackageCharacteristics(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramMaterialPackageCharacteristics();
    };
    struct __declspec(empty_bases) SmartCardCryptogramMaterialPossessionProof : llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof
    {
        SmartCardCryptogramMaterialPossessionProof(std::nullptr_t) noexcept {}
        SmartCardCryptogramMaterialPossessionProof(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramMaterialPossessionProof(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardCryptogramPlacementStep : llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep
    {
        SmartCardCryptogramPlacementStep(std::nullptr_t) noexcept {}
        SmartCardCryptogramPlacementStep(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramPlacementStep(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramPlacementStep();
    };
    struct __declspec(empty_bases) SmartCardCryptogramStorageKeyCharacteristics : llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics
    {
        SmartCardCryptogramStorageKeyCharacteristics(std::nullptr_t) noexcept {}
        SmartCardCryptogramStorageKeyCharacteristics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyCharacteristics(ptr, take_ownership_from_abi) {}
        SmartCardCryptogramStorageKeyCharacteristics();
    };
    struct __declspec(empty_bases) SmartCardCryptogramStorageKeyInfo : llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo,
        impl::require<SmartCardCryptogramStorageKeyInfo, llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo2>
    {
        SmartCardCryptogramStorageKeyInfo(std::nullptr_t) noexcept {}
        SmartCardCryptogramStorageKeyInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardCryptogramStorageKeyInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardEmulator : llm::OS::Devices::SmartCards::ISmartCardEmulator,
        impl::require<SmartCardEmulator, llm::OS::Devices::SmartCards::ISmartCardEmulator2>
    {
        SmartCardEmulator(std::nullptr_t) noexcept {}
        SmartCardEmulator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardEmulator(ptr, take_ownership_from_abi) {}
        static auto GetDefaultAsync();
        static auto GetAppletIdGroupRegistrationsAsync();
        static auto RegisterAppletIdGroupAsync(llm::OS::Devices::SmartCards::SmartCardAppletIdGroup const& appletIdGroup);
        static auto UnregisterAppletIdGroupAsync(llm::OS::Devices::SmartCards::SmartCardAppletIdGroupRegistration const& registration);
        [[nodiscard]] static auto MaxAppletIdGroupRegistrations();
        static auto IsSupported();
    };
    struct __declspec(empty_bases) SmartCardEmulatorApduReceivedEventArgs : llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs,
        impl::require<SmartCardEmulatorApduReceivedEventArgs, llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgsWithCryptograms, llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>
    {
        SmartCardEmulatorApduReceivedEventArgs(std::nullptr_t) noexcept {}
        SmartCardEmulatorApduReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs(ptr, take_ownership_from_abi) {}
        using llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs::TryRespondAsync;
        using impl::consume_t<SmartCardEmulatorApduReceivedEventArgs, llm::OS::Devices::SmartCards::ISmartCardEmulatorApduReceivedEventArgs2>::TryRespondAsync;
    };
    struct __declspec(empty_bases) SmartCardEmulatorConnectionDeactivatedEventArgs : llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs
    {
        SmartCardEmulatorConnectionDeactivatedEventArgs(std::nullptr_t) noexcept {}
        SmartCardEmulatorConnectionDeactivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionDeactivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardEmulatorConnectionProperties : llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties
    {
        SmartCardEmulatorConnectionProperties(std::nullptr_t) noexcept {}
        SmartCardEmulatorConnectionProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardEmulatorConnectionProperties(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardPinPolicy : llm::OS::Devices::SmartCards::ISmartCardPinPolicy
    {
        SmartCardPinPolicy(std::nullptr_t) noexcept {}
        SmartCardPinPolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardPinPolicy(ptr, take_ownership_from_abi) {}
        SmartCardPinPolicy();
    };
    struct __declspec(empty_bases) SmartCardPinResetDeferral : llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral
    {
        SmartCardPinResetDeferral(std::nullptr_t) noexcept {}
        SmartCardPinResetDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardPinResetDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardPinResetRequest : llm::OS::Devices::SmartCards::ISmartCardPinResetRequest
    {
        SmartCardPinResetRequest(std::nullptr_t) noexcept {}
        SmartCardPinResetRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardPinResetRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmartCardProvisioning : llm::OS::Devices::SmartCards::ISmartCardProvisioning,
        impl::require<SmartCardProvisioning, llm::OS::Devices::SmartCards::ISmartCardProvisioning2>
    {
        SmartCardProvisioning(std::nullptr_t) noexcept {}
        SmartCardProvisioning(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardProvisioning(ptr, take_ownership_from_abi) {}
        static auto FromSmartCardAsync(llm::OS::Devices::SmartCards::SmartCard const& card);
        static auto RequestVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy);
        static auto RequestVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy, llm::guid const& cardId);
        static auto RequestVirtualSmartCardDeletionAsync(llm::OS::Devices::SmartCards::SmartCard const& card);
        static auto RequestAttestedVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy);
        static auto RequestAttestedVirtualSmartCardCreationAsync(param::hstring const& friendlyName, llm::OS::Storage::Streams::IBuffer const& administrativeKey, llm::OS::Devices::SmartCards::SmartCardPinPolicy const& pinPolicy, llm::guid const& cardId);
    };
    struct __declspec(empty_bases) SmartCardReader : llm::OS::Devices::SmartCards::ISmartCardReader
    {
        SmartCardReader(std::nullptr_t) noexcept {}
        SmartCardReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardReader(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto GetDeviceSelector(llm::OS::Devices::SmartCards::SmartCardReaderKind const& kind);
        static auto FromIdAsync(param::hstring const& deviceId);
    };
    struct __declspec(empty_bases) SmartCardTriggerDetails : llm::OS::Devices::SmartCards::ISmartCardTriggerDetails,
        impl::require<SmartCardTriggerDetails, llm::OS::Devices::SmartCards::ISmartCardTriggerDetails2, llm::OS::Devices::SmartCards::ISmartCardTriggerDetails3>
    {
        SmartCardTriggerDetails(std::nullptr_t) noexcept {}
        SmartCardTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::SmartCards::ISmartCardTriggerDetails(ptr, take_ownership_from_abi) {}
    };
}
#endif
