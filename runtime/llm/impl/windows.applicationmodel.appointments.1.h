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
#ifndef LLM_OS_ApplicationModel_Appointments_1_H
#define LLM_OS_ApplicationModel_Appointments_1_H
#include "llm/impl/Windows.ApplicationModel.Appointments.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments
{
    struct __declspec(empty_bases) IAppointment :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointment>
    {
        IAppointment(std::nullptr_t = nullptr) noexcept {}
        IAppointment(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointment2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointment2>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointment2, llm::OS::ApplicationModel::Appointments::IAppointment>
    {
        IAppointment2(std::nullptr_t = nullptr) noexcept {}
        IAppointment2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointment3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointment3>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointment3, llm::OS::ApplicationModel::Appointments::IAppointment, llm::OS::ApplicationModel::Appointments::IAppointment2>
    {
        IAppointment3(std::nullptr_t = nullptr) noexcept {}
        IAppointment3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendar :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendar>
    {
        IAppointmentCalendar(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendar(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendar2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendar2>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentCalendar2, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar>
    {
        IAppointmentCalendar2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendar2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IAppointmentCalendar2, IAppointmentCalendar2>::DisplayColor;
        using impl::consume_t<IAppointmentCalendar2, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar>::DisplayColor;
        using impl::consume_t<IAppointmentCalendar2, IAppointmentCalendar2>::IsHidden;
        using impl::consume_t<IAppointmentCalendar2, llm::OS::ApplicationModel::Appointments::IAppointmentCalendar>::IsHidden;
    };
    struct __declspec(empty_bases) IAppointmentCalendar3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendar3>
    {
        IAppointmentCalendar3(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendar3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarSyncManager :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarSyncManager>
    {
        IAppointmentCalendarSyncManager(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarSyncManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarSyncManager2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarSyncManager2>
    {
        IAppointmentCalendarSyncManager2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarSyncManager2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentConflictResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentConflictResult>
    {
        IAppointmentConflictResult(std::nullptr_t = nullptr) noexcept {}
        IAppointmentConflictResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentException :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentException>
    {
        IAppointmentException(std::nullptr_t = nullptr) noexcept {}
        IAppointmentException(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentInvitee :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentInvitee>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentInvitee, llm::OS::ApplicationModel::Appointments::IAppointmentParticipant>
    {
        IAppointmentInvitee(std::nullptr_t = nullptr) noexcept {}
        IAppointmentInvitee(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentManagerForUser :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentManagerForUser>
    {
        IAppointmentManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IAppointmentManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentManagerStatics>
    {
        IAppointmentManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAppointmentManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentManagerStatics2>
    {
        IAppointmentManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentManagerStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentManagerStatics3>
    {
        IAppointmentManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IAppointmentManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentParticipant :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentParticipant>
    {
        IAppointmentParticipant(std::nullptr_t = nullptr) noexcept {}
        IAppointmentParticipant(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentPropertiesStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentPropertiesStatics>
    {
        IAppointmentPropertiesStatics(std::nullptr_t = nullptr) noexcept {}
        IAppointmentPropertiesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentPropertiesStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentPropertiesStatics2>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentPropertiesStatics2, llm::OS::ApplicationModel::Appointments::IAppointmentPropertiesStatics>
    {
        IAppointmentPropertiesStatics2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentPropertiesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentRecurrence :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentRecurrence>
    {
        IAppointmentRecurrence(std::nullptr_t = nullptr) noexcept {}
        IAppointmentRecurrence(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentRecurrence2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentRecurrence2>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence2, llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence>
    {
        IAppointmentRecurrence2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentRecurrence2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentRecurrence3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentRecurrence3>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence3, llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence, llm::OS::ApplicationModel::Appointments::IAppointmentRecurrence2>
    {
        IAppointmentRecurrence3(std::nullptr_t = nullptr) noexcept {}
        IAppointmentRecurrence3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStore>
    {
        IAppointmentStore(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStore2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStore2>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentStore2, llm::OS::ApplicationModel::Appointments::IAppointmentStore>
    {
        IAppointmentStore2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStore2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
        using impl::consume_t<IAppointmentStore2, IAppointmentStore2>::CreateAppointmentCalendarAsync;
        using impl::consume_t<IAppointmentStore2, llm::OS::ApplicationModel::Appointments::IAppointmentStore>::CreateAppointmentCalendarAsync;
    };
    struct __declspec(empty_bases) IAppointmentStore3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStore3>
    {
        IAppointmentStore3(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStore3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChange :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChange>
    {
        IAppointmentStoreChange(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChange(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChange2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChange2>,
        impl::require<llm::OS::ApplicationModel::Appointments::IAppointmentStoreChange2, llm::OS::ApplicationModel::Appointments::IAppointmentStoreChange>
    {
        IAppointmentStoreChange2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChange2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChangeReader :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChangeReader>
    {
        IAppointmentStoreChangeReader(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChangeReader(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChangeTracker :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChangeTracker>
    {
        IAppointmentStoreChangeTracker(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChangeTracker(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChangeTracker2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChangeTracker2>
    {
        IAppointmentStoreChangeTracker2(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChangeTracker2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChangedDeferral :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChangedDeferral>
    {
        IAppointmentStoreChangedDeferral(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChangedDeferral(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreChangedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreChangedEventArgs>
    {
        IAppointmentStoreChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentStoreNotificationTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentStoreNotificationTriggerDetails>
    {
        IAppointmentStoreNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IAppointmentStoreNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFindAppointmentsOptions :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IFindAppointmentsOptions>
    {
        IFindAppointmentsOptions(std::nullptr_t = nullptr) noexcept {}
        IFindAppointmentsOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
