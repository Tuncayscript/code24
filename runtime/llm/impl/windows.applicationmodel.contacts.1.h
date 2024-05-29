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
#ifndef LLM_OS_ApplicationModel_Contacts_1_H
#define LLM_OS_ApplicationModel_Contacts_1_H
#include "llm/impl/Windows.Foundation.0.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts
{
    struct __declspec(empty_bases) IAggregateContactManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAggregateContactManager>
    {
        IAggregateContactManager(std::nullptr_t = nullptr) noexcept {}
        IAggregateContactManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAggregateContactManager2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAggregateContactManager2>
    {
        IAggregateContactManager2(std::nullptr_t = nullptr) noexcept {}
        IAggregateContactManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContact :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContact>
    {
        IContact(std::nullptr_t = nullptr) noexcept {}
        IContact(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContact2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContact2>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContact2, llm::OS::ApplicationModel::Contacts::IContact>
    {
        IContact2(std::nullptr_t = nullptr) noexcept {}
        IContact2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContact3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContact3>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContact3, llm::OS::ApplicationModel::Contacts::IContact, llm::OS::ApplicationModel::Contacts::IContact2>
    {
        IContact3(std::nullptr_t = nullptr) noexcept {}
        IContact3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactAddress :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactAddress>
    {
        IContactAddress(std::nullptr_t = nullptr) noexcept {}
        IContactAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactAnnotation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactAnnotation>
    {
        IContactAnnotation(std::nullptr_t = nullptr) noexcept {}
        IContactAnnotation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactAnnotation2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactAnnotation2>
    {
        IContactAnnotation2(std::nullptr_t = nullptr) noexcept {}
        IContactAnnotation2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactAnnotationList :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactAnnotationList>
    {
        IContactAnnotationList(std::nullptr_t = nullptr) noexcept {}
        IContactAnnotationList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactAnnotationStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactAnnotationStore>
    {
        IContactAnnotationStore(std::nullptr_t = nullptr) noexcept {}
        IContactAnnotationStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactAnnotationStore2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactAnnotationStore2>
    {
        IContactAnnotationStore2(std::nullptr_t = nullptr) noexcept {}
        IContactAnnotationStore2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactBatch :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactBatch>
    {
        IContactBatch(std::nullptr_t = nullptr) noexcept {}
        IContactBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactCardDelayedDataLoader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactCardDelayedDataLoader>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader, llm::OS::Foundation::IClosable>
    {
        IContactCardDelayedDataLoader(std::nullptr_t = nullptr) noexcept {}
        IContactCardDelayedDataLoader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactCardOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactCardOptions>
    {
        IContactCardOptions(std::nullptr_t = nullptr) noexcept {}
        IContactCardOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactCardOptions2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactCardOptions2>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactCardOptions2, llm::OS::ApplicationModel::Contacts::IContactCardOptions>
    {
        IContactCardOptions2(std::nullptr_t = nullptr) noexcept {}
        IContactCardOptions2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactChange :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactChange>
    {
        IContactChange(std::nullptr_t = nullptr) noexcept {}
        IContactChange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactChangeReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactChangeReader>
    {
        IContactChangeReader(std::nullptr_t = nullptr) noexcept {}
        IContactChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactChangeTracker :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactChangeTracker>
    {
        IContactChangeTracker(std::nullptr_t = nullptr) noexcept {}
        IContactChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactChangeTracker2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactChangeTracker2>
    {
        IContactChangeTracker2(std::nullptr_t = nullptr) noexcept {}
        IContactChangeTracker2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactChangedDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactChangedDeferral>
    {
        IContactChangedDeferral(std::nullptr_t = nullptr) noexcept {}
        IContactChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactChangedEventArgs>
    {
        IContactChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactConnectedServiceAccount :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactConnectedServiceAccount>
    {
        IContactConnectedServiceAccount(std::nullptr_t = nullptr) noexcept {}
        IContactConnectedServiceAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactDate :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactDate>
    {
        IContactDate(std::nullptr_t = nullptr) noexcept {}
        IContactDate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactEmail :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactEmail>
    {
        IContactEmail(std::nullptr_t = nullptr) noexcept {}
        IContactEmail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactField :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactField>
    {
        IContactField(std::nullptr_t = nullptr) noexcept {}
        IContactField(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactFieldFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactFieldFactory>
    {
        IContactFieldFactory(std::nullptr_t = nullptr) noexcept {}
        IContactFieldFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactGroup :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactGroup>
    {
        IContactGroup(std::nullptr_t = nullptr) noexcept {}
        IContactGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactInformation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactInformation>
    {
        IContactInformation(std::nullptr_t = nullptr) noexcept {}
        IContactInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactInstantMessageField :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactInstantMessageField>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactInstantMessageField, llm::OS::ApplicationModel::Contacts::IContactField>
    {
        IContactInstantMessageField(std::nullptr_t = nullptr) noexcept {}
        IContactInstantMessageField(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactInstantMessageFieldFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactInstantMessageFieldFactory>
    {
        IContactInstantMessageFieldFactory(std::nullptr_t = nullptr) noexcept {}
        IContactInstantMessageFieldFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactJobInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactJobInfo>
    {
        IContactJobInfo(std::nullptr_t = nullptr) noexcept {}
        IContactJobInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactLaunchActionVerbsStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactLaunchActionVerbsStatics>
    {
        IContactLaunchActionVerbsStatics(std::nullptr_t = nullptr) noexcept {}
        IContactLaunchActionVerbsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactList :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactList>
    {
        IContactList(std::nullptr_t = nullptr) noexcept {}
        IContactList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactList2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactList2>
    {
        IContactList2(std::nullptr_t = nullptr) noexcept {}
        IContactList2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactList3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactList3>
    {
        IContactList3(std::nullptr_t = nullptr) noexcept {}
        IContactList3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListLimitedWriteOperations :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListLimitedWriteOperations>
    {
        IContactListLimitedWriteOperations(std::nullptr_t = nullptr) noexcept {}
        IContactListLimitedWriteOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListSyncConstraints :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListSyncConstraints>
    {
        IContactListSyncConstraints(std::nullptr_t = nullptr) noexcept {}
        IContactListSyncConstraints(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListSyncManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListSyncManager>
    {
        IContactListSyncManager(std::nullptr_t = nullptr) noexcept {}
        IContactListSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactListSyncManager2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactListSyncManager2>
    {
        IContactListSyncManager2(std::nullptr_t = nullptr) noexcept {}
        IContactListSyncManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactLocationField :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactLocationField>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactLocationField, llm::OS::ApplicationModel::Contacts::IContactField>
    {
        IContactLocationField(std::nullptr_t = nullptr) noexcept {}
        IContactLocationField(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactLocationFieldFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactLocationFieldFactory>
    {
        IContactLocationFieldFactory(std::nullptr_t = nullptr) noexcept {}
        IContactLocationFieldFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactManagerForUser :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerForUser>
    {
        IContactManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IContactManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactManagerForUser2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerForUser2>
    {
        IContactManagerForUser2(std::nullptr_t = nullptr) noexcept {}
        IContactManagerForUser2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerStatics>
    {
        IContactManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IContactManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerStatics2>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactManagerStatics2, llm::OS::ApplicationModel::Contacts::IContactManagerStatics>
    {
        IContactManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IContactManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactManagerStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerStatics3>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactManagerStatics3, llm::OS::ApplicationModel::Contacts::IContactManagerStatics, llm::OS::ApplicationModel::Contacts::IContactManagerStatics2>
    {
        IContactManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IContactManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IContactManagerStatics3, IContactManagerStatics3>::RequestStoreAsync;
        using impl::consume_t<IContactManagerStatics3, llm::OS::ApplicationModel::Contacts::IContactManagerStatics2>::RequestStoreAsync;
        using impl::consume_t<IContactManagerStatics3, IContactManagerStatics3>::ShowContactCard;
        using impl::consume_t<IContactManagerStatics3, llm::OS::ApplicationModel::Contacts::IContactManagerStatics>::ShowContactCard;
        using impl::consume_t<IContactManagerStatics3, IContactManagerStatics3>::ShowDelayLoadedContactCard;
        using impl::consume_t<IContactManagerStatics3, llm::OS::ApplicationModel::Contacts::IContactManagerStatics>::ShowDelayLoadedContactCard;
    };
    struct __declspec(empty_bases) IContactManagerStatics4 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerStatics4>
    {
        IContactManagerStatics4(std::nullptr_t = nullptr) noexcept {}
        IContactManagerStatics4(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactManagerStatics5 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactManagerStatics5>
    {
        IContactManagerStatics5(std::nullptr_t = nullptr) noexcept {}
        IContactManagerStatics5(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactMatchReason :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactMatchReason>
    {
        IContactMatchReason(std::nullptr_t = nullptr) noexcept {}
        IContactMatchReason(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactName :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactName>
    {
        IContactName(std::nullptr_t = nullptr) noexcept {}
        IContactName(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPanel :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPanel>
    {
        IContactPanel(std::nullptr_t = nullptr) noexcept {}
        IContactPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPanelClosingEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPanelClosingEventArgs>
    {
        IContactPanelClosingEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactPanelClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPanelLaunchFullAppRequestedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPanelLaunchFullAppRequestedEventArgs>
    {
        IContactPanelLaunchFullAppRequestedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IContactPanelLaunchFullAppRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPhone :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPhone>
    {
        IContactPhone(std::nullptr_t = nullptr) noexcept {}
        IContactPhone(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPicker :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPicker>
    {
        IContactPicker(std::nullptr_t = nullptr) noexcept {}
        IContactPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPicker2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPicker2>
    {
        IContactPicker2(std::nullptr_t = nullptr) noexcept {}
        IContactPicker2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPicker3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPicker3>
    {
        IContactPicker3(std::nullptr_t = nullptr) noexcept {}
        IContactPicker3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactPickerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactPickerStatics>
    {
        IContactPickerStatics(std::nullptr_t = nullptr) noexcept {}
        IContactPickerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactQueryOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactQueryOptions>
    {
        IContactQueryOptions(std::nullptr_t = nullptr) noexcept {}
        IContactQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactQueryOptionsFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactQueryOptionsFactory>
    {
        IContactQueryOptionsFactory(std::nullptr_t = nullptr) noexcept {}
        IContactQueryOptionsFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactQueryTextSearch :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactQueryTextSearch>
    {
        IContactQueryTextSearch(std::nullptr_t = nullptr) noexcept {}
        IContactQueryTextSearch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactReader>
    {
        IContactReader(std::nullptr_t = nullptr) noexcept {}
        IContactReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactSignificantOther :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactSignificantOther>
    {
        IContactSignificantOther(std::nullptr_t = nullptr) noexcept {}
        IContactSignificantOther(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactSignificantOther2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactSignificantOther2>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactSignificantOther2, llm::OS::ApplicationModel::Contacts::IContactSignificantOther>
    {
        IContactSignificantOther2(std::nullptr_t = nullptr) noexcept {}
        IContactSignificantOther2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactStore>
    {
        IContactStore(std::nullptr_t = nullptr) noexcept {}
        IContactStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactStore2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactStore2>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactStore2, llm::OS::ApplicationModel::Contacts::IContactStore>
    {
        IContactStore2(std::nullptr_t = nullptr) noexcept {}
        IContactStore2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactStore3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactStore3>
    {
        IContactStore3(std::nullptr_t = nullptr) noexcept {}
        IContactStore3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactStoreNotificationTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactStoreNotificationTriggerDetails>
    {
        IContactStoreNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IContactStoreNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactWebsite :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactWebsite>
    {
        IContactWebsite(std::nullptr_t = nullptr) noexcept {}
        IContactWebsite(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IContactWebsite2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IContactWebsite2>,
        impl::require<llm::OS::ApplicationModel::Contacts::IContactWebsite2, llm::OS::ApplicationModel::Contacts::IContactWebsite>
    {
        IContactWebsite2(std::nullptr_t = nullptr) noexcept {}
        IContactWebsite2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFullContactCardOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFullContactCardOptions>
    {
        IFullContactCardOptions(std::nullptr_t = nullptr) noexcept {}
        IFullContactCardOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IKnownContactFieldStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IKnownContactFieldStatics>
    {
        IKnownContactFieldStatics(std::nullptr_t = nullptr) noexcept {}
        IKnownContactFieldStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPinnedContactIdsQueryResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPinnedContactIdsQueryResult>
    {
        IPinnedContactIdsQueryResult(std::nullptr_t = nullptr) noexcept {}
        IPinnedContactIdsQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPinnedContactManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPinnedContactManager>
    {
        IPinnedContactManager(std::nullptr_t = nullptr) noexcept {}
        IPinnedContactManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPinnedContactManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPinnedContactManagerStatics>
    {
        IPinnedContactManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPinnedContactManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
