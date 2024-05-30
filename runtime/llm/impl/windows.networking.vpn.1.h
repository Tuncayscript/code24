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
#ifndef LLM_OS_Networking_Vpn_1_H
#define LLM_OS_Networking_Vpn_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.Networking.Vpn.0.h"
LLM_EXPORT namespace llm:OS::Networking::Vpn
{
    struct __declspec(empty_bases) IVpnAppId :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnAppId>
    {
        IVpnAppId(std::nullptr_t = nullptr) noexcept {}
        IVpnAppId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnAppIdFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnAppIdFactory>
    {
        IVpnAppIdFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnAppIdFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannel :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannel>
    {
        IVpnChannel(std::nullptr_t = nullptr) noexcept {}
        IVpnChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannel2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannel2>
    {
        IVpnChannel2(std::nullptr_t = nullptr) noexcept {}
        IVpnChannel2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannel4 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannel4>
    {
        IVpnChannel4(std::nullptr_t = nullptr) noexcept {}
        IVpnChannel4(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannel5 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannel5>
    {
        IVpnChannel5(std::nullptr_t = nullptr) noexcept {}
        IVpnChannel5(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannel6 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannel6>
    {
        IVpnChannel6(std::nullptr_t = nullptr) noexcept {}
        IVpnChannel6(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannelActivityEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannelActivityEventArgs>
    {
        IVpnChannelActivityEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVpnChannelActivityEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannelActivityStateChangedArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannelActivityStateChangedArgs>
    {
        IVpnChannelActivityStateChangedArgs(std::nullptr_t = nullptr) noexcept {}
        IVpnChannelActivityStateChangedArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannelConfiguration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannelConfiguration>
    {
        IVpnChannelConfiguration(std::nullptr_t = nullptr) noexcept {}
        IVpnChannelConfiguration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannelConfiguration2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannelConfiguration2>
    {
        IVpnChannelConfiguration2(std::nullptr_t = nullptr) noexcept {}
        IVpnChannelConfiguration2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnChannelStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnChannelStatics>
    {
        IVpnChannelStatics(std::nullptr_t = nullptr) noexcept {}
        IVpnChannelStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCredential :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCredential>
    {
        IVpnCredential(std::nullptr_t = nullptr) noexcept {}
        IVpnCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomCheckBox :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomCheckBox>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomCheckBox, llm:OS::Networking::Vpn::IVpnCustomPrompt>
    {
        IVpnCustomCheckBox(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomCheckBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomComboBox :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomComboBox>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomComboBox, llm:OS::Networking::Vpn::IVpnCustomPrompt>
    {
        IVpnCustomComboBox(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomComboBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomEditBox :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomEditBox>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomEditBox, llm:OS::Networking::Vpn::IVpnCustomPrompt>
    {
        IVpnCustomEditBox(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomEditBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomErrorBox :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomErrorBox>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomErrorBox, llm:OS::Networking::Vpn::IVpnCustomPrompt>
    {
        IVpnCustomErrorBox(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomErrorBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomPrompt :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomPrompt>
    {
        IVpnCustomPrompt(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomPrompt(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomPromptBooleanInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomPromptBooleanInput>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomPromptBooleanInput, llm:OS::Networking::Vpn::IVpnCustomPromptElement>
    {
        IVpnCustomPromptBooleanInput(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomPromptBooleanInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomPromptElement :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomPromptElement>
    {
        IVpnCustomPromptElement(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomPromptElement(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomPromptOptionSelector :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomPromptOptionSelector>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomPromptOptionSelector, llm:OS::Networking::Vpn::IVpnCustomPromptElement>
    {
        IVpnCustomPromptOptionSelector(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomPromptOptionSelector(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomPromptText :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomPromptText>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomPromptText, llm:OS::Networking::Vpn::IVpnCustomPromptElement>
    {
        IVpnCustomPromptText(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomPromptText(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomPromptTextInput :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomPromptTextInput>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomPromptTextInput, llm:OS::Networking::Vpn::IVpnCustomPromptElement>
    {
        IVpnCustomPromptTextInput(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomPromptTextInput(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnCustomTextBox :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnCustomTextBox>,
        impl::require<llm:OS::Networking::Vpn::IVpnCustomTextBox, llm:OS::Networking::Vpn::IVpnCustomPrompt>
    {
        IVpnCustomTextBox(std::nullptr_t = nullptr) noexcept {}
        IVpnCustomTextBox(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnDomainNameAssignment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnDomainNameAssignment>
    {
        IVpnDomainNameAssignment(std::nullptr_t = nullptr) noexcept {}
        IVpnDomainNameAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnDomainNameInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnDomainNameInfo>
    {
        IVpnDomainNameInfo(std::nullptr_t = nullptr) noexcept {}
        IVpnDomainNameInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnDomainNameInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnDomainNameInfo2>
    {
        IVpnDomainNameInfo2(std::nullptr_t = nullptr) noexcept {}
        IVpnDomainNameInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnDomainNameInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnDomainNameInfoFactory>
    {
        IVpnDomainNameInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnDomainNameInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnForegroundActivatedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnForegroundActivatedEventArgs>
    {
        IVpnForegroundActivatedEventArgs(std::nullptr_t = nullptr) noexcept {}
        IVpnForegroundActivatedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnForegroundActivationOperation :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnForegroundActivationOperation>
    {
        IVpnForegroundActivationOperation(std::nullptr_t = nullptr) noexcept {}
        IVpnForegroundActivationOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnInterfaceId :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnInterfaceId>
    {
        IVpnInterfaceId(std::nullptr_t = nullptr) noexcept {}
        IVpnInterfaceId(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnInterfaceIdFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnInterfaceIdFactory>
    {
        IVpnInterfaceIdFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnInterfaceIdFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnManagementAgent :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnManagementAgent>
    {
        IVpnManagementAgent(std::nullptr_t = nullptr) noexcept {}
        IVpnManagementAgent(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnNamespaceAssignment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnNamespaceAssignment>
    {
        IVpnNamespaceAssignment(std::nullptr_t = nullptr) noexcept {}
        IVpnNamespaceAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnNamespaceInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnNamespaceInfo>
    {
        IVpnNamespaceInfo(std::nullptr_t = nullptr) noexcept {}
        IVpnNamespaceInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnNamespaceInfoFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnNamespaceInfoFactory>
    {
        IVpnNamespaceInfoFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnNamespaceInfoFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnNativeProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnNativeProfile>,
        impl::require<llm:OS::Networking::Vpn::IVpnNativeProfile, llm:OS::Networking::Vpn::IVpnProfile>
    {
        IVpnNativeProfile(std::nullptr_t = nullptr) noexcept {}
        IVpnNativeProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnNativeProfile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnNativeProfile2>
    {
        IVpnNativeProfile2(std::nullptr_t = nullptr) noexcept {}
        IVpnNativeProfile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPacketBuffer :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPacketBuffer>
    {
        IVpnPacketBuffer(std::nullptr_t = nullptr) noexcept {}
        IVpnPacketBuffer(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPacketBuffer2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPacketBuffer2>
    {
        IVpnPacketBuffer2(std::nullptr_t = nullptr) noexcept {}
        IVpnPacketBuffer2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPacketBuffer3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPacketBuffer3>
    {
        IVpnPacketBuffer3(std::nullptr_t = nullptr) noexcept {}
        IVpnPacketBuffer3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPacketBufferFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPacketBufferFactory>
    {
        IVpnPacketBufferFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnPacketBufferFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPacketBufferList :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPacketBufferList>,
        impl::require<llm:OS::Networking::Vpn::IVpnPacketBufferList, llm:OS::Foundation::Collections::IIterable<llm:OS::Networking::Vpn::VpnPacketBuffer>>
    {
        IVpnPacketBufferList(std::nullptr_t = nullptr) noexcept {}
        IVpnPacketBufferList(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPacketBufferList2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPacketBufferList2>,
        impl::require<llm:OS::Networking::Vpn::IVpnPacketBufferList2, llm:OS::Foundation::Collections::IIterable<llm:OS::Networking::Vpn::VpnPacketBuffer>>
    {
        IVpnPacketBufferList2(std::nullptr_t = nullptr) noexcept {}
        IVpnPacketBufferList2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPickedCredential :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPickedCredential>
    {
        IVpnPickedCredential(std::nullptr_t = nullptr) noexcept {}
        IVpnPickedCredential(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPlugIn :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPlugIn>
    {
        IVpnPlugIn(std::nullptr_t = nullptr) noexcept {}
        IVpnPlugIn(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPlugInProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPlugInProfile>,
        impl::require<llm:OS::Networking::Vpn::IVpnPlugInProfile, llm:OS::Networking::Vpn::IVpnProfile>
    {
        IVpnPlugInProfile(std::nullptr_t = nullptr) noexcept {}
        IVpnPlugInProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnPlugInProfile2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnPlugInProfile2>,
        impl::require<llm:OS::Networking::Vpn::IVpnPlugInProfile2, llm:OS::Networking::Vpn::IVpnProfile>
    {
        IVpnPlugInProfile2(std::nullptr_t = nullptr) noexcept {}
        IVpnPlugInProfile2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnProfile :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnProfile>
    {
        IVpnProfile(std::nullptr_t = nullptr) noexcept {}
        IVpnProfile(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnRoute :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnRoute>
    {
        IVpnRoute(std::nullptr_t = nullptr) noexcept {}
        IVpnRoute(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnRouteAssignment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnRouteAssignment>
    {
        IVpnRouteAssignment(std::nullptr_t = nullptr) noexcept {}
        IVpnRouteAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnRouteFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnRouteFactory>
    {
        IVpnRouteFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnRouteFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnSystemHealth :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnSystemHealth>
    {
        IVpnSystemHealth(std::nullptr_t = nullptr) noexcept {}
        IVpnSystemHealth(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnTrafficFilter :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnTrafficFilter>
    {
        IVpnTrafficFilter(std::nullptr_t = nullptr) noexcept {}
        IVpnTrafficFilter(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnTrafficFilterAssignment :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnTrafficFilterAssignment>
    {
        IVpnTrafficFilterAssignment(std::nullptr_t = nullptr) noexcept {}
        IVpnTrafficFilterAssignment(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IVpnTrafficFilterFactory :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IVpnTrafficFilterFactory>
    {
        IVpnTrafficFilterFactory(std::nullptr_t = nullptr) noexcept {}
        IVpnTrafficFilterFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
