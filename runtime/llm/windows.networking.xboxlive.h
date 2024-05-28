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
#ifndef LLM_OS_Networking_XboxLive_H
#define LLM_OS_Networking_XboxLive_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Networking.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Networking.XboxLive.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::SnapshotChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress, llm::OS::Foundation::IInspectable> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->add_SnapshotChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::SnapshotChanged_revoker consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::SnapshotChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress, llm::OS::Foundation::IInspectable> const& handler) const
    {
        return impl::make_event_revoker<D, SnapshotChanged_revoker>(this, SnapshotChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::SnapshotChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->remove_SnapshotChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::GetSnapshotAsBase64() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->GetSnapshotAsBase64(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::GetSnapshotAsBuffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->GetSnapshotAsBuffer(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::GetSnapshotAsBytes(array_view<uint8_t> buffer, uint32_t& bytesWritten) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->GetSnapshotAsBytes(buffer.size(), put_abi(buffer), &bytesWritten));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::Compare(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& otherDeviceAddress) const
    {
        int32_t result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->Compare(*(void**)(&otherDeviceAddress), &result));
        return result;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::IsValid() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->get_IsValid(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::IsLocal() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->get_IsLocal(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveNetworkAccessKind) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddress<D>::NetworkAccessKind() const
    {
        llm::OS::Networking::XboxLive::XboxLiveNetworkAccessKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress)->get_NetworkAccessKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics<D>::CreateFromSnapshotBase64(param::hstring const& base64) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics)->CreateFromSnapshotBase64(*(void**)(&base64), &value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics<D>::CreateFromSnapshotBuffer(llm::OS::Storage::Streams::IBuffer const& buffer) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics)->CreateFromSnapshotBuffer(*(void**)(&buffer), &value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics<D>::CreateFromSnapshotBytes(array_view<uint8_t const> buffer) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics)->CreateFromSnapshotBytes(buffer.size(), get_abi(buffer), &value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics<D>::GetLocal() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics)->GetLocal(&value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_XboxLive_IXboxLiveDeviceAddressStatics<D>::MaxSnapshotBytesSize() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics)->get_MaxSnapshotBytesSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::StateChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveEndpointPair, llm::OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->add_StateChanged(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::StateChanged_revoker consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::StateChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveEndpointPair, llm::OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, StateChanged_revoker>(this, StateChanged(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::StateChanged(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->remove_StateChanged(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::DeleteAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->DeleteAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::GetRemoteSocketAddressBytes(array_view<uint8_t> socketAddress) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->GetRemoteSocketAddressBytes(socketAddress.size(), put_abi(socketAddress)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::GetLocalSocketAddressBytes(array_view<uint8_t> socketAddress) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->GetLocalSocketAddressBytes(socketAddress.size(), put_abi(socketAddress)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPairState) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::State() const
    {
        llm::OS::Networking::XboxLive::XboxLiveEndpointPairState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_State(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::Template() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_Template(&value));
        return llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::RemoteDeviceAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_RemoteDeviceAddress(&value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::RemoteHostName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_RemoteHostName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::RemotePort() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_RemotePort(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::LocalHostName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_LocalHostName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPair<D>::LocalPort() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPair)->get_LocalPort(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairCreationResult<D>::DeviceAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult)->get_DeviceAddress(&value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationStatus) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairCreationResult<D>::Status() const
    {
        llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairCreationResult<D>::IsExistingPathEvaluation() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult)->get_IsExistingPathEvaluation(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPair) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairCreationResult<D>::EndpointPair() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult)->get_EndpointPair(&value));
        return llm::OS::Networking::XboxLive::XboxLiveEndpointPair{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPairState) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStateChangedEventArgs<D>::OldState() const
    {
        llm::OS::Networking::XboxLive::XboxLiveEndpointPairState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs)->get_OldState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPairState) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStateChangedEventArgs<D>::NewState() const
    {
        llm::OS::Networking::XboxLive::XboxLiveEndpointPairState value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs)->get_NewState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPair) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStatics<D>::FindEndpointPairBySocketAddressBytes(array_view<uint8_t const> localSocketAddress, array_view<uint8_t const> remoteSocketAddress) const
    {
        void* endpointPair{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStatics)->FindEndpointPairBySocketAddressBytes(localSocketAddress.size(), get_abi(localSocketAddress), remoteSocketAddress.size(), get_abi(remoteSocketAddress), &endpointPair));
        return llm::OS::Networking::XboxLive::XboxLiveEndpointPair{ endpointPair, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPair) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairStatics<D>::FindEndpointPairByHostNamesAndPorts(llm::OS::Networking::HostName const& localHostName, param::hstring const& localPort, llm::OS::Networking::HostName const& remoteHostName, param::hstring const& remotePort) const
    {
        void* endpointPair{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStatics)->FindEndpointPairByHostNamesAndPorts(*(void**)(&localHostName), *(void**)(&localPort), *(void**)(&remoteHostName), *(void**)(&remotePort), &endpointPair));
        return llm::OS::Networking::XboxLive::XboxLiveEndpointPair{ endpointPair, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::InboundEndpointPairCreated(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate, llm::OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->add_InboundEndpointPairCreated(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::InboundEndpointPairCreated_revoker consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::InboundEndpointPairCreated(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate, llm::OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, InboundEndpointPairCreated_revoker>(this, InboundEndpointPairCreated(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::InboundEndpointPairCreated(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->remove_InboundEndpointPairCreated(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::CreateEndpointPairAsync(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->CreateEndpointPairDefaultAsync(*(void**)(&deviceAddress), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::CreateEndpointPairAsync(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors const& behaviors) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->CreateEndpointPairWithBehaviorsAsync(*(void**)(&deviceAddress), static_cast<uint32_t>(behaviors), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::CreateEndpointPairForPortsAsync(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, param::hstring const& initiatorPort, param::hstring const& acceptorPort) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->CreateEndpointPairForPortsDefaultAsync(*(void**)(&deviceAddress), *(void**)(&initiatorPort), *(void**)(&acceptorPort), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::CreateEndpointPairForPortsAsync(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, param::hstring const& initiatorPort, param::hstring const& acceptorPort, llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors const& behaviors) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->CreateEndpointPairForPortsWithBehaviorsAsync(*(void**)(&deviceAddress), *(void**)(&initiatorPort), *(void**)(&acceptorPort), static_cast<uint32_t>(behaviors), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::Name() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_Name(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveSocketKind) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::SocketKind() const
    {
        llm::OS::Networking::XboxLive::XboxLiveSocketKind value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_SocketKind(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::InitiatorBoundPortRangeLower() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_InitiatorBoundPortRangeLower(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::InitiatorBoundPortRangeUpper() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_InitiatorBoundPortRangeUpper(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::AcceptorBoundPortRangeLower() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_AcceptorBoundPortRangeLower(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint16_t) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::AcceptorBoundPortRangeUpper() const
    {
        uint16_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_AcceptorBoundPortRangeUpper(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplate<D>::EndpointPairs() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate)->get_EndpointPairs(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplateStatics<D>::GetTemplateByName(param::hstring const& name) const
    {
        void* namedTemplate{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics)->GetTemplateByName(*(void**)(&name), &namedTemplate));
        return llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate{ namedTemplate, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>) consume_Windows_Networking_XboxLive_IXboxLiveEndpointPairTemplateStatics<D>::Templates() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics)->get_Templates(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveEndpointPair) consume_Windows_Networking_XboxLive_IXboxLiveInboundEndpointPairCreatedEventArgs<D>::EndpointPair() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs)->get_EndpointPair(&value));
        return llm::OS::Networking::XboxLive::XboxLiveEndpointPair{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::MeasureAsync() const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->MeasureAsync(&action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::GetMetricResultsForDevice(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->GetMetricResultsForDevice(*(void**)(&deviceAddress), &value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::GetMetricResultsForMetric(llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric const& metric) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->GetMetricResultsForMetric(static_cast<int32_t>(metric), &value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::GetMetricResult(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress, llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric const& metric) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->GetMetricResult(*(void**)(&deviceAddress), static_cast<int32_t>(metric), &value));
        return llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::GetPrivatePayloadResult(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const& deviceAddress) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->GetPrivatePayloadResult(*(void**)(&deviceAddress), &value));
        return llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric>) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::Metrics() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_Metrics(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::DeviceAddresses() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_DeviceAddresses(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::ShouldRequestPrivatePayloads() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_ShouldRequestPrivatePayloads(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::ShouldRequestPrivatePayloads(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->put_ShouldRequestPrivatePayloads(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::TimeoutInMilliseconds() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_TimeoutInMilliseconds(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::TimeoutInMilliseconds(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->put_TimeoutInMilliseconds(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::NumberOfProbesToAttempt() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_NumberOfProbesToAttempt(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::NumberOfProbesToAttempt(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->put_NumberOfProbesToAttempt(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::NumberOfResultsPending() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_NumberOfResultsPending(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::MetricResults() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_MetricResults(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurement<D>::PrivatePayloadResults() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement)->get_PrivatePayloadResults(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::PublishPrivatePayloadBytes(array_view<uint8_t const> payload) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->PublishPrivatePayloadBytes(payload.size(), get_abi(payload)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::ClearPrivatePayload() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->ClearPrivatePayload());
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::MaxSimultaneousProbeConnections() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->get_MaxSimultaneousProbeConnections(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::MaxSimultaneousProbeConnections(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->put_MaxSimultaneousProbeConnections(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::IsSystemOutboundBandwidthConstrained() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->get_IsSystemOutboundBandwidthConstrained(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::IsSystemOutboundBandwidthConstrained(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->put_IsSystemOutboundBandwidthConstrained(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::IsSystemInboundBandwidthConstrained() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->get_IsSystemInboundBandwidthConstrained(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::IsSystemInboundBandwidthConstrained(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->put_IsSystemInboundBandwidthConstrained(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::PublishedPrivatePayload() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->get_PublishedPrivatePayload(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::PublishedPrivatePayload(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->put_PublishedPrivatePayload(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMeasurementStatics<D>::MaxPrivatePayloadSize() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics)->get_MaxPrivatePayloadSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMetricResult<D>::Status() const
    {
        llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMetricResult<D>::DeviceAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult)->get_DeviceAddress(&value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMetricResult<D>::Metric() const
    {
        llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult)->get_Metric(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint64_t) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServiceMetricResult<D>::Value() const
    {
        uint64_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult)->get_Value(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServicePrivatePayloadResult<D>::Status() const
    {
        llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::XboxLive::XboxLiveDeviceAddress) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServicePrivatePayloadResult<D>::DeviceAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult)->get_DeviceAddress(&value));
        return llm::OS::Networking::XboxLive::XboxLiveDeviceAddress{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Networking_XboxLive_IXboxLiveQualityOfServicePrivatePayloadResult<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult)->get_Value(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress>
    {
        int32_t __stdcall add_SnapshotChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().SnapshotChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress, llm::OS::Foundation::IInspectable> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SnapshotChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SnapshotChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetSnapshotAsBase64(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetSnapshotAsBase64());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSnapshotAsBuffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().GetSnapshotAsBuffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSnapshotAsBytes(uint32_t __bufferSize, uint8_t* buffer, uint32_t* bytesWritten) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetSnapshotAsBytes(array_view<uint8_t>(reinterpret_cast<uint8_t*>(buffer), reinterpret_cast<uint8_t*>(buffer) + __bufferSize), *bytesWritten);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Compare(void* otherDeviceAddress, int32_t* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *result = detach_from<int32_t>(this->shim().Compare(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&otherDeviceAddress)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsValid(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsValid());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsLocal(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsLocal());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkAccessKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveNetworkAccessKind>(this->shim().NetworkAccessKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics>
    {
        int32_t __stdcall CreateFromSnapshotBase64(void* base64, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().CreateFromSnapshotBase64(*reinterpret_cast<hstring const*>(&base64)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromSnapshotBuffer(void* buffer, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().CreateFromSnapshotBuffer(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&buffer)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateFromSnapshotBytes(uint32_t __bufferSize, uint8_t* buffer, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().CreateFromSnapshotBytes(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(buffer), reinterpret_cast<uint8_t const *>(buffer) + __bufferSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLocal(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().GetLocal());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxSnapshotBytesSize(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxSnapshotBytesSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPair> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPair>
    {
        int32_t __stdcall add_StateChanged(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().StateChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveEndpointPair, llm::OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_StateChanged(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StateChanged(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall DeleteAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetRemoteSocketAddressBytes(uint32_t __socketAddressSize, uint8_t* socketAddress) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetRemoteSocketAddressBytes(array_view<uint8_t>(reinterpret_cast<uint8_t*>(socketAddress), reinterpret_cast<uint8_t*>(socketAddress) + __socketAddressSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetLocalSocketAddressBytes(uint32_t __socketAddressSize, uint8_t* socketAddress) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().GetLocalSocketAddressBytes(array_view<uint8_t>(reinterpret_cast<uint8_t*>(socketAddress), reinterpret_cast<uint8_t*>(socketAddress) + __socketAddressSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_State(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPairState>(this->shim().State());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Template(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>(this->shim().Template());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteDeviceAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().RemoteDeviceAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteHostName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().RemoteHostName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemotePort(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().RemotePort());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalHostName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().LocalHostName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalPort(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().LocalPort());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult>
    {
        int32_t __stdcall get_DeviceAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().DeviceAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsExistingPathEvaluation(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsExistingPathEvaluation());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EndpointPair(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>(this->shim().EndpointPair());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs>
    {
        int32_t __stdcall get_OldState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPairState>(this->shim().OldState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NewState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPairState>(this->shim().NewState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStatics> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStatics>
    {
        int32_t __stdcall FindEndpointPairBySocketAddressBytes(uint32_t __localSocketAddressSize, uint8_t* localSocketAddress, uint32_t __remoteSocketAddressSize, uint8_t* remoteSocketAddress, void** endpointPair) noexcept final try
        {
            clear_abi(endpointPair);
            typename D::abi_guard guard(this->shim());
            *endpointPair = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>(this->shim().FindEndpointPairBySocketAddressBytes(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(localSocketAddress), reinterpret_cast<uint8_t const *>(localSocketAddress) + __localSocketAddressSize), array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(remoteSocketAddress), reinterpret_cast<uint8_t const *>(remoteSocketAddress) + __remoteSocketAddressSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FindEndpointPairByHostNamesAndPorts(void* localHostName, void* localPort, void* remoteHostName, void* remotePort, void** endpointPair) noexcept final try
        {
            clear_abi(endpointPair);
            typename D::abi_guard guard(this->shim());
            *endpointPair = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>(this->shim().FindEndpointPairByHostNamesAndPorts(*reinterpret_cast<llm::OS::Networking::HostName const*>(&localHostName), *reinterpret_cast<hstring const*>(&localPort), *reinterpret_cast<llm::OS::Networking::HostName const*>(&remoteHostName), *reinterpret_cast<hstring const*>(&remotePort)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate>
    {
        int32_t __stdcall add_InboundEndpointPairCreated(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().InboundEndpointPairCreated(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate, llm::OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_InboundEndpointPairCreated(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InboundEndpointPairCreated(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall CreateEndpointPairDefaultAsync(void* deviceAddress, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>>(this->shim().CreateEndpointPairAsync(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEndpointPairWithBehaviorsAsync(void* deviceAddress, uint32_t behaviors, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>>(this->shim().CreateEndpointPairAsync(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress), *reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors const*>(&behaviors)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEndpointPairForPortsDefaultAsync(void* deviceAddress, void* initiatorPort, void* acceptorPort, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>>(this->shim().CreateEndpointPairForPortsAsync(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress), *reinterpret_cast<hstring const*>(&initiatorPort), *reinterpret_cast<hstring const*>(&acceptorPort)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CreateEndpointPairForPortsWithBehaviorsAsync(void* deviceAddress, void* initiatorPort, void* acceptorPort, uint32_t behaviors, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult>>(this->shim().CreateEndpointPairForPortsAsync(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress), *reinterpret_cast<hstring const*>(&initiatorPort), *reinterpret_cast<hstring const*>(&acceptorPort), *reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationBehaviors const*>(&behaviors)));
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
        int32_t __stdcall get_SocketKind(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveSocketKind>(this->shim().SocketKind());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitiatorBoundPortRangeLower(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().InitiatorBoundPortRangeLower());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitiatorBoundPortRangeUpper(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().InitiatorBoundPortRangeUpper());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AcceptorBoundPortRangeLower(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().AcceptorBoundPortRangeLower());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AcceptorBoundPortRangeUpper(uint16_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint16_t>(this->shim().AcceptorBoundPortRangeUpper());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EndpointPairs(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>>(this->shim().EndpointPairs());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics>
    {
        int32_t __stdcall GetTemplateByName(void* name, void** namedTemplate) noexcept final try
        {
            clear_abi(namedTemplate);
            typename D::abi_guard guard(this->shim());
            *namedTemplate = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>(this->shim().GetTemplateByName(*reinterpret_cast<hstring const*>(&name)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Templates(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>>(this->shim().Templates());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs>
    {
        int32_t __stdcall get_EndpointPair(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveEndpointPair>(this->shim().EndpointPair());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement>
    {
        int32_t __stdcall MeasureAsync(void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().MeasureAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMetricResultsForDevice(void* deviceAddress, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>>(this->shim().GetMetricResultsForDevice(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMetricResultsForMetric(int32_t metric, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>>(this->shim().GetMetricResultsForMetric(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric const*>(&metric)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMetricResult(void* deviceAddress, int32_t metric, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>(this->shim().GetMetricResult(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress), *reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric const*>(&metric)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetPrivatePayloadResult(void* deviceAddress, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>(this->shim().GetPrivatePayloadResult(*reinterpret_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress const*>(&deviceAddress)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Metrics(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric>>(this->shim().Metrics());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceAddresses(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>>(this->shim().DeviceAddresses());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ShouldRequestPrivatePayloads(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ShouldRequestPrivatePayloads());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ShouldRequestPrivatePayloads(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ShouldRequestPrivatePayloads(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TimeoutInMilliseconds(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TimeoutInMilliseconds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TimeoutInMilliseconds(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TimeoutInMilliseconds(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NumberOfProbesToAttempt(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NumberOfProbesToAttempt());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NumberOfProbesToAttempt(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NumberOfProbesToAttempt(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NumberOfResultsPending(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().NumberOfResultsPending());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MetricResults(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult>>(this->shim().MetricResults());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrivatePayloadResults(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult>>(this->shim().PrivatePayloadResults());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics>
    {
        int32_t __stdcall PublishPrivatePayloadBytes(uint32_t __payloadSize, uint8_t* payload) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PublishPrivatePayloadBytes(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(payload), reinterpret_cast<uint8_t const *>(payload) + __payloadSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ClearPrivatePayload() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ClearPrivatePayload();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxSimultaneousProbeConnections(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxSimultaneousProbeConnections());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_MaxSimultaneousProbeConnections(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MaxSimultaneousProbeConnections(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSystemOutboundBandwidthConstrained(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSystemOutboundBandwidthConstrained());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsSystemOutboundBandwidthConstrained(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSystemOutboundBandwidthConstrained(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsSystemInboundBandwidthConstrained(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSystemInboundBandwidthConstrained());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsSystemInboundBandwidthConstrained(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsSystemInboundBandwidthConstrained(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PublishedPrivatePayload(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().PublishedPrivatePayload());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PublishedPrivatePayload(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PublishedPrivatePayload(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxPrivatePayloadSize(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxPrivatePayloadSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().DeviceAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Metric(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetric>(this->shim().Metric());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(uint64_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint64_t>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult> : produce_base<D, llm::OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult>
    {
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurementStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress>(this->shim().DeviceAddress());
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
    };
#endif
}
LLM_EXPORT namespace llm::OS::Networking::XboxLive
{
    constexpr auto operator|(XboxLiveEndpointPairCreationBehaviors const left, XboxLiveEndpointPairCreationBehaviors const right) noexcept
    {
        return static_cast<XboxLiveEndpointPairCreationBehaviors>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(XboxLiveEndpointPairCreationBehaviors& left, XboxLiveEndpointPairCreationBehaviors const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(XboxLiveEndpointPairCreationBehaviors const left, XboxLiveEndpointPairCreationBehaviors const right) noexcept
    {
        return static_cast<XboxLiveEndpointPairCreationBehaviors>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(XboxLiveEndpointPairCreationBehaviors& left, XboxLiveEndpointPairCreationBehaviors const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(XboxLiveEndpointPairCreationBehaviors const value) noexcept
    {
        return static_cast<XboxLiveEndpointPairCreationBehaviors>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(XboxLiveEndpointPairCreationBehaviors const left, XboxLiveEndpointPairCreationBehaviors const right) noexcept
    {
        return static_cast<XboxLiveEndpointPairCreationBehaviors>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(XboxLiveEndpointPairCreationBehaviors& left, XboxLiveEndpointPairCreationBehaviors const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline auto XboxLiveDeviceAddress::CreateFromSnapshotBase64(param::hstring const& base64)
    {
        return impl::call_factory<XboxLiveDeviceAddress, IXboxLiveDeviceAddressStatics>([&](IXboxLiveDeviceAddressStatics const& f) { return f.CreateFromSnapshotBase64(base64); });
    }
    inline auto XboxLiveDeviceAddress::CreateFromSnapshotBuffer(llm::OS::Storage::Streams::IBuffer const& buffer)
    {
        return impl::call_factory<XboxLiveDeviceAddress, IXboxLiveDeviceAddressStatics>([&](IXboxLiveDeviceAddressStatics const& f) { return f.CreateFromSnapshotBuffer(buffer); });
    }
    inline auto XboxLiveDeviceAddress::CreateFromSnapshotBytes(array_view<uint8_t const> buffer)
    {
        return impl::call_factory<XboxLiveDeviceAddress, IXboxLiveDeviceAddressStatics>([&](IXboxLiveDeviceAddressStatics const& f) { return f.CreateFromSnapshotBytes(buffer); });
    }
    inline auto XboxLiveDeviceAddress::GetLocal()
    {
        return impl::call_factory_cast<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress(*)(IXboxLiveDeviceAddressStatics const&), XboxLiveDeviceAddress, IXboxLiveDeviceAddressStatics>([](IXboxLiveDeviceAddressStatics const& f) { return f.GetLocal(); });
    }
    inline auto XboxLiveDeviceAddress::MaxSnapshotBytesSize()
    {
        return impl::call_factory_cast<uint32_t(*)(IXboxLiveDeviceAddressStatics const&), XboxLiveDeviceAddress, IXboxLiveDeviceAddressStatics>([](IXboxLiveDeviceAddressStatics const& f) { return f.MaxSnapshotBytesSize(); });
    }
    inline auto XboxLiveEndpointPair::FindEndpointPairBySocketAddressBytes(array_view<uint8_t const> localSocketAddress, array_view<uint8_t const> remoteSocketAddress)
    {
        return impl::call_factory<XboxLiveEndpointPair, IXboxLiveEndpointPairStatics>([&](IXboxLiveEndpointPairStatics const& f) { return f.FindEndpointPairBySocketAddressBytes(localSocketAddress, remoteSocketAddress); });
    }
    inline auto XboxLiveEndpointPair::FindEndpointPairByHostNamesAndPorts(llm::OS::Networking::HostName const& localHostName, param::hstring const& localPort, llm::OS::Networking::HostName const& remoteHostName, param::hstring const& remotePort)
    {
        return impl::call_factory<XboxLiveEndpointPair, IXboxLiveEndpointPairStatics>([&](IXboxLiveEndpointPairStatics const& f) { return f.FindEndpointPairByHostNamesAndPorts(localHostName, localPort, remoteHostName, remotePort); });
    }
    inline auto XboxLiveEndpointPairTemplate::GetTemplateByName(param::hstring const& name)
    {
        return impl::call_factory<XboxLiveEndpointPairTemplate, IXboxLiveEndpointPairTemplateStatics>([&](IXboxLiveEndpointPairTemplateStatics const& f) { return f.GetTemplateByName(name); });
    }
    inline auto XboxLiveEndpointPairTemplate::Templates()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate>(*)(IXboxLiveEndpointPairTemplateStatics const&), XboxLiveEndpointPairTemplate, IXboxLiveEndpointPairTemplateStatics>([](IXboxLiveEndpointPairTemplateStatics const& f) { return f.Templates(); });
    }
    inline XboxLiveQualityOfServiceMeasurement::XboxLiveQualityOfServiceMeasurement() :
        XboxLiveQualityOfServiceMeasurement(impl::call_factory_cast<XboxLiveQualityOfServiceMeasurement(*)(llm::OS::Foundation::IActivationFactory const&), XboxLiveQualityOfServiceMeasurement>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<XboxLiveQualityOfServiceMeasurement>(); }))
    {
    }
    inline auto XboxLiveQualityOfServiceMeasurement::PublishPrivatePayloadBytes(array_view<uint8_t const> payload)
    {
        impl::call_factory<XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([&](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.PublishPrivatePayloadBytes(payload); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::ClearPrivatePayload()
    {
        impl::call_factory_cast<void(*)(IXboxLiveQualityOfServiceMeasurementStatics const&), XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.ClearPrivatePayload(); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::MaxSimultaneousProbeConnections()
    {
        return impl::call_factory_cast<uint32_t(*)(IXboxLiveQualityOfServiceMeasurementStatics const&), XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.MaxSimultaneousProbeConnections(); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::MaxSimultaneousProbeConnections(uint32_t value)
    {
        impl::call_factory<XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([&](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.MaxSimultaneousProbeConnections(value); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::IsSystemOutboundBandwidthConstrained()
    {
        return impl::call_factory_cast<bool(*)(IXboxLiveQualityOfServiceMeasurementStatics const&), XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.IsSystemOutboundBandwidthConstrained(); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::IsSystemOutboundBandwidthConstrained(bool value)
    {
        impl::call_factory<XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([&](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.IsSystemOutboundBandwidthConstrained(value); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::IsSystemInboundBandwidthConstrained()
    {
        return impl::call_factory_cast<bool(*)(IXboxLiveQualityOfServiceMeasurementStatics const&), XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.IsSystemInboundBandwidthConstrained(); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::IsSystemInboundBandwidthConstrained(bool value)
    {
        impl::call_factory<XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([&](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.IsSystemInboundBandwidthConstrained(value); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::PublishedPrivatePayload()
    {
        return impl::call_factory_cast<llm::OS::Storage::Streams::IBuffer(*)(IXboxLiveQualityOfServiceMeasurementStatics const&), XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.PublishedPrivatePayload(); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::PublishedPrivatePayload(llm::OS::Storage::Streams::IBuffer const& value)
    {
        impl::call_factory<XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([&](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.PublishedPrivatePayload(value); });
    }
    inline auto XboxLiveQualityOfServiceMeasurement::MaxPrivatePayloadSize()
    {
        return impl::call_factory_cast<uint32_t(*)(IXboxLiveQualityOfServiceMeasurementStatics const&), XboxLiveQualityOfServiceMeasurement, IXboxLiveQualityOfServiceMeasurementStatics>([](IXboxLiveQualityOfServiceMeasurementStatics const& f) { return f.MaxPrivatePayloadSize(); });
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveDeviceAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveDeviceAddressStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveEndpointPair> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveEndpointPairCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveEndpointPairStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveEndpointPairTemplateStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveInboundEndpointPairCreatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMeasurementStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveQualityOfServiceMetricResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::IXboxLiveQualityOfServicePrivatePayloadResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveDeviceAddress> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveEndpointPair> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveEndpointPairCreationResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveEndpointPairStateChangedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveEndpointPairTemplate> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveInboundEndpointPairCreatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMeasurement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveQualityOfServiceMetricResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::XboxLive::XboxLiveQualityOfServicePrivatePayloadResult> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
