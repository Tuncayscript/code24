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
#ifndef LLM_OS_ApplicationModel_DataTransfer_ShareTarget_2_H
#define LLM_OS_ApplicationModel_DataTransfer_ShareTarget_2_H
#include "llm/impl/Windows.ApplicationModel.DataTransfer.ShareTarget.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::DataTransfer::ShareTarget
{
    struct __declspec(empty_bases) QuickLink : llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink
    {
        QuickLink(std::nullptr_t) noexcept {}
        QuickLink(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::ShareTarget::IQuickLink(ptr, take_ownership_from_abi) {}
        QuickLink();
    };
    struct __declspec(empty_bases) ShareOperation : llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation,
        impl::require<ShareOperation, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation2, llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation3>
    {
        ShareOperation(std::nullptr_t) noexcept {}
        ShareOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::DataTransfer::ShareTarget::IShareOperation(ptr, take_ownership_from_abi) {}
    };
}
#endif
