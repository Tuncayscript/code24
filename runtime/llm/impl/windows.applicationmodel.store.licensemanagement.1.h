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
#ifndef LLM_OS_ApplicationModel_Store_LicenseManagement_1_H
#define LLM_OS_ApplicationModel_Store_LicenseManagement_1_H
#include "llm/impl/Windows.ApplicationModel.Store.LicenseManagement.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::LicenseManagement
{
    struct __declspec(empty_bases) ILicenseManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILicenseManagerStatics>
    {
        ILicenseManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ILicenseManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILicenseManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILicenseManagerStatics2>
    {
        ILicenseManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        ILicenseManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILicenseSatisfactionInfo :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILicenseSatisfactionInfo>
    {
        ILicenseSatisfactionInfo(std::nullptr_t = nullptr) noexcept {}
        ILicenseSatisfactionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ILicenseSatisfactionResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ILicenseSatisfactionResult>
    {
        ILicenseSatisfactionResult(std::nullptr_t = nullptr) noexcept {}
        ILicenseSatisfactionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
