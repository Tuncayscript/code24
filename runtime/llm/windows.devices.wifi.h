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
#ifndef LLM_OS_Devices_WiFi_H
#define LLM_OS_Devices_WiFi_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.Connectivity.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.Devices.WiFi.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Connectivity::NetworkAdapter) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::NetworkAdapter() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->get_NetworkAdapter(&value));
        return llm::OS::Networking::Connectivity::NetworkAdapter{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ScanAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->ScanAsync(&value));
        return llm::OS::Foundation::IAsyncAction{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiNetworkReport) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::NetworkReport() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->get_NetworkReport(&value));
        return llm::OS::Devices::WiFi::WiFiNetworkReport{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFi::WiFiAdapter, llm::OS::Foundation::IInspectable> const& args) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->add_AvailableNetworksChanged(*(void**)(&args), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged_revoker consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFi::WiFiAdapter, llm::OS::Foundation::IInspectable> const& args) const
    {
        return impl::make_event_revoker<D, AvailableNetworksChanged_revoker>(this, AvailableNetworksChanged(args));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::AvailableNetworksChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->remove_AvailableNetworksChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ConnectAsync(llm::OS::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, llm::OS::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->ConnectAsync(*(void**)(&availableNetwork), static_cast<int32_t>(reconnectionKind), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ConnectAsync(llm::OS::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, llm::OS::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind, llm::OS::Security::Credentials::PasswordCredential const& passwordCredential) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->ConnectWithPasswordCredentialAsync(*(void**)(&availableNetwork), static_cast<int32_t>(reconnectionKind), *(void**)(&passwordCredential), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::ConnectAsync(llm::OS::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, llm::OS::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind, llm::OS::Security::Credentials::PasswordCredential const& passwordCredential, param::hstring const& ssid) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->ConnectWithPasswordCredentialAndSsidAsync(*(void**)(&availableNetwork), static_cast<int32_t>(reconnectionKind), *(void**)(&passwordCredential), *(void**)(&ssid), &value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiAdapter<D>::Disconnect() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter)->Disconnect());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiWpsConfigurationResult>) consume_Windows_Devices_WiFi_IWiFiAdapter2<D>::GetWpsConfigurationAsync(llm::OS::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter2)->GetWpsConfigurationAsync(*(void**)(&availableNetwork), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiWpsConfigurationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>) consume_Windows_Devices_WiFi_IWiFiAdapter2<D>::ConnectAsync(llm::OS::Devices::WiFi::WiFiAvailableNetwork const& availableNetwork, llm::OS::Devices::WiFi::WiFiReconnectionKind const& reconnectionKind, llm::OS::Security::Credentials::PasswordCredential const& passwordCredential, param::hstring const& ssid, llm::OS::Devices::WiFi::WiFiConnectionMethod const& connectionMethod) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapter2)->ConnectWithPasswordCredentialAndSsidAndConnectionMethodAsync(*(void**)(&availableNetwork), static_cast<int32_t>(reconnectionKind), *(void**)(&passwordCredential), *(void**)(&ssid), static_cast<int32_t>(connectionMethod), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAdapter>>) consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::FindAllAdaptersAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapterStatics)->FindAllAdaptersAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAdapter>>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::GetDeviceSelector() const
    {
        void* deviceSelector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapterStatics)->GetDeviceSelector(&deviceSelector));
        return hstring{ deviceSelector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAdapter>) consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncOp{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapterStatics)->FromIdAsync(*(void**)(&deviceId), &asyncOp));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAdapter>{ asyncOp, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAccessStatus>) consume_Windows_Devices_WiFi_IWiFiAdapterStatics<D>::RequestAccessAsync() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAdapterStatics)->RequestAccessAsync(&value));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAccessStatus>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::Uptime() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_Uptime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::Ssid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_Ssid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::Bssid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_Bssid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::ChannelCenterFrequencyInKilohertz() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_ChannelCenterFrequencyInKilohertz(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(double) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::NetworkRssiInDecibelMilliwatts() const
    {
        double value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_NetworkRssiInDecibelMilliwatts(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::SignalBars() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_SignalBars(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiNetworkKind) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::NetworkKind() const
    {
        llm::OS::Devices::WiFi::WiFiNetworkKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_NetworkKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiPhyKind) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::PhyKind() const
    {
        llm::OS::Devices::WiFi::WiFiPhyKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_PhyKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Connectivity::NetworkSecuritySettings) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::SecuritySettings() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_SecuritySettings(&value));
        return llm::OS::Networking::Connectivity::NetworkSecuritySettings{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::TimeSpan) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::BeaconInterval() const
    {
        llm::OS::Foundation::TimeSpan value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_BeaconInterval(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_WiFi_IWiFiAvailableNetwork<D>::IsWiFiDirect() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiAvailableNetwork)->get_IsWiFiDirect(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiConnectionStatus) consume_Windows_Devices_WiFi_IWiFiConnectionResult<D>::ConnectionStatus() const
    {
        llm::OS::Devices::WiFi::WiFiConnectionStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiConnectionResult)->get_ConnectionStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_WiFi_IWiFiNetworkReport<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiNetworkReport)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAvailableNetwork>) consume_Windows_Devices_WiFi_IWiFiNetworkReport<D>::AvailableNetworks() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiNetworkReport)->get_AvailableNetworks(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAvailableNetwork>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotConnectTriggerDetails<D>::RequestedNetwork() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails)->get_RequestedNetwork(&value));
        return llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotConnectTriggerDetails<D>::ReportError(llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectStatus const& status) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails)->ReportError(static_cast<int32_t>(status)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult>) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotConnectTriggerDetails<D>::ConnectAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails)->ConnectAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotConnectTriggerDetails<D>::Connect() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails)->Connect(&result));
        return llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectStatus) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotConnectionResult<D>::Status() const
    {
        llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectionResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetworkProperties) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetwork<D>::GetProperties() const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork)->GetProperties(&result));
        return llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetworkProperties{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetwork<D>::UpdateProperties(llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetworkProperties const& newProperties) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork)->UpdateProperties(*(void**)(&newProperties)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::guid) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetwork<D>::Id() const
    {
        llm::guid value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork)->get_Id(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiOnDemandHotspotAvailability) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::Availability() const
    {
        llm::OS::Devices::WiFi::WiFiOnDemandHotspotAvailability value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_Availability(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::Availability(llm::OS::Devices::WiFi::WiFiOnDemandHotspotAvailability const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_Availability(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<uint32_t>) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::RemainingBatteryPercent() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_RemainingBatteryPercent(&value));
        return llm::OS::Foundation::IReference<uint32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::RemainingBatteryPercent(llm::OS::Foundation::IReference<uint32_t> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_RemainingBatteryPercent(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<llm::OS::Devices::WiFi::WiFiOnDemandHotspotCellularBars>) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::CellularBars() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_CellularBars(&value));
        return llm::OS::Foundation::IReference<llm::OS::Devices::WiFi::WiFiOnDemandHotspotCellularBars>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::CellularBars(llm::OS::Foundation::IReference<llm::OS::Devices::WiFi::WiFiOnDemandHotspotCellularBars> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_CellularBars(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::IsMetered() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_IsMetered(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::IsMetered(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_IsMetered(value));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::Ssid() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_Ssid(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::Ssid(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_Ssid(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::Password() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->get_Password(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkProperties<D>::Password(llm::OS::Security::Credentials::PasswordCredential const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties)->put_Password(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork) consume_Windows_Devices_WiFi_IWiFiOnDemandHotspotNetworkStatics<D>::GetOrCreateById(llm::guid const& networkId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkStatics)->GetOrCreateById(impl::bind_in(networkId), &result));
        return llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::WiFi::WiFiWpsConfigurationStatus) consume_Windows_Devices_WiFi_IWiFiWpsConfigurationResult<D>::Status() const
    {
        llm::OS::Devices::WiFi::WiFiWpsConfigurationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiWpsKind>) consume_Windows_Devices_WiFi_IWiFiWpsConfigurationResult<D>::SupportedWpsKinds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult)->get_SupportedWpsKinds(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiWpsKind>{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiAdapter> : produce_base<D, llm::OS::Devices::WiFi::IWiFiAdapter>
    {
        int32_t __stdcall get_NetworkAdapter(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Connectivity::NetworkAdapter>(this->shim().NetworkAdapter());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ScanAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().ScanAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkReport(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiNetworkReport>(this->shim().NetworkReport());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_AvailableNetworksChanged(void* args, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().AvailableNetworksChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::WiFi::WiFiAdapter, llm::OS::Foundation::IInspectable> const*>(&args)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_AvailableNetworksChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AvailableNetworksChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall ConnectAsync(void* availableNetwork, int32_t reconnectionKind, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>>(this->shim().ConnectAsync(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<llm::OS::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectWithPasswordCredentialAsync(void* availableNetwork, int32_t reconnectionKind, void* passwordCredential, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>>(this->shim().ConnectAsync(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<llm::OS::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind), *reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectWithPasswordCredentialAndSsidAsync(void* availableNetwork, int32_t reconnectionKind, void* passwordCredential, void* ssid, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>>(this->shim().ConnectAsync(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<llm::OS::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind), *reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential), *reinterpret_cast<hstring const*>(&ssid)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Disconnect() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnect();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiAdapter2> : produce_base<D, llm::OS::Devices::WiFi::IWiFiAdapter2>
    {
        int32_t __stdcall GetWpsConfigurationAsync(void* availableNetwork, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiWpsConfigurationResult>>(this->shim().GetWpsConfigurationAsync(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectWithPasswordCredentialAndSsidAndConnectionMethodAsync(void* availableNetwork, int32_t reconnectionKind, void* passwordCredential, void* ssid, int32_t connectionMethod, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiConnectionResult>>(this->shim().ConnectAsync(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiAvailableNetwork const*>(&availableNetwork), *reinterpret_cast<llm::OS::Devices::WiFi::WiFiReconnectionKind const*>(&reconnectionKind), *reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential), *reinterpret_cast<hstring const*>(&ssid), *reinterpret_cast<llm::OS::Devices::WiFi::WiFiConnectionMethod const*>(&connectionMethod)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiAdapterStatics> : produce_base<D, llm::OS::Devices::WiFi::IWiFiAdapterStatics>
    {
        int32_t __stdcall FindAllAdaptersAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAdapter>>>(this->shim().FindAllAdaptersAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
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
            *asyncOp = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAdapter>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestAccessAsync(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAccessStatus>>(this->shim().RequestAccessAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiAvailableNetwork> : produce_base<D, llm::OS::Devices::WiFi::IWiFiAvailableNetwork>
    {
        int32_t __stdcall get_Uptime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().Uptime());
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
        int32_t __stdcall get_Bssid(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Bssid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ChannelCenterFrequencyInKilohertz(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ChannelCenterFrequencyInKilohertz());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkRssiInDecibelMilliwatts(double* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<double>(this->shim().NetworkRssiInDecibelMilliwatts());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SignalBars(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().SignalBars());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiNetworkKind>(this->shim().NetworkKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PhyKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiPhyKind>(this->shim().PhyKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SecuritySettings(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Connectivity::NetworkSecuritySettings>(this->shim().SecuritySettings());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BeaconInterval(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::TimeSpan>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::TimeSpan>(this->shim().BeaconInterval());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsWiFiDirect(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsWiFiDirect());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiConnectionResult> : produce_base<D, llm::OS::Devices::WiFi::IWiFiConnectionResult>
    {
        int32_t __stdcall get_ConnectionStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiConnectionStatus>(this->shim().ConnectionStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiNetworkReport> : produce_base<D, llm::OS::Devices::WiFi::IWiFiNetworkReport>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AvailableNetworks(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAvailableNetwork>>(this->shim().AvailableNetworks());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails> : produce_base<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails>
    {
        int32_t __stdcall get_RequestedNetwork(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork>(this->shim().RequestedNetwork());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReportError(int32_t status) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReportError(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectStatus const*>(&status));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult>>(this->shim().ConnectAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Connect(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult>(this->shim().Connect());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectionResult> : produce_base<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectionResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork> : produce_base<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork>
    {
        int32_t __stdcall GetProperties(void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetworkProperties>(this->shim().GetProperties());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateProperties(void* newProperties) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UpdateProperties(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetworkProperties const*>(&newProperties));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(llm::guid* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::guid>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties> : produce_base<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties>
    {
        int32_t __stdcall get_DisplayName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Availability(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiOnDemandHotspotAvailability>(this->shim().Availability());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Availability(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Availability(*reinterpret_cast<llm::OS::Devices::WiFi::WiFiOnDemandHotspotAvailability const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemainingBatteryPercent(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<uint32_t>>(this->shim().RemainingBatteryPercent());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RemainingBatteryPercent(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RemainingBatteryPercent(*reinterpret_cast<llm::OS::Foundation::IReference<uint32_t> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularBars(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<llm::OS::Devices::WiFi::WiFiOnDemandHotspotCellularBars>>(this->shim().CellularBars());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CellularBars(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CellularBars(*reinterpret_cast<llm::OS::Foundation::IReference<llm::OS::Devices::WiFi::WiFiOnDemandHotspotCellularBars> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsMetered(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsMetered());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsMetered(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsMetered(value);
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
        int32_t __stdcall get_Password(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().Password());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Password(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Password(*reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkStatics> : produce_base<D, llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkStatics>
    {
        int32_t __stdcall GetOrCreateById(llm::guid networkId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork>(this->shim().GetOrCreateById(*reinterpret_cast<llm::guid const*>(&networkId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult> : produce_base<D, llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::WiFi::WiFiWpsConfigurationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SupportedWpsKinds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiWpsKind>>(this->shim().SupportedWpsKinds());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::WiFi
{
    inline auto WiFiAdapter::FindAllAdaptersAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::WiFi::WiFiAdapter>>(*)(IWiFiAdapterStatics const&), WiFiAdapter, IWiFiAdapterStatics>([](IWiFiAdapterStatics const& f) { return f.FindAllAdaptersAsync(); });
    }
    inline auto WiFiAdapter::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(IWiFiAdapterStatics const&), WiFiAdapter, IWiFiAdapterStatics>([](IWiFiAdapterStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto WiFiAdapter::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<WiFiAdapter, IWiFiAdapterStatics>([&](IWiFiAdapterStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto WiFiAdapter::RequestAccessAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::WiFi::WiFiAccessStatus>(*)(IWiFiAdapterStatics const&), WiFiAdapter, IWiFiAdapterStatics>([](IWiFiAdapterStatics const& f) { return f.RequestAccessAsync(); });
    }
    inline auto WiFiOnDemandHotspotNetwork::GetOrCreateById(llm::guid const& networkId)
    {
        return impl::call_factory<WiFiOnDemandHotspotNetwork, IWiFiOnDemandHotspotNetworkStatics>([&](IWiFiOnDemandHotspotNetworkStatics const& f) { return f.GetOrCreateById(networkId); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiAdapter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiAdapter2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiAdapterStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiAvailableNetwork> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiConnectionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiNetworkReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiOnDemandHotspotConnectionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetwork> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiOnDemandHotspotNetworkStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::IWiFiWpsConfigurationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiAdapter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiAvailableNetwork> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiConnectionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiNetworkReport> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiOnDemandHotspotConnectionResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetwork> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiOnDemandHotspotNetworkProperties> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::WiFi::WiFiWpsConfigurationResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
