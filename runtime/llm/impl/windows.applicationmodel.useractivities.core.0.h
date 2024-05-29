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
#ifndef LLM_OS_ApplicationModel_UserActivities_Core_0_H
#define LLM_OS_ApplicationModel_UserActivities_Core_0_H
LLM_EXPORT namespace llm::OS::ApplicationModel::UserActivities
{
    struct UserActivity;
    struct UserActivityChannel;
    struct UserActivitySession;
}
LLM_EXPORT namespace llm::OS::Foundation
{
    struct IAsyncAction;
}
LLM_EXPORT namespace llm::OS::ApplicationModel::UserActivities::Core
{
    struct ICoreUserActivityManagerStatics;
    struct CoreUserActivityManager;
}
namespace llm::impl
{
    template <> struct category<llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics>{ using type = interface_category; };
    template <> struct category<llm::OS::ApplicationModel::UserActivities::Core::CoreUserActivityManager>{ using type = class_category; };
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::Core::CoreUserActivityManager> = L"Windows.ApplicationModel.UserActivities.Core.CoreUserActivityManager";
    template <> inline constexpr auto& name_v<llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics> = L"Windows.ApplicationModel.UserActivities.Core.ICoreUserActivityManagerStatics";
    template <> inline constexpr guid guid_v<llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics>{ 0xCA3ADB02,0xA4BE,0x4D4D,{ 0xBF,0xA8,0x67,0x95,0xF4,0x26,0x4E,0xFB } }; // CA3ADB02-A4BE-4D4D-BFA8-6795F4264EFB
    template <> struct abi<llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics>
    {
        struct __declspec(novtable) type : inspectable_abi
        {
            virtual int32_t __stdcall CreateUserActivitySessionInBackground(void*, void**) noexcept = 0;
            virtual int32_t __stdcall DeleteUserActivitySessionsInTimeRangeAsync(void*, int64_t, int64_t, void**) noexcept = 0;
        };
    };
    template <typename D>
    struct consume_Windows_ApplicationModel_UserActivities_Core_ICoreUserActivityManagerStatics
    {
        LLM_IMPL_AUTO(llm::OS::ApplicationModel::UserActivities::UserActivitySession) CreateUserActivitySessionInBackground(llm::OS::ApplicationModel::UserActivities::UserActivity const& activity) const;
        LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) DeleteUserActivitySessionsInTimeRangeAsync(llm::OS::ApplicationModel::UserActivities::UserActivityChannel const& channel, llm::OS::Foundation::DateTime const& startTime, llm::OS::Foundation::DateTime const& endTime) const;
    };
    template <> struct consume<llm::OS::ApplicationModel::UserActivities::Core::ICoreUserActivityManagerStatics>
    {
        template <typename D> using type = consume_Windows_ApplicationModel_UserActivities_Core_ICoreUserActivityManagerStatics<D>;
    };
}
#endif
