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
#ifndef LLM_OS_System_Update_2_H
#define LLM_OS_System_Update_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.System.Update.1.h"
LLM_EXPORT namespace llm:OS::System::Update
{
    struct __declspec(empty_bases) SystemUpdateItem : llm:OS::System::Update::ISystemUpdateItem
    {
        SystemUpdateItem(std::nullptr_t) noexcept {}
        SystemUpdateItem(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Update::ISystemUpdateItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SystemUpdateLastErrorInfo : llm:OS::System::Update::ISystemUpdateLastErrorInfo
    {
        SystemUpdateLastErrorInfo(std::nullptr_t) noexcept {}
        SystemUpdateLastErrorInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm:OS::System::Update::ISystemUpdateLastErrorInfo(ptr, take_ownership_from_abi) {}
    };
    struct SystemUpdateManager
    {
        SystemUpdateManager() = delete;
        static auto IsSupported();
        [[nodiscard]] static auto State();
        static auto StateChanged(llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        using StateChanged_revoker = impl::factory_event_revoker<llm:OS::System::Update::ISystemUpdateManagerStatics, &impl::abi_t<llm:OS::System::Update::ISystemUpdateManagerStatics>::remove_StateChanged>;
        [[nodiscard]] static StateChanged_revoker StateChanged(auto_revoke_t, llm:OS::Foundation::EventHandler<llm:OS::Foundation::IInspectable> const& handler);
        static auto StateChanged(llm::event_token const& token);
        [[nodiscard]] static auto DownloadProgress();
        [[nodiscard]] static auto InstallProgress();
        [[nodiscard]] static auto UserActiveHoursStart();
        [[nodiscard]] static auto UserActiveHoursEnd();
        [[nodiscard]] static auto UserActiveHoursMax();
        static auto TrySetUserActiveHours(llm:OS::Foundation::TimeSpan const& start, llm:OS::Foundation::TimeSpan const& end);
        [[nodiscard]] static auto LastUpdateCheckTime();
        [[nodiscard]] static auto LastUpdateInstallTime();
        [[nodiscard]] static auto LastErrorInfo();
        static auto GetAutomaticRebootBlockIds();
        static auto BlockAutomaticRebootAsync(param::hstring const& lockId);
        static auto UnblockAutomaticRebootAsync(param::hstring const& lockId);
        [[nodiscard]] static auto ExtendedError();
        static auto GetUpdateItems();
        [[nodiscard]] static auto AttentionRequiredReason();
        static auto SetFlightRing(param::hstring const& flightRing);
        static auto GetFlightRing();
        static auto StartInstall(llm:OS::System::Update::SystemUpdateStartInstallAction const& action);
        static auto RebootToCompleteInstall();
        static auto StartCancelUpdates();
    };
}
#endif
