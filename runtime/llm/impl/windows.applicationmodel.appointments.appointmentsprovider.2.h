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
#ifndef LLM_OS_ApplicationModel_Appointments_AppointmentsProvider_2_H
#define LLM_OS_ApplicationModel_Appointments_AppointmentsProvider_2_H
#include "llm/impl/Windows.ApplicationModel.Appointments.AppointmentsProvider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments::AppointmentsProvider
{
    struct __declspec(empty_bases) AddAppointmentOperation : llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation
    {
        AddAppointmentOperation(std::nullptr_t) noexcept {}
        AddAppointmentOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation(ptr, take_ownership_from_abi) {}
    };
    struct AppointmentsProviderLaunchActionVerbs
    {
        AppointmentsProviderLaunchActionVerbs() = delete;
        [[nodiscard]] static auto AddAppointment();
        [[nodiscard]] static auto ReplaceAppointment();
        [[nodiscard]] static auto RemoveAppointment();
        [[nodiscard]] static auto ShowTimeFrame();
        [[nodiscard]] static auto ShowAppointmentDetails();
    };
    struct __declspec(empty_bases) RemoveAppointmentOperation : llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation
    {
        RemoveAppointmentOperation(std::nullptr_t) noexcept {}
        RemoveAppointmentOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ReplaceAppointmentOperation : llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation
    {
        ReplaceAppointmentOperation(std::nullptr_t) noexcept {}
        ReplaceAppointmentOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
