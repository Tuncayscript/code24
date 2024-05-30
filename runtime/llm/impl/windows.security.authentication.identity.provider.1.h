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
#ifndef LLM_OS_Security_Authentication_Identity_Provider_1_H
#define LLM_OS_Security_Authentication_Identity_Provider_1_H
#include "llm/impl/Windows.Security.Authentication.Identity.Provider.0.h"
LLM_EXPORT namespace llm:OS::Security::Authentication::Identity::Provider
{
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorAuthentication :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorAuthentication>
    {
        ISecondaryAuthenticationFactorAuthentication(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorAuthentication(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorAuthenticationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorAuthenticationResult>
    {
        ISecondaryAuthenticationFactorAuthenticationResult(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorAuthenticationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs>
    {
        ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorAuthenticationStageChangedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorAuthenticationStageInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorAuthenticationStageInfo>
    {
        ISecondaryAuthenticationFactorAuthenticationStageInfo(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorAuthenticationStageInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorAuthenticationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorAuthenticationStatics>
    {
        ISecondaryAuthenticationFactorAuthenticationStatics(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorAuthenticationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics>
    {
        ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorDevicePresenceMonitoringRegistrationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorInfo :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorInfo>
    {
        ISecondaryAuthenticationFactorInfo(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorInfo2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorInfo2>,
        impl::require<llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo2, llm:OS::Security::Authentication::Identity::Provider::ISecondaryAuthenticationFactorInfo>
    {
        ISecondaryAuthenticationFactorInfo2(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorInfo2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorRegistration :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorRegistration>
    {
        ISecondaryAuthenticationFactorRegistration(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorRegistrationResult :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorRegistrationResult>
    {
        ISecondaryAuthenticationFactorRegistrationResult(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorRegistrationResult(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISecondaryAuthenticationFactorRegistrationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ISecondaryAuthenticationFactorRegistrationStatics>
    {
        ISecondaryAuthenticationFactorRegistrationStatics(std::nullptr_t = nullptr) noexcept {}
        ISecondaryAuthenticationFactorRegistrationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
