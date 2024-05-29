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
#ifndef LLM_OS_ApplicationModel_UserActivities_2_H
#define LLM_OS_ApplicationModel_UserActivities_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Security.Credentials.1.h"
#include "llm/impl/Windows.System.1.h"
#include "llm/impl/Windows.ApplicationModel.UserActivities.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::UserActivities
{
    struct __declspec(empty_bases) UserActivity : llm::OS::ApplicationModel::UserActivities::IUserActivity,
        impl::require<UserActivity, llm::OS::ApplicationModel::UserActivities::IUserActivity2, llm::OS::ApplicationModel::UserActivities::IUserActivity3>
    {
        UserActivity(std::nullptr_t) noexcept {}
        UserActivity(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivity(ptr, take_ownership_from_abi) {}
        explicit UserActivity(param::hstring const& activityId);
        static auto TryParseFromJson(param::hstring const& json);
        static auto TryParseFromJsonArray(param::hstring const& json);
        static auto ToJsonArray(param::iterable<llm::OS::ApplicationModel::UserActivities::UserActivity> const& activities);
    };
    struct __declspec(empty_bases) UserActivityAttribution : llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution
    {
        UserActivityAttribution(std::nullptr_t) noexcept {}
        UserActivityAttribution(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityAttribution(ptr, take_ownership_from_abi) {}
        UserActivityAttribution();
        explicit UserActivityAttribution(llm::OS::Foundation::Uri const& iconUri);
    };
    struct __declspec(empty_bases) UserActivityChannel : llm::OS::ApplicationModel::UserActivities::IUserActivityChannel,
        impl::require<UserActivityChannel, llm::OS::ApplicationModel::UserActivities::IUserActivityChannel2>
    {
        UserActivityChannel(std::nullptr_t) noexcept {}
        UserActivityChannel(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityChannel(ptr, take_ownership_from_abi) {}
        static auto GetDefault();
        static auto DisableAutoSessionCreation();
        static auto TryGetForWebAccount(llm::OS::Security::Credentials::WebAccount const& account);
        static auto GetForUser(llm::OS::System::User const& user);
    };
    struct __declspec(empty_bases) UserActivityContentInfo : llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo
    {
        UserActivityContentInfo(std::nullptr_t) noexcept {}
        UserActivityContentInfo(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityContentInfo(ptr, take_ownership_from_abi) {}
        static auto FromJson(param::hstring const& value);
    };
    struct __declspec(empty_bases) UserActivityRequest : llm::OS::ApplicationModel::UserActivities::IUserActivityRequest
    {
        UserActivityRequest(std::nullptr_t) noexcept {}
        UserActivityRequest(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityRequest(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserActivityRequestManager : llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager
    {
        UserActivityRequestManager(std::nullptr_t) noexcept {}
        UserActivityRequestManager(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityRequestManager(ptr, take_ownership_from_abi) {}
        static auto GetForCurrentView();
    };
    struct __declspec(empty_bases) UserActivityRequestedEventArgs : llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs
    {
        UserActivityRequestedEventArgs(std::nullptr_t) noexcept {}
        UserActivityRequestedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityRequestedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserActivitySession : llm::OS::ApplicationModel::UserActivities::IUserActivitySession,
        impl::require<UserActivitySession, llm::OS::Foundation::IClosable>
    {
        UserActivitySession(std::nullptr_t) noexcept {}
        UserActivitySession(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivitySession(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserActivitySessionHistoryItem : llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem
    {
        UserActivitySessionHistoryItem(std::nullptr_t) noexcept {}
        UserActivitySessionHistoryItem(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivitySessionHistoryItem(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) UserActivityVisualElements : llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements,
        impl::require<UserActivityVisualElements, llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements2>
    {
        UserActivityVisualElements(std::nullptr_t) noexcept {}
        UserActivityVisualElements(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::UserActivities::IUserActivityVisualElements(ptr, take_ownership_from_abi) {}
    };
}
#endif
