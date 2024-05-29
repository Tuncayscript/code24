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
#ifndef LLM_OS_ApplicationModel_Store_LicenseManagement_2_H
#define LLM_OS_ApplicationModel_Store_LicenseManagement_2_H
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Storage.Streams.1.h"
#include "llm/impl/Windows.ApplicationModel.Store.LicenseManagement.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Store::LicenseManagement
{
    struct LicenseManager
    {
        LicenseManager() = delete;
        static auto AddLicenseAsync(llm::OS::Storage::Streams::IBuffer const& license);
        static auto GetSatisfactionInfosAsync(param::async_iterable<hstring> const& contentIds, param::async_iterable<hstring> const& keyIds);
        static auto RefreshLicensesAsync(llm::OS::ApplicationModel::Store::LicenseManagement::LicenseRefreshOption const& refreshOption);
    };
    struct __declspec(empty_bases) LicenseSatisfactionInfo : llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo
    {
        LicenseSatisfactionInfo(std::nullptr_t) noexcept {}
        LicenseSatisfactionInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionInfo(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) LicenseSatisfactionResult : llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult
    {
        LicenseSatisfactionResult(std::nullptr_t) noexcept {}
        LicenseSatisfactionResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Store::LicenseManagement::ILicenseSatisfactionResult(ptr, take_ownership_from_abi) {}
    };
}
#endif
