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
#ifndef LLM_OS_Security_Credentials_UI_2_H
#define LLM_OS_Security_Credentials_UI_2_H
#include "llm/impl/Windows.Security.Credentials.UI.1.h"
LLM_EXPORT namespace llm:OS::Security::Credentials::UI
{
    struct CredentialPicker
    {
        CredentialPicker() = delete;
        static auto PickAsync(llm:OS::Security::Credentials::UI::CredentialPickerOptions const& options);
        static auto PickAsync(param::hstring const& targetName, param::hstring const& message);
        static auto PickAsync(param::hstring const& targetName, param::hstring const& message, param::hstring const& caption);
    };
    struct __declspec(empty_bases) CredentialPickerOptions : llm:OS::Security::Credentials::UI::ICredentialPickerOptions
    {
        CredentialPickerOptions(std::nullptr_t) noexcept {}
        CredentialPickerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::UI::ICredentialPickerOptions(ptr, take_ownership_from_abi) {}
        CredentialPickerOptions();
    };
    struct __declspec(empty_bases) CredentialPickerResults : llm:OS::Security::Credentials::UI::ICredentialPickerResults
    {
        CredentialPickerResults(std::nullptr_t) noexcept {}
        CredentialPickerResults(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Security::Credentials::UI::ICredentialPickerResults(ptr, take_ownership_from_abi) {}
    };
    struct UserConsentVerifier
    {
        UserConsentVerifier() = delete;
        static auto CheckAvailabilityAsync();
        static auto RequestVerificationAsync(param::hstring const& message);
    };
}
#endif
