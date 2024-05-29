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
#ifndef LLM_OS_ApplicationModel_Contacts_0_H
#define LLM_OS_ApplicationModel_Contacts_0_H
LLM_EXPORT namespace llm::OS::Data::Text
{
    struct TextSegment;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct Deferral;
    struct EventRegistrationToken;
    struct IAsyncAction;
    template <typename TResult> struct __declspec(empty_bases) IAsyncOperation;
    template <typename T> struct __declspec(empty_bases) IReference;
    struct Rect;
    template <typename TSender, typename TResult> struct __declspec(empty_bases) TypedEventHandler;
    struct Uri;
}
LLM_EXPORT namespace llm::OS::Foundation::Collections
{
    template <typename T> struct __declspec(empty_bases) IIterable;
    struct IPropertySet;
    template <typename T> struct __declspec(empty_bases) IVectorView;
    template <typename T> struct __declspec(empty_bases) IVector;
    struct ValueSet;
}
LLM_EXPORT namespace llm::OS::Storage::Streams
{
    struct IRandomAccessStreamReference;
    struct IRandomAccessStreamWithContentType;
    struct RandomAccessStreamReference;
}
LLM_EXPORT namespace llm::OS::System
{
    struct User;
}
LLM_EXPORT namespace llm::OS::UI
{
    struct Color;
}
LLM_EXPORT namespace llm::OS::UI::Popups
{
    enum class Placement : int32_t;
}
LLM_EXPORT namespace llm::OS::UI::ViewManagement
{
    enum class ViewSizePreference : int32_t;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Contacts
{
    enum class ContactAddressKind : int32_t
    {
        Home = 0,
        Work = 1,
        Other = 2,
    };
    enum class ContactAnnotationOperations : uint32_t
    {
        None = 0,
        ContactProfile = 0x1,
        Message = 0x2,
        AudioCall = 0x4,
        VideoCall = 0x8,
        SocialFeeds = 0x10,
        Share = 0x20,
    };
    enum class ContactAnnotationStoreAccessType : int32_t
    {
        AppAnnotationsReadWrite = 0,
        AllAnnotationsReadWrite = 1,
    };
    enum class ContactBatchStatus : int32_t
    {
        Success = 0,
        ServerSearchSyncManagerError = 1,
        ServerSearchUnknownError = 2,
    };
    enum class ContactCardHeaderKind : int32_t
    {
        Default = 0,
        Basic = 1,
        Enterprise = 2,
    };
    enum class ContactCardTabKind : int32_t
    {
        Default = 0,
        Email = 1,
        Messaging = 2,
        Phone = 3,
        Video = 4,
        OrganizationalHierarchy = 5,
    };
    enum class ContactChangeType : int32_t
    {
        Created = 0,
        Modified = 1,
        Deleted = 2,
        ChangeTrackingLost = 3,
    };
    enum class ContactDateKind : int32_t
    {
        Birthday = 0,
        Anniversary = 1,
        Other = 2,
    };
    enum class ContactEmailKind : int32_t
    {
        Personal = 0,
        Work = 1,
        Other = 2,
    };
    enum class ContactFieldCategory : int32_t
    {
        None = 0,
        Home = 1,
        Work = 2,
        Mobile = 3,
        Other = 4,
    };
    enum class ContactFieldType : int32_t
    {
        Email = 0,
        PhoneNumber = 1,
        Location = 2,
        InstantMessage = 3,
        Custom = 4,
        ConnectedServiceAccount = 5,
        ImportantDate = 6,
        Address = 7,
        SignificantOther = 8,
        Notes = 9,
        Website = 10,
        JobInfo = 11,
    };
    enum class ContactListOtherAppReadAccess : int32_t
    {
        SystemOnly = 0,
        Limited = 1,
        Full = 2,
        None = 3,
    };
    enum class ContactListOtherAppWriteAccess : int32_t
    {
        None = 0,
        SystemOnly = 1,
        Limited = 2,
    };
    enum class ContactListSyncStatus : int32_t
    {
        Idle = 0,
        Syncing = 1,
        UpToDate = 2,
        AuthenticationError = 3,
        PolicyError = 4,
        UnknownError = 5,
        ManualAccountRemovalRequired = 6,
    };
    enum class ContactMatchReasonKind : int32_t
    {
        Name = 0,
        EmailAddress = 1,
        PhoneNumber = 2,
        JobInfo = 3,
        YomiName = 4,
        Other = 5,
    };
    enum class ContactNameOrder : int32_t
    {
        FirstNameLastName = 0,
        LastNameFirstName = 1,
    };
    enum class ContactPhoneKind : int32_t
    {
        Home = 0,
        Mobile = 1,
        Work = 2,
        Other = 3,
        Pager = 4,
        BusinessFax = 5,
        HomeFax = 6,
        Company = 7,
        Assistant = 8,
        Radio = 9,
    };
    enum class ContactQueryDesiredFields : uint32_t
    {
        None = 0,
        PhoneNumber = 0x1,
        EmailAddress = 0x2,
        PostalAddress = 0x4,
    };
    enum class ContactQuerySearchFields : uint32_t
    {
        None = 0,
        Name = 0x1,
        Email = 0x2,
        Phone = 0x4,
        All = 0xffffffff,
    };
    enum class ContactQuerySearchScope : int32_t
    {
        Local = 0,
        Server = 1,
    };
    enum class ContactRelationship : int32_t
    {
        Other = 0,
        Spouse = 1,
        Partner = 2,
        Sibling = 3,
        Parent = 4,
        Child = 5,
    };
    enum class ContactSelectionMode : int32_t
    {
        Contacts = 0,
        Fields = 1,
    };
    enum class ContactStoreAccessType : int32_t
    {
        AppContactsReadWrite = 0,
        AllContactsReadOnly = 1,
        AllContactsReadWrite = 2,
    };
    enum class PinnedContactSurface : int32_t
    {
        StartMenu = 0,
        Taskbar = 1,
    };
    struct IAggregateContactManager;
    struct IAggregateContactManager2;
    struct IContact;
    struct IContact2;
    struct IContact3;
    struct IContactAddress;
    struct IContactAnnotation;
    struct IContactAnnotation2;
    struct IContactAnnotationList;
    struct IContactAnnotationStore;
    struct IContactAnnotationStore2;
    struct IContactBatch;
    struct IContactCardDelayedDataLoader;
    struct IContactCardOptions;
    struct IContactCardOptions2;
    struct IContactChange;
    struct IContactChangeReader;
    struct IContactChangeTracker;
    struct IContactChangeTracker2;
    struct IContactChangedDeferral;
    struct IContactChangedEventArgs;
    struct IContactConnectedServiceAccount;
    struct IContactDate;
    struct IContactEmail;
    struct IContactField;
    struct IContactFieldFactory;
    struct IContactGroup;
    struct IContactInformation;
    struct IContactInstantMessageField;
    struct IContactInstantMessageFieldFactory;
    struct IContactJobInfo;
    struct IContactLaunchActionVerbsStatics;
    struct IContactList;
    struct IContactList2;
    struct IContactList3;
    struct IContactListLimitedWriteOperations;
    struct IContactListSyncConstraints;
    struct IContactListSyncManager;
    struct IContactListSyncManager2;
    struct IContactLocationField;
    struct IContactLocationFieldFactory;
    struct IContactManagerForUser;
    struct IContactManagerForUser2;
    struct IContactManagerStatics;
    struct IContactManagerStatics2;
    struct IContactManagerStatics3;
    struct IContactManagerStatics4;
    struct IContactManagerStatics5;
    struct IContactMatchReason;
    struct IContactName;
    struct IContactPanel;
    struct IContactPanelClosingEventArgs;
    struct IContactPanelLaunchFullAppRequestedEventArgs;
    struct IContactPhone;
    struct IContactPicker;
    struct IContactPicker2;
    struct IContactPicker3;
    struct IContactPickerStatics;
    struct IContactQueryOptions;
    struct IContactQueryOptionsFactory;
    struct IContactQueryTextSearch;
    struct IContactReader;
    struct IContactSignificantOther;
    struct IContactSignificantOther2;
    struct IContactStore;
    struct IContactStore2;
    struct IContactStore3;
    struct IContactStoreNotificationTriggerDetails;
    struct IContactWebsite;
    struct IContactWebsite2;
    struct IFullContactCardOptions;
    struct IKnownContactFieldStatics;
    struct IPinnedContactIdsQueryResult;
    struct IPinnedContactManager;
    struct IPinnedContactManagerStatics;
    struct AggregateContactManager;
    struct Contact;
    struct ContactAddress;
    struct ContactAnnotation;
    struct ContactAnnotationList;
    struct ContactAnnotationStore;
    struct ContactBatch;
    struct ContactCardDelayedDataLoader;
    struct ContactCardOptions;
    struct ContactChange;
    struct ContactChangeReader;
    struct ContactChangeTracker;
    struct ContactChangedDeferral;
    struct ContactChangedEventArgs;
    struct ContactConnectedServiceAccount;
    struct ContactDate;
    struct ContactEmail;
    struct ContactField;
    struct ContactFieldFactory;
    struct ContactGroup;
    struct ContactInformation;
    struct ContactInstantMessageField;
    struct ContactJobInfo;
    struct ContactLaunchActionVerbs;
    struct ContactList;
    struct ContactListLimitedWriteOperations;
    struct ContactListSyncConstraints;
    struct ContactListSyncManager;
    struct ContactLocationField;
    struct ContactManager;
    struct ContactManagerForUser;
    struct ContactMatchReason;
    struct ContactPanel;
    struct ContactPanelClosingEventArgs;
    struct ContactPanelLaunchFullAppRequestedEventArgs;
    struct ContactPhone;
    struct ContactPicker;
    struct ContactQueryOptions;
    struct ContactQueryTextSearch;
    struct ContactReader;
    struct ContactSignificantOther;
    struct ContactStore;
    struct ContactStoreNotificationTriggerDetails;
    struct ContactWebsite;
    struct FullContactCardOptions;
    struct KnownContactField;
    struct PinnedContactIdsQueryResult;
    struct PinnedContactManager;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Contacts::IAggregateContactManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IAggregateContactManager2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContact>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContact2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContact3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactAddress>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactAnnotation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactAnnotation2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactAnnotationList>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactBatch>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactCardOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactCardOptions2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactChange>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactChangeReader>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactChangeTracker>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactChangeTracker2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactChangedDeferral>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactDate>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactEmail>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactField>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactFieldFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactGroup>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactInformation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactInstantMessageField>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactJobInfo>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactList>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactList2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactList3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactListSyncManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactLocationField>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactLocationFieldFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerForUser>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerForUser2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerStatics3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerStatics4>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactManagerStatics5>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactMatchReason>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactName>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPanel>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPhone>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPicker>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPicker2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPicker3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactPickerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactQueryOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactQueryOptionsFactory>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactReader>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactSignificantOther>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactSignificantOther2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactStore>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactStore2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactStore3>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactWebsite>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IContactWebsite2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IFullContactCardOptions>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IKnownContactFieldStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IPinnedContactManager>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::IPinnedContactManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::AggregateContactManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::Contact>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAddress>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAnnotation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAnnotationStore>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactBatch>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactCardDelayedDataLoader>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactCardOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactChange>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactChangeReader>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactChangeTracker>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactChangedDeferral>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactConnectedServiceAccount>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactDate>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactEmail>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactField>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactFieldFactory>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactGroup>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactInformation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactInstantMessageField>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactJobInfo>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactLaunchActionVerbs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactList>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactListLimitedWriteOperations>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactListSyncConstraints>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactListSyncManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactLocationField>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactManagerForUser>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactMatchReason>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactPanel>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactPanelClosingEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactPanelLaunchFullAppRequestedEventArgs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactPhone>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactPicker>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactQueryOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactQueryTextSearch>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactReader>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactSignificantOther>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactStore>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactStoreNotificationTriggerDetails>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactWebsite>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::FullContactCardOptions>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::KnownContactField>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::PinnedContactIdsQueryResult>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::PinnedContactManager>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAddressKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAnnotationOperations>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactAnnotationStoreAccessType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactBatchStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactCardHeaderKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactCardTabKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactChangeType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactDateKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactEmailKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactFieldCategory>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactFieldType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactListOtherAppReadAccess>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactListOtherAppWriteAccess>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactListSyncStatus>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactMatchReasonKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactNameOrder>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactPhoneKind>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactQueryDesiredFields>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactQuerySearchFields>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactQuerySearchScope>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactRelationship>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactSelectionMode>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::ContactStoreAccessType>{ using type = enum_category; };
    template <> struct category<llm::OS::ApplicationModel::Contacts::PinnedContactSurface>{ using type = enum_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::AggregateContactManager> = L"Windows.ApplicationModel.Contacts.AggregateContactManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::Contact> = L"Windows.ApplicationModel.Contacts.Contact";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAddress> = L"Windows.ApplicationModel.Contacts.ContactAddress";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAnnotation> = L"Windows.ApplicationModel.Contacts.ContactAnnotation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAnnotationList> = L"Windows.ApplicationModel.Contacts.ContactAnnotationList";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAnnotationStore> = L"Windows.ApplicationModel.Contacts.ContactAnnotationStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactBatch> = L"Windows.ApplicationModel.Contacts.ContactBatch";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactCardDelayedDataLoader> = L"Windows.ApplicationModel.Contacts.ContactCardDelayedDataLoader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactCardOptions> = L"Windows.ApplicationModel.Contacts.ContactCardOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactChange> = L"Windows.ApplicationModel.Contacts.ContactChange";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactChangeReader> = L"Windows.ApplicationModel.Contacts.ContactChangeReader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactChangeTracker> = L"Windows.ApplicationModel.Contacts.ContactChangeTracker";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactChangedDeferral> = L"Windows.ApplicationModel.Contacts.ContactChangedDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs> = L"Windows.ApplicationModel.Contacts.ContactChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactConnectedServiceAccount> = L"Windows.ApplicationModel.Contacts.ContactConnectedServiceAccount";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactDate> = L"Windows.ApplicationModel.Contacts.ContactDate";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactEmail> = L"Windows.ApplicationModel.Contacts.ContactEmail";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactField> = L"Windows.ApplicationModel.Contacts.ContactField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactFieldFactory> = L"Windows.ApplicationModel.Contacts.ContactFieldFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactGroup> = L"Windows.ApplicationModel.Contacts.ContactGroup";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactInformation> = L"Windows.ApplicationModel.Contacts.ContactInformation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactInstantMessageField> = L"Windows.ApplicationModel.Contacts.ContactInstantMessageField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactJobInfo> = L"Windows.ApplicationModel.Contacts.ContactJobInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactLaunchActionVerbs> = L"Windows.ApplicationModel.Contacts.ContactLaunchActionVerbs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactList> = L"Windows.ApplicationModel.Contacts.ContactList";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactListLimitedWriteOperations> = L"Windows.ApplicationModel.Contacts.ContactListLimitedWriteOperations";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactListSyncConstraints> = L"Windows.ApplicationModel.Contacts.ContactListSyncConstraints";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactListSyncManager> = L"Windows.ApplicationModel.Contacts.ContactListSyncManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactLocationField> = L"Windows.ApplicationModel.Contacts.ContactLocationField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactManager> = L"Windows.ApplicationModel.Contacts.ContactManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactManagerForUser> = L"Windows.ApplicationModel.Contacts.ContactManagerForUser";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactMatchReason> = L"Windows.ApplicationModel.Contacts.ContactMatchReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactPanel> = L"Windows.ApplicationModel.Contacts.ContactPanel";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactPanelClosingEventArgs> = L"Windows.ApplicationModel.Contacts.ContactPanelClosingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactPanelLaunchFullAppRequestedEventArgs> = L"Windows.ApplicationModel.Contacts.ContactPanelLaunchFullAppRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactPhone> = L"Windows.ApplicationModel.Contacts.ContactPhone";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactPicker> = L"Windows.ApplicationModel.Contacts.ContactPicker";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactQueryOptions> = L"Windows.ApplicationModel.Contacts.ContactQueryOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactQueryTextSearch> = L"Windows.ApplicationModel.Contacts.ContactQueryTextSearch";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactReader> = L"Windows.ApplicationModel.Contacts.ContactReader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactSignificantOther> = L"Windows.ApplicationModel.Contacts.ContactSignificantOther";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactStore> = L"Windows.ApplicationModel.Contacts.ContactStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactStoreNotificationTriggerDetails> = L"Windows.ApplicationModel.Contacts.ContactStoreNotificationTriggerDetails";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactWebsite> = L"Windows.ApplicationModel.Contacts.ContactWebsite";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::FullContactCardOptions> = L"Windows.ApplicationModel.Contacts.FullContactCardOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::KnownContactField> = L"Windows.ApplicationModel.Contacts.KnownContactField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::PinnedContactIdsQueryResult> = L"Windows.ApplicationModel.Contacts.PinnedContactIdsQueryResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::PinnedContactManager> = L"Windows.ApplicationModel.Contacts.PinnedContactManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAddressKind> = L"Windows.ApplicationModel.Contacts.ContactAddressKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAnnotationOperations> = L"Windows.ApplicationModel.Contacts.ContactAnnotationOperations";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactAnnotationStoreAccessType> = L"Windows.ApplicationModel.Contacts.ContactAnnotationStoreAccessType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactBatchStatus> = L"Windows.ApplicationModel.Contacts.ContactBatchStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactCardHeaderKind> = L"Windows.ApplicationModel.Contacts.ContactCardHeaderKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactCardTabKind> = L"Windows.ApplicationModel.Contacts.ContactCardTabKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactChangeType> = L"Windows.ApplicationModel.Contacts.ContactChangeType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactDateKind> = L"Windows.ApplicationModel.Contacts.ContactDateKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactEmailKind> = L"Windows.ApplicationModel.Contacts.ContactEmailKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactFieldCategory> = L"Windows.ApplicationModel.Contacts.ContactFieldCategory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactFieldType> = L"Windows.ApplicationModel.Contacts.ContactFieldType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactListOtherAppReadAccess> = L"Windows.ApplicationModel.Contacts.ContactListOtherAppReadAccess";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactListOtherAppWriteAccess> = L"Windows.ApplicationModel.Contacts.ContactListOtherAppWriteAccess";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactListSyncStatus> = L"Windows.ApplicationModel.Contacts.ContactListSyncStatus";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactMatchReasonKind> = L"Windows.ApplicationModel.Contacts.ContactMatchReasonKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactNameOrder> = L"Windows.ApplicationModel.Contacts.ContactNameOrder";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactPhoneKind> = L"Windows.ApplicationModel.Contacts.ContactPhoneKind";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactQueryDesiredFields> = L"Windows.ApplicationModel.Contacts.ContactQueryDesiredFields";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactQuerySearchFields> = L"Windows.ApplicationModel.Contacts.ContactQuerySearchFields";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactQuerySearchScope> = L"Windows.ApplicationModel.Contacts.ContactQuerySearchScope";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactRelationship> = L"Windows.ApplicationModel.Contacts.ContactRelationship";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactSelectionMode> = L"Windows.ApplicationModel.Contacts.ContactSelectionMode";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::ContactStoreAccessType> = L"Windows.ApplicationModel.Contacts.ContactStoreAccessType";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::PinnedContactSurface> = L"Windows.ApplicationModel.Contacts.PinnedContactSurface";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IAggregateContactManager> = L"Windows.ApplicationModel.Contacts.IAggregateContactManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IAggregateContactManager2> = L"Windows.ApplicationModel.Contacts.IAggregateContactManager2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContact> = L"Windows.ApplicationModel.Contacts.IContact";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContact2> = L"Windows.ApplicationModel.Contacts.IContact2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContact3> = L"Windows.ApplicationModel.Contacts.IContact3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactAddress> = L"Windows.ApplicationModel.Contacts.IContactAddress";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactAnnotation> = L"Windows.ApplicationModel.Contacts.IContactAnnotation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactAnnotation2> = L"Windows.ApplicationModel.Contacts.IContactAnnotation2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactAnnotationList> = L"Windows.ApplicationModel.Contacts.IContactAnnotationList";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore> = L"Windows.ApplicationModel.Contacts.IContactAnnotationStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore2> = L"Windows.ApplicationModel.Contacts.IContactAnnotationStore2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactBatch> = L"Windows.ApplicationModel.Contacts.IContactBatch";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader> = L"Windows.ApplicationModel.Contacts.IContactCardDelayedDataLoader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactCardOptions> = L"Windows.ApplicationModel.Contacts.IContactCardOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactCardOptions2> = L"Windows.ApplicationModel.Contacts.IContactCardOptions2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactChange> = L"Windows.ApplicationModel.Contacts.IContactChange";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactChangeReader> = L"Windows.ApplicationModel.Contacts.IContactChangeReader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactChangeTracker> = L"Windows.ApplicationModel.Contacts.IContactChangeTracker";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactChangeTracker2> = L"Windows.ApplicationModel.Contacts.IContactChangeTracker2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactChangedDeferral> = L"Windows.ApplicationModel.Contacts.IContactChangedDeferral";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs> = L"Windows.ApplicationModel.Contacts.IContactChangedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount> = L"Windows.ApplicationModel.Contacts.IContactConnectedServiceAccount";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactDate> = L"Windows.ApplicationModel.Contacts.IContactDate";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactEmail> = L"Windows.ApplicationModel.Contacts.IContactEmail";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactField> = L"Windows.ApplicationModel.Contacts.IContactField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactFieldFactory> = L"Windows.ApplicationModel.Contacts.IContactFieldFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactGroup> = L"Windows.ApplicationModel.Contacts.IContactGroup";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactInformation> = L"Windows.ApplicationModel.Contacts.IContactInformation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactInstantMessageField> = L"Windows.ApplicationModel.Contacts.IContactInstantMessageField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactInstantMessageFieldFactory> = L"Windows.ApplicationModel.Contacts.IContactInstantMessageFieldFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactJobInfo> = L"Windows.ApplicationModel.Contacts.IContactJobInfo";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics> = L"Windows.ApplicationModel.Contacts.IContactLaunchActionVerbsStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactList> = L"Windows.ApplicationModel.Contacts.IContactList";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactList2> = L"Windows.ApplicationModel.Contacts.IContactList2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactList3> = L"Windows.ApplicationModel.Contacts.IContactList3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations> = L"Windows.ApplicationModel.Contacts.IContactListLimitedWriteOperations";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints> = L"Windows.ApplicationModel.Contacts.IContactListSyncConstraints";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactListSyncManager> = L"Windows.ApplicationModel.Contacts.IContactListSyncManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactListSyncManager2> = L"Windows.ApplicationModel.Contacts.IContactListSyncManager2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactLocationField> = L"Windows.ApplicationModel.Contacts.IContactLocationField";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactLocationFieldFactory> = L"Windows.ApplicationModel.Contacts.IContactLocationFieldFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerForUser> = L"Windows.ApplicationModel.Contacts.IContactManagerForUser";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerForUser2> = L"Windows.ApplicationModel.Contacts.IContactManagerForUser2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics> = L"Windows.ApplicationModel.Contacts.IContactManagerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics2> = L"Windows.ApplicationModel.Contacts.IContactManagerStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics3> = L"Windows.ApplicationModel.Contacts.IContactManagerStatics3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics4> = L"Windows.ApplicationModel.Contacts.IContactManagerStatics4";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics5> = L"Windows.ApplicationModel.Contacts.IContactManagerStatics5";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactMatchReason> = L"Windows.ApplicationModel.Contacts.IContactMatchReason";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactName> = L"Windows.ApplicationModel.Contacts.IContactName";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPanel> = L"Windows.ApplicationModel.Contacts.IContactPanel";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs> = L"Windows.ApplicationModel.Contacts.IContactPanelClosingEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs> = L"Windows.ApplicationModel.Contacts.IContactPanelLaunchFullAppRequestedEventArgs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPhone> = L"Windows.ApplicationModel.Contacts.IContactPhone";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPicker> = L"Windows.ApplicationModel.Contacts.IContactPicker";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPicker2> = L"Windows.ApplicationModel.Contacts.IContactPicker2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPicker3> = L"Windows.ApplicationModel.Contacts.IContactPicker3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactPickerStatics> = L"Windows.ApplicationModel.Contacts.IContactPickerStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactQueryOptions> = L"Windows.ApplicationModel.Contacts.IContactQueryOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactQueryOptionsFactory> = L"Windows.ApplicationModel.Contacts.IContactQueryOptionsFactory";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch> = L"Windows.ApplicationModel.Contacts.IContactQueryTextSearch";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactReader> = L"Windows.ApplicationModel.Contacts.IContactReader";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactSignificantOther> = L"Windows.ApplicationModel.Contacts.IContactSignificantOther";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactSignificantOther2> = L"Windows.ApplicationModel.Contacts.IContactSignificantOther2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactStore> = L"Windows.ApplicationModel.Contacts.IContactStore";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactStore2> = L"Windows.ApplicationModel.Contacts.IContactStore2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactStore3> = L"Windows.ApplicationModel.Contacts.IContactStore3";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails> = L"Windows.ApplicationModel.Contacts.IContactStoreNotificationTriggerDetails";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactWebsite> = L"Windows.ApplicationModel.Contacts.IContactWebsite";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IContactWebsite2> = L"Windows.ApplicationModel.Contacts.IContactWebsite2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IFullContactCardOptions> = L"Windows.ApplicationModel.Contacts.IFullContactCardOptions";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IKnownContactFieldStatics> = L"Windows.ApplicationModel.Contacts.IKnownContactFieldStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult> = L"Windows.ApplicationModel.Contacts.IPinnedContactIdsQueryResult";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IPinnedContactManager> = L"Windows.ApplicationModel.Contacts.IPinnedContactManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Contacts::IPinnedContactManagerStatics> = L"Windows.ApplicationModel.Contacts.IPinnedContactManagerStatics";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IAggregateContactManager>{ 0x0379D5DD,0xDB5A,0x4FD3,{ 0xB5,0x4E,0x4D,0xF1,0x79,0x17,0xA2,0x12 } }; // 0379D5DD-DB5A-4FD3-B54E-4DF17917A212
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IAggregateContactManager2>{ 0x5E8CC2D8,0xA9CD,0x4430,{ 0x9C,0x4B,0x01,0x34,0x8D,0xB2,0xCA,0x50 } }; // 5E8CC2D8-A9CD-4430-9C4B-01348DB2CA50
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContact>{ 0xEC0072F3,0x2118,0x4049,{ 0x9E,0xBC,0x17,0xF0,0xAB,0x69,0x2B,0x64 } }; // EC0072F3-2118-4049-9EBC-17F0AB692B64
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContact2>{ 0xF312F365,0xBB77,0x4C94,{ 0x80,0x2D,0x83,0x28,0xCE,0xE4,0x0C,0x08 } }; // F312F365-BB77-4C94-802D-8328CEE40C08
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContact3>{ 0x48201E67,0xE08E,0x42A4,{ 0xB5,0x61,0x41,0xD0,0x8C,0xA9,0x57,0x5D } }; // 48201E67-E08E-42A4-B561-41D08CA9575D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactAddress>{ 0x9739D39A,0x42CE,0x4872,{ 0x8D,0x70,0x30,0x63,0xAA,0x58,0x4B,0x70 } }; // 9739D39A-42CE-4872-8D70-3063AA584B70
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactAnnotation>{ 0x821FC2EF,0x7D41,0x44A2,{ 0x84,0xC3,0x60,0xA2,0x81,0xDD,0x7B,0x86 } }; // 821FC2EF-7D41-44A2-84C3-60A281DD7B86
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactAnnotation2>{ 0xB691ECF3,0x4AB7,0x4A1F,{ 0x99,0x41,0x0C,0x9C,0xF3,0x17,0x1B,0x75 } }; // B691ECF3-4AB7-4A1F-9941-0C9CF3171B75
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactAnnotationList>{ 0x92A486AA,0x5C88,0x45B9,{ 0xAA,0xD0,0x46,0x18,0x88,0xE6,0x8D,0x8A } }; // 92A486AA-5C88-45B9-AAD0-461888E68D8A
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore>{ 0x23ACF4AA,0x7A77,0x457D,{ 0x82,0x03,0x98,0x7F,0x4B,0x31,0xAF,0x09 } }; // 23ACF4AA-7A77-457D-8203-987F4B31AF09
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore2>{ 0x7EDE23FD,0x61E7,0x4967,{ 0x8E,0xC5,0xBD,0xF2,0x80,0xA2,0x40,0x63 } }; // 7EDE23FD-61E7-4967-8EC5-BDF280A24063
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactBatch>{ 0x35D1972D,0xBFCE,0x46BB,{ 0x93,0xF8,0xA5,0xB0,0x6E,0xC5,0xE2,0x01 } }; // 35D1972D-BFCE-46BB-93F8-A5B06EC5E201
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader>{ 0xB60AF902,0x1546,0x434D,{ 0x86,0x9C,0x6E,0x35,0x20,0x76,0x0E,0xF3 } }; // B60AF902-1546-434D-869C-6E3520760EF3
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactCardOptions>{ 0x8C0A4F7E,0x6AB6,0x4F3F,{ 0xBE,0x72,0x81,0x72,0x36,0xEE,0xEA,0x5B } }; // 8C0A4F7E-6AB6-4F3F-BE72-817236EEEA5B
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactCardOptions2>{ 0x8F271BA0,0xD74B,0x4CC6,{ 0x9F,0x53,0x1B,0x0E,0xB5,0xD1,0x27,0x3C } }; // 8F271BA0-D74B-4CC6-9F53-1B0EB5D1273C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactChange>{ 0x951D4B10,0x6A59,0x4720,{ 0xA4,0xE1,0x36,0x3D,0x98,0xC1,0x35,0xD5 } }; // 951D4B10-6A59-4720-A4E1-363D98C135D5
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactChangeReader>{ 0x217319FA,0x2D0C,0x42E0,{ 0xA9,0xDA,0x3E,0xCD,0x56,0xA7,0x8A,0x47 } }; // 217319FA-2D0C-42E0-A9DA-3ECD56A78A47
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactChangeTracker>{ 0x6E992952,0x309B,0x404D,{ 0x97,0x12,0xB3,0x7B,0xD3,0x02,0x78,0xAA } }; // 6E992952-309B-404D-9712-B37BD30278AA
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactChangeTracker2>{ 0x7F8AD0FC,0x9321,0x4D18,{ 0x9C,0x09,0xD7,0x08,0xC6,0x3F,0xCD,0x31 } }; // 7F8AD0FC-9321-4D18-9C09-D708C63FCD31
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactChangedDeferral>{ 0xC5143AE8,0x1B03,0x46F8,{ 0xB6,0x94,0xA5,0x23,0xE8,0x3C,0xFC,0xB6 } }; // C5143AE8-1B03-46F8-B694-A523E83CFCB6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs>{ 0x525E7FD1,0x73F3,0x4B7D,{ 0xA9,0x18,0x58,0x0B,0xE4,0x36,0x61,0x21 } }; // 525E7FD1-73F3-4B7D-A918-580BE4366121
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount>{ 0xF6F83553,0xAA27,0x4731,{ 0x8E,0x4A,0x3D,0xEC,0x5C,0xE9,0xEE,0xC9 } }; // F6F83553-AA27-4731-8E4A-3DEC5CE9EEC9
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactDate>{ 0xFE98AE66,0xB205,0x4934,{ 0x91,0x74,0x0F,0xF2,0xB0,0x56,0x57,0x07 } }; // FE98AE66-B205-4934-9174-0FF2B0565707
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactEmail>{ 0x90A219A9,0xE3D3,0x4D63,{ 0x99,0x3B,0x05,0xB9,0xA5,0x39,0x3A,0xBF } }; // 90A219A9-E3D3-4D63-993B-05B9A5393ABF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactField>{ 0xB176486A,0xD293,0x492C,{ 0xA0,0x58,0xDB,0x57,0x5B,0x3E,0x3C,0x0F } }; // B176486A-D293-492C-A058-DB575B3E3C0F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactFieldFactory>{ 0x85E2913F,0x0E4A,0x4A3E,{ 0x89,0x94,0x40,0x6A,0xE7,0xED,0x64,0x6E } }; // 85E2913F-0E4A-4A3E-8994-406AE7ED646E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactGroup>{ 0x59BDEB01,0x9E9A,0x475D,{ 0xBF,0xE5,0xA3,0x7B,0x80,0x6D,0x85,0x2C } }; // 59BDEB01-9E9A-475D-BFE5-A37B806D852C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactInformation>{ 0x275EB6D4,0x6A2E,0x4278,{ 0xA9,0x14,0xE4,0x60,0xD5,0xF0,0x88,0xF6 } }; // 275EB6D4-6A2E-4278-A914-E460D5F088F6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactInstantMessageField>{ 0xCCE33B37,0x0D85,0x41FA,{ 0xB4,0x3D,0xDA,0x59,0x9C,0x3E,0xB0,0x09 } }; // CCE33B37-0D85-41FA-B43D-DA599C3EB009
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>{ 0xBA0B6794,0x91A3,0x4BB2,{ 0xB1,0xB9,0x69,0xA5,0xDF,0xF0,0xBA,0x09 } }; // BA0B6794-91A3-4BB2-B1B9-69A5DFF0BA09
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactJobInfo>{ 0x6D117B4C,0xCE50,0x4B43,{ 0x9E,0x69,0xB1,0x82,0x58,0xEA,0x53,0x15 } }; // 6D117B4C-CE50-4B43-9E69-B18258EA5315
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics>{ 0xFB1232D6,0xEE73,0x46E7,{ 0x87,0x61,0x11,0xCD,0x01,0x57,0x72,0x8F } }; // FB1232D6-EE73-46E7-8761-11CD0157728F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactList>{ 0x16DDEC75,0x392C,0x4845,{ 0x9D,0xFB,0x51,0xA3,0xE7,0xEF,0x3E,0x42 } }; // 16DDEC75-392C-4845-9DFB-51A3E7EF3E42
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactList2>{ 0xCB3943B4,0x4550,0x4DCB,{ 0x92,0x29,0x40,0xFF,0x91,0xFB,0x02,0x03 } }; // CB3943B4-4550-4DCB-9229-40FF91FB0203
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactList3>{ 0x1578EE57,0x26FC,0x41E8,{ 0xA8,0x50,0x5A,0xA3,0x25,0x14,0xAC,0xA9 } }; // 1578EE57-26FC-41E8-A850-5AA32514ACA9
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations>{ 0xE19813DA,0x4A0B,0x44B8,{ 0x9A,0x1F,0xA0,0xF3,0xD2,0x18,0x17,0x5F } }; // E19813DA-4A0B-44B8-9A1F-A0F3D218175F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints>{ 0xB2B0BF01,0x3062,0x4E2E,{ 0x96,0x9D,0x01,0x8D,0x19,0x87,0xF3,0x14 } }; // B2B0BF01-3062-4E2E-969D-018D1987F314
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactListSyncManager>{ 0x146E83BE,0x7925,0x4ACC,{ 0x9D,0xE5,0x21,0xDD,0xD0,0x6F,0x86,0x74 } }; // 146E83BE-7925-4ACC-9DE5-21DDD06F8674
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>{ 0xA9591247,0xBB55,0x4E23,{ 0x81,0x28,0x37,0x01,0x34,0xA8,0x5D,0x0D } }; // A9591247-BB55-4E23-8128-370134A85D0D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactLocationField>{ 0x9EC00F82,0xAB6E,0x4B36,{ 0x89,0xE3,0xB2,0x3B,0xC0,0xA1,0xDA,0xCC } }; // 9EC00F82-AB6E-4B36-89E3-B23BC0A1DACC
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactLocationFieldFactory>{ 0xF79932D7,0x2FDF,0x43FE,{ 0x8F,0x18,0x41,0x89,0x73,0x90,0xBC,0xFE } }; // F79932D7-2FDF-43FE-8F18-41897390BCFE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerForUser>{ 0xB74BBA57,0x1076,0x4BEF,{ 0xAE,0xF3,0x54,0x68,0x6D,0x18,0x38,0x7D } }; // B74BBA57-1076-4BEF-AEF3-54686D18387D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerForUser2>{ 0x4D469C2E,0x3B75,0x4A73,{ 0xBB,0x30,0x73,0x66,0x45,0x47,0x22,0x56 } }; // 4D469C2E-3B75-4A73-BB30-736645472256
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics>{ 0x81F21AC0,0xF661,0x4708,{ 0xBA,0x4F,0xD3,0x86,0xBD,0x0D,0x62,0x2E } }; // 81F21AC0-F661-4708-BA4F-D386BD0D622E
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics2>{ 0xA178E620,0x47D8,0x48CC,{ 0x96,0x3C,0x95,0x92,0xB6,0xE5,0x10,0xC6 } }; // A178E620-47D8-48CC-963C-9592B6E510C6
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics3>{ 0xC4CC3D42,0x7586,0x492A,{ 0x93,0x0B,0x7B,0xC1,0x38,0xFC,0x21,0x39 } }; // C4CC3D42-7586-492A-930B-7BC138FC2139
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics4>{ 0x24982272,0x347B,0x46DC,{ 0x8D,0x95,0x51,0xBD,0x41,0xE1,0x5A,0xAF } }; // 24982272-347B-46DC-8D95-51BD41E15AAF
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactManagerStatics5>{ 0xF7591A87,0xACB7,0x4FAD,{ 0x90,0xF2,0xA8,0xAB,0x64,0xCD,0xBB,0xA4 } }; // F7591A87-ACB7-4FAD-90F2-A8AB64CDBBA4
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactMatchReason>{ 0xBC922504,0xE7D8,0x413E,{ 0x95,0xF4,0xB7,0x5C,0x54,0xC7,0x40,0x77 } }; // BC922504-E7D8-413E-95F4-B75C54C74077
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactName>{ 0xF404E97B,0x9034,0x453C,{ 0x8E,0xBF,0x14,0x0A,0x38,0xC8,0x6F,0x1D } }; // F404E97B-9034-453C-8EBF-140A38C86F1D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPanel>{ 0x41BF1265,0xD2EE,0x4B97,{ 0xA8,0x0A,0x7D,0x8D,0x64,0xCC,0xA6,0xF5 } }; // 41BF1265-D2EE-4B97-A80A-7D8D64CCA6F5
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs>{ 0x222174D3,0xCF4B,0x46D7,{ 0xB7,0x39,0x6E,0xDC,0x16,0x11,0x0B,0xFB } }; // 222174D3-CF4B-46D7-B739-6EDC16110BFB
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs>{ 0x88D61C0E,0x23B4,0x4BE8,{ 0x8A,0xFC,0x07,0x2C,0x25,0xA4,0x19,0x0D } }; // 88D61C0E-23B4-4BE8-8AFC-072C25A4190D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPhone>{ 0x467DAB65,0x2712,0x4F52,{ 0xB7,0x83,0x9E,0xA8,0x11,0x1C,0x63,0xCD } }; // 467DAB65-2712-4F52-B783-9EA8111C63CD
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPicker>{ 0x0E09FD91,0x42F8,0x4055,{ 0x90,0xA0,0x89,0x6F,0x96,0x73,0x89,0x36 } }; // 0E09FD91-42F8-4055-90A0-896F96738936
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPicker2>{ 0xB35011CF,0x5CEF,0x4D24,{ 0xAA,0x0C,0x34,0x0C,0x52,0x08,0x72,0x5D } }; // B35011CF-5CEF-4D24-AA0C-340C5208725D
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPicker3>{ 0x0E723315,0xB243,0x4BED,{ 0x85,0x16,0x22,0xB1,0xA7,0xAC,0x0A,0xCE } }; // 0E723315-B243-4BED-8516-22B1A7AC0ACE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactPickerStatics>{ 0x7488C029,0x6A53,0x4258,{ 0xA3,0xE9,0x62,0xDF,0xF6,0x78,0x4B,0x6C } }; // 7488C029-6A53-4258-A3E9-62DFF6784B6C
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactQueryOptions>{ 0x4408CC9E,0x7D7C,0x42F0,{ 0x8A,0xC7,0xF5,0x07,0x33,0xEC,0xDB,0xC1 } }; // 4408CC9E-7D7C-42F0-8AC7-F50733ECDBC1
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactQueryOptionsFactory>{ 0x543FBA47,0x8CE7,0x46CB,{ 0x9D,0xAC,0x9A,0xA4,0x2A,0x1B,0xC8,0xE2 } }; // 543FBA47-8CE7-46CB-9DAC-9AA42A1BC8E2
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch>{ 0xF7E3F9CB,0xA957,0x439B,{ 0xA0,0xB7,0x1C,0x02,0xA1,0x96,0x3F,0xF0 } }; // F7E3F9CB-A957-439B-A0B7-1C02A1963FF0
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactReader>{ 0xD397E42E,0x1488,0x42F2,{ 0xBF,0x64,0x25,0x3F,0x48,0x84,0xBF,0xED } }; // D397E42E-1488-42F2-BF64-253F4884BFED
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactSignificantOther>{ 0x8873B5AB,0xC5FB,0x46D8,{ 0x93,0xFE,0xDA,0x3F,0xF1,0x93,0x40,0x54 } }; // 8873B5AB-C5FB-46D8-93FE-DA3FF1934054
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactSignificantOther2>{ 0x8D7BD474,0x3F03,0x45F8,{ 0xBA,0x0F,0xC4,0xED,0x37,0xD6,0x42,0x19 } }; // 8D7BD474-3F03-45F8-BA0F-C4ED37D64219
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactStore>{ 0x2C220B10,0x3A6C,0x4293,{ 0xB9,0xBC,0xFE,0x98,0x7F,0x6E,0x0D,0x52 } }; // 2C220B10-3A6C-4293-B9BC-FE987F6E0D52
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactStore2>{ 0x18CE1C22,0xEBD5,0x4BFB,{ 0xB6,0x90,0x5F,0x4F,0x27,0xC4,0xF0,0xE8 } }; // 18CE1C22-EBD5-4BFB-B690-5F4F27C4F0E8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactStore3>{ 0xCB882C6C,0x004E,0x4050,{ 0x87,0xF0,0x84,0x04,0x07,0xEE,0x68,0x18 } }; // CB882C6C-004E-4050-87F0-840407EE6818
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails>{ 0xABB298D6,0x878A,0x4F8B,{ 0xA9,0xCE,0x46,0xBB,0x7D,0x1C,0x84,0xCE } }; // ABB298D6-878A-4F8B-A9CE-46BB7D1C84CE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactWebsite>{ 0x9F130176,0xDC1B,0x4055,{ 0xAD,0x66,0x65,0x2F,0x39,0xD9,0x90,0xE8 } }; // 9F130176-DC1B-4055-AD66-652F39D990E8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IContactWebsite2>{ 0xF87EE91E,0x5647,0x4068,{ 0xBB,0x5E,0x4B,0x6F,0x43,0x7C,0xE3,0x08 } }; // F87EE91E-5647-4068-BB5E-4B6F437CE308
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IFullContactCardOptions>{ 0x8744436C,0x5CF9,0x4683,{ 0xBD,0xCA,0xA1,0xFD,0xEB,0xF8,0xDB,0xCE } }; // 8744436C-5CF9-4683-BDCA-A1FDEBF8DBCE
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IKnownContactFieldStatics>{ 0x2E0E1B12,0xD627,0x4FCA,{ 0xBA,0xD4,0x1F,0xAF,0x16,0x8C,0x7D,0x14 } }; // 2E0E1B12-D627-4FCA-BAD4-1FAF168C7D14
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult>{ 0x7D9B2552,0x1579,0x4DDC,{ 0x87,0x1F,0xA3,0x0A,0x3A,0xEA,0x9B,0xA1 } }; // 7D9B2552-1579-4DDC-871F-A30A3AEA9BA1
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IPinnedContactManager>{ 0xFCBC740C,0xE1D6,0x45C3,{ 0xB8,0xB6,0xA3,0x56,0x04,0xE1,0x67,0xA0 } }; // FCBC740C-E1D6-45C3-B8B6-A35604E167A0
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Contacts::IPinnedContactManagerStatics>{ 0xF65CCC7E,0xFDF9,0x486A,{ 0xAC,0xE9,0xBC,0x31,0x1D,0x0A,0xE7,0xF0 } }; // F65CCC7E-FDF9-486A-ACE9-BC311D0AE7F0
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::AggregateContactManager>{ using type = llm::OS::ApplicationModel::Contacts::IAggregateContactManager; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::Contact>{ using type = llm::OS::ApplicationModel::Contacts::IContact; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactAddress>{ using type = llm::OS::ApplicationModel::Contacts::IContactAddress; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactAnnotation>{ using type = llm::OS::ApplicationModel::Contacts::IContactAnnotation; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>{ using type = llm::OS::ApplicationModel::Contacts::IContactAnnotationList; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactAnnotationStore>{ using type = llm::OS::ApplicationModel::Contacts::IContactAnnotationStore; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactBatch>{ using type = llm::OS::ApplicationModel::Contacts::IContactBatch; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactCardDelayedDataLoader>{ using type = llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactCardOptions>{ using type = llm::OS::ApplicationModel::Contacts::IContactCardOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactChange>{ using type = llm::OS::ApplicationModel::Contacts::IContactChange; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactChangeReader>{ using type = llm::OS::ApplicationModel::Contacts::IContactChangeReader; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactChangeTracker>{ using type = llm::OS::ApplicationModel::Contacts::IContactChangeTracker; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactChangedDeferral>{ using type = llm::OS::ApplicationModel::Contacts::IContactChangedDeferral; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs>{ using type = llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactConnectedServiceAccount>{ using type = llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactDate>{ using type = llm::OS::ApplicationModel::Contacts::IContactDate; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactEmail>{ using type = llm::OS::ApplicationModel::Contacts::IContactEmail; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactField>{ using type = llm::OS::ApplicationModel::Contacts::IContactField; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactFieldFactory>{ using type = llm::OS::ApplicationModel::Contacts::IContactFieldFactory; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactGroup>{ using type = llm::OS::ApplicationModel::Contacts::IContactGroup; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactInformation>{ using type = llm::OS::ApplicationModel::Contacts::IContactInformation; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactInstantMessageField>{ using type = llm::OS::ApplicationModel::Contacts::IContactInstantMessageField; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactJobInfo>{ using type = llm::OS::ApplicationModel::Contacts::IContactJobInfo; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactList>{ using type = llm::OS::ApplicationModel::Contacts::IContactList; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactListLimitedWriteOperations>{ using type = llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactListSyncConstraints>{ using type = llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactListSyncManager>{ using type = llm::OS::ApplicationModel::Contacts::IContactListSyncManager; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactLocationField>{ using type = llm::OS::ApplicationModel::Contacts::IContactLocationField; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactManagerForUser>{ using type = llm::OS::ApplicationModel::Contacts::IContactManagerForUser; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactMatchReason>{ using type = llm::OS::ApplicationModel::Contacts::IContactMatchReason; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactPanel>{ using type = llm::OS::ApplicationModel::Contacts::IContactPanel; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactPanelClosingEventArgs>{ using type = llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactPanelLaunchFullAppRequestedEventArgs>{ using type = llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactPhone>{ using type = llm::OS::ApplicationModel::Contacts::IContactPhone; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactPicker>{ using type = llm::OS::ApplicationModel::Contacts::IContactPicker; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactQueryOptions>{ using type = llm::OS::ApplicationModel::Contacts::IContactQueryOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactQueryTextSearch>{ using type = llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactReader>{ using type = llm::OS::ApplicationModel::Contacts::IContactReader; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactSignificantOther>{ using type = llm::OS::ApplicationModel::Contacts::IContactSignificantOther; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactStore>{ using type = llm::OS::ApplicationModel::Contacts::IContactStore; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactStoreNotificationTriggerDetails>{ using type = llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::ContactWebsite>{ using type = llm::OS::ApplicationModel::Contacts::IContactWebsite; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::FullContactCardOptions>{ using type = llm::OS::ApplicationModel::Contacts::IFullContactCardOptions; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::PinnedContactIdsQueryResult>{ using type = llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult; };
    template <> struct default_interface<llm::OS::ApplicationModel::Contacts::PinnedContactManager>{ using type = llm::OS::ApplicationModel::Contacts::IPinnedContactManager; };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IAggregateContactManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindRawContactsAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryLinkContactsAsync(void*, void*, void**) noexcept = 0;
            virtual int32_t __stdcall UnlinkRawContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TrySetPreferredSourceForPictureAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IAggregateContactManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetRemoteIdentificationInformationAsync(void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContact>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_Thumbnail(void**) noexcept = 0;
            virtual int32_t __stdcall put_Thumbnail(void*) noexcept = 0;
            virtual int32_t __stdcall get_Fields(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContact2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall put_Id(void*) noexcept = 0;
            virtual int32_t __stdcall get_Notes(void**) noexcept = 0;
            virtual int32_t __stdcall put_Notes(void*) noexcept = 0;
            virtual int32_t __stdcall get_Phones(void**) noexcept = 0;
            virtual int32_t __stdcall get_Emails(void**) noexcept = 0;
            virtual int32_t __stdcall get_Addresses(void**) noexcept = 0;
            virtual int32_t __stdcall get_ConnectedServiceAccounts(void**) noexcept = 0;
            virtual int32_t __stdcall get_ImportantDates(void**) noexcept = 0;
            virtual int32_t __stdcall get_DataSuppliers(void**) noexcept = 0;
            virtual int32_t __stdcall get_JobInfo(void**) noexcept = 0;
            virtual int32_t __stdcall get_SignificantOthers(void**) noexcept = 0;
            virtual int32_t __stdcall get_Websites(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProviderProperties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContact3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContactListId(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayPictureUserUpdateTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall put_DisplayPictureUserUpdateTime(int64_t) noexcept = 0;
            virtual int32_t __stdcall get_IsMe(bool*) noexcept = 0;
            virtual int32_t __stdcall get_AggregateId(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall put_RemoteId(void*) noexcept = 0;
            virtual int32_t __stdcall get_RingToneToken(void**) noexcept = 0;
            virtual int32_t __stdcall put_RingToneToken(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsDisplayPictureManuallySet(bool*) noexcept = 0;
            virtual int32_t __stdcall get_LargeDisplayPicture(void**) noexcept = 0;
            virtual int32_t __stdcall get_SmallDisplayPicture(void**) noexcept = 0;
            virtual int32_t __stdcall get_SourceDisplayPicture(void**) noexcept = 0;
            virtual int32_t __stdcall put_SourceDisplayPicture(void*) noexcept = 0;
            virtual int32_t __stdcall get_TextToneToken(void**) noexcept = 0;
            virtual int32_t __stdcall put_TextToneToken(void*) noexcept = 0;
            virtual int32_t __stdcall get_IsAggregate(bool*) noexcept = 0;
            virtual int32_t __stdcall get_FullName(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayNameOverride(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayNameOverride(void*) noexcept = 0;
            virtual int32_t __stdcall get_Nickname(void**) noexcept = 0;
            virtual int32_t __stdcall put_Nickname(void*) noexcept = 0;
            virtual int32_t __stdcall get_SortName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactAddress>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_StreetAddress(void**) noexcept = 0;
            virtual int32_t __stdcall put_StreetAddress(void*) noexcept = 0;
            virtual int32_t __stdcall get_Locality(void**) noexcept = 0;
            virtual int32_t __stdcall put_Locality(void*) noexcept = 0;
            virtual int32_t __stdcall get_Region(void**) noexcept = 0;
            virtual int32_t __stdcall put_Region(void*) noexcept = 0;
            virtual int32_t __stdcall get_Country(void**) noexcept = 0;
            virtual int32_t __stdcall put_Country(void*) noexcept = 0;
            virtual int32_t __stdcall get_PostalCode(void**) noexcept = 0;
            virtual int32_t __stdcall put_PostalCode(void*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Kind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactAnnotation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_AnnotationListId(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContactId(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContactId(void*) noexcept = 0;
            virtual int32_t __stdcall get_RemoteId(void**) noexcept = 0;
            virtual int32_t __stdcall put_RemoteId(void*) noexcept = 0;
            virtual int32_t __stdcall get_SupportedOperations(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SupportedOperations(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_IsDisabled(bool*) noexcept = 0;
            virtual int32_t __stdcall get_ProviderProperties(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactAnnotation2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContactListId(void**) noexcept = 0;
            virtual int32_t __stdcall put_ContactListId(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactAnnotationList>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_ProviderPackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall get_UserDataAccountId(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void**) noexcept = 0;
            virtual int32_t __stdcall TrySaveAnnotationAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAnnotationAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAnnotationsByRemoteIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAnnotationsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAnnotationAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindContactIdsByEmailAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindContactIdsByPhoneNumberAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAnnotationsForContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DisableAnnotationAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateAnnotationListAsync(void**) noexcept = 0;
            virtual int32_t __stdcall CreateAnnotationListInAccountAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetAnnotationListAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall FindAnnotationListsAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindAnnotationsForContactListAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactBatch>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Contacts(void**) noexcept = 0;
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall SetData(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactCardOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_HeaderKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_HeaderKind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_InitialTabKind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_InitialTabKind(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactCardOptions2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ServerSearchContactListIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactChange>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChangeType(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Contact(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactChangeReader>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall AcceptChanges() noexcept = 0;
            virtual int32_t __stdcall AcceptChangesThrough(void*) noexcept = 0;
            virtual int32_t __stdcall ReadBatchAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactChangeTracker>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Enable() noexcept = 0;
            virtual int32_t __stdcall GetChangeReader(void**) noexcept = 0;
            virtual int32_t __stdcall Reset() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactChangeTracker2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_IsTracking(bool*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactChangedDeferral>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall Complete() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall put_Id(void*) noexcept = 0;
            virtual int32_t __stdcall get_ServiceName(void**) noexcept = 0;
            virtual int32_t __stdcall put_ServiceName(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactDate>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Day(void**) noexcept = 0;
            virtual int32_t __stdcall put_Day(void*) noexcept = 0;
            virtual int32_t __stdcall get_Month(void**) noexcept = 0;
            virtual int32_t __stdcall put_Month(void*) noexcept = 0;
            virtual int32_t __stdcall get_Year(void**) noexcept = 0;
            virtual int32_t __stdcall put_Year(void*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Kind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactEmail>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Address(void**) noexcept = 0;
            virtual int32_t __stdcall put_Address(void*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Kind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactField>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Type(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Category(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall get_Value(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactFieldFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateField_Default(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateField_Category(void*, int32_t, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateField_Custom(void*, void*, int32_t, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactGroup>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactInformation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall GetThumbnailAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_Emails(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall get_Locations(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstantMessages(void**) noexcept = 0;
            virtual int32_t __stdcall get_CustomFields(void**) noexcept = 0;
            virtual int32_t __stdcall QueryCustomFields(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactInstantMessageField>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UserName(void**) noexcept = 0;
            virtual int32_t __stdcall get_Service(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayText(void**) noexcept = 0;
            virtual int32_t __stdcall get_LaunchUri(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateInstantMessage_Default(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInstantMessage_Category(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateInstantMessage_All(void*, int32_t, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactJobInfo>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CompanyName(void**) noexcept = 0;
            virtual int32_t __stdcall put_CompanyName(void*) noexcept = 0;
            virtual int32_t __stdcall get_CompanyYomiName(void**) noexcept = 0;
            virtual int32_t __stdcall put_CompanyYomiName(void*) noexcept = 0;
            virtual int32_t __stdcall get_Department(void**) noexcept = 0;
            virtual int32_t __stdcall put_Department(void*) noexcept = 0;
            virtual int32_t __stdcall get_Title(void**) noexcept = 0;
            virtual int32_t __stdcall put_Title(void*) noexcept = 0;
            virtual int32_t __stdcall get_Manager(void**) noexcept = 0;
            virtual int32_t __stdcall put_Manager(void*) noexcept = 0;
            virtual int32_t __stdcall get_Office(void**) noexcept = 0;
            virtual int32_t __stdcall put_Office(void*) noexcept = 0;
            virtual int32_t __stdcall get_CompanyAddress(void**) noexcept = 0;
            virtual int32_t __stdcall put_CompanyAddress(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Call(void**) noexcept = 0;
            virtual int32_t __stdcall get_Message(void**) noexcept = 0;
            virtual int32_t __stdcall get_Map(void**) noexcept = 0;
            virtual int32_t __stdcall get_Post(void**) noexcept = 0;
            virtual int32_t __stdcall get_VideoCall(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactList>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Id(void**) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall put_DisplayName(void*) noexcept = 0;
            virtual int32_t __stdcall get_SourceDisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_IsHidden(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IsHidden(bool) noexcept = 0;
            virtual int32_t __stdcall get_OtherAppReadAccess(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_OtherAppReadAccess(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_OtherAppWriteAccess(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_OtherAppWriteAccess(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_ChangeTracker(void**) noexcept = 0;
            virtual int32_t __stdcall get_SyncManager(void**) noexcept = 0;
            virtual int32_t __stdcall get_SupportsServerSearch(bool*) noexcept = 0;
            virtual int32_t __stdcall get_UserDataAccountId(void**) noexcept = 0;
            virtual int32_t __stdcall add_ContactChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContactChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall SaveAsync(void**) noexcept = 0;
            virtual int32_t __stdcall DeleteAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetContactFromRemoteIdAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetMeContactAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetContactReader(void**) noexcept = 0;
            virtual int32_t __stdcall GetContactReaderWithOptions(void*, void**) noexcept = 0;
            virtual int32_t __stdcall SaveContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetContactAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactList2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RegisterSyncManagerAsync(void**) noexcept = 0;
            virtual int32_t __stdcall put_SupportsServerSearch(bool) noexcept = 0;
            virtual int32_t __stdcall get_SyncConstraints(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactList3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_LimitedWriteOperations(void**) noexcept = 0;
            virtual int32_t __stdcall GetChangeTracker(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall TryCreateOrUpdateContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall TryDeleteContactAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CanSyncDescriptions(bool*) noexcept = 0;
            virtual int32_t __stdcall put_CanSyncDescriptions(bool) noexcept = 0;
            virtual int32_t __stdcall get_MaxHomePhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxHomePhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxMobilePhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxMobilePhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxWorkPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxWorkPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxOtherPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxOtherPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPagerPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxPagerPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxBusinessFaxPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxBusinessFaxPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxHomeFaxPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxHomeFaxPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxCompanyPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxCompanyPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxAssistantPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxAssistantPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxRadioPhoneNumbers(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxRadioPhoneNumbers(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPersonalEmailAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxPersonalEmailAddresses(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxWorkEmailAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxWorkEmailAddresses(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxOtherEmailAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxOtherEmailAddresses(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxHomeAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxHomeAddresses(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxWorkAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxWorkAddresses(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxOtherAddresses(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxOtherAddresses(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxBirthdayDates(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxBirthdayDates(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxAnniversaryDates(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxAnniversaryDates(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxOtherDates(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxOtherDates(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxOtherRelationships(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxOtherRelationships(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxSpouseRelationships(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxSpouseRelationships(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxPartnerRelationships(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxPartnerRelationships(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxSiblingRelationships(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxSiblingRelationships(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxParentRelationships(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxParentRelationships(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxChildRelationships(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxChildRelationships(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxJobInfo(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxJobInfo(void*) noexcept = 0;
            virtual int32_t __stdcall get_MaxWebsites(void**) noexcept = 0;
            virtual int32_t __stdcall put_MaxWebsites(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactListSyncManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Status(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_LastSuccessfulSyncTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall get_LastAttemptedSyncTime(int64_t*) noexcept = 0;
            virtual int32_t __stdcall SyncAsync(void**) noexcept = 0;
            virtual int32_t __stdcall add_SyncStatusChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_SyncStatusChanged(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall put_Status(int32_t) noexcept = 0;
            virtual int32_t __stdcall put_LastSuccessfulSyncTime(int64_t) noexcept = 0;
            virtual int32_t __stdcall put_LastAttemptedSyncTime(int64_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactLocationField>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_UnstructuredAddress(void**) noexcept = 0;
            virtual int32_t __stdcall get_Street(void**) noexcept = 0;
            virtual int32_t __stdcall get_City(void**) noexcept = 0;
            virtual int32_t __stdcall get_Region(void**) noexcept = 0;
            virtual int32_t __stdcall get_Country(void**) noexcept = 0;
            virtual int32_t __stdcall get_PostalCode(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactLocationFieldFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateLocation_Default(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateLocation_Category(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall CreateLocation_All(void*, int32_t, void*, void*, void*, void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerForUser>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ConvertContactToVCardAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ConvertContactToVCardAsyncWithMaxBytes(void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ConvertVCardToContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestStoreAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestAnnotationStoreAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall get_SystemDisplayNameOrder(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SystemDisplayNameOrder(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SystemSortOrder(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SystemSortOrder(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerForUser2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ShowFullContactCard(void*, void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ShowContactCard(void*, llm::OS::Foundation::Rect) noexcept = 0;
            virtual int32_t __stdcall ShowContactCardWithPlacement(void*, llm::OS::Foundation::Rect, int32_t) noexcept = 0;
            virtual int32_t __stdcall ShowDelayLoadedContactCard(void*, llm::OS::Foundation::Rect, int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall RequestStoreAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerStatics3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ConvertContactToVCardAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall ConvertContactToVCardAsyncWithMaxBytes(void*, uint32_t, void**) noexcept = 0;
            virtual int32_t __stdcall ConvertVCardToContactAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall RequestStoreAsyncWithAccessType(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestAnnotationStoreAsync(int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall IsShowContactCardSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall ShowContactCardWithOptions(void*, llm::OS::Foundation::Rect, int32_t, void*) noexcept = 0;
            virtual int32_t __stdcall IsShowDelayLoadedContactCardSupported(bool*) noexcept = 0;
            virtual int32_t __stdcall ShowDelayLoadedContactCardWithOptions(void*, llm::OS::Foundation::Rect, int32_t, void*, void**) noexcept = 0;
            virtual int32_t __stdcall ShowFullContactCard(void*, void*) noexcept = 0;
            virtual int32_t __stdcall get_SystemDisplayNameOrder(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SystemDisplayNameOrder(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_SystemSortOrder(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SystemSortOrder(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerStatics4>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactManagerStatics5>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall IsShowFullContactCardSupportedAsync(void**) noexcept = 0;
            virtual int32_t __stdcall get_IncludeMiddleNameInSystemDisplayAndSort(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeMiddleNameInSystemDisplayAndSort(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactMatchReason>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Field(int32_t*) noexcept = 0;
            virtual int32_t __stdcall get_Segments(void**) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactName>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_FirstName(void**) noexcept = 0;
            virtual int32_t __stdcall put_FirstName(void*) noexcept = 0;
            virtual int32_t __stdcall get_LastName(void**) noexcept = 0;
            virtual int32_t __stdcall put_LastName(void*) noexcept = 0;
            virtual int32_t __stdcall get_MiddleName(void**) noexcept = 0;
            virtual int32_t __stdcall put_MiddleName(void*) noexcept = 0;
            virtual int32_t __stdcall get_YomiGivenName(void**) noexcept = 0;
            virtual int32_t __stdcall put_YomiGivenName(void*) noexcept = 0;
            virtual int32_t __stdcall get_YomiFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall put_YomiFamilyName(void*) noexcept = 0;
            virtual int32_t __stdcall get_HonorificNameSuffix(void**) noexcept = 0;
            virtual int32_t __stdcall put_HonorificNameSuffix(void*) noexcept = 0;
            virtual int32_t __stdcall get_HonorificNamePrefix(void**) noexcept = 0;
            virtual int32_t __stdcall put_HonorificNamePrefix(void*) noexcept = 0;
            virtual int32_t __stdcall get_DisplayName(void**) noexcept = 0;
            virtual int32_t __stdcall get_YomiDisplayName(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPanel>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ClosePanel() noexcept = 0;
            virtual int32_t __stdcall get_HeaderColor(void**) noexcept = 0;
            virtual int32_t __stdcall put_HeaderColor(void*) noexcept = 0;
            virtual int32_t __stdcall add_LaunchFullAppRequested(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_LaunchFullAppRequested(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall add_Closing(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_Closing(llm::event_token) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDeferral(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Handled(bool*) noexcept = 0;
            virtual int32_t __stdcall put_Handled(bool) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPhone>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Number(void**) noexcept = 0;
            virtual int32_t __stdcall put_Number(void*) noexcept = 0;
            virtual int32_t __stdcall get_Kind(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Kind(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPicker>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_CommitButtonText(void**) noexcept = 0;
            virtual int32_t __stdcall put_CommitButtonText(void*) noexcept = 0;
            virtual int32_t __stdcall get_SelectionMode(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SelectionMode(int32_t) noexcept = 0;
            virtual int32_t __stdcall get_DesiredFields(void**) noexcept = 0;
            virtual int32_t __stdcall PickSingleContactAsync(void**) noexcept = 0;
            virtual int32_t __stdcall PickMultipleContactsAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPicker2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesiredFieldsWithContactFieldType(void**) noexcept = 0;
            virtual int32_t __stdcall PickContactAsync(void**) noexcept = 0;
            virtual int32_t __stdcall PickContactsAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPicker3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactPickerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateForUser(void*, void**) noexcept = 0;
            virtual int32_t __stdcall IsSupportedAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactQueryOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_TextSearch(void**) noexcept = 0;
            virtual int32_t __stdcall get_ContactListIds(void**) noexcept = 0;
            virtual int32_t __stdcall get_IncludeContactsFromHiddenLists(bool*) noexcept = 0;
            virtual int32_t __stdcall put_IncludeContactsFromHiddenLists(bool) noexcept = 0;
            virtual int32_t __stdcall get_DesiredFields(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredFields(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_DesiredOperations(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredOperations(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_AnnotationListIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactQueryOptionsFactory>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateWithText(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateWithTextAndFields(void*, uint32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Fields(uint32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Fields(uint32_t) noexcept = 0;
            virtual int32_t __stdcall get_Text(void**) noexcept = 0;
            virtual int32_t __stdcall put_Text(void*) noexcept = 0;
            virtual int32_t __stdcall get_SearchScope(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_SearchScope(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactReader>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall ReadBatchAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetMatchingPropertiesWithMatchReason(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactSignificantOther>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Name(void**) noexcept = 0;
            virtual int32_t __stdcall put_Name(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactSignificantOther2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Relationship(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_Relationship(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactStore>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall FindContactsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall FindContactsWithSearchTextAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetContactAsync(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactStore2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ChangeTracker(void**) noexcept = 0;
            virtual int32_t __stdcall add_ContactChanged(void*, llm::event_token*) noexcept = 0;
            virtual int32_t __stdcall remove_ContactChanged(llm::event_token) noexcept = 0;
            virtual int32_t __stdcall get_AggregateContactManager(void**) noexcept = 0;
            virtual int32_t __stdcall FindContactListsAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetContactListAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateContactListAsync(void*, void**) noexcept = 0;
            virtual int32_t __stdcall GetMeContactAsync(void**) noexcept = 0;
            virtual int32_t __stdcall GetContactReader(void**) noexcept = 0;
            virtual int32_t __stdcall GetContactReaderWithOptions(void*, void**) noexcept = 0;
            virtual int32_t __stdcall CreateContactListInAccountAsync(void*, void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactStore3>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetChangeTracker(void*, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactWebsite>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Uri(void**) noexcept = 0;
            virtual int32_t __stdcall put_Uri(void*) noexcept = 0;
            virtual int32_t __stdcall get_Description(void**) noexcept = 0;
            virtual int32_t __stdcall put_Description(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IContactWebsite2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_RawValue(void**) noexcept = 0;
            virtual int32_t __stdcall put_RawValue(void*) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IFullContactCardOptions>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_DesiredRemainingView(int32_t*) noexcept = 0;
            virtual int32_t __stdcall put_DesiredRemainingView(int32_t) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IKnownContactFieldStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_Email(void**) noexcept = 0;
            virtual int32_t __stdcall get_PhoneNumber(void**) noexcept = 0;
            virtual int32_t __stdcall get_Location(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstantMessage(void**) noexcept = 0;
            virtual int32_t __stdcall ConvertNameToType(void*, int32_t*) noexcept = 0;
            virtual int32_t __stdcall ConvertTypeToName(int32_t, void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ContactIds(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IPinnedContactManager>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_User(void**) noexcept = 0;
            virtual int32_t __stdcall IsPinSurfaceSupported(int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall IsContactPinned(void*, int32_t, bool*) noexcept = 0;
            virtual int32_t __stdcall RequestPinContactAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestPinContactsAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall RequestUnpinContactAsync(void*, int32_t, void**) noexcept = 0;
            virtual int32_t __stdcall SignalContactActivity(void*) noexcept = 0;
            virtual int32_t __stdcall GetPinnedContactIdsAsync(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Contacts::IPinnedContactManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall GetDefault(void**) noexcept = 0;
            virtual int32_t __stdcall GetForUser(void*, void**) noexcept = 0;
            virtual int32_t __stdcall IsSupported(bool*) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IAggregateContactManager
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>>) FindRawContactsAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) TryLinkContactsAsync(llm::OS::ApplicationModel::Contacts::Contact const& primaryContact, llm::OS::ApplicationModel::Contacts::Contact const& secondaryContact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) UnlinkRawContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TrySetPreferredSourceForPictureAsync(llm::OS::ApplicationModel::Contacts::Contact const& aggregateContact, llm::OS::ApplicationModel::Contacts::Contact const& rawContact) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IAggregateContactManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IAggregateContactManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IAggregateContactManager2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SetRemoteIdentificationInformationAsync(param::hstring const& contactListId, param::hstring const& remoteSourceId, param::hstring const& accountId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IAggregateContactManager2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IAggregateContactManager2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContact
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) Thumbnail() const;
        LLM_IMPL_AUTO(void) Thumbnail(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::IContactField>) Fields() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContact>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContact<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContact2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        LLM_IMPL_AUTO(void) Id(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Notes() const;
        LLM_IMPL_AUTO(void) Notes(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactPhone>) Phones() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactEmail>) Emails() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactAddress>) Addresses() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactConnectedServiceAccount>) ConnectedServiceAccounts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactDate>) ImportantDates() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) DataSuppliers() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactJobInfo>) JobInfo() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactSignificantOther>) SignificantOthers() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactWebsite>) Websites() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IPropertySet) ProviderProperties() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContact2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContact2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContact3
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContactListId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) DisplayPictureUserUpdateTime() const;
        LLM_IMPL_AUTO(void) DisplayPictureUserUpdateTime(llm::OS::Foundation::DateTime const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsMe() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AggregateId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemoteId() const;
        LLM_IMPL_AUTO(void) RemoteId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RingToneToken() const;
        LLM_IMPL_AUTO(void) RingToneToken(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisplayPictureManuallySet() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) LargeDisplayPicture() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) SmallDisplayPicture() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) SourceDisplayPicture() const;
        LLM_IMPL_AUTO(void) SourceDisplayPicture(llm::OS::Storage::Streams::IRandomAccessStreamReference const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) TextToneToken() const;
        LLM_IMPL_AUTO(void) TextToneToken(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsAggregate() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FullName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayNameOverride() const;
        LLM_IMPL_AUTO(void) DisplayNameOverride(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Nickname() const;
        LLM_IMPL_AUTO(void) Nickname(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SortName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContact3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContact3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactAddress
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) StreetAddress() const;
        LLM_IMPL_AUTO(void) StreetAddress(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Locality() const;
        LLM_IMPL_AUTO(void) Locality(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Region() const;
        LLM_IMPL_AUTO(void) Region(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Country() const;
        LLM_IMPL_AUTO(void) Country(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PostalCode() const;
        LLM_IMPL_AUTO(void) PostalCode(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactAddressKind) Kind() const;
        LLM_IMPL_AUTO(void) Kind(llm::OS::ApplicationModel::Contacts::ContactAddressKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactAddress>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactAddress<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactAnnotation
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AnnotationListId() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContactId() const;
        LLM_IMPL_AUTO(void) ContactId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemoteId() const;
        LLM_IMPL_AUTO(void) RemoteId(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactAnnotationOperations) SupportedOperations() const;
        LLM_IMPL_AUTO(void) SupportedOperations(llm::OS::ApplicationModel::Contacts::ContactAnnotationOperations const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsDisabled() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) ProviderProperties() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactAnnotation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactAnnotation<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactAnnotation2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ContactListId() const;
        LLM_IMPL_AUTO(void) ContactListId(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactAnnotation2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactAnnotation2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactAnnotationList
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ProviderPackageFamilyName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserDataAccountId() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TrySaveAnnotationAsync(llm::OS::ApplicationModel::Contacts::ContactAnnotation const& annotation) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactAnnotation>) GetAnnotationAsync(param::hstring const& annotationId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotation>>) FindAnnotationsByRemoteIdAsync(param::hstring const& remoteId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotation>>) FindAnnotationsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteAnnotationAsync(llm::OS::ApplicationModel::Contacts::ContactAnnotation const& annotation) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactAnnotationList>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactAnnotationList<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactAnnotationStore
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>) FindContactIdsByEmailAsync(param::hstring const& emailAddress) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>) FindContactIdsByPhoneNumberAsync(param::hstring const& phoneNumber) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotation>>) FindAnnotationsForContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DisableAnnotationAsync(llm::OS::ApplicationModel::Contacts::ContactAnnotation const& annotation) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>) CreateAnnotationListAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>) CreateAnnotationListAsync(param::hstring const& userDataAccountId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>) GetAnnotationListAsync(param::hstring const& annotationListId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotationList>>) FindAnnotationListsAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactAnnotationStore<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactAnnotationStore2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactAnnotation>>) FindAnnotationsForContactListAsync(param::hstring const& contactListId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactAnnotationStore2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactAnnotationStore2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactBatch
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>) Contacts() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactBatchStatus) Status() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactBatch>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactBatch<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactCardDelayedDataLoader
    {
        LLM_IMPL_AUTO(void) SetData(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactCardDelayedDataLoader>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactCardDelayedDataLoader<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactCardOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactCardHeaderKind) HeaderKind() const;
        LLM_IMPL_AUTO(void) HeaderKind(llm::OS::ApplicationModel::Contacts::ContactCardHeaderKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactCardTabKind) InitialTabKind() const;
        LLM_IMPL_AUTO(void) InitialTabKind(llm::OS::ApplicationModel::Contacts::ContactCardTabKind const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactCardOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactCardOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactCardOptions2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) ServerSearchContactListIds() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactCardOptions2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactCardOptions2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactChange
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangeType) ChangeType() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) Contact() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactChange>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactChange<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactChangeReader
    {
        LLM_IMPL_AUTO(void) AcceptChanges() const;
        LLM_IMPL_AUTO(void) AcceptChangesThrough(llm::OS::ApplicationModel::Contacts::ContactChange const& lastChangeToAccept) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactChange>>) ReadBatchAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactChangeReader>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactChangeReader<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactChangeTracker
    {
        LLM_IMPL_AUTO(void) Enable() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangeReader) GetChangeReader() const;
        LLM_IMPL_AUTO(void) Reset() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactChangeTracker>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactChangeTracker<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactChangeTracker2
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsTracking() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactChangeTracker2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactChangeTracker2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactChangedDeferral
    {
        LLM_IMPL_AUTO(void) Complete() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactChangedDeferral>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactChangedDeferral<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactChangedEventArgs
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangedDeferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactChangedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactChangedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactConnectedServiceAccount
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        LLM_IMPL_AUTO(void) Id(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ServiceName() const;
        LLM_IMPL_AUTO(void) ServiceName(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactConnectedServiceAccount>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactConnectedServiceAccount<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactDate
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) Day() const;
        LLM_IMPL_AUTO(void) Day(llm::OS::Foundation::IReference<uint32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) Month() const;
        LLM_IMPL_AUTO(void) Month(llm::OS::Foundation::IReference<uint32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) Year() const;
        LLM_IMPL_AUTO(void) Year(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactDateKind) Kind() const;
        LLM_IMPL_AUTO(void) Kind(llm::OS::ApplicationModel::Contacts::ContactDateKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactDate>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactDate<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactEmail
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Address() const;
        LLM_IMPL_AUTO(void) Address(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactEmailKind) Kind() const;
        LLM_IMPL_AUTO(void) Kind(llm::OS::ApplicationModel::Contacts::ContactEmailKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactEmail>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactEmail<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactField
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactFieldType) Type() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactFieldCategory) Category() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Value() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactField>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactField<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactFieldFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactField) CreateField(param::hstring const& value, llm::OS::ApplicationModel::Contacts::ContactFieldType const& type) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactField) CreateField(param::hstring const& value, llm::OS::ApplicationModel::Contacts::ContactFieldType const& type, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactField) CreateField(param::hstring const& name, param::hstring const& value, llm::OS::ApplicationModel::Contacts::ContactFieldType const& type, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactFieldFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactFieldFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactGroup
    {
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactGroup>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactGroup<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactInformation
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IRandomAccessStreamWithContentType>) GetThumbnailAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactField>) Emails() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactField>) PhoneNumbers() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactLocationField>) Locations() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactInstantMessageField>) InstantMessages() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactField>) CustomFields() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactField>) QueryCustomFields(param::hstring const& customName) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactInformation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactInformation<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactInstantMessageField
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Service() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayText() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) LaunchUri() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactInstantMessageField>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactInstantMessageField<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactInstantMessageFieldFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactInstantMessageField) CreateInstantMessage(param::hstring const& userName) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactInstantMessageField) CreateInstantMessage(param::hstring const& userName, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactInstantMessageField) CreateInstantMessage(param::hstring const& userName, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category, param::hstring const& service, param::hstring const& displayText, llm::OS::Foundation::Uri const& verb) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactInstantMessageFieldFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactInstantMessageFieldFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactJobInfo
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CompanyName() const;
        LLM_IMPL_AUTO(void) CompanyName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CompanyYomiName() const;
        LLM_IMPL_AUTO(void) CompanyYomiName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Department() const;
        LLM_IMPL_AUTO(void) Department(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Title() const;
        LLM_IMPL_AUTO(void) Title(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Manager() const;
        LLM_IMPL_AUTO(void) Manager(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Office() const;
        LLM_IMPL_AUTO(void) Office(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CompanyAddress() const;
        LLM_IMPL_AUTO(void) CompanyAddress(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactJobInfo>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactJobInfo<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactLaunchActionVerbsStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Call() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Message() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Map() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Post() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) VideoCall() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactLaunchActionVerbsStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactLaunchActionVerbsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactList
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Id() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        LLM_IMPL_AUTO(void) DisplayName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourceDisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IsHidden() const;
        LLM_IMPL_AUTO(void) IsHidden(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactListOtherAppReadAccess) OtherAppReadAccess() const;
        LLM_IMPL_AUTO(void) OtherAppReadAccess(llm::OS::ApplicationModel::Contacts::ContactListOtherAppReadAccess const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactListOtherAppWriteAccess) OtherAppWriteAccess() const;
        LLM_IMPL_AUTO(void) OtherAppWriteAccess(llm::OS::ApplicationModel::Contacts::ContactListOtherAppWriteAccess const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangeTracker) ChangeTracker() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactListSyncManager) SyncManager() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) SupportsServerSearch() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UserDataAccountId() const;
        LLM_IMPL_AUTO(llm::event_token) ContactChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactList, llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs> const& value) const;
        using ContactChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Contacts::IContactList, &impl::abi_t<llm::OS::ApplicationModel::Contacts::IContactList>::remove_ContactChanged>;
        [[nodiscard]] ContactChanged_revoker ContactChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactList, llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) ContactChanged(llm::event_token const& value) const noexcept;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SaveAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) GetContactFromRemoteIdAsync(param::hstring const& remoteId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) GetMeContactAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactReader) GetContactReader() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactReader) GetContactReader(llm::OS::ApplicationModel::Contacts::ContactQueryOptions const& options) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) SaveContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) GetContactAsync(param::hstring const& contactId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactList>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactList<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactList2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) RegisterSyncManagerAsync() const;
        LLM_IMPL_AUTO(void) SupportsServerSearch(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactListSyncConstraints) SyncConstraints() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactList2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactList2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactList3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactListLimitedWriteOperations) LimitedWriteOperations() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangeTracker) GetChangeTracker(param::hstring const& identity) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactList3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactList3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactListLimitedWriteOperations
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryCreateOrUpdateContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) TryDeleteContactAsync(param::hstring const& contactId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactListLimitedWriteOperations>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactListLimitedWriteOperations<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactListSyncConstraints
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) CanSyncDescriptions() const;
        LLM_IMPL_AUTO(void) CanSyncDescriptions(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxHomePhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxHomePhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxMobilePhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxMobilePhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxWorkPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxWorkPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxOtherPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxOtherPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxPagerPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxPagerPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxBusinessFaxPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxBusinessFaxPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxHomeFaxPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxHomeFaxPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxCompanyPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxCompanyPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxAssistantPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxAssistantPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxRadioPhoneNumbers() const;
        LLM_IMPL_AUTO(void) MaxRadioPhoneNumbers(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxPersonalEmailAddresses() const;
        LLM_IMPL_AUTO(void) MaxPersonalEmailAddresses(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxWorkEmailAddresses() const;
        LLM_IMPL_AUTO(void) MaxWorkEmailAddresses(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxOtherEmailAddresses() const;
        LLM_IMPL_AUTO(void) MaxOtherEmailAddresses(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxHomeAddresses() const;
        LLM_IMPL_AUTO(void) MaxHomeAddresses(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxWorkAddresses() const;
        LLM_IMPL_AUTO(void) MaxWorkAddresses(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxOtherAddresses() const;
        LLM_IMPL_AUTO(void) MaxOtherAddresses(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxBirthdayDates() const;
        LLM_IMPL_AUTO(void) MaxBirthdayDates(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxAnniversaryDates() const;
        LLM_IMPL_AUTO(void) MaxAnniversaryDates(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxOtherDates() const;
        LLM_IMPL_AUTO(void) MaxOtherDates(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxOtherRelationships() const;
        LLM_IMPL_AUTO(void) MaxOtherRelationships(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxSpouseRelationships() const;
        LLM_IMPL_AUTO(void) MaxSpouseRelationships(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxPartnerRelationships() const;
        LLM_IMPL_AUTO(void) MaxPartnerRelationships(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxSiblingRelationships() const;
        LLM_IMPL_AUTO(void) MaxSiblingRelationships(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxParentRelationships() const;
        LLM_IMPL_AUTO(void) MaxParentRelationships(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxChildRelationships() const;
        LLM_IMPL_AUTO(void) MaxChildRelationships(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxJobInfo() const;
        LLM_IMPL_AUTO(void) MaxJobInfo(llm::OS::Foundation::IReference<int32_t> const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) MaxWebsites() const;
        LLM_IMPL_AUTO(void) MaxWebsites(llm::OS::Foundation::IReference<int32_t> const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactListSyncConstraints>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactListSyncConstraints<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactListSyncManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactListSyncStatus) Status() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) LastSuccessfulSyncTime() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) LastAttemptedSyncTime() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) SyncAsync() const;
        LLM_IMPL_AUTO(llm::event_token) SyncStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactListSyncManager, llm::OS::Foundation::IInspectable> const& handler) const;
        using SyncStatusChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Contacts::IContactListSyncManager, &impl::abi_t<llm::OS::ApplicationModel::Contacts::IContactListSyncManager>::remove_SyncStatusChanged>;
        [[nodiscard]] SyncStatusChanged_revoker SyncStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactListSyncManager, llm::OS::Foundation::IInspectable> const& handler) const;
        LLM_IMPL_AUTO(void) SyncStatusChanged(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactListSyncManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactListSyncManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactListSyncManager2
    {
        LLM_IMPL_AUTO(void) Status(llm::OS::ApplicationModel::Contacts::ContactListSyncStatus const& value) const;
        LLM_IMPL_AUTO(void) LastSuccessfulSyncTime(llm::OS::Foundation::DateTime const& value) const;
        LLM_IMPL_AUTO(void) LastAttemptedSyncTime(llm::OS::Foundation::DateTime const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactListSyncManager2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactListSyncManager2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactLocationField
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) UnstructuredAddress() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Street() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) City() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Region() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Country() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PostalCode() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactLocationField>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactLocationField<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactLocationFieldFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactLocationField) CreateLocation(param::hstring const& unstructuredAddress) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactLocationField) CreateLocation(param::hstring const& unstructuredAddress, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactLocationField) CreateLocation(param::hstring const& unstructuredAddress, llm::OS::ApplicationModel::Contacts::ContactFieldCategory const& category, param::hstring const& street, param::hstring const& city, param::hstring const& region, param::hstring const& country, param::hstring const& postalCode) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactLocationFieldFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactLocationFieldFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerForUser
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::RandomAccessStreamReference>) ConvertContactToVCardAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::RandomAccessStreamReference>) ConvertContactToVCardAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact, uint32_t maxBytes) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) ConvertVCardToContactAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& vCard) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactStore>) RequestStoreAsync(llm::OS::ApplicationModel::Contacts::ContactStoreAccessType const& accessType) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactAnnotationStore>) RequestAnnotationStoreAsync(llm::OS::ApplicationModel::Contacts::ContactAnnotationStoreAccessType const& accessType) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactNameOrder) SystemDisplayNameOrder() const;
        LLM_IMPL_AUTO(void) SystemDisplayNameOrder(llm::OS::ApplicationModel::Contacts::ContactNameOrder const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactNameOrder) SystemSortOrder() const;
        LLM_IMPL_AUTO(void) SystemSortOrder(llm::OS::ApplicationModel::Contacts::ContactNameOrder const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::User) User() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerForUser>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerForUser<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerForUser2
    {
        LLM_IMPL_AUTO(void) ShowFullContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::ApplicationModel::Contacts::FullContactCardOptions const& fullContactCardOptions) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerForUser2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerForUser2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerStatics
    {
        LLM_IMPL_AUTO(void) ShowContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection) const;
        LLM_IMPL_AUTO(void) ShowContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactCardDelayedDataLoader) ShowDelayLoadedContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerStatics2
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactStore>) RequestStoreAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerStatics3
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::RandomAccessStreamReference>) ConvertContactToVCardAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::RandomAccessStreamReference>) ConvertContactToVCardAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact, uint32_t maxBytes) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) ConvertVCardToContactAsync(llm::OS::Storage::Streams::IRandomAccessStreamReference const& vCard) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactStore>) RequestStoreAsync(llm::OS::ApplicationModel::Contacts::ContactStoreAccessType const& accessType) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactAnnotationStore>) RequestAnnotationStoreAsync(llm::OS::ApplicationModel::Contacts::ContactAnnotationStoreAccessType const& accessType) const;
        LLM_IMPL_AUTO(bool) IsShowContactCardSupported() const;
        LLM_IMPL_AUTO(void) ShowContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement, llm::OS::ApplicationModel::Contacts::ContactCardOptions const& contactCardOptions) const;
        LLM_IMPL_AUTO(bool) IsShowDelayLoadedContactCardSupported() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactCardDelayedDataLoader) ShowDelayLoadedContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement, llm::OS::ApplicationModel::Contacts::ContactCardOptions const& contactCardOptions) const;
        LLM_IMPL_AUTO(void) ShowFullContactCard(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::ApplicationModel::Contacts::FullContactCardOptions const& fullContactCardOptions) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactNameOrder) SystemDisplayNameOrder() const;
        LLM_IMPL_AUTO(void) SystemDisplayNameOrder(llm::OS::ApplicationModel::Contacts::ContactNameOrder const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactNameOrder) SystemSortOrder() const;
        LLM_IMPL_AUTO(void) SystemSortOrder(llm::OS::ApplicationModel::Contacts::ContactNameOrder const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerStatics3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerStatics3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerStatics4
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactManagerForUser) GetForUser(llm::OS::System::User const& user) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerStatics4>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerStatics4<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactManagerStatics5
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) IsShowFullContactCardSupportedAsync() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeMiddleNameInSystemDisplayAndSort() const;
        LLM_IMPL_AUTO(void) IncludeMiddleNameInSystemDisplayAndSort(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactManagerStatics5>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactManagerStatics5<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactMatchReason
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactMatchReasonKind) Field() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Data::Text::TextSegment>) Segments() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactMatchReason>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactMatchReason<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactName
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) FirstName() const;
        LLM_IMPL_AUTO(void) FirstName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) LastName() const;
        LLM_IMPL_AUTO(void) LastName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) MiddleName() const;
        LLM_IMPL_AUTO(void) MiddleName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) YomiGivenName() const;
        LLM_IMPL_AUTO(void) YomiGivenName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) YomiFamilyName() const;
        LLM_IMPL_AUTO(void) YomiFamilyName(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HonorificNameSuffix() const;
        LLM_IMPL_AUTO(void) HonorificNameSuffix(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) HonorificNamePrefix() const;
        LLM_IMPL_AUTO(void) HonorificNamePrefix(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) DisplayName() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) YomiDisplayName() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactName>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactName<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPanel
    {
        LLM_IMPL_AUTO(void) ClosePanel() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::UI::Color>) HeaderColor() const;
        LLM_IMPL_AUTO(void) HeaderColor(llm::OS::Foundation::IReference<llm::OS::UI::Color> const& value) const;
        LLM_IMPL_AUTO(llm::event_token) LaunchFullAppRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactPanel, llm::OS::ApplicationModel::Contacts::ContactPanelLaunchFullAppRequestedEventArgs> const& handler) const;
        using LaunchFullAppRequested_revoker = impl::event_revoker<llm::OS::ApplicationModel::Contacts::IContactPanel, &impl::abi_t<llm::OS::ApplicationModel::Contacts::IContactPanel>::remove_LaunchFullAppRequested>;
        [[nodiscard]] LaunchFullAppRequested_revoker LaunchFullAppRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactPanel, llm::OS::ApplicationModel::Contacts::ContactPanelLaunchFullAppRequestedEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) LaunchFullAppRequested(llm::event_token const& token) const noexcept;
        LLM_IMPL_AUTO(llm::event_token) Closing(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactPanel, llm::OS::ApplicationModel::Contacts::ContactPanelClosingEventArgs> const& handler) const;
        using Closing_revoker = impl::event_revoker<llm::OS::ApplicationModel::Contacts::IContactPanel, &impl::abi_t<llm::OS::ApplicationModel::Contacts::IContactPanel>::remove_Closing>;
        [[nodiscard]] Closing_revoker Closing(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactPanel, llm::OS::ApplicationModel::Contacts::ContactPanelClosingEventArgs> const& handler) const;
        LLM_IMPL_AUTO(void) Closing(llm::event_token const& token) const noexcept;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPanel>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPanel<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPanelClosingEventArgs
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) GetDeferral() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPanelClosingEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPanelClosingEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPanelLaunchFullAppRequestedEventArgs
    {
        [[nodiscard]] LLM_IMPL_AUTO(bool) Handled() const;
        LLM_IMPL_AUTO(void) Handled(bool value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPanelLaunchFullAppRequestedEventArgs>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPanelLaunchFullAppRequestedEventArgs<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPhone
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Number() const;
        LLM_IMPL_AUTO(void) Number(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactPhoneKind) Kind() const;
        LLM_IMPL_AUTO(void) Kind(llm::OS::ApplicationModel::Contacts::ContactPhoneKind const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPhone>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPhone<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPicker
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) CommitButtonText() const;
        LLM_IMPL_AUTO(void) CommitButtonText(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactSelectionMode) SelectionMode() const;
        LLM_IMPL_AUTO(void) SelectionMode(llm::OS::ApplicationModel::Contacts::ContactSelectionMode const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) DesiredFields() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactInformation>) PickSingleContactAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactInformation>>) PickMultipleContactsAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPicker>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPicker<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPicker2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::ContactFieldType>) DesiredFieldsWithContactFieldType() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) PickContactAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<llm::OS::ApplicationModel::Contacts::Contact>>) PickContactsAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPicker2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPicker2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPicker3
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::User) User() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPicker3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPicker3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactPickerStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactPicker) CreateForUser(llm::OS::System::User const& user) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) IsSupportedAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactPickerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactPickerStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactQueryOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQueryTextSearch) TextSearch() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) ContactListIds() const;
        [[nodiscard]] LLM_IMPL_AUTO(bool) IncludeContactsFromHiddenLists() const;
        LLM_IMPL_AUTO(void) IncludeContactsFromHiddenLists(bool value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQueryDesiredFields) DesiredFields() const;
        LLM_IMPL_AUTO(void) DesiredFields(llm::OS::ApplicationModel::Contacts::ContactQueryDesiredFields const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactAnnotationOperations) DesiredOperations() const;
        LLM_IMPL_AUTO(void) DesiredOperations(llm::OS::ApplicationModel::Contacts::ContactAnnotationOperations const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) AnnotationListIds() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactQueryOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactQueryOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactQueryOptionsFactory
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQueryOptions) CreateWithText(param::hstring const& text) const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQueryOptions) CreateWithTextAndFields(param::hstring const& text, llm::OS::ApplicationModel::Contacts::ContactQuerySearchFields const& fields) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactQueryOptionsFactory>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactQueryOptionsFactory<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactQueryTextSearch
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQuerySearchFields) Fields() const;
        LLM_IMPL_AUTO(void) Fields(llm::OS::ApplicationModel::Contacts::ContactQuerySearchFields const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Text() const;
        LLM_IMPL_AUTO(void) Text(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactQuerySearchScope) SearchScope() const;
        LLM_IMPL_AUTO(void) SearchScope(llm::OS::ApplicationModel::Contacts::ContactQuerySearchScope const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactQueryTextSearch>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactQueryTextSearch<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactReader
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactBatch>) ReadBatchAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactMatchReason>) GetMatchingPropertiesWithMatchReason(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactReader>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactReader<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactSignificantOther
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Name() const;
        LLM_IMPL_AUTO(void) Name(param::hstring const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactSignificantOther>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactSignificantOther<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactSignificantOther2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactRelationship) Relationship() const;
        LLM_IMPL_AUTO(void) Relationship(llm::OS::ApplicationModel::Contacts::ContactRelationship const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactSignificantOther2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactSignificantOther2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactStore
    {
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>>) FindContactsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::Contact>>) FindContactsAsync(param::hstring const& searchText) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) GetContactAsync(param::hstring const& contactId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactStore>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactStore<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactStore2
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangeTracker) ChangeTracker() const;
        LLM_IMPL_AUTO(llm::event_token) ContactChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactStore, llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs> const& value) const;
        using ContactChanged_revoker = impl::event_revoker<llm::OS::ApplicationModel::Contacts::IContactStore2, &impl::abi_t<llm::OS::ApplicationModel::Contacts::IContactStore2>::remove_ContactChanged>;
        [[nodiscard]] ContactChanged_revoker ContactChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Contacts::ContactStore, llm::OS::ApplicationModel::Contacts::ContactChangedEventArgs> const& value) const;
        LLM_IMPL_AUTO(void) ContactChanged(llm::event_token const& value) const noexcept;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::AggregateContactManager) AggregateContactManager() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::Contacts::ContactList>>) FindContactListsAsync() const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactList>) GetContactListAsync(param::hstring const& contactListId) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactList>) CreateContactListAsync(param::hstring const& displayName) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::Contact>) GetMeContactAsync() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactReader) GetContactReader() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactReader) GetContactReader(llm::OS::ApplicationModel::Contacts::ContactQueryOptions const& options) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::ContactList>) CreateContactListAsync(param::hstring const& displayName, param::hstring const& userDataAccountId) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactStore2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactStore2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactStore3
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactChangeTracker) GetChangeTracker(param::hstring const& identity) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactStore3>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactStore3<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactStoreNotificationTriggerDetails
    {
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactStoreNotificationTriggerDetails>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactStoreNotificationTriggerDetails<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactWebsite
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Uri) Uri() const;
        LLM_IMPL_AUTO(void) Uri(llm::OS::Foundation::Uri const& value) const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Description() const;
        LLM_IMPL_AUTO(void) Description(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactWebsite>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactWebsite<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IContactWebsite2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RawValue() const;
        LLM_IMPL_AUTO(void) RawValue(param::hstring const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IContactWebsite2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IContactWebsite2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IFullContactCardOptions
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ViewSizePreference) DesiredRemainingView() const;
        LLM_IMPL_AUTO(void) DesiredRemainingView(llm::OS::UI::ViewManagement::ViewSizePreference const& value) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IFullContactCardOptions>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IFullContactCardOptions<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IKnownContactFieldStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Email() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) PhoneNumber() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) Location() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) InstantMessage() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactFieldType) ConvertNameToType(param::hstring const& name) const;
        LLM_IMPL_AUTO(hstring) ConvertTypeToName(llm::OS::ApplicationModel::Contacts::ContactFieldType const& type) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IKnownContactFieldStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IKnownContactFieldStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IPinnedContactIdsQueryResult
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) ContactIds() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IPinnedContactIdsQueryResult>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IPinnedContactIdsQueryResult<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IPinnedContactManager
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::System::User) User() const;
        LLM_IMPL_AUTO(bool) IsPinSurfaceSupported(llm::OS::ApplicationModel::Contacts::PinnedContactSurface const& surface) const;
        LLM_IMPL_AUTO(bool) IsContactPinned(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::ApplicationModel::Contacts::PinnedContactSurface const& surface) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestPinContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::ApplicationModel::Contacts::PinnedContactSurface const& surface) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestPinContactsAsync(param::async_iterable<llm::OS::ApplicationModel::Contacts::Contact> const& contacts, llm::OS::ApplicationModel::Contacts::PinnedContactSurface const& surface) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) RequestUnpinContactAsync(llm::OS::ApplicationModel::Contacts::Contact const& contact, llm::OS::ApplicationModel::Contacts::PinnedContactSurface const& surface) const;
        LLM_IMPL_AUTO(void) SignalContactActivity(llm::OS::ApplicationModel::Contacts::Contact const& contact) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::Contacts::PinnedContactIdsQueryResult>) GetPinnedContactIdsAsync() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IPinnedContactManager>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IPinnedContactManager<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Contacts_IPinnedContactManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::PinnedContactManager) GetDefault() const;
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::PinnedContactManager) GetForUser(llm::OS::System::User const& user) const;
        LLM_IMPL_AUTO(bool) IsSupported() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Contacts::IPinnedContactManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Contacts_IPinnedContactManagerStatics<D>;
    };
}
#endif
