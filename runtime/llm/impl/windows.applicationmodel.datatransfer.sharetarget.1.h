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
#ifndef LLM_OS_ApplicationModel_DataTransfer_ShareTarget_1_H
#define LLM_OS_ApplicationModel_DataTransfer_ShareTarget_1_H
#include "llm/impl/Windows.ApplicationModel.DataTransfer.ShareTarget.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::ShareTarget
{
    struct __declspec(empty_bases) IQuickLink :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IQuickLink>
    {
        IQuickLink(std::nullptr_t = nullptr) noexcept {}
        IQuickLink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareOperation :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareOperation>
    {
        IShareOperation(std::nullptr_t = nullptr) noexcept {}
        IShareOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareOperation2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareOperation2>
    {
        IShareOperation2(std::nullptr_t = nullptr) noexcept {}
        IShareOperation2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IShareOperation3 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IShareOperation3>
    {
        IShareOperation3(std::nullptr_t = nullptr) noexcept {}
        IShareOperation3(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
