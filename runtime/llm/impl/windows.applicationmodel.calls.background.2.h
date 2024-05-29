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
#ifndef LLM_OS_ApplicationModel_Calls_Background_2_H
#define LLM_OS_ApplicationModel_Calls_Background_2_H
#include "llm/impl/Windows.ApplicationModel.Calls.Background.1.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls::Background
{
    struct __declspec(empty_bases) PhoneCallBlockedTriggerDetails : llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails
    {
        PhoneCallBlockedTriggerDetails(std::nullptr_t) noexcept {}
        PhoneCallBlockedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Background::IPhoneCallBlockedTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneCallOriginDataRequestTriggerDetails : llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails
    {
        PhoneCallOriginDataRequestTriggerDetails(std::nullptr_t) noexcept {}
        PhoneCallOriginDataRequestTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Background::IPhoneCallOriginDataRequestTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneIncomingCallDismissedTriggerDetails : llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails
    {
        PhoneIncomingCallDismissedTriggerDetails(std::nullptr_t) noexcept {}
        PhoneIncomingCallDismissedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallDismissedTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneIncomingCallNotificationTriggerDetails : llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails
    {
        PhoneIncomingCallNotificationTriggerDetails(std::nullptr_t) noexcept {}
        PhoneIncomingCallNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Background::IPhoneIncomingCallNotificationTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneLineChangedTriggerDetails : llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails
    {
        PhoneLineChangedTriggerDetails(std::nullptr_t) noexcept {}
        PhoneLineChangedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Background::IPhoneLineChangedTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) PhoneNewVoicemailMessageTriggerDetails : llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails
    {
        PhoneNewVoicemailMessageTriggerDetails(std::nullptr_t) noexcept {}
        PhoneNewVoicemailMessageTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::ApplicationModel::Calls::Background::IPhoneNewVoicemailMessageTriggerDetails(ptr, take_ownership_from_abi) {}
    };
}
#endif
