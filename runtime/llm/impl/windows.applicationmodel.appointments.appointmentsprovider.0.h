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
#ifndef LLM_OS_ApplicationModel_Appointments_AppointmentsProvider_0_H
#define LLM_OS_ApplicationModel_Appointments_AppointmentsProvider_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments
{
    struct Appointment;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    template <typename T> struct __declspec(empty_bases) IReference;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Appointments::AppointmentsProvider
{
    struct IAddAppointmentOperation;
    struct IAppointmentsProviderLaunchActionVerbsStatics;
    struct IAppointmentsProviderLaunchActionVerbsStatics2;
    struct IRemoveAppointmentOperation;
    struct IReplaceAppointmentOperation;
    struct AddAppointmentOperation;
    struct AppointmentsProviderLaunchActionVerbs;
    struct RemoveAppointmentOperation;
    struct ReplaceAppointmentOperation;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AppointmentsProviderLaunchActionVerbs>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation>{ using type = class_category; };
    template <> struct category<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.AddAppointmentOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AppointmentsProviderLaunchActionVerbs> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.AppointmentsProviderLaunchActionVerbs";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.RemoveAppointmentOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.ReplaceAppointmentOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.IAddAppointmentOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.IAppointmentsProviderLaunchActionVerbsStatics";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.IAppointmentsProviderLaunchActionVerbsStatics2";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.IRemoveAppointmentOperation";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation> = L"Windows.ApplicationModel.Appointments.AppointmentsProvider.IReplaceAppointmentOperation";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>{ 0xEC4A9AF3,0x620D,0x4C69,{ 0xAD,0xD7,0x97,0x94,0xE9,0x18,0x08,0x1F } }; // EC4A9AF3-620D-4C69-ADD7-9794E918081F
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>{ 0x36DBBA28,0x9E2E,0x49C6,{ 0x8E,0xF7,0x3A,0xB7,0xA5,0xDC,0xC8,0xB8 } }; // 36DBBA28-9E2E-49C6-8EF7-3AB7A5DCC8B8
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>{ 0xEF9049A4,0xAF21,0x473C,{ 0x88,0xDC,0x76,0xCD,0x89,0xF6,0x0C,0xA5 } }; // EF9049A4-AF21-473C-88DC-76CD89F60CA5
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>{ 0x08B66ABA,0xFE33,0x46CD,{ 0xA5,0x0C,0xA8,0xFF,0xB3,0x26,0x05,0x37 } }; // 08B66ABA-FE33-46CD-A50C-A8FFB3260537
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>{ 0xF4903D9B,0x9E61,0x4DE2,{ 0xA7,0x32,0x26,0x87,0xC0,0x7D,0x1D,0xE8 } }; // F4903D9B-9E61-4DE2-A732-2687C07D1DE8
    template <> struct default_interface<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation>{ using type = llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation; };
    template <> struct default_interface<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation>{ using type = llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation; };
    template <> struct default_interface<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation>{ using type = llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation; };
    template <> struct abi<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppointmentInformation(void**) noexcept = 0;
            virtual int32_t __stdcall get_SourcePackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall ReportCompleted(void*) noexcept = 0;
            virtual int32_t __stdcall ReportCanceled() noexcept = 0;
            virtual int32_t __stdcall ReportError(void*) noexcept = 0;
            virtual int32_t __stdcall DismissUI() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AddAppointment(void**) noexcept = 0;
            virtual int32_t __stdcall get_ReplaceAppointment(void**) noexcept = 0;
            virtual int32_t __stdcall get_RemoveAppointment(void**) noexcept = 0;
            virtual int32_t __stdcall get_ShowTimeFrame(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_ShowAppointmentDetails(void**) noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppointmentId(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstanceStartDate(void**) noexcept = 0;
            virtual int32_t __stdcall get_SourcePackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall ReportCompleted() noexcept = 0;
            virtual int32_t __stdcall ReportCanceled() noexcept = 0;
            virtual int32_t __stdcall ReportError(void*) noexcept = 0;
            virtual int32_t __stdcall DismissUI() noexcept = 0;
        };
    };
    template <> struct abi<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall get_AppointmentId(void**) noexcept = 0;
            virtual int32_t __stdcall get_AppointmentInformation(void**) noexcept = 0;
            virtual int32_t __stdcall get_InstanceStartDate(void**) noexcept = 0;
            virtual int32_t __stdcall get_SourcePackageFamilyName(void**) noexcept = 0;
            virtual int32_t __stdcall ReportCompleted(void*) noexcept = 0;
            virtual int32_t __stdcall ReportCanceled() noexcept = 0;
            virtual int32_t __stdcall ReportError(void*) noexcept = 0;
            virtual int32_t __stdcall DismissUI() noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation
    {
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::Appointment) AppointmentInformation() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourcePackageFamilyName() const;
        LLM_IMPL_AUTO(void) ReportCompleted(param::hstring const& itemId) const;
        LLM_IMPL_AUTO(void) ReportCanceled() const;
        LLM_IMPL_AUTO(void) ReportError(param::hstring const& value) const;
        LLM_IMPL_AUTO(void) DismissUI() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAddAppointmentOperation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAddAppointmentOperation<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AddAppointment() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ReplaceAppointment() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) RemoveAppointment() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ShowTimeFrame() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics2
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) ShowAppointmentDetails() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IAppointmentsProviderLaunchActionVerbsStatics2>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IAppointmentsProviderLaunchActionVerbsStatics2<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppointmentId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) InstanceStartDate() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourcePackageFamilyName() const;
        LLM_IMPL_AUTO(void) ReportCompleted() const;
        LLM_IMPL_AUTO(void) ReportCanceled() const;
        LLM_IMPL_AUTO(void) ReportError(param::hstring const& value) const;
        LLM_IMPL_AUTO(void) DismissUI() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IRemoveAppointmentOperation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IRemoveAppointmentOperation<D>;
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation
    {
        [[nodiscard]] LLM_IMPL_AUTO(hstring) AppointmentId() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::Appointment) AppointmentInformation() const;
        [[nodiscard]] LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) InstanceStartDate() const;
        [[nodiscard]] LLM_IMPL_AUTO(hstring) SourcePackageFamilyName() const;
        LLM_IMPL_AUTO(void) ReportCompleted(param::hstring const& itemId) const;
        LLM_IMPL_AUTO(void) ReportCanceled() const;
        LLM_IMPL_AUTO(void) ReportError(param::hstring const& value) const;
        LLM_IMPL_AUTO(void) DismissUI() const;
    };
    template <> struct consume<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::IReplaceAppointmentOperation>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_Appointments_AppointmentsProvider_IReplaceAppointmentOperation<D>;
    };
}
#endif
