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
#ifndef LLM_OS_ApplicationModel_Calls_Background_1_H
#define LLM_OS_ApplicationModel_Calls_Background_1_H
#include "llm/impl/Windows.ApplicationModel.Calls.Background.0.h"
LLM_EXPORT namespace llm::OS::ApplicationModel::Calls::Background
{
    struct __declspec(empty_bases) IPhoneCallBlockedTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallBlockedTriggerDetails>
    {
        IPhoneCallBlockedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallBlockedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneCallOriginDataRequestTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneCallOriginDataRequestTriggerDetails>
    {
        IPhoneCallOriginDataRequestTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneCallOriginDataRequestTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneIncomingCallDismissedTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneIncomingCallDismissedTriggerDetails>
    {
        IPhoneIncomingCallDismissedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneIncomingCallDismissedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneIncomingCallNotificationTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneIncomingCallNotificationTriggerDetails>
    {
        IPhoneIncomingCallNotificationTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneIncomingCallNotificationTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneLineChangedTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneLineChangedTriggerDetails>
    {
        IPhoneLineChangedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneLineChangedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) IPhoneNewVoicemailMessageTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<IPhoneNewVoicemailMessageTriggerDetails>
    {
        IPhoneNewVoicemailMessageTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        IPhoneNewVoicemailMessageTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
