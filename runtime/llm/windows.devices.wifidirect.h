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
#ifndef LLM_OS_Devices_WiFiDirect_H
#define LLM_OS_Devices_WiFiDirect_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Devices.Enumeration.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.WiFiDirect.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::InformationElements() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->get_InformationElements(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::InformationElements(param::vector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->put_InformationElements(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::ListenStateDiscoverability() const
    {
        llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->get_ListenStateDiscoverability(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::ListenStateDiscoverability(llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->put_ListenStateDiscoverability(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::IsAutonomousGroupOwnerEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->get_IsAutonomousGroupOwnerEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::IsAutonomousGroupOwnerEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->put_IsAutonomousGroupOwnerEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectLegacySettings) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement<D>::LegacySettings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement)->get_LegacySettings(&value));
        return llm::OS::Devices::WiFiDirect::WiFiDirectLegacySettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod>) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisement2<D>::SupportedConfigurationMethods() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement2)->get_SupportedConfigurationMethods(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisement) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::Advertisement() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher)->get_Advertisement(&value));
        return llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisement{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::Status() const
    {
        llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::StatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher)->add_StatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::StatusChanged_revoker consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::StatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, StatusChanged_revoker>(this, StatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::StatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher)->remove_StatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::Start() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher)->Start());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisher<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisherStatusChangedEventArgs<D>::Status() const
    {
        llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectError) consume_Windows_Devices_WiFiDirect_IWiFiDirectAdvertisementPublisherStatusChangedEventArgs<D>::Error() const
    {
        llm::OS::Devices::WiFiDirect::WiFiDirectError value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs)->get_Error(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionListener<D>::ConnectionRequested(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionListener, llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener)->add_ConnectionRequested(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionListener<D>::ConnectionRequested_revoker consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionListener<D>::ConnectionRequested(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionListener, llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ConnectionRequested_revoker>(this, ConnectionRequested(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionListener<D>::ConnectionRequested(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener)->remove_ConnectionRequested(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(int16_t) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionParameters<D>::GroupOwnerIntent() const
    {
        int16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters)->get_GroupOwnerIntent(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionParameters<D>::GroupOwnerIntent(int16_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters)->put_GroupOwnerIntent(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod>) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionParameters2<D>::PreferenceOrderedConfigurationMethods() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2)->get_PreferenceOrderedConfigurationMethods(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectPairingProcedure) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionParameters2<D>::PreferredPairingProcedure() const
    {
        llm::OS::Devices::WiFiDirect::WiFiDirectPairingProcedure value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2)->get_PreferredPairingProcedure(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionParameters2<D>::PreferredPairingProcedure(llm::OS::Devices::WiFiDirect::WiFiDirectPairingProcedure const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2)->put_PreferredPairingProcedure(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DevicePairingKinds) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionParametersStatics<D>::GetDevicePairingKinds(llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod const& configurationMethod) const
    {
        llm::OS::Devices::Enumeration::DevicePairingKinds result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics)->GetDevicePairingKinds(static_cast<int32_t>(configurationMethod), reinterpret_cast<uint32_t*>(&result)));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Enumeration::DeviceInformation) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionRequest<D>::DeviceInformation() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest)->get_DeviceInformation(&value));
        return llm::OS::Devices::Enumeration::DeviceInformation{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequest) consume_Windows_Devices_WiFiDirect_IWiFiDirectConnectionRequestedEventArgs<D>::GetConnectionRequest() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs)->GetConnectionRequest(&result));
        return llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequest{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFiDirect::WiFiDirectConnectionStatus) consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::ConnectionStatus() const
    {
        llm::OS::Devices::WiFiDirect::WiFiDirectConnectionStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDevice)->get_ConnectionStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDevice)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::ConnectionStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectDevice, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDevice)->add_ConnectionStatusChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::ConnectionStatusChanged_revoker consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::ConnectionStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectDevice, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, ConnectionStatusChanged_revoker>(this, ConnectionStatusChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::ConnectionStatusChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDevice)->remove_ConnectionStatusChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::EndpointPair>) consume_Windows_Devices_WiFiDirect_IWiFiDirectDevice<D>::GetConnectionEndpointPairs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDevice)->GetConnectionEndpointPairs(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::EndpointPair>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFiDirect_IWiFiDirectDeviceStatics<D>::GetDeviceSelector() const
    {
        void* deviceSelector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics)->GetDeviceSelector(&deviceSelector));
        return hstring{ deviceSelector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFiDirect::WiFiDirectDevice>) consume_Windows_Devices_WiFiDirect_IWiFiDirectDeviceStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics)->FromIdAsync(*(void**)(&deviceId), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFiDirect::WiFiDirectDevice>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFiDirect_IWiFiDirectDeviceStatics2<D>::GetDeviceSelector(llm::OS::Devices::WiFiDirect::WiFiDirectDeviceSelectorType const& type) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics2)->GetDeviceSelector(static_cast<int32_t>(type), &result));
        return hstring{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFiDirect::WiFiDirectDevice>) consume_Windows_Devices_WiFiDirect_IWiFiDirectDeviceStatics2<D>::FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::WiFiDirect::WiFiDirectConnectionParameters const& connectionParameters) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics2)->FromIdAsync(*(void**)(&deviceId), *(void**)(&connectionParameters), &result));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFiDirect::WiFiDirectDevice>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElement<D>::Oui() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement)->get_Oui(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElement<D>::Oui(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement)->put_Oui(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElement<D>::OuiType() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement)->get_OuiType(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElement<D>::OuiType(uint8_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement)->put_OuiType(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElement<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement)->get_Value(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElement<D>::Value(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElementStatics<D>::CreateFromBuffer(llm::OS::Storage::Streams::IBuffer const& buffer) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElementStatics)->CreateFromBuffer(*(void**)(&buffer), &result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>) consume_Windows_Devices_WiFiDirect_IWiFiDirectInformationElementStatics<D>::CreateFromDeviceInformation(llm::OS::Devices::Enumeration::DeviceInformation const& deviceInformation) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElementStatics)->CreateFromDeviceInformation(*(void**)(&deviceInformation), &result));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_WiFiDirect_IWiFiDirectLegacySettings<D>::IsEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings)->get_IsEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectLegacySettings<D>::IsEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings)->put_IsEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFiDirect_IWiFiDirectLegacySettings<D>::Ssid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings)->get_Ssid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectLegacySettings<D>::Ssid(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings)->put_Ssid(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Devices_WiFiDirect_IWiFiDirectLegacySettings<D>::Passphrase() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings)->get_Passphrase(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFiDirect_IWiFiDirectLegacySettings<D>::Passphrase(llm::OS::Security::Credentials::PasswordCredential const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings)->put_Passphrase(*(void**)(&value)));
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement>
    {
        int32_t __stdcall get_InformationElements(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>>(this->shim().InformationElements());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_InformationElements(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InformationElements(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ListenStateDiscoverability(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability>(this->shim().ListenStateDiscoverability());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ListenStateDiscoverability(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ListenStateDiscoverability(*reinterpret_cast<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementListenStateDiscoverability const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsAutonomousGroupOwnerEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsAutonomousGroupOwnerEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsAutonomousGroupOwnerEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsAutonomousGroupOwnerEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LegacySettings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectLegacySettings>(this->shim().LegacySettings());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement2> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement2>
    {
        int32_t __stdcall get_SupportedConfigurationMethods(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod>>(this->shim().SupportedConfigurationMethods());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher>
    {
        int32_t __stdcall get_Advertisement(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisement>(this->shim().Advertisement());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_StatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher, llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
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
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Error(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectError>(this->shim().Error());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener>
    {
        int32_t __stdcall add_ConnectionRequested(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ConnectionRequested(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionListener, llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ConnectionRequested(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionRequested(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters>
    {
        int32_t __stdcall get_GroupOwnerIntent(int16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int16_t>(this->shim().GroupOwnerIntent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_GroupOwnerIntent(int16_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GroupOwnerIntent(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2>
    {
        int32_t __stdcall get_PreferenceOrderedConfigurationMethods(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod>>(this->shim().PreferenceOrderedConfigurationMethods());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PreferredPairingProcedure(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectPairingProcedure>(this->shim().PreferredPairingProcedure());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PreferredPairingProcedure(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PreferredPairingProcedure(*reinterpret_cast<llm::OS::Devices::WiFiDirect::WiFiDirectPairingProcedure const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics>
    {
        int32_t __stdcall GetDevicePairingKinds(int32_t configurationMethod, uint32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::Enumeration::DevicePairingKinds>(this->shim().GetDevicePairingKinds(*reinterpret_cast<llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod const*>(&configurationMethod)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest>
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
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs>
    {
        int32_t __stdcall GetConnectionRequest(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequest>(this->shim().GetConnectionRequest());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectDevice> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectDevice>
    {
        int32_t __stdcall get_ConnectionStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionStatus>(this->shim().ConnectionStatus());
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
        int32_t __stdcall add_ConnectionStatusChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ConnectionStatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFiDirect::WiFiDirectDevice, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ConnectionStatusChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ConnectionStatusChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetConnectionEndpointPairs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::EndpointPair>>(this->shim().GetConnectionEndpointPairs());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** deviceSelector) noexcept final try
        {
            clear_abi(deviceSelector);
            typename D::abi_guard guard(this->shim());
            *deviceSelector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** asyncOp) noexcept final try
        {
            clear_abi(asyncOp);
            typename D::abi_guard guard(this->shim());
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFiDirect::WiFiDirectDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics2> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics2>
    {
        int32_t __stdcall GetDeviceSelector(int32_t type, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<hstring>(this->shim().GetDeviceSelector(*reinterpret_cast<llm::OS::Devices::WiFiDirect::WiFiDirectDeviceSelectorType const*>(&type)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void* connectionParameters, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFiDirect::WiFiDirectDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId), *reinterpret_cast<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionParameters const*>(&connectionParameters)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement>
    {
        int32_t __stdcall get_Oui(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Oui());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Oui(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Oui(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OuiType(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().OuiType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_OuiType(uint8_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OuiType(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElementStatics> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElementStatics>
    {
        int32_t __stdcall CreateFromBuffer(void* buffer, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>>(this->shim().CreateFromBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&buffer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromDeviceInformation(void* deviceInformation, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement>>(this->shim().CreateFromDeviceInformation(*reinterpret_cast<llm::OS::Devices::Enumeration::DeviceInformation const*>(&deviceInformation)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings> : produce_base<D, llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings>
    {
        int32_t __stdcall get_IsEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
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
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().Passphrase());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Passphrase(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Passphrase(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::WiFiDirect
{
    inline WiFiDirectAdvertisementPublisher::WiFiDirectAdvertisementPublisher() :
        WiFiDirectAdvertisementPublisher(impl::call_factory_cast<WiFiDirectAdvertisementPublisher(*)(llm::OS::Foundation::IActivationFactory const&), WiFiDirectAdvertisementPublisher>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WiFiDirectAdvertisementPublisher>(); }))
    {
    }
    inline WiFiDirectConnectionListener::WiFiDirectConnectionListener() :
        WiFiDirectConnectionListener(impl::call_factory_cast<WiFiDirectConnectionListener(*)(llm::OS::Foundation::IActivationFactory const&), WiFiDirectConnectionListener>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WiFiDirectConnectionListener>(); }))
    {
    }
    inline WiFiDirectConnectionParameters::WiFiDirectConnectionParameters() :
        WiFiDirectConnectionParameters(impl::call_factory_cast<WiFiDirectConnectionParameters(*)(llm::OS::Foundation::IActivationFactory const&), WiFiDirectConnectionParameters>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WiFiDirectConnectionParameters>(); }))
    {
    }
    inline auto WiFiDirectConnectionParameters::GetDevicePairingKinds(llm::OS::Devices::WiFiDirect::WiFiDirectConfigurationMethod const& configurationMethod)
    {
        return impl::call_factory<WiFiDirectConnectionParameters, IWiFiDirectConnectionParametersStatics>([&](IWiFiDirectConnectionParametersStatics const& f) { return f.GetDevicePairingKinds(configurationMethod); });
    }
    inline auto WiFiDirectDevice::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IWiFiDirectDeviceStatics const&), WiFiDirectDevice, IWiFiDirectDeviceStatics>([](IWiFiDirectDeviceStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto WiFiDirectDevice::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<WiFiDirectDevice, IWiFiDirectDeviceStatics>([&](IWiFiDirectDeviceStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto WiFiDirectDevice::GetDeviceSelector(llm::OS::Devices::WiFiDirect::WiFiDirectDeviceSelectorType const& type)
    {
        return impl::call_factory<WiFiDirectDevice, IWiFiDirectDeviceStatics2>([&](IWiFiDirectDeviceStatics2 const& f) { return f.GetDeviceSelector(type); });
    }
    inline auto WiFiDirectDevice::FromIdAsync(param::hstring const& deviceId, llm::OS::Devices::WiFiDirect::WiFiDirectConnectionParameters const& connectionParameters)
    {
        return impl::call_factory<WiFiDirectDevice, IWiFiDirectDeviceStatics2>([&](IWiFiDirectDeviceStatics2 const& f) { return f.FromIdAsync(deviceId, connectionParameters); });
    }
    inline WiFiDirectInformationElement::WiFiDirectInformationElement() :
        WiFiDirectInformationElement(impl::call_factory_cast<WiFiDirectInformationElement(*)(llm::OS::Foundation::IActivationFactory const&), WiFiDirectInformationElement>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<WiFiDirectInformationElement>(); }))
    {
    }
    inline auto WiFiDirectInformationElement::CreateFromBuffer(llm::OS::Storage::Streams::IBuffer const& buffer)
    {
        return impl::call_factory<WiFiDirectInformationElement, IWiFiDirectInformationElementStatics>([&](IWiFiDirectInformationElementStatics const& f) { return f.CreateFromBuffer(buffer); });
    }
    inline auto WiFiDirectInformationElement::CreateFromDeviceInformation(llm::OS::Devices::Enumeration::DeviceInformation const& deviceInformation)
    {
        return impl::call_factory<WiFiDirectInformationElement, IWiFiDirectInformationElementStatics>([&](IWiFiDirectInformationElementStatics const& f) { return f.CreateFromDeviceInformation(deviceInformation); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisement2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectAdvertisementPublisherStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParameters2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionParametersStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectConnectionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectDeviceStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectInformationElementStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::IWiFiDirectLegacySettings> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisher> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectAdvertisementPublisherStatusChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionListener> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionParameters> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequest> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectConnectionRequestedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectInformationElement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFiDirect::WiFiDirectLegacySettings> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
