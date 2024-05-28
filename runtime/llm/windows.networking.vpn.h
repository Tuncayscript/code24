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
#ifndef LLM_OS_Networking_Vpn_H
#define LLM_OS_Networking_Vpn_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Networking.h"
#include "llm/impl/Windows.ApplicationModel.Activation.2.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Networking.2.h"
#include "llm/impl/Windows.Networking.Sockets.2.h"
#include "llm/impl/Windows.Security.Credentials.2.h"
#include "llm/impl/Windows.Security.Cryptography.Certificates.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Networking.Vpn.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnAppIdType) consume_Windows_Networking_Vpn_IVpnAppId<D>::Type() const
    {
        llm::OS::Networking::Vpn::VpnAppIdType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnAppId)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnAppId<D>::Type(llm::OS::Networking::Vpn::VpnAppIdType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnAppId)->put_Type(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnAppId<D>::Value() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnAppId)->get_Value(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnAppId<D>::Value(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnAppId)->put_Value(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnAppId) consume_Windows_Networking_Vpn_IVpnAppIdFactory<D>::Create(llm::OS::Networking::Vpn::VpnAppIdType const& type, param::hstring const& value) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnAppIdFactory)->Create(static_cast<int32_t>(type), *(void**)(&value), &result));
        return llm::OS::Networking::Vpn::VpnAppId{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::AssociateTransport(llm::OS::Foundation::IInspectable const& mainOuterTunnelTransport, llm::OS::Foundation::IInspectable const& optionalOuterTunnelTransport) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->AssociateTransport(*(void**)(&mainOuterTunnelTransport), *(void**)(&optionalOuterTunnelTransport)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::Start(param::vector_view<llm::OS::Networking::HostName> const& assignedClientIPv4list, param::vector_view<llm::OS::Networking::HostName> const& assignedClientIPv6list, llm::OS::Networking::Vpn::VpnInterfaceId const& vpnInterfaceId, llm::OS::Networking::Vpn::VpnRouteAssignment const& routeScope, llm::OS::Networking::Vpn::VpnNamespaceAssignment const& namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, llm::OS::Foundation::IInspectable const& mainOuterTunnelTransport, llm::OS::Foundation::IInspectable const& optionalOuterTunnelTransport) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->Start(*(void**)(&assignedClientIPv4list), *(void**)(&assignedClientIPv6list), *(void**)(&vpnInterfaceId), *(void**)(&routeScope), *(void**)(&namespaceScope), mtuSize, maxFrameSize, optimizeForLowCostNetwork, *(void**)(&mainOuterTunnelTransport), *(void**)(&optionalOuterTunnelTransport)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::Stop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->Stop());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPickedCredential) consume_Windows_Networking_Vpn_IVpnChannel<D>::RequestCredentials(llm::OS::Networking::Vpn::VpnCredentialType const& credType, bool isRetry, bool isSingleSignOnCredential, llm::OS::Security::Cryptography::Certificates::Certificate const& certificate) const
    {
        void* credential{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->RequestCredentials(static_cast<int32_t>(credType), isRetry, isSingleSignOnCredential, *(void**)(&certificate), &credential));
        return llm::OS::Networking::Vpn::VpnPickedCredential{ credential, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::RequestVpnPacketBuffer(llm::OS::Networking::Vpn::VpnDataPathType const& type, llm::OS::Networking::Vpn::VpnPacketBuffer& vpnPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->RequestVpnPacketBuffer(static_cast<int32_t>(type), impl::bind_out(vpnPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::LogDiagnosticMessage(param::hstring const& message) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->LogDiagnosticMessage(*(void**)(&message)));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_Vpn_IVpnChannel<D>::Id() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->get_Id(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnChannelConfiguration) consume_Windows_Networking_Vpn_IVpnChannel<D>::Configuration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->get_Configuration(&value));
        return llm::OS::Networking::Vpn::VpnChannelConfiguration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_Vpn_IVpnChannel<D>::ActivityChange(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::Vpn::VpnChannel, llm::OS::Networking::Vpn::VpnChannelActivityEventArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->add_ActivityChange(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_Vpn_IVpnChannel<D>::ActivityChange_revoker consume_Windows_Networking_Vpn_IVpnChannel<D>::ActivityChange(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::Vpn::VpnChannel, llm::OS::Networking::Vpn::VpnChannelActivityEventArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ActivityChange_revoker>(this, ActivityChange(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::ActivityChange(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->remove_ActivityChange(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::PlugInContext(llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->put_PlugInContext(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Networking_Vpn_IVpnChannel<D>::PlugInContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->get_PlugInContext(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnSystemHealth) consume_Windows_Networking_Vpn_IVpnChannel<D>::SystemHealth() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->get_SystemHealth(&value));
        return llm::OS::Networking::Vpn::VpnSystemHealth{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::RequestCustomPrompt(param::vector_view<llm::OS::Networking::Vpn::IVpnCustomPrompt> const& customPrompt) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->RequestCustomPrompt(*(void**)(&customPrompt)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::SetErrorMessage(param::hstring const& message) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->SetErrorMessage(*(void**)(&message)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel<D>::SetAllowedSslTlsVersions(llm::OS::Foundation::IInspectable const& tunnelTransport, bool useTls12) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel)->SetAllowedSslTlsVersions(*(void**)(&tunnelTransport), useTls12));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel2<D>::StartWithMainTransport(param::vector_view<llm::OS::Networking::HostName> const& assignedClientIPv4list, param::vector_view<llm::OS::Networking::HostName> const& assignedClientIPv6list, llm::OS::Networking::Vpn::VpnInterfaceId const& vpnInterfaceId, llm::OS::Networking::Vpn::VpnRouteAssignment const& assignedRoutes, llm::OS::Networking::Vpn::VpnDomainNameAssignment const& assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, llm::OS::Foundation::IInspectable const& mainOuterTunnelTransport) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->StartWithMainTransport(*(void**)(&assignedClientIPv4list), *(void**)(&assignedClientIPv6list), *(void**)(&vpnInterfaceId), *(void**)(&assignedRoutes), *(void**)(&assignedDomainName), mtuSize, maxFrameSize, Reserved, *(void**)(&mainOuterTunnelTransport)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel2<D>::StartExistingTransports(param::vector_view<llm::OS::Networking::HostName> const& assignedClientIPv4list, param::vector_view<llm::OS::Networking::HostName> const& assignedClientIPv6list, llm::OS::Networking::Vpn::VpnInterfaceId const& vpnInterfaceId, llm::OS::Networking::Vpn::VpnRouteAssignment const& assignedRoutes, llm::OS::Networking::Vpn::VpnDomainNameAssignment const& assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->StartExistingTransports(*(void**)(&assignedClientIPv4list), *(void**)(&assignedClientIPv6list), *(void**)(&vpnInterfaceId), *(void**)(&assignedRoutes), *(void**)(&assignedDomainName), mtuSize, maxFrameSize, Reserved));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Networking_Vpn_IVpnChannel2<D>::ActivityStateChange(llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::Vpn::VpnChannel, llm::OS::Networking::Vpn::VpnChannelActivityStateChangedArgs> const& handler) const
    {
        llm::event_token token{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->add_ActivityStateChange(*(void**)(&handler), put_abi(token)));
        return token;
    }
    template <typename D> typename consume_Windows_Networking_Vpn_IVpnChannel2<D>::ActivityStateChange_revoker consume_Windows_Networking_Vpn_IVpnChannel2<D>::ActivityStateChange(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::Vpn::VpnChannel, llm::OS::Networking::Vpn::VpnChannelActivityStateChangedArgs> const& handler) const
    {
        return impl::make_event_revoker<D, ActivityStateChange_revoker>(this, ActivityStateChange(handler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel2<D>::ActivityStateChange(llm::event_token const& token) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->remove_ActivityStateChange(impl::bind_in(token));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnChannel2<D>::GetVpnSendPacketBuffer() const
    {
        void* vpnSendPacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->GetVpnSendPacketBuffer(&vpnSendPacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ vpnSendPacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnChannel2<D>::GetVpnReceivePacketBuffer() const
    {
        void* vpnReceivePacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->GetVpnReceivePacketBuffer(&vpnReceivePacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ vpnReceivePacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Networking_Vpn_IVpnChannel2<D>::RequestCustomPromptAsync(param::async_vector_view<llm::OS::Networking::Vpn::IVpnCustomPromptElement> const& customPromptElement) const
    {
        void* action{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->RequestCustomPromptAsync(*(void**)(&customPromptElement), &action));
        return llm::OS::Foundation::IAsyncAction{ action, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>) consume_Windows_Networking_Vpn_IVpnChannel2<D>::RequestCredentialsAsync(llm::OS::Networking::Vpn::VpnCredentialType const& credType, uint32_t credOptions, llm::OS::Security::Cryptography::Certificates::Certificate const& certificate) const
    {
        void* credential{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->RequestCredentialsWithCertificateAsync(static_cast<int32_t>(credType), credOptions, *(void**)(&certificate), &credential));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>{ credential, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>) consume_Windows_Networking_Vpn_IVpnChannel2<D>::RequestCredentialsAsync(llm::OS::Networking::Vpn::VpnCredentialType const& credType, uint32_t credOptions) const
    {
        void* credential{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->RequestCredentialsWithOptionsAsync(static_cast<int32_t>(credType), credOptions, &credential));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>{ credential, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>) consume_Windows_Networking_Vpn_IVpnChannel2<D>::RequestCredentialsAsync(llm::OS::Networking::Vpn::VpnCredentialType const& credType) const
    {
        void* credential{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->RequestCredentialsSimpleAsync(static_cast<int32_t>(credType), &credential));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>{ credential, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel2<D>::TerminateConnection(param::hstring const& message) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->TerminateConnection(*(void**)(&message)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel2<D>::StartWithTrafficFilter(param::vector_view<llm::OS::Networking::HostName> const& assignedClientIpv4List, param::vector_view<llm::OS::Networking::HostName> const& assignedClientIpv6List, llm::OS::Networking::Vpn::VpnInterfaceId const& vpnInterfaceId, llm::OS::Networking::Vpn::VpnRouteAssignment const& assignedRoutes, llm::OS::Networking::Vpn::VpnDomainNameAssignment const& assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, llm::OS::Foundation::IInspectable const& mainOuterTunnelTransport, llm::OS::Foundation::IInspectable const& optionalOuterTunnelTransport, llm::OS::Networking::Vpn::VpnTrafficFilterAssignment const& assignedTrafficFilters) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel2)->StartWithTrafficFilter(*(void**)(&assignedClientIpv4List), *(void**)(&assignedClientIpv6List), *(void**)(&vpnInterfaceId), *(void**)(&assignedRoutes), *(void**)(&assignedNamespace), mtuSize, maxFrameSize, reserved, *(void**)(&mainOuterTunnelTransport), *(void**)(&optionalOuterTunnelTransport), *(void**)(&assignedTrafficFilters)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel4<D>::AddAndAssociateTransport(llm::OS::Foundation::IInspectable const& transport, llm::OS::Foundation::IInspectable const& context) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel4)->AddAndAssociateTransport(*(void**)(&transport), *(void**)(&context)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel4<D>::StartWithTrafficFilter(param::iterable<llm::OS::Networking::HostName> const& assignedClientIpv4Addresses, param::iterable<llm::OS::Networking::HostName> const& assignedClientIpv6Addresses, llm::OS::Networking::Vpn::VpnInterfaceId const& vpninterfaceId, llm::OS::Networking::Vpn::VpnRouteAssignment const& assignedRoutes, llm::OS::Networking::Vpn::VpnDomainNameAssignment const& assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, param::iterable<llm::OS::Foundation::IInspectable> const& transports, llm::OS::Networking::Vpn::VpnTrafficFilterAssignment const& assignedTrafficFilters) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel4)->StartWithMultipleTransports(*(void**)(&assignedClientIpv4Addresses), *(void**)(&assignedClientIpv6Addresses), *(void**)(&vpninterfaceId), *(void**)(&assignedRoutes), *(void**)(&assignedNamespace), mtuSize, maxFrameSize, reserved, *(void**)(&transports), *(void**)(&assignedTrafficFilters)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel4<D>::ReplaceAndAssociateTransport(llm::OS::Foundation::IInspectable const& transport, llm::OS::Foundation::IInspectable const& context) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel4)->ReplaceAndAssociateTransport(*(void**)(&transport), *(void**)(&context)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel4<D>::StartReconnectingTransport(llm::OS::Foundation::IInspectable const& transport, llm::OS::Foundation::IInspectable const& context) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel4)->StartReconnectingTransport(*(void**)(&transport), *(void**)(&context)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Sockets::ControlChannelTriggerStatus) consume_Windows_Networking_Vpn_IVpnChannel4<D>::GetSlotTypeForTransportContext(llm::OS::Foundation::IInspectable const& context) const
    {
        llm::OS::Networking::Sockets::ControlChannelTriggerStatus slotType{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel4)->GetSlotTypeForTransportContext(*(void**)(&context), reinterpret_cast<int32_t*>(&slotType)));
        return slotType;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Networking_Vpn_IVpnChannel4<D>::CurrentRequestTransportContext() const
    {
        void* context{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel4)->get_CurrentRequestTransportContext(&context));
        return llm::OS::Foundation::IInspectable{ context, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel5<D>::AppendVpnReceivePacketBuffer(llm::OS::Networking::Vpn::VpnPacketBuffer const& decapsulatedPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel5)->AppendVpnReceivePacketBuffer(*(void**)(&decapsulatedPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel5<D>::AppendVpnSendPacketBuffer(llm::OS::Networking::Vpn::VpnPacketBuffer const& encapsulatedPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel5)->AppendVpnSendPacketBuffer(*(void**)(&encapsulatedPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel5<D>::FlushVpnReceivePacketBuffers() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel5)->FlushVpnReceivePacketBuffers());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannel5<D>::FlushVpnSendPacketBuffers() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel5)->FlushVpnSendPacketBuffers());
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Networking_Vpn_IVpnChannel6<D>::ActivateForeground(param::hstring const& packageRelativeAppId, llm::OS::Foundation::Collections::ValueSet const& sharedContext) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannel6)->ActivateForeground(*(void**)(&packageRelativeAppId), *(void**)(&sharedContext), &result));
        return llm::OS::Foundation::Collections::ValueSet{ result, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnChannelActivityEventType) consume_Windows_Networking_Vpn_IVpnChannelActivityEventArgs<D>::Type() const
    {
        llm::OS::Networking::Vpn::VpnChannelActivityEventType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelActivityEventArgs)->get_Type(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnChannelActivityEventType) consume_Windows_Networking_Vpn_IVpnChannelActivityStateChangedArgs<D>::ActivityState() const
    {
        llm::OS::Networking::Vpn::VpnChannelActivityEventType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelActivityStateChangedArgs)->get_ActivityState(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnChannelConfiguration<D>::ServerServiceName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelConfiguration)->get_ServerServiceName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>) consume_Windows_Networking_Vpn_IVpnChannelConfiguration<D>::ServerHostNameList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelConfiguration)->get_ServerHostNameList(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnChannelConfiguration<D>::CustomField() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelConfiguration)->get_CustomField(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>) consume_Windows_Networking_Vpn_IVpnChannelConfiguration2<D>::ServerUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelConfiguration2)->get_ServerUris(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnChannelStatics<D>::ProcessEventAsync(llm::OS::Foundation::IInspectable const& thirdPartyPlugIn, llm::OS::Foundation::IInspectable const& event) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnChannelStatics)->ProcessEventAsync(*(void**)(&thirdPartyPlugIn), *(void**)(&event)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Networking_Vpn_IVpnCredential<D>::PasskeyCredential() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCredential)->get_PasskeyCredential(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Cryptography::Certificates::Certificate) consume_Windows_Networking_Vpn_IVpnCredential<D>::CertificateCredential() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCredential)->get_CertificateCredential(&value));
        return llm::OS::Security::Cryptography::Certificates::Certificate{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCredential<D>::AdditionalPin() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCredential)->get_AdditionalPin(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Networking_Vpn_IVpnCredential<D>::OldPasswordCredential() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCredential)->get_OldPasswordCredential(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomCheckBox<D>::InitialCheckState(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomCheckBox)->put_InitialCheckState(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomCheckBox<D>::InitialCheckState() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomCheckBox)->get_InitialCheckState(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomCheckBox<D>::Checked() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomCheckBox)->get_Checked(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomComboBox<D>::OptionsText(param::async_vector_view<hstring> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomComboBox)->put_OptionsText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<hstring>) consume_Windows_Networking_Vpn_IVpnCustomComboBox<D>::OptionsText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomComboBox)->get_OptionsText(&value));
        return llm::OS::Foundation::Collections::IVectorView<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_Vpn_IVpnCustomComboBox<D>::Selected() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomComboBox)->get_Selected(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomEditBox<D>::DefaultText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomEditBox)->put_DefaultText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomEditBox<D>::DefaultText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomEditBox)->get_DefaultText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomEditBox<D>::NoEcho(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomEditBox)->put_NoEcho(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomEditBox<D>::NoEcho() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomEditBox)->get_NoEcho(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomEditBox<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomEditBox)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPrompt<D>::Label(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPrompt)->put_Label(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomPrompt<D>::Label() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPrompt)->get_Label(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPrompt<D>::Compulsory(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPrompt)->put_Compulsory(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPrompt<D>::Compulsory() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPrompt)->get_Compulsory(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPrompt<D>::Bordered(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPrompt)->put_Bordered(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPrompt<D>::Bordered() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPrompt)->get_Bordered(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptBooleanInput<D>::InitialValue(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptBooleanInput)->put_InitialValue(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPromptBooleanInput<D>::InitialValue() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptBooleanInput)->get_InitialValue(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPromptBooleanInput<D>::Value() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptBooleanInput)->get_Value(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptElement<D>::DisplayName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptElement)->put_DisplayName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomPromptElement<D>::DisplayName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptElement)->get_DisplayName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptElement<D>::Compulsory(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptElement)->put_Compulsory(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPromptElement<D>::Compulsory() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptElement)->get_Compulsory(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptElement<D>::Emphasized(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptElement)->put_Emphasized(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPromptElement<D>::Emphasized() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptElement)->get_Emphasized(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnCustomPromptOptionSelector<D>::Options() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptOptionSelector)->get_Options(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_Vpn_IVpnCustomPromptOptionSelector<D>::SelectedIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptOptionSelector)->get_SelectedIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptText<D>::Text(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptText)->put_Text(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomPromptText<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptText)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptTextInput<D>::PlaceholderText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptTextInput)->put_PlaceholderText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomPromptTextInput<D>::PlaceholderText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptTextInput)->get_PlaceholderText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomPromptTextInput<D>::IsTextHidden(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptTextInput)->put_IsTextHidden(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnCustomPromptTextInput<D>::IsTextHidden() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptTextInput)->get_IsTextHidden(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomPromptTextInput<D>::Text() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomPromptTextInput)->get_Text(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnCustomTextBox<D>::DisplayText(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomTextBox)->put_DisplayText(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnCustomTextBox<D>::DisplayText() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnCustomTextBox)->get_DisplayText(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnDomainNameInfo>) consume_Windows_Networking_Vpn_IVpnDomainNameAssignment<D>::DomainNameList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameAssignment)->get_DomainNameList(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnDomainNameInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnDomainNameAssignment<D>::ProxyAutoConfigurationUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameAssignment)->put_ProxyAutoConfigurationUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_Vpn_IVpnDomainNameAssignment<D>::ProxyAutoConfigurationUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameAssignment)->get_ProxyAutoConfigurationUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnDomainNameInfo<D>::DomainName(llm::OS::Networking::HostName const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo)->put_DomainName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_Vpn_IVpnDomainNameInfo<D>::DomainName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo)->get_DomainName(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnDomainNameInfo<D>::DomainNameType(llm::OS::Networking::Vpn::VpnDomainNameType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo)->put_DomainNameType(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnDomainNameType) consume_Windows_Networking_Vpn_IVpnDomainNameInfo<D>::DomainNameType() const
    {
        llm::OS::Networking::Vpn::VpnDomainNameType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo)->get_DomainNameType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>) consume_Windows_Networking_Vpn_IVpnDomainNameInfo<D>::DnsServers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo)->get_DnsServers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>) consume_Windows_Networking_Vpn_IVpnDomainNameInfo<D>::WebProxyServers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo)->get_WebProxyServers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>) consume_Windows_Networking_Vpn_IVpnDomainNameInfo2<D>::WebProxyUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfo2)->get_WebProxyUris(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnDomainNameInfo) consume_Windows_Networking_Vpn_IVpnDomainNameInfoFactory<D>::CreateVpnDomainNameInfo(param::hstring const& name, llm::OS::Networking::Vpn::VpnDomainNameType const& nameType, param::iterable<llm::OS::Networking::HostName> const& dnsServerList, param::iterable<llm::OS::Networking::HostName> const& proxyServerList) const
    {
        void* domainNameInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnDomainNameInfoFactory)->CreateVpnDomainNameInfo(*(void**)(&name), static_cast<int32_t>(nameType), *(void**)(&dnsServerList), *(void**)(&proxyServerList), &domainNameInfo));
        return llm::OS::Networking::Vpn::VpnDomainNameInfo{ domainNameInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnForegroundActivatedEventArgs<D>::ProfileName() const
    {
        void* name{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnForegroundActivatedEventArgs)->get_ProfileName(&name));
        return hstring{ name, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::ValueSet) consume_Windows_Networking_Vpn_IVpnForegroundActivatedEventArgs<D>::SharedContext() const
    {
        void* sharedContext{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnForegroundActivatedEventArgs)->get_SharedContext(&sharedContext));
        return llm::OS::Foundation::Collections::ValueSet{ sharedContext, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnForegroundActivationOperation) consume_Windows_Networking_Vpn_IVpnForegroundActivatedEventArgs<D>::ActivationOperation() const
    {
        void* activationOperation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnForegroundActivatedEventArgs)->get_ActivationOperation(&activationOperation));
        return llm::OS::Networking::Vpn::VpnForegroundActivationOperation{ activationOperation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnForegroundActivationOperation<D>::Complete(llm::OS::Foundation::Collections::ValueSet const& result) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnForegroundActivationOperation)->Complete(*(void**)(&result)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnInterfaceId<D>::GetAddressInfo(com_array<uint8_t>& id) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnInterfaceId)->GetAddressInfo(impl::put_size_abi(id), put_abi(id)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnInterfaceId) consume_Windows_Networking_Vpn_IVpnInterfaceIdFactory<D>::CreateVpnInterfaceId(array_view<uint8_t const> address) const
    {
        void* vpnInterfaceId{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnInterfaceIdFactory)->CreateVpnInterfaceId(address.size(), get_abi(address), &vpnInterfaceId));
        return llm::OS::Networking::Vpn::VpnInterfaceId{ vpnInterfaceId, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::AddProfileFromXmlAsync(param::hstring const& xml) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->AddProfileFromXmlAsync(*(void**)(&xml), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::AddProfileFromObjectAsync(llm::OS::Networking::Vpn::IVpnProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->AddProfileFromObjectAsync(*(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::UpdateProfileFromXmlAsync(param::hstring const& xml) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->UpdateProfileFromXmlAsync(*(void**)(&xml), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::UpdateProfileFromObjectAsync(llm::OS::Networking::Vpn::IVpnProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->UpdateProfileFromObjectAsync(*(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Vpn::IVpnProfile>>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::GetProfilesAsync() const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->GetProfilesAsync(&operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Vpn::IVpnProfile>>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::DeleteProfileAsync(llm::OS::Networking::Vpn::IVpnProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->DeleteProfileAsync(*(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::ConnectProfileAsync(llm::OS::Networking::Vpn::IVpnProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->ConnectProfileAsync(*(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::ConnectProfileWithPasswordCredentialAsync(llm::OS::Networking::Vpn::IVpnProfile const& profile, llm::OS::Security::Credentials::PasswordCredential const& passwordCredential) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->ConnectProfileWithPasswordCredentialAsync(*(void**)(&profile), *(void**)(&passwordCredential), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>) consume_Windows_Networking_Vpn_IVpnManagementAgent<D>::DisconnectProfileAsync(llm::OS::Networking::Vpn::IVpnProfile const& profile) const
    {
        void* operation{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnManagementAgent)->DisconnectProfileAsync(*(void**)(&profile), &operation));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>{ operation, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNamespaceAssignment<D>::NamespaceList(param::vector<llm::OS::Networking::Vpn::VpnNamespaceInfo> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceAssignment)->put_NamespaceList(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnNamespaceInfo>) consume_Windows_Networking_Vpn_IVpnNamespaceAssignment<D>::NamespaceList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceAssignment)->get_NamespaceList(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnNamespaceInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNamespaceAssignment<D>::ProxyAutoConfigUri(llm::OS::Foundation::Uri const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceAssignment)->put_ProxyAutoConfigUri(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Uri) consume_Windows_Networking_Vpn_IVpnNamespaceAssignment<D>::ProxyAutoConfigUri() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceAssignment)->get_ProxyAutoConfigUri(&value));
        return llm::OS::Foundation::Uri{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNamespaceInfo<D>::Namespace(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfo)->put_Namespace(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnNamespaceInfo<D>::Namespace() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfo)->get_Namespace(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNamespaceInfo<D>::DnsServers(param::vector<llm::OS::Networking::HostName> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfo)->put_DnsServers(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>) consume_Windows_Networking_Vpn_IVpnNamespaceInfo<D>::DnsServers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfo)->get_DnsServers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNamespaceInfo<D>::WebProxyServers(param::vector<llm::OS::Networking::HostName> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfo)->put_WebProxyServers(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>) consume_Windows_Networking_Vpn_IVpnNamespaceInfo<D>::WebProxyServers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfo)->get_WebProxyServers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnNamespaceInfo) consume_Windows_Networking_Vpn_IVpnNamespaceInfoFactory<D>::CreateVpnNamespaceInfo(param::hstring const& name, param::vector<llm::OS::Networking::HostName> const& dnsServerList, param::vector<llm::OS::Networking::HostName> const& proxyServerList) const
    {
        void* namespaceInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNamespaceInfoFactory)->CreateVpnNamespaceInfo(*(void**)(&name), *(void**)(&dnsServerList), *(void**)(&proxyServerList), &namespaceInfo));
        return llm::OS::Networking::Vpn::VpnNamespaceInfo{ namespaceInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::Servers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->get_Servers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnRoutingPolicyType) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::RoutingPolicyType() const
    {
        llm::OS::Networking::Vpn::VpnRoutingPolicyType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->get_RoutingPolicyType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::RoutingPolicyType(llm::OS::Networking::Vpn::VpnRoutingPolicyType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->put_RoutingPolicyType(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnNativeProtocolType) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::NativeProtocolType() const
    {
        llm::OS::Networking::Vpn::VpnNativeProtocolType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->get_NativeProtocolType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::NativeProtocolType(llm::OS::Networking::Vpn::VpnNativeProtocolType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->put_NativeProtocolType(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnAuthenticationMethod) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::UserAuthenticationMethod() const
    {
        llm::OS::Networking::Vpn::VpnAuthenticationMethod value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->get_UserAuthenticationMethod(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::UserAuthenticationMethod(llm::OS::Networking::Vpn::VpnAuthenticationMethod const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->put_UserAuthenticationMethod(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnAuthenticationMethod) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::TunnelAuthenticationMethod() const
    {
        llm::OS::Networking::Vpn::VpnAuthenticationMethod value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->get_TunnelAuthenticationMethod(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::TunnelAuthenticationMethod(llm::OS::Networking::Vpn::VpnAuthenticationMethod const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->put_TunnelAuthenticationMethod(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::EapConfiguration() const
    {
        void* Value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->get_EapConfiguration(&Value));
        return hstring{ Value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNativeProfile<D>::EapConfiguration(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile)->put_EapConfiguration(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnNativeProfile2<D>::RequireVpnClientAppUI() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile2)->get_RequireVpnClientAppUI(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnNativeProfile2<D>::RequireVpnClientAppUI(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile2)->put_RequireVpnClientAppUI(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnManagementConnectionStatus) consume_Windows_Networking_Vpn_IVpnNativeProfile2<D>::ConnectionStatus() const
    {
        llm::OS::Networking::Vpn::VpnManagementConnectionStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnNativeProfile2)->get_ConnectionStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::Buffer) consume_Windows_Networking_Vpn_IVpnPacketBuffer<D>::Buffer() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer)->get_Buffer(&value));
        return llm::OS::Storage::Streams::Buffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBuffer<D>::Status(llm::OS::Networking::Vpn::VpnPacketBufferStatus const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer)->put_Status(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBufferStatus) consume_Windows_Networking_Vpn_IVpnPacketBuffer<D>::Status() const
    {
        llm::OS::Networking::Vpn::VpnPacketBufferStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBuffer<D>::TransportAffinity(uint32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer)->put_TransportAffinity(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_Vpn_IVpnPacketBuffer<D>::TransportAffinity() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer)->get_TransportAffinity(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnAppId) consume_Windows_Networking_Vpn_IVpnPacketBuffer2<D>::AppId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer2)->get_AppId(&value));
        return llm::OS::Networking::Vpn::VpnAppId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBuffer3<D>::TransportContext(llm::OS::Foundation::IInspectable const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer3)->put_TransportContext(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IInspectable) consume_Windows_Networking_Vpn_IVpnPacketBuffer3<D>::TransportContext() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBuffer3)->get_TransportContext(&value));
        return llm::OS::Foundation::IInspectable{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnPacketBufferFactory<D>::CreateVpnPacketBuffer(llm::OS::Networking::Vpn::VpnPacketBuffer const& parentBuffer, uint32_t offset, uint32_t length) const
    {
        void* vpnPacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferFactory)->CreateVpnPacketBuffer(*(void**)(&parentBuffer), offset, length, &vpnPacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ vpnPacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::Append(llm::OS::Networking::Vpn::VpnPacketBuffer const& nextVpnPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->Append(*(void**)(&nextVpnPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::AddAtBegin(llm::OS::Networking::Vpn::VpnPacketBuffer const& nextVpnPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->AddAtBegin(*(void**)(&nextVpnPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::RemoveAtEnd() const
    {
        void* nextVpnPacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->RemoveAtEnd(&nextVpnPacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ nextVpnPacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::RemoveAtBegin() const
    {
        void* nextVpnPacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->RemoveAtBegin(&nextVpnPacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ nextVpnPacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::Clear() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->Clear());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::Status(llm::OS::Networking::Vpn::VpnPacketBufferStatus const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->put_Status(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBufferStatus) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::Status() const
    {
        llm::OS::Networking::Vpn::VpnPacketBufferStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->get_Status(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Networking_Vpn_IVpnPacketBufferList<D>::Size() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList)->get_Size(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBufferList2<D>::AddLeadingPacket(llm::OS::Networking::Vpn::VpnPacketBuffer const& nextVpnPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList2)->AddLeadingPacket(*(void**)(&nextVpnPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnPacketBufferList2<D>::RemoveLeadingPacket() const
    {
        void* nextVpnPacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList2)->RemoveLeadingPacket(&nextVpnPacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ nextVpnPacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPacketBufferList2<D>::AddTrailingPacket(llm::OS::Networking::Vpn::VpnPacketBuffer const& nextVpnPacketBuffer) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList2)->AddTrailingPacket(*(void**)(&nextVpnPacketBuffer)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnPacketBuffer) consume_Windows_Networking_Vpn_IVpnPacketBufferList2<D>::RemoveTrailingPacket() const
    {
        void* nextVpnPacketBuffer{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPacketBufferList2)->RemoveTrailingPacket(&nextVpnPacketBuffer));
        return llm::OS::Networking::Vpn::VpnPacketBuffer{ nextVpnPacketBuffer, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Networking_Vpn_IVpnPickedCredential<D>::PasskeyCredential() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPickedCredential)->get_PasskeyCredential(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnPickedCredential<D>::AdditionalPin() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPickedCredential)->get_AdditionalPin(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Security::Credentials::PasswordCredential) consume_Windows_Networking_Vpn_IVpnPickedCredential<D>::OldPasswordCredential() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPickedCredential)->get_OldPasswordCredential(&value));
        return llm::OS::Security::Credentials::PasswordCredential{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugIn<D>::Connect(llm::OS::Networking::Vpn::VpnChannel const& channel) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugIn)->Connect(*(void**)(&channel)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugIn<D>::Disconnect(llm::OS::Networking::Vpn::VpnChannel const& channel) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugIn)->Disconnect(*(void**)(&channel)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugIn<D>::GetKeepAlivePayload(llm::OS::Networking::Vpn::VpnChannel const& channel, llm::OS::Networking::Vpn::VpnPacketBuffer& keepAlivePacket) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugIn)->GetKeepAlivePayload(*(void**)(&channel), impl::bind_out(keepAlivePacket)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugIn<D>::Encapsulate(llm::OS::Networking::Vpn::VpnChannel const& channel, llm::OS::Networking::Vpn::VpnPacketBufferList const& packets, llm::OS::Networking::Vpn::VpnPacketBufferList const& encapulatedPackets) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugIn)->Encapsulate(*(void**)(&channel), *(void**)(&packets), *(void**)(&encapulatedPackets)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugIn<D>::Decapsulate(llm::OS::Networking::Vpn::VpnChannel const& channel, llm::OS::Networking::Vpn::VpnPacketBuffer const& encapBuffer, llm::OS::Networking::Vpn::VpnPacketBufferList const& decapsulatedPackets, llm::OS::Networking::Vpn::VpnPacketBufferList const& controlPacketsToSend) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugIn)->Decapsulate(*(void**)(&channel), *(void**)(&encapBuffer), *(void**)(&decapsulatedPackets), *(void**)(&controlPacketsToSend)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>) consume_Windows_Networking_Vpn_IVpnPlugInProfile<D>::ServerUris() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile)->get_ServerUris(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnPlugInProfile<D>::CustomConfiguration() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile)->get_CustomConfiguration(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugInProfile<D>::CustomConfiguration(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile)->put_CustomConfiguration(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnPlugInProfile<D>::VpnPluginPackageFamilyName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile)->get_VpnPluginPackageFamilyName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugInProfile<D>::VpnPluginPackageFamilyName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile)->put_VpnPluginPackageFamilyName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnPlugInProfile2<D>::RequireVpnClientAppUI() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile2)->get_RequireVpnClientAppUI(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnPlugInProfile2<D>::RequireVpnClientAppUI(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile2)->put_RequireVpnClientAppUI(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnManagementConnectionStatus) consume_Windows_Networking_Vpn_IVpnPlugInProfile2<D>::ConnectionStatus() const
    {
        llm::OS::Networking::Vpn::VpnManagementConnectionStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnPlugInProfile2)->get_ConnectionStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Networking_Vpn_IVpnProfile<D>::ProfileName() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_ProfileName(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnProfile<D>::ProfileName(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->put_ProfileName(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnAppId>) consume_Windows_Networking_Vpn_IVpnProfile<D>::AppTriggers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_AppTriggers(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnAppId>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>) consume_Windows_Networking_Vpn_IVpnProfile<D>::Routes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_Routes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnDomainNameInfo>) consume_Windows_Networking_Vpn_IVpnProfile<D>::DomainNameInfoList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_DomainNameInfoList(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnDomainNameInfo>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnTrafficFilter>) consume_Windows_Networking_Vpn_IVpnProfile<D>::TrafficFilters() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_TrafficFilters(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnTrafficFilter>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnProfile<D>::RememberCredentials() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_RememberCredentials(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnProfile<D>::RememberCredentials(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->put_RememberCredentials(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnProfile<D>::AlwaysOn() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->get_AlwaysOn(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnProfile<D>::AlwaysOn(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnProfile)->put_AlwaysOn(value));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRoute<D>::Address(llm::OS::Networking::HostName const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRoute)->put_Address(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::HostName) consume_Windows_Networking_Vpn_IVpnRoute<D>::Address() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRoute)->get_Address(&value));
        return llm::OS::Networking::HostName{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRoute<D>::PrefixSize(uint8_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRoute)->put_PrefixSize(value));
    }
    template <typename D> LLM_IMPL_AUTO(uint8_t) consume_Windows_Networking_Vpn_IVpnRoute<D>::PrefixSize() const
    {
        uint8_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRoute)->get_PrefixSize(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv4InclusionRoutes(param::vector<llm::OS::Networking::Vpn::VpnRoute> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->put_Ipv4InclusionRoutes(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv6InclusionRoutes(param::vector<llm::OS::Networking::Vpn::VpnRoute> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->put_Ipv6InclusionRoutes(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv4InclusionRoutes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->get_Ipv4InclusionRoutes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv6InclusionRoutes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->get_Ipv6InclusionRoutes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv4ExclusionRoutes(param::vector<llm::OS::Networking::Vpn::VpnRoute> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->put_Ipv4ExclusionRoutes(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv6ExclusionRoutes(param::vector<llm::OS::Networking::Vpn::VpnRoute> const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->put_Ipv6ExclusionRoutes(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv4ExclusionRoutes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->get_Ipv4ExclusionRoutes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::Ipv6ExclusionRoutes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->get_Ipv6ExclusionRoutes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::ExcludeLocalSubnets(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->put_ExcludeLocalSubnets(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnRouteAssignment<D>::ExcludeLocalSubnets() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteAssignment)->get_ExcludeLocalSubnets(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnRoute) consume_Windows_Networking_Vpn_IVpnRouteFactory<D>::CreateVpnRoute(llm::OS::Networking::HostName const& address, uint8_t prefixSize) const
    {
        void* route{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnRouteFactory)->CreateVpnRoute(*(void**)(&address), prefixSize, &route));
        return llm::OS::Networking::Vpn::VpnRoute{ route, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::Buffer) consume_Windows_Networking_Vpn_IVpnSystemHealth<D>::StatementOfHealth() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnSystemHealth)->get_StatementOfHealth(&value));
        return llm::OS::Storage::Streams::Buffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnAppId) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::AppId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_AppId(&value));
        return llm::OS::Networking::Vpn::VpnAppId{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::AppId(llm::OS::Networking::Vpn::VpnAppId const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->put_AppId(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::AppClaims() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_AppClaims(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnIPProtocol) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::Protocol() const
    {
        llm::OS::Networking::Vpn::VpnIPProtocol value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_Protocol(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::Protocol(llm::OS::Networking::Vpn::VpnIPProtocol const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->put_Protocol(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::LocalPortRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_LocalPortRanges(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::RemotePortRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_RemotePortRanges(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::LocalAddressRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_LocalAddressRanges(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::RemoteAddressRanges() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_RemoteAddressRanges(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnRoutingPolicyType) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::RoutingPolicyType() const
    {
        llm::OS::Networking::Vpn::VpnRoutingPolicyType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->get_RoutingPolicyType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnTrafficFilter<D>::RoutingPolicyType(llm::OS::Networking::Vpn::VpnRoutingPolicyType const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilter)->put_RoutingPolicyType(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnTrafficFilter>) consume_Windows_Networking_Vpn_IVpnTrafficFilterAssignment<D>::TrafficFilterList() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment)->get_TrafficFilterList(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnTrafficFilter>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnTrafficFilterAssignment<D>::AllowOutbound() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment)->get_AllowOutbound(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnTrafficFilterAssignment<D>::AllowOutbound(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment)->put_AllowOutbound(value));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Networking_Vpn_IVpnTrafficFilterAssignment<D>::AllowInbound() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment)->get_AllowInbound(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Networking_Vpn_IVpnTrafficFilterAssignment<D>::AllowInbound(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment)->put_AllowInbound(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Networking::Vpn::VpnTrafficFilter) consume_Windows_Networking_Vpn_IVpnTrafficFilterFactory<D>::Create(llm::OS::Networking::Vpn::VpnAppId const& appId) const
    {
        void* result{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Networking::Vpn::IVpnTrafficFilterFactory)->Create(*(void**)(&appId), &result));
        return llm::OS::Networking::Vpn::VpnTrafficFilter{ result, take_ownership_from_abi };
    }
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnAppId> : produce_base<D, llm::OS::Networking::Vpn::IVpnAppId>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnAppIdType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Type(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Type(*reinterpret_cast<llm::OS::Networking::Vpn::VpnAppIdType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Value(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Value(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnAppIdFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnAppIdFactory>
    {
        int32_t __stdcall Create(int32_t type, void* value, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Vpn::VpnAppId>(this->shim().Create(*reinterpret_cast<llm::OS::Networking::Vpn::VpnAppIdType const*>(&type), *reinterpret_cast<hstring const*>(&value)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannel> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannel>
    {
        int32_t __stdcall AssociateTransport(void* mainOuterTunnelTransport, void* optionalOuterTunnelTransport) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AssociateTransport(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&mainOuterTunnelTransport), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&optionalOuterTunnelTransport));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Start(void* assignedClientIPv4list, void* assignedClientIPv6list, void* vpnInterfaceId, void* routeScope, void* namespaceScope, uint32_t mtuSize, uint32_t maxFrameSize, bool optimizeForLowCostNetwork, void* mainOuterTunnelTransport, void* optionalOuterTunnelTransport) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Start(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIPv4list), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIPv6list), *reinterpret_cast<llm::OS::Networking::Vpn::VpnInterfaceId const*>(&vpnInterfaceId), *reinterpret_cast<llm::OS::Networking::Vpn::VpnRouteAssignment const*>(&routeScope), *reinterpret_cast<llm::OS::Networking::Vpn::VpnNamespaceAssignment const*>(&namespaceScope), mtuSize, maxFrameSize, optimizeForLowCostNetwork, *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&mainOuterTunnelTransport), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&optionalOuterTunnelTransport));
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
        int32_t __stdcall RequestCredentials(int32_t credType, bool isRetry, bool isSingleSignOnCredential, void* certificate, void** credential) noexcept final try
        {
            clear_abi(credential);
            typename D::abi_guard guard(this->shim());
            *credential = detach_from<llm::OS::Networking::Vpn::VpnPickedCredential>(this->shim().RequestCredentials(*reinterpret_cast<llm::OS::Networking::Vpn::VpnCredentialType const*>(&credType), isRetry, isSingleSignOnCredential, *reinterpret_cast<llm::OS::Security::Cryptography::Certificates::Certificate const*>(&certificate)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestVpnPacketBuffer(int32_t type, void** vpnPacketBuffer) noexcept final try
        {
            clear_abi(vpnPacketBuffer);
            typename D::abi_guard guard(this->shim());
            this->shim().RequestVpnPacketBuffer(*reinterpret_cast<llm::OS::Networking::Vpn::VpnDataPathType const*>(&type), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer*>(vpnPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall LogDiagnosticMessage(void* message) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().LogDiagnosticMessage(*reinterpret_cast<hstring const*>(&message));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Id(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Configuration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnChannelConfiguration>(this->shim().Configuration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ActivityChange(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ActivityChange(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::Vpn::VpnChannel, llm::OS::Networking::Vpn::VpnChannelActivityEventArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ActivityChange(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActivityChange(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall put_PlugInContext(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlugInContext(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlugInContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().PlugInContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SystemHealth(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnSystemHealth>(this->shim().SystemHealth());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCustomPrompt(void* customPrompt) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequestCustomPrompt(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Vpn::IVpnCustomPrompt> const*>(&customPrompt));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetErrorMessage(void* message) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetErrorMessage(*reinterpret_cast<hstring const*>(&message));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetAllowedSslTlsVersions(void* tunnelTransport, bool useTls12) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetAllowedSslTlsVersions(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&tunnelTransport), useTls12);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannel2> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannel2>
    {
        int32_t __stdcall StartWithMainTransport(void* assignedClientIPv4list, void* assignedClientIPv6list, void* vpnInterfaceId, void* assignedRoutes, void* assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved, void* mainOuterTunnelTransport) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartWithMainTransport(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIPv4list), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIPv6list), *reinterpret_cast<llm::OS::Networking::Vpn::VpnInterfaceId const*>(&vpnInterfaceId), *reinterpret_cast<llm::OS::Networking::Vpn::VpnRouteAssignment const*>(&assignedRoutes), *reinterpret_cast<llm::OS::Networking::Vpn::VpnDomainNameAssignment const*>(&assignedDomainName), mtuSize, maxFrameSize, Reserved, *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&mainOuterTunnelTransport));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartExistingTransports(void* assignedClientIPv4list, void* assignedClientIPv6list, void* vpnInterfaceId, void* assignedRoutes, void* assignedDomainName, uint32_t mtuSize, uint32_t maxFrameSize, bool Reserved) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartExistingTransports(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIPv4list), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIPv6list), *reinterpret_cast<llm::OS::Networking::Vpn::VpnInterfaceId const*>(&vpnInterfaceId), *reinterpret_cast<llm::OS::Networking::Vpn::VpnRouteAssignment const*>(&assignedRoutes), *reinterpret_cast<llm::OS::Networking::Vpn::VpnDomainNameAssignment const*>(&assignedDomainName), mtuSize, maxFrameSize, Reserved);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_ActivityStateChange(void* handler, llm::event_token* token) noexcept final try
        {
            zero_abi<llm::event_token>(token);
            typename D::abi_guard guard(this->shim());
            *token = detach_from<llm::event_token>(this->shim().ActivityStateChange(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Networking::Vpn::VpnChannel, llm::OS::Networking::Vpn::VpnChannelActivityStateChangedArgs> const*>(&handler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_ActivityStateChange(llm::event_token token) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ActivityStateChange(*reinterpret_cast<llm::event_token const*>(&token));
            return 0;
        }
        int32_t __stdcall GetVpnSendPacketBuffer(void** vpnSendPacketBuffer) noexcept final try
        {
            clear_abi(vpnSendPacketBuffer);
            typename D::abi_guard guard(this->shim());
            *vpnSendPacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().GetVpnSendPacketBuffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetVpnReceivePacketBuffer(void** vpnReceivePacketBuffer) noexcept final try
        {
            clear_abi(vpnReceivePacketBuffer);
            typename D::abi_guard guard(this->shim());
            *vpnReceivePacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().GetVpnReceivePacketBuffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCustomPromptAsync(void* customPromptElement, void** action) noexcept final try
        {
            clear_abi(action);
            typename D::abi_guard guard(this->shim());
            *action = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().RequestCustomPromptAsync(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Vpn::IVpnCustomPromptElement> const*>(&customPromptElement)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCredentialsWithCertificateAsync(int32_t credType, uint32_t credOptions, void* certificate, void** credential) noexcept final try
        {
            clear_abi(credential);
            typename D::abi_guard guard(this->shim());
            *credential = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>>(this->shim().RequestCredentialsAsync(*reinterpret_cast<llm::OS::Networking::Vpn::VpnCredentialType const*>(&credType), credOptions, *reinterpret_cast<llm::OS::Security::Cryptography::Certificates::Certificate const*>(&certificate)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCredentialsWithOptionsAsync(int32_t credType, uint32_t credOptions, void** credential) noexcept final try
        {
            clear_abi(credential);
            typename D::abi_guard guard(this->shim());
            *credential = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>>(this->shim().RequestCredentialsAsync(*reinterpret_cast<llm::OS::Networking::Vpn::VpnCredentialType const*>(&credType), credOptions));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RequestCredentialsSimpleAsync(int32_t credType, void** credential) noexcept final try
        {
            clear_abi(credential);
            typename D::abi_guard guard(this->shim());
            *credential = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnCredential>>(this->shim().RequestCredentialsAsync(*reinterpret_cast<llm::OS::Networking::Vpn::VpnCredentialType const*>(&credType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall TerminateConnection(void* message) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TerminateConnection(*reinterpret_cast<hstring const*>(&message));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartWithTrafficFilter(void* assignedClientIpv4List, void* assignedClientIpv6List, void* vpnInterfaceId, void* assignedRoutes, void* assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, void* mainOuterTunnelTransport, void* optionalOuterTunnelTransport, void* assignedTrafficFilters) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartWithTrafficFilter(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIpv4List), *reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName> const*>(&assignedClientIpv6List), *reinterpret_cast<llm::OS::Networking::Vpn::VpnInterfaceId const*>(&vpnInterfaceId), *reinterpret_cast<llm::OS::Networking::Vpn::VpnRouteAssignment const*>(&assignedRoutes), *reinterpret_cast<llm::OS::Networking::Vpn::VpnDomainNameAssignment const*>(&assignedNamespace), mtuSize, maxFrameSize, reserved, *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&mainOuterTunnelTransport), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&optionalOuterTunnelTransport), *reinterpret_cast<llm::OS::Networking::Vpn::VpnTrafficFilterAssignment const*>(&assignedTrafficFilters));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannel4> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannel4>
    {
        int32_t __stdcall AddAndAssociateTransport(void* transport, void* context) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAndAssociateTransport(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&transport), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&context));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartWithMultipleTransports(void* assignedClientIpv4Addresses, void* assignedClientIpv6Addresses, void* vpninterfaceId, void* assignedRoutes, void* assignedNamespace, uint32_t mtuSize, uint32_t maxFrameSize, bool reserved, void* transports, void* assignedTrafficFilters) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartWithTrafficFilter(*reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::HostName> const*>(&assignedClientIpv4Addresses), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::HostName> const*>(&assignedClientIpv6Addresses), *reinterpret_cast<llm::OS::Networking::Vpn::VpnInterfaceId const*>(&vpninterfaceId), *reinterpret_cast<llm::OS::Networking::Vpn::VpnRouteAssignment const*>(&assignedRoutes), *reinterpret_cast<llm::OS::Networking::Vpn::VpnDomainNameAssignment const*>(&assignedNamespace), mtuSize, maxFrameSize, reserved, *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Foundation::IInspectable> const*>(&transports), *reinterpret_cast<llm::OS::Networking::Vpn::VpnTrafficFilterAssignment const*>(&assignedTrafficFilters));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ReplaceAndAssociateTransport(void* transport, void* context) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ReplaceAndAssociateTransport(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&transport), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&context));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall StartReconnectingTransport(void* transport, void* context) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().StartReconnectingTransport(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&transport), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&context));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetSlotTypeForTransportContext(void* context, int32_t* slotType) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *slotType = detach_from<llm::OS::Networking::Sockets::ControlChannelTriggerStatus>(this->shim().GetSlotTypeForTransportContext(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&context)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CurrentRequestTransportContext(void** context) noexcept final try
        {
            clear_abi(context);
            typename D::abi_guard guard(this->shim());
            *context = detach_from<llm::OS::Foundation::IInspectable>(this->shim().CurrentRequestTransportContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannel5> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannel5>
    {
        int32_t __stdcall AppendVpnReceivePacketBuffer(void* decapsulatedPacketBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendVpnReceivePacketBuffer(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&decapsulatedPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AppendVpnSendPacketBuffer(void* encapsulatedPacketBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppendVpnSendPacketBuffer(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&encapsulatedPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FlushVpnReceivePacketBuffers() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlushVpnReceivePacketBuffers();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FlushVpnSendPacketBuffers() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().FlushVpnSendPacketBuffers();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannel6> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannel6>
    {
        int32_t __stdcall ActivateForeground(void* packageRelativeAppId, void* sharedContext, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().ActivateForeground(*reinterpret_cast<hstring const*>(&packageRelativeAppId), *reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&sharedContext)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannelActivityEventArgs> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannelActivityEventArgs>
    {
        int32_t __stdcall get_Type(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnChannelActivityEventType>(this->shim().Type());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannelActivityStateChangedArgs> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannelActivityStateChangedArgs>
    {
        int32_t __stdcall get_ActivityState(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnChannelActivityEventType>(this->shim().ActivityState());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannelConfiguration> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannelConfiguration>
    {
        int32_t __stdcall get_ServerServiceName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ServerServiceName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServerHostNameList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::HostName>>(this->shim().ServerHostNameList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomField(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CustomField());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannelConfiguration2> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannelConfiguration2>
    {
        int32_t __stdcall get_ServerUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Foundation::Uri>>(this->shim().ServerUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnChannelStatics> : produce_base<D, llm::OS::Networking::Vpn::IVpnChannelStatics>
    {
        int32_t __stdcall ProcessEventAsync(void* thirdPartyPlugIn, void* event) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProcessEventAsync(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&thirdPartyPlugIn), *reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&event));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCredential> : produce_base<D, llm::OS::Networking::Vpn::IVpnCredential>
    {
        int32_t __stdcall get_PasskeyCredential(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().PasskeyCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CertificateCredential(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Cryptography::Certificates::Certificate>(this->shim().CertificateCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdditionalPin(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AdditionalPin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldPasswordCredential(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().OldPasswordCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomCheckBox> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomCheckBox>
    {
        int32_t __stdcall put_InitialCheckState(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialCheckState(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialCheckState(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().InitialCheckState());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Checked(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Checked());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomComboBox> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomComboBox>
    {
        int32_t __stdcall put_OptionsText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().OptionsText(*reinterpret_cast<llm::OS::Foundation::Collections::IVectorView<hstring> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OptionsText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<hstring>>(this->shim().OptionsText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Selected(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Selected());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomEditBox> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomEditBox>
    {
        int32_t __stdcall put_DefaultText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DefaultText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DefaultText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DefaultText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NoEcho(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NoEcho(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NoEcho(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().NoEcho());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomErrorBox> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomErrorBox>
    {
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomPrompt> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomPrompt>
    {
        int32_t __stdcall put_Label(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Label(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Label(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Label());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Compulsory(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Compulsory(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Compulsory(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Compulsory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Bordered(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Bordered(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Bordered(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Bordered());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomPromptBooleanInput> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomPromptBooleanInput>
    {
        int32_t __stdcall put_InitialValue(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().InitialValue(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_InitialValue(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().InitialValue());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Value(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Value());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomPromptElement> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomPromptElement>
    {
        int32_t __stdcall put_DisplayName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayName(*reinterpret_cast<hstring const*>(&value));
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
        int32_t __stdcall put_Compulsory(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Compulsory(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Compulsory(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Compulsory());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Emphasized(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Emphasized(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Emphasized(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().Emphasized());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomPromptOptionSelector> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomPromptOptionSelector>
    {
        int32_t __stdcall get_Options(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Options());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SelectedIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().SelectedIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomPromptText> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomPromptText>
    {
        int32_t __stdcall put_Text(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Text(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomPromptTextInput> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomPromptTextInput>
    {
        int32_t __stdcall put_PlaceholderText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PlaceholderText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PlaceholderText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().PlaceholderText());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsTextHidden(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsTextHidden(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsTextHidden(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsTextHidden());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Text(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Text());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnCustomTextBox> : produce_base<D, llm::OS::Networking::Vpn::IVpnCustomTextBox>
    {
        int32_t __stdcall put_DisplayText(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DisplayText(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DisplayText(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DisplayText());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnDomainNameAssignment> : produce_base<D, llm::OS::Networking::Vpn::IVpnDomainNameAssignment>
    {
        int32_t __stdcall get_DomainNameList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnDomainNameInfo>>(this->shim().DomainNameList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProxyAutoConfigurationUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyAutoConfigurationUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProxyAutoConfigurationUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ProxyAutoConfigurationUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnDomainNameInfo> : produce_base<D, llm::OS::Networking::Vpn::IVpnDomainNameInfo>
    {
        int32_t __stdcall put_DomainName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DomainName(*reinterpret_cast<llm::OS::Networking::HostName const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DomainName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().DomainName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DomainNameType(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DomainNameType(*reinterpret_cast<llm::OS::Networking::Vpn::VpnDomainNameType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DomainNameType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnDomainNameType>(this->shim().DomainNameType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DnsServers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>>(this->shim().DnsServers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WebProxyServers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>>(this->shim().WebProxyServers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnDomainNameInfo2> : produce_base<D, llm::OS::Networking::Vpn::IVpnDomainNameInfo2>
    {
        int32_t __stdcall get_WebProxyUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>>(this->shim().WebProxyUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnDomainNameInfoFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnDomainNameInfoFactory>
    {
        int32_t __stdcall CreateVpnDomainNameInfo(void* name, int32_t nameType, void* dnsServerList, void* proxyServerList, void** domainNameInfo) noexcept final try
        {
            clear_abi(domainNameInfo);
            typename D::abi_guard guard(this->shim());
            *domainNameInfo = detach_from<llm::OS::Networking::Vpn::VpnDomainNameInfo>(this->shim().CreateVpnDomainNameInfo(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::Networking::Vpn::VpnDomainNameType const*>(&nameType), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::HostName> const*>(&dnsServerList), *reinterpret_cast<llm::OS::Foundation::Collections::IIterable<llm::OS::Networking::HostName> const*>(&proxyServerList)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnForegroundActivatedEventArgs> : produce_base<D, llm::OS::Networking::Vpn::IVpnForegroundActivatedEventArgs>
    {
        int32_t __stdcall get_ProfileName(void** name) noexcept final try
        {
            clear_abi(name);
            typename D::abi_guard guard(this->shim());
            *name = detach_from<hstring>(this->shim().ProfileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SharedContext(void** sharedContext) noexcept final try
        {
            clear_abi(sharedContext);
            typename D::abi_guard guard(this->shim());
            *sharedContext = detach_from<llm::OS::Foundation::Collections::ValueSet>(this->shim().SharedContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ActivationOperation(void** activationOperation) noexcept final try
        {
            clear_abi(activationOperation);
            typename D::abi_guard guard(this->shim());
            *activationOperation = detach_from<llm::OS::Networking::Vpn::VpnForegroundActivationOperation>(this->shim().ActivationOperation());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnForegroundActivationOperation> : produce_base<D, llm::OS::Networking::Vpn::IVpnForegroundActivationOperation>
    {
        int32_t __stdcall Complete(void* result) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Complete(*reinterpret_cast<llm::OS::Foundation::Collections::ValueSet const*>(&result));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnInterfaceId> : produce_base<D, llm::OS::Networking::Vpn::IVpnInterfaceId>
    {
        int32_t __stdcall GetAddressInfo(uint32_t* __idSize, uint8_t** id) noexcept final try
        {
            clear_abi(id);
            typename D::abi_guard guard(this->shim());
            this->shim().GetAddressInfo(detach_abi<uint8_t>(__idSize, id));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnInterfaceIdFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnInterfaceIdFactory>
    {
        int32_t __stdcall CreateVpnInterfaceId(uint32_t __addressSize, uint8_t* address, void** vpnInterfaceId) noexcept final try
        {
            clear_abi(vpnInterfaceId);
            typename D::abi_guard guard(this->shim());
            *vpnInterfaceId = detach_from<llm::OS::Networking::Vpn::VpnInterfaceId>(this->shim().CreateVpnInterfaceId(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(address), reinterpret_cast<uint8_t const *>(address) + __addressSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnManagementAgent> : produce_base<D, llm::OS::Networking::Vpn::IVpnManagementAgent>
    {
        int32_t __stdcall AddProfileFromXmlAsync(void* xml, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().AddProfileFromXmlAsync(*reinterpret_cast<hstring const*>(&xml)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddProfileFromObjectAsync(void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().AddProfileFromObjectAsync(*reinterpret_cast<llm::OS::Networking::Vpn::IVpnProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateProfileFromXmlAsync(void* xml, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().UpdateProfileFromXmlAsync(*reinterpret_cast<hstring const*>(&xml)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall UpdateProfileFromObjectAsync(void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().UpdateProfileFromObjectAsync(*reinterpret_cast<llm::OS::Networking::Vpn::IVpnProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetProfilesAsync(void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Foundation::Collections::IVectorView<llm::OS::Networking::Vpn::IVpnProfile>>>(this->shim().GetProfilesAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteProfileAsync(void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().DeleteProfileAsync(*reinterpret_cast<llm::OS::Networking::Vpn::IVpnProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectProfileAsync(void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().ConnectProfileAsync(*reinterpret_cast<llm::OS::Networking::Vpn::IVpnProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ConnectProfileWithPasswordCredentialAsync(void* profile, void* passwordCredential, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().ConnectProfileWithPasswordCredentialAsync(*reinterpret_cast<llm::OS::Networking::Vpn::IVpnProfile const*>(&profile), *reinterpret_cast<llm::OS::Security::Credentials::PasswordCredential const*>(&passwordCredential)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DisconnectProfileAsync(void* profile, void** operation) noexcept final try
        {
            clear_abi(operation);
            typename D::abi_guard guard(this->shim());
            *operation = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Networking::Vpn::VpnManagementErrorStatus>>(this->shim().DisconnectProfileAsync(*reinterpret_cast<llm::OS::Networking::Vpn::IVpnProfile const*>(&profile)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnNamespaceAssignment> : produce_base<D, llm::OS::Networking::Vpn::IVpnNamespaceAssignment>
    {
        int32_t __stdcall put_NamespaceList(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NamespaceList(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnNamespaceInfo> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NamespaceList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnNamespaceInfo>>(this->shim().NamespaceList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProxyAutoConfigUri(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProxyAutoConfigUri(*reinterpret_cast<llm::OS::Foundation::Uri const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProxyAutoConfigUri(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Uri>(this->shim().ProxyAutoConfigUri());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnNamespaceInfo> : produce_base<D, llm::OS::Networking::Vpn::IVpnNamespaceInfo>
    {
        int32_t __stdcall put_Namespace(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Namespace(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Namespace(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Namespace());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_DnsServers(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DnsServers(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DnsServers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>>(this->shim().DnsServers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_WebProxyServers(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().WebProxyServers(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WebProxyServers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName>>(this->shim().WebProxyServers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnNamespaceInfoFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnNamespaceInfoFactory>
    {
        int32_t __stdcall CreateVpnNamespaceInfo(void* name, void* dnsServerList, void* proxyServerList, void** namespaceInfo) noexcept final try
        {
            clear_abi(namespaceInfo);
            typename D::abi_guard guard(this->shim());
            *namespaceInfo = detach_from<llm::OS::Networking::Vpn::VpnNamespaceInfo>(this->shim().CreateVpnNamespaceInfo(*reinterpret_cast<hstring const*>(&name), *reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName> const*>(&dnsServerList), *reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::HostName> const*>(&proxyServerList)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnNativeProfile> : produce_base<D, llm::OS::Networking::Vpn::IVpnNativeProfile>
    {
        int32_t __stdcall get_Servers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().Servers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RoutingPolicyType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnRoutingPolicyType>(this->shim().RoutingPolicyType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RoutingPolicyType(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoutingPolicyType(*reinterpret_cast<llm::OS::Networking::Vpn::VpnRoutingPolicyType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NativeProtocolType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnNativeProtocolType>(this->shim().NativeProtocolType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_NativeProtocolType(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().NativeProtocolType(*reinterpret_cast<llm::OS::Networking::Vpn::VpnNativeProtocolType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UserAuthenticationMethod(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnAuthenticationMethod>(this->shim().UserAuthenticationMethod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_UserAuthenticationMethod(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().UserAuthenticationMethod(*reinterpret_cast<llm::OS::Networking::Vpn::VpnAuthenticationMethod const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TunnelAuthenticationMethod(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnAuthenticationMethod>(this->shim().TunnelAuthenticationMethod());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TunnelAuthenticationMethod(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TunnelAuthenticationMethod(*reinterpret_cast<llm::OS::Networking::Vpn::VpnAuthenticationMethod const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_EapConfiguration(void** Value) noexcept final try
        {
            clear_abi(Value);
            typename D::abi_guard guard(this->shim());
            *Value = detach_from<hstring>(this->shim().EapConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_EapConfiguration(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().EapConfiguration(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnNativeProfile2> : produce_base<D, llm::OS::Networking::Vpn::IVpnNativeProfile2>
    {
        int32_t __stdcall get_RequireVpnClientAppUI(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RequireVpnClientAppUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RequireVpnClientAppUI(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequireVpnClientAppUI(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnManagementConnectionStatus>(this->shim().ConnectionStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPacketBuffer> : produce_base<D, llm::OS::Networking::Vpn::IVpnPacketBuffer>
    {
        int32_t __stdcall get_Buffer(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::Buffer>(this->shim().Buffer());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Status(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBufferStatus const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnPacketBufferStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TransportAffinity(uint32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransportAffinity(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransportAffinity(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().TransportAffinity());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPacketBuffer2> : produce_base<D, llm::OS::Networking::Vpn::IVpnPacketBuffer2>
    {
        int32_t __stdcall get_AppId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnAppId>(this->shim().AppId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPacketBuffer3> : produce_base<D, llm::OS::Networking::Vpn::IVpnPacketBuffer3>
    {
        int32_t __stdcall put_TransportContext(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TransportContext(*reinterpret_cast<llm::OS::Foundation::IInspectable const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransportContext(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IInspectable>(this->shim().TransportContext());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPacketBufferFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnPacketBufferFactory>
    {
        int32_t __stdcall CreateVpnPacketBuffer(void* parentBuffer, uint32_t offset, uint32_t length, void** vpnPacketBuffer) noexcept final try
        {
            clear_abi(vpnPacketBuffer);
            typename D::abi_guard guard(this->shim());
            *vpnPacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().CreateVpnPacketBuffer(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&parentBuffer), offset, length));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPacketBufferList> : produce_base<D, llm::OS::Networking::Vpn::IVpnPacketBufferList>
    {
        int32_t __stdcall Append(void* nextVpnPacketBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Append(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&nextVpnPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddAtBegin(void* nextVpnPacketBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddAtBegin(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&nextVpnPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAtEnd(void** nextVpnPacketBuffer) noexcept final try
        {
            clear_abi(nextVpnPacketBuffer);
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().RemoveAtEnd());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveAtBegin(void** nextVpnPacketBuffer) noexcept final try
        {
            clear_abi(nextVpnPacketBuffer);
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().RemoveAtBegin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Clear() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Clear();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Status(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Status(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBufferStatus const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnPacketBufferStatus>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Size(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Size());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPacketBufferList2> : produce_base<D, llm::OS::Networking::Vpn::IVpnPacketBufferList2>
    {
        int32_t __stdcall AddLeadingPacket(void* nextVpnPacketBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddLeadingPacket(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&nextVpnPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveLeadingPacket(void** nextVpnPacketBuffer) noexcept final try
        {
            clear_abi(nextVpnPacketBuffer);
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().RemoveLeadingPacket());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall AddTrailingPacket(void* nextVpnPacketBuffer) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AddTrailingPacket(*reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&nextVpnPacketBuffer));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall RemoveTrailingPacket(void** nextVpnPacketBuffer) noexcept final try
        {
            clear_abi(nextVpnPacketBuffer);
            typename D::abi_guard guard(this->shim());
            *nextVpnPacketBuffer = detach_from<llm::OS::Networking::Vpn::VpnPacketBuffer>(this->shim().RemoveTrailingPacket());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPickedCredential> : produce_base<D, llm::OS::Networking::Vpn::IVpnPickedCredential>
    {
        int32_t __stdcall get_PasskeyCredential(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().PasskeyCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AdditionalPin(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AdditionalPin());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_OldPasswordCredential(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Security::Credentials::PasswordCredential>(this->shim().OldPasswordCredential());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPlugIn> : produce_base<D, llm::OS::Networking::Vpn::IVpnPlugIn>
    {
        int32_t __stdcall Connect(void* channel) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Connect(*reinterpret_cast<llm::OS::Networking::Vpn::VpnChannel const*>(&channel));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Disconnect(void* channel) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Disconnect(*reinterpret_cast<llm::OS::Networking::Vpn::VpnChannel const*>(&channel));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetKeepAlivePayload(void* channel, void** keepAlivePacket) noexcept final try
        {
            clear_abi(keepAlivePacket);
            typename D::abi_guard guard(this->shim());
            this->shim().GetKeepAlivePayload(*reinterpret_cast<llm::OS::Networking::Vpn::VpnChannel const*>(&channel), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer*>(keepAlivePacket));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Encapsulate(void* channel, void* packets, void* encapulatedPackets) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encapsulate(*reinterpret_cast<llm::OS::Networking::Vpn::VpnChannel const*>(&channel), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBufferList const*>(&packets), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBufferList const*>(&encapulatedPackets));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Decapsulate(void* channel, void* encapBuffer, void* decapsulatedPackets, void* controlPacketsToSend) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Decapsulate(*reinterpret_cast<llm::OS::Networking::Vpn::VpnChannel const*>(&channel), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBuffer const*>(&encapBuffer), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBufferList const*>(&decapsulatedPackets), *reinterpret_cast<llm::OS::Networking::Vpn::VpnPacketBufferList const*>(&controlPacketsToSend));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPlugInProfile> : produce_base<D, llm::OS::Networking::Vpn::IVpnPlugInProfile>
    {
        int32_t __stdcall get_ServerUris(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Foundation::Uri>>(this->shim().ServerUris());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CustomConfiguration(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CustomConfiguration());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CustomConfiguration(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CustomConfiguration(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VpnPluginPackageFamilyName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().VpnPluginPackageFamilyName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_VpnPluginPackageFamilyName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().VpnPluginPackageFamilyName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnPlugInProfile2> : produce_base<D, llm::OS::Networking::Vpn::IVpnPlugInProfile2>
    {
        int32_t __stdcall get_RequireVpnClientAppUI(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RequireVpnClientAppUI());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RequireVpnClientAppUI(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RequireVpnClientAppUI(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ConnectionStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnManagementConnectionStatus>(this->shim().ConnectionStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnProfile> : produce_base<D, llm::OS::Networking::Vpn::IVpnProfile>
    {
        int32_t __stdcall get_ProfileName(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ProfileName());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProfileName(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProfileName(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppTriggers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnAppId>>(this->shim().AppTriggers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Routes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>>(this->shim().Routes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DomainNameInfoList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnDomainNameInfo>>(this->shim().DomainNameInfoList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TrafficFilters(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnTrafficFilter>>(this->shim().TrafficFilters());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RememberCredentials(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().RememberCredentials());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RememberCredentials(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RememberCredentials(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AlwaysOn(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AlwaysOn());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AlwaysOn(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AlwaysOn(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnRoute> : produce_base<D, llm::OS::Networking::Vpn::IVpnRoute>
    {
        int32_t __stdcall put_Address(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Address(*reinterpret_cast<llm::OS::Networking::HostName const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Address(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::HostName>(this->shim().Address());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PrefixSize(uint8_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PrefixSize(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PrefixSize(uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint8_t>(this->shim().PrefixSize());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnRouteAssignment> : produce_base<D, llm::OS::Networking::Vpn::IVpnRouteAssignment>
    {
        int32_t __stdcall put_Ipv4InclusionRoutes(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv4InclusionRoutes(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Ipv6InclusionRoutes(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv6InclusionRoutes(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Ipv4InclusionRoutes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>>(this->shim().Ipv4InclusionRoutes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Ipv6InclusionRoutes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>>(this->shim().Ipv6InclusionRoutes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Ipv4ExclusionRoutes(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv4ExclusionRoutes(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Ipv6ExclusionRoutes(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Ipv6ExclusionRoutes(*reinterpret_cast<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute> const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Ipv4ExclusionRoutes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>>(this->shim().Ipv4ExclusionRoutes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Ipv6ExclusionRoutes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnRoute>>(this->shim().Ipv6ExclusionRoutes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ExcludeLocalSubnets(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ExcludeLocalSubnets(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ExcludeLocalSubnets(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().ExcludeLocalSubnets());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnRouteFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnRouteFactory>
    {
        int32_t __stdcall CreateVpnRoute(void* address, uint8_t prefixSize, void** route) noexcept final try
        {
            clear_abi(route);
            typename D::abi_guard guard(this->shim());
            *route = detach_from<llm::OS::Networking::Vpn::VpnRoute>(this->shim().CreateVpnRoute(*reinterpret_cast<llm::OS::Networking::HostName const*>(&address), prefixSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnSystemHealth> : produce_base<D, llm::OS::Networking::Vpn::IVpnSystemHealth>
    {
        int32_t __stdcall get_StatementOfHealth(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::Buffer>(this->shim().StatementOfHealth());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnTrafficFilter> : produce_base<D, llm::OS::Networking::Vpn::IVpnTrafficFilter>
    {
        int32_t __stdcall get_AppId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnAppId>(this->shim().AppId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AppId(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AppId(*reinterpret_cast<llm::OS::Networking::Vpn::VpnAppId const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppClaims(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().AppClaims());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Protocol(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnIPProtocol>(this->shim().Protocol());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Protocol(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Protocol(*reinterpret_cast<llm::OS::Networking::Vpn::VpnIPProtocol const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalPortRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().LocalPortRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemotePortRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().RemotePortRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_LocalAddressRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().LocalAddressRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RemoteAddressRanges(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().RemoteAddressRanges());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RoutingPolicyType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Networking::Vpn::VpnRoutingPolicyType>(this->shim().RoutingPolicyType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RoutingPolicyType(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RoutingPolicyType(*reinterpret_cast<llm::OS::Networking::Vpn::VpnRoutingPolicyType const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment> : produce_base<D, llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment>
    {
        int32_t __stdcall get_TrafficFilterList(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Networking::Vpn::VpnTrafficFilter>>(this->shim().TrafficFilterList());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowOutbound(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowOutbound());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowOutbound(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowOutbound(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AllowInbound(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().AllowInbound());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_AllowInbound(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().AllowInbound(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Networking::Vpn::IVpnTrafficFilterFactory> : produce_base<D, llm::OS::Networking::Vpn::IVpnTrafficFilterFactory>
    {
        int32_t __stdcall Create(void* appId, void** result) noexcept final try
        {
            clear_abi(result);
            typename D::abi_guard guard(this->shim());
            *result = detach_from<llm::OS::Networking::Vpn::VpnTrafficFilter>(this->shim().Create(*reinterpret_cast<llm::OS::Networking::Vpn::VpnAppId const*>(&appId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Networking::Vpn
{
    constexpr auto operator|(VpnChannelRequestCredentialsOptions const left, VpnChannelRequestCredentialsOptions const right) noexcept
    {
        return static_cast<VpnChannelRequestCredentialsOptions>(impl::to_underlying_type(left) | impl::to_underlying_type(right));
    }
    constexpr auto operator|=(VpnChannelRequestCredentialsOptions& left, VpnChannelRequestCredentialsOptions const right) noexcept
    {
        left = left | right;
        return left;
    }
    constexpr auto operator&(VpnChannelRequestCredentialsOptions const left, VpnChannelRequestCredentialsOptions const right) noexcept
    {
        return static_cast<VpnChannelRequestCredentialsOptions>(impl::to_underlying_type(left) & impl::to_underlying_type(right));
    }
    constexpr auto operator&=(VpnChannelRequestCredentialsOptions& left, VpnChannelRequestCredentialsOptions const right) noexcept
    {
        left = left & right;
        return left;
    }
    constexpr auto operator~(VpnChannelRequestCredentialsOptions const value) noexcept
    {
        return static_cast<VpnChannelRequestCredentialsOptions>(~impl::to_underlying_type(value));
    }
    constexpr auto operator^(VpnChannelRequestCredentialsOptions const left, VpnChannelRequestCredentialsOptions const right) noexcept
    {
        return static_cast<VpnChannelRequestCredentialsOptions>(impl::to_underlying_type(left) ^ impl::to_underlying_type(right));
    }
    constexpr auto operator^=(VpnChannelRequestCredentialsOptions& left, VpnChannelRequestCredentialsOptions const right) noexcept
    {
        left = left ^ right;
        return left;
    }
    inline VpnAppId::VpnAppId(llm::OS::Networking::Vpn::VpnAppIdType const& type, param::hstring const& value) :
        VpnAppId(impl::call_factory<VpnAppId, IVpnAppIdFactory>([&](IVpnAppIdFactory const& f) { return f.Create(type, value); }))
    {
    }
    inline auto VpnChannel::ProcessEventAsync(llm::OS::Foundation::IInspectable const& thirdPartyPlugIn, llm::OS::Foundation::IInspectable const& event)
    {
        impl::call_factory<VpnChannel, IVpnChannelStatics>([&](IVpnChannelStatics const& f) { return f.ProcessEventAsync(thirdPartyPlugIn, event); });
    }
    inline VpnCustomCheckBox::VpnCustomCheckBox() :
        VpnCustomCheckBox(impl::call_factory_cast<VpnCustomCheckBox(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomCheckBox>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomCheckBox>(); }))
    {
    }
    inline VpnCustomComboBox::VpnCustomComboBox() :
        VpnCustomComboBox(impl::call_factory_cast<VpnCustomComboBox(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomComboBox>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomComboBox>(); }))
    {
    }
    inline VpnCustomEditBox::VpnCustomEditBox() :
        VpnCustomEditBox(impl::call_factory_cast<VpnCustomEditBox(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomEditBox>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomEditBox>(); }))
    {
    }
    inline VpnCustomErrorBox::VpnCustomErrorBox() :
        VpnCustomErrorBox(impl::call_factory_cast<VpnCustomErrorBox(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomErrorBox>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomErrorBox>(); }))
    {
    }
    inline VpnCustomPromptBooleanInput::VpnCustomPromptBooleanInput() :
        VpnCustomPromptBooleanInput(impl::call_factory_cast<VpnCustomPromptBooleanInput(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomPromptBooleanInput>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomPromptBooleanInput>(); }))
    {
    }
    inline VpnCustomPromptOptionSelector::VpnCustomPromptOptionSelector() :
        VpnCustomPromptOptionSelector(impl::call_factory_cast<VpnCustomPromptOptionSelector(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomPromptOptionSelector>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomPromptOptionSelector>(); }))
    {
    }
    inline VpnCustomPromptText::VpnCustomPromptText() :
        VpnCustomPromptText(impl::call_factory_cast<VpnCustomPromptText(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomPromptText>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomPromptText>(); }))
    {
    }
    inline VpnCustomPromptTextInput::VpnCustomPromptTextInput() :
        VpnCustomPromptTextInput(impl::call_factory_cast<VpnCustomPromptTextInput(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomPromptTextInput>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomPromptTextInput>(); }))
    {
    }
    inline VpnCustomTextBox::VpnCustomTextBox() :
        VpnCustomTextBox(impl::call_factory_cast<VpnCustomTextBox(*)(llm::OS::Foundation::IActivationFactory const&), VpnCustomTextBox>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnCustomTextBox>(); }))
    {
    }
    inline VpnDomainNameAssignment::VpnDomainNameAssignment() :
        VpnDomainNameAssignment(impl::call_factory_cast<VpnDomainNameAssignment(*)(llm::OS::Foundation::IActivationFactory const&), VpnDomainNameAssignment>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnDomainNameAssignment>(); }))
    {
    }
    inline VpnDomainNameInfo::VpnDomainNameInfo(param::hstring const& name, llm::OS::Networking::Vpn::VpnDomainNameType const& nameType, param::iterable<llm::OS::Networking::HostName> const& dnsServerList, param::iterable<llm::OS::Networking::HostName> const& proxyServerList) :
        VpnDomainNameInfo(impl::call_factory<VpnDomainNameInfo, IVpnDomainNameInfoFactory>([&](IVpnDomainNameInfoFactory const& f) { return f.CreateVpnDomainNameInfo(name, nameType, dnsServerList, proxyServerList); }))
    {
    }
    inline VpnInterfaceId::VpnInterfaceId(array_view<uint8_t const> address) :
        VpnInterfaceId(impl::call_factory<VpnInterfaceId, IVpnInterfaceIdFactory>([&](IVpnInterfaceIdFactory const& f) { return f.CreateVpnInterfaceId(address); }))
    {
    }
    inline VpnManagementAgent::VpnManagementAgent() :
        VpnManagementAgent(impl::call_factory_cast<VpnManagementAgent(*)(llm::OS::Foundation::IActivationFactory const&), VpnManagementAgent>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnManagementAgent>(); }))
    {
    }
    inline VpnNamespaceAssignment::VpnNamespaceAssignment() :
        VpnNamespaceAssignment(impl::call_factory_cast<VpnNamespaceAssignment(*)(llm::OS::Foundation::IActivationFactory const&), VpnNamespaceAssignment>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnNamespaceAssignment>(); }))
    {
    }
    inline VpnNamespaceInfo::VpnNamespaceInfo(param::hstring const& name, param::vector<llm::OS::Networking::HostName> const& dnsServerList, param::vector<llm::OS::Networking::HostName> const& proxyServerList) :
        VpnNamespaceInfo(impl::call_factory<VpnNamespaceInfo, IVpnNamespaceInfoFactory>([&](IVpnNamespaceInfoFactory const& f) { return f.CreateVpnNamespaceInfo(name, dnsServerList, proxyServerList); }))
    {
    }
    inline VpnNativeProfile::VpnNativeProfile() :
        VpnNativeProfile(impl::call_factory_cast<VpnNativeProfile(*)(llm::OS::Foundation::IActivationFactory const&), VpnNativeProfile>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnNativeProfile>(); }))
    {
    }
    inline VpnPacketBuffer::VpnPacketBuffer(llm::OS::Networking::Vpn::VpnPacketBuffer const& parentBuffer, uint32_t offset, uint32_t length) :
        VpnPacketBuffer(impl::call_factory<VpnPacketBuffer, IVpnPacketBufferFactory>([&](IVpnPacketBufferFactory const& f) { return f.CreateVpnPacketBuffer(parentBuffer, offset, length); }))
    {
    }
    inline VpnPlugInProfile::VpnPlugInProfile() :
        VpnPlugInProfile(impl::call_factory_cast<VpnPlugInProfile(*)(llm::OS::Foundation::IActivationFactory const&), VpnPlugInProfile>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnPlugInProfile>(); }))
    {
    }
    inline VpnRoute::VpnRoute(llm::OS::Networking::HostName const& address, uint8_t prefixSize) :
        VpnRoute(impl::call_factory<VpnRoute, IVpnRouteFactory>([&](IVpnRouteFactory const& f) { return f.CreateVpnRoute(address, prefixSize); }))
    {
    }
    inline VpnRouteAssignment::VpnRouteAssignment() :
        VpnRouteAssignment(impl::call_factory_cast<VpnRouteAssignment(*)(llm::OS::Foundation::IActivationFactory const&), VpnRouteAssignment>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnRouteAssignment>(); }))
    {
    }
    inline VpnTrafficFilter::VpnTrafficFilter(llm::OS::Networking::Vpn::VpnAppId const& appId) :
        VpnTrafficFilter(impl::call_factory<VpnTrafficFilter, IVpnTrafficFilterFactory>([&](IVpnTrafficFilterFactory const& f) { return f.Create(appId); }))
    {
    }
    inline VpnTrafficFilterAssignment::VpnTrafficFilterAssignment() :
        VpnTrafficFilterAssignment(impl::call_factory_cast<VpnTrafficFilterAssignment(*)(llm::OS::Foundation::IActivationFactory const&), VpnTrafficFilterAssignment>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<VpnTrafficFilterAssignment>(); }))
    {
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Networking::Vpn::IVpnAppId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnAppIdFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannel2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannel4> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannel5> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannel6> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannelActivityEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannelActivityStateChangedArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannelConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannelConfiguration2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnChannelStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCredential> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomCheckBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomComboBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomEditBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomErrorBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomPrompt> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomPromptBooleanInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomPromptElement> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomPromptOptionSelector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomPromptText> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomPromptTextInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnCustomTextBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnDomainNameAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnDomainNameInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnDomainNameInfo2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnDomainNameInfoFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnForegroundActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnForegroundActivationOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnInterfaceId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnInterfaceIdFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnManagementAgent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnNamespaceAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnNamespaceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnNamespaceInfoFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnNativeProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnNativeProfile2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPacketBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPacketBuffer2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPacketBuffer3> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPacketBufferFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPacketBufferList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPacketBufferList2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPickedCredential> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPlugIn> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPlugInProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnPlugInProfile2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnRoute> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnRouteAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnRouteFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnSystemHealth> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnTrafficFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnTrafficFilterAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::IVpnTrafficFilterFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnAppId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnChannel> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnChannelActivityEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnChannelActivityStateChangedArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnChannelConfiguration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCredential> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomCheckBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomComboBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomEditBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomErrorBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomPromptBooleanInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomPromptOptionSelector> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomPromptText> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomPromptTextInput> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnCustomTextBox> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnDomainNameAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnDomainNameInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnForegroundActivatedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnForegroundActivationOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnInterfaceId> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnManagementAgent> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnNamespaceAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnNamespaceInfo> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnNativeProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnPacketBuffer> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnPacketBufferList> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnPickedCredential> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnPlugInProfile> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnRoute> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnRouteAssignment> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnSystemHealth> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnTrafficFilter> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Networking::Vpn::VpnTrafficFilterAssignment> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
