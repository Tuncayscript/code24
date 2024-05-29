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
#ifndef LLM_OS_ApplicationModel_CommunicationBlocking_1_H
#define LLM_OS_ApplicationModel_CommunicationBlocking_1_H
#include "llm/impl/Windows.ApplicationModel.CommunicationBlocking.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::CommunicationBlocking
{
    struct __declspec(empty_bases) ICommunicationBlockingAccessManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommunicationBlockingAccessManagerStatics>
    {
        ICommunicationBlockingAccessManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICommunicationBlockingAccessManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommunicationBlockingAppManagerStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommunicationBlockingAppManagerStatics>
    {
        ICommunicationBlockingAppManagerStatics(std::nullptr_t = nullptr) noexcept {}
        ICommunicationBlockingAppManagerStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ICommunicationBlockingAppManagerStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ICommunicationBlockingAppManagerStatics2>,
        impl::require<llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics2, llm::OS::ApplicationModel::CommunicationBlocking::ICommunicationBlockingAppManagerStatics>
    {
        ICommunicationBlockingAppManagerStatics2(std::nullptr_t = nullptr) noexcept {}
        ICommunicationBlockingAppManagerStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
