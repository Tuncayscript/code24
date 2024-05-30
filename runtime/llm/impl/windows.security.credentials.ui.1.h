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
#ifndef LLM_OS_Security_Credentials_UI_1_H
#define LLM_OS_Security_Credentials_UI_1_H
#include "llm/impl/Windows.Security.Credentials.UI.0.h"
LLM_EXPORT namespace llm:OS::Security::Credentials::UI
{
    struct __declspec(empty_bases) ICredentialPickerOptions :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICredentialPickerOptions>
    {
        ICredentialPickerOptions(std::nullptr_t = nullptr) noexcept {}
        ICredentialPickerOptions(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICredentialPickerResults :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICredentialPickerResults>
    {
        ICredentialPickerResults(std::nullptr_t = nullptr) noexcept {}
        ICredentialPickerResults(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICredentialPickerStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<ICredentialPickerStatics>
    {
        ICredentialPickerStatics(std::nullptr_t = nullptr) noexcept {}
        ICredentialPickerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IUserConsentVerifierStatics :
        llm:OS::Foundation::IInspectable,
        impl::consume_t<IUserConsentVerifierStatics>
    {
        IUserConsentVerifierStatics(std::nullptr_t = nullptr) noexcept {}
        IUserConsentVerifierStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
