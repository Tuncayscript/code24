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
#ifndef LLM_OS_ApplicationModel_ConversationalAgent_H
#define LLM_OS_ApplicationModel_ConversationalAgent_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.ApplicationModel.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Media.Audio.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.ApplicationModel.ConversationalAgent.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::SignalId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_SignalId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ModelId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_ModelId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::IsActive() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_IsActive(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::SetEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->SetEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::SetEnabledAsync(bool value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->SetEnabledAsync(value, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::AvailabilityInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_AvailabilityInfo(&value));
        return llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::AvailabilityChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration, llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->add_AvailabilityChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::AvailabilityChanged_revoker consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::AvailabilityChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration, llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AvailabilityChanged_revoker>(this, AvailabilityChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::AvailabilityChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->remove_AvailabilityChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::SetModelData(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->SetModelData(*(void**)(&dataType), *(void**)(&data)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::SetModelDataAsync(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->SetModelDataAsync(*(void**)(&dataType), *(void**)(&data), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::GetModelDataType() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->GetModelDataType(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::GetModelDataTypeAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->GetModelDataTypeAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IInputStream) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::GetModelData() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->GetModelData(&result));
        return llm::OS::Storage::Streams::IInputStream{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::GetModelDataAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->GetModelDataAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ClearModelData() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->ClearModelData());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ClearModelDataAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->ClearModelDataAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::TrainingStepsCompleted() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_TrainingStepsCompleted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::TrainingStepsRemaining() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_TrainingStepsRemaining(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::TrainingDataFormat() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->get_TrainingDataFormat(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ApplyTrainingData(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat const& trainingDataFormat, llm::OS::Storage::Streams::IInputStream const& trainingData) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->ApplyTrainingData(static_cast<int32_t>(trainingDataFormat), *(void**)(&trainingData), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ApplyTrainingDataAsync(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat const& trainingDataFormat, llm::OS::Storage::Streams::IInputStream const& trainingData) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->ApplyTrainingDataAsync(static_cast<int32_t>(trainingDataFormat), *(void**)(&trainingData), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ClearTrainingData() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->ClearTrainingData());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration<D>::ClearTrainingDataAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration)->ClearTrainingDataAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2<D>::SetModelDataWithResult(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2)->SetModelDataWithResult(*(void**)(&dataType), *(void**)(&data), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2<D>::SetModelDataWithResultAsync(param::hstring const& dataType, llm::OS::Storage::Streams::IInputStream const& data) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2)->SetModelDataWithResultAsync(*(void**)(&dataType), *(void**)(&data), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2<D>::SetEnabledWithResultAsync(bool value) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2)->SetEnabledWithResultAsync(value, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2<D>::SetEnabledWithResult(bool value) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2)->SetEnabledWithResult(value, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfiguration2<D>::TrainingStepCompletionMaxAllowedTime() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2)->get_TrainingStepCompletionMaxAllowedTime(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationStatus) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfigurationCreationResult<D>::Status() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetectionConfigurationCreationResult<D>::Configuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult)->get_Configuration(&value));
        return llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::Kind() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::CanCreateConfigurations() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->get_CanCreateConfigurations(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::SupportedModelDataTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->get_SupportedModelDataTypes(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::SupportedTrainingDataFormats() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->get_SupportedTrainingDataFormats(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorPowerState>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::SupportedPowerStates() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->get_SupportedPowerStates(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorPowerState>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::GetSupportedModelIdsForSignalId(param::hstring const& signalId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->GetSupportedModelIdsForSignalId(*(void**)(&signalId), &result));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::GetSupportedModelIdsForSignalIdAsync(param::hstring const& signalId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->GetSupportedModelIdsForSignalIdAsync(*(void**)(&signalId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::CreateConfiguration(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->CreateConfiguration(*(void**)(&signalId), *(void**)(&modelId), *(void**)(&displayName)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::CreateConfigurationAsync(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->CreateConfigurationAsync(*(void**)(&signalId), *(void**)(&modelId), *(void**)(&displayName), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::GetConfigurations() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->GetConfigurations(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::GetConfigurationsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->GetConfigurationsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::GetConfiguration(param::hstring const& signalId, param::hstring const& modelId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->GetConfiguration(*(void**)(&signalId), *(void**)(&modelId), &result));
        return llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::GetConfigurationAsync(param::hstring const& signalId, param::hstring const& modelId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->GetConfigurationAsync(*(void**)(&signalId), *(void**)(&modelId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::RemoveConfiguration(param::hstring const& signalId, param::hstring const& modelId) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->RemoveConfiguration(*(void**)(&signalId), *(void**)(&modelId)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector<D>::RemoveConfigurationAsync(param::hstring const& signalId, param::hstring const& modelId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector)->RemoveConfigurationAsync(*(void**)(&signalId), *(void**)(&modelId), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<hstring>>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::GetAvailableModelIdsForSignalIdAsync(param::hstring const& signalId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->GetAvailableModelIdsForSignalIdAsync(*(void**)(&signalId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<hstring>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::GetAvailableModelIdsForSignalId(param::hstring const& signalId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->GetAvailableModelIdsForSignalId(*(void**)(&signalId), &result));
        return llm::OS::Foundation::Collections::IVector<hstring>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::CreateConfigurationWithResultAsync(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->CreateConfigurationWithResultAsync(*(void**)(&signalId), *(void**)(&modelId), *(void**)(&displayName), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::CreateConfigurationWithResult(param::hstring const& signalId, param::hstring const& modelId, param::hstring const& displayName) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->CreateConfigurationWithResult(*(void**)(&signalId), *(void**)(&modelId), *(void**)(&displayName), &result));
        return llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult>) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::RemoveConfigurationWithResultAsync(param::hstring const& signalId, param::hstring const& modelId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->RemoveConfigurationWithResultAsync(*(void**)(&signalId), *(void**)(&modelId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::RemoveConfigurationWithResult(param::hstring const& signalId, param::hstring const& modelId) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->RemoveConfigurationWithResult(*(void**)(&signalId), *(void**)(&modelId), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IActivationSignalDetector2<D>::DetectorId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2)->get_DetectorId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager<D>::GetAllActivationSignalDetectors() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager)->GetAllActivationSignalDetectors(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager<D>::GetAllActivationSignalDetectorsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager)->GetAllActivationSignalDetectorsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager<D>::GetActivationSignalDetectors(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind const& kind) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager)->GetActivationSignalDetectors(static_cast<int32_t>(kind), &result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager<D>::GetActivationSignalDetectorsAsync(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind const& kind) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager)->GetActivationSignalDetectorsAsync(static_cast<int32_t>(kind), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager2<D>::GetActivationSignalDetectorFromId(param::hstring const& detectorId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2)->GetActivationSignalDetectorFromId(*(void**)(&detectorId), &result));
        return llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManager2<D>::GetActivationSignalDetectorFromIdAsync(param::hstring const& detectorId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2)->GetActivationSignalDetectorFromIdAsync(*(void**)(&detectorId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentDetectorManagerStatics<D>::Default() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics)->get_Default(&value));
        return llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SessionInterrupted(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->add_SessionInterrupted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SessionInterrupted_revoker consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SessionInterrupted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SessionInterrupted_revoker>(this, SessionInterrupted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SessionInterrupted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->remove_SessionInterrupted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SignalDetected(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->add_SignalDetected(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SignalDetected_revoker consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SignalDetected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SignalDetected_revoker>(this, SignalDetected(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SignalDetected(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->remove_SignalDetected(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SystemStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->add_SystemStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SystemStateChanged_revoker consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SystemStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SystemStateChanged_revoker>(this, SystemStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SystemStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->remove_SystemStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::AgentState() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_AgentState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::Signal() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_Signal(&value));
        return llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::IsIndicatorLightAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_IsIndicatorLightAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::IsScreenAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_IsScreenAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::IsUserAuthenticated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_IsUserAuthenticated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::IsVoiceActivationAvailable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_IsVoiceActivationAvailable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::IsInterruptible() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_IsInterruptible(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::IsInterrupted() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->get_IsInterrupted(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::RequestInterruptibleAsync(bool interruptible) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->RequestInterruptibleAsync(interruptible, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::RequestInterruptible(bool interruptible) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->RequestInterruptible(interruptible, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::RequestAgentStateChangeAsync(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState const& state) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->RequestAgentStateChangeAsync(static_cast<int32_t>(state), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::RequestAgentStateChange(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState const& state) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->RequestAgentStateChange(static_cast<int32_t>(state), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::RequestForegroundActivationAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->RequestForegroundActivationAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::RequestForegroundActivation() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->RequestForegroundActivation(reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetAudioClientAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetAudioClientAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetAudioClient() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetAudioClient(&result));
        return llm::OS::Foundation::IInspectable{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Audio::AudioDeviceInputNode>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::CreateAudioDeviceInputNodeAsync(llm::OS::Media::Audio::AudioGraph const& graph) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->CreateAudioDeviceInputNodeAsync(*(void**)(&graph), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Audio::AudioDeviceInputNode>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Media::Audio::AudioDeviceInputNode) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::CreateAudioDeviceInputNode(llm::OS::Media::Audio::AudioGraph const& graph) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->CreateAudioDeviceInputNode(*(void**)(&graph), &result));
        return llm::OS::Media::Audio::AudioDeviceInputNode{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetAudioCaptureDeviceIdAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetAudioCaptureDeviceIdAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetAudioCaptureDeviceId() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetAudioCaptureDeviceId(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<hstring>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetAudioRenderDeviceIdAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetAudioRenderDeviceIdAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<hstring>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetAudioRenderDeviceId() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetAudioRenderDeviceId(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<uint32_t>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetSignalModelIdAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetSignalModelIdAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<uint32_t>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetSignalModelId() const
    {
        uint32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetSignalModelId(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SetSignalModelIdAsync(uint32_t signalModelId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->SetSignalModelIdAsync(signalModelId, &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::SetSignalModelId(uint32_t signalModelId) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->SetSignalModelId(signalModelId, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<uint32_t>>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetSupportedSignalModelIdsAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetSupportedSignalModelIdsAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<uint32_t>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession<D>::GetSupportedSignalModelIds() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession)->GetSupportedSignalModelIds(&result));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>::RequestActivationAsync(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind const& activationKind) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2)->RequestActivationAsync(static_cast<int32_t>(activationKind), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>::RequestActivation(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind const& activationKind) const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2)->RequestActivation(static_cast<int32_t>(activationKind), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>::SetSupportLockScreenActivationAsync(bool lockScreenActivationSupported) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2)->SetSupportLockScreenActivationAsync(lockScreenActivationSupported, &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>::SetSupportLockScreenActivation(bool lockScreenActivationSupported) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2)->SetSupportLockScreenActivation(lockScreenActivationSupported));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>::GetMissingPrerequisites() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2)->GetMissingPrerequisites(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSession2<D>::GetMissingPrerequisitesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2)->GetMissingPrerequisitesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSessionStatics<D>::GetCurrentSessionAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics)->GetCurrentSessionAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSessionStatics<D>::GetCurrentSessionSync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics)->GetCurrentSessionSync(&result));
        return llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::IsSignalVerificationRequired() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->get_IsSignalVerificationRequired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::IsSignalVerificationRequired(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->put_IsSignalVerificationRequired(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->get_SignalId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalId(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->put_SignalId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->get_SignalName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->put_SignalName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->get_SignalContext(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalContext(llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->put_SignalContext(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalStart() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->get_SignalStart(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalStart(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->put_SignalStart(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalEnd() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->get_SignalEnd(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal<D>::SignalEnd(llm::OS::Foundation::TimeSpan const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal)->put_SignalEnd(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal2<D>::DetectorId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2)->get_DetectorId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSignal2<D>::DetectorKind() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2)->get_DetectorKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangeType) consume_Windows_ApplicationModel_ConversationalAgent_IConversationalAgentSystemStateChangedEventArgs<D>::SystemStateChangeType() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangeType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs)->get_SystemStateChangeType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangeKind) consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityChangedEventArgs<D>::Kind() const
    {
        llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangeKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo<D>::HasSystemResourceAccess() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo)->get_HasSystemResourceAccess(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo<D>::HasPermission() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo)->get_HasPermission(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo<D>::HasLockScreenPermission() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo)->get_HasLockScreenPermission(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::SignalDetectorResourceKind>) consume_Windows_ApplicationModel_ConversationalAgent_IDetectionConfigurationAvailabilityInfo2<D>::UnavailableSystemResources() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2)->get_UnavailableSystemResources(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::SignalDetectorResourceKind>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration>
    {
        int32_t __stdcall get_SignalId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SignalId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ModelId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsActive(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsActive());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEnabledAsync(bool value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetEnabledAsync(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailabilityInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo>(this->shim().AvailabilityInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AvailabilityChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().AvailabilityChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration, llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailabilityChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailabilityChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall SetModelData(void* dataType, void* data) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetModelData(*reinterpret_cast<hstring const*>(&dataType), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&data));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetModelDataAsync(void* dataType, void* data, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetModelDataAsync(*reinterpret_cast<hstring const*>(&dataType), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetModelDataType(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetModelDataType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetModelDataTypeAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetModelDataTypeAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetModelData(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Streams::IInputStream>(this->shim().GetModelData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetModelDataAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Storage::Streams::IInputStream>>(this->shim().GetModelDataAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearModelData() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearModelData();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearModelDataAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ClearModelDataAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrainingStepsCompleted(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TrainingStepsCompleted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrainingStepsRemaining(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TrainingStepsRemaining());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrainingDataFormat(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat>(this->shim().TrainingDataFormat());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApplyTrainingData(int32_t trainingDataFormat, void* trainingData, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus>(this->shim().ApplyTrainingData(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat const*>(&trainingDataFormat), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&trainingData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApplyTrainingDataAsync(int32_t trainingDataFormat, void* trainingData, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationTrainingStatus>>(this->shim().ApplyTrainingDataAsync(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat const*>(&trainingDataFormat), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&trainingData)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearTrainingData() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearTrainingData();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearTrainingDataAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ClearTrainingDataAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2>
    {
        int32_t __stdcall SetModelDataWithResult(void* dataType, void* data, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult>(this->shim().SetModelDataWithResult(*reinterpret_cast<hstring const*>(&dataType), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetModelDataWithResultAsync(void* dataType, void* data, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationSetModelDataResult>>(this->shim().SetModelDataWithResultAsync(*reinterpret_cast<hstring const*>(&dataType), *reinterpret_cast<llm::OS::Storage::Streams::IInputStream const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEnabledWithResultAsync(bool value, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult>>(this->shim().SetEnabledWithResultAsync(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetEnabledWithResult(bool value, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationStateChangeResult>(this->shim().SetEnabledWithResult(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrainingStepCompletionMaxAllowedTime(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TrainingStepCompletionMaxAllowedTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Configuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>(this->shim().Configuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector>
    {
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanCreateConfigurations(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanCreateConfigurations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedModelDataTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().SupportedModelDataTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedTrainingDataFormats(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionTrainingDataFormat>>(this->shim().SupportedTrainingDataFormats());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedPowerStates(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorPowerState>>(this->shim().SupportedPowerStates());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedModelIdsForSignalId(void* signalId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().GetSupportedModelIdsForSignalId(*reinterpret_cast<hstring const*>(&signalId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedModelIdsForSignalIdAsync(void* signalId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<hstring>>>(this->shim().GetSupportedModelIdsForSignalIdAsync(*reinterpret_cast<hstring const*>(&signalId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateConfiguration(void* signalId, void* modelId, void* displayName) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CreateConfiguration(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId), *reinterpret_cast<hstring const*>(&displayName));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateConfigurationAsync(void* signalId, void* modelId, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().CreateConfigurationAsync(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetConfigurations(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>>(this->shim().GetConfigurations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetConfigurationsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>>>(this->shim().GetConfigurationsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetConfiguration(void* signalId, void* modelId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>(this->shim().GetConfiguration(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetConfigurationAsync(void* signalId, void* modelId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration>>(this->shim().GetConfigurationAsync(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveConfiguration(void* signalId, void* modelId) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemoveConfiguration(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveConfigurationAsync(void* signalId, void* modelId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RemoveConfigurationAsync(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2>
    {
        int32_t __stdcall GetAvailableModelIdsForSignalIdAsync(void* signalId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVector<hstring>>>(this->shim().GetAvailableModelIdsForSignalIdAsync(*reinterpret_cast<hstring const*>(&signalId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAvailableModelIdsForSignalId(void* signalId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().GetAvailableModelIdsForSignalId(*reinterpret_cast<hstring const*>(&signalId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateConfigurationWithResultAsync(void* signalId, void* modelId, void* displayName, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>>(this->shim().CreateConfigurationWithResultAsync(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateConfigurationWithResult(void* signalId, void* modelId, void* displayName, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult>(this->shim().CreateConfigurationWithResult(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId), *reinterpret_cast<hstring const*>(&displayName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveConfigurationWithResultAsync(void* signalId, void* modelId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult>>(this->shim().RemoveConfigurationWithResultAsync(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveConfigurationWithResult(void* signalId, void* modelId, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationRemovalResult>(this->shim().RemoveConfigurationWithResult(*reinterpret_cast<hstring const*>(&signalId), *reinterpret_cast<hstring const*>(&modelId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DetectorId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DetectorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager>
    {
        int32_t __stdcall GetAllActivationSignalDetectors(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>(this->shim().GetAllActivationSignalDetectors());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAllActivationSignalDetectorsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>>(this->shim().GetAllActivationSignalDetectorsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetActivationSignalDetectors(int32_t kind, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>(this->shim().GetActivationSignalDetectors(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetActivationSignalDetectorsAsync(int32_t kind, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>>(this->shim().GetActivationSignalDetectorsAsync(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2>
    {
        int32_t __stdcall GetActivationSignalDetectorFromId(void* detectorId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>(this->shim().GetActivationSignalDetectorFromId(*reinterpret_cast<hstring const*>(&detectorId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetActivationSignalDetectorFromIdAsync(void* detectorId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector>>(this->shim().GetActivationSignalDetectorFromIdAsync(*reinterpret_cast<hstring const*>(&detectorId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics>
    {
        int32_t __stdcall get_Default(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager>(this->shim().Default());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession>
    {
        int32_t __stdcall add_SessionInterrupted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SessionInterrupted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SessionInterrupted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SessionInterrupted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SignalDetected(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SignalDetected(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SignalDetected(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalDetected(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_SystemStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SystemStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession, llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SystemStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SystemStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_AgentState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState>(this->shim().AgentState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Signal(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal>(this->shim().Signal());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsIndicatorLightAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsIndicatorLightAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsScreenAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsScreenAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsUserAuthenticated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsUserAuthenticated());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsVoiceActivationAvailable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsVoiceActivationAvailable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInterruptible(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInterruptible());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInterrupted(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInterrupted());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestInterruptibleAsync(bool interruptible, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>>(this->shim().RequestInterruptibleAsync(interruptible));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestInterruptible(bool interruptible, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>(this->shim().RequestInterruptible(interruptible));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAgentStateChangeAsync(int32_t state, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>>(this->shim().RequestAgentStateChangeAsync(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState const*>(&state)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAgentStateChange(int32_t state, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>(this->shim().RequestAgentStateChange(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentState const*>(&state)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestForegroundActivationAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>>(this->shim().RequestForegroundActivationAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestForegroundActivation(int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionUpdateResponse>(this->shim().RequestForegroundActivation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioClientAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::IInspectable>>(this->shim().GetAudioClientAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioClient(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IInspectable>(this->shim().GetAudioClient());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAudioDeviceInputNodeAsync(void* graph, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Media::Audio::AudioDeviceInputNode>>(this->shim().CreateAudioDeviceInputNodeAsync(*reinterpret_cast<llm::OS::Media::Audio::AudioGraph const*>(&graph)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateAudioDeviceInputNode(void* graph, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Media::Audio::AudioDeviceInputNode>(this->shim().CreateAudioDeviceInputNode(*reinterpret_cast<llm::OS::Media::Audio::AudioGraph const*>(&graph)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioCaptureDeviceIdAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetAudioCaptureDeviceIdAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioCaptureDeviceId(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAudioCaptureDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioRenderDeviceIdAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<hstring>>(this->shim().GetAudioRenderDeviceIdAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetAudioRenderDeviceId(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetAudioRenderDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSignalModelIdAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<uint32_t>>(this->shim().GetSignalModelIdAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSignalModelId(uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<uint32_t>(this->shim().GetSignalModelId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSignalModelIdAsync(uint32_t signalModelId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().SetSignalModelIdAsync(signalModelId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSignalModelId(uint32_t signalModelId, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().SetSignalModelId(signalModelId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedSignalModelIdsAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<uint32_t>>>(this->shim().GetSupportedSignalModelIdsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSupportedSignalModelIds(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().GetSupportedSignalModelIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2>
    {
        int32_t __stdcall RequestActivationAsync(int32_t activationKind, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult>>(this->shim().RequestActivationAsync(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind const*>(&activationKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestActivation(int32_t activationKind, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationResult>(this->shim().RequestActivation(*reinterpret_cast<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentActivationKind const*>(&activationKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSupportLockScreenActivationAsync(bool lockScreenActivationSupported, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetSupportLockScreenActivationAsync(lockScreenActivationSupported));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetSupportLockScreenActivation(bool lockScreenActivationSupported) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetSupportLockScreenActivation(lockScreenActivationSupported);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMissingPrerequisites(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>>(this->shim().GetMissingPrerequisites());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMissingPrerequisitesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentVoiceActivationPrerequisiteKind>>>(this->shim().GetMissingPrerequisitesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics>
    {
        int32_t __stdcall GetCurrentSessionAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>>(this->shim().GetCurrentSessionAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentSessionSync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>(this->shim().GetCurrentSessionSync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal>
    {
        int32_t __stdcall get_IsSignalVerificationRequired(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSignalVerificationRequired());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsSignalVerificationRequired(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSignalVerificationRequired(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SignalId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SignalId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalId(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SignalName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SignalName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().SignalContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SignalContext(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalContext(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalStart(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SignalStart());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SignalStart(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalStart(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalEnd(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().SignalEnd());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SignalEnd(int64_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SignalEnd(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2>
    {
        int32_t __stdcall get_DetectorId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DetectorId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DetectorKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectorKind>(this->shim().DetectorKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs>
    {
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs>
    {
        int32_t __stdcall get_SystemStateChangeType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangeType>(this->shim().SystemStateChangeType());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangeKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasSystemResourceAccess(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasSystemResourceAccess());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasPermission(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasPermission());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasLockScreenPermission(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasLockScreenPermission());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2> : produce_base<D, llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2>
    {
        int32_t __stdcall get_UnavailableSystemResources(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::ApplicationModel::ConversationalAgent::SignalDetectorResourceKind>>(this->shim().UnavailableSystemResources());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::ApplicationModel::ConversationalAgent
{
    inline auto ConversationalAgentDetectorManager::Default()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager(*)(IConversationalAgentDetectorManagerStatics const&), ConversationalAgentDetectorManager, IConversationalAgentDetectorManagerStatics>([](IConversationalAgentDetectorManagerStatics const& f) { return f.Default(); });
    }
    inline auto ConversationalAgentSession::GetCurrentSessionAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession>(*)(IConversationalAgentSessionStatics const&), ConversationalAgentSession, IConversationalAgentSessionStatics>([](IConversationalAgentSessionStatics const& f) { return f.GetCurrentSessionAsync(); });
    }
    inline auto ConversationalAgentSession::GetCurrentSessionSync()
    {
        return impl::call_factory_cast<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession(*)(IConversationalAgentSessionStatics const&), ConversationalAgentSession, IConversationalAgentSessionStatics>([](IConversationalAgentSessionStatics const& f) { return f.GetCurrentSessionSync(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfiguration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetectionConfigurationCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IActivationSignalDetector2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManager2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentDetectorManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSession2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionInterruptedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSessionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignal2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSignalDetectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IConversationalAgentSystemStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::IDetectionConfigurationAvailabilityInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetectionConfigurationCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ActivationSignalDetector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentDetectorManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSessionInterruptedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignal> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSignalDetectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::ConversationalAgentSystemStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::ApplicationModel::ConversationalAgent::DetectionConfigurationAvailabilityInfo> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
