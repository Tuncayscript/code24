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
#ifndef LLM_OS_Networking_Vpn_2_H
#define LLM_OS_Networking_Vpn_2_H
#include "llm/impl/Windows.ApplicationModel.Activation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Networking.1.h"
#include "llm/impl/Windows.Networking.Vpn.1.h"
LLM_EXPORT namespace llm:OS::Networking::Vpn
{
    struct __declspec(empty_bases) VpnAppId : llm:OS::Networking::Vpn::IVpnAppId
    {
        VpnAppId(std::nullptr_t) noexcept {}
        VpnAppId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnAppId(ptr, take_ownership_from_abi) {}
        VpnAppId(llm:OS::Networking::Vpn::VpnAppIdType const& type, param::hstring const& value);
    };
    struct __declspec(empty_bases) VpnChannel : llm:OS::Networking::Vpn::IVpnChannel,
        impl::require<VpnChannel, llm:OS::Networking::Vpn::IVpnChannel2, llm:OS::Networking::Vpn::IVpnChannel4, llm:OS::Networking::Vpn::IVpnChannel5, llm:OS::Networking::Vpn::IVpnChannel6>
    {
        VpnChannel(std::nullptr_t) noexcept {}
        VpnChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnChannel(ptr, take_ownership_from_abi) {}
        using impl::consume_t<VpnChannel, llm:OS::Networking::Vpn::IVpnChannel2>::StartWithTrafficFilter;
        using impl::consume_t<VpnChannel, llm:OS::Networking::Vpn::IVpnChannel4>::StartWithTrafficFilter;
        static auto ProcessEventAsync(llm:OS::Foundation::IInspectable const& thirdPartyPlugIn, llm:OS::Foundation::IInspectable const& event);
    };
    struct __declspec(empty_bases) VpnChannelActivityEventArgs : llm:OS::Networking::Vpn::IVpnChannelActivityEventArgs
    {
        VpnChannelActivityEventArgs(std::nullptr_t) noexcept {}
        VpnChannelActivityEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnChannelActivityEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnChannelActivityStateChangedArgs : llm:OS::Networking::Vpn::IVpnChannelActivityStateChangedArgs
    {
        VpnChannelActivityStateChangedArgs(std::nullptr_t) noexcept {}
        VpnChannelActivityStateChangedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnChannelActivityStateChangedArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnChannelConfiguration : llm:OS::Networking::Vpn::IVpnChannelConfiguration,
        impl::require<VpnChannelConfiguration, llm:OS::Networking::Vpn::IVpnChannelConfiguration2>
    {
        VpnChannelConfiguration(std::nullptr_t) noexcept {}
        VpnChannelConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnChannelConfiguration(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnCredential : llm:OS::Networking::Vpn::IVpnCredential
    {
        VpnCredential(std::nullptr_t) noexcept {}
        VpnCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCredential(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnCustomCheckBox : llm:OS::Networking::Vpn::IVpnCustomCheckBox
    {
        VpnCustomCheckBox(std::nullptr_t) noexcept {}
        VpnCustomCheckBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomCheckBox(ptr, take_ownership_from_abi) {}
        VpnCustomCheckBox();
    };
    struct __declspec(empty_bases) VpnCustomComboBox : llm:OS::Networking::Vpn::IVpnCustomComboBox
    {
        VpnCustomComboBox(std::nullptr_t) noexcept {}
        VpnCustomComboBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomComboBox(ptr, take_ownership_from_abi) {}
        VpnCustomComboBox();
    };
    struct __declspec(empty_bases) VpnCustomEditBox : llm:OS::Networking::Vpn::IVpnCustomEditBox
    {
        VpnCustomEditBox(std::nullptr_t) noexcept {}
        VpnCustomEditBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomEditBox(ptr, take_ownership_from_abi) {}
        VpnCustomEditBox();
    };
    struct __declspec(empty_bases) VpnCustomErrorBox : llm:OS::Networking::Vpn::IVpnCustomErrorBox
    {
        VpnCustomErrorBox(std::nullptr_t) noexcept {}
        VpnCustomErrorBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomErrorBox(ptr, take_ownership_from_abi) {}
        VpnCustomErrorBox();
    };
    struct __declspec(empty_bases) VpnCustomPromptBooleanInput : llm:OS::Networking::Vpn::IVpnCustomPromptBooleanInput
    {
        VpnCustomPromptBooleanInput(std::nullptr_t) noexcept {}
        VpnCustomPromptBooleanInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomPromptBooleanInput(ptr, take_ownership_from_abi) {}
        VpnCustomPromptBooleanInput();
    };
    struct __declspec(empty_bases) VpnCustomPromptOptionSelector : llm:OS::Networking::Vpn::IVpnCustomPromptOptionSelector
    {
        VpnCustomPromptOptionSelector(std::nullptr_t) noexcept {}
        VpnCustomPromptOptionSelector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomPromptOptionSelector(ptr, take_ownership_from_abi) {}
        VpnCustomPromptOptionSelector();
    };
    struct __declspec(empty_bases) VpnCustomPromptText : llm:OS::Networking::Vpn::IVpnCustomPromptText
    {
        VpnCustomPromptText(std::nullptr_t) noexcept {}
        VpnCustomPromptText(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomPromptText(ptr, take_ownership_from_abi) {}
        VpnCustomPromptText();
    };
    struct __declspec(empty_bases) VpnCustomPromptTextInput : llm:OS::Networking::Vpn::IVpnCustomPromptTextInput
    {
        VpnCustomPromptTextInput(std::nullptr_t) noexcept {}
        VpnCustomPromptTextInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomPromptTextInput(ptr, take_ownership_from_abi) {}
        VpnCustomPromptTextInput();
    };
    struct __declspec(empty_bases) VpnCustomTextBox : llm:OS::Networking::Vpn::IVpnCustomTextBox
    {
        VpnCustomTextBox(std::nullptr_t) noexcept {}
        VpnCustomTextBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnCustomTextBox(ptr, take_ownership_from_abi) {}
        VpnCustomTextBox();
    };
    struct __declspec(empty_bases) VpnDomainNameAssignment : llm:OS::Networking::Vpn::IVpnDomainNameAssignment
    {
        VpnDomainNameAssignment(std::nullptr_t) noexcept {}
        VpnDomainNameAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnDomainNameAssignment(ptr, take_ownership_from_abi) {}
        VpnDomainNameAssignment();
    };
    struct __declspec(empty_bases) VpnDomainNameInfo : llm:OS::Networking::Vpn::IVpnDomainNameInfo,
        impl::require<VpnDomainNameInfo, llm:OS::Networking::Vpn::IVpnDomainNameInfo2>
    {
        VpnDomainNameInfo(std::nullptr_t) noexcept {}
        VpnDomainNameInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnDomainNameInfo(ptr, take_ownership_from_abi) {}
        VpnDomainNameInfo(param::hstring const& name, llm:OS::Networking::Vpn::VpnDomainNameType const& nameType, param::iterable<llm:OS::Networking::HostName> const& dnsServerList, param::iterable<llm:OS::Networking::HostName> const& proxyServerList);
    };
    struct __declspec(empty_bases) VpnForegroundActivatedEventArgs : llm:OS::Networking::Vpn::IVpnForegroundActivatedEventArgs,
        impl::require<VpnForegroundActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgs, llm:OS::ApplicationModel::Activation::IActivatedEventArgsWithUser>
    {
        VpnForegroundActivatedEventArgs(std::nullptr_t) noexcept {}
        VpnForegroundActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnForegroundActivatedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnForegroundActivationOperation : llm:OS::Networking::Vpn::IVpnForegroundActivationOperation
    {
        VpnForegroundActivationOperation(std::nullptr_t) noexcept {}
        VpnForegroundActivationOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnForegroundActivationOperation(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnInterfaceId : llm:OS::Networking::Vpn::IVpnInterfaceId
    {
        VpnInterfaceId(std::nullptr_t) noexcept {}
        VpnInterfaceId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnInterfaceId(ptr, take_ownership_from_abi) {}
        explicit VpnInterfaceId(array_view<uint8_t const> address);
    };
    struct __declspec(empty_bases) VpnManagementAgent : llm:OS::Networking::Vpn::IVpnManagementAgent
    {
        VpnManagementAgent(std::nullptr_t) noexcept {}
        VpnManagementAgent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnManagementAgent(ptr, take_ownership_from_abi) {}
        VpnManagementAgent();
    };
    struct __declspec(empty_bases) VpnNamespaceAssignment : llm:OS::Networking::Vpn::IVpnNamespaceAssignment
    {
        VpnNamespaceAssignment(std::nullptr_t) noexcept {}
        VpnNamespaceAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnNamespaceAssignment(ptr, take_ownership_from_abi) {}
        VpnNamespaceAssignment();
    };
    struct __declspec(empty_bases) VpnNamespaceInfo : llm:OS::Networking::Vpn::IVpnNamespaceInfo
    {
        VpnNamespaceInfo(std::nullptr_t) noexcept {}
        VpnNamespaceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnNamespaceInfo(ptr, take_ownership_from_abi) {}
        VpnNamespaceInfo(param::hstring const& name, param::vector<llm:OS::Networking::HostName> const& dnsServerList, param::vector<llm:OS::Networking::HostName> const& proxyServerList);
    };
    struct __declspec(empty_bases) VpnNativeProfile : llm:OS::Networking::Vpn::IVpnNativeProfile,
        impl::require<VpnNativeProfile, llm:OS::Networking::Vpn::IVpnNativeProfile2>
    {
        VpnNativeProfile(std::nullptr_t) noexcept {}
        VpnNativeProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnNativeProfile(ptr, take_ownership_from_abi) {}
        VpnNativeProfile();
    };
    struct __declspec(empty_bases) VpnPacketBuffer : llm:OS::Networking::Vpn::IVpnPacketBuffer,
        impl::require<VpnPacketBuffer, llm:OS::Networking::Vpn::IVpnPacketBuffer2, llm:OS::Networking::Vpn::IVpnPacketBuffer3>
    {
        VpnPacketBuffer(std::nullptr_t) noexcept {}
        VpnPacketBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnPacketBuffer(ptr, take_ownership_from_abi) {}
        VpnPacketBuffer(llm:OS::Networking::Vpn::VpnPacketBuffer const& parentBuffer, uint32_t offset, uint32_t length);
    };
    struct __declspec(empty_bases) VpnPacketBufferList : llm:OS::Networking::Vpn::IVpnPacketBufferList
    {
        VpnPacketBufferList(std::nullptr_t) noexcept {}
        VpnPacketBufferList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnPacketBufferList(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnPickedCredential : llm:OS::Networking::Vpn::IVpnPickedCredential
    {
        VpnPickedCredential(std::nullptr_t) noexcept {}
        VpnPickedCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnPickedCredential(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnPlugInProfile : llm:OS::Networking::Vpn::IVpnPlugInProfile,
        impl::require<VpnPlugInProfile, llm:OS::Networking::Vpn::IVpnPlugInProfile2>
    {
        VpnPlugInProfile(std::nullptr_t) noexcept {}
        VpnPlugInProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnPlugInProfile(ptr, take_ownership_from_abi) {}
        VpnPlugInProfile();
    };
    struct __declspec(empty_bases) VpnRoute : llm:OS::Networking::Vpn::IVpnRoute
    {
        VpnRoute(std::nullptr_t) noexcept {}
        VpnRoute(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnRoute(ptr, take_ownership_from_abi) {}
        VpnRoute(llm:OS::Networking::HostName const& address, uint8_t prefixSize);
    };
    struct __declspec(empty_bases) VpnRouteAssignment : llm:OS::Networking::Vpn::IVpnRouteAssignment
    {
        VpnRouteAssignment(std::nullptr_t) noexcept {}
        VpnRouteAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnRouteAssignment(ptr, take_ownership_from_abi) {}
        VpnRouteAssignment();
    };
    struct __declspec(empty_bases) VpnSystemHealth : llm:OS::Networking::Vpn::IVpnSystemHealth
    {
        VpnSystemHealth(std::nullptr_t) noexcept {}
        VpnSystemHealth(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnSystemHealth(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) VpnTrafficFilter : llm:OS::Networking::Vpn::IVpnTrafficFilter
    {
        VpnTrafficFilter(std::nullptr_t) noexcept {}
        VpnTrafficFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnTrafficFilter(ptr, take_ownership_from_abi) {}
        explicit VpnTrafficFilter(llm:OS::Networking::Vpn::VpnAppId const& appId);
    };
    struct __declspec(empty_bases) VpnTrafficFilterAssignment : llm:OS::Networking::Vpn::IVpnTrafficFilterAssignment
    {
        VpnTrafficFilterAssignment(std::nullptr_t) noexcept {}
        VpnTrafficFilterAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Networking::Vpn::IVpnTrafficFilterAssignment(ptr, take_ownership_from_abi) {}
        VpnTrafficFilterAssignment();
    };
}
#endif
