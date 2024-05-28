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
#ifndef LLM_OS_Devices_Enumeration_H
#define LLM_OS_Devices_Enumeration_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.ApplicationModel.Background.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.UI.2.h"
#include "llm/impl/Windows.UI.Popups.2.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceAccessStatus) consume_Windows_Devices_Enumeration_IDeviceAccessChangedEventArgs<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceAccessStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDeviceAccessChangedEventArgs2<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs2)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceAccessInformation<D>::AccessChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceAccessInformation, llm::OS::Devices::Enumeration::DeviceAccessChangedEventArgs> const& handler) const
    {
        llm::event_token cookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessInformation)->add_AccessChanged(*(void**)(&handler), put_abi(cookie)));
        return cookie;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceAccessInformation<D>::AccessChanged_revoker consume_Windows_Devices_Enumeration_IDeviceAccessInformation<D>::AccessChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceAccessInformation, llm::OS::Devices::Enumeration::DeviceAccessChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, AccessChanged_revoker>(this, AccessChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceAccessInformation<D>::AccessChanged(llm::event_token const& cookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessInformation)->remove_AccessChanged(impl::bind_in(cookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceAccessStatus) consume_Windows_Devices_Enumeration_IDeviceAccessInformation<D>::CurrentStatus() const
    {
        llm::OS::Devices::Enumeration::DeviceAccessStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessInformation)->get_CurrentStatus(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceAccessInformation) consume_Windows_Devices_Enumeration_IDeviceAccessInformationStatics<D>::CreateFromId(param::hstring const& deviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessInformationStatics)->CreateFromId(*(void**)(&deviceId), &value));
        return llm::OS::Devices::Enumeration::DeviceAccessInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceAccessInformation) consume_Windows_Devices_Enumeration_IDeviceAccessInformationStatics<D>::CreateFromDeviceClassId(llm::guid const& deviceClassId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessInformationStatics)->CreateFromDeviceClassId(impl::bind_in(deviceClassId), &value));
        return llm::OS::Devices::Enumeration::DeviceAccessInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceAccessInformation) consume_Windows_Devices_Enumeration_IDeviceAccessInformationStatics<D>::CreateFromDeviceClass(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceAccessInformationStatics)->CreateFromDeviceClass(static_cast<int32_t>(deviceClass), &value));
        return llm::OS::Devices::Enumeration::DeviceAccessInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDeviceConnectionChangeTriggerDetails<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Devices_Enumeration_IDeviceDisconnectButtonClickedEventArgs<D>::Device() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs)->get_Device(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::IsDefault() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->get_IsDefault(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::EnclosureLocation) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::EnclosureLocation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->get_EnclosureLocation(&value));
        return llm::OS::Devices::Enumeration::EnclosureLocation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::Update(llm::OS::Devices::Enumeration::DeviceInformationUpdate const& updateInfo) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->Update(*(void**)(&updateInfo)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceThumbnail>) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::GetThumbnailAsync() const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->GetThumbnailAsync(&asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceThumbnail>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceThumbnail>) consume_Windows_Devices_Enumeration_IDeviceInformation<D>::GetGlyphThumbnailAsync() const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation)->GetGlyphThumbnailAsync(&asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceThumbnail>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformationKind) consume_Windows_Devices_Enumeration_IDeviceInformation2<D>::Kind() const
    {
        llm::OS::Devices::Enumeration::DeviceInformationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation2)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformationPairing) consume_Windows_Devices_Enumeration_IDeviceInformation2<D>::Pairing() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformation2)->get_Pairing(&value));
        return llm::OS::Devices::Enumeration::DeviceInformationPairing{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairAsync(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing)->PairAsync(static_cast<uint32_t>(pairingKindsSupported), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairAsync(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported, llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing)->PairWithProtectionLevelAsync(static_cast<uint32_t>(pairingKindsSupported), static_cast<int32_t>(minProtectionLevel), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairAsync(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported, llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel, llm::OS::Devices::Enumeration::IDevicePairingSettings const& devicePairingSettings) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing)->PairWithProtectionLevelAndSettingsAsync(static_cast<uint32_t>(pairingKindsSupported), static_cast<int32_t>(minProtectionLevel), *(void**)(&devicePairingSettings), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairingRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceInformationCustomPairing, llm::OS::Devices::Enumeration::DevicePairingRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing)->add_PairingRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairingRequested_revoker consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairingRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceInformationCustomPairing, llm::OS::Devices::Enumeration::DevicePairingRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, PairingRequested_revoker>(this, PairingRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceInformationCustomPairing<D>::PairingRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing)->remove_PairingRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IDeviceInformationPairing<D>::IsPaired() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing)->get_IsPaired(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IDeviceInformationPairing<D>::CanPair() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing)->get_CanPair(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationPairing<D>::PairAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing)->PairAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationPairing<D>::PairAsync(llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing)->PairWithProtectionLevelAsync(static_cast<int32_t>(minProtectionLevel), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePairingProtectionLevel) consume_Windows_Devices_Enumeration_IDeviceInformationPairing2<D>::ProtectionLevel() const
    {
        llm::OS::Devices::Enumeration::DevicePairingProtectionLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing2)->get_ProtectionLevel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformationCustomPairing) consume_Windows_Devices_Enumeration_IDeviceInformationPairing2<D>::Custom() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing2)->get_Custom(&value));
        return llm::OS::Devices::Enumeration::DeviceInformationCustomPairing{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationPairing2<D>::PairAsync(llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel, llm::OS::Devices::Enumeration::IDevicePairingSettings const& devicePairingSettings) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing2)->PairWithProtectionLevelAndSettingsAsync(static_cast<int32_t>(minProtectionLevel), *(void**)(&devicePairingSettings), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceUnpairingResult>) consume_Windows_Devices_Enumeration_IDeviceInformationPairing2<D>::UnpairAsync() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairing2)->UnpairAsync(&result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceUnpairingResult>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IDeviceInformationPairingStatics<D>::TryRegisterForAllInboundPairingRequests(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics)->TryRegisterForAllInboundPairingRequests(static_cast<uint32_t>(pairingKindsSupported), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IDeviceInformationPairingStatics2<D>::TryRegisterForAllInboundPairingRequestsWithProtectionLevel(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported, llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel) const
    {
        bool result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics2)->TryRegisterForAllInboundPairingRequestsWithProtectionLevel(static_cast<uint32_t>(pairingKindsSupported), static_cast<int32_t>(minProtectionLevel), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::CreateFromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->CreateFromIdAsync(*(void**)(&deviceId), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::CreateFromIdAsync(param::hstring const& deviceId, param::async_iterable<hstring> const& additionalProperties) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->CreateFromIdAsyncAdditionalProperties(*(void**)(&deviceId), *(void**)(&additionalProperties), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::FindAllAsync() const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->FindAllAsync(&asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::FindAllAsync(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->FindAllAsyncDeviceClass(static_cast<int32_t>(deviceClass), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::FindAllAsync(param::hstring const& aqsFilter) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->FindAllAsyncAqsFilter(*(void**)(&aqsFilter), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::FindAllAsync(param::hstring const& aqsFilter, param::async_iterable<hstring> const& additionalProperties) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->FindAllAsyncAqsFilterAndAdditionalProperties(*(void**)(&aqsFilter), *(void**)(&additionalProperties), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcher) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::CreateWatcher() const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->CreateWatcher(&watcher));
        return llm::OS::Devices::Enumeration::DeviceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcher) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::CreateWatcher(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass) const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->CreateWatcherDeviceClass(static_cast<int32_t>(deviceClass), &watcher));
        return llm::OS::Devices::Enumeration::DeviceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcher) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::CreateWatcher(param::hstring const& aqsFilter) const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->CreateWatcherAqsFilter(*(void**)(&aqsFilter), &watcher));
        return llm::OS::Devices::Enumeration::DeviceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcher) consume_Windows_Devices_Enumeration_IDeviceInformationStatics<D>::CreateWatcher(param::hstring const& aqsFilter, param::iterable<hstring> const& additionalProperties) const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics)->CreateWatcherAqsFilterAndAdditionalProperties(*(void**)(&aqsFilter), *(void**)(&additionalProperties), &watcher));
        return llm::OS::Devices::Enumeration::DeviceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDeviceInformationStatics2<D>::GetAqsFilterFromDeviceClass(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass) const
    {
        void* aqsFilter{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics2)->GetAqsFilterFromDeviceClass(static_cast<int32_t>(deviceClass), &aqsFilter));
        return hstring{ aqsFilter, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics2<D>::CreateFromIdAsync(param::hstring const& deviceId, param::async_iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics2)->CreateFromIdAsyncWithKindAndAdditionalProperties(*(void**)(&deviceId), *(void**)(&additionalProperties), static_cast<int32_t>(kind), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>) consume_Windows_Devices_Enumeration_IDeviceInformationStatics2<D>::FindAllAsync(param::hstring const& aqsFilter, param::async_iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics2)->FindAllAsyncWithKindAqsFilterAndAdditionalProperties(*(void**)(&aqsFilter), *(void**)(&additionalProperties), static_cast<int32_t>(kind), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcher) consume_Windows_Devices_Enumeration_IDeviceInformationStatics2<D>::CreateWatcher(param::hstring const& aqsFilter, param::iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind) const
    {
        void* watcher{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationStatics2)->CreateWatcherWithKindAqsFilterAndAdditionalProperties(*(void**)(&aqsFilter), *(void**)(&additionalProperties), static_cast<int32_t>(kind), &watcher));
        return llm::OS::Devices::Enumeration::DeviceWatcher{ watcher, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDeviceInformationUpdate<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationUpdate)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>) consume_Windows_Devices_Enumeration_IDeviceInformationUpdate<D>::Properties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationUpdate)->get_Properties(&value));
        return llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformationKind) consume_Windows_Devices_Enumeration_IDeviceInformationUpdate2<D>::Kind() const
    {
        llm::OS::Devices::Enumeration::DeviceInformationKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceInformationUpdate2)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs<D>::DeviceInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs)->get_DeviceInformation(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePairingKinds) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs<D>::PairingKind() const
    {
        llm::OS::Devices::Enumeration::DevicePairingKinds value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs)->get_PairingKind(reinterpret_cast<uint32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs<D>::Pin() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs)->get_Pin(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs<D>::Accept() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs)->Accept());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs<D>::Accept(param::hstring const& pin) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs)->AcceptWithPin(*(void**)(&pin)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Deferral) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs<D>::GetDeferral() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs)->GetDeferral(&result));
        return llm::OS::Foundation::Deferral{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePairingRequestedEventArgs2<D>::AcceptWithPasswordCredential(llm::OS::Security::Credentials::PasswordCredential const& passwordCredential) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs2)->AcceptWithPasswordCredential(*(void**)(&passwordCredential)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePairingResultStatus) consume_Windows_Devices_Enumeration_IDevicePairingResult<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DevicePairingResultStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingResult)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePairingProtectionLevel) consume_Windows_Devices_Enumeration_IDevicePairingResult<D>::ProtectionLevelUsed() const
    {
        llm::OS::Devices::Enumeration::DevicePairingProtectionLevel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePairingResult)->get_ProtectionLevelUsed(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePickerFilter) consume_Windows_Devices_Enumeration_IDevicePicker<D>::Filter() const
    {
        void* filter{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->get_Filter(&filter));
        return llm::OS::Devices::Enumeration::DevicePickerFilter{ filter, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePickerAppearance) consume_Windows_Devices_Enumeration_IDevicePicker<D>::Appearance() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->get_Appearance(&value));
        return llm::OS::Devices::Enumeration::DevicePickerAppearance{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Enumeration_IDevicePicker<D>::RequestedProperties() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->get_RequestedProperties(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDevicePicker<D>::DeviceSelected(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Devices::Enumeration::DeviceSelectedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->add_DeviceSelected(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDevicePicker<D>::DeviceSelected_revoker consume_Windows_Devices_Enumeration_IDevicePicker<D>::DeviceSelected(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Devices::Enumeration::DeviceSelectedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DeviceSelected_revoker>(this, DeviceSelected(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::DeviceSelected(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->remove_DeviceSelected(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDevicePicker<D>::DisconnectButtonClicked(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->add_DisconnectButtonClicked(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDevicePicker<D>::DisconnectButtonClicked_revoker consume_Windows_Devices_Enumeration_IDevicePicker<D>::DisconnectButtonClicked(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, DisconnectButtonClicked_revoker>(this, DisconnectButtonClicked(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::DisconnectButtonClicked(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->remove_DisconnectButtonClicked(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDevicePicker<D>::DevicePickerDismissed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->add_DevicePickerDismissed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDevicePicker<D>::DevicePickerDismissed_revoker consume_Windows_Devices_Enumeration_IDevicePicker<D>::DevicePickerDismissed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, DevicePickerDismissed_revoker>(this, DevicePickerDismissed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::DevicePickerDismissed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->remove_DevicePickerDismissed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::Show(llm::OS::Foundation::Rect const& selection) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->Show(impl::bind_in(selection)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::Show(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& placement) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->ShowWithPlacement(impl::bind_in(selection), static_cast<int32_t>(placement)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>) consume_Windows_Devices_Enumeration_IDevicePicker<D>::PickSingleDeviceAsync(llm::OS::Foundation::Rect const& selection) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->PickSingleDeviceAsync(impl::bind_in(selection), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>) consume_Windows_Devices_Enumeration_IDevicePicker<D>::PickSingleDeviceAsync(llm::OS::Foundation::Rect const& selection, llm::OS::UI::Popups::Placement const& placement) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->PickSingleDeviceAsyncWithPlacement(impl::bind_in(selection), static_cast<int32_t>(placement), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::Hide() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->Hide());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePicker<D>::SetDisplayStatus(llm::OS::Devices::Enumeration::DeviceInformation const& device, param::hstring const& status, llm::OS::Devices::Enumeration::DevicePickerDisplayStatusOptions const& options) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePicker)->SetDisplayStatus(*(void**)(&device), *(void**)(&status), static_cast<uint32_t>(options)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::Title() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_Title(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::Title(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_Title(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::ForegroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_ForegroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::ForegroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_ForegroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::BackgroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_BackgroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::BackgroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_BackgroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::AccentColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_AccentColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::AccentColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_AccentColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::SelectedForegroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_SelectedForegroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::SelectedForegroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_SelectedForegroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::SelectedBackgroundColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_SelectedBackgroundColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::SelectedBackgroundColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_SelectedBackgroundColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::UI::Color) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::SelectedAccentColor() const
    {
        llm::OS::UI::Color value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->get_SelectedAccentColor(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDevicePickerAppearance<D>::SelectedAccentColor(llm::OS::UI::Color const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerAppearance)->put_SelectedAccentColor(impl::bind_in(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Enumeration::DeviceClass>) consume_Windows_Devices_Enumeration_IDevicePickerFilter<D>::SupportedDeviceClasses() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerFilter)->get_SupportedDeviceClasses(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Enumeration::DeviceClass>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Enumeration_IDevicePickerFilter<D>::SupportedDeviceSelectors() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDevicePickerFilter)->get_SupportedDeviceSelectors(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Devices_Enumeration_IDeviceSelectedEventArgs<D>::SelectedDevice() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceSelectedEventArgs)->get_SelectedDevice(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceUnpairingResultStatus) consume_Windows_Devices_Enumeration_IDeviceUnpairingResult<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceUnpairingResultStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceUnpairingResult)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Added(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformation> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->add_Added(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Added_revoker consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Added(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformation> const& handler) const
    {
        return impl::make_event_revoker<D, Added_revoker>(this, Added(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Added(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->remove_Added(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Updated(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformationUpdate> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->add_Updated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Updated_revoker consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Updated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformationUpdate> const& handler) const
    {
        return impl::make_event_revoker<D, Updated_revoker>(this, Updated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Updated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->remove_Updated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Removed(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformationUpdate> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->add_Removed(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Removed_revoker consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Removed(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformationUpdate> const& handler) const
    {
        return impl::make_event_revoker<D, Removed_revoker>(this, Removed(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Removed(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->remove_Removed(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::EnumerationCompleted(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->add_EnumerationCompleted(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::EnumerationCompleted_revoker consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::EnumerationCompleted(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, EnumerationCompleted_revoker>(this, EnumerationCompleted(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::EnumerationCompleted(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->remove_EnumerationCompleted(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Stopped(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->add_Stopped(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Stopped_revoker consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Stopped(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, Stopped_revoker>(this, Stopped(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Stopped(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->remove_Stopped(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcherStatus) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Status() const
    {
        llm::OS::Devices::Enumeration::DeviceWatcherStatus status{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->get_Status(reinterpret_cast<int32_t*>(&status)));
        return status;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Enumeration_IDeviceWatcher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::ApplicationModel::Background::DeviceWatcherTrigger) consume_Windows_Devices_Enumeration_IDeviceWatcher2<D>::GetBackgroundTrigger(param::iterable<llm::OS::Devices::Enumeration::DeviceWatcherEventKind> const& requestedEventKinds) const
    {
        void* trigger{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcher2)->GetBackgroundTrigger(*(void**)(&requestedEventKinds), &trigger));
        return llm::OS::ApplicationModel::Background::DeviceWatcherTrigger{ trigger, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceWatcherEventKind) consume_Windows_Devices_Enumeration_IDeviceWatcherEvent<D>::Kind() const
    {
        llm::OS::Devices::Enumeration::DeviceWatcherEventKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcherEvent)->get_Kind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Devices_Enumeration_IDeviceWatcherEvent<D>::DeviceInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcherEvent)->get_DeviceInformation(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformationUpdate) consume_Windows_Devices_Enumeration_IDeviceWatcherEvent<D>::DeviceInformationUpdate() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcherEvent)->get_DeviceInformationUpdate(&value));
        return llm::OS::Devices::Enumeration::DeviceInformationUpdate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::DeviceWatcherEvent>) consume_Windows_Devices_Enumeration_IDeviceWatcherTriggerDetails<D>::DeviceWatcherEvents() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IDeviceWatcherTriggerDetails)->get_DeviceWatcherEvents(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::DeviceWatcherEvent>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IEnclosureLocation<D>::InDock() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IEnclosureLocation)->get_InDock(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Enumeration_IEnclosureLocation<D>::InLid() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IEnclosureLocation)->get_InLid(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::Panel) consume_Windows_Devices_Enumeration_IEnclosureLocation<D>::Panel() const
    {
        llm::OS::Devices::Enumeration::Panel value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IEnclosureLocation)->get_Panel(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Enumeration_IEnclosureLocation2<D>::RotationAngleInDegreesClockwise() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Enumeration::IEnclosureLocation2)->get_RotationAngleInDegreesClockwise(&value));
        return value;
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceAccessStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs2>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceAccessInformation> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceAccessInformation>
    {
        int32_t __stdcall add_AccessChanged(void* handler, llm::event_token* cookie) noexcept final try
        {
            zero_abi<llm::event_token>(cookie);
            typename D::abi_guard guard(this->shim());
            *cookie = detach_from<llm::event_token>(this->shim().AccessChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceAccessInformation, llm::OS::Devices::Enumeration::DeviceAccessChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AccessChanged(llm::event_token cookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccessChanged(*reinterpret_cast<llm::event_token const*>(&cookie));
            return 0;
        }
        int32_t __stdcall get_CurrentStatus(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Devices::Enumeration::DeviceAccessStatus>(this->shim().CurrentStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceAccessInformationStatics> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceAccessInformationStatics>
    {
        int32_t __stdcall CreateFromId(void* deviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceAccessInformation>(this->shim().CreateFromId(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromDeviceClassId(llm::guid deviceClassId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceAccessInformation>(this->shim().CreateFromDeviceClassId(*reinterpret_cast<llm::guid const*>(&deviceClassId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromDeviceClass(int32_t deviceClass, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceAccessInformation>(this->shim().CreateFromDeviceClass(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceClass const*>(&deviceClass)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs>
    {
        int32_t __stdcall get_Device(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().Device());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformation> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformation>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Name(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Name());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDefault(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EnclosureLocation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::EnclosureLocation>(this->shim().EnclosureLocation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Update(void* updateInfo) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Update(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformationUpdate const*>(&updateInfo));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetThumbnailAsync(void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceThumbnail>>(this->shim().GetThumbnailAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetGlyphThumbnailAsync(void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceThumbnail>>(this->shim().GetGlyphThumbnailAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformation2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformation2>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformationKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Pairing(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformationPairing>(this->shim().Pairing());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing>
    {
        int32_t __stdcall PairAsync(uint32_t pairingKindsSupported, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>>(this->shim().PairAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingKinds const*>(&pairingKindsSupported)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PairWithProtectionLevelAsync(uint32_t pairingKindsSupported, int32_t minProtectionLevel, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>>(this->shim().PairAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingKinds const*>(&pairingKindsSupported), *reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const*>(&minProtectionLevel)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PairWithProtectionLevelAndSettingsAsync(uint32_t pairingKindsSupported, int32_t minProtectionLevel, void* devicePairingSettings, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>>(this->shim().PairAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingKinds const*>(&pairingKindsSupported), *reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const*>(&minProtectionLevel), *reinterpret_cast<llm::OS::Devices::Enumeration::IDevicePairingSettings const*>(&devicePairingSettings)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_PairingRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().PairingRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceInformationCustomPairing, llm::OS::Devices::Enumeration::DevicePairingRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_PairingRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PairingRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationPairing> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationPairing>
    {
        int32_t __stdcall get_IsPaired(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsPaired());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CanPair(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().CanPair());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PairAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>>(this->shim().PairAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PairWithProtectionLevelAsync(int32_t minProtectionLevel, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>>(this->shim().PairAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const*>(&minProtectionLevel)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationPairing2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationPairing2>
    {
        int32_t __stdcall get_ProtectionLevel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel>(this->shim().ProtectionLevel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Custom(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformationCustomPairing>(this->shim().Custom());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PairWithProtectionLevelAndSettingsAsync(int32_t minProtectionLevel, void* devicePairingSettings, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DevicePairingResult>>(this->shim().PairAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const*>(&minProtectionLevel), *reinterpret_cast<llm::OS::Devices::Enumeration::IDevicePairingSettings const*>(&devicePairingSettings)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UnpairAsync(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceUnpairingResult>>(this->shim().UnpairAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics>
    {
        int32_t __stdcall TryRegisterForAllInboundPairingRequests(uint32_t pairingKindsSupported, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryRegisterForAllInboundPairingRequests(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingKinds const*>(&pairingKindsSupported)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics2>
    {
        int32_t __stdcall TryRegisterForAllInboundPairingRequestsWithProtectionLevel(uint32_t pairingKindsSupported, int32_t minProtectionLevel, bool* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<bool>(this->shim().TryRegisterForAllInboundPairingRequestsWithProtectionLevel(*reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingKinds const*>(&pairingKindsSupported), *reinterpret_cast<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const*>(&minProtectionLevel)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationStatics> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationStatics>
    {
        int32_t __stdcall CreateFromIdAsync(void* deviceId, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>>(this->shim().CreateFromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromIdAsyncAdditionalProperties(void* deviceId, void* additionalProperties, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>>(this->shim().CreateFromIdAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&additionalProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsync(void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>>(this->shim().FindAllAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncDeviceClass(int32_t deviceClass, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>>(this->shim().FindAllAsync(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceClass const*>(&deviceClass)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncAqsFilter(void* aqsFilter, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>>(this->shim().FindAllAsync(*reinterpret_cast<hstring const*>(&aqsFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncAqsFilterAndAdditionalProperties(void* aqsFilter, void* additionalProperties, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>>(this->shim().FindAllAsync(*reinterpret_cast<hstring const*>(&aqsFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&additionalProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcher(void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::DeviceWatcher>(this->shim().CreateWatcher());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherDeviceClass(int32_t deviceClass, void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::DeviceWatcher>(this->shim().CreateWatcher(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceClass const*>(&deviceClass)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherAqsFilter(void* aqsFilter, void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::DeviceWatcher>(this->shim().CreateWatcher(*reinterpret_cast<hstring const*>(&aqsFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherAqsFilterAndAdditionalProperties(void* aqsFilter, void* additionalProperties, void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::DeviceWatcher>(this->shim().CreateWatcher(*reinterpret_cast<hstring const*>(&aqsFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&additionalProperties)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationStatics2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationStatics2>
    {
        int32_t __stdcall GetAqsFilterFromDeviceClass(int32_t deviceClass, void** aqsFilter) noexcept final try
        {
            clear_abi(aqsFilter);
            typename D::abi_guard guard(this->shim());
            *aqsFilter = detach_from<hstring>(this->shim().GetAqsFilterFromDeviceClass(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceClass const*>(&deviceClass)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromIdAsyncWithKindAndAdditionalProperties(void* deviceId, void* additionalProperties, int32_t kind, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>>(this->shim().CreateFromIdAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&additionalProperties), *reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformationKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindAllAsyncWithKindAqsFilterAndAdditionalProperties(void* aqsFilter, void* additionalProperties, int32_t kind, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>>(this->shim().FindAllAsync(*reinterpret_cast<hstring const*>(&aqsFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&additionalProperties), *reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformationKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateWatcherWithKindAqsFilterAndAdditionalProperties(void* aqsFilter, void* additionalProperties, int32_t kind, void** watcher) noexcept final try
        {
            clear_abi(watcher);
            typename D::abi_guard guard(this->shim());
            *watcher = detach_from<llm::OS::Devices::Enumeration::DeviceWatcher>(this->shim().CreateWatcher(*reinterpret_cast<hstring const*>(&aqsFilter), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<hstring> const*>(&additionalProperties), *reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformationKind const*>(&kind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationUpdate> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationUpdate>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Properties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMapView<hstring, llm::OS::Foundation::IInspectable>>(this->shim().Properties());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceInformationUpdate2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceInformationUpdate2>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformationKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs>
    {
        int32_t __stdcall get_DeviceInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().DeviceInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PairingKind(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DevicePairingKinds>(this->shim().PairingKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Pin(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Pin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Accept() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AcceptWithPin(void* pin) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept(*reinterpret_cast<hstring const*>(&pin));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDeferral(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Deferral>(this->shim().GetDeferral());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs2> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs2>
    {
        int32_t __stdcall AcceptWithPasswordCredential(void* passwordCredential) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AcceptWithPasswordCredential(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePairingResult> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePairingResult>
    {
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Devices::Enumeration::DevicePairingResultStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProtectionLevelUsed(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DevicePairingProtectionLevel>(this->shim().ProtectionLevelUsed());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePairingSettings> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePairingSettings>
    {
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePicker> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePicker>
    {
        int32_t __stdcall get_Filter(void** filter) noexcept final try
        {
            clear_abi(filter);
            typename D::abi_guard guard(this->shim());
            *filter = detach_from<llm::OS::Devices::Enumeration::DevicePickerFilter>(this->shim().Filter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Appearance(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DevicePickerAppearance>(this->shim().Appearance());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RequestedProperties(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().RequestedProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DeviceSelected(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DeviceSelected(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Devices::Enumeration::DeviceSelectedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DeviceSelected(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceSelected(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DisconnectButtonClicked(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DisconnectButtonClicked(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DisconnectButtonClicked(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisconnectButtonClicked(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_DevicePickerDismissed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().DevicePickerDismissed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DevicePicker, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DevicePickerDismissed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DevicePickerDismissed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall Show(llm::OS::Foundation::Rect selection) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ShowWithPlacement(llm::OS::Foundation::Rect selection, int32_t placement) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Show(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&placement));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleDeviceAsync(llm::OS::Foundation::Rect selection, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>>(this->shim().PickSingleDeviceAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall PickSingleDeviceAsyncWithPlacement(llm::OS::Foundation::Rect selection, int32_t placement, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformation>>(this->shim().PickSingleDeviceAsync(*reinterpret_cast<llm::OS::Foundation::Rect const*>(&selection), *reinterpret_cast<llm::OS::UI::Popups::Placement const*>(&placement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Hide() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Hide();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetDisplayStatus(void* device, void* status, uint32_t options) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetDisplayStatus(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&device), *reinterpret_cast<hstring const*>(&status), *reinterpret_cast<llm::OS::Devices::Enumeration::DevicePickerDisplayStatusOptions const*>(&options));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePickerAppearance> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePickerAppearance>
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
        int32_t __stdcall get_ForegroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().ForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ForegroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ForegroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BackgroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().BackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BackgroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BackgroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AccentColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().AccentColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AccentColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AccentColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedForegroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().SelectedForegroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectedForegroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedForegroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedBackgroundColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().SelectedBackgroundColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectedBackgroundColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedBackgroundColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedAccentColor(struct struct_Windows_UI_Color* value) noexcept final try
        {
            zero_abi<llm::OS::UI::Color>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::UI::Color>(this->shim().SelectedAccentColor());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SelectedAccentColor(struct struct_Windows_UI_Color value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SelectedAccentColor(*reinterpret_cast<llm::OS::UI::Color const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDevicePickerFilter> : produce_base<D, llm::OS::Devices::Enumeration::IDevicePickerFilter>
    {
        int32_t __stdcall get_SupportedDeviceClasses(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Enumeration::DeviceClass>>(this->shim().SupportedDeviceClasses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedDeviceSelectors(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().SupportedDeviceSelectors());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceSelectedEventArgs> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceSelectedEventArgs>
    {
        int32_t __stdcall get_SelectedDevice(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().SelectedDevice());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceUnpairingResult> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceUnpairingResult>
    {
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Devices::Enumeration::DeviceUnpairingResultStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceWatcher> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceWatcher>
    {
        int32_t __stdcall add_Added(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Added(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformation> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Added(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Added(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Updated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Updated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformationUpdate> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Updated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Updated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Removed(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Removed(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Devices::Enumeration::DeviceInformationUpdate> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Removed(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Removed(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_EnumerationCompleted(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().EnumerationCompleted(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_EnumerationCompleted(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EnumerationCompleted(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall add_Stopped(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().Stopped(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Enumeration::DeviceWatcher, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_Stopped(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Stopped(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall get_Status(int32_t* status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *status = detach_from<llm::OS::Devices::Enumeration::DeviceWatcherStatus>(this->shim().Status());
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
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceWatcher2> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceWatcher2>
    {
        int32_t __stdcall GetBackgroundTrigger(void* requestedEventKinds, void** trigger) noexcept final try
        {
            clear_abi(trigger);
            typename D::abi_guard guard(this->shim());
            *trigger = detach_from<llm::OS::ApplicationModel::Background::DeviceWatcherTrigger>(this->shim().GetBackgroundTrigger(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Devices::Enumeration::DeviceWatcherEventKind> const*>(&requestedEventKinds)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceWatcherEvent> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceWatcherEvent>
    {
        int32_t __stdcall get_Kind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceWatcherEventKind>(this->shim().Kind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceInformation(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformation>(this->shim().DeviceInformation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceInformationUpdate(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::DeviceInformationUpdate>(this->shim().DeviceInformationUpdate());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IDeviceWatcherTriggerDetails> : produce_base<D, llm::OS::Devices::Enumeration::IDeviceWatcherTriggerDetails>
    {
        int32_t __stdcall get_DeviceWatcherEvents(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Enumeration::DeviceWatcherEvent>>(this->shim().DeviceWatcherEvents());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IEnclosureLocation> : produce_base<D, llm::OS::Devices::Enumeration::IEnclosureLocation>
    {
        int32_t __stdcall get_InDock(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().InDock());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InLid(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().InLid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Panel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Enumeration::Panel>(this->shim().Panel());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Enumeration::IEnclosureLocation2> : produce_base<D, llm::OS::Devices::Enumeration::IEnclosureLocation2>
    {
        int32_t __stdcall get_RotationAngleInDegreesClockwise(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().RotationAngleInDegreesClockwise());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Enumeration
{
    constexpr auto operator|(DevicePairingKinds const left, DevicePairingKinds const right) noexcept
    {
        return static_cast<DevicePairingKinds>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DevicePairingKinds& left, DevicePairingKinds const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DevicePairingKinds const left, DevicePairingKinds const right) noexcept
    {
        return static_cast<DevicePairingKinds>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DevicePairingKinds& left, DevicePairingKinds const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DevicePairingKinds const value) noexcept
    {
        return static_cast<DevicePairingKinds>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DevicePairingKinds const left, DevicePairingKinds const right) noexcept
    {
        return static_cast<DevicePairingKinds>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DevicePairingKinds& left, DevicePairingKinds const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    constexpr auto operator|(DevicePickerDisplayStatusOptions const left, DevicePickerDisplayStatusOptions const right) noexcept
    {
        return static_cast<DevicePickerDisplayStatusOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(DevicePickerDisplayStatusOptions& left, DevicePickerDisplayStatusOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(DevicePickerDisplayStatusOptions const left, DevicePickerDisplayStatusOptions const right) noexcept
    {
        return static_cast<DevicePickerDisplayStatusOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(DevicePickerDisplayStatusOptions& left, DevicePickerDisplayStatusOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(DevicePickerDisplayStatusOptions const value) noexcept
    {
        return static_cast<DevicePickerDisplayStatusOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(DevicePickerDisplayStatusOptions const left, DevicePickerDisplayStatusOptions const right) noexcept
    {
        return static_cast<DevicePickerDisplayStatusOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(DevicePickerDisplayStatusOptions& left, DevicePickerDisplayStatusOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto DeviceAccessInformation::CreateFromId(param::hstring const& deviceId)
    {
        return impl::call_factory<DeviceAccessInformation, IDeviceAccessInformationStatics>([&](IDeviceAccessInformationStatics const& f) { return f.CreateFromId(deviceId); });
    }
    inline auto DeviceAccessInformation::CreateFromDeviceClassId(llm::guid const& deviceClassId)
    {
        return impl::call_factory<DeviceAccessInformation, IDeviceAccessInformationStatics>([&](IDeviceAccessInformationStatics const& f) { return f.CreateFromDeviceClassId(deviceClassId); });
    }
    inline auto DeviceAccessInformation::CreateFromDeviceClass(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass)
    {
        return impl::call_factory<DeviceAccessInformation, IDeviceAccessInformationStatics>([&](IDeviceAccessInformationStatics const& f) { return f.CreateFromDeviceClass(deviceClass); });
    }
    inline auto DeviceInformation::CreateFromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.CreateFromIdAsync(deviceId); });
    }
    inline auto DeviceInformation::CreateFromIdAsync(param::hstring const& deviceId, param::async_iterable<hstring> const& additionalProperties)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.CreateFromIdAsync(deviceId, additionalProperties); });
    }
    inline auto DeviceInformation::FindAllAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Enumeration::DeviceInformationCollection>(*)(IDeviceInformationStatics const&), DeviceInformation, IDeviceInformationStatics>([](IDeviceInformationStatics const& f) { return f.FindAllAsync(); });
    }
    inline auto DeviceInformation::FindAllAsync(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.FindAllAsync(deviceClass); });
    }
    inline auto DeviceInformation::FindAllAsync(param::hstring const& aqsFilter)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.FindAllAsync(aqsFilter); });
    }
    inline auto DeviceInformation::FindAllAsync(param::hstring const& aqsFilter, param::async_iterable<hstring> const& additionalProperties)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.FindAllAsync(aqsFilter, additionalProperties); });
    }
    inline auto DeviceInformation::CreateWatcher()
    {
        return impl::call_factory_cast<llm::OS::Devices::Enumeration::DeviceWatcher(*)(IDeviceInformationStatics const&), DeviceInformation, IDeviceInformationStatics>([](IDeviceInformationStatics const& f) { return f.CreateWatcher(); });
    }
    inline auto DeviceInformation::CreateWatcher(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.CreateWatcher(deviceClass); });
    }
    inline auto DeviceInformation::CreateWatcher(param::hstring const& aqsFilter)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.CreateWatcher(aqsFilter); });
    }
    inline auto DeviceInformation::CreateWatcher(param::hstring const& aqsFilter, param::iterable<hstring> const& additionalProperties)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics>([&](IDeviceInformationStatics const& f) { return f.CreateWatcher(aqsFilter, additionalProperties); });
    }
    inline auto DeviceInformation::GetAqsFilterFromDeviceClass(llm::OS::Devices::Enumeration::DeviceClass const& deviceClass)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics2>([&](IDeviceInformationStatics2 const& f) { return f.GetAqsFilterFromDeviceClass(deviceClass); });
    }
    inline auto DeviceInformation::CreateFromIdAsync(param::hstring const& deviceId, param::async_iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics2>([&](IDeviceInformationStatics2 const& f) { return f.CreateFromIdAsync(deviceId, additionalProperties, kind); });
    }
    inline auto DeviceInformation::FindAllAsync(param::hstring const& aqsFilter, param::async_iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics2>([&](IDeviceInformationStatics2 const& f) { return f.FindAllAsync(aqsFilter, additionalProperties, kind); });
    }
    inline auto DeviceInformation::CreateWatcher(param::hstring const& aqsFilter, param::iterable<hstring> const& additionalProperties, llm::OS::Devices::Enumeration::DeviceInformationKind const& kind)
    {
        return impl::call_factory<DeviceInformation, IDeviceInformationStatics2>([&](IDeviceInformationStatics2 const& f) { return f.CreateWatcher(aqsFilter, additionalProperties, kind); });
    }
    inline auto DeviceInformationPairing::TryRegisterForAllInboundPairingRequests(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported)
    {
        return impl::call_factory<DeviceInformationPairing, IDeviceInformationPairingStatics>([&](IDeviceInformationPairingStatics const& f) { return f.TryRegisterForAllInboundPairingRequests(pairingKindsSupported); });
    }
    inline auto DeviceInformationPairing::TryRegisterForAllInboundPairingRequestsWithProtectionLevel(llm::OS::Devices::Enumeration::DevicePairingKinds const& pairingKindsSupported, llm::OS::Devices::Enumeration::DevicePairingProtectionLevel const& minProtectionLevel)
    {
        return impl::call_factory<DeviceInformationPairing, IDeviceInformationPairingStatics2>([&](IDeviceInformationPairingStatics2 const& f) { return f.TryRegisterForAllInboundPairingRequestsWithProtectionLevel(pairingKindsSupported, minProtectionLevel); });
    }
    inline DevicePicker::DevicePicker() :
        DevicePicker(impl::call_factory_cast<DevicePicker(*)(llm::OS::Foundation::IActivationFactory const&), DevicePicker>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<DevicePicker>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceAccessChangedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceAccessInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceAccessInformationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceConnectionChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceDisconnectButtonClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationCustomPairing> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationPairing> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationPairing2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationPairingStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceInformationUpdate2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePairingRequestedEventArgs2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePairingResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePairingSettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePickerAppearance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDevicePickerFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceSelectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceUnpairingResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceWatcher2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceWatcherEvent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IDeviceWatcherTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IEnclosureLocation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::IEnclosureLocation2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceAccessChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceAccessInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceConnectionChangeTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceDisconnectButtonClickedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceInformation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceInformationCollection> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceInformationCustomPairing> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceInformationPairing> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceInformationUpdate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DevicePairingRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DevicePairingResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DevicePicker> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DevicePickerAppearance> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DevicePickerFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceSelectedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceThumbnail> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceUnpairingResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceWatcher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceWatcherEvent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::DeviceWatcherTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Enumeration::EnclosureLocation> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
