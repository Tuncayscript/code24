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
#ifndef LLM_OS_ApplicationModel_Activation_H
#define LLM_OS_ApplicationModel_Activation_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.ApplicationModel.Appointments.AppointmentsProvider.2.h"
#include "llm/impl/Windows.ApplicationModel.Background.2.h"
#include "llm/impl/Windows.ApplicationModel.Calls.2.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.2.h"
#include "llm/impl/Windows.ApplicationModel.Contacts.Provider.2.h"
#include "llm/impl/Windows.ApplicationModel.DataTransfer.ShareTarget.2.h"
#include "llm/impl/Windows.ApplicationModel.Search.2.h"
#include "llm/impl/Windows.ApplicationModel.UserDataAccounts.Provider.2.h"
#include "llm/impl/Windows.ApplicationModel.Wallet.2.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Devices.Printers.Extensions.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Media.SpeechRecognition.2.h"
#include "llm/impl/Windows.Security.Authentication.Web.2.h"
#include "llm/impl/Windows.Security.Authentication.Web.Provider.2.h"
#include "llm/impl/Windows.Storage.2.h"
#include "llm/impl/Windows.Storage.Pickers.Provider.2.h"
#include "llm/impl/Windows.Storage.Provider.2.h"
#include "llm/impl/Windows.Storage.Search.2.h"
#include "llm/impl/Windows.System.2.h"
#include "llm/impl/Windows.UI.Notifications.2.h"
#include "llm/impl/Windows.UI.ViewManagement.2.h"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::ActivationKind) consume_Windows_ApplicationModel_Activation_IActivatedEventArgs<D>::Kind() const
    {
        llm::OS::ApplicationModel::Activation::ActivationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IActivatedEventArgs)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::ApplicationExecutionState) consume_Windows_ApplicationModel_Activation_IActivatedEventArgs<D>::PreviousExecutionState() const
    {
        llm::OS::ApplicationModel::Activation::ApplicationExecutionState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IActivatedEventArgs)->get_PreviousExecutionState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::SplashScreen) consume_Windows_ApplicationModel_Activation_IActivatedEventArgs<D>::SplashScreen() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IActivatedEventArgs)->get_SplashScreen(&value));
        return llm::OS::ApplicationModel::Activation::SplashScreen{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::User) consume_Windows_ApplicationModel_Activation_IActivatedEventArgsWithUser<D>::User() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser)->get_User(&value));
        return llm::OS::System::User{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Activation_IApplicationViewActivatedEventArgs<D>::CurrentlyShownApplicationViewId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs)->get_CurrentlyShownApplicationViewId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderActivatedEventArgs<D>::Verb() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs)->get_Verb(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderAddAppointmentActivatedEventArgs<D>::AddAppointmentOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs)->get_AddAppointmentOperation(&value));
        return llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderRemoveAppointmentActivatedEventArgs<D>::RemoveAppointmentOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs)->get_RemoveAppointmentOperation(&value));
        return llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderReplaceAppointmentActivatedEventArgs<D>::ReplaceAppointmentOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs)->get_ReplaceAppointmentOperation(&value));
        return llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>::InstanceStartDate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs)->get_InstanceStartDate(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>::LocalId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs)->get_LocalId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs<D>::RoamingId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs)->get_RoamingId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderShowTimeFrameActivatedEventArgs<D>::TimeToShow() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs)->get_TimeToShow(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_Activation_IAppointmentsProviderShowTimeFrameActivatedEventArgs<D>::Duration() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs)->get_Duration(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::IBackgroundTaskInstance) consume_Windows_ApplicationModel_Activation_IBackgroundActivatedEventArgs<D>::TaskInstance() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs)->get_TaskInstance(&value));
        return llm::OS::ApplicationModel::Background::IBackgroundTaskInstance{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IBarcodeScannerPreviewActivatedEventArgs<D>::ConnectionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs)->get_ConnectionId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Provider::CachedFileUpdaterUI) consume_Windows_ApplicationModel_Activation_ICachedFileUpdaterActivatedEventArgs<D>::CachedFileUpdaterUI() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs)->get_CachedFileUpdaterUI(&value));
        return llm::OS::Storage::Provider::CachedFileUpdaterUI{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_Activation_ICameraSettingsActivatedEventArgs<D>::VideoDeviceController() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs)->get_VideoDeviceController(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_Activation_ICameraSettingsActivatedEventArgs<D>::VideoDeviceExtension() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs)->get_VideoDeviceExtension(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::CommandLineActivationOperation) consume_Windows_ApplicationModel_Activation_ICommandLineActivatedEventArgs<D>::Operation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs)->get_Operation(&value));
        return llm::OS::ApplicationModel::Activation::CommandLineActivationOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_ICommandLineActivationOperation<D>::Arguments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation)->get_Arguments(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_ICommandLineActivationOperation<D>::CurrentDirectoryPath() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation)->get_CurrentDirectoryPath(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Activation_ICommandLineActivationOperation<D>::ExitCode(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation)->put_ExitCode(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_ApplicationModel_Activation_ICommandLineActivationOperation<D>::ExitCode() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation)->get_ExitCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_ApplicationModel_Activation_ICommandLineActivationOperation<D>::GetDeferral() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation)->GetDeferral(&value));
        return llm::OS::Foundation::Deferral{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactActivatedEventArgs<D>::Verb() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs)->get_Verb(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactCallActivatedEventArgs<D>::ServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs)->get_ServiceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactCallActivatedEventArgs<D>::ServiceUserId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs)->get_ServiceUserId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Activation_IContactCallActivatedEventArgs<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactAddress) consume_Windows_ApplicationModel_Activation_IContactMapActivatedEventArgs<D>::Address() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs)->get_Address(&value));
        return llm::OS::ApplicationModel::Contacts::ContactAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Activation_IContactMapActivatedEventArgs<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactMessageActivatedEventArgs<D>::ServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs)->get_ServiceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactMessageActivatedEventArgs<D>::ServiceUserId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs)->get_ServiceUserId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Activation_IContactMessageActivatedEventArgs<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::ContactPanel) consume_Windows_ApplicationModel_Activation_IContactPanelActivatedEventArgs<D>::ContactPanel() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs)->get_ContactPanel(&value));
        return llm::OS::ApplicationModel::Contacts::ContactPanel{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Activation_IContactPanelActivatedEventArgs<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI) consume_Windows_ApplicationModel_Activation_IContactPickerActivatedEventArgs<D>::ContactPickerUI() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs)->get_ContactPickerUI(&value));
        return llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactPostActivatedEventArgs<D>::ServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs)->get_ServiceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactPostActivatedEventArgs<D>::ServiceUserId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs)->get_ServiceUserId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Activation_IContactPostActivatedEventArgs<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactVideoCallActivatedEventArgs<D>::ServiceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs)->get_ServiceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactVideoCallActivatedEventArgs<D>::ServiceUserId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs)->get_ServiceUserId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Contacts::Contact) consume_Windows_ApplicationModel_Activation_IContactVideoCallActivatedEventArgs<D>::Contact() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs)->get_Contact(&value));
        return llm::OS::ApplicationModel::Contacts::Contact{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IContactsProviderActivatedEventArgs<D>::Verb() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContactsProviderActivatedEventArgs)->get_Verb(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_Activation_IContinuationActivatedEventArgs<D>::ContinuationData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs)->get_ContinuationData(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IDeviceActivatedEventArgs<D>::DeviceInformationId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs)->get_DeviceInformationId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IDeviceActivatedEventArgs<D>::Verb() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs)->get_Verb(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_ApplicationModel_Activation_IDevicePairingActivatedEventArgs<D>::DeviceInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs)->get_DeviceInformation(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IDialReceiverActivatedEventArgs<D>::AppName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs)->get_AppName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>) consume_Windows_ApplicationModel_Activation_IFileActivatedEventArgs<D>::Files() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs)->get_Files(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IFileActivatedEventArgs<D>::Verb() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs)->get_Verb(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IFileActivatedEventArgsWithCallerPackageFamilyName<D>::CallerPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName)->get_CallerPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Search::StorageFileQueryResult) consume_Windows_ApplicationModel_Activation_IFileActivatedEventArgsWithNeighboringFiles<D>::NeighboringFilesQuery() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles)->get_NeighboringFilesQuery(&value));
        return llm::OS::Storage::Search::StorageFileQueryResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::FileOpenPickerUI) consume_Windows_ApplicationModel_Activation_IFileOpenPickerActivatedEventArgs<D>::FileOpenPickerUI() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs)->get_FileOpenPickerUI(&value));
        return llm::OS::Storage::Pickers::Provider::FileOpenPickerUI{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IFileOpenPickerActivatedEventArgs2<D>::CallerPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2)->get_CallerPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>) consume_Windows_ApplicationModel_Activation_IFileOpenPickerContinuationEventArgs<D>::Files() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs)->get_Files(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Pickers::Provider::FileSavePickerUI) consume_Windows_ApplicationModel_Activation_IFileSavePickerActivatedEventArgs<D>::FileSavePickerUI() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs)->get_FileSavePickerUI(&value));
        return llm::OS::Storage::Pickers::Provider::FileSavePickerUI{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IFileSavePickerActivatedEventArgs2<D>::CallerPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2)->get_CallerPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IFileSavePickerActivatedEventArgs2<D>::EnterpriseId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2)->get_EnterpriseId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFile) consume_Windows_ApplicationModel_Activation_IFileSavePickerContinuationEventArgs<D>::File() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs)->get_File(&value));
        return llm::OS::Storage::StorageFile{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::StorageFolder) consume_Windows_ApplicationModel_Activation_IFolderPickerContinuationEventArgs<D>::Folder() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs)->get_Folder(&value));
        return llm::OS::Storage::StorageFolder{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_ILaunchActivatedEventArgs<D>::Arguments() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs)->get_Arguments(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_ILaunchActivatedEventArgs<D>::TileId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs)->get_TileId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Activation::TileActivatedInfo) consume_Windows_ApplicationModel_Activation_ILaunchActivatedEventArgs2<D>::TileActivatedInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2)->get_TileActivatedInfo(&value));
        return llm::OS::ApplicationModel::Activation::TileActivatedInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_Activation_ILockScreenActivatedEventArgs<D>::Info() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs)->get_Info(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Calls::LockScreenCallUI) consume_Windows_ApplicationModel_Activation_ILockScreenCallActivatedEventArgs<D>::CallUI() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs)->get_CallUI(&value));
        return llm::OS::ApplicationModel::Calls::LockScreenCallUI{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_ApplicationModel_Activation_IPhoneCallActivatedEventArgs<D>::LineId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs)->get_LineId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IPickerReturnedActivatedEventArgs<D>::PickerOperationId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs)->get_PickerOperationId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_Activation_IPrelaunchActivatedEventArgs<D>::PrelaunchActivated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs)->get_PrelaunchActivated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Printers::Extensions::Print3DWorkflow) consume_Windows_ApplicationModel_Activation_IPrint3DWorkflowActivatedEventArgs<D>::Workflow() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs)->get_Workflow(&value));
        return llm::OS::Devices::Printers::Extensions::Print3DWorkflow{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Printers::Extensions::PrintTaskConfiguration) consume_Windows_ApplicationModel_Activation_IPrintTaskSettingsActivatedEventArgs<D>::Configuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs)->get_Configuration(&value));
        return llm::OS::Devices::Printers::Extensions::PrintTaskConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_ApplicationModel_Activation_IProtocolActivatedEventArgs<D>::Uri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs)->get_Uri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData<D>::CallerPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData)->get_CallerPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_Activation_IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData<D>::Data() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData)->get_Data(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::System::ProtocolForResultsOperation) consume_Windows_ApplicationModel_Activation_IProtocolForResultsActivatedEventArgs<D>::ProtocolForResultsOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs)->get_ProtocolForResultsOperation(&value));
        return llm::OS::System::ProtocolForResultsOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_Activation_IRestrictedLaunchActivatedEventArgs<D>::SharedContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs)->get_SharedContext(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_ISearchActivatedEventArgs<D>::QueryText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs)->get_QueryText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_ISearchActivatedEventArgs<D>::Language() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs)->get_Language(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails) consume_Windows_ApplicationModel_Activation_ISearchActivatedEventArgsWithLinguisticDetails<D>::LinguisticDetails() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails)->get_LinguisticDetails(&value));
        return llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::DataTransfer::ShareTarget::ShareOperation) consume_Windows_ApplicationModel_Activation_IShareTargetActivatedEventArgs<D>::ShareOperation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs)->get_ShareOperation(&value));
        return llm::OS::ApplicationModel::DataTransfer::ShareTarget::ShareOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Rect) consume_Windows_ApplicationModel_Activation_ISplashScreen<D>::ImageLocation() const
    {
        llm::OS::Foundation::Rect value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ISplashScreen)->get_ImageLocation(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_Activation_ISplashScreen<D>::Dismissed(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Activation::SplashScreen, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ISplashScreen)->add_Dismissed(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_ApplicationModel_Activation_ISplashScreen<D>::Dismissed_revoker consume_Windows_ApplicationModel_Activation_ISplashScreen<D>::Dismissed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Activation::SplashScreen, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Dismissed_revoker>(this, Dismissed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_Activation_ISplashScreen<D>::Dismissed(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ISplashScreen)->remove_Dismissed(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IStartupTaskActivatedEventArgs<D>::TaskId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs)->get_TaskId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Notifications::ShownTileNotification>) consume_Windows_ApplicationModel_Activation_ITileActivatedInfo<D>::RecentlyShownNotifications() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::ITileActivatedInfo)->get_RecentlyShownNotifications(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Notifications::ShownTileNotification>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IToastNotificationActivatedEventArgs<D>::Argument() const
    {
        void* argument{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs)->get_Argument(&argument));
        return hstring{ argument, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_ApplicationModel_Activation_IToastNotificationActivatedEventArgs<D>::UserInput() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs)->get_UserInput(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation) consume_Windows_ApplicationModel_Activation_IUserDataAccountProviderActivatedEventArgs<D>::Operation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs)->get_Operation(&value));
        return llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::ViewManagement::ActivationViewSwitcher) consume_Windows_ApplicationModel_Activation_IViewSwitcherProvider<D>::ViewSwitcher() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IViewSwitcherProvider)->get_ViewSwitcher(&value));
        return llm::OS::UI::ViewManagement::ActivationViewSwitcher{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::SpeechRecognition::SpeechRecognitionResult) consume_Windows_ApplicationModel_Activation_IVoiceCommandActivatedEventArgs<D>::Result() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs)->get_Result(&value));
        return llm::OS::Media::SpeechRecognition::SpeechRecognitionResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IWalletActionActivatedEventArgs<D>::ItemId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs)->get_ItemId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Wallet::WalletActionKind) consume_Windows_ApplicationModel_Activation_IWalletActionActivatedEventArgs<D>::ActionKind() const
    {
        llm::OS::ApplicationModel::Wallet::WalletActionKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs)->get_ActionKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_Activation_IWalletActionActivatedEventArgs<D>::ActionId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs)->get_ActionId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation) consume_Windows_ApplicationModel_Activation_IWebAccountProviderActivatedEventArgs<D>::Operation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs)->get_Operation(&value));
        return llm::OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Authentication::Web::WebAuthenticationResult) consume_Windows_ApplicationModel_Activation_IWebAuthenticationBrokerContinuationEventArgs<D>::WebAuthenticationResult() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs)->get_WebAuthenticationResult(&result));
        return llm::OS::Security::Authentication::Web::WebAuthenticationResult{ result, take_ownership_from_abi };
    }
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IActivatedEventArgs>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Activation::ActivationKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreviousExecutionState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Activation::ApplicationExecutionState>(this->shim().PreviousExecutionState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SplashScreen(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Activation::SplashScreen>(this->shim().SplashScreen());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser> : produce_base<D, llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        int32_t __stdcall get_User(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::User>(this->shim().User());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs>
    {
        int32_t __stdcall get_CurrentlyShownApplicationViewId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().CurrentlyShownApplicationViewId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs>
    {
        int32_t __stdcall get_Verb(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Verb());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs>
    {
        int32_t __stdcall get_AddAppointmentOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::AddAppointmentOperation>(this->shim().AddAppointmentOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs>
    {
        int32_t __stdcall get_RemoveAppointmentOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::RemoveAppointmentOperation>(this->shim().RemoveAppointmentOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs>
    {
        int32_t __stdcall get_ReplaceAppointmentOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Appointments::AppointmentsProvider::ReplaceAppointmentOperation>(this->shim().ReplaceAppointmentOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs>
    {
        int32_t __stdcall get_InstanceStartDate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().InstanceStartDate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LocalId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RoamingId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RoamingId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs>
    {
        int32_t __stdcall get_TimeToShow(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().TimeToShow());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Duration(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Duration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs>
    {
        int32_t __stdcall get_TaskInstance(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Background::IBackgroundTaskInstance>(this->shim().TaskInstance());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs>
    {
        int32_t __stdcall get_ConnectionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ConnectionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs>
    {
        int32_t __stdcall get_CachedFileUpdaterUI(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Provider::CachedFileUpdaterUI>(this->shim().CachedFileUpdaterUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs>
    {
        int32_t __stdcall get_VideoDeviceController(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().VideoDeviceController());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VideoDeviceExtension(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().VideoDeviceExtension());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs>
    {
        int32_t __stdcall get_Operation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Activation::CommandLineActivationOperation>(this->shim().Operation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation> : produce_base<D, llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation>
    {
        int32_t __stdcall get_Arguments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Arguments());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentDirectoryPath(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CurrentDirectoryPath());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExitCode(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExitCode(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExitCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ExitCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs>
    {
        int32_t __stdcall get_Verb(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Verb());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs>
    {
        int32_t __stdcall get_ServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceUserId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceUserId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs>
    {
        int32_t __stdcall get_Address(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::ContactAddress>(this->shim().Address());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs>
    {
        int32_t __stdcall get_ServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceUserId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceUserId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs>
    {
        int32_t __stdcall get_ContactPanel(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::ContactPanel>(this->shim().ContactPanel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs>
    {
        int32_t __stdcall get_ContactPickerUI(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Provider::ContactPickerUI>(this->shim().ContactPickerUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs>
    {
        int32_t __stdcall get_ServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceUserId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceUserId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs>
    {
        int32_t __stdcall get_ServiceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceUserId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceUserId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Contact(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Contacts::Contact>(this->shim().Contact());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContactsProviderActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContactsProviderActivatedEventArgs>
    {
        int32_t __stdcall get_Verb(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Verb());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs>
    {
        int32_t __stdcall get_ContinuationData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().ContinuationData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs>
    {
        int32_t __stdcall get_DeviceInformationId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceInformationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Verb(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Verb());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs>
    {
        int32_t __stdcall get_DeviceInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().DeviceInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs>
    {
        int32_t __stdcall get_AppName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AppName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs>
    {
        int32_t __stdcall get_Files(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::IStorageItem>>(this->shim().Files());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Verb(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Verb());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName>
    {
        int32_t __stdcall get_CallerPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallerPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles>
    {
        int32_t __stdcall get_NeighboringFilesQuery(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Search::StorageFileQueryResult>(this->shim().NeighboringFilesQuery());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs>
    {
        int32_t __stdcall get_FileOpenPickerUI(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::FileOpenPickerUI>(this->shim().FileOpenPickerUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2>
    {
        int32_t __stdcall get_CallerPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallerPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs>
    {
        int32_t __stdcall get_Files(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Storage::StorageFile>>(this->shim().Files());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs>
    {
        int32_t __stdcall get_FileSavePickerUI(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Pickers::Provider::FileSavePickerUI>(this->shim().FileSavePickerUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2>
    {
        int32_t __stdcall get_CallerPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallerPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnterpriseId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EnterpriseId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs>
    {
        int32_t __stdcall get_File(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFile>(this->shim().File());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs>
    {
        int32_t __stdcall get_Folder(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::StorageFolder>(this->shim().Folder());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs>
    {
        int32_t __stdcall get_Arguments(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Arguments());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TileId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TileId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2> : produce_base<D, llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2>
    {
        int32_t __stdcall get_TileActivatedInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Activation::TileActivatedInfo>(this->shim().TileActivatedInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs>
    {
        int32_t __stdcall get_Info(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().Info());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs>
    {
        int32_t __stdcall get_CallUI(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Calls::LockScreenCallUI>(this->shim().CallUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs>
    {
        int32_t __stdcall get_LineId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().LineId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs>
    {
        int32_t __stdcall get_PickerOperationId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PickerOperationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs>
    {
        int32_t __stdcall get_PrelaunchActivated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().PrelaunchActivated());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs>
    {
        int32_t __stdcall get_Workflow(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Printers::Extensions::Print3DWorkflow>(this->shim().Workflow());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs>
    {
        int32_t __stdcall get_Configuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Printers::Extensions::PrintTaskConfiguration>(this->shim().Configuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs>
    {
        int32_t __stdcall get_Uri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().Uri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData> : produce_base<D, llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData>
    {
        int32_t __stdcall get_CallerPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallerPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Data(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs>
    {
        int32_t __stdcall get_ProtocolForResultsOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::System::ProtocolForResultsOperation>(this->shim().ProtocolForResultsOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs>
    {
        int32_t __stdcall get_SharedContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().SharedContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs>
    {
        int32_t __stdcall get_QueryText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().QueryText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Language(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Language());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails> : produce_base<D, llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails>
    {
        int32_t __stdcall get_LinguisticDetails(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Search::SearchPaneQueryLinguisticDetails>(this->shim().LinguisticDetails());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs>
    {
        int32_t __stdcall get_ShareOperation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::DataTransfer::ShareTarget::ShareOperation>(this->shim().ShareOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ISplashScreen> : produce_base<D, llm::OS::ApplicationModel::Activation::ISplashScreen>
    {
        int32_t __stdcall get_ImageLocation(llm::OS::Foundation::Rect* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::Rect>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Rect>(this->shim().ImageLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Dismissed(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Dismissed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::Activation::SplashScreen, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Dismissed(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Dismissed(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs>
    {
        int32_t __stdcall get_TaskId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().TaskId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::ITileActivatedInfo> : produce_base<D, llm::OS::ApplicationModel::Activation::ITileActivatedInfo>
    {
        int32_t __stdcall get_RecentlyShownNotifications(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::UI::Notifications::ShownTileNotification>>(this->shim().RecentlyShownNotifications());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs>
    {
        int32_t __stdcall get_Argument(void** argument) noexcept final try
        {
            clear_abi(argument);
            typename D::abi_guard guard(this->shim());
            *argument = detach_from<hstring>(this->shim().Argument());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserInput(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().UserInput());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs>
    {
        int32_t __stdcall get_Operation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::UserDataAccounts::Provider::IUserDataAccountProviderOperation>(this->shim().Operation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider> : produce_base<D, llm::OS::ApplicationModel::Activation::IViewSwitcherProvider>
    {
        int32_t __stdcall get_ViewSwitcher(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::ViewManagement::ActivationViewSwitcher>(this->shim().ViewSwitcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs>
    {
        int32_t __stdcall get_Result(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Media::SpeechRecognition::SpeechRecognitionResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs>
    {
        int32_t __stdcall get_ItemId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ItemId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActionKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::Wallet::WalletActionKind>(this->shim().ActionKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActionId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ActionId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs>
    {
        int32_t __stdcall get_Operation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Authentication::Web::Provider::IWebAccountProviderOperation>(this->shim().Operation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs> : produce_base<D, llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs>
    {
        int32_t __stdcall get_WebAuthenticationResult(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Security::Authentication::Web::WebAuthenticationResult>(this->shim().WebAuthenticationResult());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
}
LLM_EXPORT namespace llm::OS::ApplicationModel::Activation
{
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::Activation::IActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IActivatedEventArgsWithUser> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IApplicationViewActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IAppointmentsProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IAppointmentsProviderAddAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IAppointmentsProviderRemoveAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IAppointmentsProviderReplaceAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowAppointmentDetailsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IAppointmentsProviderShowTimeFrameActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IBackgroundActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IBarcodeScannerPreviewActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ICachedFileUpdaterActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ICameraSettingsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ICommandLineActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ICommandLineActivationOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactMapActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactMessageActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactPanelActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactPickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactPostActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactVideoCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContactsProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IContinuationActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IDeviceActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IDevicePairingActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IDialReceiverActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithCallerPackageFamilyName> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileActivatedEventArgsWithNeighboringFiles> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileOpenPickerActivatedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileOpenPickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileSavePickerActivatedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFileSavePickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IFolderPickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ILaunchActivatedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ILockScreenActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ILockScreenCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IPhoneCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IPickerReturnedActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IPrelaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IPrint3DWorkflowActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IPrintTaskSettingsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IProtocolActivatedEventArgsWithCallerPackageFamilyNameAndData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IProtocolForResultsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IRestrictedLaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ISearchActivatedEventArgsWithLinguisticDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IShareTargetActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ISplashScreen> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IStartupTaskActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ITileActivatedInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IToastNotificationActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IUserDataAccountProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IViewSwitcherProvider> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IVoiceCommandActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IWalletActionActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IWebAccountProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::IWebAuthenticationBrokerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::AppointmentsProviderAddAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::AppointmentsProviderRemoveAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::AppointmentsProviderReplaceAppointmentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::AppointmentsProviderShowAppointmentDetailsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::AppointmentsProviderShowTimeFrameActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::BackgroundActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::BarcodeScannerPreviewActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::CachedFileUpdaterActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::CameraSettingsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::CommandLineActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::CommandLineActivationOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactMapActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactMessageActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactPanelActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactPickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactPostActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ContactVideoCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::DeviceActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::DevicePairingActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::DialReceiverActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::FileActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::FileOpenPickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::FileOpenPickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::FileSavePickerActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::FileSavePickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::FolderPickerContinuationEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::LaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::LockScreenActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::LockScreenCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::LockScreenComponentActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::PhoneCallActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::PickerReturnedActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::Print3DWorkflowActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::PrintTaskSettingsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ProtocolActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ProtocolForResultsActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::RestrictedLaunchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::SearchActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ShareTargetActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::SplashScreen> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::StartupTaskActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::TileActivatedInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::ToastNotificationActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::UserDataAccountProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::VoiceCommandActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::WalletActionActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::WebAccountProviderActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::Activation::WebAuthenticationBrokerContinuationEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
