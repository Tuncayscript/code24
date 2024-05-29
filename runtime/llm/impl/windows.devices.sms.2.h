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
#ifndef LLM_OS_Devices_Sms_2_H
#define LLM_OS_Devices_Sms_2_H
#include "llm/impl/Windows.Foundation.1.h"
#include "llm/impl/Windows.Foundation.Collections.1.h"
#include "llm/impl/Windows.Devices.Sms.1.h"
LLM_EXPORT namespace llm::OS::Devices::Sms
{
    struct SmsDeviceStatusChangedEventHandler : llm::OS::Foundation::IUnknown
    {
        SmsDeviceStatusChangedEventHandler(std::nullptr_t = nullptr) noexcept {}
        SmsDeviceStatusChangedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SmsDeviceStatusChangedEventHandler(L lambda);
        template <typename F> SmsDeviceStatusChangedEventHandler(F* function);
        template <typename O, typename M> SmsDeviceStatusChangedEventHandler(O* object, M method);
        template <typename O, typename M> SmsDeviceStatusChangedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SmsDeviceStatusChangedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Devices::Sms::SmsDevice const& sender) const;
    };
    struct SmsMessageReceivedEventHandler : llm::OS::Foundation::IUnknown
    {
        SmsMessageReceivedEventHandler(std::nullptr_t = nullptr) noexcept {}
        SmsMessageReceivedEventHandler(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IUnknown(ptr, take_ownership_from_abi) {}
        template <typename L> SmsMessageReceivedEventHandler(L lambda);
        template <typename F> SmsMessageReceivedEventHandler(F* function);
        template <typename O, typename M> SmsMessageReceivedEventHandler(O* object, M method);
        template <typename O, typename M> SmsMessageReceivedEventHandler(com_ptr<O>&& object, M method);
        template <typename O, typename M> SmsMessageReceivedEventHandler(weak_ref<O>&& object, M method);
        auto operator()(llm::OS::Devices::Sms::SmsDevice const& sender, llm::OS::Devices::Sms::SmsMessageReceivedEventArgs const& e) const;
    };
    struct SmsEncodedLength
    {
        uint32_t SegmentCount;
        uint32_t CharacterCountLastSegment;
        uint32_t CharactersPerSegment;
        uint32_t ByteCountLastSegment;
        uint32_t BytesPerSegment;
    };
    inline bool operator==(SmsEncodedLength const& left, SmsEncodedLength const& right) noexcept
    {
        return left.SegmentCount == right.SegmentCount && left.CharacterCountLastSegment == right.CharacterCountLastSegment && left.CharactersPerSegment == right.CharactersPerSegment && left.ByteCountLastSegment == right.ByteCountLastSegment && left.BytesPerSegment == right.BytesPerSegment;
    }
    inline bool operator!=(SmsEncodedLength const& left, SmsEncodedLength const& right) noexcept
    {
        return !(left == right);
    }
    struct __declspec(empty_bases) DeleteSmsMessageOperation : llm::OS::Foundation::IAsyncAction
    {
        DeleteSmsMessageOperation(std::nullptr_t) noexcept {}
        DeleteSmsMessageOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IAsyncAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) DeleteSmsMessagesOperation : llm::OS::Foundation::IAsyncAction
    {
        DeleteSmsMessagesOperation(std::nullptr_t) noexcept {}
        DeleteSmsMessagesOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IAsyncAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GetSmsDeviceOperation : llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>
    {
        GetSmsDeviceOperation(std::nullptr_t) noexcept {}
        GetSmsDeviceOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GetSmsMessageOperation : llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::ISmsMessage>
    {
        GetSmsMessageOperation(std::nullptr_t) noexcept {}
        GetSmsMessageOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::ISmsMessage>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) GetSmsMessagesOperation : llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsMessage>, int32_t>
    {
        GetSmsMessagesOperation(std::nullptr_t) noexcept {}
        GetSmsMessagesOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsMessage>, int32_t>(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SendSmsMessageOperation : llm::OS::Foundation::IAsyncAction
    {
        SendSmsMessageOperation(std::nullptr_t) noexcept {}
        SendSmsMessageOperation(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Foundation::IAsyncAction(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsAppMessage : llm::OS::Devices::Sms::ISmsAppMessage
    {
        SmsAppMessage(std::nullptr_t) noexcept {}
        SmsAppMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsAppMessage(ptr, take_ownership_from_abi) {}
        SmsAppMessage();
    };
    struct __declspec(empty_bases) SmsBinaryMessage : llm::OS::Devices::Sms::ISmsBinaryMessage
    {
        SmsBinaryMessage(std::nullptr_t) noexcept {}
        SmsBinaryMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsBinaryMessage(ptr, take_ownership_from_abi) {}
        SmsBinaryMessage();
    };
    struct __declspec(empty_bases) SmsBroadcastMessage : llm::OS::Devices::Sms::ISmsBroadcastMessage
    {
        SmsBroadcastMessage(std::nullptr_t) noexcept {}
        SmsBroadcastMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsBroadcastMessage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsDevice : llm::OS::Devices::Sms::ISmsDevice
    {
        SmsDevice(std::nullptr_t) noexcept {}
        SmsDevice(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsDevice(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromIdAsync(param::hstring const& deviceId);
        static auto GetDefaultAsync();
        static auto FromNetworkAccountIdAsync(param::hstring const& networkAccountId);
    };
    struct __declspec(empty_bases) SmsDevice2 : llm::OS::Devices::Sms::ISmsDevice2
    {
        SmsDevice2(std::nullptr_t) noexcept {}
        SmsDevice2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsDevice2(ptr, take_ownership_from_abi) {}
        static auto GetDeviceSelector();
        static auto FromId(param::hstring const& deviceId);
        static auto GetDefault();
        static auto FromParentId(param::hstring const& parentDeviceId);
    };
    struct __declspec(empty_bases) SmsDeviceMessageStore : llm::OS::Devices::Sms::ISmsDeviceMessageStore
    {
        SmsDeviceMessageStore(std::nullptr_t) noexcept {}
        SmsDeviceMessageStore(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsDeviceMessageStore(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsFilterRule : llm::OS::Devices::Sms::ISmsFilterRule
    {
        SmsFilterRule(std::nullptr_t) noexcept {}
        SmsFilterRule(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsFilterRule(ptr, take_ownership_from_abi) {}
        explicit SmsFilterRule(llm::OS::Devices::Sms::SmsMessageType const& messageType);
    };
    struct __declspec(empty_bases) SmsFilterRules : llm::OS::Devices::Sms::ISmsFilterRules
    {
        SmsFilterRules(std::nullptr_t) noexcept {}
        SmsFilterRules(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsFilterRules(ptr, take_ownership_from_abi) {}
        explicit SmsFilterRules(llm::OS::Devices::Sms::SmsFilterActionType const& actionType);
    };
    struct __declspec(empty_bases) SmsMessageReceivedEventArgs : llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs
    {
        SmsMessageReceivedEventArgs(std::nullptr_t) noexcept {}
        SmsMessageReceivedEventArgs(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsMessageReceivedTriggerDetails : llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails
    {
        SmsMessageReceivedTriggerDetails(std::nullptr_t) noexcept {}
        SmsMessageReceivedTriggerDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsMessageRegistration : llm::OS::Devices::Sms::ISmsMessageRegistration
    {
        SmsMessageRegistration(std::nullptr_t) noexcept {}
        SmsMessageRegistration(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsMessageRegistration(ptr, take_ownership_from_abi) {}
        [[nodiscard]] static auto AllRegistrations();
        static auto Register(param::hstring const& id, llm::OS::Devices::Sms::SmsFilterRules const& filterRules);
    };
    struct __declspec(empty_bases) SmsReceivedEventDetails : llm::OS::Devices::Sms::ISmsReceivedEventDetails,
        impl::require<SmsReceivedEventDetails, llm::OS::Devices::Sms::ISmsReceivedEventDetails2>
    {
        SmsReceivedEventDetails(std::nullptr_t) noexcept {}
        SmsReceivedEventDetails(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsReceivedEventDetails(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsSendMessageResult : llm::OS::Devices::Sms::ISmsSendMessageResult
    {
        SmsSendMessageResult(std::nullptr_t) noexcept {}
        SmsSendMessageResult(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsSendMessageResult(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsStatusMessage : llm::OS::Devices::Sms::ISmsStatusMessage
    {
        SmsStatusMessage(std::nullptr_t) noexcept {}
        SmsStatusMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsStatusMessage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsTextMessage : llm::OS::Devices::Sms::ISmsTextMessage
    {
        SmsTextMessage(std::nullptr_t) noexcept {}
        SmsTextMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsTextMessage(ptr, take_ownership_from_abi) {}
        SmsTextMessage();
        static auto FromBinaryMessage(llm::OS::Devices::Sms::SmsBinaryMessage const& binaryMessage);
        static auto FromBinaryData(llm::OS::Devices::Sms::SmsDataFormat const& format, array_view<uint8_t const> value);
    };
    struct __declspec(empty_bases) SmsTextMessage2 : llm::OS::Devices::Sms::ISmsTextMessage2
    {
        SmsTextMessage2(std::nullptr_t) noexcept {}
        SmsTextMessage2(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsTextMessage2(ptr, take_ownership_from_abi) {}
        SmsTextMessage2();
    };
    struct __declspec(empty_bases) SmsVoicemailMessage : llm::OS::Devices::Sms::ISmsVoicemailMessage
    {
        SmsVoicemailMessage(std::nullptr_t) noexcept {}
        SmsVoicemailMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsVoicemailMessage(ptr, take_ownership_from_abi) {}
    };
    struct __declspec(empty_bases) SmsWapMessage : llm::OS::Devices::Sms::ISmsWapMessage
    {
        SmsWapMessage(std::nullptr_t) noexcept {}
        SmsWapMessage(void* ptr, take_ownership_from_abi_t) noexcept : llm::OS::Devices::Sms::ISmsWapMessage(ptr, take_ownership_from_abi) {}
    };
}
#endif
