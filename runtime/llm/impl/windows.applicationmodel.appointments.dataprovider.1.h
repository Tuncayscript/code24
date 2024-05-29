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
#ifndef LLM_OS_ApplicationModel_Appointments_DataProvider_1_H
#define LLM_OS_ApplicationModel_Appointments_DataProvider_1_H
#include "llm/impl/Windows.ApplicationModel.Appointments.DataProvider.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments::DataProvider
{
    struct __declspec(empty_bases) IAppointmentCalendarCancelMeetingRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarCancelMeetingRequest>
    {
        IAppointmentCalendarCancelMeetingRequest(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarCancelMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarCancelMeetingRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarCancelMeetingRequestEventArgs>
    {
        IAppointmentCalendarCancelMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarCancelMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarCreateOrUpdateAppointmentRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarCreateOrUpdateAppointmentRequest>
    {
        IAppointmentCalendarCreateOrUpdateAppointmentRequest(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarCreateOrUpdateAppointmentRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs>
    {
        IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarCreateOrUpdateAppointmentRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarForwardMeetingRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarForwardMeetingRequest>
    {
        IAppointmentCalendarForwardMeetingRequest(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarForwardMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarForwardMeetingRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarForwardMeetingRequestEventArgs>
    {
        IAppointmentCalendarForwardMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarForwardMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarProposeNewTimeForMeetingRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarProposeNewTimeForMeetingRequest>
    {
        IAppointmentCalendarProposeNewTimeForMeetingRequest(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarProposeNewTimeForMeetingRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs>
    {
        IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarProposeNewTimeForMeetingRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarSyncManagerSyncRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarSyncManagerSyncRequest>
    {
        IAppointmentCalendarSyncManagerSyncRequest(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarSyncManagerSyncRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarSyncManagerSyncRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarSyncManagerSyncRequestEventArgs>
    {
        IAppointmentCalendarSyncManagerSyncRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarSyncManagerSyncRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarUpdateMeetingResponseRequest :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarUpdateMeetingResponseRequest>
    {
        IAppointmentCalendarUpdateMeetingResponseRequest(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarUpdateMeetingResponseRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentCalendarUpdateMeetingResponseRequestEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentCalendarUpdateMeetingResponseRequestEventArgs>
    {
        IAppointmentCalendarUpdateMeetingResponseRequestEventArgs(std::nullptr_t = nullptr) noexcept {}
        IAppointmentCalendarUpdateMeetingResponseRequestEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentDataProviderConnection :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentDataProviderConnection>
    {
        IAppointmentDataProviderConnection(std::nullptr_t = nullptr) noexcept {}
        IAppointmentDataProviderConnection(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAppointmentDataProviderTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IAppointmentDataProviderTriggerDetails>
    {
        IAppointmentDataProviderTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IAppointmentDataProviderTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
