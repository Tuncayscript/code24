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
#ifndef LLM_OS_ApplicationModel_Calls_Provider_2_H
#define LLM_OS_ApplicationModel_Calls_Provider_2_H
#include "llm/impl/Windows.ApplicationModel.Calls.Provider.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls::Provider
{
    struct __declspec(empty_bases) PhoneCallOrigin : llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin,
        impl::require<PhoneCallOrigin, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin2, llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin3>
    {
        PhoneCallOrigin(std::nullptr_t) noexcept {}
        PhoneCallOrigin(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Provider::IPhoneCallOrigin(ptr, take_ownership_from_abi) {}
        PhoneCallOrigin();
    };
    struct PhoneCallOriginManager
    {
        PhoneCallOriginManager() = delete;
        [[nodiscard]] static auto IsCurrentAppActiveCallOriginApp();
        static auto ShowPhoneCallOriginSettingsUI();
        static auto SetCallOrigin(llm::guid const& requestId, llm::OS::ApplicationModel::Calls::Provider::PhoneCallOrigin const& callOrigin);
        static auto RequestSetAsActiveCallOriginAppAsync();
        [[nodiscard]] static auto IsSupported();
    };
}
#endif
