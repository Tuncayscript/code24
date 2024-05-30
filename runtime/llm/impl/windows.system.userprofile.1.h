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
#ifndef LLM_OS_System_UserProfile_1_H
#define LLM_OS_System_UserProfile_1_H
#include "llm/impl/Windows.Foundation.Collections.0.h"
#include "llm/impl/Windows.System.UserProfile.0.h"
LLM_EXPORT namespace llm:OS::System::UserProfile
{
    struct __declspec(empty_bases) IAdvertisingManagerForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvertisingManagerForUser>
    {
        IAdvertisingManagerForUser(std::nullptr_t = nullptr) noexcept {}
        IAdvertisingManagerForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdvertisingManagerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvertisingManagerStatics>
    {
        IAdvertisingManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IAdvertisingManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAdvertisingManagerStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAdvertisingManagerStatics2>
    {
        IAdvertisingManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IAdvertisingManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAssignedAccessSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAssignedAccessSettings>
    {
        IAssignedAccessSettings(std::nullptr_t = nullptr) noexcept {}
        IAssignedAccessSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IAssignedAccessSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IAssignedAccessSettingsStatics>
    {
        IAssignedAccessSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IAssignedAccessSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDiagnosticsSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDiagnosticsSettings>
    {
        IDiagnosticsSettings(std::nullptr_t = nullptr) noexcept {}
        IDiagnosticsSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IDiagnosticsSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IDiagnosticsSettingsStatics>
    {
        IDiagnosticsSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IDiagnosticsSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFirstSignInSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFirstSignInSettings>,
        impl::require<llm:OS::System::UserProfile::IFirstSignInSettings, llm:OS::Foundation::Collections::IIterable<llm:OS::Foundation::Collections::IKeyValuePair<hstring, llm:OS::Foundation::IInspectable>>, llm:OS::Foundation::Collections::IMapView<hstring, llm:OS::Foundation::IInspectable>>
    {
        IFirstSignInSettings(std::nullptr_t = nullptr) noexcept {}
        IFirstSignInSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IFirstSignInSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IFirstSignInSettingsStatics>
    {
        IFirstSignInSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IFirstSignInSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalizationPreferencesForUser :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalizationPreferencesForUser>
    {
        IGlobalizationPreferencesForUser(std::nullptr_t = nullptr) noexcept {}
        IGlobalizationPreferencesForUser(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalizationPreferencesStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalizationPreferencesStatics>
    {
        IGlobalizationPreferencesStatics(std::nullptr_t = nullptr) noexcept {}
        IGlobalizationPreferencesStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalizationPreferencesStatics2 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalizationPreferencesStatics2>
    {
        IGlobalizationPreferencesStatics2(std::nullptr_t = nullptr) noexcept {}
        IGlobalizationPreferencesStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IGlobalizationPreferencesStatics3 :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IGlobalizationPreferencesStatics3>
    {
        IGlobalizationPreferencesStatics3(std::nullptr_t = nullptr) noexcept {}
        IGlobalizationPreferencesStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenImageFeedStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenImageFeedStatics>
    {
        ILockScreenImageFeedStatics(std::nullptr_t = nullptr) noexcept {}
        ILockScreenImageFeedStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILockScreenStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ILockScreenStatics>
    {
        ILockScreenStatics(std::nullptr_t = nullptr) noexcept {}
        ILockScreenStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserInformationStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserInformationStatics>
    {
        IUserInformationStatics(std::nullptr_t = nullptr) noexcept {}
        IUserInformationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserProfilePersonalizationSettings :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserProfilePersonalizationSettings>
    {
        IUserProfilePersonalizationSettings(std::nullptr_t = nullptr) noexcept {}
        IUserProfilePersonalizationSettings(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserProfilePersonalizationSettingsStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserProfilePersonalizationSettingsStatics>
    {
        IUserProfilePersonalizationSettingsStatics(std::nullptr_t = nullptr) noexcept {}
        IUserProfilePersonalizationSettingsStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
