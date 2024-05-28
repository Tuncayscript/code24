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
#ifndef LLM_OS_Devices_Sms_H
#define LLM_OS_Devices_Sms_H
#include "llm/base.h"
static_assert(llm::check_version(CPPLLM_VERSION, "2.0.220110.5"), "Mismatched C++/WinRT headers.");
#define CPPLLM_VERSION "2.0.220110.5"
#include "llm/Windows.Devices.h"
#include "llm/impl/Windows.Foundation.2.h"
#include "llm/impl/Windows.Foundation.Collections.2.h"
#include "llm/impl/Windows.Storage.Streams.2.h"
#include "llm/impl/Windows.Devices.Sms.2.h"
namespace llm::impl
{
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsAppMessage<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsAppMessage<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::To(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_To(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsAppMessage<D>::From() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_From(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsAppMessage<D>::Body() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_Body(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::Body(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_Body(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsAppMessage<D>::CallbackNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_CallbackNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::CallbackNumber(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_CallbackNumber(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Sms_ISmsAppMessage<D>::IsDeliveryNotificationEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_IsDeliveryNotificationEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::IsDeliveryNotificationEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_IsDeliveryNotificationEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsAppMessage<D>::RetryAttemptCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_RetryAttemptCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::RetryAttemptCount(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_RetryAttemptCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsEncoding) consume_Windows_Devices_Sms_ISmsAppMessage<D>::Encoding() const
    {
        llm::OS::Devices::Sms::SmsEncoding value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_Encoding(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::Encoding(llm::OS::Devices::Sms::SmsEncoding const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_Encoding(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsAppMessage<D>::PortNumber() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_PortNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::PortNumber(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_PortNumber(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsAppMessage<D>::TeleserviceId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_TeleserviceId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::TeleserviceId(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_TeleserviceId(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsAppMessage<D>::ProtocolId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_ProtocolId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::ProtocolId(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_ProtocolId(value));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_Sms_ISmsAppMessage<D>::BinaryBody() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->get_BinaryBody(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsAppMessage<D>::BinaryBody(llm::OS::Storage::Streams::IBuffer const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsAppMessage)->put_BinaryBody(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDataFormat) consume_Windows_Devices_Sms_ISmsBinaryMessage<D>::Format() const
    {
        llm::OS::Devices::Sms::SmsDataFormat value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBinaryMessage)->get_Format(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsBinaryMessage<D>::Format(llm::OS::Devices::Sms::SmsDataFormat const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBinaryMessage)->put_Format(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(com_array<uint8_t>) consume_Windows_Devices_Sms_ISmsBinaryMessage<D>::GetData() const
    {
        uint32_t value_impl_size{};
        uint8_t* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBinaryMessage)->GetData(&value_impl_size, &value));
        return com_array<uint8_t>{ value, value_impl_size, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsBinaryMessage<D>::SetData(array_view<uint8_t const> value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBinaryMessage)->SetData(value.size(), get_abi(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::Body() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_Body(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::Channel() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_Channel(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsGeographicalScope) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::GeographicalScope() const
    {
        llm::OS::Devices::Sms::SmsGeographicalScope value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_GeographicalScope(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::MessageCode() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_MessageCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::UpdateNumber() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_UpdateNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsBroadcastType) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::BroadcastType() const
    {
        llm::OS::Devices::Sms::SmsBroadcastType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_BroadcastType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::IsEmergencyAlert() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_IsEmergencyAlert(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Sms_ISmsBroadcastMessage<D>::IsUserPopupRequested() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsBroadcastMessage)->get_IsUserPopupRequested(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SendSmsMessageOperation) consume_Windows_Devices_Sms_ISmsDevice<D>::SendMessageAsync(llm::OS::Devices::Sms::ISmsMessage const& message) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->SendMessageAsync(*(void**)(&message), &asyncInfo));
        return llm::OS::Devices::Sms::SendSmsMessageOperation{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsEncodedLength) consume_Windows_Devices_Sms_ISmsDevice<D>::CalculateLength(llm::OS::Devices::Sms::SmsTextMessage const& message) const
    {
        llm::OS::Devices::Sms::SmsEncodedLength encodedLength{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->CalculateLength(*(void**)(&message), put_abi(encodedLength)));
        return encodedLength;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDevice<D>::AccountPhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->get_AccountPhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::CellularClass) consume_Windows_Devices_Sms_ISmsDevice<D>::CellularClass() const
    {
        llm::OS::Devices::Sms::CellularClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->get_CellularClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDeviceMessageStore) consume_Windows_Devices_Sms_ISmsDevice<D>::MessageStore() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->get_MessageStore(&value));
        return llm::OS::Devices::Sms::SmsDeviceMessageStore{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDeviceStatus) consume_Windows_Devices_Sms_ISmsDevice<D>::DeviceStatus() const
    {
        llm::OS::Devices::Sms::SmsDeviceStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->get_DeviceStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Sms_ISmsDevice<D>::SmsMessageReceived(llm::OS::Devices::Sms::SmsMessageReceivedEventHandler const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->add_SmsMessageReceived(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Devices_Sms_ISmsDevice<D>::SmsMessageReceived_revoker consume_Windows_Devices_Sms_ISmsDevice<D>::SmsMessageReceived(auto_revoke_t, llm::OS::Devices::Sms::SmsMessageReceivedEventHandler const& eventHandler) const
    {
        return impl::make_event_revoker<D, SmsMessageReceived_revoker>(this, SmsMessageReceived(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsDevice<D>::SmsMessageReceived(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->remove_SmsMessageReceived(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Sms_ISmsDevice<D>::SmsDeviceStatusChanged(llm::OS::Devices::Sms::SmsDeviceStatusChangedEventHandler const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->add_SmsDeviceStatusChanged(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Devices_Sms_ISmsDevice<D>::SmsDeviceStatusChanged_revoker consume_Windows_Devices_Sms_ISmsDevice<D>::SmsDeviceStatusChanged(auto_revoke_t, llm::OS::Devices::Sms::SmsDeviceStatusChangedEventHandler const& eventHandler) const
    {
        return impl::make_event_revoker<D, SmsDeviceStatusChanged_revoker>(this, SmsDeviceStatusChanged(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsDevice<D>::SmsDeviceStatusChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice)->remove_SmsDeviceStatusChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDevice2<D>::SmscAddress() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->get_SmscAddress(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsDevice2<D>::SmscAddress(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->put_SmscAddress(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDevice2<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDevice2<D>::ParentDeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->get_ParentDeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDevice2<D>::AccountPhoneNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->get_AccountPhoneNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::CellularClass) consume_Windows_Devices_Sms_ISmsDevice2<D>::CellularClass() const
    {
        llm::OS::Devices::Sms::CellularClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->get_CellularClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDeviceStatus) consume_Windows_Devices_Sms_ISmsDevice2<D>::DeviceStatus() const
    {
        llm::OS::Devices::Sms::SmsDeviceStatus value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->get_DeviceStatus(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsEncodedLength) consume_Windows_Devices_Sms_ISmsDevice2<D>::CalculateLength(llm::OS::Devices::Sms::ISmsMessageBase const& message) const
    {
        llm::OS::Devices::Sms::SmsEncodedLength value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->CalculateLength(*(void**)(&message), put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsSendMessageResult>) consume_Windows_Devices_Sms_ISmsDevice2<D>::SendMessageAndGetResultAsync(llm::OS::Devices::Sms::ISmsMessageBase const& message) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->SendMessageAndGetResultAsync(*(void**)(&message), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsSendMessageResult>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Sms_ISmsDevice2<D>::DeviceStatusChanged(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sms::SmsDevice2, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->add_DeviceStatusChanged(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Devices_Sms_ISmsDevice2<D>::DeviceStatusChanged_revoker consume_Windows_Devices_Sms_ISmsDevice2<D>::DeviceStatusChanged(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sms::SmsDevice2, llm::OS::Foundation::IInspectable> const& eventHandler) const
    {
        return impl::make_event_revoker<D, DeviceStatusChanged_revoker>(this, DeviceStatusChanged(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsDevice2<D>::DeviceStatusChanged(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2)->remove_DeviceStatusChanged(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDevice2Statics<D>::GetDeviceSelector() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2Statics)->GetDeviceSelector(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDevice2) consume_Windows_Devices_Sms_ISmsDevice2Statics<D>::FromId(param::hstring const& deviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2Statics)->FromId(*(void**)(&deviceId), &value));
        return llm::OS::Devices::Sms::SmsDevice2{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDevice2) consume_Windows_Devices_Sms_ISmsDevice2Statics<D>::GetDefault() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2Statics)->GetDefault(&value));
        return llm::OS::Devices::Sms::SmsDevice2{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsDevice2) consume_Windows_Devices_Sms_ISmsDevice2Statics<D>::FromParentId(param::hstring const& parentDeviceId) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDevice2Statics)->FromParentId(*(void**)(&parentDeviceId), &value));
        return llm::OS::Devices::Sms::SmsDevice2{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Sms_ISmsDeviceMessageStore<D>::DeleteMessageAsync(uint32_t messageId) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceMessageStore)->DeleteMessageAsync(messageId, &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncAction) consume_Windows_Devices_Sms_ISmsDeviceMessageStore<D>::DeleteMessagesAsync(llm::OS::Devices::Sms::SmsMessageFilter const& messageFilter) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceMessageStore)->DeleteMessagesAsync(static_cast<int32_t>(messageFilter), &asyncInfo));
        return llm::OS::Foundation::IAsyncAction{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::ISmsMessage>) consume_Windows_Devices_Sms_ISmsDeviceMessageStore<D>::GetMessageAsync(uint32_t messageId) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceMessageStore)->GetMessageAsync(messageId, &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::ISmsMessage>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsMessage>, int32_t>) consume_Windows_Devices_Sms_ISmsDeviceMessageStore<D>::GetMessagesAsync(llm::OS::Devices::Sms::SmsMessageFilter const& messageFilter) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceMessageStore)->GetMessagesAsync(static_cast<int32_t>(messageFilter), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsMessage>, int32_t>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sms_ISmsDeviceMessageStore<D>::MaxMessages() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceMessageStore)->get_MaxMessages(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsDeviceStatics<D>::GetDeviceSelector() const
    {
        void* phstrDeviceClassSelector{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceStatics)->GetDeviceSelector(&phstrDeviceClassSelector));
        return hstring{ phstrDeviceClassSelector, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>) consume_Windows_Devices_Sms_ISmsDeviceStatics<D>::FromIdAsync(param::hstring const& deviceId) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceStatics)->FromIdAsync(*(void**)(&deviceId), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>) consume_Windows_Devices_Sms_ISmsDeviceStatics<D>::GetDefaultAsync() const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceStatics)->GetDefaultAsync(&asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>) consume_Windows_Devices_Sms_ISmsDeviceStatics2<D>::FromNetworkAccountIdAsync(param::hstring const& networkAccountId) const
    {
        void* asyncInfo{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsDeviceStatics2)->FromNetworkAccountIdAsync(*(void**)(&networkAccountId), &asyncInfo));
        return llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>{ asyncInfo, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageType) consume_Windows_Devices_Sms_ISmsFilterRule<D>::MessageType() const
    {
        llm::OS::Devices::Sms::SmsMessageType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_MessageType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::ImsiPrefixes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_ImsiPrefixes(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::DeviceIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_DeviceIds(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::SenderNumbers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_SenderNumbers(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::TextMessagePrefixes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_TextMessagePrefixes(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<int32_t>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::PortNumbers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_PortNumbers(&value));
        return llm::OS::Foundation::Collections::IVector<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::CellularClass) consume_Windows_Devices_Sms_ISmsFilterRule<D>::CellularClass() const
    {
        llm::OS::Devices::Sms::CellularClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_CellularClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsFilterRule<D>::CellularClass(llm::OS::Devices::Sms::CellularClass const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->put_CellularClass(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<int32_t>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::ProtocolIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_ProtocolIds(&value));
        return llm::OS::Foundation::Collections::IVector<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<int32_t>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::TeleserviceIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_TeleserviceIds(&value));
        return llm::OS::Foundation::Collections::IVector<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::WapApplicationIds() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_WapApplicationIds(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<hstring>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::WapContentTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_WapContentTypes(&value));
        return llm::OS::Foundation::Collections::IVector<hstring>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sms::SmsBroadcastType>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::BroadcastTypes() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_BroadcastTypes(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sms::SmsBroadcastType>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<int32_t>) consume_Windows_Devices_Sms_ISmsFilterRule<D>::BroadcastChannels() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRule)->get_BroadcastChannels(&value));
        return llm::OS::Foundation::Collections::IVector<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsFilterRule) consume_Windows_Devices_Sms_ISmsFilterRuleFactory<D>::CreateFilterRule(llm::OS::Devices::Sms::SmsMessageType const& messageType) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRuleFactory)->CreateFilterRule(static_cast<int32_t>(messageType), &value));
        return llm::OS::Devices::Sms::SmsFilterRule{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsFilterActionType) consume_Windows_Devices_Sms_ISmsFilterRules<D>::ActionType() const
    {
        llm::OS::Devices::Sms::SmsFilterActionType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRules)->get_ActionType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sms::SmsFilterRule>) consume_Windows_Devices_Sms_ISmsFilterRules<D>::Rules() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRules)->get_Rules(&value));
        return llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sms::SmsFilterRule>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsFilterRules) consume_Windows_Devices_Sms_ISmsFilterRulesFactory<D>::CreateFilterRules(llm::OS::Devices::Sms::SmsFilterActionType const& actionType) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsFilterRulesFactory)->CreateFilterRules(static_cast<int32_t>(actionType), &value));
        return llm::OS::Devices::Sms::SmsFilterRules{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sms_ISmsMessage<D>::Id() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessage)->get_Id(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageClass) consume_Windows_Devices_Sms_ISmsMessage<D>::MessageClass() const
    {
        llm::OS::Devices::Sms::SmsMessageClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessage)->get_MessageClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageType) consume_Windows_Devices_Sms_ISmsMessageBase<D>::MessageType() const
    {
        llm::OS::Devices::Sms::SmsMessageType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageBase)->get_MessageType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsMessageBase<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageBase)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::CellularClass) consume_Windows_Devices_Sms_ISmsMessageBase<D>::CellularClass() const
    {
        llm::OS::Devices::Sms::CellularClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageBase)->get_CellularClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageClass) consume_Windows_Devices_Sms_ISmsMessageBase<D>::MessageClass() const
    {
        llm::OS::Devices::Sms::SmsMessageClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageBase)->get_MessageClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsMessageBase<D>::SimIccId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageBase)->get_SimIccId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsTextMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedEventArgs<D>::TextMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs)->get_TextMessage(&value));
        return llm::OS::Devices::Sms::SmsTextMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsBinaryMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedEventArgs<D>::BinaryMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs)->get_BinaryMessage(&value));
        return llm::OS::Devices::Sms::SmsBinaryMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageType) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::MessageType() const
    {
        llm::OS::Devices::Sms::SmsMessageType value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_MessageType(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsTextMessage2) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::TextMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_TextMessage(&value));
        return llm::OS::Devices::Sms::SmsTextMessage2{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsWapMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::WapMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_WapMessage(&value));
        return llm::OS::Devices::Sms::SmsWapMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsAppMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::AppMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_AppMessage(&value));
        return llm::OS::Devices::Sms::SmsAppMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsBroadcastMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::BroadcastMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_BroadcastMessage(&value));
        return llm::OS::Devices::Sms::SmsBroadcastMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsVoicemailMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::VoicemailMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_VoicemailMessage(&value));
        return llm::OS::Devices::Sms::SmsVoicemailMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsStatusMessage) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::StatusMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->get_StatusMessage(&value));
        return llm::OS::Devices::Sms::SmsStatusMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::Drop() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->Drop());
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsMessageReceivedTriggerDetails<D>::Accept() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails)->Accept());
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsMessageRegistration<D>::Id() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageRegistration)->get_Id(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsMessageRegistration<D>::Unregister() const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageRegistration)->Unregister());
    }
    template <typename D> LLM_IMPL_AUTO(llm::event_token) consume_Windows_Devices_Sms_ISmsMessageRegistration<D>::MessageReceived(llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sms::SmsMessageRegistration, llm::OS::Devices::Sms::SmsMessageReceivedTriggerDetails> const& eventHandler) const
    {
        llm::event_token eventCookie{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageRegistration)->add_MessageReceived(*(void**)(&eventHandler), put_abi(eventCookie)));
        return eventCookie;
    }
    template <typename D> typename consume_Windows_Devices_Sms_ISmsMessageRegistration<D>::MessageReceived_revoker consume_Windows_Devices_Sms_ISmsMessageRegistration<D>::MessageReceived(auto_revoke_t, llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sms::SmsMessageRegistration, llm::OS::Devices::Sms::SmsMessageReceivedTriggerDetails> const& eventHandler) const
    {
        return impl::make_event_revoker<D, MessageReceived_revoker>(this, MessageReceived(eventHandler));
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsMessageRegistration<D>::MessageReceived(llm::event_token const& eventCookie) const noexcept
    {
        LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageRegistration)->remove_MessageReceived(impl::bind_in(eventCookie));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::SmsMessageRegistration>) consume_Windows_Devices_Sms_ISmsMessageRegistrationStatics<D>::AllRegistrations() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageRegistrationStatics)->get_AllRegistrations(&value));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::SmsMessageRegistration>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageRegistration) consume_Windows_Devices_Sms_ISmsMessageRegistrationStatics<D>::Register(param::hstring const& id, llm::OS::Devices::Sms::SmsFilterRules const& filterRules) const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsMessageRegistrationStatics)->Register(*(void**)(&id), *(void**)(&filterRules), &value));
        return llm::OS::Devices::Sms::SmsMessageRegistration{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsReceivedEventDetails<D>::DeviceId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsReceivedEventDetails)->get_DeviceId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sms_ISmsReceivedEventDetails<D>::MessageIndex() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsReceivedEventDetails)->get_MessageIndex(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsMessageClass) consume_Windows_Devices_Sms_ISmsReceivedEventDetails2<D>::MessageClass() const
    {
        llm::OS::Devices::Sms::SmsMessageClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsReceivedEventDetails2)->get_MessageClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsBinaryMessage) consume_Windows_Devices_Sms_ISmsReceivedEventDetails2<D>::BinaryMessage() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsReceivedEventDetails2)->get_BinaryMessage(&value));
        return llm::OS::Devices::Sms::SmsBinaryMessage{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::IsSuccessful() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_IsSuccessful(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<int32_t>) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::MessageReferenceNumbers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_MessageReferenceNumbers(&value));
        return llm::OS::Foundation::Collections::IVectorView<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::CellularClass) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::CellularClass() const
    {
        llm::OS::Devices::Sms::CellularClass value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_CellularClass(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsModemErrorCode) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::ModemErrorCode() const
    {
        llm::OS::Devices::Sms::SmsModemErrorCode value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_ModemErrorCode(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::IsErrorTransient() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_IsErrorTransient(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::NetworkCauseCode() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_NetworkCauseCode(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsSendMessageResult<D>::TransportFailureCause() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsSendMessageResult)->get_TransportFailureCause(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::From() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_From(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::Body() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_Body(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::Status() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_Status(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::MessageReferenceNumber() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_MessageReferenceNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::ServiceCenterTimestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_ServiceCenterTimestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsStatusMessage<D>::DischargeTime() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsStatusMessage)->get_DischargeTime(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsTextMessage<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sms_ISmsTextMessage<D>::PartReferenceId() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_PartReferenceId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sms_ISmsTextMessage<D>::PartNumber() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_PartNumber(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(uint32_t) consume_Windows_Devices_Sms_ISmsTextMessage<D>::PartCount() const
    {
        uint32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_PartCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage<D>::To(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->put_To(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage<D>::From() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_From(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage<D>::From(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->put_From(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage<D>::Body() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_Body(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage<D>::Body(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->put_Body(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsEncoding) consume_Windows_Devices_Sms_ISmsTextMessage<D>::Encoding() const
    {
        llm::OS::Devices::Sms::SmsEncoding value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->get_Encoding(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage<D>::Encoding(llm::OS::Devices::Sms::SmsEncoding const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->put_Encoding(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsBinaryMessage>) consume_Windows_Devices_Sms_ISmsTextMessage<D>::ToBinaryMessages(llm::OS::Devices::Sms::SmsDataFormat const& format) const
    {
        void* messages{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage)->ToBinaryMessages(static_cast<int32_t>(format), &messages));
        return llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsBinaryMessage>{ messages, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::To(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->put_To(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::From() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_From(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::Body() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_Body(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::Body(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->put_Body(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsEncoding) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::Encoding() const
    {
        llm::OS::Devices::Sms::SmsEncoding value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_Encoding(reinterpret_cast<int32_t*>(&value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::Encoding(llm::OS::Devices::Sms::SmsEncoding const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->put_Encoding(static_cast<int32_t>(value)));
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::CallbackNumber() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_CallbackNumber(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::CallbackNumber(param::hstring const& value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->put_CallbackNumber(*(void**)(&value)));
    }
    template <typename D> LLM_IMPL_AUTO(bool) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::IsDeliveryNotificationEnabled() const
    {
        bool value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_IsDeliveryNotificationEnabled(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::IsDeliveryNotificationEnabled(bool value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->put_IsDeliveryNotificationEnabled(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::RetryAttemptCount() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_RetryAttemptCount(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(void) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::RetryAttemptCount(int32_t value) const
    {
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->put_RetryAttemptCount(value));
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::TeleserviceId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_TeleserviceId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(int32_t) consume_Windows_Devices_Sms_ISmsTextMessage2<D>::ProtocolId() const
    {
        int32_t value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessage2)->get_ProtocolId(&value));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsTextMessage) consume_Windows_Devices_Sms_ISmsTextMessageStatics<D>::FromBinaryMessage(llm::OS::Devices::Sms::SmsBinaryMessage const& binaryMessage) const
    {
        void* textMessage{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessageStatics)->FromBinaryMessage(*(void**)(&binaryMessage), &textMessage));
        return llm::OS::Devices::Sms::SmsTextMessage{ textMessage, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Devices::Sms::SmsTextMessage) consume_Windows_Devices_Sms_ISmsTextMessageStatics<D>::FromBinaryData(llm::OS::Devices::Sms::SmsDataFormat const& format, array_view<uint8_t const> value) const
    {
        void* textMessage{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsTextMessageStatics)->FromBinaryData(static_cast<int32_t>(format), value.size(), get_abi(value), &textMessage));
        return llm::OS::Devices::Sms::SmsTextMessage{ textMessage, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsVoicemailMessage<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsVoicemailMessage)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsVoicemailMessage<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsVoicemailMessage)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsVoicemailMessage<D>::Body() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsVoicemailMessage)->get_Body(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::IReference<int32_t>) consume_Windows_Devices_Sms_ISmsVoicemailMessage<D>::MessageCount() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsVoicemailMessage)->get_MessageCount(&value));
        return llm::OS::Foundation::IReference<int32_t>{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::DateTime) consume_Windows_Devices_Sms_ISmsWapMessage<D>::Timestamp() const
    {
        llm::OS::Foundation::DateTime value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_Timestamp(put_abi(value)));
        return value;
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsWapMessage<D>::To() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_To(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsWapMessage<D>::From() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_From(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsWapMessage<D>::ApplicationId() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_ApplicationId(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(hstring) consume_Windows_Devices_Sms_ISmsWapMessage<D>::ContentType() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_ContentType(&value));
        return hstring{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Storage::Streams::IBuffer) consume_Windows_Devices_Sms_ISmsWapMessage<D>::BinaryBody() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_BinaryBody(&value));
        return llm::OS::Storage::Streams::IBuffer{ value, take_ownership_from_abi };
    }
    template <typename D> LLM_IMPL_AUTO(llm::OS::Foundation::Collections::IMap<hstring, hstring>) consume_Windows_Devices_Sms_ISmsWapMessage<D>::Headers() const
    {
        void* value{};
        check_hresult(LLM_IMPL_SHIM(llm::OS::Devices::Sms::ISmsWapMessage)->get_Headers(&value));
        return llm::OS::Foundation::Collections::IMap<hstring, hstring>{ value, take_ownership_from_abi };
    }
    template <typename H> struct delegate<llm::OS::Devices::Sms::SmsDeviceStatusChangedEventHandler, H> final : implements_delegate<llm::OS::Devices::Sms::SmsDeviceStatusChangedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Devices::Sms::SmsDeviceStatusChangedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Devices::Sms::SmsDevice const*>(&sender));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename H> struct delegate<llm::OS::Devices::Sms::SmsMessageReceivedEventHandler, H> final : implements_delegate<llm::OS::Devices::Sms::SmsMessageReceivedEventHandler, H>
    {
        delegate(H&& handler) : implements_delegate<llm::OS::Devices::Sms::SmsMessageReceivedEventHandler, H>(std::forward<H>(handler)) {}

        int32_t __stdcall Invoke(void* sender, void* e) noexcept final try
        {
            (*this)(*reinterpret_cast<llm::OS::Devices::Sms::SmsDevice const*>(&sender), *reinterpret_cast<llm::OS::Devices::Sms::SmsMessageReceivedEventArgs const*>(&e));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsAppMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsAppMessage>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_To(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_From(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().From());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Body(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Body());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Body(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallbackNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallbackNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CallbackNumber(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallbackNumber(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDeliveryNotificationEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDeliveryNotificationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsDeliveryNotificationEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDeliveryNotificationEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RetryAttemptCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RetryAttemptCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RetryAttemptCount(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetryAttemptCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Encoding(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsEncoding>(this->shim().Encoding());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Encoding(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encoding(*reinterpret_cast<llm::OS::Devices::Sms::SmsEncoding const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PortNumber(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().PortNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_PortNumber(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().PortNumber(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TeleserviceId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().TeleserviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_TeleserviceId(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().TeleserviceId(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProtocolId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ProtocolId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_ProtocolId(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().ProtocolId(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BinaryBody(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().BinaryBody());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_BinaryBody(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().BinaryBody(*reinterpret_cast<llm::OS::Storage::Streams::IBuffer const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsBinaryMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsBinaryMessage>
    {
        int32_t __stdcall get_Format(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDataFormat>(this->shim().Format());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Format(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Format(*reinterpret_cast<llm::OS::Devices::Sms::SmsDataFormat const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetData(uint32_t* __valueSize, uint8_t** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            std::tie(*__valueSize, *value) = detach_abi(this->shim().GetData());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SetData(uint32_t __valueSize, uint8_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SetData(array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(value), reinterpret_cast<uint8_t const *>(value) + __valueSize));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsBroadcastMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsBroadcastMessage>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Body(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Body());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Channel(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Channel());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_GeographicalScope(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsGeographicalScope>(this->shim().GeographicalScope());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MessageCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_UpdateNumber(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().UpdateNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BroadcastType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsBroadcastType>(this->shim().BroadcastType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsEmergencyAlert(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsEmergencyAlert());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsUserPopupRequested(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsUserPopupRequested());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsDevice> : produce_base<D, llm::OS::Devices::Sms::ISmsDevice>
    {
        int32_t __stdcall SendMessageAsync(void* message, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Devices::Sms::SendSmsMessageOperation>(this->shim().SendMessageAsync(*reinterpret_cast<llm::OS::Devices::Sms::ISmsMessage const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CalculateLength(void* message, struct struct_Windows_Devices_Sms_SmsEncodedLength* encodedLength) noexcept final try
        {
            zero_abi<llm::OS::Devices::Sms::SmsEncodedLength>(encodedLength);
            typename D::abi_guard guard(this->shim());
            *encodedLength = detach_from<llm::OS::Devices::Sms::SmsEncodedLength>(this->shim().CalculateLength(*reinterpret_cast<llm::OS::Devices::Sms::SmsTextMessage const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AccountPhoneNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AccountPhoneNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::CellularClass>(this->shim().CellularClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageStore(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDeviceMessageStore>(this->shim().MessageStore());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDeviceStatus>(this->shim().DeviceStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_SmsMessageReceived(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().SmsMessageReceived(*reinterpret_cast<llm::OS::Devices::Sms::SmsMessageReceivedEventHandler const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SmsMessageReceived(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmsMessageReceived(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
        int32_t __stdcall add_SmsDeviceStatusChanged(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().SmsDeviceStatusChanged(*reinterpret_cast<llm::OS::Devices::Sms::SmsDeviceStatusChangedEventHandler const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_SmsDeviceStatusChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmsDeviceStatusChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsDevice2> : produce_base<D, llm::OS::Devices::Sms::ISmsDevice2>
    {
        int32_t __stdcall get_SmscAddress(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SmscAddress());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_SmscAddress(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().SmscAddress(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ParentDeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ParentDeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AccountPhoneNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().AccountPhoneNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::CellularClass>(this->shim().CellularClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceStatus(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDeviceStatus>(this->shim().DeviceStatus());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall CalculateLength(void* message, struct struct_Windows_Devices_Sms_SmsEncodedLength* value) noexcept final try
        {
            zero_abi<llm::OS::Devices::Sms::SmsEncodedLength>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsEncodedLength>(this->shim().CalculateLength(*reinterpret_cast<llm::OS::Devices::Sms::ISmsMessageBase const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall SendMessageAndGetResultAsync(void* message, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsSendMessageResult>>(this->shim().SendMessageAndGetResultAsync(*reinterpret_cast<llm::OS::Devices::Sms::ISmsMessageBase const*>(&message)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_DeviceStatusChanged(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().DeviceStatusChanged(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sms::SmsDevice2, llm::OS::Foundation::IInspectable> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_DeviceStatusChanged(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().DeviceStatusChanged(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsDevice2Statics> : produce_base<D, llm::OS::Devices::Sms::ISmsDevice2Statics>
    {
        int32_t __stdcall GetDeviceSelector(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromId(void* deviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDevice2>(this->shim().FromId(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDefault(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDevice2>(this->shim().GetDefault());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromParentId(void* parentDeviceId, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsDevice2>(this->shim().FromParentId(*reinterpret_cast<hstring const*>(&parentDeviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsDeviceMessageStore> : produce_base<D, llm::OS::Devices::Sms::ISmsDeviceMessageStore>
    {
        int32_t __stdcall DeleteMessageAsync(uint32_t messageId, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteMessageAsync(messageId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall DeleteMessagesAsync(int32_t messageFilter, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncAction>(this->shim().DeleteMessagesAsync(*reinterpret_cast<llm::OS::Devices::Sms::SmsMessageFilter const*>(&messageFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMessageAsync(uint32_t messageId, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::ISmsMessage>>(this->shim().GetMessageAsync(messageId));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetMessagesAsync(int32_t messageFilter, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperationWithProgress<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsMessage>, int32_t>>(this->shim().GetMessagesAsync(*reinterpret_cast<llm::OS::Devices::Sms::SmsMessageFilter const*>(&messageFilter)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MaxMessages(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MaxMessages());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsDeviceStatics> : produce_base<D, llm::OS::Devices::Sms::ISmsDeviceStatics>
    {
        int32_t __stdcall GetDeviceSelector(void** phstrDeviceClassSelector) noexcept final try
        {
            clear_abi(phstrDeviceClassSelector);
            typename D::abi_guard guard(this->shim());
            *phstrDeviceClassSelector = detach_from<hstring>(this->shim().GetDeviceSelector());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromIdAsync(void* deviceId, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>>(this->shim().FromIdAsync(*reinterpret_cast<hstring const*>(&deviceId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall GetDefaultAsync(void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>>(this->shim().GetDefaultAsync());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsDeviceStatics2> : produce_base<D, llm::OS::Devices::Sms::ISmsDeviceStatics2>
    {
        int32_t __stdcall FromNetworkAccountIdAsync(void* networkAccountId, void** asyncInfo) noexcept final try
        {
            clear_abi(asyncInfo);
            typename D::abi_guard guard(this->shim());
            *asyncInfo = detach_from<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>>(this->shim().FromNetworkAccountIdAsync(*reinterpret_cast<hstring const*>(&networkAccountId)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsFilterRule> : produce_base<D, llm::OS::Devices::Sms::ISmsFilterRule>
    {
        int32_t __stdcall get_MessageType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageType>(this->shim().MessageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ImsiPrefixes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().ImsiPrefixes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().DeviceIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SenderNumbers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().SenderNumbers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TextMessagePrefixes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().TextMessagePrefixes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PortNumbers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<int32_t>>(this->shim().PortNumbers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::CellularClass>(this->shim().CellularClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CellularClass(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CellularClass(*reinterpret_cast<llm::OS::Devices::Sms::CellularClass const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProtocolIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<int32_t>>(this->shim().ProtocolIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TeleserviceIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<int32_t>>(this->shim().TeleserviceIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WapApplicationIds(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().WapApplicationIds());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WapContentTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<hstring>>(this->shim().WapContentTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BroadcastTypes(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sms::SmsBroadcastType>>(this->shim().BroadcastTypes());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BroadcastChannels(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<int32_t>>(this->shim().BroadcastChannels());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsFilterRuleFactory> : produce_base<D, llm::OS::Devices::Sms::ISmsFilterRuleFactory>
    {
        int32_t __stdcall CreateFilterRule(int32_t messageType, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsFilterRule>(this->shim().CreateFilterRule(*reinterpret_cast<llm::OS::Devices::Sms::SmsMessageType const*>(&messageType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsFilterRules> : produce_base<D, llm::OS::Devices::Sms::ISmsFilterRules>
    {
        int32_t __stdcall get_ActionType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsFilterActionType>(this->shim().ActionType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Rules(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVector<llm::OS::Devices::Sms::SmsFilterRule>>(this->shim().Rules());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsFilterRulesFactory> : produce_base<D, llm::OS::Devices::Sms::ISmsFilterRulesFactory>
    {
        int32_t __stdcall CreateFilterRules(int32_t actionType, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsFilterRules>(this->shim().CreateFilterRules(*reinterpret_cast<llm::OS::Devices::Sms::SmsFilterActionType const*>(&actionType)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsMessage>
    {
        int32_t __stdcall get_Id(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageClass>(this->shim().MessageClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsMessageBase> : produce_base<D, llm::OS::Devices::Sms::ISmsMessageBase>
    {
        int32_t __stdcall get_MessageType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageType>(this->shim().MessageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::CellularClass>(this->shim().CellularClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageClass>(this->shim().MessageClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_SimIccId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().SimIccId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs> : produce_base<D, llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs>
    {
        int32_t __stdcall get_TextMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsTextMessage>(this->shim().TextMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BinaryMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsBinaryMessage>(this->shim().BinaryMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails> : produce_base<D, llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails>
    {
        int32_t __stdcall get_MessageType(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageType>(this->shim().MessageType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TextMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsTextMessage2>(this->shim().TextMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_WapMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsWapMessage>(this->shim().WapMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_AppMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsAppMessage>(this->shim().AppMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BroadcastMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsBroadcastMessage>(this->shim().BroadcastMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_VoicemailMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsVoicemailMessage>(this->shim().VoicemailMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_StatusMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsStatusMessage>(this->shim().StatusMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Drop() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Drop();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Accept() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Accept();
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsMessageRegistration> : produce_base<D, llm::OS::Devices::Sms::ISmsMessageRegistration>
    {
        int32_t __stdcall get_Id(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Id());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Unregister() noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Unregister();
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall add_MessageReceived(void* eventHandler, llm::event_token* eventCookie) noexcept final try
        {
            zero_abi<llm::event_token>(eventCookie);
            typename D::abi_guard guard(this->shim());
            *eventCookie = detach_from<llm::event_token>(this->shim().MessageReceived(*reinterpret_cast<llm::OS::Foundation::TypedEventHandler<llm::OS::Devices::Sms::SmsMessageRegistration, llm::OS::Devices::Sms::SmsMessageReceivedTriggerDetails> const*>(&eventHandler)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall remove_MessageReceived(llm::event_token eventCookie) noexcept final
        {
            typename D::abi_guard guard(this->shim());
            this->shim().MessageReceived(*reinterpret_cast<llm::event_token const*>(&eventCookie));
            return 0;
        }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsMessageRegistrationStatics> : produce_base<D, llm::OS::Devices::Sms::ISmsMessageRegistrationStatics>
    {
        int32_t __stdcall get_AllRegistrations(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::SmsMessageRegistration>>(this->shim().AllRegistrations());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall Register(void* id, void* filterRules, void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageRegistration>(this->shim().Register(*reinterpret_cast<hstring const*>(&id), *reinterpret_cast<llm::OS::Devices::Sms::SmsFilterRules const*>(&filterRules)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsReceivedEventDetails> : produce_base<D, llm::OS::Devices::Sms::ISmsReceivedEventDetails>
    {
        int32_t __stdcall get_DeviceId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().DeviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageIndex(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().MessageIndex());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsReceivedEventDetails2> : produce_base<D, llm::OS::Devices::Sms::ISmsReceivedEventDetails2>
    {
        int32_t __stdcall get_MessageClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsMessageClass>(this->shim().MessageClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BinaryMessage(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsBinaryMessage>(this->shim().BinaryMessage());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsSendMessageResult> : produce_base<D, llm::OS::Devices::Sms::ISmsSendMessageResult>
    {
        int32_t __stdcall get_IsSuccessful(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsSuccessful());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageReferenceNumbers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IVectorView<int32_t>>(this->shim().MessageReferenceNumbers());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CellularClass(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::CellularClass>(this->shim().CellularClass());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ModemErrorCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsModemErrorCode>(this->shim().ModemErrorCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsErrorTransient(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsErrorTransient());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_NetworkCauseCode(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().NetworkCauseCode());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TransportFailureCause(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().TransportFailureCause());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsStatusMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsStatusMessage>
    {
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_From(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().From());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Body(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Body());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Status(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().Status());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageReferenceNumber(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().MessageReferenceNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ServiceCenterTimestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().ServiceCenterTimestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_DischargeTime(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().DischargeTime());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsTextMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsTextMessage>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PartReferenceId(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PartReferenceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PartNumber(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PartNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_PartCount(uint32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<uint32_t>(this->shim().PartCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_To(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_From(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().From());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_From(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().From(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Body(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Body());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Body(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Encoding(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsEncoding>(this->shim().Encoding());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Encoding(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encoding(*reinterpret_cast<llm::OS::Devices::Sms::SmsEncoding const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall ToBinaryMessages(int32_t format, void** messages) noexcept final try
        {
            clear_abi(messages);
            typename D::abi_guard guard(this->shim());
            *messages = detach_from<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::ISmsBinaryMessage>>(this->shim().ToBinaryMessages(*reinterpret_cast<llm::OS::Devices::Sms::SmsDataFormat const*>(&format)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsTextMessage2> : produce_base<D, llm::OS::Devices::Sms::ISmsTextMessage2>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_To(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().To(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_From(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().From());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Body(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Body());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Body(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Body(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Encoding(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Devices::Sms::SmsEncoding>(this->shim().Encoding());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_Encoding(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().Encoding(*reinterpret_cast<llm::OS::Devices::Sms::SmsEncoding const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_CallbackNumber(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().CallbackNumber());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_CallbackNumber(void* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().CallbackNumber(*reinterpret_cast<hstring const*>(&value));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_IsDeliveryNotificationEnabled(bool* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<bool>(this->shim().IsDeliveryNotificationEnabled());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_IsDeliveryNotificationEnabled(bool value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().IsDeliveryNotificationEnabled(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_RetryAttemptCount(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().RetryAttemptCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall put_RetryAttemptCount(int32_t value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            this->shim().RetryAttemptCount(value);
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_TeleserviceId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().TeleserviceId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ProtocolId(int32_t* value) noexcept final try
        {
            typename D::abi_guard guard(this->shim());
            *value = detach_from<int32_t>(this->shim().ProtocolId());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsTextMessageStatics> : produce_base<D, llm::OS::Devices::Sms::ISmsTextMessageStatics>
    {
        int32_t __stdcall FromBinaryMessage(void* binaryMessage, void** textMessage) noexcept final try
        {
            clear_abi(textMessage);
            typename D::abi_guard guard(this->shim());
            *textMessage = detach_from<llm::OS::Devices::Sms::SmsTextMessage>(this->shim().FromBinaryMessage(*reinterpret_cast<llm::OS::Devices::Sms::SmsBinaryMessage const*>(&binaryMessage)));
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall FromBinaryData(int32_t format, uint32_t __valueSize, uint8_t* value, void** textMessage) noexcept final try
        {
            clear_abi(textMessage);
            typename D::abi_guard guard(this->shim());
            *textMessage = detach_from<llm::OS::Devices::Sms::SmsTextMessage>(this->shim().FromBinaryData(*reinterpret_cast<llm::OS::Devices::Sms::SmsDataFormat const*>(&format), array_view<uint8_t const>(reinterpret_cast<uint8_t const *>(value), reinterpret_cast<uint8_t const *>(value) + __valueSize)));
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsVoicemailMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsVoicemailMessage>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Body(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().Body());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_MessageCount(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::IReference<int32_t>>(this->shim().MessageCount());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
#ifndef LLM_LEAN_AND_MEAN
    template <typename D>
    struct produce<D, llm::OS::Devices::Sms::ISmsWapMessage> : produce_base<D, llm::OS::Devices::Sms::ISmsWapMessage>
    {
        int32_t __stdcall get_Timestamp(int64_t* value) noexcept final try
        {
            zero_abi<llm::OS::Foundation::DateTime>(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::DateTime>(this->shim().Timestamp());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_To(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().To());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_From(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().From());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ApplicationId(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ApplicationId());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_ContentType(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<hstring>(this->shim().ContentType());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_BinaryBody(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Storage::Streams::IBuffer>(this->shim().BinaryBody());
            return 0;
        }
        catch (...) { return to_hresult(); }
        int32_t __stdcall get_Headers(void** value) noexcept final try
        {
            clear_abi(value);
            typename D::abi_guard guard(this->shim());
            *value = detach_from<llm::OS::Foundation::Collections::IMap<hstring, hstring>>(this->shim().Headers());
            return 0;
        }
        catch (...) { return to_hresult(); }
    };
#endif
}
LLM_EXPORT namespace llm::OS::Devices::Sms
{
    inline SmsAppMessage::SmsAppMessage() :
        SmsAppMessage(impl::call_factory_cast<SmsAppMessage(*)(llm::OS::Foundation::IActivationFactory const&), SmsAppMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SmsAppMessage>(); }))
    {
    }
    inline SmsBinaryMessage::SmsBinaryMessage() :
        SmsBinaryMessage(impl::call_factory_cast<SmsBinaryMessage(*)(llm::OS::Foundation::IActivationFactory const&), SmsBinaryMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SmsBinaryMessage>(); }))
    {
    }
    inline auto SmsDevice::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(ISmsDeviceStatics const&), SmsDevice, ISmsDeviceStatics>([](ISmsDeviceStatics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto SmsDevice::FromIdAsync(param::hstring const& deviceId)
    {
        return impl::call_factory<SmsDevice, ISmsDeviceStatics>([&](ISmsDeviceStatics const& f) { return f.FromIdAsync(deviceId); });
    }
    inline auto SmsDevice::GetDefaultAsync()
    {
        return impl::call_factory_cast<llm::OS::Foundation::IAsyncOperation<llm::OS::Devices::Sms::SmsDevice>(*)(ISmsDeviceStatics const&), SmsDevice, ISmsDeviceStatics>([](ISmsDeviceStatics const& f) { return f.GetDefaultAsync(); });
    }
    inline auto SmsDevice::FromNetworkAccountIdAsync(param::hstring const& networkAccountId)
    {
        return impl::call_factory<SmsDevice, ISmsDeviceStatics2>([&](ISmsDeviceStatics2 const& f) { return f.FromNetworkAccountIdAsync(networkAccountId); });
    }
    inline auto SmsDevice2::GetDeviceSelector()
    {
        return impl::call_factory_cast<hstring(*)(ISmsDevice2Statics const&), SmsDevice2, ISmsDevice2Statics>([](ISmsDevice2Statics const& f) { return f.GetDeviceSelector(); });
    }
    inline auto SmsDevice2::FromId(param::hstring const& deviceId)
    {
        return impl::call_factory<SmsDevice2, ISmsDevice2Statics>([&](ISmsDevice2Statics const& f) { return f.FromId(deviceId); });
    }
    inline auto SmsDevice2::GetDefault()
    {
        return impl::call_factory_cast<llm::OS::Devices::Sms::SmsDevice2(*)(ISmsDevice2Statics const&), SmsDevice2, ISmsDevice2Statics>([](ISmsDevice2Statics const& f) { return f.GetDefault(); });
    }
    inline auto SmsDevice2::FromParentId(param::hstring const& parentDeviceId)
    {
        return impl::call_factory<SmsDevice2, ISmsDevice2Statics>([&](ISmsDevice2Statics const& f) { return f.FromParentId(parentDeviceId); });
    }
    inline SmsFilterRule::SmsFilterRule(llm::OS::Devices::Sms::SmsMessageType const& messageType) :
        SmsFilterRule(impl::call_factory<SmsFilterRule, ISmsFilterRuleFactory>([&](ISmsFilterRuleFactory const& f) { return f.CreateFilterRule(messageType); }))
    {
    }
    inline SmsFilterRules::SmsFilterRules(llm::OS::Devices::Sms::SmsFilterActionType const& actionType) :
        SmsFilterRules(impl::call_factory<SmsFilterRules, ISmsFilterRulesFactory>([&](ISmsFilterRulesFactory const& f) { return f.CreateFilterRules(actionType); }))
    {
    }
    inline auto SmsMessageRegistration::AllRegistrations()
    {
        return impl::call_factory_cast<llm::OS::Foundation::Collections::IVectorView<llm::OS::Devices::Sms::SmsMessageRegistration>(*)(ISmsMessageRegistrationStatics const&), SmsMessageRegistration, ISmsMessageRegistrationStatics>([](ISmsMessageRegistrationStatics const& f) { return f.AllRegistrations(); });
    }
    inline auto SmsMessageRegistration::Register(param::hstring const& id, llm::OS::Devices::Sms::SmsFilterRules const& filterRules)
    {
        return impl::call_factory<SmsMessageRegistration, ISmsMessageRegistrationStatics>([&](ISmsMessageRegistrationStatics const& f) { return f.Register(id, filterRules); });
    }
    inline SmsTextMessage::SmsTextMessage() :
        SmsTextMessage(impl::call_factory_cast<SmsTextMessage(*)(llm::OS::Foundation::IActivationFactory const&), SmsTextMessage>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SmsTextMessage>(); }))
    {
    }
    inline auto SmsTextMessage::FromBinaryMessage(llm::OS::Devices::Sms::SmsBinaryMessage const& binaryMessage)
    {
        return impl::call_factory<SmsTextMessage, ISmsTextMessageStatics>([&](ISmsTextMessageStatics const& f) { return f.FromBinaryMessage(binaryMessage); });
    }
    inline auto SmsTextMessage::FromBinaryData(llm::OS::Devices::Sms::SmsDataFormat const& format, array_view<uint8_t const> value)
    {
        return impl::call_factory<SmsTextMessage, ISmsTextMessageStatics>([&](ISmsTextMessageStatics const& f) { return f.FromBinaryData(format, value); });
    }
    inline SmsTextMessage2::SmsTextMessage2() :
        SmsTextMessage2(impl::call_factory_cast<SmsTextMessage2(*)(llm::OS::Foundation::IActivationFactory const&), SmsTextMessage2>([](llm::OS::Foundation::IActivationFactory const& f) { return f.template ActivateInstance<SmsTextMessage2>(); }))
    {
    }
    template <typename L> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(L handler) :
        SmsDeviceStatusChangedEventHandler(impl::make_delegate<SmsDeviceStatusChangedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(F* handler) :
        SmsDeviceStatusChangedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(O* object, M method) :
        SmsDeviceStatusChangedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(com_ptr<O>&& object, M method) :
        SmsDeviceStatusChangedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> SmsDeviceStatusChangedEventHandler::SmsDeviceStatusChangedEventHandler(weak_ref<O>&& object, M method) :
        SmsDeviceStatusChangedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto SmsDeviceStatusChangedEventHandler::operator()(llm::OS::Devices::Sms::SmsDevice const& sender) const
    {
        check_hresult((*(impl::abi_t<SmsDeviceStatusChangedEventHandler>**)this)->Invoke(*(void**)(&sender)));
    }
    template <typename L> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(L handler) :
        SmsMessageReceivedEventHandler(impl::make_delegate<SmsMessageReceivedEventHandler>(std::forward<L>(handler)))
    {
    }
    template <typename F> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(F* handler) :
        SmsMessageReceivedEventHandler([=](auto&&... args) { return handler(args...); })
    {
    }
    template <typename O, typename M> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(O* object, M method) :
        SmsMessageReceivedEventHandler([=](auto&&... args) { return ((*object).*(method))(args...); })
    {
    }
    template <typename O, typename M> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(com_ptr<O>&& object, M method) :
        SmsMessageReceivedEventHandler([o = std::move(object), method](auto&&... args) { return ((*o).*(method))(args...); })
    {
    }
    template <typename O, typename M> SmsMessageReceivedEventHandler::SmsMessageReceivedEventHandler(weak_ref<O>&& object, M method) :
        SmsMessageReceivedEventHandler([o = std::move(object), method](auto&&... args) { if (auto s = o.get()) { ((*s).*(method))(args...); } })
    {
    }
    inline auto SmsMessageReceivedEventHandler::operator()(llm::OS::Devices::Sms::SmsDevice const& sender, llm::OS::Devices::Sms::SmsMessageReceivedEventArgs const& e) const
    {
        check_hresult((*(impl::abi_t<SmsMessageReceivedEventHandler>**)this)->Invoke(*(void**)(&sender), *(void**)(&e)));
    }
}
namespace std
{
#ifndef LLM_LEAN_AND_MEAN
    template<> struct hash<llm::OS::Devices::Sms::ISmsAppMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsBinaryMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsBroadcastMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsDevice2Statics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsDeviceMessageStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsDeviceStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsDeviceStatics2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsFilterRule> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsFilterRuleFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsFilterRules> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsFilterRulesFactory> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsMessageBase> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsMessageReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsMessageReceivedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsMessageRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsMessageRegistrationStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsReceivedEventDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsReceivedEventDetails2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsSendMessageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsStatusMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsTextMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsTextMessage2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsTextMessageStatics> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsVoicemailMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::ISmsWapMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::DeleteSmsMessageOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::DeleteSmsMessagesOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::GetSmsDeviceOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::GetSmsMessageOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::GetSmsMessagesOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SendSmsMessageOperation> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsAppMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsBinaryMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsBroadcastMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsDevice> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsDevice2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsDeviceMessageStore> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsFilterRule> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsFilterRules> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsMessageReceivedEventArgs> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsMessageReceivedTriggerDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsMessageRegistration> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsReceivedEventDetails> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsSendMessageResult> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsStatusMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsTextMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsTextMessage2> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsVoicemailMessage> : llm::impl::hash_base {};
    template<> struct hash<llm::OS::Devices::Sms::SmsWapMessage> : llm::impl::hash_base {};
#endif
#ifdef __cpp_lib_format
#endif
}
#endif
