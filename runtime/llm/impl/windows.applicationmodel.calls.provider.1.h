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
#ifndef LLM_OS_ApplicationModel_Calls_Provider_1_H
#define LLM_OS_ApplicationModel_Calls_Provider_1_H
#include "llm/impl/Windows.ApplicationModel.Calls.Provider.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls::Provider
{
    struct __declspec(empty_bases) IPhoneCallOrigin :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOrigin>
    {
        IPhoneCallOrigin(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOrigin(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallOrigin2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOrigin2>,
        impl::require<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin>
    {
        IPhoneCallOrigin2(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOrigin2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallOrigin3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOrigin3>,
        impl::require<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2>
    {
        IPhoneCallOrigin3(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOrigin3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallOriginManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginManagerStatics>
    {
        IPhoneCallOriginManagerStatics(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallOriginManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginManagerStatics2>,
        impl::require<llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics2, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOriginManagerStatics>
    {
        IPhoneCallOriginManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallOriginManagerStatics3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginManagerStatics3>
    {
        IPhoneCallOriginManagerStatics3(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginManagerStatics3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
