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
#ifndef LLM_OS_Security_Authentication_Identity_Provider_2_H
#define LLM_OS_Security_Authentication_Identity_Provider_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.Security.Authentication.Identity.Provider.1.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Identity::Provider
{
    struct __declspec(empty_bases) SecondaryAuthenticationFactorAuthentication : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication
    {
        SecondaryAuthenticationFactorAuthentication(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorAuthentication(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthentication(ptr, take_ownership_from_abi) {}
        static auto ShowNotificationMessageAsync(param::hstring const& deviceName, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationMessage const& message);
        static auto StartAuthenticationAsync(param::hstring const& deviceId, llm:OS::Storage::Streams::IBuffer const& serviceAuthenticationNonce);
        static auto AuthenticationStageChanged(llm:OS::Foundation::EventHandler<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler);
        using AuthenticationStageChanged_revoker = impl::factory_event_revoker<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics, &impl::abi_t<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStatics>::remove_AuthenticationStageChanged>;
        [[nodiscard]] static AuthenticationStageChanged_revoker AuthenticationStageChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs> const& handler);
        static auto AuthenticationStageChanged(llm::event_token const& token);
        static auto GetAuthenticationStageInfoAsync();
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorAuthenticationResult : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult
    {
        SecondaryAuthenticationFactorAuthenticationResult(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorAuthenticationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs
    {
        SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorAuthenticationStageInfo : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo
    {
        SecondaryAuthenticationFactorAuthenticationStageInfo(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorAuthenticationStageInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorAuthenticationStageInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorInfo : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo,
        impl::require<SecondaryAuthenticationFactorInfo, llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2>
    {
        SecondaryAuthenticationFactorInfo(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorRegistration : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration
    {
        SecondaryAuthenticationFactorRegistration(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistration(ptr, take_ownership_from_abi) {}
        static auto RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode);
        static auto RegisterDevicePresenceMonitoringAsync(param::hstring const& deviceId, param::hstring const& deviceInstancePath, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDevicePresenceMonitoringMode const& monitoringMode, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm:OS::Storage::Streams::IBuffer const& deviceConfigurationData);
        static auto UnregisterDevicePresenceMonitoringAsync(param::hstring const& deviceId);
        static auto IsDevicePresenceMonitoringSupported();
        static auto RequestStartRegisteringDeviceAsync(param::hstring const& deviceId, llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceCapabilities const& capabilities, param::hstring const& deviceFriendlyName, param::hstring const& deviceModelNumber, llm:OS::Storage::Streams::IBuffer const& deviceKey, llm:OS::Storage::Streams::IBuffer const& mutualAuthenticationKey);
        static auto FindAllRegisteredDeviceInfoAsync(llm:OS::Security::Authentication::Identity::Provider::SecondaryAuthenticationFactorDeviceFindScope const& queryType);
        static auto UnregisterDeviceAsync(param::hstring const& deviceId);
        static auto UpdateDeviceConfigurationDataAsync(param::hstring const& deviceId, llm:OS::Storage::Streams::IBuffer const& deviceConfigurationData);
    };
    struct __declspec(empty_bases) SecondaryAuthenticationFactorRegistrationResult : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult
    {
        SecondaryAuthenticationFactorRegistrationResult(std::nullptr_t) noexcept {}
        SecondaryAuthenticationFactorRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorRegistrationResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
