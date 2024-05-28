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
#ifndef LLM_OS_Networking_NetworkOperators_H
#define LLM_OS_Networking_NetworkOperators_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Networking.h"
#include "llm/impl/Windows.Data.Xml.Dom.2.h"
#include "llm/impl/Windows.Devices.Sms.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Networking.Connectivity.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Networking.NetworkOperators.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IESim<D>::AvailableMemoryInBytes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->get_AvailableMemoryInBytes(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESim<D>::Eid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->get_Eid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESim<D>::FirmwareVersion() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->get_FirmwareVersion(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESim<D>::MobileBroadbandModemDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->get_MobileBroadbandModemDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimPolicy) consume_Windows_Networking_NetworkOperators_IESim<D>::Policy() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->get_Policy(&value));
        return llm::OS::Networking::NetworkOperators::ESimPolicy{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimState) consume_Windows_Networking_NetworkOperators_IESim<D>::State() const
    {
        llm::OS::Networking::NetworkOperators::ESimState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::ESimProfile>) consume_Windows_Networking_NetworkOperators_IESim<D>::GetProfiles() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->GetProfiles(&result));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::ESimProfile>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESim<D>::DeleteProfileAsync(param::hstring const& profileId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->DeleteProfileAsync(*(void**)(&profileId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDownloadProfileMetadataResult>) consume_Windows_Networking_NetworkOperators_IESim<D>::DownloadProfileMetadataAsync(param::hstring const& activationCode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->DownloadProfileMetadataAsync(*(void**)(&activationCode), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDownloadProfileMetadataResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESim<D>::ResetAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->ResetAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESim<D>::ProfileChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESim, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->add_ProfileChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESim<D>::ProfileChanged_revoker consume_Windows_Networking_NetworkOperators_IESim<D>::ProfileChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESim, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ProfileChanged_revoker>(this, ProfileChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESim<D>::ProfileChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim)->remove_ProfileChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimDiscoverResult) consume_Windows_Networking_NetworkOperators_IESim2<D>::Discover() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim2)->Discover(&result));
        return llm::OS::Networking::NetworkOperators::ESimDiscoverResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimDiscoverResult) consume_Windows_Networking_NetworkOperators_IESim2<D>::Discover(param::hstring const& serverAddress, param::hstring const& matchingId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim2)->DiscoverWithServerAddressAndMatchingId(*(void**)(&serverAddress), *(void**)(&matchingId), &result));
        return llm::OS::Networking::NetworkOperators::ESimDiscoverResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>) consume_Windows_Networking_NetworkOperators_IESim2<D>::DiscoverAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim2)->DiscoverAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>) consume_Windows_Networking_NetworkOperators_IESim2<D>::DiscoverAsync(param::hstring const& serverAddress, param::hstring const& matchingId) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim2)->DiscoverWithServerAddressAndMatchingIdAsync(*(void**)(&serverAddress), *(void**)(&matchingId), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IESim3<D>::SlotIndex() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESim3)->get_SlotIndex(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESim) consume_Windows_Networking_NetworkOperators_IESimAddedEventArgs<D>::ESim() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimAddedEventArgs)->get_ESim(&value));
        return llm::OS::Networking::NetworkOperators::ESim{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimDiscoverEvent<D>::MatchingId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDiscoverEvent)->get_MatchingId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimDiscoverEvent<D>::RspServerAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDiscoverEvent)->get_RspServerAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::ESimDiscoverEvent>) consume_Windows_Networking_NetworkOperators_IESimDiscoverResult<D>::Events() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDiscoverResult)->get_Events(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::ESimDiscoverEvent>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimDiscoverResultKind) consume_Windows_Networking_NetworkOperators_IESimDiscoverResult<D>::Kind() const
    {
        llm::OS::Networking::NetworkOperators::ESimDiscoverResultKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDiscoverResult)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfileMetadata) consume_Windows_Networking_NetworkOperators_IESimDiscoverResult<D>::ProfileMetadata() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDiscoverResult)->get_ProfileMetadata(&value));
        return llm::OS::Networking::NetworkOperators::ESimProfileMetadata{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimOperationResult) consume_Windows_Networking_NetworkOperators_IESimDiscoverResult<D>::Result() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDiscoverResult)->get_Result(&value));
        return llm::OS::Networking::NetworkOperators::ESimOperationResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimOperationResult) consume_Windows_Networking_NetworkOperators_IESimDownloadProfileMetadataResult<D>::Result() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult)->get_Result(&value));
        return llm::OS::Networking::NetworkOperators::ESimOperationResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfileMetadata) consume_Windows_Networking_NetworkOperators_IESimDownloadProfileMetadataResult<D>::ProfileMetadata() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult)->get_ProfileMetadata(&value));
        return llm::OS::Networking::NetworkOperators::ESimProfileMetadata{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimServiceInfo) consume_Windows_Networking_NetworkOperators_IESimManagerStatics<D>::ServiceInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimManagerStatics)->get_ServiceInfo(&value));
        return llm::OS::Networking::NetworkOperators::ESimServiceInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimWatcher) consume_Windows_Networking_NetworkOperators_IESimManagerStatics<D>::TryCreateESimWatcher() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimManagerStatics)->TryCreateESimWatcher(&result));
        return llm::OS::Networking::NetworkOperators::ESimWatcher{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimManagerStatics<D>::ServiceInfoChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimManagerStatics)->add_ServiceInfoChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimManagerStatics<D>::ServiceInfoChanged_revoker consume_Windows_Networking_NetworkOperators_IESimManagerStatics<D>::ServiceInfoChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ServiceInfoChanged_revoker>(this, ServiceInfoChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimManagerStatics<D>::ServiceInfoChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimManagerStatics)->remove_ServiceInfoChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimOperationStatus) consume_Windows_Networking_NetworkOperators_IESimOperationResult<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::ESimOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimOperationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IESimPolicy<D>::ShouldEnableManagingUi() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimPolicy)->get_ShouldEnableManagingUi(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfileClass) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::Class() const
    {
        llm::OS::Networking::NetworkOperators::ESimProfileClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_Class(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::Nickname() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_Nickname(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfilePolicy) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::Policy() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_Policy(&value));
        return llm::OS::Networking::NetworkOperators::ESimProfilePolicy{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::ProviderIcon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_ProviderIcon(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::ProviderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_ProviderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfileState) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::State() const
    {
        llm::OS::Networking::NetworkOperators::ESimProfileState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::DisableAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->DisableAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::EnableAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->EnableAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESimProfile<D>::SetNicknameAsync(param::hstring const& newNickname) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfile)->SetNicknameAsync(*(void**)(&newNickname), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::IsConfirmationCodeRequired() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_IsConfirmationCodeRequired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfilePolicy) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::Policy() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_Policy(&value));
        return llm::OS::Networking::NetworkOperators::ESimProfilePolicy{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IRandomAccessStreamReference) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::ProviderIcon() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_ProviderIcon(&value));
        return llm::OS::Storage::Streams::IRandomAccessStreamReference{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::ProviderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_ProviderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimProfileMetadataState) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::State() const
    {
        llm::OS::Networking::NetworkOperators::ESimProfileMetadataState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::DenyInstallAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->DenyInstallAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::NetworkOperators::ESimOperationResult, llm::OS::Networking::NetworkOperators::ESimProfileInstallProgress>) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::ConfirmInstallAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->ConfirmInstallAsync(&operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::NetworkOperators::ESimOperationResult, llm::OS::Networking::NetworkOperators::ESimProfileInstallProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::NetworkOperators::ESimOperationResult, llm::OS::Networking::NetworkOperators::ESimProfileInstallProgress>) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::ConfirmInstallAsync(param::hstring const& confirmationCode) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->ConfirmInstallWithConfirmationCodeAsync(*(void**)(&confirmationCode), &operation));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::NetworkOperators::ESimOperationResult, llm::OS::Networking::NetworkOperators::ESimProfileInstallProgress>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::PostponeInstallAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->PostponeInstallAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::StateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimProfileMetadata, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->add_StateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::StateChanged_revoker consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::StateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimProfileMetadata, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, StateChanged_revoker>(this, StateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimProfileMetadata<D>::StateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfileMetadata)->remove_StateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IESimProfilePolicy<D>::CanDelete() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfilePolicy)->get_CanDelete(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IESimProfilePolicy<D>::CanDisable() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfilePolicy)->get_CanDisable(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IESimProfilePolicy<D>::IsManagedByEnterprise() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimProfilePolicy)->get_IsManagedByEnterprise(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESim) consume_Windows_Networking_NetworkOperators_IESimRemovedEventArgs<D>::ESim() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimRemovedEventArgs)->get_ESim(&value));
        return llm::OS::Networking::NetworkOperators::ESim{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimAuthenticationPreference) consume_Windows_Networking_NetworkOperators_IESimServiceInfo<D>::AuthenticationPreference() const
    {
        llm::OS::Networking::NetworkOperators::ESimAuthenticationPreference value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimServiceInfo)->get_AuthenticationPreference(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IESimServiceInfo<D>::IsESimUiEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimServiceInfo)->get_IsESimUiEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESim) consume_Windows_Networking_NetworkOperators_IESimUpdatedEventArgs<D>::ESim() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimUpdatedEventArgs)->get_ESim(&value));
        return llm::OS::Networking::NetworkOperators::ESim{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ESimWatcherStatus) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::ESimWatcherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimAddedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Added_revoker consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimAddedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::EnumerationCompleted_revoker consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimRemovedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Removed_revoker consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimRemovedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Stopped_revoker consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimUpdatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->add_Updated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Updated_revoker consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimUpdatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, Updated_revoker>(this, Updated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IESimWatcher<D>::Updated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IESimWatcher)->remove_Updated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Networking_NetworkOperators_IFdnAccessManagerStatics<D>::RequestUnlockAsync(param::hstring const& contactListId) const
    {
        void* returnValue{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IFdnAccessManagerStatics)->RequestUnlockAsync(*(void**)(&contactListId), &returnValue));
        return llm::OS::Foundation::IAsyncOperation<bool>{ returnValue, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(com_array<uint8_t>) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::WirelessNetworkId() const
    {
        uint32_t value_impl_size{};
        uint8_t* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->get_WirelessNetworkId(&value_impl_size, &value));
        return com_array<uint8_t>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Connectivity::NetworkAdapter) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::NetworkAdapter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->get_NetworkAdapter(&value));
        return llm::OS::Networking::Connectivity::NetworkAdapter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::RedirectMessageUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->get_RedirectMessageUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Xml::Dom::XmlDocument) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::RedirectMessageXml() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->get_RedirectMessageXml(&value));
        return llm::OS::Data::Xml::Dom::XmlDocument{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::AuthenticationUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->get_AuthenticationUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::IssueCredentials(param::hstring const& userName, param::hstring const& password, param::hstring const& extraParameters, bool markAsManualConnectOnFailure) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->IssueCredentials(*(void**)(&userName), *(void**)(&password), *(void**)(&extraParameters), markAsManualConnectOnFailure));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::AbortAuthentication(bool markAsManual) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->AbortAuthentication(markAsManual));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::SkipAuthentication() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->SkipAuthentication());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext<D>::TriggerAttentionRequired(param::hstring const& packageRelativeApplicationId, param::hstring const& applicationParameters) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext)->TriggerAttentionRequired(*(void**)(&packageRelativeApplicationId), *(void**)(&applicationParameters)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult>) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContext2<D>::IssueCredentialsAsync(param::hstring const& userName, param::hstring const& password, param::hstring const& extraParameters, bool markAsManualConnectOnFailure) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext2)->IssueCredentialsAsync(*(void**)(&userName), *(void**)(&password), *(void**)(&extraParameters), markAsManualConnectOnFailure, &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationContextStatics<D>::TryGetAuthenticationContext(param::hstring const& evenToken, llm::OS::Networking::NetworkOperators::HotspotAuthenticationContext& context) const
    {
        bool isValid{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContextStatics)->TryGetAuthenticationContext(*(void**)(&evenToken), impl::bind_out(context), &isValid));
        return isValid;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IHotspotAuthenticationEventDetails<D>::EventToken() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotAuthenticationEventDetails)->get_EventToken(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IHotspotCredentialsAuthenticationResult<D>::HasNetworkErrorOccurred() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult)->get_HasNetworkErrorOccurred(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::HotspotAuthenticationResponseCode) consume_Windows_Networking_NetworkOperators_IHotspotCredentialsAuthenticationResult<D>::ResponseCode() const
    {
        llm::OS::Networking::NetworkOperators::HotspotAuthenticationResponseCode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult)->get_ResponseCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_NetworkOperators_IHotspotCredentialsAuthenticationResult<D>::LogoffUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult)->get_LogoffUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Data::Xml::Dom::XmlDocument) consume_Windows_Networking_NetworkOperators_IHotspotCredentialsAuthenticationResult<D>::AuthenticationReplyXml() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult)->get_AuthenticationReplyXml(&value));
        return llm::OS::Data::Xml::Dom::XmlDocument{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownCSimFilePathsStatics<D>::EFSpn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownCSimFilePathsStatics)->get_EFSpn(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownCSimFilePathsStatics<D>::Gid1() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownCSimFilePathsStatics)->get_Gid1(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownCSimFilePathsStatics<D>::Gid2() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownCSimFilePathsStatics)->get_Gid2(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownRuimFilePathsStatics<D>::EFSpn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownRuimFilePathsStatics)->get_EFSpn(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownRuimFilePathsStatics<D>::Gid1() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownRuimFilePathsStatics)->get_Gid1(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownRuimFilePathsStatics<D>::Gid2() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownRuimFilePathsStatics)->get_Gid2(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownSimFilePathsStatics<D>::EFOns() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics)->get_EFOns(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownSimFilePathsStatics<D>::EFSpn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics)->get_EFSpn(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownSimFilePathsStatics<D>::Gid1() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics)->get_Gid1(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownSimFilePathsStatics<D>::Gid2() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics)->get_Gid2(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownUSimFilePathsStatics<D>::EFSpn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics)->get_EFSpn(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownUSimFilePathsStatics<D>::EFOpl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics)->get_EFOpl(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownUSimFilePathsStatics<D>::EFPnn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics)->get_EFPnn(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownUSimFilePathsStatics<D>::Gid1() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics)->get_Gid1(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IKnownUSimFilePathsStatics<D>::Gid2() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics)->get_Gid2(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount<D>::NetworkAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount)->get_NetworkAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount<D>::ServiceProviderGuid() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount)->get_ServiceProviderGuid(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount<D>::ServiceProviderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount)->get_ServiceProviderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount<D>::CurrentNetwork() const
    {
        void* network{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount)->get_CurrentNetwork(&network));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork{ network, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount<D>::CurrentDeviceInformation() const
    {
        void* deviceInformation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount)->get_CurrentDeviceInformation(&deviceInformation));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation{ deviceInformation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Connectivity::ConnectionProfile>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount2<D>::GetConnectionProfiles() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount2)->GetConnectionProfiles(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Connectivity::ConnectionProfile>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccount3<D>::AccountExperienceUrl() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount3)->get_AccountExperienceUrl(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountEventArgs<D>::NetworkAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs)->get_NetworkAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountStatics<D>::AvailableNetworkAccountIds() const
    {
        void* ppAccountIds{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountStatics)->get_AvailableNetworkAccountIds(&ppAccountIds));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ ppAccountIds, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandAccount) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountStatics<D>::CreateFromNetworkAccountId(param::hstring const& networkAccountId) const
    {
        void* ppAccount{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountStatics)->CreateFromNetworkAccountId(*(void**)(&networkAccountId), &ppAccount));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandAccount{ ppAccount, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountUpdatedEventArgs<D>::NetworkAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs)->get_NetworkAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountUpdatedEventArgs<D>::HasDeviceInformationChanged() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs)->get_HasDeviceInformationChanged(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountUpdatedEventArgs<D>::HasNetworkChanged() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs)->get_HasNetworkChanged(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountAdded(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->add_AccountAdded(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountAdded_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountAdded(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AccountAdded_revoker>(this, AccountAdded(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountAdded(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->remove_AccountAdded(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountUpdated(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->add_AccountUpdated(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountUpdated_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountUpdated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AccountUpdated_revoker>(this, AccountUpdated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountUpdated(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->remove_AccountUpdated(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountRemoved(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->add_AccountRemoved(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountRemoved_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountRemoved(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AccountRemoved_revoker>(this, AccountRemoved(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::AccountRemoved(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->remove_AccountRemoved(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::EnumerationCompleted(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->remove_EnumerationCompleted(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->add_Stopped(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Stopped_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Stopped(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->remove_Stopped(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAccountWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAntennaSar<D>::AntennaIndex() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar)->get_AntennaIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAntennaSar<D>::SarBackoffIndex() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar)->get_SarBackoffIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar) consume_Windows_Networking_NetworkOperators_IMobileBroadbandAntennaSarFactory<D>::CreateWithIndex(int32_t antennaIndex, int32_t sarBackoffIndex) const
    {
        void* antennaSar{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSarFactory)->CreateWithIndex(antennaIndex, sarBackoffIndex, &antennaSar));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar{ antennaSar, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::BaseStationId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_BaseStationId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::BaseStationPNCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_BaseStationPNCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::BaseStationLatitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_BaseStationLatitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::BaseStationLongitude() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_BaseStationLongitude(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::BaseStationLastBroadcastGpsTime() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_BaseStationLastBroadcastGpsTime(&value));
        return llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::NetworkId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_NetworkId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::PilotSignalStrengthInDB() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_PilotSignalStrengthInDB(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellCdma<D>::SystemId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma)->get_SystemId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::BaseStationId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_BaseStationId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::CellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_CellId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::ChannelNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_ChannelNumber(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::LocationAreaCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_LocationAreaCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::ReceivedSignalStrengthInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_ReceivedSignalStrengthInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellGsm<D>::TimingAdvanceInBitPeriods() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm)->get_TimingAdvanceInBitPeriods(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::CellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_CellId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::ChannelNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_ChannelNumber(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::PhysicalCellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_PhysicalCellId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::ReferenceSignalReceivedPowerInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_ReferenceSignalReceivedPowerInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::ReferenceSignalReceivedQualityInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_ReferenceSignalReceivedQualityInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::TimingAdvanceInBitPeriods() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_TimingAdvanceInBitPeriods(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellLte<D>::TrackingAreaCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte)->get_TrackingAreaCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int64_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::CellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_CellId(&value));
        return llm::OS::Foundation::IReference<int64_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::ChannelNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_ChannelNumber(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::PhysicalCellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_PhysicalCellId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::ReferenceSignalReceivedPowerInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_ReferenceSignalReceivedPowerInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::ReferenceSignalReceivedQualityInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_ReferenceSignalReceivedQualityInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::TimingAdvanceInNanoseconds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_TimingAdvanceInNanoseconds(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::TrackingAreaCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_TrackingAreaCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellNR<D>::SignalToNoiseRatioInDB() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR)->get_SignalToNoiseRatioInDB(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::CellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_CellId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::CellParameterId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_CellParameterId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::ChannelNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_ChannelNumber(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::LocationAreaCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_LocationAreaCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::PathLossInDB() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_PathLossInDB(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::ReceivedSignalCodePowerInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_ReceivedSignalCodePowerInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellTdscdma<D>::TimingAdvanceInBitPeriods() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma)->get_TimingAdvanceInBitPeriods(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::CellId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_CellId(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::ChannelNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_ChannelNumber(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::LocationAreaCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_LocationAreaCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::PathLossInDB() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_PathLossInDB(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::PrimaryScramblingCode() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_PrimaryScramblingCode(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::ProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_ProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::ReceivedSignalCodePowerInDBm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_ReceivedSignalCodePowerInDBm(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<double>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellUmts<D>::SignalToNoiseRatioInDB() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts)->get_SignalToNoiseRatioInDB(&value));
        return llm::OS::Foundation::IReference<double>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::NeighboringCellsCdma() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_NeighboringCellsCdma(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::NeighboringCellsGsm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_NeighboringCellsGsm(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::NeighboringCellsLte() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_NeighboringCellsLte(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::NeighboringCellsTdscdma() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_NeighboringCellsTdscdma(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::NeighboringCellsUmts() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_NeighboringCellsUmts(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::ServingCellsCdma() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_ServingCellsCdma(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::ServingCellsGsm() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_ServingCellsGsm(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::ServingCellsLte() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_ServingCellsLte(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::ServingCellsTdscdma() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_ServingCellsTdscdma(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo<D>::ServingCellsUmts() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo)->get_ServingCellsUmts(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo2<D>::NeighboringCellsNR() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo2)->get_NeighboringCellsNR(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCellsInfo2<D>::ServingCellsNR() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo2)->get_ServingCellsNR(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandCurrentSlotIndexChangedEventArgs<D>::CurrentSlotIndex() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandCurrentSlotIndexChangedEventArgs)->get_CurrentSlotIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkDeviceStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::NetworkDeviceStatus() const
    {
        llm::OS::Networking::NetworkOperators::NetworkDeviceStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_NetworkDeviceStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::Manufacturer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_Manufacturer(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::Model() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_Model(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::FirmwareInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_FirmwareInformation(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::CellularClass) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::CellularClass() const
    {
        llm::OS::Devices::Sms::CellularClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_CellularClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::DataClasses) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::DataClasses() const
    {
        llm::OS::Networking::NetworkOperators::DataClasses value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_DataClasses(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::CustomDataClass() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_CustomDataClass(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::MobileEquipmentId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_MobileEquipmentId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::TelephoneNumbers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_TelephoneNumbers(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::SubscriberId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_SubscriberId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::SimIccId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_SimIccId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceType) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::DeviceType() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceType pDeviceType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_DeviceType(reinterpret_cast<int32_t*>(&pDeviceType)));
        return pDeviceType;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandRadioState) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation<D>::CurrentRadioState() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandRadioState pCurrentState{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation)->get_CurrentRadioState(reinterpret_cast<int32_t*>(&pCurrentState)));
        return pCurrentState;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPinManager) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation2<D>::PinManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2)->get_PinManager(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandPinManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation2<D>::Revision() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2)->get_Revision(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation2<D>::SerialNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2)->get_SerialNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation3<D>::SimSpn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3)->get_SimSpn(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation3<D>::SimPnn() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3)->get_SimPnn(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation3<D>::SimGid1() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3)->get_SimGid1(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceInformation4<D>::SlotManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation4)->get_SlotManager(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceService<D>::DeviceServiceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService)->get_DeviceServiceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<uint32_t>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceService<D>::SupportedCommands() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService)->get_SupportedCommands(&value));
        return llm::OS::Foundation::Collections::IVectorView<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceService<D>::OpenDataSession() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService)->OpenDataSession(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandSession) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceService<D>::OpenCommandSession() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService)->OpenCommandSession(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandSession{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceCommandResult<D>::StatusCode() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult)->get_StatusCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceCommandResult<D>::ResponseData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult)->get_ResponseData(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceCommandSession<D>::SendQueryCommandAsync(uint32_t commandId, llm::OS::Storage::Streams::IBuffer const& data) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession)->SendQueryCommandAsync(commandId, *(void**)(&data), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceCommandSession<D>::SendSetCommandAsync(uint32_t commandId, llm::OS::Storage::Streams::IBuffer const& data) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession)->SendSetCommandAsync(commandId, *(void**)(&data), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceCommandSession<D>::CloseSession() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession)->CloseSession());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataReceivedEventArgs<D>::ReceivedData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs)->get_ReceivedData(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataSession<D>::WriteDataAsync(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession)->WriteDataAsync(*(void**)(&value), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataSession<D>::CloseSession() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession)->CloseSession());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession)->add_DataReceived(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> const& eventHandler) const
    {
        return impl::make_event_revoker<D, DataReceived_revoker>(this, DataReceived(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceDataSession<D>::DataReceived(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession)->remove_DataReceived(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceInformation<D>::DeviceServiceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation)->get_DeviceServiceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceInformation<D>::IsDataReadSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation)->get_IsDataReadSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceInformation<D>::IsDataWriteSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation)->get_IsDataWriteSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceTriggerDetails<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceTriggerDetails<D>::DeviceServiceId() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails)->get_DeviceServiceId(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceTriggerDetails<D>::ReceivedData() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails)->get_ReceivedData(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandDeviceServiceTriggerDetails2<D>::EventId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails2)->get_EventId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandAccount) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::CurrentAccount() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_CurrentAccount(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandAccount{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::DeviceInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_DeviceInformation(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::MaxDeviceServiceCommandSizeInBytes() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_MaxDeviceServiceCommandSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::MaxDeviceServiceDataSizeInBytes() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_MaxDeviceServiceDataSizeInBytes(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::DeviceServices() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_DeviceServices(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceService) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::GetDeviceService(llm::guid const& deviceServiceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->GetDeviceService(impl::bind_in(deviceServiceId), &value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceService{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::IsResetSupported() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_IsResetSupported(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::ResetAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->ResetAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemConfiguration>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::GetCurrentConfigurationAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->GetCurrentConfigurationAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemConfiguration>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem<D>::CurrentNetwork() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem)->get_CurrentNetwork(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem2<D>::GetIsPassthroughEnabledAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem2)->GetIsPassthroughEnabledAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<bool>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem2<D>::SetIsPassthroughEnabledAsync(bool value) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem2)->SetIsPassthroughEnabledAsync(value, &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPco>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem3<D>::TryGetPcoAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3)->TryGetPcoAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPco>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem3<D>::IsInEmergencyCallMode() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3)->get_IsInEmergencyCallMode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem3<D>::IsInEmergencyCallModeChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandModem, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3)->add_IsInEmergencyCallModeChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem3<D>::IsInEmergencyCallModeChanged_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem3<D>::IsInEmergencyCallModeChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandModem, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, IsInEmergencyCallModeChanged_revoker>(this, IsInEmergencyCallModeChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem3<D>::IsInEmergencyCallModeChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3)->remove_IsInEmergencyCallModeChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem4<D>::SetIsPassthroughEnabledAsync(bool value, int32_t slotindex) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4)->SetIsPassthroughEnabledWithSlotIndexAsync(value, slotindex, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem4<D>::GetIsPassthroughEnabledAsync(int32_t slotindex) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4)->GetIsPassthroughEnabledWithSlotIndexAsync(slotindex, &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem4<D>::SetIsPassthroughEnabled(bool value, int32_t slotindex) const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4)->SetIsPassthroughEnabledWithSlotIndex(value, slotindex, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModem4<D>::GetIsPassthroughEnabled(int32_t slotindex) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4)->GetIsPassthroughEnabledWithSlotIndex(slotindex, &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandUicc) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemConfiguration<D>::Uicc() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration)->get_Uicc(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandUicc{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemConfiguration<D>::HomeProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration)->get_HomeProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemConfiguration<D>::HomeProviderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration)->get_HomeProviderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemConfiguration2<D>::SarManager() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration2)->get_SarManager(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemIsolation<D>::AddAllowedHost(llm::OS::Networking::HostName const& host) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation)->AddAllowedHost(*(void**)(&host)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemIsolation<D>::AddAllowedHostRange(llm::OS::Networking::HostName const& first, llm::OS::Networking::HostName const& last) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation)->AddAllowedHostRange(*(void**)(&first), *(void**)(&last)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemIsolation<D>::ApplyConfigurationAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation)->ApplyConfigurationAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemIsolation<D>::ClearConfigurationAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation)->ClearConfigurationAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandModemIsolation) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemIsolationFactory<D>::Create(param::hstring const& modemDeviceId, param::hstring const& ruleGroupId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolationFactory)->Create(*(void**)(&modemDeviceId), *(void**)(&ruleGroupId), &result));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandModemIsolation{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemStatics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemStatics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandModem) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemStatics<D>::FromId(param::hstring const& deviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemStatics)->FromId(*(void**)(&deviceId), &value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandModem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandModem) consume_Windows_Networking_NetworkOperators_IMobileBroadbandModemStatics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandModemStatics)->GetDefault(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandModem{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Connectivity::NetworkAdapter) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::NetworkAdapter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_NetworkAdapter(&value));
        return llm::OS::Networking::Connectivity::NetworkAdapter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkRegistrationState) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::NetworkRegistrationState() const
    {
        llm::OS::Networking::NetworkOperators::NetworkRegistrationState registrationState{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_NetworkRegistrationState(reinterpret_cast<int32_t*>(&registrationState)));
        return registrationState;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::RegistrationNetworkError() const
    {
        uint32_t networkError{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_RegistrationNetworkError(&networkError));
        return networkError;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::PacketAttachNetworkError() const
    {
        uint32_t networkError{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_PacketAttachNetworkError(&networkError));
        return networkError;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::ActivationNetworkError() const
    {
        uint32_t networkError{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_ActivationNetworkError(&networkError));
        return networkError;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::AccessPointName() const
    {
        void* apn{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_AccessPointName(&apn));
        return hstring{ apn, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::DataClasses) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::RegisteredDataClass() const
    {
        llm::OS::Networking::NetworkOperators::DataClasses value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_RegisteredDataClass(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::RegisteredProviderId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_RegisteredProviderId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::RegisteredProviderName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->get_RegisteredProviderName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork<D>::ShowConnectionUI() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork)->ShowConnectionUI());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork2<D>::GetVoiceCallSupportAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork2)->GetVoiceCallSupportAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<bool>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork2<D>::RegistrationUiccApps() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork2)->get_RegistrationUiccApps(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandCellsInfo>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetwork3<D>::GetCellsInfoAsync() const
    {
        void* asyncOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork3)->GetCellsInfoAsync(&asyncOperation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandCellsInfo>{ asyncOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetworkRegistrationStateChange<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetworkRegistrationStateChange<D>::Network() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange)->get_Network(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails<D>::NetworkRegistrationStateChanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails)->get_NetworkRegistrationStateChanges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPco<D>::Data() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPco)->get_Data(&result));
        return llm::OS::Storage::Streams::IBuffer{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPco<D>::IsComplete() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPco)->get_IsComplete(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPco<D>::DeviceId() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPco)->get_DeviceId(&result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPco) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPcoDataChangeTriggerDetails<D>::UpdatedData() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPcoDataChangeTriggerDetails)->get_UpdatedData(&result));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandPco{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPinType) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::Type() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandPinType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockState) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::LockState() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_LockState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPinFormat) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::Format() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandPinFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::Enabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_Enabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::MaxLength() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_MaxLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::MinLength() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_MinLength(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::AttemptsRemaining() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->get_AttemptsRemaining(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::EnableAsync(param::hstring const& currentPin) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->EnableAsync(*(void**)(&currentPin), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::DisableAsync(param::hstring const& currentPin) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->DisableAsync(*(void**)(&currentPin), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::EnterAsync(param::hstring const& currentPin) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->EnterAsync(*(void**)(&currentPin), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::ChangeAsync(param::hstring const& currentPin, param::hstring const& newPin) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->ChangeAsync(*(void**)(&currentPin), *(void**)(&newPin), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPin<D>::UnblockAsync(param::hstring const& pinUnblockKey, param::hstring const& newPin) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPin)->UnblockAsync(*(void**)(&pinUnblockKey), *(void**)(&newPin), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinLockStateChange<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPinType) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinLockStateChange<D>::PinType() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandPinType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange)->get_PinType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockState) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinLockStateChange<D>::PinLockState() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange)->get_PinLockState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockStateChange>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinLockStateChangeTriggerDetails<D>::PinLockStateChanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails)->get_PinLockStateChanges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockStateChange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandPinType>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinManager<D>::SupportedPins() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinManager)->get_SupportedPins(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandPinType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandPin) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinManager<D>::GetPin(llm::OS::Networking::NetworkOperators::MobileBroadbandPinType const& pinType) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinManager)->GetPin(static_cast<int32_t>(pinType), &value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandPin{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinOperationResult<D>::IsSuccessful() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult)->get_IsSuccessful(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandPinOperationResult<D>::AttemptsRemaining() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult)->get_AttemptsRemaining(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandRadioStateChange<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandRadioState) consume_Windows_Networking_NetworkOperators_IMobileBroadbandRadioStateChange<D>::RadioState() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandRadioState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange)->get_RadioState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioStateChange>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandRadioStateChangeTriggerDetails<D>::RadioStateChanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails)->get_RadioStateChanges(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioStateChange>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::IsBackoffEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->get_IsBackoffEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::IsWiFiHardwareIntegrated() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->get_IsWiFiHardwareIntegrated(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::IsSarControlledByHardware() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->get_IsSarControlledByHardware(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::Antennas() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->get_Antennas(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::HysteresisTimerPeriod() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->get_HysteresisTimerPeriod(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::TransmissionStateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager, llm::OS::Networking::NetworkOperators::MobileBroadbandTransmissionStateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->add_TransmissionStateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::TransmissionStateChanged_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::TransmissionStateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager, llm::OS::Networking::NetworkOperators::MobileBroadbandTransmissionStateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, TransmissionStateChanged_revoker>(this, TransmissionStateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::TransmissionStateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->remove_TransmissionStateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::EnableBackoffAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->EnableBackoffAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::DisableBackoffAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->DisableBackoffAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::SetConfigurationAsync(param::async_iterable<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar> const& antennas) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->SetConfigurationAsync(*(void**)(&antennas), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::RevertSarToHardwareControlAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->RevertSarToHardwareControlAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::SetTransmissionStateChangedHysteresisAsync(llm::OS::Foundation::TimeSpan const& timerPeriod) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->SetTransmissionStateChangedHysteresisAsync(impl::bind_in(timerPeriod), &operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::GetIsTransmittingAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->GetIsTransmittingAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::StartTransmissionStateMonitoring() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->StartTransmissionStateMonitoring());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSarManager<D>::StopTransmissionStateMonitoring() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager)->StopTransmissionStateMonitoring());
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotInfo<D>::Index() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo)->get_Index(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandSlotState) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotInfo<D>::State() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandSlotState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotInfo2<D>::IccId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo2)->get_IccId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotInfoChangedEventArgs<D>::SlotInfo() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfoChangedEventArgs)->get_SlotInfo(&value));
        return llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SlotInfos() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->get_SlotInfos(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::CurrentSlotIndex() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->get_CurrentSlotIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SetCurrentSlot(int32_t slotIndex) const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->SetCurrentSlot(slotIndex, reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SetCurrentSlotAsync(int32_t slotIndex) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->SetCurrentSlotAsync(slotIndex, &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SlotInfoChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager, llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfoChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->add_SlotInfoChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SlotInfoChanged_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SlotInfoChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager, llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfoChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, SlotInfoChanged_revoker>(this, SlotInfoChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::SlotInfoChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->remove_SlotInfoChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::CurrentSlotIndexChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager, llm::OS::Networking::NetworkOperators::MobileBroadbandCurrentSlotIndexChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->add_CurrentSlotIndexChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::CurrentSlotIndexChanged_revoker consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::CurrentSlotIndexChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager, llm::OS::Networking::NetworkOperators::MobileBroadbandCurrentSlotIndexChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, CurrentSlotIndexChanged_revoker>(this, CurrentSlotIndexChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IMobileBroadbandSlotManager<D>::CurrentSlotIndexChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager)->remove_CurrentSlotIndexChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IMobileBroadbandTransmissionStateChangedEventArgs<D>::IsTransmitting() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandTransmissionStateChangedEventArgs)->get_IsTransmitting(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUicc<D>::SimIccId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUicc)->get_SimIccId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppsResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUicc<D>::GetUiccAppsAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUicc)->GetUiccAppsAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppsResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccApp<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp)->get_Id(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UiccAppKind) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccApp<D>::Kind() const
    {
        llm::OS::Networking::NetworkOperators::UiccAppKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccApp<D>::GetRecordDetailsAsync(param::async_iterable<uint32_t> const& uiccFilePath) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp)->GetRecordDetailsAsync(*(void**)(&uiccFilePath), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccApp<D>::ReadRecordAsync(param::async_iterable<uint32_t> const& uiccFilePath, int32_t recordIndex) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp)->ReadRecordAsync(*(void**)(&uiccFilePath), recordIndex, &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppReadRecordResult<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppReadRecordResult<D>::Data() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult)->get_Data(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppRecordDetailsResult<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UiccAppRecordKind) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppRecordDetailsResult<D>::Kind() const
    {
        llm::OS::Networking::NetworkOperators::UiccAppRecordKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppRecordDetailsResult<D>::RecordCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult)->get_RecordCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppRecordDetailsResult<D>::RecordSize() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult)->get_RecordSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UiccAccessCondition) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppRecordDetailsResult<D>::ReadAccessCondition() const
    {
        llm::OS::Networking::NetworkOperators::UiccAccessCondition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult)->get_ReadAccessCondition(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UiccAccessCondition) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppRecordDetailsResult<D>::WriteAccessCondition() const
    {
        llm::OS::Networking::NetworkOperators::UiccAccessCondition value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult)->get_WriteAccessCondition(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppsResult<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp>) consume_Windows_Networking_NetworkOperators_IMobileBroadbandUiccAppsResult<D>::UiccApps() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult)->get_UiccApps(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkOperatorDataUsageNotificationKind) consume_Windows_Networking_NetworkOperators_INetworkOperatorDataUsageTriggerDetails<D>::NotificationKind() const
    {
        llm::OS::Networking::NetworkOperators::NetworkOperatorDataUsageNotificationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorDataUsageTriggerDetails)->get_NotificationKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkOperatorEventMessageType) consume_Windows_Networking_NetworkOperators_INetworkOperatorNotificationEventDetails<D>::NotificationType() const
    {
        llm::OS::Networking::NetworkOperators::NetworkOperatorEventMessageType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails)->get_NotificationType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorNotificationEventDetails<D>::NetworkAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails)->get_NetworkAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Networking_NetworkOperators_INetworkOperatorNotificationEventDetails<D>::EncodingType() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails)->get_EncodingType(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorNotificationEventDetails<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails)->get_Message(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorNotificationEventDetails<D>::RuleId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails)->get_RuleId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::ISmsMessage) consume_Windows_Networking_NetworkOperators_INetworkOperatorNotificationEventDetails<D>::SmsMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails)->get_SmsMessage(&value));
        return llm::OS::Devices::Sms::ISmsMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration<D>::Ssid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration)->get_Ssid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration<D>::Ssid(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration)->put_Ssid(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration<D>::Passphrase() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration)->get_Passphrase(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration<D>::Passphrase(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration)->put_Passphrase(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration2<D>::IsBandSupported(llm::OS::Networking::NetworkOperators::TetheringWiFiBand const& band) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2)->IsBandSupported(static_cast<int32_t>(band), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<bool>) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration2<D>::IsBandSupportedAsync(llm::OS::Networking::NetworkOperators::TetheringWiFiBand const& band) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2)->IsBandSupportedAsync(static_cast<int32_t>(band), &operation));
        return llm::OS::Foundation::IAsyncOperation<bool>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::TetheringWiFiBand) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration2<D>::Band() const
    {
        llm::OS::Networking::NetworkOperators::TetheringWiFiBand value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2)->get_Band(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringAccessPointConfiguration2<D>::Band(llm::OS::Networking::NetworkOperators::TetheringWiFiBand const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2)->put_Band(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringClient<D>::MacAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClient)->get_MacAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringClient<D>::HostNames() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClient)->get_HostNames(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringClient>) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringClientManager<D>::GetTetheringClients() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClientManager)->GetTetheringClients(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringClient>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringEntitlementCheck<D>::AuthorizeTethering(bool allow, param::hstring const& entitlementFailureReason) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck)->AuthorizeTethering(allow, *(void**)(&entitlementFailureReason)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::MaxClientCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->get_MaxClientCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::ClientCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->get_ClientCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::TetheringOperationalState) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::TetheringOperationalState() const
    {
        llm::OS::Networking::NetworkOperators::TetheringOperationalState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->get_TetheringOperationalState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::GetCurrentAccessPointConfiguration() const
    {
        void* configuration{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->GetCurrentAccessPointConfiguration(&configuration));
        return llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration{ configuration, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::ConfigureAccessPointAsync(llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration const& configuration) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->ConfigureAccessPointAsync(*(void**)(&configuration), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::StartTetheringAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->StartTetheringAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManager<D>::StopTetheringAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager)->StopTetheringAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::TetheringCapability) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics<D>::GetTetheringCapability(param::hstring const& networkAccountId) const
    {
        llm::OS::Networking::NetworkOperators::TetheringCapability value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics)->GetTetheringCapability(*(void**)(&networkAccountId), reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics<D>::CreateFromNetworkAccountId(param::hstring const& networkAccountId) const
    {
        void* ppManager{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics)->CreateFromNetworkAccountId(*(void**)(&networkAccountId), &ppManager));
        return llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager{ ppManager, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::TetheringCapability) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics2<D>::GetTetheringCapabilityFromConnectionProfile(llm::OS::Networking::Connectivity::ConnectionProfile const& profile) const
    {
        llm::OS::Networking::NetworkOperators::TetheringCapability result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2)->GetTetheringCapabilityFromConnectionProfile(*(void**)(&profile), reinterpret_cast<int32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics2<D>::CreateFromConnectionProfile(llm::OS::Networking::Connectivity::ConnectionProfile const& profile) const
    {
        void* ppManager{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2)->CreateFromConnectionProfile(*(void**)(&profile), &ppManager));
        return llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager{ ppManager, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics3<D>::CreateFromConnectionProfile(llm::OS::Networking::Connectivity::ConnectionProfile const& profile, llm::OS::Networking::Connectivity::NetworkAdapter const& adapter) const
    {
        void* ppManager{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3)->CreateFromConnectionProfileWithTargetAdapter(*(void**)(&profile), *(void**)(&adapter), &ppManager));
        return llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager{ ppManager, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics4<D>::IsNoConnectionsTimeoutEnabled() const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4)->IsNoConnectionsTimeoutEnabled(&result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics4<D>::EnableNoConnectionsTimeout() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4)->EnableNoConnectionsTimeout());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics4<D>::EnableNoConnectionsTimeoutAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4)->EnableNoConnectionsTimeoutAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics4<D>::DisableNoConnectionsTimeout() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4)->DisableNoConnectionsTimeout());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringManagerStatics4<D>::DisableNoConnectionsTimeoutAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4)->DisableNoConnectionsTimeoutAsync(&operation));
        return llm::OS::Foundation::IAsyncAction{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::TetheringOperationStatus) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringOperationResult<D>::Status() const
    {
        llm::OS::Networking::NetworkOperators::TetheringOperationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_INetworkOperatorTetheringOperationResult<D>::AdditionalErrorMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult)->get_AdditionalErrorMessage(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_NetworkOperators_IProvisionFromXmlDocumentResults<D>::AllElementsProvisioned() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults)->get_AllElementsProvisioned(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IProvisionFromXmlDocumentResults<D>::ProvisionResultsXml() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults)->get_ProvisionResultsXml(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IProvisionedProfile<D>::UpdateCost(llm::OS::Networking::Connectivity::NetworkCostType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisionedProfile)->UpdateCost(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IProvisionedProfile<D>::UpdateUsage(llm::OS::Networking::NetworkOperators::ProfileUsage const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisionedProfile)->UpdateUsage(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ProvisionFromXmlDocumentResults>) consume_Windows_Networking_NetworkOperators_IProvisioningAgent<D>::ProvisionFromXmlDocumentAsync(param::hstring const& provisioningXmlDocument) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisioningAgent)->ProvisionFromXmlDocumentAsync(*(void**)(&provisioningXmlDocument), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ProvisionFromXmlDocumentResults>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ProvisionedProfile) consume_Windows_Networking_NetworkOperators_IProvisioningAgent<D>::GetProvisionedProfile(llm::OS::Networking::NetworkOperators::ProfileMediaType const& mediaType, param::hstring const& profileName) const
    {
        void* provisionedProfile{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisioningAgent)->GetProvisionedProfile(static_cast<int32_t>(mediaType), *(void**)(&profileName), &provisionedProfile));
        return llm::OS::Networking::NetworkOperators::ProvisionedProfile{ provisionedProfile, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::ProvisioningAgent) consume_Windows_Networking_NetworkOperators_IProvisioningAgentStaticMethods<D>::CreateFromNetworkAccountId(param::hstring const& networkAccountId) const
    {
        void* provisioningAgent{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IProvisioningAgentStaticMethods)->CreateFromNetworkAccountId(*(void**)(&networkAccountId), &provisioningAgent));
        return llm::OS::Networking::NetworkOperators::ProvisioningAgent{ provisioningAgent, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_ITetheringEntitlementCheckTriggerDetails<D>::NetworkAccountId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails)->get_NetworkAccountId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_ITetheringEntitlementCheckTriggerDetails<D>::AllowTethering() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails)->AllowTethering());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_ITetheringEntitlementCheckTriggerDetails<D>::DenyTethering(param::hstring const& entitlementFailureReason) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails)->DenyTethering(*(void**)(&entitlementFailureReason)));
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Networking_NetworkOperators_IUssdMessage<D>::DataCodingScheme() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessage)->get_DataCodingScheme(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IUssdMessage<D>::DataCodingScheme(uint8_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessage)->put_DataCodingScheme(value));
    }
    template <typename D> LLM_IMPL_AUTO(com_array<uint8_t>) consume_Windows_Networking_NetworkOperators_IUssdMessage<D>::GetPayload() const
    {
        uint32_t value_impl_size{};
        uint8_t* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessage)->GetPayload(&value_impl_size, &value));
        return com_array<uint8_t>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IUssdMessage<D>::SetPayload(array_view<uint8_t const> value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessage)->SetPayload(value.size(), get_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_NetworkOperators_IUssdMessage<D>::PayloadAsText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessage)->get_PayloadAsText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IUssdMessage<D>::PayloadAsText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessage)->put_PayloadAsText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UssdMessage) consume_Windows_Networking_NetworkOperators_IUssdMessageFactory<D>::CreateMessage(param::hstring const& messageText) const
    {
        void* ussdMessage{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdMessageFactory)->CreateMessage(*(void**)(&messageText), &ussdMessage));
        return llm::OS::Networking::NetworkOperators::UssdMessage{ ussdMessage, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UssdResultCode) consume_Windows_Networking_NetworkOperators_IUssdReply<D>::ResultCode() const
    {
        llm::OS::Networking::NetworkOperators::UssdResultCode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdReply)->get_ResultCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UssdMessage) consume_Windows_Networking_NetworkOperators_IUssdReply<D>::Message() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdReply)->get_Message(&value));
        return llm::OS::Networking::NetworkOperators::UssdMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::UssdReply>) consume_Windows_Networking_NetworkOperators_IUssdSession<D>::SendMessageAndGetReplyAsync(llm::OS::Networking::NetworkOperators::UssdMessage const& message) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdSession)->SendMessageAndGetReplyAsync(*(void**)(&message), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::UssdReply>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_NetworkOperators_IUssdSession<D>::Close() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdSession)->Close());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UssdSession) consume_Windows_Networking_NetworkOperators_IUssdSessionStatics<D>::CreateFromNetworkAccountId(param::hstring const& networkAccountId) const
    {
        void* ussdSession{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdSessionStatics)->CreateFromNetworkAccountId(*(void**)(&networkAccountId), &ussdSession));
        return llm::OS::Networking::NetworkOperators::UssdSession{ ussdSession, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::NetworkOperators::UssdSession) consume_Windows_Networking_NetworkOperators_IUssdSessionStatics<D>::CreateFromNetworkInterfaceId(param::hstring const& networkInterfaceId) const
    {
        void* ussdSession{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::NetworkOperators::IUssdSessionStatics)->CreateFromNetworkInterfaceId(*(void**)(&networkInterfaceId), &ussdSession));
        return llm::OS::Networking::NetworkOperators::UssdSession{ ussdSession, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESim> : produce_base<D, llm::OS::Networking::NetworkOperators::IESim>
    {
        int32_t __stdcall get_AvailableMemoryInBytes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().AvailableMemoryInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Eid(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Eid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FirmwareVersion(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FirmwareVersion());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MobileBroadbandModemDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MobileBroadbandModemDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Policy(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimPolicy>(this->shim().Policy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetProfiles(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::ESimProfile>>(this->shim().GetProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteProfileAsync(void* profileId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().DeleteProfileAsync(*reinterpret_cast<hstring const*>(&profileId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DownloadProfileMetadataAsync(void* activationCode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDownloadProfileMetadataResult>>(this->shim().DownloadProfileMetadataAsync(*reinterpret_cast<hstring const*>(&activationCode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResetAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().ResetAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ProfileChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ProfileChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESim, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ProfileChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProfileChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESim2> : produce_base<D, llm::OS::Networking::NetworkOperators::IESim2>
    {
        int32_t __stdcall Discover(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>(this->shim().Discover());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DiscoverWithServerAddressAndMatchingId(void* serverAddress, void* matchingId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>(this->shim().Discover(*reinterpret_cast<hstring const*>(&serverAddress), *reinterpret_cast<hstring const*>(&matchingId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DiscoverAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>>(this->shim().DiscoverAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DiscoverWithServerAddressAndMatchingIdAsync(void* serverAddress, void* matchingId, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimDiscoverResult>>(this->shim().DiscoverAsync(*reinterpret_cast<hstring const*>(&serverAddress), *reinterpret_cast<hstring const*>(&matchingId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESim3> : produce_base<D, llm::OS::Networking::NetworkOperators::IESim3>
    {
        int32_t __stdcall get_SlotIndex(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().SlotIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimAddedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimAddedEventArgs>
    {
        int32_t __stdcall get_ESim(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESim>(this->shim().ESim());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimDiscoverEvent> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimDiscoverEvent>
    {
        int32_t __stdcall get_MatchingId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MatchingId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RspServerAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RspServerAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimDiscoverResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimDiscoverResult>
    {
        int32_t __stdcall get_Events(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::ESimDiscoverEvent>>(this->shim().Events());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimDiscoverResultKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProfileMetadata(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfileMetadata>(this->shim().ProfileMetadata());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Result(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimOperationResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult>
    {
        int32_t __stdcall get_Result(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimOperationResult>(this->shim().Result());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProfileMetadata(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfileMetadata>(this->shim().ProfileMetadata());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimManagerStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimManagerStatics>
    {
        int32_t __stdcall get_ServiceInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimServiceInfo>(this->shim().ServiceInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TryCreateESimWatcher(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::ESimWatcher>(this->shim().TryCreateESimWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ServiceInfoChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ServiceInfoChanged(*reinterpret_cast<llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ServiceInfoChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ServiceInfoChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimOperationResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimOperationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimPolicy> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimPolicy>
    {
        int32_t __stdcall get_ShouldEnableManagingUi(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShouldEnableManagingUi());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimProfile> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimProfile>
    {
        int32_t __stdcall get_Class(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfileClass>(this->shim().Class());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Nickname(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Nickname());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Policy(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfilePolicy>(this->shim().Policy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderIcon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().ProviderIcon());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfileState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisableAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().DisableAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnableAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().EnableAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetNicknameAsync(void* newNickname, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().SetNicknameAsync(*reinterpret_cast<hstring const*>(&newNickname)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimProfileMetadata> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimProfileMetadata>
    {
        int32_t __stdcall get_IsConfirmationCodeRequired(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsConfirmationCodeRequired());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Policy(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfilePolicy>(this->shim().Policy());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderIcon(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IRandomAccessStreamReference>(this->shim().ProviderIcon());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimProfileMetadataState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DenyInstallAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().DenyInstallAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConfirmInstallAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::NetworkOperators::ESimOperationResult, llm::OS::Networking::NetworkOperators::ESimProfileInstallProgress>>(this->shim().ConfirmInstallAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConfirmInstallWithConfirmationCodeAsync(void* confirmationCode, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Networking::NetworkOperators::ESimOperationResult, llm::OS::Networking::NetworkOperators::ESimProfileInstallProgress>>(this->shim().ConfirmInstallAsync(*reinterpret_cast<hstring const*>(&confirmationCode)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PostponeInstallAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ESimOperationResult>>(this->shim().PostponeInstallAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimProfileMetadata, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimProfilePolicy> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimProfilePolicy>
    {
        int32_t __stdcall get_CanDelete(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanDelete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanDisable(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanDisable());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsManagedByEnterprise(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsManagedByEnterprise());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimRemovedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimRemovedEventArgs>
    {
        int32_t __stdcall get_ESim(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESim>(this->shim().ESim());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimServiceInfo> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimServiceInfo>
    {
        int32_t __stdcall get_AuthenticationPreference(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimAuthenticationPreference>(this->shim().AuthenticationPreference());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsESimUiEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsESimUiEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimUpdatedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimUpdatedEventArgs>
    {
        int32_t __stdcall get_ESim(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESim>(this->shim().ESim());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IESimWatcher> : produce_base<D, llm::OS::Networking::NetworkOperators::IESimWatcher>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::ESimWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimAddedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Added(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Removed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimRemovedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Updated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Updated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::ESimWatcher, llm::OS::Networking::NetworkOperators::ESimUpdatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Updated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IFdnAccessManagerStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IFdnAccessManagerStatics>
    {
        int32_t __stdcall RequestUnlockAsync(void* contactListId, void** returnValue) noexcept final try
        {
            clear_abi(returnValue);
            typename D::abi_guard guard(this->shim());
            *returnValue = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().RequestUnlockAsync(*reinterpret_cast<hstring const*>(&contactListId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext> : produce_base<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext>
    {
        int32_t __stdcall get_WirelessNetworkId(uint32_t* __valueSize, uint8_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().WirelessNetworkId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkAdapter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Connectivity::NetworkAdapter>(this->shim().NetworkAdapter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedirectMessageUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().RedirectMessageUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RedirectMessageXml(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Data::Xml::Dom::XmlDocument>(this->shim().RedirectMessageXml());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AuthenticationUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().AuthenticationUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IssueCredentials(void* userName, void* password, void* extraParameters, bool markAsManualConnectOnFailure) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IssueCredentials(*reinterpret_cast<hstring const*>(&userName), *reinterpret_cast<hstring const*>(&password), *reinterpret_cast<hstring const*>(&extraParameters), markAsManualConnectOnFailure);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AbortAuthentication(bool markAsManual) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AbortAuthentication(markAsManual);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SkipAuthentication() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SkipAuthentication();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TriggerAttentionRequired(void* packageRelativeApplicationId, void* applicationParameters) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TriggerAttentionRequired(*reinterpret_cast<hstring const*>(&packageRelativeApplicationId), *reinterpret_cast<hstring const*>(&applicationParameters));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext2> : produce_base<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext2>
    {
        int32_t __stdcall IssueCredentialsAsync(void* userName, void* password, void* extraParameters, bool markAsManualConnectOnFailure, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult>>(this->shim().IssueCredentialsAsync(*reinterpret_cast<hstring const*>(&userName), *reinterpret_cast<hstring const*>(&password), *reinterpret_cast<hstring const*>(&extraParameters), markAsManualConnectOnFailure));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContextStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContextStatics>
    {
        int32_t __stdcall TryGetAuthenticationContext(void* evenToken, void** context, bool* isValid) noexcept final try
        {
            clear_abi(context);
            typename D::abi_guard guard(this->shim());
            *isValid = detach_from<bool>(this->shim().TryGetAuthenticationContext(*reinterpret_cast<hstring const*>(&evenToken), *reinterpret_cast<llm::OS::Networking::NetworkOperators::HotspotAuthenticationContext*>(context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationEventDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::IHotspotAuthenticationEventDetails>
    {
        int32_t __stdcall get_EventToken(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().EventToken());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult>
    {
        int32_t __stdcall get_HasNetworkErrorOccurred(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasNetworkErrorOccurred());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::HotspotAuthenticationResponseCode>(this->shim().ResponseCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LogoffUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().LogoffUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AuthenticationReplyXml(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Data::Xml::Dom::XmlDocument>(this->shim().AuthenticationReplyXml());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IKnownCSimFilePathsStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IKnownCSimFilePathsStatics>
    {
        int32_t __stdcall get_EFSpn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFSpn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid1(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid2(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IKnownRuimFilePathsStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IKnownRuimFilePathsStatics>
    {
        int32_t __stdcall get_EFSpn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFSpn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid1(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid2(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics>
    {
        int32_t __stdcall get_EFOns(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFOns());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EFSpn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFSpn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid1(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid2(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics>
    {
        int32_t __stdcall get_EFSpn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFSpn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EFOpl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFOpl());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EFPnn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().EFPnn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid1(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid1());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Gid2(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().Gid2());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount>
    {
        int32_t __stdcall get_NetworkAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceProviderGuid(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().ServiceProviderGuid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceProviderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServiceProviderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentNetwork(void** network) noexcept final try
        {
            clear_abi(network);
            typename D::abi_guard guard(this->shim());
            *network = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork>(this->shim().CurrentNetwork());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentDeviceInformation(void** deviceInformation) noexcept final try
        {
            clear_abi(deviceInformation);
            typename D::abi_guard guard(this->shim());
            *deviceInformation = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation>(this->shim().CurrentDeviceInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount2>
    {
        int32_t __stdcall GetConnectionProfiles(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Connectivity::ConnectionProfile>>(this->shim().GetConnectionProfiles());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount3> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount3>
    {
        int32_t __stdcall get_AccountExperienceUrl(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().AccountExperienceUrl());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs>
    {
        int32_t __stdcall get_NetworkAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountStatics>
    {
        int32_t __stdcall get_AvailableNetworkAccountIds(void** ppAccountIds) noexcept final try
        {
            clear_abi(ppAccountIds);
            typename D::abi_guard guard(this->shim());
            *ppAccountIds = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().AvailableNetworkAccountIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromNetworkAccountId(void* networkAccountId, void** ppAccount) noexcept final try
        {
            clear_abi(ppAccount);
            typename D::abi_guard guard(this->shim());
            *ppAccount = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandAccount>(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs>
    {
        int32_t __stdcall get_NetworkAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasDeviceInformationChanged(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasDeviceInformationChanged());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HasNetworkChanged(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().HasNetworkChanged());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher>
    {
        int32_t __stdcall add_AccountAdded(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AccountAdded(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccountAdded(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountAdded(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_AccountUpdated(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AccountUpdated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccountUpdated(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountUpdated(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_AccountRemoved(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AccountRemoved(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccountRemoved(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccountRemoved(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Stop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stop();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar>
    {
        int32_t __stdcall get_AntennaIndex(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().AntennaIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SarBackoffIndex(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().SarBackoffIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSarFactory> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSarFactory>
    {
        int32_t __stdcall CreateWithIndex(int32_t antennaIndex, int32_t sarBackoffIndex, void** antennaSar) noexcept final try
        {
            clear_abi(antennaSar);
            typename D::abi_guard guard(this->shim());
            *antennaSar = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar>(this->shim().CreateWithIndex(antennaIndex, sarBackoffIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma>
    {
        int32_t __stdcall get_BaseStationId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().BaseStationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BaseStationPNCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().BaseStationPNCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BaseStationLatitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().BaseStationLatitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BaseStationLongitude(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().BaseStationLongitude());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BaseStationLastBroadcastGpsTime(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Foundation::TimeSpan>>(this->shim().BaseStationLastBroadcastGpsTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().NetworkId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PilotSignalStrengthInDB(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().PilotSignalStrengthInDB());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().SystemId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm>
    {
        int32_t __stdcall get_BaseStationId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().BaseStationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ChannelNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocationAreaCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().LocationAreaCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReceivedSignalStrengthInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReceivedSignalStrengthInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimingAdvanceInBitPeriods(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().TimingAdvanceInBitPeriods());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte>
    {
        int32_t __stdcall get_CellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ChannelNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhysicalCellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().PhysicalCellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReferenceSignalReceivedPowerInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReferenceSignalReceivedPowerInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReferenceSignalReceivedQualityInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReferenceSignalReceivedQualityInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimingAdvanceInBitPeriods(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().TimingAdvanceInBitPeriods());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrackingAreaCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().TrackingAreaCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR>
    {
        int32_t __stdcall get_CellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int64_t>>(this->shim().CellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ChannelNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhysicalCellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().PhysicalCellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReferenceSignalReceivedPowerInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReferenceSignalReceivedPowerInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReferenceSignalReceivedQualityInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReferenceSignalReceivedQualityInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimingAdvanceInNanoseconds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().TimingAdvanceInNanoseconds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrackingAreaCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().TrackingAreaCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalToNoiseRatioInDB(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().SignalToNoiseRatioInDB());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma>
    {
        int32_t __stdcall get_CellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellParameterId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CellParameterId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ChannelNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocationAreaCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().LocationAreaCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PathLossInDB(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().PathLossInDB());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReceivedSignalCodePowerInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReceivedSignalCodePowerInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimingAdvanceInBitPeriods(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().TimingAdvanceInBitPeriods());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts>
    {
        int32_t __stdcall get_CellId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().CellId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().ChannelNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocationAreaCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().LocationAreaCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PathLossInDB(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().PathLossInDB());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrimaryScramblingCode(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().PrimaryScramblingCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReceivedSignalCodePowerInDBm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().ReceivedSignalCodePowerInDBm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalToNoiseRatioInDB(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<double>>(this->shim().SignalToNoiseRatioInDB());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo>
    {
        int32_t __stdcall get_NeighboringCellsCdma(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma>>(this->shim().NeighboringCellsCdma());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeighboringCellsGsm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm>>(this->shim().NeighboringCellsGsm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeighboringCellsLte(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte>>(this->shim().NeighboringCellsLte());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeighboringCellsTdscdma(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma>>(this->shim().NeighboringCellsTdscdma());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NeighboringCellsUmts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts>>(this->shim().NeighboringCellsUmts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServingCellsCdma(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma>>(this->shim().ServingCellsCdma());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServingCellsGsm(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm>>(this->shim().ServingCellsGsm());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServingCellsLte(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte>>(this->shim().ServingCellsLte());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServingCellsTdscdma(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma>>(this->shim().ServingCellsTdscdma());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServingCellsUmts(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts>>(this->shim().ServingCellsUmts());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo2>
    {
        int32_t __stdcall get_NeighboringCellsNR(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR>>(this->shim().NeighboringCellsNR());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServingCellsNR(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR>>(this->shim().ServingCellsNR());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCurrentSlotIndexChangedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandCurrentSlotIndexChangedEventArgs>
    {
        int32_t __stdcall get_CurrentSlotIndex(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().CurrentSlotIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation>
    {
        int32_t __stdcall get_NetworkDeviceStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::NetworkDeviceStatus>(this->shim().NetworkDeviceStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Manufacturer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Manufacturer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Model(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Model());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_FirmwareInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().FirmwareInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::CellularClass>(this->shim().CellularClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DataClasses(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::DataClasses>(this->shim().DataClasses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomDataClass(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CustomDataClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MobileEquipmentId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MobileEquipmentId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TelephoneNumbers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().TelephoneNumbers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SubscriberId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SubscriberId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SimIccId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SimIccId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceType(int32_t* pDeviceType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *pDeviceType = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceType>(this->shim().DeviceType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentRadioState(int32_t* pCurrentState) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *pCurrentState = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioState>(this->shim().CurrentRadioState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2>
    {
        int32_t __stdcall get_PinManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPinManager>(this->shim().PinManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Revision(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Revision());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SerialNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SerialNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3>
    {
        int32_t __stdcall get_SimSpn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SimSpn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SimPnn(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SimPnn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SimGid1(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SimGid1());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation4> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation4>
    {
        int32_t __stdcall get_SlotManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager>(this->shim().SlotManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService>
    {
        int32_t __stdcall get_DeviceServiceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().DeviceServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedCommands(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<uint32_t>>(this->shim().SupportedCommands());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenDataSession(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession>(this->shim().OpenDataSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall OpenCommandSession(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandSession>(this->shim().OpenCommandSession());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult>
    {
        int32_t __stdcall get_StatusCode(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().StatusCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ResponseData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().ResponseData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession>
    {
        int32_t __stdcall SendQueryCommandAsync(uint32_t commandId, void* data, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>>(this->shim().SendQueryCommandAsync(commandId, *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendSetCommandAsync(uint32_t commandId, void* data, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult>>(this->shim().SendSetCommandAsync(commandId, *reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&data)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CloseSession() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseSession();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs>
    {
        int32_t __stdcall get_ReceivedData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().ReceivedData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession>
    {
        int32_t __stdcall WriteDataAsync(void* value, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().WriteDataAsync(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CloseSession() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CloseSession();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DataReceived(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().DataReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession, llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DataReceived(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataReceived(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation>
    {
        int32_t __stdcall get_DeviceServiceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().DeviceServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDataReadSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDataReadSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDataWriteSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDataWriteSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceServiceId(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().DeviceServiceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReceivedData(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().ReceivedData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails2>
    {
        int32_t __stdcall get_EventId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().EventId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem>
    {
        int32_t __stdcall get_CurrentAccount(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandAccount>(this->shim().CurrentAccount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation>(this->shim().DeviceInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxDeviceServiceCommandSizeInBytes(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxDeviceServiceCommandSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxDeviceServiceDataSizeInBytes(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxDeviceServiceDataSizeInBytes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceServices(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation>>(this->shim().DeviceServices());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeviceService(llm::guid deviceServiceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceService>(this->shim().GetDeviceService(*reinterpret_cast<llm::guid const*>(&deviceServiceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsResetSupported(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsResetSupported());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ResetAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ResetAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentConfigurationAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemConfiguration>>(this->shim().GetCurrentConfigurationAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentNetwork(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork>(this->shim().CurrentNetwork());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem2>
    {
        int32_t __stdcall GetIsPassthroughEnabledAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetIsPassthroughEnabledAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetIsPassthroughEnabledAsync(bool value, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>>(this->shim().SetIsPassthroughEnabledAsync(value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3>
    {
        int32_t __stdcall TryGetPcoAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPco>>(this->shim().TryGetPcoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsInEmergencyCallMode(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsInEmergencyCallMode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_IsInEmergencyCallModeChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().IsInEmergencyCallModeChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandModem, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_IsInEmergencyCallModeChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsInEmergencyCallModeChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4>
    {
        int32_t __stdcall SetIsPassthroughEnabledWithSlotIndexAsync(bool value, int32_t slotindex, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>>(this->shim().SetIsPassthroughEnabledAsync(value, slotindex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIsPassthroughEnabledWithSlotIndexAsync(int32_t slotindex, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetIsPassthroughEnabledAsync(slotindex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetIsPassthroughEnabledWithSlotIndex(bool value, int32_t slotindex, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>(this->shim().SetIsPassthroughEnabled(value, slotindex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIsPassthroughEnabledWithSlotIndex(int32_t slotindex, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().GetIsPassthroughEnabled(slotindex));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration>
    {
        int32_t __stdcall get_Uicc(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandUicc>(this->shim().Uicc());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HomeProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HomeProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HomeProviderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().HomeProviderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration2>
    {
        int32_t __stdcall get_SarManager(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager>(this->shim().SarManager());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation>
    {
        int32_t __stdcall AddAllowedHost(void* host) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAllowedHost(*reinterpret_cast<llm::OS::Networking::HostName const*>(&host));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddAllowedHostRange(void* first, void* last) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAllowedHostRange(*reinterpret_cast<llm::OS::Networking::HostName const*>(&first), *reinterpret_cast<llm::OS::Networking::HostName const*>(&last));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ApplyConfigurationAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ApplyConfigurationAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearConfigurationAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ClearConfigurationAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolationFactory> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolationFactory>
    {
        int32_t __stdcall Create(void* modemDeviceId, void* ruleGroupId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandModemIsolation>(this->shim().Create(*reinterpret_cast<hstring const*>(&modemDeviceId), *reinterpret_cast<hstring const*>(&ruleGroupId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandModemStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromId(void* deviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandModem>(this->shim().FromId(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandModem>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork>
    {
        int32_t __stdcall get_NetworkAdapter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Connectivity::NetworkAdapter>(this->shim().NetworkAdapter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkRegistrationState(int32_t* registrationState) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *registrationState = detach_from<llm::OS::Networking::NetworkOperators::NetworkRegistrationState>(this->shim().NetworkRegistrationState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegistrationNetworkError(uint32_t* networkError) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *networkError = detach_from<uint32_t>(this->shim().RegistrationNetworkError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PacketAttachNetworkError(uint32_t* networkError) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *networkError = detach_from<uint32_t>(this->shim().PacketAttachNetworkError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivationNetworkError(uint32_t* networkError) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *networkError = detach_from<uint32_t>(this->shim().ActivationNetworkError());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AccessPointName(void** apn) noexcept final try
        {
            clear_abi(apn);
            typename D::abi_guard guard(this->shim());
            *apn = detach_from<hstring>(this->shim().AccessPointName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegisteredDataClass(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::DataClasses>(this->shim().RegisteredDataClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegisteredProviderId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RegisteredProviderId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegisteredProviderName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RegisteredProviderName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowConnectionUI() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShowConnectionUI();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork2>
    {
        int32_t __stdcall GetVoiceCallSupportAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetVoiceCallSupportAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RegistrationUiccApps(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp>>(this->shim().RegistrationUiccApps());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork3> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork3>
    {
        int32_t __stdcall GetCellsInfoAsync(void** asyncOperation) noexcept final try
        {
            clear_abi(asyncOperation);
            typename D::abi_guard guard(this->shim());
            *asyncOperation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandCellsInfo>>(this->shim().GetCellsInfoAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Network(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork>(this->shim().Network());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails>
    {
        int32_t __stdcall get_NetworkRegistrationStateChanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange>>(this->shim().NetworkRegistrationStateChanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPco> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPco>
    {
        int32_t __stdcall get_Data(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsComplete(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsComplete());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPcoDataChangeTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPcoDataChangeTriggerDetails>
    {
        int32_t __stdcall get_UpdatedData(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPco>(this->shim().UpdatedData());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPin> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPin>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPinType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LockState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockState>(this->shim().LockState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPinFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Enabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Enabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxLength(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MinLength(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MinLength());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AttemptsRemaining(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().AttemptsRemaining());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnableAsync(void* currentPin, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>>(this->shim().EnableAsync(*reinterpret_cast<hstring const*>(&currentPin)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisableAsync(void* currentPin, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>>(this->shim().DisableAsync(*reinterpret_cast<hstring const*>(&currentPin)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnterAsync(void* currentPin, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>>(this->shim().EnterAsync(*reinterpret_cast<hstring const*>(&currentPin)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ChangeAsync(void* currentPin, void* newPin, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>>(this->shim().ChangeAsync(*reinterpret_cast<hstring const*>(&currentPin), *reinterpret_cast<hstring const*>(&newPin)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnblockAsync(void* pinUnblockKey, void* newPin, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult>>(this->shim().UnblockAsync(*reinterpret_cast<hstring const*>(&pinUnblockKey), *reinterpret_cast<hstring const*>(&newPin)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PinType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPinType>(this->shim().PinType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PinLockState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockState>(this->shim().PinLockState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails>
    {
        int32_t __stdcall get_PinLockStateChanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockStateChange>>(this->shim().PinLockStateChanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinManager> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinManager>
    {
        int32_t __stdcall get_SupportedPins(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandPinType>>(this->shim().SupportedPins());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPin(int32_t pinType, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandPin>(this->shim().GetPin(*reinterpret_cast<llm::OS::Networking::NetworkOperators::MobileBroadbandPinType const*>(&pinType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult>
    {
        int32_t __stdcall get_IsSuccessful(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSuccessful());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AttemptsRemaining(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().AttemptsRemaining());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RadioState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioState>(this->shim().RadioState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails>
    {
        int32_t __stdcall get_RadioStateChanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioStateChange>>(this->shim().RadioStateChanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager>
    {
        int32_t __stdcall get_IsBackoffEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsBackoffEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsWiFiHardwareIntegrated(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsWiFiHardwareIntegrated());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSarControlledByHardware(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSarControlledByHardware());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Antennas(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar>>(this->shim().Antennas());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HysteresisTimerPeriod(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().HysteresisTimerPeriod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_TransmissionStateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().TransmissionStateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager, llm::OS::Networking::NetworkOperators::MobileBroadbandTransmissionStateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_TransmissionStateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransmissionStateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall EnableBackoffAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().EnableBackoffAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisableBackoffAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DisableBackoffAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetConfigurationAsync(void* antennas, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetConfigurationAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar> const*>(&antennas)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RevertSarToHardwareControlAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RevertSarToHardwareControlAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetTransmissionStateChangedHysteresisAsync(int64_t timerPeriod, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().SetTransmissionStateChangedHysteresisAsync(*reinterpret_cast<llm::OS::Foundation::TimeSpan const*>(&timerPeriod)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetIsTransmittingAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().GetIsTransmittingAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartTransmissionStateMonitoring() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartTransmissionStateMonitoring();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopTransmissionStateMonitoring() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StopTransmissionStateMonitoring();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo>
    {
        int32_t __stdcall get_Index(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Index());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo2> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo2>
    {
        int32_t __stdcall get_IccId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().IccId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfoChangedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfoChangedEventArgs>
    {
        int32_t __stdcall get_SlotInfo(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo>(this->shim().SlotInfo());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager>
    {
        int32_t __stdcall get_SlotInfos(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo>>(this->shim().SlotInfos());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentSlotIndex(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().CurrentSlotIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCurrentSlot(int32_t slotIndex, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>(this->shim().SetCurrentSlot(slotIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetCurrentSlotAsync(int32_t slotIndex, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandModemStatus>>(this->shim().SetCurrentSlotAsync(slotIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SlotInfoChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SlotInfoChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager, llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfoChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SlotInfoChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SlotInfoChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_CurrentSlotIndexChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().CurrentSlotIndexChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager, llm::OS::Networking::NetworkOperators::MobileBroadbandCurrentSlotIndexChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_CurrentSlotIndexChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CurrentSlotIndexChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandTransmissionStateChangedEventArgs> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandTransmissionStateChangedEventArgs>
    {
        int32_t __stdcall get_IsTransmitting(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTransmitting());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUicc> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUicc>
    {
        int32_t __stdcall get_SimIccId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SimIccId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetUiccAppsAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppsResult>>(this->shim().GetUiccAppsAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::UiccAppKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRecordDetailsAsync(void* uiccFilePath, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult>>(this->shim().GetRecordDetailsAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<uint32_t> const*>(&uiccFilePath)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReadRecordAsync(void* uiccFilePath, int32_t recordIndex, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult>>(this->shim().ReadRecordAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<uint32_t> const*>(&uiccFilePath), recordIndex));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Data(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Data());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::UiccAppRecordKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecordCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RecordCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RecordSize(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RecordSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ReadAccessCondition(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::UiccAccessCondition>(this->shim().ReadAccessCondition());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WriteAccessCondition(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::UiccAccessCondition>(this->shim().WriteAccessCondition());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult> : produce_base<D, llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UiccApps(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp>>(this->shim().UiccApps());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorDataUsageTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorDataUsageTriggerDetails>
    {
        int32_t __stdcall get_NotificationKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::NetworkOperatorDataUsageNotificationKind>(this->shim().NotificationKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails>
    {
        int32_t __stdcall get_NotificationType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::NetworkOperatorEventMessageType>(this->shim().NotificationType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EncodingType(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().EncodingType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RuleId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RuleId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SmsMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::ISmsMessage>(this->shim().SmsMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration>
    {
        int32_t __stdcall get_Ssid(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Ssid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Ssid(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ssid(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Passphrase(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Passphrase());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Passphrase(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Passphrase(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2>
    {
        int32_t __stdcall IsBandSupported(int32_t band, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsBandSupported(*reinterpret_cast<llm::OS::Networking::NetworkOperators::TetheringWiFiBand const*>(&band)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall IsBandSupportedAsync(int32_t band, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<bool>>(this->shim().IsBandSupportedAsync(*reinterpret_cast<llm::OS::Networking::NetworkOperators::TetheringWiFiBand const*>(&band)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Band(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::TetheringWiFiBand>(this->shim().Band());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Band(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Band(*reinterpret_cast<llm::OS::Networking::NetworkOperators::TetheringWiFiBand const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClient> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClient>
    {
        int32_t __stdcall get_MacAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().MacAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_HostNames(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>>(this->shim().HostNames());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClientManager> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClientManager>
    {
        int32_t __stdcall GetTetheringClients(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringClient>>(this->shim().GetTetheringClients());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck>
    {
        int32_t __stdcall AuthorizeTethering(bool allow, void* entitlementFailureReason) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AuthorizeTethering(allow, *reinterpret_cast<hstring const*>(&entitlementFailureReason));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager>
    {
        int32_t __stdcall get_MaxClientCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxClientCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ClientCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().ClientCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TetheringOperationalState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::TetheringOperationalState>(this->shim().TetheringOperationalState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetCurrentAccessPointConfiguration(void** configuration) noexcept final try
        {
            clear_abi(configuration);
            typename D::abi_guard guard(this->shim());
            *configuration = detach_from<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration>(this->shim().GetCurrentAccessPointConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConfigureAccessPointAsync(void* configuration, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ConfigureAccessPointAsync(*reinterpret_cast<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration const*>(&configuration)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartTetheringAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>>(this->shim().StartTetheringAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StopTetheringAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult>>(this->shim().StopTetheringAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics>
    {
        int32_t __stdcall GetTetheringCapability(void* networkAccountId, int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::TetheringCapability>(this->shim().GetTetheringCapability(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromNetworkAccountId(void* networkAccountId, void** ppManager) noexcept final try
        {
            clear_abi(ppManager);
            typename D::abi_guard guard(this->shim());
            *ppManager = detach_from<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager>(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2>
    {
        int32_t __stdcall GetTetheringCapabilityFromConnectionProfile(void* profile, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::NetworkOperators::TetheringCapability>(this->shim().GetTetheringCapabilityFromConnectionProfile(*reinterpret_cast<llm::OS::Networking::Connectivity::ConnectionProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromConnectionProfile(void* profile, void** ppManager) noexcept final try
        {
            clear_abi(ppManager);
            typename D::abi_guard guard(this->shim());
            *ppManager = detach_from<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager>(this->shim().CreateFromConnectionProfile(*reinterpret_cast<llm::OS::Networking::Connectivity::ConnectionProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3>
    {
        int32_t __stdcall CreateFromConnectionProfileWithTargetAdapter(void* profile, void* adapter, void** ppManager) noexcept final try
        {
            clear_abi(ppManager);
            typename D::abi_guard guard(this->shim());
            *ppManager = detach_from<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager>(this->shim().CreateFromConnectionProfile(*reinterpret_cast<llm::OS::Networking::Connectivity::ConnectionProfile const*>(&profile), *reinterpret_cast<llm::OS::Networking::Connectivity::NetworkAdapter const*>(&adapter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4>
    {
        int32_t __stdcall IsNoConnectionsTimeoutEnabled(bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().IsNoConnectionsTimeoutEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnableNoConnectionsTimeout() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnableNoConnectionsTimeout();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall EnableNoConnectionsTimeoutAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().EnableNoConnectionsTimeoutAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisableNoConnectionsTimeout() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisableNoConnectionsTimeout();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisableNoConnectionsTimeoutAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DisableNoConnectionsTimeoutAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult> : produce_base<D, llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::TetheringOperationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdditionalErrorMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AdditionalErrorMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults> : produce_base<D, llm::OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults>
    {
        int32_t __stdcall get_AllElementsProvisioned(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllElementsProvisioned());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProvisionResultsXml(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProvisionResultsXml());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IProvisionedProfile> : produce_base<D, llm::OS::Networking::NetworkOperators::IProvisionedProfile>
    {
        int32_t __stdcall UpdateCost(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateCost(*reinterpret_cast<llm::OS::Networking::Connectivity::NetworkCostType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateUsage(struct struct_Windows_Networking_NetworkOperators_ProfileUsage value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateUsage(*reinterpret_cast<llm::OS::Networking::NetworkOperators::ProfileUsage const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IProvisioningAgent> : produce_base<D, llm::OS::Networking::NetworkOperators::IProvisioningAgent>
    {
        int32_t __stdcall ProvisionFromXmlDocumentAsync(void* provisioningXmlDocument, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::ProvisionFromXmlDocumentResults>>(this->shim().ProvisionFromXmlDocumentAsync(*reinterpret_cast<hstring const*>(&provisioningXmlDocument)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetProvisionedProfile(int32_t mediaType, void* profileName, void** provisionedProfile) noexcept final try
        {
            clear_abi(provisionedProfile);
            typename D::abi_guard guard(this->shim());
            *provisionedProfile = detach_from<llm::OS::Networking::NetworkOperators::ProvisionedProfile>(this->shim().GetProvisionedProfile(*reinterpret_cast<llm::OS::Networking::NetworkOperators::ProfileMediaType const*>(&mediaType), *reinterpret_cast<hstring const*>(&profileName)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IProvisioningAgentStaticMethods> : produce_base<D, llm::OS::Networking::NetworkOperators::IProvisioningAgentStaticMethods>
    {
        int32_t __stdcall CreateFromNetworkAccountId(void* networkAccountId, void** provisioningAgent) noexcept final try
        {
            clear_abi(provisioningAgent);
            typename D::abi_guard guard(this->shim());
            *provisioningAgent = detach_from<llm::OS::Networking::NetworkOperators::ProvisioningAgent>(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails> : produce_base<D, llm::OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails>
    {
        int32_t __stdcall get_NetworkAccountId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().NetworkAccountId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AllowTethering() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowTethering();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DenyTethering(void* entitlementFailureReason) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DenyTethering(*reinterpret_cast<hstring const*>(&entitlementFailureReason));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IUssdMessage> : produce_base<D, llm::OS::Networking::NetworkOperators::IUssdMessage>
    {
        int32_t __stdcall get_DataCodingScheme(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().DataCodingScheme());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DataCodingScheme(uint8_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DataCodingScheme(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPayload(uint32_t* __valueSize, uint8_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetPayload());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetPayload(uint32_t __valueSize, uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetPayload(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(value), reinterpret_cast<uint8_t const *>(value) + __valueSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PayloadAsText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PayloadAsText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PayloadAsText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PayloadAsText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IUssdMessageFactory> : produce_base<D, llm::OS::Networking::NetworkOperators::IUssdMessageFactory>
    {
        int32_t __stdcall CreateMessage(void* messageText, void** ussdMessage) noexcept final try
        {
            clear_abi(ussdMessage);
            typename D::abi_guard guard(this->shim());
            *ussdMessage = detach_from<llm::OS::Networking::NetworkOperators::UssdMessage>(this->shim().CreateMessage(*reinterpret_cast<hstring const*>(&messageText)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IUssdReply> : produce_base<D, llm::OS::Networking::NetworkOperators::IUssdReply>
    {
        int32_t __stdcall get_ResultCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::UssdResultCode>(this->shim().ResultCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Message(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::NetworkOperators::UssdMessage>(this->shim().Message());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IUssdSession> : produce_base<D, llm::OS::Networking::NetworkOperators::IUssdSession>
    {
        int32_t __stdcall SendMessageAndGetReplyAsync(void* message, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::NetworkOperators::UssdReply>>(this->shim().SendMessageAndGetReplyAsync(*reinterpret_cast<llm::OS::Networking::NetworkOperators::UssdMessage const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Close() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Close();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::NetworkOperators::IUssdSessionStatics> : produce_base<D, llm::OS::Networking::NetworkOperators::IUssdSessionStatics>
    {
        int32_t __stdcall CreateFromNetworkAccountId(void* networkAccountId, void** ussdSession) noexcept final try
        {
            clear_abi(ussdSession);
            typename D::abi_guard guard(this->shim());
            *ussdSession = detach_from<llm::OS::Networking::NetworkOperators::UssdSession>(this->shim().CreateFromNetworkAccountId(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromNetworkInterfaceId(void* networkInterfaceId, void** ussdSession) noexcept final try
        {
            clear_abi(ussdSession);
            typename D::abi_guard guard(this->shim());
            *ussdSession = detach_from<llm::OS::Networking::NetworkOperators::UssdSession>(this->shim().CreateFromNetworkInterfaceId(*reinterpret_cast<hstring const*>(&networkInterfaceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Networking::NetworkOperators
{
    constexpr auto operator|(DataClasses const left, DataClasses const right) noexcept
    {
        return static_cast<DataClasses>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DataClasses& left, DataClasses const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DataClasses const left, DataClasses const right) noexcept
    {
        return static_cast<DataClasses>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DataClasses& left, DataClasses const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DataClasses const value) noexcept
    {
        return static_cast<DataClasses>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DataClasses const left, DataClasses const right) noexcept
    {
        return static_cast<DataClasses>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DataClasses& left, DataClasses const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto ESimManager::ServiceInfo()
    {
        return impl::call_factory_cast<llm::OS::Networking::NetworkOperators::ESimServiceInfo(*)(IESimManagerStatics const&), ESimManager, IESimManagerStatics>([](IESimManagerStatics const& f) { return f.ServiceInfo(); });
    }
    inline auto ESimManager::TryCreateESimWatcher()
    {
        return impl::call_factory_cast<llm::OS::Networking::NetworkOperators::ESimWatcher(*)(IESimManagerStatics const&), ESimManager, IESimManagerStatics>([](IESimManagerStatics const& f) { return f.TryCreateESimWatcher(); });
    }
    inline auto ESimManager::ServiceInfoChanged(llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        return impl::call_factory<ESimManager, IESimManagerStatics>([&](IESimManagerStatics const& f) { return f.ServiceInfoChanged(handler); });
    }
    inline ESimManager::ServiceInfoChanged_revoker ESimManager::ServiceInfoChanged(auto_revoke_t, llm::OS::Foundation::EventHandler<llm::OS::Foundation::IInspectable> const& handler)
    {
        auto f = get_activation_factory<ESimManager, llm::OS::Networking::NetworkOperators::IESimManagerStatics>();
        return { f, f.ServiceInfoChanged(handler) };
    }
    inline auto ESimManager::ServiceInfoChanged(llm::event_token const& token)
    {
        impl::call_factory<ESimManager, IESimManagerStatics>([&](IESimManagerStatics const& f) { return f.ServiceInfoChanged(token); });
    }
    inline auto FdnAccessManager::RequestUnlockAsync(param::hstring const& contactListId)
    {
        return impl::call_factory<FdnAccessManager, IFdnAccessManagerStatics>([&](IFdnAccessManagerStatics const& f) { return f.RequestUnlockAsync(contactListId); });
    }
    inline auto HotspotAuthenticationContext::TryGetAuthenticationContext(param::hstring const& evenToken, llm::OS::Networking::NetworkOperators::HotspotAuthenticationContext& context)
    {
        return impl::call_factory<HotspotAuthenticationContext, IHotspotAuthenticationContextStatics>([&](IHotspotAuthenticationContextStatics const& f) { return f.TryGetAuthenticationContext(evenToken, context); });
    }
    inline auto KnownCSimFilePaths::EFSpn()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownCSimFilePathsStatics const&), KnownCSimFilePaths, IKnownCSimFilePathsStatics>([](IKnownCSimFilePathsStatics const& f) { return f.EFSpn(); });
    }
    inline auto KnownCSimFilePaths::Gid1()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownCSimFilePathsStatics const&), KnownCSimFilePaths, IKnownCSimFilePathsStatics>([](IKnownCSimFilePathsStatics const& f) { return f.Gid1(); });
    }
    inline auto KnownCSimFilePaths::Gid2()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownCSimFilePathsStatics const&), KnownCSimFilePaths, IKnownCSimFilePathsStatics>([](IKnownCSimFilePathsStatics const& f) { return f.Gid2(); });
    }
    inline auto KnownRuimFilePaths::EFSpn()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownRuimFilePathsStatics const&), KnownRuimFilePaths, IKnownRuimFilePathsStatics>([](IKnownRuimFilePathsStatics const& f) { return f.EFSpn(); });
    }
    inline auto KnownRuimFilePaths::Gid1()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownRuimFilePathsStatics const&), KnownRuimFilePaths, IKnownRuimFilePathsStatics>([](IKnownRuimFilePathsStatics const& f) { return f.Gid1(); });
    }
    inline auto KnownRuimFilePaths::Gid2()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownRuimFilePathsStatics const&), KnownRuimFilePaths, IKnownRuimFilePathsStatics>([](IKnownRuimFilePathsStatics const& f) { return f.Gid2(); });
    }
    inline auto KnownSimFilePaths::EFOns()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownSimFilePathsStatics const&), KnownSimFilePaths, IKnownSimFilePathsStatics>([](IKnownSimFilePathsStatics const& f) { return f.EFOns(); });
    }
    inline auto KnownSimFilePaths::EFSpn()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownSimFilePathsStatics const&), KnownSimFilePaths, IKnownSimFilePathsStatics>([](IKnownSimFilePathsStatics const& f) { return f.EFSpn(); });
    }
    inline auto KnownSimFilePaths::Gid1()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownSimFilePathsStatics const&), KnownSimFilePaths, IKnownSimFilePathsStatics>([](IKnownSimFilePathsStatics const& f) { return f.Gid1(); });
    }
    inline auto KnownSimFilePaths::Gid2()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownSimFilePathsStatics const&), KnownSimFilePaths, IKnownSimFilePathsStatics>([](IKnownSimFilePathsStatics const& f) { return f.Gid2(); });
    }
    inline auto KnownUSimFilePaths::EFSpn()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownUSimFilePathsStatics const&), KnownUSimFilePaths, IKnownUSimFilePathsStatics>([](IKnownUSimFilePathsStatics const& f) { return f.EFSpn(); });
    }
    inline auto KnownUSimFilePaths::EFOpl()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownUSimFilePathsStatics const&), KnownUSimFilePaths, IKnownUSimFilePathsStatics>([](IKnownUSimFilePathsStatics const& f) { return f.EFOpl(); });
    }
    inline auto KnownUSimFilePaths::EFPnn()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownUSimFilePathsStatics const&), KnownUSimFilePaths, IKnownUSimFilePathsStatics>([](IKnownUSimFilePathsStatics const& f) { return f.EFPnn(); });
    }
    inline auto KnownUSimFilePaths::Gid1()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownUSimFilePathsStatics const&), KnownUSimFilePaths, IKnownUSimFilePathsStatics>([](IKnownUSimFilePathsStatics const& f) { return f.Gid1(); });
    }
    inline auto KnownUSimFilePaths::Gid2()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<uint32_t>(*)(IKnownUSimFilePathsStatics const&), KnownUSimFilePaths, IKnownUSimFilePathsStatics>([](IKnownUSimFilePathsStatics const& f) { return f.Gid2(); });
    }
    inline auto MobileBroadbandAccount::AvailableNetworkAccountIds()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<hstring>(*)(IMobileBroadbandAccountStatics const&), MobileBroadbandAccount, IMobileBroadbandAccountStatics>([](IMobileBroadbandAccountStatics const& f) { return f.AvailableNetworkAccountIds(); });
    }
    inline auto MobileBroadbandAccount::CreateFromNetworkAccountId(param::hstring const& networkAccountId)
    {
        return impl::call_factory<MobileBroadbandAccount, IMobileBroadbandAccountStatics>([&](IMobileBroadbandAccountStatics const& f) { return f.CreateFromNetworkAccountId(networkAccountId); });
    }
    inline MobileBroadbandAccountWatcher::MobileBroadbandAccountWatcher() :
        MobileBroadbandAccountWatcher(impl::call_factory_cast<MobileBroadbandAccountWatcher(*)(llm::OS::Foundation::IActivationFactory const&), MobileBroadbandAccountWatcher>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<MobileBroadbandAccountWatcher>(); }))
    {
    }
    inline MobileBroadbandAntennaSar::MobileBroadbandAntennaSar(int32_t antennaIndex, int32_t sarBackoffIndex) :
        MobileBroadbandAntennaSar(impl::call_factory<MobileBroadbandAntennaSar, IMobileBroadbandAntennaSarFactory>([&](IMobileBroadbandAntennaSarFactory const& f) { return f.CreateWithIndex(antennaIndex, sarBackoffIndex); }))
    {
    }
    inline auto MobileBroadbandModem::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IMobileBroadbandModemStatics const&), MobileBroadbandModem, IMobileBroadbandModemStatics>([](IMobileBroadbandModemStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto MobileBroadbandModem::FromId(param::hstring const& deviceId)
    {
        return impl::call_factory<MobileBroadbandModem, IMobileBroadbandModemStatics>([&](IMobileBroadbandModemStatics const& f) { return f.FromId(deviceId); });
    }
    inline auto MobileBroadbandModem::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Networking::NetworkOperators::MobileBroadbandModem(*)(IMobileBroadbandModemStatics const&), MobileBroadbandModem, IMobileBroadbandModemStatics>([](IMobileBroadbandModemStatics const& f) { return f.GetDefault(); });
    }
    inline MobileBroadbandModemIsolation::MobileBroadbandModemIsolation(param::hstring const& modemDeviceId, param::hstring const& ruleGroupId) :
        MobileBroadbandModemIsolation(impl::call_factory<MobileBroadbandModemIsolation, IMobileBroadbandModemIsolationFactory>([&](IMobileBroadbandModemIsolationFactory const& f) { return f.Create(modemDeviceId, ruleGroupId); }))
    {
    }
    inline NetworkOperatorTetheringAccessPointConfiguration::NetworkOperatorTetheringAccessPointConfiguration() :
        NetworkOperatorTetheringAccessPointConfiguration(impl::call_factory_cast<NetworkOperatorTetheringAccessPointConfiguration(*)(llm::OS::Foundation::IActivationFactory const&), NetworkOperatorTetheringAccessPointConfiguration>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<NetworkOperatorTetheringAccessPointConfiguration>(); }))
    {
    }
    inline auto NetworkOperatorTetheringManager::GetTetheringCapability(param::hstring const& networkAccountId)
    {
        return impl::call_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics>([&](INetworkOperatorTetheringManagerStatics const& f) { return f.GetTetheringCapability(networkAccountId); });
    }
    inline auto NetworkOperatorTetheringManager::CreateFromNetworkAccountId(param::hstring const& networkAccountId)
    {
        return impl::call_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics>([&](INetworkOperatorTetheringManagerStatics const& f) { return f.CreateFromNetworkAccountId(networkAccountId); });
    }
    inline auto NetworkOperatorTetheringManager::GetTetheringCapabilityFromConnectionProfile(llm::OS::Networking::Connectivity::ConnectionProfile const& profile)
    {
        return impl::call_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics2>([&](INetworkOperatorTetheringManagerStatics2 const& f) { return f.GetTetheringCapabilityFromConnectionProfile(profile); });
    }
    inline auto NetworkOperatorTetheringManager::CreateFromConnectionProfile(llm::OS::Networking::Connectivity::ConnectionProfile const& profile)
    {
        return impl::call_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics2>([&](INetworkOperatorTetheringManagerStatics2 const& f) { return f.CreateFromConnectionProfile(profile); });
    }
    inline auto NetworkOperatorTetheringManager::CreateFromConnectionProfile(llm::OS::Networking::Connectivity::ConnectionProfile const& profile, llm::OS::Networking::Connectivity::NetworkAdapter const& adapter)
    {
        return impl::call_factory<NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics3>([&](INetworkOperatorTetheringManagerStatics3 const& f) { return f.CreateFromConnectionProfile(profile, adapter); });
    }
    inline auto NetworkOperatorTetheringManager::IsNoConnectionsTimeoutEnabled()
    {
        return impl::call_factory_cast<bool(*)(INetworkOperatorTetheringManagerStatics4 const&), NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics4>([](INetworkOperatorTetheringManagerStatics4 const& f) { return f.IsNoConnectionsTimeoutEnabled(); });
    }
    inline auto NetworkOperatorTetheringManager::EnableNoConnectionsTimeout()
    {
        impl::call_factory_cast<void(*)(INetworkOperatorTetheringManagerStatics4 const&), NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics4>([](INetworkOperatorTetheringManagerStatics4 const& f) { return f.EnableNoConnectionsTimeout(); });
    }
    inline auto NetworkOperatorTetheringManager::EnableNoConnectionsTimeoutAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncAction(*)(INetworkOperatorTetheringManagerStatics4 const&), NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics4>([](INetworkOperatorTetheringManagerStatics4 const& f) { return f.EnableNoConnectionsTimeoutAsync(); });
    }
    inline auto NetworkOperatorTetheringManager::DisableNoConnectionsTimeout()
    {
        impl::call_factory_cast<void(*)(INetworkOperatorTetheringManagerStatics4 const&), NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics4>([](INetworkOperatorTetheringManagerStatics4 const& f) { return f.DisableNoConnectionsTimeout(); });
    }
    inline auto NetworkOperatorTetheringManager::DisableNoConnectionsTimeoutAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncAction(*)(INetworkOperatorTetheringManagerStatics4 const&), NetworkOperatorTetheringManager, INetworkOperatorTetheringManagerStatics4>([](INetworkOperatorTetheringManagerStatics4 const& f) { return f.DisableNoConnectionsTimeoutAsync(); });
    }
    inline ProvisioningAgent::ProvisioningAgent() :
        ProvisioningAgent(impl::call_factory_cast<ProvisioningAgent(*)(llm::OS::Foundation::IActivationFactory const&), ProvisioningAgent>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<ProvisioningAgent>(); }))
    {
    }
    inline auto ProvisioningAgent::CreateFromNetworkAccountId(param::hstring const& networkAccountId)
    {
        return impl::call_factory<ProvisioningAgent, IProvisioningAgentStaticMethods>([&](IProvisioningAgentStaticMethods const& f) { return f.CreateFromNetworkAccountId(networkAccountId); });
    }
    inline UssdMessage::UssdMessage(param::hstring const& messageText) :
        UssdMessage(impl::call_factory<UssdMessage, IUssdMessageFactory>([&](IUssdMessageFactory const& f) { return f.CreateMessage(messageText); }))
    {
    }
    inline auto UssdSession::CreateFromNetworkAccountId(param::hstring const& networkAccountId)
    {
        return impl::call_factory<UssdSession, IUssdSessionStatics>([&](IUssdSessionStatics const& f) { return f.CreateFromNetworkAccountId(networkAccountId); });
    }
    inline auto UssdSession::CreateFromNetworkInterfaceId(param::hstring const& networkInterfaceId)
    {
        return impl::call_factory<UssdSession, IUssdSessionStatics>([&](IUssdSessionStatics const& f) { return f.CreateFromNetworkInterfaceId(networkInterfaceId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESim> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESim2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESim3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimDiscoverEvent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimDiscoverResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimDownloadProfileMetadataResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimPolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimProfileMetadata> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimProfilePolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimServiceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IESimWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IFdnAccessManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContext2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IHotspotAuthenticationContextStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IHotspotAuthenticationEventDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IHotspotCredentialsAuthenticationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IKnownCSimFilePathsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IKnownRuimFilePathsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IKnownSimFilePathsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IKnownUSimFilePathsStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccount3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAccountWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandAntennaSarFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellCdma> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellGsm> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellLte> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellNR> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellTdscdma> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellUmts> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCellsInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandCurrentSlotIndexChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceInformation4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceService> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceCommandSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceDataSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandDeviceServiceTriggerDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModem2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModem3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModem4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModemConfiguration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModemIsolationFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandModemStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandNetwork3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandNetworkRegistrationStateChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPco> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPcoDataChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPin> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPinLockStateChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPinManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandPinOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandRadioStateChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandSarManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotInfoChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandSlotManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandTransmissionStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandUicc> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppReadRecordResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppRecordDetailsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IMobileBroadbandUiccAppsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorDataUsageTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorNotificationEventDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringAccessPointConfiguration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClient> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringClientManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringEntitlementCheck> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringManagerStatics4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::INetworkOperatorTetheringOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IProvisionFromXmlDocumentResults> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IProvisionedProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IProvisioningAgent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IProvisioningAgentStaticMethods> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ITetheringEntitlementCheckTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IUssdMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IUssdMessageFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IUssdReply> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IUssdSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::IUssdSessionStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESim> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimAddedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimDiscoverEvent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimDiscoverResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimDownloadProfileMetadataResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimPolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimProfileMetadata> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimProfilePolicy> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimRemovedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimServiceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ESimWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::FdnAccessManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::HotspotAuthenticationContext> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::HotspotAuthenticationEventDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::HotspotCredentialsAuthenticationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::KnownCSimFilePaths> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::KnownRuimFilePaths> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::KnownSimFilePaths> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::KnownUSimFilePaths> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandAccount> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountUpdatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandAccountWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandAntennaSar> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellCdma> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellGsm> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellLte> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellNR> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellTdscdma> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellUmts> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCellsInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandCurrentSlotIndexChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceService> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceCommandSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceDataSession> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandDeviceServiceTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandModem> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandModemConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandModemIsolation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandNetwork> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandNetworkRegistrationStateChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPco> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPcoDataChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPin> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockStateChange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPinLockStateChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPinManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandPinOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioStateChange> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandRadioStateChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandSarManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotInfoChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandSlotManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandTransmissionStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandUicc> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccApp> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppReadRecordResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppRecordDetailsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::MobileBroadbandUiccAppsResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::NetworkOperatorDataUsageTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::NetworkOperatorNotificationEventDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringAccessPointConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringClient> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringManager> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::NetworkOperatorTetheringOperationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ProvisionFromXmlDocumentResults> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ProvisionedProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::ProvisioningAgent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::TetheringEntitlementCheckTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::UssdMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::UssdReply> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::NetworkOperators::UssdSession> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
