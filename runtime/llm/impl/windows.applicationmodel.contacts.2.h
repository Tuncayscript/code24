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
#ifndef LLM_OS_ApplicationModel_Contacts_2_H
#define LLM_OS_ApplicationModel_Contacts_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.UI.Popups.1.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts
{
    struct __declspec(empty_bases) AggregateContactManager : llm::OS::ApplicationModel::Contacts::IAggregateContactManager,
        impl::require<AggregateContactManager, llm::OS::ApplicationModel::Contacts::IAggregateContactManager2>
    {
        AggregateContactManager(std::nullptr_t) noexcept {}
        AggregateContactManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IAggregateContactManager(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) Contact : llm::OS::ApplicationModel::Contacts::IContact,
        impl::require<Contact, llm::OS::ApplicationModel::Contacts::IContact2, llm::OS::ApplicationModel::Contacts::IContactName, llm::OS::ApplicationModel::Contacts::IContact3>
    {
        Contact(std::nullptr_t) noexcept {}
        Contact(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContact(ptr, take_ownership_from_abi) {}
        Contact();
    };
    struct __declspec(empty_bases) ContactAddress : llm::OS::ApplicationModel::Contacts::IContactAddress
    {
        ContactAddress(std::nullptr_t) noexcept {}
        ContactAddress(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactAddress(ptr, take_ownership_from_abi) {}
        ContactAddress();
    };
    struct __declspec(empty_bases) ContactAnnotation : llm::OS::ApplicationModel::Contacts::IContactAnnotation,
        impl::require<ContactAnnotation, llm::OS::ApplicationModel::Contacts::IContactAnnotation2>
    {
        ContactAnnotation(std::nullptr_t) noexcept {}
        ContactAnnotation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactAnnotation(ptr, take_ownership_from_abi) {}
        ContactAnnotation();
    };
    struct __declspec(empty_bases) ContactAnnotationList : llm::OS::ApplicationModel::Contacts::IContactAnnotationList
    {
        ContactAnnotationList(std::nullptr_t) noexcept {}
        ContactAnnotationList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactAnnotationList(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactAnnotationStore : llm::OS::ApplicationModel::Contacts::IContactAnnotationStore,
        impl::require<ContactAnnotationStore, llm::OS::ApplicationModel::Contacts::IContactAnnotationStore2>
    {
        ContactAnnotationStore(std::nullptr_t) noexcept {}
        ContactAnnotationStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactAnnotationStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactBatch : llm::OS::ApplicationModel::Contacts::IContactBatch
    {
        ContactBatch(std::nullptr_t) noexcept {}
        ContactBatch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactBatch(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactCardDelayedDataLoader : llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader
    {
        ContactCardDelayedDataLoader(std::nullptr_t) noexcept {}
        ContactCardDelayedDataLoader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactCardOptions : llm::OS::ApplicationModel::Contacts::IContactCardOptions,
        impl::require<ContactCardOptions, llm::OS::ApplicationModel::Contacts::IContactCardOptions2>
    {
        ContactCardOptions(std::nullptr_t) noexcept {}
        ContactCardOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactCardOptions(ptr, take_ownership_from_abi) {}
        ContactCardOptions();
    };
    struct __declspec(empty_bases) ContactChange : llm::OS::ApplicationModel::Contacts::IContactChange
    {
        ContactChange(std::nullptr_t) noexcept {}
        ContactChange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactChangeReader : llm::OS::ApplicationModel::Contacts::IContactChangeReader
    {
        ContactChangeReader(std::nullptr_t) noexcept {}
        ContactChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactChangeReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactChangeTracker : llm::OS::ApplicationModel::Contacts::IContactChangeTracker,
        impl::require<ContactChangeTracker, llm::OS::ApplicationModel::Contacts::IContactChangeTracker2>
    {
        ContactChangeTracker(std::nullptr_t) noexcept {}
        ContactChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactChangeTracker(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactChangedDeferral : llm::OS::ApplicationModel::Contacts::IContactChangedDeferral
    {
        ContactChangedDeferral(std::nullptr_t) noexcept {}
        ContactChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactChangedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactChangedEventArgs : llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs
    {
        ContactChangedEventArgs(std::nullptr_t) noexcept {}
        ContactChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactConnectedServiceAccount : llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount
    {
        ContactConnectedServiceAccount(std::nullptr_t) noexcept {}
        ContactConnectedServiceAccount(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount(ptr, take_ownership_from_abi) {}
        ContactConnectedServiceAccount();
    };
    struct __declspec(empty_bases) ContactDate : llm::OS::ApplicationModel::Contacts::IContactDate
    {
        ContactDate(std::nullptr_t) noexcept {}
        ContactDate(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactDate(ptr, take_ownership_from_abi) {}
        ContactDate();
    };
    struct __declspec(empty_bases) ContactEmail : llm::OS::ApplicationModel::Contacts::IContactEmail
    {
        ContactEmail(std::nullptr_t) noexcept {}
        ContactEmail(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactEmail(ptr, take_ownership_from_abi) {}
        ContactEmail();
    };
    struct __declspec(empty_bases) ContactField : llm::OS::ApplicationModel::Contacts::IContactField
    {
        ContactField(std::nullptr_t) noexcept {}
        ContactField(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactField(ptr, take_ownership_from_abi) {}
        ContactField(param::hstring const& value, llm::OS::ApplicationModel::Contacts::ContactFieldType const& type);
        ContactField(param::hstring const& value, llm::OS::ApplicationModel::Contacts::ContactFieldType const& type, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category);
        ContactField(param::hstring const& name, param::hstring const& value, llm::OS::ApplicationModel::Contacts::ContactFieldType const& type, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category);
    };
    struct __declspec(empty_bases) ContactFieldFactory : llm::OS::ApplicationModel::Contacts::IContactFieldFactory,
        impl::require<ContactFieldFactory, llm::OS::ApplicationModel::Contacts::IContactLocationFieldFactory, llm::OS::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>
    {
        ContactFieldFactory(std::nullptr_t) noexcept {}
        ContactFieldFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactFieldFactory(ptr, take_ownership_from_abi) {}
        ContactFieldFactory();
    };
    struct __declspec(empty_bases) ContactGroup : llm::OS::ApplicationModel::Contacts::IContactGroup
    {
        ContactGroup(std::nullptr_t) noexcept {}
        ContactGroup(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactGroup(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactInformation : llm::OS::ApplicationModel::Contacts::IContactInformation
    {
        ContactInformation(std::nullptr_t) noexcept {}
        ContactInformation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactInformation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactInstantMessageField : llm::OS::ApplicationModel::Contacts::IContactInstantMessageField
    {
        ContactInstantMessageField(std::nullptr_t) noexcept {}
        ContactInstantMessageField(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactInstantMessageField(ptr, take_ownership_from_abi) {}
        explicit ContactInstantMessageField(param::hstring const& userName);
        ContactInstantMessageField(param::hstring const& userName, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category);
        ContactInstantMessageField(param::hstring const& userName, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category, param::hstring const& service, param::hstring const& displayText, llm::OS::Foundation::Uri const& verb);
    };
    struct __declspec(empty_bases) ContactJobInfo : llm::OS::ApplicationModel::Contacts::IContactJobInfo
    {
        ContactJobInfo(std::nullptr_t) noexcept {}
        ContactJobInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactJobInfo(ptr, take_ownership_from_abi) {}
        ContactJobInfo();
    };
    struct ContactLaunchActionVerbs
    {
        ContactLaunchActionVerbs() = delete;
        [[nodiscard]] static auto Call();
        [[nodiscard]] static auto Message();
        [[nodiscard]] static auto Map();
        [[nodiscard]] static auto Post();
        [[nodiscard]] static auto VideoCall();
    };
    struct __declspec(empty_bases) ContactList : llm::OS::ApplicationModel::Contacts::IContactList,
        impl::require<ContactList, llm::OS::ApplicationModel::Contacts::IContactList2, llm::OS::ApplicationModel::Contacts::IContactList3>
    {
        ContactList(std::nullptr_t) noexcept {}
        ContactList(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactList(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Contacts::IContactList::SupportsServerSearch;
        using impl::consume_t<ContactList, llm::OS::ApplicationModel::Contacts::IContactList2>::SupportsServerSearch;
    };
    struct __declspec(empty_bases) ContactListLimitedWriteOperations : llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations
    {
        ContactListLimitedWriteOperations(std::nullptr_t) noexcept {}
        ContactListLimitedWriteOperations(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListSyncConstraints : llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints
    {
        ContactListSyncConstraints(std::nullptr_t) noexcept {}
        ContactListSyncConstraints(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactListSyncManager : llm::OS::ApplicationModel::Contacts::IContactListSyncManager,
        impl::require<ContactListSyncManager, llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>
    {
        ContactListSyncManager(std::nullptr_t) noexcept {}
        ContactListSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactListSyncManager(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Contacts::IContactListSyncManager::LastAttemptedSyncTime;
        using impl::consume_t<ContactListSyncManager, llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>::LastAttemptedSyncTime;
        using llm::OS::ApplicationModel::Contacts::IContactListSyncManager::LastSuccessfulSyncTime;
        using impl::consume_t<ContactListSyncManager, llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>::LastSuccessfulSyncTime;
        using llm::OS::ApplicationModel::Contacts::IContactListSyncManager::Status;
        using impl::consume_t<ContactListSyncManager, llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>::Status;
    };
    struct __declspec(empty_bases) ContactLocationField : llm::OS::ApplicationModel::Contacts::IContactLocationField
    {
        ContactLocationField(std::nullptr_t) noexcept {}
        ContactLocationField(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactLocationField(ptr, take_ownership_from_abi) {}
        explicit ContactLocationField(param::hstring const& unstructuredAddress);
        ContactLocationField(param::hstring const& unstructuredAddress, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category);
        ContactLocationField(param::hstring const& unstructuredAddress, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category, param::hstring const& street, param::hstring const& city, param::hstring const& region, param::hstring const& country, param::hstring const& postalCode);
    };
    struct ContactManager
    {
        ContactManager() = delete;
        static auto ShowContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection);
        static auto ShowContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement);
        static auto ShowDelayLoadedContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement);
        static auto RequestStoreAsync();
        static auto ConvertContactToVCardAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact);
        static auto ConvertContactToVCardAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact, uint32_t maxBytes);
        static auto ConvertVCardToContactAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& vCard);
        static auto RequestStoreAsync(llm::OS::ApplicationModel::Contacts::ContactStoreAccessType const& accessType);
        static auto RequestAnnotationStoreAsync(llm::OS::ApplicationModel::Contacts::ContactAnnotationStoreAccessType const& accessType);
        static auto IsShowContactCardSupported();
        static auto ShowContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement, llm::OS::ApplicationModel::Contacts::ContactCardOptions const& contactCardOptions);
        static auto IsShowDelayLoadedContactCardSupported();
        static auto ShowDelayLoadedContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement, llm::OS::ApplicationModel::Contacts::ContactCardOptions const& contactCardOptions);
        static auto ShowFullContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::ApplicationModel::Contacts::FullContactCardOptions const& fullContactCardOptions);
        [[nodiscard]] static auto SystemDisplayNameOrder();
        static auto SystemDisplayNameOrder(llm::OS::ApplicationModel::Contacts::ContactNameOrder const& value);
        [[nodiscard]] static auto SystemSortOrder();
        static auto SystemSortOrder(llm::OS::ApplicationModel::Contacts::ContactNameOrder const& value);
        static auto GetForUser(llm::OS::System::User const& user);
        static auto IsShowFullContactCardSupportedAsync();
        [[nodiscard]] static auto IncludeMiddleNameInSystemDisplayAndSort();
        static auto IncludeMiddleNameInSystemDisplayAndSort(bool value);
    };
    struct __declspec(empty_bases) ContactManagerForUser : llm::OS::ApplicationModel::Contacts::IContactManagerForUser,
        impl::require<ContactManagerForUser, llm::OS::ApplicationModel::Contacts::IContactManagerForUser2>
    {
        ContactManagerForUser(std::nullptr_t) noexcept {}
        ContactManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactMatchReason : llm::OS::ApplicationModel::Contacts::IContactMatchReason
    {
        ContactMatchReason(std::nullptr_t) noexcept {}
        ContactMatchReason(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactMatchReason(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPanel : llm::OS::ApplicationModel::Contacts::IContactPanel
    {
        ContactPanel(std::nullptr_t) noexcept {}
        ContactPanel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactPanel(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPanelClosingEventArgs : llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs
    {
        ContactPanelClosingEventArgs(std::nullptr_t) noexcept {}
        ContactPanelClosingEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPanelLaunchFullAppRequestedEventArgs : llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs
    {
        ContactPanelLaunchFullAppRequestedEventArgs(std::nullptr_t) noexcept {}
        ContactPanelLaunchFullAppRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactPhone : llm::OS::ApplicationModel::Contacts::IContactPhone
    {
        ContactPhone(std::nullptr_t) noexcept {}
        ContactPhone(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactPhone(ptr, take_ownership_from_abi) {}
        ContactPhone();
    };
    struct __declspec(empty_bases) ContactPicker : llm::OS::ApplicationModel::Contacts::IContactPicker,
        impl::require<ContactPicker, llm::OS::ApplicationModel::Contacts::IContactPicker2, llm::OS::ApplicationModel::Contacts::IContactPicker3>
    {
        ContactPicker(std::nullptr_t) noexcept {}
        ContactPicker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactPicker(ptr, take_ownership_from_abi) {}
        ContactPicker();
        static auto CreateForUser(llm::OS::System::User const& user);
        static auto IsSupportedAsync();
    };
    struct __declspec(empty_bases) ContactQueryOptions : llm::OS::ApplicationModel::Contacts::IContactQueryOptions
    {
        ContactQueryOptions(std::nullptr_t) noexcept {}
        ContactQueryOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactQueryOptions(ptr, take_ownership_from_abi) {}
        ContactQueryOptions();
        explicit ContactQueryOptions(param::hstring const& text);
        ContactQueryOptions(param::hstring const& text, llm::OS::ApplicationModel::Contacts::ContactQuerySearchFields const& fields);
    };
    struct __declspec(empty_bases) ContactQueryTextSearch : llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch
    {
        ContactQueryTextSearch(std::nullptr_t) noexcept {}
        ContactQueryTextSearch(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactReader : llm::OS::ApplicationModel::Contacts::IContactReader
    {
        ContactReader(std::nullptr_t) noexcept {}
        ContactReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactSignificantOther : llm::OS::ApplicationModel::Contacts::IContactSignificantOther,
        impl::require<ContactSignificantOther, llm::OS::ApplicationModel::Contacts::IContactSignificantOther2>
    {
        ContactSignificantOther(std::nullptr_t) noexcept {}
        ContactSignificantOther(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactSignificantOther(ptr, take_ownership_from_abi) {}
        ContactSignificantOther();
    };
    struct __declspec(empty_bases) ContactStore : llm::OS::ApplicationModel::Contacts::IContactStore,
        impl::require<ContactStore, llm::OS::ApplicationModel::Contacts::IContactStore2, llm::OS::ApplicationModel::Contacts::IContactStore3>
    {
        ContactStore(std::nullptr_t) noexcept {}
        ContactStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactStoreNotificationTriggerDetails : llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails
    {
        ContactStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
        ContactStoreNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ContactWebsite : llm::OS::ApplicationModel::Contacts::IContactWebsite,
        impl::require<ContactWebsite, llm::OS::ApplicationModel::Contacts::IContactWebsite2>
    {
        ContactWebsite(std::nullptr_t) noexcept {}
        ContactWebsite(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IContactWebsite(ptr, take_ownership_from_abi) {}
        ContactWebsite();
    };
    struct __declspec(empty_bases) FullContactCardOptions : llm::OS::ApplicationModel::Contacts::IFullContactCardOptions
    {
        FullContactCardOptions(std::nullptr_t) noexcept {}
        FullContactCardOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IFullContactCardOptions(ptr, take_ownership_from_abi) {}
        FullContactCardOptions();
    };
    struct KnownContactField
    {
        KnownContactField() = delete;
        [[nodiscard]] static auto Email();
        [[nodiscard]] static auto PhoneNumber();
        [[nodiscard]] static auto Location();
        [[nodiscard]] static auto InstantMessage();
        static auto ConvertNameToType(param::hstring const& name);
        static auto ConvertTypeToName(llm::OS::ApplicationModel::Contacts::ContactFieldType const& type);
    };
    struct __declspec(empty_bases) PinnedContactIdsQueryResult : llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult
    {
        PinnedContactIdsQueryResult(std::nullptr_t) noexcept {}
        PinnedContactIdsQueryResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PinnedContactManager : llm::OS::ApplicationModel::Contacts::IPinnedContactManager
    {
        PinnedContactManager(std::nullptr_t) noexcept {}
        PinnedContactManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Contacts::IPinnedContactManager(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto GetForUser(llm::OS::System::User const& user);
        static auto IsSupported();
    };
}
#endif
