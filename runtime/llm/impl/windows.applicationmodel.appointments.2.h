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
#ifndef LLM_OS_ApplicationModel_Appointments_2_H
#define LLM_OS_ApplicationModel_Appointments_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.UI.Popups.1.h"
#include "llm/impl/Windows.ApplicationModel.Appointments.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments
{
    struct __declspec(empty_bases) Appointment : llm::OS::ApplicationModel::Appointments::IAppointment,
        impl::require<Appointment, llm::OS::ApplicationModel::Appointments::IAppointment2, llm::OS::ApplicationModel::Appointments::IAppointment3>
    {
        Appointment(std::nullptr_t) noexcept {}
        Appointment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointment(ptr, take_ownership_from_abi) {}
        Appointment();
    };
    struct __declspec(empty_bases) AppointmentCalendar : llm::OS::ApplicationModel::Appointments::IAppointmentCalendar,
        impl::require<AppointmentCalendar, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar2, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar3>
    {
        AppointmentCalendar(std::nullptr_t) noexcept {}
        AppointmentCalendar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentCalendar(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Appointments::IAppointmentCalendar::DisplayColor;
        using impl::consume_t<AppointmentCalendar, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar2>::DisplayColor;
        using llm::OS::ApplicationModel::Appointments::IAppointmentCalendar::IsHidden;
        using impl::consume_t<AppointmentCalendar, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar2>::IsHidden;
    };
    struct __declspec(empty_bases) AppointmentCalendarSyncManager : llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager,
        impl::require<AppointmentCalendarSyncManager, llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>
    {
        AppointmentCalendarSyncManager(std::nullptr_t) noexcept {}
        AppointmentCalendarSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager::LastAttemptedSyncTime;
        using impl::consume_t<AppointmentCalendarSyncManager, llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>::LastAttemptedSyncTime;
        using llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager::LastSuccessfulSyncTime;
        using impl::consume_t<AppointmentCalendarSyncManager, llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>::LastSuccessfulSyncTime;
        using llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager::Status;
        using impl::consume_t<AppointmentCalendarSyncManager, llm::OS::ApplicationModel::Appointments::IAppointmentCalendarSyncManager2>::Status;
    };
    struct __declspec(empty_bases) AppointmentConflictResult : llm::OS::ApplicationModel::Appointments::IAppointmentConflictResult
    {
        AppointmentConflictResult(std::nullptr_t) noexcept {}
        AppointmentConflictResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentConflictResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentException : llm::OS::ApplicationModel::Appointments::IAppointmentException
    {
        AppointmentException(std::nullptr_t) noexcept {}
        AppointmentException(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentException(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentInvitee : llm::OS::ApplicationModel::Appointments::IAppointmentInvitee
    {
        AppointmentInvitee(std::nullptr_t) noexcept {}
        AppointmentInvitee(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentInvitee(ptr, take_ownership_from_abi) {}
        AppointmentInvitee();
    };
    struct AppointmentManager
    {
        AppointmentManager() = delete;
        static auto ShowAddAppointmentAsync(llm::OS::ApplicationModel::Appointments::Appointment const& appointment, llm::OS::Foundation::Rect const& selection);
        static auto ShowAddAppointmentAsync(llm::OS::ApplicationModel::Appointments::Appointment const& appointment, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement);
        static auto ShowReplaceAppointmentAsync(param::hstring const& appointmentId, llm::OS::ApplicationModel::Appointments::Appointment const& appointment, llm::OS::Foundation::Rect const& selection);
        static auto ShowReplaceAppointmentAsync(param::hstring const& appointmentId, llm::OS::ApplicationModel::Appointments::Appointment const& appointment, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement);
        static auto ShowReplaceAppointmentAsync(param::hstring const& appointmentId, llm::OS::ApplicationModel::Appointments::Appointment const& appointment, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement, llm::OS::Foundation::DateTime const& instanceStartDate);
        static auto ShowRemoveAppointmentAsync(param::hstring const& appointmentId, llm::OS::Foundation::Rect const& selection);
        static auto ShowRemoveAppointmentAsync(param::hstring const& appointmentId, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement);
        static auto ShowRemoveAppointmentAsync(param::hstring const& appointmentId, llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& preferredPlacement, llm::OS::Foundation::DateTime const& instanceStartDate);
        static auto ShowTimeFrameAsync(llm::OS::Foundation::DateTime const& timeToShow, llm::OS::Foundation::TimeSpan const& duration);
        static auto ShowAppointmentDetailsAsync(param::hstring const& appointmentId);
        static auto ShowAppointmentDetailsAsync(param::hstring const& appointmentId, llm::OS::Foundation::DateTime const& instanceStartDate);
        static auto ShowEditNewAppointmentAsync(llm::OS::ApplicationModel::Appointments::Appointment const& appointment);
        static auto RequestStoreAsync(llm::OS::ApplicationModel::Appointments::AppointmentStoreAccessType const& options);
        static auto GetForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) AppointmentManagerForUser : llm::OS::ApplicationModel::Appointments::IAppointmentManagerForUser
    {
        AppointmentManagerForUser(std::nullptr_t) noexcept {}
        AppointmentManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentManagerForUser(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentOrganizer : llm::OS::ApplicationModel::Appointments::IAppointmentParticipant
    {
        AppointmentOrganizer(std::nullptr_t) noexcept {}
        AppointmentOrganizer(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentParticipant(ptr, take_ownership_from_abi) {}
        AppointmentOrganizer();
    };
    struct AppointmentProperties
    {
        AppointmentProperties() = delete;
        [[nodiscard]] static auto Subject();
        [[nodiscard]] static auto Location();
        [[nodiscard]] static auto StartTime();
        [[nodiscard]] static auto Duration();
        [[nodiscard]] static auto Reminder();
        [[nodiscard]] static auto BusyStatus();
        [[nodiscard]] static auto Sensitivity();
        [[nodiscard]] static auto OriginalStartTime();
        [[nodiscard]] static auto IsResponseRequested();
        [[nodiscard]] static auto AllowNewTimeProposal();
        [[nodiscard]] static auto AllDay();
        [[nodiscard]] static auto Details();
        [[nodiscard]] static auto OnlineMeetingLink();
        [[nodiscard]] static auto ReplyTime();
        [[nodiscard]] static auto Organizer();
        [[nodiscard]] static auto UserResponse();
        [[nodiscard]] static auto HasInvitees();
        [[nodiscard]] static auto IsCanceledMeeting();
        [[nodiscard]] static auto IsOrganizedByUser();
        [[nodiscard]] static auto Recurrence();
        [[nodiscard]] static auto Uri();
        [[nodiscard]] static auto Invitees();
        [[nodiscard]] static auto DefaultProperties();
        [[nodiscard]] static auto ChangeNumber();
        [[nodiscard]] static auto RemoteChangeNumber();
        [[nodiscard]] static auto DetailsKind();
    };
    struct __declspec(empty_bases) AppointmentRecurrence : llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence,
        impl::require<AppointmentRecurrence, llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence2, llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence3>
    {
        AppointmentRecurrence(std::nullptr_t) noexcept {}
        AppointmentRecurrence(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence(ptr, take_ownership_from_abi) {}
        AppointmentRecurrence();
    };
    struct __declspec(empty_bases) AppointmentStore : llm::OS::ApplicationModel::Appointments::IAppointmentStore,
        impl::require<AppointmentStore, llm::OS::ApplicationModel::Appointments::IAppointmentStore2, llm::OS::ApplicationModel::Appointments::IAppointmentStore3>
    {
        AppointmentStore(std::nullptr_t) noexcept {}
        AppointmentStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStore(ptr, take_ownership_from_abi) {}
        using llm::OS::ApplicationModel::Appointments::IAppointmentStore::CreateAppointmentCalendarAsync;
        using impl::consume_t<AppointmentStore, llm::OS::ApplicationModel::Appointments::IAppointmentStore2>::CreateAppointmentCalendarAsync;
    };
    struct __declspec(empty_bases) AppointmentStoreChange : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChange,
        impl::require<AppointmentStoreChange, llm::OS::ApplicationModel::Appointments::IAppointmentStoreChange2>
    {
        AppointmentStoreChange(std::nullptr_t) noexcept {}
        AppointmentStoreChange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChange(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentStoreChangeReader : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangeReader
    {
        AppointmentStoreChangeReader(std::nullptr_t) noexcept {}
        AppointmentStoreChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangeReader(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentStoreChangeTracker : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangeTracker,
        impl::require<AppointmentStoreChangeTracker, llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangeTracker2>
    {
        AppointmentStoreChangeTracker(std::nullptr_t) noexcept {}
        AppointmentStoreChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangeTracker(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentStoreChangedDeferral : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral
    {
        AppointmentStoreChangedDeferral(std::nullptr_t) noexcept {}
        AppointmentStoreChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangedDeferral(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentStoreChangedEventArgs : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs
    {
        AppointmentStoreChangedEventArgs(std::nullptr_t) noexcept {}
        AppointmentStoreChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStoreChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) AppointmentStoreNotificationTriggerDetails : llm::OS::ApplicationModel::Appointments::IAppointmentStoreNotificationTriggerDetails
    {
        AppointmentStoreNotificationTriggerDetails(std::nullptr_t) noexcept {}
        AppointmentStoreNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IAppointmentStoreNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) FindAppointmentsOptions : llm::OS::ApplicationModel::Appointments::IFindAppointmentsOptions
    {
        FindAppointmentsOptions(std::nullptr_t) noexcept {}
        FindAppointmentsOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::IFindAppointmentsOptions(ptr, take_ownership_from_abi) {}
        FindAppointmentsOptions();
    };
}
#endif
