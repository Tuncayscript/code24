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
#ifndef LLM_OS_Devices_SmartCards_1_H
#define LLM_OS_Devices_SmartCards_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.Devices.SmartCards.0.h"
LLM_EXPORT namespace llm::OS::Devices::SmartCards
{
    struct __declspec(empty_bases) ICardAddedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICardAddedEventArgs>
    {
        ICardAddedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICardAddedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICardRemovedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICardRemovedEventArgs>
    {
        ICardRemovedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ICardRemovedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownSmartCardAppletIds :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownSmartCardAppletIds>
    {
        IKnownSmartCardAppletIds(std::nullptr_t = nullptr) noexcept {}
        IKnownSmartCardAppletIds(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCard :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCard>
    {
        ISmartCard(std::nullptr_t = nullptr) noexcept {}
        ISmartCard(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAppletIdGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAppletIdGroup>
    {
        ISmartCardAppletIdGroup(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAppletIdGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAppletIdGroup2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAppletIdGroup2>
    {
        ISmartCardAppletIdGroup2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAppletIdGroup2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAppletIdGroupFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAppletIdGroupFactory>
    {
        ISmartCardAppletIdGroupFactory(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAppletIdGroupFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAppletIdGroupRegistration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAppletIdGroupRegistration>
    {
        ISmartCardAppletIdGroupRegistration(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAppletIdGroupRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAppletIdGroupRegistration2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAppletIdGroupRegistration2>
    {
        ISmartCardAppletIdGroupRegistration2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAppletIdGroupRegistration2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAppletIdGroupStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAppletIdGroupStatics>
    {
        ISmartCardAppletIdGroupStatics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAppletIdGroupStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAutomaticResponseApdu :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAutomaticResponseApdu>
    {
        ISmartCardAutomaticResponseApdu(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAutomaticResponseApdu(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAutomaticResponseApdu2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAutomaticResponseApdu2>
    {
        ISmartCardAutomaticResponseApdu2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAutomaticResponseApdu2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAutomaticResponseApdu3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAutomaticResponseApdu3>
    {
        ISmartCardAutomaticResponseApdu3(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAutomaticResponseApdu3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardAutomaticResponseApduFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardAutomaticResponseApduFactory>
    {
        ISmartCardAutomaticResponseApduFactory(std::nullptr_t = nullptr) noexcept {}
        ISmartCardAutomaticResponseApduFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardChallengeContext :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardChallengeContext>,
        impl::require<llm::OS::Devices::SmartCards::ISmartCardChallengeContext, llm::OS::Foundation::IClosable>
    {
        ISmartCardChallengeContext(std::nullptr_t = nullptr) noexcept {}
        ISmartCardChallengeContext(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardConnect :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardConnect>
    {
        ISmartCardConnect(std::nullptr_t = nullptr) noexcept {}
        ISmartCardConnect(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardConnection>,
        impl::require<llm::OS::Devices::SmartCards::ISmartCardConnection, llm::OS::Foundation::IClosable>
    {
        ISmartCardConnection(std::nullptr_t = nullptr) noexcept {}
        ISmartCardConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGenerator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGenerator>
    {
        ISmartCardCryptogramGenerator(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGenerator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGenerator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGenerator2>
    {
        ISmartCardCryptogramGenerator2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGenerator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGeneratorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGeneratorStatics>
    {
        ISmartCardCryptogramGeneratorStatics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGeneratorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGeneratorStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGeneratorStatics2>
    {
        ISmartCardCryptogramGeneratorStatics2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGeneratorStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult>
    {
        ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGetAllCryptogramMaterialCharacteristicsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult>
    {
        ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGetAllCryptogramMaterialPackageCharacteristicsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult>
    {
        ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramGetAllCryptogramStorageKeyCharacteristicsResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramMaterialCharacteristics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramMaterialCharacteristics>
    {
        ISmartCardCryptogramMaterialCharacteristics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramMaterialCharacteristics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramMaterialPackageCharacteristics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramMaterialPackageCharacteristics>
    {
        ISmartCardCryptogramMaterialPackageCharacteristics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramMaterialPackageCharacteristics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramMaterialPossessionProof :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramMaterialPossessionProof>
    {
        ISmartCardCryptogramMaterialPossessionProof(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramMaterialPossessionProof(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramPlacementStep :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramPlacementStep>
    {
        ISmartCardCryptogramPlacementStep(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramPlacementStep(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramStorageKeyCharacteristics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramStorageKeyCharacteristics>
    {
        ISmartCardCryptogramStorageKeyCharacteristics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramStorageKeyCharacteristics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramStorageKeyInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramStorageKeyInfo>
    {
        ISmartCardCryptogramStorageKeyInfo(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramStorageKeyInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardCryptogramStorageKeyInfo2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardCryptogramStorageKeyInfo2>
    {
        ISmartCardCryptogramStorageKeyInfo2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardCryptogramStorageKeyInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulator :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulator>
    {
        ISmartCardEmulator(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulator(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulator2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulator2>
    {
        ISmartCardEmulator2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulator2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorApduReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorApduReceivedEventArgs>
    {
        ISmartCardEmulatorApduReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorApduReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorApduReceivedEventArgs2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorApduReceivedEventArgs2>
    {
        ISmartCardEmulatorApduReceivedEventArgs2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorApduReceivedEventArgs2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorApduReceivedEventArgsWithCryptograms :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorApduReceivedEventArgsWithCryptograms>
    {
        ISmartCardEmulatorApduReceivedEventArgsWithCryptograms(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorApduReceivedEventArgsWithCryptograms(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorConnectionDeactivatedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorConnectionDeactivatedEventArgs>
    {
        ISmartCardEmulatorConnectionDeactivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorConnectionDeactivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorConnectionProperties :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorConnectionProperties>
    {
        ISmartCardEmulatorConnectionProperties(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorConnectionProperties(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorStatics>
    {
        ISmartCardEmulatorStatics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorStatics2>
    {
        ISmartCardEmulatorStatics2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardEmulatorStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardEmulatorStatics3>
    {
        ISmartCardEmulatorStatics3(std::nullptr_t = nullptr) noexcept {}
        ISmartCardEmulatorStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardPinPolicy :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardPinPolicy>
    {
        ISmartCardPinPolicy(std::nullptr_t = nullptr) noexcept {}
        ISmartCardPinPolicy(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardPinResetDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardPinResetDeferral>
    {
        ISmartCardPinResetDeferral(std::nullptr_t = nullptr) noexcept {}
        ISmartCardPinResetDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardPinResetRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardPinResetRequest>
    {
        ISmartCardPinResetRequest(std::nullptr_t = nullptr) noexcept {}
        ISmartCardPinResetRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardProvisioning :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardProvisioning>
    {
        ISmartCardProvisioning(std::nullptr_t = nullptr) noexcept {}
        ISmartCardProvisioning(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardProvisioning2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardProvisioning2>
    {
        ISmartCardProvisioning2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardProvisioning2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardProvisioningStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardProvisioningStatics>
    {
        ISmartCardProvisioningStatics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardProvisioningStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardProvisioningStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardProvisioningStatics2>
    {
        ISmartCardProvisioningStatics2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardProvisioningStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardReader>
    {
        ISmartCardReader(std::nullptr_t = nullptr) noexcept {}
        ISmartCardReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardReaderStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardReaderStatics>
    {
        ISmartCardReaderStatics(std::nullptr_t = nullptr) noexcept {}
        ISmartCardReaderStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardTriggerDetails>
    {
        ISmartCardTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ISmartCardTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardTriggerDetails2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardTriggerDetails2>
    {
        ISmartCardTriggerDetails2(std::nullptr_t = nullptr) noexcept {}
        ISmartCardTriggerDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmartCardTriggerDetails3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmartCardTriggerDetails3>
    {
        ISmartCardTriggerDetails3(std::nullptr_t = nullptr) noexcept {}
        ISmartCardTriggerDetails3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
