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
#ifndef LLM_OS_Devices_Sms_1_H
#define LLM_OS_Devices_Sms_1_H
#include "llm/impl/Windows.Devices.Sms.0.h"
LLM_EXPORT namespace llm::OS::Devices::Sms
{
    struct __declspec(empty_bases) ISmsAppMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsAppMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsAppMessage, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        ISmsAppMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsAppMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsBinaryMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsBinaryMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsBinaryMessage, llm::OS::Devices::Sms::ISmsMessage>
    {
        ISmsBinaryMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsBinaryMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsBroadcastMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsBroadcastMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsBroadcastMessage, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        ISmsBroadcastMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsBroadcastMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsDevice :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsDevice>
    {
        ISmsDevice(std::nullptr_t = nullptr) noexcept {}
        ISmsDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsDevice2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsDevice2>
    {
        ISmsDevice2(std::nullptr_t = nullptr) noexcept {}
        ISmsDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsDevice2Statics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsDevice2Statics>
    {
        ISmsDevice2Statics(std::nullptr_t = nullptr) noexcept {}
        ISmsDevice2Statics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsDeviceMessageStore :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsDeviceMessageStore>
    {
        ISmsDeviceMessageStore(std::nullptr_t = nullptr) noexcept {}
        ISmsDeviceMessageStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsDeviceStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsDeviceStatics>
    {
        ISmsDeviceStatics(std::nullptr_t = nullptr) noexcept {}
        ISmsDeviceStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsDeviceStatics2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsDeviceStatics2>
    {
        ISmsDeviceStatics2(std::nullptr_t = nullptr) noexcept {}
        ISmsDeviceStatics2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsFilterRule :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsFilterRule>
    {
        ISmsFilterRule(std::nullptr_t = nullptr) noexcept {}
        ISmsFilterRule(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsFilterRuleFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsFilterRuleFactory>
    {
        ISmsFilterRuleFactory(std::nullptr_t = nullptr) noexcept {}
        ISmsFilterRuleFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsFilterRules :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsFilterRules>
    {
        ISmsFilterRules(std::nullptr_t = nullptr) noexcept {}
        ISmsFilterRules(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsFilterRulesFactory :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsFilterRulesFactory>
    {
        ISmsFilterRulesFactory(std::nullptr_t = nullptr) noexcept {}
        ISmsFilterRulesFactory(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessage>
    {
        ISmsMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessageBase :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessageBase>
    {
        ISmsMessageBase(std::nullptr_t = nullptr) noexcept {}
        ISmsMessageBase(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessageReceivedEventArgs :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessageReceivedEventArgs>
    {
        ISmsMessageReceivedEventArgs(std::nullptr_t = nullptr) noexcept {}
        ISmsMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessageReceivedTriggerDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessageReceivedTriggerDetails>
    {
        ISmsMessageReceivedTriggerDetails(std::nullptr_t = nullptr) noexcept {}
        ISmsMessageReceivedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessageRegistration :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessageRegistration>
    {
        ISmsMessageRegistration(std::nullptr_t = nullptr) noexcept {}
        ISmsMessageRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsMessageRegistrationStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsMessageRegistrationStatics>
    {
        ISmsMessageRegistrationStatics(std::nullptr_t = nullptr) noexcept {}
        ISmsMessageRegistrationStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsReceivedEventDetails :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsReceivedEventDetails>
    {
        ISmsReceivedEventDetails(std::nullptr_t = nullptr) noexcept {}
        ISmsReceivedEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsReceivedEventDetails2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsReceivedEventDetails2>
    {
        ISmsReceivedEventDetails2(std::nullptr_t = nullptr) noexcept {}
        ISmsReceivedEventDetails2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsSendMessageResult :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsSendMessageResult>
    {
        ISmsSendMessageResult(std::nullptr_t = nullptr) noexcept {}
        ISmsSendMessageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsStatusMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsStatusMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsStatusMessage, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        ISmsStatusMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsStatusMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsTextMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsTextMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsTextMessage, llm::OS::Devices::Sms::ISmsMessage>
    {
        ISmsTextMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsTextMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsTextMessage2 :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsTextMessage2>,
        impl::require<llm::OS::Devices::Sms::ISmsTextMessage2, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        ISmsTextMessage2(std::nullptr_t = nullptr) noexcept {}
        ISmsTextMessage2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsTextMessageStatics :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsTextMessageStatics>
    {
        ISmsTextMessageStatics(std::nullptr_t = nullptr) noexcept {}
        ISmsTextMessageStatics(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsVoicemailMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsVoicemailMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsVoicemailMessage, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        ISmsVoicemailMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsVoicemailMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) ISmsWapMessage :
        llm::OS::Foundation::IInspectable,
        impl::consume_t<ISmsWapMessage>,
        impl::require<llm::OS::Devices::Sms::ISmsWapMessage, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        ISmsWapMessage(std::nullptr_t = nullptr) noexcept {}
        ISmsWapMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IInspectable(ptr, take_ownership_from_abi) {}
    };
}
#endif
