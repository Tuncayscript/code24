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
#ifndef LLM_OS_Management_Update_H
#define LLM_OS_Management_Update_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Management.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Management.Update.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IPreviewBuildsManager<D>::ArePreviewBuildsAllowed() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsManager)->get_ArePreviewBuildsAllowed(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IPreviewBuildsManager<D>::ArePreviewBuildsAllowed(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsManager)->put_ArePreviewBuildsAllowed(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::PreviewBuildsState) consume_Windows_Management_Update_IPreviewBuildsManager<D>::GetCurrentState() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsManager)->GetCurrentState(&result));
        return llm::OS::Management::Update::PreviewBuildsState{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Management_Update_IPreviewBuildsManager<D>::SyncAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsManager)->SyncAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<bool>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::PreviewBuildsManager) consume_Windows_Management_Update_IPreviewBuildsManagerStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsManagerStatics)->GetDefault(&value));
        return llm::OS::Management::Update::PreviewBuildsManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IPreviewBuildsManagerStatics<D>::IsSupported() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsManagerStatics)->IsSupported(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Management_Update_IPreviewBuildsState<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IPreviewBuildsState)->get_Properties(&value));
        return llm::OS::Foundation::Collections::ValueSet{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdate<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdate<D>::UpdateId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_UpdateId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdate<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdate<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsFeatureUpdate() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsFeatureUpdate(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsMinorImpact() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsMinorImpact(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsSecurity() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsSecurity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsCritical() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsCritical(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsForOS() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsForOS(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsDriver() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsDriver(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsMandatory() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsMandatory(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsUrgent() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsUrgent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsSeeker() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsSeeker(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Management_Update_IWindowsUpdate<D>::MoreInfoUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_MoreInfoUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Management_Update_IWindowsUpdate<D>::SupportUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_SupportUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdate<D>::IsEulaAccepted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_IsEulaAccepted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdate<D>::EulaText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_EulaText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Management_Update_IWindowsUpdate<D>::Deadline() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_Deadline(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAttentionRequiredInfo) consume_Windows_Management_Update_IWindowsUpdate<D>::AttentionRequiredInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_AttentionRequiredInfo(&value));
        return llm::OS::Management::Update::WindowsUpdateAttentionRequiredInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateActionResult) consume_Windows_Management_Update_IWindowsUpdate<D>::ActionResult() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_ActionResult(&value));
        return llm::OS::Management::Update::WindowsUpdateActionResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdate<D>::CurrentAction() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_CurrentAction(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateActionProgress) consume_Windows_Management_Update_IWindowsUpdate<D>::ActionProgress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->get_ActionProgress(&value));
        return llm::OS::Management::Update::WindowsUpdateActionProgress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Management_Update_IWindowsUpdate<D>::GetPropertyValue(param::hstring const& propertyName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->GetPropertyValue(*(void**)(&propertyName), &result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdate<D>::AcceptEula() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdate)->AcceptEula());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdate) consume_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs<D>::Update() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs)->get_Update(&value));
        return llm::OS::Management::Update::WindowsUpdate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs<D>::Action() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs)->get_Action(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Management_Update_IWindowsUpdateActionCompletedEventArgs<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateActionProgress<D>::Action() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionProgress)->get_Action(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Management_Update_IWindowsUpdateActionProgress<D>::Progress() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionProgress)->get_Progress(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Management_Update_IWindowsUpdateActionResult<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionResult)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdateActionResult<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionResult)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Management_Update_IWindowsUpdateActionResult<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionResult)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateActionResult<D>::Action() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateActionResult)->get_Action(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>::StartAdministratorScan() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministrator)->StartAdministratorScan());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>::ApproveWindowsUpdateAction(param::hstring const& updateId, param::hstring const& action) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministrator)->ApproveWindowsUpdateAction(*(void**)(&updateId), *(void**)(&action)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>::RevokeWindowsUpdateActionApproval(param::hstring const& updateId, param::hstring const& action) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministrator)->RevokeWindowsUpdateActionApproval(*(void**)(&updateId), *(void**)(&action)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>::ApproveWindowsUpdate(param::hstring const& updateId, llm::OS::Management::Update::WindowsUpdateApprovalData const& approvalData) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministrator)->ApproveWindowsUpdate(*(void**)(&updateId), *(void**)(&approvalData)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>::RevokeWindowsUpdateApproval(param::hstring const& updateId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministrator)->RevokeWindowsUpdateApproval(*(void**)(&updateId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>) consume_Windows_Management_Update_IWindowsUpdateAdministrator<D>::GetUpdates() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministrator)->GetUpdates(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateGetAdministratorResult) consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>::GetRegisteredAdministrator(param::hstring const& organizationName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministratorStatics)->GetRegisteredAdministrator(*(void**)(&organizationName), &result));
        return llm::OS::Management::Update::WindowsUpdateGetAdministratorResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAdministratorStatus) consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>::RegisterForAdministration(param::hstring const& organizationName, llm::OS::Management::Update::WindowsUpdateAdministratorOptions const& options) const
    {
        llm::OS::Management::Update::WindowsUpdateAdministratorStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministratorStatics)->RegisterForAdministration(*(void**)(&organizationName), static_cast<uint32_t>(options), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAdministratorStatus) consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>::UnregisterForAdministration(param::hstring const& organizationName) const
    {
        llm::OS::Management::Update::WindowsUpdateAdministratorStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministratorStatics)->UnregisterForAdministration(*(void**)(&organizationName), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>::GetRegisteredAdministratorName() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministratorStatics)->GetRegisteredAdministratorName(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>::RequestRestart(llm::OS::Management::Update::WindowsUpdateRestartRequestOptions const& restartOptions) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministratorStatics)->RequestRestart(*(void**)(&restartOptions), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateAdministratorStatics<D>::CancelRestartRequest(param::hstring const& requestRestartToken) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAdministratorStatics)->CancelRestartRequest(*(void**)(&requestRestartToken)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::Seeker() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->get_Seeker(&value));
        return llm::OS::Foundation::IReference<bool>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::Seeker(llm::OS::Foundation::IReference<bool> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->put_Seeker(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::AllowDownloadOnMetered() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->get_AllowDownloadOnMetered(&value));
        return llm::OS::Foundation::IReference<bool>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::AllowDownloadOnMetered(llm::OS::Foundation::IReference<bool> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->put_AllowDownloadOnMetered(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::ComplianceDeadlineInDays() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->get_ComplianceDeadlineInDays(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::ComplianceDeadlineInDays(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->put_ComplianceDeadlineInDays(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::ComplianceGracePeriodInDays() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->get_ComplianceGracePeriodInDays(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::ComplianceGracePeriodInDays(llm::OS::Foundation::IReference<int32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->put_ComplianceGracePeriodInDays(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<bool>) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::OptOutOfAutoReboot() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->get_OptOutOfAutoReboot(&value));
        return llm::OS::Foundation::IReference<bool>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateApprovalData<D>::OptOutOfAutoReboot(llm::OS::Foundation::IReference<bool> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateApprovalData)->put_OptOutOfAutoReboot(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAttentionRequiredReason) consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredInfo<D>::Reason() const
    {
        llm::OS::Management::Update::WindowsUpdateAttentionRequiredReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAttentionRequiredInfo)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredInfo<D>::Timestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAttentionRequiredInfo)->get_Timestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdate) consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredReasonChangedEventArgs<D>::Update() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs)->get_Update(&value));
        return llm::OS::Management::Update::WindowsUpdate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAttentionRequiredReason) consume_Windows_Management_Update_IWindowsUpdateAttentionRequiredReasonChangedEventArgs<D>::Reason() const
    {
        llm::OS::Management::Update::WindowsUpdateAttentionRequiredReason value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs)->get_Reason(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAdministrator) consume_Windows_Management_Update_IWindowsUpdateGetAdministratorResult<D>::Administrator() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateGetAdministratorResult)->get_Administrator(&value));
        return llm::OS::Management::Update::WindowsUpdateAdministrator{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateAdministratorStatus) consume_Windows_Management_Update_IWindowsUpdateGetAdministratorResult<D>::Status() const
    {
        llm::OS::Management::Update::WindowsUpdateAdministratorStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateGetAdministratorResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateItem<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateItem<D>::UpdateId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_UpdateId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Management_Update_IWindowsUpdateItem<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateItem<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateItem<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Management_Update_IWindowsUpdateItem<D>::MoreInfoUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_MoreInfoUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateItem<D>::Category() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_Category(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateItem<D>::Operation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateItem)->get_Operation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanningStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->add_ScanningStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanningStateChanged_revoker consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanningStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ScanningStateChanged_revoker>(this, ScanningStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanningStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->remove_ScanningStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Management_Update_IWindowsUpdateManager<D>::WorkingStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->add_WorkingStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Management_Update_IWindowsUpdateManager<D>::WorkingStateChanged_revoker consume_Windows_Management_Update_IWindowsUpdateManager<D>::WorkingStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, WorkingStateChanged_revoker>(this, WorkingStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::WorkingStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->remove_WorkingStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ProgressChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateProgressChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->add_ProgressChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Management_Update_IWindowsUpdateManager<D>::ProgressChanged_revoker consume_Windows_Management_Update_IWindowsUpdateManager<D>::ProgressChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateProgressChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ProgressChanged_revoker>(this, ProgressChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ProgressChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->remove_ProgressChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Management_Update_IWindowsUpdateManager<D>::AttentionRequiredReasonChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->add_AttentionRequiredReasonChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Management_Update_IWindowsUpdateManager<D>::AttentionRequiredReasonChanged_revoker consume_Windows_Management_Update_IWindowsUpdateManager<D>::AttentionRequiredReasonChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AttentionRequiredReasonChanged_revoker>(this, AttentionRequiredReasonChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::AttentionRequiredReasonChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->remove_AttentionRequiredReasonChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ActionCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateActionCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->add_ActionCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Management_Update_IWindowsUpdateManager<D>::ActionCompleted_revoker consume_Windows_Management_Update_IWindowsUpdateManager<D>::ActionCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateActionCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ActionCompleted_revoker>(this, ActionCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ActionCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->remove_ActionCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateScanCompletedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->add_ScanCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanCompleted_revoker consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateScanCompletedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ScanCompleted_revoker>(this, ScanCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::ScanCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->remove_ScanCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdateManager<D>::IsScanning() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->get_IsScanning(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdateManager<D>::IsWorking() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->get_IsWorking(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>) consume_Windows_Management_Update_IWindowsUpdateManager<D>::LastSuccessfulScanTimestamp() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->get_LastSuccessfulScanTimestamp(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>) consume_Windows_Management_Update_IWindowsUpdateManager<D>::GetApplicableUpdates() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->GetApplicableUpdates(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdateItem>) consume_Windows_Management_Update_IWindowsUpdateManager<D>::GetMostRecentCompletedUpdates(int32_t count) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->GetMostRecentCompletedUpdates(count, &result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdateItem>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdateItem>>) consume_Windows_Management_Update_IWindowsUpdateManager<D>::GetMostRecentCompletedUpdatesAsync(int32_t count) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->GetMostRecentCompletedUpdatesAsync(count, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdateItem>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateManager<D>::StartScan(bool userInitiated) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManager)->StartScan(userInitiated));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateManager) consume_Windows_Management_Update_IWindowsUpdateManagerFactory<D>::CreateInstance(param::hstring const& clientId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateManagerFactory)->CreateInstance(*(void**)(&clientId), &value));
        return llm::OS::Management::Update::WindowsUpdateManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdate) consume_Windows_Management_Update_IWindowsUpdateProgressChangedEventArgs<D>::Update() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateProgressChangedEventArgs)->get_Update(&value));
        return llm::OS::Management::Update::WindowsUpdate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateActionProgress) consume_Windows_Management_Update_IWindowsUpdateProgressChangedEventArgs<D>::ActionProgress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateProgressChangedEventArgs)->get_ActionProgress(&value));
        return llm::OS::Management::Update::WindowsUpdateActionProgress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::Description() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_Description(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::Description(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_Description(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::MoreInfoUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_MoreInfoUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::MoreInfoUrl(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_MoreInfoUrl(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::ComplianceDeadlineInDays() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_ComplianceDeadlineInDays(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::ComplianceDeadlineInDays(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_ComplianceDeadlineInDays(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::ComplianceGracePeriodInDays() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_ComplianceGracePeriodInDays(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::ComplianceGracePeriodInDays(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_ComplianceGracePeriodInDays(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::OrganizationName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_OrganizationName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::OrganizationName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_OrganizationName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::OptOutOfAutoReboot() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->get_OptOutOfAutoReboot(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptions<D>::OptOutOfAutoReboot(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions)->put_OptOutOfAutoReboot(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Management::Update::WindowsUpdateRestartRequestOptions) consume_Windows_Management_Update_IWindowsUpdateRestartRequestOptionsFactory<D>::CreateInstance(param::hstring const& title, param::hstring const& description, llm::OS::Foundation::Uri const& moreInfoUrl, int32_t complianceDeadlineInDays, int32_t complianceGracePeriodInDays) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory)->CreateInstance(*(void**)(&title), *(void**)(&description), *(void**)(&moreInfoUrl), complianceDeadlineInDays, complianceGracePeriodInDays, &value));
        return llm::OS::Management::Update::WindowsUpdateRestartRequestOptions{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs<D>::Succeeded() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs)->get_Succeeded(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::hresult) consume_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs<D>::ExtendedError() const
    {
        llm::hresult value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs)->get_ExtendedError(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>) consume_Windows_Management_Update_IWindowsUpdateScanCompletedEventArgs<D>::Updates() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs)->get_Updates(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IPreviewBuildsManager> : produce_base<D, llm::OS::Management::Update::IPreviewBuildsManager>
    {
        int32_t __stdcall get_ArePreviewBuildsAllowed(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ArePreviewBuildsAllowed());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ArePreviewBuildsAllowed(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ArePreviewBuildsAllowed(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentState(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::Update::PreviewBuildsState>(this->shim().GetCurrentState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SyncAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SyncAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IPreviewBuildsManagerStatics> : produce_base<D, llm::OS::Management::Update::IPreviewBuildsManagerStatics>
    {
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::PreviewBuildsManager>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsSupported(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IPreviewBuildsState> : produce_base<D, llm::OS::Management::Update::IPreviewBuildsState>
    {
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdate> : produce_base<D, llm::OS::Management::Update::IWindowsUpdate>
    {
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UpdateId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsFeatureUpdate(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsFeatureUpdate());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMinorImpact(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMinorImpact());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSecurity(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSecurity());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsCritical(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsCritical());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsForOS(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsForOS());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDriver(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDriver());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMandatory(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMandatory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsUrgent(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsUrgent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSeeker(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSeeker());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MoreInfoUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().MoreInfoUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().SupportUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEulaAccepted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEulaAccepted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EulaText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EulaText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Deadline(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().Deadline());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AttentionRequiredInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateAttentionRequiredInfo>(this->shim().AttentionRequiredInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActionResult(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateActionResult>(this->shim().ActionResult());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentAction(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CurrentAction());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActionProgress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateActionProgress>(this->shim().ActionProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPropertyValue(void* propertyName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetPropertyValue(*reinterpret_cast<hstring const*>(&propertyName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcceptEula() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptEula();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs>
    {
        int32_t __stdcall get_Update(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdate>(this->shim().Update());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Action(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Action());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateActionProgress> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateActionProgress>
    {
        int32_t __stdcall get_Action(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Action());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Progress(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().Progress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateActionResult> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateActionResult>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Action(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Action());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateAdministrator> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateAdministrator>
    {
        int32_t __stdcall StartAdministratorScan() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartAdministratorScan();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApproveWindowsUpdateAction(void* updateId, void* action) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApproveWindowsUpdateAction(*reinterpret_cast<hstring const*>(&updateId), *reinterpret_cast<hstring const*>(&action));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RevokeWindowsUpdateActionApproval(void* updateId, void* action) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RevokeWindowsUpdateActionApproval(*reinterpret_cast<hstring const*>(&updateId), *reinterpret_cast<hstring const*>(&action));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApproveWindowsUpdate(void* updateId, void* approvalData) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ApproveWindowsUpdate(*reinterpret_cast<hstring const*>(&updateId), *reinterpret_cast<llm::OS::Management::Update::WindowsUpdateApprovalData const*>(&approvalData));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RevokeWindowsUpdateApproval(void* updateId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RevokeWindowsUpdateApproval(*reinterpret_cast<hstring const*>(&updateId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUpdates(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>>(this->shim().GetUpdates());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateAdministratorStatics> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateAdministratorStatics>
    {
        int32_t __stdcall GetRegisteredAdministrator(void* organizationName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::Update::WindowsUpdateGetAdministratorResult>(this->shim().GetRegisteredAdministrator(*reinterpret_cast<hstring const*>(&organizationName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RegisterForAdministration(void* organizationName, uint32_t options, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::Update::WindowsUpdateAdministratorStatus>(this->shim().RegisterForAdministration(*reinterpret_cast<hstring const*>(&organizationName), *reinterpret_cast<llm::OS::Management::Update::WindowsUpdateAdministratorOptions const*>(&options)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnregisterForAdministration(void* organizationName, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Management::Update::WindowsUpdateAdministratorStatus>(this->shim().UnregisterForAdministration(*reinterpret_cast<hstring const*>(&organizationName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRegisteredAdministratorName(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetRegisteredAdministratorName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestRestart(void* restartOptions, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().RequestRestart(*reinterpret_cast<llm::OS::Management::Update::WindowsUpdateRestartRequestOptions const*>(&restartOptions)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CancelRestartRequest(void* requestRestartToken) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CancelRestartRequest(*reinterpret_cast<hstring const*>(&requestRestartToken));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateApprovalData> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateApprovalData>
    {
        int32_t __stdcall get_Seeker(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<bool>>(this->shim().Seeker());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Seeker(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Seeker(*reinterpret_cast<llm::OS::Foundation::IReference<bool> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowDownloadOnMetered(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<bool>>(this->shim().AllowDownloadOnMetered());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowDownloadOnMetered(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowDownloadOnMetered(*reinterpret_cast<llm::OS::Foundation::IReference<bool> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComplianceDeadlineInDays(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ComplianceDeadlineInDays());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ComplianceDeadlineInDays(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ComplianceDeadlineInDays(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComplianceGracePeriodInDays(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ComplianceGracePeriodInDays());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ComplianceGracePeriodInDays(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ComplianceGracePeriodInDays(*reinterpret_cast<llm::OS::Foundation::IReference<int32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OptOutOfAutoReboot(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<bool>>(this->shim().OptOutOfAutoReboot());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OptOutOfAutoReboot(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptOutOfAutoReboot(*reinterpret_cast<llm::OS::Foundation::IReference<bool> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateAttentionRequiredInfo> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateAttentionRequiredInfo>
    {
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateAttentionRequiredReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs>
    {
        int32_t __stdcall get_Update(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdate>(this->shim().Update());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Reason(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateAttentionRequiredReason>(this->shim().Reason());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateGetAdministratorResult> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateGetAdministratorResult>
    {
        int32_t __stdcall get_Administrator(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateAdministrator>(this->shim().Administrator());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateAdministratorStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateItem> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateItem>
    {
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().UpdateId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MoreInfoUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().MoreInfoUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Category(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Category());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Operation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Operation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateManager> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateManager>
    {
        int32_t __stdcall add_ScanningStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ScanningStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ScanningStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScanningStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_WorkingStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().WorkingStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_WorkingStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WorkingStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ProgressChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ProgressChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateProgressChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ProgressChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProgressChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_AttentionRequiredReasonChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AttentionRequiredReasonChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AttentionRequiredReasonChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AttentionRequiredReasonChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ActionCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ActionCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateActionCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ActionCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActionCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_ScanCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ScanCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Management::Update::WindowsUpdateManager, llm::OS::Management::Update::WindowsUpdateScanCompletedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ScanCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ScanCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_IsScanning(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsScanning());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsWorking(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsWorking());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LastSuccessfulScanTimestamp(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::DateTime>>(this->shim().LastSuccessfulScanTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetApplicableUpdates(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>>(this->shim().GetApplicableUpdates());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMostRecentCompletedUpdates(int32_t count, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdateItem>>(this->shim().GetMostRecentCompletedUpdates(count));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMostRecentCompletedUpdatesAsync(int32_t count, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdateItem>>>(this->shim().GetMostRecentCompletedUpdatesAsync(count));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartScan(bool userInitiated) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartScan(userInitiated);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateManagerFactory> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateManagerFactory>
    {
        int32_t __stdcall CreateInstance(void* clientId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateManager>(this->shim().CreateInstance(*reinterpret_cast<hstring const*>(&clientId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateProgressChangedEventArgs> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateProgressChangedEventArgs>
    {
        int32_t __stdcall get_Update(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdate>(this->shim().Update());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActionProgress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateActionProgress>(this->shim().ActionProgress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions>
    {
        int32_t __stdcall get_Title(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Title());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Title(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Title(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Description(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Description());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Description(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Description(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MoreInfoUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().MoreInfoUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MoreInfoUrl(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MoreInfoUrl(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComplianceDeadlineInDays(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ComplianceDeadlineInDays());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ComplianceDeadlineInDays(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ComplianceDeadlineInDays(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ComplianceGracePeriodInDays(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ComplianceGracePeriodInDays());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ComplianceGracePeriodInDays(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ComplianceGracePeriodInDays(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OrganizationName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().OrganizationName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OrganizationName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OrganizationName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OptOutOfAutoReboot(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().OptOutOfAutoReboot());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OptOutOfAutoReboot(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptOutOfAutoReboot(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory>
    {
        int32_t __stdcall CreateInstance(void* title, void* description, void* moreInfoUrl, int32_t complianceDeadlineInDays, int32_t complianceGracePeriodInDays, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Management::Update::WindowsUpdateRestartRequestOptions>(this->shim().CreateInstance(*reinterpret_cast<hstring const*>(&title), *reinterpret_cast<hstring const*>(&description), *reinterpret_cast<llm::OS::Foundation::Uri const*>(&moreInfoUrl), complianceDeadlineInDays, complianceGracePeriodInDays));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs> : produce_base<D, llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs>
    {
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Succeeded(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Succeeded());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExtendedError(llm::hresult* value) noexcept final try
        {
            zero_abi<llm::hresult>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::hresult>(this->shim().ExtendedError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Updates(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Management::Update::WindowsUpdate>>(this->shim().Updates());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Management::Update
{
    constexpr auto operator|(WindowsUpdateAdministratorOptions const left, WindowsUpdateAdministratorOptions const right) noexcept
    {
        return static_cast<WindowsUpdateAdministratorOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(WindowsUpdateAdministratorOptions& left, WindowsUpdateAdministratorOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(WindowsUpdateAdministratorOptions const left, WindowsUpdateAdministratorOptions const right) noexcept
    {
        return static_cast<WindowsUpdateAdministratorOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(WindowsUpdateAdministratorOptions& left, WindowsUpdateAdministratorOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(WindowsUpdateAdministratorOptions const value) noexcept
    {
        return static_cast<WindowsUpdateAdministratorOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(WindowsUpdateAdministratorOptions const left, WindowsUpdateAdministratorOptions const right) noexcept
    {
        return static_cast<WindowsUpdateAdministratorOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(WindowsUpdateAdministratorOptions& left, WindowsUpdateAdministratorOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto PreviewBuildsManager::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Management::Update::PreviewBuildsManager(*)(IPreviewBuildsManagerStatics const&), PreviewBuildsManager, IPreviewBuildsManagerStatics>([](IPreviewBuildsManagerStatics const& f) { return f.GetDefault(); });
    }
    inline auto PreviewBuildsManager::IsSupported()
    {
        return impl::call_factory_cast<bool(*)(IPreviewBuildsManagerStatics const&), PreviewBuildsManager, IPreviewBuildsManagerStatics>([](IPreviewBuildsManagerStatics const& f) { return f.IsSupported(); });
    }
    inline auto WindowsUpdateAdministrator::GetRegisteredAdministrator(param::hstring const& organizationName)
    {
        return impl::call_factory<WindowsUpdateAdministrator, IWindowsUpdateAdministratorStatics>([&](IWindowsUpdateAdministratorStatics const& f) { return f.GetRegisteredAdministrator(organizationName); });
    }
    inline auto WindowsUpdateAdministrator::RegisterForAdministration(param::hstring const& organizationName, llm::OS::Management::Update::WindowsUpdateAdministratorOptions const& options)
    {
        return impl::call_factory<WindowsUpdateAdministrator, IWindowsUpdateAdministratorStatics>([&](IWindowsUpdateAdministratorStatics const& f) { return f.RegisterForAdministration(organizationName, options); });
    }
    inline auto WindowsUpdateAdministrator::UnregisterForAdministration(param::hstring const& organizationName)
    {
        return impl::call_factory<WindowsUpdateAdministrator, IWindowsUpdateAdministratorStatics>([&](IWindowsUpdateAdministratorStatics const& f) { return f.UnregisterForAdministration(organizationName); });
    }
    inline auto WindowsUpdateAdministrator::GetRegisteredAdministratorName()
    {
        return impl::call_factory_cast<hstring(*)(IWindowsUpdateAdministratorStatics const&), WindowsUpdateAdministrator, IWindowsUpdateAdministratorStatics>([](IWindowsUpdateAdministratorStatics const& f) { return f.GetRegisteredAdministratorName(); });
    }
    inline auto WindowsUpdateAdministrator::RequestRestart(llm::OS::Management::Update::WindowsUpdateRestartRequestOptions const& restartOptions)
    {
        return impl::call_factory<WindowsUpdateAdministrator, IWindowsUpdateAdministratorStatics>([&](IWindowsUpdateAdministratorStatics const& f) { return f.RequestRestart(restartOptions); });
    }
    inline auto WindowsUpdateAdministrator::CancelRestartRequest(param::hstring const& requestRestartToken)
    {
        impl::call_factory<WindowsUpdateAdministrator, IWindowsUpdateAdministratorStatics>([&](IWindowsUpdateAdministratorStatics const& f) { return f.CancelRestartRequest(requestRestartToken); });
    }
    inline WindowsUpdateApprovalData::WindowsUpdateApprovalData() :
        WindowsUpdateApprovalData(impl::call_factory_cast<WindowsUpdateApprovalData(*)(llm::OS::Foundation::IActivationFactory const&), WindowsUpdateApprovalData>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WindowsUpdateApprovalData>(); }))
    {
    }
    inline WindowsUpdateManager::WindowsUpdateManager(param::hstring const& clientId) :
        WindowsUpdateManager(impl::call_factory<WindowsUpdateManager, IWindowsUpdateManagerFactory>([&](IWindowsUpdateManagerFactory const& f) { return f.CreateInstance(clientId); }))
    {
    }
    inline WindowsUpdateRestartRequestOptions::WindowsUpdateRestartRequestOptions() :
        WindowsUpdateRestartRequestOptions(impl::call_factory_cast<WindowsUpdateRestartRequestOptions(*)(llm::OS::Foundation::IActivationFactory const&), WindowsUpdateRestartRequestOptions>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WindowsUpdateRestartRequestOptions>(); }))
    {
    }
    inline WindowsUpdateRestartRequestOptions::WindowsUpdateRestartRequestOptions(param::hstring const& title, param::hstring const& description, llm::OS::Foundation::Uri const& moreInfoUrl, int32_t complianceDeadlineInDays, int32_t complianceGracePeriodInDays) :
        WindowsUpdateRestartRequestOptions(impl::call_factory<WindowsUpdateRestartRequestOptions, IWindowsUpdateRestartRequestOptionsFactory>([&](IWindowsUpdateRestartRequestOptionsFactory const& f) { return f.CreateInstance(title, description, moreInfoUrl, complianceDeadlineInDays, complianceGracePeriodInDays); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Management::Update::IPreviewBuildsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IPreviewBuildsManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IPreviewBuildsState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateActionCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateActionProgress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateActionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateAdministrator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateAdministratorStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateApprovalData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateAttentionRequiredInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateAttentionRequiredReasonChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateGetAdministratorResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateManagerFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateProgressChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateRestartRequestOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateRestartRequestOptionsFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::IWindowsUpdateScanCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::PreviewBuildsManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::PreviewBuildsState> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateActionCompletedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateActionProgress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateActionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateAdministrator> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateApprovalData> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateAttentionRequiredInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateAttentionRequiredReasonChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateGetAdministratorResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateItem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateProgressChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateRestartRequestOptions> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Management::Update::WindowsUpdateScanCompletedEventArgs> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
